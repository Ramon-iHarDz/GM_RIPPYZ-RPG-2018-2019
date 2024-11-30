#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    LocalizarComando[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}

stock MostrarLocalizador(playerid)
{
    LocalizarComando[playerid][0] = CreatePlayerTextDraw(playerid, 344.375000, 404.816558, " ");
    PlayerTextDrawLetterSize(playerid, LocalizarComando[playerid][0], 0.235000, 1.133332);
    PlayerTextDrawAlignment(playerid, LocalizarComando[playerid][0], 2);
    PlayerTextDrawColor(playerid, LocalizarComando[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, LocalizarComando[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, LocalizarComando[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, LocalizarComando[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, LocalizarComando[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, LocalizarComando[playerid][0], 117);
    PlayerTextDrawFont(playerid, LocalizarComando[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, LocalizarComando[playerid][0], 1);
    PlayerTextDrawShow(playerid, LocalizarComando[playerid][0]);
    return 1;
}

stock OcultarLocalizador(playerid)
{
    PlayerTextDrawDestroy(playerid, LocalizarComando[playerid][0]);
    LocalizarComando[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}