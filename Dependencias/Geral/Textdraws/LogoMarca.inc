#include <YSI_Coding\y_hooks>

new PlayerText:MarcaRC[MAX_PLAYERS][4];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 4; i++)
    {
        MarcaRC[playerid][i] = PlayerText:INVALID_TEXT_DRAW;   
    }
    return 1;
}

stock MostrarMarca(playerid)
{
    MarcaRC[playerid][0] = CreatePlayerTextDraw(playerid, 326.544586, 7.416667, "R");
    PlayerTextDrawLetterSize(playerid, MarcaRC[playerid][0], 0.452005, 2.253333);
    PlayerTextDrawTextSize(playerid, MarcaRC[playerid][0], 0.000000, -5.000000);
    PlayerTextDrawAlignment(playerid, MarcaRC[playerid][0], 2);
    PlayerTextDrawColor(playerid, MarcaRC[playerid][0], -5963521);
    PlayerTextDrawUseBox(playerid, MarcaRC[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, MarcaRC[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, MarcaRC[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, MarcaRC[playerid][0], 100);
    PlayerTextDrawFont(playerid, MarcaRC[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, MarcaRC[playerid][0], 1);

    MarcaRC[playerid][1] = CreatePlayerTextDraw(playerid, 330.761352, 15.000001, "C");
    PlayerTextDrawLetterSize(playerid, MarcaRC[playerid][1], 0.452005, 2.253333);
    PlayerTextDrawTextSize(playerid, MarcaRC[playerid][1], 0.000000, -5.000000);
    PlayerTextDrawAlignment(playerid, MarcaRC[playerid][1], 2);
    PlayerTextDrawColor(playerid, MarcaRC[playerid][1], -5963521);
    PlayerTextDrawUseBox(playerid, MarcaRC[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, MarcaRC[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, MarcaRC[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, MarcaRC[playerid][1], 100);
    PlayerTextDrawFont(playerid, MarcaRC[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, MarcaRC[playerid][1], 1);

    MarcaRC[playerid][2] = CreatePlayerTextDraw(playerid, 319.150085, 20.200006, "Servidor");
    PlayerTextDrawLetterSize(playerid, MarcaRC[playerid][2], 0.176830, 0.864999);
    PlayerTextDrawTextSize(playerid, MarcaRC[playerid][2], 74.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, MarcaRC[playerid][2], 3);
    PlayerTextDrawColor(playerid, MarcaRC[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, MarcaRC[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, MarcaRC[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, MarcaRC[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, MarcaRC[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, MarcaRC[playerid][2], 35);
    PlayerTextDrawFont(playerid, MarcaRC[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, MarcaRC[playerid][2], 1);

    MarcaRC[playerid][3] = CreatePlayerTextDraw(playerid, 339.506896, 20.383335, "Beta");
    PlayerTextDrawLetterSize(playerid, MarcaRC[playerid][3], 0.176830, 0.864999);
    PlayerTextDrawTextSize(playerid, MarcaRC[playerid][3], 74.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, MarcaRC[playerid][3], 1);
    PlayerTextDrawColor(playerid, MarcaRC[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, MarcaRC[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, MarcaRC[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, MarcaRC[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, MarcaRC[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, MarcaRC[playerid][3], 35);
    PlayerTextDrawFont(playerid, MarcaRC[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, MarcaRC[playerid][3], 1);

    for(new i=0; i < 4; i++)
    {
        PlayerTextDrawShow(playerid, MarcaRC[playerid][i]);
    }
    return 1;
}