function AtualizarUber(playerid)
{
    new id = pUber[playerid][PassageiroID];

    //Corrida
    if(pUber[id][StatusChamado] == 2)
    {
        new Float:MinhaPosAtual[3];
        GetPlayerPos(playerid, MinhaPosAtual[0], MinhaPosAtual[1], MinhaPosAtual[2]);
        new distancia = GetDistanceBetweenPoints(MinhaPosAtual[0], MinhaPosAtual[1], MinhaPosAtual[2], pUber[playerid][UberApos][0], pUber[playerid][UberApos][1], pUber[playerid][UberApos][2]);
        if(distancia >= 14.0)
        {
            new Mensagem[128];
            if(Jogador[id][Dinheiro] < pUber[playerid][UberValor])
            {
                OcultarUber(id);
                OcultarUber(playerid);
                KillTimer(pUber[playerid][UberTemporizador]);

                //Passageiro
                pUber[id][StatusChamado] = 0;

                //Motorista
                pUber[playerid][UberAtendeu] = false;
            
                Jogador[playerid][Dinheiro] += Jogador[id][Dinheiro];
                Jogador[id][Dinheiro] = 0;
                format(Mensagem, sizeof(Mensagem), "| UBER | Seu passageiro ficou sem dinheiro, você recebeu $%s", DinheiroSeparar(pUber[playerid][UberValor]));
                SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
                SendClientMessage(id, 0xFFFF00FF, "| UBER | Seu dinheiro acabou e sua corrida foi cancelada");
                GetPlayerPos(id, MinhaPosAtual[0], MinhaPosAtual[1], MinhaPosAtual[2]);
                SetPlayerPos(id, MinhaPosAtual[0]+2, MinhaPosAtual[1], MinhaPosAtual[2]);
                return 1;
            }

            pUber[playerid][UberValor] += 5;
            format(Mensagem, sizeof(Mensagem), "~w~Corrida_~g~$%s", DinheiroSeparar(pUber[playerid][UberValor]));
            PlayerTextDrawSetString(playerid, UberTxd[playerid][4], Mensagem);
            PlayerTextDrawSetString(id, UberTxd[id][4], Mensagem);
            
            pUber[playerid][UberApos][0] = MinhaPosAtual[0];
            pUber[playerid][UberApos][1] = MinhaPosAtual[1];
            pUber[playerid][UberApos][2] = MinhaPosAtual[2];
        }
        return 1;
    }

    //Sistema de localização
    new Float:moPos[3],
        Float:poPos[3]
    ;
    GetPlayerPos(id, poPos[0], poPos[1], poPos[2]);
    GetPlayerPos(playerid, moPos[0], moPos[1], moPos[2]);
    if(!IsPlayerInRangeOfPoint(playerid, 30.0, poPos[0], poPos[1], poPos[2]))
    {
        DestroyDynamicMapIconEx(pUber[playerid][UberIcone]);
        DestroyDynamicMapIconEx(pUber[id][UberIcone]);
        pUber[playerid][UberIcone] = CreateDynamicMapIcon(poPos[0], poPos[1], poPos[2], 58, -1, 0, 0, playerid, 99999.0, MAPICON_GLOBAL);
        pUber[id][UberIcone] = CreateDynamicMapIcon(moPos[0], moPos[1], moPos[2], 55, -1, 0, 0, id, 99999.0, MAPICON_GLOBAL);
        return 1;
    }
    DestroyDynamicMapIconEx(pUber[playerid][UberIcone]);
    DestroyDynamicMapIconEx(pUber[id][UberIcone]);
    KillTimer(pUber[playerid][UberTemporizador]);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| UBER | Seu(a) motorista {00BFFF}%s[%d]{FFFFFF} chegou", PegarNick(playerid), playerid);
    SendClientMessage(id, -1, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| UBER | Você chegou até o(a) {00BFFF}%s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}