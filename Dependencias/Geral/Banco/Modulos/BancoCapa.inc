#include <YSI_Coding\y_hooks>

new PlayerText:BancoCapa[MAX_PLAYERS][9];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 9; i++){
        BancoCapa[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function MostrarBancoCapa(playerid)
{
    BancoCapa[playerid][0] = CreatePlayerTextDraw(playerid, 203.624725, 117.033355, "box");
    PlayerTextDrawLetterSize(playerid, BancoCapa[playerid][0], 0.000000, 19.812500);
    PlayerTextDrawTextSize(playerid, BancoCapa[playerid][0], 434.499725, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoCapa[playerid][0], 1);
    PlayerTextDrawColor(playerid, BancoCapa[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, BancoCapa[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, BancoCapa[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, BancoCapa[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoCapa[playerid][0], 255);
    PlayerTextDrawFont(playerid, BancoCapa[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BancoCapa[playerid][0], 1);

    BancoCapa[playerid][1] = CreatePlayerTextDraw(playerid, 205.499725, 120.783325, "box");
    PlayerTextDrawLetterSize(playerid, BancoCapa[playerid][1], 0.000000, 1.185499);
    PlayerTextDrawTextSize(playerid, BancoCapa[playerid][1], 432.950469, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoCapa[playerid][1], 1);
    PlayerTextDrawColor(playerid, BancoCapa[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, BancoCapa[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, BancoCapa[playerid][1], 99);
    PlayerTextDrawSetShadow(playerid, BancoCapa[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoCapa[playerid][1], 255);
    PlayerTextDrawFont(playerid, BancoCapa[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, BancoCapa[playerid][1], 1);

    BancoCapa[playerid][2] = CreatePlayerTextDraw(playerid, 208.125000, 119.416664, PegarNick(playerid));
    PlayerTextDrawLetterSize(playerid, BancoCapa[playerid][2], 0.289999, 1.302499);
    PlayerTextDrawAlignment(playerid, BancoCapa[playerid][2], 1);
    PlayerTextDrawColor(playerid, BancoCapa[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, BancoCapa[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoCapa[playerid][2], 60);
    PlayerTextDrawFont(playerid, BancoCapa[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, BancoCapa[playerid][2], 1);

    BancoCapa[playerid][3] = CreatePlayerTextDraw(playerid, 208.484237, 138.600021, "hud:radar_cash");
    PlayerTextDrawTextSize(playerid, BancoCapa[playerid][3], 9.000000, 10.000000);
    PlayerTextDrawAlignment(playerid, BancoCapa[playerid][3], 1);
    PlayerTextDrawColor(playerid, BancoCapa[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, BancoCapa[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoCapa[playerid][3], 255);
    PlayerTextDrawFont(playerid, BancoCapa[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, BancoCapa[playerid][3], 0);

    BancoCapa[playerid][4] = CreatePlayerTextDraw(playerid, 261.821990, 137.666641, ConverterTexto(DinheiroSeparar(Jogador[playerid][DinheiroBanco])));
    PlayerTextDrawLetterSize(playerid, BancoCapa[playerid][4], 0.223123, 1.156664);
    PlayerTextDrawTextSize(playerid, BancoCapa[playerid][4], 464.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoCapa[playerid][4], 3);
    PlayerTextDrawColor(playerid, BancoCapa[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, BancoCapa[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoCapa[playerid][4], 61);
    PlayerTextDrawFont(playerid, BancoCapa[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, BancoCapa[playerid][4], 1);

    BancoCapa[playerid][5] = CreatePlayerTextDraw(playerid, 319.375000, 115.666694, "R");
    PlayerTextDrawLetterSize(playerid, BancoCapa[playerid][5], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BancoCapa[playerid][5], 1);
    PlayerTextDrawColor(playerid, BancoCapa[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, BancoCapa[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoCapa[playerid][5], 255);
    PlayerTextDrawFont(playerid, BancoCapa[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, BancoCapa[playerid][5], 1);

    BancoCapa[playerid][6] = CreatePlayerTextDraw(playerid, 323.125000, 120.583335, "C");
    PlayerTextDrawLetterSize(playerid, BancoCapa[playerid][6], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, BancoCapa[playerid][6], 1);
    PlayerTextDrawColor(playerid, BancoCapa[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, BancoCapa[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoCapa[playerid][6], 255);
    PlayerTextDrawFont(playerid, BancoCapa[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, BancoCapa[playerid][6], 1);

    BancoCapa[playerid][7] = CreatePlayerTextDraw(playerid, 420.000000, 120.216629, "ld_beat:cross");
    PlayerTextDrawTextSize(playerid, BancoCapa[playerid][7], 10.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, BancoCapa[playerid][7], 1);
    PlayerTextDrawColor(playerid, BancoCapa[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, BancoCapa[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoCapa[playerid][7], 255);
    PlayerTextDrawFont(playerid, BancoCapa[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, BancoCapa[playerid][7], 0);
    PlayerTextDrawSetSelectable(playerid, BancoCapa[playerid][7], true);

    BancoCapa[playerid][8] = CreatePlayerTextDraw(playerid, 208.125000, 176.000045, "box");
    PlayerTextDrawLetterSize(playerid, BancoCapa[playerid][8], 0.000000, 12.732500);
    PlayerTextDrawTextSize(playerid, BancoCapa[playerid][8], 429.800018, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoCapa[playerid][8], 1);
    PlayerTextDrawColor(playerid, BancoCapa[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, BancoCapa[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, BancoCapa[playerid][8], 48);
    PlayerTextDrawSetShadow(playerid, BancoCapa[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoCapa[playerid][8], 255);
    PlayerTextDrawFont(playerid, BancoCapa[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, BancoCapa[playerid][8], 1);

    for(new i=0; i < 9; i++){
        PlayerTextDrawShow(playerid, BancoCapa[playerid][i]);
    }

    SelectTextDrawEx(playerid, 0xFFA500FF, "OcultarBancoCapa", true);
    TogglePlayerControllable(playerid, 0);
    Jogador[playerid][AntiEsc] = true;

    return 1;
}

function OcultarBancoCapa(playerid)
{
    CancelSelectTextDrawEx(playerid, "OcultarBancoCapa");
    Jogador[playerid][AntiEsc] = false;
    for(new i=0; i < 9; i++){
        PlayerTextDrawDestroy(playerid, BancoCapa[playerid][i]);
        BancoCapa[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid != BancoCapa[playerid][7]) return 1;
    OcultarBanco(playerid);
    return 0;
}

function OcultarBanco(playerid)
{
    new FecharG[30],
        AbrirG[30];

    GetPVarString(playerid, "BankFechar", FecharG, 30); 
    GetPVarString(playerid, "BankMostrar", AbrirG, 30);

    CallRemoteFunction(FecharG, "d", playerid);
    if(!strcmp(AbrirG, "*")) OcultarBancoCapa(playerid);
    else CallRemoteFunction(AbrirG, "d", playerid);
    return 1;
}