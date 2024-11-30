#include <YSI_Coding\y_hooks>

new CeckVpp;

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{FF0000}Área VIP\n{FFFF00}Local Exclusivo para Vips\n{FFFFFF}Aperte {CCCCCC}'F'{FFFFFF} para entrar", -1, 1022.4569,-1121.8407,23.8717, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1);
    CreateDynamicPickup(1239, 1, 1022.4569,-1121.8407,23.8717, 0, 0, -1, 60.0, -1, 0);
    CreateDynamicMapIcon(1022.4569,-1121.8407,23.8717, 56, -1, 0, 0, -1, 130.0, MAPICON_LOCAL);

    CreateDynamic3DTextLabel("{FF0000}Área VIP\n{FFFF00}Local Exclusivo para Vips\n{FFFFFF}Aperte {CCCCCC}'F'{FFFFFF} para entrar", -1, 2015.0822,1106.4320,10.8203, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1);
    CreateDynamicPickup(1239, 1, 2015.0822,1106.4320,10.8203, 0, 0, -1, 60.0, -1, 0);
    CreateDynamicMapIcon(2015.0822,1106.4320,10.8203, 56, -1, 0, 0, -1, 130.0, MAPICON_LOCAL);

    CreateDynamic3DTextLabel("{FF0000}Área VIP\n{FFFF00}Local Exclusivo para Vips\n{FFFFFF}Aperte {CCCCCC}'F'{FFFFFF} para entrar", -1, -2664.9631,-8.9631,6.1328, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1);
    CreateDynamicPickup(1239, 1, -2664.9631,-8.9631,6.1328, 0, 0, -1, 60.0, -1, 0);
    CreateDynamicMapIcon(-2664.9631,-8.9631,6.1328, 56, -1, 0, 0, -1, 130.0, MAPICON_LOCAL);
    
    CreateDynamicActor(295, 2170.2644,1584.9867,999.9739,269.3950, 1, 100.0, 4176, 1, -1, 120.0, -1, 0);
    CeckVpp = CreateDynamicCP(2172.6960,1584.9326,999.9713, 1.0, 4176, 1, -1, 60.0, -1);
    return 1; 
}

stock VipDarArma(playerid, armaid, balas)
{
    if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas"); 
    if(VerificarArmaLimite(playerid, armaid, 6000)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já tem o máximo de munição");
    GivePlayerWeapon(playerid, armaid, balas);
    return 1;
}

Dialog:VipArmasDialog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new Float:asddfsa;
            GetPlayerArmour(playerid, asddfsa);
            if(asddfsa > 0.0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você ainda tem colete");
            SetPlayerArmour(playerid, 100.0);
        }
        case 1: VipDarArma(playerid, 16, 10);
        case 2: VipDarArma(playerid, 22, 500);
        case 3: VipDarArma(playerid, 23, 600);
        case 4: VipDarArma(playerid, 24, 300);
        case 5: VipDarArma(playerid, 26, 200);
        case 6: VipDarArma(playerid, 27, 200);
        case 7: VipDarArma(playerid, 28, 800);
        case 8: VipDarArma(playerid, 29, 800);
        case 9: VipDarArma(playerid, 30, 800);
        case 10: VipDarArma(playerid, 31, 800);
        case 11: VipDarArma(playerid, 32, 800);
        case 12: VipDarArma(playerid, 33, 200);
        case 13: VipDarArma(playerid, 34, 200);
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != CeckVpp) return 1;
    if(Jogador[playerid][Vip] < 1 && Jogador[playerid][Admin] < 1) return 1;
    new Dialog[300];
    strcat(Dialog, "Colete\n");
    strcat(Dialog, "Granadas\n");
    strcat(Dialog, "9mm\n");
    strcat(Dialog, "9mm com Silenciador\n");
    strcat(Dialog, "Desert Eagle\n");
    strcat(Dialog, "Sawnoff Shotgun\n");
    strcat(Dialog, "Combat Shotgun\n");
    strcat(Dialog, "Uzi\n");
    strcat(Dialog, "MP5\n");
    strcat(Dialog, "AK-47\n");
    strcat(Dialog, "M4\n");
    strcat(Dialog, "Tec-9\n");
    strcat(Dialog, "Country Rifle\n");
    strcat(Dialog, "Sniper Rifle");
    Dialog_Show(playerid, VipArmasDialog, DIALOG_STYLE_TABLIST, "{FF0000}Área VIP", Dialog, "Selecionar", "Fechar");
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1022.4569,-1121.8407,23.8717) ||
        IsPlayerInRangeOfPoint(playerid, 3.0, 2015.0822,1106.4320,10.8203) ||
        IsPlayerInRangeOfPoint(playerid, 3.0, -2664.9631,-8.9631,6.1328))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(Jogador[playerid][Vip] < 1 && Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            Jogador[playerid][uInteriorEx] = 4176;
            GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
            TogglePlayerControllable(playerid, 0);
            SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);
            SetPlayerVirtualWorld(playerid, 4176);
            SetPlayerInterior(playerid, 1);
            SetPlayerPos(playerid, 2224.4011,1597.5548,999.9766);
            SetTimerEx("Destravar", 3000, false, "d", playerid);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2224.4011,1597.5548,999.9766))
        {
            if(Jogador[playerid][uInteriorEx] != 4176) return 1;
            if(GetPlayerVirtualWorld(playerid) != 4176 || GetPlayerInterior(playerid) != 1) return 1;
            Jogador[playerid][uInteriorEx] = 0;
            TogglePlayerControllable(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
            SetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
            SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);
            SetTimerEx("Destravar", 3000, false, "d", playerid);
        }
    }
    return 1;
}