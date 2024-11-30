#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 4; i++){
        VelocimetroRC[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    GasN[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}

stock MostrarVelocimetro(playerid)
{
    VelocimetroRC[playerid][0] = CreatePlayerTextDraw(playerid, 138.925186, 393.716857, "box");
    PlayerTextDrawLetterSize(playerid, VelocimetroRC[playerid][0], 0.000000, 1.238651);
    PlayerTextDrawTextSize(playerid, VelocimetroRC[playerid][0], 226.600158, 0.000000);
    PlayerTextDrawAlignment(playerid, VelocimetroRC[playerid][0], 1);
    PlayerTextDrawColor(playerid, VelocimetroRC[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, VelocimetroRC[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, VelocimetroRC[playerid][0], 94);
    PlayerTextDrawSetShadow(playerid, VelocimetroRC[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, VelocimetroRC[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, VelocimetroRC[playerid][0], 255);
    PlayerTextDrawFont(playerid, VelocimetroRC[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, VelocimetroRC[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, VelocimetroRC[playerid][0], 0);

    VelocimetroRC[playerid][1] = CreatePlayerTextDraw(playerid, 183.092254, 393.083312, "0_Km/h");
    PlayerTextDrawLetterSize(playerid, VelocimetroRC[playerid][1], 0.305508, 1.261663);
    PlayerTextDrawAlignment(playerid, VelocimetroRC[playerid][1], 2);
    PlayerTextDrawColor(playerid, VelocimetroRC[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, VelocimetroRC[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, VelocimetroRC[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, VelocimetroRC[playerid][1], 255);
    PlayerTextDrawFont(playerid, VelocimetroRC[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, VelocimetroRC[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, VelocimetroRC[playerid][1], 1);

    VelocimetroRC[playerid][2] = CreatePlayerTextDraw(playerid, 182.718261, 409.733459, "Gasolina:_0L");
    PlayerTextDrawLetterSize(playerid, VelocimetroRC[playerid][2], 0.228049, 0.923331);
    PlayerTextDrawAlignment(playerid, VelocimetroRC[playerid][2], 2);
    PlayerTextDrawColor(playerid, VelocimetroRC[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, VelocimetroRC[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, VelocimetroRC[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, VelocimetroRC[playerid][2], 255);
    PlayerTextDrawFont(playerid, VelocimetroRC[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, VelocimetroRC[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, VelocimetroRC[playerid][2], 0);

    VelocimetroRC[playerid][3] = CreatePlayerTextDraw(playerid, 143.989898, 381.583526, "0.0_Km");
    PlayerTextDrawLetterSize(playerid, VelocimetroRC[playerid][3], 0.218680, 0.905831);
    PlayerTextDrawAlignment(playerid, VelocimetroRC[playerid][3], 1);
    PlayerTextDrawColor(playerid, VelocimetroRC[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, VelocimetroRC[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, VelocimetroRC[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, VelocimetroRC[playerid][3], 255);
    PlayerTextDrawFont(playerid, VelocimetroRC[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, VelocimetroRC[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, VelocimetroRC[playerid][3], 1);

    for(new i=0; i < 4; i++){
        PlayerTextDrawShow(playerid, VelocimetroRC[playerid][i]);
    }
    return 1;
}

stock OcultarVelocimetro(playerid)
{
    for(new i=0; i < 4; i++){
        PlayerTextDrawDestroy(playerid, VelocimetroRC[playerid][i]);
        VelocimetroRC[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarJetPack(playerid)
{
    GasN[playerid][0] = CreatePlayerTextDraw(playerid, 135.117416, 402.066711, "Gas:_~r~0m³");
    PlayerTextDrawLetterSize(playerid, GasN[playerid][0], 0.244450, 1.086664);
    PlayerTextDrawAlignment(playerid, GasN[playerid][0], 1);
    PlayerTextDrawColor(playerid, GasN[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, GasN[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, GasN[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, GasN[playerid][0], 255);
    PlayerTextDrawFont(playerid, GasN[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, GasN[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, GasN[playerid][0], 0);
    PlayerTextDrawShow(playerid, GasN[playerid][0]);
    return 1;
}

stock OcultarJetPack(playerid)
{
    PlayerTextDrawDestroy(playerid, GasN[playerid][0]);
    GasN[playerid][0] = PlayerText:INVALID_TEXT_DRAW;
    return 1;
}