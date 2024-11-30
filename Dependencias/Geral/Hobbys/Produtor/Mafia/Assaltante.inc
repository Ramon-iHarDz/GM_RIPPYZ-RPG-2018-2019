#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "TempoMochila") > 0) KillTimer(GetPVarInt(playerid, "TimerCaixa"));
    return 1;
}

hook OnPlayerPreso(playerid, pm){
    if(GetPVarInt(playerid, "TempoMochila") > 0){
        KillTimer(GetPVarInt(playerid, "TimerCaixa"));
        SetPVarInt(playerid, "TempoMochila", 0);
        OcultarTempoRoubo(playerid);
        RemovePlayerAttachedObject(playerid, 7);
    }
    return 1;
}

function AtualizarRelogioAssalto(playerid){
    SetPVarInt(playerid, "TempoMochila", GetPVarInt(playerid, "TempoMochila")-1);
    PlayerTextDrawSetString(playerid, RouboDraw[playerid][1], ConverterTexto(SegundosParaMinutosEx(GetPVarInt(playerid, "TempoMochila"))));
    if(GetPVarInt(playerid, "TempoMochila") > 0) return 1;
    new mny = random(9000-7000)+7000,
        Mensagem[128];
    OcultarTempoRoubo(playerid);
    KillTimer(GetPVarInt(playerid, "TimerCaixa"));
    RemovePlayerAttachedObject(playerid, 7);
    Jogador[playerid][Dinheiro] += mny;
    format(Mensagem, sizeof(Mensagem), "| INFO | Você recebeu R$%s pelo assalto do caixa eletrônico", DinheiroSeparar(mny));
    SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
    return 1;
}

function ExplosaoCaixaEp1(playerid){
    new id = GetPVarInt(playerid, "CaixaCacete"),
        Float:PPrta[2];
    if(pCaixa[id][Explodido] > 0) return 1;
    UpdateDynamic3DTextLabelText(pCaixa[id][CaixaTexto], 0xFFA500FF, "Caixa Eletrônico\n{FFFFFF}Você não pode usar esse caixa");
    SetPVarInt(playerid, "BlockCmansdasdsa", 0);
    ClearAnimations(playerid, 1);
    pCaixa[id][Explodido] = 1;
    Jogador[playerid][Dinamites]--;
    pTempo[playerid][RoubarCaixa] = gettime()+1800;
    PPrta[0] = pCaixa[id][PosicaoX];
    PPrta[1] = pCaixa[id][PosicaoY];
    GetXY(PPrta[0], PPrta[1], pCaixa[id][PosicaoRZ], 0.6, 0.0);
    pCaixa[id][BombaCaixaID] = CreateDynamicObject(1654, PPrta[0], PPrta[1], pCaixa[id][PosicaoZ]-0.5, 0.0, 0.0, float(random(360)), pCaixa[id][CaixaVW], pCaixa[id][CaixaInterior], -1, 50.0, 50.0, -1);
    SetTimerEx("ExplosaoCaixaEp2", 8000, false, "d", id);
    return 1;
}

function ExplosaoCaixaEp2(id){
    //UpdateDynamic3DTextLabelText(pCaixa[id][CaixaTexto], 0xFFA500FF, "Caixa Eletrônico\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} pegar a maleta com dinheiro");
    DestroyDynamicObjectEx(pCaixa[id][CaixaObjeto]);
    DestroyDynamicObjectEx(pCaixa[id][BombaCaixaID]);
    CreateExplosion(pCaixa[id][PosicaoX], pCaixa[id][PosicaoY], pCaixa[id][PosicaoZ], 7, 0.5);
    pCaixa[id][CaixaObjeto] = CreateDynamicObject(2943, pCaixa[id][PosicaoX], pCaixa[id][PosicaoY], pCaixa[id][PosicaoZ], pCaixa[id][PosicaoRX], pCaixa[id][PosicaoRY], pCaixa[id][PosicaoRZ], pCaixa[id][CaixaVW], pCaixa[id][CaixaInterior], -1, 150.0, 150.0, -1, 0);

    // Colocar Mochila com Dinheiro
    new Float:PPrta[2];
    PPrta[0] = pCaixa[id][PosicaoX];
    PPrta[1] = pCaixa[id][PosicaoY];
    GetXY(PPrta[0], PPrta[1], pCaixa[id][PosicaoRZ], 1.0, 0.0);
    pCaixa[id][BombaCaixaID] = CreateDynamicObject(11745, PPrta[0], PPrta[1], pCaixa[id][PosicaoZ]-0.5, 0.0, 0.0, float(random(360)), pCaixa[id][CaixaVW], pCaixa[id][CaixaInterior], -1, 50.0, 50.0, -1);
    pCaixa[id][BombaTextoID] = CreateDynamic3DTextLabel("Mochila com Dinheiro\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} pegar a maleta com dinheiro", 0x32CD32FF, PPrta[0], PPrta[1], pCaixa[id][PosicaoZ]-0.5, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, pCaixa[id][CaixaVW], pCaixa[id][CaixaInterior], -1, 16.0, -1);
    pCaixa[id][Explodido] = 2;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys){
    if(newkeys != KEY_YES) return 1;
    for(new i=0; i < MAX_CAIXAS; i++)
    {
        if(pCaixa[i][Conectado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ])) continue;
        if(GetPlayerInterior(playerid) != pCaixa[i][CaixaInterior] || GetPlayerVirtualWorld(playerid) != pCaixa[i][CaixaVW]) return 1;
        if(pCaixa[i][Explodido] < 1 || pCaixa[i][Explodido] == 3) return 1;
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está a pé");
        if(GetPVarInt(playerid, "TempoMochila") > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está segurando uma mochila");
        pCaixa[i][Explodido] = 3;
        Jogador[playerid][Estrelas] += 4;

        SetTimerEx("RecuperarCaixa", 600000, false, "d", i);

        DestroyDynamicObjectEx(pCaixa[i][BombaCaixaID]);
        DestroyDynamic3DTextLabelEx(pCaixa[i][BombaTextoID]);
        SetPlayerAttachedObject(playerid, 7, 11745, 1, 0.0729, -0.1270, -0.0079, 77.5999, 159.6999, 29.3999, 0.8590, 0.7560, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
        MostrarTempoRoubo(playerid);

        SetPVarInt(playerid, "TempoMochila", 300);
        new id = SetTimerEx("AtualizarRelogioAssalto", 1000, true, "d", playerid);
        SetPVarInt(playerid, "TimerCaixa", id);
        break;
    }
    return 1;
}

CMD:assaltarcaixa(playerid)
{
    if(Jogador[playerid][Level] < 15) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa ser level 15 para assaltar");
    if(pTempo[playerid][RoubarCaixa] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode roubar, aguarde");
    if(Jogador[playerid][Dinamites] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinamites");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está a pé");  

    new bool:Perrr = false;
    for(new i=0; i < MAX_CAIXAS; i++)
    {
        if(pCaixa[i][Conectado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ])) continue;
        if(GetPlayerInterior(playerid) != pCaixa[i][CaixaInterior] || GetPlayerVirtualWorld(playerid) != pCaixa[i][CaixaVW]) break;
        if(pCaixa[i][Explodido] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode assaltar esse caixa");
        if(GetPVarInt(playerid, "BlockCmansdasdsa") == 1) return 1;
        SetPVarInt(playerid, "BlockCmansdasdsa", 1);

        Jogador[playerid][Estrelas] += 6;

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| CENTRAL | %s[%d] está explodindo um caixa na região de %s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
        for(new d=0; d < MAX_PLAYERS; d++)
        {
            if(!IsPlayerConnected(d)) continue;
            if(Jogador[d][Logado] == false) continue;
            if(!IsPolicia(d)) continue;
            if(pPolicia[d][PegouUniformePolicia] == false) continue;
            if(GetPVarInt(d, "EventoJogador") > 0) continue;
            SendClientMessage(d, 0x4682B4FF, Mensagem);
        }

        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 1, 0);
        SetPVarInt(playerid, "CaixaCacete", i);
        CriarProgresso(playerid, "Colocando Bomba, aguarde.", "ExplosaoCaixaEp1", 30); 
        Perrr = true;
        break;
    }
    if(Perrr == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de um caixa eletrônico");
    return 1;
}

CMD:assaltar(playerid, params[])
{
    if(Jogador[playerid][Level] < 30) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode assaltar no level 30");
    if(pTempo[playerid][RoubarJogador] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode roubar, aguarde");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Assaltar [id]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se roubar");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode assaltar um admin");
    
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT){
        if(GetPlayerVehicleID(id) != GetPlayerVehicleID(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está a pé");
    }

    new weaponid = GetPlayerWeapon(playerid);
    if(weaponid == 0 || weaponid == 10 || weaponid == 11 || weaponid == 12 || weaponid == 13 || weaponid == 14
    || weaponid == 16 || weaponid == 17 || weaponid == 43 || weaponid == 42 || weaponid == 41) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está segurando uma arma");

    if(Jogador[id][Dinheiro] < 700) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não tem dinheiro");
    if(GetPVarInt(playerid, "RbbDl") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) ainda não pode ser roubado(a)");
    SetPVarInt(playerid, "RbbDl", gettime()+30);

    new Mensagem[128],
        Kois = random(700-500)+500;

    Jogador[playerid][Estrelas] += 6;
    pTempo[playerid][RoubarJogador] = gettime()+240;
    format(Mensagem, sizeof(Mensagem), "| ASSALTO | %s[%d] acabou de assaltar R$%s de você", PegarNick(playerid), playerid, DinheiroSeparar(Kois));
    SendClientMessage(id, 0xFFFF00FF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ASSALTO | Você roubou R$%s do(a) jogador(a) %s[%d]", DinheiroSeparar(Kois), PegarNick(id), id);
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
    format(Mensagem, sizeof(Mensagem), "~g~%d~w~+", Kois);
    GameTextForPlayer(id, ConverterTexto(Mensagem), 3000, 4);
    format(Mensagem, sizeof(Mensagem), "~y~Assaltado(a)~n~~r~%d~w~-", Kois);
    GameTextForPlayer(id, ConverterTexto(Mensagem), 3000, 4); 
    return 1;
}
