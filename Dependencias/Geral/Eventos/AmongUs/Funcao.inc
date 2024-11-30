stock VerificarTaskMapa(playerid)
{
    new taid = -1,
        rangeid = -1;

    if(AmongMapa == 0)
    {
        for(new i=0; i < sizeof(Task); i++){
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, Task[i][TaskX], Task[i][TaskY], Task[i][TaskZ])) continue;
            rangeid = i;
            break;
        }
    }
    else if(AmongMapa == 1)
    {
        for(new i=0; i < sizeof(TaskMotel); i++){
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, TaskMotel[i][TaskX], TaskMotel[i][TaskY], TaskMotel[i][TaskZ])) continue;
            rangeid = i;
            break; 
        }
    }

    if(rangeid != -1){
        taid = VerificarTasks(playerid, rangeid);
        if(taid == -2) taid = -1;
    }
    return taid;
}

stock VerificarTasks(playerid, id)
{
    for(new i=0; i < MAX_TASKS; i++)
    {
        if(JogadorTask[playerid][i][TaskID] != id) continue;
        if(JogadorTask[playerid][i][TaskConcluida] == true)
        {
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já fez essa task.");
            return -2;
        }
        return id;
    }
    return -1;
}

stock PegarNomeTask(id)
{
    new TaskN[30];
    switch(AmongMapa)
    {
        case 0: format(TaskN, 30, Task[id][TaskNome]);
        case 1: format(TaskN, 30, TaskMotel[id][TaskNome]);
    }
    return(TaskN);
}

stock VerificarSeAindaTem()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmongVivo] == false) continue;
        if(Among[i][Impostor] == true) continue;
        if(Among[i][TaskFeitas] < 5) return true; 
    }
    return false;
}

stock ImpostorID()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][Impostor] == false) continue;
        return Among[i][JogadorID];
    }
    return -1;
}
                                        // Voltar Depois para refazer.
stock EnviarVitoria(win, const GanhoMsg[])
{
    new Mensagem[128],
        idd = ImpostorID();

    if(win == 1) format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) Impostor(es) era %s[%d]", PegarNick(idd), idd);
    else if(win == 2) format(Mensagem, sizeof(Mensagem), "| EVENTO | Os Tripulantes ganharam ( Motivo: %s )", GanhoMsg);

    // EnviarAmong(1, AmongPartida[ImpostorNome], AmongPartida[ImpostorNome2], AmongPartida[MortesAmong], AmongPartida[Tassks], AmongPartida[KickAmong], win, GanhoMsg);
    
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(win == 1) GameTextForPlayer(Among[i][JogadorID], "~r~Impostor(es) ~w~Ganharam", 5000, 4);
        else if(win == 2) GameTextForPlayer(Among[i][JogadorID], "~b~Tripulantes ~w~Ganharam", 5000, 4);
        SendClientMessage(Among[i][JogadorID], 0xFF8C00FF, Mensagem);
        PlayAudioStreamForPlayer(Among[i][JogadorID], "https://www.dropbox.com/s/4wu0rlbftr1mu5k/Among_Us_Victory_Sound.mp3?dl=1");
    }
    FinalizarPartida();
    return 1;
}

stock ModoEspectadorAmong(playerid, id)
{
    if(GetPVarInt(playerid, "SpecPerm") == 0)
    {
        SetPVarInt(playerid, "SpecPerm", 1);
        SetPlayerInterior(playerid, GetPlayerInterior(id));
        SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(id));
        TogglePlayerSpectating(playerid, 1);
        PlayerSpectatePlayer(playerid, id, SPECTATE_MODE_NORMAL);
        return 1;
    }
    SetPVarInt(playerid, "AntiFaslda", gettime()+15);
    TogglePlayerSpectating(playerid, 0);
    SetPVarInt(playerid, "SpecPerm", 0); 
    return 1;
} 

stock PegarCorpoID()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(AmongCorpo[i][CorpoChao] == true) continue;
        return i;
    }  
    return -1;
}

stock AdicionarCorpoAmong(i)
{
    new id = Among[i][JogadorID],
        Float:cxPos[4],
        nc = PegarCorpoID(),
        Mensagem[128];

    GetPlayerPos(id, cxPos[0], cxPos[1], cxPos[2]);
    GetPlayerFacingAngle(id, cxPos[3]);

    format(Mensagem, sizeof(Mensagem), "Corpo do(a) {B22222}%s{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para reportar", CoresAmong[i][CorNomeAmong]);
    format(AmongCorpo[nc][CorpoCor], 40, CoresAmong[i][CorNomeAmong]);
    AmongCorpo[nc][CorpoChao] = true;  

    switch(AmongMapa)
    {
        case 0:
        {
            AmongCorpo[nc][CorpoActo] = CreateDynamicActor(GetPlayerSkin(id), cxPos[0]+1, cxPos[1], cxPos[2], cxPos[3], 1, 100.0, 2020, 5, -1, 100.0, -1, 0);
            AmongCorpo[nc][CorpoMensagem] = CreateDynamic3DTextLabel(Mensagem, -1, cxPos[0]+1, cxPos[1], cxPos[2], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2020, 5, -1, 20.0, -1);
        }
        case 1:
        {
            AmongCorpo[nc][CorpoActo] = CreateDynamicActor(GetPlayerSkin(id), cxPos[0]+1, cxPos[1], cxPos[2], cxPos[3], 1, 100.0, 2020, 15, -1, 100.0, -1, 0);
            AmongCorpo[nc][CorpoMensagem] = CreateDynamic3DTextLabel(Mensagem, -1, cxPos[0]+1, cxPos[1], cxPos[2], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2020, 15, -1, 20.0, -1);
        }
    }
    
    AmongCorpo[nc][CorpoX] = cxPos[0];
    AmongCorpo[nc][CorpoY] = cxPos[1];
    AmongCorpo[nc][CorpoZ] = cxPos[2];
    ApplyDynamicActorAnimation(AmongCorpo[nc][CorpoActo], "PED", "KO_skid_front", 4.1, 0, 1, 1, 1, 1);
    return 1;
}

stock RemoverCorposAmong()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(AmongCorpo[i][CorpoChao] == false) continue; 
        AmongCorpo[i][CorpoChao] = false;
        DestroyDynamicActorEx(AmongCorpo[i][CorpoActo]);
        DestroyDynamic3DTextLabelEx(AmongCorpo[i][CorpoMensagem]);
    }
    return 1;
}

stock IniciarReuniao(playerid, reportado)
{
    ReuniaoOnline = true;
    new Mensagem[128],
        id = Among[playerid][JogadorID]; 

    RemoverCorposAmong(); 

    // Apenas Reunião
    if(reportado == -1) format(Mensagem, sizeof(Mensagem), "| REUNIÃO | %s[%s] pediu uma reunião", PegarNick(playerid), CoresAmong[id][CorNomeAmong]);
    else format(Mensagem, sizeof(Mensagem), "| REUNIÃO | %s[%s] reportou o corpo do(a) %s", PegarNick(playerid), CoresAmong[id][CorNomeAmong], AmongCorpo[reportado][CorpoCor]);

    for(new i=0; i < MAX_AMONG; i++) 
    {
        if(Among[i][AmongEntrou] == false) continue;   
        if(Among[i][AmongVivo] == false){
            PlayAudioStreamForPlayer(Among[i][JogadorID], "https://www.dropbox.com/s/rjjw6cbhdqex2dg/Among_Us_Emergency_Meeting_-_Sound_Effect_HD.mp3?dl=1");
            continue;
        }
        
        PlayAudioStreamForPlayer(Among[i][JogadorID], "https://www.dropbox.com/s/rjjw6cbhdqex2dg/Among_Us_Emergency_Meeting_-_Sound_Effect_HD.mp3?dl=1");
        SetPVarInt(Among[i][JogadorID], "EventoJogador", 1);
        LimparChat(Among[i][JogadorID]);
        MostrarVotacaoAmong(Among[i][JogadorID]);

        if(AmongMapa == 0)
        {
            SetPlayerPos(Among[i][JogadorID], ReuniaoLocal[i][rNiaoX], ReuniaoLocal[i][rNiaoY], ReuniaoLocal[i][rNiaoZ]);  
            SetPlayerFacingAngle(Among[i][JogadorID], ReuniaoLocal[i][rNiaoA]);
        }
        else if(AmongMapa == 1)
        {
            SetPlayerPos(Among[i][JogadorID], ReuniaoLocalMotel[i][rNiaoX], ReuniaoLocalMotel[i][rNiaoY], ReuniaoLocalMotel[i][rNiaoZ]);  
            SetPlayerFacingAngle(Among[i][JogadorID], ReuniaoLocalMotel[i][rNiaoA]);  
        }
        SetCameraBehindPlayer(Among[i][JogadorID]);
        SendClientMessage(Among[i][JogadorID], 0xFF8C00FF, Mensagem);

        if(reportado == -1) AtualizarAmongVote(playerid, Among[i][JogadorID], true);
        else AtualizarAmongVote(playerid, Among[i][JogadorID], false);
    } 

    SetTimerEx("TempoVotacaoAmong", 1000, false, "d", 180); 
    return 1;
}

stock AtualizarAmongVote(playerid, id, bool:locbuitc)
{

    // Playerid = Cara que apertou o botão.
    // ID = Todos os players ON
    // locbuitc = Votação via botão

    new idx,
        blunic[65],
        cornas[30],
        Preview,
        corfc = 153;


    for(new i=0; i < MAX_AMONG; i++)
    {
        idx = Among[i][JogadorID];
        corfc = 153;

        if(Among[i][AmongSaiu] == true)
        {
            format(blunic, 65, Among[i][AmongNome]);
            Preview = 19133;
        }
        else if(Among[i][AmongEntrou] == false) Preview = 18631;
        else
        {
            Preview = 18978;
            format(blunic, 65, PegarNick(idx));
            if(Among[JogadorAmong[id][AmongID]][Impostor] == true && Among[i][Impostor] == true) corfc = -2147483393; 
            if(idx == playerid && locbuitc == true) strcat(blunic, " [Botão]");
            else if(idx == playerid && locbuitc == false) strcat(blunic, " [Reportou]");
            else if(Among[i][AmongVivo] == false)
            {
                corfc = HexToInt("300608"); 
                Preview = 1254; 
            }
        }

        // Capacetes
        PlayerTextDrawSetPreviewModel(id, VoteAmong[id][Capacetes[i][CapaceteID]], Preview); // Modelo
        if(Preview == 18978)
        {
            format(cornas, 30, CoresAmong[i][CapaceteCOR]);
            strdel(cornas, 0, 2);
            PlayerTextDrawColor(id, VoteAmong[id][Capacetes[i][CapaceteID]], HexToInt(cornas)); // Cor 
        }
        PlayerTextDrawShow(id, VoteAmong[id][Capacetes[i][CapaceteID]]); // Atualizar  

        // Plano de Fundo
        PlayerTextDrawBoxColor(id, VoteAmong[id][Capacetes[i][BoxID]], corfc); // Cor 
        PlayerTextDrawShow(id, VoteAmong[id][Capacetes[i][BoxID]]); // Atualizar 
        if(Preview == 18631) PlayerTextDrawSetString(id, VoteAmong[id][TripulanteNome[i]], ConverterTexto("Não Conectado(a).")); // Texto
        else PlayerTextDrawSetString(id, VoteAmong[id][TripulanteNome[i]], ConverterTexto(blunic)); // Texto
    }
    return true;
}

stock FinalizarVotacao()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        Among[i][JaVotou] = false;
        Among[i][EntrouReuni] = false;
        SetPVarInt(Among[i][JogadorID], "EventoJogador", 2);
        OcultarVotacaoAmong(Among[i][JogadorID]);
        TogglePlayerControllable(Among[i][JogadorID], 1);
    }

    TempoReuniaoBotao = gettime()+50;
    ReuniaoOnline = false;
    ResultadoVotacao();
    return 1;
}

stock ResultadoVotacao()
{
    new vlrmax = -1,
        uservote = -1;
    
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmongVivo] == false) continue;
        PlayAudioStreamForPlayer(Among[i][JogadorID], "https://www.dropbox.com/s/yoyxv7sexoksbtl/Among_Us_All_Vote_Out_Typing_-_Sound_Effect_HD.mp3?dl=1");
        if(aVotacao[i][VotacaoQ] > vlrmax && aVotacao[i][VotacaoQ] != 0){
            vlrmax = aVotacao[i][VotacaoQ];
            uservote = i;
        }
    }

    for(new i=0; i < MAX_AMONG; i++) 
        aVotacao[i][VotacaoQ] = 0;

    if(vlrmax > 1)
    {
        if(Among[uservote][Impostor] == true){
            RetirarTripulante(Among[uservote][JogadorID]);
            if(ExisteImpostor() < 1) EnviarVitoria(2, "Impostor(es) Ejetado(s)"); 
        }
        else if(Among[uservote][Impostor] == false)
        {
            if(ExisteTripulantes() < 2) EnviarVitoria(1, "Tripulantes foram ejetados");
            else
            {
                Among[uservote][AmongVivo] = false;
                new Mensagem[128],
                    Anuc[60],
                    Anucc[45];
                
                ModoEspectadorAmong(Among[uservote][JogadorID], Among[PegarImpostor()][JogadorID]);
                format(Mensagem, sizeof(Mensagem), "| AMONG | %s[%s] não era o(a) impostor(a)", PegarNick(Among[uservote][JogadorID]), CoresAmong[uservote][CorAmong]);
                
                format(Anucc, sizeof(Anucc), "%s [%s]", CoresAmong[uservote][CorAmong]);
                format(Anuc, sizeof(Anuc), "~y~%s~w~ não era impostor(a) - Restam: ~r~%d", PegarNick(Among[uservote][JogadorID]), ExisteImpostor());
                
                for(new i=0; i < MAX_AMONG; i++)
                {
                    if(Among[i][AmongEntrou] == false) continue;
                    SendClientMessage(Among[i][JogadorID], 0xFF8C00FF, Mensagem);
                    MostrarAmongMensagem(Among[i][JogadorID], Anucc, Anuc, 3000);
                }
                if(ExisteTripulantes() < 2) EnviarVitoria(1, "Tripulantes foram ejetados");
            }
        }
    }
    else if(!VerificarSeAindaTem()) return EnviarVitoria(2, "Conclusão de Tasks");
    return 1;
}

stock ExisteTripulantes()
{
    new aag = 0;
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmongVivo] == false) continue;
        if(Among[i][Impostor] == true) continue;
        aag++;
    } 
    return aag;
}

stock ExisteImpostor()
{
    new aag = 0;
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmongVivo] == false) continue;
        if(Among[i][Impostor] == false) continue;
        aag++;
    } 
    return aag;
}

stock PegarImpostor()
{
    for(new i=0; i < MAX_AMONG; i++){
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmongVivo] == false) continue;
        if(Among[i][Impostor] == false) continue;
        return i;
    }
    return -1;
}

stock VerificarVotos()
{
    for(new i=0; i < MAX_AMONG; i++){
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmongVivo] == false) continue;
        if(Among[i][JaVotou] == false) return false;
    }
    return true;
}

stock AtualizarMenu(playerid, i)
{
    new cco = -1,
        Mensagem[128],
        tabid;
    
    switch(i)
    {
        case 0: tabid = 4;
        case 1: tabid = 5;
        case 2: tabid = 6;
        case 3: tabid = 7;
        case 4: tabid = 8;
    }

    new NAkm[30];
    switch(AmongMapa)
    {
        case 0: format(NAkm, 30, Task[JogadorTask[playerid][i][TaskID]][TaskNome]);
        case 1: format(NAkm, 30, TaskMotel[JogadorTask[playerid][i][TaskID]][TaskNome]);
    }
    
    if(JogadorTask[playerid][i][TaskConcluida] == false) format(Mensagem, sizeof(Mensagem), "%d. %s", i+1, NAkm);
    else format(Mensagem, sizeof(Mensagem), "%d. %s", i+1, NAkm), cco = 16711935;  
    PlayerTextDrawColor(playerid, AmongTasks[playerid][tabid], cco); 
    PlayerTextDrawShow(playerid, AmongTasks[playerid][tabid]);
    PlayerTextDrawSetString(playerid, AmongTasks[playerid][tabid], ConverterTexto(Mensagem));
    return 1;
}

stock ResetarTripulantes()
{
    for(new i=0; i < MAX_AMONG; i++){
        new bzc[AmongJogador];
        Among[i] = bzc;
    }
    return 1;
}

stock RetirarTripulante(playerid)
{
    new id = JogadorAmong[playerid][AmongID];
    if(id == -1) return 1;
    Among[id][AmongSaiu] = true;
    Among[id][AmongEntrou] = false;

    if(JogadorAmong[playerid][FazendoTask] == true) KillTimer(JogadorAmong[playerid][FazendoTime]);
    if(Among[id][AmongVivo] == false) ModoEspectadorAmong(playerid, 0);

    SetPVarInt(playerid, "EventoJogador", 0);

    Jogador[playerid][uInteriorEx] = 0;
    RemovePlayerAttachedObject(playerid, 0);
    VerificarAcessorios(playerid);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 0);
    TogglePlayerControllable(playerid, 1);
    SetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
    SetPlayerEmprego(playerid, Jogador[playerid][Profissao]);
    
    if(Mysss[playerid] != -1){
        SetPlayerSkin(playerid, Mysss[playerid]);
    }else{
        Jogador[playerid][SkinProfissao] = -1;
        SetPlayerSkin(playerid, Jogador[playerid][Skin]);
    }

    OcultarTasks(playerid); // Remover Task
    
    if(ReuniaoOnline == true)
        if(Among[id][AmongVivo] == true) OcultarVotacaoAmong(playerid);

    for(new i=0; i < MAX_AMONG; i++){
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][JogadorID] != playerid) continue;
        Among[i][Impostor] = false;
        break;
    }

    new kikando[JogadorAmongID];
    JogadorAmong[playerid] = kikando;
    JogadorAmong[playerid][AmongID] = -1;
    return 1;
}

stock FinalizarPartida()
{
    RemoverCorposAmong();
    AlterarAmongMapa(1); // Remover Portas etc..
    AlterarAmongMapa(4); // Remover Tasks
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        Among[i][AmongEntrou] = false;
        Among[i][Impostor] = false;
        RetirarTripulante(Among[i][JogadorID]);
    }
    ResetarTripulantes();
    return 1;
}


stock GerarJogadorID()
{
    new ida = -1;
    for(new i=0; i < AmongVaga; i++){ 
        if(Among[i][AmongEntrou] == true) continue;
        return i;
    }
    return ida;
}

stock EntrarAmong(playerid)
{
    new id = GerarJogadorID();
    if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais vagas para esse modo.");
    
    for(new i=0; i < MAX_AMONG; i++){
        if(Among[i][AmongEntrou] == false) continue; 
        if(Among[i][JogadorID] != playerid) continue;
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já entrou nesse modo!");
        return 1;
    }

    for(new i=0; i < 5; i++){
        JogadorTask[playerid][i][TaskID] = -1;
        JogadorTask[playerid][i][SecTask] = false;
        JogadorTask[playerid][i][TaskConcluida] = false;
    }

    ResetPlayerWeapons(playerid);
    RemoverAcessorios(playerid);
    SetPlayerAttachedObject(playerid, 0, 18978, 2, 0.0680, 0.0140, 0.0000, -0.2000, 82.0999, 91.9001, 1.0000, 1.0000, 1.0000, 0x00BFFFFF, 0xFFFFFFFF);

    SetPVarInt(playerid, "EventoJogador", 1);

    Jogador[playerid][uInteriorEx] = 2144;
    GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
    
    if(AmongMapa == 0)
    {
        SetPlayerPos(playerid, 1266.7751, -781.4780, 1091.9063);
        SetPlayerInterior(playerid, 5);
    }
    else if(AmongMapa == 1)
    {
        SetPlayerPos(playerid, 2216.1753,-1150.4926,1025.7969);
        SetPlayerInterior(playerid, 15);   
    }

    Mysss[playerid] = Jogador[playerid][SkinProfissao];
    Jogador[playerid][SkinProfissao] = 165;

    SetPlayerVirtualWorld(playerid, 2020);
    SetPlayerHealth(playerid, 100.0);

    JogadorAmong[playerid][AmongID] = id;
    Among[id][JogadorID] = playerid;

    Among[id][AmongVivo] = true;
    Among[id][AmongEntrou] = true;
    Among[id][Impostor] = false;
    Among[id][EntrouReuni] = false;
    format(Among[id][AmongNome], 30, PegarNick(playerid));
    
    SetPVarInt(playerid, "ImpostorTempo", 0);
    SetPlayerColor(playerid, CoresAmong[id][CorAmong]);
    SetPlayerSkin(playerid, 165);
    
    MostrarTasks(playerid);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| AMONG | Você entrou no evento ( %s )", CoresAmong[id][CorNomeAmong]);
    SendClientMessage(playerid, 0xFF8C00FF, Mensagem);
    return 1;
}

stock IniciarAmong()
{
    EventoEstado = 2;
    AlterarAmongMapa(2);
    AlterarAmongMapa(3); // Criar Tasks

    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;   
        if(!IsPlayerConnected(Among[i][JogadorID])) continue;
        SetPVarInt(Among[i][JogadorID], "EventoJogador", 2);
        TogglePlayerControllable(Among[i][JogadorID], 1);
        PlayAudioStreamForPlayer(Among[i][JogadorID], "https://www.dropbox.com/s/fxhj00djm8xj63a/Crewman_or_Impostor_amongs_us_-_Sound_Effects.mp3?dl=1");
    }
    GerarImpostor();
    return 1;
}

stock GerarImpostor()
{
    new raid,
        Cls = 0;
    
    for(new i=0; i < 9999999; i++)
    {
        raid = random(MAX_AMONG);
        for(new d=0; d < MAX_AMONG; d++)
        {
            if(d != raid) continue;
            if(Among[d][AmongEntrou] == false) break;
            Among[raid][Impostor] = true;
            Cls++;
            break;
        }
        if(Cls >= AmongImpostor) break;
    }
    EnviarInformacaoPartida();
    return 1;
}

stock EnviarInformacaoPartida()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][Impostor] == true)
        {
            GameTextForPlayer(Among[i][JogadorID], "~r~Impostor(a)", 4000, 3);
            PlayerTextDrawSetString(Among[i][JogadorID], AmongTasks[Among[i][JogadorID]][2], "~r~Impostor(a)~w~~n~Among_Us");
        }
        else
        {
            GameTextForPlayer(Among[i][JogadorID], "~b~Tripulante", 4000, 3);
            PlayerTextDrawSetString(Among[i][JogadorID], AmongTasks[Among[i][JogadorID]][2], "~b~Tripulante~w~~n~Among_Us");
            GerarMissao(i);
        }
    }
    return 1;
}

stock GerarMissao(i)
{
    new id = Among[i][JogadorID],
        Aleaid,
        asl;
    
    for(new k=0; k < 5; k++)
    {
        for(new d=0; d < 9999; d++)
        {
            if(AmongMapa == 0) Aleaid = random(sizeof(Task));
            else if(AmongMapa == 1) Aleaid = random(sizeof(TaskMotel));

            for(new h=0; h < 5; h++)
            {   
                if(JogadorTask[id][h][TaskID] == Aleaid){
                    asl = 0;
                    break;
                }
                asl++;
            }
            if(asl >= 5) break;
        }
        asl = 0;
        JogadorTask[id][k][TaskID] = Aleaid;
        JogadorTask[id][k][TaskConcluida] = false;
    }
    AtualizarMissao(id);
    return 1;
}

stock AtualizarMissao(playerid)
{
    new Mensagem[128];
    for(new d=0; d < 5; d++)
    {
        if(AmongMapa == 0) format(Mensagem, sizeof(Mensagem), "%d. %s", d+1, Task[JogadorTask[playerid][d][TaskID]][TaskNome]);
        else if(AmongMapa == 1) format(Mensagem, sizeof(Mensagem), "%d. %s", d+1, TaskMotel[JogadorTask[playerid][d][TaskID]][TaskNome]);
        switch(d)
        {
            case 0: PlayerTextDrawSetString(playerid, AmongTasks[playerid][4], ConverterTexto(Mensagem));
            case 1: PlayerTextDrawSetString(playerid, AmongTasks[playerid][5], ConverterTexto(Mensagem));
            case 2: PlayerTextDrawSetString(playerid, AmongTasks[playerid][6], ConverterTexto(Mensagem));
            case 3: PlayerTextDrawSetString(playerid, AmongTasks[playerid][7], ConverterTexto(Mensagem));
            case 4: PlayerTextDrawSetString(playerid, AmongTasks[playerid][8], ConverterTexto(Mensagem));
        }
    }
    return 1;
}

stock PrepararAmong()
{
    AlterarAmongMapa(0);
    ResetarTripulantes();
    format(AmongPartida[ImpostorNome], 30, "N/A");
    format(AmongPartida[ImpostorNome2], 30, "N/A");
    ReuniaoOnline = false;
    TempoReuniaoBotao = 0;
    for(new i=0; i < MAX_AMONG; i++){
        aVotacao[i][VotacaoQ] = 0;
    }
    return 1;
}

stock AlterarAmongMapa(id)
{
    switch(id)
    {
        // Criação
        case 0:
        {
            if(AmongMapa == 0)
            {
                AmongObjeto[0] = CreateDynamicObject(18756, 1282.2384, -781.8312, 1090.6335, 0.0000, 0.0000, 90.0000, 2020, 5, -1, 180.0, 180.0, -1); //ElevatorDoor1
                AmongObjeto[1] = CreateDynamicObject(18756, 1282.3098, -785.6308, 1090.6335, 0.0000, 0.0000, -90.0000, 2020, 5, -1, 180.0, 180.0, -1); //ElevatorDoor1
                AmongObjeto[2] = CreateDynamicObject(19893, 1263.5393, -774.3919, 1091.5705, 0.0000, 0.0000, 64.5999, 2020, 5, -1, 180.0, 180.0, -1); //LaptopSAMP1
                AmongObjeto[3] = CreateDynamicObject(1271, 1263.4699, -774.3319, 1091.2354, 0.0000, 0.0000, 34.6999, 2020, 5, -1, 180.0, 180.0, -1); //gunbox
                SetDynamicObjectMaterial(AmongObjeto[3], 0, 10871, "blacksky_sfse", "ws_slatetiles", 0xFFFFFFFF);
            }
            else if(AmongMapa == 1)
            {
                AmongObjeto[0] = CreateDynamicObject(18756, 2230.8469, -1149.4826, 1030.4039, 0.0000, 0.0000, 0.0000, 2020, 15, -1, 180.0, 180.0, -1); 
                AmongObjeto[1] = CreateDynamicObject(19273, 2228.8256, -1151.8325, 1030.1379, 0.0000, 0.0000, -90.0000, 2020, 15, -1, 180.0, 180.0, -1); 
                AmongObjeto[2] = CreateDynamicObject(1271, 2223.2077, -1153.5506, 1025.1184, 0.0000, 0.0000, 30.4000, 2020, 15, -1, 180.0, 180.0, -1); 
                AmongObjeto[3] = CreateDynamicObject(19893, 2223.1923, -1153.5252, 1025.4482, 0.0000, 0.0000, -132.8999, 2020, 15, -1, 180.0, 180.0, -1); 
                SetDynamicObjectMaterial(AmongObjeto[2], 0, 10871, "blacksky_sfse", "ws_slatetiles", 0xFFFFFFFF);
            }
        }

        // Remover Objetos
        case 1:
        {
            if(AmongMapa == 0){
                for(new i=0; i < 4; i++)
                    DestroyDynamicObjectEx(AmongObjeto[i]);
            }
            else if(AmongMapa == 1){
                for(new i=0; i < 4; i++)
                    DestroyDynamicObjectEx(AmongObjeto[i]); 
            }
        }

        // Abrir Portas
        case 2:
        {
            if(AmongMapa == 0){
                MoveDynamicObject(AmongObjeto[0], 1282.2384+1.5, -781.8312, 1090.6335, 1.0);
	            MoveDynamicObject(AmongObjeto[1], 1282.3098-1.5, -785.6308, 1090.6335, 1.0);
            }
            else if(AmongMapa == 1) MoveDynamicObject(AmongObjeto[0], 2230.8469, -1149.4826+2.0, 1030.4039, 1.0);   
        }

        // Criação de Tasks
        case 3:
        {
            new Mensagem[128];
            if(AmongMapa == 0)
            {
                for(new i=0; i < sizeof(Task); i++)
                {
                    format(Mensagem, sizeof(Mensagem), "{7CFC00}Tarefa %s{FFFFFF}\nAperte {CCCCCC}'ALT'{FFFFFF} para fazer", Task[i][TaskNome]);
                    tTasks[i][TextoTask] = CreateDynamic3DTextLabel(Mensagem, -1, Task[i][TaskX], Task[i][TaskY], Task[i][TaskZ], 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2020, 5, -1, 30.0, -1);
                    tTasks[i][TextoCriado] = true;
                }
                TextoBotao = CreateDynamic3DTextLabel("{FF0000}Botão{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para iniciar uma reunião", -1, 1252.6251,-824.1965,1084.8087, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2020, 5, -1, 30.0, -1);
            }
            else if(AmongMapa == 1)
            {
                for(new i=0; i < sizeof(TaskMotel); i++)
                {
                    format(Mensagem, sizeof(Mensagem), "{7CFC00}Tarefa %s{FFFFFF}\nAperte {CCCCCC}'ALT'{FFFFFF} para fazer", TaskMotel[i][TaskNome]);
                    tTasks[i][TextoTask] = CreateDynamic3DTextLabel(Mensagem, -1, TaskMotel[i][TaskX], TaskMotel[i][TaskY], TaskMotel[i][TaskZ], 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2020, 15, -1, 30.0, -1);
                    tTasks[i][TextoCriado] = true;
                }
                TextoBotao = CreateDynamic3DTextLabel("{FF0000}Botão{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para iniciar uma reunião", -1, 2240.9395,-1193.2806,1029.7969, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2020, 15, -1, 30.0, -1);      
            }
        }

        // Remover Tasks
        case 4:
        {
            if(AmongMapa == 0)
            {
                for(new i=0; i < sizeof(Task); i++){
                    if(tTasks[i][TextoCriado] == false) continue;
                    DestroyDynamic3DTextLabelEx(tTasks[i][TextoTask]);
                    tTasks[i][TextoCriado] = false;
                }
            }
            else if(AmongMapa == 1)
            {
                for(new i=0; i < sizeof(TaskMotel); i++){
                    if(tTasks[i][TextoCriado] == false) continue;
                    DestroyDynamic3DTextLabelEx(tTasks[i][TextoTask]);
                    tTasks[i][TextoCriado] = false;
                }
            }
            DestroyDynamic3DTextLabelEx(TextoBotao);
        }
    }
    return 1;
}