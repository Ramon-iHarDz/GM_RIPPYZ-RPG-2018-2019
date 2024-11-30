#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    for(new i=0; i < MAX_LOCALROUBO; i++)
    {
        RouboLocal[i][LocalAtivoRoubo] = true;
        RouboLocal[i][RouboVeiculoModelo] = VeiculoRoubo[random(sizeof(VeiculoRoubo))];
        
    }
    return 1;
} 

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid == pLadraoV[playerid][RouboCheck1] || checkpointid == pLadraoV[playerid][RouboCheck2] || checkpointid == pLadraoV[playerid][RouboCheck3])
    {
        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo"); 
        if(GetPlayerVehicleID(playerid) != pLadraoV[playerid][VeiculoRouboID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo o veículo roubado"); 

        new Mensagem[128];
        DestroyVehicleEx(pLadraoV[playerid][VeiculoRouboID]);
        DestroyDynamicMapIconEx(pLadraoV[playerid][RouboIcone1]);
        DestroyDynamicMapIconEx(pLadraoV[playerid][RouboIcone2]);
        DestroyDynamicMapIconEx(pLadraoV[playerid][RouboIcone3]);

        DestroyDynamicCPEx(pLadraoV[playerid][RouboCheck1]);
        DestroyDynamicCPEx(pLadraoV[playerid][RouboCheck2]);
        DestroyDynamicCPEx(pLadraoV[playerid][RouboCheck3]);

        pLadraoV[playerid][RoubandoVeiculoStatus] = 0;
        new Valora = random(6000-4000)+4000;
        format(Mensagem, sizeof(Mensagem), "| ASSALTO | Você ganhou $%s pelo roubo", DinheiroSeparar(Valora));
        SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
        Jogador[playerid][Dinheiro] += Valora;
        Jogador[playerid][Trabalhando] = false;
        return 1;
    }

    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    for(new i=0; i < MAX_LOCALROUBO; i++)
    {
        if(RouboLocal[i][LocalAtivoRoubo] == false) continue;
        if(pLadraoV[playerid][CheckRoubo][i] != checkpointid) continue;
        MostrarMenuRoubo(playerid);
        AtualizarLadrao(playerid, i);
        break;
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == RouboVeiculo[playerid][6])
    {
        OcultarMenuRoubo(playerid);
        if(pLadraoV[playerid][RoubandoVeiculoStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está roubando!");
        
        new Mensagem[128];
        if(TempoRouboVeiculo > gettime()){
            format(Mensagem, sizeof(Mensagem), "| ERRO | Ainda restam %s para o próximo roubo", ConverterSegundos(TempoRouboVeiculo));
            SendClientMessage(playerid, 0xFF4500FF, Mensagem);
            return 1;
        }

        TempoRouboVeiculo = gettime()+600;
        new id = GetPVarInt(playerid, "IDRoubo");

        MostrarTempoAssalto(playerid);
        // format(Mensagem, sizeof(Mensagem), "| NEWS | Um veículo de modelo %s foi roubado na região de %s por um(a) suspeito(a) %s[%d]", GetVehicleNameByModel(RouboLocal[id][RouboVeiculoModelo]), GetPlayerZone(playerid), PegarNick(playerid), playerid);
        // SendClientMessageToAll(0x7CFC00FF, Mensagem);

        format(Mensagem, sizeof(Mensagem), "| CENTRAL | O(A) Assaltante %s[%d] está efetuando um roubo de um veículo, vá até o local %s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
        for(new i=0; i < MAX_PLAYERS; i++)
        {
            if(!IsPlayerConnected(i)) continue;
            if(Jogador[i][Logado] == false) continue;
            if(!IsPolicia(i)) continue;
            if(pPolicia[i][PegouUniformePolicia] == false) continue;
            SendClientMessage(i, 0x4682B4FF, Mensagem);
        }

        Jogador[playerid][Trabalhando] = true;
        Jogador[playerid][Estrelas] += random(3-2)+2;
        pLadraoV[playerid][RoubandoVeiculoStatus] = 1;
        pLadraoV[playerid][TempoParaFugir] = gettime()+300;
        pLadraoV[playerid][VeiculoRouboID] = CreateVehicleEx(playerid, RouboLocal[id][RouboVeiculoModelo], CheckRoubos[id][vRPosX], CheckRoubos[id][vRPosY], CheckRoubos[id][vRPosZ], CheckRoubos[id][vRPosA], 4, 4, -1, 0);
        VeiculoServer[pLadraoV[playerid][VeiculoRouboID]][Tranca] = 1;
        SetVehicleHealth(pLadraoV[playerid][VeiculoRouboID], 5000);
        pLadraoV[playerid][IDTempRoubo] = SetTimerEx("VerificarLadrao", 1000, true, "d", playerid);
        SetPVarInt(playerid, "AntiAbordagem", gettime()+300);
        SendClientMessage(playerid, 0xFFFF00FF, "| ASSALTO | Você tem 5 minutos para escapar da polícia");
    }
    else if(playertextid == RouboVeiculo[playerid][7]) OcultarMenuRoubo(playerid);
    return 0;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pLadraoV[playerid][RoubandoVeiculoStatus] > 0) DestroyVehicleEx(pLadraoV[playerid][VeiculoRouboID]);
    if(pLadraoV[playerid][RoubandoVeiculoStatus] == 1)
    {
        new Mensagem[128];
        KillTimer(pLadraoV[playerid][IDTempRoubo]);
        format(Mensagem, sizeof(Mensagem), "| JUIZ | O(A) %s foi penalizado(a) por sair do servidor em uma ação", PegarNick(playerid));
        SendClientMessageToAll(0x1E90FFFF, Mensagem);
        CatalogarPrisao(playerid, 60, "Sair do servidor em uma ação", "Juiza Isabella", 0);
    }

    if(pLadraoV[playerid][RoubandoVeiculoStatus] == 2)
    {
        DestroyDynamicMapIconEx(pLadraoV[playerid][RouboIcone1]);
        DestroyDynamicMapIconEx(pLadraoV[playerid][RouboIcone2]);
        DestroyDynamicMapIconEx(pLadraoV[playerid][RouboIcone3]);

        DestroyDynamicCPEx(pLadraoV[playerid][RouboCheck1]);
        DestroyDynamicCPEx(pLadraoV[playerid][RouboCheck2]);
        DestroyDynamicCPEx(pLadraoV[playerid][RouboCheck3]);
    }

    new ALohaina[JogadorLadraoV];
    pLadraoV[playerid] = ALohaina;
    return 1;
}

hook OnPlayerPreso(playerid, pm)
{
    if(pLadraoV[playerid][RoubandoVeiculoStatus] == 1)
    {
        KillTimer(pLadraoV[playerid][IDTempRoubo]);
        OcultarMenuRoubo(playerid);
    }
    if(pLadraoV[playerid][RoubandoVeiculoStatus] == 2)
    {
        DestroyDynamicMapIconEx(pLadraoV[playerid][RouboIcone1]);
        DestroyDynamicMapIconEx(pLadraoV[playerid][RouboIcone2]);
        DestroyDynamicMapIconEx(pLadraoV[playerid][RouboIcone3]);

        DestroyDynamicCPEx(pLadraoV[playerid][RouboCheck1]);
        DestroyDynamicCPEx(pLadraoV[playerid][RouboCheck2]);
        DestroyDynamicCPEx(pLadraoV[playerid][RouboCheck3]);
        pLadraoV[playerid][RoubandoVeiculoStatus] = 0;
    }
    if(pLadraoV[playerid][RoubandoVeiculoStatus] > 0)
    {
        DestroyVehicleEx(pLadraoV[playerid][VeiculoRouboID]);
        Jogador[playerid][Trabalhando] = false;
        pLadraoV[playerid][RoubandoVeiculoStatus] = 0;
    }
    return 1;
}

function VerificarLadrao(playerid)
{
    new Mensagem[128];

    // Atualizar
    if(pLadraoV[playerid][TempoParaFugir] > gettime()){
        format(Mensagem, sizeof(Mensagem), "Tempo:_%s", ConverterSegundos(pLadraoV[playerid][TempoParaFugir]));
        PlayerTextDrawSetString(playerid, TempoAssalto[playerid][1], Mensagem);
        return 1;
    }

    SetPVarInt(playerid, "AntiAbordagem", gettime()+120);

    OcultarTempoAssalto(playerid);
    KillTimer(pLadraoV[playerid][IDTempRoubo]);
    pLadraoV[playerid][RoubandoVeiculoStatus] = 2;

    pLadraoV[playerid][RouboIcone1] = CreateDynamicMapIcon(-1570.0210,98.2303,3.5547, 30, -1, 0, 0, playerid, 9999999.9, MAPICON_GLOBAL, -1);
    pLadraoV[playerid][RouboIcone2] = CreateDynamicMapIcon(2792.2139,-2494.5271,13.6449, 30, -1, 0, 0, playerid, 9999999.9, MAPICON_GLOBAL, -1);
    pLadraoV[playerid][RouboIcone3] = CreateDynamicMapIcon(940.4056,2068.4041,10.8203, 30, -1, 0, 0, playerid, 9999999.9, MAPICON_GLOBAL, -1);

    pLadraoV[playerid][RouboCheck1] = CreateDynamicCP(-1570.0210,98.2303,3.5547, 2.0, 0, 0, playerid, 120.0, -1);
    pLadraoV[playerid][RouboCheck2] = CreateDynamicCP(2792.2139,-2494.5271,13.6449, 2.0, 0, 0, playerid, 120.0, -1);
    pLadraoV[playerid][RouboCheck3] = CreateDynamicCP(940.4056,2068.4041,10.8203, 2.0, 0, 0, playerid, 120.0, -1);

    format(Mensagem, sizeof(Mensagem), "| ASSALTO | Você escapou da polícia, vá até os pontos marcados no mapa!");
    SendClientMessage(playerid, 0xFFFF00FF, Mensagem);

    // format(Mensagem, sizeof(Mensagem), "| NEWS | O(A) Ladrão %s que efetuou um roubo de um veículo modelo %s escapou das autoridades!", PegarNick(playerid), GetVehicleNameByModel(GetVehicleModel(pLadraoV[playerid][VeiculoRouboID])));
    // SendClientMessageToAll(0x7CFC00FF, Mensagem);
    return 1;
}