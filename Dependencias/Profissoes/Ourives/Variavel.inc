enum JogadorOurives
{
    // Verificar se tenho veículo
    bool:PegouOVeiculo,
    VeiculoOID,
    ObjetoMadeiraOuro,

    // Floats
    Float:OuroPosX,
    Float:OuroPosY,
    Float:OuroPosZ,

    // 
    Text3D:TextoOID[2],
    PedraOuroID,

    // Processo
    bool:SegurandoCaixaOuro,
    bool:SegurandoPedraOuro,
    bool:SegurandoTextoOuro,
    IconeOuro,
    CheckOuro,

    CavandoStatus,
    OuriTempo 
};

enum CargasOuro
{
    bool:TemCaixa,
    CaixaOID
};

enum OurivesVeiculos
{
    Float:OuroX,
    Float:OuroY,
    Float:OuroZ,
    Float:OuroA
};

new SpawnOurives[][OurivesVeiculos] =
{
    {837.7201,868.7414,13.2439,203.8929},
    {843.1579,870.7352,13.4021,203.7398},
    {847.2816,872.6362,13.5141,203.7442},
    {851.6383,874.5255,13.4123,203.7441},
    {837.2535,839.1584,12.3033,25.5262},
    {841.9451,842.9757,12.6847,25.3812}
};

new pOurives[MAX_PLAYERS][JogadorOurives];
new pOCaixa[MAX_PLAYERS][5][CargasOuro];