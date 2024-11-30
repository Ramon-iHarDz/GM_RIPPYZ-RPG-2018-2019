#include <YSI_Coding\y_hooks>

enum CriacaoRota
{
    AtualRota,
	RotaID,
	bool:CriandoRota,
	DestinoSelecionado[70]
};

new oCriacao[MAX_PLAYERS][CriacaoRota];


hook OnGameModeInit()
{
    CarregarRotas();
    return 1;
}

function CarregarRotas()
{
    new Cache:Conectar,
        id,
        idex;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `onibusrotas`");
    if(mysql_errno(IDConexao) != 0)
    {   
        print("[Rippzy:Rotas] Não foi possivel conectar com as rotas de onibus");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Rotas] Rotas de onibus sendo carregadas com sucesso!");
    new TemQAP = cache_num_rows();
    if(TemQAP > 0)
    {
        for(new i=0; i < TemQAP; i++)
        {
            // Pegar identificações
            cache_get_value_name_int(i, "RotaID", id);
            cache_get_value_name_int(i, "RotaEx", idex);

            cache_get_value_name_int(i, "ParadaID", oRota[id][idex][ParadaSel]);
            cache_get_value(i, "RotaNome", oRota[id][idex][NomeDaRota], 70);
            cache_get_value(i, "Destino", oRota[id][idex][pDestino], 70);

            oRota[id][idex][RotaAtiva] = true;
            oRota[id][idex][Setando] = false;
        }
    }
    cache_delete(Conectar);
    return 1;
}

Dialog:AdmSelecionarCidade(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
	{
		case 0: format(oCriacao[playerid][DestinoSelecionado], 70, "Los Santos");
		case 1: format(oCriacao[playerid][DestinoSelecionado], 70, "San Fierro");
		case 2: format(oCriacao[playerid][DestinoSelecionado], 70, "Las Venturas");
	}

    new Mensagem[200];

    oCriacao[playerid][AtualRota] = 0;
	oCriacao[playerid][CriandoRota] = true;
	oCriacao[playerid][RotaID] = PegarRotaID();
	oRota[oCriacao[playerid][RotaID]][0][Setando] = true;

    format(Mensagem, sizeof(Mensagem), "| ROTA-ADMIN | Você está fazendo rota {00BFFF}%s{FFFFFF} ( ID: {FF4500}%d{FFFFFF} )", oCriacao[playerid][DestinoSelecionado], oCriacao[playerid][RotaID]);
    SendClientMessage(playerid, -1, Mensagem);
    SendClientMessage(playerid, -1, "| ROTA-ADMIN | Use: /AdicionarParada ( {FF0000}Obs: Fique perto da parada{FFFFFF} )");
    SendClientMessage(playerid, -1, "| ROTA-ADMIN | Use: /FinalizarRota - Após fazer a rota");
    SendClientMessage(playerid, -1, "| ROTA-ADMIN | Use: /RotaCancelar - Para cancelar");
    return 0;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(oCriacao[playerid][CriandoRota] == false) return 1;
    oRota[oCriacao[playerid][RotaID]][0][Setando] = false;
    
    for(new i=0; i < MAX_ROTASID; i++){
        new LimpAh[RotasInfo];
        oRota[oCriacao[playerid][RotaID]][i] = LimpAh;
    }

    new Configg[CriacaoRota];
    oCriacao[playerid] = Configg;
    return 1;
}

Dialog:SelecionaNomeRota(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 30) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nome muito extenso!");
	new id = oCriacao[playerid][RotaID],
		Mensagem[300];
	oCriacao[playerid][CriandoRota] = false;
	    
	for(new i=0; i < oCriacao[playerid][AtualRota]; i++)
	{

        // Salvar na database
        format(Mensagem, sizeof(Mensagem), "INSERT INTO `onibusrotas` (`ParadaID`, `RotaNome`, `Destino`, `RotaID`, `RotaEx`) VALUES (%d, '%s', '%s', %d, %d)", oRota[id][i][ParadaSel], EscapeString(inputtext), EscapeString(oCriacao[playerid][DestinoSelecionado]), id, i);
        mysql_query(IDConexao, Mensagem, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao arquivar essa rota!");

        // Salvar no servidor
	    oRota[id][i][Setando] = false;
	    oRota[id][i][RotaAtiva] = true;
	    format(oRota[id][i][NomeDaRota], 70, inputtext);
	    format(oRota[id][i][pDestino], 70, oCriacao[playerid][DestinoSelecionado]);
	}

	format(Mensagem, sizeof(Mensagem), "| ROTA-ADMIN | Você criou rota {00BFFF}%s{FFFFFF} ( ID: {FF4500}%d{FFFFFF} / %d Paradas )", inputtext, id, oCriacao[playerid][AtualRota]);
	SendClientMessage(playerid, -1, Mensagem);
    return 0;
}

CMD:criarrota(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    if(oCriacao[playerid][CriandoRota] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está fazendo uma rota, acabe antes de iniciar outra");
    if(PegarRotaID() == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais espaço para criar uma rota");

	new Dialog[128];
	strcat(Dialog, "Los Santos\n");
	strcat(Dialog, "San Fierro\n");
	strcat(Dialog, "Las Venturas");
    Dialog_Show(playerid, AdmSelecionarCidade, DIALOG_STYLE_TABLIST, "{FF0000}Escolha uma cidade", Dialog, "Selecionar", "Fechar");
	return 1;
}

CMD:finalizarrota(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    if(oCriacao[playerid][CriandoRota] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está setando uma rota!");
    if(oCriacao[playerid][AtualRota] < 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você fez poucas rotas!");
    Dialog_Show(playerid, SelecionaNomeRota, DIALOG_STYLE_INPUT, "{FF0000}Defina um nome", "Coloque abaixo o nome para essa rota", "Selecionar", "Fechar");
	return 1;
}

CMD:rotacancelar(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
	if(oCriacao[playerid][CriandoRota] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está criando rotas");
    // if(oCriacao[playerid][AtualRota] < 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa setar mais paradas!");
    new id = oCriacao[playerid][RotaID];
    new Mensagem[128];
    
    if(oCriacao[playerid][AtualRota] > 0){
		for(new i=0; i < oCriacao[playerid][AtualRota]; i++){
		    format(Mensagem, sizeof(Mensagem), "| AVISO | Removido da parada ID: {00BFFF}%d{FFFFFF} ( {FF4500}%s{FFFFFF} )", i, oCriacao[playerid][DestinoSelecionado]);
			SendClientMessage(playerid, -1, Mensagem);
	        new Configg[RotasInfo];
			oRota[id][i] = Configg;
		}
	}
    else
    {
        new Configg[RotasInfo];
		oRota[id][0] = Configg;
	}
	SendClientMessage(playerid, -1, "| AVISO | Rotas Canceladas");
	oCriacao[playerid][CriandoRota] = false;
	return 1;
}

CMD:adicionarparada(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
	if(oCriacao[playerid][CriandoRota] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está setando uma rota!");
	new id = oCriacao[playerid][RotaID],
		numero = oCriacao[playerid][AtualRota],
		bool:ParadaPerta = false,
        Mensagem[100]
	;
	for(new i=1; i < MAX_PARADAS; i++)
	{
	    if(!IsPlayerInRangeOfPoint(playerid, 3.0, oParada[i][pPosX], oParada[i][pPosY], oParada[i][pPosZ])) continue;
	    format(Mensagem, sizeof(Mensagem), "| ROTA-ADMIN | Você adicionou a parada {FF4500}%d", i);
        SendClientMessage(playerid, -1, Mensagem);
        oRota[id][numero][ParadaSel] = i;
	    ParadaPerta = true;
	}
	if(ParadaPerta == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de uma parada de ônibus");
	oCriacao[playerid][AtualRota]++;
	return 1;
}

CMD:removerrota(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /RemoverRota [RotaID]");
    if(oRota[id][0][RotaAtiva] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa rota não existe!");

    new Enviar[200];

    format(Enviar, sizeof(Enviar), "DELETE FROM `onibusrotas` WHERE `RotaID` = %d", id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao remover essa rota!");

    format(Enviar, sizeof(Enviar), "| AVISO | Você removeu a rota %s ( ID: {FE2E2E}%d{FFFFFF} )", oRota[id][0][NomeDaRota], id);
    SendClientMessage(playerid, -1, Enviar);

    for(new i=0; i < MAX_ROTASID; i++)
    {
        new Configg[RotasInfo];
		oRota[id][i] = Configg;  
    }
    return 1;
}

Dialog:RotaPraque(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Direcao[90],
        Dialog[2000]
    ;
    
    switch(listitem)
    {
        case 0: Direcao = "Los Santos";
        case 1: Direcao = "San Fierro";
        case 2: Direcao = "Las Venturas";
    }

    strcat(Dialog, "ID\tNome\n");
    for(new i=1; i < MAX_ROTAS; i++)
    {
        if(oRota[i][0][RotaAtiva] == false) continue;
        if(strcmp(oRota[i][0][pDestino], Direcao)) continue;
        strcatEx(Dialog, "%d\t%s\n", i, oRota[i][0][NomeDaRota]);
    }
    Dialog_Show(playerid, DialogInvalida, DIALOG_STYLE_TABLIST_HEADERS, Direcao, Dialog, "Fechar", "");
    return 0;
}

CMD:onibusrota(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new Dialog[128];
	strcat(Dialog, "Los Santos\n");
	strcat(Dialog, "San Fierro\n");
	strcat(Dialog, "Las Venturas");
    Dialog_Show(playerid, RotaPraque, DIALOG_STYLE_TABLIST, "{FF0000}Visualização das Rotas", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:ajudarota(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new Dialog[1000];
    strcat(Dialog, "{1E90FF}/OnibusRota{FFFFFF} - Para visualizar todas as rotas criadas por admin\n");
    strcat(Dialog, "{1E90FF}/RemoverRota [Rota-ID]{FFFFFF} - Para remover uma determinada rota\n");
    strcat(Dialog, "{1E90FF}/CriarParada{FFFFFF} - Para criar uma determinada parada\n");
    strcat(Dialog, "{1E90FF}/RemoverParada{FFFFFF} - Para remover uma determinada parada ( Obs: {FF0000}Precisa estar perto{FFFFFF} )\n");
    strcat(Dialog, "{1E90FF}/ParadaRange{FFFFFF} - Para definir um range entre a parada e o checkpoint ( Obs: {FF0000}Precisa estar perto{FFFFFF} )\n");
    strcat(Dialog, "{1E90FF}/CriarRota{FFFFFF} - Para adicionar uma nova rota");
    Dialog_Show(playerid, SemFinalidade, DIALOG_STYLE_MSGBOX, "{FF0000}Ajuda", Dialog, "Selecionar", "");
    return 1;
}