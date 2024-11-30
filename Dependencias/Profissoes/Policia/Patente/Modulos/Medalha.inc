#include <YSI_Coding\y_hooks>

new PlayerText:PoliciaMedalha[MAX_PLAYERS][4];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 4; i++){
        PoliciaMedalha[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarMedalha(playerid)
{
    PoliciaMedalha[playerid][0] = CreatePlayerTextDraw(playerid, 321.859375, 88.000022, "Parabens!");
    PlayerTextDrawLetterSize(playerid, PoliciaMedalha[playerid][0], 0.268813, 1.343332);
    PlayerTextDrawAlignment(playerid, PoliciaMedalha[playerid][0], 2);
    PlayerTextDrawColor(playerid, PoliciaMedalha[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, PoliciaMedalha[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, PoliciaMedalha[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, PoliciaMedalha[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaMedalha[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, PoliciaMedalha[playerid][0], 40);
    PlayerTextDrawFont(playerid, PoliciaMedalha[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, PoliciaMedalha[playerid][0], 1);

    PoliciaMedalha[playerid][1] = CreatePlayerTextDraw(playerid, 321.390838, 101.333366, "Voce_foi_promovido(a)_para");
    PlayerTextDrawLetterSize(playerid, PoliciaMedalha[playerid][1], 0.243513, 1.034165);
    PlayerTextDrawAlignment(playerid, PoliciaMedalha[playerid][1], 2);
    PlayerTextDrawColor(playerid, PoliciaMedalha[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, PoliciaMedalha[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, PoliciaMedalha[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, PoliciaMedalha[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaMedalha[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, PoliciaMedalha[playerid][1], 40);
    PlayerTextDrawFont(playerid, PoliciaMedalha[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, PoliciaMedalha[playerid][1], 1);

    PoliciaMedalha[playerid][2] = CreatePlayerTextDraw(playerid, 321.964874, 113.149948, "Tenente_Coronel");
    PlayerTextDrawLetterSize(playerid, PoliciaMedalha[playerid][2], 0.293645, 1.191667);
    PlayerTextDrawTextSize(playerid, PoliciaMedalha[playerid][2], 0.000000, 108.000000);
    PlayerTextDrawAlignment(playerid, PoliciaMedalha[playerid][2], 2);
    PlayerTextDrawColor(playerid, PoliciaMedalha[playerid][2], -5963521);
    PlayerTextDrawUseBox(playerid, PoliciaMedalha[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, PoliciaMedalha[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, PoliciaMedalha[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PoliciaMedalha[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, PoliciaMedalha[playerid][2], 165);
    PlayerTextDrawFont(playerid, PoliciaMedalha[playerid][2], 3);
    PlayerTextDrawSetProportional(playerid, PoliciaMedalha[playerid][2], 1);

    PoliciaMedalha[playerid][3] = CreatePlayerTextDraw(playerid, 317.943023, 69.833320, "hud:radar_emmetgun");
    PlayerTextDrawTextSize(playerid, PoliciaMedalha[playerid][3], 12.000000, 13.000000);
    PlayerTextDrawAlignment(playerid, PoliciaMedalha[playerid][3], 1);
    PlayerTextDrawColor(playerid, PoliciaMedalha[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, PoliciaMedalha[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, PoliciaMedalha[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, PoliciaMedalha[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PoliciaMedalha[playerid][3], 255);
    PlayerTextDrawFont(playerid, PoliciaMedalha[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, PoliciaMedalha[playerid][3], 0);

    for(new i=0; i < 4; i++){
        PlayerTextDrawShow(playerid, PoliciaMedalha[playerid][i]);
    }
    return 1;
}

stock OcultarMedalha(playerid)
{
    for(new i=0; i < 4; i++){
        PlayerTextDrawDestroy(playerid, PoliciaMedalha[playerid][i]);
        PoliciaMedalha[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}