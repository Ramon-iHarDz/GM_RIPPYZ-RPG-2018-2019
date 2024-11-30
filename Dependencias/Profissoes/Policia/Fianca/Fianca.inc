#include <YSI_Coding\y_hooks>

new Fancic;
hook OnGameModeInit()
{
    Fancic = CreateDynamicCP(249.2837,67.9806,1003.6406, 1.0, 1300, 6, -1, 16.0, -1);
    return 1;
}

Dialog:CadeiaSoltar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou um ID inválido");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][Preso] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está preso(a)");
    if(Jogador[id][CadeiaEstilo] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não pode pagar fianças desse(a) jogador(a)");
    if(Jogador[playerid][Dinheiro] < DinheiroPrisao(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");

    Jogador[playerid][Dinheiro] -= DinheiroPrisao(id);
    EnviarLogDinheiro(playerid, id, DinheiroPrisao(playerid), "Fiança Request");

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| FIANÇA | Você pagou $%s para soltar %s[%d]", DinheiroSeparar(DinheiroPrisao(id)), PegarNick(id), id);
    SendClientMessage(playerid, 0x1E90FFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| FIANÇA | %s[%d] pagou para retirar você da prisão", PegarNick(playerid), playerid);
    SendClientMessage(id, 0x1E90FFFF, Mensagem);

    RemoverDaCadeia(id);
    Jogador[id][Preso] = 0;
    return 1;
}

Dialog:FiancaMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, CadeiaSoltar, DIALOG_STYLE_INPUT, "{FF0000}Fiança", "Coloque abaixo o ID do preso(a)", "Pagar", "Fechar");
        case 1: MostrarPresos(playerid);
        case 2: MostrarProcurados(playerid);
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != Fancic) return 1;

    new Dialog[128];
    strcat(Dialog, "Pagar Fiança\n");
    strcat(Dialog, "Lista de Presos\n");
    strcat(Dialog, "{FF0000}Lista de Procurados");
    Dialog_Show(playerid, FiancaMenu, DIALOG_STYLE_TABLIST, "{FF0000}Departamento de Polícia", Dialog, "Selecionar", "Fechar");
    return 1;
}