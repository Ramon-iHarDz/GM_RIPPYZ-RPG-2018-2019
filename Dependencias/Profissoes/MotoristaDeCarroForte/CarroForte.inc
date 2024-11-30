#include <YSI_Coding\y_hooks>

enum JogadorCF
{
    EntregaCF,
    CheckCF,
    MapCF,
    CaixaCFID,
    UsandoCFID,
    Text3D:TextoCF
};

new pCF[MAX_PLAYERS][JogadorCF];

hook OnGameModeInit()
{
    for(new i=0; i < sizeof(CFSpawn); i++)
    {
        CarroF[i] = CreateVehicleEx(-1, 428, CFSpawn[i][FSpawnX], CFSpawn[i][FSpawnY], CFSpawn[i][FSpawnZ], CFSpawn[i][FSpawnA], 6, 6, 360, 0);
        VeiculoServer[CarroF[i]][AntiFurar] = true;
        VeiculoServer[CarroF[i]][VeiculoRegenerar] = true;
        VeiculoServer[CarroF[i]][VidaMaxima] = 15000; 
        format(VeiculoServer[CarroF[i]][LocalVerificacao], 90, "CarroForteVeh"); 
        SetVehicleHealth(CarroF[i], VeiculoServer[CarroF[i]][VidaMaxima]);
    }

    CreateDynamicPickup(1239, 1, 1087.0491,1895.0609,10.8203, 0, 0, -1, 120.0, -1);
    CreateDynamic3DTextLabel("Prosegur{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para pegar", 0xFFA500FF, 1087.0491,1895.0609,10.8203, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);

    return 1;
}

function CarroForteVeh(playerid, vehicleid)
{
    if(Jogador[playerid][Admin] > 2) return true;
    if(strcmp(Jogador[playerid][Profissao], "Motorista de Carro Forte")){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é Motorista de Carro Forte");
        return false;
    }
    if(Jogador[playerid][Estrelas] > 0){
        if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            return false;
        }
    }

    if(pCF[playerid][EntregaCF] == 4 || 
    pCF[playerid][EntregaCF] == 5)
    {
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode entrar no carro forte");
        return false;
    }

    if(VerificarEntregaCF(playerid, vehicleid))
    {
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode pegar esse carro forte pois já está sendo utilizado");
        return false;
    }
    return true;
}

stock VerificarCarroForte(vehicleid)
{
    for(new i=0; i < sizeof(CFSpawn); i++){
        if(CarroF[i] != vehicleid) continue;
        return true;
    }
    return false;
}

stock VerificarEntregaCF(playerid, vehicleid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(playerid == i) continue;
        if(Jogador[i][Logado] == false) continue;
        if(pCF[i][EntregaCF] < 1) continue;
        if(pCF[i][UsandoCFID] == vehicleid) return true;
    }
    return false;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamicCPEx(pCF[playerid][CheckCF]);
    DestroyDynamicMapIconEx(pCF[playerid][MapCF]); 
    DestroyDynamic3DTextLabelEx(pCF[playerid][TextoCF]);

    new asdsada[JogadorCF];
    pCF[playerid] = asdsada;
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_ONFOOT)
    {
        if(GetPVarInt(playerid, "LOASIDKsdsjcSAD") == 1) return 1;
        if(Jogador[playerid][uVeiculo] != pCF[playerid][UsandoCFID]) return 1;

        if(pCF[playerid][EntregaCF] == 3)
        {
            new id = pCF[playerid][CaixaCFID];
            if(!IsPlayerInRangeOfPoint(playerid, 50.0, pCaixa[id][PosicaoX], pCaixa[id][PosicaoY], pCaixa[id][PosicaoZ])) return 1;
            pCF[playerid][EntregaCF] = 4;
            SetPVarInt(playerid, "LOASIDKsdsjcSAD", 1);
            pCF[playerid][TextoCF] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'H'{FFFFFF} para pegar", -1, 0.0000, -4.0999, -0.9000, 15.0, INVALID_PLAYER_ID, pCF[playerid][UsandoCFID], 0, 0, 0, playerid, 16.0, -1);
        }
    }
    else if(newstate == PLAYER_STATE_DRIVER)
    {
        if(GetPVarInt(playerid, "LOASIDKsdsjcSAD") == 0) return 1;
        if(GetPlayerVehicleID(playerid) == pCF[playerid][UsandoCFID]) return 1;
        DestroyDynamic3DTextLabelEx(pCF[playerid][TextoCF]);
        SetPVarInt(playerid, "LOASIDKsdsjcSAD", 0);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_CTRL_BACK)
    {
        if(AtrasVeiculo(playerid, pCF[playerid][UsandoCFID], 2.0))
        {
            if(pCF[playerid][EntregaCF] < 1) return 1;
            if(pCF[playerid][EntregaCF] == 2)
            {
                pCF[playerid][EntregaCF] = 3;
                RemovePlayerAttachedObject(playerid, 9);
                DestroyDynamic3DTextLabelEx(pCF[playerid][TextoCF]);

                new id = -1,
                    i;
                while(id == -1)
                {
                    i = random(MAX_CAIXAS);
                    if(pCaixa[i][Conectado] == false) continue;
                    id = i;
                }
                pCF[playerid][CaixaCFID] = id;

                new Mensagem[128];
                format(Mensagem, sizeof(Mensagem), "| CARRO FORTE | Você precisa ir até {FFA500}%s{FFFFFF} para abastecer seu carro forte", AreaNome(pCaixa[id][PosicaoX], pCaixa[id][PosicaoY], pCaixa[id][PosicaoZ]));
                SendClientMessage(playerid, -1, Mensagem);

                pCF[playerid][CheckCF] = CreateDynamicCP(pCaixa[id][PosicaoX], pCaixa[id][PosicaoY], pCaixa[id][PosicaoZ], 2.0, 0, 0, playerid, 90.0, -1);
                pCF[playerid][MapCF] = CreateDynamicMapIcon(pCaixa[id][PosicaoX], pCaixa[id][PosicaoY], pCaixa[id][PosicaoZ], 36, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
            }

            else if(pCF[playerid][EntregaCF] == 4)
            {
                pCF[playerid][EntregaCF] = 5;
                SetPlayerAttachedObject(playerid, 9, 11745, 1, 0.0729, -0.1270, -0.0079, 77.5999, 159.6999, 29.3999, 0.8590, 0.7560, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); 
                DestroyDynamic3DTextLabelEx(pCF[playerid][TextoCF]);
                SetPVarInt(playerid, "LOASIDKsdsjcSAD", 0);
            }
        }
    }
    else if(newkeys == KEY_YES)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1087.0491,1895.0609,10.8203))
        {
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Motorista de Carro Forte")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pCF[playerid][EntregaCF] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode fazer esse processo agora");
        
            pCF[playerid][EntregaCF] = 2;
            SetPlayerAttachedObject(playerid, 9, 11745, 1, 0.0729, -0.1270, -0.0079, 77.5999, 159.6999, 29.3999, 0.8590, 0.7560, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); 
            DestroyDynamicMapIconEx(pCF[playerid][MapCF]);
            pCF[playerid][TextoCF] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'H'{FFFFFF} para colocar", -1, 0.0000, -4.0999, -0.9000, 15.0, INVALID_PLAYER_ID, pCF[playerid][UsandoCFID], 0, 0, 0, playerid, 16.0, -1);
        }
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pCF[playerid][CheckCF]) return 1;
    if(pCF[playerid][EntregaCF] == 5 || pCF[playerid][EntregaCF] == 6 || pCF[playerid][EntregaCF] == 7)
    {
        switch(pCF[playerid][EntregaCF])
        {
            case 5:
            {
                TogglePlayerControllable(playerid, 0);
                ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
                CriarProgresso(playerid, "Abastecendo Caixa", "CarroForteEtap1", 200);
            }
            case 6:
            {
                if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
                if(!VerificarCarroForte(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no veículo do carro forte");
                TogglePlayerControllable(playerid, 0);
                CriarProgresso(playerid, "Recolhendo Dinheiro Bancário", "CarroForteEtap2", 200);
            }
            case 7:
            {
                if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
                if(!VerificarCarroForte(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no veículo do carro forte");
                TogglePlayerControllable(playerid, 0);
                CriarProgresso(playerid, "Descarregando Carro Forte", "CarroForteEtap3", 200);
            }
        }
        DestroyDynamicCPEx(pCF[playerid][CheckCF]);
        DestroyDynamicMapIconEx(pCF[playerid][MapCF]); 
    }
    return 1;
}

function CarroForteEtap1(playerid)
{
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid, 1);
    RemovePlayerAttachedObject(playerid, 9);
    pCF[playerid][EntregaCF] = 6;
    
    enum Alojp
    {
        Float:CiX,
        Float:CiY,
        Float:CiZ
    };

    new DogHosp[][Alojp] =
    {
        {1752.6537, -1677.9193, 13.3828}, // LS
        {-2660.4138, 375.7323, 4.1390}, // SF
        {2370.0889, 2470.1936, 10.6719} // LV
    };

    new id, Float:distance = 99999.9;
    for(new i, j = sizeof(DogHosp), Float:tmp_distance; i < j; i++)
    {
        tmp_distance = GetPlayerDistanceFromPoint(playerid, DogHosp[i][CiX], DogHosp[i][CiY], DogHosp[i][CiZ]+1);
        if(tmp_distance < distance){
            distance = tmp_distance;
            id = i;
        }
    }

    pCF[playerid][CheckCF] = CreateDynamicCP(DogHosp[id][CiX], DogHosp[id][CiY], DogHosp[id][CiZ], 2.0, 0, 0, playerid, 90.0, -1);
    pCF[playerid][MapCF] = CreateDynamicMapIcon(DogHosp[id][CiX], DogHosp[id][CiY], DogHosp[id][CiZ], 52, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    SendClientMessage(playerid, 0xFFFF00FF, "| CARRO FORTE | Você precisa ir até o banco para recolher dinheiro");
    return 1;
}

function CarroForteEtap2(playerid)
{
    TogglePlayerControllable(playerid, 1);
    pCF[playerid][EntregaCF] = 7;
    pCF[playerid][CheckCF] = CreateDynamicCP(1087.1039, 1889.3926, 10.8203, 2.0, 0, 0, playerid, 90.0, -1);
    pCF[playerid][MapCF] = CreateDynamicMapIcon(1087.1039, 1889.3926, 10.8203, 36, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);

    SendClientMessage(playerid, 0xFFFF00FF, "| CARRO FORTE | Você precisa ir até a Prosegur para receber seu pagamento");
    return 1;
}

function CarroForteEtap3(playerid)
{
    TogglePlayerControllable(playerid, 1);
    pCF[playerid][EntregaCF] = 0;
    pCF[playerid][UsandoCFID] = 0;
    Jogador[playerid][Trabalhando] = false;

    new Mensagem[128],
        alsdo = random(6000-5000)+5000;
    Jogador[playerid][Dinheiro] += alsdo;
    format(Mensagem, sizeof(Mensagem), "| CARRO FORTE | Você recebeu {32CD32}$%s{FFFFFF} pelos abastecimentos de caixas e bancos", DinheiroSeparar(alsdo));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

CMD:carregar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Motorista de Carro Forte")) return 0;
    if(pCF[playerid][EntregaCF] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já iniciou um serviço");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(!VerificarCarroForte(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em um carro forte");
    if(VerificarEntregaCF(playerid, GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Outro(a) jogador(a) já está usando esse carro forte");

    pCF[playerid][EntregaCF] = 1;
    Jogador[playerid][Trabalhando] = true;
    pCF[playerid][UsandoCFID] = GetPlayerVehicleID(playerid);
 
    MarcarPosicao(playerid, 1087.0491,1895.0609,10.8203);
    pCF[playerid][MapCF] = CreateDynamicMapIcon(1087.0491,1895.0609,10.8203, 52, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    SendClientMessage(playerid, 0xFFFF00FF, "| CARRO FORTE | Você precisa ir até a Prosegur para abastecer seu veículo");
    return 1;
}