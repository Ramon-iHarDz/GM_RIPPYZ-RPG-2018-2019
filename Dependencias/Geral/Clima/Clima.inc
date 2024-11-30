#include <YSI_Coding\y_hooks>

enum ClimaInf
{
    LocalClima[90],
    Float:CMaxX,
    Float:CMaxY,
    Float:CMaxZ, 

    Float:CMinX,
    Float:CMinY,
    Float:CMinZ
};

enum ClimaNome
{
    ClimaX,
    NomeClima[90]
};

new ClimaEstilo[][ClimaNome] =
{
    {8, "Chuva"},
    {9, "Neblina"},
    {19, "Chuva de Areia"}
};

new Clima[][ClimaInf] =
{
    {"Vinewood", 1120.1492,-1688.8311,87.5118, 331.9673,-878.3484,44.8373},
    {"Los Santos", 50.9837,-3013.9773,-58.8821, 2105.2095,-412.1912,-82.5181},
    {"Las Colinas", 2019.7853,-610.8140,-65.1557, 2641.7053,-1423.4542,-45.3879},
    {"Red County", 1234.1180,-751.4053,56.8158, 2344.7937,329.7235,93.0051},
    {"Las Venturas", 3176.2532,549.7524,65.2200, 267.4856,2922.0464,76.0206},
    {"Redsands West", 2082.2346,1954.5765,65.7264, 1283.1028,2512.6052,28.3683},
    {"Fort Carson", -578.9258,497.3377,-59.9835, 277.5184,1437.0126,-36.1745},
    {"Tierra Robada", -1671.5549,2929.3979,2.5144, -170.1231,2346.0232,-0.5996},
    {"Bayside", -1888.3181,2108.9106,27.2994, -2994.5420,2738.8235,37.0995},
    {"San Fierro", -3288.8909,1657.8992,-33.2621, -1063.5387,-332.7444,-52.5390},
    {"Angel Pine", -850.6725,-3303.5229,-69.0000, -2415.5774,-1666.7111,5.577},
    {"Flinty Country", 180.5370,-1415.1417,-79.2881, -1081.5093,-1424.0278,-40.1853},
    {"Whetstone", -1772.1329,-1541.6475,-16.0526, -2272.8179,-291.6072,-40.5586},
    {"Garcia", -2210.5229,-373.7435,-30.8110, -2859.3076,411.9961,-98.7350}
};

new ClimaID,
    ClimaMax,
    ClimaArea,
    bool:ClimaAtivo,
    bool:Foucadc,
    Foudac
;

hook OnGameModeInit()
{
    switch(random(1))
    {
        case 0: normalclima = 1;
        case 1: normalclima = 18;
    }

    ClimaID = -1;
    ClimaMax = -1;
    GerarTempoClima();
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid) 
{
    if(areaid != ClimaArea) return 1;
    if(GetPVarInt(playerid, "ClimaChuva") == 1) return 1;
    new id = ClimaMax;
    SetPlayerWeather(playerid, ClimaEstilo[id][ClimaX]);
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{
    if(areaid != ClimaArea) return 1;
    SetPlayerWeather(playerid, normalclima);
    return 1;
}

function AdicionarClima()
{
    if(ClimaAtivo == true) DestroyDynamicAreaEx(ClimaArea);
    Foucadc = false;
    new id,
        asd
    ;
    for(new i=0; i < 99999; i++){
        asd = random(sizeof(Clima));
        if(asd == ClimaID) continue;
        id = asd;
        break;
    }

    ClimaAtivo = true;
    new Mensagem[128];
    ClimaID = id;
    ClimaMax = random(sizeof(ClimaEstilo));
    ClimaArea = CreateDynamicRectangle(Clima[id][CMinX], Clima[id][CMinY], Clima[id][CMaxX], Clima[id][CMaxY], 0, 0, -1);

    format(Mensagem, sizeof(Mensagem), "| NEWS | Previsão de %s na região de %s", ClimaEstilo[ClimaMax][NomeClima], Clima[id][LocalClima]);
    SendClientMessageToAll(0xFFFF00FF, Mensagem);
    GerarTempoClima();
    return 1;
}

stock GerarTempoClima()
{
    new temp = random(3-1)+1,
        TempFdn
    ;
    TempFdn = (temp*3600000);
    if(Foucadc == true) KillTimer(Foudac);
    Foudac = SetTimer("AdicionarClima", TempFdn, false);
    Foucadc = true;
    return 1;
}

CMD:alterarclima(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    AdicionarClima();
    return 1;
}