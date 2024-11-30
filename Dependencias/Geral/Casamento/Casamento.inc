#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Igreja{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para interagir", 0xFFFF00FF, 2233.5569,-1333.3303,23.9816, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1314, 1, 2233.5569,-1333.3303,23.9816, 0, 0, -1, 90.0, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, 2233.5569,-1333.3303,23.9816)) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(!strcmp(Jogador[playerid][Casado], "*"))
        {
            Dialog_Show(playerid, CasamentoID, DIALOG_STYLE_INPUT, "{FF0000}Casamento", "Coloque abaixo o ID do(a) jogador(a)", "Enviar", "Fechar");
            return 1;
        }
        Dialog_Show(playerid, CasamentoDivorcio, DIALOG_STYLE_TABLIST, "{FF0000}Divórcio", "Você realmente deseja se divórciar?", "Confirmar", "Fechar");

        
    }
    return 1;
}

Dialog:CasamentoDivorcio(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[260];
    strcatEx(Enviar, "UPDATE `rippzyrpg` SET `Casado` = '*' WHERE `Casado` = '%s'; ", EscapeString(PegarNick(playerid)));
    strcatEx(Enviar, "UPDATE `rippzyrpg` SET `Casado` = '*' WHERE `Casado` = '%s'", EscapeString(Jogador[playerid][Casado]));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar seu casamento");
    format(Jogador[playerid][Casado], 30, "*");
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Casado], PegarNick(playerid))) continue;
        format(Jogador[i][Casado], 30, "*");
    }
    SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você está solteiro(a)");
    return 1;
}

Dialog:CasamentoID(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode colocar esse ID");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar em si mesmo");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");

    new Mensagem[90];
    if(strcmp(Jogador[id][Casado], "*")){
        format(Mensagem, sizeof(Mensagem), "| IGREJA | Esse(a) jogador(a) está casado(a) com %s", Jogador[id][Casado]);
        SendClientMessage(playerid, 0xFF4500FF, Mensagem);
        return 1;
    }
    if(!IsPlayerInRangeOfPoint(id, 20.0, 2233.5569,-1333.3303,23.9816)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está na igreja");

    format(Mensagem, sizeof(Mensagem), "Você aceita casar com o(a) %s?", PegarNick(playerid));

    SetPVarInt(playerid, "CasamentoID", id);
    SetPVarInt(id, "CasamentoID", playerid);
    Dialog_Show(id, CasamentoQuery, DIALOG_STYLE_MSGBOX, "{FF0000}Padre", Mensagem, "Sim", "Não");
    return 1;
}

Dialog:CasamentoQuery(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "CasamentoID"),
        Query[268];
    strcatEx(Query, "UPDATE `rippzyrpg` SET `Casado` = '%s' WHERE `Nome` = '%s';", EscapeString(PegarNick(id)), EscapeString(PegarNick(playerid)));
    strcatEx(Query, "UPDATE `rippzyrpg` SET `Casado` = '%s' WHERE `Nome` = '%s';", EscapeString(PegarNick(playerid)), EscapeString(PegarNick(id)));
    mysql_query(IDConexao, Query, false);

    format(Jogador[id][Casado], 30, PegarNick(playerid));
    format(Jogador[playerid][Casado], 30, PegarNick(id));

    format(Query, sizeof(Query), "| IGREJA | O(A) Jogador(a) %s[%d] casou com %s[%d]", PegarNick(id), id, PegarNick(playerid), playerid);
    SendClientMessageToAll(0xFFFF00FF, Query);
    return 1;
}