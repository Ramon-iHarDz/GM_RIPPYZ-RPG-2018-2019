#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;

    // Abrir Painel
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 320.3855, -26.5148, 1.5781)) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
    if(strcmp(Jogador[playerid][Profissao], "Mecanico")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Atendimentos são feitos apenas a pé");

    new Dialog[2000];
    strcat(Dialog, "Cliente\tNecessidade\n");
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(JogadorM[i][Alistou] == false) continue;
        strcatEx(Dialog, "%s[%d]\tNenhum objetivo no momento\n", PegarNick(i), i);
    }
    Dialog_Show(playerid, SemFuncaoNo, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Clientes", Dialog, "Chamar", "Fechar");
    return 1;
}