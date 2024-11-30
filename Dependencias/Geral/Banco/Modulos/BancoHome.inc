#include <YSI_Coding\y_hooks>

new PlayerText:BancoNHome[MAX_PLAYERS][6];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 6; i++){
        BancoNHome[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function MostrarBancoHome(playerid)
{
    BancoNHome[playerid][0] = CreatePlayerTextDraw(playerid, 271.875000, 197.000000, "box");
    PlayerTextDrawLetterSize(playerid, BancoNHome[playerid][0], 0.000000, 2.187500);
    PlayerTextDrawTextSize(playerid, BancoNHome[playerid][0], 366.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoNHome[playerid][0], 1);
    PlayerTextDrawColor(playerid, BancoNHome[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, BancoNHome[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, BancoNHome[playerid][0], 471604347);
    PlayerTextDrawSetShadow(playerid, BancoNHome[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoNHome[playerid][0], -5963521);
    PlayerTextDrawFont(playerid, BancoNHome[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BancoNHome[playerid][0], 1);

    BancoNHome[playerid][1] = CreatePlayerTextDraw(playerid, 292.268890, 200.299926, "Depositar");
    PlayerTextDrawLetterSize(playerid, BancoNHome[playerid][1], 0.341434, 1.401665);
    PlayerTextDrawTextSize(playerid, BancoNHome[playerid][1], 357.500030, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoNHome[playerid][1], 1);
    PlayerTextDrawColor(playerid, BancoNHome[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, BancoNHome[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, BancoNHome[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, BancoNHome[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoNHome[playerid][1], 61);
    PlayerTextDrawFont(playerid, BancoNHome[playerid][1], 3);
    PlayerTextDrawSetProportional(playerid, BancoNHome[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, BancoNHome[playerid][1], true);

    BancoNHome[playerid][2] = CreatePlayerTextDraw(playerid, 271.875000, 227.399536, "box");
    PlayerTextDrawLetterSize(playerid, BancoNHome[playerid][2], 0.000000, 2.187500);
    PlayerTextDrawTextSize(playerid, BancoNHome[playerid][2], 366.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoNHome[playerid][2], 1);
    PlayerTextDrawColor(playerid, BancoNHome[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, BancoNHome[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, BancoNHome[playerid][2], 471604347);
    PlayerTextDrawSetShadow(playerid, BancoNHome[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoNHome[playerid][2], -5963521);
    PlayerTextDrawFont(playerid, BancoNHome[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, BancoNHome[playerid][2], 1);

    BancoNHome[playerid][3] = CreatePlayerTextDraw(playerid, 301.800018, 231.099487, "Saque");
    PlayerTextDrawLetterSize(playerid, BancoNHome[playerid][3], 0.362049, 1.401666);
    PlayerTextDrawTextSize(playerid, BancoNHome[playerid][3], 341.600158, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoNHome[playerid][3], 1);
    PlayerTextDrawColor(playerid, BancoNHome[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, BancoNHome[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, BancoNHome[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, BancoNHome[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoNHome[playerid][3], 61);
    PlayerTextDrawFont(playerid, BancoNHome[playerid][3], 3);
    PlayerTextDrawSetProportional(playerid, BancoNHome[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, BancoNHome[playerid][3], true);

    BancoNHome[playerid][4] = CreatePlayerTextDraw(playerid, 271.875000, 257.799072, "box");
    PlayerTextDrawLetterSize(playerid, BancoNHome[playerid][4], 0.000000, 2.187500);
    PlayerTextDrawTextSize(playerid, BancoNHome[playerid][4], 366.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoNHome[playerid][4], 1);
    PlayerTextDrawColor(playerid, BancoNHome[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, BancoNHome[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, BancoNHome[playerid][4], 471604347);
    PlayerTextDrawSetShadow(playerid, BancoNHome[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoNHome[playerid][4], -5963521);
    PlayerTextDrawFont(playerid, BancoNHome[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, BancoNHome[playerid][4], 1);

    BancoNHome[playerid][5] = CreatePlayerTextDraw(playerid, 286.750091, 260.348999, "Transferir");
    PlayerTextDrawLetterSize(playerid, BancoNHome[playerid][5], 0.355958, 1.419165);
    PlayerTextDrawTextSize(playerid, BancoNHome[playerid][5], 357.800231, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoNHome[playerid][5], 1);
    PlayerTextDrawColor(playerid, BancoNHome[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, BancoNHome[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, BancoNHome[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, BancoNHome[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoNHome[playerid][5], 61);
    PlayerTextDrawFont(playerid, BancoNHome[playerid][5], 3);
    PlayerTextDrawSetProportional(playerid, BancoNHome[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, BancoNHome[playerid][5], true);


    for(new i=0; i < 6; i++){
        PlayerTextDrawShow(playerid, BancoNHome[playerid][i]);
    }

    SetPVarString(playerid, "BankFechar", "OcultarBancoHome");
    SetPVarString(playerid, "BankMostrar", "*");

    return 1;
}

function OcultarBancoHome(playerid)
{
    for(new i=0; i < 6; i++){
        PlayerTextDrawDestroy(playerid, BancoNHome[playerid][i]);
        BancoNHome[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == BancoNHome[playerid][1]){
        OcultarBancoHome(playerid);
        MostrarBancoDeposito(playerid);
    }
    else if(playertextid == BancoNHome[playerid][3]){
        OcultarBancoHome(playerid);
        MostrarBancoSaque(playerid);
    }
    else if(playertextid == BancoNHome[playerid][5]){
        OcultarBancoHome(playerid);
        MostrarBancoTransferencia(playerid);
    }
    return 0;
}