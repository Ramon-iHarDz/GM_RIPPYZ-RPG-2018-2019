#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicMapIcon(1664.4301,1471.1442,10.7813, 5, -1, 0, 0, -1, 120.0, MAPICON_LOCAL, -1);
    CreateDynamicMapIcon(1685.9163,-2238.2937,13.5469, 5, -1, 0, 0, -1, 120.0, MAPICON_LOCAL, -1);
    CreateDynamicMapIcon(-1421.6479,-287.6295,14.1484, 5, -1, 0, 0, -1, 120.0, MAPICON_LOCAL, -1);

    CreateDynamicPickup(1239, 1, 1664.4301,1471.1442,10.7813, 0, 0, -1, 40.0, -1);
    CreateDynamicPickup(1239, 1, 1685.9163,-2238.2937,13.5469, 0, 0, -1, 40.0, -1);
    CreateDynamicPickup(1239, 1, -1421.6479,-287.6295,14.1484, 0, 0, -1, 40.0, -1);

    CreateDynamic3DTextLabel("{00BFFF}Aeroporto - Las Venturas{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para visualizar as passagens", -1, 1664.4301,1471.1442,10.7813, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 30.0, -1);
    CreateDynamic3DTextLabel("{00BFFF}Aeroporto - Los Santos{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para visualizar as passagens", -1, 1685.9163,-2238.2937,13.5469, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 30.0, -1);
    CreateDynamic3DTextLabel("{00BFFF}Aeroporto - San Fierro{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para visualizar as passagens", -1, -1421.6479,-287.6295,14.1484, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 30.0, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, 1664.4301,1471.1442,10.7813) &&
    !IsPlayerInRangeOfPoint(playerid, 2.0, 1685.9163,-2238.2937,13.5469) &&
    !IsPlayerInRangeOfPoint(playerid, 2.0, -1421.6479,-287.6295,14.1484)) return 1;
    if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você foi barrado(a) pela Policia Federal");

    
    new Dialog[300];
    strcat(Dialog, "Local\tPreço\n");
    strcat(Dialog, "Las Venturas\t{32CD32}$15.000\n");
    strcat(Dialog, "Los Santos\t{32CD32}$15.000\n");
    strcat(Dialog, "San Fierro\t{32CD32}$15.000");
    Dialog_Show(playerid, ViajarDialog, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Aeroporto", Dialog, "Viajar", "Fechar");
    return 1;
}

Dialog:ViajarDialog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            if(IsPlayerInRangeOfPoint(playerid, 30.0, 1664.4301,1471.1442,10.7813)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está nesse aeroporto");
            if(Jogador[playerid][Dinheiro] < 15000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
            Jogador[playerid][Dinheiro] -= 15000;
            SetPlayerPos(playerid, 1664.4301,1471.1442,10.7813);
            SendClientMessage(playerid, -1, "| AEROPORTO | Você pagou {32CD32}$15.000{FFFFFF} para viajar até {00BFFF}Las Venturas");
        }
        case 1:
        {
            if(IsPlayerInRangeOfPoint(playerid, 30.0, 1685.9163,-2238.2937,13.5469)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está nesse aeroporto");
            if(Jogador[playerid][Dinheiro] < 15000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
            Jogador[playerid][Dinheiro] -= 15000;
            SetPlayerPos(playerid, 1685.9163,-2238.2937,13.5469);
            SendClientMessage(playerid, -1, "| AEROPORTO | Você pagou {32CD32}$15.000{FFFFFF} para viajar até {00BFFF}Los Santos");
        }
        case 2:
        {
            if(IsPlayerInRangeOfPoint(playerid, 30.0, -1421.6479,-287.6295,14.1484)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está nesse aeroporto");
            if(Jogador[playerid][Dinheiro] < 15000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
            Jogador[playerid][Dinheiro] -= 15000;
            SetPlayerPos(playerid, -1421.6479,-287.6295,14.1484);
            SendClientMessage(playerid, -1, "| AEROPORTO | Você pagou {32CD32}$15.000{FFFFFF} para viajar até {00BFFF}San Fierro");
        }
    }
    return 1;
}