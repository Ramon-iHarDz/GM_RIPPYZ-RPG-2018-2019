#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicObject(3749, -2433.45630, 496.19220, 34.95140,   0.00000, 0.00000, 23.59622);
    // CreateDynamicObject(19912, -2428.21875, 498.67291, 31.71010,   0.00000, 0.00000, 23.59620);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 966, -2436.8516, 495.4531, 28.9531, 0.25);
    RemoveBuildingForPlayer(playerid, 967, -2438.7266, 495.0078, 29.1016, 0.25);
    RemoveBuildingForPlayer(playerid, 968, -2436.8125, 495.4688, 29.6797, 0.25);
    return 1;
}