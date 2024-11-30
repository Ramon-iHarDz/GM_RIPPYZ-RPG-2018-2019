#include <YSI_Coding\y_hooks>

new PlayerText:UberTxd[MAX_PLAYERS][5];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 5; i++){
        UberTxd[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarUber(playerid)
{
    UberTxd[playerid][0] = CreatePlayerTextDraw(playerid, 11.875000, 202.833358, "box");
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][0], 0.000000, 3.375000);
    PlayerTextDrawTextSize(playerid, UberTxd[playerid][0], 112.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][0], 1);
    PlayerTextDrawColor(playerid, UberTxd[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, UberTxd[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, UberTxd[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][0], 255);
    PlayerTextDrawFont(playerid, UberTxd[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][0], 1);

    UberTxd[playerid][1] = CreatePlayerTextDraw(playerid, 11.875000, 202.833358, "box");
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][1], 0.000000, 0.610999);
    PlayerTextDrawTextSize(playerid, UberTxd[playerid][1], 112.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][1], 1);
    PlayerTextDrawColor(playerid, UberTxd[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, UberTxd[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, UberTxd[playerid][1], -5963521);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][1], 255);
    PlayerTextDrawFont(playerid, UberTxd[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][1], 1);

    UberTxd[playerid][2] = CreatePlayerTextDraw(playerid, 13.500013, 199.783432, "Uber");
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][2], 0.243749, 1.109999);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][2], 1);
    PlayerTextDrawColor(playerid, UberTxd[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, UberTxd[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, UberTxd[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][2], 36);
    PlayerTextDrawFont(playerid, UberTxd[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][2], 1);

    UberTxd[playerid][3] = CreatePlayerTextDraw(playerid, 59.124984, 212.166580, " "); // Info
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][3], 0.278125, 1.080833);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][3], 2);
    PlayerTextDrawColor(playerid, UberTxd[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, UberTxd[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, UberTxd[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][3], 255);
    PlayerTextDrawFont(playerid, UberTxd[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][3], 1);

    UberTxd[playerid][4] = CreatePlayerTextDraw(playerid, 58.924987, 222.967239, " "); // Info Money
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][4], 0.250625, 0.952499);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][4], 2);
    PlayerTextDrawColor(playerid, UberTxd[playerid][4], 8388863);
    PlayerTextDrawUseBox(playerid, UberTxd[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, UberTxd[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, UberTxd[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][4], 255);
    PlayerTextDrawFont(playerid, UberTxd[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][4], 1);

    for(new i=0; i < 5; i++){
        PlayerTextDrawShow(playerid, UberTxd[playerid][i]);
    }
    return 1;
}

stock OcultarUber(playerid)
{
    for(new i=0; i < 5; i++){
        PlayerTextDrawDestroy(playerid, UberTxd[playerid][i]);
        UberTxd[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}