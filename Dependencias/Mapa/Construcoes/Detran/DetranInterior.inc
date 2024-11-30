#include <YSI_Coding\y_hooks>
new Detran_obt[168];
new bool:DetranPortao;

hook OnGameModeInit()
{
    Detran_obt[0] = CreateDynamicObject(19458, 407.9306, 307.2710, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098 
    SetDynamicObjectMaterial(Detran_obt[0], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[1] = CreateDynamicObject(19458, 404.4804, 316.8507, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[1], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[2] = CreateDynamicObject(19458, 401.8104, 307.2703, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[2], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[3] = CreateDynamicObject(19458, 401.7304, 297.7608, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[3], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[4] = CreateDynamicObject(19458, 407.9306, 316.8507, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[4], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[5] = CreateDynamicObject(19458, 404.4804, 307.2703, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[5], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[6] = CreateDynamicObject(19383, 399.9884, 310.4790, 1006.5324, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall031
    SetDynamicObjectMaterial(Detran_obt[6], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[7] = CreateDynamicObject(19451, 404.8739, 321.7327, 1006.5449, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[7], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[8] = CreateDynamicObject(19451, 409.7640, 316.8830, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[8], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[9] = CreateDynamicObject(19458, 398.3705, 297.7608, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[9], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[10] = CreateDynamicObject(19458, 411.3598, 297.7608, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[10], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[11] = CreateDynamicObject(19458, 407.9302, 297.7608, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[11], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[12] = CreateDynamicObject(19458, 398.3705, 307.2703, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[12], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[13] = CreateDynamicObject(19458, 405.1300, 297.7608, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[13], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[14] = CreateDynamicObject(2152, 399.6166, 307.9890, 1004.8629, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //CJ_K5_LOW_UNIT3
    Detran_obt[15] = CreateDynamicObject(19451, 399.9843, 299.4330, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[15], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[16] = CreateDynamicObject(2152, 399.6166, 306.6791, 1004.8629, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //CJ_K5_LOW_UNIT3
    Detran_obt[17] = CreateDynamicObject(2152, 399.6166, 305.3691, 1004.8629, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //CJ_K5_LOW_UNIT3
    Detran_obt[18] = CreateDynamicObject(2152, 399.6166, 304.7390, 1004.8629, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //CJ_K5_LOW_UNIT3
    Detran_obt[19] = CreateDynamicObject(2172, 397.0638, 305.2280, 1004.8054, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //MED_OFFICE2_DESK_1
    Detran_obt[20] = CreateDynamicObject(19451, 399.9443, 299.4330, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[20], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[21] = CreateDynamicObject(2162, 397.8416, 312.1026, 1004.8352, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //MED_OFFICE_UNIT_1
    Detran_obt[22] = CreateDynamicObject(19383, 409.7585, 310.4790, 1006.5324, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall031
    SetDynamicObjectMaterial(Detran_obt[22], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[23] = CreateDynamicObject(2930, 409.7598, 311.3536, 1007.3001, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //chinaTgate
    Detran_obt[24] = CreateDynamicObject(19458, 411.4497, 319.9508, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[24], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[25] = CreateDynamicObject(19451, 399.9843, 316.8830, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[25], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[26] = CreateDynamicObject(2922, 409.6306, 311.5577, 1006.3474, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //kmb_keypad
    Detran_obt[27] = CreateDynamicObject(19176, 404.9241, 321.5463, 1006.2861, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //LSOffice1Door1
    Detran_obt[28] = CreateDynamicObject(19451, 409.7640, 293.0137, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[28], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[29] = CreateDynamicObject(19451, 404.8540, 292.8940, 1006.5449, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[29], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[30] = CreateDynamicObject(19451, 399.9843, 297.7231, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[30], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[31] = CreateDynamicObject(19383, 409.7585, 298.7485, 1006.5324, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall031
    SetDynamicObjectMaterial(Detran_obt[31], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[32] = CreateDynamicObject(19451, 409.7640, 304.7742, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[32], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[33] = CreateDynamicObject(19458, 417.5697, 297.7608, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[33], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[34] = CreateDynamicObject(19458, 411.4497, 310.3912, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[34], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[35] = CreateDynamicObject(19458, 414.8293, 310.3912, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[35], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[36] = CreateDynamicObject(19451, 414.5138, 302.6343, 1006.5449, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[36], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[37] = CreateDynamicObject(19458, 414.7396, 297.7608, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[37], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[38] = CreateDynamicObject(19451, 419.3835, 297.8146, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[38], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[39] = CreateDynamicObject(19451, 414.5138, 292.9047, 1006.5449, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[39], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[40] = CreateDynamicObject(1502, 409.7582, 298.0097, 1004.7669, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //Gen_doorINT04
    Detran_obt[41] = CreateDynamicObject(19451, 395.1542, 312.1730, 1006.5449, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[41], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[42] = CreateDynamicObject(19451, 396.5346, 307.4432, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[42], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[43] = CreateDynamicObject(19451, 395.1047, 302.7026, 1006.5449, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[43], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[44] = CreateDynamicObject(1569, 400.0259, 309.7543, 1004.8139, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //ADAM_V_DOOR
    Detran_obt[45] = CreateDynamicObject(19458, 414.8301, 319.9508, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[45], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    Detran_obt[46] = CreateDynamicObject(2258, 400.0965, 298.1604, 1006.8757, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //Frame_Clip_5
    Detran_obt[47] = CreateDynamicObject(19451, 414.5138, 305.5044, 1006.5449, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[47], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[48] = CreateDynamicObject(19451, 416.6437, 310.3041, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[48], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[49] = CreateDynamicObject(19451, 416.6437, 319.9342, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[49], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[50] = CreateDynamicObject(19451, 414.5239, 324.7839, 1006.5449, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[50], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[51] = CreateDynamicObject(19451, 409.7640, 319.8833, 1006.5449, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall091
    SetDynamicObjectMaterial(Detran_obt[51], 0, 3437, "ballypillar01", "ballywall01_64", 0xFFFFFFFF);
    Detran_obt[52] = CreateDynamicObject(3657, 409.2882, 307.0869, 1005.3598, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //airseata_LAS
    Detran_obt[53] = CreateDynamicObject(3657, 409.2882, 301.9366, 1005.3598, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //airseata_LAS
    Detran_obt[54] = CreateDynamicObject(948, 409.3901, 299.7850, 1004.8178, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_10
    Detran_obt[55] = CreateDynamicObject(948, 409.3901, 309.2547, 1004.8178, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_10
    Detran_obt[56] = CreateDynamicObject(1808, 409.4703, 304.5250, 1004.8262, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //CJ_WATERCOOLER2
    Detran_obt[57] = CreateDynamicObject(19999, 397.8467, 305.6581, 1004.8413, 0.0000, 0.0000, -155.8999, 1301, 4, -1, 100.0, 100.0, -1); //CutsceneChair2
    Detran_obt[58] = CreateDynamicObject(2007, 397.1315, 307.2131, 1004.8483, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //filing_cab_nu01
    Detran_obt[59] = CreateDynamicObject(2007, 397.1315, 308.1630, 1004.8483, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //filing_cab_nu01
    Detran_obt[60] = CreateDynamicObject(2007, 397.1315, 309.1430, 1004.8483, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //filing_cab_nu01
    Detran_obt[61] = CreateDynamicObject(2261, 397.1238, 308.2070, 1006.7753, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //Frame_SLIM_2
    Detran_obt[62] = CreateDynamicObject(19458, 411.3699, 316.8507, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[62], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[63] = CreateDynamicObject(2164, 398.7810, 302.8554, 1004.8494, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //MED_OFFICE_UNIT_5
    Detran_obt[64] = CreateDynamicObject(19807, 399.7968, 307.4768, 1005.9918, 0.0000, 0.0000, -56.9999, 1301, 4, -1, 100.0, 100.0, -1); //Telephone1
    Detran_obt[65] = CreateDynamicObject(19894, 399.7514, 305.6124, 1005.9182, 0.0000, 0.0000, -89.3999, 1301, 4, -1, 100.0, 100.0, -1); //LaptopSAMP2
    Detran_obt[66] = CreateDynamicObject(19624, 396.7398, 310.6549, 1005.2703, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //Case1
    Detran_obt[67] = CreateDynamicObject(11729, 410.2020, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[68] = CreateDynamicObject(11729, 410.8519, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[69] = CreateDynamicObject(11729, 411.5020, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[70] = CreateDynamicObject(11729, 412.1518, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[71] = CreateDynamicObject(11729, 412.8017, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[72] = CreateDynamicObject(11729, 413.4715, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[73] = CreateDynamicObject(11729, 414.1315, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[74] = CreateDynamicObject(11729, 414.7918, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[75] = CreateDynamicObject(11729, 415.4519, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[76] = CreateDynamicObject(11729, 416.1119, 324.4408, 1004.8306, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //GymLockerClosed1
    Detran_obt[77] = CreateDynamicObject(3657, 413.3872, 305.9931, 1005.3660, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //airseata_LAS
    Detran_obt[78] = CreateDynamicObject(948, 415.5531, 305.8579, 1004.8156, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_10
    Detran_obt[79] = CreateDynamicObject(948, 411.2431, 305.8579, 1004.8156, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_10
    Detran_obt[80] = CreateDynamicObject(19922, 413.1090, 320.4794, 1004.8359, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //MKTable1
    SetDynamicObjectMaterial(Detran_obt[80], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    Detran_obt[81] = CreateDynamicObject(11749, 412.6861, 319.5884, 1005.6300, 0.0000, 0.0000, -59.6999, 1301, 4, -1, 100.0, 100.0, -1); //CSHandcuffs1
    Detran_obt[82] = CreateDynamicObject(18642, 412.9305, 319.3692, 1005.6386, 90.0000, 56.5999, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Taser1
    Detran_obt[83] = CreateDynamicObject(19893, 412.9013, 320.1528, 1005.6237, 0.0000, 0.0000, -116.1998, 1301, 4, -1, 100.0, 100.0, -1); //LaptopSAMP1
    Detran_obt[84] = CreateDynamicObject(19904, 413.5134, 321.6442, 1005.9317, 0.0000, 0.0000, -36.0000, 1301, 4, -1, 100.0, 100.0, -1); //ConstructionVest1
    Detran_obt[85] = CreateDynamicObject(19792, 412.6069, 319.8898, 1005.6328, 0.0000, 0.0000, -101.6998, 1301, 4, -1, 100.0, 100.0, -1); //SAMPKeycard1
    Detran_obt[86] = CreateDynamicObject(348, 413.2434, 320.7264, 1005.6394, 90.0000, 54.5999, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //desert_eagle
    Detran_obt[87] = CreateDynamicObject(334, 412.8280, 321.3026, 1005.6195, 90.0000, -22.5998, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //nitestick
    Detran_obt[88] = CreateDynamicObject(19942, 413.3649, 319.5487, 1005.7351, 270.0000, 90.0000, 133.1000, 1301, 4, -1, 100.0, 100.0, -1); //PoliceRadio1
    Detran_obt[89] = CreateDynamicObject(19099, 413.4877, 320.2102, 1005.6931, -176.6999, 90.5000, -51.4999, 1301, 4, -1, 100.0, 100.0, -1); //PoliceCap2
    Detran_obt[90] = CreateDynamicObject(2611, 409.8962, 320.4692, 1006.6408, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //POLICE_NB1
    Detran_obt[91] = CreateDynamicObject(2604, 416.0968, 315.3776, 1005.6262, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //CJ_POLICE_COUNTER
    Detran_obt[92] = CreateDynamicObject(19999, 415.1817, 315.8833, 1004.8341, 0.0000, 0.0000, 107.6998, 1301, 4, -1, 100.0, 100.0, -1); //CutsceneChair2
    Detran_obt[93] = CreateDynamicObject(1806, 415.2778, 314.1268, 1004.8513, 0.0000, 0.0000, -64.5999, 1301, 4, -1, 100.0, 100.0, -1); //MED_OFFICE_CHAIR
    Detran_obt[94] = CreateDynamicObject(2922, 409.8504, 311.5577, 1006.3474, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //kmb_keypad
    Detran_obt[95] = CreateDynamicObject(2007, 416.0736, 312.0114, 1004.8319, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //filing_cab_nu01
    Detran_obt[96] = CreateDynamicObject(2007, 416.0736, 311.0314, 1004.8319, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //filing_cab_nu01
    Detran_obt[97] = CreateDynamicObject(2007, 416.0736, 310.0513, 1004.8319, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //filing_cab_nu01
    Detran_obt[98] = CreateDynamicObject(1808, 416.3692, 307.9519, 1004.8419, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //CJ_WATERCOOLER2
    Detran_obt[99] = CreateDynamicObject(2185, 419.1474, 294.7381, 1004.8464, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //MED_OFFICE6_DESK_1
    Detran_obt[100] = CreateDynamicObject(1663, 418.4425, 293.7178, 1005.2973, 0.0000, 0.0000, -144.8999, 1301, 4, -1, 100.0, 100.0, -1); //swivelchair_B
    Detran_obt[101] = CreateDynamicObject(19808, 418.0657, 294.5162, 1005.6848, 0.0000, 0.0000, 26.8999, 1301, 4, -1, 100.0, 100.0, -1); //Keyboard1
    Detran_obt[102] = CreateDynamicObject(2894, 418.7492, 294.6975, 1005.6580, 0.0000, 0.0000, -32.1999, 1301, 4, -1, 100.0, 100.0, -1); //kmb_rhymesbook
    Detran_obt[103] = CreateDynamicObject(19805, 414.3782, 293.0372, 1006.4594, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Whiteboard1
    Detran_obt[104] = CreateDynamicObject(2007, 410.3507, 293.5151, 1004.8344, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //filing_cab_nu01
    Detran_obt[105] = CreateDynamicObject(2007, 411.3409, 293.5151, 1004.8344, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //filing_cab_nu01
    Detran_obt[106] = CreateDynamicObject(2007, 412.3309, 293.5151, 1004.8344, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //filing_cab_nu01
    Detran_obt[107] = CreateDynamicObject(1722, 416.0859, 296.6437, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[108] = CreateDynamicObject(1722, 415.0152, 296.6437, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[109] = CreateDynamicObject(1722, 413.9151, 296.6437, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[110] = CreateDynamicObject(1722, 412.8345, 296.6437, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[111] = CreateDynamicObject(1722, 412.8345, 297.9935, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[112] = CreateDynamicObject(1722, 413.8947, 297.9935, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[113] = CreateDynamicObject(1722, 414.9948, 297.9935, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[114] = CreateDynamicObject(1722, 416.0947, 297.9935, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[115] = CreateDynamicObject(1722, 416.0947, 299.3136, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[116] = CreateDynamicObject(1722, 415.0046, 299.3136, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[117] = CreateDynamicObject(1722, 413.9042, 299.3136, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[118] = CreateDynamicObject(1722, 412.8243, 299.3136, 1004.9074, 0.0000, 0.0000, 180.0000, 1301, 4, -1, 100.0, 100.0, -1); //off_chairnu
    Detran_obt[119] = CreateDynamicObject(1808, 410.0418, 297.4584, 1004.8391, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //CJ_WATERCOOLER2
    Detran_obt[120] = CreateDynamicObject(2258, 409.8745, 295.3973, 1006.4155, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //Frame_Clip_5
    Detran_obt[121] = CreateDynamicObject(2200, 419.1492, 298.2517, 1004.8447, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //MED_OFFICE5_UNIT_1
    Detran_obt[122] = CreateDynamicObject(2200, 419.1492, 300.4418, 1004.8447, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //MED_OFFICE5_UNIT_1
    Detran_obt[123] = CreateDynamicObject(2198, 413.8681, 302.0318, 1004.8400, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //MED_OFFICE2_DESK_3
    Detran_obt[124] = CreateDynamicObject(1806, 414.5686, 301.3568, 1004.7800, 0.0000, 0.0000, 35.4999, 1301, 4, -1, 100.0, 100.0, -1); //MED_OFFICE_CHAIR
    Detran_obt[125] = CreateDynamicObject(19808, 414.3385, 301.8998, 1005.6536, 0.0000, 0.0000, 31.9999, 1301, 4, -1, 100.0, 100.0, -1); //Keyboard1
    Detran_obt[126] = CreateDynamicObject(19458, 401.0303, 316.8507, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[126], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[127] = CreateDynamicObject(19458, 404.4804, 316.8507, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[127], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[128] = CreateDynamicObject(19458, 407.9299, 316.8507, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[128], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[129] = CreateDynamicObject(19458, 404.4804, 307.2708, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[129], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[130] = CreateDynamicObject(19458, 404.4804, 297.7207, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[130], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[131] = CreateDynamicObject(19458, 401.0303, 307.2907, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[131], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[132] = CreateDynamicObject(19458, 401.0303, 297.7109, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[132], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[133] = CreateDynamicObject(19458, 407.9104, 297.7314, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[133], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[134] = CreateDynamicObject(19458, 407.9104, 307.2810, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[134], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[135] = CreateDynamicObject(19458, 397.7503, 307.2907, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[135], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[136] = CreateDynamicObject(19452, 399.9609, 304.0710, 1008.8079, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall092
    SetDynamicObjectMaterial(Detran_obt[136], 0, 1717, "cj_tv", "green_glass_64", 0xFFFFFFFF);
    Detran_obt[137] = CreateDynamicObject(19458, 414.7997, 316.8507, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[137], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[138] = CreateDynamicObject(19458, 411.3796, 307.2904, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[138], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[139] = CreateDynamicObject(19458, 414.7997, 307.2904, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[139], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[140] = CreateDynamicObject(19458, 414.7997, 320.0603, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[140], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[141] = CreateDynamicObject(19458, 411.4898, 320.0603, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[141], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[142] = CreateDynamicObject(19458, 411.3705, 297.7314, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[142], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[143] = CreateDynamicObject(19458, 414.8004, 297.7314, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[143], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[144] = CreateDynamicObject(19458, 418.1003, 297.7314, 1008.3145, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[144], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    Detran_obt[145] = CreateDynamicObject(949, 402.8645, 321.3882, 1005.4736, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_4
    Detran_obt[146] = CreateDynamicObject(949, 406.9645, 321.3882, 1005.4736, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_4
    Detran_obt[147] = CreateDynamicObject(19353, 403.6000, 292.8996, 1005.4559, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall001
    SetDynamicObjectMaterialText(Detran_obt[147], 0, "C", 90, "Arial", 38, 1, 0xFFFFFFFF, 0x0, 0);
    Detran_obt[148] = CreateDynamicObject(19353, 403.7127, 292.8958, 1005.8735, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall001
    SetDynamicObjectMaterialText(Detran_obt[148], 0, "R", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    Detran_obt[149] = CreateDynamicObject(19825, 400.1073, 317.3717, 1007.1055, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //SprunkClock1
    Detran_obt[150] = CreateDynamicObject(19353, 404.1129, 292.8955, 1004.6231, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall001

    SetDynamicObjectMaterialText(Detran_obt[150], 0, "Detran", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 0);
    Detran_obt[151] = CreateDynamicObject(3657, 409.2882, 317.4966, 1005.3598, 0.0000, 0.0000, 270.0000, 1301, 4, -1, 100.0, 100.0, -1); //airseata_LAS
    Detran_obt[152] = CreateDynamicObject(948, 409.3901, 315.2648, 1004.8178, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_10
    Detran_obt[153] = CreateDynamicObject(948, 409.3901, 319.6849, 1004.8178, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_10
    Detran_obt[154] = CreateDynamicObject(1744, 399.9151, 316.8479, 1005.4822, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //MED_SHELF
    Detran_obt[155] = CreateDynamicObject(19422, 400.2615, 317.6910, 1005.8267, 0.0000, 0.0000, 44.0000, 1301, 4, -1, 100.0, 100.0, -1); //headphones02
    Detran_obt[156] = CreateDynamicObject(330, 400.2605, 317.0264, 1005.8037, 90.0000, -153.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //cellphone
    Detran_obt[157] = CreateDynamicObject(19894, 400.2478, 316.6604, 1005.8269, 0.0000, 0.0000, 97.5000, 1301, 4, -1, 100.0, 100.0, -1); //LaptopSAMP2
    Detran_obt[158] = CreateDynamicObject(19792, 400.2413, 317.4198, 1005.8355, 0.0000, 0.0000, 64.8999, 1301, 4, -1, 100.0, 100.0, -1); //SAMPKeycard1
    Detran_obt[159] = CreateDynamicObject(11746, 400.2131, 318.0491, 1005.8389, 90.0000, 54.2999, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //DoorKey1
    Detran_obt[160] = CreateDynamicObject(3657, 400.4783, 298.2268, 1005.3598, 0.0000, 0.0000, 90.0000, 1301, 4, -1, 100.0, 100.0, -1); //airseata_LAS
    Detran_obt[161] = CreateDynamicObject(948, 400.3803, 300.4346, 1004.8178, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_10
    Detran_obt[162] = CreateDynamicObject(948, 400.3803, 295.9945, 1004.8178, 0.0000, 0.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //Plant_Pot_10
    Detran_obt[163] = CreateDynamicObject(19458, 400.9808, 316.8802, 1004.7634, 0.0000, 90.0000, 0.0000, 1301, 4, -1, 100.0, 100.0, -1); //wall098
    SetDynamicObjectMaterial(Detran_obt[163], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys){
    if(newkeys == KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){

        //Portão que dá acesso a sala do detran
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 409.7599, 311.3537, 1007.3002) && GetPlayerVirtualWorld(playerid) == 1301){
            if(Jogador[playerid][Admin] > 0){
                if(DetranPortao == false){
                    SetTimerEx("FecharPortaoDetran", 5000, false, "d", 1);
                    MoveObject(Detran_obt[23], 409.7599, 311.3537, 1007.3002+2.6, 2.0);
                    DetranPortao = true;
                }
            }
        }

    }
    return 1;
}

function FecharPortaoDetran(Gate, Objeto)
{
    MoveObject(Detran_obt[23], 409.7599, 311.3537, 1007.3002, 5.0);
    DetranPortao = false;
    return 1;
}