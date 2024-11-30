#include <YSI_Coding\y_hooks>

CMD:sim(playerid)
{
    if(GetPVarInt(playerid, "PedidoCasamento") == 0) return 0;
    SetPVarInt(playerid, "PedidoCasamento", 0);
    new id = GetPVarInt(playerid, "PedidoID"),
        Mensagem[110];

    format(Mensagem, sizeof(Mensagem), "| MENSAGEM | %s Fico muito feliz que você aceitou meu pedido <3", PegarNick(id));
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| MOTORISTA | Olá %s, estou levando você até o local", PegarNick(playerid));
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);

    SendClientMessage(id, 0xFFA500FF, "| MOTORISTA | Estou levando ela até você, ela está bem nervosa");
    return 1;
}

CMD:nao(playerid)
{
    if(GetPVarInt(playerid, "PedidoCasamento") == 0) return 0;
    SetPVarInt(playerid, "PedidoCasamento", 0);
    SendClientMessage(playerid, 0xFFA500FF, "| PEDIDO | Você recusou o pedido.");
    return 1;
}

CMD:pedircasamento(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new id, Pedido[90];
    if(sscanf(params, "ds[90]", id, Pedido)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /PedirCasamento [ID] [Pedido]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está logado(a)");
    if(GetPVarInt(id, "PedidoCasamento") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já fez o pedido, aguarde.");
    
    SetPVarInt(id, "PedidoCasamento", 1);
    SetPVarInt(id, "PedidoID", playerid);

    new Mensagem[200];
    format(Mensagem, sizeof(Mensagem), "| PEDIDO | %s: %s ( /Sim ou /Não )", PegarNick(playerid), Pedido);
    SendClientMessage(id, 0xFFA500FF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| PEDIDO | Você enviou um pedido para %s ( %s )", PegarNick(id), Pedido);
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);
    return 1;
}

CMD:ircasamento(playerid)
{
    if(Jogador[playerid][Admin] < 6) return 0;
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 1887);
    SetPlayerPos(playerid, 2226.7107,-1333.9360,24.1686);
    return 1;
}

CMD:iniciarmusica(playerid)
{
    if(Jogador[playerid][Admin] < 6) return 0;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPlayerInterior(i) != 0) continue;
        if(GetPlayerVirtualWorld(i) != 1887) continue;
        if(!IsPlayerInRangeOfPoint(i, 200.0, 2226.7107,-1333.9360,24.1686)) continue;
        PlayAudioStreamForPlayer(i, "https://www.dropbox.com/s/7hi4e13bnu17bzz/Aceita.mp3?dl=1", 2226.7107,-1333.9360,24.1686, 100.0, 1);
    }
    //Kick(npcid);
    //DestroyVehicleEx(Limousine);
    return 1;
}