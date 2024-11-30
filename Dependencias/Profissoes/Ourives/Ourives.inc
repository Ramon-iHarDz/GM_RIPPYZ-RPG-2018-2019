#include <YSI_Coding\y_hooks>

new LocalOur[4];

hook OnGameModeInit()
{
    LocalOur[0] = CreateDynamicRectangle(-739.1176,-2060.0952, -725.5892,-1989.8724, 0, 0, -1); 
    LocalOur[1] = CreateDynamicRectangle(-724.3477,-1973.0222, -697.7934,-1912.8347, 0, 0, -1); 
    LocalOur[2] = CreateDynamicRectangle(-760.4186,-2062.0688, -821.8388,-1972.8522, 0, 0, -1); 
    LocalOur[3] = CreateDynamicRectangle(-816.8371,-1941.2218, -717.8665,-1874.0682, 0, 0, -1); 

    CreateDynamic3DTextLabel("{00BFFF}Ourives\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, 831.1986,865.8692,12.5914, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 30.0, -1);
    CreateDynamicPickup(1239, 1, 831.1986,865.8692,12.5914, 0, 0, -1, 120.0, -1, 0);

    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid == LocalOur[0] || areaid == LocalOur[1] || areaid == LocalOur[2] || areaid == LocalOur[3]) MostrarMensagemBaixo(playerid, ConverterTexto("~r~Área ~w~Ourives"));
    return 1;
} 

hook OnPlayerLeaveDynArea(playerid, areaid)
{   
    if(areaid == LocalOur[0] || areaid == LocalOur[1] || areaid == LocalOur[2] || areaid == LocalOur[3]) OcultarMensagemBaixo(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pOurives[playerid][PegouOVeiculo] == true) DestroyVehicleEx(pOurives[playerid][VeiculoOID]); 
    if(pOurives[playerid][SegurandoCaixaOuro] == true) RemovePlayerAttachedObject(playerid, 9);
    if(pOurives[playerid][SegurandoPedraOuro] == true) RemovePlayerAttachedObject(playerid, 8);
    if(pOurives[playerid][CavandoStatus] == 1) KillTimer(pOurives[playerid][OuriTempo]);
    if(pOurives[playerid][CavandoStatus] == 4)
    {
        if(pOurives[playerid][SegurandoCaixaOuro] == true){
            RemovePlayerAttachedObject(playerid, 9);
            RemovePlayerAttachedObject(playerid, 8);
        }
    }

    DestroyDynamicObjectEx(pOurives[playerid][ObjetoMadeiraOuro]);
    DestroyDynamic3DTextLabelEx(pOurives[playerid][TextoOID][0]);
    DestroyDynamic3DTextLabelEx(pOurives[playerid][TextoOID][1]);
    DestroyDynamicObjectEx(pOurives[playerid][PedraOuroID]);
    DestroyDynamicMapIconEx(pOurives[playerid][IconeOuro]);
    DestroyDynamicCPEx(pOurives[playerid][CheckOuro]);

    for(new i=0; i < 5; i++){
        new DelatarR[CargasOuro];
        pOCaixa[playerid][i] = DelatarR;   
    }

    new DelataRRr[JogadorOurives];
    pOurives[playerid] = DelataRRr; 

    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid == pOurives[playerid][CheckOuro])
    {
        if(pOurives[playerid][SegurandoCaixaOuro] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está com uma caixa, vá atrás do veículo");
        
        ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
        RemovePlayerAttachedObject(playerid, 9);
        RemovePlayerAttachedObject(playerid, 8);
        pOurives[playerid][SegurandoCaixaOuro] = false;
        RetirarMaisUmOuro(playerid);
        new Mensagem[128];
        if(VerificarPedrasOuro(playerid) == 0)
        {
            new ValOhA = random(3500-2200)+2200;
            format(Mensagem, sizeof(Mensagem), "| OURIVES | Você entregou 5 pedras, encontrou {FFA500}%d{FFFFFF} ouros e ganhou {32CD32}$%s", random(30-20)+20, DinheiroSeparar(ValOhA));
            SendClientMessage(playerid, -1, Mensagem);

            DestroyDynamic3DTextLabelEx(pOurives[playerid][TextoOID][0]);
            pOurives[playerid][SegurandoTextoOuro] = false;

            Jogador[playerid][Dinheiro] += ValOhA;
            DestroyDynamicMapIconEx(pOurives[playerid][IconeOuro]);
            DestroyDynamicCPEx(pOurives[playerid][CheckOuro]); 
            pOurives[playerid][CavandoStatus] = 0; 
            return 1;
        }
        format(Mensagem, sizeof(Mensagem), "| OURIVES | Você ainda tem que pegar {FFA500}%d{FFFFFF} caixa(s)", VerificarPedrasOuro(playerid));
        SendClientMessage(playerid, -1, Mensagem);
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_ONFOOT)
    {
        if(pOurives[playerid][PegouOVeiculo] == false) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(pOurives[playerid][CavandoStatus] != 4) return 1;
        if(Jogador[playerid][uVeiculo] != pOurives[playerid][VeiculoOID]) return 1;

        pOurives[playerid][TextoOID][0] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'H'{FFFFFF} para pegar caixas e pedras", -1, 0.0000, -4.0999, -0.9000, 15.0, INVALID_PLAYER_ID, pOurives[playerid][VeiculoOID], 0, 0, 0, playerid, 15.0, -1);
        pOurives[playerid][SegurandoTextoOuro] = true;
    }

    else if(oldstate == PLAYER_STATE_ONFOOT)
    {
        if(pOurives[playerid][PegouOVeiculo] == false) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(pOurives[playerid][CavandoStatus] != 4) return 1;

        if(pOurives[playerid][SegurandoCaixaOuro] == true)
        {
            RemovePlayerAttachedObject(playerid, 9);
            RemovePlayerAttachedObject(playerid, 8);
            pOurives[playerid][SegurandoCaixaOuro] = false;
        }

        if(pOurives[playerid][SegurandoTextoOuro] == true)
        {
            DestroyDynamic3DTextLabelEx(pOurives[playerid][TextoOID][0]);
            pOurives[playerid][SegurandoTextoOuro] = false;
        }
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, 831.1986,865.8692,12.5914)) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(strcmp(Jogador[playerid][Profissao], "Ourives")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        if(VerificarTrabalhoOuro(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu serviço ainda não foi concluído");
        if(pOurives[playerid][CavandoStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu serviço ainda não foi concluído");
        if(GetPVarInt(playerid, "DelayAlugarOuro") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
        SetPVarInt(playerid, "DelayAlugarOuro", gettime()+10);

        if(pOurives[playerid][PegouOVeiculo] == false)
        {
            if(Jogador[playerid][CarteiraB] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar um carro ( Habilitação: B )");
            new soid = random(sizeof(SpawnOurives));
            pOurives[playerid][VeiculoOID] = CreateVehicleEx(playerid, 554, SpawnOurives[soid][OuroX], SpawnOurives[soid][OuroY], SpawnOurives[soid][OuroZ], SpawnOurives[soid][OuroA], random(255), random(255), 550, 0);
            VeiculoServer[pOurives[playerid][VeiculoOID]][Tranca] = 1;

            pOurives[playerid][ObjetoMadeiraOuro] = CreateDynamicObject(3800, SpawnOurives[soid][OuroX], SpawnOurives[soid][OuroY], SpawnOurives[soid][OuroZ], 0.0, 0.0, 0.0, 0, 0, -1, 100.0, 100.0, -1);
            AttachDynamicObjectToVehicle(pOurives[playerid][ObjetoMadeiraOuro], pOurives[playerid][VeiculoOID], 0.0000, -1.6000, -0.3000, 0.0000, 0.0000, 0.0000);

            pOurives[playerid][PegouOVeiculo] = true;
            Jogador[playerid][Trabalhando] = true;
            MarcarPosicao(playerid, SpawnOurives[soid][OuroX], SpawnOurives[soid][OuroY], SpawnOurives[soid][OuroZ]);
            SendClientMessage(playerid, 0xFFFF00FF, "| OURIVES | Seu veículo foi marcado no mapa");
            return 1;
        }

        VerificarMarcacao(playerid);
        DestroyDynamicObjectEx(pOurives[playerid][ObjetoMadeiraOuro]);
        DestroyVehicleEx(pOurives[playerid][VeiculoOID]);
        pOurives[playerid][PegouOVeiculo] = false;
        Jogador[playerid][Trabalhando] = false;
        SendClientMessage(playerid, 0xFFFF00FF, "| OURIVES | Você devolveu seu veículo");
    }


    // Pegar pedra ou caixa / entregar
    else if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(pOurives[playerid][PegouOVeiculo] == false) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;


        // Pegar caixa ou pedra
        if(pOurives[playerid][CavandoStatus] == 2)
        {
            // Veículo
            if(AtrasVeiculo(playerid, pOurives[playerid][VeiculoOID], 2.0))
            {
                if(pOurives[playerid][SegurandoCaixaOuro] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está com uma caixa na mão");
                pOurives[playerid][SegurandoCaixaOuro] = true;
                ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
                SetPlayerAttachedObject(playerid, 9, 19587, 5, 0.0989, 0.0000, 0.1400, -82.5999, -0.2000, -73.5999, 0.4300, 0.5680, 0.6140, 0xFFFFFFFF, 0xFFFFFFFF); 
            }

            else if(IsPlayerInRangeOfPoint(playerid, 2.0, pOurives[playerid][OuroPosX], pOurives[playerid][OuroPosY], pOurives[playerid][OuroPosZ]))
            {
                if(pOurives[playerid][SegurandoCaixaOuro] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Vá até seu veículo e pegue uma caixa");
                if(pOurives[playerid][SegurandoPedraOuro] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já pegou a pedra");
                pOurives[playerid][SegurandoPedraOuro] = true;

                UpdateDynamic3DTextLabelText(pOurives[playerid][TextoOID][1], -1, "Aperta {CCCCCC}'H'{FFFFFF} para colocar no veículo");
                DestroyDynamic3DTextLabelEx(pOurives[playerid][TextoOID][0]);
                DestroyDynamicObjectEx(pOurives[playerid][PedraOuroID]);
                
                ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
                SetPlayerAttachedObject(playerid, 8, 2936, 6, 0.0549, 0.0830, -0.1889, -2.5999, 0.8999, -1.1000, 0.2470, 0.1660, 0.3710, 0xFFFFFFFF, 0xFFFFFFFF);
                pOurives[playerid][CavandoStatus] = 3;
            }

        }

        else if(pOurives[playerid][CavandoStatus] == 4)
        {
            // Veículo
            if(AtrasVeiculo(playerid, pOurives[playerid][VeiculoOID], 2.0))
            {
                if(!IsPlayerInRangeOfPoint(playerid, 50.0, 677.7104,839.6183,-42.9609)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe do ponto de entrega");
                if(pOurives[playerid][SegurandoCaixaOuro] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está com uma caixa na mão");
                if(pOurives[playerid][SegurandoTextoOuro] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um problema, solicite um admin ou desenvolvedor!");
                pOurives[playerid][SegurandoCaixaOuro] = true;
                ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);

                SetPlayerAttachedObject(playerid, 9, 19587, 5, 0.0989, 0.0000, 0.1400, -82.5999, -0.2000, -73.5999, 0.4300, 0.5680, 0.6140, 0xFFFFFFFF, 0xFFFFFFFF);
                SetPlayerAttachedObject(playerid, 8, 2936, 6, 0.0549, 0.0830, -0.1889, -2.5999, 0.8999, -1.1000, 0.2470, 0.1660, 0.3710, 0xFFFFFFFF, 0xFFFFFFFF); 
            }    
        }

        // Colocar no veículo
        else if(pOurives[playerid][CavandoStatus] == 3)
        {
            if(AtrasVeiculo(playerid, pOurives[playerid][VeiculoOID], 3.0))
            {
                new id = VericarEspacoOuro(playerid);
                RemovePlayerAttachedObject(playerid, 9);
                RemovePlayerAttachedObject(playerid, 8);
                DestroyDynamic3DTextLabelEx(pOurives[playerid][TextoOID][1]);
                pOurives[playerid][SegurandoPedraOuro] = false;
                pOurives[playerid][SegurandoCaixaOuro] = false;
                pOCaixa[playerid][id][TemCaixa] = true;
                ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
                
                if(VericarEspacoOuro(playerid) == -1)
                {
                    pOurives[playerid][IconeOuro] = CreateDynamicMapIcon(677.7104,839.6183,-42.9609, 11, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
                    pOurives[playerid][CheckOuro] = CreateDynamicCP(677.7104,839.6183,-42.9609, 2.0, 0, 0, playerid, 100.0);
                    pOurives[playerid][CavandoStatus] = 4;
                    SendClientMessage(playerid, -1, "| OURIVES | Você pegou o máximo de pedras, vá até o local marcado no mapa");
                }
                else   
                {
                    new Mensagem[128];
                    pOurives[playerid][CavandoStatus] = 0;
                    format(Mensagem, sizeof(Mensagem), "| OURIVES | Você tem que achar mais {CCCCCC}%d{FFFFFF} pedra(s)", RestamOuros(playerid));
                    SendClientMessage(playerid, -1, Mensagem);
                }
            }
        }

    }
    return 1;
}

CMD:cavar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Ourives")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pOurives[playerid][PegouOVeiculo] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhum veículo alugado de ourives");
    if(!IsPlayerInDynamicArea(playerid, LocalOur[0]) && !IsPlayerInDynamicArea(playerid, LocalOur[1]) && !IsPlayerInDynamicArea(playerid, LocalOur[2]) && !IsPlayerInDynamicArea(playerid, LocalOur[3])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na área dos ourives");
    if(VericarEspacoOuro(playerid) == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem mais espaço para pegar pedras");
    if(pOurives[playerid][CavandoStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está fazendo esse processo, conclua e inicie outro");
    new Float:VehPo[3];
    GetPlayerPos(playerid, VehPo[0], VehPo[1], VehPo[2]);
    if(!IsVehicleInRangeOfPoint(pOurives[playerid][VeiculoOID], 50.0, VehPo[0], VehPo[1], VehPo[2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo alugado não está perto de você");

    GetPlayerPos(playerid, pOurives[playerid][OuroPosX], pOurives[playerid][OuroPosY], pOurives[playerid][OuroPosZ]);
    pOurives[playerid][CavandoStatus] = 1;
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
    TogglePlayerControllable(playerid, 0);
    CriarProgresso(playerid, "Procurando Pedras", "Cavando", 700);
    SendClientMessage(playerid, 0xFFFF00FF, "| OURIVES | Você está procurando, aguarde."); 
    return 1;
}

CMD:localcavar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Ourives")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pOurives[playerid][PegouOVeiculo] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhum veículo alugado de ourives");
    EnviarGps(playerid, -768.1153,-2049.5894,5.7274);
    SendClientMessage(playerid, 0x32CD32FF, "| OURIVES | Siga o ponto marcado no mapa"); 
    return 1;
}