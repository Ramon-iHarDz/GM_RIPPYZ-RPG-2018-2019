#include <YSI_Coding\y_hooks>

new PlayerText:KeypadTextDraw[MAX_PLAYERS][29];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 29; i++){
        KeypadTextDraw[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarKeypad(playerid, bool:travv)
{
    KeypadTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 242.941284, 261.166717, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][0], 0.000000, 17.063707);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][0], 395.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][0], 522265343);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][0], 1);

    KeypadTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 242.941360, 260.583465, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][1], 0.000000, 0.957934);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][1], 395.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][1], -626712321);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][1], 1);

    KeypadTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 246.235351, 278.183471, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][2], 0.000000, 14.712011);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][2], 332.999877, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][2], 1010580735);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][2], 1);

    KeypadTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 278.833587, 280.216339, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][3], 0.000000, 10.568707);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][3], 299.599517, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][3], 555753471);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][3], 1);

    KeypadTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 249.532196, 280.116638, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][4], 0.000000, 10.568707);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][4], 269.688140, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][4], 555753471);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][4], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][4], 1);

    KeypadTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 246.799560, 308.201202, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][5], 0.000000, 0.023528);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][5], 320.138946, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][5], 1010580735);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][5], 1);

    KeypadTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 246.799560, 342.501800, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][6], 0.000000, 0.023529);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][6], 332.839996, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][6], 1010580735);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][6], 1);

    KeypadTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 308.494689, 280.483398, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][7], 0.000000, 10.593712);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][7], 329.619995, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][7], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][7], 555753471);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][7], 1);

    KeypadTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 278.794525, 319.483612, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][8], 0.000000, 9.840767);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][8], 299.690002, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][8], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][8], 555753471);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][8], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][8], 1);

    KeypadTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 246.799560, 377.001464, "LinhaBaixo");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][9], 0.000000, 0.023529);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][9], 330.290008, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][9], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][9], 1010580735);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][9], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][9], 1);

    KeypadTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 340.093841, 278.249359, "CaixaDosNumerosVerdes");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][10], 0.000000, 2.617707);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][10], 392.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][10], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][10], 471604479);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][10], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][10], 1);

    KeypadTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 306.605957, 380.700225, "");
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][11], 26.000000, 27.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][11], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][11], 0);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][11], 0);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][11], 5);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][11], 0);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][11], true);
    PlayerTextDrawSetPreviewModel(playerid, KeypadTextDraw[playerid][11], 19134);
    PlayerTextDrawSetPreviewRot(playerid, KeypadTextDraw[playerid][11], 0.000000, -90.000000, 90.000000, 1.000000);

    KeypadTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 246.005340, 380.700225, "");
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][12], 26.000000, 27.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][12], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][12], -2147483393);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][12], 0);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][12], 0);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][12], 0);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][12], true);
    PlayerTextDrawSetPreviewModel(playerid, KeypadTextDraw[playerid][12], 19134);
    PlayerTextDrawSetPreviewRot(playerid, KeypadTextDraw[playerid][12], 0.000000, 90.000000, 90.000000, 1.000000);

    KeypadTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 387.364990, 274.149871, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][13], 0.000000, -2.018291);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][13], 395.430175, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][13], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][13], -16776961);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][13], -30527745);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][13], -16776961);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][13], 1);

    KeypadTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 388.147399, 259.166748, "X");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][14], 0.266001, 1.150831);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][14], 394.500030, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][14], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][14], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][14], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][14], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][14], true);

    KeypadTextDraw[playerid][15] = CreatePlayerTextDraw(playerid, 256.347167, 284.000122, "1");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][15], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][15], 264.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][15], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][15], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][15], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][15], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][15], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][15], true);

    KeypadTextDraw[playerid][16] = CreatePlayerTextDraw(playerid, 285.947540, 283.900024, "2");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][16], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][16], 294.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][16], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][16], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][16], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][16], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][16], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][16], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][16], true);

    KeypadTextDraw[playerid][17] = CreatePlayerTextDraw(playerid, 246.799560, 308.201202, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][17], 0.000000, 0.023528);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][17], 331.928924, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][17], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][17], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][17], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][17], 1010580735);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][17], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][17], 1);

    KeypadTextDraw[playerid][18] = CreatePlayerTextDraw(playerid, 246.799560, 342.501800, "box");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][18], 0.000000, 0.023529);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][18], 332.839996, 0.000000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][18], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][18], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][18], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][18], 1010580735);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][18], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][18], 1);

    KeypadTextDraw[playerid][19] = CreatePlayerTextDraw(playerid, 315.447692, 284.500061, "3");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][19], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][19], 324.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][19], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][19], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][19], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][19], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][19], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][19], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][19], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][19], true);

    KeypadTextDraw[playerid][20] = CreatePlayerTextDraw(playerid, 255.647369, 317.500244, "4");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][20], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][20], 264.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][20], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][20], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][20], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][20], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][20], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][20], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][20], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][20], true);

    KeypadTextDraw[playerid][21] = CreatePlayerTextDraw(playerid, 285.747528, 317.500244, "5");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][21], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][21], 294.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][21], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][21], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][21], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][21], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][21], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][21], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][21], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][21], true);

    KeypadTextDraw[playerid][22] = CreatePlayerTextDraw(playerid, 315.547760, 317.500244, "6");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][22], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][22], 323.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][22], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][22], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][22], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][22], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][22], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][22], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][22], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][22], true);

    KeypadTextDraw[playerid][23] = CreatePlayerTextDraw(playerid, 256.182586, 351.916900, "7");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][23], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][23], 264.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][23], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][23], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][23], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][23], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][23], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][23], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][23], true);

    KeypadTextDraw[playerid][24] = CreatePlayerTextDraw(playerid, 286.083007, 351.916900, "8");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][24], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][24], 295.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][24], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][24], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][24], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][24], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][24], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][24], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][24], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][24], true);

    KeypadTextDraw[playerid][25] = CreatePlayerTextDraw(playerid, 315.883361, 351.916900, "9");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][25], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][25], 324.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][25], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][25], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][25], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][25], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][25], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][25], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][25], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][25], true);

    KeypadTextDraw[playerid][26] = CreatePlayerTextDraw(playerid, 285.682983, 386.717254, "0");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][26], 0.400000, 1.600000);
    PlayerTextDrawTextSize(playerid, KeypadTextDraw[playerid][26], 295.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][26], 1);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][26], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][26], 1);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][26], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][26], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][26], 3);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][26], 1);
    PlayerTextDrawSetSelectable(playerid, KeypadTextDraw[playerid][26], true);

    KeypadTextDraw[playerid][27] = CreatePlayerTextDraw(playerid, 366.838012, 283.333435, "....");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][27], 0.191507, 1.191664);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][27], 2);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][27], 16711935);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][27], 0);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][27], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, KeypadTextDraw[playerid][27], 1);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][27], 50);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][27], 2);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][27], 1);

    KeypadTextDraw[playerid][28] = CreatePlayerTextDraw(playerid, 320.190948, 258.233367, "Keypad");
    PlayerTextDrawLetterSize(playerid, KeypadTextDraw[playerid][28], 0.272093, 1.226665);
    PlayerTextDrawAlignment(playerid, KeypadTextDraw[playerid][28], 2);
    PlayerTextDrawColor(playerid, KeypadTextDraw[playerid][28], -1);
    PlayerTextDrawUseBox(playerid, KeypadTextDraw[playerid][28], 0);
    PlayerTextDrawBoxColor(playerid, KeypadTextDraw[playerid][28], 0);
    PlayerTextDrawSetShadow(playerid, KeypadTextDraw[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, KeypadTextDraw[playerid][28], 255);
    PlayerTextDrawFont(playerid, KeypadTextDraw[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, KeypadTextDraw[playerid][28], 1);

    for(new i=0; i < 29; i++){
        PlayerTextDrawShow(playerid, KeypadTextDraw[playerid][i]);
    }
    SelectTextDrawEx(playerid, 0x00BFFFFF, "OcultarKeypad", travv);
    return 1;
}

stock OcultarKeypad(playerid){
    for(new i=0; i < 29; i++){
        PlayerTextDrawDestroy(playerid, KeypadTextDraw[playerid][i]);
        KeypadTextDraw[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    CancelSelectTextDrawEx(playerid, "OcultarKeypad");
    return 1;
}