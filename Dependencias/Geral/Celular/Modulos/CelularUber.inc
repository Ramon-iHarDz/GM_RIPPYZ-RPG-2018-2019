#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 6; i++){
        CelularUber[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == CelularUber[playerid][0])
    {
        new Dialog[2000],
            TemUbb = 0,
            Float:udPos[3];

        strcat(Dialog, "Uber\tLocal\tStatus\tVeículo\n");
        for(new i=0; i < MAX_PLAYERS; i++)
        {
            if(!IsPlayerConnected(i)) continue;
            if(Jogador[i][Logado] == false) continue;
            if(pUber[i][EmServico] == false) continue; 
            if(Jogador[i][Admin] > 0 && pAdmin[i][FalsoPlayer] == false) continue;
            GetPlayerPos(i, udPos[0], udPos[1], udPos[2]);
            if(pUber[i][UberStatus] > 0) strcatEx(Dialog, "%s[%d]\t{e2b960}%s\t{ff2d26}Indisponível\t{CCCCCC}%s\n", PegarNick(i), i, GetPlayerZone(i), GetVehicleNameByModel(pVeiculo[i][pUber[i][UberSlot]][MeuVeiculoModelo]));
            else strcatEx(Dialog, "%s[%d]\t{e2b960}%s\t{32CD32}Disponível\t{CCCCCC}%s\n", PegarNick(i), i, GetPlayerZone(i), GetVehicleNameByModel(pVeiculo[i][pUber[i][UberSlot]][MeuVeiculoModelo]));
            TemUbb++;
        }
        if(TemUbb == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há ubers no momento");
        Dialog_Show(playerid, UbersOnline, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Ubers", Dialog, "Fechar", "");
    }

    else if(playertextid == CelularUber[playerid][1])
    {
        if(Jogador[playerid][Operadora] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem CHIP");
        if(pUber[playerid][UberChamada] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já possui um chamado, aguarde.");
        if(pUber[playerid][UberStatusChamada] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está em um chamado");
        if(GetPlayerInterior(playerid) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode solicitar um uber");
        if(GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode solicitar um uber");

        new Mensagem[138],
            bba = 0;
        format(Mensagem, sizeof(Mensagem), "| CHAMADO | O(A) Jogador(a) {FFA500}%s[%d]{FFFFFF} está solicitando uber em {e2b960}%s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
        for(new i=0; i < MAX_PLAYERS; i++) 
        {
            if(!IsPlayerConnected(i)) continue;
            if(Jogador[i][Logado] == false) continue;
            if(pUber[i][EmServico] == false) continue;
            SendClientMessage(i, -1, Mensagem);
            bba++;
        }

        if(bba == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há ubers no momento");
        pUber[playerid][UberChamada] = gettime()+60;
        format(Mensagem, sizeof(Mensagem), "| UBER | Sua solicitação chegou para %d uber(s), aguarde.", bba);
        SendClientMessage(playerid, 0xFFA500FF, Mensagem);
    }

    else if(playertextid == CelularUber[playerid][2])
    {
        if(pUber[playerid][UberStatus] == 1)
        {
            new id = GetPVarInt(playerid, "uBERR"),
                Mensagem[128];
            FinalizarUber(id);

            if(Jogador[playerid][Dinheiro] < 1000){
                Jogador[playerid][Dinheiro] -= Jogador[playerid][Dinheiro];  
            }else Jogador[playerid][Dinheiro] -= 650;
            SendClientMessage(playerid, 0xFFFF00FF, "| UBER | Você cancelou o atendimento e perdeu $1.000");
            format(Mensagem, sizeof(Mensagem), "| UBER | Infelizmente o(a) motorista %s cancelou o pedido", PegarNick(playerid));
            SendClientMessage(id, 0xFFFF00FF, Mensagem);
            return 1;
        }
        else if(pUber[playerid][UberStatusChamada] == 1)
        {
            FinalizarUber(playerid); 
            new id = GetPVarInt(playerid, "uBERR"),
                Mensagem[128];

            if(Jogador[playerid][Dinheiro] < 650){
                Jogador[playerid][Dinheiro] -= Jogador[playerid][Dinheiro];  
            }else Jogador[playerid][Dinheiro] -= 650;
            SendClientMessage(playerid, 0xFFFF00FF, "| UBER | Você cancelou o chamado e perdeu $650");
            format(Mensagem, sizeof(Mensagem), "| UBER | Infelizmente o(a) passageiro(a) %s cancelou o chamado", PegarNick(playerid));
            SendClientMessage(id, 0xFFFF00FF, Mensagem);
            return 1;
        }
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não solicitou um uber");
    }
    return 0;
}

function MostrarCelularUber(playerid)
{
    CelularUber[playerid][0] = CreatePlayerTextDraw(playerid, 440.495452, 325.916778, "Ubers");
    PlayerTextDrawLetterSize(playerid, CelularUber[playerid][0], 0.322693, 1.430833);
    PlayerTextDrawTextSize(playerid, CelularUber[playerid][0], 470.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularUber[playerid][0], 1);
    PlayerTextDrawColor(playerid, CelularUber[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularUber[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CelularUber[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, CelularUber[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularUber[playerid][0], 70);
    PlayerTextDrawFont(playerid, CelularUber[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CelularUber[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, CelularUber[playerid][0], true);

    CelularUber[playerid][1] = CreatePlayerTextDraw(playerid, 435.395141, 343.617858, "Solicitar");
    PlayerTextDrawLetterSize(playerid, CelularUber[playerid][1], 0.322693, 1.430833);
    PlayerTextDrawTextSize(playerid, CelularUber[playerid][1], 478.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularUber[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularUber[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CelularUber[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, CelularUber[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, CelularUber[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularUber[playerid][1], 70);
    PlayerTextDrawFont(playerid, CelularUber[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CelularUber[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, CelularUber[playerid][1], true);

    CelularUber[playerid][2] = CreatePlayerTextDraw(playerid, 435.395141, 360.318878, "Cancelar");
    PlayerTextDrawLetterSize(playerid, CelularUber[playerid][2], 0.322693, 1.430833);
    PlayerTextDrawTextSize(playerid, CelularUber[playerid][2], 478.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularUber[playerid][2], 1);
    PlayerTextDrawColor(playerid, CelularUber[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularUber[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, CelularUber[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CelularUber[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularUber[playerid][2], 70);
    PlayerTextDrawFont(playerid, CelularUber[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CelularUber[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, CelularUber[playerid][2], true);

    CelularUber[playerid][3] = CreatePlayerTextDraw(playerid, 428.045318, 326.500030, "hud:radar_runway");
    PlayerTextDrawTextSize(playerid, CelularUber[playerid][3], 14.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, CelularUber[playerid][3], 1);
    PlayerTextDrawColor(playerid, CelularUber[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, CelularUber[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, CelularUber[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, CelularUber[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularUber[playerid][3], 255);
    PlayerTextDrawFont(playerid, CelularUber[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, CelularUber[playerid][3], 0);

    CelularUber[playerid][4] = CreatePlayerTextDraw(playerid, 423.160034, 343.683288, "hud:radar_impound");
    PlayerTextDrawTextSize(playerid, CelularUber[playerid][4], 10.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, CelularUber[playerid][4], 1);
    PlayerTextDrawColor(playerid, CelularUber[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, CelularUber[playerid][4], 0);
    PlayerTextDrawBoxColor(playerid, CelularUber[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, CelularUber[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularUber[playerid][4], 255);
    PlayerTextDrawFont(playerid, CelularUber[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, CelularUber[playerid][4], 0);

    CelularUber[playerid][5] = CreatePlayerTextDraw(playerid, 423.160034, 361.583465, "hud:radar_modgarage");
    PlayerTextDrawTextSize(playerid, CelularUber[playerid][5], 10.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, CelularUber[playerid][5], 1);
    PlayerTextDrawColor(playerid, CelularUber[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, CelularUber[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, CelularUber[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, CelularUber[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularUber[playerid][5], 255);
    PlayerTextDrawFont(playerid, CelularUber[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, CelularUber[playerid][5], 0);

    for(new i=0; i < 6; i++){
        PlayerTextDrawShow(playerid, CelularUber[playerid][i]);
    }

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarCelularUber");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarHome");
    return 1;
}

function OcultarCelularUber(playerid)
{
    for(new i=0; i < 6; i++){
        PlayerTextDrawDestroy(playerid, CelularUber[playerid][i]);
        CelularUber[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}