#include <YSI_Coding\y_hooks>

new ArenaCheckPoint;

hook OnGameModeInit()
{
    //
    CreateDynamicPickup(1238, 1, 2780.0898,-1814.0895,11.8438, 0, 0, -1, 128.0, -1, 0);
    CreateDynamic3DTextLabel("{00FA9A}Arenas\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para visualizar as opções", -1, 2780.0898,-1814.0895,11.8438, 70.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 70.0, -1, 0);
    CreateDynamicMapIcon(2780.0898,-1814.0895,11.8438, 16, -1, 0, 0, -1, 190.0, MAPICON_LOCAL, -1, 0);

    ArenaCheckPoint = CreateDynamicCP(2695.7234,-1704.7076,11.8438, 2.0, 0, 0, -1, 40.0, -1, 0);

    // Counter Load
    new id;
    for(new i=0; i < CounterServer; i++){
        id = random(sizeof(MapasCounter));
        format(pCounter[i][Mapa], 70, MapasCounter[id][MapaSelect]);
    }

    //Arena Load
    for(new i=0; i < ArenaServer; i++){
        strcat(pArena[i][ArenaDono], "*");
        strcat(pArena[i][SenhaArena], "*");
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pModo[playerid][Jogando] == true){
        if(pModo[playerid][ModoAtl] == 1) TirarJogadorCounter(playerid);
        else if(pModo[playerid][ModoAtl] == 2) TirarJogadorArena(playerid);
    }
    new Deletar[JogadorModos];
    pModo[playerid] = Deletar;
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(pModo[playerid][Jogando] == false) return 1;
    if(killerid == INVALID_PLAYER_ID){
        pModo[playerid][Acumulado] = 0;
        return 1;
    }
    if(pModo[killerid][ModoAtl] != pModo[playerid][ModoAtl]) return 1;
    if(pModo[killerid][Sala] != pModo[playerid][Sala]) return 1;
  
    new Mensagem[128];
    if(pModo[playerid][ModoAtl] > 0)
    {
        pModo[killerid][Acumulado]++;
        if(pModo[killerid][Acumulado] == 2) GameTextForPlayer(killerid, "~r~Double Kill", 3000, 4);
        else if(pModo[killerid][Acumulado] == 3) GameTextForPlayer(killerid, "~r~Triple Kill", 3000, 4);
        else if(pModo[killerid][Acumulado] >= 4) GameTextForPlayer(killerid, "~r~Chain Killer", 3000, 4);
        pModo[playerid][Acumulado] = 0;
    }
    

    //Counter - Reset
    if(pModo[playerid][ModoAtl] == 1)
    {
        format(Mensagem, sizeof(Mensagem), "| MORTE | %s[%d] morreu para %s[%d]", PegarNick(playerid), playerid, PegarNick(killerid), killerid);
        new NewKillFeedA[70];
        pModo[killerid][Kill]++;
        pModo[playerid][Morte]++;

        format(NewKillFeedA, sizeof(NewKillFeedA), "%d", pModo[killerid][Kill]);
        PlayerTextDrawSetString(killerid, CounterMenu[killerid][4], NewKillFeedA);
        format(NewKillFeedA, sizeof(NewKillFeedA), "%d", pModo[playerid][Morte]);
        PlayerTextDrawSetString(playerid, CounterMenu[playerid][5], NewKillFeedA);

        for(new i=0; i < MAX_PLAYERS; i++)
        {
            if(!IsPlayerConnected(i)) continue;
            if(pModo[i][Jogando] == false) continue;
            if(pModo[i][ModoAtl] != pModo[playerid][ModoAtl]) continue;
            if(pModo[i][Sala] != pModo[playerid][Sala]) continue;
            SendClientMessage(i, 0xC0C0C0FF, Mensagem);
        }
    }
                
    //Arena - Reset
    else if(pModo[playerid][ModoAtl] == 2)
    {
        Jogador[killerid][VitimasArena]++;
        Jogador[playerid][MortesArena]++;
        AtualizarVM(playerid);
        AtualizarVM(killerid);
    }
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if(pModo[playerid][Jogando] == false) return 1;
    if(pModo[playerid][ModoAtl] == 1){
        new id = pModo[playerid][Sala];
        if(pCounter[id][Tempo] < CounterTempo) RespawnarCounter(playerid);    
    }
    else if(pModo[playerid][ModoAtl] == 2) RespawnarArena(playerid); 
    return 1; 
}

CMD:sairarena(playerid){cmd_desistir(playerid); return 1;}
CMD:desistir(playerid)
{
    if(pModo[playerid][Jogando] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está em um modo!");
    if(pModo[playerid][ModoAtl] == 1) TirarJogadorCounter(playerid);
    else if(pModo[playerid][ModoAtl] == 2) TirarJogadorArena(playerid);
    pModo[playerid][Sala] = 0;
    pModo[playerid][ModoAtl] = 0;
    pModo[playerid][Jogando] = false;
    pModo[playerid][Acumulado] = 0; 
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != ArenaCheckPoint) return 1;
    if(Jogador[playerid][Level] < 70) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você precisa ter level 70 para acessar arena");
    if(pModo[playerid][TempoEntrar] > gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Aguarde um pouco antes de entrar ou criar uma sala");
    new Dialog[1000];
    strcat(Dialog, "Sala\tMapa\tJogadores\tStatus\n");
    for(new i=0; i < ArenaServer; i++)
    { 
        if(!strcmp(pArena[i][ArenaDono], "*")) strcatEx(Dialog, "%d\t{32CD32}N/A\t{FFA500}%d/20\t{FFFFFF}N/A\n", i+1, 0);
        else
        {
            if(strcmp(pArena[i][SenhaArena], "*")) strcatEx(Dialog, "%d\t{32CD32}%s\t{FFA500}%d/20\t{FF0000}Trancada\n", i+1, ArenasID[pArena[i][MapaID]], pArena[i][Jogadores]); 
            else strcatEx(Dialog, "%d\t{32CD32}%s\t{FFA500}%d/20\t{00FF00}Destrancada\n", i+1, ArenasID[pArena[i][MapaID]], pArena[i][Jogadores]); 
        }
    }
    Dialog_Show(playerid, ArenaDialog, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Arenas", Dialog, "Selecionar", "Fechar");
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, 2780.0898,-1814.0895,11.8438)) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(Jogador[playerid][Level] < 5) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você precisa ter level 5 para acessar o modo de jogo");
        if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está procurado(a)");
        new Dialog[400];
        strcat(Dialog, "Modos\tStatus\n");
        strcat(Dialog, "Counter War\t{32CD32}Aberto\n");
        strcat(Dialog, "Bandeira\t{32CD32}Bloqueado\n");
        strcat(Dialog, "Battle Royale\t{FF4500}Bloqueado");
        Dialog_Show(playerid, MenuModos, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Modos", Dialog, "Selecionar", "Fechar");
    }
    return 1;
}

Dialog:MenuModos(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[1000];
    switch(listitem)
    {
        case 0:
        {
            strcat(Dialog, "Arena\tJogadores\tTempo\tMapa\n");
            for(new i=0; i < CounterServer; i++){
                strcatEx(Dialog, "Arena: {00BFFF}%d\t{FF0000}%d\tTempo: {32CD32}%s\t{FF4500}%s\n", i+1, pCounter[i][Jogadores], SegundosParaMinutos(pCounter[i][Tempo]), pCounter[i][Mapa]);
            }
            Dialog_Show(playerid, CounterDialog, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Counter War", Dialog, "Selecionar", "Fechar");
        }
        /*case 1:
        {
            strcat(Dialog, "Sala\tJogadores\tPlacar\tStatus\n");
            for(new i=0; i < MAX_BANDEIRAS_SALA; i++){
                strcatEx(Dialog, "%d\t{00BFFF}%d\t{8B0000}%d{FFFFFF}/{00CED1}%d\t{FFA500}%s\n", i+1, Bandeira[i][Jogadores], Bandeira[i][PlacarVermelho], Bandeira[i][PlacarAzul], PegarBandeiraStatus(i));
            }
            Dialog_Show(playerid, BandeiraDialog, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Bandeira", Dialog, "Selecionar", "Fechar");  
        }*/ 
    }
    return 0;
}

hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart) 
{
    if(pModo[playerid][Jogando] == false) return 1;
    if(pModo[playerid][ModoAtl] != 1 && pModo[playerid][ModoAtl] != 2) return 1;
    PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0); 
    return 1;
}