#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    LenhadorMensagem = CreateDynamicRectangle(-382.1227,-1480.5509, -468.2939,-1596.8207, 0, 0, -1); 

    CreateDynamicPickup(1239, 1, -503.2280,-1509.6061,11.4961, 0, 0, -1, 90.0);    
    CreateDynamicPickup(1239, 1, -503.2404,-1518.8188,10.8504, 0, 0, -1, 90.0);    

    CreateDynamic3DTextLabel("{00BFFF}Madeireira\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para pegar motoserra", -1, -503.2280,-1509.6061,11.4961, 40.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);
    CreateDynamic3DTextLabel("{00BFFF}Madeireira\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, -503.2404,-1518.8188,10.8504, 40.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);

    for(new i=0; i < sizeof(LenhaLoad); i++)
    {
        Lenha[i][TemLenha] = true;
        Lenha[i][LenhaObjeto] = CreateDynamicObject(654, LenhaLoad[i][LenhaLPosX], LenhaLoad[i][LenhaLPosY], LenhaLoad[i][LenhaLPosZ], LenhaLoad[i][LenhaLRotX], LenhaLoad[i][LenhaLRotY], LenhaLoad[i][LenhaLRotZ], 0, 0, -1, 500.0, 500.0, -1);   
        LenhaTexto[i] = CreateDynamic3DTextLabel("{32CD32}Madeireira{FFFFFF}\nDisponível", 0xFFFFFFFF, LenhaLoad[i][LenhaLPosX], LenhaLoad[i][LenhaLPosY], LenhaLoad[i][LenhaLPosZ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1);
    }
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid == LenhadorMensagem) MostrarMensagemBaixo(playerid, ConverterTexto("Área de ~r~Lenhador~w~, cuidado."));
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{   
    if(areaid == LenhadorMensagem) OcultarMensagemBaixo(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamicObjectEx(Lenhador[playerid][LenhaObjetoID]);
    DestroyDynamicCPEx(Lenhador[playerid][CheckLenhaID]);
    DestroyDynamic3DTextLabelEx(Lenhador[playerid][LenhaVehTexto]);

    if(Lenhador[playerid][LenhadorVeiculo] == true) DestroyVehicleEx(Lenhador[playerid][LenhadorVeiculoID]);
    if(Lenhador[playerid][MadeiraMao] == true) RemovePlayerAttachedObject(playerid, 9);
    if(Lenhador[playerid][StatusLenha] == 1 || Lenhador[playerid][StatusLenha] == 2)
    {
        KillTimer(Lenhador[playerid][LenhaTempo]);
        if(Lenhador[playerid][StatusLenha] == 1)
        {
            UpdateDynamic3DTextLabelText(LenhaTexto[Lenhador[playerid][SuaLenhaID]], 0xFFFFFFFF, "{32CD32}Madeireira{FFFFFF}\nDisponível");
            Lenha[Lenhador[playerid][SuaLenhaID]][LenhaSendoUsada] = false;
        }   
        if(Lenhador[playerid][StatusLenha] == 2)
        {
            UpdateDynamic3DTextLabelText(LenhaTexto[Lenhador[playerid][SuaLenhaID]], 0xFFFFFFFF, "{32CD32}Madeireira{FFFFFF}\n{FFFF00}Deconectado(a), regenerando.");
            SetTimerEx("CortandoArvore", 40000, false, "ddd", 3, Lenhador[playerid][SuaLenhaID], playerid);
        } 
    }

    new Crazzp[JogadorLenhador];
    Lenhador[playerid] = Crazzp;
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(Lenhador[playerid][Motoserra] == true) Lenhador[playerid][Motoserra] = false;
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_ONFOOT)
    {
        if(Lenhador[playerid][LenhadorVeiculo] == true && Lenhador[playerid][AntigoLenhaVehID] == Lenhador[playerid][LenhadorVeiculoID])
        {
            if(Lenhador[playerid][StatusLenha] != 3) return 1;
            if(!IsVehicleInRangeOfPoint(Lenhador[playerid][LenhadorVeiculoID], 50.0, -91.9084,-7.3044,3.2585)) return 1;

            if(Lenhador[playerid][TemTextoLenha] == false)
            {
                Lenhador[playerid][LenhaVehTexto] = CreateDynamic3DTextLabel("Aperte {CCCCCC}H{FFFFFF} para pegar as madeiras", 0xFFFFFFFF, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, Lenhador[playerid][LenhadorVeiculoID], 0, 0, 0, playerid, 20.0, -1);
                Lenhador[playerid][TemTextoLenha] = true;
            }
 
        }
        Lenhador[playerid][AntigoLenhaVehID] = GetPlayerVehicleID(playerid);
    }  

    else if(newstate == PLAYER_STATE_DRIVER)
    {
        if(Lenhador[playerid][MadeiraMao] == true)
        {
            RemovePlayerAttachedObject(playerid, 9);   
            Lenhador[playerid][MadeiraMao] = true;
        }
        if(Lenhador[playerid][StatusLenha] == 2)
        {
            new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
            GetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
            if(portamalas == VEHICLE_PARAMS_ON) SetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_OFF, ob); 

            DestroyDynamic3DTextLabelEx(Lenhador[playerid][LenhaVehTexto]);
            Lenhador[playerid][StatusLenha] = 0;
            Lenhador[playerid][TemTextoLenha] = false;
            Lenhador[playerid][LenhaQuebrando] = false;
            SendClientMessage(playerid, 0xFFFF00FF, "| LENHADOR | Você entrou no veículo e seu serviço foi cancelado");
            return 1;
        }

        if(GetPlayerVehicleID(playerid) != Lenhador[playerid][LenhadorVeiculoID]) return 1;
        if(Lenhador[playerid][StatusLenha] == 3)
        {
            if(Lenhador[playerid][TemTextoLenha] == true)
            {
                DestroyDynamic3DTextLabelEx(Lenhador[playerid][LenhaVehTexto]);
                Lenhador[playerid][TemTextoLenha] = false;
            }
        }
    }

    if(newstate != PLAYER_STATE_ONFOOT){
        Lenhador[playerid][AntigoLenhaVehID] = GetPlayerVehicleID(playerid);  
    }

    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        // Pegar Motoserra
        if(IsPlayerInRangeOfPoint(playerid, 3.0, -503.2280,-1509.6061,11.4961))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa sair do veículo");
            if(strcmp(Jogador[playerid][Profissao], "Lenhador")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(Lenhador[playerid][LenhaQuebrando] == true || Lenhador[playerid][StatusLenha] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu serviço ainda não foi concluído!");
            if(Lenhador[playerid][Motoserra] == false)
            {
                if(Jogador[playerid][CarteiraB] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar um carro ( Habilitação: B )");
                GivePlayerWeapon(playerid, 9, 1); 
                Lenhador[playerid][Motoserra] = true;  
                return 1;
            }
            if(Lenhador[playerid][LenhaQuebrando] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu serviço ainda não foi concluído!");
            RemoverArma(playerid, 9);
            Lenhador[playerid][Motoserra] = false;
        }

        // Pegar Veículo
        else if(IsPlayerInRangeOfPoint(playerid, 3.0, -503.2404,-1518.8188,10.8504))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa sair do veículo");
            if(strcmp(Jogador[playerid][Profissao], "Lenhador")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(Lenhador[playerid][LenhaQuebrando] == true || Lenhador[playerid][StatusLenha] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu serviço ainda não foi concluído!");
            if(Lenhador[playerid][LenhadorVeiculo] == false)
            {
                if(Lenhador[playerid][Motoserra] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Pegue sua motoserra antes");
                Jogador[playerid][Trabalhando] = true;
                new rra = random(sizeof(VeiculoLLoad));
                Lenhador[playerid][LenhadorVeiculoID] = CreateVehicleEx(playerid, 554, VeiculoLLoad[rra][LenhaVehX], VeiculoLLoad[rra][LenhaVehY], VeiculoLLoad[rra][LenhaVehZ], VeiculoLLoad[rra][LenhaVehA], 159, 159, 360, 0);
                MarcarPosicao(playerid, VeiculoLLoad[rra][LenhaVehX], VeiculoLLoad[rra][LenhaVehY], VeiculoLLoad[rra][LenhaVehZ]);
                SendClientMessage(playerid, 0xFFFF00FF, "| MADEIREIRA | Seu veículo foi marcado no mapa");
                Lenhador[playerid][LenhadorVeiculo] = true; 
                return 1;
            }
            if(Lenhador[playerid][Motoserra] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Devolva sua motoserra antes");
            DestroyVehicleEx(Lenhador[playerid][LenhadorVeiculoID]);
            VerificarMarcacao(playerid);
            SendClientMessage(playerid, 0xFFFF00FF, "| MADEIREIRA | Você devolveu seu veículo");
            Lenhador[playerid][LenhadorVeiculo] = false;
            Jogador[playerid][Trabalhando] = false; 
        }
    }


    // Colocar no veículo
    else if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(strcmp(Jogador[playerid][Profissao], "Lenhador")) return 1;
        if(Lenhador[playerid][LenhadorVeiculo] == false) return 1;

        if(AtrasVeiculo(playerid, Lenhador[playerid][LenhadorVeiculoID], 2.0))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa sair do veículo");
            if(Lenhador[playerid][StatusLenha] == 3)
            {
                if(Lenhador[playerid][MadeiraMao] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está segurando as madeiras");
                if(!IsPlayerInRangeOfPoint(playerid, 90, -91.9084,-7.3044,3.2585)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto do local de entrega");
                if(!IsVehicleInRangeOfPoint(Lenhador[playerid][LenhadorVeiculoID], 90, -91.9084,-7.3044,3.2585)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está perto do local");
                Lenhador[playerid][MadeiraMao] = true;
                
                DestroyDynamicObjectEx(Lenhador[playerid][LenhaObjetoID]);
                SetPlayerAttachedObject(playerid, 9, 1463, 5, 0.0659, 0.1059, 0.1839, 90.7999, 178.9997, 98.4001, 0.4389, 0.3140, 0.4209, 0xFFFFFFFF, 0xFFFFFFFF);
                ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
        
                new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
                GetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
                if(portamalas == VEHICLE_PARAMS_OFF) SetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_ON, ob); 
                return 1;
            }

            if(Lenhador[playerid][MadeiraMao] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está segurando as madeiras!");

            DestroyDynamic3DTextLabelEx(Lenhador[playerid][LenhaVehTexto]);
            Lenhador[playerid][TemTextoLenha] = false;

            ApplyAnimation(playerid, "CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
            RemovePlayerAttachedObject(playerid, 9);

            new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
            GetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
            if(portamalas == VEHICLE_PARAMS_ON) SetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_OFF, ob); 
            
            Lenhador[playerid][LenhaObjetoID] = CreateDynamicObject(1463, 0.0000, -1.7000, 0.3000, 0.0000, 0.0000, 0.0000, 0, 0, -1, 70.0, 70.0, -1);
            AttachDynamicObjectToVehicle(Lenhador[playerid][LenhaObjetoID], Lenhador[playerid][LenhadorVeiculoID], 0.0000, -1.7000, 0.3000, 0.0000, 0.0000, 0.0000);

            Lenhador[playerid][CheckLenhaID] = CreateDynamicCP(-91.9084,-7.3044,3.2585, 1.0, 0, 0, playerid, 99999.0, -1, 0);

            Lenhador[playerid][StatusLenha] = 3;
            Lenhador[playerid][LenhaQuebrando] = false;
            Lenhador[playerid][MadeiraMao] = false; 
        }
    }

    // Pegar madeira
    else if(newkeys == KEY_NO && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(strcmp(Jogador[playerid][Profissao], "Lenhador")) return 1;
        if(Lenhador[playerid][LenhaQuebrando] == false) return 1;
        new id = Lenhador[playerid][SuaLenhaID];
        if(!IsPlayerInRangeOfPoint(playerid, 6.0, LenhaLoad[id][LenhaLPosX], LenhaLoad[id][LenhaLPosY], LenhaLoad[id][LenhaLPosZ])) return 1;
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa sair do veículo");
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(Lenhador[playerid][StatusLenha] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde, essa árvore não está pronta");
        if(Lenhador[playerid][MadeiraMao] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está segurando as madeiras, coloque em seu veículo agora");
        if(!IsVehicleInRangeOfPoint(Lenhador[playerid][LenhadorVeiculoID], 20.0, LenhaLoad[id][LenhaLPosX], LenhaLoad[id][LenhaLPosY], LenhaLoad[id][LenhaLPosZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está perto da árvore!");

        KillTimer(Lenhador[playerid][LenhaTempo]);
        SetTimerEx("CortandoArvore", 60000, false, "ddd", 3, id, playerid);
        UpdateDynamic3DTextLabelText(LenhaTexto[id], 0xFFFFFFFF, "{32CD32}Árvore{FFFFFF}\n{FFFF00}Regenerando");

        Lenhador[playerid][LenhaVehTexto] = CreateDynamic3DTextLabel("Aperte {CCCCCC}H{FFFFFF} para colocar as madeiras", 0xFFFFFFFF, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, Lenhador[playerid][LenhadorVeiculoID], 0, 0, 0, playerid, 20.0, -1);
        Lenhador[playerid][TemTextoLenha] = true;

        SetPlayerAttachedObject(playerid, 9, 1463, 5, 0.0659, 0.1059, 0.1839, 90.7999, 178.9997, 98.4001, 0.4389, 0.3140, 0.4209, 0xFFFFFFFF, 0xFFFFFFFF);
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
        
        new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
        GetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
        if(portamalas == VEHICLE_PARAMS_OFF) SetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_ON, ob); 
        
        Lenhador[playerid][MadeiraMao] = true;
        SendClientMessage(playerid, 0xFFFF00FF, "| LENHADOR | Você pegou a madeira, leve-a até seu veículo");
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(strcmp(Jogador[playerid][Profissao], "Lenhador")) return 1;
    if(checkpointid != Lenhador[playerid][CheckLenhaID]) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa sair do veículo");
    if(Lenhador[playerid][MadeiraMao] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Vá atrás do seu veículo e pegue as madeiras");

    new Mensagem[128],
        DinheLenha = random(950-650)+650;

    if(Lenhador[playerid][TemTextoLenha] == true)
    {
        DestroyDynamic3DTextLabelEx(Lenhador[playerid][LenhaVehTexto]);
        Lenhador[playerid][TemTextoLenha] = false;
    }

    format(Mensagem, sizeof(Mensagem), "| MADEIREIRA | Você recebeu {32CD32}$%s{FFFFFF} por {00BFFF}%d{FFFFFF} madeiras", DinheiroSeparar(DinheLenha), random(5-3)+3);
    SendClientMessage(playerid, -1, Mensagem);

    ApplyAnimation(playerid, "CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
    RemovePlayerAttachedObject(playerid, 9);
    new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
    GetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
    if(portamalas == VEHICLE_PARAMS_ON) SetVehicleParamsEx(Lenhador[playerid][LenhadorVeiculoID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_OFF, ob); 

    Lenhador[playerid][StatusLenha] = 0;
    Lenhador[playerid][LenhaQuebrando] = false;
    Lenhador[playerid][MadeiraMao] = false;

    DestroyDynamicCPEx(Lenhador[playerid][CheckLenhaID]);
    Jogador[playerid][Dinheiro] += DinheLenha;
    return 1;
}

CMD:derrubar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Lenhador")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa sair do veículo");
    if(!IsPlayerInDynamicArea(playerid, LenhadorMensagem)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na madeireira");
    if(Lenhador[playerid][LenhaQuebrando] == true || Lenhador[playerid][StatusLenha] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu serviço ainda não foi concluído!");
    if(Lenhador[playerid][Motoserra] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem uma motoserra, vá até dentro da HQ e pegue");
    if(Lenhador[playerid][LenhadorVeiculo] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Alugue um veículo antes de começar");
    if(GetPlayerWeapon(playerid) != WEAPON_CHAINSAW) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está segurando a motoserra!");

    new bool:tha = false;
    for(new i=0; i < sizeof(LenhaLoad); i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 7.0, LenhaLoad[i][LenhaLPosX], LenhaLoad[i][LenhaLPosY], LenhaLoad[i][LenhaLPosZ])) continue;
        if(Lenha[i][TemLenha] == false) continue;
        if(Lenha[i][LenhaQuebrada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa árvore está quebrada, aguarde");
        if(Lenha[i][LenhaSendoUsada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa árvore já está sendo usada");

        Lenha[i][LenhaSendoUsada] = true;
        Lenhador[playerid][LenhaQuebrando] = true;
        Lenhador[playerid][SuaLenhaID] = i;
        Lenhador[playerid][StatusLenha] = 1;
        TogglePlayerControllable(playerid, 0);
        ApplyAnimation(playerid, "CHAINSAW", "WEAPON_csaw", 4.1, 1, 1, 1, 1, 1);

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "{32CD32}Madeireira{FFFFFF}\n{FFFFFF}De: %s[%d]", PegarNick(playerid), playerid);
        UpdateDynamic3DTextLabelText(LenhaTexto[i], 0xFFFFFFFF, Mensagem);
        Lenhador[playerid][LenhaTempo] = SetTimerEx("CortandoArvore", 20000, false, "ddd", 1, i, playerid);

        SendClientMessage(playerid, 0xFFFF00FF, "| MADEIREIRA | Você está quebrando e cortando essa árvore, aguarde.");
        tha = true;
        break;
    }
    if(tha == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de nenhuma árvore");
    return 1;
}