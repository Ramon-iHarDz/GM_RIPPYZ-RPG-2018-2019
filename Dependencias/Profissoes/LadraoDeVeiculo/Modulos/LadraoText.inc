#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 8; i++){
        RouboVeiculo[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarMenuRoubo(playerid)
{
    RouboVeiculo[playerid][0] = CreatePlayerTextDraw(playerid, 15.625000, 218.583343, "box");
    PlayerTextDrawLetterSize(playerid, RouboVeiculo[playerid][0], 0.000000, 10.381995);
    PlayerTextDrawTextSize(playerid, RouboVeiculo[playerid][0], 126.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, RouboVeiculo[playerid][0], 1);
    PlayerTextDrawColor(playerid, RouboVeiculo[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, RouboVeiculo[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, RouboVeiculo[playerid][0], 471604479); 
    PlayerTextDrawSetShadow(playerid, RouboVeiculo[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RouboVeiculo[playerid][0], 255);
    PlayerTextDrawFont(playerid, RouboVeiculo[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, RouboVeiculo[playerid][0], 1);

    RouboVeiculo[playerid][1] = CreatePlayerTextDraw(playerid, 15.625000, 218.583343, "box");
    PlayerTextDrawLetterSize(playerid, RouboVeiculo[playerid][1], 0.000000, 0.988005);
    PlayerTextDrawTextSize(playerid, RouboVeiculo[playerid][1], 126.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, RouboVeiculo[playerid][1], 1);
    PlayerTextDrawColor(playerid, RouboVeiculo[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, RouboVeiculo[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, RouboVeiculo[playerid][1], -5963521);
    PlayerTextDrawSetShadow(playerid, RouboVeiculo[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RouboVeiculo[playerid][1], 255);
    PlayerTextDrawFont(playerid, RouboVeiculo[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, RouboVeiculo[playerid][1], 1);

    RouboVeiculo[playerid][2] = CreatePlayerTextDraw(playerid, 73.449989, 216.666732, "Ladrao");
    PlayerTextDrawLetterSize(playerid, RouboVeiculo[playerid][2], 0.278124, 1.226665);
    PlayerTextDrawTextSize(playerid, RouboVeiculo[playerid][2], 0.000000, -2.000000);
    PlayerTextDrawAlignment(playerid, RouboVeiculo[playerid][2], 2);
    PlayerTextDrawColor(playerid, RouboVeiculo[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, RouboVeiculo[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, RouboVeiculo[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, RouboVeiculo[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, RouboVeiculo[playerid][2], 54);
    PlayerTextDrawFont(playerid, RouboVeiculo[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, RouboVeiculo[playerid][2], 1);

    RouboVeiculo[playerid][3] = CreatePlayerTextDraw(playerid, 38.750000, 214.116668, "");
    PlayerTextDrawTextSize(playerid, RouboVeiculo[playerid][3], 64.000000, 73.000000);
    PlayerTextDrawAlignment(playerid, RouboVeiculo[playerid][3], 1);
    PlayerTextDrawColor(playerid, RouboVeiculo[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, RouboVeiculo[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, RouboVeiculo[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, RouboVeiculo[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RouboVeiculo[playerid][3], 0);
    PlayerTextDrawFont(playerid, RouboVeiculo[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, RouboVeiculo[playerid][3], 0);
    PlayerTextDrawSetPreviewModel(playerid, RouboVeiculo[playerid][3], 411);
    PlayerTextDrawSetPreviewRot(playerid, RouboVeiculo[playerid][3], 0.000000, 0.000000, 60.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, RouboVeiculo[playerid][3], 1, 1);

    RouboVeiculo[playerid][4] = CreatePlayerTextDraw(playerid, 70.000000, 265.833374, "Infernus");
    PlayerTextDrawLetterSize(playerid, RouboVeiculo[playerid][4], 0.319999, 1.454166);
    PlayerTextDrawAlignment(playerid, RouboVeiculo[playerid][4], 2);
    PlayerTextDrawColor(playerid, RouboVeiculo[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, RouboVeiculo[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, RouboVeiculo[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, RouboVeiculo[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, RouboVeiculo[playerid][4], 107);
    PlayerTextDrawFont(playerid, RouboVeiculo[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, RouboVeiculo[playerid][4], 1);

    RouboVeiculo[playerid][5] = CreatePlayerTextDraw(playerid, 69.699966, 278.683441, " ");
    PlayerTextDrawLetterSize(playerid, RouboVeiculo[playerid][5], 0.218749, 1.080831);
    PlayerTextDrawAlignment(playerid, RouboVeiculo[playerid][5], 2);
    PlayerTextDrawColor(playerid, RouboVeiculo[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, RouboVeiculo[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, RouboVeiculo[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, RouboVeiculo[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, RouboVeiculo[playerid][5], 255);
    PlayerTextDrawFont(playerid, RouboVeiculo[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, RouboVeiculo[playerid][5], 1);

    RouboVeiculo[playerid][6] = CreatePlayerTextDraw(playerid, 49.475002, 295.000152, "ld_chat:thumbup");
    PlayerTextDrawTextSize(playerid, RouboVeiculo[playerid][6], 13.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, RouboVeiculo[playerid][6], 1);
    PlayerTextDrawColor(playerid, RouboVeiculo[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, RouboVeiculo[playerid][6], 0);
    PlayerTextDrawBoxColor(playerid, RouboVeiculo[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, RouboVeiculo[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, RouboVeiculo[playerid][6], 255);
    PlayerTextDrawFont(playerid, RouboVeiculo[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, RouboVeiculo[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, RouboVeiculo[playerid][6], true);

    RouboVeiculo[playerid][7] = CreatePlayerTextDraw(playerid, 77.274986, 295.000152, "ld_chat:thumbdn");
    PlayerTextDrawTextSize(playerid, RouboVeiculo[playerid][7], 13.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, RouboVeiculo[playerid][7], 1);
    PlayerTextDrawColor(playerid, RouboVeiculo[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, RouboVeiculo[playerid][7], 0);
    PlayerTextDrawBoxColor(playerid, RouboVeiculo[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, RouboVeiculo[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, RouboVeiculo[playerid][7], 255);
    PlayerTextDrawFont(playerid, RouboVeiculo[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, RouboVeiculo[playerid][7], 0);
    PlayerTextDrawSetSelectable(playerid, RouboVeiculo[playerid][7], true);

    SelectTextDrawEx(playerid, 0xFFA500FF, "OcultarMenuRoubo", true);
    for(new i=0; i < 8; i++){
        PlayerTextDrawShow(playerid, RouboVeiculo[playerid][i]);
    }
    return 1;
}

function OcultarMenuRoubo(playerid)
{
    CancelSelectTextDrawEx(playerid, "OcultarMenuRoubo"); 
    for(new i=0; i < 8; i++){
        PlayerTextDrawDestroy(playerid, RouboVeiculo[playerid][i]);
        RouboVeiculo[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}