CMD:removerreforma(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /RemoverReforma [Casa-ID]");
    if(pCasa[id][Colocado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa não existe no servidor");
    if(pCasa[id][cReforma] < gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa não está em reforma!");

    new Enviar[90];
    
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Reforma` = %d WHERE `Numero` = %d", gettime(), id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um erro ao remover a reforma");
    pCasa[id][cReforma] = gettime();
    SendClientMessage(playerid, 0xFFFF00FF, "| ADMIN | Reforma removida com sucesso!");
    return 1;
}

CMD:editarcasa(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /EditarCasa [ID]");
    if(pCasa[id][Colocado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa não existe no servidor");
    SetPVarInt(playerid, "CasaEdit", id);
    new Dialog[300];
    strcat(Dialog, "{FFFFFF}Alterar Interior\n");
    strcat(Dialog, "Alterar Interior Máximo\n");
    strcat(Dialog, "Alterar Preço ( Coins )\n");
    strcat(Dialog, "Alterar Preço ( Preço )\n");
    strcat(Dialog, "Bloquear/Desbloquear Compra");
    Dialog_Show(playerid, EditarConfigCasa, DIALOG_STYLE_TABLIST, "{FF0000}Editar Casa", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:removercasa(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /RemoverCasa [ID]");
    if(pCasa[id][Colocado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa não existe");
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "DELETE FROM `casas` WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Não foi possivel deletar essa casa");
    pCasa[id][Colocado] = false;
    DestroyDynamic3DTextLabelEx(pCasa[id][cTexto]);
    DestroyDynamicMapIconEx(pCasa[id][cMapa]);
    DestroyDynamicPickupEx(pCasa[id][cPickup]);
    RemoverMoveisAdmin(id);
    return 1;
}

CMD:liberarcasa(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /LiberarCasa [Casa-ID]");
    if(pCasa[id][Colocado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa não existe no servidor");
    if(!strcmp(pCasa[id][cDono], "*")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa não tem moderador");

    new Enviar[300];

    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Dono`= '*', `LixoF` = 0, `LixoD` = 0, `JPreco` = 0, `Impostos` = 0, `Mensagem` = '*', `Interior` = 1, `Reforma` = 0, `Tranca` = 0, `Morador0` = '*', `Morador1` = '*', `Morador2` = '*', `Morador3` = '*', `Morador4` = '*', `Morador5` = '*' WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Não foi possivel remover o morador dessa casa!");

    format(Enviar, sizeof(Enviar), "DELETE FROM `Moradores` WHERE `CasaID`=%d", id);
    mysql_query(IDConexao, Enviar, false);

    format(Enviar, sizeof(Enviar), "| ADMIN | Você removeu a moradia do(a) {00BFFF}%s{FFFFFF} da casa id {00BFFF}%d", pCasa[id][cDono], id);
    SendClientMessage(playerid, -1, Enviar);

    // Reset
    pCasa[id][cReforma] = 0;
    pCasa[id][cInterior] = 1;
    pCasa[id][cJPreco] = 0;
    pCasa[id][cTranca] = 0; 
    if(pCasa[id][LixoF] > 0) DestroyDynamicObjectEx(pCasa[id][LixoOb]); 
    pCasa[id][LixoF] = 0;
    pCasa[id][LixoD] = 0;
    pCasa[id][Impostos] = 0;

    // Reset - Strings
    format(pCasa[id][cDono], 90, "*");
    format(pCasa[id][cSenha], 90, "*");
    format(pCasa[id][cMensagem], 90, "*");

    new adsada[MoradorInfo];
    if(new d=0; d < MAX_MORADOR; d++){
        pMorador[id][d] = adsada;
    }

    RemoverMoveisAdmin(id);
    AtualizarCasa(id);
    return 1;
}

CMD:criarcasa(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new vcoins, vgrana, vinterior;
    if(sscanf(params, "ddd", vinterior, vgrana, vcoins)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /criarcasa [InteriorMax] [Dinheiro do Jogo] [Coins]");
    
    new Float:gPos[4],
        idcasa = CasaID(),
        Query[400]
    ;
    GetPlayerPos(playerid, gPos[0], gPos[1], gPos[2]);
    GetPlayerFacingAngle(playerid, gPos[3]);
    //new ReformaTime = (gettime() + (7 * 24 * 60 * 60));
    format(Query, sizeof(Query), "INSERT INTO `casas` (`Numero`, `InteriorMax`, `Interior`, `Dono`, `Senha`, `Mensagem`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `PosicaoA`, `Morador0`, `Morador1`, `Morador2`, `Morador3`, `Morador4`, `Morador5`, `Preco`, `Coins`) VALUES (%d, %d, %d, '*', '*', '*', %f, %f, %f, %f, '*', '*', '*', '*', '*', '*', %d, %d)", idcasa, vinterior, 1, gPos[0], gPos[1], gPos[2], gPos[3], vgrana, vcoins);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Não foi possível criar essa casa!");

    pCasa[idcasa][Colocado] = true;
    pCasa[idcasa][cPosicaoX] = gPos[0];
    pCasa[idcasa][cPosicaoY] = gPos[1];
    pCasa[idcasa][cPosicaoZ] = gPos[2];
    pCasa[idcasa][cPosicaoA] = gPos[3];

    pCasa[idcasa][cInterior] = 1;
    pCasa[idcasa][cInteriorMax] = vinterior;

    pCasa[idcasa][cPreco] = vgrana;
    pCasa[idcasa][cCoins] = vcoins;
    pCasa[idcasa][cReforma] = 0;
    pCasa[idcasa][cJPreco] = 0;
    
    format(pCasa[idcasa][cSenha], 70, "*");
    format(pCasa[idcasa][cDono], 70, "*");
    format(pCasa[idcasa][cMensagem], 70, "*");

    for(new i=0; i < MAX_MORADOR; i++){
        format(pMorador[idcasa][i][Morador], 90, "*");
    }

    AdicionarCasa(idcasa);
    return 1;
}

Dialog:EditarConfigCasa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "CasaEdit");
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, AlterarInteriorCasa, DIALOG_STYLE_INPUT, "{FF0000}Interior", "Coloque abaixo o interior desejado", "Aceitar", "Cancelar");
        case 1: Dialog_Show(playerid, AlterarInteriorCasaMax, DIALOG_STYLE_INPUT, "{FF0000}Interior Máximo", "Coloque abaixo o interior desejado", "Aceitar", "Cancelar");
        case 2: Dialog_Show(playerid, AlterarPrecoCoins, DIALOG_STYLE_INPUT, "{FF0000}Preço Coins", "Coloque abaixo o preço coins desejado", "Aceitar", "Cancelar");
        case 3: Dialog_Show(playerid, AlterarPrecoValor, DIALOG_STYLE_INPUT, "{FF0000}Preço", "Coloque abaixo o preço desejado", "Aceitar", "Cancelar");
        case 4:
        {
            new Mensagem[128];
            if(pCasa[id][cBloqueada] == false)
            {
                format(Mensagem, sizeof(Mensagem), "UPDATE `casas` SET `Bloqueada` = 1 WHERE `Numero` = %d", id);
                mysql_query(IDConexao, Mensagem, false);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao bloquear essa casa");
                format(Mensagem, sizeof(Mensagem), "| ADMIN | Você bloqueou a casa {00BFFF}%d{FFFFFF} de ser comprada", id);
                SendClientMessage(playerid, -1, Mensagem);
                pCasa[id][cBloqueada] = true;
                return 1;
            }
            format(Mensagem, sizeof(Mensagem), "UPDATE `casas` SET `Bloqueada` = 0 WHERE `Numero` = %d", id);
            mysql_query(IDConexao, Mensagem, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao desbloquear essa casa");
            format(Mensagem, sizeof(Mensagem), "| ADMIN | Você desbloqueou a casa {00BFFF}%d{FFFFFF} para ser comprada", id);
            SendClientMessage(playerid, -1, Mensagem);
            pCasa[id][cBloqueada] = false;
        }
    }
    return 0;
}

Dialog:AlterarPrecoCoins(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "CasaEdit"),
        novointer
    ;
    if(sscanf(inputtext, "d", novointer)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Valor inválido, coloque apenas números");
    
    new Enviar[100];
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Coins` = %d WHERE `Numero` = %d", novointer, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao alterar o valor");
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou o preço coins da casa {00BFFF}%d{FFFFFF} para {FF8C00}%s", id, DinheiroSeparar(novointer));
    SendClientMessage(playerid, -1, Enviar);
    pCasa[id][cCoins] = novointer;
    AtualizarCasa(id);
    return 0;
}

Dialog:AlterarPrecoValor(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "CasaEdit"),
        novointer
    ;
    if(sscanf(inputtext, "d", novointer)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Valor inválido, coloque apenas números");
    
    new Enviar[100];
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Preco` = %d WHERE `Numero` = %d", novointer, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao alterar o valor");
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou o preço da casa {00BFFF}%d{FFFFFF} para {FF8C00}%s", id, DinheiroSeparar(novointer));
    SendClientMessage(playerid, -1, Enviar);
    pCasa[id][cPreco] = novointer;
    AtualizarCasa(id);
    return 0;
}

Dialog:AlterarInteriorCasaMax(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "CasaEdit"),
        novointer
    ;
    if(sscanf(inputtext, "d", novointer)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Interior inválido, coloque apenas números");
    if(novointer > 20 || novointer < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse interior não existe");
    
    new Enviar[100];
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `InteriorMax` = %d WHERE `Numero` = %d", novointer, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao alterar o interior");
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou o interior máximo da casa {00BFFF}%d{FFFFFF} para {FF8C00}%d", id, novointer);
    SendClientMessage(playerid, -1, Enviar);
    pCasa[id][cInteriorMax] = novointer;
    AtualizarCasa(id);
    return 0;
}

Dialog:AlterarInteriorCasa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "CasaEdit"),
        novointer
    ;
    if(sscanf(inputtext, "d", novointer)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Interior inválido, coloque apenas números");
    if(novointer > 20 || novointer < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse interior não existe");
    
    new Enviar[100];
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Interior` = %d WHERE `Numero` = %d", novointer, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao alterar o interior");
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou o interior da casa {00BFFF}%d{FFFFFF} para {FF8C00}%d", id, novointer);
    SendClientMessage(playerid, -1, Enviar);
    pCasa[id][cInterior] = novointer;
    AtualizarCasa(id);
    return 0;
}

CMD:preco(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new id, valorc, valor;
    if(sscanf(params, "ddd", id, valor, valorc)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Preco [Casa-ID] [Preço] [Coins (0 - Para remover )]");
    if(pCasa[id][Colocado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa não existe");
    
    new Query[128];
    format(Query, sizeof(Query), "UPDATE `casas` SET `Preco` = %d, `Coins` = %d WHERE `Numero` = %d", valor, valorc, id);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema na database");

    pCasa[id][cPreco] = valor;
    pCasa[id][cCoins] = valorc;
    AtualizarCasa(id);

    format(Query, sizeof(Query), "| BETA | Casa %d atualizada com sucesso", id);
    SendClientMessage(playerid, -1, Query);
    return 1;
}