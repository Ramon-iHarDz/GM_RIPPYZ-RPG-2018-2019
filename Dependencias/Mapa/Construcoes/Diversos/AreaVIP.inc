#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    new asdjasuhs[28]; 
    asdjasuhs[0] = CreateDynamicObject(19922, 2171.4792, 1584.9783, 998.9439, 0.0000, 0.0000, 90.0000, 4176, 1, -1, 160.0, 170.0, -1); //MKTable1
    SetDynamicObjectMaterial(asdjasuhs[0], 0, 18058, "mp_diner2", "mp_diner_table", 0xFFFFFFFF);
    asdjasuhs[1] = CreateDynamicObject(355, 2171.4707, 1585.9096, 999.7270, 84.4999, -49.3000, -12.4999, 4176, 1, -1, 160.0, 170.0, -1); //ak47
    asdjasuhs[2] = CreateDynamicObject(355, 2171.6208, 1584.8106, 999.7250, 84.4999, -49.3000, -161.1999, 4176, 1, -1, 160.0, 170.0, -1); //ak47
    asdjasuhs[3] = CreateDynamicObject(348, 2170.9023, 1586.2154, 999.7395, 90.0000, -32.4000, 69.2999, 4176, 1, -1, 160.0, 170.0, -1); //desert_eagle
    asdjasuhs[4] = CreateDynamicObject(348, 2170.9880, 1585.8647, 999.7395, 90.0000, -32.4000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //desert_eagle
    asdjasuhs[5] = CreateDynamicObject(1575, 2171.8574, 1586.1942, 999.7290, 0.0000, 0.0000, -52.0999, 4176, 1, -1, 160.0, 170.0, -1); //drug_white
    asdjasuhs[6] = CreateDynamicObject(356, 2171.2475, 1584.3204, 999.7429, 86.1000, -47.9000, -43.4999, 4176, 1, -1, 160.0, 170.0, -1); //m4
    asdjasuhs[7] = CreateDynamicObject(356, 2171.6066, 1584.3110, 999.7264, 86.1000, -47.9000, -43.4999, 4176, 1, -1, 160.0, 170.0, -1); //m4
    asdjasuhs[8] = CreateDynamicObject(19941, 2171.9450, 1583.7065, 999.7302, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //GoldBar1
    asdjasuhs[9] = CreateDynamicObject(19941, 2171.9450, 1583.8466, 999.7302, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //GoldBar1
    asdjasuhs[10] = CreateDynamicObject(19941, 2171.9450, 1583.7766, 999.7302, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //GoldBar1
    asdjasuhs[11] = CreateDynamicObject(19941, 2171.9450, 1583.9167, 999.7302, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //GoldBar1
    asdjasuhs[12] = CreateDynamicObject(19941, 2171.9450, 1583.9868, 999.7302, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //GoldBar1
    asdjasuhs[13] = CreateDynamicObject(19941, 2171.9450, 1583.9167, 999.7703, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //GoldBar1
    asdjasuhs[14] = CreateDynamicObject(19941, 2171.9450, 1583.8466, 999.7703, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //GoldBar1
    asdjasuhs[15] = CreateDynamicObject(19941, 2171.9450, 1583.7766, 999.7703, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //GoldBar1
    asdjasuhs[16] = CreateDynamicObject(19941, 2171.9450, 1583.8466, 999.8103, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //GoldBar1
    asdjasuhs[17] = CreateDynamicObject(350, 2172.0217, 1584.1724, 999.7138, 90.0000, 140.8999, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //sawnoff
    asdjasuhs[18] = CreateDynamicObject(1580, 2172.0026, 1585.2565, 999.7001, 0.0000, 0.0000, -93.3999, 4176, 1, -1, 160.0, 170.0, -1); //drug_red
    asdjasuhs[19] = CreateDynamicObject(358, 2172.4028, 1586.2026, 999.2513, -26.5000, -84.2999, 88.1000, 4176, 1, -1, 160.0, 170.0, -1); //sniper
    asdjasuhs[20] = CreateDynamicObject(2041, 2170.9741, 1584.8594, 999.9326, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //AMMO_BOX_M2
    asdjasuhs[21] = CreateDynamicObject(2358, 2168.5397, 1588.3179, 999.0588, 0.0000, 0.0000, 90.0000, 4176, 1, -1, 160.0, 170.0, -1); //AMMO_BOX_c2
    asdjasuhs[22] = CreateDynamicObject(2358, 2168.5397, 1587.6179, 999.0588, 0.0000, 0.0000, 90.0000, 4176, 1, -1, 160.0, 170.0, -1); //AMMO_BOX_c2
    asdjasuhs[23] = CreateDynamicObject(2358, 2168.5397, 1587.9482, 999.2791, 0.0000, 0.0000, 90.0000, 4176, 1, -1, 160.0, 170.0, -1); //AMMO_BOX_c2
    asdjasuhs[24] = CreateDynamicObject(1569, 2223.5742, 1598.2131, 998.9540, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //ADAM_V_DOOR
    asdjasuhs[25] = CreateDynamicObject(1569, 2225.0957, 1598.2131, 1003.9445, 0.0000, 180.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //ADAM_V_DOOR
    asdjasuhs[26] = CreateDynamicObject(1569, 2175.6755, 1594.2897, 998.9388, 0.0000, 0.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //ADAM_V_DOOR
    asdjasuhs[27] = CreateDynamicObject(1569, 2177.1767, 1594.2897, 1003.9382, 0.0000, 180.0000, 0.0000, 4176, 1, -1, 160.0, 170.0, -1); //ADAM_V_DOOR
    return 1;
}