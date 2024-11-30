#include <YSI_Coding\y_hooks>

new PlayerText:SaqueBanco[MAX_PLAYERS][10];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 10; i++){
        SaqueBanco[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarSaque(playerid)
{
    SaqueBanco[playerid][0] = CreatePlayerTextDraw(playerid, 204.729141, 96.416702, "box");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][0], 0.000000, 20.588577);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][0], 438.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][0], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, SaqueBanco[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, SaqueBanco[playerid][0], 25);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][0], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][0], 0);

    SaqueBanco[playerid][1] = CreatePlayerTextDraw(playerid, 206.566177, 98.866630, "box");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][1], 0.000000, 20.022537);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][1], 436.550018, 0.000000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][1], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, SaqueBanco[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, SaqueBanco[playerid][1], 471604479);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][1], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][1], 0);

    SaqueBanco[playerid][2] = CreatePlayerTextDraw(playerid, 209.956970, 101.283309, "Saldo_Bancario:");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][2], 0.209307, 1.110000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][2], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][2], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][2], 0);

    new DinheiroSeparadoCoisado[128];
    format(DinheiroSeparadoCoisado, sizeof(DinheiroSeparadoCoisado), "R$%s", DinheiroSeparar(Jogador[playerid][DinheiroBanco]));
    SaqueBanco[playerid][3] = CreatePlayerTextDraw(playerid, 265.710968, 101.866645, DinheiroSeparadoCoisado);
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][3], 0.165270, 1.028334);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][3], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][3], 8388863);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][3], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][3], 0);

    SaqueBanco[playerid][4] = CreatePlayerTextDraw(playerid, 289.172424, 284.500030, "Rippzy_Banco");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][4], 0.323161, 1.413333);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][4], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][4], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][4], 1);

    SaqueBanco[playerid][5] = CreatePlayerTextDraw(playerid, 264.857269, 175.416656, "box");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][5], 0.000000, 1.894582);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][5], 382.299835, 0.000000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][5], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, SaqueBanco[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, SaqueBanco[playerid][5], 133);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][5], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][5], 0);

    SaqueBanco[playerid][6] = CreatePlayerTextDraw(playerid, 323.596496, 155.083282, "Saque");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][6], 0.279120, 1.343331);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][6], 2);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][6], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][6], 0);

    SaqueBanco[playerid][7] = CreatePlayerTextDraw(playerid, 268.827148, 179.233428, "Clique_aqui_para_colocar_o_valor");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][7], 0.197597, 1.051663);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][7], 382.099822, 12.0000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][7], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][7], -1);
    // PlayerTextDrawUseBox(playerid, SaqueBanco[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, SaqueBanco[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][7], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][7], 0);
    PlayerTextDrawSetSelectable(playerid, SaqueBanco[playerid][7], true);

    SaqueBanco[playerid][8] = CreatePlayerTextDraw(playerid, 306.746490, 198.166641, "");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][8], 33.000000, 43.000000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][8], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][8], 0);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, SaqueBanco[playerid][8], true);
    PlayerTextDrawSetPreviewModel(playerid, SaqueBanco[playerid][8], 19134);
    PlayerTextDrawSetPreviewRot(playerid, SaqueBanco[playerid][8], 0.000000, 90.000000, 90.000000, 1.000000);

    SaqueBanco[playerid][9] = CreatePlayerTextDraw(playerid, 424.765869, 99.583312, "ld_beat:cross");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][9], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][9], 10.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][9], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, SaqueBanco[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][9], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][9], 0);
    PlayerTextDrawSetSelectable(playerid, SaqueBanco[playerid][9], true);

    for(new i=0; i < 10; i++){
        PlayerTextDrawShow(playerid, SaqueBanco[playerid][i]);
    }
    SelectTextDraw(playerid, 0xFFA500FF);
    TogglePlayerControllable(playerid, 0);
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")+1);
    Jogador[playerid][AntiEsc] = true;
    return 1;
}

function OcultarSaque(playerid)
{
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")-1);
    if(GetPVarInt(playerid, "EscEvento") == 0){
        CancelSelectTextDraw(playerid);
        TogglePlayerControllable(playerid, 1);
    }
    Jogador[playerid][AntiEsc] = false;
    for(new i=0; i < 10; i++){
        PlayerTextDrawDestroy(playerid, SaqueBanco[playerid][i]);
        SaqueBanco[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    DeletePVar(playerid, "ValorSaque");
    return 1;
}