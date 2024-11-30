#include <YSI_Coding\y_hooks>

enum TransportadorSpawn
{
    Float:TrSpawnX,
    Float:TrSpawnY,
    Float:TrSpawnZ,
    Float:TrSpawnA
};

enum JogadorTransporte
{
    // Jogador
    bool:PegouVeiculo,
    VeiculoTransID,
    VeiculoTransOld,
    EmpTransAtual,

    // Infs
    bool:NaMao,
    bool:ComTexto,
    Text3D:TransTexto,

    // Dupla
    bool:ComDupla,
    DuplaID
};

enum TransporteEmp
{
    bool:EntregaAtiva,
    REntregas,
    TransIcone,
    TransCheck,
    EmpresaTransID
};

new TransporteSpawn[][TransportadorSpawn] = 
{
    {2208.8403,-2267.6079,13.6485,44.6245}, //  Veículo 0
    {2213.0378,-2264.0894,13.6483,44.3798}, //  Veículo 1
    {2215.6589,-2260.2739,13.6484,44.5326}, //  Veículo 2
    {2220.2610,-2256.0149,13.6483,46.9719}, //  Veículo 3
    {2222.7603,-2252.6965,13.6484,46.2969}, //  Veículo 4
    {2227.5396,-2248.8809,13.6485,45.5627}, //  Veículo 5
    {2175.1309,-2264.1709,13.4569,224.8454}, //  Veículo 6
    {2172.0229,-2268.7839,13.4699,224.9773}, //  Veículo 7
    {2168.7063,-2271.7285,13.4667,224.5714}, //  Veículo 8
    {2164.4792,-2276.0791,13.4679,226.2975}, //  Veículo 9
    {2160.4280,-2279.8586,13.4655,225.2396} //  Veículo 0
};

new pTransportador[MAX_PLAYERS][JogadorTransporte];
new pTransporte[MAX_PLAYERS][4][TransporteEmp];

hook OnPlayerDisconnect(playerid, reason)
{
    new id = pTransportador[playerid][DuplaID];
    if(pTransportador[playerid][PegouVeiculo] == true) DestroyVehicleEx(pTransportador[playerid][VeiculoTransID]); 
    if(pTransportador[playerid][NaMao] == true) RemovePlayerAttachedObject(playerid, 5); 

    DestroyDynamic3DTextLabelEx(pTransportador[playerid][TransTexto]);
    new FaixaRosa[TransporteEmp];
    for(new i=0; i < 4; i++)
    {
        if(pTransporte[playerid][i][EntregaAtiva] == true)
        {
            DestroyDynamicCPEx(pTransporte[playerid][i][TransCheck]);
            pTransporte[playerid][i][TransCheck] = INVALID_STREAMER_ID;
            DestroyDynamicMapIconEx(pTransporte[playerid][i][TransIcone]);

            // Remover infos do(a) parceiro(a)
            if(pTransportador[playerid][ComDupla] == true)
            {
                DestroyDynamicCPEx(pTransporte[id][i][TransCheck]);
                pTransporte[id][i][TransCheck] = INVALID_STREAMER_ID;
                DestroyDynamicMapIconEx(pTransporte[id][i][TransIcone]);    
            }
        }
        if(pTransportador[playerid][ComDupla] == true) pTransporte[id][i] = FaixaRosa;
        pTransporte[playerid][i] = FaixaRosa;
    }

    if(pTransportador[playerid][ComDupla] == true)
    {

        DestroyDynamic3DTextLabelEx(pTransportador[id][TransTexto]);
        DestroyDynamic3DTextLabelEx(pTransportador[playerid][TransTexto]);
        if(pTransportador[id][NaMao] == true)
        {
            RemovePlayerAttachedObject(id, 5);  
            ApplyAnimation(id, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
            pTransportador[id][NaMao] = false;
        }
        pTransportador[id][ComDupla] = false;
    }

    new Delatar[JogadorTransporte];
    pTransportador[playerid] = Delatar;
    return 1;
}