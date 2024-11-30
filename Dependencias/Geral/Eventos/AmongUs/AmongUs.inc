#include <YSI_Coding\y_hooks>

#define MAX_AMONG 11

new PlayerText:AmongTasks[MAX_PLAYERS][12];
new PlayerText:VoteAmong[MAX_PLAYERS][20];

enum PartidaAmong
{
    AmongStatus, // 0 == Aguardando / 1 == Jogando / 2 == Reunião
    Tassks,
    KickAmong,
    MortesAmong,
    ImpostorNome[30],
    ImpostorNome2[30],

    TempoAmongVoto
};

enum TaskJogador
{
    bool:SecTask,
    bool:TaskConcluida,
    TaskID
};

enum JogadoresAmong
{
    bool:AmongEntrou,
    bool:AmongVivo,
    bool:Impostor,
    bool:JaVotou,
    bool:EntrouReuni,
    AmID,
    AmongCor[40]
};

enum CorpoInfo
{
    bool:TemCorpo,
    Text3D:CorpoMensagem,
    CorpoID,
    CorpoDeQuem[40],
    Float:CorpoX,
    Float:CorpoY,
    Float:CorpoZ
};

enum CoresInfo
{
    CorNomeAmong[30],
    CorAmong[30]
};

new CoresAmong[][CoresInfo] =
{
    {"Azul", 0x00BFFF00},
    {"Ciano", 0x00FFFF00},
    {"Roxo", 0x9400D300},
    {"Rosa", 0xFF69B400},
    {"Vermelho", 0xFF000000},
    {"Branco", 0xFFFFFF00},
    {"Amarelo", 0xFFFF0000},
    {"Laranja", 0xFFA50000},
    {"Verde Claro", 0x7FFF0000},
    {"Verde Escuro", 0x228B2200},
    {"Marrom", 0xA0522D00}
};

enum ReuniaoInf
{
    Float:rNiaoX,
    Float:rNiaoY,
    Float:rNiaoZ,
    Float:rNiaoA
};

new ReuniaoLocal[][ReuniaoInf] =
{
    {1249.5024,-825.8740,1084.0078,356.4101},
    {1250.4208,-825.8734,1084.0078,358.0641},
    {1251.3109,-825.8759,1084.0078,359.8558},
    {1249.4966,-822.6578,1084.0078,177.7852},
    {1250.4257,-822.6578,1084.0078,177.7852},
    {1251.3469,-822.6572,1084.0078,178.8878},
    {1252.1630,-822.6577,1084.0078,180.9552},
    {1253.1934,-822.6578,1084.0078,180.8174},
    {1254.0996,-825.8848,1084.0078,358.6090},
    {1255.9805,-825.8740,1084.0078,355.8524},
    {1255.8301,-822.6577,1084.0078,185.5037}
};

new ReuniaoLocalMotel[][ReuniaoInf] =
{
    {2248.1936,-1189.6918,1029.8043,91.0852},
    {2248.2183,-1190.9338,1029.7969,87.9183},
    {2248.2268,-1192.4248,1029.7969,87.6427},
    {2248.2280,-1193.4814,1029.7969,75.9273},
    {2243.7527,-1194.3706,1029.7969,0.2598},
    {2242.4597,-1194.2050,1029.7969,359.2950},
    {2241.3428,-1194.3695,1029.7969,359.2950},
    {2240.3943,-1192.1465,1029.7969,181.9106},
    {2241.6841,-1192.2567,1029.7969,173.9165},
    {2246.1604,-1187.9745,1029.7969,175.9808},
    {2239.6873,-1193.2991,1029.7969,268.0498}
};

enum MapaTask
{
    bool:TextoCriado,
    Text3D:TextoTask
};


enum TaskInfo
{
    TaskNome[80],
    Float:TaskX,
    Float:TaskY,
    Float:TaskZ
};

new Task[][TaskInfo] =
{
    {"Lavar Pratos", 1280.3467,-808.9504,1085.6328},
    {"Desligar Televisão", 1238.2614,-820.1305,1083.1563},
    {"Consertar Jogo", 1274.6644,-837.8719,1085.6328},
    {"Arrumar Cama", 1292.2240,-815.5965,1089.9375},
    {"Arrumar Quadro", 1271.9902,-804.3839,1089.9299},
    {"Verificar Som", 1292.4600,-792.2359,1089.9375},
    {"Cortar Mato", 1279.4015,-778.4695,1090.7108},
    {"Entregar Relatório", 1232.0740,-810.9753,1084.0078},
    {"Trancar Cofre", 1230.7659,-807.1722,1084.0078},
    {"Regular Microfone", 1248.3171,-804.4749,1084.0151},
    {"Colocar Disco", 1254.7645,-804.7670,1084.0151},
    {"Fazer Bebidas", 1254.6700,-792.7340,1084.2344},
    {"Verificar Armário", 1224.6824,-772.7559,1084.0016},
    {"Arrumar Livros", 1295.3387,-831.6762,1085.6328},
    {"Jogar Basket", 1234.1125,-757.8215,1084.0150},
    {"Pegar Uniforme", 1226.3517,-772.7861,1084.0040},
    {"Regar Plantas", 1255.7881,-772.6137,1084.0078},
    {"Acender Lareira", 1274.8951,-822.2958,1089.9375},
    {"Arrumar Cadeiras", 1283.5909,-812.6695,1085.6328},
    {"Procurar CD", 1268.6566,-808.3604,1084.0078},
    {"Desligar PS5", 1276.5746,-792.8572,1084.0078},
    {"Trancar Porta", 1298.8929,-796.2915,1084.0078}
};

new TaskMotel[][TaskInfo] =
{
    {"Verificar Saltos", 2246.5410,-1159.7297,1029.7969},
    {"Desligar Televisão", 2233.7964,-1158.0887,1029.7969},
    {"Trancar Porta", 2235.1506,-1162.5714,1029.7969},
    {"Arrumar Cama", 2236.0303,-1166.9897,1029.7969},
    {"Fechar Cortina", 2228.0654,-1170.5190,1029.7969},
    {"Desvirar Móvel", 2243.9045,-1188.7869,1029.7969},
    {"Arrumar Banheira", 2205.0627,-1199.1763,1029.7969},
    {"Limpar Sujeira", 2186.4490,-1185.3440,1029.7969},
    {"Criado Mudo", 2196.3521,-1175.9619,1029.8043},
    {"Desligar Luz", 2190.5591,-1158.8824,1029.7969},
    {"Regar Muda", 2189.2813,-1146.4059,1029.7969},
    {"Cortar Planta", 2223.1946,-1141.8801,1025.7969},
    {"Verificar Recepção", 2217.3811,-1146.4077,1025.7969},
    {"Verificar Extintor", 2242.2993,-1152.0845,1029.7969},
    {"Fechar Criado Mudo", 2186.5527,-1151.4739,1029.7969},
    {"Arrumar Quadro", 2199.0112,-1147.3025,1029.7969}
};

enum JogadorInfoAmong
{
    TaskJaFeitas,
    bool:FazendoTask,
    FazendoTime
};

enum pLAPLA
{
    ID
};

enum Votacao
{
    VotacaoQ
};

// Configuração de Votos
new VotoTabela[MAX_AMONG];

// Configuração da Sala
new AmongVaga = MAX_AMONG;
new AmongImpostor = 1;
new AmongMapa = 0;

new AmongObjeto[4];
new bool:ReuniaoOnline;
new TempoReuniaoBotao;
new Text3D:TextoBotao;
new JogadorAmong[MAX_PLAYERS][JogadorInfoAmong]; // Informações pessoais
new mAmong[MAX_AMONG][CorpoInfo]; // Informação do Corpo
new Among[MAX_AMONG][JogadoresAmong]; // Global ID
new tAmong[MAX_PLAYERS][5][TaskJogador]; // Tasks Jogador ID
new pAmong[MAX_PLAYERS][pLAPLA]; // ID do Jogador
new AmongPartida[PartidaAmong]; // Informações da Partida
new tTasks[sizeof(Task)][MapaTask]; // Task ID
new aVotacao[MAX_AMONG][Votacao];

hook OnGameModeInit()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        switch(i)
        {
            case 0: VotoTabela[i] = 8;
            case 1: VotoTabela[i] = 9;
            case 2: VotoTabela[i] = 10;
            case 3: VotoTabela[i] = 11;
            case 4: VotoTabela[i] = 12; 
            case 5: VotoTabela[i] = 13;
            case 6: VotoTabela[i] = 14;
            case 7: VotoTabela[i] = 15;
            case 8: VotoTabela[i] = 16;
            case 9: VotoTabela[i] = 17;
            case 10: VotoTabela[i] = 18;
        }
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    pAmong[playerid][ID] = -1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(EventoID == 2)
    { 
        for(new i=0; i < MAX_AMONG; i++)
        {
            if(Among[i][AmongEntrou] == false) continue;   
            if(Among[i][AmID] != playerid) continue;
            RetirarAmong(i);
            if(EventoEstado == 2 && Among[i][Impostor] == true){
                if(ExisteImpostor() < 1) EnviarVitoria(2, "Impostor(es) Sairam"); 
            }
            else if(EventoEstado == 2 && Among[i][Impostor] == false){
                if(ExisteTripulantes() < 2) EnviarVitoria(1, "Tripulantes Quitaram");
            }
        }
    }
    
    ResetarJogador(playerid);
    return 1;
}

stock PrepararAmong()
{
    AlterarAmongMapa(0);
    format(AmongPartida[ImpostorNome], 30, "N/A");
    format(AmongPartida[ImpostorNome2], 30, "N/A");
    ReuniaoOnline = false;
    TempoReuniaoBotao = 0;
    for(new i=0; i < MAX_AMONG; i++){
        aVotacao[i][VotacaoQ] = 0;
    }
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
        if(!IsPlayerConnected(Among[i][AmID])) continue;
        SetPVarInt(Among[i][AmID], "EventoJogador", 2);
        TogglePlayerControllable(Among[i][AmID], 1);
        PlayAudioStreamForPlayer(Among[i][AmID], "https://www.dropbox.com/s/fxhj00djm8xj63a/Crewman_or_Impostor_amongs_us_-_Sound_Effects.mp3?dl=1");
    }
    GererImpostor();
    return 1;
}

stock GererImpostor()
{
    new raid,
        Cls = 0
    ;
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
            GameTextForPlayer(Among[i][AmID], "~r~Impostor(a)", 4000, 3);
            PlayerTextDrawSetString(Among[i][AmID], AmongTasks[Among[i][AmID]][2], "~r~Impostor(a)~w~~n~Among_Us");
            if(!strcmp(AmongPartida[ImpostorNome], "N/A")) format(AmongPartida[ImpostorNome], 30, PegarNick(Among[i][AmID]));
            else if(!strcmp(AmongPartida[ImpostorNome2], "N/A")) format(AmongPartida[ImpostorNome2], 30, PegarNick(Among[i][AmID]));
        }
        else
        {
            GameTextForPlayer(Among[i][AmID], "~b~Tripulante", 4000, 3);
            PlayerTextDrawSetString(Among[i][AmID], AmongTasks[Among[i][AmID]][2], "~b~Tripulante~w~~n~Among_Us");
            GerarMissao(i);
        }
    }
    return 1;
}

stock GerarMissao(i)
{
    new id = Among[i][AmID],
        Aleaid,
        asl
    ;
    for(new k=0; k < 5; k++)
    {
        for(new d=0; d < 9999; d++)
        {
            if(AmongMapa == 0) Aleaid = random(sizeof(Task));
            else if(AmongMapa == 1) Aleaid = random(sizeof(TaskMotel));

            for(new h=0; h < 5; h++)
            {   
                if(tAmong[id][h][TaskID] == Aleaid){
                    asl = 0;
                    break;
                }
                asl++;
            }
            if(asl >= 5) break;
        }
        asl = 0;
        tAmong[id][k][TaskID] = Aleaid;
        tAmong[id][k][TaskConcluida] = false;
    }
    AtualizarMissao(id);
    return 1;
}

stock AtualizarMissao(playerid)
{
    new Mensagem[128];
    for(new d=0; d < 5; d++)
    {
        if(AmongMapa == 0) format(Mensagem, sizeof(Mensagem), "%d. %s", d+1, Task[tAmong[playerid][d][TaskID]][TaskNome]);
        else if(AmongMapa == 1) format(Mensagem, sizeof(Mensagem), "%d. %s", d+1, TaskMotel[tAmong[playerid][d][TaskID]][TaskNome]);
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

stock EntrarAmong(playerid)
{
    new id = GerarJogadorID();
    if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais vagas para esse modo!");
    
    for(new i=0; i < 5; i++){
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmID] != playerid) continue;
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já entrou nesse modo!");
        return 1;
    }

    for(new i=0; i < 5; i++){
        tAmong[playerid][i][TaskID] = -1;
        tAmong[playerid][i][SecTask] = false;
        tAmong[playerid][i][TaskConcluida] = false;
    }

    ResetPlayerWeapons(playerid);
    SetPVarInt(playerid, "EventoJogador", 1);
    ResetarJogador(playerid);
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

    SetPlayerVirtualWorld(playerid, 2020);
    SetPlayerHealth(playerid, 100.0);
    Among[id][AmID] = playerid;
    Among[id][AmongVivo] = true;
    Among[id][AmongEntrou] = true;
    Among[id][Impostor] = false;
    Among[id][EntrouReuni] = false;
    pAmong[playerid][ID] = id;
    SetPVarInt(playerid, "ImpostorTempo", 0);
    format(Among[id][AmongCor], 30, CoresAmong[id][CorNomeAmong]);
    SetPlayerColor(playerid, CoresAmong[id][CorAmong]);
    MostrarTasks(playerid);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| AMONG | Você entrou no evento ( %s )", Among[id][AmongCor]);
    SendClientMessage(playerid, 0xFF8C00FF, Mensagem);

    return 1;
}

stock ResetarPartida()
{
    RemoverCorposAmong();
    AlterarAmongMapa(1); // Remover Portas etc..
    AlterarAmongMapa(4); // Remover Tasks


    for(new i=0; i < MAX_AMONG; i++){
        new ResetarTasDSAdks[CorpoInfo];
        mAmong[i] = ResetarTasDSAdks;
    }

    for(new i=0; i < MAX_AMONG; i++){
        if(Among[i][AmongEntrou] == false) continue;
        Among[i][AmongEntrou] = false;
        Among[i][Impostor] = false;
        SendClientMessage(Among[i][AmID], 0xFF8C00FF, "| EVENTO | O Evento foi cancelado e você foi expulso(a)");
        RetirarAmong(i);
    }

    AmongPartida[KickAmong] = 0;
    AmongPartida[MortesAmong] = 0;
    AmongPartida[Tassks] = 0;
    AmongPartida[AmongStatus] = 0;
    AmongPartida[TempoAmongVoto] = 0;
    return 1;
}

stock RetirarAmong(id)
{
    Among[id][AmongEntrou] = false;
    Among[id][Impostor] = false;
    
    new i = Among[id][AmID];
    OcultarTasks(i); // Remover Task
    if(Among[id][AmongVivo] == false) ModoEspectadorAmong(i, 0);
    if(ReuniaoOnline == true){
        if(Among[id][AmongVivo] == true) OcultarVotacaoAmong(i);
    }
    Jogador[i][uInteriorEx] = 0;
    SetPlayerVirtualWorld(i, 0);
    SetPlayerInterior(i, 0);
    TogglePlayerControllable(i, 1);
    SetPlayerPos(i, Jogador[i][uInteriorExP][0], Jogador[i][uInteriorExP][1], Jogador[i][uInteriorExP][2]);
    SetPlayerEmprego(i, Jogador[i][Profissao]);
    ResetarJogador(i);
    return 1;
}

stock ResetarJogador(playerid)
{
    if(JogadorAmong[playerid][FazendoTask] == true){
        KillTimer(JogadorAmong[playerid][FazendoTime]);
        JogadorAmong[playerid][FazendoTask] = false;
    }
    
    SetPVarInt(playerid, "EventoJogador", 0);
    for(new i=0; i < MAX_AMONG; i++){
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmID] != playerid) continue;
        Among[i][AmongEntrou] = false;
        Among[i][Impostor] = false;
        break;
    }
    
    new idddd = pAmong[playerid][ID];
    pAmong[playerid][ID] = -1;

    new ASJODAS[JogadorInfoAmong];
    JogadorAmong[playerid] = ASJODAS;

    if(idddd != -1){
        new ResetarJJ[JogadoresAmong];
        Among[idddd] = ResetarJJ;
    }
    return 1;
}

stock GerarJogadorID()
{
    new ida = -1;
    for(new i=0; i < MAX_AMONG; i++){
        if(Among[i][AmongEntrou] == true) continue;
        return i;
    }
    return ida;
}

stock ImpostorID()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][Impostor] == false) continue;
        return Among[i][AmID];
    }
    return -1;
}

stock EnviarVitoria(win, const GanhoMsg[])
{
    new Mensagem[128],
        idd = ImpostorID()
    ;

    if(win == 1) format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) Impostor(es) era %s[%d]", PegarNick(idd), idd);
    else if(win == 2) format(Mensagem, sizeof(Mensagem), "| EVENTO | Os Tripulantes ganharam ( Motivo: %s )", GanhoMsg);

    EnviarAmong(1, AmongPartida[ImpostorNome], AmongPartida[ImpostorNome2], AmongPartida[MortesAmong], AmongPartida[Tassks], AmongPartida[KickAmong], win, GanhoMsg);
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(win == 1) GameTextForPlayer(Among[i][AmID], "~r~Impostor(es) ~w~Ganharam", 5000, 4);
        else if(win == 2) GameTextForPlayer(Among[i][AmID], "~b~Tripulantes ~w~Ganharam", 5000, 4);
        SendClientMessage(Among[i][AmID], 0xFF8C00FF, Mensagem);
        PlayAudioStreamForPlayer(Among[i][AmID], "https://www.dropbox.com/s/4wu0rlbftr1mu5k/Among_Us_Victory_Sound.mp3?dl=1");
        RetirarAmong(i);
    }
    ResetarPartida();
    return 1;
}

stock PegarCorpoID()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(mAmong[i][TemCorpo] == true) continue;
        return i;
    }  
    return -1;
}

stock RemoverCorposAmong()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(mAmong[i][TemCorpo] == false) continue; 
        mAmong[i][TemCorpo] = false;
        DestroyDynamicActorEx(mAmong[i][CorpoID]);
        DestroyDynamic3DTextLabelEx(mAmong[i][CorpoMensagem]);
    }
    return 1;
}

stock AdicionarCorpoAmong(i)
{
    new id = Among[i][AmID],
        Float:cxPos[4],
        nc = PegarCorpoID(),
        Mensagem[128]
    ;
    GetPlayerPos(id, cxPos[0], cxPos[1], cxPos[2]);
    GetPlayerFacingAngle(id, cxPos[3]);

    format(Mensagem, sizeof(Mensagem), "Corpo do(a) {B22222}%s{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para reportar", Among[i][AmongCor]);
    format(mAmong[nc][CorpoDeQuem], 40, Among[i][AmongCor]);

    mAmong[nc][TemCorpo] = true;  
    
    switch(AmongMapa)
    {
        case 0:
        {
            mAmong[nc][CorpoID] = CreateDynamicActor(GetPlayerSkin(id), cxPos[0]+1, cxPos[1], cxPos[2], cxPos[3], 1, 100.0, 2020, 5, -1, 100.0, -1, 0);
            mAmong[nc][CorpoMensagem] = CreateDynamic3DTextLabel(Mensagem, -1, cxPos[0]+1, cxPos[1], cxPos[2], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2020, 5, -1, 20.0, -1);
        }
        case 1:
        {
            mAmong[nc][CorpoID] = CreateDynamicActor(GetPlayerSkin(id), cxPos[0]+1, cxPos[1], cxPos[2], cxPos[3], 1, 100.0, 2020, 15, -1, 100.0, -1, 0);
            mAmong[nc][CorpoMensagem] = CreateDynamic3DTextLabel(Mensagem, -1, cxPos[0]+1, cxPos[1], cxPos[2], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2020, 15, -1, 20.0, -1);
        }
    }
    
    
    mAmong[nc][CorpoX] = cxPos[0];
    mAmong[nc][CorpoY] = cxPos[1];
    mAmong[nc][CorpoZ] = cxPos[2];

    ApplyDynamicActorAnimation(mAmong[nc][CorpoID], "PED", "KO_skid_front", 4.1, 0, 1, 1, 1, 1);
    return 1;
}

stock AtualizarAmongVote(playerid, id, bool:locbuitc)
{
    new Mensagem[90];
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) format(Mensagem, sizeof(Mensagem), "%d. ~r~N/A", i+1);
        else
        {
            if(Among[Among[i][AmID]][Impostor] == true && Among[playerid][Impostor] == true){
                PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][VotoTabela[i]], -16777156);
                PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][VotoTabela[i]], 255);
            }

            if(Among[i][AmID] == id && locbuitc == true) format(Mensagem, sizeof(Mensagem), "%d. %s[%s] - ~b~Apertou Botão", i+1, PegarNick(Among[i][AmID]), Among[i][AmongCor]);
            else if(Among[i][AmID] == id) format(Mensagem, sizeof(Mensagem), "%d. %s[%s] - ~g~Reportou", i+1, PegarNick(Among[i][AmID]), Among[i][AmongCor]);
            else
            {
                if(Among[i][AmongVivo] == false) format(Mensagem, sizeof(Mensagem), "%d. %s[%s] - ~r~Morto(a)", i+1, PegarNick(Among[i][AmID]), Among[i][AmongCor]);
                else format(Mensagem, sizeof(Mensagem), "%d. %s[%s]", i+1, PegarNick(Among[i][AmID]), Among[i][AmongCor]);                  
            }
        }
        PlayerTextDrawColor(playerid, VoteAmong[playerid][VotoTabela[i]], -1);  
        PlayerTextDrawShow(playerid, VoteAmong[playerid][VotoTabela[i]]);  
        PlayerTextDrawSetString(playerid, VoteAmong[playerid][VotoTabela[i]], ConverterTexto(Mensagem));
    }
    return true;
}

stock IniciarReuniao(playerid, report = 99999)
{
    new Mensagem[128];

    // Apenas Reunião
    if(report == 99999) format(Mensagem, sizeof(Mensagem), "| REUNIÃO | %s[%s] pediu uma reunião", PegarNick(playerid), Among[pAmong[playerid][ID]][AmongCor]);
    else format(Mensagem, sizeof(Mensagem), "| REUNIÃO | %s[%s] reportou o corpo do(a) %s", PegarNick(playerid), Among[pAmong[playerid][ID]][AmongCor], mAmong[report][CorpoDeQuem]);

    ReuniaoOnline = true;
    RemoverCorposAmong();
    SetTimerEx("TempoVotacaoAmong", 1000, false, "d", 180);

    for(new i=0; i < MAX_AMONG; i++) 
    {
        if(Among[i][AmongEntrou] == false) continue;   
        if(Among[i][AmongVivo] == false){
            PlayAudioStreamForPlayer(Among[i][AmID], "https://www.dropbox.com/s/rjjw6cbhdqex2dg/Among_Us_Emergency_Meeting_-_Sound_Effect_HD.mp3?dl=1");
            continue;
        }
        
        if(AmongMapa == 0)
        {
            SetPlayerPos(Among[i][AmID], ReuniaoLocal[i][rNiaoX], ReuniaoLocal[i][rNiaoY], ReuniaoLocal[i][rNiaoZ]);  
            SetPlayerFacingAngle(Among[i][AmID], ReuniaoLocal[i][rNiaoA]);
        }
        else if(AmongMapa == 1)
        {
            SetPlayerPos(Among[i][AmID], ReuniaoLocalMotel[i][rNiaoX], ReuniaoLocalMotel[i][rNiaoY], ReuniaoLocalMotel[i][rNiaoZ]);  
            SetPlayerFacingAngle(Among[i][AmID], ReuniaoLocalMotel[i][rNiaoA]);  
        }
        
        SetCameraBehindPlayer(Among[i][AmID]);
        SendClientMessage(Among[i][AmID], 0xFF8C00FF, Mensagem);
        PlayAudioStreamForPlayer(Among[i][AmID], "https://www.dropbox.com/s/rjjw6cbhdqex2dg/Among_Us_Emergency_Meeting_-_Sound_Effect_HD.mp3?dl=1");
        SetPVarInt(Among[i][AmID], "EventoJogador", 1);
        MostrarVotacaoAmong(Among[i][AmID]);
        LimparChat(Among[i][AmID]);

        if(report == 99999) AtualizarAmongVote(Among[i][AmID], playerid, true);
        else AtualizarAmongVote(Among[i][AmID], playerid, false);
        Among[i][EntrouReuni] = true;
    } 
    return 1;
}

stock VerificarTasks(playerid, id)
{
    for(new i=0; i < 5; i++)
    {
        if(tAmong[playerid][i][TaskID] != id) continue;
        if(tAmong[playerid][i][TaskConcluida] == true)
        {
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa task já foi feita por você!");
            return false;
        }
        return true;
    }
    return false;
}

stock VerificarSeAindaTem()
{
    new id;
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmongVivo] == false) continue;
        if(Among[i][Impostor] == true) continue;
        id = Among[i][AmID];
        if(JogadorAmong[id][TaskJaFeitas] < 5) return true;
    }
    return false;
}

stock AtualizarMenu(playerid, i)
{
    new cco = -1,
        Mensagem[128],
        tabid
    ;
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
        case 0: format(NAkm, 30, Task[tAmong[playerid][i][TaskID]][TaskNome]);
        case 1: format(NAkm, 30, TaskMotel[tAmong[playerid][i][TaskID]][TaskNome]);
    }
    
    if(tAmong[playerid][i][TaskConcluida] == false) format(Mensagem, sizeof(Mensagem), "%d. %s", i+1, NAkm);
    else format(Mensagem, sizeof(Mensagem), "%d. %s", i+1, NAkm), cco = 16711935;  
    PlayerTextDrawColor(playerid, AmongTasks[playerid][tabid], cco); 
    PlayerTextDrawShow(playerid, AmongTasks[playerid][tabid]);
    PlayerTextDrawSetString(playerid, AmongTasks[playerid][tabid], ConverterTexto(Mensagem));
    return 1;
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

stock FinalizarVotacao()
{
    for(new i=0; i < MAX_AMONG; i++)
    {
        if(Among[i][AmongEntrou] == false) continue;
        Among[i][JaVotou] = false;
        Among[i][EntrouReuni] = false;
        SetPVarInt(Among[i][AmID], "EventoJogador", 2);
        OcultarVotacaoAmong(Among[i][AmID]);
        TogglePlayerControllable(Among[i][AmID], 1);
    }

    TempoReuniaoBotao = gettime()+50;
    ReuniaoOnline = false;
    ResultadoVotacao();
    return 1;
}

stock ResultadoVotacao()
{
    new vlrmax = -1,
        uservote = -1
    ;
    for(new i=0; i < MAX_AMONG; i++){
        if(Among[i][AmongEntrou] == false) continue;
        if(Among[i][AmongVivo] == false) continue;
        PlayAudioStreamForPlayer(Among[i][AmID], "https://www.dropbox.com/s/yoyxv7sexoksbtl/Among_Us_All_Vote_Out_Typing_-_Sound_Effect_HD.mp3?dl=1");
        if(aVotacao[i][VotacaoQ] > vlrmax && aVotacao[i][VotacaoQ] != 0){
            vlrmax = aVotacao[i][VotacaoQ];
            uservote = i;
        }
    }

    for(new i=0; i < MAX_AMONG; i++){
        aVotacao[i][VotacaoQ] = 0;
    }

    if(vlrmax > 1)
    {
        if(Among[uservote][Impostor] == true){
            RetirarAmong(uservote);
            if(ExisteImpostor() < 1) EnviarVitoria(2, "Impostor(es) Ejetado(s)"); 
        }
        else if(Among[uservote][Impostor] == false)
        {
            if(ExisteTripulantes() < 2) EnviarVitoria(1, "Tripulantes foram ejetados");
            else
            {
                AmongPartida[KickAmong]++;
                Among[uservote][AmongVivo] = false;
                new Mensagem[128],
                    Anuc[60],
                    Anucc[45]
                ;
                
                ModoEspectadorAmong(Among[uservote][AmID], Among[PegarImpostor()][AmID]);
                format(Mensagem, sizeof(Mensagem), "| AMONG | %s[%s] não era o(a) impostor(a)", PegarNick(Among[uservote][AmID]), Among[uservote][AmongCor]);
                
                format(Anucc, sizeof(Anucc), "%s [%s]", CoresAmong[uservote][CorAmong]);
                format(Anuc, sizeof(Anuc), "~y~%s~w~ não era impostor(a) - Restam: ~r~%d", PegarNick(Among[uservote][AmID]), ExisteImpostor());
                
                for(new i=0; i < MAX_AMONG; i++)
                {
                    if(Among[i][AmongEntrou] == false) continue;
                    SendClientMessage(Among[i][AmID], 0xFF8C00FF, Mensagem);
                    MostrarAmongMensagem(Among[i][AmID], Anucc, Anuc, 3000);
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

function TempoVotacaoAmong(tempo)
{
    if(ReuniaoOnline == false) return 1;
    if(tempo > 0)
    {
        tempo--;
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "Tempo: %s", SegundosParaMinutosEx(tempo));
        
        for(new i=0; i < MAX_AMONG; i++){
            if(Among[i][AmongEntrou] == false) continue;   
            if(Among[i][AmongVivo] == false) continue;
            if(Among[i][EntrouReuni] == false) continue;
            PlayerTextDrawSetString(Among[i][AmID], VoteAmong[Among[i][AmID]][4], ConverterTexto(Mensagem));
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
        if(!IsPlayerConnected(Among[i][AmID])) continue;
        GameTextForPlayer(Among[i][AmID], Contd, 5000, 4);
        PlayerPlaySound(Among[i][AmID], 1056, 0.0, 0.0, 0.0);
    }
    c--;
    SetTimerEx("IniciarContagemAmong", 1000, false, "d", c);
    return 1;
}

function FazendoTaskAlohaa(playerid, id)
{
    TogglePlayerControllable(playerid, 1);
    JogadorAmong[playerid][FazendoTask] = false;
    for(new i=0; i < 5; i++){
        if(tAmong[playerid][i][TaskID] != id) continue;
        tAmong[playerid][i][TaskConcluida] = true;
        AtualizarMenu(playerid, i);
        break;
    }
    JogadorAmong[playerid][TaskJaFeitas] += 1;
    AmongPartida[Tassks]++;

    if(JogadorAmong[playerid][TaskJaFeitas] >= 5) SendClientMessage(playerid, 0xFFFF00FF, "| AMONG | Você finalizou suas tasks!");
    else SendClientMessage(playerid, 0xFFFF00FF, "| AMONG | Você ainda tem tasks para fazer!");
    if(!VerificarSeAindaTem()) return EnviarVitoria(2, "Conclusão de Tasks");
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    // Sistema para reportar
    if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(pAmong[playerid][ID] == -1) return 1;

        for(new i=0; i < MAX_AMONG; i++)
        {
            if(mAmong[i][TemCorpo] == false) continue; 
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, mAmong[i][CorpoX], mAmong[i][CorpoY], mAmong[i][CorpoZ])) continue;
            IniciarReuniao(playerid, i);
            return 1;
        }

        if(IsPlayerInRangeOfPoint(playerid, 5.0, 1252.6251, -824.1965, 1084.8087) && AmongMapa == 0 || 
        IsPlayerInRangeOfPoint(playerid, 5.0, 2240.9395,-1193.2806,1029.7969) && AmongMapa == 1)
        {
            if(ReuniaoOnline == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode iniciar uma reunião");
            if(TempoReuniaoBotao > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode fazer reunião, aguarde.");
            IniciarReuniao(playerid, 99999);
            return 1;
        }
    }

    // Sistema para tasks
    else if(newkeys == KEY_WALK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(pAmong[playerid][ID] == -1) return 1;
        if(JogadorAmong[playerid][FazendoTask] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está fazendo uma task, aguarde");
        new id = pAmong[playerid][ID],
            taid = -1
        ;

        if(AmongMapa == 0){
            for(new i=0; i < sizeof(Task); i++){
                if(!IsPlayerInRangeOfPoint(playerid, 3.0, Task[i][TaskX], Task[i][TaskY], Task[i][TaskZ])) continue;
                if(!VerificarTasks(playerid, i)) continue;
                taid = i;
                break;
            }
        }
        else if(AmongMapa == 1){
            for(new i=0; i < sizeof(TaskMotel); i++){
                if(!IsPlayerInRangeOfPoint(playerid, 3.0, TaskMotel[i][TaskX], TaskMotel[i][TaskY], TaskMotel[i][TaskZ])) continue;
                if(!VerificarTasks(playerid, i)) continue;
                taid = i;
                break;
            }    
        }

        if(taid != -1)
        {
            if(Among[id][Impostor] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode fazer tasks!");
            TogglePlayerControllable(playerid, 0);
            JogadorAmong[playerid][FazendoTask] = true;
            JogadorAmong[playerid][FazendoTime] = SetTimerEx("FazendoTaskAlohaa", 6000, false, "dd", playerid, taid);

            new TaskN[30];
            switch(AmongMapa)
            {
                case 0: format(TaskN, 30, Task[taid][TaskNome]);
                case 1: format(TaskN, 30, TaskMotel[taid][TaskNome]);
            }

            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "| AMONG | Você está fazendo a task de %s", TaskN);
            SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
        }
    }

    // Sistema para matar
    else if(newkeys == KEY_NO && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(pAmong[playerid][ID] == -1) return 1;   
        new id = pAmong[playerid][ID];
        if(Among[id][Impostor] == false) return 1;
        
        if(GetPVarInt(playerid, "ImpostorTempo") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode matar ainda, aguarde!");
        new Float:iMp[3];
        GetPlayerPos(playerid, iMp[0], iMp[1], iMp[2]);
        for(new i=0; i < MAX_AMONG; i++)
        {
            if(id == i) continue;
            if(Among[i][AmongEntrou] == false) continue;   
            if(Among[i][AmongVivo] == false) continue;
            if(Among[i][Impostor] == true) continue;
            if(!IsPlayerInRangeOfPoint(Among[i][AmID], 5.0, iMp[0], iMp[1], iMp[2])) continue;

            if(JogadorAmong[Among[i][AmID]][FazendoTask] == true){
                KillTimer(JogadorAmong[Among[i][AmID]][FazendoTime]);
                JogadorAmong[Among[i][AmID]][FazendoTask] = false;
            }

            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "| AMONG | Você morreu para o(a) impostor(a) %s", PegarNick(playerid), playerid);
            SendClientMessage(Among[i][AmID], 0xFF8C00FF, Mensagem);
            
            format(Mensagem, sizeof(Mensagem), "| AMONG | Você matou o(a) %s(a)", Among[i][AmongCor]);
            SendClientMessage(playerid, 0xFF8C00FF, Mensagem);

            AmongPartida[MortesAmong]++;

            SetPVarInt(playerid, "ImpostorTempo", gettime()+25);
            PlayAudioStreamForPlayer(Among[i][AmID], "https://www.dropbox.com/s/8f2m5n0nav5vf2r/Among_us_death_sound.mp3?dl=1");

            Among[i][AmongVivo] = false;
            ModoEspectadorAmong(Among[i][AmID], playerid);
            AdicionarCorpoAmong(i);

            if(ExisteTripulantes() < 2) return EnviarVitoria(1, "Matou Todos");
            break;
        }
    }

    return 1;
}

hook OnPlayerClickAD_TXD(playerid, PlayerText:playertextid)
{

    if(playertextid == VoteAmong[playerid][19])
    {
        new id = pAmong[playerid][ID]; 
        if(Among[id][JaVotou] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já votou");
        Among[id][JaVotou] = true;

        PlayerTextDrawColor(playerid, VoteAmong[playerid][19], 16711935); 
        PlayerTextDrawShow(playerid, VoteAmong[playerid][19]);
        SendClientMessage(playerid, 0xFF8C00FF, "| VOTAÇÃO | Você pulou o seu voto");

        if(VerificarVotos()) return FinalizarVotacao();   
    }
    else
    {
        for(new i=0; i < MAX_AMONG; i++)
        {
            if(playertextid != VoteAmong[playerid][VotoTabela[i]]) continue;

            if(Among[i][AmongEntrou] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não está na partida!");
            if(Among[i][AmongVivo] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) já foi morto(a)");
            
            new id = pAmong[playerid][ID]; 
            if(Among[id][JaVotou] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já votou");
            
            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "| VOTAÇÃO | Você votou em %s[%s]", PegarNick(Among[i][AmID]), Among[i][AmongCor]);
            SendClientMessage(playerid, 0xFF8C00FF, Mensagem);

            Among[id][JaVotou] = true;
            aVotacao[i][VotacaoQ] += 1;

            PlayerTextDrawColor(playerid, VoteAmong[playerid][VotoTabela[i]], 16711935); 
            PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][VotoTabela[i]], 120);
            PlayerTextDrawShow(playerid, VoteAmong[playerid][VotoTabela[i]]);
            if(VerificarVotos()) return FinalizarVotacao();
            break;
        }
    }
    return 0;
}

stock ModoEspectadorAmong(playerid, id)
{
    if(GetPVarInt(playerid, "SpecPerm") == 0){
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

stock AmongMapaNome(id)
{
    new MapN[20];
    switch(id)
    {
        case 0: MapN = "Casa do Maddog";
        case 1: MapN = "Motel Jefferson";
    }
    return (MapN);
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
                for(new i=0; i < 4; i++){
                    DestroyDynamicObjectEx(AmongObjeto[i]);
                }
            }
            else if(AmongMapa == 1){
                for(new i=0; i < 4; i++){
                    DestroyDynamicObjectEx(AmongObjeto[i]);
                }   
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

stock ConfigurarAmong(playerid)
{
    new Dialog[180];
    strcatEx(Dialog, "{FFFFFF}Vagas: {00BFFF}%d\n", AmongVaga);
    strcatEx(Dialog, "{FFFFFF}Impostores: {FF0000}%d\n", AmongImpostor);
    strcatEx(Dialog, "{FFFFFF}Mapa: {FFA500}%s\n", AmongMapaNome(AmongMapa));
    strcat(Dialog, "{00FF00}Confirmar");
    Dialog_Show(playerid, AdminConfigAmong, DIALOG_STYLE_TABLIST, "{FF0000}Among US", Dialog, "Selecionar", "Fechar");
    return 1;
}


// Dialogs
Dialog:AdminConfigAmong(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, ConfigVagasAmong, DIALOG_STYLE_INPUT, "{FF0000}Vagas", "Coloque abaixo o tanto de vagas", "Selecionar", "Fechar");
        case 1: Dialog_Show(playerid, ConfigImpostoresAmong, DIALOG_STYLE_INPUT, "{FF0000}Impostores", "Coloque abaixo o tanto de impostores", "Selecionar", "Fechar");
        case 2:
        {
            new Dialog[90];
            for(new i=0; i < 2; i++)
            {
                strcatEx(Dialog, "%s\n", AmongMapaNome(i));
            }
            Dialog_Show(playerid, ConfigMapaAmong, DIALOG_STYLE_TABLIST, "{FF0000}Mapa", Dialog, "Selecionar", "Fechar");
        }
        case 3:
        {
            PrepararAmong();
            new Mensagem[128];
            EventoEstado = 1;
            EventoID = 2;
            format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) %s %s criou um evento de Among Us ( /IrEvento )", CargoAdmin(2, playerid), PegarNick(playerid));
            SendClientMessageToAll(0xFF8C00FF, Mensagem);
            EnviarAmong(0);
        }
    }
    return 1;
}

Dialog:ConfigVagasAmong(playerid, response, listitem, inputtext[])
{  
    if(!response) return ConfigurarAmong(playerid);
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque apenas números");
    if(id < 2 || id > MAX_AMONG) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Minimo ( 2 ) - Máximo ( 11 )");
    AmongVaga = id;
    ConfigurarAmong(playerid);
    return 1;
}

Dialog:ConfigImpostoresAmong(playerid, response, listitem, inputtext[])
{
    if(!response) return ConfigurarAmong(playerid);
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque apenas números");
    if(id < 1 || id > 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Minimo ( 1 ) - Máximo ( 2 )");
    AmongImpostor = id;
    ConfigurarAmong(playerid);
    return 1;
}

Dialog:ConfigMapaAmong(playerid, response, listitem, inputtext[])
{
    if(!response) return ConfigurarAmong(playerid);
    AmongMapa = listitem;
    ConfigurarAmong(playerid);
    return 1;
}