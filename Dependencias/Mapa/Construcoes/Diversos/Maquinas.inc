#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 955, 0.0, 0.0, 0.0, 99999.0);
    RemoveBuildingForPlayer(playerid, 956, 0.0, 0.0, 0.0, 99999.0); 
    RemoveBuildingForPlayer(playerid, 1302, 0.0, 0.0, 0.0, 99999.0); 
    RemoveBuildingForPlayer(playerid, 1209, 0.0, 0.0, 0.0, 99999.0); 
    RemoveBuildingForPlayer(playerid, 1776, 0.0, 0.0, 0.0, 99999.0); 
    RemoveBuildingForPlayer(playerid, 1775, 0.0, 0.0, 0.0, 99999.0); 
    return 1;
}