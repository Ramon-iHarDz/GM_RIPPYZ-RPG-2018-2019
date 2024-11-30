#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 18; i++){
        CelularHome[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function MostrarHome(playerid)
{
    CelularHome[playerid][0] = CreatePlayerTextDraw(playerid, 420.643432, 308.916442, "hud:radar_gangb");
    PlayerTextDrawTextSize(playerid, CelularHome[playerid][0], 13.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][0], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][0], 255);
    PlayerTextDrawFont(playerid, CelularHome[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, CelularHome[playerid][0], true);

    CelularHome[playerid][1] = CreatePlayerTextDraw(playerid, 414.626617, 323.249908, "Agenda");
    PlayerTextDrawLetterSize(playerid, CelularHome[playerid][1], 0.192445, 1.010832);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, CelularHome[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][1], 59);
    PlayerTextDrawFont(playerid, CelularHome[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][1], 1);

    CelularHome[playerid][2] = CreatePlayerTextDraw(playerid, 453.310638, 310.616394, "hud:radar_modgarage");
    PlayerTextDrawTextSize(playerid, CelularHome[playerid][2], 12.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][2], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][2], 255);
    PlayerTextDrawFont(playerid, CelularHome[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, CelularHome[playerid][2], true);

    CelularHome[playerid][3] = CreatePlayerTextDraw(playerid, 446.425384, 323.549896, "Mecanico");
    PlayerTextDrawLetterSize(playerid, CelularHome[playerid][3], 0.178389, 0.993332);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][3], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, CelularHome[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][3], 59);
    PlayerTextDrawFont(playerid, CelularHome[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][3], 1);

    CelularHome[playerid][4] = CreatePlayerTextDraw(playerid, 483.009490, 310.816406, "hud:radar_police");
    PlayerTextDrawTextSize(playerid, CelularHome[playerid][4], 11.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][4], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][4], 255);
    PlayerTextDrawFont(playerid, CelularHome[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, CelularHome[playerid][4], true);

    CelularHome[playerid][5] = CreatePlayerTextDraw(playerid, 479.224090, 323.849884, "Policia");
    PlayerTextDrawLetterSize(playerid, CelularHome[playerid][5], 0.171830, 0.940832);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][5], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, CelularHome[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][5], 59);
    PlayerTextDrawFont(playerid, CelularHome[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][5], 1);

    CelularHome[playerid][6] = CreatePlayerTextDraw(playerid, 422.577697, 342.115173, "hud:radar_hostpital");
    PlayerTextDrawTextSize(playerid, CelularHome[playerid][6], 11.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][6], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][6], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][6], 255);
    PlayerTextDrawFont(playerid, CelularHome[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, CelularHome[playerid][6], true);

    CelularHome[playerid][7] = CreatePlayerTextDraw(playerid, 413.023742, 354.650054, "Paramedico");
    PlayerTextDrawLetterSize(playerid, CelularHome[playerid][7], 0.155431, 0.975832);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][7], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][7], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, CelularHome[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][7], 59);
    PlayerTextDrawFont(playerid, CelularHome[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][7], 1);

    CelularHome[playerid][8] = CreatePlayerTextDraw(playerid, 454.109161, 340.615173, "hud:radar_impound");
    PlayerTextDrawTextSize(playerid, CelularHome[playerid][8], 12.000000, 14.000000);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][8], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][8], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][8], 255);
    PlayerTextDrawFont(playerid, CelularHome[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, CelularHome[playerid][8], true);

    CelularHome[playerid][9] = CreatePlayerTextDraw(playerid, 453.724090, 355.349884, "Uber");
    PlayerTextDrawLetterSize(playerid, CelularHome[playerid][9], 0.180731, 0.923332);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][9], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][9], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, CelularHome[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][9], 59);
    PlayerTextDrawFont(playerid, CelularHome[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][9], 1);

    CelularHome[playerid][10] = CreatePlayerTextDraw(playerid, 482.109161, 342.115173, "hud:radar_waypoint");
    PlayerTextDrawTextSize(playerid, CelularHome[playerid][10], 12.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][10], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][10], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][10], 255);
    PlayerTextDrawFont(playerid, CelularHome[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, CelularHome[playerid][10], true);

    CelularHome[playerid][11] = CreatePlayerTextDraw(playerid, 482.724090, 355.349884, "Gps");
    PlayerTextDrawLetterSize(playerid, CelularHome[playerid][11], 0.180731, 0.923332);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][11], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][11], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, CelularHome[playerid][11], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][11], 59);
    PlayerTextDrawFont(playerid, CelularHome[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][11], 1);

    CelularHome[playerid][12] = CreatePlayerTextDraw(playerid, 422.940612, 374.115173, "hud:radar_datedisco");
    PlayerTextDrawTextSize(playerid, CelularHome[playerid][12], 11.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][12], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][12], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][12], 255);
    PlayerTextDrawFont(playerid, CelularHome[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][12], 0);
    PlayerTextDrawSetSelectable(playerid, CelularHome[playerid][12], true);

    CelularHome[playerid][13] = CreatePlayerTextDraw(playerid, 421.924591, 387.349884, "MP3");
    PlayerTextDrawLetterSize(playerid, CelularHome[playerid][13], 0.180730, 0.923331);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][13], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][13], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][13], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, CelularHome[playerid][13], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][13], 59);
    PlayerTextDrawFont(playerid, CelularHome[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][13], 1);

    CelularHome[playerid][14] = CreatePlayerTextDraw(playerid, 454.540527, 373.615173, "hud:radar_cash");
    PlayerTextDrawTextSize(playerid, CelularHome[playerid][14], 10.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][14], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][14], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][14], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][14], 255);
    PlayerTextDrawFont(playerid, CelularHome[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][14], 0);
    PlayerTextDrawSetSelectable(playerid, CelularHome[playerid][14], true);

    CelularHome[playerid][15] = CreatePlayerTextDraw(playerid, 450.823974, 387.349884, "Banco");
    PlayerTextDrawLetterSize(playerid, CelularHome[playerid][15], 0.180730, 0.923331);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][15], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][15], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][15], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][15], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, CelularHome[playerid][15], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][15], 59);
    PlayerTextDrawFont(playerid, CelularHome[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][15], 1);

    CelularHome[playerid][16] = CreatePlayerTextDraw(playerid, 483.140625, 374.615173, "hud:radar_light");
    PlayerTextDrawTextSize(playerid, CelularHome[playerid][16], 10.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][16], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][16], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][16], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][16], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][16], 255);
    PlayerTextDrawFont(playerid, CelularHome[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][16], 0);
    PlayerTextDrawSetSelectable(playerid, CelularHome[playerid][16], true);

    CelularHome[playerid][17] = CreatePlayerTextDraw(playerid, 482.724090, 387.349884, "Olx");
    PlayerTextDrawLetterSize(playerid, CelularHome[playerid][17], 0.180730, 0.923331);
    PlayerTextDrawAlignment(playerid, CelularHome[playerid][17], 1);
    PlayerTextDrawColor(playerid, CelularHome[playerid][17], -1);
    PlayerTextDrawUseBox(playerid, CelularHome[playerid][17], 0);
    PlayerTextDrawBoxColor(playerid, CelularHome[playerid][17], 0);
    PlayerTextDrawSetShadow(playerid, CelularHome[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, CelularHome[playerid][17], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularHome[playerid][17], 59);
    PlayerTextDrawFont(playerid, CelularHome[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, CelularHome[playerid][17], 1);

    for(new i=0; i < 18; i++){
        PlayerTextDrawShow(playerid, CelularHome[playerid][i]);
    }

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarCelular");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "*");

    return 1;
}

stock OcultarHome(playerid)
{
    for(new i=0; i < 18; i++){
        PlayerTextDrawDestroy(playerid, CelularHome[playerid][i]);
        CelularHome[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}