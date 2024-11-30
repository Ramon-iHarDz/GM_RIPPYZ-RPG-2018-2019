#include <YSI_Coding\y_hooks>

enum CarroConcrect{
    Float:ccX,
    Float:ccY,
    Float:ccZ,
    Float:ccA
};

enum JogadorConcreto{
    ConcretoStatus,
    ConcretoArray,
    ConcretoVeiculo,

    ConcretoCheck,
    ConcretoMap
};

new ConcretoSpawn[][CarroConcrect] =
{
    //{630.0190,915.0486,-41.7085,170.1393}, // 1
    //{635.5952,914.4461,-41.5100,171.1287}, // 2
    {641.1168,913.7120,-41.1981,173.4260}, // 3
    {646.3046,912.9873,-40.7263,173.6008}, // 4
    {651.4130,912.3211,-40.2138,172.1214}, // 5
    {656.4717,911.0571,-39.7637,166.3446}, // 6
    {619.6812,866.8940,-42.0285,123.1964}, // 7
    {628.3690,872.9783,-42.0223,124.5930}, // 8
    {636.4159,878.8531,-42.0252,126.5813}, // 9
    {644.1631,884.5997,-41.6636,124.6914}, // 10
    {653.8214,894.0140,-40.5711,355.0147}, // 11
    {649.1237,894.6925,-41.1071,353.7847}, // 12
    {644.0391,895.3915,-41.6995,350.6653} // 13
};
new EntregasConcreto[][CarroConcrect] =
{
    {-2099.8032,-2240.7947,30.6250}, // Entrega 1
    {2450.0166,-2488.2141,13.6434}, // Entrega 2
    {1570.0096,-1477.0111,13.5519}, // Entrega 3
    {-72.6383,-1117.3462,1.0781}, // Entrega 4
    {575.4684,1212.3486,12.1835}, // Entrega 5
    {1144.4639,1968.8121,10.8203}, // Entrega 6
    {2120.3662,2753.3530,10.8203}, // Entrega 7
    {2477.6621,1765.3510,10.8203}, // Entrega 8
    {2635.5583,1075.9246,10.8203}, // Entrega 9
    {1326.0436,1162.2589,10.8203}, // Entrega 10
    {-1724.3105,-119.9975,3.5489}, // Entrega 11
    {-2111.9136,-859.5379,32.1719} // Entrega 12
};
new ConcretoID[sizeof(ConcretoSpawn)];
new pConcreto[MAX_PLAYERS][JogadorConcreto];

hook OnGameModeInit(){
    new corr;
    for(new i=0; i < sizeof(ConcretoSpawn); i++){
        corr = random(999);
        ConcretoID[i] = CreateVehicleEx(-1, 524, ConcretoSpawn[i][ccX], ConcretoSpawn[i][ccY], ConcretoSpawn[i][ccZ], ConcretoSpawn[i][ccA], corr, corr, 360, 0);
        format(VeiculoServer[ConcretoID[i]][LocalVerificacao], 90, "ConcretoVeh");
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason){
    DestroyDynamicRaceCPEx(pConcreto[playerid][ConcretoStatus]);
    DestroyDynamicMapIconEx(pConcreto[playerid][ConcretoMap]);
    new adsda[JogadorConcreto];
    pConcreto[playerid] = adsda;
    return 1;
}

function ConcretoVeh(playerid, vehicleid)
{
    if(strcmp(Jogador[playerid][Profissao], "Transportador de Concreto")){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        return false;
    }
    return true;
}

function ConcretoEtapa1(playerid){
    new Mensagem[128];
    TogglePlayerControllable(playerid, 1);
    pConcreto[playerid][ConcretoStatus] = 2;
    pConcreto[playerid][ConcretoArray] = random(sizeof(EntregasConcreto));

    pConcreto[playerid][ConcretoCheck] = CreateDynamicRaceCP(1, EntregasConcreto[pConcreto[playerid][ConcretoArray]][ccX], EntregasConcreto[pConcreto[playerid][ConcretoArray]][ccY], EntregasConcreto[pConcreto[playerid][ConcretoArray]][ccZ], 0.0, 0.0, 0.0, 16.0, 0, 0, playerid, 60.0, -1);
    pConcreto[playerid][ConcretoMap] = CreateDynamicMapIcon(EntregasConcreto[pConcreto[playerid][ConcretoArray]][ccX], EntregasConcreto[pConcreto[playerid][ConcretoArray]][ccY], EntregasConcreto[pConcreto[playerid][ConcretoArray]][ccZ], 11, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    format(Mensagem, sizeof(Mensagem), "| CONCRETO | Você precisa ir até {daa520}%s{FFFFFF} para descarregar seu caminhão", AreaNome(EntregasConcreto[pConcreto[playerid][ConcretoArray]][ccX], EntregasConcreto[pConcreto[playerid][ConcretoArray]][ccY], EntregasConcreto[pConcreto[playerid][ConcretoArray]][ccZ]));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

function ConcretoEtapa2(playerid){
    new Mensagem[128],
        dasda = random(4000-2800)+2800;
    format(Mensagem, sizeof(Mensagem), "| CONCRETO | Você descarregou seu caminhão e recebeu {32CD32}$%s", DinheiroSeparar(dasda));
    SendClientMessage(playerid, -1, Mensagem);
    Jogador[playerid][Dinheiro] += dasda;
    pConcreto[playerid][ConcretoStatus] = 0;
    Jogador[playerid][Trabalhando] = false;
    TogglePlayerControllable(playerid, 1);
    return 1;
}

hook OnPlayerEnterDynRaceCP(playerid, checkpointid){
    if(checkpointid != pConcreto[playerid][ConcretoCheck]) return 1;
    if(GetPlayerVehicleID(playerid) != pConcreto[playerid][ConcretoVeiculo]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu caminhão");
    DestroyDynamicRaceCPEx(pConcreto[playerid][ConcretoCheck]);
    DestroyDynamicMapIconEx(pConcreto[playerid][ConcretoMap]);
    TogglePlayerControllable(playerid, 0);
    switch(pConcreto[playerid][ConcretoStatus])
    {
        case 1: CriarProgresso(playerid, "Carregando Caminhão, Aguarde.", "ConcretoEtapa1", 50);
        case 2: CriarProgresso(playerid, "Descarregando Caminhão, Aguarde.", "ConcretoEtapa2", 50);
    }
    return 1;
}

CMD:concreto(playerid){
    if(strcmp(Jogador[playerid][Profissao], "Transportador de Concreto")) return 0;
    if(pConcreto[playerid][ConcretoStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está em serviço");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    new bool:Fouind,
        iiia;
    for(new i=0; i < sizeof(ConcretoSpawn); i++){
        if(GetPlayerVehicleID(playerid) != ConcretoID[i]) continue;
        Fouind = true;
        iiia = i;
        break;
    }
    if(Fouind == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo um Caminhão de Concreto");

    pConcreto[playerid][ConcretoStatus] = 1;
    pConcreto[playerid][ConcretoArray] = iiia;
    pConcreto[playerid][ConcretoVeiculo] = GetPlayerVehicleID(playerid);
    pConcreto[playerid][ConcretoCheck] = CreateDynamicRaceCP(1, 583.4571,856.5820,-41.9831, 0.0, 0.0, 0.0, 2.5, 0, 0, playerid, 60.0, -1);
    pConcreto[playerid][ConcretoMap] = CreateDynamicMapIcon(583.4571,856.5820,-41.9831, 11, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    Jogador[playerid][Trabalhando] = true;
    SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Vá até o ponto marcado no mapa");
    return 1;
}