#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_CTRL_BACK || GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(pMEntregador[playerid][IndoEntregar] == false) return 1;

    if(AtrasVeiculo(playerid, pMEntregador[playerid][mVID], 2.0))
    {
        new id = pMEntregador[playerid][CasaEntregg];
        if(!IsPlayerInRangeOfPoint(playerid, 90.0, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe do local de entrega.");
        if(pMEntregador[playerid][EntregaMao] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem uma caixa na mão, vá entregar");
        pMEntregador[playerid][EntregaMao] = true;
        ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
        SetPlayerAttachedObject(playerid, 9, 1220, 3, 0.1310, -0.4270, -0.1290, -7.3999, 3.4000, 29.9000, 0.5850, 0.5280, 0.6530, 0xFFFFFFFF, 0xFFFFFFFF);
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pMEntregador[playerid][CheckEntrega]) return 1;
    if(pMEntregador[playerid][EntregaMao] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Vá atrás do seu caminhão e pegue uma caixa");
    pMEntregador[playerid][EntregaMao] = false;
    ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
    RemovePlayerAttachedObject(playerid, 9);
    pMEntregador[playerid][TemQEntrr]--;

    /*new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "{00BFFF}Caminhão\n{FFFFFF}Aperte {CCCCCC}H{FFFFFF} para pegar as caixas ( Restante: %d )", pMEntregador[playerid][TemQEntrr]);
    UpdateDynamic3DTextLabelText(pMEntregador[playerid][EntregaTexto], -1, Mensagem);*/

    if(pMEntregador[playerid][TemQEntrr] < 1)
    {
        // Remover Informações
        OcultarCaixaEntregas(playerid);
        DestroyDynamicMapIconEx(pMEntregador[playerid][MapaEntrega]);
        DestroyDynamicCPEx(pMEntregador[playerid][CheckEntrega]);
        DestroyDynamic3DTextLabelEx(pMEntregador[playerid][EntregaTexto]);
        pMEntregador[playerid][IndoEntregar] = false;
        SetPVarInt(playerid, "ASDDASDASASD", 0);

        new fdsss = GetPVarInt(playerid, "FASDASDSA");
        new id = pMEntregador[playerid][CasaEntregg],
            Gangar = (350*fdsss),
            Enviar[128];

        Jogador[playerid][Dinheiro] += Gangar;
        format(Enviar, sizeof(Enviar), "| ENTREGAS | Você recebeu {32CD32}$%s{FFFFFF} por entregar {00BFFF}%d{FFFFFF} entrega(s)", DinheiroSeparar(Gangar), eMoveis[id][MoveisQuantidade]);
        SendClientMessage(playerid, -1, Enviar);

        format(Enviar, sizeof(Enviar), "UPDATE `moveis` SET `Status` = 0 WHERE `Casa` = %d", id);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um problema, solicite um admin.");

        // Casa
        eMoveis[id][JaLevando] = false;
        eMoveis[id][MovelStatusPlayer] = 0;
        eMoveis[id][MoveisQuantidade] -= GetPVarInt(playerid, "FASDASDSA");
        for(new i=0; i < MAX_MOVEIS; i++)
        {
            if(cMovel[id][i][cMovelObjeto] < 1) continue; 
            cMovel[id][i][cStatus] = 0;
        }

        new pid = PegarIdPeloNick(pCasa[id][cDono]);
        if(IsPlayerConnected(playerid)){
            format(Enviar, sizeof(Enviar), "| MÓVEIS | Seus móveis foram entregues em sua própriedade por %s[%d].", PegarNick(playerid), playerid);
            SendClientMessage(pid, 0xFFFF00FF, Enviar);
        }

    }
    AtualizarCaixaEntregas(playerid, pMEntregador[playerid][TemQEntrr], GetPVarInt(playerid, "FASDASDSA"));
    return 1;
}