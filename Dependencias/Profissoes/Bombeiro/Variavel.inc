#define MAX_FOGOS (10)

enum VeiculoBombeiroSpawn
{
    Float:BSpawnX,
    Float:BSpawnY,
    Float:BSpawnZ,
    Float:BSpawnA
};

new BSpawn[][VeiculoBombeiroSpawn] =
{
    {1770.0167,2077.8274,11.0551,180.9219},
    {1763.5898,2077.7654,11.0554,181.2667},
    {1757.0953,2077.8228,11.0543,180.6753},
    {1750.8538,2077.8140,11.0562,180.1702},
    {1741.8420,2067.2339,11.0559,257.2407},
    {1741.5856,2081.5273,11.0554,270.7470},
    {1730.7606,2081.3875,11.0570,270.7467}
};

enum BombeiroJogador
{
    // Booleans
    bool:BombeiroVeiculo,
    bool:BombeiroRoupa,
    BombeiroVeiculoID,
    BombeiroIcone,

    bool:BombeiraDupla,
    bool:ApagandoFogo,
    DonoBombeiro,
    BombeiroTempo
};

enum BombeiroDupla
{
    bool:EmDuplaBombeiro
};

enum FogosInfo
{
    bool:FogoAtivo,
    PorcentagemFogo,
    FogoID,
    Text3D:TextoFogo,
    Float:FogoX,
    Float:FogoY,
    Float:FogoZ
};

new pFogo[MAX_PLAYERS][MAX_FOGOS][FogosInfo];
new pBombeiro[MAX_PLAYERS][BombeiroJogador];
new pBombeiroDupla[MAX_PLAYERS][MAX_PLAYERS][BombeiroDupla];