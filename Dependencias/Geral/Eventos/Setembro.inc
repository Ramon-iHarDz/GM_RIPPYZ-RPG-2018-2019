#include <YSI_Coding\y_hooks>

new checkasetembro;
new bool:SetembroJogador[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    SetembroJogador[playerid] = false;
    return 1;
}

stock ConfigurarSetembro(playerid) 
{
    checkasetembro = CreateDynamicRectangle(2327.7485,2208.9714, 2167.0471,2167.5266, 2021, 0, -1);

    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 2021);
    SetPlayerPos(playerid, 2242.2200,2186.6379,103.8786);

    EventoEstado = 1;
    EventoID = 4;

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) %s %s criou um evento de 11 de Setembro ( /IrEvento )", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessageToAll(0xFF8C00FF, Mensagem);
    return 1;
}

function FinalizarSetembro()
{
    for(new i=0; i < MAX_PLAYERS; i++){
        if(SetembroJogador[i] == false) continue;
        RemoverSetembro(i);  
    }
    return 1;
}

function IniciarContagemSetembro(c)
{
    new Contd[20];
    format(Contd, sizeof(Contd), "~r~%d", c);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(SetembroJogador[i] == false) continue;
        GameTextForPlayer(i, Contd, 5000, 4);
        PlayerPlaySound(i, 1056, 0.0, 0.0, 0.0);
    }
    c--;
    SetTimerEx("IniciarContagemCorrida", 1000, false, "d", c);
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{
    if(areaid != checkasetembro) return 1;
    if(SetembroJogador[playerid] == false) return 1;
    RemoverSetembro(playerid);
    return 1;
}

stock RemoverSetembro(playerid)
{
    SetembroJogador[playerid] = false;
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerPos(playerid, 1176.6755,-1324.3308,14.0330);
    return 1;
}

stock ColocarSetembro(playerid)
{
    SetembroJogador[playerid] = true;
    ResetPlayerWeapons(playerid);
    SetPlayerHealth(playerid, 100.0);
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 2021);
    SetPlayerPos(playerid, 2242.2200,2186.6379,103.8786+random(5));
    return 1;
}