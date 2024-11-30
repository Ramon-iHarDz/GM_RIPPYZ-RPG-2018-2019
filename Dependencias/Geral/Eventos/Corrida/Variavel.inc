// Corrida Infos
enum CorridaInfo
{
    bool:VagaC,
    bool:GanhouC,
    JogadorC,
    PosicaoC,
    VeiculoC,
    CheckpointC,
    MapCorridaC,

    // Objetos
    pO1,
    pO2,
    pO3,
    pO4
};

enum CorridaVeiculo
{
    bool:CorridaUsad,
    Float:CorridaVX,
    Float:CorridaVY,
    Float:CorridaVZ,
    Float:CorridaVA
};

enum CorridaCheckInfo
{
    bool:CheckUsad,
    Float:CheckVX,
    Float:CheckVY,
    Float:CheckVZ
};

// Corrida
new bool:CorridaConfig;
new bool:VeiculoFanstasma;
new CorridaModelo;
new CorridaSlot;
new CorridaCheck;
new PosicaoGanhou;
new pCorrida[150][CorridaInfo];
new CheckCorrida[150][CorridaCheckInfo];
new VeiculoCorrida[150][CorridaVeiculo];

// Veículos Mods
new bool:VeiculoPers;
new SlotVeiculoPers;


// Admin
new AdminCriando = -1;
new cChecks;
new CoVeiculos;


new Float:aCheck[MAX_PLAYERS][150][3];
new Float:AoVeiculos[MAX_PLAYERS][150][4];