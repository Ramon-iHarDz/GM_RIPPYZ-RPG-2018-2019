#include <YSI_Coding\y_hooks>

enum PresoIndicacao
{
    bool:PedidoChegou,
    AdvogadoReqID,

    bool:PediuJa,
    TempoRev
};

enum AdvogadoIndicacao
{
    bool:EnviouReq,
    PresoReqID
};

new PresoReq[MAX_PLAYERS][PresoIndicacao];
new AdvogadoReq[MAX_PLAYERS][AdvogadoIndicacao];

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Advogados", -1, 253.4617,67.1255,1003.6406, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1300, 6, -1, 16.0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(PresoReq[playerid][PediuJa] == true)
    {
        KillTimer(PresoReq[playerid][TempoRev]);
        if(PresoReq[playerid][PedidoChegou] == true)
        {
            new i = PresoReq[playerid][AdvogadoReqID]; // ID do Advogado
            AdvogadoReq[i][EnviouReq] = false;
        }
    }

    if(AdvogadoReq[playerid][EnviouReq] == true)
    {
        new i = AdvogadoReq[playerid][PresoReqID]; // ID do Preso
        KillTimer(PresoReq[i][TempoRev]);  
        PresoReq[i][PedidoChegou] = false; 
        PresoReq[i][PediuJa] = false;
    }

    // Resetar variaveis
    new AdReset[AdvogadoIndicacao];
    AdvogadoReq[playerid] = AdReset;

    new PrReset[PresoIndicacao];
    PresoReq[playerid] = PrReset;
    return 1;
}

CMD:solicitar(playerid)
{
    if(Jogador[playerid][Preso] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está preso(a)");
    if(Jogador[playerid][CadeiaEstilo] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão para solicitar");
    if(PresoReq[playerid][PediuJa] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco antes de solicitar!");
    if(PresoReq[playerid][PedidoChegou] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já recebeu uma solicitação");
    if(Jogador[playerid][DinheiroBanco] < DinheiroPrisao(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente.");

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| PRESO | O(A) Jogador(a) %s[%d] está solicitando seu serviço", PegarNick(playerid), playerid);

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Advogado")) continue;
        SendClientMessage(i, 0xFFD700FF, Mensagem);
    }
    
    SendClientMessage(playerid, 0xFFA500FF, "| INFO | Seu pedido foi enviado, aguarde um(a) advogado(a)");
    PresoReq[playerid][PediuJa] = true;
    PresoReq[playerid][TempoRev] = SetTimerEx("ResetarPedido", 20000, false, "dd", 1, playerid);
    return 1;
}

CMD:soltarpreso(playerid, params[])
{
    if(strcmp(Jogador[playerid][Profissao], "Advogado")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!IsPlayerInRangeOfPoint(playerid, 6.0, 253.4617,67.1255,1003.6406) || GetPlayerInterior(playerid) != 6 || GetPlayerVirtualWorld(playerid) != 1300) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no departamento de policia");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /SoltarPreso [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não foi encontrado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está logado(a)");
    if(Jogador[id][Preso] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está preso(a)");
    if(Jogador[id][CadeiaEstilo] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode soltar esse jogador(a)");
    if(AdvogadoReq[playerid][EnviouReq] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já enviou uma solicitação, aguarde um pouco!");
    if(PresoReq[id][PedidoChegou] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Uma solicitação já foi enviada para esse(a) preso(a)");
    if(Jogador[id][DinheiroBanco] < DinheiroPrisao(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Preso(a) não tem dinheiro sucifiente no banco");

    // Preso
    PresoReq[id][PedidoChegou] = true;
    PresoReq[id][AdvogadoReqID] = playerid;

    // Advogado
    AdvogadoReq[playerid][EnviouReq] = true;
    AdvogadoReq[playerid][PresoReqID] = id;

    if(PresoReq[id][PediuJa] == true) KillTimer(PresoReq[id][TempoRev]); 
    PresoReq[id][TempoRev] = SetTimerEx("ResetarPedido", 10000, false, "dd", 2, id);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADVOGADO | O(A) Advogado(a) %s[%d] está solicitando sua retirada por $%s reais ( /SairPrisao ou /FicarPrisao )", PegarNick(playerid), playerid, DinheiroSeparar(DinheiroPrisao(id)));
    SendClientMessage(id, 0xFFA500FF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADVOGADO | Você enviou uma solicitação para %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);
    return 1;
}

function ResetarPedido(id, playerid)
{
    if(id == 1)
    {
        PresoReq[playerid][PediuJa] = false;
        SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você já pode solicitar novamente um(a) advogado(a)");
    }

    else if(id == 2)
    {
        new i = PresoReq[playerid][AdvogadoReqID]; // ID do Advogado
        PresoReq[playerid][PedidoChegou] = false; 
        PresoReq[playerid][PediuJa] = false;
        AdvogadoReq[i][EnviouReq] = false;

        SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você demorou muito para aceitar ou recusar!");  
        SendClientMessage(i, 0xFFFF00FF, "| AVISO | O(A) Preso(a) demorou para aceitar");
    }
    return 1;
}

CMD:advogados(playerid)
{
    new Dialog[2000];
    new bool:ANAN = false;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Advogado")) continue;

        if(!IsPlayerInRangeOfPoint(i, 40.0, 253.4617,67.1255,1003.6406)) strcatEx(Dialog, "%s[%d]\t{FE2E2E}Indisponível\n", PegarNick(i), i);
        else strcatEx(Dialog, "%s[%d]\t{32CD32}Disponível\n", PegarNick(i), i);

        ANAN = true;
    }
    if(ANAN == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há advogados(as)");
    Dialog_Show(playerid, ASDJKASJ, DIALOG_STYLE_MSGBOX, "{FF0000}Advogados", Dialog, "Fechar", "");
    return 1;
}

CMD:sairprisao(playerid)
{
    if(Jogador[playerid][Preso] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está preso(a)");
    if(Jogador[playerid][CadeiaEstilo] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão aceitar ou recusar");
    if(PresoReq[playerid][PedidoChegou] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não recebeu nenhuma solicitação");

    new id = PresoReq[playerid][AdvogadoReqID]; // ID do Advogado
    KillTimer(PresoReq[playerid][TempoRev]);
    PresoReq[playerid][PedidoChegou] = false; 
    PresoReq[playerid][PediuJa] = false;
    AdvogadoReq[id][EnviouReq] = false;

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADVOGADO | Você pagou $%s ao advogado(a) %s[%d] para sair da prisão", DinheiroSeparar(DinheiroPrisao(playerid)), PegarNick(id), id);
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADVOGADO | %s[%d] aceitou sua solicitação. Seu dinheiro foi depositado na conta bancária ( %s )", PegarNick(playerid), playerid, DinheiroSeparar(DinheiroPrisao(playerid)));
    SendClientMessage(id, 0xFFA500FF, Mensagem);

    Jogador[id][DinheiroBanco] += DinheiroPrisao(playerid);
    Jogador[playerid][DinheiroBanco] -= DinheiroPrisao(playerid);

    EnviarLogDinheiro(id, playerid, DinheiroPrisao(playerid), "Advogado Request");
    AtualizarSaldoBancario(id, Jogador[id][DinheiroBanco]);
    AtualizarSaldoBancario(playerid, Jogador[playerid][DinheiroBanco]);

    RemoverDaCadeia(playerid);
    Jogador[playerid][Preso] = 0;
    return 1;
}

CMD:ficarprisao(playerid)
{
    if(Jogador[playerid][Preso] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está preso(a)");
    if(Jogador[playerid][CadeiaEstilo] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão aceitar ou recusar");
    if(PresoReq[playerid][PedidoChegou] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não recebeu nenhuma solicitação");

    new id = PresoReq[playerid][AdvogadoReqID]; // ID do Advogado
    KillTimer(PresoReq[playerid][TempoRev]);
    PresoReq[playerid][PedidoChegou] = false; 
    PresoReq[playerid][PediuJa] = false;
    AdvogadoReq[id][EnviouReq] = false;
    new Mensagem[128];

    format(Mensagem, sizeof(Mensagem), "| ADVOGADO | Você recusou o pedido do(a) advogado(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADVOGADO | %s[%d] recusou sua solicitação", PegarNick(playerid), playerid);
    SendClientMessage(id, 0xFFA500FF, Mensagem);
    return 1;
}

CMD:presos(playerid)
{
    if(Jogador[playerid][Admin] < 2 && strcmp(Jogador[playerid][Profissao], "Advogado")) return 0;
    if(Jogador[playerid][Admin] < 2){
        if(!IsPlayerInRangeOfPoint(playerid, 6.0, 253.4617,67.1255,1003.6406) || GetPlayerInterior(playerid) != 6 || GetPlayerVirtualWorld(playerid) != 1300) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no departamento de policia");
    }
    MostrarPresos(playerid);
    return 1;
}

stock MostrarPresos(playerid)
{
    new Dialog[2000];
    strcat(Dialog, "Preso(a)\tPrisão\tTempo\tPreço\n");
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue; 
        if(Jogador[i][Preso] == 0) continue;
 
        if(Jogador[i][CadeiaEstilo] == 1) strcatEx(Dialog, "{FFFF00}%s[%d]\t{1E90FF}Municipal\t{FF4500}%s\t{32CD32}R$%s\n", PegarNick(i), i, SegundosParaMinutos(Jogador[i][Preso]), DinheiroSeparar(DinheiroPrisao(i)));
        else if(Jogador[i][CadeiaEstilo] == 0) strcatEx(Dialog, "{FFFF00}%s[%d]\t{FE2E2E}Admin\t{FF4500}%s\t{fc2c03}N/A\n", PegarNick(i), i, SegundosParaMinutos(Jogador[i][Preso]));
    }
    Dialog_Show(playerid, KSAJDA, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Presos", Dialog, "Fechar", "");
    return 1;
}

stock DinheiroPrisao(playerid)
{
    new ValorEstrela = (Jogador[playerid][Estrelas]*250);
    return ValorEstrela;
}