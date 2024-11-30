#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(strcmp(Jogador[playerid][Profissao], "Transportador")) return 1;

    // Pegar entrega no caminhão
    if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(!VerificarEntrega(playerid)) return 1;
        new Float:cMotoH[3];
        new Float:X, Float:Y;
        GetVehiclePos(pTransportador[playerid][VeiculoTransID], cMotoH[0], cMotoH[1], cMotoH[2]);
        GetXYBehindOfVehicle(pTransportador[playerid][VeiculoTransID], X, Y, 4.0);
        if(IsPlayerInRangeOfPoint(playerid, 2.0, X, Y, cMotoH[2]))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            new id = pTransportador[playerid][DuplaID];
            if(pTransportador[playerid][ComDupla] == true && pTransportador[playerid][PegouVeiculo] == false)
            {
                if(pTransportador[id][ComTexto] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de nenhuma entrega");
            }
            else if(pTransportador[playerid][ComTexto] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de nenhuma entrega");

            if(pTransportador[playerid][NaMao] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem uma caixa na mão");
            pTransportador[playerid][ComTexto] = true;
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
            SetPlayerAttachedObject(playerid, 9, 1220, 3, 0.1310, -0.4270, -0.1290, -7.3999, 3.4000, 29.9000, 0.5850, 0.5280, 0.6530, 0xFFFFFFFF, 0xFFFFFFFF);
            pTransportador[playerid][NaMao] = true;
        
            new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
            GetVehicleParamsEx(pTransportador[playerid][VeiculoTransID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
            if(portamalas == VEHICLE_PARAMS_OFF) SetVehicleParamsEx(pTransportador[playerid][VeiculoTransID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_ON, ob);  

            if(pTransportador[playerid][ComDupla] == true && pTransportador[id][ComTexto] == true){
                UpdateDynamic3DTextLabelText(pTransportador[id][TransTexto], -1, "{FFFF00}Aguardando Entrega");
            }
            UpdateDynamic3DTextLabelText(pTransportador[playerid][TransTexto], -1, "{FFFF00}Aguardando Entrega");
        }
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(strcmp(Jogador[playerid][Profissao], "Transportador")) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0) return 1;

    // Verificações
    if(newstate != PLAYER_STATE_ONFOOT)
    {
        if(pTransportador[playerid][PegouVeiculo] == true && pTransportador[playerid][VeiculoTransOld] == pTransportador[playerid][VeiculoTransID] && VerificarEntrega(playerid))
        {
            new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
            GetVehicleParamsEx(pTransportador[playerid][VeiculoTransID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
            if(portamalas == VEHICLE_PARAMS_ON) SetVehicleParamsEx(pTransportador[playerid][VeiculoTransID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_OFF, ob);  
            if(pTransportador[playerid][ComTexto] == true)
            {
                new id = pTransportador[playerid][DuplaID];
                if(pTransportador[playerid][ComDupla] == true) DestroyDynamic3DTextLabelEx(pTransportador[id][TransTexto]);
                DestroyDynamic3DTextLabelEx(pTransportador[playerid][TransTexto]);
                pTransportador[playerid][ComTexto] = false;
            } 
            if(pTransportador[playerid][NaMao] == true)
            {
                RemovePlayerAttachedObject(playerid, 9);
                ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
                pTransportador[playerid][NaMao] = false;
            }
        }
        pTransportador[playerid][VeiculoTransOld] = GetPlayerVehicleID(playerid);
    }


    else if(newstate == PLAYER_STATE_ONFOOT && pTransportador[playerid][VeiculoTransID] == pTransportador[playerid][VeiculoTransOld])
    {
        if(pTransportador[playerid][PegouVeiculo] == false) return 1;
        if(pTransportador[playerid][ComTexto] == true) return 1;

        new id;
        for(new i=0; i < 4; i++)
        {
            if(pTransporte[playerid][i][EntregaAtiva] == false) continue;
            id = pTransporte[playerid][i][EmpresaTransID];
            if(!IsPlayerInRangeOfPoint(playerid, 50.0, pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ])) continue;
            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "{FFFFFF}Aperte {CCCCCC}H{FFFFFF} para pegar ( Restante: {CCCCCC}%d{FFFFFF} )", pTransporte[playerid][i][REntregas]);
            pTransportador[playerid][TransTexto] = CreateDynamic3DTextLabel(Mensagem, 0xFFFFFFFF, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, pTransportador[playerid][VeiculoTransID], 0, 0, 0, playerid, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
            
            if(pTransportador[playerid][ComDupla] == true){
                new cuaa = pTransportador[playerid][DuplaID];
                pTransportador[cuaa][TransTexto] = CreateDynamic3DTextLabel(Mensagem, 0xFFFFFFFF, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, pTransportador[cuaa][VeiculoTransID], 0, 0, 0, cuaa, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
            } 
            pTransportador[playerid][ComTexto] = true; 
            break;
        }
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(strcmp(Jogador[playerid][Profissao], "Transportador")) return 1;
    
    new id = pTransportador[playerid][DuplaID];
    for(new i=0; i < 4; i++)
    {
        if(pTransporte[playerid][i][EntregaAtiva] == false) continue;
        if(pTransporte[playerid][i][TransCheck] != checkpointid) continue;   

        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa sair do veículo");
        if(pTransportador[playerid][NaMao] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa pegar as encomendas atrás do caminhão");
        
        // Remover caixa da mão
        ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
        RemovePlayerAttachedObject(playerid, 9);
        pTransportador[playerid][NaMao] = false;

        // Remover uma unidade do caminhão
        if(pTransportador[playerid][ComDupla] == true)
        {
            pTransporte[playerid][i][REntregas]--;
            pTransporte[id][i][REntregas]--;
        } 
        else pTransporte[playerid][i][REntregas] --;

     
        // Verificar se as entregas acabaraqm
        new Mensagem[128], bool:acabou = false;
        if(pTransportador[playerid][ComDupla] == true && pTransportador[playerid][PegouVeiculo] == false)
        {
            if(pTransporte[id][i][REntregas] <= 0) acabou = true;
        }
        else if(pTransporte[playerid][i][REntregas] <= 0) acabou = true;


        if(acabou == true)
        {
            new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;

            if(pTransportador[playerid][ComDupla] == true) pTransporte[id][i][EntregaAtiva] = false;
            pTransporte[playerid][i][EntregaAtiva] = false;

            GetVehicleParamsEx(pTransportador[playerid][VeiculoTransID], Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
            if(portamalas == VEHICLE_PARAMS_ON) SetVehicleParamsEx(pTransportador[playerid][VeiculoTransID], Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_OFF, ob);   
            if(pTransportador[playerid][ComDupla] == true)
            {
                if(pTransportador[id][ComTexto] == true)
                {
                    DestroyDynamic3DTextLabelEx(pTransportador[id][TransTexto]);
                    pTransportador[id][ComTexto] = false;
                }
                DestroyDynamic3DTextLabelEx(pTransportador[playerid][TransTexto]);
                DestroyDynamicCPEx(pTransporte[playerid][i][TransCheck]);
                DestroyDynamicCPEx(pTransporte[id][i][TransCheck]);
                DestroyDynamicMapIconEx(pTransporte[id][i][TransIcone]);
                DestroyDynamicMapIconEx(pTransporte[playerid][i][TransIcone]);
                pTransportador[playerid][ComTexto] = false;
            }
            else
            {
                if(pTransportador[playerid][ComTexto] == true)
                {
                    DestroyDynamic3DTextLabelEx(pTransportador[playerid][TransTexto]);
                    pTransportador[playerid][ComTexto] = false;
                }
                DestroyDynamicCPEx(pTransporte[playerid][i][TransCheck]);
                DestroyDynamicMapIconEx(pTransporte[playerid][i][TransIcone]);
            }
            // EnviarDinheiroEmpresa(pTransporte[playerid][i][REntregas], random(50-30)+30); 

            new Ganho, Totalzy;
            if(pTransportador[playerid][ComDupla] == true)
            {
                Ganho = random(3200-1200)+1200;
                Totalzy = Ganho/2;
                Jogador[playerid][Dinheiro] += Totalzy;
                Jogador[id][Dinheiro] += Totalzy;

                SendClientMessage(playerid, 0xFFFF00FF, "| TRANSPORTADORA | Você entregou as encomendas nessa empresa com sucesso!");
                SendClientMessage(id, 0xFFFF00FF, "| TRANSPORTADORA | Você entregou as encomendas nessa empresa com sucesso!");

                format(Mensagem, sizeof(Mensagem), "| TRANSPORTADORA | Você recebeu {32CD32}$%s{FFFFFF} pela entrega com %s[%d]", DinheiroSeparar(Totalzy), PegarNick(id), id);
                SendClientMessage(playerid, -1, Mensagem);

                format(Mensagem, sizeof(Mensagem), "| TRANSPORTADORA | Você recebeu {32CD32}$%s{FFFFFF} pela entrega com %s[%d]", DinheiroSeparar(Totalzy), PegarNick(playerid), playerid);
                SendClientMessage(id, -1, Mensagem);
            }
            else
            {
                SendClientMessage(playerid, 0xFFFF00FF, "| TRANSPORTADORA | Você entregou as encomendas nessa empresa com sucesso!");
                Ganho = random(850-700)+700;  
                Jogador[playerid][Dinheiro] += Ganho; 
                format(Mensagem, sizeof(Mensagem), "| TRANSPORTADORA | Você recebeu {32CD32}$%s", DinheiroSeparar(Ganho));
                SendClientMessage(playerid, -1, Mensagem);
            }
            
        
            // Remover animação caso tenha
            if(pTransportador[playerid][ComDupla] == true){
                if(pTransportador[id][NaMao] == true){
                    RemovePlayerAttachedObject(id, 9);  
                    ApplyAnimation(id,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
                    pTransportador[id][NaMao] = false;
                } 
            }
        
        }
        else
        {
            // format(Mensagem, sizeof(Mensagem), "| TRANSPORTADOR | Você ainda tem %d entrega(s) para pegar atrás do caminhão!", pTransporte[playerid][i][REntregas]);
            // SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
            format(Mensagem, sizeof(Mensagem), "{FFFFFF}Aperte {CCCCCC}H{FFFFFF} para pegar ( Restante: {CCCCCC}%d{FFFFFF} )", pTransporte[playerid][i][REntregas]);
            if(pTransportador[playerid][ComDupla] == true) UpdateDynamic3DTextLabelText(pTransportador[id][TransTexto], -1, Mensagem);
            UpdateDynamic3DTextLabelText(pTransportador[playerid][TransTexto], -1, Mensagem);
        }

        break;

    }
    return 1;
}

CMD:encomendas(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Transportador")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    
    if(pTransportador[playerid][ComDupla] == false){
        if(pTransportador[playerid][PegouVeiculo] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo da transportadora alugado");
    }
    
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPlayerVehicleID(playerid) != pTransportador[playerid][VeiculoTransID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo da transportadora");
    if(!IsPlayerInDynamicArea(playerid, TransporteMensagem)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na área de carregamento");
    if(VerificarEntrega(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem entregas");
    EntregasTransporteEmpresas(playerid);
    return 1;
}

CMD:dupla(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Transportador")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    
    if(pTransportador[playerid][ComDupla] == true)
    {
        if(VerificarEntrega(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem entregas");
        new id = pTransportador[playerid][DuplaID];
        if(pTransportador[id][PegouVeiculo] == false) Jogador[playerid][Trabalhando] = false;
        pTransportador[id][ComDupla] = false;
        pTransportador[playerid][ComDupla] = false;   

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| AVISO | Seu parceiro(a) %s[%d] saiu de dupla", PegarNick(playerid), playerid);
        SendClientMessage(id, 0xFF4500FF, Mensagem);

        format(Mensagem, sizeof(Mensagem), "| AVISO | Você não está fazendo mais dupla com %s[%d]", PegarNick(id), id);
        SendClientMessage(playerid, 0xFF4500FF, Mensagem);
        return 1;
    }
    
    if(pTransportador[playerid][PegouVeiculo] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo da transportadora alugado");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPlayerVehicleID(playerid) != pTransportador[playerid][VeiculoTransID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo da transportadora");
    if(VerificarEntrega(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem entregas");

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| TRANSPORTADORA | O(A) %s[%d] iniciou serviço com você", PegarNick(playerid), playerid);

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(i == playerid) continue;
        if(!IsPlayerConnected(i)) continue;
        if(strcmp(Jogador[i][Profissao], "Transportador")) continue;
        if(GetPlayerState(i) != PLAYER_STATE_PASSENGER || GetPlayerVehicleID(i) != pTransportador[playerid][VeiculoTransID]) continue;
    
        if(Jogador[i][Trabalhando] == true)
        {
            new String32[128];
            format(String32, sizeof(String32), "| ERRO | %s[%d] está com serviço ativo ainda", PegarNick(i), i);
            SendClientMessage(playerid, 0xfc520fFF, String32);
            return 1;    
        }

        if(pTransportador[i][PegouVeiculo] == true)
        {
            new String32[128];
            format(String32, sizeof(String32), "| ERRO | %s[%d] está com um veículo alugado", PegarNick(i), i);
            SendClientMessage(playerid, 0xfc520fFF, String32);
            return 1;
        }
    
        if(pTransportador[i][ComDupla] == true)
        {
            new String32[128];
            format(String32, sizeof(String32), "| ERRO | %s[%d] já tem um(a) parceiro(a)", PegarNick(i), i);
            SendClientMessage(playerid, 0xfc520fFF, String32);
            return 1;
        }

        pTransportador[i][ComDupla] = true;
        pTransportador[playerid][ComDupla] = true;
        Jogador[i][Trabalhando] = true;

        VeiculoServer[pTransportador[playerid][VeiculoTransID]][Dono2] = i;
        pTransportador[playerid][DuplaID] = i;
        pTransportador[i][DuplaID] = playerid;
        pTransportador[i][VeiculoTransID] = pTransportador[playerid][VeiculoTransID];

        SendClientMessage(i, 0xFFFF00FF, Mensagem);
        format(Mensagem, sizeof(Mensagem), "| TRANSPORTADORA | O(A) %s[%d] iniciou serviço com você", PegarNick(i), i);
        SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
    }

    return 1;
}

stock EntregasTransporteEmpresas(playerid)
{
    new CapEntrega = 0,
        cUID,
        Mensagem[128],
        rrd = 0,
        id = pTransportador[playerid][DuplaID]
    ;

    for(new i=0; i < 99999; i++)
    {
        cUID = random(MAX_EMPRESAS);
        if(pEmpresa[cUID][Colocado] == false) continue;
        //if(!IsPlayerInRangeOfPoint(playerid, 990.0, pEmpresa[cUID][ePosicaoX], pEmpresa[cUID][ePosicaoY], pEmpresa[cUID][ePosicaoZ])) continue;
        for(new o=0; o < 4; o++)
        {
            if(pTransporte[playerid][o][EntregaAtiva] == true) continue;
            new bool:pdd = false;
            for(new p=0; p < 4; p++){
                if(pTransporte[playerid][p][EmpresaTransID] != cUID) continue;
                pdd = true;
                break;
            }
            
            if(pdd == true) break;
            if(pTransportador[playerid][ComDupla] == true) rrd = random(12-8)+8;
            else rrd = random(6-3)+3;
            pTransporte[playerid][o][TransCheck] = CreateDynamicCP(pEmpresa[cUID][ePosicaoX], pEmpresa[cUID][ePosicaoY], pEmpresa[cUID][ePosicaoZ], 1.0, 0, 0, playerid, 100.0);
            pTransporte[playerid][o][TransIcone] = CreateDynamicMapIcon(pEmpresa[cUID][ePosicaoX], pEmpresa[cUID][ePosicaoY], pEmpresa[cUID][ePosicaoZ], 60, -1, 0, 0, playerid, 9999999.0, MAPICON_GLOBAL);
            pTransporte[playerid][o][EntregaAtiva] = true;
            pTransporte[playerid][o][EmpresaTransID] = cUID;
            pTransporte[playerid][o][REntregas] = rrd;

            if(pTransportador[playerid][ComDupla] == true)
            {
                pTransporte[id][o][TransCheck] = CreateDynamicCP(pEmpresa[cUID][ePosicaoX], pEmpresa[cUID][ePosicaoY], pEmpresa[cUID][ePosicaoZ], 1.0, 0, 0, id, 100.0);
                pTransporte[id][o][TransIcone] = CreateDynamicMapIcon(pEmpresa[cUID][ePosicaoX], pEmpresa[cUID][ePosicaoY], pEmpresa[cUID][ePosicaoZ], 60, -1, 0, 0, id, 9999999.0, MAPICON_GLOBAL);
                pTransporte[id][o][EmpresaTransID] = cUID;
                pTransporte[id][o][REntregas] = rrd;
                pTransporte[id][o][EntregaAtiva] = true;
            }

            CapEntrega++;
            break;
        }
        if(CapEntrega >= 4) break;
    }
    if(CapEntrega <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nenhuma empresa foi informada, tente novamente!");
    else
    {
        format(Mensagem, sizeof(Mensagem), "| ENTREGA | Você tem {00BFFF}%d{FFFFFF} entrega(s) para fazer, siga o(s) ponto(s) no mapa", CapEntrega);
        SendClientMessage(playerid, -1, Mensagem);

        new Dialog[500];
        for(new i=0; i < 4; i++){
            strcatEx(Dialog, "{FFFFFF}Empresa {00BFFF}%d\t{FFFFFF}Entregas {FF4500}%d\n", pTransporte[playerid][i][EmpresaTransID], pTransporte[playerid][i][REntregas]);
        }
        if(pTransportador[playerid][ComDupla] == true) Dialog_Show(id, SeMfUCANSCA, DIALOG_STYLE_TABLIST, "{FF0000}Entregas", Dialog, "Fechar", "");
        Dialog_Show(playerid, SeMfUCANSCA, DIALOG_STYLE_TABLIST, "{FF0000}Entregas", Dialog, "Fechar", "");
    }
    return 1;
}