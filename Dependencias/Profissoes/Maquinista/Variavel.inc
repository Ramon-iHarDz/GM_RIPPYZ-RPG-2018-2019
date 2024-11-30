enum TremSpawn
{
    Float:TSpawnX,
    Float:TSpawnY,
    Float:TSpawnZ,
    Float:TSpawnA
};

enum MaquinistaJogador
{
    TCP,
    TIcon,
    TTempoT,
    bool:TIni
};

new TremS[][TremSpawn] =
{
    {2081.7937,-1953.7500,15.3495,271.9587},
    {2002.5925,-1953.7500,15.3495,271.9587},
    {1879.3777,-1953.7634,15.3227,271.9587},
    {1801.4403,-1953.8319,15.0995,271.9587},
    {1718.8081,-1953.7173,15.0995,271.9587},
    {-1944.2885,122.0552,27.2245,271.9587},
    {-1939.4995,206.2036,26.9114,271.9587}
};

new Estac[4];
new ETrem[sizeof(TremS)];
new pTrem[MAX_PLAYERS][MaquinistaJogador];