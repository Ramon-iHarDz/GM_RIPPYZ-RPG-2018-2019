#include <YSI_Coding\y_hooks>


hook OnGameModeInit()
{
    // Deinifir ID's de Textdraws
    for(new i=0; i < MAX_AMONG; i++)
    {
        switch(i)
        {
            case 0: {Capacetes[i][BoxID] = 1; Capacetes[i][CapaceteID] = 14;}
            case 1: {Capacetes[i][BoxID] = 2; Capacetes[i][CapaceteID] = 25;}
            case 2: {Capacetes[i][BoxID] = 3; Capacetes[i][CapaceteID] = 26;}
            case 3: {Capacetes[i][BoxID] = 4; Capacetes[i][CapaceteID] = 27;}
            case 4: {Capacetes[i][BoxID] = 5; Capacetes[i][CapaceteID] = 28;}
            case 5: {Capacetes[i][BoxID] = 6; Capacetes[i][CapaceteID] = 29;}
            case 6: {Capacetes[i][BoxID] = 7; Capacetes[i][CapaceteID] = 30;}
            case 7: {Capacetes[i][BoxID] = 8; Capacetes[i][CapaceteID] = 31;}
            case 8: {Capacetes[i][BoxID] = 9; Capacetes[i][CapaceteID] = 32;}
            case 9: {Capacetes[i][BoxID] = 10; Capacetes[i][CapaceteID] = 33;}
            case 10: {Capacetes[i][BoxID] = 11; Capacetes[i][CapaceteID] = 34;}
        }
    }

    for(new i=0; i < MAX_AMONG; i++)
    {
        switch(i)
        {
            case 0: TripulanteNome[i] = 35;
            case 1: TripulanteNome[i] = 36;
            case 2: TripulanteNome[i] = 37;
            case 3: TripulanteNome[i] = 38;
            case 4: TripulanteNome[i] = 39;
            case 5: TripulanteNome[i] = 40;
            case 6: TripulanteNome[i] = 41;
            case 7: TripulanteNome[i] = 42;
            case 8: TripulanteNome[i] = 43;
            case 9: TripulanteNome[i] = 44;
            case 10: TripulanteNome[i] = 45;
        }    
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    JogadorAmong[playerid][AmongID] = -1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(EventoID == 2)
    { 
        for(new i=0; i < MAX_AMONG; i++)
        {
            if(Among[i][AmongEntrou] == false) continue;   
            if(Among[i][JogadorID] != playerid) continue;
            RetirarTripulante(playerid);
            if(EventoEstado == 2 && Among[i][Impostor] == true){
                if(ExisteImpostor() < 1) EnviarVitoria(2, "Impostor(es) Sairam"); 
            }
            else if(EventoEstado == 2 && Among[i][Impostor] == false){
                if(ExisteTripulantes() < 2) EnviarVitoria(1, "Tripulantes Quitaram");
            }
        }
    }
    
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{

    // Fazer Task
    if(newkeys == KEY_WALK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(JogadorAmong[playerid][AmongID] == -1) return 1;
        if(JogadorAmong[playerid][FazendoTask] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está fazendo uma task, aguarde");
        new id = JogadorAmong[playerid][AmongID],
            taid = VerificarTaskMapa(playerid);

        if(taid != -1)
        {
            if(Among[id][Impostor] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode fazer task");
            TogglePlayerControllable(playerid, 0);

            JogadorAmong[playerid][FazendoTask] = true;
            JogadorAmong[playerid][FazendoTime] = SetTimerEx("ProgressoTask", (random(10)*1000), false, "dd", playerid, taid);

            new Mensagem[90];
            format(Mensagem, sizeof(Mensagem), "| AMONG | Você está fazendo a task de %s", PegarNomeTask(taid)); 
            SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
        }
    }


    // Sistema para matar
    else if(newkeys == KEY_NO && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(JogadorAmong[playerid][AmongID] == -1) return 1; 
        new id = JogadorAmong[playerid][AmongID];
        if(Among[id][Impostor] == false) return 1;
        if(GetPVarInt(playerid, "ImpostorTempo") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está bloqueado(a) de matar, aguarde.");
        
        new Float:iMp[3];
        GetPlayerPos(playerid, iMp[0], iMp[1], iMp[2]);

        for(new i=0; i < MAX_AMONG; i++)
        {
            if(id == i) continue;
            if(Among[i][AmongEntrou] == false) continue;   
            if(Among[i][AmongVivo] == false) continue;
            if(Among[i][Impostor] == true) continue;
            if(!IsPlayerInRangeOfPoint(Among[i][JogadorID], 5.0, iMp[0], iMp[1], iMp[2])) continue;

            SetPVarInt(playerid, "ImpostorTempo", gettime()+25);

            new ex = Among[i][JogadorID],
                Mensagem[128];

            if(JogadorAmong[ex][FazendoTask] == true){
                KillTimer(JogadorAmong[ex][FazendoTime]);
                JogadorAmong[ex][FazendoTask] = false;
            }

            Among[i][AmongVivo] = false;

            AdicionarCorpoAmong(i);
            ModoEspectadorAmong(ex, playerid);
            
            format(Mensagem, sizeof(Mensagem), "| AMONG | Você morreu para o(a) impostor(a) %s", PegarNick(playerid));
            SendClientMessage(ex, 0xFF8C00FF, Mensagem);
            
            format(Mensagem, sizeof(Mensagem), "| AMONG | Você matou o(a) tripulante %s[%s]", PegarNick(ex), CoresAmong[i][CorNomeAmong]);
            SendClientMessage(playerid, 0xFF8C00FF, Mensagem);

            PlayAudioStreamForPlayer(ex, "https://www.dropbox.com/s/8f2m5n0nav5vf2r/Among_us_death_sound.mp3?dl=1");

            if(ExisteTripulantes() < 2) return EnviarVitoria(1, "Matou Todos");
            break;
        }
    }

    // Sistema para reportar
    else if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(JogadorAmong[playerid][AmongID] == -1) return 1;
        for(new i=0; i < MAX_AMONG; i++)
        {
            if(AmongCorpo[i][CorpoChao] == false) continue; 
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, AmongCorpo[i][CorpoX], AmongCorpo[i][CorpoY], AmongCorpo[i][CorpoZ])) continue;
            IniciarReuniao(playerid, i);
            return 1;
        }

        if(IsPlayerInRangeOfPoint(playerid, 5.0, 1252.6251, -824.1965, 1084.8087) && AmongMapa == 0 || 
        IsPlayerInRangeOfPoint(playerid, 5.0, 2240.9395,-1193.2806,1029.7969) && AmongMapa == 1)
        {
            if(ReuniaoOnline == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode iniciar uma reunião");
            if(TempoReuniaoBotao > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode fazer reunião, aguarde.");
            IniciarReuniao(playerid, -1);
            return 1;
        }
    }

    return 1;
}

function ProgressoTask(playerid, id)
{
    TogglePlayerControllable(playerid, 1);
    JogadorAmong[playerid][FazendoTask] = false;
    for(new i=0; i < MAX_TASKS; i++)
    {
        if(JogadorTask[playerid][i][TaskID] != id) continue;
        JogadorTask[playerid][i][TaskConcluida] = true;
        JogadorTask[playerid][i][TaskID] = id;
        AtualizarMenu(playerid, i);
        break;
    }

    new ex = JogadorAmong[playerid][AmongID];
    Among[ex][TaskFeitas] += 1;

    if(Among[ex][TaskFeitas] >= 5) SendClientMessage(playerid, 0xFFFF00FF, "| AMONG | Você finalizou suas tasks!");
    else SendClientMessage(playerid, 0xFFFF00FF, "| AMONG | Você ainda tem tasks para fazer!");
    if(!VerificarSeAindaTem()) return EnviarVitoria(2, "Conclusão de Tasks");
    return 1;
}

function TempoVotacaoAmong(tempo)
{
    if(ReuniaoOnline == false) return 1;
    if(tempo > 0)
    {
        tempo--;
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "Tempo: %s", SegundosParaMinutosEx(tempo));
        
        for(new i=0; i < MAX_AMONG; i++)
        {
            if(Among[i][AmongEntrou] == false) continue;   
            if(Among[i][AmongVivo] == false) continue;
            PlayerTextDrawSetString(Among[i][JogadorID], VoteAmong[Among[i][JogadorID]][12], ConverterTexto(Mensagem));
        }
        SetTimerEx("TempoVotacaoAmong", 1000, false, "d", tempo);
        return 1;
    }
    FinalizarVotacao();
    return 1;
}

function IniciarContagemAmong(c)
{
    if(c == 0)
    {
        IniciarAmong();
        return 1;
    }
    new Contd[20];
    format(Contd, sizeof(Contd), "~r~%d", c);
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;   
        if(!IsPlayerConnected(Among[i][JogadorID])) continue;
        GameTextForPlayer(Among[i][JogadorID], Contd, 5000, 4);
        PlayerPlaySound(Among[i][JogadorID], 1056, 0.0, 0.0, 0.0);
    }
    c--;
    SetTimerEx("IniciarContagemAmong", 1000, false, "d", c);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == VoteAmong[playerid][49])
    {
        new id = JogadorAmong[playerid][AmongID]; 
        if(JogadorAmong[playerid][AmongID] == -1) return 1;
        if(Among[id][JaVotou] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já votou");
        Among[id][JaVotou] = true;

        PlayerTextDrawColor(playerid, VoteAmong[playerid][49], 16711935); 
        PlayerTextDrawShow(playerid, VoteAmong[playerid][49]);
        SendClientMessage(playerid, 0xFF8C00FF, "| VOTAÇÃO | Você pulou o seu voto.");

        if(VerificarVotos()) return FinalizarVotacao();   
    }
    else
    {
        for(new i=0; i < MAX_AMONG; i++)
        {
            if(playertextid != VoteAmong[playerid][TripulanteNome[i]]) continue;

            if(Among[i][AmongEntrou] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há nenhum tripulante nesse slot");
            if(Among[i][AmongVivo] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Tripulante Morto(a)");
            
            new id = JogadorAmong[playerid][AmongID]; 
            if(Among[id][JaVotou] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já votou, aguarde.");
            
            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "| VOTAÇÃO | Você votou em %s[%s]", PegarNick(Among[i][JogadorID]), CoresAmong[i][CorNomeAmong]);
            SendClientMessage(playerid, 0xFF8C00FF, Mensagem);

            Among[id][JaVotou] = true;
            aVotacao[i][VotacaoQ] += 1;

            PlayerTextDrawColor(playerid, VoteAmong[playerid][TripulanteNome[i]], 16711935); 
            PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][TripulanteNome[i]], 120);
            PlayerTextDrawShow(playerid, VoteAmong[playerid][TripulanteNome[i]]);
            if(VerificarVotos()) return FinalizarVotacao();
            break;
        }
    }
    return 0;
}