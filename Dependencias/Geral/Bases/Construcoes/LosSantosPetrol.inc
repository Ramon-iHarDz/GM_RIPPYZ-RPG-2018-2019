#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicObject(987, 1062.65002, 2155.29932, 9.81940,   0.00000, 0.00000, 89.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, 1061.71240, 2064.18481, 9.81340,   0.00000, 0.00000, 91.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(3749, 1019.30756, 2132.89868, 15.60000,   0.00000, 0.00000, 270.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(7621, 1310.67688, -1595.85791, -9213.19141,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(8341, 1044.86792, 2216.49146, 14.00000,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(9131, 1017.51324, 2143.00098, 12.12000,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(9131, 1017.50354, 2142.99731, 10.90000,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(8341, 1028.21606, 2081.60156, 13.20000,   0.00000, 0.00000, -180.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(3928, 1029.60632, 2188.76782, 9.81700,   0.00000, 0.00000, -91.00000, -1, 0, -1, 450.0, 450.0, -1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 7674, 1029.3594, 2082.8516, 13.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 7675, 1031.6172, 2173.8203, 15.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 3474, 1080.5234, 2069.8125, 16.7422, 0.25);
    RemoveBuildingForPlayer(playerid, 7620, 1029.3594, 2082.8516, 13.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 7647, 1005.2891, 2105.4531, 21.1016, 0.25);
    RemoveBuildingForPlayer(playerid, 3474, 1024.2578, 2110.6953, 16.7422, 0.25);
    RemoveBuildingForPlayer(playerid, 3459, 1016.6953, 2144.4609, 17.3203, 0.25);
    RemoveBuildingForPlayer(playerid, 7622, 1031.6172, 2173.8203, 15.9219, 0.25);
    RemoveBuildingForPlayer(playerid, 3474, 1052.8359, 2191.4844, 16.7422, 0.25);
    return 1;
}