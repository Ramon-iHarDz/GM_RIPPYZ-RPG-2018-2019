#include <YSI_Coding\y_hooks>

function MecanicaVerificador(playerid, vid, slot)
{
    if(!IsPlayerInRangeOfPoint(playerid, 60.0, 317.5602, -40.2021, 1.5781))
    {
        SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Você saiu de perto da mecânica e seu alistamento foi cancelado!");
        JogadorM[playerid][Alistou] = false;   
        JogadorM[playerid][DelayAlistament] = gettime()+20;
        KillTimer(JogadorM[playerid][TimerID]);
    }
    else if(pVeiculo[playerid][slot][VehConectado] == false)
    {
        SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Seu veículo não está conectado e seu alistamento foi cancelado!");
        JogadorM[playerid][Alistou] = false;   
        JogadorM[playerid][DelayAlistament] = gettime()+20;
        KillTimer(JogadorM[playerid][TimerID]);  
    }
    else if(!IsVehicleInRangeOfPoint(playerid, 60.0, 317.5602, -40.2021, 1.5781))
    {
        SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Seu veículo está perto da mêcanica e seu alistamento foi cancelado!");
        JogadorM[playerid][Alistou] = false;   
        JogadorM[playerid][DelayAlistament] = gettime()+20;
        KillTimer(JogadorM[playerid][TimerID]);  
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 326.7445, -43.5736, 1.5429)) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Atendimentos são feitos apenas a pé");
    if(JogadorM[playerid][DelayAlistament] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa aguardar alguns minutos.");

    new SeusVehTru = 0,
        Dialog[300]
    ;

    if(JogadorM[playerid][Alistou] == true)
    {
        Dialog_Show(playerid, CancelamentoMec, DIALOG_STYLE_MSGBOX, "{FF0000}Cancelar", "Você deseja cancelar o pedido na mecânica?", "Sim", "Não"); 
        return 1;
    }

    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][VehConectado] == false) continue;
        if(!IsApenasCarro(pVeiculo[playerid][i][MeuVeiculoID])) continue;
        //strcatEx(Dialog, "{FF0000}%s\n", GetVehicleNameByModel(GetVehicleModel(pVeiculo[playerid][i][MeuVeiculoID])));
        SeusVehTru++;
    }

    strcat(Dialog, "{FFFFFF}Consertar Veículo\n");
    strcat(Dialog, "Pintar Veículo");

    if(SeusVehTru == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhum veículo conectado");
    else Dialog_Show(playerid, MecanicaMenu, DIALOG_STYLE_TABLIST, "{FF0000}Mecânica", Dialog, "Selecionar", "Fechar");

    return 1;
}

Dialog:MecanicaMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[300];
    JogadorM[playerid][PedidoStatus] = listitem;
    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][VehConectado] == false) continue;
        if(!IsApenasCarro(pVeiculo[playerid][i][MeuVeiculoID])) continue;
        
        // Verificar se o veículo não está na blacklist
        if(!VerificarMBlock(GetVehicleModel(pVeiculo[playerid][i][VehConectado]))) strcatEx(Dialog, "{FF0000}%s\t{32CD32}Permitido(a)\n", GetVehicleNameByModel(GetVehicleModel(pVeiculo[playerid][i][MeuVeiculoID])));
        else strcatEx(Dialog, "{FF0000}%s\t{FF4500}Bloqueado(a)\n", GetVehicleNameByModel(GetVehicleModel(pVeiculo[playerid][i][MeuVeiculoID])));
        
    }
    Dialog_Show(playerid, SelecaoVeiculoMec, DIALOG_STYLE_TABLIST, "{FF0000}Mecânica", Dialog, "Selecionar", "Fechar");
    return 0;
}


Dialog:SelecaoVeiculoMec(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new selec = 0;
    for(new i=0; i < MAX_SLOT_VEH; i++) 
    {
        if(pVeiculo[playerid][i][VehConectado] == false) continue;
        if(listitem != selec){
            selec++;
            continue;
        }
        if(!IsVehicleInRangeOfPoint(pVeiculo[playerid][i][MeuVeiculoID], 60.0, 317.5602, -40.2021, 1.5781)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está perto da mecânica");
        if(VerificarMBlock(GetVehicleModel(pVeiculo[playerid][i][VehConectado]))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse veículo não está liberado para ser usado na mecânica!");

        new Mensagem[128];
        JogadorM[playerid][Alistou] = true;
        JogadorM[playerid][VeiculoCl] = pVeiculo[playerid][i][MeuVeiculoID];
        JogadorM[playerid][SlotCl] = i;
        JogadorM[playerid][TimerID] = SetTimerEx("MecanicaVerificador", 3000, true, "ddd", playerid, JogadorM[playerid][VeiculoCl], i);
        format(Mensagem, sizeof(Mensagem), "| MECÂNICA | O(A) Jogador(a) {FF8C00}%s[%d]{FFFFFF} está aguardando um atendimento", PegarNick(playerid), playerid);
        for(new p=0; p < MAX_PLAYERS; p++)
        {
            if(!IsPlayerConnected(p)) continue;
            if(Jogador[p][Logado] == false) continue;
            if(strcmp(Jogador[p][Profissao], "Mecanico")) continue;
            SendClientMessage(p, -1, Mensagem);
        }
        SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você entrou na lista de espera, não saia do local!");
        JogadorM[playerid][DelayAlistament] = gettime()+60;
        break;
    }
    return 0;
}

Dialog:CancelamentoMec(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(JogadorM[playerid][DelayAlistament] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa aguardar para cancelar");
    JogadorM[playerid][Alistou] = false;
    JogadorM[playerid][DelayAlistament] = gettime()+60;
    KillTimer(JogadorM[playerid][TimerID]);
    SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você cancelou seu pedido com sucesso!");
    return 0;
} 
 