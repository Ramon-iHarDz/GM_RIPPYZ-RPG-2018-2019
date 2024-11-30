stock MostrarGariMenuLixo(playerid)
{
    GariMenu[playerid][0] = CreatePlayerTextDraw(playerid, 24.375000, 226.749954, "0/250");
    PlayerTextDrawLetterSize(playerid, GariMenu[playerid][0], 0.200624, 0.882499);
    PlayerTextDrawAlignment(playerid, GariMenu[playerid][0], 2);
    PlayerTextDrawColor(playerid, GariMenu[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, GariMenu[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, GariMenu[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, GariMenu[playerid][0], 255);
    PlayerTextDrawFont(playerid, GariMenu[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, GariMenu[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, GariMenu[playerid][0], 0);

    GariMenu[playerid][1] = CreatePlayerTextDraw(playerid, -3.125000, 213.333297, "");
    PlayerTextDrawLetterSize(playerid, GariMenu[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, GariMenu[playerid][1], 27.000000, 24.000000);
    PlayerTextDrawAlignment(playerid, GariMenu[playerid][1], 1);
    PlayerTextDrawColor(playerid, GariMenu[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, GariMenu[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, GariMenu[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, GariMenu[playerid][1], 0);
    PlayerTextDrawFont(playerid, GariMenu[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, GariMenu[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, GariMenu[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, GariMenu[playerid][1], 1264);
    PlayerTextDrawSetPreviewRot(playerid, GariMenu[playerid][1], 0.000000, 0.000000, 0.000000, 1.000000);

    GariMenu[playerid][2] = CreatePlayerTextDraw(playerid, 3.750000, 213.216674, "");
    PlayerTextDrawLetterSize(playerid, GariMenu[playerid][2], 0.000000, 3.180496);
    PlayerTextDrawTextSize(playerid, GariMenu[playerid][2], 43.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, GariMenu[playerid][2], 1);
    PlayerTextDrawColor(playerid, GariMenu[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, GariMenu[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, GariMenu[playerid][2], 35);
    PlayerTextDrawSetShadow(playerid, GariMenu[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, GariMenu[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, GariMenu[playerid][2], 255);
    PlayerTextDrawFont(playerid, GariMenu[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, GariMenu[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, GariMenu[playerid][2], 0);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, GariMenu[playerid][i]);
    }
    return 1;
}

stock OcultarMenuGari(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawHide(playerid, GariMenu[playerid][i]);
    }
    return 1;
}