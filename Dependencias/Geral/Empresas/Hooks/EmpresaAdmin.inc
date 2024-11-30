#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    new Deletar[AdminEmpresa];
    pEADM[playerid] = Deletar;
    return 1;
}

CMD:criarempresa(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new Valor;
    if(sscanf(params, "d", Valor)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /CriarEmpresa [Preço]");
    pEADM[playerid][eValorEsc] = Valor;
    new Enviar[200];
    strcat(Enviar, "Utilitarios\n");
    strcat(Enviar, "Comida\n");
    strcat(Enviar, "Armas\n");
    strcat(Enviar, "Roupas\n");
    strcat(Enviar, "Diversos\n");
    Dialog_Show(playerid, CriacaoSelecionar, DIALOG_STYLE_TABLIST, "{FF0000}Criar Empresa", Enviar, "Selecionar", "Fechar");
    return 1;
}

CMD:econfirmar(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    if(pEADM[playerid][eConfimacao] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está confirmando nenhuma empresa");
    Dialog_Show(playerid, ConfirmacaoEmp, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", "Confirme ação dessa empresa", "Criar", "Cancelar");
    return 1;
}

CMD:removerempresa(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /RemoverEmpresa [ID]");
    if(pEmpresa[id][Colocado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa empresa não existe");
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "DELETE FROM `empresas` WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Não foi possivel deletar essa empresa");
    
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você removeu a empresa ID: %d", id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);

    DestroyDynamic3DTextLabelEx(pEmpresa[id][eTexto]);
    DestroyDynamicMapIconEx(pEmpresa[id][eMapa]);
    DestroyDynamicPickupEx(pEmpresa[id][ePickup]); 
    RemoverHotelQuarto(id);
    RemoverEmpresaSql(id);
    return 1;
}

CMD:liberarempresa(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /LiberarEmpresa [ID]");
    if(pEmpresa[id][Colocado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa empresa não existe");
    if(!strcmp(pEmpresa[id][eDono], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa empresa não tem proprietário(a)");
    
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "| ADMIN | Você removeu {fc520f}%s{FFFFFF} da empresa id {fc520f}%d", pEmpresa[id][eDono], id);
    SendClientMessage(playerid, -1, Enviar);

    RemoverEmpresaSql(id);
    AtualizarEmpresa(id);
    return 1;
}

CMD:eir(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id, Mensagem[228];
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /eIr [Interior]");
    
    new bool:AchouE = false;
    for(new i=0; i < sizeof(iEmpresa); i++)
    {
        if(iEmpresa[i][eListaID] != id) continue;
        SetPlayerInterior(playerid, iEmpresa[i][Interior]);
        SetPlayerPos(playerid, iEmpresa[i][SaidaX], iEmpresa[i][SaidaY], iEmpresa[i][SaidaZ]);
        
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Você foi teleportado(a) para ( {FE2E2E}%s{FFFFFF} / {FE2E2E}%s{FFFFFF} )", iEmpresa[i][Tipo], iEmpresa[i][NomeInterior]);
        SendClientMessage(playerid, -1, Mensagem);

        AchouE = true;
        return 1;
    }

    if(AchouE == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse interior de empresa não foi encontrado");
    return 1;
}

CMD:editarempresa(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /EditarEmpresa [ID]");
    if(pEmpresa[id][Colocado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa empresa não existe");
    SetPVarInt(playerid, "EmpresaEdit", id);
    new Dialog[128];
    strcat(Dialog, "{FFFFFF}Bloquear/Desbloquear Compra\n");
    strcat(Dialog, "Alterar Preço\n");
    strcat(Dialog, "Posição Veículo");
    Dialog_Show(playerid, EditarEmpresaMenu, DIALOG_STYLE_TABLIST, "{FF0000}Editar Empresa", Dialog, "Selcionar", "Fechar");
    return 1;
}

Dialog:EditarEmpresaMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "EmpresaEdit");
    switch(listitem)
    {
        case 0:
        {
            new Mensagem[128];
            if(pEmpresa[id][eBloqueada] == false)
            {
                format(Mensagem, sizeof(Mensagem), "UPDATE `empresas` SET `Bloqueada` = 1 WHERE `Numero` = %d", id);
                mysql_query(IDConexao, Mensagem, false);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao bloquear essa empresa");
                format(Mensagem, sizeof(Mensagem), "| ADMIN | Você bloqueou a empresa {00BFFF}%d{FFFFFF} de ser comprada", id);
                SendClientMessage(playerid, -1, Mensagem);
                pEmpresa[id][eBloqueada] = true;
                return 1;
            }
            format(Mensagem, sizeof(Mensagem), "UPDATE `empresas` SET `Bloqueada` = 0 WHERE `Numero` = %d", id);
            mysql_query(IDConexao, Mensagem, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao desbloquear essa empresa");
            format(Mensagem, sizeof(Mensagem), "| ADMIN | Você desbloqueou a empresa {00BFFF}%d{FFFFFF} para ser comprada", id);
            SendClientMessage(playerid, -1, Mensagem);
            pEmpresa[id][eBloqueada] = false;
        }
        case 1: Dialog_Show(playerid, AlterarValorEmpresa, DIALOG_STYLE_INPUT, "{00FF00}Preço", "Coloque abaixo o valor desejado", "Aceitar", "Fechar");
        case 2:
        {
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode salvar uma posição sem estar dirigindo!");
            if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 609) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você precisa estar no veículo ( 609 )");
            new Float:Mk[4],
                Enviar[300];
            GetVehiclePos(GetPlayerVehicleID(playerid), Mk[0], Mk[1], Mk[2]);
            GetVehicleZAngle(GetPlayerVehicleID(playerid), Mk[3]);

            format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `VeiculoX` = %f, `VeiculoY` = %f, `VeiculoZ` = %f, `VeiculoA` = %f WHERE `Numero` = %d", Mk[0], Mk[1], Mk[2], Mk[3], id);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao atualizar ou adicionar posição!");

            pEmpresa[id][eVposX] = Mk[0];
            pEmpresa[id][eVposY] = Mk[1];
            pEmpresa[id][eVposZ] = Mk[2];
            pEmpresa[id][eVposA] = Mk[3];

            format(Enviar, sizeof(Enviar), "| EMPRESA | Você adicionou uma posição {00BFFF}%0.2f %0.2f %0.2f{FFFFFF} na empresa {00BFFF}%d", pEmpresa[id][eVposX], pEmpresa[id][eVposY], pEmpresa[id][eVposZ], id);
            SendClientMessage(playerid, -1, Enviar);
        }
    }
    return 0;
}

Dialog:AlterarValorEmpresa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "EmpresaEdit"),
        novointer;
    if(sscanf(inputtext, "d", novointer)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Valor inválido, coloque apenas números");
    
    new Enviar[100];
    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Preco` = %d WHERE `Numero` = %d", novointer, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao alterar o valor");
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou o preço da empresa {00BFFF}%d{FFFFFF} para {FF8C00}%s", id, DinheiroSeparar(novointer));
    SendClientMessage(playerid, -1, Enviar);
    pEmpresa[id][ePreco] = novointer;
    AtualizarEmpresa(id);
    return 0;
}

Dialog:CriacaoSelecionar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[500],
        Selectt[30]
    ;

    if(listitem == 0) Selectt = "Loja de Utilitários";
    else if(listitem == 1) Selectt = "Lanchonetes";
    else if(listitem == 2) Selectt = "Ammu-Nation";
    else if(listitem == 3) Selectt = "Loja de Skin";
    else if(listitem == 4) Selectt = "Diversos";
    format(pEADM[playerid][EmpEscolheu], 50, Selectt);

    strcat(Enviar, "ID\tTipo\n");
    for(new i=0; i < sizeof(iEmpresa); i++)
    {
        if(strcmp(iEmpresa[i][Tipo], Selectt)) continue;
        strcatEx(Enviar, "%d.\t%s\n", i, iEmpresa[i][InteriorNomeAdm]);
    }
    Dialog_Show(playerid, SelecaoCriacao, DIALOG_STYLE_TABLIST_HEADERS, Selectt, Enviar, "Selecionar", "Fechar");
    return 0;
}

Dialog:SelecaoCriacao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    GetPlayerPos(playerid, pEADM[playerid][eAPos][0], pEADM[playerid][eAPos][1], pEADM[playerid][eAPos][2]);
    GetPlayerFacingAngle(playerid, pEADM[playerid][eAPos][3]);
    new Mensagem[128],
        cca;

    for(new i=0; i < sizeof(iEmpresa); i++)
    {
        if(strcmp(iEmpresa[i][Tipo], pEADM[playerid][EmpEscolheu])) continue;
        if(cca != listitem){
            cca++;
            continue;
        }
        SetPlayerInterior(playerid, iEmpresa[i][Interior]);
        SetPlayerPos(playerid, iEmpresa[i][SaidaX], iEmpresa[i][SaidaY], iEmpresa[i][SaidaZ]);
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Você está visualizando interior %s", pEADM[playerid][EmpEscolheu]);
        SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
        SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Use: /econfirmar para selecionar uma ação");
        pEADM[playerid][eConfimacao] = true;
        pEADM[playerid][IntID] = iEmpresa[i][eListaID];
        break;
    }
    
    return 0;
}

Dialog:ConfirmacaoEmp(playerid, response, listitem, inputtext[])
{
    new Enviar[350];
    pEADM[playerid][eConfimacao] = false;
    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, pEADM[playerid][eAPos][0], pEADM[playerid][eAPos][1], pEADM[playerid][eAPos][2]);

    if(response)
    {
        new id = PegarEmpresaID();
        format(Enviar, sizeof(Enviar), "INSERT INTO `empresas` (`Numero`, `Interior`, `Dono`, `Mensagem`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `PosicaoA`, `Preco`) VALUES (%d, %d, '*', '*', %f, %f, %f, %f, %d)", id, pEADM[playerid][IntID], pEADM[playerid][eAPos][0], pEADM[playerid][eAPos][1], pEADM[playerid][eAPos][2], pEADM[playerid][eAPos][3], pEADM[playerid][eValorEsc]);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao criar essa empresa!");

        pEmpresa[id][eNumero] = id;
        pEmpresa[id][eImpostos] = 0;
        pEmpresa[id][eMateriaPrima] = 0;
        pEmpresa[id][ePosicaoX] = pEADM[playerid][eAPos][0];
        pEmpresa[id][ePosicaoY] = pEADM[playerid][eAPos][1];
        pEmpresa[id][ePosicaoZ] = pEADM[playerid][eAPos][2];
        pEmpresa[id][ePosicaoA] = pEADM[playerid][eAPos][3];
        pEmpresa[id][eInterior] = pEADM[playerid][IntID];
        pEmpresa[id][ePreco] = pEADM[playerid][eValorEsc];
        format(pEmpresa[id][eDono], 90, "*");
        format(pEmpresa[id][eMensagem], 90, "*");
        for(new o=0; o < MAX_FUNCIONARIOS; o++){
            format(pFuncionario[id][o][Funcionario], 90, "*");
        }
        AdicionarEmpresa(id);
        return 1;
    }
    SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Você cancelou a criação da empresa"); 
    return 1;
}

CMD:editarproducao(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id, value;
    if(sscanf(params, "dd", id, value)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /EditarProducao [ID] [Valor]");
    if(pEmpresa[id][Colocado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa empresa não existe");

    new Query[128];
    format(Query, sizeof(Query), "UPDATE `empresas` SET `Producao`=%d WHERE `Numero`=%d", value, id);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return 1;
    
    pEmpresa[id][eProducao] = value;
    AtualizarEmpresa(id);
    return 1;
}