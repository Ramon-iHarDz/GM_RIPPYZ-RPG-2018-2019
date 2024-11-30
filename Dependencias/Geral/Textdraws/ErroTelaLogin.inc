#include <YSI_Coding\y_hooks>

new PlayerText:ErroMensagem[MAX_PLAYERS][5]; 
new bool:ErroLoginStt[MAX_PLAYERS];
new TempoErro[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    if(ErroLoginStt[playerid] == true){
        KillTimer(TempoErro[playerid]);
        ErroLoginStt[playerid] = false;
    }
    for(new i=0; i < 5; i++){
        ErroMensagem[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarMensagemLogin(playerid)
{
    ErroMensagem[playerid][0] = CreatePlayerTextDraw(playerid, 10.761337, 219.750015, "box");
    PlayerTextDrawLetterSize(playerid, ErroMensagem[playerid][0], 0.000000, 2.128843);
    PlayerTextDrawTextSize(playerid, ErroMensagem[playerid][0], 145.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ErroMensagem[playerid][0], 1);
    PlayerTextDrawColor(playerid, ErroMensagem[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, ErroMensagem[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, ErroMensagem[playerid][0], 62);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ErroMensagem[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ErroMensagem[playerid][0], 255);
    PlayerTextDrawFont(playerid, ErroMensagem[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ErroMensagem[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][0], 0);

    ErroMensagem[playerid][1] = CreatePlayerTextDraw(playerid, 10.761337, 219.750015, "box");
    PlayerTextDrawLetterSize(playerid, ErroMensagem[playerid][1], 0.000000, 2.128843);
    PlayerTextDrawTextSize(playerid, ErroMensagem[playerid][1], 10.550046, 0.000000);
    PlayerTextDrawAlignment(playerid, ErroMensagem[playerid][1], 1);
    PlayerTextDrawColor(playerid, ErroMensagem[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, ErroMensagem[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, ErroMensagem[playerid][1], 26);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ErroMensagem[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ErroMensagem[playerid][1], 255);
    PlayerTextDrawFont(playerid, ErroMensagem[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ErroMensagem[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][1], 0);

    ErroMensagem[playerid][2] = CreatePlayerTextDraw(playerid, 77.017227, 222.933471, "Sua_senha_esta_invalida");
    PlayerTextDrawLetterSize(playerid, ErroMensagem[playerid][2], 0.196192, 1.191665);
    PlayerTextDrawAlignment(playerid, ErroMensagem[playerid][2], 2);
    PlayerTextDrawColor(playerid, ErroMensagem[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, ErroMensagem[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ErroMensagem[playerid][2], 105);
    PlayerTextDrawFont(playerid, ErroMensagem[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ErroMensagem[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][2], 1);

    ErroMensagem[playerid][3] = CreatePlayerTextDraw(playerid, 10.366896, 242.399780, "box");
    PlayerTextDrawLetterSize(playerid, ErroMensagem[playerid][3], 0.000000, -0.354317);
    PlayerTextDrawTextSize(playerid, ErroMensagem[playerid][3], 144.899566, 0.000000);
    PlayerTextDrawAlignment(playerid, ErroMensagem[playerid][3], 1);
    PlayerTextDrawColor(playerid, ErroMensagem[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, ErroMensagem[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, ErroMensagem[playerid][3], -5963521);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ErroMensagem[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ErroMensagem[playerid][3], 255);
    PlayerTextDrawFont(playerid, ErroMensagem[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, ErroMensagem[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][3], 0);

    ErroMensagem[playerid][4] = CreatePlayerTextDraw(playerid, 10.366896, 242.399780, "box");
    PlayerTextDrawLetterSize(playerid, ErroMensagem[playerid][4], 0.000000, -0.354317);
    PlayerTextDrawTextSize(playerid, ErroMensagem[playerid][4], 144.899566, 0.000000);
    PlayerTextDrawAlignment(playerid, ErroMensagem[playerid][4], 1);
    PlayerTextDrawColor(playerid, ErroMensagem[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, ErroMensagem[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, ErroMensagem[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ErroMensagem[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ErroMensagem[playerid][4], 255);
    PlayerTextDrawFont(playerid, ErroMensagem[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, ErroMensagem[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, ErroMensagem[playerid][4], 0);

    for(new i=0; i < 5; i++){
        PlayerTextDrawShow(playerid, ErroMensagem[playerid][i]);
    }
    return 1;
}

function OcultarMensagemLogin(playerid)
{
    for(new i=0; i < 5; i++){
        PlayerTextDrawDestroy(playerid, ErroMensagem[playerid][i]);
        ErroMensagem[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    ErroLoginStt[playerid] = false;
    return 1;
}

stock MostrarMensagem(playerid, const mensagem[], tempo)
{
    if(ErroLoginStt[playerid] == true){
        KillTimer(TempoErro[playerid]);
        OcultarMensagemLogin(playerid);
    }
    ErroLoginStt[playerid] = true;
    MostrarMensagemLogin(playerid);
    PlayerTextDrawSetString(playerid, ErroMensagem[playerid][2], ConverterTexto(mensagem));

    new News,
        Retro
	;
	News = tempo/1000;
    Retro = News*10;
	if(News < 5) TempoErro[playerid] = SetTimerEx("TempoTirar", 200, false, "dff", playerid, 144.899566, float(Retro));
    else TempoErro[playerid] = SetTimerEx("TempoTirar", 200, false, "dff", playerid, 144.899566, float(News));
    return 1;
}

function TempoTirar(playerid, Float:valor, Float:tempo)
{
	if(valor <= 7.049463)
    {
        KillTimer(TempoErro[playerid]);
        OcultarMensagemLogin(playerid);
	    return 1;
	}
	valor -= tempo;
    if(valor <= 7.049463) valor = 7.049463;
    PlayerTextDrawTextSize(playerid, ErroMensagem[playerid][4], valor, 0.000000);
    PlayerTextDrawShow(playerid, ErroMensagem[playerid][4]);
	TempoErro[playerid] = SetTimerEx("TempoTirar", 200, false, "dff", playerid, valor, tempo);
	return 1;
}