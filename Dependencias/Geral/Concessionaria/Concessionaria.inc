#include <YSI_Coding\y_hooks>

hook OnGameModeInit(){
    new Cache:Conectar,
        QuantosTem = cache_num_rows(),
        id;

    Conectar = mysql_query(IDConexao, "SELECT * FROM `concessionariaveiculo`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Concessionaria:Veiculos] Não foi possivel estabelecer uma conexão nas concessionarias");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Concessionaria:Veiculos] Sistema de concessionarias [Veiculos] está sendo carregado.");

    QuantosTem = cache_num_rows();
    if(QuantosTem > 0)
    {
        new idx;
        for(new i=0; i < QuantosTem; i++)
        {
            cache_get_value_name_int(i, "Conce", id);
            cache_get_value_name_int(i, "Slot", idx);

            cache_get_value_name_float(i, "PosicaoX", vConcessionaria[id][idx][SpecVehX]);
            cache_get_value_name_float(i, "PosicaoY", vConcessionaria[id][idx][SpecVehY]);
            cache_get_value_name_float(i, "PosicaoZ", vConcessionaria[id][idx][SpecVehZ]);
            cache_get_value_name_float(i, "PosicaoA", vConcessionaria[id][idx][SpecVehA]);  
            vConcessionaria[id][idx][SpecDb] = true;
        }
        print("[Rippzy:Concessionaria:Veiculos] Sistema de concessionarias [Veiculos] foi carregado.");
    }
    cache_delete(Conectar);

    Conectar = mysql_query(IDConexao, "SELECT * FROM `concessionaria`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Concessionaria] Não foi possivel estabelecer uma conexão nas concessionarias");
        SendRconCommand("exit");
        return 1;
    }
    QuantosTem = cache_num_rows();
    if(QuantosTem > 0)
    {
        for(new i=0; i < QuantosTem; i++)
        {
            //Int
            cache_get_value_name_int(i, "Numero", id);
            cache_get_value_name_int(i, "Impostos", Concessionaria[id][ImpostosConce]);
            cache_get_value_name_int(i, "Estoque", Concessionaria[id][EstoqueConce]);
            cache_get_value_name_int(i, "Vendas", Concessionaria[id][VendasConce]);
            cache_get_value_name_int(i, "Preco", Concessionaria[id][PrecoConce]);
            cache_get_value_name_int(i, "Type", Concessionaria[id][TypeConce]);
            cache_get_value_name_int(i, "Modo", Concessionaria[id][ModoConce]); 
            cache_get_value_name_int(i, "Cofre", Concessionaria[id][CofreConce]);

            //String
            cache_get_value(i, "Dono", Concessionaria[id][ConceDono], 30);
            cache_get_value(i, "Mensagem", Concessionaria[id][ConceMsg], 128);
            
            //Float
            cache_get_value_name_float(i, "PosicaoX", Concessionaria[id][ConceX]);
            cache_get_value_name_float(i, "PosicaoY", Concessionaria[id][ConceY]);
            cache_get_value_name_float(i, "PosicaoZ", Concessionaria[id][ConceZ]);
            //
            cache_get_value_name_float(i, "VeiculoX", Concessionaria[id][vConceX]);
            cache_get_value_name_float(i, "VeiculoY", Concessionaria[id][vConceY]);
            cache_get_value_name_float(i, "VeiculoZ", Concessionaria[id][vConceZ]);
            cache_get_value_name_float(i, "VeiculoA", Concessionaria[id][vConceA]);
            CarregarConcessionaria(id);
        }
        print("[Rippzy:Concessionaria] Sistema de concessionarias carregado com sucesso.");
    }
    cache_delete(Conectar);

    return 1;
}

stock CarregarConcessionaria(id){
    new Mensagem[260];
    strcatEx(Mensagem, "{daa520}Concessionária (ID: %d)\n", id);
    strcatEx(Mensagem, "{FFA500}%s\n", PegarConcessionariaType(Concessionaria[id][TypeConce]));
    
    if(!strcmp(Concessionaria[id][ConceDono], "*")){
        strcatEx(Mensagem, "{FFFFFF}Preço: {32CD32}$%s\n", DinheiroSeparar(Concessionaria[id][PrecoConce]));   
        strcat(Mensagem, "{FFFFFF}Use: {CCCCCC}'/ComprarConcessionaria'{FFFFFF} para comprar\n");
        if(Concessionaria[id][ModoConce] == 1 || !strcmp(Concessionaria[id][ConceDono], "*")) strcat(Mensagem, "Aperte {CCCCCC}'Y'{FFFFFF} para interagir");
    }else{
        strcatEx(Mensagem, "{FFFFFF}Proprietário(a): {daa520}%s\n", Concessionaria[id][ConceDono]);
        strcatEx(Mensagem, "{FFFFFF}Compras Efetuadas: {daa520}%d\n", Concessionaria[id][VendasConce]);
        if(Concessionaria[id][ModoConce] == 1 || !strcmp(Concessionaria[id][ConceDono], "*")) strcat(Mensagem, "Aperte {CCCCCC}'Y'{FFFFFF} para interagir");
        else CarregarVeiculosConce(id);
    }
    Concessionaria[id][Colocado] = true; 
    Concessionaria[id][ConceTexto] = CreateDynamic3DTextLabel(Mensagem, -1, Concessionaria[id][ConceX], Concessionaria[id][ConceY], Concessionaria[id][ConceZ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    Concessionaria[id][ConceIcone] = CreateDynamicMapIcon(Concessionaria[id][ConceX], Concessionaria[id][ConceY], Concessionaria[id][ConceZ], 12, -1, 0, 0, -1, 70.0, MAPICON_LOCAL, -1);
    Concessionaria[id][ConcePick] = CreateDynamicPickup(1239, 1, Concessionaria[id][ConceX], Concessionaria[id][ConceY], Concessionaria[id][ConceZ], 0, 0, -1, 30.0, -1);
    Concessionaria[id][TimerConce] = SetTimerEx("ConcessionariaSync", 1200000, true, "d", id);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys){

    if(newkeys == KEY_YES){
        for(new i=0; i < MAX_CONCESSIONARIA; i++){
            if(Concessionaria[i][Colocado] == false) continue;
            if(!IsPlayerInRangeOfPoint(playerid, 2.0, Concessionaria[i][ConceX], Concessionaria[i][ConceY], Concessionaria[i][ConceZ])) continue;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(Concessionaria[i][ModoConce] != 1 && strcmp(Concessionaria[i][ConceDono], "*")) return 1;
            CarregarDrawConce(playerid, i, 0);
            break; 
        } 
    }
    else if(newkeys == KEY_CTRL_BACK){
        new bool:lasd;
        for(new i=0; i < MAX_CONCESSIONARIA; i++){
            if(Concessionaria[i][Colocado] == false) continue;
            for(new d=0; d < MAX_CONCESSIONARIA_VEH; d++){
                if(vConcessionaria[i][d][SpecDb] == false) continue;
                if(vConcessionaria[i][d][SpecColocado] == false) continue;

                new Float:Alpdd[3];
                GetVehiclePos(vConcessionaria[i][d][SpecVehID], Alpdd[0], Alpdd[1], Alpdd[2]);
                if(!IsPlayerInRangeOfPoint(playerid, 4.0, Alpdd[0], Alpdd[1], Alpdd[2])) continue;
                if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
                CarregarDrawConce(playerid, i, d);
                lasd = true;
                break;
            }
            if(lasd == true) break;
        }  
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid){
    if(playertextid == ConceDrawY[playerid][12]){ // Frente
        new id = GetPVarInt(playerid, "ConceID"); 
        if(GetPVarInt(playerid, "ConcePosEx") >= PegarTypesConce(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais veículos para frente, volte");
        SetPVarInt(playerid, "ConcePosEx", GetPVarInt(playerid, "ConcePosEx")+1);
        AtualizarDrawConce(playerid, id, GetPVarInt(playerid, "ConcePosEx"));
    }
    
    else if(playertextid == ConceDrawY[playerid][11]){ // Tras
        new id = GetPVarInt(playerid, "ConceID");
        if(GetPVarInt(playerid, "ConcePosEx") <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais veículos para trás, volte");
        SetPVarInt(playerid, "ConcePosEx", GetPVarInt(playerid, "ConcePosEx")-1);
        AtualizarDrawConce(playerid, id, GetPVarInt(playerid, "ConcePosEx"));
    }

    else if(playertextid == ConceDraw[playerid][6] || playertextid == ConceDrawY[playerid][10]){ // Cancelar     
        new id = GetPVarInt(playerid, "ConceID");
        if(Concessionaria[id][ModoConce] == 1 || !strcmp(Concessionaria[id][ConceDono], "*")) OcultarDrawY(playerid);
        else OcultarDrawConce(playerid);
    }
    else if(playertextid == ConceDraw[playerid][5] || playertextid == ConceDrawY[playerid][9]){ // Comprar
        new Dialog[75];
        strcatEx(Dialog, "Você realmente deseja comprar o veículo %s por {32CD32}$%s", ConceModelos[GetPVarInt(playerid, "ConcePos")][Nome], DinheiroSeparar(ConceModelos[GetPVarInt(playerid, "ConcePos")][Valor]));
        Dialog_Show(playerid, ConfirmacaoConce, DIALOG_STYLE_MSGBOX, "{FF0000}Concessionária", Dialog, "Confirmar", "Fechar"); 
    }
    return 0;
}

CMD:comprarconcessionaria(playerid){
    for(new i=0; i < MAX_CONCESSIONARIA; i++){
        if(Concessionaria[i][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, Concessionaria[i][ConceX], Concessionaria[i][ConceY], Concessionaria[i][ConceZ])) continue;
        if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) continue;
        if(strcmp(Concessionaria[i][ConceDono], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa concessionária já possui proprietário(a)");
        if(PegarMinhaConce(playerid) != -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem uma concessionária em seu nome");
        if(Jogador[playerid][Dinheiro] < Concessionaria[i][PrecoConce]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");

        new Dialog[65];
        SetPVarInt(playerid, "KAKAKACONCE", i);
        format(Dialog, sizeof(Dialog), "Você realmente deseja comprar essa concessionária por $%s", DinheiroSeparar(Concessionaria[i][PrecoConce]));
        Dialog_Show(playerid, ConceComprar, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", Dialog, "Comprar", "Fechar");
        break;
    }
    return 1;
}