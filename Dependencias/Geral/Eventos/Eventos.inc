new EventoEstado = 0,
    EventoID = 0;

CMD:criarevento(playerid)
{
    if(Jogador[playerid][Admin] < 4) return 0;
    if(EventoEstado > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Já existe um evento criado, aguarde!");
    if(GetPVarInt(playerid, "ConfigurandoCorridaGG") == 1) return ConfigurarCorrida(playerid);
    new Dialog[200];
    strcat(Dialog, "Derby\n");
    strcat(Dialog, "Among Us\n");
    strcat(Dialog, "Corrida\n");
    strcat(Dialog, "11 de Setembro\n");
    strcat(Dialog, "Jason");
    Dialog_Show(playerid, CriarEvento, DIALOG_STYLE_TABLIST, "{FF0000}Eventos", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:iniciarevento(playerid)
{
    if(Jogador[playerid][Admin] < 4) return 0;   
    if(EventoEstado == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nenhum evento foi criado");
    if(EventoEstado != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Evento já iniciado");
    if(EventoID == 1){
        EventoEstado = 2;
        SetTimerEx("IniciarContagemDerby", 1000, false, "d", 5);
    }
    else if(EventoID == 2){
        EventoEstado = 2;
        SetTimerEx("IniciarContagemAmong", 1000, false, "d", 5);
    }
    else if(EventoID == 3){
        EventoEstado = 2;
        SetTimerEx("IniciarContagemCorrida", 1000, false, "d", 5);    
    }
    else if(EventoID == 4){
        EventoEstado = 2;
        SetTimerEx("IniciarContagemSetembro", 1000, false, "d", 5);    
    }
    else if(EventoID == 5) IniciarJason();
    return 1;
}

CMD:finalizarevento(playerid)
{
    if(Jogador[playerid][Admin] < 4) return 0;   
    if(EventoEstado == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nenhum evento foi criado");
    if(EventoID == 1) ResetarDerby();
    else if(EventoID == 2) FinalizarPartida();
    else if(EventoID == 3) ResetarCorrida();
    else if(EventoID == 4) FinalizarSetembro();
    else if(EventoID == 5) FinalizarJason();

    EventoEstado = 0;
    EventoID = 0;
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) %s %s finalizou o evento", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessageToAll(0x1E90FFFF, Mensagem);
    return 1;
}

Dialog:CriarEvento(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(EventoEstado > 0) return 1;
    switch(listitem)
    {
        case 0:
        {
            new Mensagem[128];
            SetPlayerInterior(playerid, 15);
            SetPlayerVirtualWorld(playerid, 2020);
            SetPlayerPos(playerid, -1513.1956, 988.0545, 1037.3265);
            PrepararDerby();
            EventoEstado = 1;
            EventoID = 1;
            format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) %s %s criou um evento de Derby ( /IrEvento )", CargoAdmin(2, playerid), PegarNick(playerid));
            SendClientMessageToAll(0xFF8C00FF, Mensagem);
            
        }
        case 1: ConfigurarAmong(playerid);
        case 2: ConfigurarCorridaEvent(playerid); 
        case 3: ConfigurarSetembro(playerid);
        case 4: ConfigurarJason(playerid);
    }
    return 1;
}

stock IrEvento(playerid)
{
    if(EventoID == 1) EntrarDerby(playerid);
    else if(EventoID == 2) EntrarAmong(playerid);
    else if(EventoID == 3) EntrarCorrida(playerid);
    else if(EventoID == 4) ColocarSetembro(playerid);
    else if(EventoID == 5) ColocarJason(playerid);
    return 1;
}

CMD:irevento(playerid)
{
    if(EventoEstado == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há nenhum evento iniciado");
    if(EventoEstado > 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Evento já se iniciou");
    if(pModo[playerid][Jogando] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está jogando em um modo de jogo!");
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
        new Float:SADc[3];
        GetPlayerPos(playerid, SADc[0], SADc[1], SADc[2]);
        SetPlayerPos(playerid, SADc[0], SADc[1], SADc[2]+3);
    }
    IrEvento(playerid);
    return 1;
}

CMD:eventos(playerid)
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new Dialog[228];
    strcat(Dialog, "/CriarEvento - Para criar um evento\n");
    strcat(Dialog, "/InciarEvento - Para inciar um evento\n");
    strcat(Dialog, "/FinalizarEvento - Para finalizar um evento");
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_MSGBOX, "{FF0000}Evento Admin", Dialog, "Fechar", "");
    return 1;
}