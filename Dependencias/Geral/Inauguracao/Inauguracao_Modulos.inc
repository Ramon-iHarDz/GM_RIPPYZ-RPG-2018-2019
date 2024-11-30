#include <YSI_Coding\y_hooks>

new PlayerText:InauT[MAX_PLAYERS][5];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 5; i++){
        InauT[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarInau(playerid)
{
    InauT[playerid][0] = CreatePlayerTextDraw(playerid, 242.579345, 161.416671, "box");
    PlayerTextDrawLetterSize(playerid, InauT[playerid][0], 0.000000, 9.129940);
    PlayerTextDrawTextSize(playerid, InauT[playerid][0], 400.899993, 0.000000);
    PlayerTextDrawAlignment(playerid, InauT[playerid][0], 1);
    PlayerTextDrawColor(playerid, InauT[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, InauT[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, InauT[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, InauT[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, InauT[playerid][0], 255);
    PlayerTextDrawFont(playerid, InauT[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, InauT[playerid][0], 1);

    InauT[playerid][1] = CreatePlayerTextDraw(playerid, 315.026062, 170.483306, "R");
    PlayerTextDrawLetterSize(playerid, InauT[playerid][1], 0.506823, 2.072499);
    PlayerTextDrawAlignment(playerid, InauT[playerid][1], 1);
    PlayerTextDrawColor(playerid, InauT[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, InauT[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, InauT[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, InauT[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, InauT[playerid][1], 255);
    PlayerTextDrawFont(playerid, InauT[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, InauT[playerid][1], 1);

    InauT[playerid][2] = CreatePlayerTextDraw(playerid, 319.574218, 177.483322, "C");
    PlayerTextDrawLetterSize(playerid, InauT[playerid][2], 0.506823, 2.072499);
    PlayerTextDrawAlignment(playerid, InauT[playerid][2], 1);
    PlayerTextDrawColor(playerid, InauT[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, InauT[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, InauT[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, InauT[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, InauT[playerid][2], 255);
    PlayerTextDrawFont(playerid, InauT[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, InauT[playerid][2], 1);

    InauT[playerid][3] = CreatePlayerTextDraw(playerid, 321.897644, 198.033355, "Inauguracao");
    PlayerTextDrawLetterSize(playerid, InauT[playerid][3], 0.263660, 1.442499);
    PlayerTextDrawAlignment(playerid, InauT[playerid][3], 2);
    PlayerTextDrawColor(playerid, InauT[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, InauT[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, InauT[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, InauT[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InauT[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, InauT[playerid][3], 37);
    PlayerTextDrawFont(playerid, InauT[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, InauT[playerid][3], 1);

    InauT[playerid][4] = CreatePlayerTextDraw(playerid, 321.747833, 215.366668, "00:00:00");
    PlayerTextDrawLetterSize(playerid, InauT[playerid][4], 0.393020, 1.780832);
    PlayerTextDrawAlignment(playerid, InauT[playerid][4], 2);
    PlayerTextDrawColor(playerid, InauT[playerid][4], -5963521);
    PlayerTextDrawUseBox(playerid, InauT[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, InauT[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, InauT[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InauT[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, InauT[playerid][4], 27);
    PlayerTextDrawFont(playerid, InauT[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, InauT[playerid][4], 1);

    for(new i=0; i < 5; i++){
        PlayerTextDrawShow(playerid, InauT[playerid][i]);
    }
    return 1;
}

stock OcultarInau(playerid)
{
    for(new i=0; i < 5; i++){
        PlayerTextDrawDestroy(playerid, InauT[playerid][i]);
        InauT[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}