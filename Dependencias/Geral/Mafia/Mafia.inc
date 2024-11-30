#include <YSI_Coding\y_hooks>

new CompraMafia,
    Checc;

new MaconhaUnd,
    CrackUnd,
    CocainaUnd,
    LsdUnd;

hook OnGameModeInit()
{
    CreateDynamicActor(28, 2313.2844,56.3396,26.4844,265.8852, 1, 100.0, 0, 0, -1, 120.0, -1, 0);
    CompraMafia = CreateDynamicCP(2445.4421,-1970.0737,13.5469, 1.0, 0, 0, -1, 20.0, -1);
    Checc = CreateDynamicCP(2314.3752,56.4010,26.4809, 1.0, 0, 0, -1, 20.0, -1);
    return 1;
}

Dialog:MafiaEntrega(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    switch(listitem)
    {
        case 0: Dialog_Show(playerid, PlantacaoFuncao, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", "Você realmente deseja vender suas drogas?", "Confirmar", "Fechar");
        case 1: Dialog_Show(playerid, ProducaoFuncaoCargo, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", "Você realmente deseja vender seus itens?", "Confirmar", "Fechar");
    }
    return 1;
}

Dialog:CompraMaconha(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Maconha] >= 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode comprar mais maconhas, você já tem 20");

    new Somazinha,
        PrecoX;
    if(Quantidade >= 20) Somazinha = Ponta(Jogador[playerid][Maconha], Quantidade, 20);
    else Somazinha = Quantidade;
    PrecoX = 25*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    if(Somazinha > MaconhaUnd) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ponto de tráfico não tem toda essa quantinha");

    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    MaconhaUnd -= Somazinha;
    Jogador[playerid][Maconha] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| TRÁFICO | Você comprou {FFA500}%d{FFFFFF} grama(s) de maconha por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:CompraCrack(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Crack] >= 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode comprar mais crack, você já tem 20");

    new Somazinha,
        PrecoX;
    if(Quantidade >= 20) Somazinha = Ponta(Jogador[playerid][Crack], Quantidade, 20);
    else Somazinha = Quantidade;
    PrecoX = 10*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    if(Somazinha > CrackUnd) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ponto de tráfico não tem toda essa quantinha");

    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    CrackUnd -= Somazinha;
    Jogador[playerid][Crack] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| TRÁFICO | Você comprou {FFA500}%d{FFFFFF} pedra(s) de crack por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:CompraCocaina(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Cocaina] >= 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode comprar mais cocaina, você já tem 20");

    new Somazinha,
        PrecoX;
    if(Quantidade >= 20) Somazinha = Ponta(Jogador[playerid][Cocaina], Quantidade, 20);
    else Somazinha = Quantidade;
    PrecoX = 85*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    if(Somazinha > CocainaUnd) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ponto de tráfico não tem toda essa quantinha");

    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    CocainaUnd -= Somazinha;
    Jogador[playerid][Cocaina] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| TRÁFICO | Você comprou {FFA500}%d{FFFFFF} grama(s) de cocaina por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:CompraLsd(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Lsd] >= 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode comprar mais lsd, você já tem 5");

    new Somazinha,
        PrecoX;
    if(Quantidade >= 5) Somazinha = Ponta(Jogador[playerid][Lsd], Quantidade, 5);
    else Somazinha = Quantidade;
    PrecoX = 5000*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    if(Somazinha > LsdUnd) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ponto de tráfico não tem toda essa quantinha");

    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    LsdUnd -= Somazinha;
    Jogador[playerid][Lsd] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| TRÁFICO | Você comprou {FFA500}%d{FFFFFF} grama(s) de lsd por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:CompraTrafico(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, CompraMaconha, DIALOG_STYLE_INPUT, "{FF0000}Maconha", "Quanto de maconha você deseja comprar?", "Comprar", "Fechar");
        case 1: Dialog_Show(playerid, CompraCrack, DIALOG_STYLE_INPUT, "{FF0000}Crack", "Quanto de crack você deseja comprar?", "Comprar", "Fechar");
        case 2: Dialog_Show(playerid, CompraCocaina, DIALOG_STYLE_INPUT, "{FF0000}Cocaina", "Quanto de cocaina você deseja comprar?", "Comprar", "Fechar");
        case 3: Dialog_Show(playerid, CompraLsd, DIALOG_STYLE_INPUT, "{FF0000}Lsd", "Quanto de lsd você deseja comprar?", "Comprar", "Fechar");
    }
    return 1;
}

Dialog:MafiaOpcao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new Dialog[300];
    switch(listitem)
    {
        case 0:
        {
            strcat(Dialog, "Opção\tEstoque\tPreço\n");
            strcatEx(Dialog, "Maconha\t{FFA500}%d\t{32CD32}R$25 Und\n", MaconhaUnd);
            strcatEx(Dialog, "Crack\t{FFA500}%d\t{32CD32}R$10 Und\n", CrackUnd);
            strcatEx(Dialog, "Cocaina\t{FFA500}%d\t{32CD32}R$85 Und\n", CocainaUnd);
            strcatEx(Dialog, "Lsd\t{FFA500}%d\t{32CD32}R$5.000 Und", LsdUnd);
            Dialog_Show(playerid, CompraTrafico, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Máfia", Dialog, "Comprar", "Fechar");
        }
        case 1:
        {
            strcat(Dialog, "Plantador de Maconha\n");
            strcat(Dialog, "Produtor da Máfia\n");
            Dialog_Show(playerid, MafiaEntrega, DIALOG_STYLE_TABLIST, "{FF0000}Máfia", Dialog, "Selecionar", "Fechar");
        }
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(checkpointid == CompraMafia)
    {
        if(strcmp(Jogador[playerid][Profissao], "Plantador de Maconha")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        new Dialog[300];
        strcat(Dialog, "Opção\tPreço\tOpcional\n");
        strcat(Dialog, "Sementes\t{32CD32}$200\n");
        strcat(Dialog, "Vasos\t{32CD32}$90\n"); 
        strcat(Dialog, "Adubos (Opcional)\t{32CD32}$250\t{00BFFF}Boost no Plantio\n");
        Dialog_Show(playerid, MenuPlantadorMafia, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Compra Máfia", Dialog, "Selecionar", "Fechar");
    }

    else if(checkpointid == Checc)
    {
        new Dialog[300];
        strcat(Dialog, "Opção\n");
        strcat(Dialog, "Comprar Drogas\n");
        strcat(Dialog, "Encomendas\n");
        Dialog_Show(playerid, MafiaOpcao, DIALOG_STYLE_TABLIST_HEADERS, "Máfia", Dialog, "Comprar", "Fechar");   
    }
    return 1;
}

CMD:boca(playerid)
{
    if(!IsMafia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    EnviarGps(playerid, 2314.3752,56.4010,26.4809); // Local Venda
    return 1;
}

CMD:traficante(playerid)
{
    if(!IsMafia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    NpcBoca(playerid);
    return 1;
}