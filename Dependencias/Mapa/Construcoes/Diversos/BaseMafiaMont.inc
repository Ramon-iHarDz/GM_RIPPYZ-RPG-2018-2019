#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 785, -2823.9219, -1564.2734, 139.1250, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -2856.3906, -1542.4922, 134.5391, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -2867.5234, -1515.8359, 134.3047, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -2836.5625, -1597.4063, 138.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -2796.0625, -1582.7656, 139.1250, 0.25);
    RemoveBuildingForPlayer(playerid, 785, -2847.3359, -1483.7344, 134.4219, 0.25);
    RemoveBuildingForPlayer(playerid, 784, -2800.7188, -1488.3906, 141.8359, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -2867.5234, -1515.8359, 134.3047, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -2856.3906, -1542.4922, 134.5391, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -2836.5625, -1597.4063, 138.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -2847.3359, -1483.7344, 134.4219, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -2823.9219, -1564.2734, 139.1250, 0.25);
    RemoveBuildingForPlayer(playerid, 18267, -2816.1797, -1524.2813, 139.7656, 0.25);
    RemoveBuildingForPlayer(playerid, 18230, -2811.0313, -1523.9141, 140.1250, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -2796.0625, -1582.7656, 139.1250, 0.25);
    RemoveBuildingForPlayer(playerid, 694, -2800.7188, -1488.3906, 141.8359, 0.25);
    return 1;
}

hook OnGameModeInit()
{
    CreateDynamicActor(111, -2808.2461,-1514.9591,139.2891,89.3275, 1, 100.0, 0, 0, -1, 90.0, -1, 0);
    CreateDynamicObject(3264, -2786.99194, -1729.50537, 140.54556,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(19486, -2813.81567, -1513.72388, 140.90289,   0.00000, 0.00000, 270.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(16409, -2816.12720, -1583.23962, 140.32629,   0.00000, 0.00000, 180.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(13367, -2805.40161, -1555.81580, 150.90259,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3279, -2867.77246, -1545.72510, 138.30881,   0.00000, 0.00000, 359.47430, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3279, -2867.74878, -1491.49463, 135.30881,   0.00000, 0.00000, 359.47430, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3633, -2820.97192, -1578.71899, 140.83150,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(923, -2821.12329, -1585.38696, 141.25060,   0.00000, 0.00000, 270.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2975, -2820.97021, -1580.52148, 140.34700,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2975, -2820.96606, -1582.04993, 140.34700,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2975, -2820.94336, -1583.60486, 140.34700,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(944, -2815.62891, -1585.63586, 141.24451,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(944, -2815.62891, -1578.83691, 141.24451,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(922, -2815.65552, -1574.87024, 141.20911,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(18260, -2824.22900, -1522.69189, 139.84560,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1893, -2809.37622, -1515.58423, 143.31310,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1893, -2816.60205, -1581.27710, 145.76221,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3015, -2812.19019, -1578.32263, 140.46390,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(930, -2811.65283, -1586.11829, 140.86749,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3052, -2820.96265, -1582.08167, 142.05650,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2358, -2820.93750, -1583.57471, 142.03810,   0.00000, 0.00000, 129.39891, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3630, -2802.42920, -1598.69043, 141.89290,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3630, -2802.42920, -1601.69043, 141.89290,   0.00000, 0.00000, 180.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3066, -2814.59839, -1590.42615, 141.41631,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1893, -2816.60205, -1583.14709, 145.76221,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1893, -2818.52124, -1514.95422, 143.31310,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1893, -2818.52124, -1521.88416, 143.31310,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1893, -2809.36523, -1521.88416, 143.31310,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1893, -2809.37622, -1508.91516, 143.31310,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1893, -2818.52124, -1508.95618, 143.31310,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2115, -2809.16284, -1515.44836, 138.28470,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1550, -2809.11230, -1516.11353, 138.64590,   0.00000, 0.00000, 100.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1575, -2809.11353, -1514.48193, 139.03819,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1575, -2809.11353, -1514.81091, 139.03819,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1575, -2809.11353, -1514.62292, 139.17920,   0.00000, 0.00000, 25.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(350, -2809.41772, -1515.31067, 139.08530,   90.00000, 0.00000, 25.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1654, -2809.09692, -1515.67480, 139.27730,   0.00000, 0.00000, 290.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(348, -2809.20313, -1515.53760, 139.08560,   90.00000, 0.00000, 220.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(355, -2809.78589, -1514.26025, 138.56670,   15.00000, 270.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1756, -2818.03735, -1511.33936, 138.28560,   0.00000, 0.00000, 180.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1516, -2819.00684, -1507.60474, 138.47231,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(14772, -2818.98779, -1507.62354, 139.18510,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(19812, -2817.11401, -1511.46143, 138.80350,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1486, -2819.36841, -1507.96436, 139.14720,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2858, -2819.03906, -1509.35168, 138.28670,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2056, -2806.00781, -1518.15332, 139.56970,   0.00000, 0.00000, 270.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3027, -2809.48706, -1515.04016, 139.08580,   90.00000, 0.00000, 20.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2226, -2818.93164, -1511.99524, 138.27609,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(19831, -2810.61133, -1530.07690, 138.28600,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1432, -2818.96460, -1518.69238, 138.37840,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1432, -2818.96460, -1522.69141, 138.37840,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(11709, -2821.67114, -1514.80933, 138.96519,   0.00000, 0.00000, 90.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1756, -2818.03735, -1528.67944, 138.28560,   0.00000, 0.00000, 180.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1820, -2819.42456, -1526.80127, 138.28590,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(336, -2819.13525, -1526.15942, 138.81410,   90.00000, 0.00000, 25.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(335, -2818.62085, -1526.33447, 138.76590,   90.00000, 0.00000, 170.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(1575, -2818.95190, -1522.68835, 138.96640,   0.00000, 0.00000, 25.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(923, -2807.63110, -1528.90796, 139.16750,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2975, -2811.38257, -1528.75916, 138.26820,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2975, -2811.38257, -1527.52917, 138.26820,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2975, -2811.38257, -1526.32825, 138.26820,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2975, -2811.38257, -1528.75916, 139.82820,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3015, -2812.00342, -1527.97009, 139.98830,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(2567, -2809.14063, -1508.11377, 140.18840,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(922, -2818.83447, -1506.11206, 139.15260,   0.00000, 0.00000, 0.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    CreateDynamicObject(3577, -2820.46777, -1499.90161, 139.02071,   0.00000, 0.00000, 180.00000, -1, 0, -1, 350.0, 350.0, -1, 0);
    return 1;
}