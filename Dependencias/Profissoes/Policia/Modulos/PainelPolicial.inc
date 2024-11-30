#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 11; i++){
        PainelPolicial[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarPainelPolicial(playerid)
{
    SelectTextDraw(playerid, 0xFFA500FF); 
    PainelPolicial[playerid][0] = CreatePlayerTextDraw(playerid, 167.715972, 89.666641, "box");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][0], 0.000000, 30.146408);
    PlayerTextDrawTextSize(playerid, PainelPolicial[playerid][0], 495.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][0], 1);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, PainelPolicial[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, PainelPolicial[playerid][0], -1061109505);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][0], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][0], 0);

    PainelPolicial[playerid][1] = CreatePlayerTextDraw(playerid, 169.521530, 91.999992, "box");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][1], 0.000000, 1.066436);
    PlayerTextDrawTextSize(playerid, PainelPolicial[playerid][1], 492.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][1], 1);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, PainelPolicial[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, PainelPolicial[playerid][1], 1211993087);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][1], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][1], 0);

    PainelPolicial[playerid][2] = CreatePlayerTextDraw(playerid, 170.625000, 108.916679, "box");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][2], 0.000000, 27.687500);
    PlayerTextDrawTextSize(playerid, PainelPolicial[playerid][2], 242.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][2], 1);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, PainelPolicial[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, PainelPolicial[playerid][2], 110);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][2], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][2], 0);

    PainelPolicial[playerid][3] = CreatePlayerTextDraw(playerid, 163.750000, 83.833343, "");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][3], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PainelPolicial[playerid][3], 26.000000, 25.000000);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][3], 1);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][3], 0);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][3], 0);
    PlayerTextDrawSetPreviewModel(playerid, PainelPolicial[playerid][3], 18646);
    PlayerTextDrawSetPreviewRot(playerid, PainelPolicial[playerid][3], 0.000000, 0.000000, 0.000000, 1.000000);

    PainelPolicial[playerid][4] = CreatePlayerTextDraw(playerid, 185.000000, 91.416648, "~>~");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][4], 0.136874, 1.016666);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][4], 1);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][4], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][4], 0);

    PainelPolicial[playerid][5] = CreatePlayerTextDraw(playerid, 196.950042, 90.649971, "Console");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][5], 0.259373, 1.197499);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][5], 1);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][5], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][5], 0);

    PainelPolicial[playerid][6] = CreatePlayerTextDraw(playerid, 481.300079, 91.766685, "box");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][6], 0.000000, 1.106498);
    PlayerTextDrawTextSize(playerid, PainelPolicial[playerid][6], 492.299957, 0.000000);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][6], 1);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, PainelPolicial[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, PainelPolicial[playerid][6], -16777065);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][6], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][6], 0);

    PainelPolicial[playerid][7] = CreatePlayerTextDraw(playerid, 483.274932, 90.166648, "X");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][7], 0.343748, 1.366665);
    PlayerTextDrawTextSize(playerid, PainelPolicial[playerid][7], 491.899993, 12.0000);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][7], 1);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][7], -1);
    //PlayerTextDrawUseBox(playerid, PainelPolicial[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, PainelPolicial[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][7], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][7], 0);
    PlayerTextDrawSetSelectable(playerid, PainelPolicial[playerid][7], true);

    PainelPolicial[playerid][8] = CreatePlayerTextDraw(playerid, 205.625000, 110.749984, "Suas_Prisoes:~n~~r~0");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][8], 0.222499, 0.993332);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][8], 2);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][8], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][8], 0);

    PainelPolicial[playerid][9] = CreatePlayerTextDraw(playerid, 340.549957, 115.333335, "Procurados(as)");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][9], 0.252499, 1.010833);
    PlayerTextDrawTextSize(playerid, PainelPolicial[playerid][9], 400.299957, 0.000000);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][9], 1);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, PainelPolicial[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, PainelPolicial[playerid][9], 96);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][9], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][9], 0);

    PainelPolicial[playerid][10] = CreatePlayerTextDraw(playerid, 370.749969, 133.233398, " ");
    PlayerTextDrawLetterSize(playerid, PainelPolicial[playerid][10], 0.151249, 0.794999);
    PlayerTextDrawTextSize(playerid, PainelPolicial[playerid][10], 0.000000, 237.000000);
    PlayerTextDrawAlignment(playerid, PainelPolicial[playerid][10], 2);
    PlayerTextDrawColor(playerid, PainelPolicial[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, PainelPolicial[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, PainelPolicial[playerid][10], 67);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PainelPolicial[playerid][10], 1);
    PlayerTextDrawBackgroundColor(playerid, PainelPolicial[playerid][10], 255);
    PlayerTextDrawFont(playerid, PainelPolicial[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, PainelPolicial[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, PainelPolicial[playerid][10], 0); 

    for(new i=0; i < 11; i++){
        PlayerTextDrawShow(playerid, PainelPolicial[playerid][i]);
    }

    SetPVarString(playerid, "ValorOcultar", "OcultarPainelPolicial");
    Jogador[playerid][AntiEsc] = true;
    return 1;
}

function OcultarPainelPolicial(playerid)
{
    CancelSelectTextDraw(playerid);
    for(new i=0; i < 11; i++){
        PlayerTextDrawDestroy(playerid, PainelPolicial[playerid][i]);
        PainelPolicial[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    Jogador[playerid][AntiEsc] = false;
    return 1;
}