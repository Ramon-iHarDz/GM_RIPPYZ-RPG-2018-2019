
//Counter
#define     CounterServer           (3)
#define     CounterJogadores        (10)
#define     CounterTempo            (300)

//Arena
#define     ArenaServer             (10)

//Bandeira
#define     MAX_BANDEIRAS_SALA      (10)
#define     MAX_BANDEIRAS_JOGADOR   (20)


//Seleção
enum SelecaoDeMapas{
    MapaSelect[60]
};

new MapasCounter[][SelecaoDeMapas] =
{
    {"Dust 3"},
    {"Small"} 
};

enum NomeArena
{
    ArenaNomeH[60]
};

new ArenasID[][NomeArena] =
{
    {"Favela"},
    {"Canyon"}
};

//Jogador info
enum JogadorModos
{
    bool:Jogando,
    Sala,
    ModoAtl,
    Morte,
    Kill,
    Acumulado,
    TempoEntrar,
    TempoCurar
};

new pModo[MAX_PLAYERS][JogadorModos];



//Counter
enum MapasInfo
{
    Mapa[60],
    Estado,
    Jogadores,
    VirtualWorld,
    bool:Iniciou,
    Tempo,
    TempoPlayer
};
new pCounter[CounterServer][MapasInfo];



//Arena
enum KitsInfo
{
    ArmaA1,
    ArmaA2,
    ArmaA3,
    ArmaA4,
    ArmaA5
};

enum ArenaInfo
{
    ArenaDono[70],
    SenhaArena[70],
    MapaID,
    KitID,
    Jogadores,
    AreaArena,

    Text3D:ArenaTexto1,
    Text3D:ArenaTexto2,
    Text3D:ArenaTexto3,

    ArenaPick1,
    ArenaPick2,
    ArenaPick3
};

new pArmaArena[ArenaServer][KitsInfo];
new pArena[ArenaServer][ArenaInfo];



// Bandeira
/*enum BandeiraInfo
{
    Jogadores,
    BandeiraStatus,

    // Placar
    PlacarVermelho,
    PlacarAzul,

    // Equipes
    JogadoresVermelho,
    JogadoresAzul
};

enum JogadorBandeira
{
    bool:BandeiraPlayer,
    BandeiraID,
    BandeiraSala,
    TimeBandeira
};

new Bandeira[MAX_BANDEIRAS_SALA][BandeiraInfo];
new pBandeira[MAX_BANDEIRAS_SALA][MAX_BANDEIRAS_JOGADOR][JogadorBandeira];*/