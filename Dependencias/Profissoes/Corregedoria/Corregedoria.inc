
CMD:prenderpolicia(playerid, params[])
{
    if(strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    new id,
        tempoa,
        motivoa[70];
    if(sscanf(params, "dds[70]", id, tempoa, motivoa)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /PrenderPolicia [ID] [Tempo] [Motivo]");
    if(tempoa > 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode colocar mais de 20 minutos de prisão!");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se prender!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode prender um admin");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) policial");
    if(!IsPolicia(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse Jogador(a) não é um(a) policial");

    Jogador[id][uInterior] = Departamento(id);
    CatalogarPrisao(id, tempoa, motivoa, PegarNick(playerid), 0);

    new Mensagem[198];
    format(Mensagem, sizeof(Mensagem), "| CORREGEDORIA | O(A) Corregedor(a) %s[%d] prendeu o(a) policial %s[%d] por %d minuto(s) ( Motivo: %s )", PegarNick(playerid), playerid, PegarNick(id), id, tempoa, motivoa);
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Corregedoria") && Jogador[i][Admin] < 2) continue;
        SendClientMessage(i, 0x4682B4FF, Mensagem);
    }

    SendClientMessage(id, 0x4682B4FF, Mensagem);

    new TempoRemake = (tempoa * 60);
    Jogador[id][Preso] = TempoRemake;
    MostrarRelogioPrisao(id);
    ColocarNaCadeia(id);
    return 1;
}

CMD:motivoprisoes(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Corregedoria") && Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    new Dialog[400];
    strcat(Dialog, "{FF0000}Prisões{FFFFFF}\n");
    strcat(Dialog, "Andando com máfia - {CCCCCC}20 Minutos{FFFFFF}\n");
    strcat(Dialog, "Em local da máfia - {CCCCCC}20 Minutos{FFFFFF}\n");
    strcat(Dialog, "Multas Irregulares - {CCCCCC}10 Minutos{FFFFFF}\n");
    strcat(Dialog, "Procurar Irregular - {CCCCCC}20 Minutos{FFFFFF}\n");
    strcat(Dialog, "Death Match - {CCCCCC}15 Minutos");
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_MSGBOX, "{FF0000}Motivos e Prisões", Dialog, "Fechar", "");
    return 1;
}