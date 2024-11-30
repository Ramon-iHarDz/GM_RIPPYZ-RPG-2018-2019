#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 3; i++){
        CelularSaldo[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function MostrarCelularSaldo(playerid) 
{
    CelularSaldo[playerid][0] = CreatePlayerTextDraw(playerid, 413.616912, 324.166625, "box");
    PlayerTextDrawLetterSize(playerid, CelularSaldo[playerid][0], 0.000000, 5.545991);
    PlayerTextDrawTextSize(playerid, CelularSaldo[playerid][0], 497.999572, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularSaldo[playerid][0], 1);
    PlayerTextDrawColor(playerid, CelularSaldo[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularSaldo[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CelularSaldo[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, CelularSaldo[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularSaldo[playerid][0], 255);
    PlayerTextDrawFont(playerid, CelularSaldo[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, CelularSaldo[playerid][0], 1);

    new Mensagem[60];
    format(Mensagem, sizeof(Mensagem), "$%s", DinheiroSeparar(Jogador[playerid][DinheiroBanco]));
    CelularSaldo[playerid][1] = CreatePlayerTextDraw(playerid, 455.856567, 353.550262, ConverterTexto(Mensagem));
    PlayerTextDrawLetterSize(playerid, CelularSaldo[playerid][1], 0.200877, 1.144997);
    PlayerTextDrawTextSize(playerid, CelularSaldo[playerid][1], 0.000000, 10.000000);
    PlayerTextDrawAlignment(playerid, CelularSaldo[playerid][1], 2);
    PlayerTextDrawColor(playerid, CelularSaldo[playerid][1], 852308735);
    PlayerTextDrawUseBox(playerid, CelularSaldo[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, CelularSaldo[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, CelularSaldo[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, CelularSaldo[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularSaldo[playerid][1], 255);
    PlayerTextDrawFont(playerid, CelularSaldo[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CelularSaldo[playerid][1], 1);

    format(Mensagem, sizeof(Mensagem), "Login: %s", PegarNick(playerid));
    CelularSaldo[playerid][2] = CreatePlayerTextDraw(playerid, 455.667572, 336.400024, ConverterTexto(Mensagem));
    PlayerTextDrawLetterSize(playerid, CelularSaldo[playerid][2], 0.210716, 0.969998);
    PlayerTextDrawTextSize(playerid, CelularSaldo[playerid][2], 0.000000, 74.000000);
    PlayerTextDrawAlignment(playerid, CelularSaldo[playerid][2], 2);
    PlayerTextDrawColor(playerid, CelularSaldo[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularSaldo[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, CelularSaldo[playerid][2], -2139062252);
    PlayerTextDrawSetShadow(playerid, CelularSaldo[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularSaldo[playerid][2], 137);
    PlayerTextDrawFont(playerid, CelularSaldo[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CelularSaldo[playerid][2], 1);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, CelularSaldo[playerid][i]);
    }

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarCelularSaldo");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarCelularBanco");
    return 1;
}

function OcultarCelularSaldo(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, CelularSaldo[playerid][i]);
        CelularSaldo[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}