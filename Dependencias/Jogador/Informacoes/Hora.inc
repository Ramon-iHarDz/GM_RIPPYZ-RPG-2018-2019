#include <YSI_Coding\y_hooks>

enum RelogioJogador
{
    TempoRelogio,
    bool:RelogioOn,
    HoraString[128],
    DataString[90]
};

new pHora[MAX_PLAYERS][RelogioJogador];

hook OnPlayerConnect(playerid)
{
    if(pHora[playerid][RelogioOn] == false){
        pHora[playerid][RelogioOn] = true;  
        pHora[playerid][TempoRelogio] = SetTimerEx("AtualizarHora", 1000, true, "d", playerid);
    }
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if(GetPVarInt(playerid, "Koappals") == 0){
        MostrarRelogio(playerid);
        SetPVarInt(playerid, "Koappals", 1);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pHora[playerid][RelogioOn] == true){
        KillTimer(pHora[playerid][TempoRelogio]);
        new Limpar[RelogioJogador];
        pHora[playerid] = Limpar;
    }

    for(new i=0; i < 2; i++){
        Relogio[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function AtualizarHora(playerid)
{
    new Ano, Mes, Dia,
        Horas, Minutos, Segundos;

    getdate(Ano, Mes, Dia);
    gettime(Horas, Minutos, Segundos);

    if(Jogador[playerid][Logado] == true)
    {
        if(GetPVarInt(playerid, "Koappals") == 0) return 1;
        if(TravarCodigo(playerid, "AtualizarHora", 1)) return 1;
        if(Jogador[playerid][SemStatus] == false){
            format(pHora[playerid][HoraString], 90, "%02d:%02d", Horas, Minutos);
            format(pHora[playerid][DataString], 128, "%02d_%s_%d", Dia, MesR(Mes), Ano); 
            PlayerTextDrawSetString(playerid, Relogio[playerid][0], pHora[playerid][DataString]);
            PlayerTextDrawSetString(playerid, Relogio[playerid][1], pHora[playerid][HoraString]);
        }
    }

    if(Horapers == false){
        if(Horas > 12 && Horas <= 23) SetPlayerTime(playerid, Horas+4, Minutos); 
        else SetPlayerTime(playerid, Horas, Minutos);
    }
    else SetPlayerTime(playerid, HorasSync, HorasSyncMic);
    return 1;
}

stock MostrarRelogio(playerid)
{
    Relogio[playerid][0] = CreatePlayerTextDraw(playerid, 502.475036, 4.416673, " ");
    PlayerTextDrawLetterSize(playerid, Relogio[playerid][0], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, Relogio[playerid][0], 1);
    PlayerTextDrawColor(playerid, Relogio[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, Relogio[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, Relogio[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, Relogio[playerid][0], 255);
    PlayerTextDrawFont(playerid, Relogio[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, Relogio[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, Relogio[playerid][0], 0);

    Relogio[playerid][1] = CreatePlayerTextDraw(playerid, 547.974914, 23.083330, " "); //Hora
    PlayerTextDrawLetterSize(playerid, Relogio[playerid][1], 0.589624, 1.716666);
    PlayerTextDrawAlignment(playerid, Relogio[playerid][1], 1);
    PlayerTextDrawColor(playerid, Relogio[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, Relogio[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Relogio[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, Relogio[playerid][1], 255);
    PlayerTextDrawFont(playerid, Relogio[playerid][1], 3);
    PlayerTextDrawSetProportional(playerid, Relogio[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, Relogio[playerid][1], 0);

    PlayerTextDrawShow(playerid, Relogio[playerid][0]);
    PlayerTextDrawShow(playerid, Relogio[playerid][1]);
    return 1;
}

stock OcultarRelogio(playerid)
{
    PlayerTextDrawDestroy(playerid, Relogio[playerid][0]);
    PlayerTextDrawDestroy(playerid, Relogio[playerid][1]);
    return 1;
}