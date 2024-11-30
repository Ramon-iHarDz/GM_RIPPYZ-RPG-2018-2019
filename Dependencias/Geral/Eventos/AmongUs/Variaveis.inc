#define MAX_AMONG 11
#define MAX_TASKS 5


    
    



    // Novas Variaveis
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


// Tripulantes (Playerid)
enum JogadorAmongID
{
    bool:FazendoTask,
    FazendoTime,
    AmongID
};

// Trupulantes (ID)
enum AmongJogador
{
    bool:AmongEntrou,
    bool:AmongVivo,
    bool:AmongSaiu,
    bool:Impostor,
    bool:JaVotou,
    bool:EntrouReuni,
    AmongNome[30],
    TaskFeitas,
    JogadorID
};

// Sistema de Votação
enum TripulantesTextdraw
{
    CapaceteID,
    BoxID
};

// Tasks ( Por Player )
enum TaskJogador
{
    bool:SecTask,
    bool:TaskConcluida,
    TaskID
};

enum CorposAmong
{
    bool:CorpoChao,
    CorpoCor[30],
    Float:CorpoX,
    Float:CorpoY,
    Float:CorpoZ,
    Text3D:CorpoMensagem[90],
    CorpoActo
};

enum MapaTask
{
    bool:TextoCriado,
    Text3D:TextoTask
};

enum Votacao
{
    VotacaoQ
};

enum CoresInfo
{
    CorNomeAmong[30],
    CorAmong[30],
    CapaceteCOR[30]
};

new Capacetes[MAX_AMONG][TripulantesTextdraw],
    PlayerText:AmongTasks[MAX_PLAYERS][12],
    PlayerText:VoteAmong[MAX_PLAYERS][50],
    TripulanteNome[MAX_AMONG],
    JogadorTask[MAX_PLAYERS][MAX_TASKS][TaskJogador], // Tasks Jogador ID
    JogadorAmong[MAX_PLAYERS][JogadorAmongID],
    Among[MAX_AMONG][AmongJogador],
    AmongCorpo[MAX_AMONG][CorposAmong],
    aVotacao[MAX_AMONG][Votacao],
    AmongPartida[PartidaAmong], // Informações da Partida
    tTasks[sizeof(Task)][MapaTask],
    Mysss[MAX_PLAYERS];

new AmongVaga = MAX_AMONG,
    AmongImpostor = 1,
    AmongMapa = 0,
    AmongObjeto[4],
    bool:ReuniaoOnline,
    TempoReuniaoBotao,
    Text3D:TextoBotao;

new CoresAmong[][CoresInfo] =
{
    {"Azul", 0x00BFFF00, "0x00BFFFFF"},
    {"Ciano", 0x00FFFF00, "0x00FFFFFF"},
    {"Roxo", 0x9400D300, "0x9400D3FF"},
    {"Rosa", 0xFF69B400, "0xFF69B4FF"},
    {"Vermelho", 0xFF000000, "0xFF0000FF"},
    {"Branco", 0xFFFFFF00, "0xFFFFFFFF"},
    {"Amarelo", 0xFFFF0000, "0xFFFF00FF"},
    {"Laranja", 0xFFA50000, "0xFFA500FF"},
    {"Verde Claro", 0x7FFF0000, "0x7FFF00FF"},
    {"Verde Escuro", 0x228B2200, "0x228B22FF"},
    {"Marrom", 0xA0522D00, "0xA0522DFF"}
};