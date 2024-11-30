new PlayerText:UberTxd[MAX_PLAYERS][5];

stock MostrarUber(playerid)
{
    UberTxd[playerid][0] = CreatePlayerTextDraw(playerid, 6.875000, 166.083374, "box");
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][0], 0.000000, 4.698506);
    PlayerTextDrawTextSize(playerid, UberTxd[playerid][0], 84.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][0], 1);
    PlayerTextDrawColor(playerid, UberTxd[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, UberTxd[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, UberTxd[playerid][0], 39);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, UberTxd[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][0], 255);
    PlayerTextDrawFont(playerid, UberTxd[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][0], 0);

    UberTxd[playerid][1] = CreatePlayerTextDraw(playerid, 7.300000, 179.333145, "box");
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][1], 0.000000, 3.136990);
    PlayerTextDrawTextSize(playerid, UberTxd[playerid][1], 83.690017, 0.000000);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][1], 1);
    PlayerTextDrawColor(playerid, UberTxd[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, UberTxd[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, UberTxd[playerid][1], -2139062186);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, UberTxd[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][1], 255);
    PlayerTextDrawFont(playerid, UberTxd[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][1], 0);

    UberTxd[playerid][2] = CreatePlayerTextDraw(playerid, 44.525028, 165.050125, "Uber");
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][2], 0.200624, 1.028332);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][2], 2);
    PlayerTextDrawColor(playerid, UberTxd[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, UberTxd[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][2], 255);
    PlayerTextDrawFont(playerid, UberTxd[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][2], 1);

    UberTxd[playerid][3] = CreatePlayerTextDraw(playerid, 8.425001, 181.949890, " "); //Passageiro
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][3], 0.165000, 0.916666);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][3], 1);
    PlayerTextDrawColor(playerid, UberTxd[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, UberTxd[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][3], 255);
    PlayerTextDrawFont(playerid, UberTxd[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][3], 0);

    UberTxd[playerid][4] = CreatePlayerTextDraw(playerid, 8.425001, 192.850555, " "); //Money
    PlayerTextDrawLetterSize(playerid, UberTxd[playerid][4], 0.180000, 0.939999);
    PlayerTextDrawAlignment(playerid, UberTxd[playerid][4], 1);
    PlayerTextDrawColor(playerid, UberTxd[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, UberTxd[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, UberTxd[playerid][4], 255);
    PlayerTextDrawFont(playerid, UberTxd[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, UberTxd[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, UberTxd[playerid][4], 0);

    for(new i=0; i < 5; i++){
        PlayerTextDrawShow(playerid, UberTxd[playerid][i]);
    }
    return 1;
}

stock OcultarUber(playerid)
{
    for(new i=0; i < 5; i++){
        PlayerTextDrawHide(playerid, UberTxd[playerid][i]);
    }
    return 1;
}