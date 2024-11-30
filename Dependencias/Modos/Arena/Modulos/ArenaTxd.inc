#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 9; i++){
        ArenaKD[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarArenaKD(playerid, const Inff[] = "Arena") 
{
    ArenaKD[playerid][0] = CreatePlayerTextDraw(playerid, 16.852151, 251.216567, "box");
    PlayerTextDrawLetterSize(playerid, ArenaKD[playerid][0], 0.000000, 6.844686);
    PlayerTextDrawTextSize(playerid, ArenaKD[playerid][0], 99.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ArenaKD[playerid][0], 1);
    PlayerTextDrawColor(playerid, ArenaKD[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, ArenaKD[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, ArenaKD[playerid][0], 471604393);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ArenaKD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ArenaKD[playerid][0], 255);
    PlayerTextDrawFont(playerid, ArenaKD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ArenaKD[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][0], 0);

    ArenaKD[playerid][1] = CreatePlayerTextDraw(playerid, 16.852151, 250.916549, "box");
    PlayerTextDrawLetterSize(playerid, ArenaKD[playerid][1], 0.000000, 0.838682);
    PlayerTextDrawTextSize(playerid, ArenaKD[playerid][1], 99.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ArenaKD[playerid][1], 1);
    PlayerTextDrawColor(playerid, ArenaKD[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, ArenaKD[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, ArenaKD[playerid][1], -1061109505);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ArenaKD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ArenaKD[playerid][1], 255);
    PlayerTextDrawFont(playerid, ArenaKD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ArenaKD[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][1], 0);

    ArenaKD[playerid][2] = CreatePlayerTextDraw(playerid, 10.592777, 246.850204, Inff);
    PlayerTextDrawLetterSize(playerid, ArenaKD[playerid][2], 0.171830, 0.789167);
    PlayerTextDrawTextSize(playerid, ArenaKD[playerid][2], 28.199989, 0.000000);
    PlayerTextDrawAlignment(playerid, ArenaKD[playerid][2], 1);
    PlayerTextDrawColor(playerid, ArenaKD[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, ArenaKD[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, ArenaKD[playerid][2], -5963521);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ArenaKD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ArenaKD[playerid][2], 255);
    PlayerTextDrawFont(playerid, ArenaKD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ArenaKD[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][2], 0);

    ArenaKD[playerid][3] = CreatePlayerTextDraw(playerid, 36.846820, 248.449996, "Informacoes");
    PlayerTextDrawLetterSize(playerid, ArenaKD[playerid][3], 0.229926, 1.191666);
    PlayerTextDrawAlignment(playerid, ArenaKD[playerid][3], 1);
    PlayerTextDrawColor(playerid, ArenaKD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ArenaKD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ArenaKD[playerid][3], 255);
    PlayerTextDrawFont(playerid, ArenaKD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, ArenaKD[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][3], 0);

    ArenaKD[playerid][4] = CreatePlayerTextDraw(playerid, 4.970720, 267.199981, "");
    PlayerTextDrawLetterSize(playerid, ArenaKD[playerid][4], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, ArenaKD[playerid][4], 55.000000, 24.000000);
    PlayerTextDrawAlignment(playerid, ArenaKD[playerid][4], 1);
    PlayerTextDrawColor(playerid, ArenaKD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ArenaKD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ArenaKD[playerid][4], 0);
    PlayerTextDrawFont(playerid, ArenaKD[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, ArenaKD[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, ArenaKD[playerid][4], 335);
    PlayerTextDrawSetPreviewRot(playerid, ArenaKD[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);

    ArenaKD[playerid][5] = CreatePlayerTextDraw(playerid, 18.089313, 292.699951, "");
    PlayerTextDrawLetterSize(playerid, ArenaKD[playerid][5], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, ArenaKD[playerid][5], 14.000000, 18.000000);
    PlayerTextDrawAlignment(playerid, ArenaKD[playerid][5], 1);
    PlayerTextDrawColor(playerid, ArenaKD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ArenaKD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ArenaKD[playerid][5], 0);
    PlayerTextDrawFont(playerid, ArenaKD[playerid][5], 5);
    PlayerTextDrawSetProportional(playerid, ArenaKD[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][5], 0);
    PlayerTextDrawSetPreviewModel(playerid, ArenaKD[playerid][5], 1254);
    PlayerTextDrawSetPreviewRot(playerid, ArenaKD[playerid][5], 0.000000, 0.000000, 0.000000, 1.000000);

    ArenaKD[playerid][6] = CreatePlayerTextDraw(playerid, 34.655929, 269.333251, "~g~N/A");
    PlayerTextDrawLetterSize(playerid, ArenaKD[playerid][6], 0.284275, 1.238333);
    PlayerTextDrawAlignment(playerid, ArenaKD[playerid][6], 1);
    PlayerTextDrawColor(playerid, ArenaKD[playerid][6], 8388863);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ArenaKD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ArenaKD[playerid][6], 255);
    PlayerTextDrawFont(playerid, ArenaKD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, ArenaKD[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][6], 0);

    ArenaKD[playerid][7] = CreatePlayerTextDraw(playerid, 34.655929, 293.400054, "~r~N/A");
    PlayerTextDrawLetterSize(playerid, ArenaKD[playerid][7], 0.284275, 1.238333);
    PlayerTextDrawAlignment(playerid, ArenaKD[playerid][7], 1);
    PlayerTextDrawColor(playerid, ArenaKD[playerid][7], -16776961);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ArenaKD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ArenaKD[playerid][7], 255);
    PlayerTextDrawFont(playerid, ArenaKD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, ArenaKD[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][7], 0);

    ArenaKD[playerid][8] = CreatePlayerTextDraw(playerid, 14.509544, 317.166625, "#Rippzy");
    PlayerTextDrawLetterSize(playerid, ArenaKD[playerid][8], 0.233206, 1.022499);
    PlayerTextDrawAlignment(playerid, ArenaKD[playerid][8], 1);
    PlayerTextDrawColor(playerid, ArenaKD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ArenaKD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ArenaKD[playerid][8], 255);
    PlayerTextDrawFont(playerid, ArenaKD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, ArenaKD[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, ArenaKD[playerid][8], 0);

    for(new i=0; i < 9; i++){
        PlayerTextDrawShow(playerid, ArenaKD[playerid][i]);
    }
    return 1;
}

stock OcultarArenaKD(playerid)
{
    for(new i=0; i < 9; i++){
        PlayerTextDrawDestroy(playerid, ArenaKD[playerid][i]);
        ArenaKD[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}