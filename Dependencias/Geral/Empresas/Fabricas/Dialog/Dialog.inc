CMD:menufabrica(playerid)
{
    if(Jogador[playerid][uInteriorEx] != 12) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em uma fábrica");
    new permjogador = PermissaoFabrica(PegarNick(playerid));
    if(permjogador == -1) return 1; 

    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");

    new Dialog[400];
    strcat(Dialog, "Opção\tAdicional\n");
    strcatEx(Dialog, "Funcionários(as)\t{FF8C00}%d\n", QuantidadeFuncionarioFabrica(id));
    strcatEx(Dialog, "Cofre\t{32CD32}$%s\n", DinheiroSeparar(pFabrica[id][FabricaCofre]));    
    strcat(Dialog, "{00FF00}Vender Fábrica\t{FF8C00}-");
    Dialog_Show(playerid, MenuFabrica, DIALOG_STYLE_TABLIST_HEADERS, "{1E90FF}Fábrica", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:MenuFabrica(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        Dialog[600];

    new permjogador = PermissaoFabrica(PegarNick(playerid)); 
    switch(listitem)
    {
        // Funcionários
        case 0:
        {
            strcat(Dialog, "Slot\tFuncionário(a)\tCargo\n");
            for(new i=0; i < MAX_FUNCIONARIOSFAB; i++){ 
                if(pFuncionarioFab[id][i][TemFunc] == false) strcatEx(Dialog, "%d\t{FF0000}N/A\t{FF0000}N/A\n", i+1);
                else strcatEx(Dialog, "%d\t{00BFFF}%s\t{FFA500}%s\n", i+1, pFuncionarioFab[id][i][Funcionario], PegarCargoFuncionarioFab(id, i));
            }
            Dialog_Show(playerid, MenuFuncionariosFab, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Funcionários", Dialog, "Selecionar", "Fechar");
        }

        // Cofre
        case 1:
        {
            if(permjogador < 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pFabrica[id][FabricaCofre] < 300000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode retirar a partir de R$300.000");
            format(Dialog, sizeof(Dialog), "Você deseja retirar R$%s do cofre da sua fábrica", DinheiroSeparar(pFabrica[id][FabricaCofre]));
            Dialog_Show(playerid, CofreFabrica, DIALOG_STYLE_MSGBOX, "{FF0000}Cofre", Dialog, "Retirar", "Fechar");
        }

        // Vender Fábrica
        case 2:
        {
            new i = 0;
            if(i == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Opção não ativada no momento");
            if(permjogador < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            Dialog_Show(playerid, FabricaVenda, DIALOG_STYLE_INPUT, "{FF0000}Código", "Coloque abaixo o código da sua conta", "Confirmar", "Cancelar");
        }
    }

    return 1;
}

Dialog:MenuFuncionariosFab(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        i = listitem;
    SetPVarInt(playerid, "FabList", listitem);
    if(pFuncionarioFab[id][i][TemFunc] == false) return Dialog_Show(playerid, FuncionarioContratar, DIALOG_STYLE_INPUT, "{FF0000}Fábrica", "Coloque abaixo o ID do funcionário que deseja contratar", "Contratar", "Fechar");
    new permjogador = PermissaoFabrica(PegarNick(playerid));
    if(strcmp(pFuncionarioFab[id][i][Funcionario], PegarNick(playerid)) && permjogador < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    permjogador = PermissaoFabrica(pFuncionarioFab[id][i][Funcionario]);
    if(permjogador >= 2 && strcmp(pFabrica[id][fDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode visualizar o(a) dono(a)");

    new Dialog[400];
    strcat(Dialog, "Opção\tAdicional\n");
    strcatEx(Dialog, "Cargo\t{FFA500}%s\n", PegarCargoFuncionarioFab(id, i));
    strcatEx(Dialog, "Produção\t{FFA500}%d\n", pFuncionarioFab[id][i][ProdFabrica]);
    strcatEx(Dialog, "Contração\t{1E90FF}%s\n", GetDateFromTimeExx(pFuncionarioFab[id][i][Contratacao]));
    strcat(Dialog, "{FF0000}Demitir Funcionário(a)\t{1E90FF}-\n");
    Dialog_Show(playerid, FuncionarioMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Funcionário(a)", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:FabricaVenda(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1; 
    if(strcmp(Jogador[playerid][Codigo], inputtext)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Código informado está incorreto");
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    Jogador[playerid][Dinheiro] += pFabrica[id][FabricaPreco];
    LiberarFabricaSQL(id);
    return 1;
}

Dialog:CofreFabrica(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        Query[128];
    format(Query, sizeof(Query), "UPDATE `fabricas` SET `Cofre` = 0 WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema no cofre");
    format(Query, sizeof(Query), "| FÁBRICA | Você retirou {32CD32}R$%s{FFFFFF} do cofre da fábrica", DinheiroSeparar(pFabrica[id][FabricaCofre]));
    Jogador[playerid][Dinheiro] += pFabrica[id][FabricaCofre];
    pFabrica[id][FabricaCofre] = 0;
    SendClientMessage(playerid, -1, Query);
    return 1;
}

Dialog:FuncionarioMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        i = GetPVarInt(playerid, "FabList"),
        Dialog[128];
    new perm = PermissaoFabrica(pFuncionarioFab[id][i][Funcionario]),
        permjogador = PermissaoFabrica(PegarNick(playerid));

    switch(listitem)
    {
        case 0: // Cargo
        {
            if(permjogador < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(perm > permjogador) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão para alterar esse cargo");
            strcat(Dialog, "Funcionário(a)\n");
            strcat(Dialog, "Gerente");
            Dialog_Show(playerid, FuncionarioCargo, DIALOG_STYLE_TABLIST, "{FF0000}Cargo", Dialog, "Selecionar", "Fechar");
        }
        case 3: // Demitir
        {
            if(strcmp(pFuncionarioFab[id][i][Funcionario], PegarNick(playerid)) && strcmp(pFabrica[id][fDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(perm > permjogador) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão para alterar esse cargo");
            Dialog_Show(playerid, FuncionarioDemitir, DIALOG_STYLE_MSGBOX, "{FF0000}Demitir", "Você tem certeza que deseja remover esse(a) funcionário(a)", "Confirmar", "Cancelar");
        }
    }
    return 1;
}

Dialog:FuncionarioDemitir(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        i = GetPVarInt(playerid, "FabList"),
        Query[128];
    format(Query, sizeof(Query), "DELETE FROM `fabricafuncionarios` WHERE `Slot` = %d AND `Fabrica` = %d", i, id);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao demitir");

    format(Query, sizeof(Query), "| FÁBRICA | Você demitiu o(a) funcionário(a) %s da sua fábrica", pFuncionarioFab[id][i][Funcionario]);
    SendClientMessage(playerid, 0xFFFF00FF, Query);

    new emilylindacherosa[FuncionarioInfo];
    pFuncionarioFab[id][i] = emilylindacherosa;
    return 1;
}

Dialog:FabricaEntrada(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: EntrarFabrica(playerid, GetPVarInt(playerid, "KDLASDdasdsaASD"));
        case 1:
        {
            new id = PegarMinhaConce(playerid);
            if(id == -1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não possui uma concessionária");
            if(Concessionaria[id][EstoqueConce] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Sua concessionária ainda possui veículos");
            if(Concessionaria[id][EstoqueConce] == -1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já encomendou os veículos");
            if(Concessionaria[id][EstoqueConce] == -2) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Seus veículos já estão a caminho");
            if(Jogador[playerid][Dinheiro] < 800000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não possui $800.000 para comprar as chaves");
            Jogador[playerid][Dinheiro] -= 800000;

            new Query[128];
            format(Query, sizeof(Query), "UPDATE `concessionaria` SET `Estoque` = -1 WHERE `Numero` = %d", id);
            mysql_query(IDConexao, Query, false);
            Concessionaria[id][EstoqueConce] = -1;
            SendClientMessage(playerid, -1, "| FÁBRICA | Você encomendou {daa520}25 veículos{FFFFFF} por {32CD32}$1.500.000");
        }
    }
    return 1;
}

Dialog:FuncionarioCargo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Query[128],
        id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        i = GetPVarInt(playerid, "FabList");
    format(Query, sizeof(Query), "UPDATE `fabricafuncionarios` SET `Cargo` = %d WHERE `Fabrica` = %d AND `Slot` = %d", listitem, id, i);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao alterar o cargo");
    pFuncionarioFab[id][i][CargoEmpresa] = listitem;
    format(Query, sizeof(Query), "| FÁBRICA | Você alterou o cargo do(a) funcionário(a) %s para %s", pFuncionarioFab[id][i][Funcionario], PegarCargoFuncionarioFab(id, i));
    SendClientMessage(playerid, 0xFFFF00FF, Query);
    return 1;
}

Dialog:FuncionarioContratar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new pid;
    if(sscanf(inputtext, "d", pid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador Inválido");
    if(!IsPlayerConnected(pid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não está conectado(a)");
    if(Jogador[pid][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não está logado(a)");
    if(GetPVarInt(pid, "InteriorPersonalizadoID") != GetPVarInt(playerid, "InteriorPersonalizadoID")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Não está em sua fábrica");
    if(Jogador[pid][uInteriorEx] != 12) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não está em uma fábrica");
    if(ProcurarFabricaID(PegarNick(pid)) != -1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) já trabalha em uma fabrica"); 
    
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        i = GetPVarInt(playerid, "FabList"),
        Query[160];
    format(Query, sizeof(Query), "INSERT INTO `fabricafuncionarios` (`Nome`, `Slot`, `Fabrica`, `Contratacao`) VALUES ('%s', %d, %d, %d)", EscapeString(PegarNick(pid)), i, id, gettime());
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao adicionar");

    pFuncionarioFab[id][i][TemFunc] = true;
    pFuncionarioFab[id][i][Contratacao] = gettime();
    format(pFuncionarioFab[id][i][Funcionario], 30, PegarNick(pid));

    format(Query, sizeof(Query), "| FÁBRICA | Você agora está trabalhando na fábrica ID %d", id);
    SendClientMessage(pid, 0xFFFF00FF, Query);

    format(Query, sizeof(Query), "| FÁBRICA | Você contratou %s para sua fábrica", PegarNick(pid));
    SendClientMessage(playerid, 0xFFFF00FF, Query);
    return 1;
}

Dialog:ComprarFabricaConf(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new i = GetPVarInt(playerid, "ComprredFab");
    if(strcmp(pFabrica[i][fDono], "*")) return 1;
    new Query[400]; 
    format(Query, sizeof(Query), "UPDATE `fabricas` SET `Dono` = '%s' WHERE `Numero` = %d; ", EscapeString(PegarNick(playerid)), i);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao comprar [0x1]");

    format(Query, sizeof(Query), "INSERT INTO `fabricafuncionarios` (`Nome`, `Slot`, `Fabrica`, `Cargo`, `Contratacao`) VALUES ('%s', 0, %d, 2, %d)", EscapeString(PegarNick(playerid)), i, gettime());
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao comprar [0x2]");

    format(Query, sizeof(Query), "| FÁBRICA | O(A) Jogador(a) %s[%d] comprou uma fábrica ID %d localizada em %s", PegarNick(playerid), playerid, i, GetPlayerZone(playerid));
    SendClientMessageToAll(0xCCCCCCFF, Query);

    Jogador[playerid][Dinheiro] -= pFabrica[i][FabricaPreco];

    format(pFuncionarioFab[i][0][Funcionario], 30, PegarNick(playerid));
    pFuncionarioFab[i][0][TemFunc] = true;
    pFuncionarioFab[i][0][CargoEmpresa] = 2;
    pFuncionarioFab[i][0][Contratacao] = gettime();

    pFabrica[i][Colocado] = true;
    format(pFabrica[i][fDono], 30, PegarNick(playerid));

    AtualizarFabrica(i);
    return 1;
}