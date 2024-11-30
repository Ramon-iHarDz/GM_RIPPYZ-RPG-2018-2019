#include <YSI_Coding\y_hooks>

enum ProducaoFabTEx{
    FabStatusEx,
    FabOjetoIDEx,
    FabEmpIdEx,
    FabCheckEx,
    FabMapEx,
    FabTypeEx
};

new pFabConce[MAX_PLAYERS][ProducaoFabTEx];

hook OnPlayerDisconnect(playerid, reason){
    DestroyDynamicObjectEx(pFabConce[playerid][FabOjetoIDEx]);
    DestroyDynamicCPEx(pFabConce[playerid][FabCheckEx]);
    DestroyDynamicMapIconEx(pFabConce[playerid][FabMapEx]);

    if(pFabConce[playerid][FabTypeEx] == 1){
        if(pFabConce[playerid][FabStatusEx] > 0){
            new id = pFabConce[playerid][FabEmpIdEx];
            Concessionaria[id][EstoqueConce] = -1;
        }
    }
    new sadas[ProducaoFabTEx];
    pFabConce[playerid] = sadas;
    return 1;
}

Dialog:PedidosFabricaEx(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new sata;
    for(new i=0; i < MAX_CONCESSIONARIA; i++)
    {
        if(Concessionaria[i][Colocado] == false) continue;
        if(!strcmp(Concessionaria[i][ConceDono], "*")) continue;
        if(Concessionaria[i][EstoqueConce] >= 0) continue;
        if(listitem != sata){  
            sata++;
            continue;   
        }
        if(Concessionaria[i][EstoqueConce] == -2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Já estão produzindo para essa empresa");
        Concessionaria[i][EstoqueConce] = -2;
        pFabConce[playerid][FabStatusEx] = 2;
        pFabConce[playerid][FabEmpIdEx] = i;
        pFabConce[playerid][FabTypeEx] = 1;
        SetPVarInt(playerid, "SaidaFab", 1);
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| FÁBRICA | Você está produzindo para concessionária %d.", i);
        SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
        break;
    }
    return 1;
}

Dialog:PedidosFabricaExMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new Dialog[2400];
            strcat(Dialog, "ID\tProprietário(a)\tLocal\tEstado\n");
            for(new i=0; i < MAX_CONCESSIONARIA; i++){
                if(Concessionaria[i][Colocado] == false) continue;
                if(!strcmp(Concessionaria[i][ConceDono], "*")) continue;
                if(Concessionaria[i][EstoqueConce] > 0) continue;
 
                if(Concessionaria[i][EstoqueConce] == -1) strcatEx(Dialog, "%d\t{00BFFF}%s\t{e2b960}%s\tAguardando\n", i, Concessionaria[i][ConceDono], AreaNome(Concessionaria[i][ConceX], Concessionaria[i][ConceY], Concessionaria[i][ConceZ]));
                else if(Concessionaria[i][EstoqueConce] == -2) strcatEx(Dialog, "%d\t{00BFFF}%s\t{e2b960}%s\tProduzindo\n", i, Concessionaria[i][ConceDono], AreaNome(Concessionaria[i][ConceX], Concessionaria[i][ConceY], Concessionaria[i][ConceZ]));
            }
            Dialog_Show(playerid, PedidosFabricaEx, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Fábricas", Dialog, "Confirmar", "Fechar");
        }
        case 1:
        {
            if(pTempo[playerid][FabricaProduc] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode fazer, volte novamente mais tarde.");
            pFabConce[playerid][FabStatusEx] = 2;
            pFabConce[playerid][FabTypeEx] = 2;
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
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1198.3597,1276.8523,1037.9102))
        {
            if(!FabricaPermissao(playerid, id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pFabConce[playerid][FabStatusEx] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem entregas");

            new Dialog[60];
            strcat(Dialog, "Pedidos de Concessionárias\n");
            strcat(Dialog, "Pedidos para BaySide");
            Dialog_Show(playerid, PedidosFabricaExMenu, DIALOG_STYLE_TABLIST, "{FF0000}Fábrica", Dialog, "Selecionar", "Fechar");
        }
    }
    else if(newkeys == KEY_CTRL_BACK)
    {
        if(Jogador[playerid][uInteriorEx] != 12) return 1;
        new id = GetPVarInt(playerid, "InteriorPersonalizadoID"),
            Float:Fgas[6],
            bool:Blocky,
            organizacao;

        switch(pFabConce[playerid][FabStatusEx])
        {
            
            case 2: {Fgas[0] = 1186.9625; Fgas[1] = 1201.7100; Fgas[2] = 1037.9102; Fgas[3] = 1192.6911; Fgas[4] = 1199.2492; Fgas[5] = 1037.5185; organizacao = 0;} // Etapa 1
            case 5: {Fgas[0] = 1187.2439; Fgas[1] = 1227.5432; Fgas[2] = 1037.9102; Fgas[3] = 1192.6911; Fgas[4] = 1226.2301; Fgas[5] = 1037.5185; organizacao = 1;} // Etapa 2
            case 8: {Fgas[0] = 1187.1711; Fgas[1] = 1251.1036; Fgas[2] = 1037.9102; Fgas[3] = 1192.6911; Fgas[4] = 1250.6018; Fgas[5] = 1037.5185; organizacao = 2;} // Etapa 3
            case 12: {Fgas[0] = 1187.3713; Fgas[1] = 1272.7625; Fgas[2] = 1037.9102; Fgas[3] = 1192.6911; Fgas[4] = 1275.0423; Fgas[5] = 1037.5185; organizacao = 3;} // Etapa 4
            case 15: {Fgas[0] = 1159.8416; Fgas[1] = 1213.9882; Fgas[2] = 1037.9102; Fgas[3] = 1163.9492; Fgas[4] = 1273.9924; Fgas[5] = 1037.5185; organizacao = 4;} // Etapa 5
            default: Blocky = true;
        }

        if(Blocky == true) return 1;
        if(IsPlayerInRangeOfPoint(playerid, 3.0, Fgas[0], Fgas[1], Fgas[2]))
        {
            if(!FabricaPermissao(playerid, id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(organizacao == 0) SetPVarInt(playerid, "ModeloFabrica", 12957);
            switch(organizacao)
            {
                case 0:
                {
                    TogglePlayerControllable(playerid, 0);
                    pFabConce[playerid][FabOjetoIDEx] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), Fgas[3], Fgas[4], Fgas[5], 0.0, 0.0, 0.0, PegarFabricaVw(id), 5, -1, 90.0, 90.0, -1);
                    pFabConce[playerid][FabStatusEx] = 3;
                    CriarProgresso(playerid, "Fazendo Etapa 1, aguarde.", "EtapaFabricaEx1", 600);
                }
                case 1:
                {
                    TogglePlayerControllable(playerid, 0);
                    DestroyDynamicObjectEx(pFabConce[playerid][FabOjetoIDEx]);
                    pFabConce[playerid][FabOjetoIDEx] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), Fgas[3], Fgas[4], Fgas[5], 0.0, 0.0, 0.0, PegarFabricaVw(id), 5, -1, 90.0, 90.0, -1);
                    pFabConce[playerid][FabStatusEx] = 6;
                    CriarProgresso(playerid, "Fazendo Etapa 2, aguarde.", "EtapaFabricaEx2", 600);    
                }
                case 2:
                {
                    TogglePlayerControllable(playerid, 0);
                    DestroyDynamicObjectEx(pFabConce[playerid][FabOjetoIDEx]);
                    pFabConce[playerid][FabOjetoIDEx] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), Fgas[3], Fgas[4], Fgas[5], 0.0, 0.0, 0.0, PegarFabricaVw(id), 5, -1, 90.0, 90.0, -1);
                    pFabConce[playerid][FabStatusEx] = 9;
                    CriarProgresso(playerid, "Fazendo Etapa 3, aguarde.", "EtapaFabricaEx3", 600);    
                }
                case 3:
                {
                    TogglePlayerControllable(playerid, 0);
                    DestroyDynamicObjectEx(pFabConce[playerid][FabOjetoIDEx]);
                    pFabConce[playerid][FabOjetoIDEx] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), Fgas[3], Fgas[4], Fgas[5], 0.0, 0.0, 0.0, PegarFabricaVw(id), 5, -1, 90.0, 90.0, -1);   
                    pFabConce[playerid][FabStatusEx] = 13;
                    CriarProgresso(playerid, "Mesa de Preparo, aguarde.", "EtapaFabricaEx4", 600);
                }
                case 4:
                {
                    DestroyDynamicObjectEx(pFabConce[playerid][FabOjetoIDEx]);  
                    EtapaFabricaEx5(playerid);
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
        if(pFabConce[i][FabOjetoIDEx] != objectid) continue;
        switch(pFabConce[i][FabStatusEx])
        {
            case 4:{
                pFabConce[i][FabStatusEx] = 5;    
                SendClientMessage(i, 0xFFFF00FF, "| FABRICA | Você fez a etepa 1. Vá para o passo 2");  
            }
            case 7:{
                pFabConce[i][FabStatusEx] = 8;    
                SendClientMessage(i, 0xFFFF00FF, "| FABRICA | Você fez a etepa 2. Vá para o passo 3");  
            }
            case 10:{
                pFabConce[i][FabStatusEx] = 11;
                DestroyDynamicObjectEx(pFabConce[i][FabOjetoIDEx]);
                pFabConce[i][FabOjetoIDEx] = CreateDynamicObject(GetPVarInt(i, "ModeloFabrica"), 2153.5712, -2272.1169, 12.9289, 0.0, 0.0, 0.0, PegarFabricaVw(GetPVarInt(i, "InteriorPersonalizadoID")), 0, -1, 90.0, 90.0, -1);
                MoveDynamicObject(pFabConce[i][FabOjetoIDEx], 2163.1108, -2262.6374, 13.0123, 1.5);
            }
            case 11:{
                pFabConce[i][FabStatusEx] = 12;
                SendClientMessage(i, 0xFFFF00FF, "| FABRICA | Você fez a etepa 4. Vá para o passo 5");  
            }
            case 14:{
                pFabConce[i][FabStatusEx] = 15;
            }
        }
        break;
    }
    return 1;
}

function EtapaFabricaEx1(playerid){
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicObjectEx(pFabConce[playerid][FabOjetoIDEx]);
    pFabConce[playerid][FabOjetoIDEx] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), 1192.6911, 1199.2492, 1037.5185, 0.0, 0.0, 0.0, PegarFabricaVw(id), 5, -1, 90.0, 90.0, -1);
    MoveDynamicObject(pFabConce[playerid][FabOjetoIDEx], 1192.6911, 1226.2301, 1037.5185, 1.5);
    pFabConce[playerid][FabStatusEx] = 4;
    return 1;
}

function EtapaFabricaEx2(playerid){
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicObjectEx(pFabConce[playerid][FabOjetoIDEx]);
    pFabConce[playerid][FabOjetoIDEx] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), 1192.6911, 1226.2301, 1037.5185, 0.0, 0.0, 0.0, PegarFabricaVw(id), 5, -1, 90.0, 90.0, -1);
    MoveDynamicObject(pFabConce[playerid][FabOjetoIDEx], 1192.6911, 1250.6018, 1037.5185, 1.5);
    pFabConce[playerid][FabStatusEx] = 7;
    return 1;
}

function EtapaFabricaEx3(playerid){
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicObjectEx(pFabConce[playerid][FabOjetoIDEx]);
    pFabConce[playerid][FabOjetoIDEx] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), 1192.6911, 1250.6018, 1037.5185, 0.0, 0.0, 0.0, PegarFabricaVw(id), 5, -1, 90.0, 90.0, -1);
    MoveDynamicObject(pFabConce[playerid][FabOjetoIDEx], 1192.6911, 1275.0423, 1037.5185, 1.5);
    SendClientMessage(playerid, 0xFFFF00FF, "| FABRICA | Você fez a etepa 3. Aguarde.");
    pFabConce[playerid][FabStatusEx] = 10;
    return 1;
}

function EtapaFabricaEx4(playerid){
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicObjectEx(pFabConce[playerid][FabOjetoIDEx]);
    pFabConce[playerid][FabOjetoIDEx] = CreateDynamicObject(GetPVarInt(playerid, "ModeloFabrica"), 1163.9492, 1273.9924, 1037.5185, 0.0, 0.0, 0.0, PegarFabricaVw(id), 5, -1, 90.0, 90.0, -1);
    MoveDynamicObject(pFabConce[playerid][FabOjetoIDEx], 1163.9492, 1215.9002, 1037.5185, 1.5);
    pFabConce[playerid][FabStatusEx] = 14;
    return 1;
}

stock EtapaFabricaEx5(playerid){
    SetPVarInt(playerid, "SaidaFab", 0);
    TogglePlayerControllable(playerid, 1);
    new Mensagem[128];
    SetPVarInt(playerid, "blueien", GetPVarInt(playerid, "InteriorPersonalizadoID"));

    switch(pFabConce[playerid][FabTypeEx])
    {
        case 1:
        {
            new id = pFabConce[playerid][FabEmpIdEx];
            pFabConce[playerid][FabMapEx] = CreateDynamicMapIcon(Concessionaria[id][ConceX], Concessionaria[id][ConceY], Concessionaria[id][ConceZ], 51, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
            pFabConce[playerid][FabCheckEx] = CreateDynamicCP(Concessionaria[id][ConceX], Concessionaria[id][ConceY], Concessionaria[id][ConceZ], 1.0, 0, 0, playerid, 20.0, -1);     
            format(Mensagem, sizeof(Mensagem), "| FÁBRICA | Você precisa ir até a concessionária ID: %d para entregar as chaves", id);
        }
        case 2:
        {
            pFabConce[playerid][FabMapEx] = CreateDynamicMapIcon(-2281.8577,2288.3420,4.9727, 51, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
            pFabConce[playerid][FabCheckEx] = CreateDynamicCP(-2281.8577,2288.3420,4.9727, 1.0, 0, 0, playerid, 20.0, -1);        
        }
        
    }
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pFabConce[playerid][FabCheckEx]) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    DestroyDynamicCPEx(pFabConce[playerid][FabCheckEx]);
    DestroyDynamicMapIconEx(pFabConce[playerid][FabMapEx]);
    new idfab = GetPVarInt(playerid, "blueien"),
        i = ProcurarFabricaIDFunc(PegarNick(playerid)), 
        Query[500];

    pFuncionarioFab[idfab][i][ProdFabrica]++; 
    pFabrica[idfab][FabricaProducao]++;
    pFabConce[playerid][FabStatusEx] = 0; 
    pTempo[playerid][FabricaProduc] = gettime()+4680;

    switch(pFabConce[playerid][FabTypeEx])
    {
        case 1:
        {
            new id = pFabConce[playerid][FabEmpIdEx];
            pFabrica[idfab][FabricaCofre] += 550000;
            strcatEx(Query, "UPDATE `concessionaria` SET `Estoque` = 20 WHERE `Numero` = %d; ", id); // SQL Empresa
            strcatEx(Query, "UPDATE `fabricas` SET `Producao` = %d, `Cofre` = %d WHERE `Numero` = %d; ", pFabrica[idfab][FabricaProducao], pFabrica[idfab][FabricaCofre], idfab); // SQL Fábrica
            strcatEx(Query, "UPDATE `fabricafuncionarios` SET `Producao` = %d WHERE `Slot` = %d AND `Fabrica` = %d", pFuncionarioFab[idfab][i][ProdFabrica], i, idfab); // SQL Funcionário
            mysql_query(IDConexao, Query, false);

            Concessionaria[id][EstoqueConce] = 50;
            AtualizarFabrica(idfab);
            format(Query, sizeof(Query), "| FÁBRICA | Você entregou as encomendas na concessionária (ID: %d)", id);
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