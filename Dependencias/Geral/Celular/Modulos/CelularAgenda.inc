#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 18; i++){
        CelularAgenda[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    for(new i=0; i < 3; i++){
        CelularAgendaOP[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    for(new i=0; i < 15; i++){
        CelularRecente[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function MostrarCelularAgenda(playerid)
{
    CelularAgenda[playerid][0] = CreatePlayerTextDraw(playerid, 456.482604, 403.666656, "0/30");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][0], 0.174172, 0.841667);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][0], 2);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][0], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][0], 1);

    CelularAgenda[playerid][1] = CreatePlayerTextDraw(playerid, 415.858215, 311.666961, "box");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][1], 0.000000, 0.853281);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][1], 496.170440, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][1], 167);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][1], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][1], 1);

    CelularAgenda[playerid][2] = CreatePlayerTextDraw(playerid, 408.536224, 308.349822, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][2], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][2], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][2], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][2], 0);

    CelularAgenda[playerid][3] = CreatePlayerTextDraw(playerid, 425.139556, 310.866729, "...");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][3], 0.212122, 0.958332);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][3], 496.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][3], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, CelularAgenda[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][3], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, CelularAgenda[playerid][3], true);

    CelularAgenda[playerid][4] = CreatePlayerTextDraw(playerid, 415.858215, 329.667114, "box");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][4], 0.000000, 0.853281);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][4], 496.170440, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][4], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][4], 167);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][4], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][4], 1);

    CelularAgenda[playerid][5] = CreatePlayerTextDraw(playerid, 408.536224, 326.349822, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][5], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][5], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][5], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][5], 0);

    CelularAgenda[playerid][6] = CreatePlayerTextDraw(playerid, 425.139556, 328.866729, "...");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][6], 0.225709, 0.952499);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][6], 497.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][6], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, CelularAgenda[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][6], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, CelularAgenda[playerid][6], true);

    CelularAgenda[playerid][7] = CreatePlayerTextDraw(playerid, 415.858215, 349.167114, "box");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][7], 0.000000, 0.853281);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][7], 496.170440, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][7], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][7], 167);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][7], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][7], 1);

    CelularAgenda[playerid][8] = CreatePlayerTextDraw(playerid, 408.536224, 345.349822, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][8], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][8], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][8], 0);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][8], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][8], 0);

    CelularAgenda[playerid][9] = CreatePlayerTextDraw(playerid, 425.139556, 347.866729, "...");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][9], 0.206031, 1.004999);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][9], 496.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][9], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, CelularAgenda[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][9], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, CelularAgenda[playerid][9], true);

    CelularAgenda[playerid][10] = CreatePlayerTextDraw(playerid, 415.858215, 368.167114, "box");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][10], 0.000000, 0.853281);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][10], 496.170440, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][10], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][10], 167);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][10], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][10], 1);

    CelularAgenda[playerid][11] = CreatePlayerTextDraw(playerid, 408.536224, 364.849822, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][11], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][11], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][11], 0);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][11], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][11], 0);

    CelularAgenda[playerid][12] = CreatePlayerTextDraw(playerid, 425.139556, 367.366729, "...");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][12], 0.225709, 0.946665);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][12], 497.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][12], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, CelularAgenda[playerid][12], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][12], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, CelularAgenda[playerid][12], true);

    CelularAgenda[playerid][13] = CreatePlayerTextDraw(playerid, 416.326751, 387.583770, "box");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][13], 0.000000, 0.853281);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][13], 497.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][13], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][13], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][13], 167);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][13], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][13], 1);

    CelularAgenda[playerid][14] = CreatePlayerTextDraw(playerid, 408.536224, 383.849822, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][14], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][14], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][14], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][14], 0);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][14], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][14], 0);

    CelularAgenda[playerid][15] = CreatePlayerTextDraw(playerid, 425.139556, 386.866729, "...");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][15], 0.217276, 0.940832);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][15], 498.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][15], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][15], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][15], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, CelularAgenda[playerid][15], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][15], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, CelularAgenda[playerid][15], true);

    CelularAgenda[playerid][16] = CreatePlayerTextDraw(playerid, 476.160369, 401.250030, "~>~");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][16], 0.288960, 1.302500);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][16], 484.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][16], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][16], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][16], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][16], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][16], 1);
    PlayerTextDrawSetSelectable(playerid, CelularAgenda[playerid][16], true);

    CelularAgenda[playerid][17] = CreatePlayerTextDraw(playerid, 427.660369, 401.250030, "~<~");
    PlayerTextDrawLetterSize(playerid, CelularAgenda[playerid][17], 0.288960, 1.302500);
    PlayerTextDrawTextSize(playerid, CelularAgenda[playerid][17], 435.500000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularAgenda[playerid][17], 1);
    PlayerTextDrawColor(playerid, CelularAgenda[playerid][17], -1);
    PlayerTextDrawUseBox(playerid, CelularAgenda[playerid][17], 0);
    PlayerTextDrawBoxColor(playerid, CelularAgenda[playerid][17], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgenda[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgenda[playerid][17], 255);
    PlayerTextDrawFont(playerid, CelularAgenda[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgenda[playerid][17], 1);
    PlayerTextDrawSetSelectable(playerid, CelularAgenda[playerid][17], true);

    for(new i=0; i < 18; i++){
        PlayerTextDrawShow(playerid, CelularAgenda[playerid][i]);
    }
    DeletePVar(playerid, "ApartirAgenda");
    DeletePVar(playerid, "AgendaReverb");
    DeletePVar(playerid, "Agendauvalor");

    DeletePVar(playerid, "Agenda1");
    DeletePVar(playerid, "Agenda2");
    DeletePVar(playerid, "Agenda3");
    DeletePVar(playerid, "Agenda4");
    DeletePVar(playerid, "Agenda5");

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarCelularAgenda");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarAgendaOP"); 
    AtualizarAgenda(playerid, false);
    return 1;
}

function MostrarCelularRecente(playerid)
{
    CelularRecente[playerid][0] = CreatePlayerTextDraw(playerid, 416.063659, 313.816802, "box"); 
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][0], 0.000000, 0.863835);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][0], 495.500030, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][0], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][0], 140);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][0], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][0], 1);

    CelularRecente[playerid][1] = CreatePlayerTextDraw(playerid, 409.773071, 310.316558, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][1], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][1], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][1], 0);

    CelularRecente[playerid][2] = CreatePlayerTextDraw(playerid, 426.339721, 312.266845, "Desconhecido");
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][2], 0.215402, 1.010830);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][2], 495.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][2], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][2], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, CelularRecente[playerid][2], true);

    CelularRecente[playerid][3] = CreatePlayerTextDraw(playerid, 416.063659, 333.717254, "box");
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][3], 0.000000, 0.863835);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][3], 495.500030, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][3], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][3], 140);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][3], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][3], 1);

    CelularRecente[playerid][4] = CreatePlayerTextDraw(playerid, 409.773071, 330.616912, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][4], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][4], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][4], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][4], 0);

    CelularRecente[playerid][5] = CreatePlayerTextDraw(playerid, 426.339721, 332.567199, "Desconhecido");
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][5], 0.215402, 1.010830);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][5], 495.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][5], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][5], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, CelularRecente[playerid][5], true);

    CelularRecente[playerid][6] = CreatePlayerTextDraw(playerid, 416.063659, 355.417633, "box");
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][6], 0.000000, 0.863835);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][6], 495.500030, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][6], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][6], 140);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][6], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][6], 1);

    CelularRecente[playerid][7] = CreatePlayerTextDraw(playerid, 409.773071, 351.617279, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][7], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][7], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][7], 0);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][7], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][7], 0);

    CelularRecente[playerid][8] = CreatePlayerTextDraw(playerid, 426.339721, 354.267578, "Desconhecido");
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][8], 0.215402, 1.010830);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][8], 495.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][8], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][8], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, CelularRecente[playerid][8], true);

    CelularRecente[playerid][9] = CreatePlayerTextDraw(playerid, 416.063659, 377.118011, "box");
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][9], 0.000000, 0.863835);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][9], 495.500030, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][9], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][9], 140);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][9], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][9], 1);

    CelularRecente[playerid][10] = CreatePlayerTextDraw(playerid, 409.773071, 373.317657, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][10], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][10], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][10], 0);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][10], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][10], 0);

    CelularRecente[playerid][11] = CreatePlayerTextDraw(playerid, 426.339721, 375.767425, "Desconhecido");
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][11], 0.215402, 1.010830);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][11], 495.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][11], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][11], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, CelularRecente[playerid][11], true);

    CelularRecente[playerid][12] = CreatePlayerTextDraw(playerid, 416.063659, 399.317108, "box");
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][12], 0.000000, 0.863835);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][12], 495.500030, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][12], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][12], 140);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][12], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][12], 1);

    CelularRecente[playerid][13] = CreatePlayerTextDraw(playerid, 409.773071, 395.516754, "hud:radar_gangn");
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][13], 14.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][13], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][13], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][13], 0);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][13], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][13], 0);

    CelularRecente[playerid][14] = CreatePlayerTextDraw(playerid, 426.339721, 397.666534, "Desconhecido");
    PlayerTextDrawLetterSize(playerid, CelularRecente[playerid][14], 0.215402, 1.010830);
    PlayerTextDrawTextSize(playerid, CelularRecente[playerid][14], 495.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularRecente[playerid][14], 1);
    PlayerTextDrawColor(playerid, CelularRecente[playerid][14], -1);
    PlayerTextDrawUseBox(playerid, CelularRecente[playerid][14], 1);
    PlayerTextDrawBoxColor(playerid, CelularRecente[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, CelularRecente[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularRecente[playerid][14], 255);
    PlayerTextDrawFont(playerid, CelularRecente[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, CelularRecente[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, CelularRecente[playerid][14], true);

    for(new i=0; i < 15; i++){
        PlayerTextDrawShow(playerid, CelularRecente[playerid][i]);
    }

    AtualizarRecentes(playerid);

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarCelularRecente");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarAgendaOP");
    return 1;
}

function OcultarCelularRecente(playerid)
{
    for(new i=0; i < 15; i++){
        PlayerTextDrawDestroy(playerid, CelularRecente[playerid][i]);
        CelularRecente[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    } 
    return 1;
}

function MostrarAgendaOP(playerid)
{
    CelularAgendaOP[playerid][0] = CreatePlayerTextDraw(playerid, 410.895690, 296.733093, "box");
    PlayerTextDrawLetterSize(playerid, CelularAgendaOP[playerid][0], 0.000000, 13.427821);
    PlayerTextDrawTextSize(playerid, CelularAgendaOP[playerid][0], 500.299865, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularAgendaOP[playerid][0], 1);
    PlayerTextDrawColor(playerid, CelularAgendaOP[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularAgendaOP[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgendaOP[playerid][0], 512819199);
    PlayerTextDrawSetShadow(playerid, CelularAgendaOP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularAgendaOP[playerid][0], 255);
    PlayerTextDrawFont(playerid, CelularAgendaOP[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgendaOP[playerid][0], 1);

    CelularAgendaOP[playerid][1] = CreatePlayerTextDraw(playerid, 431.782592, 330.066680, "Historico");
    PlayerTextDrawLetterSize(playerid, CelularAgendaOP[playerid][1], 0.353147, 1.535832);
    PlayerTextDrawTextSize(playerid, CelularAgendaOP[playerid][1], 481.000000, 12.0000); 
    PlayerTextDrawAlignment(playerid, CelularAgendaOP[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularAgendaOP[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CelularAgendaOP[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgendaOP[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgendaOP[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularAgendaOP[playerid][1], 90);
    PlayerTextDrawFont(playerid, CelularAgendaOP[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgendaOP[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, CelularAgendaOP[playerid][1], true);

    CelularAgendaOP[playerid][2] = CreatePlayerTextDraw(playerid, 431.182586, 353.467010, "Contatos"); 
    PlayerTextDrawLetterSize(playerid, CelularAgendaOP[playerid][2], 0.353147, 1.535832);
    PlayerTextDrawTextSize(playerid, CelularAgendaOP[playerid][2], 482.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularAgendaOP[playerid][2], 1);
    PlayerTextDrawColor(playerid, CelularAgendaOP[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularAgendaOP[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, CelularAgendaOP[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CelularAgendaOP[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularAgendaOP[playerid][2], 90);
    PlayerTextDrawFont(playerid, CelularAgendaOP[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CelularAgendaOP[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, CelularAgendaOP[playerid][2], true);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, CelularAgendaOP[playerid][i]);
    }
    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarAgendaOP");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarHome");
    return 1;
}

function OcultarAgendaOP(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, CelularAgendaOP[playerid][i]);
        CelularAgendaOP[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }  
    return 1;
}

function OcultarCelularAgenda(playerid)
{
    for(new i=0; i < 18; i++){
        PlayerTextDrawDestroy(playerid, CelularAgenda[playerid][i]);
        CelularAgenda[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    DeletePVar(playerid, "ApartirAgenda");
    DeletePVar(playerid, "AgendaReverb");
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    // Direita - Frente
    if(playertextid == CelularAgenda[playerid][16]) AtualizarAgenda(playerid, false);
    // Esquerda - Trás
    if(playertextid == CelularAgenda[playerid][17]) AtualizarAgenda(playerid, true); 

    else if(playertextid == CelularAgenda[playerid][3]){
        SelecinarContato(playerid, 1);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if(playertextid == CelularAgenda[playerid][6]){
        SelecinarContato(playerid, 2);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if(playertextid == CelularAgenda[playerid][9]){
        SelecinarContato(playerid, 3);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    else if(playertextid == CelularAgenda[playerid][12]){
        SelecinarContato(playerid, 4);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if(playertextid == CelularAgenda[playerid][15]){
        SelecinarContato(playerid, 5);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // Selecionar Últimas Ligações
    else if(playertextid == CelularRecente[playerid][3]){
        SelecionarRecentes(playerid, 0);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if(playertextid == CelularRecente[playerid][6]){
        SelecionarRecentes(playerid, 1);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if(playertextid == CelularRecente[playerid][9]){
        SelecionarRecentes(playerid, 2);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if(playertextid == CelularRecente[playerid][12]){
        SelecionarRecentes(playerid, 3);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    else if(playertextid == CelularRecente[playerid][15]){
        SelecionarRecentes(playerid, 4);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // Últimas Ligações
    else if(playertextid == CelularAgendaOP[playerid][1]){
        OcultarAgendaOP(playerid);
        MostrarCelularRecente(playerid);
        return Y_HOOKS_BREAK_RETURN_1;   
    }

    // Abrir Agenda
    else if(playertextid == CelularAgendaOP[playerid][2]){
        OcultarAgendaOP(playerid);
        MostrarCelularAgenda(playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    return 0;
}

Dialog:AlterarContatoNome(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "SlotAtualAgenda");
    if(isnull(inputtext)) return MostrarDialogContato(playerid, id);
    if(strlen(inputtext) > 30){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou um nome muito grande");
        MostrarDialogContato(playerid, id);
        return 1;
    }
    new Enviar[190];
    format(Enviar, sizeof(Enviar), "UPDATE `celular` SET `Contato`='%s' WHERE `Nome`='%s' AND `NumeroNome`='%s'", EscapeString(inputtext), EscapeString(PegarNick(playerid)), EscapeString(pAgenda[playerid][id][aNome]));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao salvar o nome desse contato");
    
    format(pAgenda[playerid][id][Contato], 30, inputtext);
    AtualizarAgendaTextdraw(playerid, GetPVarInt(playerid, "SlotTextdraw"));

    format(Enviar, sizeof(Enviar), "| AGENDA | Você alterou o contato do(a) {FF4500}%s{FFFFFF} para {00BFFF}%s", pAgenda[playerid][id][aNome], inputtext);
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}

Dialog:ContatoOpcao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "SlotAtualAgenda");
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, AlterarContatoNome, DIALOG_STYLE_INPUT, "{FF0000}Agenda", "Coloque abaixo um novo nome para seu contato", "Alterar", "Cancelar");
        case 1: MostrarDialogContato(playerid, id);
        case 2:
        {
            new Enviar[190];
            format(Enviar, sizeof(Enviar), "DELETE FROM `celular` WHERE `Nome`='%s' AND `NumeroNome`='%s'", EscapeString(PegarNick(playerid)), EscapeString(pAgenda[playerid][id][aNome]));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao deletar esse contato");  
            
            format(Enviar, sizeof(Enviar), "| AGENDA | Você deletou o contato de {00BFFF}%s", pAgenda[playerid][id][aNome]);
            SendClientMessage(playerid, -1, Enviar);

            new Delet31231ar[AgendaTelefonica];
            pAgenda[playerid][id] = Delet31231ar; 
            AtualizarAgendaTextdraw(playerid, GetPVarInt(playerid, "SlotTextdraw"));
        }
        case 3:
        {
            if(GetPVarInt(playerid, "EmLigacao") > 0){
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está em ligação");
                MostrarDialogContato(playerid, id);
                return 1;
            }
            if(Jogador[playerid][Operadora] == 0){
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem um Chip");
                MostrarDialogContato(playerid, id);
                return 1;
            }
            new i = PegarIdPeloNickEx(pAgenda[playerid][id][aNome]);
            if(!IsPlayerConnected(i)){
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
                MostrarDialogContato(playerid, id);
                return 1;
            }
            if(Jogador[i][Logado] == false){
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está disponível para ligações");
                MostrarDialogContato(playerid, id);
                return 1;  
            }
            if(Jogador[i][Operadora] == 0){
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) está sem chip");
                MostrarDialogContato(playerid, id);
                return 1;  
            }
            if(GetPVarInt(i, "EmLigacao") > 0){
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) já está em ligação");
                MostrarDialogContato(playerid, id);
                return 1;
            }
            SetPVarInt(playerid, "EuChamando", 1);
            EnviarLigacao(playerid, i);
        }
    }
    return 1;
}

Dialog:AdicionarNumeroAgenda(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(!ApenasNumeros(inputtext)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Número Inválido");

    new iNumero;
    sscanf(inputtext, "d", iNumero);
    if(iNumero == Jogador[playerid][pNumero]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode adicionar seu próprio número");
    if(iNumero < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Número Inválido");
    new Enviar[228],
        Cache:Conectar;
    format(Enviar, sizeof(Enviar), "SELECT * FROM `rippzyrpg` WHERE `Numero` = %d", iNumero);
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Erro ao verificar número");
    if(cache_num_rows() < 1)
    {
        SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse número não existe");
        cache_delete(Conectar);
        return 1;
    }
    new NomeCTTB[30];
    cache_get_value_name(0, "Nome", NomeCTTB, 30);
    cache_delete(Conectar);

    stringclear(Enviar);
    strcat(Enviar, "INSERT INTO `celular` ");
    strcat(Enviar, "(`Nome`, `Numero`, `NumeroNome`, `Contato`, `Data`) VALUES ");
    strcatEx(Enviar, "('%s', %d, '%s', '%s', %d)", EscapeString(PegarNick(playerid)), iNumero, EscapeString(NomeCTTB), EscapeString(NomeCTTB), gettime());
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao adicionar esse número");

    new i = PegarLocalAgenda(playerid); 
    format(pAgenda[playerid][i][Contato], 30, NomeCTTB);
    format(pAgenda[playerid][i][aNome], 30, NomeCTTB);
    pAgenda[playerid][i][aNumero] = iNumero;
    pAgenda[playerid][i][aUsada] = true;

    new slot = GetPVarInt(playerid, "SlotTextdraw"),
        mdss[11];
    format(mdss, 11, "Agenda%d", slot);
    SetPVarInt(playerid, mdss, i);
    SetPVarInt(playerid, "SlotAtualAgenda", i); 

    format(Enviar, sizeof(Enviar), "| AGENDA | Você adicionou o contato de {fc520f}%s{FFFFFF} na sua agenda", NomeCTTB);
    SendClientMessage(playerid, -1, Enviar);

    AtualizarAgendaTextdraw(playerid, GetPVarInt(playerid, "SlotTextdraw")); 
    return 1;
}