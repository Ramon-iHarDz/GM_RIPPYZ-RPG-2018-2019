#include <YSI_Coding\y_hooks>



hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("", color, 90.5170,-301.8167,1.5781, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1)
    return 1;
}

CMD:cargas(playerid)
{
    
    return 1;
}