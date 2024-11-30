#include <YSI_Coding\y_hooks>

new cilindroccc;
hook OnGameModeInit()
{
    new DASDASDASDZa[9];
    DASDASDASDZa[0] = CreateDynamicObject(3626, 2750.3593, -2552.0480, 14.1490, 0.0000, 0.0000, 0.0000, -1, 0, -1, 90.0, 90.0, -1); //dckwrkhut
    DASDASDASDZa[1] = CreateDynamicObject(1348, 2753.6313, -2554.1350, 13.3283, 0.0000, 0.0000, 0.0000, -1, 0, -1, 90.0, 90.0, -1); //CJ_O2Tanks
    DASDASDASDZa[2] = CreateDynamicObject(14699, 2752.7204, -2554.2556, 13.9215, 0.0000, 0.0000, 0.0000, -1, 0, -1, 90.0, 90.0, -1); //Int_tat_lights
    DASDASDASDZa[3] = CreateDynamicObject(1348, 2751.9199, -2554.1350, 13.3283, 0.0000, 0.0000, 0.0000, -1, 0, -1, 90.0, 90.0, -1); //CJ_O2Tanks
    DASDASDASDZa[4] = CreateDynamicObject(1420, 2755.2351, -2550.4721, 12.6206, 0.0000, 0.0000, -91.4000, -1, 0, -1, 90.0, 90.0, -1); //DYN_AIRCON
    DASDASDASDZa[5] = CreateDynamicObject(1806, 2754.2373, -2552.4296, 12.9176, 0.0000, 0.0000, 90.5000, -1, 0, -1, 90.0, 90.0, -1); //MED_OFFICE_CHAIR
    DASDASDASDZa[6] = CreateDynamicObject(1623, 2754.7399, -2550.7141, 14.9799, 0.0000, 0.0000, 0.0000, -1, 0, -1, 90.0, 90.0, -1); //nt_aircon3_01
    DASDASDASDZa[7] = CreateDynamicObject(2185, 2753.2626, -2551.6660, 12.9189, 0.0000, 0.0000, -89.2999, -1, 0, -1, 90.0, 90.0, -1); //MED_OFFICE6_DESK_1
    DASDASDASDZa[8] = CreateDynamicObject(1808, 2753.4592, -2550.1401, 12.7929, 0.0000, 0.0000, -1.7999, -1, 0, -1, 90.0, 90.0, -1); //CJ_WATERCOOLER2
    cilindroccc = CreateDynamicCP(2752.1509,-2552.5562,13.9332, 1.0, 0, 0, -1, 10.0, -1);
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != cilindroccc) return 1;
    if(strcmp(Jogador[playerid][Profissao], "Mergulhador")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    Dialog_Show(playerid, CilindroCompra, DIALOG_STYLE_INPUT, "{FF0000}Cilindro", "Coloque abaixo a quantidade de cilindros que deseja\nCada unidade custa $1.000", "Comprar", "Fechar");
    return 1;
}

Dialog:CilindroCompra(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Cilindro] >= 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de Cilindros ( 3 )");
    
    new Somazinha,
        PrecoX;

    if(Quantidade >= 3) Somazinha = Ponta(Jogador[playerid][Cilindro], Quantidade, 3);
    else Somazinha = Quantidade;
    PrecoX = 1000*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    Jogador[playerid][Cilindro] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| DOCA | Você comprou {00BFFF}%d{FFFFFF} Cilindro(s) por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}