#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 4; i++){
        CellNot[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarNotificacaoCelular(playerid, const Msgg[])
{
    if(GetPVarInt(playerid, "CelularNotOn") == 1) return 1;
    SetPVarInt(playerid, "CelularNotOn", 1);

    CellNot[playerid][0] = CreatePlayerTextDraw(playerid, 536.910827, 171.916671, "box");
    PlayerTextDrawLetterSize(playerid, CellNot[playerid][0], 0.000000, 2.175697);
    PlayerTextDrawTextSize(playerid, CellNot[playerid][0], 634.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, CellNot[playerid][0], 1);
    PlayerTextDrawColor(playerid, CellNot[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CellNot[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CellNot[playerid][0], 70);
    PlayerTextDrawSetShadow(playerid, CellNot[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CellNot[playerid][0], 0);
    PlayerTextDrawFont(playerid, CellNot[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CellNot[playerid][0], 1);

    CellNot[playerid][1] = CreatePlayerTextDraw(playerid, 541.164794, 172.216705, "ld_pool:ball");
    PlayerTextDrawTextSize(playerid, CellNot[playerid][1], 16.000000, 19.000000);
    PlayerTextDrawAlignment(playerid, CellNot[playerid][1], 1);
    PlayerTextDrawColor(playerid, CellNot[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, CellNot[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CellNot[playerid][1], 255);
    PlayerTextDrawFont(playerid, CellNot[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, CellNot[playerid][1], 0);

    CellNot[playerid][2] = CreatePlayerTextDraw(playerid, 520.812622, 167.249984, "");
    PlayerTextDrawTextSize(playerid, CellNot[playerid][2], 40.000000, 27.000000);
    PlayerTextDrawAlignment(playerid, CellNot[playerid][2], 1);
    PlayerTextDrawColor(playerid, CellNot[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, CellNot[playerid][2], 0);
    PlayerTextDrawFont(playerid, CellNot[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, CellNot[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CellNot[playerid][2], 0);
    PlayerTextDrawSetPreviewModel(playerid, CellNot[playerid][2], 18865);
    PlayerTextDrawSetPreviewRot(playerid, CellNot[playerid][2], -90.000000, 0.000000, 160.000000, 1.000000);

    CellNot[playerid][3] = CreatePlayerTextDraw(playerid, 561.336425, 176.100006, ConverterTexto(Msgg));
    PlayerTextDrawLetterSize(playerid, CellNot[playerid][3], 0.182137, 1.092499);
    PlayerTextDrawAlignment(playerid, CellNot[playerid][3], 1);
    PlayerTextDrawColor(playerid, CellNot[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, CellNot[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, CellNot[playerid][3], 72);
    PlayerTextDrawFont(playerid, CellNot[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, CellNot[playerid][3], 1);

    for(new i=0; i < 4; i++){
        PlayerTextDrawShow(playerid, CellNot[playerid][i]);
    }
    return 1;
}

stock OcultarNotificacaoChamada(playerid)
{
    SetPVarInt(playerid, "CelularNotOn", 0);
    for(new i=0; i < 4; i++){
        PlayerTextDrawDestroy(playerid, CellNot[playerid][i]);
        CellNot[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}