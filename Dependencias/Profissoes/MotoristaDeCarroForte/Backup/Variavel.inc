enum CarFSpawn
{
    Float:FSpawnX,
    Float:FSpawnY,
    Float:FSpawnZ,
    Float:FSpawnA
};

enum CarroForteJogador
{
    CarregandoCF,
    CPBanco,
    CPCaixa,
    CFID,
    CaixaIDCF,

    CFTempo,

    CFIcone,
    CFPreco,
    CFCaixa,

    // Zero Coments
    bool:CFMaleta,
    bool:CFTexto,
    Text3D:CFTextoID

};

new CFSpawn[][CarFSpawn] =
{
    {1109.0006,1935.0726,10.9445,91.4306},
    {1108.9639,1926.2571,10.9442,89.4826},
    {1108.8971,1920.1533,10.9454,90.2186},
    {1108.9421,1911.4642,10.9446,90.8365}, 
    {1109.3240,1903.8322,10.9440,91.1223}, 
    {1109.1450,1896.4677,10.9446,90.8222},
    {1091.4160,1914.9939,10.9434,0.5506},
    {1082.6429,1914.7881,10.9429,359.4985},
    {1076.5740,1914.9440,10.9423,359.8084},
    {1067.7710,1914.8019,10.9439,0.3129},
    {1060.4111,1915.2021,10.9448,359.2862},
    {1052.8575,1915.2186,10.9445,0.5800}
};
 
new pCF[MAX_PLAYERS][CarroForteJogador];
new CarroF[sizeof(CFSpawn)];