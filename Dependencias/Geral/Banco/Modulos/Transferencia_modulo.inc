#include <YSI_Coding\y_hooks>
new PlayerText:BancoTransferencia[MAX_PLAYERS][13];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 13; i++){
        BancoTransferencia[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarTransferencia(playerid)
{
    BancoTransferencia[playerid][0] = CreatePlayerTextDraw(playerid, 204.729141, 96.416702, "box");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][0], 0.000000, 20.588577);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][0], 438.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][0], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][0], 25);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][0], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][0], 0);

    BancoTransferencia[playerid][1] = CreatePlayerTextDraw(playerid, 206.566177, 98.866630, "box");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][1], 0.000000, 20.022537);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][1], 436.550018, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][1], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][1], 471604479);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][1], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][1], 0);

    BancoTransferencia[playerid][2] = CreatePlayerTextDraw(playerid, 209.956970, 101.283309, "Saldo_Bancario:");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][2], 0.209307, 1.110000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][2], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][2], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][2], 0);

    new DinheiroSeparadoCoisado[128];
    format(DinheiroSeparadoCoisado, sizeof(DinheiroSeparadoCoisado), "R$%s", DinheiroSeparar(Jogador[playerid][DinheiroBanco]));
    BancoTransferencia[playerid][3] = CreatePlayerTextDraw(playerid, 265.710968, 101.866645, DinheiroSeparadoCoisado);
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][3], 0.165270, 1.028334);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][3], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][3], 8388863);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][3], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][3], 0);

    BancoTransferencia[playerid][4] = CreatePlayerTextDraw(playerid, 289.172424, 284.500030, "Rippzy_Banco");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][4], 0.323161, 1.413333);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][4], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][4], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][4], 1);

    BancoTransferencia[playerid][5] = CreatePlayerTextDraw(playerid, 265.394104, 206.883514, "box");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][5], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][5], 381.200012, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][5], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][5], 121);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][5], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][5], 0);

    BancoTransferencia[playerid][6] = CreatePlayerTextDraw(playerid, 265.394104, 161.283340, "box");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][6], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][6], 381.200012, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][6], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][6], 121);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][6], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][6], 0);

    BancoTransferencia[playerid][7] = CreatePlayerTextDraw(playerid, 306.398132, 144.500000, "Usuario");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][7], 0.193850, 1.174165);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][7], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][7], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][7], 0);

    BancoTransferencia[playerid][8] = CreatePlayerTextDraw(playerid, 311.085327, 191.333602, "Valor");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][8], 0.194318, 1.179999);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][8], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][8], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][8], 0);

    BancoTransferencia[playerid][9] = CreatePlayerTextDraw(playerid, 273.301605, 164.633361, "Clique_aqui_para_colocar");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][9], 0.243981, 0.987498);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][9], 378.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][9], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][9], -1);
    // PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][9], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][9], 0);
    PlayerTextDrawSetSelectable(playerid, BancoTransferencia[playerid][9], true);

    BancoTransferencia[playerid][10] = CreatePlayerTextDraw(playerid, 270.655761, 209.450195, "Clique_aqui_para_adicionar_o_valor");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][10], 0.181669, 1.121665);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][10], 378.899993, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][10], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][10], -1);
    // PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][10], -301989888);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][10], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][10], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, BancoTransferencia[playerid][10], true);

    BancoTransferencia[playerid][11] = CreatePlayerTextDraw(playerid, 307.198547, 230.833328, "");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][11], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][11], 33.000000, 41.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][11], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][11], 0);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][11], 5);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][11], 0);
    PlayerTextDrawSetSelectable(playerid, BancoTransferencia[playerid][11], true);
    PlayerTextDrawSetPreviewModel(playerid, BancoTransferencia[playerid][11], 19134);
    PlayerTextDrawSetPreviewRot(playerid, BancoTransferencia[playerid][11], 0.000000, 90.000000, 90.000000, 1.000000);

    BancoTransferencia[playerid][12] = CreatePlayerTextDraw(playerid, 424.765869, 99.583312, "ld_beat:cross");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][12], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][12], 10.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][12], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, BancoTransferencia[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][12], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][12], 0);
    PlayerTextDrawSetSelectable(playerid, BancoTransferencia[playerid][12], true);

    for(new i=0; i < 13; i++){
        PlayerTextDrawShow(playerid, BancoTransferencia[playerid][i]);
    }
    SelectTextDraw(playerid, 0xFFA500FF);
    TogglePlayerControllable(playerid, 0);
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")+1);
    Jogador[playerid][AntiEsc] = true;
    return 1;
}

function OcultarTransferencia(playerid)
{
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")-1);
    if(GetPVarInt(playerid, "EscEvento") == 0){
        CancelSelectTextDraw(playerid);
        TogglePlayerControllable(playerid, 1);
    }
    Jogador[playerid][AntiEsc] = false;
    for(new i=0; i < 13; i++){
        PlayerTextDrawDestroy(playerid, BancoTransferencia[playerid][i]);
        BancoTransferencia[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    DeletePVar(playerid, "UsuarioBancoTrans");
    DeletePVar(playerid, "ValorTransferencia");
    return 1;
}