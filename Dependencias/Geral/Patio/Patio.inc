#include <YSI_Coding\y_hooks>

new portax;
hook OnGameModeInit(){
    // CreateDynamicActor(281, -1616.4994,678.6681,7.1875,359.7736, 1, 100.0, 0, 0, -1, 90.0, -1, 0);
    portax = CreateDynamicCP(-1616.4994,678.6681,7.1875, 1.0, 0, 0, -1, 20.0, -1);
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != portax) return 1;
    new Dialog[2000];
    strcat(Dialog, "Veículo\tPlaca\tStatus\tPreço\n");
    for(new i=0; i < MAX_SLOT_VEH; i++){
        if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0)
        {
            if(pVeiculo[playerid][i][Patio] > 0) strcatEx(Dialog, "%d. {FFFFFF}Veículo: {FF0000}%s\t{FF4500}%s\t{FFFF00}Apreendido\t{32CD32}R$%s\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]), pVeiculo[playerid][i][Placa], DinheiroSeparar(pVeiculo[playerid][i][Patio]));
            else strcatEx(Dialog, "%d. {FFFFFF}Veículo: {FF0000}%s\t{FF4500}%s\t{FF0000}Nenhuma Iregularidade\t{B22222}R$--\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]), pVeiculo[playerid][i][Placa]);    
        }
        else strcatEx(Dialog, "%d. {FFFFFF}Veículo: {FF0000}N/A\n", i);   
    }
    Dialog_Show(playerid, PatioDialog, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Pátio", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:PatioDialog(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    new id = listitem;
    if(pVeiculo[playerid][id][MeuVeiculoModelo] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há veículos nesse slot");
    if(pVeiculo[playerid][id][Patio] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não está apreendido no pátio");
    if(Jogador[playerid][Dinheiro] < pVeiculo[playerid][id][Patio]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
    
    Jogador[playerid][Dinheiro] -= pVeiculo[playerid][id][Patio];
    new Mensagem[168];
    format(Mensagem, sizeof(Mensagem), "| PÁTIO | Você pagou {32CD32}R$%s{FFFFFF} pela retirada do veículo do pátio", DinheiroSeparar(pVeiculo[playerid][id][Patio]));
    SendClientMessage(playerid, -1, Mensagem);

    format(Mensagem, sizeof(Mensagem), "UPDATE `veiculos` SET `Patio`=0, `PosX`=%f, `PosY`=%f, `PosZ`=%f, `PosA`=%f WHERE `Nome`='%s' AND `Slot`=%d", -1635.4442,664.5022,6.8496,270.6471, EscapeString(PegarNick(playerid)), id);
    mysql_query(IDConexao, Mensagem, false);

    pVeiculo[playerid][id][vPosX] = -1635.4442;
    pVeiculo[playerid][id][vPosY] = 664.5022;
    pVeiculo[playerid][id][vPosZ] = 6.8496;
    pVeiculo[playerid][id][vPosA] = 270.6471;
    pVeiculo[playerid][id][Patio] = 0;
    return 1;
}