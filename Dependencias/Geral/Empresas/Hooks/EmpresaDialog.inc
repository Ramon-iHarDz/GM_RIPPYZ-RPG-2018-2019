Dialog:MenuEmpresa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        prrm = PegarCargoEmpresa(PegarNick(playerid));

    switch(listitem)
    {
        // Menu funcionário
        case 0: 
        {
            new Dialog[500];
            strcat(Dialog, "ID\tNome\tCargo\n");
            for(new i=0; i < MAX_FUNCIONARIOS; i++)
            {
                if(pFuncionario[id][i][TemFunc] == false) strcatEx(Dialog, "{FFFFFF}%d\t{FF0000}Sem Funcionário(a)\t{FFA500}N/A\n", i+1);
                else strcatEx(Dialog, "{FFFFFF}%d\t{00BFFF}%s\t{00BFFF}%s\t{FFA500}%d\n", i+1, pFuncionario[id][i][Funcionario], PegarEmpresaCargoNome(id, i), pFuncionario[id][i][Entregas]);
            }
            Dialog_Show(playerid, MenuFuncionario, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Funcionários(as)", Dialog, "Selecionar", "Fechar");
        }

        // Mensagem
        case 1:
        {
            if(prrm < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            Dialog_Show(playerid, AlterarMensagemEmp, DIALOG_STYLE_INPUT, "{FF0000}Mensagem", "Adicione abaixo uma mensagem para sua empresa", "Confirmar", "Fechar");
        }

        // Menu cofre
        case 2:
        {
            if(prrm < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            new Dialog[128];
            strcat(Dialog, "Opção\tAdicional\n");
            strcat(Dialog, "Informações\t{FF8C00}-\n");
            strcatEx(Dialog, "Sacar Dinheiro\t{32CD32}$%s", DinheiroSeparar(pEmpresa[id][eCofre]));
            Dialog_Show(playerid, MenuCofre, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Menu Cofre", Dialog, "Selecionar", "Fechar");
        }
        case 3: SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Desativada pelo desenvolvedor!");


        // Encomendas
        case 4:
        {
            if(GetPVarInt(playerid, "PegouMercaca") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pegou nenhuma encomenda");
            
            new intaa = PegarTipoInteriorEmpresa(id);
            
            new Enviar[158],
                HAsj = random(iEmpresa[intaa][GanhoMax]-iEmpresa[intaa][GanhoMin])+iEmpresa[intaa][GanhoMin],
                idx = SlotEmpresa(playerid, id);
        
            SetPVarInt(playerid, "PegouMercaca", 0);
            pFuncionario[id][idx][Entregas]++;
            format(Enviar, sizeof(Enviar), "UPDATE `empresafuncionarios` SET `Entregas` = %d, `BaysideEntrega` = 0, `UltimaEntrega` = %d WHERE `Empresa` = %d AND `Slot` = %d", pFuncionario[id][idx][Entregas], gettime(), id, idx);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve em problema ao efetuar entrega");

            pFuncionario[id][idx][BaysideEntrega] = false;
            Jogador[playerid][Dinheiro] += HAsj;
            pEmpresa[id][eEntregasG] += 1; 
            pEmpresa[id][eProducao] += 1;
            EnviarDinheiroEmpresaEx(id, HAsj);  

            format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Producao`=%d, `Entregas`=%d WHERE `Numero`=%d", pEmpresa[id][eProducao], pEmpresa[id][eEntregasG], id);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao salvar a empresa ( 0x2 )");

            format(Enviar, sizeof(Enviar), "| EMPRESA | Você entregou uma encomenda na empresa ( $%s )", DinheiroSeparar(HAsj));
            SendClientMessage(playerid, 0x1E90FFFF, Enviar);

            if(pFuncionario[id][idx][BonusValor] != 0 && pFuncionario[id][idx][BonusFazer] != 0)
            {
                pFuncionario[id][idx][BonusEntrega]++;
                format(Enviar, sizeof(Enviar), "UPDATE `empresafuncionarios` SET `BonusProgresso` = %d WHERE `Empresa` = %d AND `Slot` = %d", pFuncionario[id][idx][BonusEntrega], id, idx);
                mysql_query(IDConexao, Enviar, false);
                if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao salvar sua informações."); 
            }
            pFuncionario[id][idx][UltimaEntrega] = gettime();
            AtualizarEmpresa(id);
        }

        // Estoque
        case 5:
        {
            if(pEmpresa[id][eEstoque] == 666) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua empresa está aguardando a entrega das caixas.");
            if(pEmpresa[id][eEstoque] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua empresa ainda tem estoque, espere esvaziar");
            new Msg[80];
            if(Jogador[playerid][Dinheiro] < EstoqueValor(id)){
                format(Msg, sizeof(Msg), "| ERRO | Você não tem $%s para solicitar estoque", DinheiroSeparar(EstoqueValor(id)));
                SendClientMessage(playerid, 0xFF4500FF, Msg);
                return 1;
            }
            format(Msg, sizeof(Msg), "Você deseja comprar 50 estoque de caixas por $%s?", DinheiroSeparar(EstoqueValor(id)));
            Dialog_Show(playerid, EstoqueConfirmacao, DIALOG_STYLE_MSGBOX, "{FF0000}Estoque", Msg, "Confirmar", "Fechar");
        }

        // Venda Escolha
        case 6:
        {
            if(strcmp(pEmpresa[id][eDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(VerificarSeTemFuncionarios(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Retire todos os funcionários(as) da sua empresa");
            new Dialog[128];
            strcat(Dialog, "1. Liberar Empresa\n");
            strcat(Dialog, "2. Colocar Preço\n");
            if(pEmpresa[id][eJPreco] > 0) strcat(Dialog, "3. {FF0000}Remover Venda");
            Dialog_Show(playerid, VendaEscolhaEmpresa, DIALOG_STYLE_TABLIST, "{FF0000}Opção", Dialog, "Selecionar", "Fechar");
        }

    }
    return 0;
}

Dialog:EstoqueConfirmacao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        Msg[128];
    format(Msg, sizeof(Msg), "UPDATE `empresas` SET `Estoque` = -1 WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Msg, false);

    pEmpresa[id][eEstoque] = -1;
    Jogador[playerid][Dinheiro] -= EstoqueValor(id);
    
    format(Msg, sizeof(Msg), "| EMPRESA | Você solicitou um estoque de {FFA500}50{FFFFFF} caixas por {32CD32}$%s", DinheiroSeparar(EstoqueValor(id)));
    SendClientMessage(playerid, -1, Msg);
    return 1;
}

Dialog:MenuCofre(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        prrm = PegarCargoEmpresa(PegarNick(playerid));
    switch(listitem)
    {
        case 0:
        {
            new Dialog[248];
            strcatEx(Dialog, "{FFFFFF}Valor por Entregas: {32CD32}$%s\n", DinheiroSeparar(pEmpresa[id][eEntregasValor]));
            strcatEx(Dialog, "{FFFFFF}Valor do Cofre: {32CD32}$%s\n", DinheiroSeparar(pEmpresa[id][eCofre]));
            strcatEx(Dialog, "{FFFFFF}Valor por Consumo: {32CD32}$%s\n\n", DinheiroSeparar(pEmpresa[id][eConsumo])); 
            
            new c1 = pEmpresa[id][eEntregasValor],
                c2 = pEmpresa[id][eConsumo];
            new sdadsa = c1+c2;
            strcatEx(Dialog, "{FFFFFF}Total: {32CD32}$%s", DinheiroSeparar(sdadsa));
            Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_MSGBOX, "{FF0000}Informações do Cofre", Dialog, "Fechar", "");
        }
        case 1: 
        {
            if(prrm < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pEmpresa[id][eCofre] < 2000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode retirar seu dinheiro a partir de $2.000");
            Dialog_Show(playerid, DinheiroEmpresa, DIALOG_STYLE_MSGBOX, "{00FF00}Cofre", "Você realmente deseja retirar o dinheiro do cofre da sua empresa?", "Sim", "Não");
        }
    }
    return 1;
}

Dialog:VendaEscolhaEmpresa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, ConfirmarVendaEmpresa, DIALOG_STYLE_INPUT, "{FF0000}Confirmação", "Coloque abaixo o código da sua conta para confimar", "Selecionar", "Fechar");   
        case 1: Dialog_Show(playerid, VendaPrecoEmpresa, DIALOG_STYLE_INPUT, "{00FF00}Venda", "Coloque abaixo o preço que você está pedindo", "Selecionar", "Fechar");   
        case 2:
        {
            new Enviar[128],
                empresaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
            format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `JPreco` = 0 WHERE `Numero` = %d", empresaid);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao atualizar sua empresa");
            pEmpresa[empresaid][eJPreco] = 0;
            AtualizarEmpresa(empresaid);
        }
    }
    return 0;
}

Dialog:ConfirmarVendaEmpresa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strcmp(Jogador[playerid][Codigo], inputtext, true)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Código Inválido");
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(strcmp(pEmpresa[id][eDono], PegarNick(playerid))) return 1;
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "| EMPRESA | O(A) Jogador(a) {00BFFF}%s[%d]{FFFFFF} vendeu sua empresa id {00BFFF}%d", PegarNick(playerid), playerid, id);
    SendClientMessageToAll(-1, Enviar);
    Jogador[playerid][Dinheiro] += pEmpresa[id][ePreco];
    RemoverEmpresaSql(id);
    AtualizarEmpresa(id);
    cmd_sairempresa(playerid);
    return 0;
}

Dialog:VendaPrecoEmpresa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new PrecoJ;
    if(sscanf(inputtext, "d", PrecoJ)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Preço inválido");
    if(PrecoJ < 150000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você precisa colocar um valor maior que $150.000");
    if(PrecoJ > 70000000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você precisa colocar um valor menor que $70.000.000");

    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `JPreco` = %d WHERE `Numero` = %d", PrecoJ, id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao atualizar sua empresa");
    pEmpresa[id][eJPreco] = PrecoJ;

    format(Enviar, sizeof(Enviar), "| EMPRESA | Você colocou sua empresa para vender por {32CD32}$%s", DinheiroSeparar(PrecoJ));
    SendClientMessage(playerid, -1, Enviar);

    AtualizarEmpresa(id);
    return 0;
}

Dialog:DinheiroEmpresa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Mensagem[70],
        id = GetPVarInt(playerid, "InteriorPersonalizadoID");

    format(Mensagem, sizeof(Mensagem), "UPDATE `empresas` SET `Cofre` = 0 WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao atualizar sua empresa");

    format(Mensagem, sizeof(Mensagem), "| EMPRESA | Você retirou {32CD32}$%s reais{FFFFFF} da sua empresa.", DinheiroSeparar(pEmpresa[id][eCofre]));
    SendClientMessage(playerid, -1, Mensagem);
    Jogador[playerid][Dinheiro] += pEmpresa[id][eCofre]; 
    pEmpresa[id][eCofre] = 0;
    return 1;
}

Dialog:AlterarMensagemEmp(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(strlen(inputtext) > 40) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa mensagem está muito longa!");
    if(strlen(inputtext) < 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa mensagem está muito curta!");
    if(CaracterEspecial(inputtext)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar caracteres especiais!");

    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Mensagem` = '%s' WHERE `Numero` = %d", EscapeString(inputtext), id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao salvar essa mensagem!");

    format(pEmpresa[id][eMensagem], 90, inputtext);
    format(Enviar, sizeof(Enviar), "| EMPRESA | Você alterou a mensagem da sua empresa para {FFA500}%s", inputtext);
    SendClientMessage(playerid, -1, Enviar);
    AtualizarEmpresa(id);
    return 0;
}

Dialog:AdicionarFuncionario(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Coloque o ID do(a) novo(a) funcionario(a)");
    if(id == playerid) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode se adicionar");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não encontrado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não efetuou login");

    new idemp = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        idex = GetPVarInt(playerid, "EmpresaFID"),
        intex = pEmpresa[idemp][eInterior],
        Enviar[200];
    if(pEmpresa[idemp][eJPreco] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode contratar funcionários(as), sua empresa está a venda");
    new vw = PegarEmpresaVw(idemp);

    for(new i=0; i < MAX_FUNCIONARIOS; i++){
        if(pFuncionario[idemp][i][TemFunc] == false) continue;
        if(!strcmp(pFuncionario[idemp][i][Funcionario], PegarNick(id))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse(a) funcionário(a) já está trabalhando nessa empresa"); 
    }

    for(new i=0; i < MAX_EMPRESAS; i++){
        if(pEmpresa[i][Colocado] == false) continue;
        if(!strcmp(pEmpresa[i][eDono], PegarNick(id))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Já é dono(a) de uma empresa"); 
        for(new j=0; j < MAX_FUNCIONARIOS; j++){
            if(pFuncionario[i][j][TemFunc] == false) continue;
            if(!strcmp(pFuncionario[i][j][Funcionario], PegarNick(id))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse(a) funcionário(a) já está trabalhando em uma empresa!"); 
        }   
    }

    if(GetPlayerVirtualWorld(playerid) != vw) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não está em sua empresa");
    for(new i=0; i < sizeof(iEmpresa); i++) 
    {
        if(iEmpresa[i][eListaID] != intex) continue;
        if(GetPlayerInterior(id) != iEmpresa[i][Interior]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não está em sua empresa");
        if(!IsPlayerInRangeOfPoint(id, 4.0, iEmpresa[i][SaidaX], iEmpresa[i][SaidaY], iEmpresa[i][SaidaZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está perto da porta");
    }

    format(Enviar, sizeof(Enviar), "INSERT INTO `empresafuncionarios` (`Nome`, `Slot`, `Empresa`, `Contratacao`, `Cargo`) VALUES ('%s', %d, %d, %d, 1)", EscapeString(PegarNick(id)), idex, idemp, gettime());
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao adicionar esse(a) funcionario(a)");  
    format(Enviar, sizeof(Enviar), "| EMPRESA | Você agora está trabalhando na empresa ID %d que pertence a %s", idemp, PegarNick(playerid));
    SendClientMessage(id, 0xFFFF00FF, Enviar);
    format(Enviar, sizeof(Enviar), "| EMPRESA | %s está trabalhando na sua empresa", PegarNick(id));
    SendClientMessage(playerid, 0xFFFF00FF, Enviar);

    format(pFuncionario[idemp][idex][Funcionario], 30, PegarNick(id));
    pFuncionario[idemp][idex][Contratacao] = gettime();
    pFuncionario[idemp][idex][CargoEmpresa] = 1; 
    pFuncionario[idemp][idex][TemFunc] = true; 

    AtualizarEmpresa(idemp);
    return 1;
}

Dialog:TirarFuncionario(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new idemp = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        idex = GetPVarInt(playerid, "EmpresaFID"),
        Enviar[128];
    format(Enviar, sizeof(Enviar), "DELETE FROM `empresafuncionarios` WHERE `Slot` = %d AND `Empresa` = %d", idex, idemp);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao remover esse(a) funcionario(a)");  

    format(Enviar, sizeof(Enviar), "| EMPRESA | Você removeu da sua empresa %s", pFuncionario[idemp][idex][Funcionario]);
    SendClientMessage(playerid, 0x1E90FFFF, Enviar);
    if(IsPlayerConnected(PegarIdPeloNick(pFuncionario[idemp][idex][Funcionario])))
    {
        format(Enviar, sizeof(Enviar), "| EMPRESA | Você foi removido da empresa %d por %s", idemp, PegarNick(playerid));
        SendClientMessage(PegarIdPeloNick(pFuncionario[idemp][idex][Funcionario]), 0x1E90FFFF, Enviar);
    }

    new dsac[FuncionarioInfo];
    pFuncionario[idemp][idex] = dsac;

    AtualizarEmpresa(idemp);
    return 0;
}

Dialog:BonusValorMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new valor;
    if(sscanf(inputtext, "d", valor)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou um valor inválido");
    if(valor < 1000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou um valor abaixo de $1.000");
    if(valor > 150000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou um valor maior de $150.000");

    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        idex = GetPVarInt(playerid, "EmpresaFID");

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "UPDATE `empresafuncionarios` SET `Bonus` = %d WHERE `Slot` = %d AND `Empresa` = %d", valor, idex, id);
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao adicionar o valor bônus pra entrega");
    pFuncionario[id][idex][BonusValor] = valor;
    format(Mensagem, sizeof(Mensagem), "| EMPRESA | Você adicionou o valor do bônus por entrega {32CD32}$%s", DinheiroSeparar(valor));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:BonusEntregaMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new valor;
    if(sscanf(inputtext, "d", valor)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou um valor inválido");
    if(valor < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou um valor abaixo de 1");
    if(valor > 200) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou um valor maior de 200");

    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        idex = GetPVarInt(playerid, "EmpresaFID");

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "UPDATE `empresafuncionarios` SET `BonusFazer` = %d WHERE `Slot` = %d AND `Empresa` = %d", valor, idex, id);
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao adicionar bônus pra entrega");
    pFuncionario[id][idex][BonusFazer] = valor;
    format(Mensagem, sizeof(Mensagem), "| EMPRESA | Você adicionou o valor bônus em %d entrega(s)", valor);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:BonusMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        idex = GetPVarInt(playerid, "EmpresaFID"),
        Mensagem[128];
    
    switch(listitem)
    {
        case 0:
        {
            if(pFuncionario[id][idex][CargoEmpresa] > 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pFuncionario[id][idex][BonusValor] != 0)
            {
                format(Mensagem, sizeof(Mensagem), "UPDATE `empresafuncionarios` SET `BonusFazer` = 0 WHERE `Slot` = %d AND `Empresa` = %d", idex, id);
                mysql_query(IDConexao, Mensagem, false);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar esse funcionário");
                pFuncionario[id][idex][BonusValor] = 0;
                pFuncionario[id][idex][BonusEntrega] = 0;
                SendClientMessage(playerid, 0xFFFF00FF, "| EMPRESA | Você removeu o bônus de entrega");
                return 1;
            }
            if(pFuncionario[id][idex][BonusFazer] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa selecionar uma quantidade de entregas");
            Dialog_Show(playerid, BonusValorMenu, DIALOG_STYLE_INPUT, "{FF0000}Bônus", "Coloque o valor do bônus abaixo", "Selecionar", "Fechar");
        }
        case 1:
        {
            if(pFuncionario[id][idex][CargoEmpresa] > 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            Dialog_Show(playerid, BonusEntregaMenu, DIALOG_STYLE_INPUT, "{FF0000}Bônus", "Coloque abaixo a quantidade de entregas", "Selecionar", "Fechar");
        }
    }
    return 1;
}

Dialog:FuncionarioOpcao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        idex = GetPVarInt(playerid, "EmpresaFID"),
        prrm = PegarCargoEmpresa(PegarNick(playerid));

    switch(listitem)
    {
        // Bônus
        case 2:
        {
            if(prrm < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            new Dialog[228];
            strcat(Dialog, "Opção\tAdicional\n");
            if(pFuncionario[id][idex][BonusValor] == 0) strcat(Dialog, "Bônus\t{32CD32}N/A\n");
            else strcatEx(Dialog, "Bônus\t{32CD32}%s - {FF4500}Desativar\n", DinheiroSeparar(pFuncionario[id][idex][BonusValor]));
            strcatEx(Dialog, "Entregas\t{e2b960}%d", pFuncionario[id][idex][BonusFazer]);
            Dialog_Show(playerid, BonusMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Empresa", Dialog, "Selecionar", "Fechar");
        }

        // Pagamento
        case 3:
        {
            if(prrm < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pFuncionario[id][idex][BonusValor] == 0 || pFuncionario[id][idex][BonusFazer] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Bônus de entregas não configurado para esse funcionário");
            if(pFuncionario[id][idex][BonusEntrega] < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Bônus de entregas precisa estar no minimo 3");

            if(Jogador[playerid][Dinheiro] < pFuncionario[id][idex][BonusValor]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
            new ii = PegarIdPeloNick(pFuncionario[id][idex][Funcionario]);
            if(Jogador[ii][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não encontrado(a)");

            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "| EMPRESA | Você recebeu o pagamento de $%s da sua empresa", DinheiroSeparar(pFuncionario[id][idex][BonusValor]));
            SendClientMessage(ii, 0x1E90FFFF, Mensagem);

            format(Mensagem, sizeof(Mensagem), "| EMPRESA | Você pagou ao funcionário %s[%d] o valor de $%s", PegarNick(ii), ii, DinheiroSeparar(pFuncionario[id][idex][BonusValor]));
            SendClientMessage(playerid, 0x1E90FFFF, Mensagem);

            pFuncionario[id][idex][BonusEntrega] -= pFuncionario[id][idex][BonusFazer];
            Jogador[playerid][Dinheiro] -= pFuncionario[id][idex][BonusValor];
            Jogador[ii][Dinheiro] += pFuncionario[id][idex][BonusValor];
        }

        // Remover Funcionário
        case 7:
        {
            if(strcmp(pEmpresa[id][eDono], pFuncionario[id][idex][Funcionario]) && !strcmp(pFuncionario[id][idex][Funcionario], PegarNick(playerid))) Dialog_Show(playerid, TirarFuncionario, DIALOG_STYLE_MSGBOX, "{FF0000}Trabalho", "Você realmente deseja deixar de trabalhar aqui?", "Confirmar", "Cancelar");
            else
            {
                if(!strcmp(pEmpresa[id][eDono], pFuncionario[id][idex][Funcionario])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode sair da sua empresa");
                Dialog_Show(playerid, TirarFuncionario, DIALOG_STYLE_MSGBOX, "{FF0000}Trabalho", "Você realmente deseja para remover esse(a) funcionário(a)?", "Confirmar", "Cancelar");
            }
        }
    }
    return 1;
}

Dialog:MenuFuncionario(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        idex = listitem;

    if(pFuncionario[id][idex][TemFunc] == false)
    {
        if(PegarCargoEmpresa(PegarNick(playerid)) < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
        SetPVarInt(playerid, "EmpresaFID", idex);
        Dialog_Show(playerid, AdicionarFuncionario, DIALOG_STYLE_INPUT, "{FF0000}Adicionar Funcionario(a)", "Adicione abaixo o ID do(a) novo(a) funcionario(a)", "Contratar", "Cancelar");
        return 1;
    }

    new prrm = PegarCargoEmpresa(PegarNick(playerid)),
        Dialog[600];
    if(prrm < 2 && strcmp(pFuncionario[id][idex][Funcionario], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
    SetPVarInt(playerid, "EmpresaFID", idex);

    strcat(Dialog, "Opção\tAdicional\tAdicional\n");
    strcatEx(Dialog, "Funcionário(a)\t{FFA500}%s\n", pFuncionario[id][idex][Funcionario]);
    strcatEx(Dialog, "Entregas\t{1E90FF}%d\n", pFuncionario[id][idex][Entregas]);
    
    if(pFuncionario[id][idex][BonusValor] == 0) strcat(Dialog, "Bônus de Entrega\t{FF4500}Desativado\n"); 
    else strcatEx(Dialog, "Bônus de Entrega\t{32CD32}$%s\t{e2b960}Progresso: %d/%d\n", DinheiroSeparar(pFuncionario[id][idex][BonusValor]), pFuncionario[id][idex][BonusEntrega], pFuncionario[id][idex][BonusFazer]);

    strcat(Dialog, "{e2b960}Pagar Bônus\n");

    strcatEx(Dialog, "Bayside\t%s\n", pFuncionario[id][idex][BaysideEntrega] ? ("{FFD700}Encomendas Pendente") : ("{FF4500}Não há encomendas"));
    strcatEx(Dialog, "Última Entrega\t{e2b960}%s\n", ConverterSegundos(pFuncionario[id][idex][UltimaEntrega]));
    strcatEx(Dialog, "Contratação\t{e2b960}%s\n", GetDateFromTime(pFuncionario[id][idex][Contratacao]));
    if(prrm < 3) strcat(Dialog, "{FF0000}Sair do Emprego");
    else strcat(Dialog, "{FF0000}Expulsar Funcionário(a)");
    Dialog_Show(playerid, FuncionarioOpcao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Funcionário(a)", Dialog, "Selecionar", "Fechar");
    return 0;
}


Dialog:CompraConfirmarEmpresa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new i = GetPVarInt(playerid, "EmpresaIDTartaruga"),
        Enviar[600];
    
    if(strcmp(pEmpresa[i][eDono], "*") && pEmpresa[i][eJPreco] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa empresa já possui proprietário(a)");
    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Dono`= '%s', `JPreco` = 0, `Cofre` = 0, `Impostos` = 0, `Mensagem` = '*' WHERE `Numero` = %d", EscapeString(PegarNick(playerid)), i);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao comprar essa empresa");
    
    format(Enviar, sizeof(Enviar), "DELETE FROM `empresafuncionarios` WHERE `Empresa` = %d", i);
    mysql_query(IDConexao, Enviar, false);

    new Mensagem[128];
    if(pEmpresa[i][eJPreco] > 0)
    {
        format(Mensagem, sizeof(Mensagem), "| EMPRESA | O(A) Jogador(a) {00BFFF}%s[%d]{FFFFFF} comprou a empresa {00BFFF}%d{FFFFFF} do(a) jogador(a) {00BFFF}%s", PegarNick(playerid), playerid, i, pEmpresa[i][eDono]);
        Jogador[playerid][Dinheiro] -= pEmpresa[i][eJPreco];
        Jogador[PegarIdPeloNick(pEmpresa[i][eDono])][Dinheiro] += pEmpresa[i][eJPreco];
        SendClientMessageToAll(0xDCDCDCFF, Mensagem);

        format(Mensagem, sizeof(Mensagem), "| VENDA | Sua empresa foi comprada pelo(a) jogador(a) {FF0000}%s[%d]{FFFFFF} por {00FF00}$%s", PegarNick(playerid), playerid, DinheiroSeparar(pEmpresa[i][eJPreco]));
        SendClientMessage(PegarIdPeloNick(pEmpresa[i][eDono]), -1, Mensagem);

        format(Mensagem, sizeof(Mensagem), "| COMPRA | Você comprou essa empresa por {00FF00}$%s", DinheiroSeparar(pEmpresa[i][eJPreco]));
        SendClientMessage(playerid, -1, Mensagem);
    }
    else
    {
        format(Mensagem, sizeof(Mensagem), "| EMPRESA | O(A) Jogador(a) %s[%d] comprou a empresa %d localizada em %s", PegarNick(playerid), playerid, i, GetPlayerZone(playerid));
        Jogador[playerid][Dinheiro] -= pEmpresa[i][ePreco]; 
        SendClientMessageToAll(0xDCDCDCFF, Mensagem);
    }

    format(Enviar, sizeof(Enviar), "INSERT INTO `empresafuncionarios` (`Nome`, `Slot`, `Empresa`, `Contratacao`, `Cargo`) VALUES ('%s', 0, %d, %d, 3)", EscapeString(PegarNick(playerid)), i, gettime());
    mysql_query(IDConexao, Enviar, false);

    new lasdd[FuncionarioInfo];
    if(new d=0; d < MAX_FUNCIONARIOS; d++){
        pFuncionario[i][d] = lasdd;
    }

    format(pFuncionario[i][0][Funcionario], 30, PegarNick(playerid));
    pFuncionario[i][0][CargoEmpresa] = 3;
    pFuncionario[i][0][TemFunc] = true;
    pFuncionario[i][0][Contratacao] = gettime();

    // Setando Informações e resetando outras
    pEmpresa[i][eJPreco] = 0;
    pEmpresa[i][eImpostos] = 0;
    pEmpresa[i][eEntregasG] = 0;
    pEmpresa[i][eCofre] = 0;
    pEmpresa[i][eConsumo] = 0;
    pEmpresa[i][eEntregasValor] = 0;
    format(pEmpresa[i][eDono], 90, PegarNick(playerid));
    format(pEmpresa[i][eMensagem], 90, "*");
    
    AtualizarEmpresa(i);
    EntrarEmpresa(playerid, i);
    return 0;
}