#include <YSI_Coding\y_hooks>

new iTempWeapon[MAX_PLAYERS],
    bool:DriveBy[MAX_PLAYERS]
;

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_PASSENGER)
	{
	    iTempWeapon[playerid] = GetPlayerWeapon(playerid);
	    DriveBy[playerid] = false;
	}
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(PRESSEDEx(KEY_CROUCH))
    {
	    if(GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
		{
	        if(DriveBy[playerid] == false) DriveBy[playerid] = true;
			else if(DriveBy[playerid] == true)
			{
	            SetPlayerArmedWeapon(playerid, 0);
	            ApplyAnimation(playerid,"PED","CAR_GETIN_RHS",4.1,0,0,0,0,1,1);
	            SetTimerEx("GiveWeaponBack",350,0,"d",playerid);
	            DriveBy[playerid] = true;
			}
		}
	}
	return 1;
}

function GiveWeaponBack(playerid)
{
	new ammo;
	GetPlayerWeaponData(playerid, GetWeaponSlot(iTempWeapon[playerid]), ammo, ammo);
    if(ammo > 0) SetPlayerArmedWeapon(playerid, iTempWeapon[playerid]);
    DriveBy[playerid] = false;
}

stock GetWeaponSlot(weaponid)
{
	new slotid;
    switch(weaponid) {
    case 0,1: 				slotid = 0;
    case 2,3,4,5,6,7,8,9: 	slotid = 1;
    case 22,23,24: 			slotid = 2;
    case 25,26: 			slotid = 3;
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