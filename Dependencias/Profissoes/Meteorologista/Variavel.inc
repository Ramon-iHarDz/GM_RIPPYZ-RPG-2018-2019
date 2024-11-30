enum MetreoVeiculo
{
    Float:MeteoX,
    Float:MeteoY,
    Float:MeteoZ,
    Float:MeteoA
};

enum AntenaInfo
{
    Float:AntenaX,
    Float:AntenaY,
    Float:AntenaZ
};

enum MeteoroJogador
{
    bool:MeteoAlugado,
    MeteoID,
    AntenaID,

    // Ids
    MeteoIconID,
    Text3D:MeteoTextoID,

    // Valores
    bool:CarregandoDados,
    bool:EntregaRelatorio,

    // Timers
    bool:CarregarDados,
    bool:MMaleta,
    bool:AbertoAtras,
    Text3D:MaletaInn,
    CrDados,
    bool:Ativandoslt,
    SltTempo
};

new AntenaLOC[][AntenaInfo] = 
{
    {2832.2742,2708.9871,10.8203},
    {1261.6552,766.1816,10.8203},
    {2857.2332,-2127.5784,10.2529},
    {860.2471,319.6462,20.1208},
    {-2629.0376,-2282.6880,7.3854}
};

new MetroVeiculo[][MetreoVeiculo] = 
{
    {-2535.5449,-602.4467,132.6209,179.7489},
    {-2531.8628,-602.4730,132.6165,180.2230},
    {-2528.1331,-602.5458,132.6213,180.1033},
    {-2524.4338,-602.5885,132.6190,180.1331},
    {-2520.6917,-602.5261,132.6145,180.2740},
    {-2516.8992,-602.6503,132.6210,180.6380},
    {-2513.1765,-602.7266,132.6180,180.1447},
    {-2509.4900,-602.4501,132.6231,180.8242},
    {-2505.7244,-602.8666,132.6175,179.5321},
    {-2501.9668,-602.5558,132.6219,180.4262},
    {-2498.2402,-602.3958,132.6229,180.1049},
    {-2494.5437,-602.8090,132.6227,180.4994}
};

new pMeteo[MAX_PLAYERS][MeteoroJogador];