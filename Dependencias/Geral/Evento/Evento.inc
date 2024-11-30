#include <YSI_Coding\y_hooks>

new asdd;
new checkevento;

hook OnGameModeInit()
{
    asdd = CreateDynamicRectangle(1026.984375, 2690.015625, 1566.984375, 2951.015625, 0, 0, -1);
    CreateDynamicMapIcon(1268.5186,2793.4861,10.8203, 49, -1, 0, 0, -1, 99999.9, MAPICON_GLOBAL, -1);
    
    CreateDynamic3DTextLabel("Fernando", 0xFFFFFF60, 1168.8076,2735.1331,10.8375+0.5, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 11.0, -1, 0);
    CreateDynamicActor(171, 1168.8076,2735.1331,10.8375,355.5580, 1, 100.0, 0, 0, -1, 120.0, -1, 0);
    
    // Policias
    CreateDynamic3DTextLabel("Paulo", 0xFFFFFF60, 1432.2622,2821.0999,10.8203+0.5, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 11.0, -1, 0);
    CreateDynamicActor(163, 1432.2622,2821.0999,10.8203,274.2826, 1, 100.0, 0, 0, -1, 120.0, -1, 0);

    CreateDynamic3DTextLabel("Silva", 0xFFFFFF60, 1435.0840,2816.6172,10.8203+0.5, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 11.0, -1, 0);
    CreateDynamicActor(164, 1435.0840,2816.6172,10.8203,3.4374, 1, 100.0, 0, 0, -1, 120.0, -1, 0);

    CreateDynamic3DTextLabel("Mike", 0xFFFFFF60, 1495.7661,2809.9790,10.8203+0.5, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 11.0, -1, 0);
    CreateDynamicActor(165, 1495.7661,2809.9790,10.8203,115.6424, 1, 100.0, 0, 0, -1, 120.0, -1, 0);

    CreateDynamicActor(168, 1426.7954,2810.6572,10.8203,320.5037, 1, 100.0, 0, 0, -1, 120.0, -1, 0);
    CreateDynamicActor(172, 1232.6754,2754.1260,11.0516,68.1786, 1, 100.0, 0, 0, -1, 120.0, -1, 0);
    checkevento = CreateDynamicCP(1168.5885,2736.8445,10.8375, 1.0, 0, 0, -1, 15.0, -1);
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid != asdd) return 1;
    MostrarTextoEvento(playerid);
    if(IsPlayerInAnyVehicle(playerid)){
        SetVehiclePos(GetPlayerVehicleID(playerid), 1587.5992,2621.4907,10.6719);
    }
    ResetPlayerWeapons(playerid);
    PlayAudioStreamForPlayer(playerid, "http://66.70.177.195:8048/stream", 1135.0563,2790.1729,10.8203, 1200.0, 1);
    SetPVarInt(playerid, "NoEvento", 1);
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{
    if(areaid != asdd) return 1;
    OcultarTextoEvento(playerid);
    SetPVarInt(playerid, "NoEvento", 0);
    StopAudioStreamForPlayer(playerid);
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER){
        if(GetPVarInt(playerid, "NoEvento") == 1){
            SetVehiclePos(GetPlayerVehicleID(playerid), 1587.5992,2621.4907,10.6719);  
        } 
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != checkevento) return 1;
    if(Jogador[playerid][Admin] < 1 && Jogador[playerid][Vip] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    
    new Dialog[300];
    strcat(Dialog, "{FFFF00}~~~~Bebidas~~~~\n");
    strcat(Dialog, "- Cerveja\n");
    strcat(Dialog, "- Whisky\n");
    strcat(Dialog, "- Vinho\n");
    strcat(Dialog, "- Vodka\n");
    strcat(Dialog, "- Skol Beats\n");
    strcat(Dialog, "- Capirinha\n");
    strcat(Dialog, "- Licores\n");
    strcat(Dialog, "- Tequila\n");
    strcat(Dialog, "{FFFF00}~~~~Comidas~~~~\n");
    strcat(Dialog, "- Churrasco\n");
    strcat(Dialog, "- Coxinhas\n");
    strcat(Dialog, "- Quibes\n");
    strcat(Dialog, "- Esfirras\n");
    strcat(Dialog, "- Empanadas");
    Dialog_Show(playerid, ComidasMenuEvento, DIALOG_STYLE_TABLIST, "{FF0000}Área VIP", Dialog, "Pegar", "Fechar");
    return 1;
}

Dialog:ComidasMenuEvento(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 1..8: ComidaFesta(playerid, 2);
        case 10..14: ComidaFesta(playerid, 1);
    }
    return 1;
}

stock ComidaFesta(playerid, type)
{
    if(type == 1) ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
    else ApplyAnimation(playerid, "VENDING", "VEND_Drink_P", 3.0, 0, 0, 0, 0, 0);
    EnviarComida(playerid, type, 11.0); 
    return 1;
}

hook OnPlayerMochila(playerid, arma, bala, type)
{
    if(GetPVarInt(playerid, "NoEvento") == 0) return 1;
    switch(type)
    {
        case 1:
        {
            ResetPlayerWeapons(playerid);
            SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você não pode usar armas no evento");
        }
    }
    return 1;
}

hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
    if(damagedid == INVALID_PLAYER_ID) return 1;
    if(GetPVarInt(playerid, "NoEvento") == 1){
        TogglePlayerControllable(playerid, 0);
        SetTimerEx("Destravar", 3000, false, "d", playerid);
        SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você não pode fazer D.M");
    }
    return 1;
}