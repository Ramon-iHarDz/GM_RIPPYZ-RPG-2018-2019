#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    // CreateDynamicPickup(1009, 1, 1579.6575,-1634.7493,13.5621, 0, 0, -1, 30.0);
    //CreateDynamic3DTextLabel("{00BFFF}Veículos\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para visualizar a lista", -1, 1579.6575,-1634.7493,13.5621, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);
    CreateDynamic3DTextLabel("{00BFFF}Armário{FFFFFF}\nComandos:\n{CCCCCC}/Uniforme{FFFFFF} - Para pegar uma farda\n{CCCCCC}/Equipamentos{FFFFFF} - Para se equipar", -1, 218.5183,70.9667,1005.0391, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 1300, 6, -1, 25.0);
    
    CreateDynamicPickup(1239, 1, 1568.6171,-1690.0969,6.2188, 0, 0, -1, 30.0);
    CreateDynamicPickup(1239, 1, 1564.9625,-1666.5808,28.3956, 0, 0, -1, 30.0);
    CreateDynamic3DTextLabel("{FFFF00}Departamento\n{FFFFFF}Aperte {CCCCCC}'F'{FFFFFF} para subir", -1, 1568.6171,-1690.0969,6.2188, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1);
    CreateDynamic3DTextLabel("{FFFF00}Departamento\n{FFFFFF}Aperte {CCCCCC}'F'{FFFFFF} para descer", -1, 1564.9625,-1666.5808,28.3956, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pAbordado[playerid][Algemado] == true || pAbordado[playerid][Acompanhando] == true || pAbordado[playerid][Abordado] == true) KillTimer(pAbordado[playerid][TempoAbordado]);
    
    new Mensagem[128];
    if(pAbordado[playerid][Acompanhando] == true || pAbordado[playerid][SeRendeu] == true || pAbordado[playerid][Algemado] == true){
        KillTimer(pAbordado[playerid][TempoAbordado]);
    }

    if(pAbordado[playerid][Algemado] == true){
        format(Mensagem, sizeof(Mensagem), "| JUIZ | O(A) %s foi penalizado(a) por sair do servidor algemado(a)", PegarNick(playerid));
        SendClientMessageToAll(0x1E90FFFF, Mensagem);
        CatalogarPrisao(playerid, 60, "Sair do servidor algemado(a)", "Isabella", 0);
    }
    else if(pAbordado[playerid][Acompanhando] == true){
        format(Mensagem, sizeof(Mensagem), "| JUIZ | O(A) %s foi penalizado(a) por sair do servidor em acompanhamento", PegarNick(playerid));
        SendClientMessageToAll(0x1E90FFFF, Mensagem);
        CatalogarPrisao(playerid, 60, "Sair do servidor acompanhamento", "Isabella", 0);
    }
    else if(pAbordado[playerid][Abordado] == true){
        format(Mensagem, sizeof(Mensagem), "| JUIZ | O(A) %s foi penalizado(a) por sair do servidor abordado(a)", PegarNick(playerid));
        SendClientMessageToAll(0x1E90FFFF, Mensagem);
        CatalogarPrisao(playerid, 60, "Sair do servidor abordado(a)", "Isabella", 0);
    }

    //Limpar Informações
    new Deletar[PegarVeiculoPMInfo];
    pVPolicia[playerid] = Deletar;
    
    new DeleCdsatar[AbordadoInfo];
    pAbordado[playerid] = DeleCdsatar;
    
    new Popo[PolicialInfo];
    pPolicia[playerid] = Popo;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && GetPlayerVirtualWorld(playerid) == 0)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1564.9625,-1666.5808,28.3956))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            SetPlayerPos(playerid, 1568.6171,-1690.0969,6.2188);
        } 
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 1568.6171,-1690.0969,6.2188))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            SetPlayerPos(playerid, 1564.9625,-1666.5808,28.3956);
        }
    }
    return 1;
}

CMD:algemar(playerid, params[])
{
    if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    if(!VerificarPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é um policial");
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Algemar [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se algemar");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não encontrado(a)");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar um admin");
    // if(pPolicia[playerid][UltimoPolicia] != pPolicia[playerid][PoliciaCarroID] && !UltimoVeiculoExercito(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é o seu alugado!");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar dentro de um veículo");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 7) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(GetPlayerVirtualWorld(id) != GetPlayerVirtualWorld(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está na mesma cidade que você");
    if(Jogador[id][Estrelas] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) não está procurado(a)");
    if(pAbordado[id][Algemado] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) já esta algemado(a)");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar um(a) jogador(a) dentro do veículo");
    if(GetPlayerState(id) == PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar o(a) jogador(a) dentro de um veículo");
    // if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar um admin");
    if(GetPVarInt(playerid, "DentroCofre") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar dentro do cofre");
    //if(pAbordado[id][Abordado] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador ainda não se rendeu");
    if(GetPVarInt(id, "Mochhila") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa matar(a) esse procurado(a)");

    if(pAbordado[id][Acompanhando] == true || pAbordado[id][SeRendeu] == true || pAbordado[id][Algemado] == true || pAbordado[id][Abordado] == true){
        if(pAbordado[id][Abordado] == true) OcultarAbordagem(id);
        KillTimer(pAbordado[id][TempoAbordado]);
    }

    /*if(pMorreu[id][EstaCaido] == true)
    {
        if(pMorreu[id][MorteStatus] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde o paramédico(a) efetuar os procedimentos!");
        RespawnarMorto(id, false);
    }*/

    if(DesligarChamada(id)){
        new cara = jTelefone[id][Ligando];
        new Amigor[128];
        format(Amigor, sizeof(Amigor), "| LIGAÇÃO | %s[%d] acabou sendo pego pela polícia", PegarNick(id), id);
        SendClientMessage(cara, 0xFF4500FF, Amigor);
    }

    new Mensagem[128];
    TogglePlayerControllable(id, 0);
    pAbordado[id][SeRendeu] = false;
    pAbordado[id][Abordado] = false;
    pAbordado[id][Acompanhando] = false;
    pAbordado[id][Algemado] = true;
    pAbordado[id][PmID] = playerid;
    pAbordado[id][APolicial] = playerid;

    new Float:FFL;
    if(GetPlayerHealth(id, FFL)){
        if(FFL < 15.0) SetPlayerHealth(id, 30.0);
    }

    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    SetPlayerSpecialAction(id, SPECIAL_ACTION_CUFFED);

    format(Mensagem, sizeof(Mensagem), "| AVISO | Você algemou o(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x1E90FFFF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| AVISO | Algemado(a) por %s[%d]", PegarNick(playerid), playerid);
    SendClientMessage(id, 0x1E90FFFF, Mensagem);
    pAbordado[id][TempoAbordado] = SetTimerEx("Desalgemar", 120000, false, "d", id);
    return 1;
}

CMD:abordar(playerid, params[])
{
    if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    if(!VerificarPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é um policial");
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Abordar [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se abordar");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não encontrado(a)");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode abordar um admin");
    //if(pPolicia[playerid][UltimoPolicia] != pPolicia[playerid][PoliciaCarroID] && !UltimoVeiculoExercito(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é o seu alugado");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 17) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(GetPVarInt(id, "AntiAbordagem") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode abordar esse(a) jogador(a), apenas algema-lo(a)");
    // if(pAbordado[id][PmID] != playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode prender esse(a) jogador(a)");
    if(GetPVarInt(playerid, "DentroCofre") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar dentro do cofre");
    if(GetPVarInt(id, "Mochhila") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa matar(a) esse procurado(a)");

    AbordarJogador(playerid, id);
    return 1;
}

CMD:prender(playerid, params[])
{
    if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    if(!VerificarPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é um policial");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Prender [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se prender");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não encontrado(a)");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode prender um admin");
    // if(pPolicia[playerid][UltimoPolicia] != pPolicia[playerid][PoliciaCarroID] && !UltimoVeiculoExercito(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é o seu alugado!");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar dentro de um veículo");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(GetPlayerVirtualWorld(id) != GetPlayerVirtualWorld(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está na mesma cidade que você");
    if(Jogador[id][Estrelas] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) não está procurado(a)");
    if(pAbordado[id][Algemado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) não está algemado(a)");
    if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode prender um admin");
    if(pAbordado[id][APolicial] != playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode prender esse jogador, aguarde o(a) policial que algemou");

    if(pAbordado[id][Abordado] == true) OcultarAbordagem(id);
    if(pAbordado[id][Acompanhando] == true || pAbordado[id][SeRendeu] == true || pAbordado[id][Algemado] == true){
        KillTimer(pAbordado[id][TempoAbordado]);
    }
    EnviarCadeia(id, playerid);
    return 1;
}

stock EnviarCadeia(playerid, policial)
{
    if(!VerificarPolicia(policial)) return 1;

    if(pAbordado[playerid][Abordado] == true) OcultarAbordagem(playerid);
    if(pAbordado[playerid][Acompanhando] == true || pAbordado[playerid][SeRendeu] == true || pAbordado[playerid][Algemado] == true){
        KillTimer(pAbordado[playerid][TempoAbordado]);
    }

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| POLÍCIA | O(A) Policial %s[%d] prendeu %s[%d]", PegarNick(policial), policial, PegarNick(playerid), playerid);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Corregedoria")) continue;
        SendClientMessage(i, 0x1E90FFFF, Mensagem);
    }

    CallRemoteFunction("OnPlayerPreso", "dd", playerid, policial);
    ResetPlayerWeapons(playerid); 

    new ValorEstrela = (120*Jogador[playerid][Estrelas]); 
    Jogador[policial][Dinheiro] += ValorEstrela;
    Jogador[policial][Prisoes]++;
    UparPolicia(policial);

    format(Mensagem, sizeof(Mensagem), "| CENTRAL | Você recebeu $%s por prender %s[%d] com %d estrela(s)", DinheiroSeparar(ValorEstrela), PegarNick(playerid), playerid, Jogador[playerid][Estrelas]);
    SendClientMessage(policial, 0x00BFFFFF, Mensagem);
    SendClientMessage(playerid, 0x00BFFFFF, "| PRISAO | Você foi preso(a)");
    
    Jogador[playerid][Preso] += TempoCadeiaMunicipal(playerid, Jogador[playerid][Estrelas]); 
    Jogador[playerid][CadeiaEstilo] = 1;
    Jogador[playerid][uInterior] = Departamento(playerid);
    Jogador[playerid][uInteriorEx] = 0;
    
    MostrarRelogioPrisao(playerid);
    CatalogarPrisao(playerid, Jogador[playerid][Estrelas], "Procurado(a)", PegarNick(policial), 1);
    ColocarNaCadeia(playerid);

    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    pAbordado[playerid][SeRendeu] = false;
    pAbordado[playerid][Algemado] = false;
    pAbordado[playerid][Abordado] = false; 
    pAbordado[playerid][Acompanhando] = false; 
    TogglePlayerControllable(playerid, 1);
    return 1;
}

CMD:r(playerid) 
{
    if(pAbordado[playerid][SeRendeu] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já se rendeu");
    if(pAbordado[playerid][Abordado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está abordado(a)");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se render em um veículo");
    KillTimer(pAbordado[playerid][TempoAbordado]);
    OcultarAbordagem(playerid);
    pAbordado[playerid][Abordado] = false;
    pAbordado[playerid][SeRendeu] = true;

    TogglePlayerControllable(playerid, 0); 

    ClearAnimations(playerid);
    ApplyAnimation(playerid, "ROB_BANK","SHP_HandsUp_Scr", 4.0, 0, 1, 1, 1, 0);

    new id = pAbordado[playerid][APolicial],
        Mensagem[128];

    format(Mensagem, sizeof(Mensagem), "| AVISO | O(A) Jogador(a) %s[%d] se rendeu", PegarNick(playerid), playerid);
    SendClientMessage(id, 0x00BFFFFF, Mensagem);
    SendClientMessage(playerid, 0x00BFFFFF, "| AVISO | Você se rendeu");
    pAbordado[playerid][TempoAbordado] = SetTimerEx("Desalgemar", 180000, false, "d", playerid);
    return 1;
}

/*CMD:console(playerid)
{
    if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    if(pPolicia[playerid][PegouVeiculoPolicia] == false && !UltimoVeiculoExercito(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem seu veículo polícia");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no seu veiculo polícia");
    if(GetPlayerVehicleID(playerid) != pPolicia[playerid][PoliciaCarroID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no seu veiculo policial");
    MostrarPainelPolicial(playerid);
    InformarPainelPM(playerid);
    return 1;
}*/

stock AbordarJogador(playerid, id)
{
    if(GetPlayerVirtualWorld(id) != GetPlayerVirtualWorld(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está na mesma cidade que você");
    if(GetPlayerState(id) == PLAYER_STATE_SPECTATING) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está na mesma cidade que você");
    // if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)")
    if(pAbordado[id][Algemado] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) está algemado(a)");
    if(pAbordado[id][Abordado] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) já está abordado(a)");
    if(pAbordado[id][SeRendeu] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) já está rendido(a)");
    if(pAbordado[id][Acompanhando] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) já está sendo acompanhado(a)");
    if(Jogador[id][Estrelas] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) não está procurado(a)");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar um admin");
    // if(pMorreu[id][EstaCaido] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode abordar um(a) jogador(a) morto(a)");
    
    pAbordado[id][APolicial] = playerid;
    pAbordado[id][Abordado] = true;
    MostrarAbordagem(id);
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| AVISO | O(A) Policial %s[%d] abordou você", PegarNick(playerid), playerid);
    SendClientMessage(id, 0x00BFFFFF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| AVISO | Você abordou o(a) procurado(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    pAbordado[id][TempoAbordado] = SetTimerEx("AceitarAbordagem", 10000, false, "d", id);
    return 1;
}

CMD:procurados(playerid)
{
    if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    if(pPolicia[playerid][PegouUniformePolicia] == false && !VerificarPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    MostrarProcurados(playerid);
    return 1;
}

stock MostrarProcurados(playerid)
{
    new Dialog[2000],
        gga = 0;
    strcat(Dialog, "Procurado(a)\tEstrelas\tLocal\n");
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0 && pAdmin[i][FalsoPlayer] == false) continue;
        if(Jogador[i][CadeiaEstilo] > 0) continue;
        if(Jogador[i][Estrelas] < 1) continue;
        gga++;
        strcatEx(Dialog, "{FFFFFF}%s[%d]\t{FF0000}%d\t{FF4500}%s\n", PegarNick(i), i, Jogador[i][Estrelas], GetPlayerZone(i));
    }
    if(gga == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há procurados(as)");
    Dialog_Show(playerid, SemFucnaacao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Procurados(as)", Dialog, "Fechar", "");
    return 1;
}

CMD:desalgemar(playerid, params[]) 
{
    if(!IsPolicia(playerid) && Jogador[playerid][Admin] < 3) return 0;
    if(!strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Desalgemar [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se desalgemar");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não encontrado(a)");
    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode desalgemar dentro de um veículo");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 7) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(GetPlayerVirtualWorld(id) != GetPlayerVirtualWorld(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está na mesma cidade que você");
    if(pAbordado[id][Algemado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) não esta algemado(a)");
    if(GetPlayerState(id) == PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode desalgemar o(a) jogador(a) dentro de um veículo");

    KillTimer(pAbordado[id][TempoAbordado]);
    TogglePlayerControllable(id, 1);
    pAbordado[id][Algemado] = false;

    new Mensagem[128];
    SetPlayerSpecialAction(id, SPECIAL_ACTION_NONE);

    format(Mensagem, sizeof(Mensagem), "| AVISO | Você desalgemou o(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x1E90FFFF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| AVISO | Desalgemado(a) por %s[%d]", PegarNick(playerid), playerid);
    SendClientMessage(id, 0x1E90FFFF, Mensagem);
    return 1;
}

CMD:prenderarmas(playerid, params[])
{
    if(!IsPolicia(playerid)) return 0;
    if(!strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /PrenderArmas [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não prender suas armas");
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não encontrado(a)");
    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode prender armas de um admin");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode prender armas dentro de um veículo");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 7) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(GetPlayerVirtualWorld(id) != GetPlayerVirtualWorld(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está na mesma cidade que você");
    if(Jogador[id][Estrelas] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está procurado(a)");
    if(GetPlayerState(id) == PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode prender armas do(a) jogador(a) dentro de um veículo");
    if(GetPVarInt(id, "Mochhila") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa matar(a) esse procurado(a)");

    new Mensagem[75];
    format(Mensagem, sizeof(Mensagem), "| POLÍCIA | O(A) Policial %s[%d] prendeu suas armas", PegarNick(playerid), playerid);
    SendClientMessage(id, 0x1E90FFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| POLÍCIA | Você prendeu as armas do(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x1E90FFFF, Mensagem);

    ResetPlayerWeapons(id);
    return 1;
}

CMD:multas(playerid)
{
    if(!IsPolicia(playerid) && Jogador[playerid][Admin] < 1) return 0;
    new Dialog[300];
    strcat(Dialog, "{1E90FF}Contra Mão\t{32CD32}R$2.000\n");
    strcat(Dialog, "{1E90FF}Parado na calçada\t{32CD32}R$2.000\n");
    strcat(Dialog, "{1E90FF}Cúmplice\t{32CD32}R$1.000\n");
    strcat(Dialog, "{1E90FF}CNH Vencida\t{32CD32}R$5.000\n");
    strcat(Dialog, "{1E90FF}Sem CNH\t{32CD32}R$6.000");
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_MSGBOX, "{FF0000}Multas", Dialog, "Fechar", "");
    return 1;
}

CMD:multar(playerid, params[])
{
    if(!IsPolicia(playerid)) return 0;
    new id, mvalor, mvv[30];
    if(sscanf(params, "dds[30]", id, mvalor, mvv)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Multar [ID] [Valor] [Multa]");
    if(mvalor > 6000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode colocar esse valor");
    if(mvalor < 1000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode colocar esse valor");
    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    if(!VerificarPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é um policial");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode multar um admin");
    if(GetPlayerVirtualWorld(id) != GetPlayerVirtualWorld(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está na mesma cidade que você");
    if(Jogador[playerid][Level] < 200) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode multar a partir do level 200");

    new Mensagem[158];
    format(Mensagem, sizeof(Mensagem), "| MULTA | Você foi multado(a) pelo(a) %s[%d] por %s no valor de $%s", PegarNick(playerid), playerid, mvv, DinheiroSeparar(mvalor));
    SendClientMessage(id, 0x1E90FFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| MULTA | Você multou o(a) jogador(a) %s[%d] pelo motivo %s por $%s", PegarNick(id), id, mvv, DinheiroSeparar(mvalor));
    SendClientMessage(playerid, 0x1E90FFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| MULTA| O(A) Policial %s[%d] multou %s[%d] pelo motivo %s por $%s", PegarNick(playerid), playerid, PegarNick(id), id, mvv, DinheiroSeparar(mvalor));

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] < 2 && strcmp(Jogador[i][Profissao], "Corregedoria")) continue;
        SendClientMessage(i, 0x1E90FFFF, Mensagem);
    }
    return 1;
}

CMD:procurar(playerid, params[])
{
    if(!IsPolicia(playerid) && 
    strcmp(Jogador[playerid][Profissao], "Exército") &&
    strcmp(Jogador[playerid][Profissao], "Marinha") &&
    strcmp(Jogador[playerid][Profissao], "Aeronáutica")) return 0;

    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    if(!VerificarPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é um policial");

    new id, mvt[30];
    if(sscanf(params, "ds[30]", id, mvt)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Procurar [ID] [Motivo]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se procurar");
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode procurar um admin");
    if(GetPVarInt(id, "Mochhila") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa matar(a) esse procurado(a)");
    if(Jogador[playerid][Prisoes] < 400) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem 400 prisões");

    Jogador[id][Estrelas] += 1;

    new Mensagem[148];
    format(Mensagem, sizeof(Mensagem), "| PROCURADO | Você foi colocado(a) na lista de procurados por %s[%d] ( Motivo: %s )", PegarNick(playerid), playerid, mvt);
    SendClientMessage(id, 0x1E90FFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| PROCURADO | Você colocou %s[%d] na lista de procurados ( Motivo: %s )", PegarNick(id), id, mvt);
    SendClientMessage(playerid, 0x1E90FFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| PROCURADO | O(A) Policial %s[%d] colocou %s[%d] na lista de procurados ( Motivo: %s )", PegarNick(playerid), playerid, PegarNick(id), id, mvt);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] < 2 && strcmp(Jogador[i][Profissao], "Corregedoria")) continue;
        SendClientMessage(i, 0x1E90FFFF, Mensagem);
    }
    return 1;
}

CMD:acompanhamento(playerid, params[])
{
    if(!IsPolicia(playerid)) return 0;
    if(!strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");

    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    if(!VerificarPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é um policial");
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Acompanhamento [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se prender");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não encontrado(a)");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode prender um admin");
    // if(pPolicia[playerid][UltimoPolicia] != pPolicia[playerid][PoliciaCarroID] && !UltimoVeiculoExercito(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é o seu alugado!");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode algemar dentro de um veículo");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 7) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(GetPlayerVirtualWorld(id) != GetPlayerVirtualWorld(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está na mesma cidade que você");
    if(pAbordado[id][Abordado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) não está abordado(a)");
    // if(pAbordado[id][APolicial] != playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode acompanhar esse jogador, aguarde o(a) policial que abordou");

    KillTimer(pAbordado[id][TempoAbordado]);
    AceitarAbordagem(id);
    return 1;
}

CMD:arrombarporta(playerid)
{
    for(new i=0; i < MAX_CASAS; i++){
        if(pCasa[i][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ])) continue;
        if(pCasa[i][cTranca] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa casa já está com a porta aberta");
        if(pCasa[i][PortaArrombada] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa casa já está com a porta quebrada");

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| AVISO | Você arrombou a porta da casa ID: %d", i);
        SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
        pCasa[i][PortaArrombada] = gettime()+60;
        break;
    }
    return 1;
}

hook OV_DamageStatusUpdate(vehicleid, playerid)
{
    if(VeiculoServer[vehicleid][AntiFurar] == false) return 1;
    new panels, doors, lights, tires;
    GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
    tires = 0;
    UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
    return 1;
}