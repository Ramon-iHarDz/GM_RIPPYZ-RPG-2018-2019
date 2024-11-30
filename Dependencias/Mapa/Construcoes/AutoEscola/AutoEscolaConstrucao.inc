#include <YSI_Coding\y_hooks>

hook OnGameModeInit(){
    new AEscolaObj[88];
    AEscolaObj[0] = CreateDynamicObject(19448, 691.9389, -590.2470, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[0], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[1] = CreateDynamicObject(19448, 711.0805, -586.7672, -25.5881, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[1], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[2] = CreateDynamicObject(3657, 702.7401, -598.4945, -24.9754, 0.0000, 0.0000, 180.0000, -1, 1, -1, 150.0, 150.0); //airseata_LAS
    AEscolaObj[3] = CreateDynamicObject(19450, 706.3363, -582.5183, -23.7693, 0.0000, 0.0000, -0.3998, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[3], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[4] = CreateDynamicObject(19448, 691.9389, -586.8068, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[4], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[5] = CreateDynamicObject(19448, 701.5490, -597.2077, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[5], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[6] = CreateDynamicObject(19450, 711.0144, -587.3521, -23.7693, 0.0000, 0.0000, -89.9000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[6], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[7] = CreateDynamicObject(19448, 701.5194, -583.3864, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[7], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[8] = CreateDynamicObject(19448, 691.9389, -583.3864, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[8], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[9] = CreateDynamicObject(19448, 701.5092, -593.7064, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[9], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[10] = CreateDynamicObject(19448, 701.5194, -586.8164, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[10], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[11] = CreateDynamicObject(19448, 711.0805, -593.7191, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[11], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[12] = CreateDynamicObject(3440, 690.5355, -593.0050, -23.4923, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //arptpillar01_lvs
    AEscolaObj[13] = CreateDynamicObject(19450, 687.3599, -595.9967, -23.7693, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[13], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[14] = CreateDynamicObject(19450, 687.3599, -586.4376, -23.7693, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[14], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[15] = CreateDynamicObject(19448, 691.9389, -593.7064, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[15], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[16] = CreateDynamicObject(19448, 691.9389, -597.2077, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[16], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[17] = CreateDynamicObject(19448, 711.0805, -590.3488, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[17], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[18] = CreateDynamicObject(19450, 691.9185, -598.9987, -23.7693, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[18], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[19] = CreateDynamicObject(19448, 701.4799, -593.8092, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[19], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[20] = CreateDynamicObject(19450, 691.9780, -581.6185, -23.7693, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[20], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[21] = CreateDynamicObject(3657, 698.1608, -598.4945, -24.9754, 0.0000, 0.0000, 180.0000, -1, 1, -1, 150.0, 150.0); //airseata_LAS
    AEscolaObj[22] = CreateDynamicObject(19450, 701.4301, -598.9987, -23.7693, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[22], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[23] = CreateDynamicObject(19431, 690.5592, -591.0377, -22.6016, 90.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //wall071
    SetDynamicObjectMaterial(AEscolaObj[23], 0, 6873, "vgnshambild1", "glasswindow3b_256", 0xFFFFFFFF);
    AEscolaObj[24] = CreateDynamicObject(19431, 690.5592, -589.2675, -22.6016, 90.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //wall071
    SetDynamicObjectMaterial(AEscolaObj[24], 0, 6873, "vgnshambild1", "glasswindow3b_256", 0xFFFFFFFF);
    AEscolaObj[25] = CreateDynamicObject(19450, 711.0233, -592.8734, -23.7693, 0.0000, 0.0000, -89.9000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[25], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[26] = CreateDynamicObject(19448, 701.5194, -590.2468, -25.5680, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[26], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[27] = CreateDynamicObject(3657, 698.1608, -582.1035, -24.9754, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //airseata_LAS
    AEscolaObj[28] = CreateDynamicObject(2435, 690.7744, -590.2158, -25.4922, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[29] = CreateDynamicObject(2435, 690.7744, -591.1362, -25.4922, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[30] = CreateDynamicObject(2435, 690.7744, -589.3059, -25.4922, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[31] = CreateDynamicObject(2435, 690.7744, -588.3961, -25.4922, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[32] = CreateDynamicObject(2435, 690.7744, -592.0462, -25.4922, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[33] = CreateDynamicObject(2434, 690.6129, -593.1734, -25.4878, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2b
    AEscolaObj[34] = CreateDynamicObject(19448, 711.0805, -593.7465, -25.5881, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[34], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    AEscolaObj[35] = CreateDynamicObject(948, 695.9431, -582.2332, -25.5060, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //Plant_Pot_10
    AEscolaObj[36] = CreateDynamicObject(2434, 690.7832, -587.5128, -25.4878, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2b
    AEscolaObj[37] = CreateDynamicObject(19448, 701.4799, -586.8596, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[37], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[38] = CreateDynamicObject(3657, 702.7401, -582.1035, -24.9754, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //airseata_LAS
    AEscolaObj[39] = CreateDynamicObject(948, 695.9431, -598.5717, -25.5060, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //Plant_Pot_10
    AEscolaObj[40] = CreateDynamicObject(2435, 689.6843, -593.1762, -25.4922, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[41] = CreateDynamicObject(19448, 691.9086, -597.3485, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[41], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[42] = CreateDynamicObject(19448, 701.4799, -597.3093, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[42], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[43] = CreateDynamicObject(19448, 701.4799, -590.3292, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[43], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[44] = CreateDynamicObject(2435, 688.7644, -593.1762, -25.4922, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[45] = CreateDynamicObject(19448, 701.4799, -583.3894, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[45], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[46] = CreateDynamicObject(2435, 687.9144, -593.1762, -25.4922, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[47] = CreateDynamicObject(19448, 711.0805, -586.8590, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[47], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[48] = CreateDynamicObject(2435, 689.6643, -587.3457, -25.4922, 0.0000, 0.0000, 180.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[49] = CreateDynamicObject(19448, 691.9086, -583.3894, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[49], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[50] = CreateDynamicObject(19448, 691.9086, -590.3493, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[50], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[51] = CreateDynamicObject(19448, 691.9086, -586.8792, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[51], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[52] = CreateDynamicObject(19448, 691.9086, -593.8488, -22.1081, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[52], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    AEscolaObj[53] = CreateDynamicObject(2435, 688.7645, -587.3457, -25.4922, 0.0000, 0.0000, 180.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[54] = CreateDynamicObject(2435, 687.8839, -587.3457, -25.4922, 0.0000, 0.0000, 180.0000, -1, 1, -1, 150.0, 150.0); //CJ_FF_CONTER_2
    AEscolaObj[55] = CreateDynamicObject(3440, 690.5355, -587.5128, -23.4923, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //arptpillar01_lvs
    AEscolaObj[56] = CreateDynamicObject(19450, 715.8900, -586.4376, -23.7693, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[56], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[57] = CreateDynamicObject(19450, 706.2893, -597.7285, -23.7693, 0.0000, 0.0000, 179.9998, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[57], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[58] = CreateDynamicObject(19450, 701.4984, -581.6185, -23.7693, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[58], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[59] = CreateDynamicObject(19431, 688.5689, -592.9688, -22.6016, 90.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall071
    SetDynamicObjectMaterial(AEscolaObj[59], 0, 6873, "vgnshambild1", "glasswindow3b_256", 0xFFFFFFFF);
    AEscolaObj[60] = CreateDynamicObject(19431, 688.5689, -587.4578, -22.6016, 90.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall071
    SetDynamicObjectMaterial(AEscolaObj[60], 0, 6873, "vgnshambild1", "glasswindow3b_256", 0xFFFFFFFF);
    AEscolaObj[61] = CreateDynamicObject(1569, 687.4462, -584.1649, -25.5123, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //ADAM_V_DOOR
    AEscolaObj[62] = CreateDynamicObject(1663, 688.7988, -591.7116, -25.0233, 0.0000, 0.0000, -139.4998, -1, 1, -1, 150.0, 150.0); //swivelchair_B
    AEscolaObj[63] = CreateDynamicObject(2002, 687.9558, -584.8936, -25.4803, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //water_coolnu
    AEscolaObj[64] = CreateDynamicObject(2261, 687.9882, -585.9848, -24.2280, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //Frame_SLIM_2
    AEscolaObj[65] = CreateDynamicObject(19176, 715.7766, -590.0932, -24.1788, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //LSOffice1Door1
    AEscolaObj[66] = CreateDynamicObject(1886, 715.1574, -592.5963, -22.0704, 15.9998, -0.2998, -103.6998, -1, 1, -1, 150.0, 150.0); //shop_sec_cam
    AEscolaObj[67] = CreateDynamicObject(19893, 689.5371, -596.6743, -24.6788, 0.0000, 0.0000, -114.1997, -1, 1, -1, 150.0, 150.0); //LaptopSAMP1
    AEscolaObj[68] = CreateDynamicObject(19423, 689.4699, -596.3048, -24.6634, 0.0000, 0.0000, -70.7996, -1, 1, -1, 150.0, 150.0); //headphones03
    AEscolaObj[69] = CreateDynamicObject(2826, 690.1010, -596.1710, -24.6625, 0.0000, 0.0000, 27.1000, -1, 1, -1, 150.0, 150.0); //GB_novels04
    AEscolaObj[70] = CreateDynamicObject(948, 705.0357, -582.2332, -25.5060, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //Plant_Pot_10
    AEscolaObj[71] = CreateDynamicObject(948, 700.4545, -582.2332, -25.5060, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //Plant_Pot_10
    AEscolaObj[72] = CreateDynamicObject(948, 700.4345, -598.5941, -25.5060, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //Plant_Pot_10
    AEscolaObj[73] = CreateDynamicObject(948, 705.0465, -598.5941, -25.5060, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //Plant_Pot_10
    AEscolaObj[74] = CreateDynamicObject(2824, 690.0869, -596.9110, -24.6529, 0.0000, 0.0000, 28.2999, -1, 1, -1, 150.0, 150.0); //GB_novels02
    AEscolaObj[75] = CreateDynamicObject(2162, 687.4849, -589.0748, -25.4783, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //MED_OFFICE_UNIT_1
    AEscolaObj[76] = CreateDynamicObject(19426, 691.0150, -590.1964, -26.2702, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //wall066
    SetDynamicObjectMaterialText(AEscolaObj[76], 0, "Auto Escola", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 0);
    AEscolaObj[77] = CreateDynamicObject(2165, 687.9387, -592.2623, -25.5265, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //MED_OFFICE_DESK_1
    AEscolaObj[78] = CreateDynamicObject(2167, 687.4760, -590.1613, -25.4923, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //MED_OFFICE_UNIT_7
    AEscolaObj[79] = CreateDynamicObject(2030, 689.9688, -596.4572, -25.0680, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //MED_DINNING_1
    AEscolaObj[80] = CreateDynamicObject(2263, 687.9912, -596.5344, -23.8092, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //Frame_SLIM_4
    AEscolaObj[81] = CreateDynamicObject(1702, 687.9766, -597.4420, -25.5062, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //kb_couch06
    AEscolaObj[82] = CreateDynamicObject(19450, 715.8499, -596.0374, -23.7693, 0.0000, 0.0000, 0.0000, -1, 1, -1, 150.0, 150.0); //wall090
    SetDynamicObjectMaterial(AEscolaObj[82], 0, 13007, "sw_bankint", "bank_wall1", 0xFFFFFFFF);
    AEscolaObj[83] = CreateDynamicObject(19893, 690.7163, -589.1298, -24.4307, 0.0000, 0.0000, -66.9999, -1, 1, -1, 150.0, 150.0); //LaptopSAMP1
    AEscolaObj[84] = CreateDynamicObject(19893, 690.7089, -591.3997, -24.4307, 0.0000, 0.0000, -136.8000, -1, 1, -1, 150.0, 150.0); //LaptopSAMP1
    AEscolaObj[85] = CreateDynamicObject(11711, 715.7785, -590.0715, -22.5069, 0.0000, 0.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //ExitSign1
    AEscolaObj[86] = CreateDynamicObject(11713, 706.1837, -593.8040, -23.5461, 0.0000, 0.0000, 180.0000, -1, 1, -1, 150.0, 150.0); //FireExtPanel1
    AEscolaObj[87] = CreateDynamicObject(19448, 711.0805, -590.2567, -25.5881, 0.0000, 90.0000, 90.0000, -1, 1, -1, 150.0, 150.0); //wall088
    SetDynamicObjectMaterial(AEscolaObj[87], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF); 
    return 1;
}