#include <YSI_Coding\y_hooks>

new PlayerText:LojaMoveis[MAX_PLAYERS][12];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 12; i++){
        LojaMoveis[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarLoja(playerid, const NomeCateg[])
{
    LojaMoveis[playerid][0] = CreatePlayerTextDraw(playerid, 197.500000, 108.333358, "box");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][0], 0.000000, 20.000000);
    PlayerTextDrawTextSize(playerid, LojaMoveis[playerid][0], 436.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][0], 1);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, LojaMoveis[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, LojaMoveis[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][0], 255);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][0], 0);

    LojaMoveis[playerid][1] = CreatePlayerTextDraw(playerid, 192.124786, 101.183319, "box");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][1], 0.000000, 1.125000);
    PlayerTextDrawTextSize(playerid, LojaMoveis[playerid][1], 333.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][1], 1);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, LojaMoveis[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, LojaMoveis[playerid][1], -5963521);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][1], 255);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][1], 0);

    LojaMoveis[playerid][2] = CreatePlayerTextDraw(playerid, 262.725128, 99.916641, "Loja_de_Moveis");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][2], 0.253123, 1.203331);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][2], 2);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][2], 66);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][2], 1);

    LojaMoveis[playerid][3] = CreatePlayerTextDraw(playerid, 256.425048, 122.233268, NomeCateg);
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][3], 0.242500, 1.150832);
    PlayerTextDrawTextSize(playerid, LojaMoveis[playerid][3], 0.000000, 58.000000);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][3], 2);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, LojaMoveis[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, LojaMoveis[playerid][3], 79);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][3], 255);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][3], 0);

    LojaMoveis[playerid][4] = CreatePlayerTextDraw(playerid, 260.000000, 155.000000, "");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][4], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, LojaMoveis[playerid][4], 114.000000, 107.000000);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][4], 1);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][4], 22);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, LojaMoveis[playerid][4], 19786);
    PlayerTextDrawSetPreviewRot(playerid, LojaMoveis[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);

    LojaMoveis[playerid][5] = CreatePlayerTextDraw(playerid, 394.650054, 199.599929, ">");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][5], 0.486874, 2.743333);
    PlayerTextDrawTextSize(playerid, LojaMoveis[playerid][5], 405.900054, 12.0000);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][5], 1);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, LojaMoveis[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, LojaMoveis[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][5], 255);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, LojaMoveis[playerid][5], true);

    LojaMoveis[playerid][6] = CreatePlayerTextDraw(playerid, 228.075378, 198.433258, "<");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][6], 0.486874, 2.743333);
    PlayerTextDrawTextSize(playerid, LojaMoveis[playerid][6], 238.200378, 12.0000);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][6], 1);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, LojaMoveis[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, LojaMoveis[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][6], 255);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, LojaMoveis[playerid][6], true);

    LojaMoveis[playerid][7] = CreatePlayerTextDraw(playerid, 200.000000, 273.999938, "Carrinho");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][7], 0.271874, 1.179998);
    PlayerTextDrawTextSize(playerid, LojaMoveis[playerid][7], 237.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][7], 1);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, LojaMoveis[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, LojaMoveis[playerid][7], 8388669);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][7], 1);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][7], 61);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, LojaMoveis[playerid][7], true);

    LojaMoveis[playerid][8] = CreatePlayerTextDraw(playerid, 423.950469, 109.383338, "ld_beat:cross");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, LojaMoveis[playerid][8], 11.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][8], 1);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][8], 255);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, LojaMoveis[playerid][8], true);

    LojaMoveis[playerid][9] = CreatePlayerTextDraw(playerid, 360.000000, 138.666625, ".");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][9], 0.249999, 1.156665);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][9], 2);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][9], 1);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][9], 61);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][9], 1);

    LojaMoveis[playerid][10] = CreatePlayerTextDraw(playerid, 361.875000, 272.833374, "hud:radar_cash");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][10], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, LojaMoveis[playerid][10], 11.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][10], 1);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][10], 255);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][10], 0);

    LojaMoveis[playerid][11] = CreatePlayerTextDraw(playerid, 372.924987, 273.316680, "0");
    PlayerTextDrawLetterSize(playerid, LojaMoveis[playerid][11], 0.206874, 1.028333);
    PlayerTextDrawAlignment(playerid, LojaMoveis[playerid][11], 1);
    PlayerTextDrawColor(playerid, LojaMoveis[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, LojaMoveis[playerid][11], 1);
    PlayerTextDrawBackgroundColor(playerid, LojaMoveis[playerid][11], 255);
    PlayerTextDrawFont(playerid, LojaMoveis[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, LojaMoveis[playerid][11], 1);
    PlayerTextDrawSetShadow(playerid, LojaMoveis[playerid][11], 0);

    for(new i=0; i < 12; i++){
        PlayerTextDrawShow(playerid, LojaMoveis[playerid][i]);
    }

    SelectTextDrawEx(playerid, 0xB22222FF, "OcultarLoja", true);
    return 1;
}

stock OcultarLoja(playerid)
{
    CancelSelectTextDrawEx(playerid, "OcultarLoja");
    for(new i=0; i < 12; i++){
        PlayerTextDrawDestroy(playerid, LojaMoveis[playerid][i]);
        LojaMoveis[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}