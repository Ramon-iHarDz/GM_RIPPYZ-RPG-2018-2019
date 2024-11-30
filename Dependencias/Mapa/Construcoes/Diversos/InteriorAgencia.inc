#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 1502, 365.7969, 189.6172, 1007.3750, 0.25);
    return 1;
}

hook OnGameModeInit()
{
    CreateObject(19802, 371.25168, 166.65636, 1007.38098,   0.00000, 0.00000, 0.00000);
    CreateObject(19802, 365.77991, 189.40050, 1007.38159,   0.00000, 0.00000, 0.00000);
    return 1;
}