#include <YSI_Coding\y_hooks>

new PlayerText:RouboDraw[MAX_PLAYERS][3];

hook OnPlayerDisconnect(playerid, reason){
    for(new i=0; i < 3; i++){
        RouboDraw[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarTempoRoubo(playerid){
    RouboDraw[playerid][0] = CreatePlayerTextDraw(playerid, 588.386657, 200.499908, "box");
    PlayerTextDrawLetterSize(playerid, RouboDraw[playerid][0], 0.000000, 1.191802);
    PlayerTextDrawTextSize(playerid, RouboDraw[playerid][0], 632.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, RouboDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, RouboDraw[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, RouboDraw[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, RouboDraw[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, RouboDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RouboDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, RouboDraw[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, RouboDraw[playerid][0], 1);

    RouboDraw[playerid][1] = CreatePlayerTextDraw(playerid, 609.562316, 200.016845, "00:00");
    PlayerTextDrawLetterSize(playerid, RouboDraw[playerid][1], 0.275373, 1.162499);
    PlayerTextDrawAlignment(playerid, RouboDraw[playerid][1], 2);
    PlayerTextDrawColor(playerid, RouboDraw[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, RouboDraw[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, RouboDraw[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, RouboDraw[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RouboDraw[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, RouboDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, RouboDraw[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, RouboDraw[playerid][1], 1);

    RouboDraw[playerid][2] = CreatePlayerTextDraw(playerid, 588.386657, 215.299682, "box");
    PlayerTextDrawLetterSize(playerid, RouboDraw[playerid][2], 0.000000, -0.418197);
    PlayerTextDrawTextSize(playerid, RouboDraw[playerid][2], 632.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, RouboDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, RouboDraw[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, RouboDraw[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, RouboDraw[playerid][2], -56286977);
    PlayerTextDrawSetShadow(playerid, RouboDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RouboDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, RouboDraw[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, RouboDraw[playerid][2], 1);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, RouboDraw[playerid][i]);
    }
    return 1;
}

stock OcultarTempoRoubo(playerid){
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, RouboDraw[playerid][i]);
        RouboDraw[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}