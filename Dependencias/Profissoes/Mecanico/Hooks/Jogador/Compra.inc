#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES){
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, 326.5619, -53.5201, 1.5268)) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        new Dialog[228];
        strcat(Dialog, "Item\tPreço\n");
        strcat(Dialog, "Compra de Som\t{32CD32}$3.600\n");
        strcat(Dialog, "Compra de Tranca\t{32CD32}$2.400");
        Dialog_Show(playerid, CompraMec, DIALOG_STYLE_TABLIST_HEADERS, "Mecânica", Dialog, "Selecionar", "Fechar");
    }
    return 1;
}

Dialog:CompraMec(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new Dialog[700];
            for(new i=0; i < MAX_SLOT_VEH; i++)
            {
                if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0)
                {
                    if(pVeiculo[playerid][i][VehConectado] == true) strcatEx(Dialog, "%d.\t%s\t{00FF00}Conectado\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
                    else strcatEx(Dialog, "%d.\t%s\t{FF0000}Deconectado\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
                }
                else strcatEx(Dialog, "%d.\t{FF0000}Nenhum Veículo\t{00FF00}N/A\n", i); 
            }
            Dialog_Show(playerid, ComprarSom, DIALOG_STYLE_TABLIST, "{FF0000}Mecânica", Dialog, "Selecionar", "Fechar");
        }
        case 1:
        {
            new Dialog[700];
            for(new i=0; i < MAX_SLOT_VEH; i++)
            {
                if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0)
                {
                    if(pVeiculo[playerid][i][VehConectado] == true) strcatEx(Dialog, "%d.\t%s\t{00FF00}Conectado\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
                    else strcatEx(Dialog, "%d.\t%s\t{FF0000}Deconectado\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
                }
                else strcatEx(Dialog, "%d.\t{FF0000}Nenhum Veículo\t{00FF00}N/A\n", i); 
            }
            Dialog_Show(playerid, ComprarTranca, DIALOG_STYLE_TABLIST, "{FF0000}Mecânica", Dialog, "Selecionar", "Fechar");    
        }
    }
    return 1;
}

Dialog:ComprarSom(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = listitem;
    if(pVeiculo[playerid][id][MeuVeiculoModelo] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há nenhum veículo nesse slot");
    if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Veículo não conectado!");
    if(pVeiculo[playerid][id][TemSom] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse veículo já possui som");
    if(Jogador[playerid][Dinheiro] < 3600) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui toda essa quantia em dinheiro");

    new Float:EucPos[3],
        Float:VehcPos[3]
    ;
    GetVehiclePos(pVeiculo[playerid][id][MeuVeiculoID], VehcPos[0], VehcPos[1], VehcPos[2]);
    GetPlayerPos(playerid, EucPos[0], EucPos[1], EucPos[2]);
    new distancia = GetDistanceBetweenPoints(VehcPos[0], VehcPos[1], VehcPos[2], EucPos[0], EucPos[1], EucPos[2]);
    if(distancia > 60.0) return SendClientMessage(playerid, 0xFF4500FF, "| MECÂNICA | Traga seu veículo para mais perto da mecânica");
    Jogador[playerid][Dinheiro] -= 3600;
    pVeiculo[playerid][id][TemSom] = true;
    SendClientMessage(playerid, -1, "| MECÂNICA | Você comprou o equipamento de som para seu veículo por {32CD32}$3.600");
    return 1;
}

Dialog:ComprarTranca(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = listitem;
    if(pVeiculo[playerid][id][MeuVeiculoModelo] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há nenhum veículo nesse slot");
    if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Veículo não conectado!");
    if(pVeiculo[playerid][id][TemTranca] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse veículo já possui tranca");
    if(Jogador[playerid][Dinheiro] < 2400) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui toda essa quantia em dinheiro");

    new Float:EucPos[3],
        Float:VehcPos[3]
    ;
    GetVehiclePos(pVeiculo[playerid][id][MeuVeiculoID], VehcPos[0], VehcPos[1], VehcPos[2]);
    GetPlayerPos(playerid, EucPos[0], EucPos[1], EucPos[2]);
    new distancia = GetDistanceBetweenPoints(VehcPos[0], VehcPos[1], VehcPos[2], EucPos[0], EucPos[1], EucPos[2]);
    if(distancia > 60.0) return SendClientMessage(playerid, 0xFF4500FF, "| MECÂNICA | Traga seu veículo para mais perto da mecânica");
    Jogador[playerid][Dinheiro] -= 2400;
    pVeiculo[playerid][id][TemTranca] = true;
    SendClientMessage(playerid, -1, "| MECÂNICA | Você comprou uma tranca para seu veículo por {32CD32}$2.400");
    return 1;
}