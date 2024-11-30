#include <YSI_Coding\y_hooks>

new PlayerText:CilindroTextDraw[MAX_PLAYERS][3];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 3; i++){
        CilindroTextDraw[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarCilindro(playerid)
{
    CilindroTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 552.500000, 136.916656, "box");
    PlayerTextDrawLetterSize(playerid, CilindroTextDraw[playerid][0], 0.000000, 1.812500);
    PlayerTextDrawTextSize(playerid, CilindroTextDraw[playerid][0], 631.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, CilindroTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, CilindroTextDraw[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CilindroTextDraw[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CilindroTextDraw[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, CilindroTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CilindroTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, CilindroTextDraw[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CilindroTextDraw[playerid][0], 1);

    CilindroTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 528.125000, 115.700012, "");
    PlayerTextDrawTextSize(playerid, CilindroTextDraw[playerid][1], 54.000000, 50.000000);
    PlayerTextDrawAlignment(playerid, CilindroTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, CilindroTextDraw[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CilindroTextDraw[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, CilindroTextDraw[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, CilindroTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CilindroTextDraw[playerid][1], 0);
    PlayerTextDrawFont(playerid, CilindroTextDraw[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, CilindroTextDraw[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, CilindroTextDraw[playerid][1], 2690);
    PlayerTextDrawSetPreviewRot(playerid, CilindroTextDraw[playerid][1], 0.000000, 0.000000, 0.000000, 1.000000);

    CilindroTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 594.625244, 137.816741, "07:00");
    PlayerTextDrawLetterSize(playerid, CilindroTextDraw[playerid][2], 0.357499, 1.442499);
    PlayerTextDrawAlignment(playerid, CilindroTextDraw[playerid][2], 2);
    PlayerTextDrawColor(playerid, CilindroTextDraw[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CilindroTextDraw[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, CilindroTextDraw[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CilindroTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CilindroTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, CilindroTextDraw[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CilindroTextDraw[playerid][2], 1);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, CilindroTextDraw[playerid][i]);
    }
    return 1;
}

stock OcultarCilindro(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, CilindroTextDraw[playerid][i]);
        CilindroTextDraw[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}