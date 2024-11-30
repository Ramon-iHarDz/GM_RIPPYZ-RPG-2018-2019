#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 3686, 2195.0859, -2216.8438, 15.9063, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2193.2578, -2286.2891, 14.8125, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2183.1719, -2237.2734, 14.8125, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2174.6406, -2215.6563, 15.1016, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2193.0625, -2196.6406, 15.1016, 0.25);
    RemoveBuildingForPlayer(playerid, 5305, 2198.8516, -2213.9219, 14.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3747, 2234.3906, -2244.8281, 14.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 3747, 2226.9688, -2252.1406, 14.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 3747, 2219.4219, -2259.5234, 14.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3747, 2212.0938, -2267.0703, 14.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 3747, 2204.6328, -2274.4141, 14.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2193.2578, -2286.2891, 14.8125, 0.25);
    RemoveBuildingForPlayer(playerid, 3569, 2204.6328, -2274.4141, 14.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 3569, 2212.0938, -2267.0703, 14.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 3569, 2219.4219, -2259.5234, 14.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3578, 2194.4766, -2242.8750, 13.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 2217.2188, -2250.3594, 16.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 3569, 2226.9688, -2252.1406, 14.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 3569, 2234.3906, -2244.8281, 14.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2183.1719, -2237.2734, 14.8125, 0.25);
    RemoveBuildingForPlayer(playerid, 3578, 2235.1641, -2231.8516, 13.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2174.6406, -2215.6563, 15.1016, 0.25);
    RemoveBuildingForPlayer(playerid, 3627, 2195.0859, -2216.8438, 15.9063, 0.25);
    RemoveBuildingForPlayer(playerid, 5244, 2198.8516, -2213.9219, 14.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2193.0625, -2196.6406, 15.1016, 0.25);
    return 1;
}

hook OnGameModeInit()
{
    //CreateDynamicObject(2933, 2240.91602, -2222.60938, 14.25710,   0.00000, 0.00000, 134.93518, -1, 0, -1, 400.0, 400.0, -1);
    //CreateDynamicObject(2933, 2227.31030, -2208.95264, 14.25710,   0.00000, 0.00000, 134.93520, -1, 0, -1, 400.0, 400.0, -1);
    //CreateDynamicObject(10829, 2236.68750, -2228.88477, 12.47470,   0.00000, 0.00000, 313.58307, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(2567, 2177.21851, -2245.06543, 14.36951,   0.00000, 0.00000, 314.43246, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(2974, 2180.61084, -2249.01685, 12.34021,   0.00000, 0.00000, 44.61407, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(5126, 2189.95728, -2214.76587, 27.42680,   0.00000, 0.00000, 314.82211, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(8077, 2195.09546, -2190.98584, 16.47672,   0.00000, 0.00000, 315.10184, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(8335, 2182.75391, -2206.89502, 16.53330,   0.00000, 0.00000, 315.10181, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(2934, 2163.35107, -2230.63037, 13.74210,   0.00000, 0.00000, 44.63190, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(8886, 2171.08398, -2214.34106, 15.79480,   0.00000, 0.00000, 134.98993, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(943, 2178.57935, -2217.64136, 13.16620,   0.00000, 0.00000, 44.91445, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(2991, 2164.82520, -2215.61816, 13.09840,   0.00000, 0.00000, 44.53481, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(2991, 2161.97925, -2218.41211, 13.09840,   0.00000, 0.00000, 44.53481, -1, 0, -1, 400.0, 400.0, -1);
    CreateDynamicObject(1390, 2191.64209, -2216.33130, 25.80184,   0.00000, 0.00000, 135.35374, -1, 0, -1, 400.0, 400.0, -1);
    return 1;
}