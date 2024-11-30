#include <YSI_Coding\y_hooks>

enum SpawnUberEats
{
    Float:eSpawnX,
    Float:eSpawnY,
    Float:eSpawnZ,
    Float:eSpawnA
};

new uESpawn[][SpawnUberEats] = 
{
    {782.3651,-1633.6926,12.9571,271.3198}, 
    {782.2390,-1630.2201,12.9522,271.7751},
    {782.9084,-1626.7345,12.9536,270.7129},
    {781.7927,-1623.0914,12.9523,267.3715},
    {782.2482,-1619.3423,12.9621,275.4384},
    {782.0939,-1616.0765,12.9575,269.3120},
    {782.7384,-1612.5045,12.9489,274.7471},
    {782.0982,-1608.6735,12.9524,271.0050},
    {782.4081,-1605.2469,12.9524,269.5962},
    {782.2899,-1601.6819,12.9509,270.3136} 
};

hook OnGameModeInit()
{
    CreateDynamicPickup(1239, 1, 781.5804,-1637.5038,12.9429, 0, 0, -1, 30.0);
    CreateDynamic3DTextLabel("{00BFFF}Uber Eats\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, 781.5804,-1637.5038,12.9429, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "AnimacaoBauUber") == 1) KillTimer(GetPVarInt(playerid, "TimerBauUber"));
    DestroyDynamic3DTextLabelEx(mUber[playerid][TextoUbb]);
    DestroyDynamicObjectEx(mUber[playerid][BauID]);
    if(mUber[playerid][UberMoto] == true) DestroyVehicleEx(mUber[playerid][UberVid]);   
    if(mUber[playerid][ComEntrega] == true) RemovePlayerAttachedObject(playerid, 9);

    // Limpar Entrega ( Caso Tenha )
    new LimpezaH[UberEntregas];
    for(new i=0; i < 4; i++){
        DestroyDynamicMapIconEx(UberEntrega[playerid][i][MapaAtiva]);
        DestroyDynamicCPEx(UberEntrega[playerid][i][CheckAtiva]);
        UberEntrega[playerid][i] = LimpezaH;
    }

    // Limpeza de Stings
    new LimpezaaH[UberEatsJogador];
    mUber[playerid] = LimpezaaH;
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(strcmp(Jogador[playerid][Profissao], "Uber Eats")) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0) return 1;
    if(mUber[playerid][BikeUber] == true) return 1;

    if(newstate != PLAYER_STATE_ONFOOT)
    {
        if(mUber[playerid][ComEntrega] == true)
        {
            RemovePlayerAttachedObject(playerid, 9);
            mUber[playerid][ComEntrega] = false;
        } 

        if(mUber[playerid][UberMoto] == true && mUber[playerid][TextoVis] == true)
        {
            DestroyDynamic3DTextLabelEx(mUber[playerid][TextoUbb]);
            mUber[playerid][TextoVis] = false;
        }
    }

    else if(newstate == PLAYER_STATE_ONFOOT && Jogador[playerid][uVeiculo] == mUber[playerid][UberVid])
    {
        if(mUber[playerid][UberMoto] == true && mUber[playerid][TextoVis] == false)
        {
            new bool:PertoG = false,
                id;
            for(new i=0; i < 4; i++)
            {
                if(UberEntrega[playerid][i][EntregaAtiva] == false) continue;
                if(i == 0) break;
                id = UberEntrega[playerid][i][CasaUUber];
                if(!IsPlayerInRangeOfPoint(playerid, 40.0, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ])) continue;
                mUber[playerid][TextoVis] = true;
                mUber[playerid][TextoUbb] = CreateDynamic3DTextLabel("Aperte {CCCCCC}H{FFFFFF} para pegar", -1, 0.0000, -1.2999, 0.0000, 20.0, INVALID_PLAYER_ID, mUber[playerid][UberVid], 0, 0, 0, playerid, 20.0);
                PertoG = true;
                break;
            }
            if(PertoG == false) return 1;
        }    
    }
    return 1; 
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, 781.5804,-1637.5038,12.9429)) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa sair do veículo");
        if(strcmp(Jogador[playerid][Profissao], "Uber Eats")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        if(mUber[playerid][DelayAlg] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco");
        if(EntregandoUber(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem entregas para finalizar");

        if(mUber[playerid][UberMoto] == false) return Dialog_Show(playerid, SelecionarUberVeh, DIALOG_STYLE_TABLIST, "{FF0000}Selecionar Veículo", "{FF4500}1. {FFFFFF}Bike\n{FF4500}2. {FFFFFF}Moto", "Selecionar", "Fechar");
        
        Jogador[playerid][Trabalhando] = false;
        mUber[playerid][DelayAlg] = gettime()+15;
        mUber[playerid][UberMoto] = false;
        
        DestroyVehicleEx(mUber[playerid][UberVid]);
        VerificarMarcacao(playerid);
        if(mUber[playerid][BikeUber] == true)
        {
            RemovePlayerAttachedObject(playerid, 9);
            SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você devolveu sua bike");
        }
        else
        {
            DestroyDynamicObjectEx(mUber[playerid][BauID]);
            SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você devolveu sua moto");
        } 
        mUber[playerid][BikeUber] = false;
    }

    else if(newkeys == KEY_CTRL_BACK)
    {
        if(strcmp(Jogador[playerid][Profissao], "Uber Eats")) return 1;
        if(mUber[playerid][BikeUber] == true) return 1;

        if(AtrasVeiculo(playerid, mUber[playerid][UberVid], 2.0))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(mUber[playerid][ComEntrega] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem um saco na mão, entregue-o");
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            new bool:PertoG = false,
                id;
            for(new i=0; i < 4; i++)
            {
                if(i == 0) continue;
                if(UberEntrega[playerid][i][EntregaAtiva] == false) continue;
                id = UberEntrega[playerid][i][CasaUUber];
                if(!IsPlayerInRangeOfPoint(playerid, 25.0, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ])) continue;
                PertoG = true;
                break;
            }
            if(PertoG == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de uma entrega");
            mUber[playerid][ComEntrega] = true;
            SetPlayerAttachedObject(playerid, 9, 2663, 5, 0.2710, 0.0070, 0.0260, -18.4999, -97.5998, 9.4000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
            SendClientMessage(playerid, -1, "| UBER | Você pegou encomenda, leve-a até o solicitante");
        }
    }
    return 1;
} 

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(mUber[playerid][UberMoto] == false) return 1; 
    for(new i=0; i < 4; i++)
    {
        if(UberEntrega[playerid][i][EntregaAtiva] == false) continue;
        if(UberEntrega[playerid][i][CheckAtiva] != checkpointid) continue;
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa sair do veículo");
        if(i == 0)
        {
            DestroyDynamicMapIconEx(UberEntrega[playerid][i][MapaAtiva]);
            DestroyDynamicCPEx(UberEntrega[playerid][i][CheckAtiva]); 
            mUber[playerid][DinheiroUberTotal] = 0;
            UberEntrega[playerid][i][CasaUUber] = 0;
            UberEntrega[playerid][i][EntregaAtiva] = false;
            UberEntregaCasa(playerid);
            return 1;
        }

        if(mUber[playerid][ComEntrega] == false && mUber[playerid][BikeUber] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa pegar a encomenda atrás da moto no baú");
        
        new Float:ALKSD[3];
        GetPlayerPos(playerid, ALKSD[0], ALKSD[1], ALKSD[2]);
        if(!IsVehicleInRangeOfPoint(mUber[playerid][UberVid], 40.0, ALKSD[0], ALKSD[1], ALKSD[2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo está longe de você");

        mUber[playerid][ComEntrega] = false;
        UberEntrega[playerid][i][CasaUUber] = 0; 

        DestroyDynamicMapIconEx(UberEntrega[playerid][i][MapaAtiva]);
        DestroyDynamicCPEx(UberEntrega[playerid][i][CheckAtiva]); 
        UberEntrega[playerid][i][EntregaAtiva] = false;

        if(mUber[playerid][BikeUber] == true)
        {
            SetPVarInt(playerid, "AnimacaoBauUber", 1);
            TogglePlayerControllable(playerid, 0);
            ClearAnimations(playerid);
            ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
            RemovePlayerAttachedObject(playerid, 9);   
            SetPlayerAttachedObject(playerid, 9, 19572, 5, 0.0310, 0.0671, 0.0960, -61.9999, 116.2000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); 
            new PocPoc = 1000*(random(4-3)+3);
            new id = SetTimerEx("EnviarEntregasU", PocPoc, false, "d", playerid);
            SetPVarInt(playerid, "TimerBauUber", id);
        }
        else
        {
            RemovePlayerAttachedObject(playerid, 9); 
            EnviarEntregasU(playerid);
        }
        break;
    }
    return 1;
}

function EnviarEntregasU(playerid)
{
    if(mUber[playerid][BikeUber] == true)
    {
        TogglePlayerControllable(playerid, 1);
        SetPVarInt(playerid, "AnimacaoBauUber", 0);
        ClearAnimations(playerid);
        RemovePlayerAttachedObject(playerid, 9);   
        SetPlayerAttachedObject(playerid, 9, 19572, 1, -0.0580, -0.2349, -0.0169, 0.0000, 87.6000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);   
    }

    new Mensagem[120],
        EntregaVU;
    
    EntregaVU = random(500-400)+400;
    format(Mensagem, sizeof(Mensagem), "| ENTREGA | Você entregou {00BFFF}%d{FFFFFF} pedidos e ganhou {32CD32}$%s", random(5-3)+3, DinheiroSeparar(EntregaVU));
    SendClientMessage(playerid, -1, Mensagem);
    Jogador[playerid][Dinheiro] += EntregaVU; 
    mUber[playerid][DinheiroUberTotal] += EntregaVU;

    if(!EntregandoUber(playerid))
    {
        EntregaVU = random(100-90)+90;
        Jogador[playerid][Dinheiro] += EntregaVU; 
        format(Mensagem, sizeof(Mensagem), "| ENTREGA | Você entregou os {00BFFF}%d pedidos{FFFFFF} e ganhou {32CD32}$%s{FFFFFF} + {32CD32}$%s de gorjeta", mUber[playerid][CappaMoney], DinheiroSeparar(mUber[playerid][DinheiroUberTotal]), DinheiroSeparar(EntregaVU));
        SendClientMessage(playerid, -1, Mensagem);   
        ResetarUber(playerid);
    }
    return 1;
}

CMD:entregas(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Uber Eats")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(mUber[playerid][UberMoto] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem um veículo de uber eats alugado");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPlayerVehicleID(playerid) != mUber[playerid][UberVid]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo do uber eats");
    if(EntregandoUber(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem entregas");
    if(!IsPlayerInRangeOfPoint(playerid, 120.0, 786.7988,-1614.0635,13.3828)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em sua HQ");

    new eid,
        bool:HaEmpresa = false, 
        Mensagem[128];
    
    for(new i=0; i < 99999; i++)
    {
        eid = random(MAX_EMPRESAS);
        if(pEmpresa[eid][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 1350.0, pEmpresa[eid][ePosicaoX], pEmpresa[eid][ePosicaoY], pEmpresa[eid][ePosicaoZ])) continue;
        if(!VerificarInterior(pEmpresa[eid][eInterior])) continue;
        UberEntrega[playerid][0][CheckAtiva] = CreateDynamicCP(pEmpresa[eid][ePosicaoX], pEmpresa[eid][ePosicaoY], pEmpresa[eid][ePosicaoZ], 1.0, 0, 0, playerid, 100.0);
        UberEntrega[playerid][0][MapaAtiva] = CreateDynamicMapIcon(pEmpresa[eid][ePosicaoX], pEmpresa[eid][ePosicaoY], pEmpresa[eid][ePosicaoZ], 62, -1, 0, 0, playerid, 9999999.0, MAPICON_GLOBAL);
        UberEntrega[playerid][0][EntregaAtiva] = true;
        format(Mensagem, sizeof(Mensagem), "| CHAMADO | Você foi chamado(a) pela empresa {FF8C00}%d{FFFFFF}, siga o mapa", eid);
        SendClientMessage(playerid, 0xFFFFFFFF, Mensagem);
        HaEmpresa = true;
        break;
    }  
    if(HaEmpresa == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nenhuma empresa chamou você, tente novamente");
    return 1;
}

Dialog:SelecionarUberVeh(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new s2id22m = random(sizeof(uESpawn));

    switch(listitem)
    {
        case 0:
        {
            mUber[playerid][UberVid] = CreateVehicleEx(playerid, 510, uESpawn[s2id22m][eSpawnX], uESpawn[s2id22m][eSpawnY], uESpawn[s2id22m][eSpawnZ], uESpawn[s2id22m][eSpawnA], random(999), 116, -1, 0);
            mUber[playerid][BikeUber] = true;
            SetPlayerAttachedObject(playerid, 9, 19572, 1, -0.0580, -0.2349, -0.0169, 0.0000, 87.6000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
            SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Bike alugada foi marcada no mapa");
        }
        case 1:
        {
            if(Jogador[playerid][CarteiraA] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar uma moto ( Habilitação: A )");
            mUber[playerid][UberVid] = CreateVehicleEx(playerid, 461, uESpawn[s2id22m][eSpawnX], uESpawn[s2id22m][eSpawnY], uESpawn[s2id22m][eSpawnZ], uESpawn[s2id22m][eSpawnA], 116, 116, -1, 0);
            mUber[playerid][BauID] = CreateDynamicObject(19572, 2036.0747, 1234.5502, 10.9123, 0.0000, 0.0000, 81.2026, 0, 0, -1, 120.0, 120.0);
            SetDynamicObjectMaterial(mUber[playerid][BauID], 0, 2765, "cj_cb_sign", "CJ_PIZZA_MENU2", 0x00000000);
            AttachDynamicObjectToVehicle(mUber[playerid][BauID], mUber[playerid][UberVid], 0.0000, -0.8999, 0.5000, 0.0000, 0.0000, 0.0000);
            SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Moto alugada foi marcada no mapa");
            
        }
    }

    mUber[playerid][UberMoto] = true; 
    Jogador[playerid][Trabalhando] = true;
    VeiculoServer[mUber[playerid][UberVid]][Tranca] = 1;
    MarcarPosicao(playerid, uESpawn[s2id22m][eSpawnX], uESpawn[s2id22m][eSpawnY], uESpawn[s2id22m][eSpawnZ]);
    mUber[playerid][DelayAlg] = gettime()+15;
    return 1;
}