#include <YSI_Coding\y_hooks>

new PlayerText:BaseIf[MAX_PLAYERS][1];

hook OnPlayerDisconnect(playerid, reason)
{
    BaseIf[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}

stock MostrarBaseInfo(playerid)
{
    BaseIf[playerid][0] = CreatePlayerTextDraw(playerid, 326.544555, 430.333312, "Base_(ID:0)_[N/A]");
    PlayerTextDrawLetterSize(playerid, BaseIf[playerid][0], 0.228521, 1.092498);
    PlayerTextDrawAlignment(playerid, BaseIf[playerid][0], 2);
    PlayerTextDrawColor(playerid, BaseIf[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, BaseIf[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, BaseIf[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, BaseIf[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, BaseIf[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, BaseIf[playerid][0], 80);
    PlayerTextDrawFont(playerid, BaseIf[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BaseIf[playerid][0], 1);
    PlayerTextDrawShow(playerid, BaseIf[playerid][0]);
    return 1;
}

stock OcultarBaseInfo(playerid)
{
    PlayerTextDrawDestroy(playerid, BaseIf[playerid][0]);
    BaseIf[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}