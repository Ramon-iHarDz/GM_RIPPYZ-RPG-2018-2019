stock EntrarFabrica(playerid, i)
{
    if(cAC[playerid][Travado] == true) return 1;

    TogglePlayerControllable(playerid, 0);
    SetTimerEx("Destravar", 2000, false, "d", playerid);

    //Setar algumas informações
    Jogador[playerid][uInteriorEx] = 12;
    SetPVarInt(playerid, "InteriorPersonalizadoID", i); 
    GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
    SetPlayerFacingAngle(playerid, random(360));

    new vw = PegarFabricaVw(i);

    if(pFabrica[i][FabricaTipo] != 3)
    {
        SetPlayerPos(playerid, 2120.0952,-2273.6880,20.6719);
        SetPlayerInterior(playerid, 0);
    }
    else
    {
        SetPlayerPos(playerid, 1142.7058,1285.1805,1037.9102);
        SetPlayerInterior(playerid, 5);   
    }
    
    SetPlayerVirtualWorld(playerid, vw);
    return 1;
}

stock PegarTipoFabrica(id){
    new msa[30];
    switch(pFabrica[id][FabricaTipo])
    {
        case 0: msa = "Fábrica de Armas";
        case 1: msa = "Fábrica de Roupas";
        case 2: msa = "Fábrica de Diversos";
        case 3: msa = "Fábrica de Veículos";
    }
    return msa;
}

stock PrecoFabricaImpostos(id){
    new vvlr;
    if(pFabrica[id][FabricaTipo] != 3) vvlr = 30150;
    else vvlr = 200000;
    new ValorMN = vvlr*pFabrica[id][FabricaImposto];
    return ValorMN;
}

stock PermissaoFabrica(const Nna[]){
    for(new i=0; i < MAX_FABRICAS; i++){
        if(pFabrica[i][Colocado] == false) continue;
        for(new d=0; d < MAX_FUNCIONARIOSFAB; d++){
            if(pFuncionarioFab[i][d][TemFunc] == false) continue;
            if(strcmp(pFuncionarioFab[i][d][Funcionario], Nna)) continue;
            return pFuncionarioFab[i][d][CargoEmpresa];
        }
    }
    return -1;
}

stock FabricaPermissao(playerid, id){
    for(new i=0; i < MAX_FUNCIONARIOSFAB; i++){
        if(pFuncionarioFab[id][i][TemFunc] == false) continue;
        if(strcmp(PegarNick(playerid), pFuncionarioFab[id][i][Funcionario])) continue;
        return true;
    }
    return false;
}

stock ProcurarFabricaID(const Nna[]){
    for(new i=0; i < MAX_FABRICAS; i++){
        if(pFabrica[i][Colocado] == false) continue;
        for(new d=0; d < MAX_FUNCIONARIOSFAB; d++){
            if(pFuncionarioFab[i][d][TemFunc] == false) continue;
            if(strcmp(pFuncionarioFab[i][d][Funcionario], Nna)) continue;
            return i;
        }
    }
    return -1;
}

stock ProcurarFabricaIDFunc(const Nna[]){
    for(new i=0; i < MAX_FABRICAS; i++){
        if(pFabrica[i][Colocado] == false) continue;
        for(new d=0; d < MAX_FUNCIONARIOSFAB; d++){
            if(pFuncionarioFab[i][d][TemFunc] == false) continue;
            if(strcmp(pFuncionarioFab[i][d][Funcionario], Nna)) continue;
            return d;
        }
    }
    return -1;
}

stock QuantidadeFuncionarioFabrica(id){
    new qnt;
    for(new i=0; i < MAX_FUNCIONARIOSFAB; i++){
        if(pFuncionarioFab[id][i][TemFunc] == false) continue;
        qnt++;
    }
    return qnt;
}

stock PegarCargoFuncionarioFab(id, i){
    new lasd[30];
    switch(pFuncionarioFab[id][i][CargoEmpresa]){
        case 0: lasd = "Funcionário(a)";
        case 1: lasd = "Gerente";
        case 2: lasd = "Dono(a)";
    }
    return(lasd);
}

stock PegarFabricaID(){
    for(new i=1; i < MAX_FABRICAS; i++){
        if(pFabrica[i][Colocado] == true) continue;
        return i;
    }
    return -1;
}

stock PegarFabricaVw(id){
    new vw = id,
        ld;
    vw++;
    vw = (vw*vw);
    vw += id;
    ld += (vw*pFabrica[id][FabricaTipo]);
    ld += ld;
    ld += (vw*pFabrica[id][FabricaTipo]);
    vw = (vw*vw);
    ld++;
    ld += vw;
    return ld;
}

stock ReiniciarFabrica(bool:modo)  
{
    new Enviar[450],
        Llbr;
    
    print("[Rippzy:Fabrica] Salvando Fábricas.");
    for(new i=0; i < MAX_FABRICAS; i++)
    {
        if(pFabrica[i][Colocado] == false) continue;
        if(!strcmp(pFabrica[i][fDono], "*")) continue;
        
        // String
        new LiberacaoMotivo[50] = "*";

        // Adicionar
        if(modo == true) 
        {
            pFabrica[i][FabricaImposto]++;
            if(pFabrica[i][FabricaImposto] >= 7) LiberacaoMotivo = "Impostos Atrasados";
        }

        if(strcmp(LiberacaoMotivo, "*")) 
        {
            Llbr++;
            SqlRemoverFabrica(i);
        }
        else
        {
            format(Enviar, sizeof(Enviar), "UPDATE `fabricas` SET `Impostos` = %d, `Producao` = %d WHERE `Numero` = %d", pFabrica[i][FabricaImposto], pFabrica[i][FabricaProducao], i);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) printf("[Rippzy:Fabrica] Houve um problema ao salvar a empresa número %d", pEmpresa[i][eNumero]);
        }
    }
    printf("[Rippzy:Fabrica] Fabricas salvas com sucesso. ( Liberadas: %d )", Llbr);
    return 1;
}

stock LiberarFabricaSQL(id){
    new Query[158];
    format(Query, sizeof(Query), "UPDATE `fabricas` SET `Dono` = '*', `Impostos` = 0, `Producao` = 0, `Liquido` = 100, `Reparo` = 100, `Cofre` = 0 WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Query, false);

    format(Query, sizeof(Query), "DELETE FROM `fabricafuncionarios` WHERE `Fabrica` = %d", id);
    mysql_query(IDConexao, Query, false);

    new acabeideabrir[FuncionarioInfo];
    for(new i=0; i < MAX_FUNCIONARIOSFAB; i++){
        pFuncionarioFab[id][i] = acabeideabrir;
    }

    format(pFabrica[id][fDono], 30, "*");
    pFabrica[id][LiquidoTonel] = 100;
    pFabrica[id][ReparoTonel] = 100;
    pFabrica[id][FabricaImposto] = 0;
    pFabrica[id][FabricaProducao] = 0;
    pFabrica[id][FabricaCofre] = 0;
    return 1;
}

stock SqlRemoverFabrica(id)
{
    new Query[128];
    format(Query, sizeof(Query), "DELETE FROM `fabricas` WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Query, false);

    format(Query, sizeof(Query), "DELETE FROM `fabricafuncionarios` WHERE `Fabrica` = %d", id);
    mysql_query(IDConexao, Query, false);

    DestroyDynamicObjectEx(pFabrica[id][LiquidosInfo]);
    DestroyDynamicObjectEx(pFabrica[id][ReparoInfo]);
    DestroyDynamicObjectEx(pFabrica[id][FabricaIDInfo]);
    //
    DestroyDynamicPickupEx(pFabrica[id][fPick]);
    DestroyDynamic3DTextLabelEx(pFabrica[id][FabricaTexto]);
    DestroyDynamicMapIconEx(pFabrica[id][fMapa]);
    //
    RemoverObjetoFabrica(id);
    RemoverMesasFabrica(id); 

    new acabeideabrirr[FabricaInfo];
    pFabrica[id] = acabeideabrirr; 

    new acabeideabrir[FuncionarioInfo];
    for(new i=0; i < MAX_FUNCIONARIOSFAB; i++){
        pFuncionarioFab[id][i] = acabeideabrir;
    }
    return 1;
}

stock AtualizarFabrica(id){
    DestroyDynamicObjectEx(pFabrica[id][LiquidosInfo]);
    DestroyDynamicObjectEx(pFabrica[id][ReparoInfo]);
    DestroyDynamicObjectEx(pFabrica[id][FabricaIDInfo]);
    //
    DestroyDynamicPickupEx(pFabrica[id][fPick]); 
    DestroyDynamic3DTextLabelEx(pFabrica[id][FabricaTexto]);
    DestroyDynamicMapIconEx(pFabrica[id][fMapa]);
    //
    RemoverObjetoFabrica(id);
    RemoverMesasFabrica(id);
    AdicionarFabrica(id);
    return 1;
}