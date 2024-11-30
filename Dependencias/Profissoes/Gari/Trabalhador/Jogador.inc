#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamic3DTextLabelEx(pGari[playerid][GariTexto]);    
    DestroyDynamicMapIconEx(pGari[playerid][GariIcone]);
    DestroyDynamicCPEx(pGari[playerid][GariCheck]);
    if(pGari[playerid][VeiculoAlugado] == true) DestroyVehicleEx(pGari[playerid][CaminhaoLixo]);

    // Verificar se tem parceiro
    if(pGari[playerid][TemParceiro] == true)
    {
        new prc = pGari[playerid][Parceiro],
            String[128];
        if(pGari[prc][LixosColetado] > 0) 
        {
            pGari[prc][LixosColetado] = 0;
            DestroyDynamic3DTextLabelEx(pGari[prc][GariTexto]);
            DestroyDynamicMapIconEx(pGari[prc][GariIcone]);
            DestroyDynamicCPEx(pGari[prc][GariCheck]);
        }
        OcultarMenuGari(prc);
        pGari[prc][TemParceiro] = false;
        format(String, sizeof(String), "| AVISO | %s desconectou-se do servidor", PegarNick(playerid));
        SendClientMessage(prc, 0xfc520fFF, String);
    }


    new Limpar[GariInfo];
    pGari[playerid] = Limpar;
    return 1;
}


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        // Veículo
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 2109.5657,-2069.0015,13.5544))
        { 
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Gari")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão!");
            // if(pGari[playerid][UniformeAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está sem uniforme!");
            if(pGari[playerid][LixosColetado] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você ainda tem lixos, entregue antes de devolver o veículo");
            if(pGari[playerid][GariDelayVeiculo] > gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Aguarde um pouco!");
            pGari[playerid][GariDelayVeiculo] = gettime()+10;
            if(pGari[playerid][VeiculoAlugado] == false)
            {
                if(Jogador[playerid][CarteiraC] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar um carro ( Habilitação: C )");
                new posid = random(sizeof(pLixo));
                pGari[playerid][CaminhaoLixo] = CreateVehicleEx(playerid, 408, pLixo[posid][PosicaoX], pLixo[posid][PosicaoY], pLixo[posid][PosicaoZ], pLixo[posid][PosicaoA], 1, 1, 360, 0);
                pGari[playerid][VeiculoAlugado] = true;
                Jogador[playerid][Trabalhando] = true; // Remvoer verificação de trabalhando
                MarcarPosicao(playerid, pLixo[posid][PosicaoX], pLixo[posid][PosicaoY], pLixo[posid][PosicaoZ]);
                SendClientMessage(playerid, 0xFFFF00FF, "| GARI | Você alugou o veículo");
                return 1;
            }
            DestroyVehicleEx(pGari[playerid][CaminhaoLixo]);
            VerificarMarcacao(playerid);
            pGari[playerid][VeiculoAlugado] = false;
            Jogador[playerid][Trabalhando] = false;
            // pGari[playerid][UniformeAlugado] = false;  
            SendClientMessage(playerid, 0xFFFF00FF, "| GARI | Você devolveu o veículo");
            return 1;
        }
    }
    return 1;
}


CMD:iniciardupla(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Gari")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão!");
    // if(pGari[playerid][UniformeAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está uniforme!");
    if(pGari[playerid][VeiculoAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não alugou um veículo!");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está dirigindo!");
    if(pGari[playerid][TemParceiro] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já está trabalhando com um(a) parceiro(a)!");
    if(pGari[playerid][LixosColetado] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não concluiu o serviço!");
    if(GetPlayerVehicleID(playerid) != pGari[playerid][CaminhaoLixo]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está em seu veículo alugado!");

    new String[128];
    format(String, sizeof(String), "| GARI | Você iniciou serviço com %s[%d]", PegarNick(playerid), playerid);

    new String2[128];
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(i == playerid) continue;
        if(!IsPlayerConnected(i)) continue;
        if(strcmp(Jogador[i][Profissao], "Gari")) continue;
        if(GetPlayerState(i) != PLAYER_STATE_PASSENGER || GetPlayerVehicleID(i) != pGari[playerid][CaminhaoLixo]) continue;

        if(pGari[i][VeiculoAlugado] == true)
        {
            new String32[128];
            format(String32, sizeof(String32), "| ERRO | %s[%d] está com um veículo alugado", PegarNick(i), i);
            SendClientMessage(playerid, 0xfc520fFF, String32);
            return 1;
        }

        /*if(pGari[i][UniformeAlugado] == false)
        {
            new String32[128];
            format(String32, sizeof(String32), "| ERRO | %s[%d] não está utilizando seu uniforme!", PegarNick(i), i);
            SendClientMessage(playerid, 0xfc520fFF, String32);
            return 1;
        }*/

        if(pGari[i][TemParceiro] == true)
        {
            new String32[128];
            format(String32, sizeof(String32), "| ERRO | %s[%d] já tem um(a) parceiro(a)!", PegarNick(i), i);
            SendClientMessage(playerid, 0xfc520fFF, String32);
            return 1;
        }

        if(pGari[i][LixosColetado] > 0)
        {
            new String32[128];
            format(String32, sizeof(String32), "| ERRO | %s[%d] ainda não concluiu o serviço!", PegarNick(i), i);
            SendClientMessage(playerid, 0xfc520fFF, String32);
            return 1;
        }

        format(String2, sizeof(String2), "| GARI | %s[%d] Iniciou serviço com você", PegarNick(i), i);
        SendClientMessage(playerid, 0xFFFF00FF, String2);
        SendClientMessage(i, 0xFFFF00FF, String);

        pGari[i][CaminhaoLixo] = pGari[playerid][CaminhaoLixo];

        pGari[i][TemParceiro] = true;
        pGari[playerid][TemParceiro] = true;

        pGari[i][Parceiro] = playerid;
        pGari[playerid][Parceiro] = i;

        MostrarGariMenuLixo(i);
        MostrarGariMenuLixo(playerid);

        format(String, sizeof(String), "%d/%d", pGari[playerid][LixosColetado], MaximoLixo);
        PlayerTextDrawSetString(playerid, GariMenu[playerid][0], String);
        PlayerTextDrawSetString(i, GariMenu[i][0], String);
        break;
    }
    return 1;
}