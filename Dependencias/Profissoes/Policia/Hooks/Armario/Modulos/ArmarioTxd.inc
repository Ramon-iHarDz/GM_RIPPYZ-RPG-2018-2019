#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 12; i++){
        VestiarioPM[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    for(new i=0; i < 3; i++){
        PreArmario[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarPreArmario(playerid)
{
    PreArmario[playerid][0] = CreatePlayerTextDraw(playerid, 220.208129, 108.916664, "box");
    PlayerTextDrawLetterSize(playerid, PreArmario[playerid][0], 0.000000, 19.417272);
    PlayerTextDrawTextSize(playerid, PreArmario[playerid][0], 399.899200, 0.000000);
    PlayerTextDrawAlignment(playerid, PreArmario[playerid][0], 1);
    PlayerTextDrawColor(playerid, PreArmario[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, PreArmario[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, PreArmario[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, PreArmario[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PreArmario[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PreArmario[playerid][0], 255);
    PlayerTextDrawFont(playerid, PreArmario[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, PreArmario[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, PreArmario[playerid][0], 0);

    PreArmario[playerid][1] = CreatePlayerTextDraw(playerid, 265.000000, 155.000000, "");
    PlayerTextDrawLetterSize(playerid, PreArmario[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PreArmario[playerid][1], 90.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, PreArmario[playerid][1], 1);
    PlayerTextDrawColor(playerid, PreArmario[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, PreArmario[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PreArmario[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PreArmario[playerid][1], 0);
    PlayerTextDrawFont(playerid, PreArmario[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, PreArmario[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, PreArmario[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, PreArmario[playerid][1], 18646);
    PlayerTextDrawSetPreviewRot(playerid, PreArmario[playerid][1], 0.000000, 0.000000, 0.000000, 1.000000);

    PreArmario[playerid][2] = CreatePlayerTextDraw(playerid, 220.208129, 108.916664, "box");
    PlayerTextDrawLetterSize(playerid, PreArmario[playerid][2], 0.000000, 0.948077);
    PlayerTextDrawTextSize(playerid, PreArmario[playerid][2], 400.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PreArmario[playerid][2], 1);
    PlayerTextDrawColor(playerid, PreArmario[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, PreArmario[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, PreArmario[playerid][2], 4144959);
    PlayerTextDrawSetShadow(playerid, PreArmario[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PreArmario[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PreArmario[playerid][2], 255);
    PlayerTextDrawFont(playerid, PreArmario[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, PreArmario[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, PreArmario[playerid][2], 0);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, PreArmario[playerid][i]);
    }
    SetPVarInt(playerid, "PreArmario", 1);
    TogglePlayerControllable(playerid, 0);
    SetTimerEx("AnimacaoPreArmario", 200, false, "df", playerid, 19.4461);
    return 1;
}

stock OcultarPreAnimacao(playerid)
{
    SetPVarInt(playerid, "PreArmario", 0);
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, PreArmario[playerid][i]);
        PreArmario[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function AnimacaoPreArmario(playerid, Float:Valor)
{
    if(!IsPlayerConnected(playerid)) return 1;
    if(Valor <= 0.938078)
    {
        OcultarPreAnimacao(playerid);
        MostrarArmarioPolicia(playerid);
        return 1;
    }
    Valor -= 2.3;
    if(Valor <= 0.938078) Valor = 0.938078;
    PlayerTextDrawLetterSize(playerid, PreArmario[playerid][2], 0.000000, Valor);
    PlayerTextDrawShow(playerid, PreArmario[playerid][2]);
    SetTimerEx("AnimacaoPreArmario", 200, false, "df", playerid, Valor);
    return 1;
}


stock MostrarArmarioPolicia(playerid) 
{
    VestiarioPM[playerid][0] = CreatePlayerTextDraw(playerid, 220.208129, 108.916664, "box");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][0], 0.000000, 19.417272);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][0], 399.899200, 0.000000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][0], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][0], 255);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][0], 0);

    VestiarioPM[playerid][1] = CreatePlayerTextDraw(playerid, 241.875000, 138.666656, "");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][1], 142.000000, 127.000000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][1], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][1], 0);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, VestiarioPM[playerid][1], 280);
    PlayerTextDrawSetPreviewRot(playerid, VestiarioPM[playerid][1], 0.000000, 0.000000, 0.000000, 1.000000);

    VestiarioPM[playerid][2] = CreatePlayerTextDraw(playerid, 220.208129, 108.916664, "box");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][2], 0.000000, 0.948077);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][2], 400.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][2], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][2], -1061109725);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][2], 255);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][2], 0);

    VestiarioPM[playerid][3] = CreatePlayerTextDraw(playerid, 359.624572, 188.833374, ">");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][3], 0.537744, 2.953332);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][3], 372.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][3], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][3], 44);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, VestiarioPM[playerid][3], true);

    VestiarioPM[playerid][4] = CreatePlayerTextDraw(playerid, 250.725311, 188.833374, "<");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][4], 0.537744, 2.953332);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][4], 264.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][4], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][4], 44);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, VestiarioPM[playerid][4], true);

    VestiarioPM[playerid][5] = CreatePlayerTextDraw(playerid, 222.101470, 107.600006, "Armario_-_Policial");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][5], 0.217276, 1.127498);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][5], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][5], 1);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][5], 90);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][5], 1);

    VestiarioPM[playerid][6] = CreatePlayerTextDraw(playerid, 389.794464, 108.999961, "box");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][6], 0.000000, 0.957540);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][6], 399.929321, 0.000000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][6], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][6], -16777087);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][6], 255);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][6], 0);

    VestiarioPM[playerid][7] = CreatePlayerTextDraw(playerid, 391.588806, 105.316658, "x");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][7], 0.295624, 1.419165);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][7], 400.400024, 12.0000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][7], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][7], 1);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][7], 55);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, VestiarioPM[playerid][7], true);

    VestiarioPM[playerid][8] = CreatePlayerTextDraw(playerid, 228.675674, 247.166748, "Confirmar");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][8], 0.204625, 1.168331);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][8], 264.300140, 12.0000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][8], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][8], 1);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][8], 100);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, VestiarioPM[playerid][8], true);

    VestiarioPM[playerid][9] = CreatePlayerTextDraw(playerid, 229.412734, 265.466461, "Remover");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][9], 0.229926, 1.086665);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][9], 264.700164, 12.0000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][9], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][9], 1);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][9], 100);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, VestiarioPM[playerid][9], true);

    VestiarioPM[playerid][10] = CreatePlayerTextDraw(playerid, 225.155151, 248.333343, "box");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][10], 0.000000, 1.038476);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][10], 223.899978, 0.000000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][10], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][10], -5963521);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][10], 255);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][10], 0);

    VestiarioPM[playerid][11] = CreatePlayerTextDraw(playerid, 225.155151, 265.733032, "box");
    PlayerTextDrawLetterSize(playerid, VestiarioPM[playerid][11], 0.000000, 1.038476);
    PlayerTextDrawTextSize(playerid, VestiarioPM[playerid][11], 223.899978, 0.000000);
    PlayerTextDrawAlignment(playerid, VestiarioPM[playerid][11], 1);
    PlayerTextDrawColor(playerid, VestiarioPM[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, VestiarioPM[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, VestiarioPM[playerid][11], -2139062197);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, VestiarioPM[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, VestiarioPM[playerid][11], 255);
    PlayerTextDrawFont(playerid, VestiarioPM[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, VestiarioPM[playerid][11], 1);
    PlayerTextDrawSetShadow(playerid, VestiarioPM[playerid][11], 0);

    for(new i=0; i < 12; i++){
        PlayerTextDrawShow(playerid, VestiarioPM[playerid][i]);
    }
    SelectTextDrawEx(playerid, 0xFFA500FF, "OcultarArmarioPolicia", true);
    return 1;
}

stock OcultarArmarioPolicia(playerid)
{
    CancelSelectTextDrawEx(playerid, "OcultarArmarioPolicia");
    SetPVarInt(playerid, "EqupandoPM", 0);
    for(new i=0; i < 12; i++){
        PlayerTextDrawDestroy(playerid, VestiarioPM[playerid][i]);
        VestiarioPM[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}