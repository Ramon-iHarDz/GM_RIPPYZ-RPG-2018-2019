#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 10; i++){
        AcessorioL[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarLojaAcessorios(playerid)
{
    AcessorioL[playerid][0] = CreatePlayerTextDraw(playerid, 253.923324, 89.666664, "box");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][0], 0.000000, 24.102485);
    PlayerTextDrawTextSize(playerid, AcessorioL[playerid][0], 387.459625, 0.000000);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][0], 1);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, AcessorioL[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, AcessorioL[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][0], 255);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][0], 0);

    AcessorioL[playerid][1] = CreatePlayerTextDraw(playerid, 261.994323, 132.916671, "");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, AcessorioL[playerid][1], 118.000000, 138.000000);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][1], 1);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][1], 0);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, AcessorioL[playerid][1], 1111);
    PlayerTextDrawSetPreviewRot(playerid, AcessorioL[playerid][1], 0.000000, 0.000000, 0.000000, 1.000000);

    AcessorioL[playerid][2] = CreatePlayerTextDraw(playerid, 275.475738, 191.166656, "<");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][2], 0.437949, 2.329165);
    PlayerTextDrawTextSize(playerid, AcessorioL[playerid][2], 288.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][2], 1);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][2], -1);
    //PlayerTextDrawUseBox(playerid, AcessorioL[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, AcessorioL[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][2], 255);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, AcessorioL[playerid][2], true);

    AcessorioL[playerid][3] = CreatePlayerTextDraw(playerid, 356.377777, 190.466659, ">");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][3], 0.437949, 2.329165);
    PlayerTextDrawTextSize(playerid, AcessorioL[playerid][3], 368.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][3], 1);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][3], -1);
    //PlayerTextDrawUseBox(playerid, AcessorioL[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, AcessorioL[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][3], 255);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, AcessorioL[playerid][3], true);

    AcessorioL[playerid][4] = CreatePlayerTextDraw(playerid, 322.150268, 266.899993, "$3.000");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][4], 0.306295, 1.203333);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][4], 2);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][4], 8388863);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][4], 255);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][4], 0);

    AcessorioL[playerid][5] = CreatePlayerTextDraw(playerid, 320.691040, 121.799972, "Pedestre");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][5], 0.295987, 1.465832);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][5], 2);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][5], 255);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][5], 0);

    AcessorioL[playerid][6] = CreatePlayerTextDraw(playerid, 320.091033, 108.500015, "Apenas_para_Vip_e_Nitro_Booster");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][6], 0.160585, 1.028330);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][6], 2);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][6], -65281);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][6], 255);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][6], 0);

    AcessorioL[playerid][7] = CreatePlayerTextDraw(playerid, 245.095825, 83.200073, "Loja");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][7], 0.188695, 1.004999);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][7], 1);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][7], 255);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][7], 0);

    AcessorioL[playerid][8] = CreatePlayerTextDraw(playerid, 306.340759, 288.200073, "Comprar");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][8], 0.229926, 0.929163);
    PlayerTextDrawTextSize(playerid, AcessorioL[playerid][8], 338.199981, 12.0000);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][8], 1);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, AcessorioL[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, AcessorioL[playerid][8], 8388707);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][8], 255);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, AcessorioL[playerid][8], true);

    AcessorioL[playerid][9] = CreatePlayerTextDraw(playerid, 381.911743, 89.650001, "X");
    PlayerTextDrawLetterSize(playerid, AcessorioL[playerid][9], 0.213058, 1.022498);
    PlayerTextDrawTextSize(playerid, AcessorioL[playerid][9], 387.400085, 12.0000);
    PlayerTextDrawAlignment(playerid, AcessorioL[playerid][9], 1);
    PlayerTextDrawColor(playerid, AcessorioL[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, AcessorioL[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, AcessorioL[playerid][9], -2147483576);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, AcessorioL[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, AcessorioL[playerid][9], 255);
    PlayerTextDrawFont(playerid, AcessorioL[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, AcessorioL[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, AcessorioL[playerid][9], 0);
    PlayerTextDrawSetSelectable(playerid, AcessorioL[playerid][9], true);

    for(new i=0; i < 10; i++)
    {
        PlayerTextDrawShow(playerid, AcessorioL[playerid][i]);
    }
    SelectTextDrawEx(playerid, 0xFFA500FF, "OcultarLojaAcessorios", true);
    return 1;
}

function OcultarLojaAcessorios(playerid)
{
    CancelSelectTextDrawEx(playerid, "OcultarLojaAcessorios");
    for(new i=0; i < 10; i++)
    {
        PlayerTextDrawDestroy(playerid, AcessorioL[playerid][i]);
        AcessorioL[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}