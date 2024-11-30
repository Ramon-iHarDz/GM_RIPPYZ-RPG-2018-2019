#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    new bb_Bombeiros[77];
    bb_Bombeiros[0] = CreateDynamicObject(19381, 2434.4926, -1174.6934, 1027.4594, 0.0000, 90.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall029
    SetDynamicObjectMaterial(bb_Bombeiros[0], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    bb_Bombeiros[1] = CreateDynamicObject(19381, 2424.0642, -1174.6934, 1027.4594, 0.0000, 90.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall029
    SetDynamicObjectMaterial(bb_Bombeiros[1], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    bb_Bombeiros[2] = CreateDynamicObject(19381, 2434.4926, -1165.1237, 1027.4594, 0.0000, 90.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall029
    SetDynamicObjectMaterial(bb_Bombeiros[2], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    bb_Bombeiros[3] = CreateDynamicObject(19461, 2418.7580, -1174.6867, 1029.2796, 0.0000, 0.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[3], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[4] = CreateDynamicObject(19461, 2424.4658, -1169.8409, 1029.2796, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[4], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[5] = CreateDynamicObject(19461, 2414.8659, -1169.8409, 1029.2796, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[5], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[6] = CreateDynamicObject(19461, 2429.2565, -1165.1105, 1029.2796, 0.0000, 0.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[6], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[7] = CreateDynamicObject(19461, 2439.7966, -1165.1105, 1029.2796, 0.0000, 0.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[7], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[8] = CreateDynamicObject(19461, 2439.7966, -1174.7102, 1029.2796, 0.0000, 0.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[8], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[9] = CreateDynamicObject(19461, 2435.0153, -1179.5192, 1029.2796, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[9], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[10] = CreateDynamicObject(19461, 2435.0654, -1160.2690, 1029.2796, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[10], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[11] = CreateDynamicObject(19461, 2425.4655, -1160.2690, 1029.2796, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[11], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[12] = CreateDynamicObject(19461, 2415.8327, -1179.5192, 1029.2796, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[12], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[13] = CreateDynamicObject(2614, 2439.6647, -1174.2852, 1029.5627, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //CJ_US_FLAG
    bb_Bombeiros[14] = CreateDynamicObject(19176, 2418.9257, -1174.6727, 1028.9941, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //LSOffice1Door1
    bb_Bombeiros[15] = CreateDynamicObject(19461, 2425.4121, -1179.5192, 1029.2796, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall101
    SetDynamicObjectMaterial(bb_Bombeiros[15], 0, 7525, "vgnfirestat", "vgnfirestat4_256", 0xFFFFFFFF);
    bb_Bombeiros[16] = CreateDynamicObject(11729, 2429.5976, -1160.6917, 1027.5361, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[17] = CreateDynamicObject(18092, 2437.8505, -1174.3027, 1028.0416, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //ammun3_counter
    SetDynamicObjectMaterial(bb_Bombeiros[17], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    bb_Bombeiros[18] = CreateDynamicObject(11729, 2429.5976, -1161.3521, 1027.5361, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[19] = CreateDynamicObject(11729, 2429.5976, -1162.0124, 1027.5361, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[20] = CreateDynamicObject(11729, 2429.5976, -1162.6630, 1027.5361, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[21] = CreateDynamicObject(11729, 2429.5976, -1163.3137, 1027.5361, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[22] = CreateDynamicObject(11729, 2429.5976, -1163.9737, 1027.5361, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[23] = CreateDynamicObject(11729, 2429.5976, -1164.6243, 1027.5361, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[24] = CreateDynamicObject(11729, 2429.5976, -1165.2747, 1027.5361, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[25] = CreateDynamicObject(11729, 2429.5976, -1165.9250, 1027.5361, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[26] = CreateDynamicObject(11729, 2439.4604, -1165.9250, 1027.5361, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[27] = CreateDynamicObject(11729, 2439.4604, -1165.2646, 1027.5361, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[28] = CreateDynamicObject(11729, 2439.4604, -1164.6146, 1027.5361, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[29] = CreateDynamicObject(11729, 2439.4604, -1163.9641, 1027.5361, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[30] = CreateDynamicObject(11729, 2439.4604, -1163.3041, 1027.5361, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[31] = CreateDynamicObject(11729, 2439.4604, -1162.6541, 1027.5361, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[32] = CreateDynamicObject(11729, 2439.4604, -1162.0040, 1027.5361, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[33] = CreateDynamicObject(11729, 2439.4604, -1161.3540, 1027.5361, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[34] = CreateDynamicObject(11729, 2439.4604, -1160.6942, 1027.5361, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //GymLockerClosed1
    bb_Bombeiros[35] = CreateDynamicObject(19825, 2439.6547, -1168.5135, 1029.6463, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //SprunkClock1
    bb_Bombeiros[36] = CreateDynamicObject(19807, 2437.5859, -1175.4254, 1028.6174, 0.0000, 0.0000, 123.5000, 7181, 5, -1, 90.0, 90.0, -1); //Telephone1
    bb_Bombeiros[37] = CreateDynamicObject(2190, 2437.5061, -1173.6772, 1028.5312, 0.0000, 0.0000, 48.9000, 7181, 5, -1, 90.0, 90.0, -1); //PC_1
    bb_Bombeiros[38] = CreateDynamicObject(3657, 2423.9902, -1170.3333, 1028.0324, 0.0000, 0.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //airseata_LAS
    bb_Bombeiros[39] = CreateDynamicObject(3657, 2423.9902, -1179.0236, 1028.0324, 0.0000, 0.0000, 180.0000, 7181, 5, -1, 90.0, 90.0, -1); //airseata_LAS
    bb_Bombeiros[40] = CreateDynamicObject(19805, 2434.3137, -1160.4013, 1029.1656, 0.0000, 0.0000, -180.0000, 7181, 5, -1, 90.0, 90.0, -1); //Whiteboard1
    bb_Bombeiros[41] = CreateDynamicObject(19331, 2434.6279, -1164.7360, 1028.4353, -4.5999, -90.7999, -142.3000, 7181, 5, -1, 90.0, 90.0, -1); //fire_hat02
    bb_Bombeiros[42] = CreateDynamicObject(19330, 2434.1372, -1165.3193, 1028.4350, -175.4999, 88.6999, -29.5999, 7181, 5, -1, 90.0, 90.0, -1); //fire_hat01
    bb_Bombeiros[43] = CreateDynamicObject(19922, 2434.3627, -1164.3424, 1027.5468, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //MKTable1
    SetDynamicObjectMaterial(bb_Bombeiros[43], 0, 3881, "apsecurity_sfxrf", "CJ_WOOD1", 0xFFFFFFFF);
    bb_Bombeiros[44] = CreateDynamicObject(2690, 2434.6677, -1163.3326, 1028.6923, 0.0000, 0.0000, -40.7000, 7181, 5, -1, 90.0, 90.0, -1); //CJ_FIRE_EXT
    bb_Bombeiros[45] = CreateDynamicObject(2690, 2434.3784, -1163.1433, 1028.6923, 0.0000, 0.0000, -3.5999, 7181, 5, -1, 90.0, 90.0, -1); //CJ_FIRE_EXT
    bb_Bombeiros[46] = CreateDynamicObject(2690, 2433.9377, -1163.2309, 1028.6923, 0.0000, 0.0000, 48.1000, 7181, 5, -1, 90.0, 90.0, -1); //CJ_FIRE_EXT
    bb_Bombeiros[47] = CreateDynamicObject(11713, 2427.6474, -1169.9735, 1029.2366, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //FireExtPanel1
    bb_Bombeiros[48] = CreateDynamicObject(2961, 2418.8583, -1172.4743, 1029.0773, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //fire_break
    bb_Bombeiros[49] = CreateDynamicObject(11710, 2418.8269, -1174.6687, 1030.6751, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //FireExitSign1
    bb_Bombeiros[50] = CreateDynamicObject(19893, 2434.6276, -1165.5007, 1028.3453, 0.0000, 0.0000, -29.3000, 7181, 5, -1, 90.0, 90.0, -1); //LaptopSAMP1
    bb_Bombeiros[51] = CreateDynamicObject(19631, 2434.2780, -1164.0263, 1028.3850, 0.0000, 90.0000, 149.3999, 7181, 5, -1, 90.0, 90.0, -1); //SledgeHammer1
    bb_Bombeiros[52] = CreateDynamicObject(19330, 2433.9936, -1163.9537, 1028.4301, -175.4999, 88.6999, -100.8000, 7181, 5, -1, 90.0, 90.0, -1); //fire_hat01
    bb_Bombeiros[53] = CreateDynamicObject(19331, 2434.7009, -1164.0338, 1028.4411, -4.5999, -90.7999, -66.9001, 7181, 5, -1, 90.0, 90.0, -1); //fire_hat02
    bb_Bombeiros[54] = CreateDynamicObject(19894, 2433.9787, -1164.7279, 1028.3262, 0.0000, 0.0000, -47.3999, 7181, 5, -1, 90.0, 90.0, -1); //LaptopSAMP2
    bb_Bombeiros[55] = CreateDynamicObject(2267, 2429.3767, -1167.9727, 1029.3408, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //Frame_WOOD_3
    bb_Bombeiros[56] = CreateDynamicObject(2002, 2429.8486, -1169.2401, 1027.5412, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //water_coolnu
    bb_Bombeiros[57] = CreateDynamicObject(19381, 2424.0642, -1174.6934, 1031.0900, 0.0000, 90.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall029
    SetDynamicObjectMaterial(bb_Bombeiros[57], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    bb_Bombeiros[58] = CreateDynamicObject(19381, 2434.5126, -1174.6934, 1031.0900, 0.0000, 90.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall029
    SetDynamicObjectMaterial(bb_Bombeiros[58], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    bb_Bombeiros[59] = CreateDynamicObject(19381, 2434.5126, -1165.1132, 1031.0900, 0.0000, 90.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //wall029
    SetDynamicObjectMaterial(bb_Bombeiros[59], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    bb_Bombeiros[60] = CreateDynamicObject(2164, 2434.2780, -1179.4255, 1027.5487, 0.0000, 0.0000, -180.0000, 7181, 5, -1, 90.0, 90.0, -1); //MED_OFFICE_UNIT_5
    bb_Bombeiros[61] = CreateDynamicObject(2164, 2432.5285, -1179.4255, 1027.5487, 0.0000, 0.0000, -180.0000, 7181, 5, -1, 90.0, 90.0, -1); //MED_OFFICE_UNIT_5
    bb_Bombeiros[62] = CreateDynamicObject(2007, 2430.4694, -1178.9346, 1027.5230, 0.0000, 0.0000, -180.0000, 7181, 5, -1, 90.0, 90.0, -1); //filing_cab_nu01
    bb_Bombeiros[63] = CreateDynamicObject(2007, 2429.4785, -1178.9346, 1027.5230, 0.0000, 0.0000, -180.0000, 7181, 5, -1, 90.0, 90.0, -1); //filing_cab_nu01
    bb_Bombeiros[64] = CreateDynamicObject(2007, 2428.4975, -1178.9346, 1027.5230, 0.0000, 0.0000, -180.0000, 7181, 5, -1, 90.0, 90.0, -1); //filing_cab_nu01
    bb_Bombeiros[65] = CreateDynamicObject(1671, 2438.8923, -1174.4796, 1027.9927, 0.0000, 0.0000, -158.3000, 7181, 5, -1, 90.0, 90.0, -1); //swivelchair_A
    bb_Bombeiros[66] = CreateDynamicObject(2199, 2439.6306, -1178.0012, 1027.5417, 0.0000, 0.0000, -90.0000, 7181, 5, -1, 90.0, 90.0, -1); //MED_OFFICE6_MC_1
    bb_Bombeiros[67] = CreateDynamicObject(2269, 2437.1608, -1178.9266, 1029.0407, 0.0000, 0.0000, 180.0000, 7181, 5, -1, 90.0, 90.0, -1); //Frame_WOOD_4
    bb_Bombeiros[68] = CreateDynamicObject(2270, 2419.3620, -1177.4062, 1028.8239, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //Frame_WOOD_6
    bb_Bombeiros[69] = CreateDynamicObject(2002, 2419.3574, -1178.4935, 1027.5200, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //water_coolnu
    bb_Bombeiros[70] = CreateDynamicObject(2894, 2437.6250, -1172.5040, 1028.5394, 0.0000, 0.0000, 50.5999, 7181, 5, -1, 90.0, 90.0, -1); //kmb_rhymesbook
    bb_Bombeiros[71] = CreateDynamicObject(1893, 2421.7309, -1177.0786, 1031.1878, 0.0000, 0.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //shoplight1
    bb_Bombeiros[72] = CreateDynamicObject(1893, 2421.7309, -1172.2559, 1031.1878, 0.0000, 0.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //shoplight1
    bb_Bombeiros[73] = CreateDynamicObject(1893, 2434.1037, -1172.2559, 1031.1878, 0.0000, 0.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //shoplight1
    bb_Bombeiros[74] = CreateDynamicObject(1893, 2434.1037, -1177.0867, 1031.1878, 0.0000, 0.0000, 0.0000, 7181, 5, -1, 90.0, 90.0, -1); //shoplight1
    bb_Bombeiros[75] = CreateDynamicObject(1893, 2431.9013, -1164.8652, 1031.1878, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //shoplight1
    bb_Bombeiros[76] = CreateDynamicObject(1893, 2437.1560, -1164.8652, 1031.1878, 0.0000, 0.0000, 90.0000, 7181, 5, -1, 90.0, 90.0, -1); //shoplight1
    return 1;
}