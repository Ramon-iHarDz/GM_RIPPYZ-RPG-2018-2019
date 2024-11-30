#include <YSI_Coding\y_hooks>

Dialog:ConceComprar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new i = GetPVarInt(playerid, "KAKAKACONCE");
    if(strcmp(Concessionaria[i][ConceDono], "*")) return 1;
    new Query[128];
    format(Query, sizeof(Query), "UPDATE `concessionaria` SET `Dono`='%s', `Estoque`=25 WHERE `Numero`=%d", EscapeString(PegarNick(playerid)), i);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema na compra");

    Jogador[playerid][Dinheiro] -= Concessionaria[i][PrecoConce];

    format(Query, sizeof(Query), "| CONCESSIONÁRIA | O(A) Jogador(a) %s[%d] comprou uma concessionária de %s", PegarNick(playerid), playerid, PegarConcessionariaType(Concessionaria[i][TypeConce]));
    SendClientMessageToAll(0xDCDCDCFF, Query);

    format(Concessionaria[i][ConceDono], 30, PegarNick(playerid));
    Concessionaria[i][EstoqueConce] = 25;
    AtualizarConcessionaria(i); 
    return 1;
}

Dialog:ConfirmacaoConce(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "ConceID");
    if(Concessionaria[id][ModoConce] == 1) OcultarDrawY(playerid);
    else OcultarDrawConce(playerid);

    if(Concessionaria[id][EstoqueConce] < 1){
        if(strcmp(Concessionaria[id][ConceDono], "*")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Não há estoque nessa concessionária");
    }

    new i = VagasGaragem(playerid);
    if(i >= MAX_SLOT_VEH) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem mais vagas na garagem");
    if(i >= 3 && Jogador[playerid][Vip] < gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Sua garagem não tem espaço, adquira o VIP para liberar mais.");
    if(Jogador[playerid][Dinheiro] < ConceModelos[GetPVarInt(playerid, "ConcePos")][Valor]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro suficiente");
    i = VagaSlotGaragem(playerid);

    new ValorAtual,
        Antes,
        ffd,
        Revenda,
        Sql[400],
        PlacaGeradaH[30];
          
    ValorAtual = ConceModelos[GetPVarInt(playerid, "ConcePos")][Valor];
    Antes = (ConceModelos[GetPVarInt(playerid, "ConcePos")][Valor] * 15) / 100;  
    ffd = ValorAtual;   
    Revenda = ffd-=Antes;

    if(ConceModelos[GetPVarInt(playerid, "ConcePos")][Modelo] == 481 || ConceModelos[GetPVarInt(playerid, "ConcePos")][Modelo] == 509) format(PlacaGeradaH, 30, "N/A");
    else format(PlacaGeradaH, 30, GerarPlaca());

    strcat(Sql, "INSERT INTO `veiculos` (`Nome`, `Preco`, `Modelo`, `Slot`, `Cor1`, `Cor2`, `PosX`, `PosY`, `PosZ`, `PosA`, `Placa`, `Preso`, `Gasolina`, `Vida`) VALUES ");
    strcatEx(Sql, "('%s', %d, %d, %d, %d, %d, %f, %f, %f, %f, '%s', '*', %f, %f)", EscapeString(PegarNick(playerid)), Revenda, ConceModelos[GetPVarInt(playerid, "ConcePos")][Modelo], i, 1, 1, Concessionaria[id][vConceX], Concessionaria[id][vConceY], Concessionaria[id][vConceZ], Concessionaria[id][vConceA], PlacaGeradaH, 60.0, 1000);
    mysql_query(IDConexao, Sql, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao comprar o veículo");

    if(strcmp(Concessionaria[id][ConceDono], "*")){
        Concessionaria[id][EstoqueConce]--;
        format(Sql, sizeof(Sql), "UPDATE `concessionaria` SET `Estoque`=%d WHERE `Numero`=%d", Concessionaria[id][EstoqueConce], id);
        mysql_query(IDConexao, Sql, false);
    }

    if(Concessionaria[id][ModoConce] == 0) VeiculoOutConce(id, GetPVarInt(playerid, "ConcePos"));
    EnviarCofreConce(id, ConceModelos[GetPVarInt(playerid, "ConcePos")][Valor]);

    Jogador[playerid][Dinheiro] -= ConceModelos[GetPVarInt(playerid, "ConcePos")][Valor];

    format(pVeiculo[playerid][i][Placa], 30, PlacaGeradaH);
    format(pVeiculo[playerid][i][Apreendido], 30, "*");

    pVeiculo[playerid][i][vPosX] = Concessionaria[id][vConceX];
    pVeiculo[playerid][i][vPosY] = Concessionaria[id][vConceY];
    pVeiculo[playerid][i][vPosZ] = Concessionaria[id][vConceZ];
    pVeiculo[playerid][i][vPosA] = Concessionaria[id][vConceA];
    pVeiculo[playerid][i][Cor1Veh] = 1;
    pVeiculo[playerid][i][Cor2Veh] = 1;
    pVeiculo[playerid][i][MeuVeiculoModelo] = ConceModelos[GetPVarInt(playerid, "ConcePos")][Modelo];
    pVeiculo[playerid][i][Preco] = Revenda;
    pVeiculo[playerid][i][GasolinaEx] = 60.0;
    pVeiculo[playerid][i][vVida] = 1000;

    new Dialog[800];
    strcat(Dialog, "\t\t{00FF00}Concessionaria{FFFFFF}\n");
    strcat(Dialog, "{FFFFFF}Informações da compra\n");
    strcatEx(Dialog, "{FFFFFF}Modelo: {00BFFF}%s\n", GetVehicleNameByModel(ConceModelos[GetPVarInt(playerid, "ConcePos")][Modelo]));
    strcatEx(Dialog, "{FFFFFF}Placa: {00BFFF}%s\n", PlacaGeradaH);
    strcatEx(Dialog, "{FFFFFF}Preço: {00FF00}$%s\n", DinheiroSeparar(ValorAtual));
    strcatEx(Dialog, "{FFFFFF}Revenda: {FFFF00}$%s\n", DinheiroSeparar(Revenda));
    strcat(Dialog, " \n");
    strcatEx(Dialog, "{FFFFFF}Seu veículo foi colocado na vaga {FFFF00}%d\n", i);
    strcat(Dialog, "{FFFFFF}Utilize {00BFFF}/garagem{FFFFFF} para conectar seu veículo\n\n");
    strcat(Dialog, "{FFFFFF}Obs: {00BFFF}Ao vender o veículo você perderá 15% do valor do mesmo");
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_MSGBOX, "{FF0000}Compra", Dialog, "Fechar", "");
    return 1;
}

stock VagaGaragem(playerid)
{
    for(new i=0; i < MAX_SLOT_VEH; i++){
        if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0) continue;
        return true;
    }
    return false;
}

stock VagasGaragem(playerid){
    new qqt;
    for(new i=0; i < MAX_SLOT_VEH; i++){
        if(pVeiculo[playerid][i][MeuVeiculoModelo] < 1) continue;
        qqt++;
    }
    return qqt;  
}

stock VagaSlotGaragem(playerid)
{
    for(new i=0; i < MAX_SLOT_VEH; i++){
        if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0) continue;
        return i;
    }
    return -1;  
}