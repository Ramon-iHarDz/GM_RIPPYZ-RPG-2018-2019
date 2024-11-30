Dialog:ConceVeiculo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "ConceAdminID"),
        Dialog[600];
    switch(listitem)
    {
        case 0: // Adicionar
        {
            strcat(Dialog, "ID\tModelo\n");
            for(new i=0; i < MAX_CONCESSIONARIA_VEH; i++){
                if(vConcessionaria[id][i][SpecDb] == true) strcatEx(Dialog, "%d\t{FFFF00}Setado\n", i+1);
                else if(vConcessionaria[id][i][SpecColocado] == false) strcatEx(Dialog, "%d\t{FF0000}Sem Veículo\n", i+1);
                else strcatEx(Dialog, "%d\t%s\n", i+1, GetVehicleNameByModel(ConceModelos[vConcessionaria[id][i][SpecVehIndex]][Modelo])); 
            }
            Dialog_Show(playerid, ConcessionariaAdicionar, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Adicionar", Dialog, "Selecionar", "Fechar");   
        }
        case 1: // Remover
        {
            strcat(Dialog, "ID\tModelo\n");
            for(new i=0; i < MAX_CONCESSIONARIA_VEH; i++){
                if(vConcessionaria[id][i][SpecDb] == true) strcatEx(Dialog, "%d\t{FFFF00}Setado\n", i+1);
                else if(vConcessionaria[id][i][SpecColocado] == false) strcatEx(Dialog, "%d\t{FF0000}Sem Veículo\n", i+1);
                else strcatEx(Dialog, "%d\t%s\n", i+1, GetVehicleNameByModel(ConceModelos[vConcessionaria[id][i][SpecVehIndex]][Modelo])); 
            }
            Dialog_Show(playerid, ConcessionariaRemover, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Remover", Dialog, "Selecionar", "Fechar");
        }
    }
    return 1;
}

Dialog:ConcessionariaRemover(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new i = listitem,
        id = GetPVarInt(playerid, "ConceAdminID");
    if(vConcessionaria[id][i][SpecColocado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há veículo nesse slot");

    new Query[75];
    format(Query, sizeof(Query), "DELETE FROM `concessionariaveiculo` WHERE `Conce`=%d AND `Slot`=%d", id, i);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao remover o veículo");

    DestroyVehicleEx(vConcessionaria[id][i][SpecVehID]);
    DestroyDynamic3DTextLabelEx(vConcessionaria[id][i][SpecText]);
    DestroyDynamicPickupEx(vConcessionaria[id][i][SpecPick]);

    new Loasd[ConcessionariaVeh];
    vConcessionaria[id][i] = Loasd;
    return 1;
}

Dialog:ConcessionariaAdicionar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new i = listitem,
        id = GetPVarInt(playerid, "ConceAdminID");
    if(vConcessionaria[id][i][SpecColocado] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Já tem um veículo nesse slot");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");

    new Query[200],
        Float:vJog[4];
    GetVehiclePos(GetPlayerVehicleID(playerid), vJog[0], vJog[1], vJog[2]);
    GetVehicleZAngle(GetPlayerVehicleID(playerid), vJog[3]);

    format(Query, sizeof(Query), "INSERT INTO `concessionariaveiculo` (`Conce`, `Slot`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `PosicaoA`) VALUES (%d, %d, %f, %f, %f, %f)", id, i, vJog[0], vJog[1], vJog[2], vJog[3]);
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao adicionar o veículo");

    vConcessionaria[id][i][SpecVehX] = vJog[0];
    vConcessionaria[id][i][SpecVehY] = vJog[1];
    vConcessionaria[id][i][SpecVehZ] = vJog[2];
    vConcessionaria[id][i][SpecVehA] = vJog[3];
    vConcessionaria[id][i][SpecDb] = true;
    CarregarVeiculosConce(id, true); 
    return 1;
}

Dialog:ConceTypeS(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarInt(playerid, "ConceType", listitem);
    return 1;
}

Dialog:ConcePrecoS(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id;
    if(sscanf(inputtext, "d", id)) return 1;
    SetPVarInt(playerid, "ConcePreco", id);
    return 1;
}

Dialog:TypeConceConfig(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarInt(playerid, "ModeConce", listitem);
    return 1;
}

Dialog:ConceCriacao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new Float:Olasd[3];
            GetPlayerPos(playerid, Olasd[0], Olasd[1], Olasd[2]);
            SetPVarFloat(playerid, "aConceX", Olasd[0]);
            SetPVarFloat(playerid, "aConceY", Olasd[1]);
            SetPVarFloat(playerid, "aConceZ", Olasd[2]);
        }
        case 1:
        {
            new Float:Olasd[4];
            GetPlayerPos(playerid, Olasd[0], Olasd[1], Olasd[2]);
            GetPlayerFacingAngle(playerid, Olasd[3]);
            SetPVarFloat(playerid, "aVeiculoX", Olasd[0]);
            SetPVarFloat(playerid, "aVeiculoY", Olasd[1]);
            SetPVarFloat(playerid, "aVeiculoZ", Olasd[2]);  
            SetPVarFloat(playerid, "aVeiculoA", Olasd[3]);  
        }
        case 2:
        {
            new Dialog[128];
            for(new i=0; i < 6; i++){
                strcatEx(Dialog, "%s\n", PegarConcessionariaType(i)); 
            }
            Dialog_Show(playerid, ConceTypeS, DIALOG_STYLE_TABLIST, "{FF0000}Tipos", Dialog, "Selecionar", "Fechar");
        }
        case 3: Dialog_Show(playerid, ConcePrecoS, DIALOG_STYLE_INPUT, "{FF0000}Preco", "Selecionar preço", "Selecionar", "Fechar");
        case 4:
        {
            new Dialog[20];
            strcat(Dialog, "Tipo H\n");
            strcat(Dialog, "Tipo Y");
            Dialog_Show(playerid, TypeConceConfig, DIALOG_STYLE_TABLIST, "Type", Dialog, "Selecionar", "Fechar");
        }
        case 5:
        {
            DeletePVar(playerid, "ConcePreco");
            DeletePVar(playerid, "ConceType");
            //
            DeletePVar(playerid, "aConceX");
            DeletePVar(playerid, "aConceY");
            DeletePVar(playerid, "aConceZ");
            //
            DeletePVar(playerid, "aVeiculoX");
            DeletePVar(playerid, "aVeiculoY");
            DeletePVar(playerid, "aVeiculoZ");
            DeletePVar(playerid, "aVeiculoA");
        }
        case 6:
        {
            new Query[450],
                id = PegarConceID();
            format(Query, sizeof(Query), "INSERT INTO `concessionaria` (`Numero`, `Dono`, `Mensagem`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `VeiculoX`, `VeiculoY`, `VeiculoZ`, `VeiculoA`, `Type`, `Preco`, `Modo`) VALUES (%d, '*', '*', %f, %f, %f, %f, %f, %f, %f, %d, %d, %d)", id, GetPVarFloat(playerid, "aConceX"), GetPVarFloat(playerid, "aConceY"), GetPVarFloat(playerid, "aConceZ"), GetPVarFloat(playerid, "aVeiculoX"), GetPVarFloat(playerid, "aVeiculoY"), GetPVarFloat(playerid, "aVeiculoZ"), GetPVarFloat(playerid, "aVeiculoA"), GetPVarInt(playerid, "ConceType"), GetPVarInt(playerid, "ConcePreco"), GetPVarInt(playerid, "ModeConce"));
            mysql_query(IDConexao, Query, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao criar essa concessionária");

            //
            Concessionaria[id][ConceX] = GetPVarFloat(playerid, "aConceX");
            Concessionaria[id][ConceY] = GetPVarFloat(playerid, "aConceY");
            Concessionaria[id][ConceZ] = GetPVarFloat(playerid, "aConceZ");

            Concessionaria[id][vConceX] = GetPVarFloat(playerid, "aVeiculoX");
            Concessionaria[id][vConceY] = GetPVarFloat(playerid, "aVeiculoY");
            Concessionaria[id][vConceZ] = GetPVarFloat(playerid, "aVeiculoZ");
            Concessionaria[id][vConceA] = GetPVarFloat(playerid, "aVeiculoA");

            //
            Concessionaria[id][TypeConce] = GetPVarInt(playerid, "ConceType");
            Concessionaria[id][PrecoConce] = GetPVarInt(playerid, "ConcePreco");
            Concessionaria[id][ModoConce] = GetPVarInt(playerid, "ModeConce");

            //
            format(Concessionaria[id][ConceDono], 30, "*");
            format(Concessionaria[id][ConceMsg], 30, "*");
            CarregarConcessionaria(id);

        }
    }
    return 1;
}

CMD:criarconcessionaria(playerid){
    if(Jogador[playerid][Admin] < 7) return 0;
    new Dialog[228];
    strcatEx(Dialog, "%0.2f %0.2f %0.2f\n", GetPVarFloat(playerid, "aConceX"), GetPVarFloat(playerid, "aConceY"), GetPVarFloat(playerid, "aConceZ"));
    strcatEx(Dialog, "%0.2f %0.2f %0.2f %0.2f\n", GetPVarFloat(playerid, "aVeiculoX"), GetPVarFloat(playerid, "aVeiculoY"), GetPVarFloat(playerid, "aVeiculoZ"), GetPVarFloat(playerid, "aVeiculoA"));
    strcatEx(Dialog, "Type: %s\n", PegarConcessionariaType(GetPVarInt(playerid, "ConceType")));
    strcatEx(Dialog, "R$%s\n", DinheiroSeparar(GetPVarInt(playerid, "ConcePreco")));
    strcat(Dialog, "Tipo\n");
    strcat(Dialog, "{FF4500}Resetar Configuração\n"); 
    strcat(Dialog, "{32CD32}Criar Concessionária");
    Dialog_Show(playerid, ConceCriacao, DIALOG_STYLE_TABLIST, "{FF0000}Concessionária", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:concessionariaveiculo(playerid, params[]){
    if(Jogador[playerid][Admin] < 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /ConcessionariaVeiculo [ID]");
    if(Concessionaria[id][Colocado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há concessionária com esse ID");
    new Dialog[20];
    SetPVarInt(playerid, "ConceAdminID", id);
    strcat(Dialog, "Adicionar\n");
    strcat(Dialog, "Remover");
    Dialog_Show(playerid, ConceVeiculo, DIALOG_STYLE_TABLIST, "{FFFF00}Concessionária", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:liberarconcessionaria(playerid, params[]){
    if(Jogador[playerid][Admin] < 5) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /LiberarConcessionaria [ID]");
    if(Concessionaria[id][Colocado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há concessionária com esse ID");
    if(!strcmp(Concessionaria[id][ConceDono], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há dono(a)");
    LiberarConceSQL(id);
    AtualizarConcessionaria(id);
    return 1;
}

CMD:removerconcessionaria(playerid, params[]){
    if(Jogador[playerid][Admin] < 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /RemoverConcessionaria [ID]");
    if(Concessionaria[id][Colocado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há concessionária com esse ID");
    RemoverConceSQL(id);
    return 1;
}