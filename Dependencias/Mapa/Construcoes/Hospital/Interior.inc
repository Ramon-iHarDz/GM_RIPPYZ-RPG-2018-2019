#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    new g_hospital[119];
    g_hospital[0] = CreateDynamicObject(19452, 1032.1174, 57.9911, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[0], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[1] = CreateDynamicObject(19452, 1032.1174, 64.9710, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[1], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[2] = CreateDynamicObject(19452, 1041.7375, 64.9710, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[2], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[3] = CreateDynamicObject(19452, 1041.7375, 61.4809, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[3], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[4] = CreateDynamicObject(19453, 1032.1141, 66.8084, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[4], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[5] = CreateDynamicObject(19452, 1032.1174, 61.4813, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[5], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[6] = CreateDynamicObject(19453, 1027.2331, 61.9183, 1001.1367, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[6], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[7] = CreateDynamicObject(19176, 1027.4271, 61.9177, 1000.9406, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //LSOffice1Door1
    g_hospital[8] = CreateDynamicObject(2424, 1030.9781, 58.1679, 999.4520, 0.0000, 0.0000, 180.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //CJ_FF_CONTER_1
    g_hospital[9] = CreateDynamicObject(3657, 1030.7049, 66.3126, 999.9558, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //airseata_LAS
    g_hospital[10] = CreateDynamicObject(2424, 1031.9083, 58.1679, 999.4520, 0.0000, 0.0000, 180.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //CJ_FF_CONTER_1
    g_hospital[11] = CreateDynamicObject(19388, 1028.9276, 58.5457, 1001.1273, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall036
    SetDynamicObjectMaterial(g_hospital[11], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[12] = CreateDynamicObject(2424, 1032.8387, 58.1679, 999.4520, 0.0000, 0.0000, 180.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //CJ_FF_CONTER_1
    g_hospital[13] = CreateDynamicObject(2424, 1033.7690, 58.1679, 999.4520, 0.0000, 0.0000, 180.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //CJ_FF_CONTER_1
    g_hospital[14] = CreateDynamicObject(19453, 1039.9956, 58.5483, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[14], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[15] = CreateDynamicObject(19452, 1041.7375, 57.9809, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[15], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[16] = CreateDynamicObject(2424, 1034.6993, 58.1679, 999.4520, 0.0000, 0.0000, 180.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //CJ_FF_CONTER_1
    g_hospital[17] = CreateDynamicObject(19453, 1041.7342, 66.8084, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[17], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[18] = CreateDynamicObject(19452, 1032.1174, 54.5410, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[18], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[19] = CreateDynamicObject(19452, 1041.7486, 54.5410, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[19], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[20] = CreateDynamicObject(19453, 1032.1141, 52.7583, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[20], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[21] = CreateDynamicObject(19453, 1027.2347, 55.4883, 1001.1367, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[21], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[22] = CreateDynamicObject(19453, 1037.0251, 53.7983, 1001.1367, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[22], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[23] = CreateDynamicObject(949, 1032.9643, 66.2805, 1000.1137, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //Plant_Pot_4
    g_hospital[24] = CreateDynamicObject(3657, 1035.2485, 66.3182, 999.9370, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //airseata_LAS
    g_hospital[25] = CreateDynamicObject(2002, 1028.0738, 66.2098, 999.4635, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //water_coolnu
    g_hospital[26] = CreateDynamicObject(19453, 1047.4082, 54.5717, 1001.1367, 0.0000, 0.0000, 33.7000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[26], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[27] = CreateDynamicObject(19452, 1051.3680, 61.4809, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[27], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[28] = CreateDynamicObject(19452, 1051.3680, 64.9710, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[28], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[29] = CreateDynamicObject(19452, 1051.3680, 58.0209, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[29], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[30] = CreateDynamicObject(19452, 1051.3680, 54.5611, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[30], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[31] = CreateDynamicObject(19452, 1051.3680, 51.1511, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[31], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[32] = CreateDynamicObject(19453, 1054.6367, 58.5483, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[32], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[33] = CreateDynamicObject(19453, 1052.5600, 54.5224, 1001.1367, 0.0000, 0.0000, 33.7000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[33], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[34] = CreateDynamicObject(19453, 1051.3642, 66.8084, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[34], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[35] = CreateDynamicObject(19453, 1056.2551, 62.7882, 1001.1367, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[35], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[36] = CreateDynamicObject(19388, 1050.9504, 49.2456, 1001.1373, 0.0000, 0.0000, 33.5998, -1, 3, -1, 350.0, 350.0, -1, 0); //wall036
    SetDynamicObjectMaterial(g_hospital[36], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[37] = CreateDynamicObject(19388, 1056.1168, 49.1847, 1001.1373, 0.0000, 0.0000, 33.5998, -1, 3, -1, 350.0, 350.0, -1, 0); //wall036
    SetDynamicObjectMaterial(g_hospital[37], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[38] = CreateDynamicObject(19452, 1051.3680, 47.7108, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[38], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[39] = CreateDynamicObject(19452, 1051.3680, 44.2910, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[39], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[40] = CreateDynamicObject(19452, 1060.9283, 44.2910, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[40], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[41] = CreateDynamicObject(19452, 1060.9283, 47.7108, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[41], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[42] = CreateDynamicObject(19452, 1060.9283, 51.1910, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[42], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[43] = CreateDynamicObject(19452, 1060.9283, 54.6310, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[43], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[44] = CreateDynamicObject(19452, 1041.7486, 51.0912, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[44], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[45] = CreateDynamicObject(19452, 1041.7486, 47.6810, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[45], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[46] = CreateDynamicObject(19452, 1041.7486, 44.2811, 999.3731, 0.0000, 90.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall092
    SetDynamicObjectMaterial(g_hospital[46], 0, 14846, "genintintpoliceb", "p_floor4", 0xFFFFFFFF);
    g_hospital[47] = CreateDynamicObject(19381, 1032.3631, 52.3586, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[47], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[48] = CreateDynamicObject(19381, 1032.3631, 61.9486, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[48], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[49] = CreateDynamicObject(19381, 1042.8138, 61.9486, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[49], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[50] = CreateDynamicObject(19381, 1053.2635, 61.9486, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[50], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[51] = CreateDynamicObject(19381, 1053.2635, 52.3787, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[51], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[52] = CreateDynamicObject(19381, 1042.8204, 52.3787, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[52], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[53] = CreateDynamicObject(19381, 1053.2513, 42.8086, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[53], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[54] = CreateDynamicObject(19381, 1063.6893, 42.7985, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[54], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[55] = CreateDynamicObject(19381, 1063.6893, 52.3787, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[55], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[56] = CreateDynamicObject(19453, 1039.9956, 58.5382, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[56], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    //g_hospital[57] = CreateObject(19454, 1035.3452, 58.5419, 1003.1021, 0.0000, 0.0000, 90.0000); //wall094
    //SetObjectMaterial(g_hospital[57], 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0xFFFFFFFF);
    g_hospital[58] = CreateDynamicObject(1523, 1028.1373, 58.5135, 999.3917, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //Gen_doorEXT10
    g_hospital[59] = CreateDynamicObject(2167, 1035.6622, 58.4207, 999.4506, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //MED_OFFICE_UNIT_7
    g_hospital[60] = CreateDynamicObject(2165, 1036.4393, 56.0233, 999.4635, 0.0000, 0.0000, 270.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //MED_OFFICE_DESK_1
    g_hospital[61] = CreateDynamicObject(1806, 1035.6357, 55.2368, 999.4530, 0.0000, 0.0000, -67.6997, -1, 3, -1, 350.0, 350.0, -1, 0); //MED_OFFICE_CHAIR
    g_hospital[62] = CreateDynamicObject(2162, 1034.3314, 52.8582, 999.4553, 0.0000, 0.0000, 180.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //MED_OFFICE_UNIT_1
    g_hospital[63] = CreateDynamicObject(2164, 1031.3227, 52.8968, 999.4431, 0.0000, 0.0000, 180.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //MED_OFFICE_UNIT_5
    g_hospital[64] = CreateDynamicObject(2961, 1027.3349, 64.0083, 1001.0874, 0.0000, 0.0000, 90.6998, -1, 3, -1, 350.0, 350.0, -1, 0); //fire_break
    g_hospital[65] = CreateDynamicObject(19807, 1031.2646, 58.1929, 1000.5670, 0.0000, 0.0000, 36.9999, -1, 3, -1, 350.0, 350.0, -1, 0); //Telephone1
    g_hospital[66] = CreateDynamicObject(2190, 1033.7408, 58.0978, 1000.5014, 0.0000, 0.0000, -70.9000, -1, 3, -1, 350.0, 350.0, -1, 0); //PC_1
    g_hospital[67] = CreateDynamicObject(19808, 1032.8817, 58.1693, 1000.5222, 0.0000, 0.0000, -42.0998, -1, 3, -1, 350.0, 350.0, -1, 0); //Keyboard1
    g_hospital[68] = CreateDynamicObject(2826, 1034.4809, 58.2004, 1000.5072, 0.0000, 0.0000, -97.0998, -1, 3, -1, 350.0, 350.0, -1, 0); //GB_novels04
    g_hospital[69] = CreateDynamicObject(1569, 1040.1529, 66.7465, 999.4063, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //ADAM_V_DOOR
    g_hospital[70] = CreateDynamicObject(3034, 1044.1202, 66.6977, 1001.0562, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //bd_window
    g_hospital[71] = CreateDynamicObject(19453, 1049.9029, 63.3883, 1001.1367, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[71], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[72] = CreateDynamicObject(19176, 1049.8193, 61.9177, 1000.9406, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //LSOffice1Door1
    g_hospital[73] = CreateDynamicObject(19810, 1049.7873, 64.1205, 1001.4011, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //StaffOnlySign1
    g_hospital[74] = CreateDynamicObject(2922, 1049.8100, 64.1127, 1000.9849, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //kmb_keypad
    g_hospital[75] = CreateDynamicObject(19453, 1043.4392, 53.2681, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[75], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[76] = CreateDynamicObject(19453, 1054.2231, 46.4981, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[76], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[77] = CreateDynamicObject(19436, 1057.4327, 47.1985, 1001.1447, 0.0000, 0.0000, 33.7999, -1, 3, -1, 350.0, 350.0, -1, 0); //wall076
    SetDynamicObjectMaterial(g_hospital[77], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[78] = CreateDynamicObject(19436, 1052.2851, 47.2523, 1001.1447, 0.0000, 0.0000, 33.7999, -1, 3, -1, 350.0, 350.0, -1, 0); //wall076
    SetDynamicObjectMaterial(g_hospital[78], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[79] = CreateDynamicObject(19453, 1044.6141, 46.4981, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[79], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[80] = CreateDynamicObject(19453, 1060.6617, 46.4981, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[80], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[81] = CreateDynamicObject(19453, 1058.3210, 53.3482, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[81], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[82] = CreateDynamicObject(19453, 1061.5251, 53.3482, 1001.1367, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[82], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[83] = CreateDynamicObject(19453, 1065.5649, 49.9081, 1001.1367, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[83], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[84] = CreateDynamicObject(3034, 1049.4851, 51.6174, 1000.9810, 0.0000, 0.0000, 123.5998, -1, 3, -1, 350.0, 350.0, -1, 0); //bd_window
    g_hospital[85] = CreateDynamicObject(3034, 1054.4940, 51.4528, 1001.0512, 0.0000, 0.0000, -56.4000, -1, 3, -1, 350.0, 350.0, -1, 0); //bd_window
    g_hospital[86] = CreateDynamicObject(1523, 1050.4792, 49.8762, 999.3657, 0.0000, 0.0000, -56.5000, -1, 3, -1, 350.0, 350.0, -1, 0); //Gen_doorEXT10
    g_hospital[87] = CreateDynamicObject(1523, 1055.6405, 49.8147, 999.3657, 0.0000, 0.0000, -56.5000, -1, 3, -1, 350.0, 350.0, -1, 0); //Gen_doorEXT10
    g_hospital[88] = CreateDynamicObject(19453, 1039.7181, 49.8381, 1001.1367, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall093
    SetDynamicObjectMaterial(g_hospital[88], 0, 14383, "burg_1", "hospital_wall2", 0xFFFFFFFF);
    g_hospital[89] = CreateDynamicObject(19381, 1042.8204, 42.8086, 1002.9448, 0.0000, 90.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //wall029
    SetDynamicObjectMaterial(g_hospital[89], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    g_hospital[90] = CreateDynamicObject(1997, 1044.5433, 52.1539, 999.4536, 0.0000, 0.0000, 5.1999, -1, 3, -1, 350.0, 350.0, -1, 0); //hos_trolley
    g_hospital[91] = CreateDynamicObject(3386, 1043.1372, 52.8050, 999.4611, 0.0000, 0.0000, 90.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //a51_srack2_
    g_hospital[92] = CreateDynamicObject(2009, 1045.3779, 48.1073, 999.4442, 0.0000, 0.0000, -90.9999, -1, 3, -1, 350.0, 350.0, -1, 0); //officedesk2l
    g_hospital[93] = CreateDynamicObject(1671, 1045.6075, 47.1576, 999.9124, 0.0000, 0.0000, 128.8999, -1, 3, -1, 350.0, 350.0, -1, 0); //swivelchair_A
    g_hospital[94] = CreateDynamicObject(1811, 1047.3199, 47.8479, 1000.0380, 0.0000, 0.0000, -17.8999, -1, 3, -1, 350.0, 350.0, -1, 0); //MED_DIN_CHAIR_5
    g_hospital[95] = CreateDynamicObject(2813, 1045.5979, 48.1977, 1000.2766, 0.0000, 0.0000, -3.0999, -1, 3, -1, 350.0, 350.0, -1, 0); //GB_novels01
    g_hospital[96] = CreateDynamicObject(932, 1040.6417, 47.7271, 999.4282, 0.0000, 0.0000, 140.1999, -1, 3, -1, 350.0, 350.0, -1, 0); //H_WHEELCHAIR
    g_hospital[97] = CreateDynamicObject(3034, 1049.3315, 51.5051, 1000.9810, 0.0000, 0.0000, -56.7999, -1, 3, -1, 350.0, 350.0, -1, 0); //bd_window
    g_hospital[98] = CreateDynamicObject(3034, 1054.6684, 51.5494, 1001.0512, 0.0000, 0.0000, 123.7997, -1, 3, -1, 350.0, 350.0, -1, 0); //bd_window
    g_hospital[99] = CreateDynamicObject(19834, 1056.0987, 49.0105, 1000.8217, 0.0000, 25.7000, 124.0998, -1, 3, -1, 350.0, 350.0, -1, 0); //PoliceLineTape1
    g_hospital[100] = CreateDynamicObject(19944, 1062.9836, 50.0489, 999.4528, 0.0000, 0.0000, 179.4998, -1, 3, -1, 350.0, 350.0, -1, 0); //BodyBag1
    g_hospital[101] = CreateDynamicObject(19836, 1062.9503, 49.2985, 999.7614, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //BloodPool1
    g_hospital[102] = CreateDynamicObject(1997, 1059.7823, 52.0084, 999.9133, 0.0000, 89.0998, -48.4999, -1, 3, -1, 350.0, 350.0, -1, 0); //hos_trolley
    g_hospital[103] = CreateDynamicObject(348, 1062.0279, 49.2051, 999.4605, 91.9000, -8.8000, 41.5998, -1, 3, -1, 350.0, 350.0, -1, 0); //desert_eagle
    g_hospital[104] = CreateDynamicObject(19836, 1062.4121, 50.4305, 999.4843, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //BloodPool1
    g_hospital[105] = CreateDynamicObject(19836, 1060.8122, 49.7507, 999.4843, 0.0000, 0.0000, -39.8997, -1, 3, -1, 350.0, 350.0, -1, 0); //BloodPool1
    g_hospital[106] = CreateDynamicObject(19836, 1058.8631, 50.6631, 999.4843, 0.0000, 0.0000, 124.7997, -1, 3, -1, 350.0, 350.0, -1, 0); //BloodPool1
    g_hospital[107] = CreateObject(19436, 1040.5008, 58.5539, 1000.1721, 0.0000, 0.0000, 90.0000); //wall076
    SetObjectMaterialText(g_hospital[107], "Rippzy City", 0, 90, "Tahoma", 27, 1, 0xFF78222B, 0x0, 0);
    g_hospital[108] = CreateObject(19436, 1039.1196, 58.5539, 999.5515, 0.0000, 0.0000, 90.0000); //wall076
    SetObjectMaterialText(g_hospital[108], "Hospital", 0, 90, "Tahoma", 27, 1, 0xFF78222B, 0x0, 0);
    g_hospital[109] = CreateDynamicObject(14680, 1034.9774, 59.3232, 1001.1757, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //Int_tat_lights01
    g_hospital[110] = CreateDynamicObject(14680, 1045.3510, 59.3232, 1001.1757, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //Int_tat_lights01
    g_hospital[111] = CreateDynamicObject(14680, 1049.5506, 50.4430, 1001.1857, 0.0000, 0.0000, -58.7999, -1, 3, -1, 350.0, 350.0, -1, 0); //Int_tat_lights01
    g_hospital[112] = CreateDynamicObject(14680, 1045.8739, 47.3554, 1001.1857, 0.0000, 0.0000, 0.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //Int_tat_lights01
    g_hospital[113] = CreateDynamicObject(2009, 1064.9805, 47.0686, 999.4315, 0.0000, 0.0000, 89.5000, -1, 3, -1, 350.0, 350.0, -1, 0); //officedesk2l
    g_hospital[114] = CreateDynamicObject(19836, 1064.0339, 47.2385, 1000.2537, 0.0000, 0.0000, -32.5000, -1, 3, -1, 350.0, 350.0, -1, 0); //BloodPool1
    g_hospital[115] = CreateDynamicObject(1715, 1060.6921, 47.5177, 999.6975, 1.6999, 82.0998, 124.1999, -1, 3, -1, 350.0, 350.0, -1, 0); //kb_swivelchair2
    g_hospital[116] = CreateDynamicObject(2007, 1064.9737, 50.3350, 999.4597, 0.0000, 0.0000, 270.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //filing_cab_nu01
    g_hospital[117] = CreateDynamicObject(2007, 1064.9737, 51.3250, 999.4597, 0.0000, 0.0000, 270.0000, -1, 3, -1, 350.0, 350.0, -1, 0); //filing_cab_nu01
    g_hospital[118] = CreateDynamicObject(2007, 1056.1191, 51.5737, 999.9846, -91.9000, -8.6000, -61.4999, -1, 3, -1, 350.0, 350.0, -1, 0); //filing_cab_nu01
    return 1;
}