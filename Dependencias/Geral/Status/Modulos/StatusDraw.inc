#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 20; i++){
        StatusTxd[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    for(new i=0; i < 15; i++)
    {
        BlackSono[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarStatus(playerid)
{
    StatusTxd[playerid][0] = CreatePlayerTextDraw(playerid, 541.523986, 352.365631, "box");
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][0], 0.000000, 9.906486);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][0], 634.019226, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][0], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][0], 70);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][0], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][0], 1);

    StatusTxd[playerid][1] = CreatePlayerTextDraw(playerid, 576.949829, 357.999664, "hud:radar_burgershot");
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][1], 12.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][1], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][1], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][1], 0);

    StatusTxd[playerid][2] = CreatePlayerTextDraw(playerid, 578.649414, 375.400787, "hud:radar_datedrink");
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][2], 10.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][2], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][2], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][2], 0);

    StatusTxd[playerid][3] = CreatePlayerTextDraw(playerid, 574.075561, 359.483123, "box");
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][3], 0.000000, 8.382998);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][3], 568.070434, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][3], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][3], -12254977);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][3], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][3], 1);

    StatusTxd[playerid][4] = CreatePlayerTextDraw(playerid, 595.399780, 360.649749, "box");
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][4], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][4], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][4], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][4], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][4], 471604479);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][4], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][4], 1);

    StatusTxd[playerid][5] = CreatePlayerTextDraw(playerid, 578.674316, 392.517791, "hud:radar_hostpital");
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][5], 10.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][5], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][5], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][5], 0);

    StatusTxd[playerid][6] = CreatePlayerTextDraw(playerid, 547.000000, 382.700103, "");
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][6], 19.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][6], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][6], -1);
    // PlayerTextDrawUseBox(playerid, StatusTxd[playerid][6], 0);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][6], 0);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][6], 0);
    PlayerTextDrawSetPreviewModel(playerid, StatusTxd[playerid][6], 1247);
    PlayerTextDrawSetPreviewRot(playerid, StatusTxd[playerid][6], 0.000000, 0.000000, 0.000000, 1.000000);

    StatusTxd[playerid][7] = CreatePlayerTextDraw(playerid, 556.424987, 400.249816, "0");
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][7], 0.241870, 1.045832);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][7], 2);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][7], 0);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][7], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][7], 1);

    StatusTxd[playerid][8] = CreatePlayerTextDraw(playerid, 588.899841, 339.349273, "+EXP_00:00");
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][8], 0.211869, 0.876666);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][8], 2);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][8], 0);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, StatusTxd[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][8], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][8], 1);

    StatusTxd[playerid][9] = CreatePlayerTextDraw(playerid, 595.399780, 377.549926, "box");
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][9], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][9], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][9], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][9], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][9], 471604479);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][9], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][9], 1);

    StatusTxd[playerid][10] = CreatePlayerTextDraw(playerid, 595.399780, 394.849914, "box");
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][10], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][10], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][10], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][10], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][10], 471604479);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][10], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][10], 1);

    StatusTxd[playerid][11] = CreatePlayerTextDraw(playerid, 595.399780, 411.766876, "box");
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][11], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][11], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][11], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][11], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][11], 471604479);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][11], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][11], 1);

    StatusTxd[playerid][12] = CreatePlayerTextDraw(playerid, 578.049316, 408.618072, "hud:radar_zero");
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][12], 10.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][12], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][12], 0);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][12], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][12], 0);

    StatusTxd[playerid][13] = CreatePlayerTextDraw(playerid, 595.399780, 428.450500, "box");
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][13], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][13], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][13], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][13], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][13], 471604479);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][13], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][13], 1);

    StatusTxd[playerid][14] = CreatePlayerTextDraw(playerid, 574.375000, 423.333251, "");
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][14], 17.000000, 15.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][14], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][14], -1);
    // PlayerTextDrawUseBox(playerid, StatusTxd[playerid][14], 0);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][14], 2);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][14], 5);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][14], 0);
    PlayerTextDrawSetPreviewModel(playerid, StatusTxd[playerid][14], 1241);
    PlayerTextDrawSetPreviewRot(playerid, StatusTxd[playerid][14], 0.000000, 0.000000, 0.000000, 1.000000);

    StatusTxd[playerid][15] = CreatePlayerTextDraw(playerid, 595.399780, 360.649749, "box"); // Fome
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][15], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][15], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][15], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][15], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][15], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][15], 1);

    StatusTxd[playerid][16] = CreatePlayerTextDraw(playerid, 595.399780, 377.549926, "box"); // Sede
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][16], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][16], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][16], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][16], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][16], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][16], 1);

    StatusTxd[playerid][17] = CreatePlayerTextDraw(playerid, 595.399780, 394.849914, "box"); // Saude
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][17], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][17], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][17], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][17], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][17], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][17], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][17], 1);

    StatusTxd[playerid][18] = CreatePlayerTextDraw(playerid, 595.399780, 411.766876, "box"); // Sono
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][18], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][18], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][18], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][18], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][18], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][18], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][18], 1);

    StatusTxd[playerid][19] = CreatePlayerTextDraw(playerid, 595.399780, 428.450500, "box"); // Vicio
    PlayerTextDrawLetterSize(playerid, StatusTxd[playerid][19], 0.000000, 0.568499);
    PlayerTextDrawTextSize(playerid, StatusTxd[playerid][19], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, StatusTxd[playerid][19], 1);
    PlayerTextDrawColor(playerid, StatusTxd[playerid][19], 471604479);
    PlayerTextDrawUseBox(playerid, StatusTxd[playerid][19], 1);
    PlayerTextDrawBoxColor(playerid, StatusTxd[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, StatusTxd[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, StatusTxd[playerid][19], 255);
    PlayerTextDrawFont(playerid, StatusTxd[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, StatusTxd[playerid][19], 1);

    for(new i=0; i < 20; i++){
        PlayerTextDrawShow(playerid, StatusTxd[playerid][i]);
    }
    return 1;
}

stock MostrarTelaSono(playerid)
{
    BlackSono[playerid][0] = CreatePlayerTextDraw(playerid, -3.125000, -3.083338, "box");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][0], 0.000000, 52.187500);
    PlayerTextDrawTextSize(playerid, BlackSono[playerid][0], 696.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][0], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][0], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][0], 1);

    BlackSono[playerid][1] = CreatePlayerTextDraw(playerid, 286.875000, 179.500015, "DORMINDO");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][1], 0.485624, 1.909167);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][1], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][1], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][1], 3);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][1], 1);

    BlackSono[playerid][2] = CreatePlayerTextDraw(playerid, 290.625000, 197.000061, "AGUARDE.");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][2], 0.485624, 1.909167);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][2], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][2], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][2], 3);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][2], 1);

    BlackSono[playerid][3] = CreatePlayerTextDraw(playerid, 115.000000, 232.000000, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][3], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][3], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][3], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][3], 1);

    BlackSono[playerid][4] = CreatePlayerTextDraw(playerid, 491.875000, 100.166679, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][4], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][4], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][4], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][4], 1);

    BlackSono[playerid][5] = CreatePlayerTextDraw(playerid, 533.750000, 214.500015, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][5], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][5], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][5], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][5], 1);

    BlackSono[playerid][6] = CreatePlayerTextDraw(playerid, 238.750000, 310.750030, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][6], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][6], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][6], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][6], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][6], 1);

    BlackSono[playerid][7] = CreatePlayerTextDraw(playerid, 291.875000, 90.833381, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][7], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][7], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][7], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][7], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][7], 1);

    BlackSono[playerid][8] = CreatePlayerTextDraw(playerid, 404.375000, 281.583343, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][8], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][8], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][8], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][8], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][8], 1);

    BlackSono[playerid][9] = CreatePlayerTextDraw(playerid, 123.125000, 81.499992, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][9], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][9], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][9], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][9], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][9], 1);

    BlackSono[playerid][10] = CreatePlayerTextDraw(playerid, 196.250000, 138.083328, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][10], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][10], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][10], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][10], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][10], 1);

    BlackSono[playerid][11] = CreatePlayerTextDraw(playerid, 472.500000, 189.416671, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][11], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][11], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][11], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][11], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][11], 1);

    BlackSono[playerid][12] = CreatePlayerTextDraw(playerid, 298.125000, 268.166656, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][12], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][12], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][12], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][12], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][12], 1);

    BlackSono[playerid][13] = CreatePlayerTextDraw(playerid, 45.000000, 160.833480, "Z");
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][13], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][13], 1);
    PlayerTextDrawColor(playerid, BlackSono[playerid][13], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][13], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][13], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][13], 1);

    BlackSono[playerid][14] = CreatePlayerTextDraw(playerid, 320.625000, 223.250076, ConverterTexto("Sabia que o dinheiro é feito de papel?"));
    PlayerTextDrawLetterSize(playerid, BlackSono[playerid][14], 0.241875, 1.220833);
    PlayerTextDrawAlignment(playerid, BlackSono[playerid][14], 2);
    PlayerTextDrawColor(playerid, BlackSono[playerid][14], -1);
    PlayerTextDrawUseBox(playerid, BlackSono[playerid][14], 0);
    PlayerTextDrawBoxColor(playerid, BlackSono[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, BlackSono[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, BlackSono[playerid][14], 255);
    PlayerTextDrawFont(playerid, BlackSono[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, BlackSono[playerid][14], 1);

    for(new i=0; i < 15; i++)
    {
        PlayerTextDrawShow(playerid, BlackSono[playerid][i]);
    }
    return 1;
}

stock OcultarTelaSono(playerid)
{
    for(new i=0; i < 15; i++)
    {
        PlayerTextDrawDestroy(playerid, BlackSono[playerid][i]);
        BlackSono[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;   
}

/*OcultarStatus(playerid)
{
    for(new i=0; i < 20; i++){
        PlayerTextDrawDestroy(playerid, StatusTxd[playerid][i]);
        StatusTxd[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}*/

stock MostrarStatusEx(playerid)
{
    for(new i=0; i < 20; i++){
        PlayerTextDrawShow(playerid, StatusTxd[playerid][i]);
    }
    AtualizarStatus(playerid); 
    return 1;
}

stock OcultarStatusEx(playerid)
{
    for(new i=0; i < 20; i++){
        PlayerTextDrawHide(playerid, StatusTxd[playerid][i]);
    }
    return 1;
}
