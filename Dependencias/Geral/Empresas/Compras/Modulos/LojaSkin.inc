#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 11; i++){
        SkinT[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarLojaSkin(playerid)
{
    SkinT[playerid][0] = CreatePlayerTextDraw(playerid, 253.923324, 89.666664, "box");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][0], 0.000000, 24.102485);
    PlayerTextDrawTextSize(playerid, SkinT[playerid][0], 387.459625, 0.000000);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][0], 1);
    PlayerTextDrawColor(playerid, SkinT[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, SkinT[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, SkinT[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][0], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][0], 0);

    SkinT[playerid][1] = CreatePlayerTextDraw(playerid, 261.994323, 132.916671, "");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, SkinT[playerid][1], 118.000000, 138.000000);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][1], 1);
    PlayerTextDrawColor(playerid, SkinT[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][1], 0);
    PlayerTextDrawFont(playerid, SkinT[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, SkinT[playerid][1], 189);
    PlayerTextDrawSetPreviewRot(playerid, SkinT[playerid][1], 0.000000, 0.000000, 0.000000, 1.000000);

    SkinT[playerid][2] = CreatePlayerTextDraw(playerid, 275.475738, 191.166656, "<");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][2], 0.437950, 2.329166);
    PlayerTextDrawTextSize(playerid, SkinT[playerid][2], 288.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][2], 1);
    PlayerTextDrawColor(playerid, SkinT[playerid][2], -1);
    //PlayerTextDrawUseBox(playerid, SkinT[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, SkinT[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][2], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, SkinT[playerid][2], true);

    SkinT[playerid][3] = CreatePlayerTextDraw(playerid, 356.377777, 190.466659, ">");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][3], 0.437950, 2.329166);
    PlayerTextDrawTextSize(playerid, SkinT[playerid][3], 368.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][3], 1);
    PlayerTextDrawColor(playerid, SkinT[playerid][3], -1);
    //PlayerTextDrawUseBox(playerid, SkinT[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, SkinT[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][3], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, SkinT[playerid][3], true);

    SkinT[playerid][4] = CreatePlayerTextDraw(playerid, 322.150268, 266.899993, "$3.000");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][4], 0.306295, 1.203333);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][4], 2);
    PlayerTextDrawColor(playerid, SkinT[playerid][4], 8388863);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][4], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][4], 0);

    SkinT[playerid][5] = CreatePlayerTextDraw(playerid, 320.691040, 121.099983, "Pedestre");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][5], 0.295988, 1.465833);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][5], 2);
    PlayerTextDrawColor(playerid, SkinT[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][5], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][5], 0);

    SkinT[playerid][6] = CreatePlayerTextDraw(playerid, 320.091033, 108.500015, "Masculino");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][6], 0.204626, 1.139165);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][6], 2);
    PlayerTextDrawColor(playerid, SkinT[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][6], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][6], 0);

    SkinT[playerid][7] = CreatePlayerTextDraw(playerid, 245.095825, 83.200073, "Loja");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][7], 0.188696, 1.004999);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][7], 1);
    PlayerTextDrawColor(playerid, SkinT[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][7], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][7], 0);

    SkinT[playerid][8] = CreatePlayerTextDraw(playerid, 306.340759, 288.200073, "Comprar");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][8], 0.229926, 0.929164);
    PlayerTextDrawTextSize(playerid, SkinT[playerid][8], 338.199981, 12.0000);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][8], 1);
    PlayerTextDrawColor(playerid, SkinT[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, SkinT[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, SkinT[playerid][8], 8388707);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][8], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, SkinT[playerid][8], true);

    SkinT[playerid][9] = CreatePlayerTextDraw(playerid, 257.614593, 288.200073, "Acessorios");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][9], 0.229926, 0.929164);
    PlayerTextDrawTextSize(playerid, SkinT[playerid][9], 296.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][9], 1);
    PlayerTextDrawColor(playerid, SkinT[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, SkinT[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, SkinT[playerid][9], -5963673);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][9], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][9], 0);
    PlayerTextDrawSetSelectable(playerid, SkinT[playerid][9], true);

    SkinT[playerid][10] = CreatePlayerTextDraw(playerid, 381.911743, 89.650001, "X");
    PlayerTextDrawLetterSize(playerid, SkinT[playerid][10], 0.213059, 1.022499);
    PlayerTextDrawTextSize(playerid, SkinT[playerid][10], 387.400085, 12.0000);
    PlayerTextDrawAlignment(playerid, SkinT[playerid][10], 1);
    PlayerTextDrawColor(playerid, SkinT[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, SkinT[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, SkinT[playerid][10], -2147483576);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, SkinT[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, SkinT[playerid][10], 255);
    PlayerTextDrawFont(playerid, SkinT[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, SkinT[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, SkinT[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, SkinT[playerid][10], true);

    for(new i=0; i < 11; i++)
    {
        PlayerTextDrawShow(playerid, SkinT[playerid][i]);
    }
    SelectTextDrawEx(playerid, 0xB22222FF, "OcultarLojaSkin", true);
    return 1;
}

function OcultarLojaSkin(playerid)
{
    CancelSelectTextDrawEx(playerid, "OcultarLojaSkin");
    for(new i=0; i < 11; i++)
    {
        PlayerTextDrawDestroy(playerid, SkinT[playerid][i]);
        SkinT[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}