stock PegarConcessionariaType(id){
    new Rhf[20];
    switch(id)
    {
        case 0: Rhf = "Comuns";
        case 1: Rhf = "Esportivos";
        case 2: Rhf = "Clássicos";
        case 3: Rhf = "Caminhões";
        case 4: Rhf = "Helicópteros";
        case 5: Rhf = "Aviões";
    }
    /*Tipo Comums:
    - Off Road
    - Saloons
    - Station Wagons
    - Unique Vehicles

    Tipo Esportivos:
    - Sport Vehicles

    Tipo Clássicos:
    - Lowriders

    Tipo Motocicletas:
    - Bikes

    Tipo Caminhões:
    - Industrial*/
    return (Rhf);
}

stock PegarMinhaConce(playerid){
    for(new i=0; i < MAX_CONCESSIONARIA; i++){
        if(Concessionaria[i][Colocado] == false) continue;
        if(strcmp(Concessionaria[i][ConceDono], PegarNick(playerid))) continue;
        return i;
    }
    return -1;
}

stock PrecoConceImpostos(id){
    new ValorMN = 580000*Concessionaria[id][ImpostosConce];
    return ValorMN;
}

stock PegarTypesConce(id){
    new qntat;
    for(new i=0; i < sizeof(ConceModelos); i++){
        if(Concessionaria[id][TypeConce] != ConceModelos[i][TypeVehic]) continue; 
        qntat++;
    }
    return qntat;
}

stock ConceIDDraw(id, puls){
    new qntat;
    for(new i=0; i < sizeof(ConceModelos); i++){
        if(ConceModelos[i][TypeVehic] != Concessionaria[id][TypeConce]) continue;
        if(puls != qntat){
            qntat++;
            continue;
        }
        return i;
    }
    return 0;
}

stock EnviarCofreConce(id, valor){
    if(!strcmp(Concessionaria[id][ConceDono], "*")) return 1;
    new Query[128],
        Summ = Concessionaria[id][CofreConce];
    Summ += valor;
    format(Query, sizeof(Query), "UPDATE `concessionaria` SET `Cofre`=%d WHERE `Numero`=%d", Summ, id);
    mysql_query(IDConexao, Query, false);
    Concessionaria[id][CofreConce] = Summ;
    return 1;
}

stock PegarConceID(){
    for(new i=1; i < MAX_CONCESSIONARIA; i++){
        if(Concessionaria[i][Colocado] == true) continue;
        return i;
    }
    return -1;
}

stock GetModelConce(id){
    new idx,
        rnd = PegarTypesConce(id),
        qnnt;
    idx = random(rnd);

    for(new i=0; i < sizeof(ConceModelos); i++){
        if(ConceModelos[i][TypeVehic] != Concessionaria[id][TypeConce]) continue;
        if(idx != qnnt){
            qnnt++;
            continue;
        }
        idx = i;
        break;
    }
    return idx;
}

stock CarregarVeiculosConce(id, bool:Verf = false){
    if(Verf == true){
        if(!strcmp(Concessionaria[id][ConceDono], "*")) return 1;
    }
    if(Concessionaria[id][EstoqueConce] < 1) return 1;
    new ssds = Concessionaria[id][EstoqueConce];
    for(new i=0; i < MAX_CONCESSIONARIA_VEH; i++){
        if(vConcessionaria[id][i][SpecDb] == false) continue;
        if(vConcessionaria[id][i][SpecColocado] == true) continue;
        CarregarVeiculoConce(id, i);
        ssds--;
        if(ssds < 1) break;
    }
    return 1;
}

stock AtualizarConcessionaria(id){
    DestroyDynamic3DTextLabelEx(Concessionaria[id][ConceTexto]);
    DestroyDynamicMapIconEx(Concessionaria[id][ConceIcone]);
    DestroyDynamicPickupEx(Concessionaria[id][ConcePick]);
    KillTimer(Concessionaria[id][TimerConce]);
    CarregarConcessionaria(id);
    return 1;
}

stock LiberarConceSQL(id){
    new Query[148];
    strcatEx(Query, "UPDATE `concessionaria` SET `Dono`='*', `Mensagem`='*', `Impostos`=0, `Estoque`=0, `Cofre`=0, `Vendas`=0 WHERE `Numero`=%d", id);
    mysql_query(IDConexao, Query, false);

    for(new i=0; i < MAX_CONCESSIONARIA_VEH; i++){
        if(vConcessionaria[id][i][SpecColocado] == false) continue;
        //if(vConcessionaria[id][i][SpecStatus] == 1) KillTimer(vConcessionaria[id][i][SpecTimer]);
        DestroyVehicleEx(vConcessionaria[id][i][SpecVehID]);
        DestroyDynamic3DTextLabelEx(vConcessionaria[id][i][SpecText]);
        DestroyDynamicPickupEx(vConcessionaria[id][i][SpecPick]);
        vConcessionaria[id][i][SpecColocado] = false;
    }

    Concessionaria[id][ImpostosConce] = 0;
    Concessionaria[id][EstoqueConce] = 0;
    Concessionaria[id][VendasConce] = 0;
    Concessionaria[id][CofreConce] = 0;
    format(Concessionaria[id][ConceDono], 30, "*");
    format(Concessionaria[id][ConceMsg], 30, "*");
    return 1;
}

stock RemoverConceSQL(id){
    new Query[158];
    strcatEx(Query, "DELETE FROM `concessionaria` WHERE `Numero`=%d;", id);
    strcatEx(Query, "DELETE FROM `concessionariaveiculo` WHERE `Conce`=%d;", id);
    mysql_query(IDConexao, Query, false);

    DestroyDynamic3DTextLabelEx(Concessionaria[id][ConceTexto]);
    DestroyDynamicMapIconEx(Concessionaria[id][ConceIcone]);
    DestroyDynamicPickupEx(Concessionaria[id][ConcePick]);
    KillTimer(Concessionaria[id][TimerConce]);

    new casda[ConcessionariaVeh];
    for(new i=0; i < MAX_CONCESSIONARIA_VEH; i++){
        if(vConcessionaria[id][i][SpecStatus] == 1) KillTimer(vConcessionaria[id][i][SpecTimer]);
        DestroyVehicleEx(vConcessionaria[id][i][SpecVehID]);
        DestroyDynamic3DTextLabelEx(vConcessionaria[id][i][SpecText]);
        DestroyDynamicPickupEx(vConcessionaria[id][i][SpecPick]);
        vConcessionaria[id][i] = casda;
    }

    new cdsaasda[ConcessionariaInfo];
    Concessionaria[id] = cdsaasda;
    return 1;
}

stock AtualizarDrawConce(playerid, conce, idx){
    new qnnt,
        kaleb;
    for(new i=0; i < sizeof(ConceModelos); i++){
        if(ConceModelos[i][TypeVehic] != Concessionaria[conce][TypeConce]) continue;
        if(idx != qnnt){
            qnnt++;
            continue;
        }
        kaleb = i;
        break;
    }
    SetPVarInt(playerid, "ConcePos", kaleb);
    PlayerTextDrawSetString(playerid, ConceDrawY[playerid][5], ConverterTexto(GetVehicleNameByModel(ConceModelos[kaleb][Modelo])));
    PlayerTextDrawSetString(playerid, ConceDrawY[playerid][8], ConverterTexto(ConceModelos[kaleb][Categoria]));
    PlayerTextDrawSetPreviewModel(playerid, ConceDrawY[playerid][13], ConceModelos[kaleb][Modelo]);  
    PlayerTextDrawShow(playerid, ConceDrawY[playerid][13]);
    return 1;
}

stock CarregarDrawConce(playerid, conce, id){
    SetPVarInt(playerid, "ConceID", conce);
    if(Concessionaria[conce][ModoConce] == 1 || !strcmp(Concessionaria[conce][ConceDono], "*")) // Modo Y
    {
        DeletePVar(playerid, "ConcePosEx");
        DeletePVar(playerid, "ConcePos");
        MostrarConceY(playerid);
        AtualizarDrawConce(playerid, conce, GetPVarInt(playerid, "ConceID"));
    }
    else
    {
        SetPVarInt(playerid, "ConcePos", vConcessionaria[conce][id][SpecVehIndex]);
        MostrarDrawConce(playerid);
        PlayerTextDrawSetString(playerid, ConceDraw[playerid][3], ConverterTexto(ConceModelos[GetPVarInt(playerid, "ConcePos")][Nome]));
    }
    return 1;
}

function CarregarVeiculoConce(id, idx){
    new Mensagem[168],
        i = GetModelConce(id);

    strcatEx(Mensagem, "{FFA500}Concessionária (ID: %d - %d)\n", id, idx);
    strcatEx(Mensagem, "{FFFFFF}Modelo: {00BFFF}%s\n", GetVehicleNameByModel(ConceModelos[i][Modelo]));
    strcatEx(Mensagem, "{FFFFFF}Preço: {32CD32}R$%s\n", DinheiroSeparar(ConceModelos[i][Valor]));
    strcat(Mensagem, "{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para visualizar");
    vConcessionaria[id][idx][SpecVehID] = CreateVehicleEx(-1, ConceModelos[i][Modelo], vConcessionaria[id][idx][SpecVehX], vConcessionaria[id][idx][SpecVehY], vConcessionaria[id][idx][SpecVehZ], vConcessionaria[id][idx][SpecVehA], 1, 1, 2, 0);
    vConcessionaria[id][idx][SpecText] = CreateDynamic3DTextLabel(Mensagem, -1, 0.0, 0.0, 0.0, 15.0, INVALID_PLAYER_ID, vConcessionaria[id][idx][SpecVehID], 0, 0, 0, -1, 16.0, -1);
    vConcessionaria[id][idx][SpecVehIndex] = i;
    VeiculoServer[vConcessionaria[id][idx][SpecVehID]][Tranca] = 1;
    format(VeiculoServer[vConcessionaria[id][idx][SpecVehID]][LocalVerificacao], 30, "SyncConce");
    vConcessionaria[id][idx][SpecStatus] = 0;
    vConcessionaria[id][idx][SpecColocado] = true;
    return 1;
}

stock VeiculoOutConce(id, idx){
    for(new i=0; i < MAX_CONCESSIONARIA_VEH; i++){
        if(vConcessionaria[id][i][SpecDb] == false) continue;
        if(vConcessionaria[id][i][SpecColocado] == false) continue;
        if(vConcessionaria[id][i][SpecVehIndex] != idx) continue;
        if(vConcessionaria[id][i][SpecStatus] != 0) continue;
        vConcessionaria[id][i][SpecStatus] = 1;
        //vConcessionaria[id][i][SpecTimer] = SetTimerEx("CarregarVeiculoConce", , false, "dd", id, i);
        DestroyDynamic3DTextLabelEx(vConcessionaria[id][i][SpecText]);
        DestroyVehicleEx(vConcessionaria[id][i][SpecVehID]);
        break;  
    }
    return 1;
}

function ConcessionariaSync(id){
    if(!strcmp(Concessionaria[id][ConceDono], "*")) return 1;
    if(Concessionaria[id][EstoqueConce] < 1) return 1;
    for(new i=0; i < MAX_CONCESSIONARIA_VEH; i++){
        if(vConcessionaria[id][i][SpecDb] == false) continue;
        if(vConcessionaria[id][i][SpecColocado] == false) continue;
        if(vConcessionaria[id][i][SpecStatus] != 1) continue;
        CarregarVeiculoConce(id, i);
        Concessionaria[id][EstoqueConce]--;
        if(Concessionaria[id][EstoqueConce] < 1) break; 
    }
    return 1;
}

function SyncConce(playerid){
    SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode entrar nesse veículo");
    return false;
}

function ReiniciarConcessionaria(bool:modo)
{
    new Enviar[90];
    print("[Rippzy:Concessionaria] Salvando Concessionarias.");
    for(new i=0; i < MAX_CONCESSIONARIA; i++)
    {
        if(Concessionaria[i][Colocado] == false) continue;
        if(!strcmp(Concessionaria[i][ConceDono], "*")) continue;
        
        //String
        new LiberacaoMotivo[50] = "*";

        //Adicionar Lixos e Impostos
        if(modo == true)
        {
            Concessionaria[i][ImpostosConce]++;
            if(Concessionaria[i][ImpostosConce] >= 7) LiberacaoMotivo = "Impostos Atrasados";
        }

        if(strcmp(LiberacaoMotivo, "*")) LiberarConceSQL(i);
        else
        {
            format(Enviar, sizeof(Enviar), "UPDATE `concessionaria` SET `Impostos`=%d, `Estoque`=%d WHERE `Numero`=%d", Concessionaria[i][ImpostosConce], Concessionaria[i][EstoqueConce], i);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) printf("[Rippzy:Concessionaria] Houve um problema ao salvar a concessionaria número %d", i);
        }
    }
    print("[Rippzy:Concessionaria] Concessionarias salvas com sucesso.");
    return 1;
} 