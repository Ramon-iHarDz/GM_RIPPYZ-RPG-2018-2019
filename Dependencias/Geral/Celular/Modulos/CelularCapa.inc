#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 13; i++){
        CelularCapa[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarCelular(playerid)
{
    CelularCapa[playerid][0] = CreatePlayerTextDraw(playerid, 404.367858, 272.883117, "ld_poke:cd1d");
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][0], 102.000000, 167.000000);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][0], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][0], 471604479);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][0], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][0], 0);

    CelularCapa[playerid][1] = CreatePlayerTextDraw(playerid, 409.353149, 280.749511, "box");
    PlayerTextDrawLetterSize(playerid, CelularCapa[playerid][1], 0.000000, 16.770832);
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][1], 501.669097, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][1], -2139062017);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][1], 471604479);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][1], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][1], 1);

    CelularCapa[playerid][2] = CreatePlayerTextDraw(playerid, 409.056365, 287.566497, "box");
    PlayerTextDrawLetterSize(playerid, CelularCapa[playerid][2], 0.000000, 13.427821);
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][2], 92.789978, 131.839721);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][2], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][2], -1);
    //PlayerTextDrawUseBox(playerid, CelularCapa[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][2], 512819199);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][2], 0);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][2], 1);

    /*CelularCapa[playerid][2] = CreatePlayerTextDraw(playerid, 409.056365, 287.566497, "vehicle:vehicleenvmap128");
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][2], 92.789978, 131.839721);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][2], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][2], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][2], 0);*/

    CelularCapa[playerid][3] = CreatePlayerTextDraw(playerid, 411.089538, 282.866455, "box");
    PlayerTextDrawLetterSize(playerid, CelularCapa[playerid][3], 0.000000, 1.030315);
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][3], 499.930084, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][3], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][3], 471604479);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][3], -2139062017);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][3], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][3], 1);

    CelularCapa[playerid][4] = CreatePlayerTextDraw(playerid, 436.852508, 279.099792, "ld_poke:cd1d");
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][4], 37.799903, 8.000000);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][4], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][4], 471604479);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][4], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][4], 0);

    CelularCapa[playerid][5] = CreatePlayerTextDraw(playerid, 448.897460, 421.850036, "ld_pool:ball");
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][5], 15.000000, 15.000000);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][5], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][5], -5963521);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][5], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, CelularCapa[playerid][5], true);

    CelularCapa[playerid][6] = CreatePlayerTextDraw(playerid, 449.597442, 422.750030, "ld_pool:ball"); // Voltar
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][6], 13.579998, 12.869997);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][6], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][6], 0);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][6], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, CelularCapa[playerid][6], true);

    CelularCapa[playerid][7] = CreatePlayerTextDraw(playerid, 439.847595, 281.000061, "box");
    PlayerTextDrawLetterSize(playerid, CelularCapa[playerid][7], 0.000000, 0.395314);
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][7], 471.999786, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][7], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][7], 471604479);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][7], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][7], 1);

    CelularCapa[playerid][8] = CreatePlayerTextDraw(playerid, 423.123535, 282.416717, PegarOperadora(playerid));
    PlayerTextDrawLetterSize(playerid, CelularCapa[playerid][8], 0.219618, 0.917497);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][8], 2);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][8], 0);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][8], 87);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][8], 1);

    CelularCapa[playerid][9] = CreatePlayerTextDraw(playerid, 488.423614, 282.616729, "00:00");
    PlayerTextDrawLetterSize(playerid, CelularCapa[playerid][9], 0.198065, 0.882498);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][9], 2);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][9], 0);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][9], 90);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][9], 1);

    CelularCapa[playerid][10] = CreatePlayerTextDraw(playerid, 464.291625, 280.233337, "ld_pool:ball");
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][10], 6.000000, 5.000000);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][10], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][10], 162);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][10], 0);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][10], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, CelularCapa[playerid][10], true);

    CelularCapa[playerid][11] = CreatePlayerTextDraw(playerid, 445.458160, 283.466583, "box");
    PlayerTextDrawLetterSize(playerid, CelularCapa[playerid][11], 0.000000, -0.213760);
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][11], 459.399963, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][11], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][11], 130);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][11], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][11], 1);

    CelularCapa[playerid][12] = CreatePlayerTextDraw(playerid, 411.309783, 296.633850, "box");
    PlayerTextDrawLetterSize(playerid, CelularCapa[playerid][12], 0.000000, 13.340002);
    PlayerTextDrawTextSize(playerid, CelularCapa[playerid][12], 500.100067, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularCapa[playerid][12], 1);
    PlayerTextDrawColor(playerid, CelularCapa[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, CelularCapa[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, CelularCapa[playerid][12], 44);
    PlayerTextDrawSetShadow(playerid, CelularCapa[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularCapa[playerid][12], 255);
    PlayerTextDrawFont(playerid, CelularCapa[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, CelularCapa[playerid][12], 1);

    for(new i=0; i < 13; i++){
        PlayerTextDrawShow(playerid, CelularCapa[playerid][i]);
    }

    pCelularEx[playerid][CellAberto] = true;
    pCelularEx[playerid][CellTID] = SetTimerEx("AtualizarHoraCelular", 1000, true, "d", playerid);

    SelectTextDrawEx(playerid, 0xFF8C00FF, "OcultarCelular", false);
    Jogador[playerid][AntiEsc] = true;
    return 1;
}

function OcultarCelular(playerid)
{
    CancelSelectTextDrawEx(playerid, "OcultarCelular");
    Jogador[playerid][AntiEsc] = false;

    if(pCelularEx[playerid][CellAberto] == true){
        pCelularEx[playerid][CellAberto] = false;
        KillTimer(pCelularEx[playerid][CellTID]);
    }

    for(new i=0; i < 13; i++){
        PlayerTextDrawDestroy(playerid, CelularCapa[playerid][i]);
        CelularCapa[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    SetPVarInt(playerid, "CerulaAberto", 0);
    return 1;
}

function AtualizarHoraCelular(playerid)
{
    new Horas, Minutos, Segundos, Kkapp[11];
    gettime(Horas, Minutos, Segundos);
    format(Kkapp, sizeof(Kkapp), "%02d:%02d", Horas, Minutos);
    PlayerTextDrawSetString(playerid, CelularCapa[playerid][9], Kkapp);
    return 1;
}