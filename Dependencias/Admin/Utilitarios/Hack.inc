#include <YSI_Coding\y_hooks>

enum HackAdmin
{
    bool:WallHack,
    HackTempo  
};

enum HackJogador
{
    Text3D:WallHackTexto
};

new pHack[MAX_PLAYERS][MAX_PLAYERS][HackJogador];
new pHackAdmin[MAX_PLAYERS][HackAdmin];

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "HackAttAdmin") == 1) KillTimer(pHackAdmin[playerid][HackTempo]);
    new Olasd[HackJogador];
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        DestroyDynamic3DTextLabelEx(pHack[i][playerid][WallHackTexto]);
        DestroyDynamic3DTextLabelEx(pHack[playerid][i][WallHackTexto]);
        pHack[i][playerid] = Olasd;
        pHack[playerid][i] = Olasd;
    }
    new Kjah[HackAdmin];
    pHackAdmin[playerid] = Kjah;
    return 1;
}

hook OnPlayerConnect(playerid)
{
    if(IsPlayerNPC(playerid)) return 1;
    if(GetPVarInt(playerid, "HackAttAdmin") == 0)
    {
        SetPVarInt(playerid, "HackAttAdmin", 1);
        pHackAdmin[playerid][HackTempo] = SetTimerEx("AtualizarCheat", 2000, true, "d", playerid);
    }
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if(GetPVarInt(playerid, "HackAdmin") == 1) return 1;
    SetPVarInt(playerid, "HackAdmin", 1);
    AdicionarCheat(playerid);
    return 1;
}

function AtualizarCheat(playerid)
{
    if(TravarCodigo(playerid, "AdminCheatUpdate", 1)) return 1;
    new Enviar[168];
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(pHackAdmin[playerid][WallHack] == true)
        {
            format(Enviar, sizeof(Enviar), "%s[%d]{FFFFFF}\nDistância: {00BFFF}%d\n{FFFFFF}Tipo: {F4A460}%s\n{FFFFFF}Velocidade: {32CD32}%d\n{FFFFFF}Esc: {32CD32}%s", PegarNick(i), i, GetDistanceBetweenPlayers(playerid, i), PegarEstadoJogador(i), GetPlayerSpeed(i), IsPlayerPaused(i) ? ("Pausado") : ("Não Pausado"));
            UpdateDynamic3DTextLabelText(pHack[playerid][i][WallHackTexto], 0xFFA500FF, Enviar);
        }
    }
    return 1;
}

stock AdicionarCheat(playerid, bool:EAdmin = false)
{
    new Enviar[168];
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        format(Enviar, sizeof(Enviar), "%s[%d]{FFFFFF}\nDistância: {00BFFF}%d\n{FFFFFF}Tipo: {F4A460}%s\n{FFFFFF}Velocidade: {32CD32}%d\n{FFFFFF}Esc: {32CD32}%s", PegarNick(i), i, GetDistanceBetweenPlayers(playerid, i), PegarEstadoJogador(i), GetPlayerSpeed(i), IsPlayerPaused(i) ? ("Pausado") : ("Não Pausado"));
        if(EAdmin == false)
        {
            if(pHackAdmin[i][WallHack] == true)
            {
                pHack[i][playerid][WallHackTexto] = CreateDynamic3DTextLabel(Enviar, 0xFFA50050, 0.0, 0.0, -2.0, 600.0, playerid, INVALID_VEHICLE_ID, 0, 0, 0, i, 601.0, -1);   
            }
        }
        else
        {
            pHack[playerid][i][WallHackTexto] = CreateDynamic3DTextLabel(Enviar, 0xFFA50050, 0.0, 0.0, -2.0, 600.0, i, INVALID_VEHICLE_ID, 0, 0, 0, playerid, 601.0, -1);   
        }
    }
    return 1;
}

stock RemoverCheat(playerid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        DestroyDynamic3DTextLabelEx(pHack[playerid][i][WallHackTexto]);
    }
    return 1;
}

Dialog:AdminHackOpcao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            pHackAdmin[playerid][WallHack] = pHackAdmin[playerid][WallHack] ? (false) : (true);
            switch(pHackAdmin[playerid][WallHack])
            {
                case 0: RemoverCheat(playerid);
                case 1: AdicionarCheat(playerid, true);
            }
        }
    }
    return 1;
}

CMD:hack(playerid)
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new Dialog[90];
    strcatEx(Dialog, "WallHack: %s\n", pHackAdmin[playerid][WallHack] ? ("{32CD32}Sim") : ("{FF4500}Não"));
    Dialog_Show(playerid, AdminHackOpcao, DIALOG_STYLE_TABLIST, "{FF0000}Admin Cheat", Dialog, "Selecionar", "Fechar");
    return 1;
}