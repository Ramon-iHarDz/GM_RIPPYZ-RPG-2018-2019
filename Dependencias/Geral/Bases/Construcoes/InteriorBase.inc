#include <YSI_Coding\y_hooks>

stock ColocarBaseObjeto(id)
{
    BaseObjeto[id][0] = CreateDynamicObject(2000, 1207.13123, 32.35922, 1011.45825,   0.00000, 0.00000, 0.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][1] = CreateDynamicObject(1535, 2119.22681, -2273.47632, 19.67440,   0.00000, 0.00000, -46.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][2] = CreateDynamicObject(18885, 2131.31226, -2284.63892, 20.75000,   0.00000, 0.00000, -137.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][3] = CreateDynamicObject(2206, 2125.37500, -2274.17310, 19.67270,   0.00000, 0.00000, 46.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][4] = CreateDynamicObject(2310, 2124.45557, -2272.85181, 20.10000,   0.00000, 0.00000, 136.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][5] = CreateDynamicObject(1775, 2134.50781, -2281.31616, 20.75000,   0.00000, 0.00000, -135.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][6] = CreateDynamicObject(956, 2132.97974, -2282.92554, 20.05000,   0.00000, 0.00000, 225.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][7] = CreateDynamicObject(2286, 2125.13037, -2279.11768, 21.80000,   0.00000, 0.00000, 135.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][8] = CreateDynamicObject(2283, 2120.31689, -2270.37524, 21.95470,   0.00000, 0.00000, 44.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][9] = CreateDynamicObject(2286, 2128.29175, -2282.37476, 21.80000,   0.00000, 0.00000, 135.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][10] = CreateDynamicObject(1893, 2121.48462, -2272.07886, 23.83950,   0.00000, 0.00000, 46.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][11] = CreateDynamicObject(1893, 2129.88770, -2280.57593, 23.83950,   0.00000, 0.00000, 53.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][12] = CreateDynamicObject(1893, 2125.63892, -2276.35645, 23.83950,   0.00000, 0.00000, 46.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][13] = CreateDynamicObject(19893, 2125.92407, -2273.87427, 20.60750,   0.00000, 0.00000, 50.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][14] = CreateDynamicObject(1742, 2121.61475, -2268.87891, 19.70000,   0.00000, 0.00000, 44.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][15] = CreateDynamicObject(2310, 2126.79736, -2274.34058, 20.10000,   0.00000, 0.00000, -44.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    BaseObjeto[id][16] = CreateDynamicObject(2310, 2125.27002, -2272.00830, 20.10000,   0.00000, 0.00000, 136.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    
    // Produc
    BaseObjeto[id][17] = CreateDynamicObject(11327, 2177.52148, -2255.64575, 16.19600,   0.00000, 0.00000, -45.00000, BaseVw(id), 0, -1, 120.00, 120.0, -1);
    return 1;
}

stock RemoverObjetoBase(id)
{
    for(new i=0; i < 18; i++){
        DestroyDynamicObjectEx(BaseObjeto[id][i]);
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 2964, -225.7422, 1396.2422, 27.3438, 0.25);
    RemoveBuildingForPlayer(playerid, 16780, -225.3359, 1400.2500, 29.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 16151, -223.1250, 1405.2734, 27.1016, 0.25);
    RemoveBuildingForPlayer(playerid, 16152, -228.5234, 1406.7266, 26.7656, 0.25);
    RemoveBuildingForPlayer(playerid, 16153, -225.7500, 1406.6953, 26.7656, 0.25);
    RemoveBuildingForPlayer(playerid, 16779, -225.3359, 1407.0469, 29.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 16154, -219.4375, 1407.3828, 26.7656, 0.25);
    RemoveBuildingForPlayer(playerid, 16155, -218.4219, 1407.4141, 28.3438, 0.25);

    // Produc
    RemoveBuildingForPlayer(playerid, 5171, 2124.9453, -2275.4531, 20.1406, 0.25);
    RemoveBuildingForPlayer(playerid, 3631, 2149.1406, -2266.9063, 12.8750, 0.25);
    RemoveBuildingForPlayer(playerid, 5260, 2161.3438, -2264.9141, 14.0156, 0.25);
    RemoveBuildingForPlayer(playerid, 3631, 2161.8516, -2264.0938, 16.3516, 0.25);
    RemoveBuildingForPlayer(playerid, 3631, 2163.3750, -2262.6875, 16.3516, 0.25);
    RemoveBuildingForPlayer(playerid, 3633, 2142.9141, -2256.3359, 13.9297, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2144.2969, -2258.1484, 13.9297, 0.25);
    RemoveBuildingForPlayer(playerid, 3631, 2142.3047, -2255.8984, 12.8750, 0.25);
    RemoveBuildingForPlayer(playerid, 5262, 2152.7109, -2256.7813, 15.2109, 0.25);
    RemoveBuildingForPlayer(playerid, 3633, 2158.0078, -2257.2656, 16.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3633, 2167.6641, -2256.7813, 12.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 3633, 2167.6641, -2256.7813, 13.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 3633, 2167.6641, -2256.7813, 14.6719, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2167.8047, -2257.3516, 16.3828, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2167.1719, -2257.1250, 16.4063, 0.25);
    RemoveBuildingForPlayer(playerid, 3577, 2170.0781, -2257.6641, 16.0391, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2169.3516, -2258.0703, 17.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2168.8281, -2257.5234, 17.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 3633, 2140.3828, -2254.1016, 13.9297, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2150.6641, -2251.5547, 12.7656, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2150.2813, -2250.8516, 12.7656, 0.25);
    RemoveBuildingForPlayer(playerid, 3633, 2150.6953, -2252.9141, 16.2344, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2149.8125, -2253.3672, 16.2344, 0.25);
    RemoveBuildingForPlayer(playerid, 5269, 2146.3750, -2248.7969, 14.6172, 0.25);
    RemoveBuildingForPlayer(playerid, 3633, 2153.7734, -2253.0859, 14.2031, 0.25);
    RemoveBuildingForPlayer(playerid, 3633, 2154.5078, -2254.4766, 14.2109, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2158.5703, -2251.0156, 15.8125, 0.25);
    RemoveBuildingForPlayer(playerid, 3632, 2158.0469, -2250.5078, 15.8125, 0.25);
    RemoveBuildingForPlayer(playerid, 5132, 2163.2891, -2251.6094, 14.1406, 0.25);
    RemoveBuildingForPlayer(playerid, 5259, 2168.8438, -2246.7813, 13.9375, 0.25);
    return 1;
}