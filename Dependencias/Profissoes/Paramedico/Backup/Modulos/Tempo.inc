#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 2; i++)
    {
        MorteAviso[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarMorte(playerid)
{
    MorteAviso[playerid][0] = CreatePlayerTextDraw(playerid, 273.125000, 407.000000, "Aguardando_paramedico(a)");
    PlayerTextDrawLetterSize(playerid, MorteAviso[playerid][0], 0.273124, 1.319999);
    PlayerTextDrawAlignment(playerid, MorteAviso[playerid][0], 1);
    PlayerTextDrawColor(playerid, MorteAviso[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, MorteAviso[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, MorteAviso[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, MorteAviso[playerid][0], 255);
    PlayerTextDrawFont(playerid, MorteAviso[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, MorteAviso[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, MorteAviso[playerid][0], 1);

    MorteAviso[playerid][1] = CreatePlayerTextDraw(playerid, 332.724975, 426.250213, "Tempo:_~r~05:00");
    PlayerTextDrawLetterSize(playerid, MorteAviso[playerid][1], 0.239374, 1.150832);
    PlayerTextDrawTextSize(playerid, MorteAviso[playerid][1], 0.000000, 81.000000);
    PlayerTextDrawAlignment(playerid, MorteAviso[playerid][1], 2);
    PlayerTextDrawColor(playerid, MorteAviso[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, MorteAviso[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, MorteAviso[playerid][1], 105);
    PlayerTextDrawSetShadow(playerid, MorteAviso[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, MorteAviso[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, MorteAviso[playerid][1], 255);
    PlayerTextDrawFont(playerid, MorteAviso[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, MorteAviso[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, MorteAviso[playerid][1], 0);
    for(new i=0; i < 2; i++)
    {
        PlayerTextDrawShow(playerid, MorteAviso[playerid][i]);
    }
    return 1;
}

stock OcultarMorte(playerid)
{
    for(new i=0; i < 2; i++)
    {
        PlayerTextDrawDestroy(playerid, MorteAviso[playerid][i]);
        MorteAviso[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

