CMD:liberarbase(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id,
        Mensagem[128];
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /LiberarBase [ID]");
    if(Base[id][BaseColocada] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa base não existe no servidor");
    if(!strcmp(Base[id][BaseNome], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa base não possui proprietário(a)");

    SqlRemoverBase(id);
    LimparBaseInfo(id);
    AtualizarBase(id);
    AbrirPortaoBase(id, false);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você liberou a base (ID: %d) com sucesso", id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:removerbase(playerid, params[])
{
    if(Jogador[playerid][Admin] < 7) return 0;
    new id,
        Mensagem[128];
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /LiberarBase [ID]");
    if(Base[id][BaseColocada] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa base não existe no servidor");
    // if(!strcmp(Base[id][BaseNome], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa base não possui proprietário(a)");
    RemoverBaseInfo(id); 
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você removeu a base (ID: %d) com sucesso", id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:editarbase(playerid, params[])
{
    if(Jogador[playerid][Admin] < 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /EditarBase [ID]");
    if(Base[id][BaseColocada] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa base não existe no servidor");
    // if(!strcmp(Base[id][BaseNome], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa base não possui proprietário(a)");
    SetPVarInt(playerid, "BaseADMID", id);

    new Dialog[200];
    strcat(Dialog, "Opção\tSobre\n");
    strcatEx(Dialog, "Vencimento\t{FFA500}%s\n", GetDateFromTimeEx(Base[id][BaseVencimento]));
    strcatEx(Dialog, "Nome\t{FFA500}%s\n", Base[id][BaseNome]);
    strcatEx(Dialog, "Tag\t{FFA500}%s\n", Base[id][BaseTag]);
    strcatEx(Dialog, "Veículos\t{FFA500}%d\n", VeiculosBase(id));
    strcatEx(Dialog, "Preço\t{FFA500}$%s\n", DinheiroSeparar(Base[id][BaseCoins]));
    strcatEx(Dialog, "Desconto\t{FFA500}$%s\n", DinheiroSeparar(Base[id][BaseDesconto]));
    strcat(Dialog, "Bloquear/Desbloquear Renovação\n");
    Dialog_Show(playerid, EditBaseMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Editando Base", Dialog, "Selecionar", "Fechar");

    return 1;
}

Dialog:AlteraVencimento(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "BaseADMID"),
        DiasB;
    if(sscanf(inputtext, "d", DiasB)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Tempo Inválido");

    new Enviar[128],
        TempoSOMM = (gettime() + (DiasB*86400));
    format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Vencimento` = %d WHERE `Numero` = %d", TempoSOMM, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema.");
    Base[id][BaseVencimento] = TempoSOMM;
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou o vencimento para a data %s", GetDateFromTimeEx(TempoSOMM));
    SendClientMessage(playerid, 0x00BFFFFF, Enviar);
    return 1;
}

Dialog:AdicionarVencimento(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "BaseADMID"),
        DiasB;
    if(sscanf(inputtext, "d", DiasB)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Tempo Inválido");

    new Enviar[128],
        TempoSOMM = Base[id][BaseVencimento];

    TempoSOMM += (DiasB*86400);
    format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Vencimento` = %d WHERE `Numero` = %d", TempoSOMM, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema.");
    Base[id][BaseVencimento] = TempoSOMM;
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou o vencimento para a data %s", GetDateFromTimeEx(TempoSOMM));
    SendClientMessage(playerid, 0x00BFFFFF, Enviar);
    return 1;
}

Dialog:VencimentoBaseADM(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, AlteraVencimento, DIALOG_STYLE_INPUT, "{FF0000}Vencimento", "Adicione abaixo um novo vencimento", "Confirmar", "Fechar");
        case 1: Dialog_Show(playerid, AdicionarVencimento, DIALOG_STYLE_INPUT, "{FF0000}Vencimento", "Adicione abaixo os dias que deseja", "Confirmar", "Fechar");
    }
    return 1;
}

Dialog:AlteraBaseNomeADM(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 24) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Máximo é de 24 caracteres");
    
    new Enviar[128];
    new id = GetPVarInt(playerid, "BaseADMID");
    format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Nome` = '%s' WHERE `Numero` = %d", EscapeString(inputtext), id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar o nome");
    format(Base[id][BaseNome], 30, inputtext);
    AtualizarBase(id);

    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou o nome da base para %s", inputtext);
    SendClientMessage(playerid, 0x00BFFFFF, Enviar);
    return 1;
}

Dialog:AlteraBaseTagADM(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 6) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Máximo é de 24 caracteres");
    if(strlen(inputtext) < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | mínimo é de 3 caracteres");

    new Enviar[128];
    new id = GetPVarInt(playerid, "BaseADMID");
    format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Tag` = '%s' WHERE `Numero` = %d", EscapeString(inputtext), id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar a tag");
    format(Base[id][BaseTag], 30, inputtext);
    // AtualizarBase(id);

    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou a TAG da base para %s", inputtext);
    SendClientMessage(playerid, 0x00BFFFFF, Enviar);
    return 1;
}

Dialog:MenuVeiculoBaseADM(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarInt(playerid, "VeiculoBaseAdemir", listitem);
    new id = GetPVarInt(playerid, "BaseADMID"),
        Float:Fdcc[4],
        Enviar[228];

    if(vBase[id][listitem][SlotDataBase] == false)
    {
        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa estar dirigindo");
        
        GetVehiclePos(GetPlayerVehicleID(playerid), Fdcc[0], Fdcc[1], Fdcc[2]);
        GetVehicleZAngle(GetPlayerVehicleID(playerid), Fdcc[3]);

        format(Enviar, sizeof(Enviar), "INSERT INTO `baseveiculos` (`BaseID`, `PosicaoID`, `BaseX`, `BaseY`, `BaseZ`, `BaseA`) VALUES (%d, %d, %f, %f, %f, %f)", id, listitem, Fdcc[0], Fdcc[1], Fdcc[2], Fdcc[3]);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um erro ao adicionar esse slot");
       
        vBase[id][listitem][SlotDataBase] = true;
        vBase[id][listitem][vBaseX] = Fdcc[0];
        vBase[id][listitem][vBaseY] = Fdcc[1];
        vBase[id][listitem][vBaseZ] = Fdcc[2];
        vBase[id][listitem][vBaseA] = Fdcc[3];

        format(Enviar, sizeof(Enviar), "| ADMIN | Você configurou o slot %d da base %d", listitem, id);
        SendClientMessage(playerid, 0x00BFFFFF, Enviar);
        return 1;
    }

    else if(vBase[id][listitem][SlotDataBase] == true)
    {
        strcat(Enviar, "Escolher Modelo\n");
        strcat(Enviar, "Escolher Modelo ( Loja )");
        Dialog_Show(playerid, BaseModeloADM, DIALOG_STYLE_TABLIST, "{FF0000}Modelo", Enviar, "Selecionar", "Fechar");
    }
    return 1;
}

Dialog:BaseEscolherModelo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new modelll;
    if(sscanf(inputtext, "d", modelll)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque apenas ID's");
    
    new id = GetPVarInt(playerid, "BaseADMID"),
        idx = GetPVarInt(playerid, "VeiculoBaseAdemir"),
        Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `baseveiculos` SET `Modelo` = %d WHERE `BaseID` = %d AND `PosicaoID` = %d", modelll, id, idx);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao registrar esse modelo");
    vBase[id][idx][VeiculoModeloBase] = modelll;
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Modelo alterado");
    return 1;
}

Dialog:BaseEscolherModeloLoja(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "BaseADMID"),
        idx = GetPVarInt(playerid, "VeiculoBaseAdemir"),
        Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `baseveiculos` SET `Modelo` = %d WHERE `BaseID` = %d AND `PosicaoID` = %d", BaseLoja[listitem][ModeloX], id, idx);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao registrar esse modelo");
    vBase[id][idx][VeiculoModeloBase] = BaseLoja[listitem][ModeloX];
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Modelo alterado");
    return 1;
}

Dialog:BasePrecoAdmin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "BaseADMID"),
        precc;
    if(sscanf(inputtext, "d", precc)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque apenas números"); 

    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Valor` = %d WHERE `Numero` = %d", precc, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar preço");
    Base[id][BaseCoins] = precc;
    AtualizarBase(id);

    return 1;
}

Dialog:BaseDescontoAdmin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "BaseADMID"),
        precc;
    if(sscanf(inputtext, "d", precc)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque apenas números"); 

    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Desconto` = %d WHERE `Numero` = %d", precc, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar preço");
    Base[id][BaseDesconto] = precc;
    AtualizarBase(id);

    return 1;
}

Dialog:BaseModeloADM(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, BaseEscolherModelo, DIALOG_STYLE_INPUT, "{FF0000}Modelo", "Coloque o modelo abaixo", "Confirmar", "Fechar");
        case 1:
        {
            new Dialog[500];
            strcat(Dialog, "Modelo\tPreço\n");
            for(new d=0; d < sizeof(BaseLoja); d++)
            {
                if(BaseLoja[d][CoinX] == true) strcatEx(Dialog, "{CCCCCC}%s\t{FFFF00}$%s Coins\n", GetVehicleNameByModel(BaseLoja[d][ModeloX]), DinheiroSeparar(BaseLoja[d][PrecoX]));
                else strcatEx(Dialog, "{CCCCCC}%s\t{32CD32}$%s\n", GetVehicleNameByModel(BaseLoja[d][ModeloX]), DinheiroSeparar(BaseLoja[d][PrecoX]));
            }
            Dialog_Show(playerid, BaseEscolherModeloLoja, DIALOG_STYLE_TABLIST_HEADERS, "{32CD32}Base Loja", Dialog, "Selecionar", "Fechar");
        }
    }
    return 1;
}

Dialog:EditBaseMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new Dialog[500];
    switch(listitem)
    {
        case 0:
        {
            strcat(Dialog, "Alterar Vencimento\n");
            strcat(Dialog, "Adicionar mais dias");
            Dialog_Show(playerid, VencimentoBaseADM, DIALOG_STYLE_TABLIST, "{FF0000}Vencimento", Dialog, "Confirmar", "Fechar");
        }
        case 1: Dialog_Show(playerid, AlteraBaseNomeADM, DIALOG_STYLE_INPUT, "{FF0000}Nome", "Coloque abaixo o nome que deseja", "Confirmar", "Fechar");
        case 2: Dialog_Show(playerid, AlteraBaseTagADM, DIALOG_STYLE_INPUT, "{FF0000}Tag", "Coloque abaixo a tag que deseja", "Confirmar", "Fechar");
        case 3:
        {
            new id = GetPVarInt(playerid, "BaseADMID");
            strcat(Dialog, "Slot\tModelo\tEstado\n");
            for(new i=0; i < MAX_BASEVEH; i++)
            {
                if(vBase[id][i][SlotDataBase] == false) strcatEx(Dialog, "{FF0000}%d\t{CCCCCC}Esperando Configuração\n", i+1);
                else if(vBase[id][i][VeiculoModeloBase] == 0) strcatEx(Dialog, "{FF0000}%d\t{CCCCCC}Não Comprado\n", i+1);
                else if(vBase[id][i][VeiculoColocado] == false) strcatEx(Dialog, "{CCCCCC}%d\t{FFA500}%s\t{ff2d19}Desconectado\n", i+1, GetVehicleNameByModel(vBase[id][i][VeiculoModeloBase]));
                else strcatEx(Dialog, "{CCCCCC}%d\t{FFA500}%s\t{32CD32}Conectado\n", i+1, GetVehicleNameByModel(vBase[id][i][VeiculoModeloBase]));
            }
            Dialog_Show(playerid, MenuVeiculoBaseADM, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Veículos", Dialog, "Selecionar", "Fechar");
        }
        case 4: Dialog_Show(playerid, BasePrecoAdmin, DIALOG_STYLE_INPUT, "{FF0000}Preço", "Coloque o novo preço abaixo", "Confirmar", "Fechar");
        case 5: Dialog_Show(playerid, BaseDescontoAdmin, DIALOG_STYLE_INPUT, "{FF0000}Desconto", "Coloque o novo desconto abaixo", "Confirmar", "Fechar");
        case 6:
        {
            new id = GetPVarInt(playerid, "BaseADMID"),
                Query[128];
            Base[id][BloquearRenovacao] = (Base[id][BloquearRenovacao] ? (false) : (true));
            format(Query, sizeof(Query), "UPDATE `bases` SET `BloquearRenovacao` = %d WHERE `Numero` = %d", Base[playerid][BloquearRenovacao], id);
            mysql_query(IDConexao, Query, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar essa base");
            format(Query, sizeof(Query), "| ADMIN | Você mudou o status dessa base para %s", Base[playerid][BloquearRenovacao] ? ("Desbloqueado") : ("Bloqueado"));
            SendClientMessage(playerid, -1, Query);
        }
    }
    return 1;
}
