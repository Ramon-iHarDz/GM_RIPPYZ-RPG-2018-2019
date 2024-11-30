#include <YSI_Coding\y_hooks>

new PlayerText:EventoTexto[MAX_PLAYERS][3];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 3; i++){
        EventoTexto[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarTextoEvento(playerid)
{
    EventoTexto[playerid][0] = CreatePlayerTextDraw(playerid, 322.500000, 416.150268, ConverterTexto("Rippzy City~n~~r~#SuaSegundaVida"));
    PlayerTextDrawLetterSize(playerid, EventoTexto[playerid][0], 0.244375, 1.137498);
    PlayerTextDrawAlignment(playerid, EventoTexto[playerid][0], 2);
    PlayerTextDrawColor(playerid, EventoTexto[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, EventoTexto[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, EventoTexto[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, EventoTexto[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, EventoTexto[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, EventoTexto[playerid][0], 70);
    PlayerTextDrawFont(playerid, EventoTexto[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, EventoTexto[playerid][0], 1);

    EventoTexto[playerid][1] = CreatePlayerTextDraw(playerid, 352.350067, 415.150207, "Rippzy_City");
    PlayerTextDrawLetterSize(playerid, EventoTexto[playerid][1], 0.244375, 1.137498);
    PlayerTextDrawAlignment(playerid, EventoTexto[playerid][1], 2);
    PlayerTextDrawColor(playerid, EventoTexto[playerid][1], -5963521);
    PlayerTextDrawUseBox(playerid, EventoTexto[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, EventoTexto[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, EventoTexto[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, EventoTexto[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, EventoTexto[playerid][1], 70);
    PlayerTextDrawFont(playerid, EventoTexto[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, EventoTexto[playerid][1], 1);

    EventoTexto[playerid][2] = CreatePlayerTextDraw(playerid, 358.125000, 394.166351, "");
    PlayerTextDrawTextSize(playerid, EventoTexto[playerid][2], 37.000000, 41.000000);
    PlayerTextDrawAlignment(playerid, EventoTexto[playerid][2], 1);
    PlayerTextDrawColor(playerid, EventoTexto[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, EventoTexto[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, EventoTexto[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, EventoTexto[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, EventoTexto[playerid][2], 0);
    PlayerTextDrawFont(playerid, EventoTexto[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, EventoTexto[playerid][2], 0);
    PlayerTextDrawSetPreviewModel(playerid, EventoTexto[playerid][2], 18846);
    PlayerTextDrawSetPreviewRot(playerid, EventoTexto[playerid][2], -30.000000, -35.000000, 30.000000, 1.000000);

    for(new i=0; i < 3; i++){
        if(i != 0) continue;
        PlayerTextDrawShow(playerid, EventoTexto[playerid][i]);
    }

    return 1;
}

stock OcultarTextoEvento(playerid)
{
    for(new i=0; i < 3; i++){
        if(i != 0) continue;
        PlayerTextDrawDestroy(playerid, EventoTexto[playerid][i]);
        EventoTexto[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}