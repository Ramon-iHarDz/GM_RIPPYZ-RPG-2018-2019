#include <YSI_Coding\y_hooks>

new Text:LoteriaDraw[6];

stock ExibirLoteriaInfo()
{
    LoteriaDraw[0] = TextDrawCreate(525.666198, 144.500000, "box");
    TextDrawLetterSize(LoteriaDraw[0], 0.000000, 5.407268);
    TextDrawTextSize(LoteriaDraw[0], 622.000000, 0.000000);
    TextDrawAlignment(LoteriaDraw[0], 1);
    TextDrawColor(LoteriaDraw[0], -1);
    TextDrawUseBox(LoteriaDraw[0], 1);
    TextDrawBoxColor(LoteriaDraw[0], 471604479);
    TextDrawSetShadow(LoteriaDraw[0], 0);
    TextDrawBackgroundColor(LoteriaDraw[0], 255);
    TextDrawFont(LoteriaDraw[0], 1);
    TextDrawSetProportional(LoteriaDraw[0], 1);

    LoteriaDraw[1] = TextDrawCreate(525.666198, 144.500000, "box");
    TextDrawLetterSize(LoteriaDraw[1], 0.000000, 0.696268);
    TextDrawTextSize(LoteriaDraw[1], 622.000000, 0.000000);
    TextDrawAlignment(LoteriaDraw[1], 1);
    TextDrawColor(LoteriaDraw[1], -1);
    TextDrawUseBox(LoteriaDraw[1], 1);
    TextDrawBoxColor(LoteriaDraw[1], -56286977);
    TextDrawSetShadow(LoteriaDraw[1], 0);
    TextDrawBackgroundColor(LoteriaDraw[1], 255);
    TextDrawFont(LoteriaDraw[1], 1);
    TextDrawSetProportional(LoteriaDraw[1], 1);

    LoteriaDraw[2] = TextDrawCreate(575.629333, 142.383377, "Loterica");
    TextDrawLetterSize(LoteriaDraw[2], 0.247730, 1.034165);
    TextDrawAlignment(LoteriaDraw[2], 2);
    TextDrawColor(LoteriaDraw[2], -1);
    TextDrawUseBox(LoteriaDraw[2], 0);
    TextDrawBoxColor(LoteriaDraw[2], 0);
    TextDrawSetShadow(LoteriaDraw[2], 1);
    TextDrawBackgroundColor(LoteriaDraw[2], 57);
    TextDrawFont(LoteriaDraw[2], 1);
    TextDrawSetProportional(LoteriaDraw[2], 1);

    LoteriaDraw[3] = TextDrawCreate(527.995361, 157.283218, "Numero:_240");
    TextDrawLetterSize(LoteriaDraw[3], 0.200408, 1.069164);
    TextDrawAlignment(LoteriaDraw[3], 1);
    TextDrawColor(LoteriaDraw[3], -1);
    TextDrawUseBox(LoteriaDraw[3], 0);
    TextDrawBoxColor(LoteriaDraw[3], 0);
    TextDrawSetShadow(LoteriaDraw[3], 1);
    TextDrawBackgroundColor(LoteriaDraw[3], 90);
    TextDrawFont(LoteriaDraw[3], 1);
    TextDrawSetProportional(LoteriaDraw[3], 1);

    LoteriaDraw[4] = TextDrawCreate(527.326904, 167.883865, "Ganhador(a):_N/A");
    TextDrawLetterSize(LoteriaDraw[4], 0.200408, 1.069164);
    TextDrawAlignment(LoteriaDraw[4], 1);
    TextDrawColor(LoteriaDraw[4], -1);
    TextDrawUseBox(LoteriaDraw[4], 0);
    TextDrawBoxColor(LoteriaDraw[4], 0);
    TextDrawSetShadow(LoteriaDraw[4], 1);
    TextDrawBackgroundColor(LoteriaDraw[4], 90);
    TextDrawFont(LoteriaDraw[4], 1);
    TextDrawSetProportional(LoteriaDraw[4], 1);

    LoteriaDraw[5] = TextDrawCreate(574.704284, 183.151382, "R$0");
    TextDrawLetterSize(LoteriaDraw[5], 0.167612, 0.835830);
    TextDrawAlignment(LoteriaDraw[5], 2);
    TextDrawColor(LoteriaDraw[5], 8388863);
    TextDrawUseBox(LoteriaDraw[5], 0);
    TextDrawBoxColor(LoteriaDraw[5], 0);
    TextDrawSetShadow(LoteriaDraw[5], 0);
    TextDrawSetOutline(LoteriaDraw[5], 1);
    TextDrawBackgroundColor(LoteriaDraw[5], 255);
    TextDrawFont(LoteriaDraw[5], 1);
    TextDrawSetProportional(LoteriaDraw[5], 1);

    for(new i=0; i < 6; i++){
        TextDrawShowForAll(LoteriaDraw[i]);
    }
    return 1;
}

function OcultarLoteriaInfo(){
    for(new i=0; i < 6; i++){
        TextDrawDestroy(LoteriaDraw[i]);
        LoteriaDraw[i] = Text:INVALID_TEXT_DRAW;
    }
    return 1;
}