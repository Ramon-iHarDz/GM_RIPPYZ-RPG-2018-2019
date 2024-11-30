#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    if(pCelularEx[playerid][CellAberto] == true) KillTimer(pCelularEx[playerid][CellTID]);

    rRecente[playerid] = 0;
    for(new i=0; i < 3; i++){
        new Delet331231ar[UltimasLigacoes];
        rCelular[playerid][i] = Delet331231ar;    
    }

    new Delet31231ar[CelularPInfo];
    pCelularEx[playerid] = Delet31231ar; 
    
    return 1;
}

Dialog:ChamarMecanicoMensagem(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Texto muito grande");
    if(Jogador[playerid][Operadora] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui um CHIP");
    if(ChamadoMec[playerid][ChamouMecanico] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco antes de chamar novamente um reboque");
    if(ChamadoMec[playerid][FuiAtendido] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já solicitou um(a) mecânico(a)");

    new Float:mas[3],
        bool:asdas;
    
    GetPlayerPos(playerid, mas[0], mas[1], mas[2]);
    for(new i=0; i < MAX_VEHICLES; i++)
    {
        if(VeiculoServer[i][VeiculoOn] == false) continue;
        if(!IsVehicleInRangeOfPoint(i, 3.0, mas[0], mas[1], mas[2])) continue;
        if(VeiculoServer[i][vQuebrado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse veículo não está quebrado");
        ChamadoMec[playerid][VeiculoReparo] = i;
        asdas = true;
        break;
    }
    if(asdas == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de nenhum veículo quebrado");

    new Mensagem[238],
        Mecanc = 0,
        Ersodsa;
    
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(i == playerid) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Mecânico")) continue;
        if(pMecanico[i][MecanicoAlugado] == false) continue;
        if(pMecanico[i][AtendendoMec] == true) continue;
        format(Mensagem, sizeof(Mensagem), "| MECÂNICO | O(A) Jogador(a) {00BFFF}%s[%d]{FFFFFF} está solicitando mecânico em %s, mande sua proposta.", PegarNick(playerid), playerid, GetPlayerZone(playerid));
        SendClientMessage(i, -1, Mensagem);
        Mecanc++;
    }
    if(Mecanc == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mecanicos(as) disponíveis no momento!");
    else if(Mecanc == 0 && Ersodsa > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente para pegar um mecânico mais próximo");
    else SendClientMessage(playerid, -1, "| CELULAR | Seu chamado foi enviado com sucesso, aguarde uma resposta.");
    ChamadoMec[playerid][ChamouMecanico] = gettime()+60;
    return 1;
}

Dialog:MensagemParamedicos(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 30) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Texto muito grande");
    if(GetPVarInt(playerid, "TempoDenuA") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco!");
    SetPVarInt(playerid, "TempoDenuA", gettime()+40);
    new Mensagem[148];
    format(Mensagem, sizeof(Mensagem), "| CENTRAL | %s[%d] enviou uma solicitação: %s", PegarNick(playerid), playerid, inputtext);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Paramédico") && Jogador[i][Admin] < 2) continue;
        if(Jogador[i][Admin] < 2){
            if(pPolicia[i][PegouUniformePolicia] == false) continue;
        }
        SendClientMessage(i, 0x4682B4FF, Mensagem);
    }
    SendClientMessage(playerid, 0x4682B4FF, "| CENTRAL | Sua solitação foi enviada para os paramédicos");
    return 1;
}

Dialog:MensagemPolicia(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 30) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Texto muito grande");
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    if(GetPVarInt(playerid, "TempoDenu") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco!");
    SetPVarInt(playerid, "TempoDenu", gettime()+60);
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| CENTRAL | %s[%d] fez uma denúncia: %s", PegarNick(playerid), playerid, inputtext);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(!IsPolicia(i) && Jogador[i][Admin] < 2) continue;
        if(Jogador[i][Admin] < 2){
            if(pPolicia[i][PegouUniformePolicia] == false) continue;
        }
        SendClientMessage(i, 0x4682B4FF, Mensagem);
    }
    SendClientMessage(playerid, 0x4682B4FF, "| CENTRAL | Seu chamado foi enviado para os policias");
    return 1;
}


hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    // Voltar ou Fechar
    if(playertextid == CelularCapa[playerid][6])
    {
        if(GetPVarInt(playerid, "EmLigacao") > 0){
            new id = GetPVarInt(playerid, "LigacaoID");
            RecusarChamada(playerid);
            RecusarChamada(id);
        }

        if(!strcmp(pCelularEx[playerid][PagOcultarCelular], "OcultarCelular")) OcultarHome(playerid);
        CallRemoteFunction(pCelularEx[playerid][PagOcultarCelular], "d", playerid);
        if(strcmp(pCelularEx[playerid][PagMostrarCelular], "*")) CallRemoteFunction(pCelularEx[playerid][PagMostrarCelular], "d", playerid); 
    }

    // Banco - Tansferência - Saldo etc..
    else if(playertextid == CelularHome[playerid][14]){
        OcultarHome(playerid);
        MostrarCelularBanco(playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // Policia
    else if(playertextid == CelularHome[playerid][4]){
        Dialog_Show(playerid, MensagemPolicia, DIALOG_STYLE_INPUT, "{FF0000}190", "Coloque o problema que está acontecendo abaixo", "Confirmar", "Cancelar");
        return Y_HOOKS_BREAK_RETURN_1;  
    }

    // Paramédicos
    else if(playertextid == CelularHome[playerid][6]){
        Dialog_Show(playerid, MensagemParamedicos, DIALOG_STYLE_INPUT, "{FF0000}192", "Coloque o problema que está acontecendo abaixo", "Confirmar", "Cancelar");
        return Y_HOOKS_BREAK_RETURN_1;  
    }
    
    // Agenda
    else if(playertextid == CelularHome[playerid][0]){ 
        OcultarHome(playerid);
        MostrarAgendaOP(playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // MP3
    else if(playertextid == CelularHome[playerid][12])
    {
        if(Jogador[playerid][MP4] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não comprou o MP3, vá até uma loja de utilitários.");
        MostrarRadio(playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // GPS
    else if(playertextid == CelularHome[playerid][10])
    {
        if(Jogador[playerid][Gps] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não comprou o GPS, vá até uma loja de utilitários.");
        MostrarGPS(playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // Chamar Uber
    else if(playertextid == CelularHome[playerid][8]){
        OcultarHome(playerid);
        MostrarCelularUber(playerid);
        return Y_HOOKS_BREAK_RETURN_1; 
    }

    // Chamer Mecânico
    else if(playertextid == CelularHome[playerid][2]){
        Dialog_Show(playerid, ChamarMecanicoMensagem, DIALOG_STYLE_INPUT, "{FF0000}Mecânico", "Coloque o problema que está acontecendo abaixo", "Confirmar", "Cancelar");
        return Y_HOOKS_BREAK_RETURN_1;    
    }

    else if(playertextid == CelularHome[playerid][16]){
        OcultarHome(playerid);
        MostrarOlx(playerid); 
        return Y_HOOKS_BREAK_RETURN_1;    
    }

    return 0;
}

CMD:celular(playerid)
{
    if(Jogador[playerid][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui um celular");
    if(GetPVarInt(playerid, "CerulaAberto") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está segurando o celular");
    SetPVarInt(playerid, "CerulaAberto", 1);
    RequestCelular(playerid);
    return 1;
}