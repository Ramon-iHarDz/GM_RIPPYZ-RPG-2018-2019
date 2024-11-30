#include <YSI_Coding\y_hooks>

enum BarraProgresso
{
    bool:BarraIniciada,
    Float:TempoBarra,
    TimerBarra,

    CallProgresso[128],
    NomeProgresso[128]
};

new pProgresso[MAX_PLAYERS][BarraProgresso];
new PlayerText:ProgressoBarra[MAX_PLAYERS][3];

hook OnPlayerDisconnect(playerid)
{
    if(pProgresso[playerid][BarraIniciada] == true) KillTimer(pProgresso[playerid][TimerBarra]);

    for(new i=0; i < 3; i++){
        ProgressoBarra[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    new Fdsa[BarraProgresso];
    pProgresso[playerid] = Fdsa;
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    PararProgresso(playerid);
    return 1;
}

stock CriarProgresso(playerid, const NomeBarra[], const AcabarCall[], tempo)
{
    if(pProgresso[playerid][BarraIniciada] == true) return 1;
    pProgresso[playerid][BarraIniciada] = true;
    pProgresso[playerid][TempoBarra] = 0.0;
    MostrarBarra(playerid);

    new Mensagem[128];
    PlayerTextDrawTextSize(playerid, ProgressoBarra[playerid][1], (266.2 + ((133.0 * pProgresso[playerid][TempoBarra]) / 100)), 0.000000);
    format(Mensagem, sizeof(Mensagem), "%s %d%", NomeBarra, 0);
    PlayerTextDrawSetString(playerid, ProgressoBarra[playerid][2], ConverterTexto(Mensagem));
    PlayerTextDrawShow(playerid, ProgressoBarra[playerid][1]);

    format(pProgresso[playerid][CallProgresso], 128, AcabarCall);
    format(pProgresso[playerid][NomeProgresso], 128, NomeBarra);

    pProgresso[playerid][TimerBarra] = SetTimerEx("AtualizarBarraProgresso", tempo, true, "d", playerid);
    return true;
}

stock PararProgresso(playerid)
{
    if(pProgresso[playerid][BarraIniciada] == false) return 1;
    pProgresso[playerid][BarraIniciada] = false;
    KillTimer(pProgresso[playerid][TimerBarra]);
    OcultarBarra(playerid);
    return 1;
}

function AtualizarBarraProgresso(playerid)
{
    new Mensagem[128];
    pProgresso[playerid][TempoBarra] += 1.0;

    PlayerTextDrawTextSize(playerid, ProgressoBarra[playerid][1], (266.2 + ((133.0 * pProgresso[playerid][TempoBarra]) / 100)), 0.000000);
    format(Mensagem, sizeof(Mensagem), "%s %d%", pProgresso[playerid][NomeProgresso], floatround(pProgresso[playerid][TempoBarra], floatround_round));
    PlayerTextDrawSetString(playerid, ProgressoBarra[playerid][2], ConverterTexto(Mensagem));
    PlayerTextDrawShow(playerid, ProgressoBarra[playerid][1]);

    if(pProgresso[playerid][TempoBarra] >= 100.0)
    {
        KillTimer(pProgresso[playerid][TimerBarra]);
        OcultarBarra(playerid);
        pProgresso[playerid][BarraIniciada] = false;
        CallRemoteFunction(pProgresso[playerid][CallProgresso], "d", playerid);
    }
    return true;
}

stock MostrarBarra(playerid)
{
    ProgressoBarra[playerid][0] = CreatePlayerTextDraw(playerid, 266.279418, 389.033477, "box");
    PlayerTextDrawLetterSize(playerid, ProgressoBarra[playerid][0], 0.000000, 1.022061);
    PlayerTextDrawTextSize(playerid, ProgressoBarra[playerid][0], 399.999877, 0.000000);
    PlayerTextDrawAlignment(playerid, ProgressoBarra[playerid][0], 1);
    PlayerTextDrawColor(playerid, ProgressoBarra[playerid][0], -5963521);
    PlayerTextDrawUseBox(playerid, ProgressoBarra[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, ProgressoBarra[playerid][0], -5963743);
    PlayerTextDrawSetShadow(playerid, ProgressoBarra[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressoBarra[playerid][0], 255);
    PlayerTextDrawFont(playerid, ProgressoBarra[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ProgressoBarra[playerid][0], 1);

    ProgressoBarra[playerid][1] = CreatePlayerTextDraw(playerid, 266.279418, 389.033477, "box");
    PlayerTextDrawLetterSize(playerid, ProgressoBarra[playerid][1], 0.000000, 0.975210);
    PlayerTextDrawTextSize(playerid, ProgressoBarra[playerid][1], 399.956939, 0.000000);
    PlayerTextDrawAlignment(playerid, ProgressoBarra[playerid][1], 1);
    PlayerTextDrawColor(playerid, ProgressoBarra[playerid][1], -5963521);
    PlayerTextDrawUseBox(playerid, ProgressoBarra[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, ProgressoBarra[playerid][1], -5963646);
    PlayerTextDrawSetShadow(playerid, ProgressoBarra[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressoBarra[playerid][1], 255);
    PlayerTextDrawFont(playerid, ProgressoBarra[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ProgressoBarra[playerid][1], 1);

    ProgressoBarra[playerid][2] = CreatePlayerTextDraw(playerid, 334.509643, 401.749877, " ");
    PlayerTextDrawLetterSize(playerid, ProgressoBarra[playerid][2], 0.192444, 0.952499);
    PlayerTextDrawAlignment(playerid, ProgressoBarra[playerid][2], 2);
    PlayerTextDrawColor(playerid, ProgressoBarra[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, ProgressoBarra[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, ProgressoBarra[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, ProgressoBarra[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, ProgressoBarra[playerid][2], 70);
    PlayerTextDrawFont(playerid, ProgressoBarra[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ProgressoBarra[playerid][2], 1);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, ProgressoBarra[playerid][i]);
    }
    return 1;
}

stock OcultarBarra(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, ProgressoBarra[playerid][i]);
        ProgressoBarra[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}