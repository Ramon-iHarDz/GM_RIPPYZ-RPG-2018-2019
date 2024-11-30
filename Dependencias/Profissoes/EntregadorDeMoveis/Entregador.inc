#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Entregador de Móveis - Entregas{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para visualizar", 0x00BFFFFF, -1707.5701,1018.1252,17.5859, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 30.0, -1);
    CreateDynamicPickup(1239, 1, -1707.5701,1018.1252,17.5859, 0, 0, -1, 70.0, -1);

    CreateDynamic3DTextLabel("Entregador de Móveis{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", 0x00BFFFFF, -1731.8093,991.4303,17.5900, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 30.0, -1);
    CreateDynamicPickup(1239, 1, -1731.8093,991.4303,17.5900, 0, 0, -1, 70.0, -1);

    CreateDynamic3DTextLabel("Entregador de Móveis - Carregamento{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para pegar", 0x00BFFFFF, -1716.3253,1018.1722,17.5859, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 30.0, -1);
    CreateDynamicPickup(1239, 1, -1716.3253,1018.1722,17.5859, 0, 0, -1, 70.0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamicMapIconEx(pMEntregador[playerid][MapaEntrega]);
    DestroyDynamicCPEx(pMEntregador[playerid][CheckEntrega]);
    DestroyDynamic3DTextLabelEx(pMEntregador[playerid][EntregaTexto]);
    if(pMEntregador[playerid][mVAlugado] == true) DestroyVehicleEx(pMEntregador[playerid][mVID]);
    if(pMEntregador[playerid][IndoEntregar] == true || pMEntregador[playerid][SelecEntrega] == true){
        new id = pMEntregador[playerid][CasaEntregg];
        eMoveis[id][JaLevando] = false;
        eMoveis[id][MovelStatusPlayer] = 0;
    }

    new Pdas[EntregadorMoveis];
    pMEntregador[playerid] = Pdas;
    return 1;
}

hook OnVehicleDeath(vehicleid, killerid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(pMEntregador[i][mVAlugado] == false) continue;
        if(pMEntregador[i][mVID] != vehicleid) continue;
        if(pMEntregador[i][IndoEntregar] == false) break;

        new id = pMEntregador[i][CasaEntregg];
        eMoveis[id][JaLevando] = false;
        eMoveis[id][MovelStatusPlayer] = 0;
        pMEntregador[i][IndoEntregar] = false;
        DestroyDynamicMapIconEx(pMEntregador[i][MapaEntrega]);
        DestroyDynamicCPEx(pMEntregador[i][CheckEntrega]);
        DestroyDynamic3DTextLabelEx(pMEntregador[i][EntregaTexto]); 

        SendClientMessage(i, 0xFFFF00FF, "| ENTREGA | Você danificou sem veículo e a entrega foi cancelada!");
        break;
    }
    return 1;
}

Dialog:EntregarCasa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new slot;
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(eMoveis[i][MoveisQuantidade] < 1) continue; 
        if(slot != listitem){
            slot++;
            continue;
        }
        if(eMoveis[i][JaLevando] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa entrega já está a caminho");
        if(!strcmp(pCasa[i][cDono], PegarNick(playerid), true)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode entregar para sua propria casa.");

        eMoveis[i][MovelStatusPlayer] = 1;
        eMoveis[i][JaLevando] = true;
        pMEntregador[playerid][CaixasVeeh] = 0;
        pMEntregador[playerid][SelecEntrega] = true;
        pMEntregador[playerid][CasaEntregg] = i; 
        pMEntregador[playerid][TemQEntrr] = eMoveis[i][MoveisQuantidade];
        SetPVarInt(playerid, "FASDASDSA", eMoveis[i][MoveisQuantidade]);

        MostrarCaixaEntregas(playerid);
        MarcarPosicao(playerid, -1716.3253, 1018.1722, 17.5859);
        AtualizarCaixaEntregas(playerid, 0, pMEntregador[playerid][TemQEntrr]);

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| ENTREGA | Você está indo até %s para entregar %d móveis", AreaNome(pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ]), eMoveis[i][MoveisQuantidade]);
        SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
        SendClientMessage(playerid, 0xFFFF00FF, "| ENTREGA | Vá até o ponto marcado no mapa para carregar.");

        new id = PegarIdPeloNick(pCasa[i][cDono]);
        if(IsPlayerConnected(id)){
            format(Mensagem, sizeof(Mensagem), "| LOJA DE MÓVEIS | %s[%d] está carregando os móveis para levar até sua casa", PegarNick(playerid), playerid);
            SendClientMessage(id, 0xFFFF00FF, Mensagem);
        }
        break;
    }

    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(AtrasVeiculo(playerid, pMEntregador[playerid][mVID], 2.0))
    {
        if(pMEntregador[playerid][SelecEntrega] == false) return 1;
        ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
        RemovePlayerAttachedObject(playerid, 9);
        pMEntregador[playerid][CaixaMaoTemp] = false;
        pMEntregador[playerid][CaixasVeeh]++;
        AtualizarCaixaEntregas(playerid, pMEntregador[playerid][CaixasVeeh], pMEntregador[playerid][TemQEntrr]); 
        if(pMEntregador[playerid][CaixasVeeh] >= pMEntregador[playerid][TemQEntrr])
        {
            new i = pMEntregador[playerid][CasaEntregg];
            pMEntregador[playerid][IndoEntregar] = true;
            pMEntregador[playerid][SelecEntrega] = false;

            DestroyDynamic3DTextLabelEx(pMEntregador[playerid][EntregaTexto]);
            pMEntregador[playerid][MapaEntrega] = CreateDynamicMapIcon(pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ], 51, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
            pMEntregador[playerid][CheckEntrega] = CreateDynamicCP(pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ], 1.0, 0, 0, playerid, 15.0, -1);

            new id = PegarIdPeloNick(pCasa[i][cDono]);
            if(IsPlayerConnected(id)){
                new Mensagem[128];
                format(Mensagem, sizeof(Mensagem), "| LOJA DE MÓVEIS | %s[%d] está levando os móveis até sua casa.", PegarNick(playerid), playerid);
                SendClientMessage(id, 0xFFFF00FF, Mensagem);
            }
        }

    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, -1716.3253,1018.1722,17.5859))
    {
        if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
        if(strcmp(Jogador[playerid][Profissao], "Entregador de Móveis")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        if(pMEntregador[playerid][IndoEntregar] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem uma entrega pendente, vá até o local marcado no mapa!");
        if(pMEntregador[playerid][SelecEntrega] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não selecionou nenhuma entrega");
        if(pMEntregador[playerid][CaixaMaoTemp] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está segurando uma caixa");
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
        SetPlayerAttachedObject(playerid, 9, 1220, 3, 0.1310, -0.4270, -0.1290, -7.3999, 3.4000, 29.9000, 0.5850, 0.5280, 0.6530, 0xFFFFFFFF, 0xFFFFFFFF);
        pMEntregador[playerid][CaixaMaoTemp] = true;
        if(pMEntregador[playerid][CaixasVeeh] == 0){
            pMEntregador[playerid][EntregaTexto] = CreateDynamic3DTextLabel("Caminhão{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para colocar", 0x00BFFFFF, 0.0000, -4.0999, -0.9000, 15.0, INVALID_PLAYER_ID, pMEntregador[playerid][mVID], 0, 0, 0, playerid, 20.0, -1);
        }
    }
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, -1731.8093,991.4303,17.5900))
    {
        if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
        if(strcmp(Jogador[playerid][Profissao], "Entregador de Móveis")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        if(pMEntregador[playerid][IndoEntregar] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem uma entrega pendente, vá até o local marcado no mapa!");
        if(pMEntregador[playerid][SelecEntrega] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está carregando seu caminhão");
        if(GetPVarInt(playerid, "DellalyA") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
        SetPVarInt(playerid, "DellalyA", gettime()+60);

        if(pMEntregador[playerid][mVAlugado] == false)
        {
            new i = random(sizeof(eSpawn)),
                rra = random(999);
            pMEntregador[playerid][mVID] = CreateVehicleEx(playerid, 609, eSpawn[i][EntregadorX], eSpawn[i][EntregadorY], eSpawn[i][EntregadorZ], eSpawn[i][EntregadorA], rra, rra, 560, 0);
            pMEntregador[playerid][mVAlugado] = true;
            Jogador[playerid][Trabalhando] = true;
            VeiculoServer[pMEntregador[playerid][mVID]][Tranca] = 1;
            MarcarPosicao(playerid, eSpawn[i][EntregadorX], eSpawn[i][EntregadorY], eSpawn[i][EntregadorZ]);
            SendClientMessage(playerid, 0xFFFF00FF, "| ENTREGADOR | Seu veículo foi colocado na vaga e marcado no mapa");
            return 1;
        }
        VerificarMarcacao(playerid);
        DestroyVehicleEx(pMEntregador[playerid][mVID]);
        pMEntregador[playerid][mVAlugado] = false;
        Jogador[playerid][Trabalhando] = false;
        SendClientMessage(playerid, 0xFFFF00FF, "| ENTREGADOR | Veículo devolvido com sucesso");
    }

    else if(IsPlayerInRangeOfPoint(playerid, 2.0, -1707.5701,1018.1252,17.5859))
    {
        if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
        if(strcmp(Jogador[playerid][Profissao], "Entregador de Móveis") && Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        if(pMEntregador[playerid][IndoEntregar] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem uma entrega pendente, vá até o local marcado no mapa!");
        if(pMEntregador[playerid][SelecEntrega] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está carregando seu caminhão");
        if(pMEntregador[playerid][mVAlugado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem um veículo alugado.");

        new Dialog[2000];
        strcat(Dialog, "Dono\tLocal\tMóveis\tStatus\n");
        for(new i=0; i < MAX_CASAS; i++) {
            if(pCasa[i][Colocado] == false) continue;
            if(eMoveis[i][MoveisQuantidade] < 1) continue; // MovelLevadPor
            if(eMoveis[i][MovelStatusPlayer] == 0) strcatEx(Dialog, "{FFFFFF}%s\t{00BFFF}%s{FFFFFF}\t%d\t%s\n", pCasa[i][cDono], AreaNome(pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ]), eMoveis[i][MoveisQuantidade], "{32CD32}Para Entregar");
            else if(eMoveis[i][MovelStatusPlayer] == 1) strcatEx(Dialog, "{FFFFFF}%s\t{00BFFF}%s{FFFFFF}\t%d\t%s\n", pCasa[i][cDono], AreaNome(pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ]), eMoveis[i][MoveisQuantidade], "{DAA520}A Caminho");
        }
        Dialog_Show(playerid, EntregarCasa, DIALOG_STYLE_TABLIST_HEADERS, "{7FFF00}Entregas", Dialog, "Selecionar", "Fechar");
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate != PLAYER_STATE_ONFOOT && oldstate != PLAYER_STATE_DRIVER) return 1;

    if(Jogador[playerid][uVeiculo] != pMEntregador[playerid][mVID]) return 1;
    if(pMEntregador[playerid][IndoEntregar] == false) return 1;
    new id = pMEntregador[playerid][CasaEntregg];
    if(!IsPlayerInRangeOfPoint(playerid, 90.0, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ])) return 1;
    if(GetPVarInt(playerid, "ASDDASDASASD") == 1) return 1;
    SetPVarInt(playerid, "ASDDASDASASD", 1);

    new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
    GetVehicleParamsEx(pMEntregador[playerid][mVID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
    SetVehicleParamsEx(pMEntregador[playerid][mVID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_ON, ob);  
    pMEntregador[playerid][EntregaTexto] = CreateDynamic3DTextLabel("Caminhão\n{FFFFFF}Aperte {CCCCCC}H{FFFFFF} para pegar as caixas", 0x00BFFFFF, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, pMEntregador[playerid][mVID], 0, 0, 0, playerid, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
    return 1;
}