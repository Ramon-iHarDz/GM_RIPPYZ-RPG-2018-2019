#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicPickup(1239, 1, -1656.3829,1217.9264,7.2500, 0, 0, -1, 120.0, -1);
    CreateDynamic3DTextLabel("Transferência{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para usar", 0x00FF00FF, -1656.3829,1217.9264,7.2500, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 17.0, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, -1656.3829,1217.9264,7.2500)) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;

    new Dialog[700];
    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0)
        {
            if(pVeiculo[playerid][i][VehConectado] == true) strcatEx(Dialog, "%d.\t%s\t{00FF00}Conectado\n", i+1, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
            else strcatEx(Dialog, "%d.\t%s\t{FF0000}Deconectado\n", i+1, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
        }
        else strcatEx(Dialog, "%d.\t{FF0000}Nenhum Veículo\t{FF0000}N/A\n", i+1); 
    }
    Dialog_Show(playerid, RevendaLoc, DIALOG_STYLE_TABLIST, "{00FF00}Transferência", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:RevendaLoc(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = listitem;
    if(pVeiculo[playerid][id][MeuVeiculoModelo] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há nenhum veículo nesse slot");
    if(pVeiculo[playerid][id][VehConectado] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo está conectado");
    SetPVarInt(playerid, "Kapalsd", id);

    Dialog_Show(playerid, RevendaID, DIALOG_STYLE_INPUT, "{00FF00}ID", "Coloque o ID do(a) jogador(a) abaixo", "Confirmar", "Fechar");
    return 1;
}

Dialog:SelecionarPrecoRev(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque apenas números");
    if(id > 20000000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode colocar todo esse valor");

    SetPVarInt(playerid, "RevendaPreccco", 1);
    SetPVarInt(playerid, "RevandaValor", id);
    Dialog_Show(playerid, RevendaID, DIALOG_STYLE_INPUT, "{00FF00}ID", "Coloque o ID do(a) jogador(a) abaixo", "Confirmar", "Fechar");
    return 1;
}

Dialog:RevendaID(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) ID Inválido");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está logado(a)");
    if(!VagaGaragem(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não possui vagas na garagem");
    if(!IsPlayerInRangeOfPoint(id, 20.0, -1656.3829,1217.9264,7.2500)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) não está no local/perto de você");
    
    if(GetPVarInt(playerid, "RevendaPreccco") == 1){
        if(Jogador[id][Dinheiro] < GetPVarInt(playerid, "RevandaValor")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) não tem dinheiro suficiente");
    }
    
    SetPVarInt(playerid, "TrnasfIDCVar", id);
    Dialog_Show(playerid, RevendaConfirm, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", "Você realmente deseja transferir seu veículo?", "Confirmar", "Cancelar");
    return 1;
}

Dialog:RevendaConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new vh = GetPVarInt(playerid, "Kapalsd"),
        id = GetPVarInt(playerid, "TrnasfIDCVar"),
        Enviar[128];
    if(!VagaGaragem(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não possui vagas na garagem");

    SetPVarInt(id, "IdRevend", playerid);
    SetPVarInt(playerid, "IdRevend", id);

    if(GetPVarInt(playerid, "RevendaPreccco") == 1) format(Enviar, sizeof(Enviar), "%s[%d] está transferindo o veículo modelo %s para seu nome por $%s, deseja aceitar?", PegarNick(playerid), playerid, GetVehicleNameByModel(pVeiculo[playerid][vh][MeuVeiculoModelo]), DinheiroSeparar(GetPVarInt(playerid, "RevandaValor")));
    else format(Enviar, sizeof(Enviar), "%s[%d] está transferindo o veículo modelo %s para seu nome, deseja aceitar?", PegarNick(playerid), playerid, GetVehicleNameByModel(pVeiculo[playerid][vh][MeuVeiculoModelo]));
    Dialog_Show(id, AceitarRevenda, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", Enviar, "Confirmar", "Cancelar");
    return 1;
}

Dialog:AceitarRevenda(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new aai =  GetPVarInt(playerid, "IdRevend");
    new vh = GetPVarInt(aai, "Kapalsd"),
        id = GetPVarInt(aai, "TrnasfIDCVar"),
        Enviar[128];
    if(!VagaGaragem(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não possui vagas na garagem");

    new did = VagaSlotGaragem(id);
    format(Enviar, sizeof(Enviar), "UPDATE `veiculos` SET `Nome` = '%s', `Slot` = %d WHERE `Nome` = '%s' AND `Slot` = %d", EscapeString(PegarNick(id)), did, EscapeString(PegarNick(aai)), vh);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema na consulta");

    format(Enviar, sizeof(Enviar), "UPDATE `portamalas` SET `Nome` = '%s', `Slot` = %d WHERE `Nome` = '%s' AND `Slot` = %d", EscapeString(PegarNick(id)), did, EscapeString(PegarNick(aai)), vh);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema na consulta [0x1]");

    format(Enviar, sizeof(Enviar), "UPDATE `tunagens` SET `Nome` = '%s', `Slot` = %d WHERE `Nome` = '%s' AND `Slot` = %d", EscapeString(PegarNick(id)), did, EscapeString(PegarNick(aai)), vh);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema na consulta [0x2]");

    if(GetPVarInt(aai, "RevendaPreccco") == 1){
        Jogador[playerid][Dinheiro] += GetPVarInt(aai, "RevandaValor");
        Jogador[aai][Dinheiro] -= GetPVarInt(aai, "RevandaValor");
    }

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| TRANSFERÊNCIA | Você transferiu seu veículo %s para %s[%d]", GetVehicleNameByModel(pVeiculo[aai][vh][MeuVeiculoModelo]), PegarNick(id), id);
    SendClientMessage(aai, 0xFFFF00FF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| TRANSFERÊNCIA | %s[%d] transferiu o veículo %s para seu nome", PegarNick(aai), aai, GetVehicleNameByModel(pVeiculo[aai][vh][MeuVeiculoModelo]));
    SendClientMessage(id, 0xFFFF00FF, Mensagem);
    
    pVeiculo[id][did] = pVeiculo[aai][vh];
    new sadasdas[TuningVehh];
    for(new i=0; i < 18; i++){
        pTunagem[id][did][i] = pTunagem[aai][vh][i];
        pTunagem[aai][vh][i] = sadasdas;
    }
    new sadas[PlayerVeiculoInfo];
    pVeiculo[aai][vh] = sadas;
    return 1;
}