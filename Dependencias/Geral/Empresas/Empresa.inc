#include <YSI_Coding\y_hooks>

enum EmpresaIntt
{
    eListaID,
    Interior,
    Icone,
    Float:SaidaX,
    Float:SaidaY,
    Float:SaidaZ,
    Tipo[50],
    NomeInterior[90],
    InteriorNomeAdm[90],
    EmpresaType,
    EmpresaTypeCompra,
    EmpresaTypeComprada,
    GanhoMax,
    GanhoMin,
    TipoFabrica,
    EncomendaMoney
};


new iEmpresa[][EmpresaIntt] =
{
    //Utilitarios
    {1, 18, 17, -30.946699, -89.609596, 1003.546875, "Loja de Utilitários", "Loja de Utilitários", "Loja de Utilitários 1", 0, 19606, 19605, 5000, 4000, 2, 120000}, //Loja de Utilitários (1)
    {30, 17, 17, -25.9080, -187.8842, 1003.5469, "Loja de Utilitários", "Loja de Utilitários", "Loja de Utilitários 2", 0, 19606, 19605, 5000, 4000, 2, 120000}, //Loja de Utilitários (2)
    {31, 10, 17, 6.0760, -31.3044, 1003.5494, "Loja de Utilitários", "Loja de Utilitários", "Loja de Utilitários 3", 0, 19606, 19605, 5000, 4000, 2, 120000}, //Loja de Utilitários (3)

    //Loja de Comidas
    {2, 5, 29, 372.3141,-133.0576,1001.4922, "Lanchonetes", "Well Stacked Pizza", "Well Stacked Pizza", 0, 19606, 19605, 6000, 4000, 2, 40000}, //Pizzaria
    {3, 9, 14, 364.8413, -11.0870, 1001.8516, "Lanchonetes", "Cluckin' Bell", "Cluckin' Bell", 0, 19606, 19605, 6000, 4000, 2, 40000}, //Cluckin' bell
    {4, 10, 10, 363.0750, -74.8525, 1001.5078, "Lanchonetes", "Burguer Shot", "Burguer Shot", 0, 19606, 19605, 6000, 4000, 2, 40000}, //Burguer
    {5, 4, 50, 460.1335, -88.5683,999.5547, "Lanchonetes", "Jay's diner", "Jay's diner", 0, 19606, 19605, 6000, 4000, 2, 40000}, //Jay's diner
    {6, 18, 49, -228.8966,1401.1687,27.7656, "Lanchonetes", "Ufo", "Bar do Ufo", 0, 19606, 19605, 6000, 4000, 2, 40000}, //Ufo
    {7, 11, 49, 501.980987,-69.150199,998.757812, "Lanchonetes", "Bar", "Bar Comum", 0, 19606, 19605, 6000, 4000, 2, 40000}, //Bar  
    {8, 17, 50, 377.1717, -192.7773,1000.6401, "Lanchonetes", "Rusty browns donuts", "Rosquinha", 0, 19606, 19605, 6000, 4000, 2, 40000}, //Rosquiinha

    //Ammu
    {9, 7, 18, 314.820983, -141.431991, 999.601562, "Ammu-Nation", "Ammunation", "Ammunation Grande", 0, 19606, 19605, 6000, 4000, 0, 50000}, //Ammu (1)
    {10, 6, 18, 316.4519,-169.7756,999.6010, "Ammu-Nation", "Ammunation", "Ammunation Militar", 0, 19606, 19605, 6000, 4000, 0, 50000}, //Ammu Militar
    {26, 6, 18, 296.8062, -111.6715, 1001.5156, "Ammu-Nation", "Ammunation", "Ammunation Pequena", 0, 19606, 19605, 6000, 4000, 0, 50000}, //Ammu Pequena
    // {32, 1, 18, 285.3910, -41.6140, 1001.5156, "Ammu-Nation", "Ammunation", "Ammunation Padrão", 0, 19606, 19605, 6000, 4000, 0, 50000}, //Ammu Pequena
    {33, 4, 18, 285.8150, -86.3244, 1001.5229, "Ammu-Nation", "Ammunation", "Ammunation Pequena", 0, 19606, 19605, 6000, 4000, 0, 50000}, //Ammu Pequena

    //Loja de Roupas
    {11, 18, 45, 161.3365, -96.5243,1001.8047, "Loja de Skin", "Zip", "Zip", 0, 19606, 19605, 6000, 4000, 1, 30000}, //Zip
    {12, 1, 45, 203.7706, -50.1874,1001.8047, "Loja de Skin", "Suburban", "Suburban", 0, 19606, 19605, 6000, 4000, 1, 30000}, //SubUrban 
    {13, 5, 45, 226.9727, -8.2475,1002.2109, "Loja de Skin", "Victim", "Victim", 0, 19606, 19605, 6000, 4000, 1, 30000}, //Victim
    {14, 15, 45, 207.6632, -110.6852,1005.1328, "Loja de Skin", "Binco", "Binco", 0, 19606, 19605, 6000, 4000, 1, 30000}, //Binco
    {15, 14, 45, 204.3509, -168.2714,1000.5234, "Loja de Skin", "Didier Sachs", "Ds Skin", 0, 19606, 19605, 6000, 4000, 1, 30000}, //Ds Skin
    {16, 3, 45, 206.9580, -140.0532,1003.5078, "Loja de Skin", "ProLabs", "ProLabs", 0, 19606, 19605, 6000, 4000, 1, 30000}, //ProLabs

    //Diversos
    {17, 3, 21, -100.4532, -24.8650, 1000.7188, "Diversos", "SexShop", "SexShop", 0, 19606, 19605, 6000, 4000, 2, 20000}, //SexShop
    {18, 5, 54, 772.111999,-3.898649,1000.728820, "Diversos", "Academia", "Academia", 0, 19606, 19605, 6000, 4000, 2, 20000}, //Academia
    {27, 7, 54, 773.9105,-78.4121,1000.6622, "Diversos", "Academia (2)", "Academia Destruida", 0, 19606, 19605, 6000, 4000, 2, 20000}, //Academia
    {19, 17, 39, -204.3825,-8.7871,1002.2734, "Diversos", "Tatuagem", "Tatuagem", 0, 19606, 19605, 6000, 4000, 2, 20000}, //Tatuagem
    {20, 17, 48, 493.3417,-24.4304,1000.6797, "Diversos", "Balada", "Balada", 0, 19606, 19605, 6000, 4000, 2, 20000}, //Balada
    {21, 12, 7, 411.9189,-54.1292,1001.8984, "Diversos", "Barbearia", "Barbearia", 0, 19606, 19605, 6000, 4000, 2, 20000}, //Barbearia
    {22, 10, 25, 2018.6979,1017.9231,996.8750, "Diversos", "FourDragons", "FourDragons", 0, 19606, 19605, 15000, 6000, 2, 20000}, //FourDragons
    {23, 3, 21, -2636.7051,1402.8839,906.4609, "Diversos", "Puteiro", "Puteiro de San Fierro", 0, 19606, 19605, 6000, 4000, 2, 20000}, //Puteiro SF
    {25, 2, 21, 1204.7269,-13.3518,1000.9219, "Diversos", "Puteiro", "Puteiro de Los Santos", 0, 19606, 19605, 6000, 4000, 2, 20000}, //Puteiro LS
    {24, 12, 25, 1133.2107,-15.4149,1000.6797, "Diversos", "Royal Casino", "Royal Casino", 0, 19606, 19605, 15000, 6000, 2, 20000}, //Royal Casino
    {28, 1, 25, 2233.9341,1714.1890,1012.3695, "Diversos", "Caligulas", "Caligulas", 0, 19606, 19605, 10000, 6000, 2, 20000}, //Caligulas
    {29, 6, 47, -2240.6367,137.1840,1035.4141, "Diversos", "Zero RC", "Zero RC", 0, 19606, 19605, 6000, 4000, 2, 20000}, //Zero RC
    {38, 1, 35, 2265.2002,1619.4540,1090.4453, "Diversos", "Hotel", "Hotel", 0, 1277, 1277, 6000, 4000, 2, 20000}, // Hotel - Vermelho

    //Fabricas
    {34, 2, 20, 2531.6313,-1282.0238,1048.2891, "Fabricas", "Fabrica de Roupas", "Fabrica de Roupas", 1, 19606, 19605, 3000, 2000},
    {35, 2, 20, 2531.6313,-1282.0238,1048.2891, "Fabricas", "Fabrica de Armas", "Fabrica de Armas", 1, 19606, 19605, 3000, 2000},
    {37, 2, 20, 2531.6313,-1282.0238,1048.2891, "Fabricas", "Fabrica de Utilitários", "Fabrica de Utilitários", 1, 19606, 19605, 3000, 2000},
    {36, 2, 20, 2531.6313,-1282.0238,1048.2891, "Fabricas", "Fabrica de Comidas", "Fabrica de Comidas", 1, 19606, 19605, 3000, 2000}
};

hook OnGameModeInit()
{
    CarregarEmpresa();
    return 1;
}

function CarregarEmpresa()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `empresas`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Empresa] Não foi possivel conectar com o banco de dados das empresas\n");
        SendRconCommand("exit");
        return 1;
    }
    new EmpresaQNT = cache_num_rows(),
        id;
    if(EmpresaQNT < 1) return 1;
    printf("[Rippzy:Empresa] Iniciando carregamento de empresas %d empresas", EmpresaQNT);
    for(new i=0; i < EmpresaQNT; i++)
    {
        cache_get_value_name_int(i, "Numero", id);

        //Stings
        cache_get_value(i, "Dono", pEmpresa[id][eDono], 30);
        cache_get_value(i, "Mensagem", pEmpresa[id][eMensagem], 90);

        //Int
        cache_get_value_name_int(i, "Interior", pEmpresa[id][eInterior]);
        cache_get_value_name_int(i, "Cofre", pEmpresa[id][eCofre]);
        cache_get_value_name_int(i, "Preco", pEmpresa[id][ePreco]);
        cache_get_value_name_int(i, "JPreco", pEmpresa[id][eJPreco]);
        cache_get_value_name_int(i, "Impostos", pEmpresa[id][eImpostos]); 
        cache_get_value_name_int(i, "Bloqueada", pEmpresa[id][eBloqueada]);
        cache_get_value_name_int(i, "Entregas", pEmpresa[id][eEntregasG]);
        cache_get_value_name_int(i, "Producao", pEmpresa[id][eProducao]);
        cache_get_value_name_int(i, "Consumo", pEmpresa[id][eConsumo]);
        cache_get_value_name_int(i, "MediaEntregas", pEmpresa[id][eEntregasValor]);
        cache_get_value_name_int(i, "MateriasPrimas", pEmpresa[id][eMateriaPrima]);
        cache_get_value_name_int(i, "Fabricacao", pEmpresa[id][eFabricacao]);
        cache_get_value_name_int(i, "Concluidas", pEmpresa[id][eConcluidas]);
        cache_get_value_name_int(i, "CaixasFabrica", pEmpresa[id][eCaixasFabrica]);
        cache_get_value_name_int(i, "Estoque", pEmpresa[id][eEstoque]);

        //Floats
        cache_get_value_name_float(i, "PosicaoX", pEmpresa[id][ePosicaoX]);
        cache_get_value_name_float(i, "PosicaoY", pEmpresa[id][ePosicaoY]);
        cache_get_value_name_float(i, "PosicaoZ", pEmpresa[id][ePosicaoZ]);
        cache_get_value_name_float(i, "PosicaoA", pEmpresa[id][ePosicaoA]);

        //
        cache_get_value_name_float(i, "VeiculoX", pEmpresa[id][eVposX]);
        cache_get_value_name_float(i, "VeiculoY", pEmpresa[id][eVposY]);
        cache_get_value_name_float(i, "VeiculoZ", pEmpresa[id][eVposZ]);
        cache_get_value_name_float(i, "VeiculoA", pEmpresa[id][eVposA]);

        pEmpresa[id][eNumero] = id;
        AdicionarEmpresa(id);
    }
    cache_delete(Conectar);

    Conectar = mysql_query(IDConexao, "SELECT * FROM `empresafuncionarios`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Empresa] Não foi possivel conectar com o banco de dados dos funcionários\n");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Empresa] Conectando com o banco de dados de funcionários");
    EmpresaQNT = cache_num_rows();
    new idx;
    if(EmpresaQNT > 0)
    {
        for(new i=0; i < EmpresaQNT; i++)
        {
            // Informações da Empresa
            cache_get_value_name_int(i, "Empresa", id);
            cache_get_value_name_int(i, "Slot", idx);
            
            // Strings
            cache_get_value(i, "Nome", pFuncionario[id][idx][Funcionario], 30);
            
            // Int
            cache_get_value_name_int(i, "Entregas", pFuncionario[id][idx][Entregas]);
            cache_get_value_name_int(i, "BaysideEntrega", pFuncionario[id][idx][BaysideEntrega]);
            cache_get_value_name_int(i, "Bonus", pFuncionario[id][idx][BonusValor]);
            cache_get_value_name_int(i, "BonusFazer", pFuncionario[id][idx][BonusFazer]);
            cache_get_value_name_int(i, "Cargo", pFuncionario[id][idx][CargoEmpresa]);
            cache_get_value_name_int(i, "BonusProgresso", pFuncionario[id][idx][BonusEntrega]);
            cache_get_value_name_int(i, "Contratacao", pFuncionario[id][idx][Contratacao]);
            cache_get_value_name_int(i, "UltimaEntrega", pFuncionario[id][idx][UltimaEntrega]);
            pFuncionario[id][idx][TemFunc] = true;
        }
    }
    print("[Rippzy:Empresa] Funcionários de empresas foram carregados com sucesso");
    cache_delete(Conectar);

    
    print("[Rippzy:Empresa] Empresas foram carregadas com sucesso");
    CreateDynamic3DTextLabel("{00BFFF}Bayside{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para pegar", -1, -2434.1501,2308.9834,4.9844, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 15.0, -1);
    CreateDynamicPickup(1239, 1,-2434.1501,2308.9834,4.9844, 0, 0, -1, 60.0, -1);
    CreateDynamicMapIcon(-2434.1501,2308.9834,4.9844, 51, -1, 0, 0, -1, 150.0, MAPICON_GLOBAL, -1);
    return 1;
}

AdicionarEmpresa(id)
{
    if(id < 1) return 1;
    new Mensagem[900],
        IconeIDxE,
        ListaAli;
    
    for(new i=0; i < sizeof(iEmpresa); i++){
        if(iEmpresa[i][eListaID] != pEmpresa[id][eInterior]) continue;
        ListaAli = i;
        break;
    }

    if(iEmpresa[ListaAli][eListaID] == 38) CarregarHotel(id, PegarEmpresaVw(id));

    // Empresa não comprada
    if(!strcmp(pEmpresa[id][eDono], "*"))
    {
        strcatEx(Mensagem, "{FFFFFF}Empresa ID: %d\n", id);
        strcatEx(Mensagem, "%s\n", iEmpresa[ListaAli][NomeInterior]);
        strcatEx(Mensagem, "Preço: {32CD32}$%s\n", DinheiroSeparar(pEmpresa[id][ePreco]));
        strcat(Mensagem, "{1E90FF}/comprarempresa");
        pEmpresa[id][ePickup] = CreateDynamicPickup(iEmpresa[ListaAli][EmpresaTypeCompra], 1, pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ], 0, 0, -1, 49.0);
    }
    
    // Empresa comprada
    else
    {
        strcatEx(Mensagem, "{FF0000}Empresa ID: %d\n", id);
        strcatEx(Mensagem, "{FFFFFF}%s\n", iEmpresa[ListaAli][NomeInterior]);
        strcatEx(Mensagem, "{00BFFF}Dono(a) %s\n", pEmpresa[id][eDono]);
        // strcatEx(Mensagem, "{FFD700}Funcionarios(as): {FFFFFF}%d\n", QuantidadeFuncionario(id));
        strcatEx(Mensagem, "{228B22}Produção: {FFFFFF}%d\n", pEmpresa[id][eProducao]);
        if(strcmp(pEmpresa[id][eMensagem], "*")) strcatEx(Mensagem, "%s{FFFFFF}\n", pEmpresa[id][eMensagem]);
        if(pEmpresa[id][eJPreco] > 0) strcatEx(Mensagem, "{FFFFFF}Sendo vendida por {32CD32}$%s\n", DinheiroSeparar(pEmpresa[id][eJPreco]));
        strcat(Mensagem, "{1E90FF}/entrarempresa");   

        if(pEmpresa[id][eJPreco] > 0) pEmpresa[id][ePickup] = CreateDynamicPickup(iEmpresa[ListaAli][EmpresaTypeCompra], 1, pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ], 0, 0, -1, 90.0);
        else pEmpresa[id][ePickup] = CreateDynamicPickup(iEmpresa[ListaAli][EmpresaTypeComprada], 1, pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ], 0, 0, -1, 90.0);
    }

    for(new i=0; i < sizeof(iEmpresa); i++){
        if(iEmpresa[i][eListaID] != pEmpresa[id][eInterior]) continue;
        IconeIDxE = iEmpresa[i][Icone];
    }

    pEmpresa[id][Colocado] = true;
    pEmpresa[id][eMapa] = CreateDynamicMapIcon(pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ], IconeIDxE, -1, 0, 0, -1, 120.0, MAPICON_LOCAL);
    pEmpresa[id][eTexto] = CreateDynamic3DTextLabel(Mensagem, -1, pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0 && newkeys == KEY_SECONDARY_ATTACK){
        for(new i=0; i < MAX_EMPRESAS; i++){
            if(pEmpresa[i][Colocado] == false) continue;
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ])) continue;
            cmd_entrarempresa(playerid);
            break;
        }
        return 1;
    }

    else if(Jogador[playerid][uInteriorEx] == 2){
        new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
        if(casaid != 0 && GetPlayerVirtualWorld(playerid) > 0 && newkeys == KEY_SECONDARY_ATTACK){
            cmd_sairempresa(playerid);
        }
    }

    else if(newkeys == KEY_YES && GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0)
    {
        // Mercadorias
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, -2434.1501,2308.9834,4.9844)) return 1;
        if(GetPVarInt(playerid, "PegouMercaca") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já pegou uma encomenda");

        new id = MinhaEmpresaID(playerid);
        if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não trabalha ou possui nenhuma empresa");
        new idx = SlotEmpresa(playerid, id);
        if(pFuncionario[id][idx][BaysideEntrega] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode pegar");
        SetPVarInt(playerid, "PegouMercaca", 1);
        SendClientMessage(playerid, 0x00BFFFFF, "| PORTO | Você pegou uma encomenda, vá até sua empresa entregar");
    }
    return 1;
}

CMD:entrarempresa(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(Jogador[playerid][uInteriorEx] != 0) return 1; 
    if(Dialog_IsOpened(playerid)) return 1;
    if(GetPlayerInterior(playerid) != 0 && GetPlayerVirtualWorld(playerid) != 0) return 1;
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ])) continue;
        EntrarEmpresa(playerid, i);
        break;
    }   
    return 1;
}

CMD:sairempresa(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    if(Dialog_IsOpened(playerid)) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(id != 0 && GetPlayerVirtualWorld(playerid) > 0)
    {
        if(Jogador[playerid][uInteriorEx] != 2) return 1;
        for(new i=0; i < sizeof(iEmpresa); i++)
        {
            if(pEmpresa[id][eInterior] != iEmpresa[i][eListaID]) continue;
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, iEmpresa[i][SaidaX], iEmpresa[i][SaidaY], iEmpresa[i][SaidaZ])) continue;
            //if(!PodeSairFabrica(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode sair sem concluir o serviço.");
            TogglePlayerControllable(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
            SetPlayerPos(playerid, pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ]);
            SetTimerEx("Destravar", 3000, false, "d", playerid);
            Jogador[playerid][uInteriorEx] = 0;
            SetPVarInt(playerid, "InteriorPersonalizadoID", 0);
            break;
        }   
    }
    return 1;
}

CMD:comprarempresa(playerid)
{
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        if(!strcmp(PegarNick(playerid), pEmpresa[i][eDono])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já é proprietário(a) de uma empresa no servidor!");
        for(new d=0; d < MAX_FUNCIONARIOS; d++)
        {
            if(pFuncionario[i][d][TemFunc] == false) continue;
            if(!strcmp(pFuncionario[i][d][Funcionario], PegarNick(playerid))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está trabalhando em uma empresa");
        }
    }
    
    new bool:ePerto = false,
        Dialog[228];
    
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 4.0, pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ])) continue;
        if(strcmp(pEmpresa[i][eDono], "*") && pEmpresa[i][eJPreco] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa empresa já possui proprietário(a)");
        if(Jogador[playerid][Level] < 80) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você precisa de level 80 para comprar essa empresa");
        if(pEmpresa[i][eBloqueada] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa empresa foi bloqueada pelo desenvolvedor");
        
        if(strcmp(pEmpresa[i][eDono], "*")){
            if(!IsPlayerConnected(PegarIdPeloNick(pEmpresa[i][eDono]))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Proprietário(a) dessa empresa não se encontra online");
        }
        SetPVarInt(playerid, "EmpresaIDTartaruga", i);
        
        if(pEmpresa[i][eJPreco] > 0){
            if(Jogador[playerid][Dinheiro] < pEmpresa[i][eJPreco]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não possui dinheiro sucifiente para comprar essa empresa");
        }else{
            if(Jogador[playerid][Dinheiro] < pEmpresa[i][ePreco]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não possui dinheiro sucifiente para comprar essa empresa");
        }

        if(pEmpresa[i][eJPreco] > 0) strcatEx(Dialog, "{FFFFFF}Valor {32CD32}$%s\n", DinheiroSeparar(pEmpresa[i][eJPreco]));
        else strcatEx(Dialog, "{FFFFFF}Valor {32CD32}$%s\n", DinheiroSeparar(pEmpresa[i][ePreco]));
        strcat(Dialog, "{FFFFFF}Você realmente deseja comprar essa empresa?");
        Dialog_Show(playerid, CompraConfirmarEmpresa, DIALOG_STYLE_MSGBOX, "{00BFFF}Empresa Compra", Dialog, "Comprar", "Cancelar");
        ePerto = true;
        break; 
    }
    if(ePerto == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está perto de uma empresa");
    return 1;
}

CMD:menuempresa(playerid)
{
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(Jogador[playerid][uInteriorEx] != 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em uma empresa ou fábrica");
    if(strcmp(pEmpresa[id][eDono], PegarNick(playerid)) && !FuncionarioFunc(PegarNick(playerid), id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
    new Dialog[400];
    strcat(Dialog, "Opção\tAdicional\n");
    strcatEx(Dialog, "Funcionários(as)\t{FF8C00}%d\n", QuantidadeFuncionario(id));
    if(!strcmp(pEmpresa[id][eMensagem], "*")) strcat(Dialog, "Alterar Mensagem\t{FF8C00}-\n");
    else strcatEx(Dialog, "Alterar Mensagem\t{FFFFFF}%s\n", pEmpresa[id][eMensagem]);
    strcatEx(Dialog, "Cofre\t{32CD32}$%s\n", DinheiroSeparar(pEmpresa[id][eCofre]));
    strcat(Dialog, "Veículo Empresa\t{FF8C00}-\n");
    strcat(Dialog, "Encomendas\t{FF8C00}-\n");
    if(pEmpresa[id][eEstoque] == 0) strcat(Dialog, "Estoque\t{FF0000}Sem Estoque\n");
    else if(pEmpresa[id][eEstoque] == -1) strcat(Dialog, "Estoque\t{e2b960}Aguardando Entrega\n");
    else if(pEmpresa[id][eEstoque] == -2) strcat(Dialog, "Estoque\t{32CD32}Sendo Produzido\n");
    else strcatEx(Dialog, "Estoque\t{FF8C00}%d\n", pEmpresa[id][eEstoque]);
    strcat(Dialog, "{00FF00}Vender Empresa\t{FF8C00}-");
    Dialog_Show(playerid, MenuEmpresa, DIALOG_STYLE_TABLIST_HEADERS, "{1E90FF}Empresa", Dialog, "Selecionar", "Fechar");
    return 1;
}