#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    if(pUber[playerid][UberStatus] > 0)
    {
        FinalizarUber(playerid);
        new id = GetPVarInt(playerid, "uBERR");
        Jogador[playerid][Dinheiro] += pUber[playerid][UberValor];
        Jogador[id][Dinheiro] -= pUber[playerid][UberValor];
    }
    else if(pUber[playerid][UberStatusChamada] > 0)
    {
        new id = GetPVarInt(playerid, "uBERR");
        FinalizarUber(playerid);
        Jogador[id][Dinheiro] += pUber[id][UberValor];
        Jogador[playerid][Dinheiro] -= pUber[id][UberValor];
    }

    new dasdada[UberJogador];
    pUber[playerid] = dasdada;
    return 1;
}

CMD:iniciaruber(playerid)
{
    if(pUber[playerid][UberStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está atendendo um(a) passageiro(a)");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPVarInt(playerid, "KDLAKSLDAS") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco");
    SetPVarInt(playerid, "KDLAKSLDAS", gettime()+10);

    new Mensagem[128];
    if(pUber[playerid][EmServico] == false)
    {
        new bool:dasda;
        for(new i=0; i < MAX_SLOT_VEH; i++)
        {
            if(pVeiculo[playerid][i][MeuVeiculoModelo] < 1) continue;
            if(pVeiculo[playerid][i][MeuVeiculoID] != GetPlayerVehicleID(playerid)) continue;
            if(!IsApenasCarro(pVeiculo[playerid][i][MeuVeiculoModelo])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode trabalhar com esse veículo");

            pUber[playerid][UberSlot] = i;
            pUber[playerid][EmServico] = true;
            pVeiculo[playerid][i][VeiculoUber] = true;
            dasda = true;
            
            format(Mensagem, sizeof(Mensagem), "| UBER | Você agora está em serviço com o veículo {e2b960}%s", GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
            SendClientMessage(playerid, -1, Mensagem);
            break;
        }
        if(dasda == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo pessoal");
        return 1;
    }
    pUber[playerid][EmServico] = false;
    pVeiculo[playerid][pUber[playerid][UberSlot]][VeiculoUber] = false;
    SendClientMessage(playerid, 0xFFFF00FF, "| UBER | Você saiu de serviço");
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate != PLAYER_STATE_ONFOOT) return 1;

    if(pUber[playerid][UberStatus] == 3){
        new id = GetPVarInt(playerid, "uBERR");
        pUber[playerid][UberStatus] = 4;
        pUber[id][UberStatusChamada] = 4;
    }
    else if(pUber[playerid][UberStatusChamada] == 3){
        new id = GetPVarInt(playerid, "uBERR");
        pUber[id][UberStatus] = 4;
        pUber[playerid][UberStatusChamada] = 4;  
    }
    return 1;
}

function AtualizarUber(playerid, id)
{
    if(pUber[playerid][UberStatus] == 2 || pUber[playerid][UberStatus] == 3 || pUber[playerid][UberStatus] == 4)
    {
        if(pUber[playerid][UberStatus] == 2)
        {
            if(GetPlayerState(id) == PLAYER_STATE_PASSENGER && GetPlayerVehicleID(id) == pVeiculo[playerid][pUber[playerid][UberSlot]][MeuVeiculoID])
            {
                MostrarUber(id);
                MostrarUber(playerid);

                PlayerTextDrawSetString(id, UberTxd[id][3], ConverterTexto(PegarNick(playerid)));
                PlayerTextDrawSetString(playerid, UberTxd[playerid][3], ConverterTexto(PegarNick(id)));

                pUber[id][UberStatusChamada] = 3;
                pUber[playerid][UberStatus] = 3;
            }
        } 
        else if(pUber[playerid][UberStatus] == 3)
        {
            new Float:MinhaPosAtual[3];
            GetPlayerPos(playerid, MinhaPosAtual[0], MinhaPosAtual[1], MinhaPosAtual[2]);
            new distancia = GetDistanceBetweenPoints(MinhaPosAtual[0], MinhaPosAtual[1], MinhaPosAtual[2], pUber[playerid][UberApos][0], pUber[playerid][UberApos][1], pUber[playerid][UberApos][2]);
            if(distancia >= 14.0)
            {
                new Mensagem[75];
                if(Jogador[id][Dinheiro] < pUber[playerid][UberValor])
                {
                    KillTimer(pUber[playerid][UberTimer]);
                    OcultarUber(id);
                    OcultarUber(playerid);
                    
                    pUber[playerid][UberStatus] = 0;
                    pUber[id][UberStatusChamada] = 0;
                    Jogador[playerid][Dinheiro] += Jogador[id][Dinheiro];
                    Jogador[id][Dinheiro] = 0;
                    
                    format(Mensagem, sizeof(Mensagem), "| UBER | Seu passageiro ficou sem dinheiro. Você recebeu $%s", DinheiroSeparar(pUber[playerid][UberValor]));
                    SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
                    SendClientMessage(id, 0xFFFF00FF, "| UBER | Seu dinheiro acabou e sua corrida foi cancelada");
                    GetPlayerPos(id, MinhaPosAtual[0], MinhaPosAtual[1], MinhaPosAtual[2]);
                    SetPlayerPos(id, MinhaPosAtual[0], MinhaPosAtual[1], MinhaPosAtual[2]+2);
                    return 1;
                }

                pUber[playerid][UberValor] += 5;
                format(Mensagem, sizeof(Mensagem), "$%s", DinheiroSeparar(pUber[playerid][UberValor]));
                PlayerTextDrawSetString(playerid, UberTxd[playerid][4], Mensagem);
                PlayerTextDrawSetString(id, UberTxd[id][4], Mensagem);
                
                pUber[playerid][UberApos][0] = MinhaPosAtual[0];
                pUber[playerid][UberApos][1] = MinhaPosAtual[1];
                pUber[playerid][UberApos][2] = MinhaPosAtual[2];   
            }
        }
        else if(pUber[playerid][UberStatus] == 4)
        {
            new Mensagem[90];
            KillTimer(pUber[playerid][UberTimer]);
            OcultarUber(id);
            OcultarUber(playerid);

            new prct = (pUber[playerid][UberValor] * 40) / 100;
            new fkedasda = prct+pUber[playerid][UberValor];

            pUber[playerid][UberStatus] = 0;
            pUber[id][UberStatusChamada] = 0;
            Jogador[playerid][Dinheiro] += fkedasda;
            Jogador[id][Dinheiro] -= pUber[playerid][UberValor];


            format(Mensagem, sizeof(Mensagem), "| UBER | Você deixou seu passageiro no destino e recebeu {32CD32}$%s", DinheiroSeparar(fkedasda));
            SendClientMessage(playerid, -1, Mensagem);

            format(Mensagem, sizeof(Mensagem), "| UBER | Você chegou em seu destino e pagou {32CD32}$%s", DinheiroSeparar(pUber[playerid][UberValor]));
            SendClientMessage(id, -1, Mensagem);
        }
        return 1;
    }
    
    DestroyDynamicMapIconEx(pUber[id][MapIc]);
    DestroyDynamicMapIconEx(pUber[playerid][MapIc]);
    new Float:Hoob[6];
    GetPlayerPos(id, Hoob[0], Hoob[1], Hoob[2]);
    GetPlayerPos(playerid, Hoob[3], Hoob[4], Hoob[5]);
    if(!IsPlayerInRangeOfPoint(playerid, 20.0, Hoob[0], Hoob[1], Hoob[2]))
    {
        pUber[playerid][MapIc] = CreateDynamicMapIcon(Hoob[0], Hoob[1], Hoob[2], 61, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1); 
        pUber[id][MapIc] = CreateDynamicMapIcon(Hoob[3], Hoob[4], Hoob[5], 55, -1, 0, 0, id, 999999.9, MAPICON_GLOBAL, -1); 
        return 1;
    }
    
    SendClientMessage(playerid, 0x00BFFFFF, "| UBER | Você chegou até seu passageiro(a).");
    SendClientMessage(id, 0x00BFFFFF, "| UBER | Seu uber chegou, vá até o(a) motorista");

    pUber[playerid][UberStatus] = 2;
    pUber[id][UberStatusChamada] = 2;
    return 1;
}

stock FinalizarUber(playerid)
{
    if(pUber[playerid][UberStatus] > 0)
    {
        KillTimer(pUber[playerid][UberTimer]);
        new id = GetPVarInt(playerid, "uBERR");
        pUber[id][UberStatusChamada] = 0;
        pUber[playerid][UberStatus] = 0;
        DestroyDynamicMapIconEx(pUber[id][MapIc]);
        DestroyDynamicMapIconEx(pUber[playerid][MapIc]);
        if(pUber[playerid][UberStatus] > 2 && pUber[playerid][UberStatus] <= 3) OcultarUber(id);
    }
    else if(pUber[playerid][UberStatusChamada] > 0)
    {
        new id = GetPVarInt(playerid, "uBERR");
        KillTimer(pUber[id][UberTimer]);
        pUber[id][UberStatus] = 0;
        pUber[playerid][UberStatusChamada] = 0;
        DestroyDynamicMapIconEx(pUber[id][MapIc]);
        DestroyDynamicMapIconEx(pUber[playerid][MapIc]);
        if(pUber[playerid][UberStatusChamada] > 2 && pUber[playerid][UberStatusChamada] <= 3) OcultarUber(id);
    }
    return 1;
}

CMD:aceitar(playerid, params[])
{
    if(pUber[playerid][EmServico] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em serviço");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPlayerVehicleID(playerid) != pVeiculo[playerid][pUber[playerid][UberSlot]][MeuVeiculoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo pessoal");
    if(pUber[playerid][UberStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está aceitou um pedido");

    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Aceitar [ID]"); 
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O(A) Jogador(a) não está conectado(a)"); 
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se aceitar");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O(A) Jogador(a) não está logado(a)");
    if(pUber[id][UberStatusChamada] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) já foi atendido(a)");
    if(pUber[id][UberChamada] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode aceitar esse(a) jogador(a)");
    
    SetPVarInt(playerid, "uBERR", id);
    SetPVarInt(id, "uBERR", playerid);

    pUber[playerid][UberValor] = 0;
    pUber[playerid][UberStatus] = 1; 
    pUber[id][UberStatusChamada] = 1;
    pUber[id][UberChamada] = 0;
    pUber[playerid][UberTimer] = SetTimerEx("AtualizarUber", 2000, true, "dd", playerid, id);

    new Mensagem[90];
    format(Mensagem, sizeof(Mensagem), "| UBER | Você aceitou o chamado do(a) %s[%d], vá até %s", PegarNick(id), id, GetPlayerZone(id));
    SendClientMessage(playerid, -1, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| UBER | O(A) Uber %s[%d] aceitou seu chamado", PegarNick(playerid), playerid);
    SendClientMessage(id, -1, Mensagem);
    return 1;
}