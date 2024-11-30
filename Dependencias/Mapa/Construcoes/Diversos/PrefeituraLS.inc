#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicObject(3873,1436.6368400,-1775.8306900,29.8964000,0.0000000,0.0000000,0.0000000, -1, 0, -1, 380.0, 380.0, -1); //
    CreateDynamicObject(5882,1493.4716800,-1780.5615200,67.4567000,0.0000000,0.0000000,-90.0000000, -1, 0, -1, 380.0, 380.0, -1); //
    CreateDynamicObject(8041,1555.6665000,-1789.8898900,18.2344000,0.0000000,0.0000000,0.0000000, -1, 0, -1, 380.0, 380.0, -1); //
    CreateDynamicObject(987,1555.2684300,-1811.3925800,12.5411000,0.0000000,0.0000000,89.0000000, -1, 0, -1, 380.0, 380.0, -1); //
    CreateDynamicObject(987,1557.3498500,-1780.3070100,12.5411000,0.0000000,0.0000000,89.0000000, -1, 0, -1, 380.0, 380.0, -1); //
    CreateDynamicObject(3627,1496.8366700,-1811.9934100,16.2553000,0.0000000,0.0000000,-91.0000000, -1, 0, -1, 380.0, 380.0, -1); //
    CreateDynamicObject(8041,1529.0371100,-1833.0046400,18.1324000,0.0000000,0.0000000,-90.0000000, -1, 0, -1, 380.0, 380.0, -1); //
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 4024, 1479.8672, -1790.3984, 56.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 4044, 1481.1875, -1785.0703, 22.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 1527, 1448.2344, -1755.8984, 14.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 713, 1407.1953, -1749.3125, 13.0938, 0.25);
    RemoveBuildingForPlayer(playerid, 700, 1404.9141, -1765.2656, 12.9141, 0.25);
    RemoveBuildingForPlayer(playerid, 4173, 1427.2734, -1756.1797, 15.0000, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1415.3125, -1748.5625, 12.3984, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1429.5313, -1748.4219, 12.9063, 0.25);
    RemoveBuildingForPlayer(playerid, 700, 1438.0313, -1747.9375, 13.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1447.9063, -1748.2266, 12.9063, 0.25);
    RemoveBuildingForPlayer(playerid, 4002, 1479.8672, -1790.3984, 56.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 3980, 1481.1875, -1785.0703, 22.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 4003, 1481.0781, -1747.0313, 33.5234, 0.25);
    return 1;
}