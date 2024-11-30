#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    // Pegar lixo na lixeira
    if(newkeys == KEY_NO && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) 
    { 
        for(new i=0; i < MAX_LIXOS; i++)
        {
            if(Lixo[i][cColocado] == false) continue;
            if(!IsPlayerInRangeOfPoint(playerid, 2.0, Lixo[i][PosX], Lixo[i][PosY], Lixo[i][PosZ])) continue;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Gari")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão!");
            if(pGari[playerid][LixosColetado] >= MaximoLixo) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Seu caminhão está lotado");
            if(pGari[playerid][LixoNaMao] >= 2) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já tem um lixo na mão, coloque-o no caminhão para pegar o outro!");
            if(pGari[playerid][TemParceiro] == false && pGari[playerid][VeiculoAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está em serviço");

            // if(pGari[playerid][UniformeAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está sem uniforme");
            if(Lixo[i][LixoAtual] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse latão/lata não tem lixos");
            
            // Verificar se estou no lixo
            SetPVarInt(playerid, "asdasdas", gettime()+2);

            new Float:MinhaX[3];
            GetPlayerPos(playerid, MinhaX[0], MinhaX[1], MinhaX[2]);
            if(!IsVehicleInRangeOfPoint(pGari[playerid][CaminhaoLixo], 50.0, MinhaX[0], MinhaX[1], MinhaX[2])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Veículo está muito longe!");
            if(Lixo[i][LixoAtual] == Lixo[i][LixoMaximo]) SetTimerEx("ResetarLixos", 180000, false, "i", i); // Resetar Lixo
        
            Lixo[i][LixoAtual]--; // Reduzir lixo na lixeira
            AtualizarLixeira(i); // Atualizar

            if(pGari[playerid][LixoNaMao] == 0){
                SetPlayerAttachedObject(playerid, 9, 1265, 5, 0.2300, -0.0060, -0.0100, 0.0000, -132.1999, 0.0000, 0.5289, 0.5289, 0.7270, 0xFFFFFFFF, 0xFFFFFFFF); // Colocar Lixdo na Mão
                pGari[playerid][GariTexto] = CreateDynamic3DTextLabel("Aperte {CCCCCC}H{FFFFFF} para colocar o lixo", 0xFFFFFFFF, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, pGari[playerid][CaminhaoLixo], 0, 0, 0, playerid, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
            }
            else if(pGari[playerid][LixoNaMao] == 1) SetPlayerAttachedObject(playerid, 8, 1265, 6, 0.2360, -0.0290, 0.0300, 10.6000, -132.7999, 0.0000, 0.4680, 0.5070, 0.6909, 0xFFFFFFFF, 0xFFFFFFFF); // Colocar Lixdo na Mão

            // Colocar Mensagem no Caminhão
            pGari[playerid][LixoNaMao]++; // Verificar lixo na mão
            break;
        }
        if(pGari[playerid][LixoNaMao] < 1)
        {
            for(new i=0; i < MAX_CASAS; i++)
            {
                if(pCasa[i][Colocado] == false) continue;
                if(pCasa[i][LixoF] < 1) continue;
                if(!IsPlayerInRangeOfPoint(playerid, 2.0, pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ])) continue;
                if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
                if(strcmp(Jogador[playerid][Profissao], "Gari")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão!");
                if(pGari[playerid][LixosColetado] >= MaximoLixo) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Seu caminhão está lotado");
                if(pGari[playerid][LixoNaMao] >= 2) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já tem um lixo na mão, coloque-o no caminhão para pegar o outro!");
                if(pGari[playerid][TemParceiro] == false && pGari[playerid][VeiculoAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está em serviço");

                // Verificar se estou no lixo
                SetPVarInt(playerid, "asdasdas", gettime()+2);

                pCasa[i][LixoF]--;
                AtualizarCasa(i);

                if(pGari[playerid][LixoNaMao] == 0){
                    SetPlayerAttachedObject(playerid, 9, 1265, 5, 0.2300, -0.0060, -0.0100, 0.0000, -132.1999, 0.0000, 0.5289, 0.5289, 0.7270, 0xFFFFFFFF, 0xFFFFFFFF); // Colocar Lixdo na Mão
                    pGari[playerid][GariTexto] = CreateDynamic3DTextLabel("Aperte {CCCCCC}H{FFFFFF} para colocar o lixo", 0xFFFFFFFF, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, pGari[playerid][CaminhaoLixo], 0, 0, 0, playerid, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
                }
                else if(pGari[playerid][LixoNaMao] == 1) SetPlayerAttachedObject(playerid, 8, 1265, 6, 0.2360, -0.0290, 0.0300, 10.6000, -132.7999, 0.0000, 0.4680, 0.5070, 0.6909, 0xFFFFFFFF, 0xFFFFFFFF); // Colocar Lixdo na Mão
                pGari[playerid][LixoNaMao]++; // Verificar lixo na mão
                break;
            }
        }
    } 


    // Colocar Lixo no Caminhão
    else if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) 
    { 
        if(AtrasVeiculo(playerid, pGari[playerid][CaminhaoLixo], 3.0)) 
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(pGari[playerid][LixoNaMao] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está com lixo na mão");
            if(GetPVarInt(playerid, "asdasdas") > gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Aguarde um pouco.");

            new String[30],
                bool:EntaoNe = false;
            if(pGari[playerid][LixosColetado] < 1) EntaoNe = true;

            // Adicionar Lixo
            pGari[playerid][LixosColetado] += pGari[playerid][LixoNaMao];
            if(pGari[playerid][LixosColetado] > MaximoLixo) pGari[playerid][LixosColetado] = MaximoLixo;
            
            if(pGari[playerid][LixosColetado] >= MaximoLixo) format(String, sizeof(String), "~r~%d/%d", pGari[playerid][LixosColetado], MaximoLixo);
            else format(String, sizeof(String), "%d/%d", pGari[playerid][LixosColetado], MaximoLixo);

            // Caso tenha parceiro(a)
            if(pGari[playerid][TemParceiro] == true)
            {
                new id = pGari[playerid][Parceiro];

                // Verificar sem tem parceiro(a) e verificar dependencias
                if(EntaoNe == true){
                    pGari[id][GariIcone] = CreateDynamicMapIcon(2107.2844,-2008.5096,13.5469, 51, 3, 0, 0, id, 99999.9, MAPICON_GLOBAL);
                    pGari[id][GariCheck] = CreateDynamicCP(2107.2844,-2008.5096,13.5469, 2.0, 0, 0, id, 40.0, -1, 0);
                    SendClientMessage(id, 0xFFFF00FF, "| MAPA | Localização de descarregamento foi marcada em seu mapa!");
                }
                pGari[id][LixosColetado] += pGari[playerid][LixoNaMao];
                if(pGari[id][LixosColetado] > MaximoLixo) pGari[id][LixosColetado] = MaximoLixo;

                // Atualizar e Remover Lixo caso tenha chegado no máximo
                if(pGari[playerid][LixosColetado] >= MaximoLixo)
                {
                    if(pGari[id][LixoNaMao] >= 1)
                    {
                        RemovePlayerAttachedObject(id, 9);
                        if(pGari[id][LixoNaMao] > 1) RemovePlayerAttachedObject(id, 8);
                        DestroyDynamic3DTextLabelEx(pGari[id][GariTexto]);
                        pGari[id][LixoNaMao] = 0;
                    }
                }
                PlayerTextDrawSetString(id, GariMenu[id][0], String);  
            }

            // Marcar no mapa ao pegar o lixo
            if(EntaoNe == true)
            {
                pGari[playerid][GariIcone] = CreateDynamicMapIcon(2107.2844,-2008.5096,13.5469, 51, 3, 0, 0, playerid, 99999.9, MAPICON_GLOBAL);
                pGari[playerid][GariCheck] = CreateDynamicCP(2107.2844,-2008.5096,13.5469, 2.0, 0, 0, playerid, 40.0, -1, 0);
                SendClientMessage(playerid, 0xFFFF00FF, "| MAPA | Localização de descarregamento foi marcada em seu mapa");
            }

            // Apagar Texto e Remover Lixo
            RemovePlayerAttachedObject(playerid, 9);
            if(pGari[playerid][LixoNaMao] > 1) RemovePlayerAttachedObject(playerid, 8);
            DestroyDynamic3DTextLabelEx(pGari[playerid][GariTexto]);
            if(EntaoNe == true && pGari[playerid][TemParceiro] == false) MostrarGariMenuLixo(playerid);
            PlayerTextDrawSetString(playerid, GariMenu[playerid][0], String);
            pGari[playerid][LixoNaMao] = 0;
        }
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pGari[playerid][GariCheck]) return 1;

    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você precisa sair do veículo!");
    if(pGari[playerid][LixosColetado] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem lixo para entregar!");
    if(pGari[playerid][LixoNaMao] >= 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Coloque o lixo no caminhão para descarregar!");
    
    new id;
    if(pGari[playerid][TemParceiro] == true){
        id = pGari[playerid][Parceiro];
        if(pGari[id][LixoNaMao] >= 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Seu(a) parceiro(a) precisa colocar o lixo no caminhão!");
    }

    OcultarMenuGari(playerid);
    DestroyDynamicCPEx(pGari[playerid][GariCheck]);
    DestroyDynamicMapIconEx(pGari[playerid][GariIcone]);

    if(pGari[playerid][TemParceiro] == true)
    {
        DestroyDynamicCPEx(pGari[id][GariCheck]);
        DestroyDynamicMapIconEx(pGari[id][GariIcone]);
        pGari[id][LixosColetado] = 0;
    }

    new ValorTotal,
        ValorCoisado,
        LixosTT,
        tt = LixoPreco;
        
    if(pGari[playerid][TemParceiro] == true)
    {
        LixosTT = pGari[playerid][LixosColetado];
        ValorTotal = (tt*LixosTT);
        ValorCoisado = ValorTotal/2;
    }
    else
    {
        LixosTT = pGari[playerid][LixosColetado];  
        ValorCoisado = (tt*LixosTT);    
    }

    pGari[playerid][LixosColetado] = 0;

    //Entrega do Dinheiro
    if(pGari[playerid][TemParceiro] == true) Jogador[id][Dinheiro] += ValorCoisado;
    Jogador[playerid][Dinheiro] += ValorCoisado;

    new String[158];
    if(pGari[playerid][TemParceiro] == true)
    {
        format(String, sizeof(String), "| GARI | Você recebeu {32CD32}$%s{FFFFFF} por entregar {5DADE2}%d{FFFFFF} lixo(s) com {5DADE2}%s[%d]", DinheiroSeparar(ValorCoisado), LixosTT, PegarNick(id), id);
        SendClientMessage(playerid, -1, String);

        format(String, sizeof(String), "| GARI | Você recebeu {32CD32}$%s{FFFFFF} por entregar {5DADE2}%d{FFFFFF} lixo(s) com {5DADE2}%s[%d]", DinheiroSeparar(ValorCoisado), LixosTT, PegarNick(playerid), playerid);
        SendClientMessage(id, -1, String);

        SendClientMessage(playerid, 0xFFFF00FF, "| GARI | Vocês acabaram o serviço, espere outro(a) parceiro(a) ou utilize o comando /iniciardupla novamente!");
        SendClientMessage(id, 0xFFFF00FF, "| GARI | Vocês acabaram o serviço, espere outro(a) parceiro(a) ou utilize o comando /iniciardupla novamente!");
        
        pGari[id][Parceiro] = 0;
        pGari[playerid][Parceiro] = 0;
        pGari[playerid][TemParceiro] = false;
        OcultarMenuGari(id);
    }
    else
    {
        format(String, sizeof(String), "| GARI | Você coletou {5DADE2}%d{FFFFFF} saco(s) de lixo(s) e ganhou {32CD32}$%s", LixosTT, DinheiroSeparar(ValorCoisado));
        SendClientMessage(playerid, -1, String);   
    }
    return 1;
}