new PlayerText:RouboVeiculo[MAX_PLAYERS][8];
new PlayerText:TempoAssalto[MAX_PLAYERS][3];

#define MAX_LOCALROUBO 12

enum RouboLocalInfo
{
    bool:LocalAtivoRoubo,
    RouboVeiculoCheck,
    RouboVeiculoModelo
};

enum InfoRouboCheck
{
    Float:cRPosX,
    Float:cRPosY,
    Float:cRPosZ,

    Float:vRPosX,
    Float:vRPosY,
    Float:vRPosZ,
    Float:vRPosA
};

enum JogadorLadraoV
{
    RoubandoVeiculoStatus,
    VeiculoRouboID,
    TempoParaFugir,

    IDTempRoubo,

    RouboIcone1,
    RouboIcone2,
    RouboIcone3,

    RouboCheck1,
    RouboCheck2,
    RouboCheck3,

    CheckRoubo[MAX_LOCALROUBO],
    MappRoubo[MAX_LOCALROUBO]
};

new VeiculoRoubo[] =
{
    400, 402, 411, 412, 415, 429, 434, 
    451, 477, 489, 494, 495, 500, 502, 
    503, 506, 533, 535, 536, 541, 555, 
    558, 559, 560, 562, 565, 573, 579,
    580, 587, 589, 603
};

new CheckRoubos[][InfoRouboCheck] =
{
    {1600.9213,-1830.8284,13.4821, 1602.6526,-1824.8615,13.1643,271.2053},
    {1602.9550,-1559.5016,14.1864, 1602.5679,-1554.8064,13.4022,3.1158},
    {2696.2925,-1106.9066,69.5084, 2694.7126,-1110.0269,69.2417,91.7807},
    {664.5981,-1522.6840,14.8584, 664.2302,-1526.8744,14.5573,270.6774},
    {1523.7639,-765.1341,79.9453, 1516.5697,-765.0598,79.7060,136.2169},
    {2753.5313,-1952.8339,13.5469, 2750.8689,-1944.5652,13.2512,273.8592},
    {2611.6345,2057.3762,10.8130, 2606.8472,2055.1045,10.5242,89.1920},
    {1264.1235,2699.3538,10.8203, 1269.8792,2696.0454,10.5291,178.8927},
    {869.4379,1967.5548,10.8203, 878.4791,1964.9423,10.5247,268.9458},
    {-1672.7449,2493.7432,87.1566, -1666.0422,2495.3550,86.6840,278.8583},
    {-2527.1514,2242.8818,4.9844, -2528.7520,2250.5730,4.6827,336.9205},
    {-2851.6653,899.6973,44.0547, -2846.7378,893.6856,43.7261,271.0145}
};

new pLadraoV[MAX_PLAYERS][JogadorLadraoV];
new RouboLocal[MAX_LOCALROUBO][RouboLocalInfo];
new TempoRouboVeiculo;