Dialog:MenuPlantadorMafia(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        // Sementes
        case 0: Dialog_Show(playerid, ComprasSementes, DIALOG_STYLE_INPUT, "{FF0000}Mafia", "Coloque abaixo a quantidade de sementes que deseja comprar", "Comprar", "Fechar");

        // Vasos
        case 1: Dialog_Show(playerid, ComprasVasos, DIALOG_STYLE_INPUT, "{FF0000}Mafia", "Coloque abaixo a quantidade de vasos que deseja comprar", "Comprar", "Fechar");

        // Adubos
        case 2: Dialog_Show(playerid, ComprasAdubos, DIALOG_STYLE_INPUT, "{FF0000}Mafia", "Coloque abaixo a quantidade de vasos que deseja comprar", "Comprar", "Fechar");
    }
    return 0;
}

Dialog:ComprasSementes(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Sementes] >= 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de sementes ( 10 )");
    
    new Somazinha,
        PrecoX;

    if(Quantidade >= 10) Somazinha = Ponta(Jogador[playerid][Sementes], Quantidade, 10);
    else Somazinha = Quantidade;
    PrecoX = 200*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    Jogador[playerid][Sementes] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| MAFIA | Você comprou {00BFFF}%d{FFFFFF} semente(s) por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 0;
}

Dialog:ComprasVasos(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Vasos] >= 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de vasos ( 10 )");
    
    new Somazinha,
        PrecoX;

    if(Quantidade >= 10) Somazinha = Ponta(Jogador[playerid][Vasos], Quantidade, 10);
    else Somazinha = Quantidade;
    PrecoX = 90*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    Jogador[playerid][Vasos] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| MAFIA | Você comprou {00BFFF}%d{FFFFFF} vaso(s) por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 0;
}

Dialog:ComprasAdubos(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Adubos] >= 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de Adubos ( 5 )");
    
    new Somazinha,
        PrecoX;

    if(Quantidade >= 5) Somazinha = Ponta(Jogador[playerid][Adubos], Quantidade, 5);
    else Somazinha = Quantidade;
    PrecoX = 250*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    Jogador[playerid][Adubos] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| MAFIA | Você comprou {00BFFF}%d{FFFFFF} Adubos(s) por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 0;
}