#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 2; i++){
        CelularBanco[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function MostrarCelularBanco(playerid)
{
    CelularBanco[playerid][0] = CreatePlayerTextDraw(playerid, 431.782592, 330.066680, "Transferir");
    PlayerTextDrawLetterSize(playerid, CelularBanco[playerid][0], 0.353147, 1.535832);
    PlayerTextDrawTextSize(playerid, CelularBanco[playerid][0], 481.000000, 12.0000); 
    PlayerTextDrawAlignment(playerid, CelularBanco[playerid][0], 1);
    PlayerTextDrawColor(playerid, CelularBanco[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularBanco[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CelularBanco[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, CelularBanco[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularBanco[playerid][0], 90);
    PlayerTextDrawFont(playerid, CelularBanco[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CelularBanco[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, CelularBanco[playerid][0], true);

    CelularBanco[playerid][1] = CreatePlayerTextDraw(playerid, 431.182586, 353.467010, "Saldo"); 
    PlayerTextDrawLetterSize(playerid, CelularBanco[playerid][1], 0.353147, 1.535832);
    PlayerTextDrawTextSize(playerid, CelularBanco[playerid][1], 482.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularBanco[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularBanco[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CelularBanco[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, CelularBanco[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, CelularBanco[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularBanco[playerid][1], 90);
    PlayerTextDrawFont(playerid, CelularBanco[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CelularBanco[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, CelularBanco[playerid][1], true);

    for(new i=0; i < 2; i++){
        PlayerTextDrawShow(playerid, CelularBanco[playerid][i]);
    }

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarCelularBanco");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarHome"); 
    return 1;
}

function OcultarCelularBanco(playerid)
{
    for(new i=0; i < 2; i++){
        PlayerTextDrawDestroy(playerid, CelularBanco[playerid][i]);
        CelularBanco[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == CelularBanco[playerid][0]){
        OcultarCelularBanco(playerid);
        MostrarCelularTransferencia(playerid);
    }
    else if(playertextid == CelularBanco[playerid][1]){ 
        OcultarCelularBanco(playerid);  
        MostrarCelularSaldo(playerid);
    }
    return 0;
}