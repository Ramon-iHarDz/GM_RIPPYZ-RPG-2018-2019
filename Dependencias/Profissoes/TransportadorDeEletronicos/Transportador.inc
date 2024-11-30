#include <YSI_Coding\y_hooks>

enum PositionEletc{
    Float:peX,
    Float:peY,
    Float:peZ,
    Float:peA
};

enum EletronicosJogador{
    EletStatus,
    EletMap,
    EletCheck,
    EletVehID[2]
};

new TrailerEletric[][PositionEletc] = // 435
{
    {2687.4529, -2453.8945, 13.9370, 180.0000},
    {2687.4910, -2475.8074, 13.9370, 180.0000},
    {2687.3462, -2431.3049, 13.9370, 180.0000},
    {2556.0642, -2507.1660, 13.9370, -90.0000},
    {2577.9312, -2507.0503, 13.9370, -90.0000},
    {2600.9272, -2507.0996, 13.9370, -90.0000},
    {2623.1563, -2507.1023, 13.9370, -90.0000},
    {2645.8389, -2507.1743, 13.9370, -90.0000},
    {2533.9214, -2507.0034, 13.9370, -90.0000}
};

new CaminhaoEletric[][PositionEletc] = // 403
{
    {2545.1814, -2507.1377, 13.9317, -90.0000},
    {2657.0957, -2507.2456, 13.9317, -90.0000},
    {2634.4712, -2507.2559, 13.9317, -90.0000},
    {2612.3281, -2507.1851, 13.9317, -90.0000},
    {2590.4070, -2507.1638, 13.9317, -90.0000},
    {2567.4250, -2507.1646, 13.9317, -90.0000},
    {2687.3447, -2442.2783, 13.9317, 180.0000},
    {2687.1648, -2487.2925, 13.9317, 180.0000},
    {2687.3132, -2465.1855, 13.9317, 180.0000}
};

new CaminhaoEletricID[sizeof(CaminhaoEletric)];
new TrailerEletricID[sizeof(TrailerEletric)];
new pEletronicos[MAX_PLAYERS][EletronicosJogador];

hook OnGameModeInit(){
    for(new i=0; i < sizeof(CaminhaoEletric); i++){
        CaminhaoEletricID[i] = CreateVehicleEx(-1, 403, CaminhaoEletric[i][peX], CaminhaoEletric[i][peY], CaminhaoEletric[i][peZ], CaminhaoEletric[i][peA], random(999), random(999), 360, 0);
        format(VeiculoServer[CaminhaoEletricID[i]][LocalVerificacao], 90, "CaminhaoConcretoVeh");
    }
    for(new i=0; i < sizeof(TrailerEletric); i++){
        TrailerEletricID[i] = CreateVehicleEx(-1, 435, TrailerEletric[i][peX], TrailerEletric[i][peY], TrailerEletric[i][peZ], TrailerEletric[i][peA], random(999), random(999), 360, 0);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason){
    DestroyDynamicRaceCPEx(pEletronicos[playerid][EletCheck]);
    DestroyDynamicMapIconEx(pEletronicos[playerid][EletMap]);
    new asdasda[EletronicosJogador];
    pEletronicos[playerid] = asdasda;
    return 1;
}

function CaminhaoConcretoVeh(playerid){
    if(strcmp(Jogador[playerid][Profissao], "Transportador de Eletrônicos")){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        return false;
    }
    return 1;
}

function CaminhaoEletEtapa1(playerid){
    TogglePlayerControllable(playerid, 1);

    enum LocalEletricAA{
        Float:ppEX,
        Float:ppEY,
        Float:ppEZ
    };
    new LocalEletric[][LocalEletricAA] =
    {
        {2306.5022,2793.5251,10.8203},
        {2047.3660,2221.2666,10.8203},
        {-1838.8705,134.7322,14.8442},
        {2834.7502,2389.1040,10.8203},
        {-2262.0059,2308.2900,4.8202},
        {-2107.3396,-2262.6318,30.4688}
    };
    new i = random(sizeof(LocalEletric)),
        Mensagem[128];
    pEletronicos[playerid][EletStatus] = 2;
    pEletronicos[playerid][EletCheck] = CreateDynamicRaceCP(1, LocalEletric[i][ppEX], LocalEletric[i][ppEY], LocalEletric[i][ppEZ], 0.0, 0.0, 0.0, 2.5, 0, 0, playerid, 40.0, -1);
    pEletronicos[playerid][EletMap] = CreateDynamicMapIcon(LocalEletric[i][ppEX], LocalEletric[i][ppEY], LocalEletric[i][ppEZ], 56, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    format(Mensagem, sizeof(Mensagem), "| DOCAS | Você precisa ir até {daa520}%s{FFFFFF} para entregar os eletrônicos", AreaNome(LocalEletric[i][ppEX], LocalEletric[i][ppEY], LocalEletric[i][ppEZ]));
    SendClientMessage(playerid, -1, Mensagem);

    return 1;
}

function CaminhaoEletEtapa2(playerid){
    TogglePlayerControllable(playerid, 1);
    new Mensagem[128],
        ralsd = random(4300-3000)+3000;
    Jogador[playerid][Dinheiro] += ralsd;
    Jogador[playerid][Trabalhando] = false;
    pEletronicos[playerid][EletStatus] = 0;
    format(Mensagem, sizeof(Mensagem), "| CAMINHÃO | Você recebeu {32CD32}$%s{FFFFFF} por entregar encomendas", DinheiroSeparar(ralsd));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

hook OnPlayerEnterDynRaceCP(playerid, checkpointid){
    if(checkpointid != pEletronicos[playerid][EletCheck]) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 1;
    if(GetPlayerVehicleID(playerid) != pEletronicos[playerid][EletVehID][0]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo o caminhão");
    if(GetVehicleTrailer(pEletronicos[playerid][EletVehID][0]) != pEletronicos[playerid][EletVehID][1]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo o caminhão");

    DestroyDynamicRaceCPEx(pEletronicos[playerid][EletCheck]);
    DestroyDynamicMapIconEx(pEletronicos[playerid][EletMap]);
    TogglePlayerControllable(playerid, 0);
    switch(pEletronicos[playerid][EletStatus])
    {
        case 1: CriarProgresso(playerid, "Carregando Caminhão, Aguarde.", "CaminhaoEletEtapa1", 50);
        case 2: CriarProgresso(playerid, "Descarregando Caminhão, Aguarde.", "CaminhaoEletEtapa2", 50); 
    }
    return 1;
}

CMD:carregareletronico(playerid){
    if(strcmp(Jogador[playerid][Profissao], "Transportador de Eletrônicos")) return 0;
    if(pEletronicos[playerid][EletStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está em serviço");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");

    new bool:Fouind,
        iiia;
    for(new i=0; i < sizeof(CaminhaoEletric); i++){
        if(GetPlayerVehicleID(playerid) != CaminhaoEletricID[i]) continue;
        Fouind = true;
        iiia = i;
        break;
    }
    if(Fouind == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo o caminhão");
    Fouind = false;

    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(pEletronicos[i][EletStatus] < 1) continue;
        if(pEletronicos[i][EletVehID][0] == GetPlayerVehicleID(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse caminhão já está sendo utilizado");
    }

    for(new i=0; i < sizeof(TrailerEletric); i++){
        if(GetVehicleTrailer(GetPlayerVehicleID(playerid)) != TrailerEletricID[i]) continue;
        Fouind = true;
        iiia = i;
        break;
    }
    if(Fouind == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhum trailer equipado em seu caminhão");

    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(pEletronicos[i][EletStatus] < 1) continue;
        if(pEletronicos[i][EletVehID][1] == TrailerEletricID[iiia]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse trailer já está sendo utilizado");
    }

    Jogador[playerid][Trabalhando] = true;
    pEletronicos[playerid][EletStatus] = 1;
    pEletronicos[playerid][EletVehID][0] = GetPlayerVehicleID(playerid);
    pEletronicos[playerid][EletVehID][1] = TrailerEletricID[iiia];
    pEletronicos[playerid][EletMap] = CreateDynamicMapIcon(2760.3936,-2457.3372,13.2768, 56, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    pEletronicos[playerid][EletCheck] = CreateDynamicRaceCP(1, 2760.3936,-2457.3372,13.2768, 0.0, 0.0, 0.0, 2.5, 0, 0, playerid, 40.0, -1);
    SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Vá até o ponto marcado no mapa");
    return 1;
}