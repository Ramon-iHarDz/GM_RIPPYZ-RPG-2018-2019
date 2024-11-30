#include <YSI_Coding\y_hooks>

new PlayerText:CaixaEntregas[MAX_PLAYERS][3];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 3; i++){
        CaixaEntregas[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarCaixaEntregas(playerid)
{
    CaixaEntregas[playerid][0] = CreatePlayerTextDraw(playerid, 14.275009, 229.083343, "box");
    PlayerTextDrawLetterSize(playerid, CaixaEntregas[playerid][0], 0.000000, 2.015001);
    PlayerTextDrawTextSize(playerid, CaixaEntregas[playerid][0], 63.700004, 0.000000);
    PlayerTextDrawAlignment(playerid, CaixaEntregas[playerid][0], 1);
    PlayerTextDrawColor(playerid, CaixaEntregas[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CaixaEntregas[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CaixaEntregas[playerid][0], 110);
    PlayerTextDrawSetShadow(playerid, CaixaEntregas[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CaixaEntregas[playerid][0], 255);
    PlayerTextDrawFont(playerid, CaixaEntregas[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CaixaEntregas[playerid][0], 1);

    CaixaEntregas[playerid][1] = CreatePlayerTextDraw(playerid, -2.500000, 217.999969, "");
    PlayerTextDrawTextSize(playerid, CaixaEntregas[playerid][1], 37.000000, 37.000000);
    PlayerTextDrawAlignment(playerid, CaixaEntregas[playerid][1], 1);
    PlayerTextDrawColor(playerid, CaixaEntregas[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, CaixaEntregas[playerid][1], 0);
    PlayerTextDrawFont(playerid, CaixaEntregas[playerid][1], 5);
    PlayerTextDrawUseBox(playerid, CaixaEntregas[playerid][1], 0);
    PlayerTextDrawSetProportional(playerid, CaixaEntregas[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CaixaEntregas[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, CaixaEntregas[playerid][1], 1220);
    PlayerTextDrawSetPreviewRot(playerid, CaixaEntregas[playerid][1], -30.000000, 0.000000, 30.000000, 1.000000);

    CaixaEntregas[playerid][2] = CreatePlayerTextDraw(playerid, 46.700042, 232.099945, "0/0");
    PlayerTextDrawLetterSize(playerid, CaixaEntregas[playerid][2], 0.231249, 1.179999);
    PlayerTextDrawAlignment(playerid, CaixaEntregas[playerid][2], 2);
    PlayerTextDrawColor(playerid, CaixaEntregas[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, CaixaEntregas[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, CaixaEntregas[playerid][2], 80);
    PlayerTextDrawFont(playerid, CaixaEntregas[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CaixaEntregas[playerid][2], 1);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, CaixaEntregas[playerid][i]);
    }
    return 1;
}

stock OcultarCaixaEntregas(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, CaixaEntregas[playerid][i]);
        CaixaEntregas[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock AtualizarCaixaEntregas(playerid, valor, valor2)
{
    new Inff[20];
    format(Inff, sizeof(Inff), "%d/%d", valor, valor2);
    PlayerTextDrawSetString(playerid, CaixaEntregas[playerid][2], ConverterTexto(Inff));
    return 1;
}