#include <YSI_Coding\y_hooks>

new PlayerText:MensagemPlayer[MAX_PLAYERS][3],
    bool:AlertaTela[MAX_PLAYERS],
    AlertaTempo[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    if(AlertaTela[playerid] == true){
        KillTimer(AlertaTempo[playerid]);
        AlertaTela[playerid] = false;
    }

    for(new i=0; i < 3; i++){
        MensagemPlayer[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock EnviarAlerta(playerid, const InfoF[], const Msgg[], tempo)
{
    if(AlertaTela[playerid] == true){
        KillTimer(AlertaTempo[playerid]);
        OcultarAlertaPlayer(playerid);
    }

    AlertaPlayer(playerid, InfoF, Msgg);
    AlertaTela[playerid] = true;
    AlertaTempo[playerid] = SetTimerEx("OcultarAlertaPlayer", tempo, false, "d", playerid);
    return 1;
}

stock AlertaPlayer(playerid, const InfoF[], const Msgg[])
{
    MensagemPlayer[playerid][0] = CreatePlayerTextDraw(playerid, 10.292819, 196.416687, "box");
    PlayerTextDrawLetterSize(playerid, MensagemPlayer[playerid][0], 0.000000, 1.238654);
    PlayerTextDrawTextSize(playerid, MensagemPlayer[playerid][0], 110.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, MensagemPlayer[playerid][0], 1);
    PlayerTextDrawColor(playerid, MensagemPlayer[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, MensagemPlayer[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, MensagemPlayer[playerid][0], 119);
    PlayerTextDrawSetShadow(playerid, MensagemPlayer[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, MensagemPlayer[playerid][0], 255);
    PlayerTextDrawFont(playerid, MensagemPlayer[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, MensagemPlayer[playerid][0], 1);

    MensagemPlayer[playerid][1] = CreatePlayerTextDraw(playerid, 59.644935, 197.016952, ConverterTexto(InfoF));
    PlayerTextDrawLetterSize(playerid, MensagemPlayer[playerid][1], 0.206031, 1.063331);
    PlayerTextDrawAlignment(playerid, MensagemPlayer[playerid][1], 2);
    PlayerTextDrawColor(playerid, MensagemPlayer[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, MensagemPlayer[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, MensagemPlayer[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, MensagemPlayer[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, MensagemPlayer[playerid][1], 39);
    PlayerTextDrawFont(playerid, MensagemPlayer[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, MensagemPlayer[playerid][1], 1);

    MensagemPlayer[playerid][2] = CreatePlayerTextDraw(playerid, 60.156127, 212.099899, ConverterTexto(Msgg));
    PlayerTextDrawLetterSize(playerid, MensagemPlayer[playerid][2], 0.197129, 0.870830);
    PlayerTextDrawTextSize(playerid, MensagemPlayer[playerid][2], 0.000000, 99.000000);
    PlayerTextDrawAlignment(playerid, MensagemPlayer[playerid][2], 2);
    PlayerTextDrawColor(playerid, MensagemPlayer[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, MensagemPlayer[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, MensagemPlayer[playerid][2], 471604479);
    PlayerTextDrawSetShadow(playerid, MensagemPlayer[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, MensagemPlayer[playerid][2], 25);
    PlayerTextDrawFont(playerid, MensagemPlayer[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, MensagemPlayer[playerid][2], 1);

    for(new i=0; i < 3; i++){
        PlayerTextDrawShow(playerid, MensagemPlayer[playerid][i]);
    }
    return 1;
}

function OcultarAlertaPlayer(playerid)
{
    for(new i=0; i < 3; i++){
        PlayerTextDrawDestroy(playerid, MensagemPlayer[playerid][i]);
        MensagemPlayer[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarAdminAlerta()
{
    AlertaAdmin[0] = TextDrawCreate(10.292819, 196.416687, "box");
    TextDrawLetterSize(AlertaAdmin[0], 0.000000, 1.238654);
    TextDrawTextSize(AlertaAdmin[0], 110.000000, 0.000000);
    TextDrawAlignment(AlertaAdmin[0], 1);
    TextDrawColor(AlertaAdmin[0], -1);
    TextDrawUseBox(AlertaAdmin[0], 1);
    TextDrawBoxColor(AlertaAdmin[0], 119);
    TextDrawSetShadow(AlertaAdmin[0], 0);
    TextDrawBackgroundColor(AlertaAdmin[0], 255);
    TextDrawFont(AlertaAdmin[0], 1);
    TextDrawSetProportional(AlertaAdmin[0], 1);

    AlertaAdmin[1] = TextDrawCreate(59.644935, 197.016952, "Alerta");
    TextDrawLetterSize(AlertaAdmin[1], 0.206031, 1.063331);
    TextDrawAlignment(AlertaAdmin[1], 2);
    TextDrawColor(AlertaAdmin[1], -1);
    TextDrawUseBox(AlertaAdmin[1], 0);
    TextDrawBoxColor(AlertaAdmin[1], 0);
    TextDrawSetShadow(AlertaAdmin[1], 1);
    TextDrawBackgroundColor(AlertaAdmin[1], 39);
    TextDrawFont(AlertaAdmin[1], 1);
    TextDrawSetProportional(AlertaAdmin[1], 1);

    AlertaAdmin[2] = TextDrawCreate(60.156127, 212.099899, "Teste");
    TextDrawLetterSize(AlertaAdmin[2], 0.197129, 0.870830);
    TextDrawTextSize(AlertaAdmin[2], 0.000000, 99.000000);
    TextDrawAlignment(AlertaAdmin[2], 2);
    TextDrawColor(AlertaAdmin[2], -1);
    TextDrawUseBox(AlertaAdmin[2], 1);
    TextDrawBoxColor(AlertaAdmin[2], 471604479);
    TextDrawSetShadow(AlertaAdmin[2], 1);
    TextDrawBackgroundColor(AlertaAdmin[2], 25);
    TextDrawFont(AlertaAdmin[2], 1);
    TextDrawSetProportional(AlertaAdmin[2], 1);

    for(new i=0; i < 3; i++){
        TextDrawShowForAll(AlertaAdmin[i]);
    }
    return 1;
}

function OcultarAdminAlerta()
{
    AlertaAdminStt = false;
    for(new i=0; i < 3; i++){
        TextDrawDestroy(AlertaAdmin[i]);
        AlertaAdmin[i] = Text:INVALID_TEXT_DRAW;
    }
    return 1;
}