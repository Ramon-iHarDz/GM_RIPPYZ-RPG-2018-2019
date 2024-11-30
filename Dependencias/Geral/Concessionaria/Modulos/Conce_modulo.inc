#include <YSI_Coding\y_hooks>

new PlayerText:ConceT[MAX_PLAYERS][19];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 19; i++){
        ConceT[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    for(new i=0; i < 3; i++){
        TestDrive[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarConce(playerid)
{
    ConceT[playerid][0] = CreatePlayerTextDraw(playerid, 469.773284, 146.833312, "box");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][0], 0.000000, 15.200584);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][0], 630.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][0], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][0], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][0], 0);

    ConceT[playerid][1] = CreatePlayerTextDraw(playerid, 469.772583, 146.833236, "box");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][1], 0.000000, 0.753579);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][1], 629.800781, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][1], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][1], 47);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][1], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][1], 0);

    ConceT[playerid][2] = CreatePlayerTextDraw(playerid, 521.786254, 143.666687, "Concessionaria");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][2], 0.262254, 1.226664);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][2], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][2], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][2], 0);

    ConceT[playerid][3] = CreatePlayerTextDraw(playerid, 574.710998, 160.250030, "box");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][3], 0.000000, 13.454612);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][3], 628.259765, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][3], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][3], -7601921);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][3], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][3], 0);

    ConceT[playerid][4] = CreatePlayerTextDraw(playerid, 553.734741, 127.500099, "");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][4], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][4], 87.000000, 93.000000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][4], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][4], 0);
    PlayerTextDrawFont(playerid, ConceT[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, ConceT[playerid][4], 411);
    PlayerTextDrawSetPreviewRot(playerid, ConceT[playerid][4], -30.000000, 0.000000, 50.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, ConceT[playerid][4], 1, 1);

    ConceT[playerid][5] = CreatePlayerTextDraw(playerid, 575.892456, 215.083328, "Teste_Drive");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][5], 0.241639, 0.975831);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][5], 620.500000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][5], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][5], -5963521);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][5], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, ConceT[playerid][5], true);

    ConceT[playerid][6] = CreatePlayerTextDraw(playerid, 575.892456, 231.583328, "Cancelar");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][6], 0.241639, 0.975831);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][6], 620.500000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][6], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][6], -5963521);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][6], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, ConceT[playerid][6], true);

    ConceT[playerid][7] = CreatePlayerTextDraw(playerid, 575.892456, 248.083328, "Comprar");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][7], 0.241639, 0.975831);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][7], 620.500000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][7], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][7], -5963521);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][7], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][7], 0);
    PlayerTextDrawSetSelectable(playerid, ConceT[playerid][7], true);

    ConceT[playerid][8] = CreatePlayerTextDraw(playerid, 475.908264, 189.499954, "box");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][8], 0.000000, 1.034654);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][8], 566.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][8], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][8], 125);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][8], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][8], 0);

    ConceT[playerid][9] = CreatePlayerTextDraw(playerid, 475.908264, 217.999954, "box");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][9], 0.000000, 1.034654);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][9], 566.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][9], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][9], 125);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][9], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][9], 0);

    ConceT[playerid][10] = CreatePlayerTextDraw(playerid, 475.908264, 245.499954, "box");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][10], 0.000000, 1.034654);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][10], 566.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][10], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][10], 125);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][10], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][10], 0);

    ConceT[playerid][11] = CreatePlayerTextDraw(playerid, 506.268096, 175.750000, "Modelo");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][11], 0.261317, 1.034165);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][11], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][11], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][11], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][11], 0);

    ConceT[playerid][12] = CreatePlayerTextDraw(playerid, 504.268096, 205.250000, "Categoria");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][12], 0.235548, 0.987497);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][12], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][12], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][12], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][12], 0);

    ConceT[playerid][13] = CreatePlayerTextDraw(playerid, 513.268066, 232.250000, "Preco");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][13], 0.235548, 0.987497);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][13], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][13], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][13], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][13], 0);

    ConceT[playerid][14] = CreatePlayerTextDraw(playerid, 541.568176, 262.750030, ">");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][14], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][14], 552.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][14], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][14], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][14], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][14], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][14], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][14], 0);
    PlayerTextDrawSetSelectable(playerid, ConceT[playerid][14], true);

    ConceT[playerid][15] = CreatePlayerTextDraw(playerid, 492.068176, 262.750030, "<");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][15], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, ConceT[playerid][15], 502.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][15], 1);
    PlayerTextDrawColor(playerid, ConceT[playerid][15], -1);
    PlayerTextDrawUseBox(playerid, ConceT[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, ConceT[playerid][15], 0);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][15], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][15], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][15], 0);
    PlayerTextDrawSetSelectable(playerid, ConceT[playerid][15], true);

    ConceT[playerid][16] = CreatePlayerTextDraw(playerid, 522.449584, 187.416641, "Infernus");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][16], 0.284274, 1.261664);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][16], 2);
    PlayerTextDrawColor(playerid, ConceT[playerid][16], -2139062017);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][16], 1);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][16], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][16], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][16], 1);

    ConceT[playerid][17] = CreatePlayerTextDraw(playerid, 522.449584, 215.916641, "Sport");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][17], 0.290365, 1.214998);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][17], 2);
    PlayerTextDrawColor(playerid, ConceT[playerid][17], -1523963137);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][17], 1);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][17], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][17], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][17], 1);

    ConceT[playerid][18] = CreatePlayerTextDraw(playerid, 522.949584, 244.416641, "$8.000.000");
    PlayerTextDrawLetterSize(playerid, ConceT[playerid][18], 0.248667, 1.144997);
    PlayerTextDrawAlignment(playerid, ConceT[playerid][18], 2);
    PlayerTextDrawColor(playerid, ConceT[playerid][18], 8388863);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ConceT[playerid][18], 1);
    PlayerTextDrawBackgroundColor(playerid, ConceT[playerid][18], 255);
    PlayerTextDrawFont(playerid, ConceT[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, ConceT[playerid][18], 1);
    PlayerTextDrawSetShadow(playerid, ConceT[playerid][18], 0);

    for(new i=0; i < 19; i++){
        PlayerTextDrawShow(playerid, ConceT[playerid][i]);
    }

    SelectTextDrawEx(playerid, 0xB22222FF, "OcultarConce", true);
    return 1;
} 

function OcultarConce(playerid)
{
    CancelSelectTextDrawEx(playerid, "OcultarConce");
    for(new i=0; i < 19; i++){
        PlayerTextDrawDestroy(playerid, ConceT[playerid][i]);
        ConceT[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarTestDrive(playerid)
{
    TestDrive[playerid][0] = CreatePlayerTextDraw(playerid, 5.000000, 247.916854, "box");
    PlayerTextDrawLetterSize(playerid, TestDrive[playerid][0], 0.000000, 1.750000);
    PlayerTextDrawTextSize(playerid, TestDrive[playerid][0], 69.650047, 0.000000);
    PlayerTextDrawAlignment(playerid, TestDrive[playerid][0], 1);
    PlayerTextDrawColor(playerid, TestDrive[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, TestDrive[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, TestDrive[playerid][0], 471604324);
    PlayerTextDrawSetShadow(playerid, TestDrive[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, TestDrive[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, TestDrive[playerid][0], 255);
    PlayerTextDrawFont(playerid, TestDrive[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, TestDrive[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, TestDrive[playerid][0], 0);

    TestDrive[playerid][1] = CreatePlayerTextDraw(playerid, 6.449859, 249.866607, "Tempo:_03:00");
    PlayerTextDrawLetterSize(playerid, TestDrive[playerid][1], 0.260000, 1.174165);
    PlayerTextDrawAlignment(playerid, TestDrive[playerid][1], 1);
    PlayerTextDrawColor(playerid, TestDrive[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, TestDrive[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, TestDrive[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, TestDrive[playerid][1], 255);
    PlayerTextDrawFont(playerid, TestDrive[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, TestDrive[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, TestDrive[playerid][1], 1);

    TestDrive[playerid][2] = CreatePlayerTextDraw(playerid, 15.975221, 267.216552, "SairTeste");
    PlayerTextDrawLetterSize(playerid, TestDrive[playerid][2], 0.239749, 0.921666);
    PlayerTextDrawAlignment(playerid, TestDrive[playerid][2], 1);
    PlayerTextDrawColor(playerid, TestDrive[playerid][2], -1061109505);
    PlayerTextDrawSetShadow(playerid, TestDrive[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, TestDrive[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, TestDrive[playerid][2], 255);
    PlayerTextDrawFont(playerid, TestDrive[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, TestDrive[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, TestDrive[playerid][2], 0);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, TestDrive[playerid][i]);
    }
    return 1;
}

stock OcultarTestDrive(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, TestDrive[playerid][i]);
        TestDrive[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}