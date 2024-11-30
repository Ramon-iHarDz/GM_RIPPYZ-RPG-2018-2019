enum DerbySpawnInfo
{
    Float:DSpawnX,
    Float:DSpawnY,
    Float:DSpawnZ,
    Float:DSpawnA
};

enum DerbyInfo
{
    bool:SlotEntou,
    SlotJogadorID,
    DerbyVeiculoID
};

new DerbySpawn[][DerbySpawnInfo] =
{
    {-1486.5610,952.0186,1036.6833,326.9536},
    {-1491.7290,955.6504,1036.7468,311.9899},
    {-1496.3754,960.1980,1036.8312,304.9651},
    {-1500.2256,964.6288,1036.8986,302.7606},
    {-1504.2156,970.1628,1037.0763,303.7272},
    {-1507.8496,975.0685,1037.0958,295.3932},
    {-1510.6713,980.4313,1037.2142,288.9514},
    {-1513.1956,988.0545,1037.3265,275.0326},
    {-1513.8180,993.5978,1037.4222,274.7174},
    {-1513.4828,999.3591,1037.5105,267.3317},
    {-1512.3906,1004.8309,1037.5907,258.9505},
    {-1510.9839,1010.0699,1037.6825,252.1527},
    {-1508.7103,1014.8188,1037.7573,246.6054},
    {-1506.2296,1019.5723,1037.8337,241.8651},
    {-1503.4209,1024.3356,1037.9053,233.9848},
    {-1499.9565,1028.5569,1037.9723,227.4413},
    {-1496.1072,1032.0194,1038.0228,222.9878},
    {-1361.1832,934.0104,1036.1445,5.2687},
    {-1352.3638,936.1123,1036.1733,8.0829},
    {-1345.3812,938.1346,1036.1395,11.6883},
    {-1339.1626,939.8125,1036.1967,16.2591},
    {-1332.3835,942.4058,1036.2473,22.7045},
    {-1326.1945,944.4307,1036.2697,21.9657},
    {-1320.3373,947.7461,1036.3142,27.6110},
    {-1314.7146,950.1328,1036.3418,30.7987},
    {-1310.1111,953.3616,1036.3883,31.4220},
    {-1304.5156,957.6652,1036.4471,38.2207},
    {-1298.8225,962.1540,1036.5155,43.3304},
    {-1294.2183,967.6509,1036.5858,54.5380},
    {-1291.2013,971.9546,1036.6724,63.1877}
};

new pDerby[sizeof(DerbySpawn)][DerbyInfo];

stock EntrarDerby(playerid)
{
    new bool:kja = false;

    for(new i=0; i < sizeof(DerbySpawn); i++){
        if(pDerby[i][SlotEntou] == false) continue; 
        if(pDerby[i][SlotJogadorID] == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está esse modo de jogo!");
    }

    for(new i=0; i < sizeof(DerbySpawn); i++)
    {
        if(pDerby[i][SlotEntou] == true) continue;
        pDerby[i][SlotEntou] = true;
        pDerby[i][SlotJogadorID] = playerid;

        SetPVarInt(playerid, "ProibidoReparo", 1);

        pDerby[i][DerbyVeiculoID] = CreateVehicleEx(playerid, 504, DerbySpawn[i][DSpawnX], DerbySpawn[i][DSpawnY], DerbySpawn[i][DSpawnZ], DerbySpawn[i][DSpawnA], random(360), random(360), -1, 0);
        cAC[playerid][VeiculoPermitido] = pDerby[i][DerbyVeiculoID];
        LinkVehicleToInterior(pDerby[i][DerbyVeiculoID], 15);
        SetVehicleVirtualWorld(pDerby[i][DerbyVeiculoID], 2020);

        Jogador[playerid][uInteriorEx] = 2144;
        SetPVarInt(playerid, "Jasdsa", 0);
        GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
        SetPlayerInterior(playerid, 15);
        SetPlayerVirtualWorld(playerid, 2020);
        SetPlayerPos(playerid, DerbySpawn[i][DSpawnX], DerbySpawn[i][DSpawnY], DerbySpawn[i][DSpawnZ]);
        PutPlayerInVehicle(playerid, pDerby[i][DerbyVeiculoID], 0);
        TogglePlayerControllable(playerid, 0);
        PlayerPlaySound(playerid, 1062, 0.0, 0.0, 0.0);
        SetTimerEx("VerificarDerby", 1000, false, "dd", playerid, i);
        kja = true;
        break;   
    }
    if(kja == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais espaço nesse evento!");
    return 1;
}

stock PrepararDerby()
{
    for(new i=0; i < sizeof(DerbySpawn); i++)
    {
        pDerby[i][SlotEntou] = false;
    }
    return 1;
}

stock IniciarDerby()
{
    for(new i=0; i < sizeof(DerbySpawn); i++)
    {
        if(pDerby[i][SlotEntou] == false) continue;   
        if(!IsPlayerConnected(pDerby[i][SlotJogadorID])) continue;
        TogglePlayerControllable(pDerby[i][SlotJogadorID], 1);
        GameTextForPlayer(pDerby[i][SlotJogadorID], "~g~Evento Iniciado", 5000, 4);
        PlayerPlaySound(pDerby[i][SlotJogadorID], 1057, 0.0, 0.0, 0.0);
    }
    return 1;
}

stock ResetarDerby()
{
    for(new i=0; i < sizeof(DerbySpawn); i++)
    {
        if(pDerby[i][SlotEntou] == false) continue;
        pDerby[i][SlotEntou] = false;
        if(!IsPlayerConnected(pDerby[i][SlotJogadorID])) continue;
        DestroyVehicleEx(pDerby[i][DerbyVeiculoID]);
        Jogador[pDerby[i][SlotJogadorID]][uInteriorEx] = 0;
        SetPlayerVirtualWorld(pDerby[i][SlotJogadorID], 0);
        SetPlayerInterior(pDerby[i][SlotJogadorID], 0);
        PlayerPlaySound(pDerby[i][SlotJogadorID], 0, 0.0, 0.0, 0.0);
        TogglePlayerControllable(pDerby[i][SlotJogadorID], 1);
        SetPlayerPos(pDerby[i][SlotJogadorID], Jogador[pDerby[i][SlotJogadorID]][uInteriorExP][0], Jogador[pDerby[i][SlotJogadorID]][uInteriorExP][1], Jogador[pDerby[i][SlotJogadorID]][uInteriorExP][2]);
    }
    return 1;
}

function VerificarDerby(playerid, id)
{
    if(!IsPlayerConnected(playerid)){
        pDerby[id][SlotEntou] = false;
        DestroyVehicleEx(pDerby[id][DerbyVeiculoID]);
        return 1;
    }
    if(pDerby[id][SlotEntou] == false) return 1;

    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) return SetTimerEx("VerificarDerby", 1000, false, "dd", playerid, id);
    if(EventoEstado != 2) return SetTimerEx("VerificarDerby", 1000, false, "dd", playerid, id);
    
    pDerby[id][SlotEntou] = false;
    SetPVarInt(playerid, "ProibidoReparo", 0);
    DestroyVehicleEx(pDerby[id][DerbyVeiculoID]);
    Jogador[playerid][uInteriorEx] = 0;
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 0);
    PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
    SetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
    SendClientMessage(playerid, 0xFF4500FF, "| EVENTO | Você foi eliminado(a) do evento");
    return 1;
}

function IniciarContagemDerby(c)
{
    if(c == 0) return IniciarDerby();
    new Contd[20];
    format(Contd, sizeof(Contd), "~r~%d", c);
    for(new i=0; i < sizeof(DerbySpawn); i++)
    {
        if(pDerby[i][SlotEntou] == false) continue;   
        if(!IsPlayerConnected(pDerby[i][SlotJogadorID])) continue;
        GameTextForPlayer(pDerby[i][SlotJogadorID], Contd, 5000, 4);
        PlayerPlaySound(pDerby[i][SlotJogadorID], 1056, 0.0, 0.0, 0.0);
    }
    c--;
    SetTimerEx("IniciarContagemDerby", 1000, false, "d", c);
    return 1;
}