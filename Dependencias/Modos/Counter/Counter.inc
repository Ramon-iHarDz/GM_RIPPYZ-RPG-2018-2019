#include <YSI_Coding\y_hooks>
#include "../Dependencias/Modos/Counter/Modulos/CounterMenu"
#include "../Dependencias/Modos/Counter/Mapas/Mapa1"

enum SpawnsCounter
{
    Float:SpawnX,
    Float:SpawnY,
    Float:SpawnZ
};

new DustSpawn[][SpawnsCounter] = 
{
    {-2218.6643,897.4009,1100.9557},
    {-2232.1541,859.3331,1100.9557},
    {-2269.8442,845.7894,1100.9557},
    {-2285.5388,871.7054,1100.9557},
    {-2260.0559,896.6804,1100.9557},
    {-2246.6055,883.8661,1100.9557},
    {-2252.5308,862.7970,1100.9557},
    {-2243.9507,862.2785,1100.9557},
    {-2228.1328,877.0559,1100.9557},
    {-2277.7639,886.3625,1100.9557}
};

new Small[][SpawnsCounter] =
{
    {-1054.4047,1036.2162,1343.1863},
    {-1015.0067,1048.9094,1342.3457},
    {-991.0762,1025.0331,1341.8513},
    {-1002.5436,1072.1404,1342.7120},
    {-1027.4028,1092.2714,1343.0552},
    {-976.4536,1056.4301,1344.9968},
    {-971.7753,1095.5270,1344.9913},
    {-973.2580,1023.4338,1345.0516},
    {-1046.1132,1022.3232,1343.0696},
    {-1080.7841,1025.6211,1342.5782},
    {-1095.5104,1069.3514,1342.5853},
    {-1108.1769,1094.8783,1341.8438},
    {-1119.1875,1058.2446,1343.1620},
    {-1132.3306,1029.0718,1345.7343},
    {-1132.7284,1062.5076,1345.7654},
    {-1132.0547,1095.1847,1345.7926}
};

Dialog:CounterDialog(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    new id = listitem;
    if(pCounter[id][Jogadores] >= CounterJogadores) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa sala não suporta mais jogadores!");
    pCounter[id][Jogadores]++;
    ColocarCounter(playerid, id);
    return 0;
}

stock ColocarCounter(playerid, arena)
{
    if(!strcmp(pCounter[arena][Mapa], "Dust 3")){
        new spawnid = random(sizeof(DustSpawn));
        SetPlayerPos(playerid, DustSpawn[spawnid][SpawnX], DustSpawn[spawnid][SpawnY], DustSpawn[spawnid][SpawnZ]+1);
        SetPlayerInterior(playerid, arena+arena+1);
    }
    else if(!strcmp(pCounter[arena][Mapa], "Small")){
        new spawnid = random(sizeof(Small));
        SetPlayerPos(playerid, Small[spawnid][SpawnX], Small[spawnid][SpawnY], Small[spawnid][SpawnZ]);    
        SetPlayerInterior(playerid, 10);
    }

    //Setando Dependencias
    SetPlayerVirtualWorld(playerid, arena+arena+2);
    pModo[playerid][ModoAtl] = 1;
    pModo[playerid][Sala] = arena;
    pModo[playerid][Jogando] = true;
    pModo[playerid][Kill] = 0;
    pModo[playerid][Morte] = 0;
    RemoverAcessorios(playerid);

    if(pCounter[arena][Iniciou] == false)
    { 
        if(pCounter[arena][Jogadores] >= 2)
        {
            pCounter[arena][Iniciou] = true;
            pCounter[arena][Tempo] = 0;
            pCounter[arena][TempoPlayer] = CounterTempo;
            for(new i=0; i < MAX_PLAYERS; i++)
            {
                if(!IsPlayerConnected(i)) continue;
                if(pModo[i][ModoAtl] != 1) continue;
                if(pModo[i][Sala] != arena) continue;
                SendClientMessage(i, 0xFFFF00FF, "| ARENA | Servidor foi iniciado."); 
            }
            SetTimerEx("ArenaConfig", 1000, false, "d", arena);
        }
    }

    ResetPlayerWeapons(playerid);
    DarArmaCounter(playerid);
    MostrarCounter(playerid);
    SendClientMessage(playerid, 0xfc520fFF, "| AVISO | Para sair dessa sessão use /desistir");
    return 1;
}

stock RespawnarCounter(playerid)
{
    new id = pModo[playerid][Sala];
    cAC[playerid][InteriorBloqueioEx] = true; // Proteção contra falso positivo
    TogglePlayerControllable(playerid, 0);
    if(!strcmp(pCounter[id][Mapa], "Dust 3"))
    {
        new spawnid = random(sizeof(DustSpawn));
        SetPlayerInterior(playerid, pModo[playerid][Sala]+pModo[playerid][Sala]+1);
        SetPlayerPos(playerid, DustSpawn[spawnid][SpawnX], DustSpawn[spawnid][SpawnY], DustSpawn[spawnid][SpawnZ]+1);
    }
    else if(!strcmp(pCounter[id][Mapa], "Small"))
    {
        new spawnid = random(sizeof(Small));
        SetPlayerInterior(playerid, 10); 
        SetPlayerPos(playerid, Small[spawnid][SpawnX], Small[spawnid][SpawnY], Small[spawnid][SpawnZ]);    
    }
    
    //Setando Dependencias
    ResetPlayerWeapons(playerid); 
    DarArmaCounter(playerid); 
    SetPlayerHealth(playerid, 99999);
    SendClientMessage(playerid, 0xfc520fFF, "| AVISO | Você ficará invulnerável durante 5 segundos!");
    SetTimerEx("VoltarAoNormal", 5000, false, "d", playerid);
    SetTimerEx("Destravar", 2000, false, "d", playerid);
    return 1;
}

function VoltarAoNormal(playerid)
{
    SetPlayerHealth(playerid, 100);
    return 1;
}

stock TirarJogadorCounter(playerid)
{
    new id = pModo[playerid][Sala];
    pCounter[id][Jogadores]--;

    SetPVarInt(playerid, "SemHospital", gettime()+10);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| COUNTER | %s saiu da sessão ( %d/%d )", PegarNick(playerid), pCounter[id][Jogadores], CounterJogadores);
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(pModo[i][Jogando] == false) continue;
        if(i == playerid) continue;
        if(pModo[i][ModoAtl] != 1) continue;
        if(pModo[i][Sala] != id) continue;
        SendClientMessage(i, 0xfc520fFF, Mensagem);   
    }

    if(cDados[playerid][Morreu] == false)
    {
        SetPlayerInterior(playerid, 0); 
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerPos(playerid, 2780.0898,-1814.0895,11.8438);
    }

    VerificarAcessorios(playerid);
    pModo[playerid][Jogando] = false;
    pModo[playerid][Sala] = 0;
    pModo[playerid][ModoAtl] = 0;
    pModo[playerid][Kill] = 0;
    pModo[playerid][Morte] = 0;
    ResetPlayerWeapons(playerid); 
    OcultarCounter(playerid);
    return 1;
}

stock DarArmaCounter(playerid)
{
    if(Jogador[playerid][Vip] > gettime()){
        GivePlayerWeapon(playerid, 24, 9999); //Desert
        GivePlayerWeapon(playerid, 29, 9999); //MP5 
        GivePlayerWeapon(playerid, 8, 1); //Katana 
    }
    else
    {
        GivePlayerWeapon(playerid, 3, 1); //Cacetete
    }
    GivePlayerWeapon(playerid, 34, 9999); //Sniper
    GivePlayerWeapon(playerid, 31, 9999); //M4
    return 1;
}

function ArenaConfig(arenaid)
{
    if(pCounter[arenaid][Tempo] >= CounterTempo)
    {
        ResetarMapaCounter(arenaid);
        new Max[2] = 0;
        Max[1] = -1;

        new MensagemNovamente[128];
        format(MensagemNovamente, sizeof(MensagemNovamente), "| FINALIZAÇÃO | Servidor %d do Counter War finalizou-se.", arenaid);
        for(new i=0; i < MAX_PLAYERS; i++)
        {
            if(!IsPlayerConnected(i)) continue;
            if(pModo[i][Jogando] == false) continue;
            if(pModo[i][ModoAtl] != 1) continue;
            if(pModo[i][Sala] != arenaid) continue;

            if(pModo[i][Kill] > Max[0])
            {
                Max[0] = pModo[i][Kill];
                Max[1] = i; 
            }
            TirarJogadorCounter(i);
            SendClientMessage(i, 0x00BFFFFF, MensagemNovamente);
        }
        format(MensagemNovamente, sizeof(MensagemNovamente), "| FINALIZAÇÃO | Parabéns, você foi top kill do último counter war com %d vitima(s)", Max[0]);
        SendClientMessage(Max[1], 0x00BFFFFF, MensagemNovamente);

        pCounter[arenaid][Tempo] = 0;
        pCounter[arenaid][Iniciou] = false;
        return 1;   
    }

    new TempoStt[128];
    format(TempoStt, sizeof(TempoStt), "Tempo:_%s", SegundosParaMinutos(pCounter[arenaid][TempoPlayer]));

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(pModo[i][Jogando] == false) continue;
        if(pModo[i][ModoAtl] != 1) continue;
        if(pModo[i][Sala] != arenaid) continue;
        PlayerTextDrawSetString(i, CounterMenu[i][7], TempoStt);
    }

    pCounter[arenaid][Tempo]++;
    pCounter[arenaid][TempoPlayer]--;
    SetTimerEx("ArenaConfig", 1000, false, "d", arenaid);
    return 1;
}

stock ResetarMapaCounter(id)
{
    new ddid = random(sizeof(MapasCounter));
    format(pCounter[id][Mapa], 70, MapasCounter[ddid][MapaSelect]);
    return 1;
}