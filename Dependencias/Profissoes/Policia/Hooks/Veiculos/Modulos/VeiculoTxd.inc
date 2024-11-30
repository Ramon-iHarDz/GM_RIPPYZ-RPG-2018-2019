#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 15; i++){
        PoliciaVeiculoTXD[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarPoliciaVeiculo(playerid)
{
    SelectTextDraw(playerid, 0xFFA500FF);
    PoliciaVeiculoTXD[playerid][0] = CreatePlayerTextDraw(playerid, 192.547576, 109.199974, "box");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][0], 0.000000, 25.988904);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][0], 465.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][0], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][0], -1061109505);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][0], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][0], 0);

    PoliciaVeiculoTXD[playerid][1] = CreatePlayerTextDraw(playerid, 194.421661, 111.250007, "box");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][1], 0.000000, 1.754027);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][1], 463.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][1], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][1], 1182971135);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][1], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][1], 0);

    PoliciaVeiculoTXD[playerid][2] = CreatePlayerTextDraw(playerid, 194.421676, 134.000000, "box");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][2], 0.000000, 23.007522);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][2], 463.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][2], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][2], 471604479);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][2], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][2], 0);

    PoliciaVeiculoTXD[playerid][3] = CreatePlayerTextDraw(playerid, 186.756973, 106.399986, "");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][3], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][3], 33.000000, 24.000000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][3], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][3], 0);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][3], 0);
    PlayerTextDrawSetPreviewModel(playerid, PoliciaVeiculoTXD[playerid][3], 18646);
    PlayerTextDrawSetPreviewRot(playerid, PoliciaVeiculoTXD[playerid][3], 0.000000, 0.000000, 0.000000, 1.000000);

    PoliciaVeiculoTXD[playerid][4] = CreatePlayerTextDraw(playerid, 214.568084, 112.416656, "~>~");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][4], 0.343777, 1.267500);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][4], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][4], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][4], 0);

    PoliciaVeiculoTXD[playerid][5] = CreatePlayerTextDraw(playerid, 226.818099, 112.416648, "Garagem");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][5], 0.293644, 1.349166);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][5], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][5], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][5], 0);

    PoliciaVeiculoTXD[playerid][6] = CreatePlayerTextDraw(playerid, 448.920227, 111.616661, "box");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][6], 0.000000, 1.660323);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][6], 462.450897, 0.000000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][6], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][6], -16777086);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][6], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][6], 0);

    PoliciaVeiculoTXD[playerid][7] = CreatePlayerTextDraw(playerid, 452.577056, 110.666671, "X");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][7], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][7], 462.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][7], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][7], -1);
    //PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][7], 1);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][7], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][7], 3);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, PoliciaVeiculoTXD[playerid][7], true);

    PoliciaVeiculoTXD[playerid][8] = CreatePlayerTextDraw(playerid, 238.931106, 178.333358, "box");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][8], 0.000000, 11.124449);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][8], 420.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][8], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][8], -1061109505);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][8], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][8], 0);

    PoliciaVeiculoTXD[playerid][9] = CreatePlayerTextDraw(playerid, 264.999816, 156.749954, "");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][9], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][9], 115.000000, 128.000000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][9], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][9], 0);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][9], 5);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][9], 0);
    PlayerTextDrawSetPreviewModel(playerid, PoliciaVeiculoTXD[playerid][9], 596);
    PlayerTextDrawSetPreviewRot(playerid, PoliciaVeiculoTXD[playerid][9], -30.000000, 0.000000, 50.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, PoliciaVeiculoTXD[playerid][9], 116, 116);

    PoliciaVeiculoTXD[playerid][10] = CreatePlayerTextDraw(playerid, 349.970581, 284.500030, "~>~");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][10], 0.428579, 1.967499);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][10], 363.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][10], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][10], -1);
    //PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][10], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, PoliciaVeiculoTXD[playerid][10], true);

    PoliciaVeiculoTXD[playerid][11] = CreatePlayerTextDraw(playerid, 296.090118, 284.500030, "~<~");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][11], 0.428579, 1.967499);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][11], 311.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][11], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][11], -1);
    //PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][11], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][11], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][11], 0);
    PlayerTextDrawSetSelectable(playerid, PoliciaVeiculoTXD[playerid][11], true);

    PoliciaVeiculoTXD[playerid][12] = CreatePlayerTextDraw(playerid, 200.043914, 308.416625, "Pegar_Veiculo");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][12], 0.248667, 1.010830);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][12], 254.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][12], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][12], 16711798);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][12], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][12], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][12], 0);
    PlayerTextDrawSetSelectable(playerid, PoliciaVeiculoTXD[playerid][12], true);

    PoliciaVeiculoTXD[playerid][13] = CreatePlayerTextDraw(playerid, 200.044036, 324.166625, "Devolver_Veiculo");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][13], 0.248667, 1.010830);
    PlayerTextDrawTextSize(playerid, PoliciaVeiculoTXD[playerid][13], 267.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][13], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][13], -1);
    PlayerTextDrawUseBox(playerid, PoliciaVeiculoTXD[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, PoliciaVeiculoTXD[playerid][13], -16777092);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][13], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][13], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][13], 0);
    PlayerTextDrawSetSelectable(playerid, PoliciaVeiculoTXD[playerid][13], true);

    PoliciaVeiculoTXD[playerid][14] = CreatePlayerTextDraw(playerid, 235.625000, 164.333282, "Veiculo:_N/A");
    PlayerTextDrawLetterSize(playerid, PoliciaVeiculoTXD[playerid][14], 0.237499, 0.952499);
    PlayerTextDrawAlignment(playerid, PoliciaVeiculoTXD[playerid][14], 1);
    PlayerTextDrawColor(playerid, PoliciaVeiculoTXD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][14], 1);
    PlayerTextDrawSetOutline(playerid, PoliciaVeiculoTXD[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaVeiculoTXD[playerid][14], 255);
    PlayerTextDrawFont(playerid, PoliciaVeiculoTXD[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaVeiculoTXD[playerid][14], 1);
    PlayerTextDrawSetShadow(playerid, PoliciaVeiculoTXD[playerid][14], 1);

    for(new i=0; i < 15; i++){
        PlayerTextDrawShow(playerid, PoliciaVeiculoTXD[playerid][i]);
    }

    TogglePlayerControllable(playerid, 0);
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")+1);
    Jogador[playerid][AntiEsc] = true;
    return 1;
}

function OcultarPoliciaVeiculo(playerid)
{
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")-1);
    if(GetPVarInt(playerid, "EscEvento") == 0){
        CancelSelectTextDraw(playerid);
        TogglePlayerControllable(playerid, 1);
    }
    for(new i=0; i < 15; i++){
        PlayerTextDrawDestroy(playerid, PoliciaVeiculoTXD[playerid][i]);
        PoliciaVeiculoTXD[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    Jogador[playerid][AntiEsc] = false;
    return 1;
}