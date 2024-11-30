#include <YSI_Coding\y_hooks>

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_PASSENGER){
        if(!ArmaBlock(GetPlayerWeapon(playerid))) return 1;
        SetPVarInt(playerid, "Anrasg", GetPlayerWeapon(playerid));
        SetPlayerArmedWeapon(playerid, 0);   
    }
    else if(newstate == PLAYER_STATE_ONFOOT){
        if(GetPVarInt(playerid, "Anrasg") != 0) return 1;
        new ammo;
        GetPlayerWeaponData(playerid, GetWeaponSlot(GetPVarInt(playerid, "Anrasg")), ammo, ammo);
        if(ammo > 0) SetPlayerArmedWeapon(playerid, GetPVarInt(playerid, "Anrasg"));
        SetPVarInt(playerid, "Anrasg", 0);   
    }
    return 1;
}

stock ArmaBlock(weaponid)
{
    switch(weaponid){
        case 22, 23, 24, 25, 26, 27: return true;
    }
    return false;
}

stock GetWeaponSlot(weaponid)
{
	new slotid;
    switch(weaponid) {
    case 0,1: 				slotid = 0;
    case 2,3,4,5,6,7,8,9: 	slotid = 1;
    case 22,23,24: 			slotid = 2;
    case 25,26,27: 			slotid = 3;
    case 28,29,32: 			slotid = 4;
    case 30,31: 			slotid = 5;
    case 33,34: 			slotid = 6;
    case 35,36,37,38: 		slotid = 7; 
    case 16,17,18,19,39: 	slotid = 8;
    case 41,42,43: 			slotid = 9;
    case 10,11,12,13,14,15: slotid = 10;
    case 44,45,46: 			slotid = 11;
    case 40: 				slotid = 12; }
    return slotid;
}