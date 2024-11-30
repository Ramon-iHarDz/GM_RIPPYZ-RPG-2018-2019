#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicPickup(1239, 1, -2521.1218,-624.6491,132.7830, 0, 0, -1, 90.0);
    CreateDynamic3DTextLabel("{FFFF00}Meteorologista{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para entrar", -1, -2521.1218,-624.6491,132.7830, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);
    
    CreateDynamicPickup(1239, 1, -2489.2190,-603.9090,132.6239, 0, 0, -1, 90.0);
    CreateDynamic3DTextLabel("{00BFFF}Meteorologista{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, -2489.2190,-603.9090,132.6239, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);
    
    CreateDynamic3DTextLabel("{00BFFF}Satélite{FFFFFF}\nUse {CCCCCC}/AtivarSatelite", -1, -951.9061,1911.1409,5.0734, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 341, 17, -1, 15.0, -1);
    
    CreateDynamicPickup(1239, 1, -959.7164,1953.4796,9.0000, 341, 17, -1, 90.0);
    CreateDynamic3DTextLabel("{FFFF00}Meteorologista{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para sair", -1, -959.7164,1953.4796,9.0000, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 341, 17, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pMeteo[playerid][Ativandoslt] == true) KillTimer(pMeteo[playerid][SltTempo]);
    if(pMeteo[playerid][CarregarDados] == true) KillTimer(pMeteo[playerid][CrDados]);
    if(pMeteo[playerid][MeteoAlugado] == true) DestroyVehicleEx(pMeteo[playerid][MeteoID]);
    if(pMeteo[playerid][MMaleta] == true) RemovePlayerAttachedObject(playerid, 9);

    DestroyDynamic3DTextLabelEx(pMeteo[playerid][MeteoTextoID]);
    DestroyDynamicMapIconEx(pMeteo[playerid][MeteoIconID]);
    DestroyDynamic3DTextLabelEx(pMeteo[playerid][MaletaInn]);

    new LimpezaaH[MeteoroJogador];
    pMeteo[playerid] = LimpezaaH;

    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        // Dentro do Local
        if(IsPlayerInRangeOfPoint(playerid, 3.0, -959.7164,1953.4796,9.0000))
        {
            if(Jogador[playerid][uInteriorEx] != 341) return 1;
            if(GetPlayerInterior(playerid) != 17 || GetPlayerVirtualWorld(playerid) != 341) return 1;
            Jogador[playerid][uInteriorEx] = 0;
            SetPlayerInterior(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerPos(playerid, -2521.1218,-624.6491,132.7830);
        }

        // Local de Fora
        else if(IsPlayerInRangeOfPoint(playerid, 3.0, -2521.1218,-624.6491,132.7830))
        {
            
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            // if(strcmp(Jogador[playerid][Profissao], "Meteorologista") && Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            // if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            Jogador[playerid][uInteriorEx] = 341;
            GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
            SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);

            SetPlayerInterior(playerid, 17);
            SetPlayerVirtualWorld(playerid, 341);
            SetPlayerPos(playerid, -959.7164,1953.4796,9.0000); 
        }
    }
    else if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) 
    {
        // Alugar
        if(IsPlayerInRangeOfPoint(playerid, 3.0, -2489.2190,-603.9090,132.6239))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Meteorologista")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");

            if(pMeteo[playerid][Ativandoslt] == true || 
            pMeteo[playerid][CarregandoDados] == true ||
            pMeteo[playerid][EntregaRelatorio] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa concluir os serviços");

            if(GetPVarInt(playerid, "MetroAdELAY") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            SetPVarInt(playerid, "MetroAdELAY", gettime()+15);
            if(pMeteo[playerid][MeteoAlugado] == false)
            {
                if(Jogador[playerid][CarteiraB] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar um carro ( Habilitação: B )");
                new rda = random(sizeof(MetroVeiculo));
                pMeteo[playerid][MeteoID] = CreateVehicleEx(playerid, 582, MetroVeiculo[rda][MeteoX], MetroVeiculo[rda][MeteoY], MetroVeiculo[rda][MeteoZ], MetroVeiculo[rda][MeteoA], 1, 2, -1, 0);
                MarcarPosicao(playerid, MetroVeiculo[rda][MeteoX], MetroVeiculo[rda][MeteoY], MetroVeiculo[rda][MeteoZ]);
                VeiculoServer[pMeteo[playerid][MeteoID]][Tranca] = 1;
                Jogador[playerid][Trabalhando] = true;
                pMeteo[playerid][MeteoAlugado] = true;
                SendClientMessage(playerid, 0xFFFF00FF, "| METEOROLOGISTA | Veículo alugado com sucesso!");
                return 1;
            }
            Jogador[playerid][Trabalhando] = false;
            pMeteo[playerid][MeteoAlugado] = false;
            VerificarMarcacao(playerid);
            DestroyVehicleEx(pMeteo[playerid][MeteoID]);
            SendClientMessage(playerid, 0xFFFF00FF, "| METEOROLOGISTA | Veículo devolvido com sucesso!");
        }

        else if(IsPlayerInRangeOfPoint(playerid, 3.0, -940.0644,1913.3827,5.0051))
        {
            if(GetPlayerInterior(playerid) != 17 || GetPlayerVirtualWorld(playerid) != 341) return 1;
            if(pMeteo[playerid][EntregaRelatorio] == false) return 1;
            new Mensagem[200],
                VlrA = random(2200-1400)+1400;
            DestroyDynamic3DTextLabelEx(pMeteo[playerid][MeteoTextoID]);
            DestroyDynamicMapIconEx(pMeteo[playerid][MeteoIconID]);
            pMeteo[playerid][EntregaRelatorio] = false;
            Jogador[playerid][Dinheiro] += VlrA;
            format(Mensagem, sizeof(Mensagem), "| METEOROLOGISTA | Você entregou o relátorio do satélite {00FA9A}%d{FFFFFF} e recebeu {32CD32}$%s", random(360), DinheiroSeparar(VlrA));
            SendClientMessage(playerid, -1, Mensagem);
        }

    }

    else if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(AtrasVeiculo(playerid, pMeteo[playerid][MeteoID], 4.0))
        {
            if(pMeteo[playerid][MMaleta] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já pegou uma maleta!");
            pMeteo[playerid][MMaleta] = true;
            SetPlayerAttachedObject(playerid, 9, 19921, 5, 0.0220, 0.0010, 0.0059, -125.2999, -10.2999, -103.7999, 0.7490, 0.6630, 0.7380, 0xFF4C75B7, 0xFF9F9D94); 
        }
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_ONFOOT && oldstate == PLAYER_STATE_DRIVER)
    {
        if(pMeteo[playerid][CarregandoDados] == false) return 1;
        new id = pMeteo[playerid][AntenaID];
        if(!IsPlayerInRangeOfPoint(playerid, 50.0, AntenaLOC[id][AntenaX], AntenaLOC[id][AntenaY], AntenaLOC[id][AntenaZ])) return 1;
        if(pMeteo[playerid][AbertoAtras] == true) return 1;
        pMeteo[playerid][AbertoAtras] = true;
        pMeteo[playerid][MaletaInn] = CreateDynamic3DTextLabel("Aperte 'H' para pegar a maleta", -1, 0.0000, -4.0999, -0.9000, 15.0, INVALID_PLAYER_ID, pMeteo[playerid][MeteoID], 0, 0, -1, playerid, 15.0, -1);
    }

    else if(newstate == PLAYER_STATE_DRIVER)
    {
        if(pMeteo[playerid][AbertoAtras] == false) return 1;
        pMeteo[playerid][AbertoAtras] = false;
        DestroyDynamic3DTextLabelEx(pMeteo[playerid][MaletaInn]);
        if(pMeteo[playerid][MMaleta] == true){
            pMeteo[playerid][MMaleta] = false;
            RemovePlayerAttachedObject(playerid, 9);
        }
    }
    return 1;
}

function AtivandoSatelitePR(playerid)
{
    new rda = random(sizeof(AntenaLOC)),
        Mensagem[260];

    // Valores
    pMeteo[playerid][CarregandoDados] = true;
    pMeteo[playerid][Ativandoslt] = false;

    pMeteo[playerid][AntenaID] = rda;

    format(Mensagem, sizeof(Mensagem), "Antena de {7CFC00}%s{FFFFFF}\nUse: {CCCCCC}/CarregarDados", AreaNome(AntenaLOC[rda][AntenaX], AntenaLOC[rda][AntenaY], AntenaLOC[rda][AntenaZ]));
    pMeteo[playerid][MeteoTextoID] = CreateDynamic3DTextLabel(Mensagem, -1, AntenaLOC[rda][AntenaX], AntenaLOC[rda][AntenaY], AntenaLOC[rda][AntenaZ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, playerid, 15.0, -1);
    pMeteo[playerid][MeteoIconID] = CreateDynamicMapIcon(AntenaLOC[rda][AntenaX], AntenaLOC[rda][AntenaY], AntenaLOC[rda][AntenaZ], 27, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);

    GameTextForPlayer(playerid, "", 500, 4);
    TogglePlayerControllable(playerid, 1);

    format(Mensagem, sizeof(Mensagem), "| METEOROLOGISTA | Vá até a antena localizada em {00BFFF}%s{FFFFFF} e carregue os dados. Saia de dentro da HQ", AreaNome(AntenaLOC[rda][AntenaX], AntenaLOC[rda][AntenaY], AntenaLOC[rda][AntenaZ]));
    SendClientMessage(playerid, -1, Mensagem);

    return 1;
}

function CarregandoDadosPR(playerid)
{
    new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
    pMeteo[playerid][CarregandoDados] = false;
    pMeteo[playerid][CarregarDados] = false;
    pMeteo[playerid][EntregaRelatorio] = true;
    pMeteo[playerid][AbertoAtras] = false;
    pMeteo[playerid][MMaleta] = false;
    DestroyDynamic3DTextLabelEx(pMeteo[playerid][MeteoTextoID]);
    DestroyDynamicMapIconEx(pMeteo[playerid][MeteoIconID]);
    DestroyDynamic3DTextLabelEx(pMeteo[playerid][MaletaInn]);
    RemovePlayerAttachedObject(playerid, 9);
        
    GetVehicleParamsEx(pMeteo[playerid][MeteoID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
    if(portamalas == VEHICLE_PARAMS_ON) SetVehicleParamsEx(pMeteo[playerid][MeteoID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_OFF, ob); 

    pMeteo[playerid][MeteoIconID] = CreateDynamicMapIcon(-2521.1218,-624.6491,132.7830, 19, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
    pMeteo[playerid][MeteoTextoID] = CreateDynamic3DTextLabel("{00BFFF}Entrega de Relátorio{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para entregar o relátorio", -1, -940.0644,1913.3827,5.0051, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 341, 17, playerid, 15.0, -1);

    GameTextForPlayer(playerid, "", 500, 4);
    TogglePlayerControllable(playerid, 1);
    SendClientMessage(playerid, 0xFFFF00FF, "| METEOROLOGISTA | Vá dentro da sua HQ para entregar o relátorio");
    return 1;
}

CMD:ativarsatelite(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Meteorologista")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, -951.9061,1911.1409,5.0734)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Para ativar entre na sua HQ e vá até o satélite");
    if(GetPlayerInterior(playerid) != 17 || GetPlayerVirtualWorld(playerid) != 341) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Para ativar entre na sua HQ e vá até o satélite");
    if(pMeteo[playerid][MeteoAlugado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa alugar um veículo!");
    if(pMeteo[playerid][Ativandoslt] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está ativando o satélite, aguarde!");
    if(pMeteo[playerid][CarregandoDados] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa ir até a antena!");
    if(pMeteo[playerid][EntregaRelatorio] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não entregou o relátorio!");
    pMeteo[playerid][Ativandoslt] = true;
    TogglePlayerControllable(playerid, 0);
    pMeteo[playerid][SltTempo] = SetTimerEx("AtivandoSatelitePR", 8000, false, "d", playerid);
    GameTextForPlayer(playerid, "~y~Aguarde", 7000, 4);
    SendClientMessage(playerid, 0xFFFF00FF, "| METEOROLOGISTA | Você está ativando o satélite, aguarde.");
    return 1;
}

CMD:carregardados(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Meteorologista")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pMeteo[playerid][CarregandoDados] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não precisa carregar dados em nenhuma antena!");

    new id = pMeteo[playerid][AntenaID];
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, AntenaLOC[id][AntenaX], AntenaLOC[id][AntenaY], AntenaLOC[id][AntenaZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na antena");

    new Float:Ain[3];
    GetPlayerPos(playerid, Ain[0], Ain[1], Ain[2]);
    if(!IsVehicleInRangeOfPoint(pMeteo[playerid][MeteoID], 60.0, Ain[0], Ain[1], Ain[2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo está muito longe de você!");
    
    if(pMeteo[playerid][AbertoAtras] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Porta malas não está aberto, tente entrar no veículo e sair novamente");
    if(pMeteo[playerid][MMaleta] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Pegue a maleta de reparos atrás do seu veículo");
    if(pMeteo[playerid][CarregarDados] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está carregando dados, aguarde!");
    pMeteo[playerid][CarregarDados] = true;
    TogglePlayerControllable(playerid, 0);
    pMeteo[playerid][CrDados] = SetTimerEx("CarregandoDadosPR", 10000, false, "d", playerid);
    GameTextForPlayer(playerid, "~y~Aguarde", 9000, 4);
    SendClientMessage(playerid, 0xFFFF00FF, "| METEOROLOGISTA | Você está carregando os dados, aguarde.");
    return 1;
}