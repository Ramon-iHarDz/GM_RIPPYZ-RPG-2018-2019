#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    SetTimer("TirarBackup", 7200000, true);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    SalvarDados(playerid);
    return 1;
}

stock SalvarDados(playerid, bool:Backup = false)
{
    if(Backup == false){
        if(!IsPlayerConnected(playerid)) return 1;
    }
    if(Jogador[playerid][Logado] == false)
    {
        if(Backup == false)
        {
            new Deletar[JogadorInfo];
            Jogador[playerid] = Deletar;

            new Delet31231ar[JogadorDelay];
            pTempo[playerid] = Delet31231ar; 
        }
        return 1;
    }

    new Float:Xbbb,
        Float:Ybbb,
        Float:Zbbb,
        Float:Abbb,
        SalvarSQL[1900],
        Niicky[30];

    format(Niicky, 30, PegarNick(playerid));
    strcat(SalvarSQL, "UPDATE `rippzyrpg` SET ");
    if(Backup == false)
    {
        ResetProfissao(playerid); // Remover Informações de Profissões
        if(pAdmin[playerid][CarroAdmin] > 0) DestroyVehicleEx(pAdmin[playerid][CarroAdmin]);
        GetPlayerPos(playerid, Xbbb, Ybbb, Zbbb);
        GetPlayerFacingAngle(playerid, Abbb);
        if(Jogador[playerid][uInteriorEx] > 0) strcatEx(SalvarSQL, "`PosicaoX`=%f, `PosicaoY`=%f, `PosicaoZ`=%f, `PosicaoA`=%f, ", Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2], Abbb);
        else strcatEx(SalvarSQL, "`PosicaoX`=%f, `PosicaoY`=%f, `PosicaoZ`=%f, `PosicaoA`=%f, ", Xbbb, Ybbb, Zbbb, Abbb);
        strcat(SalvarSQL, "`Logado`=0, ");
    }

    strcatEx(SalvarSQL, "`Skin`=%d, `Dinheiro`=%d, `DinheiroSujo`=%d, `Vip`=%d, `Level`=%d, `KitReparos`=%d, `GasolinaGalao`=%d, ", Jogador[playerid][Skin], Jogador[playerid][Dinheiro], Jogador[playerid][DinheiroSujo], Jogador[playerid][Vip], Jogador[playerid][Level], Jogador[playerid][KitReparos], Jogador[playerid][GasolinaGalao]);
    strcatEx(SalvarSQL, "`Avisos`=%d, `Experiencia`=%d, `TempoUp`=%d, `UltimoLogin`=%d, `Coins`=%d, `UltimoInterior`=%d, `Profissao`='%s', `Estrelas`=%d, `Doenca`=%d, ", Jogador[playerid][Avisos], Jogador[playerid][Experiencia], Jogador[playerid][TempoUp], gettime(), Jogador[playerid][Coins], Jogador[playerid][uInterior], EscapeString(Jogador[playerid][Profissao]), Jogador[playerid][Estrelas], Jogador[playerid][Doenca]);
    strcatEx(SalvarSQL, "`Tag`=%d, `Prisoes`=%d, `VitimasArena`=%d, `MortesArena`=%d, `Creditos`=%d, `Ip`='%s', `CorVIP`=%d, `Vacina`=%d, `Sede`=%f, `Fome`=%f, `Saude`=%f, `Sono`=%f, `Vicio`=%f, `PandoraCaixa`=%d ", Jogador[playerid][TagPersonalizada], Jogador[playerid][Prisoes], Jogador[playerid][VitimasArena], Jogador[playerid][MortesArena], Jogador[playerid][Creditos], EscapeString(Jogador[playerid][uIp]), Jogador[playerid][CorVIP], Jogador[playerid][Vacina], Jogador[playerid][Sede], Jogador[playerid][Fome], Jogador[playerid][Saude], Jogador[playerid][Sono], Jogador[playerid][Vicio], Jogador[playerid][PandoraCaixa]);
    strcatEx(SalvarSQL, "WHERE `Nome`='%s'", EscapeString(Niicky));
    mysql_query(IDConexao, SalvarSQL, false);
    if(mysql_errno(IDConexao) != 0) printf("[ ERRO ] Conta ao salvar conta do(a) jogador(a) %s[%d]", Niicky, playerid);
    stringclear(SalvarSQL);

    
    // Atualizar conta do jogador novamente
    strcat(SalvarSQL, "UPDATE `rippzyrpg` SET ");
    strcatEx(SalvarSQL, "`Jetpack`=%d, `Luta`=%d, `Encomendas`=%d, `PlanoDeSaude`=%d, `Mutado`=%d, `Raspberry`=%d, `KitMedico`=%d, ", Jogador[playerid][GasJetpack], Jogador[playerid][Luta], Jogador[playerid][EncomendasPlayer], Jogador[playerid][PlanoDeSaude], Jogador[playerid][Mutado], Jogador[playerid][Raspberry], Jogador[playerid][KitMedico]); 
    strcatEx(SalvarSQL, "`VicioType`=%d, `Cilindro`=%d, `VitimasBase`=%d, `MortesBase`=%d, `MutadoVoip`=%d, `SementeFazenda`=%d ", Jogador[playerid][VicioEstilo], Jogador[playerid][Cilindro], Jogador[playerid][VitimasBase], Jogador[playerid][MortesBase], Jogador[playerid][MutadoVoip], Jogador[playerid][SementeFazenda]);
    strcatEx(SalvarSQL, "WHERE `Nome`='%s'", EscapeString(Niicky));
    mysql_query(IDConexao, SalvarSQL, false);
    if(mysql_errno(IDConexao) != 0) printf("[ ERRO ] Conta ao salvar conta (V2) do(a) jogador(a) %s[%d]", Niicky, playerid);
    stringclear(SalvarSQL);

        
    if(Backup == false)
    {
        // Salvar algumas dependencias de mafia
        strcat(SalvarSQL, "UPDATE `mafia` SET ");
        strcatEx(SalvarSQL, "`Sementes`=%d, `Sacos`=%d, `Agua`=%d, `Adubos`=%d, `Drogas`=%d, `Vasos`=%d, `LockPick`=%d, `Dinamites`=%d, ", Jogador[playerid][Sementes], Jogador[playerid][Sacos], Jogador[playerid][Agua], Jogador[playerid][Adubos], Jogador[playerid][Drogas], Jogador[playerid][Vasos], Jogador[playerid][LockPick], Jogador[playerid][Dinamites]);
        strcatEx(SalvarSQL, "`Maconha`=%d, `Crack`=%d, `Cocaina`=%d, `Lsd`=%d, `Capsulas`=%d, `Pecas`=%d ", Jogador[playerid][Maconha], Jogador[playerid][Crack], Jogador[playerid][Cocaina], Jogador[playerid][Lsd], Jogador[playerid][Capsulas], Jogador[playerid][Pecas]);
        strcatEx(SalvarSQL, "WHERE `Nome`='%s'", EscapeString(Niicky));
        mysql_query(IDConexao, SalvarSQL, false);
        if(mysql_errno(IDConexao) != 0) printf("[ ERRO ] Conta ao informacoes mafia do(a) jogador(a) %s[%d]", Niicky, playerid);
        stringclear(SalvarSQL);


        // Salvar Carteiras
        strcat(SalvarSQL, "UPDATE `carteiras` SET ");
        strcatEx(SalvarSQL, "`CarteiraA` = %d, `CarteiraB` = %d, `CarteiraC` = %d, `CarteiraD` = %d, `CarteiraE` = %d, ", Jogador[playerid][CarteiraA], Jogador[playerid][CarteiraB], Jogador[playerid][CarteiraC], Jogador[playerid][CarteiraD], Jogador[playerid][CarteiraE]);
        strcatEx(SalvarSQL, "`MultaA` = %d, `MultaB` = %d, `MultaC` = %d, `MultaD` = %d, `MultaE` = %d ", Jogador[playerid][MultaA], Jogador[playerid][MultaB], Jogador[playerid][MultaC], Jogador[playerid][MultaD], Jogador[playerid][MultaE]);
        strcatEx(SalvarSQL, "WHERE `Nome` = '%s'", EscapeString(Niicky));
        mysql_query(IDConexao, SalvarSQL, false);
        if(mysql_errno(IDConexao) != 0) printf("[ ERRO ] Conta ao carteira conta do(a) jogador(a) %s[%d]", Niicky, playerid);
        stringclear(SalvarSQL);


        // Salvar Tempos
        strcat(SalvarSQL, "UPDATE `tempos` SET ");
        strcatEx(SalvarSQL, "`Trabalho`=%d, `RoubarJogador`=%d, `RoubarCaixa`=%d, `TransferirMao`=%d, `TransferirBanco`=%d, `TransferirCoins`=%d, `TrocarLuta`=%d, ", pTempo[playerid][TrocaProfissao], pTempo[playerid][RoubarJogador], pTempo[playerid][RoubarCaixa], pTempo[playerid][TransferirMao], pTempo[playerid][TransferirBanco], pTempo[playerid][TransferirCoins], pTempo[playerid][TrocarLuta]);
        strcatEx(SalvarSQL, "`RoubarCarroForte`=%d, `AbrirDenuncia`=%d, `TransferirCelular`=%d, `TrabalharFabrica`=%d, `Produtor`=%d, `AnunciarOlx`=%d, `AnunciarRadio`=%d, ", pTempo[playerid][RoubarCarroForte], pTempo[playerid][AbrirDenuncia], pTempo[playerid][TransferirCelular], pTempo[playerid][TrabalharFabrica], pTempo[playerid][HobbieProdutor], pTempo[playerid][AnunciarOlx], pTempo[playerid][AnunciarRadio]);
        strcatEx(SalvarSQL, "`Homembomba`=%d, `ExplosaoBomba`=%d, `Apoio`=%d, `FabricaProduc`=%d ", pTempo[playerid][Homembomba], pTempo[playerid][ExplosaoBomba], pTempo[playerid][UsoApoio], pTempo[playerid][FabricaProduc]);
        strcatEx(SalvarSQL, "WHERE `Nome` = '%s'", EscapeString(Niicky));
        mysql_query(IDConexao, SalvarSQL, false);
        if(mysql_errno(IDConexao) != 0) printf("[ ERRO ] Conta ao tempo conta do(a) jogador(a) %s[%d]", Niicky, playerid);
        stringclear(SalvarSQL);

        // Backup Presos
        strcat(SalvarSQL, "UPDATE `presos` SET ");
        strcatEx(SalvarSQL, "`TempoAtual` = %d WHERE `Nome` = '%s'", Jogador[playerid][Preso], EscapeString(Niicky));
        mysql_query(IDConexao, SalvarSQL, false);
        if(mysql_errno(IDConexao) != 0) printf("[ ERRO ] Conta ao salvar prisão do(a) jogador(a) %s[%d]", Niicky, playerid);
        stringclear(SalvarSQL);
    }

    // Salver Veículos
    new id;
    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][MeuVeiculoModelo] == 0) continue;
        if(Backup == false)
        {
            if(pVeiculo[playerid][i][VehConectado] == true)
            {
                new Float:vvVida;
                id = pVeiculo[playerid][i][MeuVeiculoID];
                GetVehicleHealth(id, vvVida);
                pVeiculo[playerid][i][KilometrosEx] = VeiculoServer[id][Kilometros];
                pVeiculo[playerid][i][GasolinaEx] = VeiculoServer[id][Gasolina];
                pVeiculo[playerid][i][vVida] = vvVida; 
                DestroyDynamic3DTextLabelEx(pVeiculo[playerid][i][PortaMalasText]);
                DestroyVehicleEx(pVeiculo[playerid][i][MeuVeiculoID]);
            }
        }
        strcat(SalvarSQL, "UPDATE `veiculos` SET ");
        strcatEx(SalvarSQL, "`Tranca`=%d, `PosX`=%f, `PosY`=%f, `PosZ`=%f, `PosA`=%f, `Cor1`=%d, `Cor2`=%d, `Gasolina`=%f, `Kilometros`=%f, `Preso`='%s', `Vida`=%f, `TemTranca`=%d, `Som`=%d", pVeiculo[playerid][i][Tranca], pVeiculo[playerid][i][vPosX], pVeiculo[playerid][i][vPosY], pVeiculo[playerid][i][vPosZ], pVeiculo[playerid][i][vPosA], pVeiculo[playerid][i][Cor1Veh], pVeiculo[playerid][i][Cor2Veh], pVeiculo[playerid][i][GasolinaEx], pVeiculo[playerid][i][KilometrosEx], pVeiculo[playerid][i][Apreendido], pVeiculo[playerid][i][vVida], pVeiculo[playerid][i][TemTranca], pVeiculo[playerid][i][TemSom]);
        strcatEx(SalvarSQL, " WHERE `Nome` = '%s' AND `Slot`= %d", EscapeString(Niicky), i);
        mysql_query(IDConexao, SalvarSQL, false);
        if(mysql_errno(IDConexao) != 0) printf("[ ERRO ] Conta ao veiculo %d do(a) jogador(a) %s[%d]", i, Niicky, playerid);
        stringclear(SalvarSQL);
    }


    // Resetar Strings
        // Acessorios
    if(Backup == false)
    {
        for(new i=0; i < MAX_ACESSORIOSINV; i++){
            new dsada[AcessoriosJogador];
            pAcessorio[playerid][i] = dsada;
        }
            // Veículos
        for(new i=0; i < MAX_SLOT_VEH; i++){
            new sadas[PlayerVeiculoInfo];
            pVeiculo[playerid][i] = sadas;
        }

        for(new i=0; i < MAX_NUMEROS; i++){
            new sadas[AgendaTelefonica];
            pAgenda[playerid][i] = sadas;   
        }

            // Jogador
        new Deletar[JogadorInfo];
        Jogador[playerid] = Deletar;

        new Delet31231ar[JogadorDelay];
        pTempo[playerid] = Delet31231ar; 

        new ppa[SmsBlock];
        for(new i=0; i < MAX_PLAYERS; i++){
            if(JogadorSms[i][playerid][BloqueadoSms] == true) JogadorSms[i][playerid][BloqueadoSms] = false;
            JogadorSms[playerid][i] = ppa;
        }
    }
    return 1;
}

function TirarBackup()
{
    //SemTeleportes = gettime()+5;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] >= 2) SendClientMessage(i, 0xFFFF00FF, "| ADMIN | Servidor está tirando um backup das contas.");
        SalvarDados(i, true);
    }
    return 1;
}