#include <YSI_Coding\y_hooks>

new Priaa;

hook OnGameModeInit()
{
    Priaa = CreateDynamicRectangle(1787, -1509.5, 2065, -1309.5, 0, 0, -1);
    CreateDynamicObject(19332, 1909.80737, -1407.45862, 40.00000,   0.00000, 0.00000, 0.00000, 0, 0, -1, 600.0, 600.0, -1);
    CreateDynamicObject(19334, 1867.11694, -1372.19983, 50.00000,   0.00000, 0.00000, 0.00000, 0, 0, -1, 600.0, 600.0, -1);
    CreateDynamicObject(19338, 1887.32312, -1444.02600, 75.00000,   0.00000, 0.00000, 0.00000, 0, 0, -1, 600.0, 600.0, -1);
    CreateDynamicObject(19335, 1971.08972, -1394.65344, 80.00000,   0.00000, 0.00000, 0.00000, 0, 0, -1, 600.0, 600.0, -1);
    CreateDynamicObject(19337, 1963.67407, -1459.28198, 85.00000,   0.00000, 0.00000, 0.00000, 0, 0, -1, 600.0, 600.0, -1);
    CreateDynamicMapIcon(1920.8453,-1404.2169,13.5703, 48, -1, 0, 0, -1, 99999.9, MAPICON_GLOBAL, -1);
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid != Priaa) return 1;
    MostrarTextoEvento(playerid);
    ResetPlayerWeapons(playerid);
    PlayAudioStreamForPlayer(playerid, "http://66.70.177.195:8048/stream");
    SetPVarInt(playerid, "NoEvento", 1);
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{
    if(areaid != Priaa) return 1;
    OcultarTextoEvento(playerid);
    SetPVarInt(playerid, "NoEvento", 0);
    StopAudioStreamForPlayer(playerid);
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
        new Float:adasda;
        GetPlayerHealth(playerid, adasda);
        SetPlayerHealth(playerid, adasda+amount);
    }
    return 1;
}

Dialog:EquiparEventoAcessorios(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            SetPlayerAttachedObject(playerid, 9, 19878, 1, 0.0680, -0.1459, 0.0020, -94.0999, 0.0000, -9.9999, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
            SendClientMessage(playerid, 0xFFA500FF, "| EVENTO | Você está usando o acessório de Skate");
        }
        case 1:
        {
            SetPlayerAttachedObject(playerid, 9, 11704, 2, 0.0740, 0.1019, -0.0080, 179.2000, 95.0000, 0.0000, 0.4340, 1.0000, 0.5180, 0xFFFFFFFF, 0xFFFFFFFF);
            SendClientMessage(playerid, 0xFFA500FF, "| EVENTO | Você está usando o acessório de Mascará do Capete");
        }
        case 2:
        {
            SetPlayerAttachedObject(playerid, 9, 19317, 1, 0.1299, -0.1049, -0.0120, -87.6999, 86.9999, 91.0999, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
            SendClientMessage(playerid, 0xFFA500FF, "| EVENTO | Você está usando o acessório de Guitarra");
        }
        case 3:
        {
            SetPlayerAttachedObject(playerid, 9, 18689, 1, -0.6029, -0.2179, -1.6760, 0.0000, 0.0000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
            SendClientMessage(playerid, 0xFFA500FF, "| EVENTO | Você está usando o acessório de Fogo");    
        }
        case 4:
        {
            RemovePlayerAttachedObject(playerid, 9);
            SendClientMessage(playerid, 0xFFA500FF, "| EVENTO | Você removeu os acessórios equipados");   
        }
    }
    return 1;
}

CMD:evento(playerid){
    if(Jogador[playerid][Admin] < 1 && Jogador[playerid][Vip] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    new Dialog[128];
    strcat(Dialog, "Skate\n");
    strcat(Dialog, "Mascará do Capeta\n");
    strcat(Dialog, "Guitarra\n");
    strcat(Dialog, "Fogo\n");
    strcat(Dialog, "{FF0000}Remover Acessório");
    Dialog_Show(playerid, EquiparEventoAcessorios, DIALOG_STYLE_TABLIST, "{FF0000}Evento [VIP]", Dialog, "Selecionar", "Fechar");
    return 1;
}