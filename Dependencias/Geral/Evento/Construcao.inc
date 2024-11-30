#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 617, 1147.3672, 2722.9844, 9.4375, 0.25);
    RemoveBuildingForPlayer(playerid, 621, 1121.8438, 2732.4375, 9.8281, 0.25);
    RemoveBuildingForPlayer(playerid, 645, 1133.2109, 2741.0938, 9.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 645, 1130.4219, 2784.9219, 9.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 622, 1157.2344, 2783.4063, 9.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1129.9609, 2784.0234, 11.2891, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1127.1328, 2783.3672, 11.2891, 0.25);
    RemoveBuildingForPlayer(playerid, 645, 1122.1250, 2788.0234, 9.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 647, 1128.5859, 2786.9453, 11.2891, 0.25);
    RemoveBuildingForPlayer(playerid, 617, 1120.7266, 2810.2188, 9.4375, 0.25);
    return 1;
}

hook OnGameModeInit()
{
    new haska[327];
    haska[0] = CreateDynamicObject(987, 1405.9010, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[1] = CreateDynamicObject(987, 1417.8520, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[2] = CreateDynamicObject(987, 1393.9516, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[3] = CreateDynamicObject(987, 1382.0019, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[4] = CreateDynamicObject(987, 1370.0610, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[5] = CreateDynamicObject(987, 1358.1208, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[6] = CreateDynamicObject(987, 1346.1695, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[7] = CreateDynamicObject(987, 1334.2198, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[8] = CreateDynamicObject(987, 1298.3579, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[9] = CreateDynamicObject(987, 1322.2689, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[10] = CreateDynamicObject(987, 1310.3182, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[11] = CreateDynamicObject(987, 1274.4272, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[12] = CreateDynamicObject(987, 1286.3878, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[13] = CreateDynamicObject(987, 1262.4770, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[14] = CreateDynamicObject(987, 1244.5362, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[15] = CreateDynamicObject(987, 1250.5268, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[16] = CreateDynamicObject(987, 1232.5766, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[17] = CreateDynamicObject(987, 1226.5860, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[18] = CreateDynamicObject(987, 1214.6351, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[19] = CreateDynamicObject(987, 1202.6639, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[20] = CreateDynamicObject(987, 1130.9117, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[21] = CreateDynamicObject(987, 1190.6733, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[22] = CreateDynamicObject(987, 1178.7231, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[23] = CreateDynamicObject(987, 1166.7728, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[24] = CreateDynamicObject(987, 1154.8125, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[25] = CreateDynamicObject(987, 1142.8619, 2862.6845, 9.7719, 0.0000, 0.0000, 180.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[26] = CreateDynamicObject(18783, 1108.9786, 2804.9538, 10.0888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///FunBoxTop1
    haska[27] = CreateDynamicObject(987, 1119.0322, 2862.6845, 9.7719, 0.0000, 0.0000, 270.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[28] = CreateDynamicObject(987, 1119.0322, 2850.7346, 9.7719, 0.0000, 0.0000, 270.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[29] = CreateDynamicObject(987, 1119.0322, 2838.7924, 9.7719, 0.0000, 0.0000, 270.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[30] = CreateDynamicObject(18783, 1108.9786, 2776.0468, 10.0888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///FunBoxTop1
    haska[31] = CreateDynamicObject(987, 1154.8227, 2723.4631, 9.7719, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[32] = CreateDynamicObject(987, 1119.0322, 2826.8400, 9.7719, 0.0000, 0.0000, 270.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[33] = CreateDynamicObject(18783, 1108.9786, 2784.9821, 10.0888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///FunBoxTop1
    haska[34] = CreateDynamicObject(18783, 1081.3945, 2776.1350, 10.0888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///FunBoxTop1
    haska[35] = CreateDynamicObject(10830, 1095.2456, 2790.6125, 20.7723, 0.0000, 0.0000, 134.5997, -1, 0, -1, 900.0, 900.0, -1); ///drydock2_SFSe
    haska[36] = CreateDynamicObject(18783, 1088.9775, 2784.9821, 10.0888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///FunBoxTop1
    haska[37] = CreateDynamicObject(18783, 1081.3846, 2785.8068, 10.0888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///FunBoxTop1
    haska[38] = CreateDynamicObject(18783, 1088.9775, 2805.0017, 10.0888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///FunBoxTop1
    haska[39] = CreateDynamicObject(18783, 1081.3597, 2805.0017, 10.0888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///FunBoxTop1
    haska[40] = CreateDynamicObject(18783, 1088.9775, 2776.1350, 10.0888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///FunBoxTop1
    haska[41] = CreateDynamicObject(987, 1142.8636, 2723.4631, 9.7719, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[42] = CreateDynamicObject(19458, 1114.1667, 2766.0263, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[43] = CreateDynamicObject(987, 1130.9138, 2723.4631, 9.7719, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[44] = CreateDynamicObject(19458, 1104.5356, 2766.0415, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[45] = CreateDynamicObject(19458, 1094.9073, 2766.0615, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[46] = CreateDynamicObject(987, 1118.9930, 2723.4631, 9.7719, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[47] = CreateDynamicObject(19458, 1114.0218, 2815.0668, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[48] = CreateDynamicObject(987, 1118.9930, 2735.3828, 9.7719, 0.0000, 0.0000, 270.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[49] = CreateDynamicObject(19458, 1085.2772, 2766.0781, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[50] = CreateDynamicObject(19458, 1076.0760, 2766.0925, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[51] = CreateDynamicObject(19458, 1104.3902, 2815.0817, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[52] = CreateDynamicObject(19458, 1094.8492, 2815.0969, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[53] = CreateDynamicObject(19458, 1085.2596, 2815.1142, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[54] = CreateDynamicObject(19458, 1071.3326, 2771.0041, 10.9076, 0.0000, 0.3000, -179.9998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[55] = CreateDynamicObject(19458, 1076.1485, 2815.1281, 10.8956, 0.0000, 0.0000, -90.0998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[56] = CreateDynamicObject(987, 1118.9930, 2747.3232, 9.7719, 0.0000, 0.0000, 270.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[57] = CreateDynamicObject(987, 1118.9930, 2759.2941, 9.7719, 0.0000, 0.0000, 270.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[58] = CreateDynamicObject(987, 1118.9930, 2765.7951, 9.7719, 0.0000, 0.0000, 270.0000, -1, 0, -1, 900.0, 900.0, -1); ///elecfence_BAR
    haska[59] = CreateDynamicObject(19458, 1071.3330, 2810.4035, 10.8956, 0.0000, 0.0000, 0.0996, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[60] = CreateDynamicObject(19458, 1071.3498, 2800.7937, 10.8956, 0.0000, 0.0000, 0.0996, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[61] = CreateDynamicObject(19458, 1071.3806, 2792.1723, 7.4179, 0.0000, 0.3000, -179.9998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[62] = CreateDynamicObject(19458, 1071.3630, 2781.5415, 10.9076, 0.0000, 0.3000, -179.9998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[63] = CreateDynamicObject(19458, 1071.3630, 2791.1711, 10.9076, 0.0000, 0.3000, -179.9998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[64] = CreateDynamicObject(19458, 1071.3127, 2776.6569, 10.9075, 0.0000, 0.3000, -179.9998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[65] = CreateDynamicObject(19458, 1071.3806, 2782.6328, 7.4179, 0.0000, 0.3000, -179.9998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[66] = CreateDynamicObject(19447, 1118.9791, 2780.2954, 10.8430, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[66], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[67] = CreateDynamicObject(19458, 1071.3806, 2773.1530, 7.4179, 0.0000, 0.3000, -179.9998, -1, 0, -1, 900.0, 900.0, -1); ///wall098
    haska[68] = CreateDynamicObject(19447, 1118.9791, 2770.7343, 10.8430, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[68], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[69] = CreateDynamicObject(19450, 1071.6997, 2771.3039, 14.3388, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[69], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[70] = CreateDynamicObject(19447, 1118.9791, 2789.8754, 10.8430, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[70], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[71] = CreateDynamicObject(19447, 1118.9791, 2799.4660, 10.8430, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[71], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[72] = CreateDynamicObject(19447, 1118.9791, 2809.0461, 10.8430, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[72], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[73] = CreateDynamicObject(19450, 1071.7110, 2810.3071, 14.3190, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[73], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[74] = CreateDynamicObject(19447, 1118.8990, 2810.3264, 10.8430, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[74], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[75] = CreateDynamicObject(19447, 1114.1494, 2815.1059, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[75], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[76] = CreateDynamicObject(19450, 1071.7110, 2810.3071, 17.7490, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[76], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[77] = CreateDynamicObject(19450, 1071.7110, 2810.3071, 21.2390, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[77], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[78] = CreateDynamicObject(19450, 1071.7110, 2800.7431, 21.2290, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[78], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[79] = CreateDynamicObject(19450, 1071.7110, 2800.7446, 14.3189, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[79], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[80] = CreateDynamicObject(19450, 1071.7110, 2800.7446, 17.7388, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[80], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[81] = CreateDynamicObject(19447, 1104.5693, 2815.1059, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[81], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[82] = CreateDynamicObject(19450, 1071.6997, 2771.3039, 17.8390, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[82], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[83] = CreateDynamicObject(19447, 1095.0091, 2815.1059, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[83], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[84] = CreateDynamicObject(19450, 1071.6997, 2771.3039, 21.2490, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[84], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[85] = CreateDynamicObject(19447, 1085.4293, 2815.1259, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[85], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[86] = CreateDynamicObject(19447, 1071.2994, 2774.8215, 9.7826, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[86], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[87] = CreateDynamicObject(19450, 1071.7110, 2791.1208, 21.2290, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[87], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[88] = CreateDynamicObject(19450, 1071.7110, 2791.1208, 17.7290, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[88], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[89] = CreateDynamicObject(19447, 1076.0483, 2815.1459, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[89], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[90] = CreateDynamicObject(19450, 1071.7110, 2791.1208, 14.2390, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[90], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[91] = CreateDynamicObject(19450, 1071.7110, 2781.4904, 14.2390, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[91], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[92] = CreateDynamicObject(19450, 1071.7110, 2781.4904, 17.7390, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[92], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[93] = CreateDynamicObject(19450, 1071.7110, 2781.4904, 21.2289, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[93], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[94] = CreateDynamicObject(19450, 1071.7110, 2781.4904, 24.0188, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[94], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[95] = CreateDynamicObject(19447, 1071.3194, 2810.4165, 10.9027, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[95], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[96] = CreateDynamicObject(19450, 1071.7110, 2791.0515, 24.0188, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[96], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[97] = CreateDynamicObject(19450, 1071.7110, 2800.5808, 24.0188, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[97], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[98] = CreateDynamicObject(19450, 1071.7110, 2803.8300, 23.3187, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[98], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[99] = CreateDynamicObject(19450, 1071.7110, 2810.2819, 22.2789, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[99], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[100] = CreateDynamicObject(19447, 1071.3194, 2800.8762, 10.9027, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[100], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[101] = CreateDynamicObject(19450, 1071.6997, 2774.6557, 21.3390, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[101], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[102] = CreateDynamicObject(19450, 1071.6997, 2774.6557, 17.8390, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[102], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[103] = CreateDynamicObject(19447, 1071.3194, 2791.3164, 10.9027, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[103], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[104] = CreateDynamicObject(19450, 1071.7110, 2793.3315, 24.9988, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[104], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[105] = CreateDynamicObject(19447, 1071.2994, 2781.7365, 10.9027, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[105], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[106] = CreateDynamicObject(19450, 1071.7110, 2786.1718, 24.9988, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[106], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[107] = CreateDynamicObject(19450, 1071.6997, 2774.6557, 14.2988, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[107], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[108] = CreateDynamicObject(19447, 1071.2994, 2772.1853, 10.9027, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[108], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[109] = CreateDynamicObject(19450, 1071.7110, 2775.9011, 23.0389, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[109], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[110] = CreateDynamicObject(19450, 1071.7110, 2771.8183, 22.2488, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[110], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[111] = CreateDynamicObject(19447, 1071.2994, 2770.8339, 10.9027, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[111], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[112] = CreateDynamicObject(19447, 1071.2994, 2784.3425, 9.5129, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[112], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[113] = CreateDynamicObject(19447, 1071.2994, 2793.8715, 9.5129, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[113], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[114] = CreateDynamicObject(19450, 1071.6997, 2771.3039, 22.0590, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[114], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[115] = CreateDynamicObject(19447, 1076.0493, 2766.0751, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[115], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[116] = CreateDynamicObject(19450, 1071.6997, 2776.3674, 17.3889, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[116], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[117] = CreateDynamicObject(19447, 1085.5885, 2766.0651, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[117], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[118] = CreateDynamicObject(19447, 1095.1479, 2766.0551, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[118], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[119] = CreateDynamicObject(19447, 1103.2585, 2766.0351, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[119], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[120] = CreateDynamicObject(19447, 1112.7495, 2766.0151, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[120], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[121] = CreateDynamicObject(19450, 1095.1214, 2771.1337, 14.3388, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[121], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[122] = CreateDynamicObject(19447, 1114.0897, 2766.0151, 10.9130, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[122], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[123] = CreateDynamicObject(970, 1121.0782, 2814.9121, 10.3612, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[124] = CreateDynamicObject(970, 1123.1474, 2812.8527, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[125] = CreateDynamicObject(970, 1123.1474, 2808.7324, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[126] = CreateDynamicObject(970, 1123.1474, 2804.6015, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[127] = CreateDynamicObject(970, 1123.1474, 2800.4812, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[128] = CreateDynamicObject(970, 1123.1474, 2796.3500, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[129] = CreateDynamicObject(19450, 1071.7110, 2797.0673, 24.4888, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[129], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[130] = CreateDynamicObject(970, 1123.1474, 2792.2299, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[131] = CreateDynamicObject(19450, 1071.7110, 2790.8374, 25.7388, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[131], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[132] = CreateDynamicObject(970, 1123.1474, 2788.1005, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[133] = CreateDynamicObject(970, 1123.1474, 2783.9799, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[134] = CreateDynamicObject(970, 1123.1474, 2779.8503, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[135] = CreateDynamicObject(970, 1123.1474, 2775.7099, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[136] = CreateDynamicObject(970, 1123.1474, 2771.5800, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[137] = CreateDynamicObject(970, 1123.1474, 2768.0207, 10.3612, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[138] = CreateDynamicObject(970, 1121.0969, 2765.9602, 10.3612, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///fencesmallb
    haska[139] = CreateDynamicObject(14537, 1153.4377, 2814.1779, 11.7868, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///pdomesBar
    haska[140] = CreateDynamicObject(19129, 1108.9095, 2795.9267, 12.5439, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DanceFloor2
    haska[141] = CreateDynamicObject(19129, 1105.0891, 2776.0285, 12.5340, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DanceFloor2
    haska[142] = CreateDynamicObject(19129, 1105.0891, 2785.3981, 12.5242, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DanceFloor2
    haska[143] = CreateDynamicObject(19129, 1105.0898, 2805.1325, 12.5242, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DanceFloor2
    haska[144] = CreateDynamicObject(12843, 1168.1031, 2738.6140, 9.8247, 0.0000, 0.0000, -178.8999, -1, 0, -1, 900.0, 900.0, -1); ///cos_liquorshop
    SetDynamicObjectMaterial(haska[144], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    haska[145] = CreateDynamicObject(19129, 1108.9095, 2776.0285, 12.5439, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DanceFloor2
    haska[146] = CreateDynamicObject(16778, 1108.9090, 2808.8752, 8.4428, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///des_ufosign
    haska[147] = CreateDynamicObject(19129, 1108.9095, 2805.1384, 12.5340, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DanceFloor2
    haska[148] = CreateDynamicObject(19431, 1119.1540, 2790.5744, 26.9395, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall071
    SetDynamicObjectMaterialText(haska[148], 0, "R", 90, "Arial", 150, 1, 0xFFFFFFFF, 0x0, 0);
    haska[149] = CreateDynamicObject(16778, 1108.9090, 2772.2954, 8.4428, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///des_ufosign
    haska[150] = CreateDynamicObject(12844, 1171.0708, 2738.6738, 11.8065, 0.0000, 0.0000, -178.8999, -1, 0, -1, 900.0, 900.0, -1); ///cos_liqinside
    SetDynamicObjectMaterial(haska[150], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    haska[151] = CreateDynamicObject(1491, 1165.5576, 2743.3542, 9.7995, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///Gen_doorINT01
    SetDynamicObjectMaterial(haska[151], 0, 3853, "gay_xref", "ws_gayflag1", 0xFFFFFFFF);
    haska[152] = CreateDynamicObject(1537, 1177.5544, 2734.1572, 9.6141, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///Gen_doorEXT16
    haska[153] = CreateDynamicObject(19437, 1164.7600, 2743.3312, 10.4399, 0.0000, 0.0000, -88.8999, -1, 0, -1, 900.0, 900.0, -1); ///wall077
    SetDynamicObjectMaterial(haska[153], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[154] = CreateDynamicObject(19431, 1119.1540, 2791.0246, 25.3596, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall071
    SetDynamicObjectMaterialText(haska[154], 0, "C", 90, "Arial", 150, 1, 0xFFFFFFFF, 0x0, 0);
    haska[155] = CreateDynamicObject(19437, 1167.8691, 2743.3908, 10.4399, 0.0000, 0.0000, -88.8999, -1, 0, -1, 900.0, 900.0, -1); ///wall077
    SetDynamicObjectMaterial(haska[155], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    haska[156] = CreateDynamicObject(18844, 1103.6872, 2859.7990, 115.9692, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///WaterUVAnimSphere1
    SetDynamicObjectMaterial(haska[156], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[157] = CreateDynamicObject(19447, 1102.8602, 2863.1127, 67.3255, 0.0000, 90.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[157], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[158] = CreateDynamicObject(19447, 1106.9216, 2859.6823, 67.3255, 0.0000, 90.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[158], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[159] = CreateDynamicObject(19447, 1102.8602, 2859.9130, 67.3255, 0.0000, 90.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[159], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[160] = CreateDynamicObject(19447, 1102.8602, 2856.6230, 67.3255, 0.0000, 90.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[160], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[161] = CreateDynamicObject(19447, 1102.8602, 2856.6230, 164.5758, 0.0000, 90.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[161], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[162] = CreateDynamicObject(2773, 1165.0117, 2744.7641, 10.3289, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[163] = CreateDynamicObject(2773, 1167.6418, 2744.7641, 10.3289, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[164] = CreateDynamicObject(19447, 1102.8602, 2859.9221, 164.5758, 0.0000, 90.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[164], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[165] = CreateDynamicObject(19447, 1102.8602, 2863.2819, 164.5758, 0.0000, 90.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[165], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[166] = CreateDynamicObject(19447, 1107.2408, 2860.2211, 164.5758, 0.0000, 90.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall087
    SetDynamicObjectMaterial(haska[166], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[167] = CreateDynamicObject(19450, 1095.1214, 2771.1337, 17.7989, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[167], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[168] = CreateDynamicObject(19450, 1095.1214, 2771.1337, 21.2189, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[168], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[169] = CreateDynamicObject(19450, 1095.1214, 2780.7563, 21.2189, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[169], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[170] = CreateDynamicObject(19450, 1095.1214, 2780.7563, 17.7488, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[170], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[171] = CreateDynamicObject(19450, 1095.1214, 2780.7563, 14.2988, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[171], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[172] = CreateDynamicObject(18846, 1154.5904, 2810.6066, 95.5212, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BigCesar
    haska[173] = CreateDynamicObject(19450, 1095.1214, 2792.5063, 14.2988, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[173], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[174] = CreateDynamicObject(19450, 1095.1214, 2802.1171, 14.2988, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[174], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[175] = CreateDynamicObject(18846, 1167.9101, 2834.3569, 101.2113, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BigCesar
    haska[176] = CreateDynamicObject(19450, 1095.1214, 2810.0908, 14.2988, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[176], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[177] = CreateDynamicObject(18846, 1167.9101, 2857.8872, 99.0010, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BigCesar
    haska[178] = CreateDynamicObject(19450, 1095.1214, 2810.0734, 17.7688, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[178], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[179] = CreateDynamicObject(19450, 1095.1214, 2800.5449, 17.7688, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[179], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[180] = CreateDynamicObject(18846, 1103.6605, 2859.8283, 223.5012, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BigCesar
    haska[181] = CreateDynamicObject(19450, 1095.1214, 2792.5434, 17.7688, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[181], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[182] = CreateDynamicObject(19450, 1095.1214, 2792.5434, 21.2189, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[182], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[183] = CreateDynamicObject(19450, 1095.1214, 2802.1777, 21.2189, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[183], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[184] = CreateDynamicObject(19450, 1095.1214, 2810.0891, 21.2189, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[184], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[185] = CreateDynamicObject(19450, 1095.1214, 2792.5434, 24.7688, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[185], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[186] = CreateDynamicObject(19450, 1095.1214, 2802.1245, 23.5790, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[186], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[187] = CreateDynamicObject(19450, 1095.1214, 2796.3620, 24.3390, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[187], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[188] = CreateDynamicObject(19450, 1095.1214, 2806.3015, 22.3789, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[188], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[189] = CreateDynamicObject(19450, 1095.1214, 2782.9409, 22.3789, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[189], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[190] = CreateDynamicObject(19450, 1095.1214, 2784.1115, 24.0990, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[190], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[191] = CreateDynamicObject(18656, 1103.6728, 2859.0480, 224.6286, -90.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///LightBeamWhite
    haska[192] = CreateDynamicObject(19450, 1095.1214, 2786.3125, 24.6389, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[192], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[193] = CreateDynamicObject(19450, 1095.1214, 2778.7814, 22.2789, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall090
    SetDynamicObjectMaterial(haska[193], 0, 10765, "airportgnd_sfse", "black64", 0xFFFFFFFF);
    haska[194] = CreateDynamicObject(11687, 1155.6568, 2809.0258, 9.8163, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[195] = CreateDynamicObject(11687, 1157.3071, 2809.0258, 9.8163, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[196] = CreateDynamicObject(11687, 1158.6175, 2810.2956, 9.8163, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[197] = CreateDynamicObject(11687, 1158.6175, 2812.1174, 9.8163, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[198] = CreateDynamicObject(11687, 1148.3868, 2818.0986, 9.8261, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[199] = CreateDynamicObject(11687, 1151.3669, 2819.3789, 9.8261, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[200] = CreateDynamicObject(11687, 1149.6870, 2819.3789, 9.8261, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[201] = CreateDynamicObject(18092, 1115.9038, 2790.9213, 13.0572, 0.0000, 0.0000, -90.0000, -1, 0, -1, 900.0, 900.0, -1); ///ammun3_counter
    SetDynamicObjectMaterial(haska[201], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
    haska[202] = CreateDynamicObject(19431, 1163.8331, 2743.4467, 10.1646, 0.0000, 0.0000, 90.5998, -1, 0, -1, 900.0, 900.0, -1); ///wall071
    SetDynamicObjectMaterialText(haska[202], 0, "VIP", 90, "Segoe UI", 55, 1, 0xFFD78E10, 0x0, 0);
    haska[203] = CreateDynamicObject(14537, 1236.0897, 2750.7827, 11.9968, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///pdomesBar
    haska[204] = CreateDynamicObject(19158, 1170.9145, 2783.9682, 11.1695, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///MetalLightBars2
    haska[205] = CreateDynamicObject(11687, 1230.8248, 2753.1066, 9.8395, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[206] = CreateDynamicObject(11687, 1230.9543, 2747.5139, 9.9294, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[207] = CreateDynamicObject(11687, 1230.9543, 2748.5249, 9.9294, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[208] = CreateDynamicObject(18694, 1118.4913, 2778.9042, 12.4538, 90.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///flamethrower
    SetDynamicObjectMaterial(haska[208], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    haska[209] = CreateDynamicObject(18694, 1118.4913, 2805.0349, 12.4538, 90.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///flamethrower
    SetDynamicObjectMaterial(haska[209], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    haska[210] = CreateDynamicObject(2232, 1136.3083, 2750.0292, 10.4062, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[211] = CreateDynamicObject(14820, 1116.0946, 2790.9138, 13.6208, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///dj_stuff
    haska[212] = CreateDynamicObject(18694, 1118.4913, 2805.0349, 12.4538, 90.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///flamethrower
    SetDynamicObjectMaterial(haska[212], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    haska[213] = CreateDynamicObject(3872, 1113.6474, 2771.9628, 17.0743, 0.0000, 0.0000, -124.5998, -1, 0, -1, 900.0, 900.0, -1); ///WS_floodbeams
    haska[214] = CreateDynamicObject(18694, 1118.4913, 2778.9042, 12.4538, 90.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///flamethrower
    SetDynamicObjectMaterial(haska[214], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
    haska[215] = CreateDynamicObject(11687, 1230.8248, 2754.0976, 9.8395, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///CBarStool1
    haska[216] = CreateDynamicObject(3872, 1113.0323, 2808.2666, 18.3071, 0.0000, 0.0000, 101.3001, -1, 0, -1, 900.0, 900.0, -1); ///WS_floodbeams
    haska[217] = CreateDynamicObject(19129, 1170.8183, 2783.8984, 9.8442, 0.0000, 179.9998, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DanceFloor2
    haska[218] = CreateDynamicObject(19129, 1170.8183, 2783.8984, 14.7539, 0.0000, 179.9998, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DanceFloor2
    haska[219] = CreateDynamicObject(19893, 1115.9892, 2792.4411, 13.5439, 0.0000, 0.0000, -64.9999, -1, 0, -1, 900.0, 900.0, -1); ///LaptopSAMP1
    haska[220] = CreateDynamicObject(1954, 1115.9195, 2788.9360, 13.6426, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///turn_table_R
    haska[221] = CreateDynamicObject(981, 1477.3883, 2526.1166, 10.3655, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///helix_barrier
    haska[222] = CreateDynamicObject(1422, 1480.9613, 2524.8869, 10.0284, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[223] = CreateDynamicObject(981, 1247.4536, 2626.3398, 10.4670, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///helix_barrier
    haska[224] = CreateDynamicObject(19793, 1118.5096, 2777.3176, 12.5867, -2.4999, 91.5998, 85.0998, -1, 0, -1, 900.0, 900.0, -1); ///FireWoodLog1
    SetDynamicObjectMaterial(haska[224], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[225] = CreateDynamicObject(19793, 1118.4609, 2803.4594, 12.5801, -2.4999, 91.5998, 85.0998, -1, 0, -1, 900.0, 900.0, -1); ///FireWoodLog1
    SetDynamicObjectMaterial(haska[225], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    haska[226] = CreateDynamicObject(19421, 1115.9707, 2792.8264, 13.5733, 0.0000, 0.0000, -27.6000, -1, 0, -1, 900.0, 900.0, -1); ///headphones01
    haska[227] = CreateDynamicObject(19299, 1116.2694, 2790.7138, 18.7588, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///PointLightMoon1
    haska[228] = CreateDynamicObject(19146, 1109.4853, 2767.0461, 21.7688, 0.0000, 0.0000, -32.7999, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[229] = CreateDynamicObject(2232, 1115.8620, 2794.1179, 13.1464, 0.0000, 0.0000, 113.9999, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[230] = CreateDynamicObject(19610, 1116.0594, 2789.5708, 13.5733, 0.0000, 0.0000, 62.5998, -1, 0, -1, 900.0, 900.0, -1); ///Microphone1
    haska[231] = CreateDynamicObject(16151, 1170.0361, 2734.9592, 10.1596, 0.0000, 0.0000, -89.4999, -1, 0, -1, 900.0, 900.0, -1); ///ufo_bar
    SetDynamicObjectMaterial(haska[231], 0, 10041, "archybuild10", "whitedecosfe4", 0xFFFFFFFF);
    haska[232] = CreateDynamicObject(19146, 1109.4853, 2767.0461, 21.0687, 0.0000, 0.0000, -32.7999, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[233] = CreateDynamicObject(2232, 1115.8553, 2787.7863, 13.1464, 0.0000, 0.0000, 68.7996, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[234] = CreateDynamicObject(2232, 1115.8620, 2794.1179, 14.3365, 0.0000, 0.0000, 113.9999, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[235] = CreateDynamicObject(19146, 1109.4853, 2767.0461, 22.3187, 0.0000, 0.0000, -32.7999, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[236] = CreateDynamicObject(19146, 1110.5356, 2766.3684, 22.3187, 0.0000, 0.0000, -32.7999, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[237] = CreateDynamicObject(2232, 1115.8553, 2787.7863, 14.3365, 0.0000, 0.0000, 68.7996, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[238] = CreateDynamicObject(19146, 1110.5356, 2766.3684, 21.7289, 0.0000, 0.0000, -41.5998, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[239] = CreateDynamicObject(19146, 1110.5356, 2766.3684, 21.0988, 0.0000, 0.0000, -41.5998, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[240] = CreateDynamicObject(1422, 1583.7015, 2643.8217, 10.0352, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[241] = CreateDynamicObject(1280, 1177.4195, 2737.5417, 10.2151, 0.0000, 0.0000, 1.0000, -1, 0, -1, 900.0, 900.0, -1); ///parkbench1
    SetDynamicObjectMaterial(haska[241], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    haska[242] = CreateDynamicObject(1422, 1590.9388, 2643.8337, 10.0308, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[243] = CreateDynamicObject(1422, 1243.8739, 2625.0134, 10.0362, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[244] = CreateDynamicObject(1422, 1251.0751, 2625.0134, 10.0362, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[245] = CreateDynamicObject(1422, 1473.8704, 2524.8869, 10.0284, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[246] = CreateDynamicObject(981, 1384.8187, 2516.3815, 10.5603, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///helix_barrier
    haska[247] = CreateDynamicObject(1958, 1115.5609, 2792.9489, 13.5374, 0.0000, 0.0000, 178.8999, -1, 0, -1, 900.0, 900.0, -1); ///mxr_mix_body
    haska[248] = CreateDynamicObject(2448, 1164.5229, 2738.6059, 9.7916, 0.0000, 0.0000, 91.1996, -1, 0, -1, 900.0, 900.0, -1); ///CJ_FF_CONTER_5d
    haska[249] = CreateDynamicObject(2232, 1118.4311, 2775.4196, 13.1962, 0.0000, 0.0000, 102.9000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[250] = CreateDynamicObject(2232, 1118.3957, 2779.1145, 13.1962, 0.0000, 0.0000, 70.0998, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[251] = CreateDynamicObject(1422, 1381.1623, 2516.1506, 10.2583, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[252] = CreateDynamicObject(2232, 1118.4206, 2801.5754, 14.3563, 0.0000, 0.0000, 102.9000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[253] = CreateDynamicObject(2232, 1118.3829, 2805.2270, 13.1962, 0.0000, 0.0000, 70.0998, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[254] = CreateDynamicObject(1422, 1388.4936, 2516.1506, 10.2583, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[255] = CreateDynamicObject(981, 1894.3670, 2713.3532, 10.4385, 0.0000, 0.0000, 87.9000, -1, 0, -1, 900.0, 900.0, -1); ///helix_barrier
    haska[256] = CreateDynamicObject(1422, 1894.5073, 2709.7741, 9.9933, 0.0000, 0.0000, -93.7000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[257] = CreateDynamicObject(2232, 1118.3829, 2805.2270, 14.3765, 0.0000, 0.0000, 70.0998, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[258] = CreateDynamicObject(1422, 1894.9709, 2716.9404, 9.9933, 0.0000, 0.0000, -93.7000, -1, 0, -1, 900.0, 900.0, -1); ///DYN_ROADBARRIER_5
    haska[259] = CreateDynamicObject(981, 1587.3166, 2643.9775, 10.4873, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///helix_barrier
    haska[260] = CreateDynamicObject(19123, 1264.5754, 2819.0749, 10.3366, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BollardLight3
    haska[261] = CreateDynamicObject(2232, 1118.3957, 2779.1145, 14.3662, 0.0000, 0.0000, 70.0998, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[262] = CreateDynamicObject(19123, 1282.7028, 2788.0729, 10.3296, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BollardLight3
    haska[263] = CreateDynamicObject(2232, 1118.4206, 2801.5754, 13.1962, 0.0000, 0.0000, 102.9000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[264] = CreateDynamicObject(19123, 1277.8607, 2769.7824, 10.3582, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BollardLight3
    haska[265] = CreateDynamicObject(19123, 1317.1557, 2847.1960, 10.4040, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BollardLight3
    haska[266] = CreateDynamicObject(19123, 1392.9968, 2823.3796, 10.3867, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BollardLight3
    haska[267] = CreateDynamicObject(19123, 1390.4888, 2732.1738, 10.4076, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///BollardLight3
    haska[268] = CreateDynamicObject(19146, 1111.1529, 2814.8220, 23.0988, 0.0000, 0.0000, -174.5997, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[269] = CreateDynamicObject(2232, 1118.4311, 2775.4196, 14.3365, 0.0000, 0.0000, 102.9000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[270] = CreateDynamicObject(19146, 1111.1529, 2814.8220, 23.6690, 0.0000, 0.0000, -174.5997, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[271] = CreateDynamicObject(19146, 1111.1529, 2814.8220, 22.5088, 0.0000, 0.0000, -174.5997, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[272] = CreateDynamicObject(19146, 1112.4162, 2814.6301, 22.2789, 0.0000, 0.0000, -174.5997, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[273] = CreateDynamicObject(19146, 1112.4162, 2814.6301, 22.9188, 0.0000, 0.0000, -174.5997, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[274] = CreateDynamicObject(19146, 1112.4162, 2814.6301, 23.5090, 0.0000, 0.0000, -174.5997, -1, 0, -1, 900.0, 900.0, -1); ///PinSpotLight4
    haska[275] = CreateDynamicObject(2232, 1136.8852, 2749.6147, 10.3964, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[276] = CreateDynamicObject(2232, 1136.8852, 2749.6147, 11.5762, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[277] = CreateDynamicObject(2232, 1137.9913, 2748.8183, 10.3964, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[278] = CreateDynamicObject(2232, 1136.3083, 2750.0292, 11.5762, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[279] = CreateDynamicObject(19371, 1095.1219, 2790.5229, 17.9957, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall019
    SetDynamicObjectMaterialText(haska[279], 0, "RIPPZY", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 0);
    haska[280] = CreateDynamicObject(2232, 1137.4311, 2749.2219, 11.5762, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[281] = CreateDynamicObject(2232, 1137.4311, 2749.2219, 10.3964, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[282] = CreateDynamicObject(2232, 1137.9913, 2748.8183, 11.5762, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[283] = CreateDynamicObject(2232, 1138.5604, 2748.4082, 11.5762, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[284] = CreateDynamicObject(2232, 1138.5604, 2748.4082, 10.4165, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[285] = CreateDynamicObject(19371, 1095.1219, 2792.5842, 16.4556, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///wall019
    SetDynamicObjectMaterialText(haska[285], 0, "CITY", 90, "Arial", 80, 1, 0xFF53387E, 0x0, 0);
    haska[286] = CreateDynamicObject(2232, 1139.1219, 2748.0041, 10.4165, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[287] = CreateDynamicObject(2232, 1139.6993, 2747.5891, 11.5762, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[288] = CreateDynamicObject(2232, 1139.1219, 2748.0041, 11.5762, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[289] = CreateDynamicObject(2232, 1139.6993, 2747.5891, 10.4165, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[290] = CreateDynamicObject(2232, 1140.2281, 2747.2082, 10.4165, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[291] = CreateDynamicObject(2232, 1140.2281, 2747.2082, 11.5663, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[292] = CreateDynamicObject(2232, 1140.2281, 2747.2082, 12.7565, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[293] = CreateDynamicObject(18075, 1170.9707, 2738.8864, 13.7482, 0.0000, 0.0000, 89.5998, -1, 0, -1, 900.0, 900.0, -1); ///lightD
    haska[294] = CreateDynamicObject(2232, 1139.6577, 2747.6184, 12.7565, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[295] = CreateDynamicObject(2232, 1139.0970, 2748.0214, 12.7565, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[296] = CreateDynamicObject(2232, 1138.5361, 2748.4257, 12.7565, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[297] = CreateDynamicObject(2232, 1137.9665, 2748.8359, 12.7565, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[298] = CreateDynamicObject(2232, 1137.3962, 2749.2460, 12.7565, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[299] = CreateDynamicObject(2232, 1136.9090, 2749.5971, 12.7565, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[300] = CreateDynamicObject(2232, 1136.3330, 2750.0117, 12.7465, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[301] = CreateDynamicObject(2773, 1419.9288, 2823.1367, 10.3191, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[302] = CreateDynamicObject(2773, 1421.8487, 2823.1367, 10.3191, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[303] = CreateDynamicObject(2773, 1423.7690, 2823.1367, 10.3191, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[304] = CreateDynamicObject(2773, 1425.6992, 2823.1367, 10.3191, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[305] = CreateDynamicObject(18728, 1116.1440, 2793.0891, 11.9750, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///smoke_flare
    haska[306] = CreateDynamicObject(2773, 1427.6092, 2823.1367, 10.3191, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[307] = CreateDynamicObject(2773, 1429.5395, 2823.1367, 10.3191, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[308] = CreateDynamicObject(2773, 1431.4604, 2823.1367, 10.3191, 0.0000, 0.0000, 90.0000, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[309] = CreateDynamicObject(2773, 1437.1987, 2815.4360, 10.3191, 0.0000, 0.0000, 31.3999, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[310] = CreateDynamicObject(18728, 1116.1440, 2788.5568, 11.9750, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///smoke_flare
    haska[311] = CreateDynamicObject(2773, 1436.1981, 2817.0759, 10.3191, 0.0000, 0.0000, 31.3999, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[312] = CreateDynamicObject(2773, 1432.9178, 2822.3161, 10.3191, 0.0000, 0.0000, 31.3999, -1, 0, -1, 900.0, 900.0, -1); ///CJ_AIRPRT_BAR
    haska[313] = CreateDynamicObject(2984, 1437.1407, 2811.2626, 11.1360, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///portaloo
    haska[314] = CreateDynamicObject(2984, 1437.1407, 2813.8940, 11.1360, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///portaloo
    haska[315] = CreateDynamicObject(18716, 1095.4687, 2786.5144, 11.2062, 0.0000, 0.0000, 0.0000, -1, 0, -1, 900.0, 900.0, -1); ///prt_smoke_expand
    haska[316] = CreateDynamicObject(16778, 1441.5959, 2818.6530, 6.0163, 0.0000, 0.0000, -155.8999, -1, 0, -1, 900.0, 900.0, -1); ///des_ufosign
    haska[317] = CreateDynamicObject(2232, 1140.2281, 2747.2082, 13.9364, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[318] = CreateDynamicObject(2232, 1139.6501, 2747.6242, 13.9364, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[319] = CreateDynamicObject(2232, 1139.0810, 2748.0344, 13.9364, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[320] = CreateDynamicObject(2232, 1138.5040, 2748.4504, 13.9364, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[321] = CreateDynamicObject(2232, 1138.0323, 2748.7895, 13.9364, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[322] = CreateDynamicObject(1342, 1427.5981, 2811.4277, 10.8205, 0.0000, 0.0000, -128.7998, -1, 0, -1, 900.0, 900.0, -1); ///noodlecart_prop
    haska[323] = CreateDynamicObject(2232, 1137.4548, 2749.2050, 13.9364, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[324] = CreateDynamicObject(2232, 1136.9663, 2749.5563, 13.9364, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[325] = CreateDynamicObject(2232, 1136.4051, 2749.9599, 13.9364, 0.0000, 0.0000, 144.3000, -1, 0, -1, 900.0, 900.0, -1); ///MED_SPEAKER_4
    haska[326] = CreateDynamicObject(19380, 1141.3083, 2753.2358, 9.7465, 0.0000, 90.0000, 53.2999, -1, 0, -1, 900.0, 900.0, -1); ///wall028
    SetDynamicObjectMaterial(haska[326], 0, 14786, "ab_sfgymbeams", "knot_wood128", 0xFFFFFFFF);
    return 1;
}