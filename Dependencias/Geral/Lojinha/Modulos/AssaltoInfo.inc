#include <YSI_Coding\y_hooks>

new PlayerText:LojinhaText[MAX_PLAYERS][5];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 5; i++){
        LojinhaText[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarLojaAssalto(playerid)
{
    LojinhaText[playerid][0] = CreatePlayerTextDraw(playerid, 458.899261, 196.033325, "Lojinha");
    PlayerTextDrawLetterSize(playerid, LojinhaText[playerid][0], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, LojinhaText[playerid][0], 1);
    PlayerTextDrawColor(playerid, LojinhaText[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, LojinhaText[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, LojinhaText[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, LojinhaText[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, LojinhaText[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, LojinhaText[playerid][0], 50);
    PlayerTextDrawFont(playerid, LojinhaText[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, LojinhaText[playerid][0], 1);

    LojinhaText[playerid][1] = CreatePlayerTextDraw(playerid, 456.662109, 211.283294, "Tempo:_03:00");
    PlayerTextDrawLetterSize(playerid, LojinhaText[playerid][1], 0.208843, 1.098332);
    PlayerTextDrawAlignment(playerid, LojinhaText[playerid][1], 1);
    PlayerTextDrawColor(playerid, LojinhaText[playerid][1], -5963521);
    PlayerTextDrawUseBox(playerid, LojinhaText[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, LojinhaText[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, LojinhaText[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, LojinhaText[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, LojinhaText[playerid][1], 50);
    PlayerTextDrawFont(playerid, LojinhaText[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, LojinhaText[playerid][1], 1);

    LojinhaText[playerid][2] = CreatePlayerTextDraw(playerid, 444.449005, 223.783218, "Aperte");
    PlayerTextDrawLetterSize(playerid, LojinhaText[playerid][2], 0.302547, 1.424999);
    PlayerTextDrawAlignment(playerid, LojinhaText[playerid][2], 1);
    PlayerTextDrawColor(playerid, LojinhaText[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, LojinhaText[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, LojinhaText[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, LojinhaText[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, LojinhaText[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, LojinhaText[playerid][2], 17);
    PlayerTextDrawFont(playerid, LojinhaText[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, LojinhaText[playerid][2], 1);

    LojinhaText[playerid][3] = CreatePlayerTextDraw(playerid, 482.162322, 225.483306, "F");
    PlayerTextDrawLetterSize(playerid, LojinhaText[playerid][3], 0.302547, 1.424999);
    PlayerTextDrawTextSize(playerid, LojinhaText[playerid][3], 489.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, LojinhaText[playerid][3], 1);
    PlayerTextDrawColor(playerid, LojinhaText[playerid][3], -16776961);
    PlayerTextDrawUseBox(playerid, LojinhaText[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, LojinhaText[playerid][3], 29);
    PlayerTextDrawSetShadow(playerid, LojinhaText[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, LojinhaText[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, LojinhaText[playerid][3], 17);
    PlayerTextDrawFont(playerid, LojinhaText[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, LojinhaText[playerid][3], 1);

    LojinhaText[playerid][4] = CreatePlayerTextDraw(playerid, 493.375244, 225.100036, "Cancelar");
    PlayerTextDrawLetterSize(playerid, LojinhaText[playerid][4], 0.244919, 1.302499);
    PlayerTextDrawAlignment(playerid, LojinhaText[playerid][4], 1);
    PlayerTextDrawColor(playerid, LojinhaText[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, LojinhaText[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, LojinhaText[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, LojinhaText[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, LojinhaText[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, LojinhaText[playerid][4], 17);
    PlayerTextDrawFont(playerid, LojinhaText[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, LojinhaText[playerid][4], 1);

    for(new i=0; i < 5; i++){
        PlayerTextDrawShow(playerid, LojinhaText[playerid][i]);
    }
    return 1;
}

stock OcultarAssaltoLoja(playerid)
{
    for(new i=0; i < 5; i++){
        PlayerTextDrawDestroy(playerid, LojinhaText[playerid][i]);
        LojinhaText[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarParadaRoubo(playerid)
{
    PlayerTextDrawColor(playerid, LojinhaText[playerid][3], 16711935);
    PlayerTextDrawShow(playerid, LojinhaText[playerid][3]);
    return 1;
}