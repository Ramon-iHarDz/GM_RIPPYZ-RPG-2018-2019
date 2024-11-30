#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicObject(3749, 1879.60437, 702.70380, 15.40000,   0.00000, 0.00000, 90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, 1877.79895, 694.06696, 9.81590,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, 1877.79382, 723.34216, 9.81590,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, 1977.11011, 704.80157, 9.82110,   0.00000, 0.00000, 90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(987, 1977.06519, 692.86292, 9.82110,   0.00000, 0.00000, 90.00000, -1, 0, -1, 450.0, 450.0, -1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 1344, 1878.6484, 683.7734, 10.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 625, 1879.0547, 698.9141, 10.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 625, 1879.0547, 710.3359, 10.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 1343, 1976.6797, 693.7109, 10.5625, 0.25);
    RemoveBuildingForPlayer(playerid, 625, 1978.2031, 698.9141, 10.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 625, 1978.2031, 710.0156, 10.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 1294, 1871.6875, 717.3828, 14.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 1343, 1877.8828, 722.7344, 10.5625, 0.25);
    return 1;
}