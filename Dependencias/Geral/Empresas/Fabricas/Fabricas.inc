#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `fabricafuncionarios`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Fabrica:Funcionarios] Não foi possivel conectar com o banco de dados dos funcionarios fabrica");
        SendRconCommand("exit");
        return 1;
    }

    new fabprog = cache_num_rows(),
        id;
    
    if(fabprog > 0){
        new idx;
        printf("[Rippzy:Fabrica:Funcionarios] Carregando %d funcionarios", fabprog);
        for(new i=0; i < fabprog; i++){
            cache_get_value_name_int(i, "Fabrica", id);
            cache_get_value_name_int(i, "Slot", idx);

            // Int
            cache_get_value_name_int(i, "Contratacao", pFuncionarioFab[id][idx][Contratacao]);
            cache_get_value_name_int(i, "Cargo", pFuncionarioFab[id][idx][CargoEmpresa]);
            cache_get_value_name_int(i, "Producao", pFuncionarioFab[id][idx][ProdFabrica]);
            cache_get_value_name_int(i, "Contratacao", pFuncionarioFab[id][idx][Contratacao]);

            // String
            cache_get_value(i, "Nome", pFuncionarioFab[id][idx][Funcionario], 30);
            pFuncionarioFab[id][idx][TemFunc] = true;
        }
        print("[Rippzy:Fabrica:Funcionarios] Funcionarios carregado com sucesso");
    }
    cache_delete(Conectar);

    Conectar = mysql_query(IDConexao, "SELECT * FROM `fabricas`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Fabrica] Não foi possivel conectar com o banco de dados das fabricas");
        SendRconCommand("exit");
        return 1;
    }

    fabprog = cache_num_rows();
    if(fabprog > 0)
    {
        printf("[Rippzy:Fabrica] Iniciando carregamento de fabricas %d fabricas", fabprog);
        for(new i=0; i < fabprog; i++)
        {
            //
            cache_get_value_name_int(i, "Numero", id);
            
            //
            cache_get_value(i, "Dono", pFabrica[id][fDono], 30);

            //
            cache_get_value_name_float(i, "PosicaoX", pFabrica[id][fPosicaoX]);
            cache_get_value_name_float(i, "PosicaoY", pFabrica[id][fPosicaoY]);
            cache_get_value_name_float(i, "PosicaoZ", pFabrica[id][fPosicaoZ]); 

            //
            cache_get_value_name_int(i, "Impostos", pFabrica[id][FabricaImposto]);
            cache_get_value_name_int(i, "Producao", pFabrica[id][FabricaProducao]);
            cache_get_value_name_int(i, "Preco", pFabrica[id][FabricaPreco]);
            cache_get_value_name_int(i, "Tipo", pFabrica[id][FabricaTipo]); 
            cache_get_value_name_int(i, "Cofre", pFabrica[id][FabricaCofre]);

            //
            cache_get_value_name_int(i, "Liquido", pFabrica[id][LiquidoTonel]);
            cache_get_value_name_int(i, "Reparo", pFabrica[id][ReparoTonel]);

            AdicionarFabrica(id);
        }
        print("[Rippzy:Fabrica] Fabricas carregadas com sucesso");
    }
    cache_delete(Conectar);
    return 1;
}

AdicionarFabrica(id)
{
    new Mensagem[600],
        IconeIDxE,
        vw = PegarFabricaVw(id);

    if(pFabrica[id][FabricaTipo] != 3)
    {
        pFabrica[id][LiquidosInfo] = CreateDynamicObject(19431, 2153.0759, -2245.8447, 14.8744, 0.0000, 0.0000, 58.1001, vw, 0, -1, 150.0, 150.0, -1); //wall071
        format(Mensagem, sizeof(Mensagem), "Liquidos: %d/100", pFabrica[id][LiquidoTonel]);
        SetDynamicObjectMaterialText(pFabrica[id][LiquidosInfo], 0, Mensagem, 90, "System", 15, 0, 0xFFD78E10, 0x0, 0);

        pFabrica[id][ReparoInfo] = CreateDynamicObject(19431, 2152.9733, -2245.7802, 14.4344, 0.0000, 0.0000, 58.1001, vw, 0, -1, 150.0, 150.0, -1); //wall071
        format(Mensagem, sizeof(Mensagem), "Reparo: %d%", pFabrica[id][ReparoTonel]);
        SetDynamicObjectMaterialText(pFabrica[id][ReparoInfo], 0, Mensagem, 90, "System", 15, 0, 0xFF840410, 0x0, 0);

        pFabrica[id][FabricaIDInfo] = CreateDynamicObject(19431, 2140.4934, -2248.7351, 14.7244, 0.0000, 0.0000, -44.7999, vw, 0, -1, 150.0, 150.0, -1); //wall071
        format(Mensagem, sizeof(Mensagem), "ID: %d", id);
        SetDynamicObjectMaterialText(pFabrica[id][FabricaIDInfo], 0, Mensagem, 90, "System", 20, 1, 0xFF840410, 0x0, 0);
        stringclear(Mensagem);
    }
    
    switch(pFabrica[id][FabricaTipo])
    {
        case 0: IconeIDxE = 18;
        case 1: IconeIDxE = 45;
        case 2: IconeIDxE = 25;
        case 3: IconeIDxE = 55;
    }

    // Não Comprado
    if(!strcmp(pFabrica[id][fDono], "*"))
    {
        strcatEx(Mensagem, "Fabrica ID: %d\n", id);
        strcatEx(Mensagem, "%s\n", PegarTipoFabrica(id));
        strcatEx(Mensagem, "Preço: {32CD32}$%s\n", DinheiroSeparar(pFabrica[id][FabricaPreco]));
        strcat(Mensagem, "{1E90FF}/comprarfabrica");
    }

    // Comprado
    else
    {
        strcatEx(Mensagem, "{FF0000}Fabrica ID: %d\n", id);
        strcatEx(Mensagem, "{FFFFFF}Dono(a): %s\n", pFabrica[id][fDono]);
        strcatEx(Mensagem, "{FFFFFF}Produção: {e2b960}%d\n", pFabrica[id][FabricaProducao]);
        strcatEx(Mensagem, "{FFFFFF}Funcionários(as): {e2b960}%d\n", QuantidadeFuncionarioFabrica(id));
        strcatEx(Mensagem, "%s\n", PegarTipoFabrica(id));
        strcat(Mensagem, "{1E90FF}/entrarfabrica");
    }

    ConfigurarMesasFabrica(id);
    ConfigurarInteriorFabrica(id);

    pFabrica[id][Colocado] = true;
    pFabrica[id][fPick] = CreateDynamicPickup(1239, 1, pFabrica[id][fPosicaoX], pFabrica[id][fPosicaoY], pFabrica[id][fPosicaoZ], 0, 0, -1, 90.0);
    pFabrica[id][fMapa] = CreateDynamicMapIcon(pFabrica[id][fPosicaoX], pFabrica[id][fPosicaoY], pFabrica[id][fPosicaoZ], IconeIDxE, -1, 0, 0, -1, 120.0, MAPICON_LOCAL);
    pFabrica[id][FabricaTexto] = CreateDynamic3DTextLabel(Mensagem, -1, pFabrica[id][fPosicaoX], pFabrica[id][fPosicaoY], pFabrica[id][fPosicaoZ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys){

    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0 && newkeys == KEY_SECONDARY_ATTACK)
    {
        for(new i=0; i < MAX_FABRICAS; i++){
            if(pFabrica[i][Colocado] == false) continue;
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, pFabrica[i][fPosicaoX], pFabrica[i][fPosicaoY], pFabrica[i][fPosicaoZ])) continue;
            cmd_entrarfabrica(playerid);
            break;
        }
        return 1;
    }
    else if(Jogador[playerid][uInteriorEx] == 12)
    {
        if(GetPVarInt(playerid, "InteriorPersonalizadoID") != 0 && GetPlayerVirtualWorld(playerid) > 0 && newkeys == KEY_SECONDARY_ATTACK){
            cmd_sairfabrica(playerid);
        }
    }
    return 1;
}

CMD:entrarfabrica(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(Jogador[playerid][uInteriorEx] != 0) return 1; 
    if(Dialog_IsOpened(playerid)) return 1;
    if(GetPlayerInterior(playerid) != 0 && GetPlayerVirtualWorld(playerid) != 0) return 1;
    for(new i=0; i < MAX_FABRICAS; i++)
    {
        if(pFabrica[i][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, pFabrica[i][fPosicaoX], pFabrica[i][fPosicaoY], pFabrica[i][fPosicaoZ])) continue;

        if(pFabrica[i][FabricaTipo] != 3) EntrarFabrica(playerid, i);
        else 
        {
            new Dialog[90];
            SetPVarInt(playerid, "KDLASDdasdsaASD", i);
            strcat(Dialog, "Opção\tAdicional\n");
            strcat(Dialog, "Entrar na Fábrica\n");
            strcat(Dialog, "Encomendar Veículos\t{32CD32}$800.000");
            Dialog_Show(playerid, FabricaEntrada, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Fábrica", Dialog, "Selecionar", "Fechar");
        }
        break;
    }
    return 1;
}

CMD:sairfabrica(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    if(Dialog_IsOpened(playerid)) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(id != 0 && GetPlayerVirtualWorld(playerid) > 0)
    {
        if(Jogador[playerid][uInteriorEx] != 12) return 1;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, 2120.0952,-2273.6880,20.6719) && !IsPlayerInRangeOfPoint(playerid, 3.0, 1142.7058,1285.1805,1037.9102)) return 1;
        if(GetPVarInt(playerid, "SaidaFab") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode sair em serviço");
        TogglePlayerControllable(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, pFabrica[id][fPosicaoX], pFabrica[id][fPosicaoY], pFabrica[id][fPosicaoZ]);
        SetTimerEx("Destravar", 3000, false, "d", playerid);
        Jogador[playerid][uInteriorEx] = 0;
        SetPVarInt(playerid, "InteriorPersonalizadoID", 0);
    }
    return 1;
}

CMD:comprarfabrica(playerid){
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(GetPlayerInterior(playerid) != 0 && GetPlayerVirtualWorld(playerid) != 0) return 1;
    for(new i=0; i < MAX_FABRICAS; i++)
    {
        if(pFabrica[i][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, pFabrica[i][fPosicaoX], pFabrica[i][fPosicaoY], pFabrica[i][fPosicaoZ])) continue;
        if(strcmp(pFabrica[i][fDono], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa fábrica já foi comprada");
        if(ProcurarFabricaID(PegarNick(playerid)) != -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já trabalha ou possui uma fábrica");
        if(Jogador[playerid][Dinheiro] < pFabrica[i][FabricaPreco]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");

        SetPVarInt(playerid, "ComprredFab", i);

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "Você realmente deseja comprar essa fábrica por {00FF00}R$%s", DinheiroSeparar(pFabrica[i][FabricaPreco]));
        Dialog_Show(playerid, ComprarFabricaConf, DIALOG_STYLE_MSGBOX, "Compra", Mensagem, "Comprar", "Fechar");
        break;
    }
    return 1;
}