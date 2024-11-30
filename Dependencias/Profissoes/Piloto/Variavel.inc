enum JogadorPiloto
{
    bool:AviaoPiloto,
    AviaoID,
    AviaoViagens,
    AviaoTipo,

    // Escada
    bool:AviaoEscada,
    AviaoEscadaID,

    // Configs
    AviaoTempo,
    AviaoMapa,
    AviaoCheck
};

enum AviaoPilotoS
{
    Float:PPosX,
    Float:PPosY,
    Float:PPosZ,
    Float:PPosA
};

new AviaoPos[][AviaoPilotoS] =
{
    {1962.9021,-2287.6902,13.4633,113.3397},
    {1962.4276,-2353.6570,13.4889,113.3411},
    {1963.9315,-2434.1824,13.4777,110.4271},
    {1845.8779,-2407.0762,13.4697,179.8375}
};

new AviaoDodo[][AviaoPilotoS] =
{
    {1904.8750,-2648.8030,14.0049,0.5643},
    {1870.8043,-2649.9814,14.0052,0.5643},
    {1838.3512,-2648.3870,14.0053,0.5643},
    {1804.5797,-2649.0498,14.0055,0.5643},
    {1772.2864,-2648.6067,14.0085,0.5643},
    {1737.9900,-2648.9084,14.0068,0.5643}
};

//new AeroBS;
new pPiloto[MAX_PLAYERS][JogadorPiloto];
new DodoID[sizeof(AviaoDodo)];
new AeroBS;
new AeroLS;