#include <YSI_Coding\y_hooks>

new PickupEntrada[9999];
new PickupSaida[9999];

hook OnGameModeInit()
{
    new Float:Local[3];
    for(new i=0; i < sizeof(Pick); i++)
    {
        if(Pick[i][PickupIcon] > 0){
            Create3DTextLabel(Pick[i][MensagemPickup], 0xFFFFFFFF, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ], 40.0, 0, 0);
            PickupEntrada[i] = CreateDynamicPickup(Pick[i][PickupIcon], 1, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ], 0, 0, -1, 70.0);
        } 
        if(Pick[i][MapIcon] > 0) CreateDynamicMapIcon(Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ], Pick[i][MapIcon], -1, 0, 0, -1, 130.0, MAPICON_LOCAL);

        if(Pick[i][SaidaX] == 0.0 && Pick[i][SaidaX] == 0.0 && Pick[i][SaidaZ] == 0.0) continue;
        if(Pick[i][SaidaX] == Local[0] && Pick[i][SaidaY] == Local[1] && Pick[i][SaidaZ] == Local[2]) continue;
        PickupSaida[i] = CreateDynamicPickup(1318, 1, Pick[i][SaidaX], Pick[i][SaidaY], Pick[i][SaidaZ], Pick[i][VirtualWorld], Pick[i][Interior], -1, 40.0);
        Local[0] = Pick[i][SaidaX];
        Local[1] = Pick[i][SaidaY];
        Local[2] = Pick[i][SaidaZ];
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){
        if(cAC[playerid][Travado] == true) return 1;
        if(Jogador[playerid][uInterior] > 0) cmd_sair(playerid);
        else cmd_entrar(playerid); 
    }
    return 1;
}

CMD:entrar(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
    for(new i=0; i < sizeof(Pick); i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 1.8, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ])) continue;
        if(Pick[i][SaidaX] == 0.0 && Pick[i][SaidaY] == 0.0 && Pick[i][SaidaZ] == 0.0) continue;
        // if(pMorreu[playerid][EstaCaido] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está ferido(a)");
        TogglePlayerControllable(playerid, 0);
        SetPlayerVirtualWorld(playerid, Pick[i][VirtualWorld]);
        SetPlayerInterior(playerid, Pick[i][Interior]);
        SetPlayerPos(playerid, Pick[i][SaidaX], Pick[i][SaidaY], Pick[i][SaidaZ]);
        Jogador[playerid][uInterior] = Pick[i][LocalID];
        SetTimerEx("Destravar", 3000, false, "d", playerid);
        break;
    }
    return 1;
}

CMD:sair(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    for(new i=0; i < sizeof(Pick); i++)
    {
        if(Pick[i][LocalID] != Jogador[playerid][uInterior]) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 1.8, Pick[i][SaidaX], Pick[i][SaidaY], Pick[i][SaidaZ])) continue;
        if(GetPlayerVirtualWorld(playerid) != Pick[i][VirtualWorld]) break;
        TogglePlayerControllable(playerid, 0);  
        Jogador[playerid][uInterior] = 0;
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
        SetTimerEx("Destravar", 2000, false, "d", playerid);
    } 
    return 1;
}

stock PegarInteriorRegistro(playerid)
{
    new id;
    for(new i=0; i < sizeof(Pick); i++)
    {
        if(Pick[i][LocalID] != Jogador[playerid][uInterior]) continue;
        return i;
    }
    return 0;
}

//Função usada quando o jogador conecta
stock ForceSaida(playerid)
{
    for(new i=0; i < sizeof(Pick); i++)
    {
        if(Pick[i][LocalID] != Jogador[playerid][uInterior]) continue;
        Jogador[playerid][uInterior] = 0;
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]); 
    }
    return 1;
}