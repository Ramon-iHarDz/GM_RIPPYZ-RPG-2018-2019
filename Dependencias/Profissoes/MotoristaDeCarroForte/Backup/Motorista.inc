#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    for(new i=0; i < sizeof(CFSpawn); i++){
        CarroF[i] = CreateVehicleEx(-1, 428, CFSpawn[i][FSpawnX], CFSpawn[i][FSpawnY], CFSpawn[i][FSpawnZ], CFSpawn[i][FSpawnA], 1, 2, 360, 0);
        VeiculoServer[CarroF[i]][AntiFurar] = true;
        VeiculoServer[CarroF[i]][VeiculoRegenerar] = true;
        VeiculoServer[CarroF[i]][VidaMaxima] = 15000; 
        format(VeiculoServer[CarroF[i]][LocalVerificacao], 90, "CarroForteVeh"); 
        SetVehicleHealth(CarroF[i], VeiculoServer[CarroF[i]][VidaMaxima]);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "TempCf") == 1) KillTimer(pCF[playerid][CFTempo]);
    DestroyDynamicRaceCPEx(pCF[playerid][CPCaixa]);
    DestroyDynamicRaceCPEx(pCF[playerid][CPBanco]);
    DestroyDynamicMapIconEx(pCF[playerid][CFIcone]);
    DestroyDynamic3DTextLabelEx(pCF[playerid][CFTextoID]);

    new DelataRRr[CarroForteJogador];
    pCF[playerid] = DelataRRr; 
    return 1;
}

function CarroForteVeh(playerid, vehicleid)
{
    if(Jogador[playerid][Admin] > 2) return true;
    if(strcmp(Jogador[playerid][Profissao], "Motorista de Carro Forte")){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é Motorista de Carro Forte");
        return false;
    }
    if(Jogador[playerid][Estrelas] > 0){
        if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            return false;
        }
    }
    return true;
}

Dialog:SelecionarBancooH(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new Kabbie[60],
        Dialog[1500],
        Float:Kjal[3],
        Float:Diss
    ;
    switch(listitem)
    {
        case 0:
        {
            Kabbie = "Los Santos";
            Kjal[0] = 596.7069;
            Kjal[1] = -1287.5359;
            Kjal[2] = 15.6685;
        }
        case 1:
        {
            Kabbie = "San Fierro";
            Kjal[0] = -2660.4138;
            Kjal[1] = 375.7323;
            Kjal[2] = 4.1390;
        }
        case 2:
        {
            Kabbie = "Las Venturas";
            Kjal[0] = 2370.0889;
            Kjal[1] = 2470.1936;
            Kjal[2] = 10.6719;
        }
    }

    strcat(Dialog, "Local\tDistância\tPreço\n");
    for(new i=0; i < MAX_CAIXAS; i++){
        if(pCaixa[i][Conectado] == false) continue;
        if(strcmp(PegarCidade(pCaixa[i][PosicaoX], pCaixa[i][PosicaoY]), Kabbie)) continue;
        Diss = GetDistanceBetweenPoints(pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ], Kjal[0], Kjal[1], Kjal[2]);
        strcatEx(Dialog, "{FFFFFF}%s\t{00BFFF}%0.2f\t{32CD32}$%s\n", AreaNome(pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ]), Diss, DinheiroSeparar(DistanciaValor(Diss, 2, 4)));
    }

    SetPVarInt(playerid, "LocalCRSF", listitem);
    Dialog_Show(playerid, CarregamentoCF, DIALOG_STYLE_TABLIST_HEADERS, Kabbie, Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:CarregamentoCF(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new Slas = 0,
        Kabbie[60],
        Float:Kjal[3]
    ;
    
    switch(GetPVarInt(playerid, "LocalCRSF"))
    {
        case 0:
        {
            Kabbie = "Los Santos";
            Kjal[0] = 596.7069;
            Kjal[1] = -1287.5359;
            Kjal[2] = 15.6685;
        }
        case 1:
        {
            Kabbie = "San Fierro";
            Kjal[0] = -2660.4138;
            Kjal[1] = 375.7323;
            Kjal[2] = 4.1390;
        }
        case 2:
        {
            Kabbie = "Las Venturas";
            Kjal[0] = 2370.0889;
            Kjal[1] = 2470.1936;
            Kjal[2] = 10.6719;
        }
    }

    for(new i=0; i < MAX_CAIXAS; i++)
    {
        if(pCaixa[i][Conectado] == false) continue;
        if(strcmp(PegarCidade(pCaixa[i][PosicaoX], pCaixa[i][PosicaoY]), Kabbie)) continue;
        if(listitem != Slas){
            Slas++;
            continue;
        }

        new Mensagem[128];
        new Float:Diss = GetDistanceBetweenPoints(pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ], Kjal[0], Kjal[1], Kjal[2]);
        pCF[playerid][CarregandoCF] = 1;
        pCF[playerid][CFPreco] = DistanciaValor(Diss, 2, 4);
        pCF[playerid][CFID] = GetPlayerVehicleID(playerid);
        pCF[playerid][CFCaixa] = i;

        pCF[playerid][CPBanco] = CreateDynamicRaceCP(1, Kjal[0], Kjal[1], Kjal[2], 0.0, 0.0, 0.0, 1.0, 0, 0, playerid, 90.0, -1);
        pCF[playerid][CFIcone] = CreateDynamicMapIcon(Kjal[0], Kjal[1], Kjal[2], 52, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);

        Jogador[playerid][Trabalhando] = true;

        format(Mensagem, sizeof(Mensagem), "| BANCO | Você precisa ir no banco de %s para carregar", Kabbie);
        SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
        break;
    }

    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_ONFOOT)
    {
        if(GetPVarInt(playerid, "Carff") == 0) return 1;
        if(!VerificarCarroForte(Jogador[playerid][uVeiculo])) return 1;
        new i = pCF[playerid][CaixaIDCF];
        if(!IsPlayerInRangeOfPoint(playerid, 30.0, pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ])) return 1;
        pCF[playerid][CFTexto] = true;
        pCF[playerid][CFTextoID] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'Y'{FFFFFF} para pegar a maleta", -1, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, Jogador[playerid][uVeiculo], 0, 0, 0, playerid, 25.0, -1);
    }

    else if(oldstate == PLAYER_STATE_ONFOOT)
    {
        if(pCF[playerid][CFTexto] == false) return 1;
        DestroyDynamic3DTextLabelEx(pCF[playerid][CFTextoID]);
        pCF[playerid][CFTexto] = false;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(pCF[playerid][CFTexto] == false) return 1;
        if(pCF[playerid][CFMaleta] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já pegou a maleta");
        if(!AtrasVeiculo(playerid, pCF[playerid][CFID], 2.0)) return 1;

        new i = pCF[playerid][CaixaIDCF];
        if(!IsPlayerInRangeOfPoint(playerid, 30.0, pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto do caixa eletrônico");
        
        pCF[playerid][CFMaleta] = true;
        SetPlayerAttachedObject(playerid, 9, 11745, 1, 0.0729, -0.1270, -0.0079, 77.5999, 159.6999, 29.3999, 0.8590, 0.7560, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); 
    }
    return 1;
}

hook OnPlayerEnterDynRaceCP(playerid, checkpointid)
{
    if(checkpointid == pCF[playerid][CPBanco])
    {
        if(GetPVarInt(playerid, "TempCf") == 1) return 1;
        if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em um veículo");
        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa está dirigindo");
        if(!VerificarCarroForte(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo um carro forte");
        TogglePlayerControllable(playerid, 0);
        SetPVarInt(playerid, "TempCf", 1);
        pCF[playerid][CFTempo] = SetTimerEx("GerarCaixa", 6000, false, "d", playerid);
        GameTextForPlayer(playerid, "~y~Carregando, aguarde.", 6000, 4);
    }
    
    else if(checkpointid == pCF[playerid][CPCaixa])
    {
        if(GetPVarInt(playerid, "TempCf") == 1) return 1;
        if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa descer do veículo");
        if(pCF[playerid][CFMaleta] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Vá atrás do seu veículo e pegue a maleta");
        TogglePlayerControllable(playerid, 0);
        SetPVarInt(playerid, "TempCf", 1);
        pCF[playerid][CFTempo] = SetTimerEx("EntregarCaixaCF", 6000, false, "d", playerid);
        GameTextForPlayer(playerid, "~y~Descarregando, aguarde.", 6000, 4);
    }
    return 1;
}

function GerarCaixa(playerid)
{
    GameTextForPlayer(playerid, "~g~Carregado!", 4000, 4);
    SetPVarInt(playerid, "TempCf", 0);
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicMapIconEx(pCF[playerid][CFIcone]);
    DestroyDynamicRaceCPEx(pCF[playerid][CPBanco]);

    new i = pCF[playerid][CFCaixa],
        Mensagem[128]
    ;

    format(Mensagem, sizeof(Mensagem), "| MÁFIA | O(A) Jogador(a) %s[%d] está transportando uma carga.", PegarNick(playerid), playerid);
    for(new d=0; d < MAX_PLAYERS; d++)
    {
        if(!IsPlayerConnected(d)) continue;
        if(Jogador[d][Logado] == false) continue;
        if(strcmp(Jogador[d][Profissao], "Assaltante")) continue;
        SendClientMessage(d, -1, Mensagem);
    }

    SetPVarInt(playerid, "Carff", 1);
    pCF[playerid][CaixaIDCF] = i;
    pCF[playerid][CPCaixa] = CreateDynamicRaceCP(0, pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ], 0.0, 0.0, 0.0, 2.0, 0, 0, playerid, 90.0, -1);
    pCF[playerid][CFIcone] = CreateDynamicMapIcon(pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ], 52, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);

    format(Mensagem, sizeof(Mensagem), "| BANCO | Você carregou seu carro forte para %s", AreaNome(pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ]));
    SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
    return 1;
}

function EntregarCaixaCF(playerid)
{
    GameTextForPlayer(playerid, "~g~Descarregado!", 4000, 4);
    SetPVarInt(playerid, "TempCf", 0);
    SetPVarInt(playerid, "Carff", 0);
    SetPVarInt(playerid, "AguardarTempoCarg", gettime()+180);
    pCF[playerid][CarregandoCF] = 0;
    Jogador[playerid][Trabalhando] = false;
    pCF[playerid][CFMaleta] = false;
    RemovePlayerAttachedObject(playerid, 9);
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicMapIconEx(pCF[playerid][CFIcone]);
    DestroyDynamicRaceCPEx(pCF[playerid][CPCaixa]);
    if(pCF[playerid][CFTexto] == true){
        DestroyDynamic3DTextLabelEx(pCF[playerid][CFTextoID]);
        pCF[playerid][CFTexto] = false;
    }

    new i = pCF[playerid][CFPreco],
        Mensagem[128]
    ;
    Jogador[playerid][Dinheiro] += i;
    format(Mensagem, sizeof(Mensagem), "| BANCO | Você entregou o malote no caixa e recebeu {32CD32}$%s", DinheiroSeparar(i));
    SendClientMessage(playerid, -1, Mensagem);

    return 1;
}

CMD:carregar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Motorista de Carro Forte")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
    if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em um veículo");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(!VerificarCarroForte(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo um carro forte");
    if(pCF[playerid][CarregandoCF] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não acabou o serviço!");
    if(VerificarCarregandoCF(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você nãa pode usar esse Carro Forte");
    if(GetPVarInt(playerid, "AguardarTempoCarg") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa aguardar um pouco.");

    new Dialog[128];
    strcat(Dialog, "Los Santos\n");
    strcat(Dialog, "San Fierro\n");
    strcat(Dialog, "Las Venturas");
    Dialog_Show(playerid, SelecionarBancooH, DIALOG_STYLE_TABLIST, "{FF0000}Selecione um Banco", Dialog, "Selecionar", "Fechar");
    return 1;
}