enum InfosComidaS
{
    NomeComida[35],
    PrecoComida,
    ComidaEstiloID,
    Float:QuantidadeComida
};

new Restaurante[][InfosComidaS] =
{
    {"Comidas", 0, 0, 0.0},
    {"Lasanha", 30, 1, 30.0},
    {"Bolonhesa", 50, 1, 30.0},
    {"Macarrão", 25, 1, 30.0},
    {"Sushi", 100, 1, 2.0},
    {"Frango Frito", 85, 1, 30.0},
    {"Feijoada", 60, 1, 30.0},
    {"Comidas Veganas", 0, 0, 0.0},
    {"Salada de Frutas", 25, 1, 30.0},
    {"Frutas Picadas", 25, 1, 30.0},
    {"Cookies Integrais", 25, 1, 30.0},
    {"Bebidas", 0, 0, 0.0},
    {"Coca-Cola", 15, 2, 30.0},
    {"Sprite", 12, 2, 30.0},
    {"Água", 5, 2, 30.0},
    {"Refrigerante", 20, 2, 30.0},
    {"Chá", 10, 2, 30.0}
};

new Pizzarias[][InfosComidaS] =
{
    {"Pizzas", 0, 0, 0.0},
    {"Pizza de Pepperoni", 120, 1, 30.0},
    {"Pizza de Bacon", 130, 1, 30.0},
    {"Pizza de Calabresa", 150, 1, 30.0},
    {"Pizza de Portuguesa", 200, 1, 30.0},
    {"Pizza Moda da Casa", 110, 1, 30.0},
    {"Pizza de Quarto Queijos", 120, 1, 30.0},
    {"Nuggets", 60, 1, 30.0},
    {"Bebidas", 0, 0, 0.0},
    {"Coca-Cola", 15, 2, 30.0},
    {"Sprite", 12, 2, 30.0},
    {"Água", 5, 2, 30.0},
    {"Refrigerante", 20, 2, 30.0},
    {"Chá", 10, 2, 30.0}
    
};

new Hamburgueria[][InfosComidaS] =
{
    {"Hamburgueres", 0, 0, 0.0},
    {"Big Mac", 70, 1, 30.0},
    {"Travis Scott", 150, 1, 30.0},
    {"CBO", 80, 1, 30.0},
    {"Quarteirão", 60, 1, 30.0},
    {"Mac Chicken", 50, 1, 30.0},
    {"Batatas-Fritas", 30, 1, 30.0},
    {"Saladas", 30, 1, 30.0},
    {"Bauru", 20, 1, 30.0},
    {"Sopa", 20, 1, 30.0},
    {"Nuggets", 60, 1, 30.0},
    {"Hambúrguers Veganos", 0, 0, 0.0},
    {"Hambúrguer Vegano de Feijão", 25, 1, 30.0},
    {"Hambúrguer de Feijão Acebolado", 25, 1, 30.0},
    {"Bebidas", 0, 0, 0.0},
    {"Coca-Cola", 15, 2, 30.0},
    {"Sprite", 12, 2, 30.0},
    {"Água", 5, 2, 30.0},
    {"Refrigerante", 20, 2, 30.0},
    {"Chá", 10, 2, 30.0} 
};

new Bares[][InfosComidaS] = 
{
    {"Petiscos", 0, 0, 0.0},
    {"Amendoim", 10, 1, 30.0},
    {"Salgadinho", 15, 1, 30.0},
    {"Feijão Verde", 30, 1, 30.0},
    {"Bebidas", 0, 0, 0.0},
    {"Cerveja", 20, 2, 30.0},
    {"Corote", 1, 2, 30.0},
    {"Caipirinha", 25, 2, 30.0},
    {"Vodka", 60, 2, 30.0},
    {"Malibu", 30, 2, 30.0},
    {"Vodquila", 100, 2, 30.0},
    {"Rum", 50, 2, 30.0},
    {"Gim", 80, 2, 30.0},
    {"Cuba Libre", 50, 2, 30.0},
    {"Absinto", 150, 2, 30.0}
};

new Donalds[][InfosComidaS] =
{
    {"Rosquinhas", 0, 0, 0.0},
    {"Amendoim", 10, 1, 30.0},
    {"Salgadinho", 15, 1, 30.0},
    {"Donalds", 20, 1, 30.0},
    {"Bebidas", 0, 0, 0.0},
    {"Coca-Cola", 15, 2, 30.0},
    {"Sprite", 12, 2, 30.0},
    {"Água", 5, 2, 30.0},
    {"Refrigerante", 20, 2, 30.0},
    {"Chá", 10, 2, 30.0} 
};

stock PegarEmpresaID()
{
    for(new i=1; i < MAX_EMPRESAS; i++){
        if(pEmpresa[i][Colocado] == true) continue;
        return i;
    }
    return -1; 
}

stock EstoqueValor(id){
    for(new d=0; d < sizeof(iEmpresa); d++){
        if(iEmpresa[d][eListaID] != pEmpresa[id][eInterior]) continue;
        return iEmpresa[d][EncomendaMoney];
    }
    return -1;
}

stock EntrarEmpresa(playerid, i)
{
    if(cAC[playerid][Travado] == true) return 1;
    // if(pMorreu[playerid][EstaCaido] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está ferido(a)");

    TogglePlayerControllable(playerid, 0);
    SetTimerEx("Destravar", 2000, false, "d", playerid);

    //Setar algumas informações
    GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
    SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);
    SetPVarInt(playerid, "InteriorPersonalizadoID", i);

    new vw = PegarEmpresaVw(i),
        Mensagem[128],
        iid = pEmpresa[i][eInterior];

    for(new d=0; d < sizeof(iEmpresa); d++) 
    {
        if(iEmpresa[d][eListaID] != iid) continue;
        SetPlayerVirtualWorld(playerid, vw);
        SetPlayerInterior(playerid, iEmpresa[d][Interior]);
        SetPlayerPos(playerid, iEmpresa[d][SaidaX], iEmpresa[d][SaidaY], iEmpresa[d][SaidaZ]);

        Jogador[playerid][uInteriorEx] = 2;
        if(!strcmp(pEmpresa[i][eDono], PegarNick(playerid))) format(Mensagem, sizeof(Mensagem), "| EMPRESA | Bem-Vindo(a) %s, Use: /MenuEmpresa", pEmpresa[i][eDono]);
        else if(!strcmp(pEmpresa[i][eDono], "*")) format(Mensagem, sizeof(Mensagem), "| EMPRESA | Você entrou na empresa {FF8C00}%d{FFFFFF} que não possui proprietário(a)", i);
        else format(Mensagem, sizeof(Mensagem), "| EMPRESA | Você entrou na empresa {FF8C00}%d{FFFFFF} que pertence {00BFFF}%s", i, pEmpresa[i][eDono]);
        SendClientMessage(playerid, -1, Mensagem); 
        break;
    }
    return 1;
}

/*EntregasEmpresa(id)
{
    new Qant = pEmpresa[id][eEntregasG];
    for(new i=0; i < MAX_FUNCIONARIOS; i++){
        Qant += pFuncionario[id][i][eEntregas]; 
    }
    return Qant;
}*/

stock PrecoEmpresaImpostos(casaid)
{
    new ValorMN = 5740*pEmpresa[casaid][eImpostos];
    return ValorMN;
}

stock QuantidadeFuncionario(empresaid)
{
    new qnt = 0;
    for(new i=0; i < MAX_FUNCIONARIOS; i++)
    {
        if(pFuncionario[empresaid][i][TemFunc] == false) continue;
        qnt++;
    }
    return qnt;
}

stock ReiniciarEmpresa(bool:modo)  
{
    new Enviar[450],
        Llbr;
    
    print("[Rippzy:Empresa] Salvando Empresas.");
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        if(!strcmp(pEmpresa[i][eDono], "*")) continue;
        
        // String
        new LiberacaoMotivo[50] = "*";

        // Adicionar
        if(modo == true) 
        {
            pEmpresa[i][eImpostos]++;
            if(pEmpresa[i][eImpostos] >= 7) LiberacaoMotivo = "Impostos Atrasados";
        }

        if(strcmp(LiberacaoMotivo, "*")) 
        {
            Llbr++;
            RemoverEmpresaSql(i);
        }
        else
        {
            format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Concluidas` = %d, `Fabricacao` = %d, `Cofre` = %d, `Impostos` = %d, `MateriasPrimas` = %d, `Entregas` = %d, `Producao` = %d, `Consumo` = %d, `MediaEntregas` = %d, `CaixasFabrica` = %d, `Estoque` = %d WHERE `Numero` = %d", pEmpresa[i][eConcluidas], pEmpresa[i][eFabricacao], pEmpresa[i][eCofre], pEmpresa[i][eImpostos], pEmpresa[i][eMateriaPrima], pEmpresa[i][eEntregasG], pEmpresa[i][eProducao], pEmpresa[i][eConsumo], pEmpresa[i][eEntregasValor], pEmpresa[i][eCaixasFabrica], pEmpresa[i][eEstoque], i);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) printf("[ RC-Empresa ] Houve um problema ao salvar a empresa número %d", pEmpresa[i][eNumero]);
        }
    }
    printf("[Rippzy:Empresa] Empresas salvas com sucesso. ( Liberadas: %d )", Llbr);
    return 1;
}

stock PegarEmpresaVw(id)
{
    new vw = id;
    vw++;
    vw = (vw*vw);
    return vw;
}

stock PegarTipoEmpresa(id)
{
    new iid = pEmpresa[id][eInterior];
    for(new d=0; d < sizeof(iEmpresa); d++) 
    {
        if(iEmpresa[d][eListaID] != iid) continue;
        return iEmpresa[d][EmpresaType];
    }
    return -1;
}

stock PegarTipoInteriorEmpresa(id)
{
    new iid;
    for(new d=0; d < sizeof(iEmpresa); d++) {
        if(iEmpresa[d][eListaID] != pEmpresa[id][eInterior]) continue;
        iid = d;
        break;
    }
    return iid;
}

stock SalvarMateriasFabrica(id)
{
    new Enviar[80];
    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `MateriasPrimas` = %d WHERE `Numero` = %d", pEmpresa[id][eMateriaPrima], id);
    mysql_query(IDConexao, Enviar, false);
    return 1;
}

stock SalvarEntregasFabrica(id)
{
    new Enviar[80];
    pEmpresa[id][eConcluidas] += 1;
    
    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Concluidas` = %d WHERE `Numero` = %d", pEmpresa[id][eConcluidas], id);
    mysql_query(IDConexao, Enviar, false);
    AtualizarEmpresa(id);
    return 1;
}

stock AtualizarCaixasFab(id)
{
    new Enviar[100];
    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `CaixasFabrica` = %d, `Fabricacao` = %d WHERE `Numero` = %d", pEmpresa[id][eConcluidas], pEmpresa[id][eFabricacao], id);
    mysql_query(IDConexao, Enviar, false);
    AtualizarEmpresa(id);
    return 1;
}

stock EnviarDinheiroFabricaEx(empresa, quantidade)
{
    if(!strcmp(pEmpresa[empresa][eDono], "*")) return 1;
    pEmpresa[empresa][eCofre] += quantidade;
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Cofre` = %d WHERE `Numero` = %d", pEmpresa[empresa][eCofre], empresa);
    mysql_query(IDConexao, Enviar, false);
    return 1;
}

// 0 - Nada?
// 1 - Funcionário
// 2 - Gerente
// 3 - Dono

stock GerarMercadoria(playerid) 
{
    new id = MinhaEmpresaID(playerid);
    if(id == -1) return true;
    new idx = SlotEmpresa(playerid, id);
    if(idx == -1) return 1;

    new Enviar[95];
    format(Enviar, sizeof(Enviar), "UPDATE `empresafuncionarios` SET `BaysideEntrega` = 1 WHERE `Empresa` = %d AND `Slot` = %d", id, idx);
    mysql_query(IDConexao, Enviar, false);

    pFuncionario[id][idx][BaysideEntrega] = true;
    return true;
}

stock AtualizarEmpresa(id)
{
    // Geral e Empresas
    DestroyDynamicMapIconEx(pEmpresa[id][eMapa]);
    DestroyDynamicPickupEx(pEmpresa[id][ePickup]);

    // Fabricas
    DestroyDynamic3DTextLabelEx(pEmpresa[id][eTexto]);

    // Hoteis
    RemoverHotelQuarto(id);
    
    // Atualização
    AdicionarEmpresa(id);
    return 1;
}

stock VerificarEmpFunc(const Dna[])
{
    for(new i=1; i < MAX_EMPRESAS; i++){
        if(pEmpresa[i][Colocado] == false) continue;
        for(new j=0; j < MAX_FUNCIONARIOS; j++){
            if(pFuncionario[i][j][TemFunc] == false) continue;
            if(strcmp(pFuncionario[i][j][Funcionario], Dna)) continue;
            return true;
        }
    }
    return false;
}

stock MinhaEmpresaID(playerid)
{
    new bbsa[30];
    format(bbsa, 30, PegarNick(playerid));
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        for(new j=0; j < MAX_FUNCIONARIOS; j++){
            if(pFuncionario[i][j][TemFunc] == false) continue;
            if(strcmp(pFuncionario[i][j][Funcionario], bbsa)) continue;
            return i;
        }
    }
    return -1;
}

stock PegarEmpresaCargoNome(id, idx) 
{
    new CargoN[16] = "N/A";
    switch(pFuncionario[id][idx][CargoEmpresa])
    {
        case 1: CargoN = "Funcionário(a)";
        case 2: CargoN = "Gerente";
        case 3: CargoN = "Dono(a)";
    }
    return CargoN;
}

stock SlotEmpresa(playerid, idx)
{
    for(new i=0; i < MAX_FUNCIONARIOS; i++)
    {
        if(pFuncionario[idx][i][TemFunc] == false) continue;
        if(strcmp(pFuncionario[idx][i][Funcionario], PegarNick(playerid))) continue;
        return i;
    }
    return -1;
}

stock VerificarSeTemFuncionarios(id)
{
    for(new i=0; i < MAX_FUNCIONARIOS; i++){
        if(i == 0) continue;
        return pFuncionario[id][i][TemFunc];
    } 
    return false;
}

stock EnviarDinheiroEmpresa(empresa, quantidade)
{
    new Fdss = quantidade;
    new NovaQnat = (Fdss * 20) / 100;
    new SAD = quantidade-=NovaQnat;
    new Enviar[128];
    pEmpresa[empresa][eCofre] += SAD;
    pEmpresa[empresa][eConsumo] += SAD;

    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Consumo` = %d, `Cofre` = %d WHERE `Numero` = %d", pEmpresa[empresa][eConsumo], pEmpresa[empresa][eCofre], empresa);
    mysql_query(IDConexao, Enviar, false);
    return 1;
}

stock EnviarDinheiroEmpresaEx(id, quantidade, bool:Consumo = false) 
{
    pEmpresa[id][eEntregasValor] += quantidade;
    pEmpresa[id][eCofre] += quantidade;
    if(Consumo == true){
        pEmpresa[id][eConsumo] += quantidade;
    }

    new Enviar[148];
    format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Consumo` = %d, `MediaEntregas` = %d, `Cofre` = %d WHERE `Numero` = %d", pEmpresa[id][eConsumo], pEmpresa[id][eEntregasValor], pEmpresa[id][eCofre], id);
    mysql_query(IDConexao, Enviar, false);
    return 1;
}

stock PegarCargoEmpresa(const FuncioNome[])
{
    for(new idx=0; idx < MAX_EMPRESAS; idx++)
    {
        if(pEmpresa[idx][Colocado] == false) continue;
        for(new i=0; i < MAX_FUNCIONARIOS; i++)
        {
            if(pFuncionario[idx][i][TemFunc] == false) continue;
            if(strcmp(pFuncionario[idx][i][Funcionario], FuncioNome)) continue;
            return pFuncionario[idx][i][CargoEmpresa];
        }
    }
    return 0;
}

stock RemoverEmpresaSql(id)
{
    new Enviar[560];
    strcatEx(Enviar, "UPDATE `empresas` SET `Dono`= '*', `JPreco` = 0, `Cofre` = 0, `Consumo` = 0, `Producao` = 0, `MediaEntregas` = 0, `Entregas` = 0, `Impostos` = 0, `Mensagem` = '*', `Estoque` = 0 WHERE `Numero` = %d; ", id);
    strcatEx(Enviar, "DELETE FROM `empresafuncionarios` WHERE `Empresa` = %d", id);
    mysql_query(IDConexao, Enviar, false);

    new lasd[FuncionarioInfo];
    for(new i=0; i < MAX_FUNCIONARIOS; i++){
        pFuncionario[id][i] = lasd;
    }

    pEmpresa[id][eJPreco] = 0;
    pEmpresa[id][eImpostos] = 0;
    pEmpresa[id][eMateriaPrima] = 0;
    pEmpresa[id][eEntregasG] = 0;
    pEmpresa[id][eProducao] = 0;
    pEmpresa[id][eCofre] = 0;
    pEmpresa[id][eConsumo] = 0;
    pEmpresa[id][eEstoque] = 0;
    pEmpresa[id][eConcluidas] = 0;
    pEmpresa[id][eCaixasFabrica] = 0;
    pEmpresa[id][eFabricacao] = 0;
    pEmpresa[id][eEntregasValor] = 0;
    pEmpresa[id][Colocado] = false;

    format(pEmpresa[id][eDono], 90, "*");
    format(pEmpresa[id][eMensagem], 90, "*");

    // AtualizarEmpresa(id);
    return 1;
}

stock FuncionarioFunc(const Ncc[], id)
{
    for(new i=0; i < MAX_FUNCIONARIOS; i++)
    {
        if(pFuncionario[id][i][TemFunc] == false) continue;
        if(!strcmp(pFuncionario[id][i][Funcionario], Ncc)) return true;
    }
    return false;
}

stock PegarEmpresaNick(const Ncc[])
{
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        for(new d=0; d < MAX_FUNCIONARIOS; d++)
        {
            if(pFuncionario[i][d][TemFunc] == false) continue;
            if(strcmp(pFuncionario[i][d][Funcionario], Ncc)) continue;
            return i;
        }
    }
    return -1;
}

stock EmpresaTipo(id)
{
    new ListaAli;
    for(new i=0; i < sizeof(iEmpresa); i++){
        if(iEmpresa[i][eListaID] != pEmpresa[id][eInterior]) continue;
        ListaAli = i;
        break;
    }
    return ListaAli;
}

stock InteriorTipo(id)
{
    new fasda[90];
    strcat(fasda, iEmpresa[EmpresaTipo(id)][NomeInterior]);
    return fasda;
}