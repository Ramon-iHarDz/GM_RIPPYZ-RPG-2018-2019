#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    for(new i=0; i < sizeof(TremS); i++){
        ETrem[i] = CreateVehicleEx(-1, 538, TremS[i][TSpawnX], TremS[i][TSpawnY], TremS[i][TSpawnZ], TremS[i][TSpawnA], 1, 1, 600, 0);
        VeiculoServer[ETrem[i]][VidaMaxima] = 20000;
        VeiculoServer[ETrem[i]][AntiRadar] = true;
        VeiculoServer[ETrem[i]][VeiculoRegenerar] = true;
        format(VeiculoServer[ETrem[i]][LocalVerificacao], 90, "TremVC");
        SetVehicleHealth(ETrem[i], VeiculoServer[ETrem[i]][VidaMaxima]);
    }   

    Estac[0] = CreateDynamicRectangle(1687.7552,-1961.6355, 1917.9542,-1943.6394, 0, 0, -1); // Los Santos
    Estac[1] = CreateDynamicRectangle(-1970.8846,210.2634, -1917.9143,-18.0874, 0, 0, -1); // San Fierro
    Estac[2] = CreateDynamicRectangle(1370.2808,2615.5935, 1528.5797,2666.9121, 0, 0, -1); // Las Venturas
    Estac[3] = CreateDynamicRectangle(2875.7444,1209.0770, 2841.3381,1348.0906, 0, 0, -1); // Las Venturas

    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid == Estac[0]) MostrarMensagemBaixo(playerid, ConverterTexto("~w~Estação de ~b~Los Santos"));
    else if(areaid == Estac[1]) MostrarMensagemBaixo(playerid, ConverterTexto("~w~Estação de ~b~San Fierro"));
    else if(areaid == Estac[2]) MostrarMensagemBaixo(playerid, ConverterTexto("~w~Estação de ~b~Las Venturas"));
    else if(areaid == Estac[3]) MostrarMensagemBaixo(playerid, ConverterTexto("~w~Estação de ~b~Las Venturas"));
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{   
    if(areaid == Estac[0] || areaid == Estac[1] || areaid == Estac[2] || areaid == Estac[3]) OcultarMensagemBaixo(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamicRaceCPEx(pTrem[playerid][TCP]);
    DestroyDynamicMapIconEx(pTrem[playerid][TIcon]);
    if(GetPVarInt(playerid, "TemAlgTrem") == 1) KillTimer(pTrem[playerid][TTempoT]);

    new DelataRRr[MaquinistaJogador];
    pTrem[playerid] = DelataRRr; 
    return 1;
}

hook OnPlayerEnterDynRaceCP(playerid, checkpointid)
{
    if(checkpointid != pTrem[playerid][TCP]) return 1;
    if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em um veículo");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(!VerificarTrem(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo um trem");
    if(GetVehicleSpeed(GetPlayerVehicleID(playerid)) > 15) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está parado!");

    TogglePlayerControllable(playerid, 0);
    SetPVarInt(playerid, "TemAlgTrem", 1);
    GameTextForPlayer(playerid, "~y~Desembarcando.", 6000, 4);
    pTrem[playerid][TTempoT] = SetTimerEx("ProximaParadaTrem", 6000, false, "dd", playerid, GetPVarInt(playerid, "TremEst"));
    return 1;
}

function TremVC(playerid, id)
{
    for(new i=0; i < sizeof(TremS); i++)
    {
        if(ETrem[i] != id) continue;
        if(strcmp(Jogador[playerid][Profissao], "Maquinista")){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            return false;
        }
    }
    return true;
}

function ProximaParadaTrem(playerid, est)
{
    TogglePlayerControllable(playerid, 1);
    SetPVarInt(playerid, "TemAlgTrem", 0);

    if(est == 0)
    {
        SetPVarInt(playerid, "TremEst", 1);
        GameTextForPlayer(playerid, "~g~Embarcado.", 3000, 4);
        pTrem[playerid][TIcon] = CreateDynamicMapIcon(-1943.6306,149.0243,25.7109, 57, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
        pTrem[playerid][TCP] = CreateDynamicRaceCP(0, -1943.6306,149.0243,25.7109, 0.0, 0.0, 0.0, 2.0, 0, 0, playerid, 150.0, -1);
        SendClientMessage(playerid, 0xFFFF00FF, "| MAQUINISTA | Você precisa desembarcar passageiros(as) na estação de San Fierro");
    }
    else if(est == 1)
    {
        SetPVarInt(playerid, "TremEst", 2);
        GameTextForPlayer(playerid, "~g~Desembarcado.", 3000, 4);
        DestroyDynamicRaceCPEx(pTrem[playerid][TCP]);
        DestroyDynamicMapIconEx(pTrem[playerid][TIcon]);
        pTrem[playerid][TIcon] = CreateDynamicMapIcon(1420.3221,2632.3452,10.8203, 57, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
        pTrem[playerid][TCP] = CreateDynamicRaceCP(0, 1420.3221,2632.3452,10.8203, 0.0, 0.0, 0.0, 2.0, 0, 0, playerid, 150.0, -1);
        SendClientMessage(playerid, 0xFFFF00FF, "| MAQUINISTA | Você precisa desembarcar passageiros(as) na estação de Las Venturas");
    }
    else if(est == 2)
    {
        SetPVarInt(playerid, "TremEst", 3);
        GameTextForPlayer(playerid, "~g~Desembarcado.", 3000, 4);
        DestroyDynamicRaceCPEx(pTrem[playerid][TCP]);
        DestroyDynamicMapIconEx(pTrem[playerid][TIcon]);
        pTrem[playerid][TIcon] = CreateDynamicMapIcon(2864.8235,1292.0789,10.8203, 57, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
        pTrem[playerid][TCP] = CreateDynamicRaceCP(0, 2864.8235,1292.0789,10.8203, 0.0, 0.0, 0.0, 2.0, 0, 0, playerid, 150.0, -1);
        SendClientMessage(playerid, 0xFFFF00FF, "| MAQUINISTA | Você precisa desembarcar passageiros(as) na próxima estação de Las Venturas");
    }
    else if(est == 3)
    {
        new Mensagem[128],
            Dinheirada = random(3500-3000)+3000;
        Jogador[playerid][Dinheiro] += Dinheirada;
        Jogador[playerid][Trabalhando] = false;
        format(Mensagem, sizeof(Mensagem), "| MAQUINISTA | Você passou em todas as estações e recebeu {32CD32}$%s", DinheiroSeparar(Dinheirada));
        SendClientMessage(playerid, -1, Mensagem);
        DestroyDynamicRaceCPEx(pTrem[playerid][TCP]);
        DestroyDynamicMapIconEx(pTrem[playerid][TIcon]);
        SetPVarInt(playerid, "TremEst", 0);
        SetPVarInt(playerid, "Alasdl", 0);
    }


    return 1;
}

stock VerificarTrem(vehicleid)
{
    for(new i=0; i < sizeof(TremS); i++){
        if(ETrem[i] != vehicleid) continue;
        return true;
    }
    return false;
}

CMD:estacao(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Maquinista")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em um veículo");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(!VerificarTrem(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo um trem");
    if(pTrem[playerid][TIni] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já ainda não finalizou o serviço");
    if(!IsPlayerInDynamicArea(playerid, Estac[0])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na estação de Los Santos");
    if(GetVehicleSpeed(GetPlayerVehicleID(playerid)) > 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa está parado para carregar!");
    if(GetPVarInt(playerid, "Alasdl") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já iniciou");

    Jogador[playerid][Trabalhando] = true;
    TogglePlayerControllable(playerid, 0);
    SetPVarInt(playerid, "TremEst", 0);
    SetPVarInt(playerid, "TemAlgTrem", 1);
    SetPVarInt(playerid, "Alasdl", 1);
    GameTextForPlayer(playerid, "~y~Aguarde.", 6000, 4);
    pTrem[playerid][TTempoT] = SetTimerEx("ProximaParadaTrem", 6000, false, "dd", playerid, GetPVarInt(playerid, "TremEst"));
    return 1;
}