#include <YSI_Coding\y_hooks>

new PlayerText:AbordagemTxd[MAX_PLAYERS][2];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 2; i++){
        AbordagemTxd[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarAbordagem(playerid)
{
    AbordagemTxd[playerid][0] = CreatePlayerTextDraw(playerid, 444.463562, 174.833404, "Abordado(a)");
    PlayerTextDrawLetterSize(playerid, AbordagemTxd[playerid][0], 0.422488, 1.576665);
    PlayerTextDrawAlignment(playerid, AbordagemTxd[playerid][0], 1);
    PlayerTextDrawColor(playerid, AbordagemTxd[playerid][0], 65535);
    PlayerTextDrawSetShadow(playerid, AbordagemTxd[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, AbordagemTxd[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, AbordagemTxd[playerid][0], 255);
    PlayerTextDrawFont(playerid, AbordagemTxd[playerid][0], 0);
    PlayerTextDrawSetProportional(playerid, AbordagemTxd[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, AbordagemTxd[playerid][0], 0);

    AbordagemTxd[playerid][1] = CreatePlayerTextDraw(playerid, 414.158111, 191.750015, "Use:_~r~/r~w~_para_se_render");
    PlayerTextDrawLetterSize(playerid, AbordagemTxd[playerid][1], 0.313322, 1.360831);
    PlayerTextDrawAlignment(playerid, AbordagemTxd[playerid][1], 1);
    PlayerTextDrawColor(playerid, AbordagemTxd[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, AbordagemTxd[playerid][1], 1);
    PlayerTextDrawSetOutline(playerid, AbordagemTxd[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, AbordagemTxd[playerid][1], 255);
    PlayerTextDrawFont(playerid, AbordagemTxd[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, AbordagemTxd[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, AbordagemTxd[playerid][1], 1);

    /*AbordagemTxd[playerid][2] = CreatePlayerTextDraw(playerid, 502.500000, 167.833297, "");
    PlayerTextDrawLetterSize(playerid, AbordagemTxd[playerid][2], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, AbordagemTxd[playerid][2], 32.000000, 28.000000);
    PlayerTextDrawAlignment(playerid, AbordagemTxd[playerid][2], 1);
    PlayerTextDrawColor(playerid, AbordagemTxd[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, AbordagemTxd[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, AbordagemTxd[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, AbordagemTxd[playerid][2], 0);
    PlayerTextDrawFont(playerid, AbordagemTxd[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, AbordagemTxd[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, AbordagemTxd[playerid][2], 0);
    PlayerTextDrawSetPreviewModel(playerid, AbordagemTxd[playerid][2], 18646);
    PlayerTextDrawSetPreviewRot(playerid, AbordagemTxd[playerid][2], 0.000000, 0.000000, 0.000000, 1.000000);*/
    
    for(new i=0; i < 2; i++){
        PlayerTextDrawShow(playerid, AbordagemTxd[playerid][i]);
    }

    return 1;
}

stock OcultarAbordagem(playerid)
{
    for(new i=0; i < 2; i++){
        PlayerTextDrawDestroy(playerid, AbordagemTxd[playerid][i]);
        AbordagemTxd[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}