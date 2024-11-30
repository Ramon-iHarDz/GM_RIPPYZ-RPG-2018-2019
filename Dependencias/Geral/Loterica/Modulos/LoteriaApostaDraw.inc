#include <YSI_Coding\y_hooks>

new PlayerText:ApostaMenu[MAX_PLAYERS][11];

hook OnPlayerDisconnect(playerid, reason){
    for(new i=0; i < 11; i++){
        ApostaMenu[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarApostaMenu(playerid)
{
    ApostaMenu[playerid][0] = CreatePlayerTextDraw(playerid, 258.140411, 172.500015, "box");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][0], 0.000000, 12.933876);
    PlayerTextDrawTextSize(playerid, ApostaMenu[playerid][0], 385.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][0], 1);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][0], 255);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][0], 1);

    ApostaMenu[playerid][1] = CreatePlayerTextDraw(playerid, 258.140411, 172.500015, "box");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][1], 0.000000, 1.073895);
    PlayerTextDrawTextSize(playerid, ApostaMenu[playerid][1], 385.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][1], 1);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][1], -2139062217);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][1], 255);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][1], 1);

    ApostaMenu[playerid][2] = CreatePlayerTextDraw(playerid, 322.764923, 171.366638, "Loteria");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][2], 0.293177, 1.168332);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][2], 2);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][2], 52);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][2], 1);

    ApostaMenu[playerid][3] = CreatePlayerTextDraw(playerid, 321.354003, 191.166671, "Acumulado");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][3], 0.294582, 1.366665);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][3], 2);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][3], 60);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][3], 1);

    ApostaMenu[playerid][4] = CreatePlayerTextDraw(playerid, 321.253997, 204.067459, "R$0");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][4], 0.208842, 1.074997);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][4], 2);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][4], 8388863);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, ApostaMenu[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][4], 60);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][4], 1);

    ApostaMenu[playerid][5] = CreatePlayerTextDraw(playerid, 282.865203, 223.300109, "box");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][5], 0.000000, -0.319909);
    PlayerTextDrawTextSize(playerid, ApostaMenu[playerid][5], 356.580169, 0.000000);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][5], 1);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][5], 59);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][5], 255);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][5], 1);

    ApostaMenu[playerid][6] = CreatePlayerTextDraw(playerid, 274.507354, 232.833251, "Clique_aqui_para_apostar");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][6], 0.208373, 0.993332);
    PlayerTextDrawTextSize(playerid, ApostaMenu[playerid][6], 369.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][6], 1);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][6], 47);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ApostaMenu[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][6], 38);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, ApostaMenu[playerid][6], true);

    ApostaMenu[playerid][7] = CreatePlayerTextDraw(playerid, 274.507354, 250.133728, "Clique_aqui_para_apostar");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][7], 0.208373, 1.003332);
    PlayerTextDrawTextSize(playerid, ApostaMenu[playerid][7], 369.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][7], 1);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][7], 47);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ApostaMenu[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][7], 38);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, ApostaMenu[playerid][7], true);

    ApostaMenu[playerid][8] = CreatePlayerTextDraw(playerid, 310.109588, 264.066680, "");
    PlayerTextDrawTextSize(playerid, ApostaMenu[playerid][8], 23.000000, 24.000000);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][8], 1);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][8], 0);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][8], 0);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, ApostaMenu[playerid][8], true);
    PlayerTextDrawSetPreviewModel(playerid, ApostaMenu[playerid][8], 19134);
    PlayerTextDrawSetPreviewRot(playerid, ApostaMenu[playerid][8], 0.000000, -90.000000, 90.000000, 1.000000);

    ApostaMenu[playerid][9] = CreatePlayerTextDraw(playerid, 377.219329, 172.516723, "box");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][9], 0.000000, 1.092989);
    PlayerTextDrawTextSize(playerid, ApostaMenu[playerid][9], 385.110321, 0.000000);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][9], 1);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][9], -30527745);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][9], 255);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][9], 1);

    ApostaMenu[playerid][10] = CreatePlayerTextDraw(playerid, 378.081939, 172.550003, "X");
    PlayerTextDrawLetterSize(playerid, ApostaMenu[playerid][10], 0.259911, 1.098332);
    PlayerTextDrawTextSize(playerid, ApostaMenu[playerid][10], 385.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, ApostaMenu[playerid][10], 1);
    PlayerTextDrawColor(playerid, ApostaMenu[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, ApostaMenu[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, ApostaMenu[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, ApostaMenu[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, ApostaMenu[playerid][10], 255);
    PlayerTextDrawFont(playerid, ApostaMenu[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, ApostaMenu[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, ApostaMenu[playerid][10], true);

    for(new i=0; i < 11; i++){
        PlayerTextDrawShow(playerid, ApostaMenu[playerid][i]);
    }

    SelectTextDrawEx(playerid, 0x00BFFFFF, "OcultarApostaMenu", true);
    return 1;
}

function OcultarApostaMenu(playerid){
    CancelSelectTextDrawEx(playerid, "OcultarApostaMenu");
    for(new i=0; i < 11; i++){
        PlayerTextDrawDestroy(playerid, ApostaMenu[playerid][i]);
        ApostaMenu[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}