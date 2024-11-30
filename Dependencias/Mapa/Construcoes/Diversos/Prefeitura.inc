#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    new prst_TartatugaIndiana[158]; 
    prst_TartatugaIndiana[0] = CreateDynamicObject(2200, -72.5485, -2.1898, 1002.3635, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE5_UNIT_1
    prst_TartatugaIndiana[1] = CreateDynamicObject(2174, -72.1707, -5.0711, 1002.3823, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE4_DESK_2
    prst_TartatugaIndiana[2] = CreateDynamicObject(19380, -55.9538, -1.7955, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[2], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[3] = CreateDynamicObject(18756, -48.7024, -1.6677, 1004.2819, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //ElevatorDoor1
    prst_TartatugaIndiana[4] = CreateDynamicObject(18757, -48.7136, -1.6727, 1004.2811, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //ElevatorDoor2
    prst_TartatugaIndiana[5] = CreateDynamicObject(19380, -76.8833, -1.7955, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[5], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[6] = CreateDynamicObject(638, -70.4477, 2.6063, 1003.0866, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //kb_planter+bush
    prst_TartatugaIndiana[7] = CreateDynamicObject(638, -70.4477, -6.2136, 1003.0866, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //kb_planter+bush
    prst_TartatugaIndiana[8] = CreateDynamicObject(19380, -55.9538, -11.4055, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[8], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[9] = CreateDynamicObject(19380, -66.4139, -11.4055, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[9], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[10] = CreateDynamicObject(19454, -55.4752, -16.2808, 1004.1029, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[10], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[11] = CreateDynamicObject(19366, -52.2905, -6.6406, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[11], 0, 17588, "lae2coast_alpha", "plainglass", 0xFFFFFFFF);
    prst_TartatugaIndiana[12] = CreateDynamicObject(2208, -57.4011, -11.3753, 1002.3521, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE7_UNIT_1
    prst_TartatugaIndiana[13] = CreateDynamicObject(19454, -65.0550, -16.2808, 1004.1029, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[13], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[14] = CreateDynamicObject(19454, -74.6549, -16.2808, 1004.1029, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[14], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[15] = CreateDynamicObject(19366, -61.8204, -6.6406, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[15], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[16] = CreateDynamicObject(2208, -60.1211, -11.3753, 1002.3521, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE7_UNIT_1
    prst_TartatugaIndiana[17] = CreateDynamicObject(2207, -58.2415, -11.9841, 1002.4359, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE7_DESK_1
    prst_TartatugaIndiana[18] = CreateDynamicObject(2207, -56.4416, -10.7040, 1002.4359, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE7_DESK_1
    prst_TartatugaIndiana[19] = CreateDynamicObject(1663, -53.8558, -11.3176, 1002.8532, 0.0000, 0.0000, -104.30000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[20] = CreateDynamicObject(1663, -55.5965, -10.3641, 1002.8532, 0.0000, 0.0000, 7.69990, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[21] = CreateDynamicObject(1663, -55.3614, -12.3338, 1002.8532, 0.0000, 0.0000, -160.50000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[22] = CreateDynamicObject(1663, -59.2551, -12.4069, 1002.8532, 0.0000, 0.0000, 168.10000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[23] = CreateDynamicObject(1663, -59.1343, -10.3766, 1002.8532, 0.0000, 0.0000, -1.69990, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[24] = CreateDynamicObject(1663, -61.0904, -11.2374, 1002.8532, 0.0000, 0.0000, 69.90000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[25] = CreateDynamicObject(2183, -67.4430, -12.7180, 1002.3646, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE3_DESK_09
    prst_TartatugaIndiana[26] = CreateDynamicObject(1671, -66.7453, -12.1478, 1002.8248, 0.0000, 0.0000, -89.50000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[27] = CreateDynamicObject(1671, -66.7602, -10.4378, 1002.8248, 0.0000, 0.0000, -140.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[28] = CreateDynamicObject(1671, -69.3075, -12.2733, 1002.8248, 0.0000, 0.0000, 138.30000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[29] = CreateDynamicObject(1671, -69.3479, -10.3823, 1002.8248, 0.0000, 0.0000, 88.90000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[30] = CreateDynamicObject(2190, -68.0195, -10.7889, 1003.1514, 0.0000, 0.0000, 118.50000, 1303, 3, -1, 100.0, 100.0, -1, 0); //PC_1
    prst_TartatugaIndiana[31] = CreateDynamicObject(2190, -67.6473, -11.2825, 1003.1514, 0.0000, 0.0000, 31.50000, 1303, 3, -1, 100.0, 100.0, -1, 0); //PC_1
    prst_TartatugaIndiana[32] = CreateDynamicObject(2190, -68.1194, -11.6527, 1003.1514, 0.0000, 0.0000, -57.99990, 1303, 3, -1, 100.0, 100.0, -1, 0); //PC_1
    prst_TartatugaIndiana[33] = CreateDynamicObject(2190, -68.5035, -11.1941, 1003.1514, 0.0000, 0.0000, -146.19970, 1303, 3, -1, 100.0, 100.0, -1, 0); //PC_1
    prst_TartatugaIndiana[34] = CreateDynamicObject(19808, -67.5130, -10.1763, 1003.1832, 0.0000, 0.0000, 121.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Keyboard1
    prst_TartatugaIndiana[35] = CreateDynamicObject(19808, -67.4915, -12.2515, 1003.1832, 0.0000, 0.0000, 68.90000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Keyboard1
    prst_TartatugaIndiana[36] = CreateDynamicObject(19808, -68.6595, -12.2509, 1003.1832, 0.0000, 0.0000, -60.99990, 1303, 3, -1, 100.0, 100.0, -1, 0); //Keyboard1
    prst_TartatugaIndiana[37] = CreateDynamicObject(19808, -68.7143, -10.2705, 1003.1832, 0.0000, 0.0000, -113.19960, 1303, 3, -1, 100.0, 100.0, -1, 0); //Keyboard1
    prst_TartatugaIndiana[38] = CreateDynamicObject(19380, -55.9538, -1.7955, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[38], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[39] = CreateDynamicObject(18756, -48.7024, -1.6677, 1004.2819, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //ElevatorDoor1
    prst_TartatugaIndiana[40] = CreateDynamicObject(18757, -48.7136, -1.6727, 1004.2811, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //ElevatorDoor2
    prst_TartatugaIndiana[41] = CreateDynamicObject(19380, -66.4038, -1.7955, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[41], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[42] = CreateDynamicObject(19454, -55.4752, 12.5888, 1004.1029, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[42], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[43] = CreateDynamicObject(19454, -72.7853, -11.3711, 1004.1029, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[43], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[44] = CreateDynamicObject(19380, -55.9538, -11.4055, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[44], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[45] = CreateDynamicObject(19380, -66.4139, -11.4055, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[45], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[46] = CreateDynamicObject(19366, -68.1100, -6.6406, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[46], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[47] = CreateDynamicObject(2208, -57.4011, -11.3753, 1002.3521, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE7_UNIT_1
    prst_TartatugaIndiana[48] = CreateDynamicObject(19387, -58.6180, -6.6517, 1004.0963, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall035
    SetDynamicObjectMaterial(prst_TartatugaIndiana[48], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[49] = CreateDynamicObject(2208, -60.1211, -11.3753, 1002.3521, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE7_UNIT_1
    prst_TartatugaIndiana[50] = CreateDynamicObject(2207, -58.2415, -11.9841, 1002.4359, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE7_DESK_1
    prst_TartatugaIndiana[51] = CreateDynamicObject(2207, -56.4416, -10.7040, 1002.4359, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE7_DESK_1
    prst_TartatugaIndiana[52] = CreateDynamicObject(1663, -53.8558, -11.3176, 1002.8532, 0.0000, 0.0000, -104.30000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[53] = CreateDynamicObject(1663, -55.5965, -10.3641, 1002.8532, 0.0000, 0.0000, 7.69990, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[54] = CreateDynamicObject(1663, -55.3614, -12.3338, 1002.8532, 0.0000, 0.0000, -160.50000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[55] = CreateDynamicObject(1663, -59.2551, -12.4069, 1002.8532, 0.0000, 0.0000, 168.10000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[56] = CreateDynamicObject(1663, -59.1343, -10.3766, 1002.8532, 0.0000, 0.0000, -1.69990, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[57] = CreateDynamicObject(1663, -61.0904, -11.2374, 1002.8532, 0.0000, 0.0000, 69.90000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_B
    prst_TartatugaIndiana[58] = CreateDynamicObject(2183, -67.4430, -12.7180, 1002.3646, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE3_DESK_09
    prst_TartatugaIndiana[59] = CreateDynamicObject(1671, -66.7453, -12.1478, 1002.8248, 0.0000, 0.0000, -89.50000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[60] = CreateDynamicObject(1671, -66.7602, -10.4378, 1002.8248, 0.0000, 0.0000, -140.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[61] = CreateDynamicObject(1671, -69.3075, -12.2733, 1002.8248, 0.0000, 0.0000, 138.30000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[62] = CreateDynamicObject(1671, -69.3479, -10.3823, 1002.8248, 0.0000, 0.0000, 88.90000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[63] = CreateDynamicObject(2190, -68.0195, -10.7889, 1003.1514, 0.0000, 0.0000, 118.50000, 1303, 3, -1, 100.0, 100.0, -1, 0); //PC_1
    prst_TartatugaIndiana[64] = CreateDynamicObject(2190, -67.6473, -11.2825, 1003.1514, 0.0000, 0.0000, 31.50000, 1303, 3, -1, 100.0, 100.0, -1, 0); //PC_1
    prst_TartatugaIndiana[65] = CreateDynamicObject(2190, -68.1194, -11.6527, 1003.1514, 0.0000, 0.0000, -57.99990, 1303, 3, -1, 100.0, 100.0, -1, 0); //PC_1
    prst_TartatugaIndiana[66] = CreateDynamicObject(2190, -68.5035, -11.1941, 1003.1514, 0.0000, 0.0000, -146.19970, 1303, 3, -1, 100.0, 100.0, -1, 0); //PC_1
    prst_TartatugaIndiana[67] = CreateDynamicObject(19808, -67.5130, -10.1763, 1003.1832, 0.0000, 0.0000, 121.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Keyboard1
    prst_TartatugaIndiana[68] = CreateDynamicObject(19808, -67.4915, -12.2515, 1003.1832, 0.0000, 0.0000, 68.90000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Keyboard1
    prst_TartatugaIndiana[69] = CreateDynamicObject(19808, -68.6595, -12.2509, 1003.1832, 0.0000, 0.0000, -60.99990, 1303, 3, -1, 100.0, 100.0, -1, 0); //Keyboard1
    prst_TartatugaIndiana[70] = CreateDynamicObject(19808, -68.7143, -10.2705, 1003.1832, 0.0000, 0.0000, -113.19960, 1303, 3, -1, 100.0, 100.0, -1, 0); //Keyboard1
    prst_TartatugaIndiana[71] = CreateDynamicObject(2268, -65.9952, 2.4828, 1003.7991, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Frame_WOOD_2
    prst_TartatugaIndiana[72] = CreateDynamicObject(2007, -63.0064, -15.6892, 1002.3737, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //filing_cab_nu01
    prst_TartatugaIndiana[73] = CreateDynamicObject(2007, -62.0265, -15.6892, 1002.3737, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //filing_cab_nu01
    prst_TartatugaIndiana[74] = CreateDynamicObject(2007, -61.0465, -15.6892, 1002.3737, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //filing_cab_nu01
    prst_TartatugaIndiana[75] = CreateDynamicObject(2007, -60.0564, -15.6892, 1002.3737, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //filing_cab_nu01
    prst_TartatugaIndiana[76] = CreateDynamicObject(2202, -55.3568, -15.7214, 1002.3732, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //PHOTOCOPIER_2
    prst_TartatugaIndiana[77] = CreateDynamicObject(2256, -61.5689, -16.1553, 1004.6666, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Frame_Clip_3
    prst_TartatugaIndiana[78] = CreateDynamicObject(19366, -71.2500, -6.6406, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[78], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[79] = CreateDynamicObject(1536, -59.4042, -6.6448, 1002.3582, 0.0000, 0.0000, -111.69960, 1303, 3, -1, 100.0, 100.0, -1, 0); //Gen_doorEXT15
    prst_TartatugaIndiana[80] = CreateDynamicObject(2267, -50.7341, -11.3156, 1004.3765, 0.0000, 0.0000, 270.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Frame_WOOD_3
    prst_TartatugaIndiana[81] = CreateDynamicObject(19366, -55.4205, -6.6406, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[81], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[82] = CreateDynamicObject(19380, -76.9038, -11.4055, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[82], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[83] = CreateDynamicObject(19366, -52.2905, -6.6406, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[83], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[84] = CreateDynamicObject(19366, -64.9701, -6.6406, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[84], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[85] = CreateDynamicObject(2268, -65.9952, -6.0471, 1003.7991, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Frame_WOOD_2
    prst_TartatugaIndiana[86] = CreateDynamicObject(19454, -50.6152, -11.3809, 1004.1029, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[86], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[87] = CreateDynamicObject(19366, -52.2905, 3.0592, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[87], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[88] = CreateDynamicObject(638, -61.5478, -6.2136, 1003.0866, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //kb_planter+bush
    prst_TartatugaIndiana[89] = CreateDynamicObject(638, -61.5277, 2.6063, 1003.0866, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //kb_planter+bush
    prst_TartatugaIndiana[90] = CreateDynamicObject(19380, -55.9538, -1.7955, 1005.9127, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[90], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    prst_TartatugaIndiana[91] = CreateDynamicObject(19366, -55.4205, 3.0692, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[91], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[92] = CreateDynamicObject(19387, -58.6180, 3.0683, 1004.0963, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall035
    SetDynamicObjectMaterial(prst_TartatugaIndiana[92], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[93] = CreateDynamicObject(1536, -57.9752, 2.9900, 1002.3781, 0.0000, 0.0000, 58.80020, 1303, 3, -1, 100.0, 100.0, -1, 0); //Gen_doorEXT15
    prst_TartatugaIndiana[94] = CreateDynamicObject(19380, -55.9538, 7.8344, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[94], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[95] = CreateDynamicObject(19366, -61.8204, 3.0692, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[95], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[96] = CreateDynamicObject(19366, -64.9701, 3.0694, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[96], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[97] = CreateDynamicObject(19366, -68.1100, 3.0692, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[97], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[98] = CreateDynamicObject(19366, -71.2500, 3.0592, 1004.0996, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall014
    SetDynamicObjectMaterial(prst_TartatugaIndiana[98], 0, 3979, "civic01_lan", "sl_laglasswall1", 0xFFFFFFFF);
    prst_TartatugaIndiana[99] = CreateDynamicObject(19380, -66.4337, -1.7955, 1005.9127, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[99], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    prst_TartatugaIndiana[100] = CreateDynamicObject(19380, -76.9134, -1.7955, 1005.9127, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[100], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    prst_TartatugaIndiana[101] = CreateDynamicObject(19380, -66.4235, 7.8344, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[101], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[102] = CreateDynamicObject(19454, -50.6152, 7.8288, 1004.1029, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[102], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[103] = CreateDynamicObject(19454, -65.0849, 12.5888, 1004.1029, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[103], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[104] = CreateDynamicObject(19454, -74.6549, 12.5888, 1004.1029, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[104], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[105] = CreateDynamicObject(19454, -72.7853, 7.7989, 1004.1029, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[105], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[106] = CreateDynamicObject(19454, -72.7853, -1.8207, 1004.1029, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[106], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    prst_TartatugaIndiana[107] = CreateDynamicObject(19380, -76.8737, 7.8344, 1002.3021, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[107], 0, 14415, "carter_block_2", "mp_shop_floor2", 0xFFFFFFFF);
    prst_TartatugaIndiana[108] = CreateDynamicObject(19380, -55.9538, 7.6943, 1005.9127, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[108], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    prst_TartatugaIndiana[109] = CreateDynamicObject(19380, -66.4337, 7.6943, 1005.9127, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[109], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    prst_TartatugaIndiana[110] = CreateDynamicObject(19380, -76.9134, 7.6943, 1005.9127, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[110], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    prst_TartatugaIndiana[111] = CreateDynamicObject(19380, -55.9538, -11.3955, 1005.9127, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[111], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    prst_TartatugaIndiana[112] = CreateDynamicObject(19380, -66.4337, -11.3955, 1005.9127, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[112], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    prst_TartatugaIndiana[113] = CreateDynamicObject(19380, -76.9138, -11.3955, 1005.9127, 0.0000, 90.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall028
    SetDynamicObjectMaterial(prst_TartatugaIndiana[113], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    prst_TartatugaIndiana[114] = CreateDynamicObject(638, -61.5277, 3.5063, 1003.0866, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //kb_planter+bush
    prst_TartatugaIndiana[115] = CreateDynamicObject(2198, -67.9012, 10.8607, 1002.3519, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE2_DESK_3
    prst_TartatugaIndiana[116] = CreateDynamicObject(2198, -64.5712, 10.8208, 1002.3519, 0.0000, 0.0000, 180.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE2_DESK_3
    prst_TartatugaIndiana[117] = CreateDynamicObject(638, -70.4477, 3.5063, 1003.0866, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //kb_planter+bush
    prst_TartatugaIndiana[118] = CreateDynamicObject(638, -61.5478, -7.1036, 1003.0866, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //kb_planter+bush
    prst_TartatugaIndiana[119] = CreateDynamicObject(1671, -64.9312, 11.8871, 1002.8579, 0.0000, 0.0000, 42.59990, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[120] = CreateDynamicObject(1671, -68.5141, 11.7479, 1002.8579, 0.0000, 0.0000, 0.79980, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[121] = CreateDynamicObject(638, -70.4477, -7.1036, 1003.0866, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //kb_planter+bush
    prst_TartatugaIndiana[122] = CreateDynamicObject(2007, -72.2007, 6.5800, 1002.3781, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //filing_cab_nu01
    prst_TartatugaIndiana[123] = CreateDynamicObject(2007, -72.2007, 4.6100, 1002.3781, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //filing_cab_nu01
    prst_TartatugaIndiana[124] = CreateDynamicObject(2007, -72.2007, 5.6002, 1002.3781, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //filing_cab_nu01
    prst_TartatugaIndiana[125] = CreateDynamicObject(2164, -72.6602, 7.7157, 1002.3734, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE_UNIT_5
    prst_TartatugaIndiana[126] = CreateDynamicObject(2202, -72.2162, 10.2475, 1002.3590, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //PHOTOCOPIER_2
    prst_TartatugaIndiana[127] = CreateDynamicObject(2164, -61.8334, 12.4657, 1002.3707, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE_UNIT_5
    prst_TartatugaIndiana[128] = CreateDynamicObject(2200, -50.8484, 9.7847, 1002.3906, 0.0000, 0.0000, -90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE5_UNIT_1
    prst_TartatugaIndiana[129] = CreateDynamicObject(2200, -50.8484, 7.5545, 1002.3906, 0.0000, 0.0000, -90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE5_UNIT_1
    prst_TartatugaIndiana[130] = CreateDynamicObject(2200, -50.8484, 7.5545, 1002.3906, 0.0000, 0.0000, -90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE5_UNIT_1
    prst_TartatugaIndiana[131] = CreateDynamicObject(2200, -50.8484, 7.5545, 1002.3906, 0.0000, 0.0000, -90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE5_UNIT_1
    prst_TartatugaIndiana[132] = CreateDynamicObject(2181, -56.5969, 12.0590, 1002.3665, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE5_DESK_2
    prst_TartatugaIndiana[133] = CreateDynamicObject(1671, -56.0726, 11.3276, 1002.8189, 0.0000, 0.0000, 175.50000, 1303, 3, -1, 100.0, 100.0, -1, 0); //swivelchair_A
    prst_TartatugaIndiana[134] = CreateDynamicObject(2162, -53.2406, 12.4784, 1002.3850, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE_UNIT_1
    prst_TartatugaIndiana[135] = CreateDynamicObject(638, -68.0378, -15.8436, 1003.0866, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //kb_planter+bush
    prst_TartatugaIndiana[136] = CreateDynamicObject(19893, -55.2695, -11.3915, 1003.1970, 0.0000, 0.0000, 135.89990, 1303, 3, -1, 100.0, 100.0, -1, 0); //LaptopSAMP1
    prst_TartatugaIndiana[137] = CreateDynamicObject(19893, -59.5276, -11.3452, 1003.1970, 0.0000, 0.0000, -108.80000, 1303, 3, -1, 100.0, 100.0, -1, 0); //LaptopSAMP1
    prst_TartatugaIndiana[138] = CreateDynamicObject(1806, -71.4309, -4.5967, 1002.3308, 0.0000, 0.0000, 62.59980, 1303, 3, -1, 100.0, 100.0, -1, 0); //MED_OFFICE_CHAIR
    prst_TartatugaIndiana[139] = CreateDynamicObject(1808, -72.5057, 1.4204, 1002.3577, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //CJ_WATERCOOLER2
    prst_TartatugaIndiana[140] = CreateDynamicObject(19786, -72.7938, -11.1533, 1004.6306, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //LCDTVBig1
    prst_TartatugaIndiana[141] = CreateDynamicObject(2270, -66.8125, 12.0030, 1004.2269, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Frame_WOOD_6
    prst_TartatugaIndiana[142] = CreateDynamicObject(2286, -58.9244, 12.4600, 1004.6621, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Frame_5
    prst_TartatugaIndiana[143] = CreateDynamicObject(2276, -51.2392, 4.3804, 1004.2728, 0.0000, 0.0000, -90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Frame_Fab_3
    prst_TartatugaIndiana[144] = CreateDynamicObject(2262, -72.1974, 5.5803, 1004.3159, 0.0000, 0.0000, 90.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //Frame_SLIM_3
    prst_TartatugaIndiana[145] = CreateDynamicObject(1893, -57.0125, -3.6301, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[146] = CreateDynamicObject(1893, -57.0125, 0.1797, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[147] = CreateDynamicObject(1893, -57.0125, 9.8098, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[148] = CreateDynamicObject(1893, -57.0125, 5.7396, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[149] = CreateDynamicObject(1893, -57.0125, -9.4602, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[150] = CreateDynamicObject(1893, -57.0125, -13.3402, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[151] = CreateDynamicObject(1893, -68.7725, -13.3402, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[152] = CreateDynamicObject(1893, -68.7725, -9.4502, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[153] = CreateDynamicObject(1893, -68.7725, -3.5701, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[154] = CreateDynamicObject(1893, -68.7725, 0.1597, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[155] = CreateDynamicObject(1893, -68.7725, 5.7396, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[156] = CreateDynamicObject(1893, -68.7725, 9.8395, 1006.0806, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //shoplight1
    prst_TartatugaIndiana[157] = CreateDynamicObject(19454, -50.6152, -1.7611, 1004.1029, 0.0000, 0.0000, 0.00000, 1303, 3, -1, 100.0, 100.0, -1, 0); //wall094
    SetDynamicObjectMaterial(prst_TartatugaIndiana[157], 0, 1714, "cj_office", "white32", 0xFFFFFFFF);
    return 1;
}