#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicObject(5779, 2005.65930, 2303.34180, 11.35080,   0.00000, 0.00000, 90.00000, -1, 0, -1, 250.0, 250.0, -1);
    CreateDynamicObject(5779, 1843.30835, -1856.56458, 13.91280,   0.00000, 0.00000, 0.00000, -1, 0, -1, 250.0, 250.0, -1);
    CreateDynamicObject(5779, -1695.44434, 1035.52649, 45.68720,   0.00000, 0.00000, 0.00000, -1, 0, -1, 250.0, 250.0, -1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 5043, 1843.3672, -1856.3203, 13.8750, 0.25);
    RemoveBuildingForPlayer(playerid, 10149, -1695.0703, 1035.6172, 45.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 7709, 2006.0000, 2303.7266, 11.3125, 0.25); 
    return 1;
}