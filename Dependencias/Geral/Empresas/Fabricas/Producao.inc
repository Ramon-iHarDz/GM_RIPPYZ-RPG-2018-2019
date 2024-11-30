#include <YSI_Coding\y_hooks>

enum ProducaoFabT{
    FabStatus,
    FabOjetoID,
    FabEmpId,
    FabCheck,
    FabMap,
    FabType
};

new pFab[MAX_PLAYERS][ProducaoFabT];

hook OnPlayerDisconnect(playerid, reason){
    DestroyDynamicObjectEx(pFab[playerid][FabOjetoID]);
    DestroyDynamicCPEx(pFab[playerid][FabCheck]);
    DestroyDynamicMapIconEx(pFab[playerid][FabMap]);

    if(pFab[playerid][FabType] == 1){
        if(pFab[playerid][FabStatus] > 0){
            new id = pFab[playerid][FabEmpId];
            pEmpresa[id][eEstoque] = -1;
        }
    }
    new sadas[ProducaoFabT];
    pFab[playerid] = sadas;
    return 1;
}

Dialog:PedidosFabrica(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new sata;
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        if(!strcmp(pEmpresa[i][eDono], "*")) continue;
        if(pEmpresa[i][eEstoque] >= 0) continue;
        if(iEmpresa[PegarTipoInteriorEmpresa(i)][TipoFabrica] != pFabrica[GetPVarInt(playerid, "InteriorPersonalizadoID")][FabricaTipo]) continue;
        if(listitem != sata){  
            sata++;
            continue;   
        }
        if(pEmpresa[i][eEstoque] == -2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Já estão produzindo para essa empresa");
        pEmpresa[i][eEstoque] = -2;
        pFab[playerid][FabStatus] = 1;
        pFab[playerid][FabEmpId] = i;
        pFab[playerid][FabType] = 1;
        SetPVarInt(playerid, "SaidaFab", 1);
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| FÁBRICA | Você está produzindo para empresa %d. Vá pegar o líquido nos toneis para começar.", i);
        SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
        break;
    }
    return 1;
}

Dialog:PedidosFabricaMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new Dialog[2400],
                id = GetPVarInt(playerid, "InteriorPersonalizadoID");
            strcat(Dialog, "ID\tProprietário(a)\tLocal\tEstado\n");
            for(new i=0; i < MAX_EMPRESAS; i++){
                if(pEmpresa[i][Colocado] == false) continue;
                if(!strcmp(pEmpresa[i][eDono], "*")) continue;
                if(pEmpresa[i][eEstoque] > 0) continue;
                if(iEmpresa[PegarTipoInteriorEmpresa(i)][TipoFabrica] != pFabrica[id][FabricaTipo]) continue;
                if(pEmpresa[i][eEstoque] == -1) strcatEx(Dialog, "%d\t{00BFFF}%s\t{e2b960}%s\tAguardando\n", i, pEmpresa[i][eDono], AreaNome(pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ]));
                else if(pEmpresa[i][eEstoque] == -2) strcatEx(Dialog, "%d\t{00BFFF}%s\t{e2b960}%s\tProduzindo\n", i, pEmpresa[i][eDono], AreaNome(pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ]));
            }
            Dialog_Show(playerid, PedidosFabrica, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Fábricas", Dialog, "Confirmar", "Fechar");
        }
        case 1:
        {
            if(pTempo[playerid][FabricaProduc] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode fazer, volte novamente mais tarde.");
            pFab[playerid][FabStatus] = 1;
            pFab[playerid][FabType] = 2;
            SetPVarInt(playerid, "SaidaFab", 1);
            SendClientMessage(playerid, 0xFFA500FF, "| FÁBRICA | Você precisa pegar o líquido para produzir, vá até a parte de baixo.");
        }
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_NO)
    {
        if(Jogador[playerid][uInteriorEx] != 12) return 1;
        new id = GetPVarInt(playerid, "InteriorPersonalizadoID");

        // Pedidos
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 2179.1050,-2249.7874,20.6746))
        {
            if(!FabricaPermissao(playerid, id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pFab[playerid][FabStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem entregas");

            new Dialog[60];
            strcat(Dialog, "Pedidos de Empresas\n");
            strcat(Dialog, "Pedidos para BaySide");
            Dialog_Show(playerid, PedidosFabricaMenu, DIALOG_STYLE_TABLIST, "{FF0000}Fábrica", Dialog, "Selecionar", "Fechar");
        }

        // Liquidos
        else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2154.8591,-2250.3179,13.2972))
        {
            if(!FabricaPermissao(playerid, id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pFab[playerid][FabStatus] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não confirmou o pedido");
            if(pFab[playerid][FabStatus] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está no processo de produção");
            if(pFabrica[id][LiquidoTonel] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há líquidos no tonel");
            if(pFabrica[id][ReparoTonel] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Está máquina está precisando de reparos.");
            new Mensagem[60];
            
            pFabrica[id][LiquidoTonel]--;
            pFab[playerid][FabStatus] = 2;

            format(Mensagem, sizeof(Mensagem), "Liquidos: %d/100", pFabrica[id][LiquidoTonel]);
            SetDynamicObjectMaterialText(pFabrica[id][LiquidosInfo], 0, Mensagem, 90, "System", 15, 0, 0xFFD78E10, 0x0, 0);
            if(random(100) > 60){
                pFabrica[id][ReparoTonel]--;
                format(Mensagem, sizeof(Mensagem), "Reparo: %d%", pFabrica[id][ReparoTonel]);
                SetDynamicObjectMaterialText(pFabrica[id][ReparoInfo], 0, Mensagem, 90, "System", 15, 0, 0xFF840410, 0x0, 0);
            }
            SendClientMessage(playerid, 0xFFFF00FF, "| FABRICA | Você pegou o líquido para iniciar as produções. Vá para Mesa ID 1");
        }

        // Empacotamento
        else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2162.9751,-2237.7522,13.3713))
        {
            if(!FabricaPermissao(playerid, id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão"); 
            if(pFab[playerid][FabStatus] != 16) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode fazer esse processo"); 
            pFab[playerid][FabStatus] = 17;
            ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
            RemovePlayerAttachedObject(playerid, 9);
            TogglePlayerControllable(playerid, 0);
            CriarProgresso(playerid, "Empacotando, aguarde.", "EtapaFabrica5", 600);
        }

    }
    else if(newkeys == KEY_CTRL_BACK)
    {
        if(Jogador[playerid][uInteriorEx] != 12) return 1;
        new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
            Float:Fgas[3],
            bool:Blocky,
            organizacao;

        switch(pFab[playerid][FabStatus])
        {
            case 2: {Fgas[0] = 2146.9045; Fgas[1] = -2265.5725; Fgas[2] = 12.7749; organizacao = 0;} // Etapa 1
            case 5: {Fgas[0] = 2148.8195; Fgas[1] = -2267.4768; Fgas[2] = 12.7749; organizacao = 1;} // Etapa 2
            case 8: {Fgas[0] = 2150.8547; Fgas[1] = -2269.5014; Fgas[2] = 12.7749; organizacao = 2;} // Etapa 3
            case 12: {Fgas[0] = 2161.9594; Fgas[1] = -2261.7885; Fgas[2] = 12.7600; organizacao = 3;} // Mesa de Reparo
            case 15: {Fgas[0] = 2167.5781; Fgas[1] = -2256.3222; Fgas[2] = 12.7600; organizacao = 4;} // Mesa de Verificação
            default: Blocky = true;
        }

        if(Blocky == true) return 1;
        if(IsPlayerInRangeOfPoint(playerid, 3.0, Fgas[0], Fgas[1], Fgas[2]))
        {
            if(!FabricaPermissao(playerid, id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(organizacao == 0){
                switch(pFabrica[id][FabricaTipo]){
                    case 0:{ // Armas
                        switch(random(5)){
                            case 0: SetPVarInt(playerid, "ModeloFabrica", 356);
                            case 1: SetPVarInt(playerid, "ModeloFabrica", 362);
                            case 2: SetPVarInt(playerid, "ModeloFabrica", 363);
                            case 3: SetPVarInt(playerid, "ModeloFabrica", 360);
                            case 4: SetPVarInt(playerid, "ModeloFabrica", 359);
                            case 5: SetPVarInt(playerid, "ModeloFabrica", 357);
                        }
                    }
                    case 1:{
                        switch(random(2)){
                            case 0: SetPVarInt(playerid, "ModeloFabrica", 2706); 
                            case 1: SetPVarInt(playerid, "ModeloFabrica", 2705);
                            case 2: SetPVarInt(playerid, "ModeloFabrica", 2704);
                        }
                    }
                    case 2:{
                        switch(random(5)){
                            case 0: SetPVarInt(playerid, "ModeloFabrica", 19878);
                            case 1: SetPVarInt(playerid, "ModeloFabrica", 19559);
                            case 2: SetPVarInt(playerid, "ModeloFabrica", 19308);
                            case 3: SetPVarInt(playerid, "ModeloFabrica", 1514);
                            case 4: SetPVarInt(playerid, "ModeloFabrica", 18919);
                            case 5: SetPVarInt(playerid, "ModeloFabrica", 19031);
                        }
                    }
                }
            }

            switch(organizacao)
            {
                case 0:
                {
                    TogglePlayerControllable(playerid, 0);
                    pFab[playerid][FabOjetoID] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), Fgas[0], Fgas[1], Fgas[2]+0.7, 0.0, 0.0, float(random(360)), PegarFabricaVw(id), 0, -1, 90.0, 90.0, -1);
                    pFab[playerid][FabStatus] = 3;
                    CriarProgresso(playerid, "Fazendo Etapa 1, aguarde.", "EtapaFabrica1", 600);
                }
                case 1:
                {
                    TogglePlayerControllable(playerid, 0);
                    DestroyDynamicObjectEx(pFab[playerid][FabOjetoID]);
                    pFab[playerid][FabOjetoID] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), Fgas[0], Fgas[1], Fgas[2]+0.7, 0.0, 0.0, float(random(360)), PegarFabricaVw(id), 0, -1, 90.0, 90.0, -1);
                    pFab[playerid][FabStatus] = 6;
                    CriarProgresso(playerid, "Fazendo Etapa 2, aguarde.", "EtapaFabrica2", 600);    
                }
                case 2:
                {
                    TogglePlayerControllable(playerid, 0);
                    DestroyDynamicObjectEx(pFab[playerid][FabOjetoID]);
                    pFab[playerid][FabOjetoID] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), Fgas[0], Fgas[1], Fgas[2]+0.7, 0.0, 0.0, float(random(360)), PegarFabricaVw(id), 0, -1, 90.0, 90.0, -1);
                    pFab[playerid][FabStatus] = 9;
                    CriarProgresso(playerid, "Fazendo Etapa 3, aguarde.", "EtapaFabrica3", 600);    
                }
                case 3:
                {
                    TogglePlayerControllable(playerid, 0);
                    DestroyDynamicObjectEx(pFab[playerid][FabOjetoID]);
                    pFab[playerid][FabOjetoID] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), Fgas[0], Fgas[1], Fgas[2]+0.7, 0.0, 0.0, float(random(360)), PegarFabricaVw(id), 0, -1, 90.0, 90.0, -1);   
                    pFab[playerid][FabStatus] = 13;
                    CriarProgresso(playerid, "Mesa de Preparo, aguarde.", "EtapaFabrica4", 600);
                }
                case 4:
                {
                    DestroyDynamicObjectEx(pFab[playerid][FabOjetoID]);  
                    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
                    SetPlayerAttachedObject(playerid, 9, 1220, 3, 0.1310, -0.4270, -0.1290, -7.3999, 3.4000, 29.9000, 0.5850, 0.5280, 0.6530, 0xFFFFFFFF, 0xFFFFFFFF);
                    pFab[playerid][FabStatus] = 16;
                }
            }
        }

    
    }
    return 1;
}

hook OnDynamicObjectMoved(objectid)
{
    for(new i=0; i < MAX_PLAYERS; i++){
        if(Jogador[i][uInteriorEx] != 12) continue;
        if(pFab[i][FabOjetoID] != objectid) continue;
        switch(pFab[i][FabStatus])
        {
            case 4:{
                pFab[i][FabStatus] = 5;    
                SendClientMessage(i, 0xFFFF00FF, "| FABRICA | Você fez a etepa 1. Vá para Mesa ID 2");  
            }
            case 7:{
                pFab[i][FabStatus] = 8;    
                SendClientMessage(i, 0xFFFF00FF, "| FABRICA | Você fez a etepa 2. Vá para Mesa ID 3");  
            }
            case 10:{
                pFab[i][FabStatus] = 11;
                DestroyDynamicObjectEx(pFab[i][FabOjetoID]);
                pFab[i][FabOjetoID] = CreateDynamicObject(GetPVarInt(i, "ModeloFabrica"), 2153.5712, -2272.1169, 12.9289, 0.0, 0.0, float(random(360)), PegarFabricaVw(GetPVarInt(i, "InteriorPersonalizadoID")), 0, -1, 90.0, 90.0, -1);
                MoveDynamicObject(pFab[i][FabOjetoID], 2163.1108, -2262.6374, 13.0123, 1.5);
            }
            case 11:{
                pFab[i][FabStatus] = 12;
                SendClientMessage(i, 0xFFFF00FF, "| FABRICA | Vá até a mesa de preparo");
            }
            case 14:{
                pFab[i][FabStatus] = 15;
                SendClientMessage(i, 0xFFFF00FF, "| FABRICA | Você fez o preparo. Vá para mesa de Verificação");  
            }
        }
        break;
    }
    return 1;
}

function EtapaFabrica1(playerid){
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicObjectEx(pFab[playerid][FabOjetoID]);
    pFab[playerid][FabOjetoID] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), 2145.6584, -2266.8728, 13.2993, 0.0, 0.0, float(random(360)), PegarFabricaVw(id), 0, -1, 90.0, 90.0, -1);
    MoveDynamicObject(pFab[playerid][FabOjetoID], 2147.6286, -2268.7346, 13.3025, 1.5);
    pFab[playerid][FabStatus] = 4;
    return 1;
}

function EtapaFabrica2(playerid){
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicObjectEx(pFab[playerid][FabOjetoID]);
    pFab[playerid][FabOjetoID] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), 2147.6286, -2268.7346, 13.3025, 0.0, 0.0, float(random(360)), PegarFabricaVw(id), 0, -1, 90.0, 90.0, -1);
    MoveDynamicObject(pFab[playerid][FabOjetoID], 2149.6286, -2270.7863, 13.3061, 1.5);
    pFab[playerid][FabStatus] = 7;
    return 1;
}

function EtapaFabrica3(playerid){
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicObjectEx(pFab[playerid][FabOjetoID]);
    pFab[playerid][FabOjetoID] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), 2149.6286, -2270.7863, 13.3061, 0.0, 0.0, float(random(360)), PegarFabricaVw(id), 0, -1, 90.0, 90.0, -1);
    MoveDynamicObject(pFab[playerid][FabOjetoID], 2151.6496, -2272.9677, 13.3103, 1.5);
    SendClientMessage(playerid, 0xFFFF00FF, "| FABRICA | Você fez a etepa 3. Aguarde.");
    pFab[playerid][FabStatus] = 10;
    return 1;
}

function EtapaFabrica4(playerid){
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicObjectEx(pFab[playerid][FabOjetoID]);
    pFab[playerid][FabOjetoID] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), 2163.1108, -2262.6374, 13.0123, 0.0, 0.0, float(random(360)), PegarFabricaVw(id), 0, -1, 90.0, 90.0, -1);
    MoveDynamicObject(pFab[playerid][FabOjetoID], 2168.7766, -2257.1325, 13.0027, 1.5);
    pFab[playerid][FabStatus] = 14;
    return 1;
}

function EtapaFabrica5(playerid){
    SetPVarInt(playerid, "SaidaFab", 0);
    TogglePlayerControllable(playerid, 1);
    new Mensagem[128];
    SetPVarInt(playerid, "blueien", GetPVarInt(playerid, "InteriorPersonalizadoID"));

    switch(pFab[playerid][FabType])
    {
        case 1:
        {
            new id = pFab[playerid][FabEmpId];
            pFab[playerid][FabMap] = CreateDynamicMapIcon(pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ], 51, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
            pFab[playerid][FabCheck] = CreateDynamicCP(pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ], 1.0, 0, 0, playerid, 20.0, -1);     
            format(Mensagem, sizeof(Mensagem), "| FÁBRICA | Você precisa ir até a empresa ID: %d para entregar", id);
        }
        case 2:
        {
            pFab[playerid][FabMap] = CreateDynamicMapIcon(-2281.8577,2288.3420,4.9727, 51, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
            pFab[playerid][FabCheck] = CreateDynamicCP(-2281.8577,2288.3420,4.9727, 1.0, 0, 0, playerid, 20.0, -1);        
        }
        
    }
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pFab[playerid][FabCheck]) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    DestroyDynamicCPEx(pFab[playerid][FabCheck]);
    DestroyDynamicMapIconEx(pFab[playerid][FabMap]);
    new idfab = GetPVarInt(playerid, "blueien"),
        i = ProcurarFabricaIDFunc(PegarNick(playerid)), 
        Query[500];

    pFuncionarioFab[idfab][i][ProdFabrica]++; 
    pFabrica[idfab][FabricaProducao]++;
    pFab[playerid][FabStatus] = 0; 
    pTempo[playerid][FabricaProduc] = gettime()+4680;

    switch(pFab[playerid][FabType])
    {
        case 1:
        {
            new id = pFab[playerid][FabEmpId];
            pFabrica[idfab][FabricaCofre] += EstoqueValor(id);
            strcatEx(Query, "UPDATE `empresas` SET `Estoque` = 50 WHERE `Numero` = %d; ", id); // SQL Empresa
            strcatEx(Query, "UPDATE `fabricas` SET `Producao` = %d, `Cofre` = %d WHERE `Numero` = %d; ", pFabrica[idfab][FabricaProducao], pFabrica[idfab][FabricaCofre], idfab); // SQL Fábrica
            strcatEx(Query, "UPDATE `fabricafuncionarios` SET `Producao` = %d WHERE `Slot` = %d AND `Fabrica` = %d", pFuncionarioFab[idfab][i][ProdFabrica], i, idfab); // SQL Funcionário
            mysql_query(IDConexao, Query, false);

            pEmpresa[id][eEstoque] = 50;
            AtualizarFabrica(idfab);
            format(Query, sizeof(Query), "| FÁBRICA | Você entregou as encomendas na empresa (ID: %d)", id);
            SendClientMessage(playerid, 0xFFFF00FF, Query);
        }
        case 2:
        {
            pFabrica[idfab][FabricaCofre] += random(45000-20000)+20000;     
            strcatEx(Query, "UPDATE `fabricas` SET `Producao` = %d, `Cofre` = %d WHERE `Numero` = %d; ", pFabrica[idfab][FabricaProducao], pFabrica[idfab][FabricaCofre], idfab); // SQL Fábrica
            strcatEx(Query, "UPDATE `fabricafuncionarios` SET `Producao` = %d WHERE `Slot` = %d AND `Fabrica` = %d", pFuncionarioFab[idfab][i][ProdFabrica], i, idfab); // SQL Funcionário
            mysql_query(IDConexao, Query, false);

            AtualizarFabrica(idfab);
            SendClientMessage(playerid, 0xFFFF00FF, "| FÁBRICA | Você entregou uma encomenda em Bayside");
        }
    }
    return 1;
}