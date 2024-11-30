#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 5; i++){
        RadarRC[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarRadarBox(playerid)
{
    RadarRC[playerid][0] = CreatePlayerTextDraw(playerid, 6.250000, 285.666351, "box");
    PlayerTextDrawLetterSize(playerid, RadarRC[playerid][0], 0.000000, 1.937500);
    PlayerTextDrawTextSize(playerid, RadarRC[playerid][0], 5.319982, 0.000000);
    PlayerTextDrawAlignment(playerid, RadarRC[playerid][0], 1);
    PlayerTextDrawColor(playerid, RadarRC[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, RadarRC[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, RadarRC[playerid][0], -1061109505);
    PlayerTextDrawSetShadow(playerid, RadarRC[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RadarRC[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RadarRC[playerid][0], 255);
    PlayerTextDrawFont(playerid, RadarRC[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, RadarRC[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, RadarRC[playerid][0], 0);

    RadarRC[playerid][1] = CreatePlayerTextDraw(playerid, 6.250000, 285.666351, "box");
    PlayerTextDrawLetterSize(playerid, RadarRC[playerid][1], 0.000000, 1.937500);
    PlayerTextDrawTextSize(playerid, RadarRC[playerid][1], 4.609939, 0.000000);
    PlayerTextDrawAlignment(playerid, RadarRC[playerid][1], 1);
    PlayerTextDrawColor(playerid, RadarRC[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, RadarRC[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, RadarRC[playerid][1], 471604479);
    PlayerTextDrawSetShadow(playerid, RadarRC[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RadarRC[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RadarRC[playerid][1], 255);
    PlayerTextDrawFont(playerid, RadarRC[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, RadarRC[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, RadarRC[playerid][1], 0);

    PlayerTextDrawShow(playerid, RadarRC[playerid][0]);
    PlayerTextDrawShow(playerid, RadarRC[playerid][1]);
    return 1;
}

stock MostrarRadar(playerid)
{
    RadarRC[playerid][2] = CreatePlayerTextDraw(playerid, 46.575004, 288.783508, "Velocidade:_90_Km/h");
    PlayerTextDrawLetterSize(playerid, RadarRC[playerid][2], 0.209374, 1.168332);
    PlayerTextDrawAlignment(playerid, RadarRC[playerid][2], 2);
    PlayerTextDrawColor(playerid, RadarRC[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, RadarRC[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RadarRC[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RadarRC[playerid][2], 255);
    PlayerTextDrawFont(playerid, RadarRC[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, RadarRC[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, RadarRC[playerid][2], 0);

    RadarRC[playerid][3] = CreatePlayerTextDraw(playerid, 8.199999, 271.783386, "Radar");
    PlayerTextDrawLetterSize(playerid, RadarRC[playerid][3], 0.257499, 1.191665);
    PlayerTextDrawAlignment(playerid, RadarRC[playerid][3], 1);
    PlayerTextDrawColor(playerid, RadarRC[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, RadarRC[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RadarRC[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RadarRC[playerid][3], 255);
    PlayerTextDrawFont(playerid, RadarRC[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, RadarRC[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, RadarRC[playerid][3], 0);

    PlayerTextDrawShow(playerid, RadarRC[playerid][2]);
    PlayerTextDrawShow(playerid, RadarRC[playerid][3]);
    return 1;
}

function OcultarRadar(playerid)
{
    for(new i=0; i < 4; i++){
        PlayerTextDrawDestroy(playerid, RadarRC[playerid][i]);
        RadarRC[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}