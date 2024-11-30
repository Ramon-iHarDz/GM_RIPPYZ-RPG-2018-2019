#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    if(pAssaltante[playerid][RoubandoCaixa] > 0) KillTimer(pAssaltante[playerid][TempoRoubo]);
    if(pAssaltante[playerid][RoubandoCaixa] == 2) DestroyDynamicObjectEx(pAssaltante[playerid][C4Dinamite]);

    if(pAssaltante[playerid][AssaltandoCF] == 3) RemovePlayerAttachedObject(playerid, 9);
    if(pAssaltante[playerid][AssaltandoCF] == 2) DestroyDynamic3DTextLabelEx(pAssaltante[playerid][RouboCF]);
    if(pAssaltante[playerid][AssaltandoCF] == 1)
    {
        new id = pAssaltante[playerid][AssaltandoID]; 
        KillTimer(pAssaltante[playerid][CFAssaltoTempo]);
        SetPVarInt(id, "AntiAssaltoCF", gettime()+120);

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| ASSALTO | O(A) Assaltante %s saiu do servidor e o assalto foi cancelado", PegarNick(playerid));
        SendClientMessage(id, 0xFF8C00FF, Mensagem);
    }

    DestroyDynamicCPEx(pAssaltante[playerid][RouboCFCP]);
    DestroyDynamicMapIconEx(pAssaltante[playerid][RouboCFIC]);

    new FullFdss[JogadorAssaltante];
    pAssaltante[playerid] = FullFdss;
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pAssaltante[playerid][RouboCFCP]) return 1;
    
    new Vlr = random(3500-2000)+2000,
        Mensagem[128];
    pAssaltante[playerid][AssaltandoCF] = 0;
    RemovePlayerAttachedObject(playerid, 9);

    DestroyDynamicCPEx(pAssaltante[playerid][RouboCFCP]);
    DestroyDynamicMapIconEx(pAssaltante[playerid][RouboCFIC]);
    Jogador[playerid][Dinheiro] += Vlr;
    format(Mensagem, sizeof(Mensagem), "| ASSALTO | Você entregou a carga roubada e recebeu {32CD32}$%s", DinheiroSeparar(Vlr));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(pAssaltante[playerid][AssaltandoCF] != 2) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        
        // Veículo
        if(AtrasVeiculo(playerid, pAssaltante[playerid][AssaltandoCFID], 2.0))
        {
            SetPlayerAttachedObject(playerid, 9, 11745, 1, 0.0729, -0.1270, -0.0079, 77.5999, 159.6999, 29.3999, 0.8590, 0.7560, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
            pAssaltante[playerid][RouboCFCP] = CreateDynamicCP(-2816.8816,-1582.1282,141.3576, 1.0, 0, 0, playerid, 50.0, -1);
            pAssaltante[playerid][RouboCFIC] = CreateDynamicMapIcon(-2816.8816,-1582.1282,141.3576, 19, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
            pAssaltante[playerid][AssaltandoCF] = 3;
            DestroyDynamic3DTextLabelEx(pAssaltante[playerid][RouboCF]);
        }
    }
    return 1;
}

function AssaltoCaixa(playerid)
{
    Jogador[playerid][Dinamites] -= 1;
    pAssaltante[playerid][RoubandoCaixa] = 2;
    pTempo[playerid][RoubarCaixa] = gettime()+240; 
    pAssaltante[playerid][C4Dinamite] = CreateDynamicObject(1654, pAssaltante[playerid][Expp][0], pAssaltante[playerid][Expp][1], pAssaltante[playerid][Expp][2]-1, 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0, -1);
    ClearAnimations(playerid);
    pAssaltante[playerid][TempoRoubo] = SetTimerEx("BombaPlantada", 8000, false, "d", playerid);
    SendClientMessage(playerid, 0x32CD32FF, "| BOMBA | Você plantou uma bomba no caixa, aguarde e saia de perto!");
    return 1; 
}

function BombaPlantada(playerid)
{
    pAssaltante[playerid][RoubandoCaixa] = 0;
    DestroyDynamicObjectEx(pAssaltante[playerid][C4Dinamite]);
    if(random(100) > 50) return SendClientMessage(playerid, 0xFF4500FF, "| BOMBA | Dinamite falhou, tente novamente!");
    
    
    
    Jogador[playerid][Estrelas] += 5;
    CreateExplosion(pAssaltante[playerid][Expp][0], pAssaltante[playerid][Expp][1], pAssaltante[playerid][Expp][2], 12, 40);
    new Mensagem[228],
        Kjos = random(2100-1800)+1800;

    format(Mensagem, sizeof(Mensagem), "| CENTRAL | %s[%d] explodiu um caixa eletrônico localizado em %s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(!IsPolicia(i)) continue;
        if(pPolicia[i][PegouUniformePolicia] == false) continue;
        if(GetPVarInt(i, "EventoJogador") > 0) continue;
        SendClientMessage(i, 0x4682B4FF, Mensagem);
    }

    Jogador[playerid][Dinheiro] += Kjos;
    format(Mensagem, sizeof(Mensagem), "| ROUBO | Você roubou esse caixa eletrônico e recebeu {32CD32}$%s", DinheiroSeparar(Kjos));
    SendClientMessage(playerid, -1, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| CENTRAL | Atenção todas as unidades. Um caixa eletrônico foi roubado na região de %s suspeito(a) %s[%d]", GetPlayerZone(playerid), PegarNick(playerid), playerid);
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(!IsPolicia(i)) continue;
        if(pPolicia[i][PegouUniformePolicia] == false) continue;
        SendClientMessage(i, 0x4682B4FF, Mensagem);
    }
    return 1;
}

CMD:assaltarcaixa(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Assaltante") && strcmp(Jogador[playerid][Profissao], "Terrorista")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando!");
    if(pTempo[playerid][RoubarCaixa] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode roubar, aguarde");
    if(Jogador[playerid][Dinamites] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinamites, vá até sua HQ para comprar");
    if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode roubar agora");
    if(pAssaltante[playerid][RoubandoCaixa] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está assaltando, aguarde.");

    new bool:Perrr = false;
    for(new i=0; i < MAX_CAIXAS; i++)
    {
        if(pCaixa[i][Conectado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ])) continue;
        pAssaltante[playerid][TempoRoubo] = SetTimerEx("AssaltoCaixa", 3000, false, "d", playerid);
        
        GetPlayerPos(playerid, pAssaltante[playerid][Expp][0], pAssaltante[playerid][Expp][1], pAssaltante[playerid][Expp][2]);

        pAssaltante[playerid][CaixaAsst] = i;
        pAssaltante[playerid][RoubandoCaixa] = 1;
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 1, 0);
        SendClientMessage(playerid, 0xFFFF00FF, "| ASSALTO | Você está colocando uma dinamite");
        Perrr = true;
        break;
    }
    if(Perrr == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de um caixa eletrônico");
    return 1;
}

CMD:assaltar(playerid, params[])
{
    if(strcmp(Jogador[playerid][Profissao], "Assaltante") && strcmp(Jogador[playerid][Profissao], "Terrorista")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando!");
    if(pTempo[playerid][RoubarJogador] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode roubar, aguarde");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Assaltar [id]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se roubar!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode assaltar um admin");
    if(Jogador[id][Dinheiro] < 700) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não tem dinheiro");
    if(GetPVarInt(playerid, "RbbDl") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) ainda não pode ser roubado(a)");
    SetPVarInt(playerid, "RbbDl", gettime()+30);

    new Mensagem[128],
        Kois = random(700-500)+500;

    Jogador[playerid][Estrelas] += 6;
    pTempo[playerid][RoubarJogador] = gettime()+240;
    format(Mensagem, sizeof(Mensagem), "| ASSALTO | %s[%d] acabou de assaltar $%s de você", PegarNick(playerid), playerid, DinheiroSeparar(Kois));
    SendClientMessage(id, 0xFFFF00FF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ASSALTO | Você roubou $%s do(a) jogador(a) %s[%d]", DinheiroSeparar(Kois), PegarNick(id), id);
    SendClientMessage(playerid, 0xFFFF00FF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| CENTRAL | %s[%d] acabou de efetuar um roubo na região de %s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(!IsPolicia(i)) continue;
        if(pPolicia[i][PegouUniformePolicia] == false) continue;
        if(GetPVarInt(i, "EventoJogador") > 0) continue;
        SendClientMessage(i, 0x4682B4FF, Mensagem);
    }


    Jogador[playerid][Dinheiro] += Kois;
    Jogador[id][Dinheiro] -= Kois;

    GameTextForPlayer(id, ConverterTexto("~r~Assaltado(a)"), 3000, 4);
    format(Mensagem, sizeof(Mensagem), "~g~%d~w~+", Kois);
    GameTextForPlayer(playerid, ConverterTexto(Mensagem), 3000, 4); 
    format(Mensagem, sizeof(Mensagem), "~r~%d~w~-", Kois);
    GameTextForPlayer(id, ConverterTexto(Mensagem), 3000, 4); 
    return 1;
}

/*CMD:assaltarcarroforte(playerid, params[])
{
    if(strcmp(Jogador[playerid][Profissao], "Assaltante")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando!");
    if(pTempo[playerid][RoubarCarroForte] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando agora, aguarde.");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /AssaltarCarroForte [id]");
    if(GetPVarInt(id, "Carff") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está transportando uma carga");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 6) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está longe desse(a) jogador(a)");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa estar a pé para assaltar");
    if(VerificarPertoCaixa(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode roubar esse(a) jogador(a) neste local");
    EnviarAssaltoCF(id);
    
    new Mensagem[128],
        vlars = random(3000-1500)+1500;

    Jogador[playerid][Dinheiro] += vlars;
    Jogador[playerid][Estrelas] += 5;
    pTempo[playerid][RoubarCarroForte] = gettime()+600;

    format(Mensagem, sizeof(Mensagem), "+~g~$%s", DinheiroSeparar(vlars));
    GameTextForPlayer(playerid, ConverterTexto(Mensagem), 4000, 4);
    GameTextForPlayer(id, ConverterTexto("~r~Assaltado(a)"), 4000, 4);
    return 1;
}*/