#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 3; i++){
        Federal[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarRelogioPrisao(playerid)
{
    Federal[playerid][0] = CreatePlayerTextDraw(playerid, 21.537330, 307.249969, "box");
    PlayerTextDrawLetterSize(playerid, Federal[playerid][0], 0.000000, 1.426063);
    PlayerTextDrawTextSize(playerid, Federal[playerid][0], 106.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, Federal[playerid][0], 1);
    PlayerTextDrawColor(playerid, Federal[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, Federal[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, Federal[playerid][0], 66);
    PlayerTextDrawSetShadow(playerid, Federal[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, Federal[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, Federal[playerid][0], 255);
    PlayerTextDrawFont(playerid, Federal[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, Federal[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, Federal[playerid][0], 0);

    Federal[playerid][1] = CreatePlayerTextDraw(playerid, 16.683763, 305.250305, "");
    PlayerTextDrawLetterSize(playerid, Federal[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, Federal[playerid][1], 25.000000, 26.000000);
    PlayerTextDrawAlignment(playerid, Federal[playerid][1], 1);
    PlayerTextDrawColor(playerid, Federal[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, Federal[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Federal[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, Federal[playerid][1], 0);
    PlayerTextDrawFont(playerid, Federal[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, Federal[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, Federal[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, Federal[playerid][1], 11750);
    PlayerTextDrawSetPreviewRot(playerid, Federal[playerid][1], 60.000000, 0.000000, -180.000000, 1.000000);

    Federal[playerid][2] = CreatePlayerTextDraw(playerid, 66.889488, 307.350036, "00:00:00");
    PlayerTextDrawLetterSize(playerid, Federal[playerid][2], 0.257100, 1.226666);
    PlayerTextDrawAlignment(playerid, Federal[playerid][2], 2);
    PlayerTextDrawColor(playerid, Federal[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, Federal[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, Federal[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, Federal[playerid][2], 255);
    PlayerTextDrawFont(playerid, Federal[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, Federal[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, Federal[playerid][2], 0);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, Federal[playerid][i]);
    }
    return 1;
}

stock RemoverRelogioPrisao(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, Federal[playerid][i]);
        Federal[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}