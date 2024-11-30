#include <YSI_Coding\y_hooks>

new PlayerText:GasolinaTexto[MAX_PLAYERS][1];

hook OnPlayerDisconnect(playerid, reason)
{
    GasolinaTexto[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    for(new i=0; i < 6; i++){
        AbastecimentoPosto[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarAbastecimento(playerid)
{
    AbastecimentoPosto[playerid][0] = CreatePlayerTextDraw(playerid, 6.250000, 243.666717, "box");
    PlayerTextDrawLetterSize(playerid, AbastecimentoPosto[playerid][0], 0.000000, 8.125000);
    PlayerTextDrawTextSize(playerid, AbastecimentoPosto[playerid][0], 85.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, AbastecimentoPosto[playerid][0], 1);
    PlayerTextDrawColor(playerid, AbastecimentoPosto[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, AbastecimentoPosto[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, AbastecimentoPosto[playerid][0], 102);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, AbastecimentoPosto[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, AbastecimentoPosto[playerid][0], 104);
    PlayerTextDrawFont(playerid, AbastecimentoPosto[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, AbastecimentoPosto[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][0], 0);

    AbastecimentoPosto[playerid][1] = CreatePlayerTextDraw(playerid, 11.374979, 246.250106, "Combustivel");
    PlayerTextDrawLetterSize(playerid, AbastecimentoPosto[playerid][1], 0.312499, 1.232498);
    PlayerTextDrawAlignment(playerid, AbastecimentoPosto[playerid][1], 1);
    PlayerTextDrawColor(playerid, AbastecimentoPosto[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, AbastecimentoPosto[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, AbastecimentoPosto[playerid][1], 255);
    PlayerTextDrawFont(playerid, AbastecimentoPosto[playerid][1], 3);
    PlayerTextDrawSetProportional(playerid, AbastecimentoPosto[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][1], 0);

    AbastecimentoPosto[playerid][2] = CreatePlayerTextDraw(playerid, -6.875000, 261.749908, "");
    PlayerTextDrawLetterSize(playerid, AbastecimentoPosto[playerid][2], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, AbastecimentoPosto[playerid][2], 48.000000, 40.000000);
    PlayerTextDrawAlignment(playerid, AbastecimentoPosto[playerid][2], 1);
    PlayerTextDrawColor(playerid, AbastecimentoPosto[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, AbastecimentoPosto[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, AbastecimentoPosto[playerid][2], 0);
    PlayerTextDrawFont(playerid, AbastecimentoPosto[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, AbastecimentoPosto[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][2], 0);
    PlayerTextDrawSetPreviewModel(playerid, AbastecimentoPosto[playerid][2], 3465);
    PlayerTextDrawSetPreviewRot(playerid, AbastecimentoPosto[playerid][2], 0.000000, 0.000000, 60.000000, 1.000000);

    AbastecimentoPosto[playerid][3] = CreatePlayerTextDraw(playerid, 30.700002, 270.183227, "Litros:_0.0L");
    PlayerTextDrawLetterSize(playerid, AbastecimentoPosto[playerid][3], 0.217499, 1.080832);
    PlayerTextDrawAlignment(playerid, AbastecimentoPosto[playerid][3], 1);
    PlayerTextDrawColor(playerid, AbastecimentoPosto[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, AbastecimentoPosto[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, AbastecimentoPosto[playerid][3], 255);
    PlayerTextDrawFont(playerid, AbastecimentoPosto[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, AbastecimentoPosto[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][3], 1);

    AbastecimentoPosto[playerid][4] = CreatePlayerTextDraw(playerid, 30.200002, 285.583465, "Valor:_$0");
    PlayerTextDrawLetterSize(playerid, AbastecimentoPosto[playerid][4], 0.205624, 1.057498);
    PlayerTextDrawAlignment(playerid, AbastecimentoPosto[playerid][4], 1);
    PlayerTextDrawColor(playerid, AbastecimentoPosto[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, AbastecimentoPosto[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, AbastecimentoPosto[playerid][4], 255);
    PlayerTextDrawFont(playerid, AbastecimentoPosto[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, AbastecimentoPosto[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][4], 1);

    AbastecimentoPosto[playerid][5] = CreatePlayerTextDraw(playerid, 6.250000, 309.333251, "RC");
    PlayerTextDrawLetterSize(playerid, AbastecimentoPosto[playerid][5], 0.163750, 0.929165);
    PlayerTextDrawAlignment(playerid, AbastecimentoPosto[playerid][5], 1);
    PlayerTextDrawColor(playerid, AbastecimentoPosto[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, AbastecimentoPosto[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, AbastecimentoPosto[playerid][5], 255);
    PlayerTextDrawFont(playerid, AbastecimentoPosto[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, AbastecimentoPosto[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, AbastecimentoPosto[playerid][5], 0);

    for(new i=0; i < 6; i++){
        PlayerTextDrawShow(playerid, AbastecimentoPosto[playerid][i]);
    }
    return 1;
}

stock OcultarAbastecimento(playerid)
{
    for(new i=0; i < 6; i++){
        PlayerTextDrawDestroy(playerid, AbastecimentoPosto[playerid][i]);
        AbastecimentoPosto[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarLocalPosto(playerid)
{
    new Mensagem[70];
    format(Mensagem, sizeof(Mensagem), "Posto_de_Gasolina_~y~%s", GetPlayerZone(playerid));
    GasolinaTexto[playerid][0] = CreatePlayerTextDraw(playerid, 337.320800, 433.250000, Mensagem);
    PlayerTextDrawLetterSize(playerid, GasolinaTexto[playerid][0], 0.241171, 0.981664);
    PlayerTextDrawTextSize(playerid, GasolinaTexto[playerid][0], 0.000000, 183.000000);
    PlayerTextDrawAlignment(playerid, GasolinaTexto[playerid][0], 2);
    PlayerTextDrawColor(playerid, GasolinaTexto[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, GasolinaTexto[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, GasolinaTexto[playerid][0], 43);
    PlayerTextDrawSetShadow(playerid, GasolinaTexto[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, GasolinaTexto[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, GasolinaTexto[playerid][0], 255);
    PlayerTextDrawFont(playerid, GasolinaTexto[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, GasolinaTexto[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, GasolinaTexto[playerid][0], 1);
    PlayerTextDrawShow(playerid, GasolinaTexto[playerid][0]);
    return 1;
}

stock OcultarLocalPosto(playerid)
{
    PlayerTextDrawDestroy(playerid, GasolinaTexto[playerid][0]);
    GasolinaTexto[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}