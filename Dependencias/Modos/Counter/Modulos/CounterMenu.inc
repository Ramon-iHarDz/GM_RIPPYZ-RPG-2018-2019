#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 8; i++){
        CounterMenu[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarCounter(playerid)
{
    CounterMenu[playerid][0] = CreatePlayerTextDraw(playerid, 16.875000, 167.250015, "box");
    PlayerTextDrawLetterSize(playerid, CounterMenu[playerid][0], 0.000000, 8.438504);
    PlayerTextDrawTextSize(playerid, CounterMenu[playerid][0], 87.079956, 0.000000);
    PlayerTextDrawAlignment(playerid, CounterMenu[playerid][0], 1);
    PlayerTextDrawColor(playerid, CounterMenu[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CounterMenu[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CounterMenu[playerid][0], 71);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, CounterMenu[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CounterMenu[playerid][0], 255);
    PlayerTextDrawFont(playerid, CounterMenu[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CounterMenu[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][0], 0);

    CounterMenu[playerid][1] = CreatePlayerTextDraw(playerid, 22.824996, 171.116729, "Counter_War");
    PlayerTextDrawLetterSize(playerid, CounterMenu[playerid][1], 0.283124, 1.238332);
    PlayerTextDrawAlignment(playerid, CounterMenu[playerid][1], 1);
    PlayerTextDrawColor(playerid, CounterMenu[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, CounterMenu[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CounterMenu[playerid][1], 255);
    PlayerTextDrawFont(playerid, CounterMenu[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CounterMenu[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][1], 1);

    CounterMenu[playerid][2] = CreatePlayerTextDraw(playerid, 20.850006, 214.716888, "");
    PlayerTextDrawLetterSize(playerid, CounterMenu[playerid][2], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, CounterMenu[playerid][2], 20.000000, 21.000000);
    PlayerTextDrawAlignment(playerid, CounterMenu[playerid][2], 1);
    PlayerTextDrawColor(playerid, CounterMenu[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, CounterMenu[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CounterMenu[playerid][2], 0);
    PlayerTextDrawFont(playerid, CounterMenu[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, CounterMenu[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][2], 0);
    PlayerTextDrawSetPreviewModel(playerid, CounterMenu[playerid][2], 1254);
    PlayerTextDrawSetPreviewRot(playerid, CounterMenu[playerid][2], 0.000000, 0.000000, 0.000000, 1.000000);

    CounterMenu[playerid][3] = CreatePlayerTextDraw(playerid, 17.850006, 187.716888, "");
    PlayerTextDrawLetterSize(playerid, CounterMenu[playerid][3], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, CounterMenu[playerid][3], 25.000000, 23.000000);
    PlayerTextDrawAlignment(playerid, CounterMenu[playerid][3], 1);
    PlayerTextDrawColor(playerid, CounterMenu[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, CounterMenu[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, CounterMenu[playerid][3], 0);
    PlayerTextDrawFont(playerid, CounterMenu[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, CounterMenu[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][3], 0);
    PlayerTextDrawSetPreviewModel(playerid, CounterMenu[playerid][3], 1313);
    PlayerTextDrawSetPreviewRot(playerid, CounterMenu[playerid][3], 0.000000, 0.000000, 0.000000, 1.000000);

    CounterMenu[playerid][4] = CreatePlayerTextDraw(playerid, 43.175003, 194.499984, "0");
    PlayerTextDrawLetterSize(playerid, CounterMenu[playerid][4], 0.244999, 1.150833);
    PlayerTextDrawAlignment(playerid, CounterMenu[playerid][4], 1);
    PlayerTextDrawColor(playerid, CounterMenu[playerid][4], 8388863);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, CounterMenu[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, CounterMenu[playerid][4], 255);
    PlayerTextDrawFont(playerid, CounterMenu[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, CounterMenu[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][4], 0);

    CounterMenu[playerid][5] = CreatePlayerTextDraw(playerid, 41.675006, 218.800231, "0");
    PlayerTextDrawLetterSize(playerid, CounterMenu[playerid][5], 0.245624, 1.162500);
    PlayerTextDrawAlignment(playerid, CounterMenu[playerid][5], 1);
    PlayerTextDrawColor(playerid, CounterMenu[playerid][5], -2147483393);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, CounterMenu[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, CounterMenu[playerid][5], 255);
    PlayerTextDrawFont(playerid, CounterMenu[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, CounterMenu[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][5], 0);

    CounterMenu[playerid][6] = CreatePlayerTextDraw(playerid, 49.700000, 234.633255, "RC");
    PlayerTextDrawLetterSize(playerid, CounterMenu[playerid][6], 0.188125, 0.794999);
    PlayerTextDrawAlignment(playerid, CounterMenu[playerid][6], 1);
    PlayerTextDrawColor(playerid, CounterMenu[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, CounterMenu[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, CounterMenu[playerid][6], 255);
    PlayerTextDrawFont(playerid, CounterMenu[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, CounterMenu[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][6], 0);  

    CounterMenu[playerid][7] = CreatePlayerTextDraw(playerid, 25.974996, 247.749969, "Tempo:_~r~Desligado");
    PlayerTextDrawLetterSize(playerid, CounterMenu[playerid][7], 0.217499, 0.900000);
    PlayerTextDrawAlignment(playerid, CounterMenu[playerid][7], 1);
    PlayerTextDrawColor(playerid, CounterMenu[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, CounterMenu[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, CounterMenu[playerid][7], 255);
    PlayerTextDrawFont(playerid, CounterMenu[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, CounterMenu[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, CounterMenu[playerid][7], 0);

    for(new i=0; i < 8; i++){
        PlayerTextDrawShow(playerid, CounterMenu[playerid][i]);
    }
    return 1;
}

stock OcultarCounter(playerid){
    for(new i=0; i < 8; i++){
        PlayerTextDrawDestroy(playerid, CounterMenu[playerid][i]);
        CounterMenu[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}