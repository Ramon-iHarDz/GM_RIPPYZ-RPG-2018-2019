#include <YSI_Coding\y_hooks>

new PlayerText:BancoMain[MAX_PLAYERS][12];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 12; i++){
        BancoMain[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarBancoMain(playerid)
{
    BancoMain[playerid][0] = CreatePlayerTextDraw(playerid, 204.729141, 96.416702, "box");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][0], 0.000000, 20.588577);
    PlayerTextDrawTextSize(playerid, BancoMain[playerid][0], 438.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][0], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, BancoMain[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, BancoMain[playerid][0], 25);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][0], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][0], 0);

    BancoMain[playerid][1] = CreatePlayerTextDraw(playerid, 206.566177, 98.866630, "box");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][1], 0.000000, 20.022537);
    PlayerTextDrawTextSize(playerid, BancoMain[playerid][1], 436.550018, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][1], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, BancoMain[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, BancoMain[playerid][1], 471604479);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][1], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][1], 0);

    BancoMain[playerid][2] = CreatePlayerTextDraw(playerid, 209.956970, 101.283309, "Saldo_Bancario:");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][2], 0.209307, 1.110000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][2], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][2], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][2], 0);

    new DinheiroSeparadoCoisado[128];
    format(DinheiroSeparadoCoisado, sizeof(DinheiroSeparadoCoisado), "R$%s", DinheiroSeparar(Jogador[playerid][DinheiroBanco]));
    BancoMain[playerid][3] = CreatePlayerTextDraw(playerid, 265.710968, 101.866645, DinheiroSeparadoCoisado);
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][3], 0.165270, 1.028334);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][3], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][3], 8388863);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][3], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][3], 0);

    BancoMain[playerid][4] = CreatePlayerTextDraw(playerid, -99.700271, 288.000152, "Rippzy_Banco");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][4], 0.323161, 1.413333);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][4], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][4], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][4], 1);

    BancoMain[playerid][5] = CreatePlayerTextDraw(playerid, 272.627502, 152.900100, "box");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][5], 0.000000, 2.035140);
    PlayerTextDrawTextSize(playerid, BancoMain[playerid][5], 374.899993, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][5], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, BancoMain[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, BancoMain[playerid][5], 70);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][5], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][5], 0);

    BancoMain[playerid][6] = CreatePlayerTextDraw(playerid, 272.627502, 189.799850, "box");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][6], 0.000000, 2.035140);
    PlayerTextDrawTextSize(playerid, BancoMain[playerid][6], 374.899993, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][6], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, BancoMain[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, BancoMain[playerid][6], 70);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][6], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][6], 0);

    BancoMain[playerid][7] = CreatePlayerTextDraw(playerid, 273.096038, 227.599594, "box");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][7], 0.000000, 2.035140);
    PlayerTextDrawTextSize(playerid, BancoMain[playerid][7], 375.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][7], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, BancoMain[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, BancoMain[playerid][7], 70);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][7], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][7], 0);

    BancoMain[playerid][8] = CreatePlayerTextDraw(playerid, 299.187194, 155.266693, "Depositar");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][8], 0.303014, 1.459998);
    PlayerTextDrawTextSize(playerid, BancoMain[playerid][8], 350.799926, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][8], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, BancoMain[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, BancoMain[playerid][8], 4);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][8], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][8], 3);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, BancoMain[playerid][8], true);

    BancoMain[playerid][9] = CreatePlayerTextDraw(playerid, 308.081390, 191.983200, "Saque");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][9], 0.327847, 1.395831);
    PlayerTextDrawTextSize(playerid, BancoMain[playerid][9], 348.199951, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][9], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, BancoMain[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, BancoMain[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][9], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][9], 3);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][9], 0);
    PlayerTextDrawSetSelectable(playerid, BancoMain[playerid][9], true);

    BancoMain[playerid][10] = CreatePlayerTextDraw(playerid, 293.255249, 230.199859, "Transferir");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][10], 0.334405, 1.512498);
    PlayerTextDrawTextSize(playerid, BancoMain[playerid][10], 360.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][10], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, BancoMain[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, BancoMain[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][10], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][10], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][10], 3);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, BancoMain[playerid][10], true);

    BancoMain[playerid][11] = CreatePlayerTextDraw(playerid, 425.939910, 98.833290, "ld_beat:cross");
    PlayerTextDrawLetterSize(playerid, BancoMain[playerid][11], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, BancoMain[playerid][11], 10.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, BancoMain[playerid][11], 1);
    PlayerTextDrawColor(playerid, BancoMain[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, BancoMain[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoMain[playerid][11], 255);
    PlayerTextDrawFont(playerid, BancoMain[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, BancoMain[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, BancoMain[playerid][11], 0);
    PlayerTextDrawSetSelectable(playerid, BancoMain[playerid][11], true);

    for(new i=0; i < 12; i++){
        PlayerTextDrawShow(playerid, BancoMain[playerid][i]);
    }

    SelectTextDraw(playerid, 0xFFA500FF);
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")+1);
    TogglePlayerControllable(playerid, 0);
    Jogador[playerid][AntiEsc] = true;
    return 1;
}

function OcultarBancoMain(playerid)
{
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")-1);
    if(GetPVarInt(playerid, "EscEvento") == 0){
        CancelSelectTextDraw(playerid);
        TogglePlayerControllable(playerid, 1);
    }
    Jogador[playerid][AntiEsc] = false;
    for(new i=0; i < 12; i++){
        PlayerTextDrawDestroy(playerid, BancoMain[playerid][i]);
        BancoMain[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}