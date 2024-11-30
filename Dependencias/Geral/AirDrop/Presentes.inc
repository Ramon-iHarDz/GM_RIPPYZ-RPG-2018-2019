#include <YSI_Coding\y_hooks>

enum AirDropItens
{
    ItemNome[70]
};

enum SkinAirDrop
{
    ModeloSkin,
    TexturaAir[70],
    TexturaEAir[70]
};

new SkinAir[][SkinAirDrop] =
{
    {10810, "ap_build4e", "redwhite_stripe"},
    {1948, "kbslotnu", "slot_black"},
    {2127, "cj_kitchen", "CJ_RED"},
    {13761, "lahills_whisky", "lasviper7"},
    {7650, "vgnusedcar", "lightpurple2_32"},
    {9683, "goldengate_sfw", "ws_goldengate4"},
    {6866, "vgncnstrct1", "Circus_gls_01"},
    {6404, "beafron1_law2", "blueshade2_64"},
    {14674, "civic02cj", "hotelarch1_LAn"},
    {8409, "gnhotel1", "redstuff"},
    {14674, "civic02cj", "sl_hotelwall1"},
    {8710, "nuhotel01", "nuhotel03_128"},
    {2577, "cj_sex", "gun_dildo3"},
    {16640, "a51", "ws_carparkwall2"}
};

new ItensAir[][AirDropItens] =
{
    {"3 Dias de VIP"},
    {"2 Dias de VIP"},
    {"30 Dias de VIP"},
    {"+5 Estrelas de Procurado"}, 
    {"Doença Aleatória"},
    {"Arma Aleatória"},
    {"Dildo Roxo"},
    {"$2.000 Coins"},
    {"$50.000"},
    {"$20.000"},
    {"Vacinas"},
    {"Vazio"},
    {"Beijo da Administração"},
    {"Beijo da Isabella"},
    {"Tapa"},
    {"+10 Sementes de Maconha"},
    {"+10 Vasos de Maconha"},
    {"+1 Level"},
    {"+2 Leveis"},
    {"+2 Experiências"},
    {"+20 Estrelas de Procurado"},
    {"Teleporte para o Oceano"},
    {"+5 Explosivos"},
    {"Teleporte para o Maze Bank"},
    {"Morte"},
    {"Bomba Nuclear"},
    {"10m³ de gás para Jetpack"},
    {"25m³ de gás para Jetpack"},
    {"1 Dia de VIP"},
    {"$-1.000"},
    {"$-500"},
    {"Minigun por 5 Segundos"},
    {"$1.000 Coins"},
    {"Admin por 30 Dias ( Mentira )"},
    {"$1.000"},
    {"$5.000"},
    {"Remoção de Estrelas"}
};

enum FDSSADASD
{
    ArmasIDD
};

enum AirDropPlayer
{
    TempoMinigun
};

new pAir[MAX_PLAYERS][AirDropPlayer];
new ArmasAlea[][FDSSADASD] =
{
    22, // 9mm
    23, // 9mm Sile
    24, // Desert
    25, // Shotgun
    26, // Sawnoff
    27, // Combat
    28, // Uzi
    29, // MP5
    30, // AK-47
    31, // M4
    32, // Rifle
    34 // Sniper
};

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "Imunizado") == 1) KillTimer(pAir[playerid][TempoMinigun]);
    return 1;
}

stock DarItemAirDrop(playerid, id)
{
    switch(id)
    {
        case 0: AtivarVIP(playerid, 3);
        case 1: AtivarVIP(playerid, 2);
        case 2: AtivarVIP(playerid, 30);
        case 3: Jogador[playerid][Estrelas] += 5;
        case 4: Jogador[playerid][Doenca] = random(sizeof(Doencas));
        case 5: GivePlayerWeapon(playerid, ArmasAlea[random(sizeof(ArmasAlea))][ArmasIDD], 400);
        case 6: GivePlayerWeapon(playerid, 10, 1);
        case 7: Jogador[playerid][Coins] += 2000;
        case 8: Jogador[playerid][Dinheiro] += 50000;   
        case 9: Jogador[playerid][Dinheiro] += 20000;   
        case 10: DarVacina(playerid, random(2-10)+10);
        case 11: SendClientMessage(playerid, 0x1E90FFFF, "| SERVIDOR | Opa, beleza? veio nada ok?");   
        case 12: SendClientMessageToAll(0x1E90FFFF, "* Servidor: Beijão viu?");       
        case 13: SendClientMessageToAll(0x1E90FFFF, "* Administradora Isabella: Beijoooooooooooo <3");       
        case 14:
        {
            new Float:sf[3];
            GetPlayerPos(playerid, sf[0], sf[1], sf[2]);
            SetPlayerPos(playerid, sf[0], sf[1], sf[2]+60);
        }
        case 15: Jogador[playerid][Sementes] += 10;       
        case 16: Jogador[playerid][Vasos] += 10;  
        case 17: Jogador[playerid][Level] += 1;  
        case 18: Jogador[playerid][Level] += 2;
        case 19: Jogador[playerid][Experiencia] += 2;
        case 20: Jogador[playerid][Estrelas] += 20;
        case 21: SetPlayerPos(playerid, 703.5000, -2902.0000, -1.0140);
        case 22: Jogador[playerid][Dinamites] += 5;
        case 23:
        {
            SetPlayerPos(playerid, 1544.2931, -1353.8833, 329.4733);
            GivePlayerWeapon(playerid, 46, 1);    
        }
        case 24: SetPlayerHealth(playerid, 0.0);
        case 25:
        {
            new Float:BNL[3],
                Mensagem[190];
            GetPlayerPos(playerid, BNL[0], BNL[1], BNL[2]);
            format(Mensagem, sizeof(Mensagem), "| BOMBA NUCLEAR | Uma bomba nuclear acabou de cair na região de %s ( Latitude: %f / Longitude: %f )", GetPlayerZone(playerid), BNL[2], BNL[0]);
            SendClientMessageToAll(-1, Mensagem);
            for(new i=0; i < MAX_PLAYERS; i++)
            {
                if(!IsPlayerConnected(i)) continue;
                if(Jogador[i][Logado] == false) continue;
                if(!IsPlayerInRangeOfPoint(i, 90.0, BNL[0], BNL[1], BNL[2])) continue;
                if(GetPlayerVirtualWorld(i) != 0 || GetPlayerInterior(i) != 0) continue;
                SetPlayerHealth(playerid, 10.0);
                CreateExplosionForPlayer(i, BNL[0], BNL[1], BNL[2], 7, 90);
                CreateExplosionForPlayer(i, BNL[0], BNL[1], BNL[2], 5, 90);
            }
        }
        case 26: Jogador[playerid][GasJetpack] += 10;
        case 27: Jogador[playerid][GasJetpack] += 25;
        case 28: AtivarVIP(playerid, 1);
        case 29: Jogador[playerid][Dinheiro] -= 1000;
        case 30: Jogador[playerid][Dinheiro] -= 500;
        case 31:
        {
            SetPVarInt(playerid, "Imunizado", 1);
            GivePlayerWeapon(playerid, 38, 9999);
            pAir[playerid][TempoMinigun] = SetTimerEx("MinigunRemover", 5000, false, "d", playerid);
        }
        case 32: Jogador[playerid][Coins] += 1000;
        case 34: Jogador[playerid][Dinheiro] += 1000;
        case 35: Jogador[playerid][Dinheiro] += 1000;
        case 36: Jogador[playerid][Estrelas] = 0;
    }
    return 1;
}

function MinigunRemover(playerid)
{
    RemoverArma(playerid, 38);
    SetTimerEx("LDSASSSDA", 1500, false, "d", playerid);
    return 1;
}

function LDSASSSDA(playerid)
{
    SetPVarInt(playerid, "Imunizado", 0);
    return 1;
}