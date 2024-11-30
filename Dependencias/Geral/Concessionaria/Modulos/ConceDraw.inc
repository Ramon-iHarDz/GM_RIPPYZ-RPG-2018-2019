#include <YSI_Coding\y_hooks>

new PlayerText:ConceDraw[MAX_PLAYERS][7];
new PlayerText:ConceDrawY[MAX_PLAYERS][14];

hook OnPlayerDisconnect(playerid, reason){
    for(new i=0; i < 7; i++){
        ConceDraw[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    for(new i=0; i < 14; i++){
        ConceDrawY[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarDrawConce(playerid){
    ConceDraw[playerid][0] = CreatePlayerTextDraw(playerid, 210.819931, 223.250030, "box");
    PlayerTextDrawLetterSize(playerid, ConceDraw[playerid][0], 0.000000, 5.949268);
    PlayerTextDrawTextSize(playerid, ConceDraw[playerid][0], 315.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, ConceDraw[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, ConceDraw[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, ConceDraw[playerid][0], 1010580735);
    PlayerTextDrawSetShadow(playerid, ConceDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, ConceDraw[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ConceDraw[playerid][0], 1);

    ConceDraw[playerid][1] = CreatePlayerTextDraw(playerid, 210.730880, 222.949813, "box");
    PlayerTextDrawLetterSize(playerid, ConceDraw[playerid][1], 0.000000, 0.004263);
    PlayerTextDrawTextSize(playerid, ConceDraw[playerid][1], 315.009826, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, ConceDraw[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, ConceDraw[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, ConceDraw[playerid][1], -56286977);
    PlayerTextDrawSetShadow(playerid, ConceDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, ConceDraw[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ConceDraw[playerid][1], 1);

    ConceDraw[playerid][2] = CreatePlayerTextDraw(playerid, 223.470016, 243.483444, "box");
    PlayerTextDrawLetterSize(playerid, ConceDraw[playerid][2], 0.000000, 0.723280);
    PlayerTextDrawTextSize(playerid, ConceDraw[playerid][2], 304.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, ConceDraw[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, ConceDraw[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, ConceDraw[playerid][2], 70);
    PlayerTextDrawSetShadow(playerid, ConceDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, ConceDraw[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ConceDraw[playerid][2], 1);

    ConceDraw[playerid][3] = CreatePlayerTextDraw(playerid, 265.225860, 241.717163, "Infernus");
    PlayerTextDrawLetterSize(playerid, ConceDraw[playerid][3], 0.226647, 1.016664);
    PlayerTextDrawAlignment(playerid, ConceDraw[playerid][3], 2);
    PlayerTextDrawColor(playerid, ConceDraw[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, ConceDraw[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, ConceDraw[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, ConceDraw[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, ConceDraw[playerid][3], 50);
    PlayerTextDrawFont(playerid, ConceDraw[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, ConceDraw[playerid][3], 1);

    ConceDraw[playerid][4] = CreatePlayerTextDraw(playerid, 237.068511, 232.383834, "Modelo");
    PlayerTextDrawLetterSize(playerid, ConceDraw[playerid][4], 0.202751, 0.894164);
    PlayerTextDrawAlignment(playerid, ConceDraw[playerid][4], 2);
    PlayerTextDrawColor(playerid, ConceDraw[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, ConceDraw[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, ConceDraw[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, ConceDraw[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, ConceDraw[playerid][4], 50);
    PlayerTextDrawFont(playerid, ConceDraw[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, ConceDraw[playerid][4], 1);

    ConceDraw[playerid][5] = CreatePlayerTextDraw(playerid, 223.469985, 262.916748, "Comprar");
    PlayerTextDrawLetterSize(playerid, ConceDraw[playerid][5], 0.203220, 0.911665);
    PlayerTextDrawTextSize(playerid, ConceDraw[playerid][5], 251.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceDraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, ConceDraw[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, ConceDraw[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, ConceDraw[playerid][5], 113);
    PlayerTextDrawSetShadow(playerid, ConceDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, ConceDraw[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, ConceDraw[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, ConceDraw[playerid][5], true);

    ConceDraw[playerid][6] = CreatePlayerTextDraw(playerid, 276.370697, 263.500091, "Cancelar");
    PlayerTextDrawLetterSize(playerid, ConceDraw[playerid][6], 0.203689, 0.911665);
    PlayerTextDrawTextSize(playerid, ConceDraw[playerid][6], 304.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceDraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, ConceDraw[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, ConceDraw[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, ConceDraw[playerid][6], 113);
    PlayerTextDrawSetShadow(playerid, ConceDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, ConceDraw[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, ConceDraw[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, ConceDraw[playerid][6], true);

    for(new i=0; i < 7; i++){
        PlayerTextDrawShow(playerid, ConceDraw[playerid][i]);
    }
    SelectTextDrawEx(playerid, 0x00BFFFFF, "OcultarDrawConce", true);
    return 1;
}

stock MostrarConceY(playerid){
    ConceDrawY[playerid][0] = CreatePlayerTextDraw(playerid, 255.329376, 148.583328, "box");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][0], 0.000000, 16.907402);
    PlayerTextDrawTextSize(playerid, ConceDrawY[playerid][0], 381.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][0], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][0], 1010580735);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][0], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][0], 1);

    ConceDrawY[playerid][1] = CreatePlayerTextDraw(playerid, 255.329376, 148.583328, "box");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][1], 0.000000, 0.701393);
    PlayerTextDrawTextSize(playerid, ConceDrawY[playerid][1], 381.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][1], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][1], -56286977);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][1], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][1], 1);

    ConceDrawY[playerid][2] = CreatePlayerTextDraw(playerid, 259.077484, 146.833343, "Concessionaria");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][2], 0.210717, 0.952499);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][2], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][2], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][2], 1);

    ConceDrawY[playerid][3] = CreatePlayerTextDraw(playerid, 269.385192, 182.416671, "box");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][3], 0.000000, 1.098098);
    PlayerTextDrawTextSize(playerid, ConceDrawY[playerid][3], 368.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][3], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][3], 109);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][3], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][3], 1);

    ConceDrawY[playerid][4] = CreatePlayerTextDraw(playerid, 269.853485, 169.000030, "Nome");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][4], 0.209311, 0.987500);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][4], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][4], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][4], 1);

    ConceDrawY[playerid][5] = CreatePlayerTextDraw(playerid, 319.516754, 182.033370, "Shamal");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][5], 0.211185, 0.981666);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][5], 2);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][5], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][5], 1);

    ConceDrawY[playerid][6] = CreatePlayerTextDraw(playerid, 269.385192, 211.316741, "box");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][6], 0.000000, 1.098098);
    PlayerTextDrawTextSize(playerid, ConceDrawY[playerid][6], 368.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][6], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][6], 109);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][6], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][6], 1);

    ConceDrawY[playerid][7] = CreatePlayerTextDraw(playerid, 269.853485, 198.399902, "Modelo");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][7], 0.209311, 0.987500);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][7], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][7], 0);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][7], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][7], 1);

    ConceDrawY[playerid][8] = CreatePlayerTextDraw(playerid, 319.516754, 210.733245, "Airplane");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][8], 0.211185, 0.981666);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][8], 2);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][8], 0);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][8], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][8], 1);

    ConceDrawY[playerid][9] = CreatePlayerTextDraw(playerid, 268.916320, 236.083358, "Comprar");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][9], 0.206500, 1.016666);
    PlayerTextDrawTextSize(playerid, ConceDrawY[playerid][9], 297.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][9], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][9], -5963709);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][9], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, ConceDrawY[playerid][9], true);

    ConceDrawY[playerid][10] = CreatePlayerTextDraw(playerid, 309.517028, 236.083358, "Cancelar");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][10], 0.204158, 1.028332);
    PlayerTextDrawTextSize(playerid, ConceDrawY[playerid][10], 336.490722, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][10], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][10], -5963709);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][10], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, ConceDrawY[playerid][10], true);

    ConceDrawY[playerid][11] = CreatePlayerTextDraw(playerid, 345.285614, 232.583312, "~<~");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][11], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, ConceDrawY[playerid][11], 356.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][11], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][11], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, ConceDrawY[playerid][11], true);

    ConceDrawY[playerid][12] = CreatePlayerTextDraw(playerid, 361.385894, 232.583312, "~>~");
    PlayerTextDrawLetterSize(playerid, ConceDrawY[playerid][12], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, ConceDrawY[playerid][12], 371.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][12], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][12], 255);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, ConceDrawY[playerid][12], true);

    ConceDrawY[playerid][13] = CreatePlayerTextDraw(playerid, 316.068878, 245.416687, "");
    PlayerTextDrawTextSize(playerid, ConceDrawY[playerid][13], 62.000000, 56.000000);
    PlayerTextDrawAlignment(playerid, ConceDrawY[playerid][13], 1);
    PlayerTextDrawColor(playerid, ConceDrawY[playerid][13], -1);
    PlayerTextDrawUseBox(playerid, ConceDrawY[playerid][13], 0);
    PlayerTextDrawBoxColor(playerid, ConceDrawY[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, ConceDrawY[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, ConceDrawY[playerid][13], 0);
    PlayerTextDrawFont(playerid, ConceDrawY[playerid][13], 5);
    PlayerTextDrawSetProportional(playerid, ConceDrawY[playerid][13], 0);
    PlayerTextDrawSetPreviewModel(playerid, ConceDrawY[playerid][13], 519);
    PlayerTextDrawSetPreviewRot(playerid, ConceDrawY[playerid][13], -30.000000, 0.000000, 40.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, ConceDrawY[playerid][13], 1, 1);

    for(new i=0; i < 14; i++){
        PlayerTextDrawShow(playerid, ConceDrawY[playerid][i]);
    }
    SelectTextDrawEx(playerid, 0x00BFFFFF, "OcultarDrawY", true);
    return 1;
}

function OcultarDrawConce(playerid){
    for(new i=0; i < 7; i++){
        PlayerTextDrawDestroy(playerid, ConceDraw[playerid][i]);
        ConceDraw[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    CancelSelectTextDrawEx(playerid, "OcultarDrawConce");
    return 1;
}

function OcultarDrawY(playerid){
    for(new i=0; i < 14; i++){
        PlayerTextDrawDestroy(playerid, ConceDrawY[playerid][i]);
        ConceDrawY[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    CancelSelectTextDrawEx(playerid, "OcultarDrawY");
    return 1;
}