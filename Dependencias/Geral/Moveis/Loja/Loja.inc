#include <YSI_Coding\y_hooks>

enum PosLojaRC
{
    LojaNome[30],
    Float:LojaPosX,
    Float:LojaPosY,
    Float:LojaPosZ
};

new LojaLoad[][PosLojaRC] =
{
    {"Quarto", 2035.2031,1303.3396,270.8355},
    {"Eletrônicos", 2038.1700,1319.9973,270.8355},
    {"Sala", 2035.4235,1336.8312,270.8355},
    {"Banheiro", 2016.5210,1339.6556,270.8355},
    {"Cozinha",  2003.8861,1333.0839,270.8355},
    {"Plantas", 2003.7860,1317.3917,270.8355}
};

hook OnGameModeInit()
{
    CreateDynamicActor(141, 2017.6525,1320.8092,270.8663,185.1168, 1, 100.0, 2012, 7, -1, 100.0, -1, 0);
    CreateDynamic3DTextLabel("Caixa{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para interagir", 0x32CD32FF, 2018.2606,1318.9801,270.8663, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2012, 7, -1, 30.0, -1);

    CreateDynamicMapIcon(-1754.1930,962.8623,24.8828, 51, -1, 0, 0, -1, 170.0, MAPICON_LOCAL, -1);
    CreateDynamicPickup(1239, 1, -1754.1930,962.8623,24.8828, 0, 0, -1, 60.0, -1);
    CreateDynamic3DTextLabel("Loja de Móveis{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para entrar", 0xFFFF00FF, -1754.1930,962.8623,24.8828, 40.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 50.0, -1);

    new Mensagem[70];
    for(new i=0; i < sizeof(LojaLoad); i++)
    {
        format(Mensagem, sizeof(Mensagem), "%s{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para interagir", LojaLoad[i][LojaNome]);
        CreateDynamicPickup(1239, 1, LojaLoad[i][LojaPosX], LojaLoad[i][LojaPosY], LojaLoad[i][LojaPosZ], 2012, 7, -1, 60.0, -1);
        CreateDynamic3DTextLabel(Mensagem, 0x00BFFFFF, LojaLoad[i][LojaPosX], LojaLoad[i][LojaPosY], LojaLoad[i][LojaPosZ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2012, 7, -1, 30.0, -1);
    }
    return 1; 
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    for(new i=0; i < sizeof(LojaLoad); i++){
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, LojaLoad[i][LojaPosX], LojaLoad[i][LojaPosY], LojaLoad[i][LojaPosZ])) continue;
        if(GetPlayerInterior(playerid) != 7 || GetPlayerVirtualWorld(playerid) != 2012) return 1;
        EnviarLoja(playerid, LojaLoad[i][LojaNome]);
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == LojaMoveis[playerid][5]) AtualizarLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), GetPVarInt(playerid, "MoveisLoja"), false);
    else if(playertextid == LojaMoveis[playerid][6]) AtualizarLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), GetPVarInt(playerid, "MoveisLoja"), true); 
    else if(playertextid == LojaMoveis[playerid][8]) OcultarLoja(playerid);
    else if(playertextid == LojaMoveis[playerid][7]) AtualizarLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), GetPVarInt(playerid, "MoveisLoja"), false, true);
    return 0;
}