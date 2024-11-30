#include <YSI_Coding\y_hooks>

Dialog:ConfirmarCompraCarro(playerid, response, listitem, inputtext[])
{
    pConce[playerid][VendoCarros] = false;
    if(!response) return 1;
    new vehid = pConce[playerid][Atual],
        id = pConce[playerid][Lista];

    if(GetPVarInt(playerid, "ConceS") == 1){
        if(Jogador[playerid][Dinheiro] < AeroConceInfo[vehid][Valor]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro suficiente!");
    }else{
        if(Jogador[playerid][Dinheiro] < VeiculoConceInfo[vehid][Valor]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro suficiente!");
    }

    new bool:Espaco = false;
    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][MeuVeiculoModelo] == 0)
        {
            Espaco = true;
            new Antes,
                ValorAtual,
                ModddA;
            
            if(GetPVarInt(playerid, "ConceS") == 1) ModddA = AeroConceInfo[vehid][Modelo];
            else ModddA = VeiculoConceInfo[vehid][Modelo];

            if(GetPVarInt(playerid, "ConceS") == 1)
            {
                ValorAtual = AeroConceInfo[vehid][Valor];
                Antes = (AeroConceInfo[vehid][Valor] * 15) / 100;
            }
            else
            {
                ValorAtual = VeiculoConceInfo[vehid][Valor];
                Antes = (VeiculoConceInfo[vehid][Valor] * 15) / 100; 
            }

            new ffd = ValorAtual;
            new Revenda = ffd-=Antes,
                Sql[400],
                PlacaGeradaH[90];

            if(VeiculoConceInfo[vehid][Modelo] == 481 || VeiculoConceInfo[vehid][Modelo] == 481 || VeiculoConceInfo[vehid][Modelo] == 509 || GetPVarInt(playerid, "ConceS") == 1) format(PlacaGeradaH, 90, "N/A");
            else format(PlacaGeradaH, 90, GerarPlaca());

            strcat(Sql, "INSERT INTO `veiculos` (`Nome`, `Preco`, `Modelo`, `Slot`, `Cor1`, `Cor2`, `PosX`, `PosY`, `PosZ`, `PosA`, `Placa`, `Preso`, `Gasolina`, `Vida`) VALUES ");
            strcatEx(Sql, "('%s', %d, %d, %d, %d, %d, %f, %f, %f, %f, '%s', '*', %f, %f)", EscapeString(PegarNick(playerid)), Revenda, ModddA, i, 1, 1, ConceLocal[id][VeiculoCX], ConceLocal[id][VeiculoCY], ConceLocal[id][VeiculoCZ], ConceLocal[id][VeiculoCA], PlacaGeradaH, 60.0, 1000);
            mysql_query(IDConexao, Sql, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao comprar o veículo!");

            Jogador[playerid][Dinheiro] -= ValorAtual;

            format(pVeiculo[playerid][i][Placa], 90, PlacaGeradaH);
            format(pVeiculo[playerid][i][Apreendido], 90, "*");
            pVeiculo[playerid][i][vPosX] = ConceLocal[id][VeiculoCX];
            pVeiculo[playerid][i][vPosY] = ConceLocal[id][VeiculoCY];
            pVeiculo[playerid][i][vPosZ] = ConceLocal[id][VeiculoCZ];
            pVeiculo[playerid][i][vPosA] = ConceLocal[id][VeiculoCA];
            pVeiculo[playerid][i][Cor1Veh] = 1;
            pVeiculo[playerid][i][Cor2Veh] = 1;
            pVeiculo[playerid][i][MeuVeiculoModelo] = ModddA;
            pVeiculo[playerid][i][Preco] = Revenda;
            pVeiculo[playerid][i][GasolinaEx] = 60.0;
            pVeiculo[playerid][i][vVida] = 1000;

            new Dialog[800];
            strcat(Dialog, "\t\t{00FF00}Concessionaria{FFFFFF}\n");
            strcat(Dialog, "{FFFFFF}Informações da compra\n");
            strcatEx(Dialog, "{FFFFFF}Modelo: {00BFFF}%s\n", GetVehicleNameByModel(ModddA));
            strcatEx(Dialog, "{FFFFFF}Placa: {00BFFF}%s\n", PlacaGeradaH);
            strcatEx(Dialog, "{FFFFFF}Preço: {00FF00}$%s\n", DinheiroSeparar(ValorAtual));
            strcatEx(Dialog, "{FFFFFF}Revenda: {FFFF00}$%s\n", DinheiroSeparar(Revenda));
            strcat(Dialog, " \n");
            strcatEx(Dialog, "{FFFFFF}Seu veículo foi colocado na vaga {FFFF00}%d\n", i);
            strcat(Dialog, "{FFFFFF}Utilize {00BFFF}/garagem{FFFFFF} para conectar seu veículo\n\n");
            strcat(Dialog, "{FFFFFF}Obs: {00BFFF}Ao vender o veículo você perderá 15% do valor do mesmo");
            Dialog_Show(playerid, NaoPrecisaPosCompra, DIALOG_STYLE_MSGBOX, "{FF0000}Compra", Dialog, "Fechar", "");
            break;
        }

        if(i == 2){
            if(Jogador[playerid][Vip] < gettime()){
                break;
            }
        }
    }

    if(Espaco == false){
        SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem mais espaços para veículos!");
    }
    return 1;
}

stock VagaGaragem(playerid)
{
    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0) continue;
        return true;
    }
    return false;
}

stock VagaSlotGaragem(playerid)
{
    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0) continue;
        return i;
    }
    return -1;  
}