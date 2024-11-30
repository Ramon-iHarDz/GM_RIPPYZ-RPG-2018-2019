#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{

    CreateDynamicObject(1569, 1737.69568, 2112.03760, 11.15920,   0.00000, 0.00000, -90.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(1569, 1737.69568, 2109.07666, 11.15920,   0.00000, 0.00000, 90.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(2010, 1737.32776, 2112.25391, 11.28920,   0.00000, 0.00000, 0.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(2010, 1737.32776, 2108.82300, 11.28920,   0.00000, 0.00000, 0.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(1256, 1732.73926, 2116.28491, 11.93830,   0.00000, 0.00000, 90.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(1256, 1732.73926, 2105.16089, 11.93830,   0.00000, 0.00000, -90.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(11713, 1735.86157, 2104.78198, 12.77360,   0.00000, 0.00000, 90.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(11245, 1747.89172, 2079.17700, 19.97000,   0.00000, 0.00000, -90.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(11245, 1772.81372, 2079.17700, 19.97000,   0.00000, 0.00000, -90.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(983, 1773.16846, 2079.69604, 10.49560,   0.00000, 0.00000, 0.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(983, 1773.17078, 2073.31104, 10.49560,   0.00000, 0.00000, 0.00000, -1, -1, -1, 190.0, 190.0, -1);
    CreateDynamicObject(983, 1773.17676, 2066.93188, 10.49560,   0.00000, 0.00000, 0.00000, -1, -1, -1, 190.0, 190.0, -1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 710, 1767.7344, 2110.4766, 25.2109, 0.25);
    RemoveBuildingForPlayer(playerid, 710, 1723.7969, 2157.1094, 25.2109, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 1722.5078, 2083.8828, 19.0156, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1723.8125, 2081.2109, 10.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1723.3125, 2075.1094, 10.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 651, 1721.9688, 2072.1172, 10.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 651, 1723.1094, 2086.2266, 10.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1732.1328, 2073.1641, 10.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1735.7344, 2069.0625, 10.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 651, 1734.0078, 2072.1875, 10.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 651, 1737.0391, 2066.9609, 10.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 1724.0156, 2117.7109, 19.7266, 0.25);
    RemoveBuildingForPlayer(playerid, 753, 1725.5703, 2120.1172, 11.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 651, 1725.2578, 2118.7578, 11.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1753.2656, 2138.2500, 10.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 753, 1751.5313, 2139.9453, 9.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 645, 1755.7188, 2132.6328, 9.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 680, 1779.3047, 2071.2031, 9.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 680, 1778.7188, 2080.8281, 9.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1778.1719, 2066.3359, 9.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1779.0859, 2069.8984, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1777.8828, 2077.6641, 9.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1781.1875, 2066.2109, 10.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 652, 1783.0313, 2067.2422, 9.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1781.5547, 2071.5391, 10.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1783.5781, 2080.8281, 9.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1785.3750, 2079.8906, 9.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 1788.7031, 2066.1094, 19.0391, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1780.5391, 2086.2422, 10.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1778.7266, 2088.6016, 9.7734, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1778.5469, 2084.9063, 10.0469, 0.25);
    RemoveBuildingForPlayer(playerid, 652, 1783.9297, 2088.1406, 9.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 753, 1777.3281, 2102.3359, 9.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 651, 1777.8906, 2100.7969, 10.1953, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1777.4922, 2096.6797, 9.8281, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1788.1250, 2094.9141, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1780.5078, 2101.4609, 10.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1789.1328, 2073.0938, 10.0313, 0.25);
    RemoveBuildingForPlayer(playerid, 623, 1790.0391, 2072.0078, 9.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1789.3359, 2070.1172, 9.8516, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1794.9375, 2077.0781, 9.8516, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1792.3828, 2077.4141, 10.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1722.1406, 2151.7500, 10.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 680, 1729.0156, 2154.6719, 9.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 651, 1721.3594, 2153.0625, 10.1953, 0.25);
    RemoveBuildingForPlayer(playerid, 753, 1734.1094, 2149.9219, 9.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1731.8750, 2153.2500, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1735.4297, 2153.9922, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1719.9063, 2151.1953, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1732.8750, 2155.4141, 10.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 651, 1724.5000, 2147.0234, 10.7891, 0.25);
    RemoveBuildingForPlayer(playerid, 680, 1747.0234, 2149.2891, 9.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1743.1797, 2146.3984, 11.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1748.3047, 2149.2656, 10.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1745.8438, 2150.3672, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1741.7266, 2151.9141, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 759, 1743.0703, 2150.5781, 10.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 753, 1750.8672, 2146.7891, 9.9375, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 1746.7891, 2153.3203, 19.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1729.7344, 2155.9922, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 680, 1737.7031, 2157.0313, 9.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1737.3672, 2157.6016, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1733.9297, 2159.8125, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 682, 1722.6172, 2159.8203, 10.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 753, 1727.6953, 2155.9063, 9.9375, 0.25);
    return 1;
}