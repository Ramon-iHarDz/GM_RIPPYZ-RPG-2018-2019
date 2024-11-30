#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicObject(3749, -489.02771, -561.75238, 30.20000,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(3934, -607.42719, -488.91089, 24.52540,   0.00000, 0.00000, -91.00000, -1, 0, -1, 450.0, 450.0, -1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 17019, -606.0313, -528.8203, 30.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 1441, -503.6172, -540.5313, 25.2266, 0.25);
    RemoveBuildingForPlayer(playerid, 1440, -502.1172, -521.0313, 25.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 1441, -502.4063, -513.0156, 25.2266, 0.25);
    RemoveBuildingForPlayer(playerid, 1415, -620.4141, -490.5078, 24.5859, 0.25);
    RemoveBuildingForPlayer(playerid, 1415, -619.6250, -473.4531, 24.5859, 0.25);
    RemoveBuildingForPlayer(playerid, 1440, -503.1250, -509.0000, 25.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 17020, -475.9766, -544.8516, 28.1172, 0.25);
    return 1;
}