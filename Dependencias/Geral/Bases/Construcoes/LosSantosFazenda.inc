#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicObject(987, -75.60160, -295.42450, 2.90000,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, -75.68950, -384.04791, 2.90000,   -2.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, -75.70908, -372.15302, 2.90000,   -2.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(3749, -73.94357, -353.07626, 6.00000,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, -75.55176, -360.24243, 2.90000,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, -75.65651, -331.28595, 2.90000,   -2.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, -75.66569, -319.29504, 2.90000,   -2.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, -75.59504, -307.40961, 2.90000,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 706, -56.6094, -387.5078, 4.0469, 0.25);
    RemoveBuildingForPlayer(playerid, 780, -42.2109, -390.1563, 5.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 773, -0.8672, -387.1875, 4.4297, 0.25);
    RemoveBuildingForPlayer(playerid, 780, -23.0625, -390.1563, 5.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 780, 9.0625, -364.9453, 5.1016, 0.25);
    RemoveBuildingForPlayer(playerid, 773, -70.8359, -338.9688, 4.4297, 0.25);
    RemoveBuildingForPlayer(playerid, 12932, -117.9609, -337.4531, 3.6172, 0.25);
    RemoveBuildingForPlayer(playerid, 773, -71.7813, -312.4219, 4.4297, 0.25);
    RemoveBuildingForPlayer(playerid, 780, 10.3359, -330.1016, 5.1016, 0.25);
    RemoveBuildingForPlayer(playerid, 773, 10.0078, -298.9375, 4.4297, 0.25);
    RemoveBuildingForPlayer(playerid, 1278, 5.9609, -287.1016, 18.9844, 0.25);
    return 1;
}