#include <YSI_Coding\y_hooks>

Dialog:BancoNomeTransferencia(playerid, response, listitem, inputtext[])
{ 
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    PlayerTextDrawSetString(playerid, BancoTransferencia[playerid][7], inputtext);
    SetPVarString(playerid, "UsuarioBancoTrans", inputtext); 
    return 0;
}

Dialog:BancoValorTransferencia(playerid, response, listitem, inputtext[])
{
    if(!response) return 1; 
    if(isnull(inputtext)) return 1;
    if(!ApenasNumeros(inputtext)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Valor Inválido");
    new Valor;
    sscanf(inputtext, "d", Valor);
    if(Valor > 500000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você só pode transferir até R$500.000");
    if(Valor < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode colocar esse valor");
    PlayerTextDrawSetString(playerid, BancoTransferencia[playerid][8], DinheiroSeparar(Valor));
    SetPVarInt(playerid, "ValorTransferencia", Valor);
    return 0;
}


Dialog:SaqueDialog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(!ApenasNumeros(inputtext)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Valor Inválido");
    new Valor;
    sscanf(inputtext, "d", Valor);
    if(Valor > 2000000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você só pode sacar até R$2.000.00");
    if(Valor < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode colocar esse valor");
    PlayerTextDrawSetString(playerid, SaqueBanco[playerid][4], DinheiroSeparar(Valor));
    SetPVarInt(playerid, "ValorSaque", Valor);
    return 0;
}


Dialog:DepositoDialog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(!ApenasNumeros(inputtext)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Valor Inválido");
    new Valor;
    sscanf(inputtext, "d", Valor);
    if(Valor > 2000000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você só pode depositar até R$2.000.00 por vez");
    if(Valor < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode colocar esse valor");
    PlayerTextDrawSetString(playerid, DepositoBanco[playerid][4], DinheiroSeparar(Valor));
    SetPVarInt(playerid, "ValorDeposito", Valor);
    return 0;
}