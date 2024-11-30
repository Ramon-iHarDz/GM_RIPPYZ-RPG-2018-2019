#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 13; i++){
        AntiAFKTXD[playerid][i] = PlayerText:INVALID_TEXT_DRAW; 
    }
    return 1; 
}

stock MostrarAntiAFK(playerid)
{
    AntiAFKTXD[playerid][0] = CreatePlayerTextDraw(playerid, 400.102600, 112.416625, "box");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][0], 0.000000, 16.325035);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][0], 517.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][0], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][0], 255);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][0], 1);

    AntiAFKTXD[playerid][1] = CreatePlayerTextDraw(playerid, 400.102478, 112.416625, "box");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][1], 0.000000, 0.852361);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][1], 517.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][1], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][1], -5963521);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][1], 255);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][1], 1);

    AntiAFKTXD[playerid][2] = CreatePlayerTextDraw(playerid, 401.976867, 110.333290, "Anti-AFK");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][2], 0.253820, 1.063331);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][2], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][2], 96);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][2], 1);

    AntiAFKTXD[playerid][3] = CreatePlayerTextDraw(playerid, 459.441741, 135.750015, "Tempo:_00:00");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][3], 0.235080, 1.209166);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][3], 2);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][3], 255);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][3], 1);

    AntiAFKTXD[playerid][4] = CreatePlayerTextDraw(playerid, 442.267578, 156.716690, "1");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][4], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][4], 450.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][4], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][4], 255);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, AntiAFKTXD[playerid][4], true);

    AntiAFKTXD[playerid][5] = CreatePlayerTextDraw(playerid, 465.764007, 156.766693, "2");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][5], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][5], 474.600006, 12.0000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][5], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][5], 255);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, AntiAFKTXD[playerid][5], true);

    AntiAFKTXD[playerid][6] = CreatePlayerTextDraw(playerid, 442.743316, 178.833297, "3");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][6], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][6], 454.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][6], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][6], 255);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, AntiAFKTXD[playerid][6], true);

    AntiAFKTXD[playerid][7] = CreatePlayerTextDraw(playerid, 466.169586, 178.833282, "4");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][7], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][7], 472.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][7], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][7], 255);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, AntiAFKTXD[playerid][7], true);

    AntiAFKTXD[playerid][8] = CreatePlayerTextDraw(playerid, 442.274902, 201.583236, "5");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][8], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][8], 450.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][8], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][8], 255);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, AntiAFKTXD[playerid][8], true);

    AntiAFKTXD[playerid][9] = CreatePlayerTextDraw(playerid, 466.638061, 201.583236, "6");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][9], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][9], 474.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][9], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][9], 255);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, AntiAFKTXD[playerid][9], true);

    AntiAFKTXD[playerid][10] = CreatePlayerTextDraw(playerid, 430.088073, 226.166671, "Visualizar_Slots");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][10], 0.242108, 1.063332);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][10], 490.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][10], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][10], 12582911);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][10], 12582668);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][10], 1);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][10], 53);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, AntiAFKTXD[playerid][10], true);

    AntiAFKTXD[playerid][11] = CreatePlayerTextDraw(playerid, 459.136474, 243.083343, "Procure_o_slot_com_o_texto_diferente");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][11], 0.168081, 0.934999);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][11], 2);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][11], -16776961);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][11], 0);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, AntiAFKTXD[playerid][11], 1);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][11], 85);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][11], 1);

    AntiAFKTXD[playerid][12] = CreatePlayerTextDraw(playerid, 476.002929, 111.249992, "Gerar_outro");
    PlayerTextDrawLetterSize(playerid, AntiAFKTXD[playerid][12], 0.204158, 0.993333);
    PlayerTextDrawTextSize(playerid, AntiAFKTXD[playerid][12], 517.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, AntiAFKTXD[playerid][12], 1);
    PlayerTextDrawColor(playerid, AntiAFKTXD[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, AntiAFKTXD[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, AntiAFKTXD[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, AntiAFKTXD[playerid][12], 1);
    PlayerTextDrawBackgroundColor(playerid, AntiAFKTXD[playerid][12], 24);
    PlayerTextDrawFont(playerid, AntiAFKTXD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, AntiAFKTXD[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, AntiAFKTXD[playerid][12], true);

    for(new i=0; i < 13; i++){
        PlayerTextDrawShow(playerid, AntiAFKTXD[playerid][i]);
    }
    SelectTextDrawEx(playerid, 0xB22222FF, "OcultarAntiAFK", true); 
    return 1;
}

function OcultarAntiAFK(playerid) 
{
    CancelSelectTextDrawEx(playerid, "OcultarAntiAFK");
    for(new i=0; i < 13; i++){
        PlayerTextDrawDestroy(playerid, AntiAFKTXD[playerid][i]);
        AntiAFKTXD[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}