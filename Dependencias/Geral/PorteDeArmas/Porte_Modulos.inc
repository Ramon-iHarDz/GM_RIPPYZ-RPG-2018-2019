#include <YSI_Coding\y_hooks>

new PlayerText:PorteMod[MAX_PLAYERS][8];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 8; i++)
    {
        PorteMod[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarTreinamento(playerid)
{
    PorteMod[playerid][0] = CreatePlayerTextDraw(playerid, 532.225341, 164.333312, "box");
    PlayerTextDrawLetterSize(playerid, PorteMod[playerid][0], 0.000000, 7.610542);
    PlayerTextDrawTextSize(playerid, PorteMod[playerid][0], 627.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PorteMod[playerid][0], 1);
    PlayerTextDrawColor(playerid, PorteMod[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, PorteMod[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, PorteMod[playerid][0], -457613057);
    PlayerTextDrawSetShadow(playerid, PorteMod[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PorteMod[playerid][0], 255);
    PlayerTextDrawFont(playerid, PorteMod[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, PorteMod[playerid][0], 1);

    PorteMod[playerid][1] = CreatePlayerTextDraw(playerid, 532.225341, 164.333312, "box");
    PlayerTextDrawLetterSize(playerid, PorteMod[playerid][1], 0.000000, 0.839538);
    PlayerTextDrawTextSize(playerid, PorteMod[playerid][1], 627.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PorteMod[playerid][1], 1);
    PlayerTextDrawColor(playerid, PorteMod[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, PorteMod[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, PorteMod[playerid][1], 471604479);
    PlayerTextDrawSetShadow(playerid, PorteMod[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PorteMod[playerid][1], 255);
    PlayerTextDrawFont(playerid, PorteMod[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, PorteMod[playerid][1], 1);

    PorteMod[playerid][2] = CreatePlayerTextDraw(playerid, 580.152404, 162.000030, "Treinamento");
    PlayerTextDrawLetterSize(playerid, PorteMod[playerid][2], 0.270688, 1.214999);
    PlayerTextDrawAlignment(playerid, PorteMod[playerid][2], 2);
    PlayerTextDrawColor(playerid, PorteMod[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, PorteMod[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, PorteMod[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, PorteMod[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, PorteMod[playerid][2], 80);
    PlayerTextDrawFont(playerid, PorteMod[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, PorteMod[playerid][2], 1);

    PorteMod[playerid][3] = CreatePlayerTextDraw(playerid, 579.040283, 180.083374, "Alvos: 0/5");
    PlayerTextDrawLetterSize(playerid, PorteMod[playerid][3], 0.257569, 1.127499);
    PlayerTextDrawTextSize(playerid, PorteMod[playerid][3], 0.000000, 123.000000);
    PlayerTextDrawAlignment(playerid, PorteMod[playerid][3], 2);
    PlayerTextDrawColor(playerid, PorteMod[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, PorteMod[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, PorteMod[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PorteMod[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, PorteMod[playerid][3], 95);
    PlayerTextDrawFont(playerid, PorteMod[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, PorteMod[playerid][3], 1);

    PorteMod[playerid][4] = CreatePlayerTextDraw(playerid, 578.940307, 193.884170, "Progresso: 0/60");
    PlayerTextDrawLetterSize(playerid, PorteMod[playerid][4], 0.257569, 1.127499);
    PlayerTextDrawTextSize(playerid, PorteMod[playerid][4], 0.000000, 123.000000);
    PlayerTextDrawAlignment(playerid, PorteMod[playerid][4], 2);
    PlayerTextDrawColor(playerid, PorteMod[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, PorteMod[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, PorteMod[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, PorteMod[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, PorteMod[playerid][4], 95);
    PlayerTextDrawFont(playerid, PorteMod[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, PorteMod[playerid][4], 1);

    PorteMod[playerid][5] = CreatePlayerTextDraw(playerid, 579.508789, 207.100082, "Tempo:_00:00");
    PlayerTextDrawLetterSize(playerid, PorteMod[playerid][5], 0.245856, 1.104166);
    PlayerTextDrawTextSize(playerid, PorteMod[playerid][5], 0.000000, 123.000000);
    PlayerTextDrawAlignment(playerid, PorteMod[playerid][5], 2);
    PlayerTextDrawColor(playerid, PorteMod[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, PorteMod[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, PorteMod[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, PorteMod[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, PorteMod[playerid][5], 95);
    PlayerTextDrawFont(playerid, PorteMod[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, PorteMod[playerid][5], 1);

    PorteMod[playerid][6] = CreatePlayerTextDraw(playerid, 596.713256, 132.833267, "");
    PlayerTextDrawTextSize(playerid, PorteMod[playerid][6], 68.000000, 77.000000);
    PlayerTextDrawAlignment(playerid, PorteMod[playerid][6], 1);
    PlayerTextDrawColor(playerid, PorteMod[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, PorteMod[playerid][6], 0);
    PlayerTextDrawBoxColor(playerid, PorteMod[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, PorteMod[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PorteMod[playerid][6], 0);
    PlayerTextDrawFont(playerid, PorteMod[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, PorteMod[playerid][6], 0);
    PlayerTextDrawSetPreviewModel(playerid, PorteMod[playerid][6], 347);
    PlayerTextDrawSetPreviewRot(playerid, PorteMod[playerid][6], 0.000000, 0.000000, 0.000000, 1.399999);

    PorteMod[playerid][7] = CreatePlayerTextDraw(playerid, 531.757019, 224.416641, "RC");
    PlayerTextDrawLetterSize(playerid, PorteMod[playerid][7], 0.190102, 1.086666);
    PlayerTextDrawAlignment(playerid, PorteMod[playerid][7], 1);
    PlayerTextDrawColor(playerid, PorteMod[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, PorteMod[playerid][7], 0);
    PlayerTextDrawBoxColor(playerid, PorteMod[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, PorteMod[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PorteMod[playerid][7], 255);
    PlayerTextDrawFont(playerid, PorteMod[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, PorteMod[playerid][7], 1);

    for(new i=0; i < 8; i++)
    {
        PlayerTextDrawShow(playerid, PorteMod[playerid][i]);
    }
    return 1;
}

stock OcultarTreinamento(playerid)
{
    for(new i=0; i < 8; i++)
    {
        PlayerTextDrawDestroy(playerid, PorteMod[playerid][i]);
        PorteMod[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}