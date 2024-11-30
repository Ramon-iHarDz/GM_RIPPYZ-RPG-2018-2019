#include <YSI_Coding\y_hooks>

new PlayerText:RegistroText[MAX_PLAYERS][21],
    PlayerText:CodigoLogin[MAX_PLAYERS][9] 
;

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 21; i++){
        RegistroText[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    for(new i=0; i < 9; i++){
        CodigoLogin[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarRegistro(playerid)
{
    SelectTextDraw(playerid, 0xFFA500FF);
    RegistroText[playerid][0] = CreatePlayerTextDraw(playerid, 248.770019, 119.999977, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][0], 0.000000, 18.840795);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][0], 395.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][0], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][0], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][0], 0);

    RegistroText[playerid][1] = CreatePlayerTextDraw(playerid, 248.644134, 119.916664, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][1], 0.000000, 1.341999);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][1], 394.979614, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][1], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][1], -2139062262);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][1], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][1], 0);

    RegistroText[playerid][2] = CreatePlayerTextDraw(playerid, 258.609008, 150.333389, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][2], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][2], 385.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][2], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][2], -2139062248);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][2], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][2], 0);

    RegistroText[playerid][3] = CreatePlayerTextDraw(playerid, 258.609008, 150.333389, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][3], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][3], 269.339538, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][3], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][3], 471604370);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][3], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][3], 0);

    RegistroText[playerid][4] = CreatePlayerTextDraw(playerid, 258.609008, 181.633407, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][4], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][4], 385.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][4], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][4], -2139062248);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][4], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][4], 0);

    RegistroText[playerid][5] = CreatePlayerTextDraw(playerid, 258.609008, 181.833175, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][5], 0.000000, 1.183246);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][5], 269.339538, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][5], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][5], 471604370);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][5], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][5], 0);

    RegistroText[playerid][6] = CreatePlayerTextDraw(playerid, 302.590972, 121.183372, "Rippzy_City");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][6], 0.221959, 1.098330);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][6], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][6], 1);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][6], 83);
    PlayerTextDrawFont(playerid, RegistroText[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][6], 1);

    RegistroText[playerid][7] = CreatePlayerTextDraw(playerid, 250.944320, 148.316680, "");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][7], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][7], 24.000000, 15.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][7], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][7], 0);
    PlayerTextDrawFont(playerid, RegistroText[playerid][7], 5);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][7], 0);
    PlayerTextDrawSetPreviewModel(playerid, RegistroText[playerid][7], 1239);
    PlayerTextDrawSetPreviewRot(playerid, RegistroText[playerid][7], 0.000000, 0.000000, 180.000000, 1.000000);

    RegistroText[playerid][8] = CreatePlayerTextDraw(playerid, 251.844314, 178.016479, "");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][8], 24.000000, 18.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][8], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][8], 0);
    PlayerTextDrawFont(playerid, RegistroText[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][8], 0);
    PlayerTextDrawSetPreviewModel(playerid, RegistroText[playerid][8], 19804); 
    PlayerTextDrawSetPreviewRot(playerid, RegistroText[playerid][8], 0.000000, 0.000000, 0.000000, 1.000000);

    RegistroText[playerid][9] = CreatePlayerTextDraw(playerid, 275.944274, 149.749969, PegarNick(playerid));
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][9], 0.264126, 1.250000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][9], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][9], 100);
    PlayerTextDrawFont(playerid, RegistroText[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][9], 0);

    RegistroText[playerid][10] = CreatePlayerTextDraw(playerid, 275.944274, 181.249755, "Coloque_sua_senha_aqui");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][10], 0.231800, 1.156666);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][10], 368.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][10], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][10], -1);
    //PlayerTextDrawUseBox(playerid, RegistroText[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][10], 100);
    PlayerTextDrawFont(playerid, RegistroText[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, RegistroText[playerid][10], true);

    RegistroText[playerid][11] = CreatePlayerTextDraw(playerid, 211.588577, 78.583358, "");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][11], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][11], 90.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][11], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][11], 0);
    PlayerTextDrawFont(playerid, RegistroText[playerid][11], 5);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][11], 0);
    PlayerTextDrawSetPreviewModel(playerid, RegistroText[playerid][11], NatalGorroID); 
    PlayerTextDrawSetPreviewRot(playerid, RegistroText[playerid][11], 0.000000, 0.000000, 180.000000, 1.000000);

    RegistroText[playerid][12] = CreatePlayerTextDraw(playerid, 309.078216, 259.900238, "");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][12], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][12], 23.000000, 27.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][12], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][12], 0);
    PlayerTextDrawFont(playerid, RegistroText[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][12], 0);
    PlayerTextDrawSetSelectable(playerid, RegistroText[playerid][12], true);
    PlayerTextDrawSetPreviewModel(playerid, RegistroText[playerid][12], 19134);
    PlayerTextDrawSetPreviewRot(playerid, RegistroText[playerid][12], 0.000000, -90.000000, 90.000000, 1.000000);

    RegistroText[playerid][13] = CreatePlayerTextDraw(playerid, 258.609008, 211.233520, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][13], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][13], 385.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][13], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][13], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][13], -2139062248);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][13], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][13], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][13], 0);

    RegistroText[playerid][14] = CreatePlayerTextDraw(playerid, 258.609008, 211.433288, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][14], 0.000000, 1.183246);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][14], 269.339538, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][14], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][14], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][14], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][14], 471604370);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][14], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][14], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][14], 0);

    RegistroText[playerid][15] = CreatePlayerTextDraw(playerid, 258.609008, 240.833633, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][15], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][15], 385.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][15], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][15], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][15], -2139062248);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][15], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][15], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][15], 0);

    RegistroText[playerid][16] = CreatePlayerTextDraw(playerid, 258.609008, 240.533370, "box");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][16], 0.000000, 1.224247);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][16], 269.339538, 0.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][16], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][16], -1);
    PlayerTextDrawUseBox(playerid, RegistroText[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][16], 471604370);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][16], 255);
    PlayerTextDrawFont(playerid, RegistroText[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][16], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][16], 0);

    RegistroText[playerid][17] = CreatePlayerTextDraw(playerid, 252.701721, 209.499954, "");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][17], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][17], 22.000000, 15.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][17], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][17], 0);
    PlayerTextDrawFont(playerid, RegistroText[playerid][17], 5);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][17], 0);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][17], 0);
    PlayerTextDrawSetPreviewModel(playerid, RegistroText[playerid][17], 954);
    PlayerTextDrawSetPreviewRot(playerid, RegistroText[playerid][17], 0.000000, 0.000000, 0.000000, 1.000000);

    RegistroText[playerid][18] = CreatePlayerTextDraw(playerid, 255.844314, 237.216705, "");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][18], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][18], 16.000000, 18.000000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][18], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][18], 0);
    PlayerTextDrawFont(playerid, RegistroText[playerid][18], 5);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][18], 0);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][18], 0);
    PlayerTextDrawSetPreviewModel(playerid, RegistroText[playerid][18], 1240);
    PlayerTextDrawSetPreviewRot(playerid, RegistroText[playerid][18], 0.000000, 0.000000, 0.000000, 1.000000);

    RegistroText[playerid][19] = CreatePlayerTextDraw(playerid, 275.944274, 210.049865, "Coloque_seu_email_aqui");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][19], 0.231800, 1.156666);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][19], 368.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][19], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][19], -1);
    //PlayerTextDrawUseBox(playerid, RegistroText[playerid][19], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][19], 0);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][19], 100);
    PlayerTextDrawFont(playerid, RegistroText[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][19], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][19], 0);
    PlayerTextDrawSetSelectable(playerid, RegistroText[playerid][19], true);

    RegistroText[playerid][20] = CreatePlayerTextDraw(playerid, 275.944274, 240.449981, "Selecionar_Sexo");
    PlayerTextDrawLetterSize(playerid, RegistroText[playerid][20], 0.231800, 1.156666);
    PlayerTextDrawTextSize(playerid, RegistroText[playerid][20], 368.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, RegistroText[playerid][20], 1);
    PlayerTextDrawColor(playerid, RegistroText[playerid][20], -1);
    //PlayerTextDrawUseBox(playerid, RegistroText[playerid][20], 1);
    PlayerTextDrawBoxColor(playerid, RegistroText[playerid][20], 0);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, RegistroText[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, RegistroText[playerid][20], 100);
    PlayerTextDrawFont(playerid, RegistroText[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, RegistroText[playerid][20], 1);
    PlayerTextDrawSetShadow(playerid, RegistroText[playerid][20], 0);
    PlayerTextDrawSetSelectable(playerid, RegistroText[playerid][20], true);

    for(new i=0; i < 21; i++){
        PlayerTextDrawShow(playerid, RegistroText[playerid][i]);
    }

    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")+1);
    Jogador[playerid][AntiEsc] = true;
    return 1;
}

function OcultarRegistro(playerid)
{
    Jogador[playerid][AntiEsc] = false;
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")-1);
    if(GetPVarInt(playerid, "EscEvento") == 0) CancelSelectTextDraw(playerid);
    for(new i=0; i < 21; i++){
        PlayerTextDrawDestroy(playerid, RegistroText[playerid][i]);
        RegistroText[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarCodigo(playerid)
{
    SelectTextDraw(playerid, 0xFFA500FF);
    CodigoLogin[playerid][0] = CreatePlayerTextDraw(playerid, 248.770019, 119.999977, "box");
    PlayerTextDrawLetterSize(playerid, CodigoLogin[playerid][0], 0.000000, 8.562849);
    PlayerTextDrawTextSize(playerid, CodigoLogin[playerid][0], 395.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, CodigoLogin[playerid][0], 1);
    PlayerTextDrawColor(playerid, CodigoLogin[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CodigoLogin[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CodigoLogin[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, CodigoLogin[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CodigoLogin[playerid][0], 255);
    PlayerTextDrawFont(playerid, CodigoLogin[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CodigoLogin[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][0], 0);

    CodigoLogin[playerid][1] = CreatePlayerTextDraw(playerid, 248.644134, 119.916664, "box");
    PlayerTextDrawLetterSize(playerid, CodigoLogin[playerid][1], 0.000000, 1.341999);
    PlayerTextDrawTextSize(playerid, CodigoLogin[playerid][1], 394.979614, 0.000000);
    PlayerTextDrawAlignment(playerid, CodigoLogin[playerid][1], 1);
    PlayerTextDrawColor(playerid, CodigoLogin[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CodigoLogin[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, CodigoLogin[playerid][1], -2139062262);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, CodigoLogin[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CodigoLogin[playerid][1], 255);
    PlayerTextDrawFont(playerid, CodigoLogin[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CodigoLogin[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][1], 0);

    CodigoLogin[playerid][2] = CreatePlayerTextDraw(playerid, 258.609008, 150.333389, "box");
    PlayerTextDrawLetterSize(playerid, CodigoLogin[playerid][2], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, CodigoLogin[playerid][2], 385.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, CodigoLogin[playerid][2], 1);
    PlayerTextDrawColor(playerid, CodigoLogin[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CodigoLogin[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, CodigoLogin[playerid][2], -2139062248);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, CodigoLogin[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CodigoLogin[playerid][2], 255);
    PlayerTextDrawFont(playerid, CodigoLogin[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CodigoLogin[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][2], 0);

    CodigoLogin[playerid][3] = CreatePlayerTextDraw(playerid, 258.609008, 150.333389, "box");
    PlayerTextDrawLetterSize(playerid, CodigoLogin[playerid][3], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, CodigoLogin[playerid][3], 269.339538, 0.000000);
    PlayerTextDrawAlignment(playerid, CodigoLogin[playerid][3], 1);
    PlayerTextDrawColor(playerid, CodigoLogin[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, CodigoLogin[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, CodigoLogin[playerid][3], 471604370);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, CodigoLogin[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, CodigoLogin[playerid][3], 255);
    PlayerTextDrawFont(playerid, CodigoLogin[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, CodigoLogin[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][3], 0);

    CodigoLogin[playerid][4] = CreatePlayerTextDraw(playerid, 302.790985, 120.599990, "Rippzy_City");
    PlayerTextDrawLetterSize(playerid, CodigoLogin[playerid][4], 0.210714, 1.127497);
    PlayerTextDrawAlignment(playerid, CodigoLogin[playerid][4], 1);
    PlayerTextDrawColor(playerid, CodigoLogin[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, CodigoLogin[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CodigoLogin[playerid][4], 83);
    PlayerTextDrawFont(playerid, CodigoLogin[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, CodigoLogin[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][4], 1);

    CodigoLogin[playerid][5] = CreatePlayerTextDraw(playerid, 250.944320, 148.316680, "");
    PlayerTextDrawLetterSize(playerid, CodigoLogin[playerid][5], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, CodigoLogin[playerid][5], 24.000000, 15.000000);
    PlayerTextDrawAlignment(playerid, CodigoLogin[playerid][5], 1);
    PlayerTextDrawColor(playerid, CodigoLogin[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, CodigoLogin[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CodigoLogin[playerid][5], 0);
    PlayerTextDrawFont(playerid, CodigoLogin[playerid][5], 5);
    PlayerTextDrawSetProportional(playerid, CodigoLogin[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][5], 0);
    PlayerTextDrawSetPreviewModel(playerid, CodigoLogin[playerid][5], 1239);
    PlayerTextDrawSetPreviewRot(playerid, CodigoLogin[playerid][5], 0.000000, 0.000000, 180.000000, 1.000000);

    CodigoLogin[playerid][6] = CreatePlayerTextDraw(playerid, 275.944274, 149.749969, "Coloque_o_codigo_aqui");
    PlayerTextDrawLetterSize(playerid, CodigoLogin[playerid][6], 0.241169, 1.209166);
    PlayerTextDrawTextSize(playerid, CodigoLogin[playerid][6], 381.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CodigoLogin[playerid][6], 1);
    PlayerTextDrawColor(playerid, CodigoLogin[playerid][6], -1);
    //PlayerTextDrawUseBox(playerid, CodigoLogin[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, CodigoLogin[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, CodigoLogin[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, CodigoLogin[playerid][6], 100);
    PlayerTextDrawFont(playerid, CodigoLogin[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, CodigoLogin[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, CodigoLogin[playerid][6], true);

    CodigoLogin[playerid][7] = CreatePlayerTextDraw(playerid, 211.588577, 78.583358, "");
    PlayerTextDrawLetterSize(playerid, CodigoLogin[playerid][7], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, CodigoLogin[playerid][7], 90.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, CodigoLogin[playerid][7], 1);
    PlayerTextDrawColor(playerid, CodigoLogin[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, CodigoLogin[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, CodigoLogin[playerid][7], 0);
    PlayerTextDrawFont(playerid, CodigoLogin[playerid][7], 5);
    PlayerTextDrawSetProportional(playerid, CodigoLogin[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][7], 0);
    PlayerTextDrawSetPreviewModel(playerid, CodigoLogin[playerid][7], NatalGorroID);
    PlayerTextDrawSetPreviewRot(playerid, CodigoLogin[playerid][7], 0.000000, 0.000000, 180.000000, 1.000000);

    CodigoLogin[playerid][8] = CreatePlayerTextDraw(playerid, 309.078216, 166.999588, "");
    PlayerTextDrawLetterSize(playerid, CodigoLogin[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, CodigoLogin[playerid][8], 23.000000, 27.000000);
    PlayerTextDrawAlignment(playerid, CodigoLogin[playerid][8], 1);
    PlayerTextDrawColor(playerid, CodigoLogin[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, CodigoLogin[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, CodigoLogin[playerid][8], 0);
    PlayerTextDrawFont(playerid, CodigoLogin[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, CodigoLogin[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, CodigoLogin[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, CodigoLogin[playerid][8], true);
    PlayerTextDrawSetPreviewModel(playerid, CodigoLogin[playerid][8], 19134);
    PlayerTextDrawSetPreviewRot(playerid, CodigoLogin[playerid][8], 0.000000, -90.000000, 90.000000, 1.000000);
    
    for(new i=0; i < 9; i++){
        PlayerTextDrawShow(playerid, CodigoLogin[playerid][i]);
    }

    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")+1);
    Jogador[playerid][AntiEsc] = true;
    return 1;
}

function OcultarCodigo(playerid)
{
    Jogador[playerid][AntiEsc] = false;
    SetPVarInt(playerid, "EscEvento", GetPVarInt(playerid, "EscEvento")-1);
    if(GetPVarInt(playerid, "EscEvento") == 0) CancelSelectTextDraw(playerid);
    for(new i=0; i < 9; i++){
        PlayerTextDrawDestroy(playerid, CodigoLogin[playerid][i]);
        CodigoLogin[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}