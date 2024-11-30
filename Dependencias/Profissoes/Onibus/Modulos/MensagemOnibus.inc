#include <YSI_Coding\y_hooks>

new PlayerText:OnibusMensagem[MAX_PLAYERS][1];

hook OnPlayerDisconnect(playerid, reason)
{
    OnibusMensagem[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}

stock MostrarEmbarque(playerid)
{
    OnibusMensagem[playerid][0] = CreatePlayerTextDraw(playerid, 261.875000, 115.333358, "Aguarde,_embarcando...");
    PlayerTextDrawLetterSize(playerid, OnibusMensagem[playerid][0], 0.338749, 1.442499);
    PlayerTextDrawTextSize(playerid, OnibusMensagem[playerid][0], 395.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, OnibusMensagem[playerid][0], 1);
    PlayerTextDrawColor(playerid, OnibusMensagem[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, OnibusMensagem[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, OnibusMensagem[playerid][0], -16777186);
    PlayerTextDrawSetShadow(playerid, OnibusMensagem[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, OnibusMensagem[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, OnibusMensagem[playerid][0], 255);
    PlayerTextDrawFont(playerid, OnibusMensagem[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, OnibusMensagem[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, OnibusMensagem[playerid][0], 1);
    PlayerTextDrawShow(playerid, OnibusMensagem[playerid][0]);
    return 1;
}

stock OcultarEmbarque(playerid)
{
    PlayerTextDrawDestroy(playerid, OnibusMensagem[playerid][0]);
    OnibusMensagem[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}