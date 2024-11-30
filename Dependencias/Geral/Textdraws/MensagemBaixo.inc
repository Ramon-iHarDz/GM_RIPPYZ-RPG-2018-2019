#include <YSI_Coding\y_hooks>

new PlayerText:MensagemAbaixo[MAX_PLAYERS][1];

hook OnPlayerDisconnect(playerid, reason)
{
    MensagemAbaixo[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}

stock MostrarMensagemBaixo(playerid, const mensagem[])
{
    MensagemAbaixo[playerid][0] = CreatePlayerTextDraw(playerid, 351.875000, 429.750000, mensagem);
    PlayerTextDrawLetterSize(playerid, MensagemAbaixo[playerid][0], 0.258124, 1.104165);
    PlayerTextDrawAlignment(playerid, MensagemAbaixo[playerid][0], 2);
    PlayerTextDrawColor(playerid, MensagemAbaixo[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, MensagemAbaixo[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, MensagemAbaixo[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, MensagemAbaixo[playerid][0], 255);
    PlayerTextDrawFont(playerid, MensagemAbaixo[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, MensagemAbaixo[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, MensagemAbaixo[playerid][0], 0);
    PlayerTextDrawShow(playerid, MensagemAbaixo[playerid][0]);
    return 1;
}

stock OcultarMensagemBaixo(playerid)
{
    PlayerTextDrawDestroy(playerid, MensagemAbaixo[playerid][0]);
    MensagemAbaixo[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}