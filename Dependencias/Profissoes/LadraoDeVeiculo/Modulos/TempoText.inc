#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 3; i++){
        TempoAssalto[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarTempoAssalto(playerid)
{
    TempoAssalto[playerid][0] = CreatePlayerTextDraw(playerid, 543.750000, 211.000045, "box");
    PlayerTextDrawLetterSize(playerid, TempoAssalto[playerid][0], 0.000000, 1.750000);
    PlayerTextDrawTextSize(playerid, TempoAssalto[playerid][0], 631.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, TempoAssalto[playerid][0], 1);
    PlayerTextDrawColor(playerid, TempoAssalto[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, TempoAssalto[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, TempoAssalto[playerid][0], -1061109692);
    PlayerTextDrawSetShadow(playerid, TempoAssalto[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TempoAssalto[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TempoAssalto[playerid][0], 255);
    PlayerTextDrawFont(playerid, TempoAssalto[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, TempoAssalto[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TempoAssalto[playerid][0], 0);

    TempoAssalto[playerid][1] = CreatePlayerTextDraw(playerid, 586.394042, 213.649856, "Tempo:_00:05:00");
    PlayerTextDrawLetterSize(playerid, TempoAssalto[playerid][1], 0.216249, 1.086665);
    PlayerTextDrawAlignment(playerid, TempoAssalto[playerid][1], 2);
    PlayerTextDrawColor(playerid, TempoAssalto[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TempoAssalto[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, TempoAssalto[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TempoAssalto[playerid][1], 255);
    PlayerTextDrawFont(playerid, TempoAssalto[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, TempoAssalto[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TempoAssalto[playerid][1], 0);

    TempoAssalto[playerid][2] = CreatePlayerTextDraw(playerid, 574.600097, 229.299987, "Rippzy");
    PlayerTextDrawLetterSize(playerid, TempoAssalto[playerid][2], 0.219999, 0.917499);
    PlayerTextDrawAlignment(playerid, TempoAssalto[playerid][2], 1);
    PlayerTextDrawColor(playerid, TempoAssalto[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, TempoAssalto[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TempoAssalto[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, TempoAssalto[playerid][2], 255);
    PlayerTextDrawFont(playerid, TempoAssalto[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, TempoAssalto[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TempoAssalto[playerid][2], 0);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, TempoAssalto[playerid][i]);
    }
    return 1;
}

stock OcultarTempoAssalto(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, TempoAssalto[playerid][i]);
        TempoAssalto[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}