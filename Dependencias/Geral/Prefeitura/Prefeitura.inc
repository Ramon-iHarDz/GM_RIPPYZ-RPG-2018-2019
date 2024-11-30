#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    // CreateDynamicActor(17, , 1, 100.0, 1303, 3, -1, 50.0);
    CreateDynamic3DTextLabel("{00BFFF}Estrelas\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para interagir", -1, -64.9506,9.6362,1003.3881, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 3, 1303, 3, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(newkeys != KEY_YES) return 1;
    if(GetPlayerVirtualWorld(playerid) != 1303 || GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -64.9506,9.6362,1003.3881))
    {
        if(Jogador[playerid][Estrelas] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está procurado(a)");
        new Dialog[1500],
            precoss = 0
        ;
        new cc = 1;
        for(new i=0; i < Jogador[playerid][Estrelas]; i++) 
        {
            precoss = 400*cc;
            cc++;
            strcatEx(Dialog, "{FFFFFF}%d\t{32CD32}%s\n", i+1, DinheiroSeparar(precoss));
            if(i >= 49) break;
        }
        Dialog_Show(playerid, EstrelasPrefeitura, DIALOG_STYLE_TABLIST, "{FF0000}Estrelas", Dialog, "Pagar", "Fechar");
    }
    return 1;
}