#include <YSI_Coding\y_hooks>

stock ConfigurarInteriorFabrica(id)
{
    new vw = PegarFabricaVw(id);
    pFabricaObjeto[id][0] = CreateDynamicObject(3037, 2178.2712, -2254.4511, 15.9153, 0.0000, 0.0000, -44.8997, vw, 0, -1, 400.0, 400.0, -1); //warehouse_door2b
    pFabricaObjeto[id][1] = CreateDynamicObject(1344, 2138.4064, -2251.7019, 13.0993, 0.0000, 0.0000, 46.6999, vw, 0, -1, 400.0, 400.0, -1); //CJ_Dumpster2
    pFabricaObjeto[id][2] = CreateDynamicObject(17051, 2158.3452, -2240.4726, -1.2135, 0.0000, 0.0000, 107.9000, vw, 0, -1, 400.0, 400.0, -1); //cw_Silo03
    pFabricaObjeto[id][3] = CreateDynamicObject(17051, 2151.7189, -2248.3312, -1.2135, 0.0000, 0.0000, 107.9000, vw, 0, -1, 400.0, 400.0, -1); //cw_Silo03
    pFabricaObjeto[id][4] = CreateDynamicObject(1542, 2154.1440, -2249.8957, 13.6913, 0.0000, 0.0996, 55.8997, vw, 0, -1, 400.0, 400.0, -1); //CJ_BEER_TAPS_2
    pFabricaObjeto[id][5] = CreateDynamicObject(1744, 2153.7583, -2250.1699, 12.9685, 0.0000, 0.0000, 57.5998, vw, 0, -1, 400.0, 400.0, -1); //MED_SHELF
    pFabricaObjeto[id][6] = CreateDynamicObject(19893, 2154.8222, -2249.3562, 13.3170, 0.0000, 0.0000, 50.2000, vw, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    pFabricaObjeto[id][7] = CreateDynamicObject(19431, 2160.6960, -2241.9587, 14.0741, 0.0000, 0.0000, -32.8997, vw, 0, -1, 400.0, 400.0, -1); //wall071
    SetDynamicObjectMaterialText(pFabricaObjeto[id][7], 0, "Cuidado", 90, "System", 25, 1, 0xFF840410, 0x0, 0);
    pFabricaObjeto[id][8] = CreateDynamicObject(19431, 2154.0693, -2249.8320, 14.9644, 0.0000, 0.0000, -32.8997, vw, 0, -1, 400.0, 400.0, -1); //wall071
    SetDynamicObjectMaterialText(pFabricaObjeto[id][8], 0, "Liquidos", 90, "System", 35, 1, 0xFFFFFFFF, 0x0, 0);
    pFabricaObjeto[id][9] = CreateDynamicObject(19431, 2154.0593, -2249.8337, 14.0444, 0.0000, 0.0000, -32.8997, vw, 0, -1, 400.0, 400.0, -1); //wall071
    SetDynamicObjectMaterialText(pFabricaObjeto[id][9], 0, "Cuidado", 90, "System", 25, 1, 0xFF840410, 0x0, 0);
    pFabricaObjeto[id][10] = CreateDynamicObject(19431, 2160.7141, -2241.9357, 14.9644, 0.0000, 0.0000, -32.8997, vw, 0, -1, 400.0, 400.0, -1); //wall071
    SetDynamicObjectMaterialText(pFabricaObjeto[id][10], 0, "Energia", 90, "System", 35, 1, 0xFFFFFFFF, 0x0, 0);
    pFabricaObjeto[id][11] = CreateDynamicObject(19431, 2152.7944, -2245.6745, 15.7742, 0.0000, 0.0000, 58.7000, vw, 0, -1, 400.0, 400.0, -1); //wall071
    SetDynamicObjectMaterialText(pFabricaObjeto[id][11], 0, "Painel", 90, "Impact", 25, 1, 0xFFFFFFFF, 0x0, 0);
    pFabricaObjeto[id][12] = CreateDynamicObject(2567, 2167.6928, -2240.9582, 14.2011, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
    pFabricaObjeto[id][13] = CreateDynamicObject(19431, 2152.8713, -2245.7214, 15.4244, 0.0000, 0.0000, 58.7000, vw, 0, -1, 400.0, 400.0, -1); //wall071
    SetDynamicObjectMaterialText(pFabricaObjeto[id][13], 0, "----------", 90, "Impact", 25, 1, 0xFFFFFFFF, 0x0, 0);
    pFabricaObjeto[id][14] = CreateDynamicObject(19427, 2153.1853, -2245.9318, 16.4855, -0.2000, 0.0000, 58.0998, vw, 0, -1, 400.0, 400.0, -1); //wall067
    SetDynamicObjectMaterial(pFabricaObjeto[id][14], 0, 2188, "kbblackjack", "wheel_o_2b", 0xFFFFFFFF);
    pFabricaObjeto[id][17] = CreateDynamicObject(2567, 2167.6928, -2240.9582, 18.0410, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
    pFabricaObjeto[id][18] = CreateDynamicObject(2567, 2171.4013, -2244.6174, 14.2011, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
    pFabricaObjeto[id][19] = CreateDynamicObject(2567, 2171.4013, -2244.6174, 18.0510, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
    
    switch(pFabrica[id][FabricaTipo])
    {
        // Armas
        case 0:
        {
            pFabricaObjeto[id][20] = CreateDynamicObject(1535, 2119.1035, -2273.5854, 19.5939, 0.0000, 0.0000, -45.2999, vw, 0, -1, 400.0, 400.0, -1); //Gen_doorEXT14
            pFabricaObjeto[id][21] = CreateDynamicObject(19383, 2119.7841, -2274.0168, 21.3271, 0.0000, 0.0000, 44.8997, vw, 0, -1, 400.0, 400.0, -1); //wall031
            SetDynamicObjectMaterial(pFabricaObjeto[id][21], 0, 18065, "ab_sfammumain", "gun_floor1", 0xFFFFFFFF);
            pFabricaObjeto[id][22] = CreateDynamicObject(2664, 2120.3415, -2274.5070, 20.8910, 0.0000, 0.0000, 134.6999, vw, 0, -1, 400.0, 400.0, -1); //CJ_SUBURB_DOOR
            pFabricaObjeto[id][23] = CreateDynamicObject(18092, 2125.6091, -2273.9858, 20.2115, 0.0000, 0.0000, 134.1000, vw, 0, -1, 400.0, 400.0, -1); //ammun3_counter
            pFabricaObjeto[id][24] = CreateDynamicObject(19380, 2122.1152, -2275.3342, 19.6077, 0.0000, 89.7997, 45.2999, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][24], 0, 18065, "ab_sfammumain", "gun_floor2", 0xFFFFFFFF);
            pFabricaObjeto[id][25] = CreateDynamicObject(1491, 2132.1503, -2277.7868, 19.6791, 0.3998, 0.0997, -43.7999, vw, 0, -1, 400.0, 400.0, -1); //Gen_doorINT01
            SetDynamicObjectMaterial(pFabricaObjeto[id][25], 0, 18049, "ammu_twofloor", "gun_ceiling2", 0xFFFFFFFF);
            pFabricaObjeto[id][26] = CreateDynamicObject(19427, 2121.4875, -2275.7124, 21.3271, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][26], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][27] = CreateDynamicObject(19380, 2131.9802, -2284.6779, 24.9332, 0.0000, 0.0000, 135.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][27], 0, 18065, "ab_sfammumain", "gun_floor1", 0xFFFFFFFF);
            pFabricaObjeto[id][28] = CreateDynamicObject(19380, 2125.4870, -2279.6582, 24.9332, 0.0000, 0.0000, 45.2999, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][28], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][29] = CreateDynamicObject(19380, 2127.7875, -2281.9370, 24.9332, 0.0000, 0.0000, 45.2999, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][29], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][30] = CreateDynamicObject(937, 2146.9045, -2265.5725, 12.7749, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP
            pFabricaObjeto[id][31] = CreateDynamicObject(3785, 2161.7998, -2240.2995, 13.9582, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][32] = CreateDynamicObject(3785, 2164.2319, -2237.5402, 13.9582, 0.0000, 0.0000, -177.7996, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][33] = CreateDynamicObject(2115, 2162.3928, -2236.7568, 12.3584, 0.0000, 0.0000, 3.5000, vw, 0, -1, 400.0, 400.0, -1); //LOW_DINNING_1
            pFabricaObjeto[id][34] = CreateDynamicObject(2399, 2162.9357, -2236.8422, 13.6632, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //CJ_4_S_SWEATER_2
            pFabricaObjeto[id][35] = CreateDynamicObject(2669, 2163.0073, -2238.7905, 13.5888, 0.0000, 0.0000, 3.6998, vw, 0, -1, 400.0, 400.0, -1); //CJ_CHRIS_CRATE
            pFabricaObjeto[id][36] = CreateDynamicObject(2196, 2162.5791, -2236.5764, 13.1552, 0.0000, 0.0000, -57.4999, vw, 0, -1, 400.0, 400.0, -1); //WORK_LAMP1
            pFabricaObjeto[id][37] = CreateDynamicObject(16301, 2169.2072, -2256.8745, 12.4306, 0.0000, 15.6000, 44.1999, vw, 0, -1, 400.0, 400.0, -1); //des_quarrybelt13
            SetDynamicObjectMaterial(pFabricaObjeto[id][37], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][38] = CreateDynamicObject(1344, 2136.7197, -2253.4926, 13.0993, 0.0000, 0.0000, 46.6999, vw, 0, -1, 400.0, 400.0, -1); //CJ_Dumpster2
            pFabricaObjeto[id][39] = CreateDynamicObject(1344, 2135.0126, -2255.3046, 13.0993, 0.0000, 0.0000, 46.6999, vw, 0, -1, 400.0, 400.0, -1); //CJ_Dumpster2
            pFabricaObjeto[id][40] = CreateDynamicObject(937, 2148.8195, -2267.4768, 12.7749, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP
            pFabricaObjeto[id][41] = CreateDynamicObject(937, 2150.8547, -2269.5014, 12.7749, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP
            pFabricaObjeto[id][42] = CreateDynamicObject(941, 2161.9594, -2261.7885, 12.7600, 0.0000, 0.0000, 44.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP_3
            pFabricaObjeto[id][43] = CreateDynamicObject(941, 2167.5781, -2256.3222, 12.7600, 0.0000, 0.0000, 44.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP_3
            pFabricaObjeto[id][44] = CreateDynamicObject(19431, 2136.4992, -2252.7158, 13.3542, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //wall071
            SetDynamicObjectMaterialText(pFabricaObjeto[id][44], 0, "Lixos", 90, "Arial", 25, 1, 0xFFFFFFFF, 0x0, 0);
            pFabricaObjeto[id][45] = CreateDynamicObject(19898, 2159.2263, -2254.3933, 12.3044, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
            pFabricaObjeto[id][46] = CreateDynamicObject(1348, 2159.1726, -2254.2360, 12.9687, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //CJ_O2Tanks
            pFabricaObjeto[id][47] = CreateDynamicObject(19383, 2132.6286, -2278.4038, 21.3159, 0.0000, 0.0000, 45.0998, vw, 0, -1, 400.0, 400.0, -1); //wall031
            SetDynamicObjectMaterial(pFabricaObjeto[id][47], 0, 18065, "ab_sfammumain", "gun_floor1", 0xFFFFFFFF);
            pFabricaObjeto[id][48] = CreateDynamicObject(19427, 2120.8188, -2275.0397, 23.8722, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][48], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][49] = CreateDynamicObject(2509, 2132.0134, -2284.4594, 21.7010, 0.0000, 0.0000, -135.1000, vw, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_6
            pFabricaObjeto[id][50] = CreateDynamicObject(19427, 2119.4270, -2273.6450, 23.8722, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][50], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][51] = CreateDynamicObject(19380, 2128.1157, -2273.8818, 24.9332, 0.0000, 0.0000, 45.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][51], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][52] = CreateDynamicObject(19427, 2118.0913, -2272.3068, 21.3288, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][52], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][53] = CreateDynamicObject(19380, 2125.8474, -2271.6135, 24.9332, 0.0000, 0.0000, 45.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][53], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][54] = CreateDynamicObject(2368, 2134.7390, -2283.9248, 19.7709, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //Shop_counter_1
            pFabricaObjeto[id][55] = CreateDynamicObject(19427, 2132.7268, -2278.5200, 23.8421, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][55], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][56] = CreateDynamicObject(2567, 2127.8930, -2276.4130, 13.7209, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][57] = CreateDynamicObject(19427, 2134.8137, -2280.5979, 21.3404, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][57], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][58] = CreateDynamicObject(19427, 2134.1618, -2279.9572, 23.8722, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][58], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][59] = CreateDynamicObject(19427, 2134.3264, -2280.1093, 21.3393, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][59], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
            pFabricaObjeto[id][60] = CreateDynamicObject(2509, 2133.2170, -2283.2590, 21.7010, 0.0000, 0.0000, -135.1000, vw, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_6
            pFabricaObjeto[id][61] = CreateDynamicObject(2509, 2134.4489, -2282.0295, 21.7010, 0.0000, 0.0000, -135.1000, vw, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_6
            pFabricaObjeto[id][62] = CreateDynamicObject(355, 2119.7395, -2271.0671, 21.3328, 167.5000, 172.6999, 52.3998, vw, 0, -1, 400.0, 400.0, -1); //ak47
            pFabricaObjeto[id][63] = CreateDynamicObject(19380, 2128.9453, -2282.0910, 19.6077, 0.0000, 89.7997, 45.2999, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][63], 0, 18065, "ab_sfammumain", "gun_floor2", 0xFFFFFFFF);
            pFabricaObjeto[id][64] = CreateDynamicObject(2051, 2123.2651, -2269.2084, 21.2033, 0.0000, 0.0000, -45.2999, vw, 0, -1, 400.0, 400.0, -1); //CJ_TARGET4
            pFabricaObjeto[id][65] = CreateDynamicObject(2050, 2123.8073, -2269.7707, 22.2261, 0.0000, 0.0000, -43.0000, vw, 0, -1, 400.0, 400.0, -1); //CJ_TARGET2
            pFabricaObjeto[id][66] = CreateDynamicObject(2049, 2124.3266, -2270.2866, 21.1937, 0.0000, 0.0000, -44.0998, vw, 0, -1, 400.0, 400.0, -1); //CJ_TARGET1
            pFabricaObjeto[id][67] = CreateDynamicObject(2475, 2119.4562, -2271.4052, 19.7299, -0.9998, 0.0000, 46.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_3
            pFabricaObjeto[id][68] = CreateDynamicObject(2475, 2121.1437, -2269.6794, 19.7255, 0.0000, 0.0000, 46.5999, vw, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_3
            pFabricaObjeto[id][69] = CreateDynamicObject(2690, 2120.4855, -2270.3146, 20.9738, 0.0000, 0.0000, 44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_FIRE_EXT
            pFabricaObjeto[id][70] = CreateDynamicObject(2369, 2125.7644, -2274.0969, 20.7133, 0.0000, 0.0000, -46.2999, vw, 0, -1, 400.0, 400.0, -1); //CJ_Till
            pFabricaObjeto[id][71] = CreateDynamicObject(2614, 2120.4169, -2270.3000, 22.7099, 0.0000, 0.0000, 44.8998, vw, 0, -1, 400.0, 400.0, -1); //CJ_US_FLAG
            pFabricaObjeto[id][72] = CreateDynamicObject(2041, 2121.7028, -2269.3232, 20.7378, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //AMMO_BOX_M2
            pFabricaObjeto[id][73] = CreateDynamicObject(2041, 2121.1613, -2269.8720, 20.7301, 0.0000, 0.0000, -43.4000, vw, 0, -1, 400.0, 400.0, -1); //AMMO_BOX_M2
            pFabricaObjeto[id][74] = CreateDynamicObject(1654, 2119.3806, -2271.7377, 20.7486, 0.0000, 0.0000, 54.9999, vw, 0, -1, 400.0, 400.0, -1); //dynamite
            pFabricaObjeto[id][75] = CreateDynamicObject(1654, 2119.5319, -2271.5861, 20.7486, 0.0000, 0.0000, 54.9999, vw, 0, -1, 400.0, 400.0, -1); //dynamite
            pFabricaObjeto[id][76] = CreateDynamicObject(1886, 2134.6374, -2281.0590, 23.9848, 19.1000, 0.0000, -105.9999, vw, 0, -1, 400.0, 400.0, -1); //shop_sec_cam
            pFabricaObjeto[id][77] = CreateDynamicObject(8674, 2165.6264, -2260.5478, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][78] = CreateDynamicObject(8674, 2172.8774, -2253.2480, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][79] = CreateDynamicObject(8674, 2180.1276, -2245.9455, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][80] = CreateDynamicObject(8674, 2155.4648, -2270.6645, 21.0452, 0.0000, 0.0000, 44.9999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][81] = CreateDynamicObject(8674, 2148.2075, -2277.9589, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][82] = CreateDynamicObject(8674, 2146.5507, -2279.6103, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][83] = CreateDynamicObject(8674, 2158.3283, -2260.6059, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][84] = CreateDynamicObject(8674, 2151.0275, -2253.3557, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][85] = CreateDynamicObject(8674, 2143.7258, -2246.1052, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][86] = CreateDynamicObject(8674, 2147.4333, -2255.2707, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][87] = CreateDynamicObject(8674, 2155.5270, -2263.3967, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][88] = CreateDynamicObject(8674, 2151.9033, -2259.7949, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][89] = CreateDynamicObject(1654, 2119.6896, -2271.4274, 20.7486, 0.0000, 0.0000, 54.9999, vw, 0, -1, 400.0, 400.0, -1); //dynamite
            pFabricaObjeto[id][90] = CreateDynamicObject(1886, 2119.0708, -2272.5830, 23.8673, 21.2999, 0.0000, 73.5000, vw, 0, -1, 400.0, 400.0, -1); //shop_sec_cam
            pFabricaObjeto[id][91] = CreateDynamicObject(1654, 2119.8330, -2271.2705, 20.7486, 0.0000, 0.0000, 54.9999, vw, 0, -1, 400.0, 400.0, -1); //dynamite
            pFabricaObjeto[id][92] = CreateDynamicObject(1654, 2119.9738, -2271.0998, 20.7387, 0.0000, 0.0000, 54.9999, vw, 0, -1, 400.0, 400.0, -1); //dynamite
            pFabricaObjeto[id][93] = CreateDynamicObject(2985, 2123.0942, -2270.6716, 19.6105, 0.0000, 0.0000, -150.0999, vw, 0, -1, 400.0, 400.0, -1); //minigun_base
            pFabricaObjeto[id][94] = CreateDynamicObject(1654, 2120.1455, -2270.9379, 20.7486, 0.0000, 0.0000, 54.9999, vw, 0, -1, 400.0, 400.0, -1); //dynamite
            pFabricaObjeto[id][95] = CreateDynamicObject(2567, 2162.7314, -2267.7644, 21.3136, 0.0000, 0.0000, 46.0998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][96] = CreateDynamicObject(363, 2119.2651, -2271.7944, 20.1658, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //satchel
            pFabricaObjeto[id][97] = CreateDynamicObject(363, 2119.4553, -2271.6042, 20.1658, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //satchel
            pFabricaObjeto[id][98] = CreateDynamicObject(2567, 2140.4619, -2290.0783, 21.2749, 0.0000, 0.0000, 44.5000, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][99] = CreateDynamicObject(939, 2132.3925, -2258.5336, 22.0415, 0.0000, 0.0000, 45.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_UNIT
            pFabricaObjeto[id][100] = CreateDynamicObject(939, 2136.1318, -2254.7770, 22.0415, 0.0000, 0.0000, -133.5997, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_UNIT
            pFabricaObjeto[id][101] = CreateDynamicObject(1421, 2136.7775, -2290.4858, 20.4085, 0.0000, 0.0000, -76.6997, vw, 0, -1, 400.0, 400.0, -1); //DYN_BOXES
            pFabricaObjeto[id][102] = CreateDynamicObject(1624, 2139.6442, -2249.3793, 21.2462, 0.0000, 0.0000, 133.8000, vw, 0, -1, 400.0, 400.0, -1); //nt_cablebox1_01
            pFabricaObjeto[id][103] = CreateDynamicObject(1625, 2140.2504, -2248.5224, 21.2385, 0.0000, 0.0000, 134.7998, vw, 0, -1, 400.0, 400.0, -1); //nt_cablebox2_01
            pFabricaObjeto[id][104] = CreateDynamicObject(2991, 2149.8972, -2253.6960, 20.2751, 0.0000, 0.0000, -44.4999, vw, 0, -1, 400.0, 400.0, -1); //imy_bbox
            pFabricaObjeto[id][105] = CreateDynamicObject(2991, 2149.8972, -2253.6960, 21.5352, 0.0000, 0.0000, -44.4999, vw, 0, -1, 400.0, 400.0, -1); //imy_bbox
            pFabricaObjeto[id][106] = CreateDynamicObject(1421, 2128.7436, -2265.7385, 20.4085, 0.0000, 0.0000, -135.5000, vw, 0, -1, 400.0, 400.0, -1); //DYN_BOXES
            pFabricaObjeto[id][107] = CreateDynamicObject(1271, 2138.0092, -2288.4064, 20.0135, 0.0000, 0.0000, -44.9000, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][108] = CreateDynamicObject(19898, 2173.1882, -2255.6081, 19.6833, 0.0000, 0.0000, -97.7997, vw, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
            pFabricaObjeto[id][109] = CreateDynamicObject(19898, 2154.2094, -2259.1755, 19.6833, 0.0000, 0.0000, 20.6000, vw, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
            pFabricaObjeto[id][110] = CreateDynamicObject(1271, 2138.5898, -2288.8425, 20.0387, 0.0000, 0.0000, -41.6999, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][111] = CreateDynamicObject(1271, 2138.8266, -2288.0605, 20.0356, 0.0000, 0.0000, 49.3997, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][112] = CreateDynamicObject(1271, 2138.3754, -2288.4655, 20.6877, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][113] = CreateDynamicObject(2886, 2131.7214, -2277.6843, 21.1695, 0.0000, 0.0000, -45.2000, vw, 0, -1, 400.0, 400.0, -1); //sec_keypad
            pFabricaObjeto[id][114] = CreateDynamicObject(1271, 2142.6682, -2256.9213, 13.7839, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][115] = CreateDynamicObject(2567, 2127.8930, -2276.4130, 17.3111, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][116] = CreateDynamicObject(939, 2139.0939, -2288.7783, 16.1539, 0.0000, 0.0000, 0.4000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_UNIT
            pFabricaObjeto[id][117] = CreateDynamicObject(2567, 2123.9562, -2272.5292, 13.7209, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][118] = CreateDynamicObject(2567, 2123.9562, -2272.5292, 17.3411, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][119] = CreateDynamicObject(363, 2119.6254, -2271.3940, 20.1658, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //satchel
            pFabricaObjeto[id][120] = CreateDynamicObject(2468, 2121.8383, -2269.1584, 19.8446, 0.0000, 0.0000, -44.0998, vw, 0, -1, 400.0, 400.0, -1); //MODEL_BOX4
            pFabricaObjeto[id][121] = CreateDynamicObject(363, 2119.8056, -2271.1838, 20.1658, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //satchel
            pFabricaObjeto[id][122] = CreateDynamicObject(363, 2120.0178, -2270.9736, 20.1658, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //satchel
            pFabricaObjeto[id][123] = CreateDynamicObject(2468, 2121.3486, -2269.6696, 19.8397, 0.0000, 0.0000, -43.5998, vw, 0, -1, 400.0, 400.0, -1); //MODEL_BOX4
            pFabricaObjeto[id][124] = CreateDynamicObject(358, 2134.2687, -2282.1914, 22.0323, 0.4999, 4.5000, 49.3998, vw, 0, -1, 400.0, 400.0, -1); //sniper
            pFabricaObjeto[id][125] = CreateDynamicObject(356, 2134.2956, -2282.1821, 22.4183, 0.0000, 0.0000, 49.9000, vw, 0, -1, 400.0, 400.0, -1); //m4
            pFabricaObjeto[id][126] = CreateDynamicObject(362, 2121.9387, -2269.3085, 21.6142, -29.0000, 37.7999, -137.8999, vw, 0, -1, 400.0, 400.0, -1); //minigun
            pFabricaObjeto[id][127] = CreateDynamicObject(2059, 2124.1210, -2272.3757, 20.7297, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //CJ_GUNSTUFF1
            pFabricaObjeto[id][128] = CreateDynamicObject(353, 2134.3088, -2282.1647, 21.6501, 0.0000, 0.0000, 54.4000, vw, 0, -1, 400.0, 400.0, -1); //mp5lng
            pFabricaObjeto[id][129] = CreateDynamicObject(349, 2134.2687, -2282.2243, 21.2791, 0.0000, 0.0000, 53.0000, vw, 0, -1, 400.0, 400.0, -1); //chromegun
            pFabricaObjeto[id][130] = CreateDynamicObject(356, 2133.0373, -2283.3967, 20.9983, 0.0000, 0.0000, 49.9000, vw, 0, -1, 400.0, 400.0, -1); //m4
            pFabricaObjeto[id][131] = CreateDynamicObject(351, 2134.1569, -2282.2998, 20.8967, 0.0000, 0.0000, 52.2999, vw, 0, -1, 400.0, 400.0, -1); //shotgspa
            pFabricaObjeto[id][132] = CreateDynamicObject(358, 2133.0437, -2283.4128, 21.3768, 0.4999, 4.5000, 49.3998, vw, 0, -1, 400.0, 400.0, -1); //sniper
            pFabricaObjeto[id][133] = CreateDynamicObject(2058, 2126.9091, -2275.4304, 20.7238, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //CJ_Gun_docs
            pFabricaObjeto[id][134] = CreateDynamicObject(351, 2132.9550, -2283.4790, 21.7467, 0.0000, 0.0000, 52.2999, vw, 0, -1, 400.0, 400.0, -1); //shotgspa
            pFabricaObjeto[id][135] = CreateDynamicObject(357, 2133.0490, -2283.4384, 22.1793, 0.0000, 0.0000, 52.4000, vw, 0, -1, 400.0, 400.0, -1); //cuntgun
            pFabricaObjeto[id][136] = CreateDynamicObject(360, 2132.2231, -2284.2324, 21.7754, 0.0000, -89.1999, 46.4999, vw, 0, -1, 400.0, 400.0, -1); //heatseek
            pFabricaObjeto[id][137] = CreateDynamicObject(1744, 2133.6723, -2283.0668, 20.1266, 0.0000, 0.0000, -135.0001, vw, 0, -1, 400.0, 400.0, -1); //MED_SHELF
            pFabricaObjeto[id][138] = CreateDynamicObject(2596, 2124.8046, -2271.1291, 23.0902, 0.0000, 0.0000, -44.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_SEX_TV
            pFabricaObjeto[id][139] = CreateDynamicObject(359, 2131.9331, -2284.5493, 21.7567, 0.0000, -88.9000, 47.7999, vw, 0, -1, 400.0, 400.0, -1); //rocketla
            pFabricaObjeto[id][140] = CreateDynamicObject(2700, 2128.3347, -2274.6096, 23.1224, 0.0000, 0.0000, -137.8000, vw, 0, -1, 400.0, 400.0, -1); //CJ_SEX_TV2
            pFabricaObjeto[id][141] = CreateDynamicObject(347, 2132.6174, -2283.5000, 20.4361, 86.0000, -24.7999, 42.5998, vw, 0, -1, 400.0, 400.0, -1); //silenced
            pFabricaObjeto[id][142] = CreateDynamicObject(2061, 2124.1513, -2273.0063, 20.9842, 0.0000, 0.0000, 50.3999, vw, 0, -1, 400.0, 400.0, -1); //CJ_SHELLS1
            pFabricaObjeto[id][143] = CreateDynamicObject(2700, 2131.3400, -2284.7639, 23.3145, 0.0000, 0.0000, 89.6998, vw, 0, -1, 400.0, 400.0, -1); //CJ_SEX_TV2
            pFabricaObjeto[id][144] = CreateDynamicObject(372, 2133.2082, -2283.0732, 20.4694, 93.3000, 0.0000, 45.4999, vw, 0, -1, 400.0, 400.0, -1); //tec9
            pFabricaObjeto[id][145] = CreateDynamicObject(2061, 2124.0466, -2272.9233, 20.9954, 0.0000, 0.0000, 48.6000, vw, 0, -1, 400.0, 400.0, -1); //CJ_SHELLS1
            pFabricaObjeto[id][146] = CreateDynamicObject(2048, 2130.1005, -2276.0942, 22.1101, 0.0000, 0.0000, -47.3000, vw, 0, -1, 400.0, 400.0, -1); //CJ_FLAG2
            pFabricaObjeto[id][147] = CreateDynamicObject(1744, 2129.9741, -2275.6394, 20.5268, 0.0000, 0.0000, -44.8999, vw, 0, -1, 400.0, 400.0, -1); //MED_SHELF
            pFabricaObjeto[id][148] = CreateDynamicObject(1586, 2129.7009, -2283.6574, 20.8841, 0.0000, 0.0000, -43.2999, vw, 0, -1, 400.0, 400.0, -1); //tar_civ1
            pFabricaObjeto[id][149] = CreateDynamicObject(1586, 2122.3015, -2276.3115, 20.8871, 0.0000, 0.0000, -45.1999, vw, 0, -1, 400.0, 400.0, -1); //tar_civ1
            pFabricaObjeto[id][150] = CreateDynamicObject(1977, 2126.3173, -2279.5871, 19.7002, 0.0000, 0.0000, 133.6999, vw, 0, -1, 400.0, 400.0, -1); //vendin3
            pFabricaObjeto[id][151] = CreateDynamicObject(1654, 2129.5109, -2275.6811, 21.0690, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //dynamite
            pFabricaObjeto[id][152] = CreateDynamicObject(1654, 2130.6582, -2276.7958, 21.0563, 0.0000, 0.0000, -84.2999, vw, 0, -1, 400.0, 400.0, -1); //dynamite
            pFabricaObjeto[id][153] = CreateDynamicObject(2690, 2124.5261, -2278.4858, 21.5138, 0.0000, 0.0000, 140.2001, vw, 0, -1, 400.0, 400.0, -1); //CJ_FIRE_EXT
            pFabricaObjeto[id][154] = CreateDynamicObject(363, 2130.3559, -2276.5070, 21.1865, 0.0000, 0.0000, -42.5999, vw, 0, -1, 400.0, 400.0, -1); //satchel
            pFabricaObjeto[id][155] = CreateDynamicObject(2690, 2127.4169, -2281.2719, 21.5138, 0.0000, 0.0000, 140.2001, vw, 0, -1, 400.0, 400.0, -1); //CJ_FIRE_EXT
            pFabricaObjeto[id][156] = CreateDynamicObject(363, 2129.5676, -2275.7163, 21.1687, 0.0000, 0.0000, -42.4999, vw, 0, -1, 400.0, 400.0, -1); //satchel
            pFabricaObjeto[id][157] = CreateDynamicObject(363, 2129.9616, -2276.0969, 21.1636, 0.0000, 0.0000, -43.6999, vw, 0, -1, 400.0, 400.0, -1); //satchel
            pFabricaObjeto[id][158] = CreateDynamicObject(2010, 2131.2453, -2284.7775, 19.6613, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //nu_plant3_ofc
            pFabricaObjeto[id][159] = CreateDynamicObject(2010, 2134.8752, -2281.2456, 19.6613, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //nu_plant3_ofc
            pFabricaObjeto[id][160] = CreateDynamicObject(2985, 2129.0551, -2278.4956, 19.6105, 0.0000, 0.0000, -75.4999, vw, 0, -1, 400.0, 400.0, -1); //minigun_base
            pFabricaObjeto[id][161] = CreateDynamicObject(19380, 2118.9172, -2271.6149, 24.9332, 0.0000, 0.0000, 135.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][161], 0, 18065, "ab_sfammumain", "gun_floor1", 0xFFFFFFFF);

            pFabricaBot[id][0] = CreateDynamicActor(73, 2126.0020,-2273.5654,20.7076,134.7395, 1, 100.0, vw, 0, -1, 200.0, -1, 0);
        
        }

        // Roupas
        case 1:
        {
            pFabricaObjeto[id][20] = CreateDynamicObject(1535, 2119.1035, -2273.5854, 19.5939, 0.0000, 0.0000, -45.2999, vw, 0, -1, 400.0, 400.0, -1); //Gen_doorEXT14
            pFabricaObjeto[id][21] = CreateDynamicObject(2626, 2125.8125, -2274.6040, 20.1435, -0.5999, 0.0000, -44.3999, vw, 0, -1, 400.0, 400.0, -1); //CJ_URB_COUNTER
            pFabricaObjeto[id][22] = CreateDynamicObject(2414, 2126.9309, -2275.6142, 19.6137, 0.0000, 0.0000, -44.2999, vw, 0, -1, 400.0, 400.0, -1); //Shop_counter_3b
            pFabricaObjeto[id][23] = CreateDynamicObject(19436, 2127.6767, -2275.8784, 18.9129, 0.0000, 0.0000, 45.5999, vw, 0, -1, 400.0, 400.0, -1); //wall076
            SetDynamicObjectMaterial(pFabricaObjeto[id][23], 0, 14652, "ab_trukstpa", "mp_diner_wood", 0xFFFFFFFF);
            pFabricaObjeto[id][24] = CreateDynamicObject(2626, 2128.6784, -2277.4082, 20.1435, -0.0999, 0.0000, -44.3999, vw, 0, -1, 400.0, 400.0, -1); //CJ_URB_COUNTER
            pFabricaObjeto[id][25] = CreateDynamicObject(1491, 2132.1503, -2277.7868, 19.6792, 0.3998, 0.0999, -43.7999, vw, 0, -1, 400.0, 400.0, -1); //Gen_doorINT01
            SetDynamicObjectMaterial(pFabricaObjeto[id][25], 0, 2732, "cj_zip_sign", "CJ_ZIP_1", 0xFFFFFFFF);
            pFabricaObjeto[id][26] = CreateDynamicObject(19436, 2127.3906, -2275.5979, 18.9129, 0.0000, 0.0000, 45.5999, vw, 0, -1, 400.0, 400.0, -1); //wall076
            SetDynamicObjectMaterial(pFabricaObjeto[id][26], 0, 14652, "ab_trukstpa", "mp_diner_wood", 0xFFFFFFFF);
            pFabricaObjeto[id][27] = CreateDynamicObject(2414, 2124.0673, -2272.8205, 19.6137, 0.0000, 0.0000, -44.2999, vw, 0, -1, 400.0, 400.0, -1); //Shop_counter_3b
            pFabricaObjeto[id][28] = CreateDynamicObject(19436, 2124.8161, -2273.0815, 18.9129, 0.0000, 0.0000, 45.5999, vw, 0, -1, 400.0, 400.0, -1); //wall076
            SetDynamicObjectMaterial(pFabricaObjeto[id][28], 0, 14652, "ab_trukstpa", "mp_diner_wood", 0xFFFFFFFF);
            pFabricaObjeto[id][29] = CreateDynamicObject(19436, 2124.5312, -2272.8000, 18.9129, 0.0000, 0.0000, 45.5999, vw, 0, -1, 400.0, 400.0, -1); //wall076
            SetDynamicObjectMaterial(pFabricaObjeto[id][29], 0, 14652, "ab_trukstpa", "mp_diner_wood", 0xFFFFFFFF);
            pFabricaObjeto[id][30] = CreateDynamicObject(2414, 2124.5134, -2271.1071, 19.6137, 0.0000, 0.0000, -134.6999, vw, 0, -1, 400.0, 400.0, -1); //Shop_counter_3b
            pFabricaObjeto[id][31] = CreateDynamicObject(937, 2146.9045, -2265.5725, 12.7749, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP
            pFabricaObjeto[id][32] = CreateDynamicObject(3785, 2161.7998, -2240.2995, 13.9584, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][33] = CreateDynamicObject(3785, 2164.2319, -2237.5402, 13.9584, 0.0000, 0.0000, -177.7996, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][34] = CreateDynamicObject(2115, 2162.3928, -2236.7568, 12.3585, 0.0000, 0.0000, 3.5000, vw, 0, -1, 400.0, 400.0, -1); //LOW_DINNING_1
            pFabricaObjeto[id][35] = CreateDynamicObject(2399, 2162.9357, -2236.8422, 13.6633, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //CJ_4_S_SWEATER_2
            pFabricaObjeto[id][36] = CreateDynamicObject(2669, 2163.0073, -2238.7905, 13.5888, 0.0000, 0.0000, 3.6998, vw, 0, -1, 400.0, 400.0, -1); //CJ_CHRIS_CRATE
            pFabricaObjeto[id][37] = CreateDynamicObject(2196, 2162.5791, -2236.5764, 13.1552, 0.0000, 0.0000, -57.4999, vw, 0, -1, 400.0, 400.0, -1); //WORK_LAMP1
            pFabricaObjeto[id][38] = CreateDynamicObject(16301, 2169.2072, -2256.8745, 12.4306, 0.0000, 15.6000, 44.1999, vw, 0, -1, 400.0, 400.0, -1); //des_quarrybelt13
            SetDynamicObjectMaterial(pFabricaObjeto[id][38], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][39] = CreateDynamicObject(1344, 2136.7197, -2253.4926, 13.0994, 0.0000, 0.0000, 46.6999, vw, 0, -1, 400.0, 400.0, -1); //CJ_Dumpster2
            pFabricaObjeto[id][40] = CreateDynamicObject(1344, 2135.0126, -2255.3046, 13.0994, 0.0000, 0.0000, 46.6999, vw, 0, -1, 400.0, 400.0, -1); //CJ_Dumpster2
            pFabricaObjeto[id][41] = CreateDynamicObject(937, 2148.8195, -2267.4768, 12.7749, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP
            pFabricaObjeto[id][42] = CreateDynamicObject(937, 2150.8547, -2269.5014, 12.7749, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP
            pFabricaObjeto[id][43] = CreateDynamicObject(941, 2161.9594, -2261.7885, 12.7600, 0.0000, 0.0000, 44.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP_3
            pFabricaObjeto[id][44] = CreateDynamicObject(941, 2167.5781, -2256.3222, 12.7600, 0.0000, 0.0000, 44.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP_3
            pFabricaObjeto[id][45] = CreateDynamicObject(19431, 2140.4934, -2248.7351, 14.7243, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //wall071
            SetDynamicObjectMaterialText(pFabricaObjeto[id][45], 0, "Lixos", 90, "Arial", 25, 1, 0xFFFFFFFF, 0x0, 0);
            pFabricaObjeto[id][48] = CreateDynamicObject(19898, 2159.2263, -2254.3933, 12.3044, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
            pFabricaObjeto[id][49] = CreateDynamicObject(1348, 2159.1726, -2254.2360, 12.9687, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //CJ_O2Tanks
            pFabricaObjeto[id][50] = CreateDynamicObject(2400, 2139.6955, -2249.8166, 12.9837, 0.0000, 0.0000, 46.5999, vw, 0, -1, 400.0, 400.0, -1); //CJ_SPORTS_WALL01
            pFabricaObjeto[id][51] = CreateDynamicObject(2383, 2139.7875, -2250.0351, 14.2516, 0.0000, 0.0000, -41.1999, vw, 0, -1, 400.0, 400.0, -1); //CJ_6_SWEATER
            pFabricaObjeto[id][52] = CreateDynamicObject(2389, 2140.1809, -2249.6088, 14.2595, 0.0000, 0.0000, 45.9001, vw, 0, -1, 400.0, 400.0, -1); //CJ_4_SWEATERS
            pFabricaObjeto[id][53] = CreateDynamicObject(2382, 2140.7187, -2249.2724, 13.4798, 6.5998, 0.0000, 46.4999, vw, 0, -1, 400.0, 400.0, -1); //CJ_8_JEANS_Light
            pFabricaObjeto[id][54] = CreateDynamicObject(2374, 2141.0029, -2248.7583, 14.2480, 0.0000, 0.0000, 46.3998, vw, 0, -1, 400.0, 400.0, -1); //CJ_Tshirt
            pFabricaObjeto[id][55] = CreateDynamicObject(2377, 2141.8283, -2247.8896, 13.4008, 0.0000, 0.0000, 47.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_jean_dark
            pFabricaObjeto[id][56] = CreateDynamicObject(2384, 2141.7856, -2247.9594, 15.0191, 0.0000, 0.0000, 46.5998, vw, 0, -1, 400.0, 400.0, -1); //CJ_8_JEANS_DARK
            pFabricaObjeto[id][57] = CreateDynamicObject(2384, 2140.2319, -2249.6003, 15.0191, 0.0000, 0.0000, 46.5998, vw, 0, -1, 400.0, 400.0, -1); //CJ_8_JEANS_DARK
            pFabricaObjeto[id][58] = CreateDynamicObject(19427, 2134.8137, -2280.5979, 21.3406, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][58], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][59] = CreateDynamicObject(19436, 2124.5375, -2271.5659, 18.9129, 0.0000, 0.0000, -44.2000, vw, 0, -1, 400.0, 400.0, -1); //wall076
            SetDynamicObjectMaterial(pFabricaObjeto[id][59], 0, 14652, "ab_trukstpa", "mp_diner_wood", 0xFFFFFFFF);
            pFabricaObjeto[id][60] = CreateDynamicObject(2736, 2126.2519, -2272.2014, 21.7090, 0.0000, 0.0000, -44.8999, vw, 0, -1, 400.0, 400.0, -1); //CJ_ZIP_POST_05
            pFabricaObjeto[id][61] = CreateDynamicObject(2736, 2129.9121, -2275.8666, 21.6780, 0.0000, 0.0000, -44.8999, vw, 0, -1, 400.0, 400.0, -1); //CJ_ZIP_POST_05
            pFabricaObjeto[id][62] = CreateDynamicObject(2875, 2120.2915, -2274.5214, 20.8805, -0.3999, 0.0000, 134.9000, vw, 0, -1, 400.0, 400.0, -1); //CJ_GAP_DOOR_
            pFabricaObjeto[id][63] = CreateDynamicObject(2654, 2123.8642, -2271.4733, 20.8732, 0.0000, 0.0000, -45.6999, vw, 0, -1, 400.0, 400.0, -1); //CJ_shoe_box
            pFabricaObjeto[id][64] = CreateDynamicObject(2846, 2126.3288, -2276.2375, 20.6595, 0.0000, 0.0000, 14.5000, vw, 0, -1, 400.0, 400.0, -1); //gb_bedclothes05
            pFabricaObjeto[id][65] = CreateDynamicObject(2368, 2134.7390, -2283.9248, 19.7709, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //Shop_counter_1
            pFabricaObjeto[id][66] = CreateDynamicObject(19427, 2121.4875, -2275.7124, 21.3273, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][66], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][67] = CreateDynamicObject(2567, 2127.8930, -2276.4130, 13.7211, 0.0000, 0.0000, -44.5999, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][68] = CreateDynamicObject(19383, 2119.7841, -2274.0168, 21.3273, 0.0000, 0.0000, 44.8999, vw, 0, -1, 400.0, 400.0, -1); //wall031
            SetDynamicObjectMaterial(pFabricaObjeto[id][68], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][69] = CreateDynamicObject(19380, 2118.9172, -2271.6149, 24.9332, 0.0000, 0.0000, 135.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][69], 0, 3629, "arprtxxref_las", "dirtywhite", 0xFFFFFFFF);
            pFabricaObjeto[id][70] = CreateDynamicObject(19427, 2118.0913, -2272.3068, 21.3289, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][70], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][71] = CreateDynamicObject(19380, 2127.7875, -2281.9370, 24.9332, 0.0000, 0.0000, 45.3000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][71], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][72] = CreateDynamicObject(19427, 2119.4270, -2273.6450, 23.8722, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][72], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][73] = CreateDynamicObject(19427, 2120.8188, -2275.0397, 23.8722, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][73], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][74] = CreateDynamicObject(19380, 2125.4870, -2279.6582, 24.9332, 0.0000, 0.0000, 45.3000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][74], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][75] = CreateDynamicObject(2625, 2132.9128, -2282.9521, 20.9502, 0.0000, 0.0000, -135.3001, vw, 0, -1, 400.0, 400.0, -1); //CJ_SHOE_URBAN2
            pFabricaObjeto[id][76] = CreateDynamicObject(2652, 2134.3989, -2281.1721, 20.1800, 0.0000, 0.0000, 13.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_SKATE_CUBES
            pFabricaObjeto[id][77] = CreateDynamicObject(19427, 2132.7268, -2278.5200, 23.8422, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][77], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][78] = CreateDynamicObject(19380, 2128.6655, -2281.8217, 19.6177, 0.0000, 89.7999, 45.3000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][78], 0, 14786, "ab_sfgymbeams", "knot_wood128", 0xFFFFFFFF);
            pFabricaObjeto[id][79] = CreateDynamicObject(19380, 2128.1157, -2273.8818, 24.9332, 0.0000, 0.0000, 45.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][79], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][80] = CreateDynamicObject(2652, 2131.0498, -2284.4711, 20.2128, 0.0000, 0.0000, -127.2999, vw, 0, -1, 400.0, 400.0, -1); //CJ_SKATE_CUBES
            pFabricaObjeto[id][81] = CreateDynamicObject(19427, 2134.3264, -2280.1093, 21.3394, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][81], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][82] = CreateDynamicObject(19383, 2132.6286, -2278.4038, 21.3160, 0.0000, 0.0000, 45.1000, vw, 0, -1, 400.0, 400.0, -1); //wall031
            SetDynamicObjectMaterial(pFabricaObjeto[id][82], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][83] = CreateDynamicObject(19427, 2134.1618, -2279.9572, 23.8722, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][83], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][84] = CreateDynamicObject(19380, 2131.9802, -2284.6779, 24.9332, 0.0000, 0.0000, 135.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][84], 0, 3629, "arprtxxref_las", "dirtywhite", 0xFFFFFFFF);
            pFabricaObjeto[id][85] = CreateDynamicObject(19380, 2125.8474, -2271.6135, 24.9332, 0.0000, 0.0000, 45.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][85], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][86] = CreateDynamicObject(19380, 2122.1152, -2275.3342, 19.6077, 0.0000, 89.7999, 45.3000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][86], 0, 14786, "ab_sfgymbeams", "knot_wood128", 0xFFFFFFFF);
            pFabricaObjeto[id][87] = CreateDynamicObject(1886, 2134.6374, -2281.0590, 23.9849, 19.1000, 0.0000, -105.9999, vw, 0, -1, 400.0, 400.0, -1); //shop_sec_cam
            pFabricaObjeto[id][88] = CreateDynamicObject(8674, 2165.6264, -2260.5478, 21.0453, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][89] = CreateDynamicObject(8674, 2172.8774, -2253.2480, 21.0453, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][90] = CreateDynamicObject(8674, 2180.1276, -2245.9455, 21.0453, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][91] = CreateDynamicObject(8674, 2155.4648, -2270.6645, 21.0453, 0.0000, 0.0000, 44.9999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][92] = CreateDynamicObject(8674, 2148.2075, -2277.9589, 21.0453, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][93] = CreateDynamicObject(8674, 2146.5507, -2279.6103, 21.0453, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][94] = CreateDynamicObject(8674, 2158.3283, -2260.6059, 21.0453, 0.0000, 0.0000, -44.8000, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][95] = CreateDynamicObject(8674, 2151.0275, -2253.3557, 21.0453, 0.0000, 0.0000, -44.8000, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][96] = CreateDynamicObject(8674, 2143.7258, -2246.1052, 21.0453, 0.0000, 0.0000, -44.8000, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][97] = CreateDynamicObject(8674, 2147.4333, -2255.2707, 21.0453, 0.0000, 0.0000, -44.8000, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][98] = CreateDynamicObject(8674, 2155.5270, -2263.3967, 21.0453, 0.0000, 0.0000, -44.8000, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][99] = CreateDynamicObject(8674, 2151.9033, -2259.7949, 21.0453, 0.0000, 0.0000, -44.8000, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][100] = CreateDynamicObject(2407, 2129.0085, -2277.8774, 21.0163, 0.0000, 0.0000, -71.1999, vw, 0, -1, 400.0, 400.0, -1); //CJ_F_TORSO
            pFabricaObjeto[id][101] = CreateDynamicObject(1886, 2119.0708, -2272.5830, 23.8674, 21.3000, 0.0000, 73.5000, vw, 0, -1, 400.0, 400.0, -1); //shop_sec_cam
            pFabricaObjeto[id][102] = CreateDynamicObject(638, 2120.4501, -2270.6772, 20.3692, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
            pFabricaObjeto[id][103] = CreateDynamicObject(2257, 2120.2819, -2270.4240, 22.1060, 0.0000, 0.0000, 45.8000, vw, 0, -1, 400.0, 400.0, -1); //Frame_Clip_4
            pFabricaObjeto[id][104] = CreateDynamicObject(19786, 2122.2956, -2276.4790, 21.8047, 0.3999, 0.0000, 136.3998, vw, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
            pFabricaObjeto[id][105] = CreateDynamicObject(19786, 2127.5349, -2281.6704, 21.8103, 0.0000, 0.0000, 136.8999, vw, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
            pFabricaObjeto[id][106] = CreateDynamicObject(2567, 2162.7314, -2267.7644, 21.3137, 0.0000, 0.0000, 46.1000, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][107] = CreateDynamicObject(2010, 2123.3393, -2272.4497, 19.7201, 0.0000, 0.0000, 8.4999, vw, 0, -1, 400.0, 400.0, -1); //nu_plant3_ofc
            pFabricaObjeto[id][108] = CreateDynamicObject(640, 2125.1926, -2278.6582, 20.3842, 0.0000, 0.0000, 45.4999, vw, 0, -1, 400.0, 400.0, -1); //kb_planter+bush2
            pFabricaObjeto[id][109] = CreateDynamicObject(2567, 2140.4619, -2290.0783, 21.2749, 0.0000, 0.0000, 44.5000, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][110] = CreateDynamicObject(939, 2132.3925, -2258.5336, 22.0416, 0.0000, 0.0000, 45.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_UNIT
            pFabricaObjeto[id][111] = CreateDynamicObject(939, 2136.1318, -2254.7770, 22.0416, 0.0000, 0.0000, -133.5999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_UNIT
            pFabricaObjeto[id][112] = CreateDynamicObject(1421, 2136.7775, -2290.4858, 20.4086, 0.0000, 0.0000, -76.6999, vw, 0, -1, 400.0, 400.0, -1); //DYN_BOXES
            pFabricaObjeto[id][113] = CreateDynamicObject(1624, 2139.6442, -2249.3793, 21.2462, 0.0000, 0.0000, 133.8000, vw, 0, -1, 400.0, 400.0, -1); //nt_cablebox1_01
            pFabricaObjeto[id][114] = CreateDynamicObject(1625, 2140.2504, -2248.5224, 21.2386, 0.0000, 0.0000, 134.7999, vw, 0, -1, 400.0, 400.0, -1); //nt_cablebox2_01
            pFabricaObjeto[id][115] = CreateDynamicObject(2991, 2149.8972, -2253.6960, 20.2753, 0.0000, 0.0000, -44.4999, vw, 0, -1, 400.0, 400.0, -1); //imy_bbox
            pFabricaObjeto[id][116] = CreateDynamicObject(2991, 2149.8972, -2253.6960, 21.5353, 0.0000, 0.0000, -44.4999, vw, 0, -1, 400.0, 400.0, -1); //imy_bbox
            pFabricaObjeto[id][117] = CreateDynamicObject(1421, 2128.7436, -2265.7385, 20.4086, 0.0000, 0.0000, -135.5000, vw, 0, -1, 400.0, 400.0, -1); //DYN_BOXES
            pFabricaObjeto[id][118] = CreateDynamicObject(1271, 2138.0092, -2288.4064, 20.0136, 0.0000, 0.0000, -44.9000, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][119] = CreateDynamicObject(19898, 2173.1882, -2255.6081, 19.6834, 0.0000, 0.0000, -97.7999, vw, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
            pFabricaObjeto[id][120] = CreateDynamicObject(19898, 2154.2094, -2259.1755, 19.6834, 0.0000, 0.0000, 20.6000, vw, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
            pFabricaObjeto[id][121] = CreateDynamicObject(1271, 2138.5898, -2288.8425, 20.0387, 0.0000, 0.0000, -41.6999, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][122] = CreateDynamicObject(1271, 2138.8266, -2288.0605, 20.0356, 0.0000, 0.0000, 49.3999, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][123] = CreateDynamicObject(1271, 2138.3754, -2288.4655, 20.6878, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][124] = CreateDynamicObject(2886, 2131.7214, -2277.6843, 21.1695, 0.0000, 0.0000, -45.2000, vw, 0, -1, 400.0, 400.0, -1); //sec_keypad
            pFabricaObjeto[id][125] = CreateDynamicObject(1271, 2142.6682, -2256.9213, 13.7839, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][126] = CreateDynamicObject(2567, 2127.8930, -2276.4130, 17.3111, 0.0000, 0.0000, -44.5999, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][127] = CreateDynamicObject(939, 2139.0939, -2288.7783, 16.1539, 0.0000, 0.0000, 0.4000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_UNIT
            pFabricaObjeto[id][128] = CreateDynamicObject(2567, 2123.9562, -2272.5292, 13.7211, 0.0000, 0.0000, -44.5999, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][129] = CreateDynamicObject(2567, 2123.9562, -2272.5292, 17.3411, 0.0000, 0.0000, -44.5999, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf

            pFabricaBot[id][0] = CreateDynamicActor(172, 2125.9719,-2273.6279,20.7073,137.1615, 1, 100.0, vw, 0, -1, 200.0, -1, 0);
            pFabricaBot[id][1] = CreateDynamicActor(171, 2128.8115,-2276.4099,20.7174,134.3821, 1, 100.0, vw, 0, -1, 200.0, -1, 0);
        }

        // Diversos
        case 2:
        {
            pFabricaObjeto[id][20] = CreateDynamicObject(1535, 2119.1035, -2273.5854, 19.5939, 0.0000, 0.0000, -45.2999, vw, 0, -1, 400.0, 400.0, -1); //Gen_doorEXT14
            pFabricaObjeto[id][21] = CreateDynamicObject(19380, 2121.8349, -2275.0637, 19.6177, 0.0000, 89.7997, 45.2999, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][21], 0, 14786, "ab_sfgymbeams", "knot_wood128", 0xFFFFFFFF);
            pFabricaObjeto[id][22] = CreateDynamicObject(1491, 2132.1503, -2277.7868, 19.6791, 0.3998, 0.0997, -43.7999, vw, 0, -1, 400.0, 400.0, -1); //Gen_doorINT01
            SetDynamicObjectMaterial(pFabricaObjeto[id][22], 0, 10023, "bigwhitesfe", "sfe_arch6", 0xFFFFFFFF);
            pFabricaObjeto[id][23] = CreateDynamicObject(19380, 2118.9172, -2271.6149, 24.9332, 0.0000, 0.0000, 135.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][23], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
            pFabricaObjeto[id][24] = CreateDynamicObject(19380, 2131.9802, -2284.6779, 24.9332, 0.0000, 0.0000, 135.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][24], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
            pFabricaObjeto[id][25] = CreateDynamicObject(2877, 2120.2971, -2274.5288, 20.8934, 0.0000, 0.0000, 134.3000, vw, 0, -1, 400.0, 400.0, -1); //CJ_BINCO_DOOR
            pFabricaObjeto[id][26] = CreateDynamicObject(19380, 2125.4870, -2279.6582, 24.9332, 0.0000, 0.0000, 45.2999, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][26], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][27] = CreateDynamicObject(19427, 2121.4875, -2275.7124, 21.3271, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][27], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][28] = CreateDynamicObject(19380, 2127.7875, -2281.9370, 24.9332, 0.0000, 0.0000, 45.2999, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][28], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][29] = CreateDynamicObject(19427, 2120.8188, -2275.0397, 23.8722, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][29], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][30] = CreateDynamicObject(19427, 2118.0913, -2272.3068, 21.3288, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][30], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][31] = CreateDynamicObject(937, 2146.9045, -2265.5725, 12.7749, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP
            pFabricaObjeto[id][32] = CreateDynamicObject(3785, 2161.7998, -2240.2995, 13.9582, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][33] = CreateDynamicObject(3785, 2164.2319, -2237.5402, 13.9582, 0.0000, 0.0000, -177.7996, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][34] = CreateDynamicObject(2115, 2162.3928, -2236.7568, 12.3584, 0.0000, 0.0000, 3.5000, vw, 0, -1, 400.0, 400.0, -1); //LOW_DINNING_1
            pFabricaObjeto[id][35] = CreateDynamicObject(2399, 2162.9357, -2236.8422, 13.6632, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //CJ_4_S_SWEATER_2
            pFabricaObjeto[id][36] = CreateDynamicObject(2669, 2163.0073, -2238.7905, 13.5888, 0.0000, 0.0000, 3.6998, vw, 0, -1, 400.0, 400.0, -1); //CJ_CHRIS_CRATE
            pFabricaObjeto[id][37] = CreateDynamicObject(2196, 2162.5791, -2236.5764, 13.1552, 0.0000, 0.0000, -57.4999, vw, 0, -1, 400.0, 400.0, -1); //WORK_LAMP1
            pFabricaObjeto[id][38] = CreateDynamicObject(16301, 2169.2072, -2256.8745, 12.4306, 0.0000, 15.6000, 44.1999, vw, 0, -1, 400.0, 400.0, -1); //des_quarrybelt13
            SetDynamicObjectMaterial(pFabricaObjeto[id][38], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][39] = CreateDynamicObject(1344, 2136.7197, -2253.4926, 13.0993, 0.0000, 0.0000, 46.6999, vw, 0, -1, 400.0, 400.0, -1); //CJ_Dumpster2
            pFabricaObjeto[id][40] = CreateDynamicObject(1344, 2135.0126, -2255.3046, 13.0993, 0.0000, 0.0000, 46.6999, vw, 0, -1, 400.0, 400.0, -1); //CJ_Dumpster2
            pFabricaObjeto[id][41] = CreateDynamicObject(937, 2148.8195, -2267.4768, 12.7749, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP
            pFabricaObjeto[id][42] = CreateDynamicObject(937, 2150.8547, -2269.5014, 12.7749, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP
            pFabricaObjeto[id][43] = CreateDynamicObject(941, 2161.9594, -2261.7885, 12.7600, 0.0000, 0.0000, 44.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP_3
            pFabricaObjeto[id][44] = CreateDynamicObject(941, 2167.5781, -2256.3222, 12.7600, 0.0000, 0.0000, 44.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_WORKTOP_3
            pFabricaObjeto[id][45] = CreateDynamicObject(19431, 2136.4992, -2252.7158, 13.3542, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //wall071
            SetDynamicObjectMaterialText(pFabricaObjeto[id][45], 0, "Lixos", 90, "Arial", 25, 1, 0xFFFFFFFF, 0x0, 0);
            pFabricaObjeto[id][46] = CreateDynamicObject(19898, 2159.2263, -2254.3933, 12.3044, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
            pFabricaObjeto[id][47] = CreateDynamicObject(1348, 2159.1726, -2254.2360, 12.9687, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //CJ_O2Tanks
            pFabricaObjeto[id][48] = CreateDynamicObject(19172, 2120.4377, -2270.2839, 21.9272, 0.0000, 0.0000, 44.9999, vw, 0, -1, 400.0, 400.0, -1); //SAMPPicture1
            pFabricaObjeto[id][49] = CreateDynamicObject(19427, 2119.4270, -2273.6450, 23.8722, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][49], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][50] = CreateDynamicObject(19380, 2125.8474, -2271.6135, 24.9332, 0.0000, 0.0000, 45.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][50], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][51] = CreateDynamicObject(19380, 2128.1157, -2273.8818, 24.9332, 0.0000, 0.0000, 45.0000, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][51], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][52] = CreateDynamicObject(19427, 2132.7268, -2278.5200, 23.8421, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][52], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][53] = CreateDynamicObject(19427, 2134.3264, -2280.1093, 21.3393, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][53], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][54] = CreateDynamicObject(19427, 2134.1618, -2279.9572, 23.8722, -90.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][54], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][55] = CreateDynamicObject(2368, 2134.7390, -2283.9248, 19.7709, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //Shop_counter_1
            pFabricaObjeto[id][56] = CreateDynamicObject(19427, 2134.8137, -2280.5979, 21.3404, -0.1000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //wall067
            SetDynamicObjectMaterial(pFabricaObjeto[id][56], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][57] = CreateDynamicObject(2567, 2127.8930, -2276.4130, 13.7209, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][58] = CreateDynamicObject(2623, 2132.3413, -2282.3352, 21.3052, 0.0000, 0.0000, -134.4001, vw, 0, -1, 400.0, 400.0, -1); //CJ_PRO_COUNTER
            pFabricaObjeto[id][59] = CreateDynamicObject(19383, 2119.7841, -2274.0168, 21.3271, 0.0000, 0.0000, 44.8997, vw, 0, -1, 400.0, 400.0, -1); //wall031
            SetDynamicObjectMaterial(pFabricaObjeto[id][59], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][60] = CreateDynamicObject(3785, 2121.9428, -2268.8413, 20.8390, 0.0000, 0.0000, -43.3998, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][61] = CreateDynamicObject(1661, 2130.7236, -2280.2617, 23.8423, 0.0000, -0.8999, 44.0000, vw, 0, -1, 400.0, 400.0, -1); //htl_fan_rotate_dy
            pFabricaObjeto[id][62] = CreateDynamicObject(3785, 2119.0478, -2271.7592, 20.8390, 0.0000, 0.0000, -43.3998, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][63] = CreateDynamicObject(1661, 2124.1674, -2273.6882, 23.8400, 0.0000, -0.8999, 76.7998, vw, 0, -1, 400.0, 400.0, -1); //htl_fan_rotate_dy
            pFabricaObjeto[id][64] = CreateDynamicObject(638, 2120.6311, -2270.5058, 20.4020, 0.0000, 0.0000, -45.4000, vw, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
            pFabricaObjeto[id][65] = CreateDynamicObject(2169, 2128.2211, -2276.4846, 19.7126, 0.0000, 0.0000, 135.0000, vw, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
            SetDynamicObjectMaterial(pFabricaObjeto[id][65], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][66] = CreateDynamicObject(2169, 2126.8479, -2275.1113, 19.7126, 0.0000, 0.0000, 135.0000, vw, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
            SetDynamicObjectMaterial(pFabricaObjeto[id][66], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][67] = CreateDynamicObject(2169, 2125.4685, -2273.7319, 19.7126, 0.0000, 0.0000, 135.0000, vw, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
            SetDynamicObjectMaterial(pFabricaObjeto[id][67], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][68] = CreateDynamicObject(19380, 2128.6655, -2281.8217, 19.6177, 0.0000, 89.7997, 45.2999, vw, 0, -1, 400.0, 400.0, -1); //wall028
            SetDynamicObjectMaterial(pFabricaObjeto[id][68], 0, 14786, "ab_sfgymbeams", "knot_wood128", 0xFFFFFFFF);
            pFabricaObjeto[id][69] = CreateDynamicObject(2169, 2124.3432, -2272.3234, 19.7126, 0.0000, 0.0000, 44.9000, vw, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
            SetDynamicObjectMaterial(pFabricaObjeto[id][69], 0, 14803, "bdupsnew", "Bdup2_wallpaperC", 0xFFFFFFFF);
            pFabricaObjeto[id][70] = CreateDynamicObject(19786, 2127.3581, -2281.4738, 21.9160, 0.0000, 0.0000, 135.2998, vw, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
            pFabricaObjeto[id][71] = CreateDynamicObject(19893, 2126.7548, -2275.1049, 20.4988, 0.0000, 0.0000, 144.3000, vw, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
            pFabricaObjeto[id][72] = CreateDynamicObject(19383, 2132.6286, -2278.4038, 21.3159, 0.0000, 0.0000, 45.0998, vw, 0, -1, 400.0, 400.0, -1); //wall031
            SetDynamicObjectMaterial(pFabricaObjeto[id][72], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
            pFabricaObjeto[id][73] = CreateDynamicObject(19893, 2124.4743, -2272.6330, 20.4988, 0.0000, 0.0000, 101.6998, vw, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
            pFabricaObjeto[id][74] = CreateDynamicObject(19328, 2129.3496, -2275.2834, 21.9789, 0.0000, 0.0000, -46.7999, vw, 0, -1, 400.0, 400.0, -1); //7_11_sign03
            SetDynamicObjectMaterial(pFabricaObjeto[id][74], 0, 7088, "casinoshops1", "247sign1", 0xFFFFFFFF);
            pFabricaObjeto[id][75] = CreateDynamicObject(19786, 2122.9321, -2277.0917, 21.9160, 0.0000, 0.0000, 135.2998, vw, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
            pFabricaObjeto[id][76] = CreateDynamicObject(19328, 2126.1936, -2272.1147, 21.9789, 0.0000, 0.0000, -46.7999, vw, 0, -1, 400.0, 400.0, -1); //7_11_sign03
            SetDynamicObjectMaterial(pFabricaObjeto[id][76], 0, 7088, "casinoshops1", "247sign1", 0xFFFFFFFF);
            pFabricaObjeto[id][77] = CreateDynamicObject(1886, 2134.6374, -2281.0590, 23.9848, 19.1000, 0.0000, -105.9999, vw, 0, -1, 400.0, 400.0, -1); //shop_sec_cam
            pFabricaObjeto[id][78] = CreateDynamicObject(8674, 2165.6264, -2260.5478, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][79] = CreateDynamicObject(8674, 2172.8774, -2253.2480, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][80] = CreateDynamicObject(8674, 2180.1276, -2245.9455, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][81] = CreateDynamicObject(8674, 2155.4648, -2270.6645, 21.0452, 0.0000, 0.0000, 44.9999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][82] = CreateDynamicObject(8674, 2148.2075, -2277.9589, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][83] = CreateDynamicObject(8674, 2146.5507, -2279.6103, 21.0452, 0.0000, 0.0000, 45.1999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][84] = CreateDynamicObject(8674, 2158.3283, -2260.6059, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][85] = CreateDynamicObject(8674, 2151.0275, -2253.3557, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][86] = CreateDynamicObject(8674, 2143.7258, -2246.1052, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][87] = CreateDynamicObject(8674, 2147.4333, -2255.2707, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][88] = CreateDynamicObject(8674, 2155.5270, -2263.3967, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][89] = CreateDynamicObject(8674, 2151.9033, -2259.7949, 21.0452, 0.0000, 0.0000, -44.7999, vw, 0, -1, 400.0, 400.0, -1); //csrsfence02_lvs
            pFabricaObjeto[id][90] = CreateDynamicObject(19431, 2127.8884, -2273.6616, 20.2133, 0.0000, 0.0000, 45.0999, vw, 0, -1, 400.0, 400.0, -1); //wall071
            SetDynamicObjectMaterialText(pFabricaObjeto[id][90], 0, "Atendimento", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 0);
            pFabricaObjeto[id][91] = CreateDynamicObject(1886, 2119.0708, -2272.5830, 23.8673, 21.2999, 0.0000, 73.5000, vw, 0, -1, 400.0, 400.0, -1); //shop_sec_cam
            pFabricaObjeto[id][92] = CreateDynamicObject(1716, 2126.2890, -2275.0881, 19.7192, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //kb_slot_stool
            pFabricaObjeto[id][93] = CreateDynamicObject(1716, 2124.6174, -2273.3964, 19.7192, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //kb_slot_stool
            pFabricaObjeto[id][94] = CreateDynamicObject(1808, 2123.6318, -2269.8496, 19.7161, 0.0000, 0.0000, -45.5998, vw, 0, -1, 400.0, 400.0, -1); //CJ_WATERCOOLER2
            pFabricaObjeto[id][95] = CreateDynamicObject(2059, 2128.0571, -2276.3403, 20.5136, 0.0000, 0.0000, -56.5998, vw, 0, -1, 400.0, 400.0, -1); //CJ_GUNSTUFF1
            pFabricaObjeto[id][96] = CreateDynamicObject(2567, 2162.7314, -2267.7644, 21.3136, 0.0000, 0.0000, 46.0998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][97] = CreateDynamicObject(2567, 2140.4619, -2290.0783, 21.2749, 0.0000, 0.0000, 44.5000, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][98] = CreateDynamicObject(939, 2132.3925, -2258.5336, 22.0415, 0.0000, 0.0000, 45.2000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_UNIT
            pFabricaObjeto[id][99] = CreateDynamicObject(939, 2136.1318, -2254.7770, 22.0415, 0.0000, 0.0000, -133.5997, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_UNIT
            pFabricaObjeto[id][100] = CreateDynamicObject(1421, 2136.7775, -2290.4858, 20.4085, 0.0000, 0.0000, -76.6997, vw, 0, -1, 400.0, 400.0, -1); //DYN_BOXES
            pFabricaObjeto[id][101] = CreateDynamicObject(1624, 2139.6442, -2249.3793, 21.2462, 0.0000, 0.0000, 133.8000, vw, 0, -1, 400.0, 400.0, -1); //nt_cablebox1_01
            pFabricaObjeto[id][102] = CreateDynamicObject(1625, 2140.2504, -2248.5224, 21.2385, 0.0000, 0.0000, 134.7998, vw, 0, -1, 400.0, 400.0, -1); //nt_cablebox2_01
            pFabricaObjeto[id][103] = CreateDynamicObject(2991, 2149.8972, -2253.6960, 20.2751, 0.0000, 0.0000, -44.4999, vw, 0, -1, 400.0, 400.0, -1); //imy_bbox
            pFabricaObjeto[id][104] = CreateDynamicObject(2991, 2149.8972, -2253.6960, 21.5352, 0.0000, 0.0000, -44.4999, vw, 0, -1, 400.0, 400.0, -1); //imy_bbox
            pFabricaObjeto[id][105] = CreateDynamicObject(1421, 2128.7436, -2265.7385, 20.4085, 0.0000, 0.0000, -135.5000, vw, 0, -1, 400.0, 400.0, -1); //DYN_BOXES
            pFabricaObjeto[id][106] = CreateDynamicObject(1271, 2138.0092, -2288.4064, 20.0135, 0.0000, 0.0000, -44.9000, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][107] = CreateDynamicObject(19898, 2173.1882, -2255.6081, 19.6833, 0.0000, 0.0000, -97.7997, vw, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
            pFabricaObjeto[id][108] = CreateDynamicObject(19898, 2154.2094, -2259.1755, 19.6833, 0.0000, 0.0000, 20.6000, vw, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
            pFabricaObjeto[id][109] = CreateDynamicObject(1271, 2138.5898, -2288.8425, 20.0387, 0.0000, 0.0000, -41.6999, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][110] = CreateDynamicObject(1271, 2138.8266, -2288.0605, 20.0356, 0.0000, 0.0000, 49.3997, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][111] = CreateDynamicObject(1271, 2138.3754, -2288.4655, 20.6877, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][112] = CreateDynamicObject(2886, 2131.7214, -2277.6843, 21.1695, 0.0000, 0.0000, -45.2000, vw, 0, -1, 400.0, 400.0, -1); //sec_keypad
            pFabricaObjeto[id][113] = CreateDynamicObject(1271, 2142.6682, -2256.9213, 13.7839, 0.0000, 0.0000, 0.0000, vw, 0, -1, 400.0, 400.0, -1); //gunbox
            pFabricaObjeto[id][114] = CreateDynamicObject(2567, 2127.8930, -2276.4130, 17.3111, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][115] = CreateDynamicObject(939, 2139.0939, -2288.7783, 16.1539, 0.0000, 0.0000, 0.4000, vw, 0, -1, 400.0, 400.0, -1); //CJ_DF_UNIT
            pFabricaObjeto[id][116] = CreateDynamicObject(2567, 2123.9562, -2272.5292, 13.7209, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][117] = CreateDynamicObject(2567, 2123.9562, -2272.5292, 17.3411, 0.0000, 0.0000, -44.5998, vw, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][118] = CreateDynamicObject(3785, 2121.3852, -2275.3139, 20.8390, 0.0000, 0.0000, 46.5001, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][119] = CreateDynamicObject(3785, 2129.1210, -2282.9992, 20.8390, 0.0000, 0.0000, 46.5001, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][120] = CreateDynamicObject(2010, 2125.4667, -2278.9479, 19.6835, 0.0000, 0.0000, -41.5999, vw, 0, -1, 400.0, 400.0, -1); //nu_plant3_ofc
            pFabricaObjeto[id][121] = CreateDynamicObject(3785, 2125.1984, -2279.1120, 20.8390, 0.0000, 0.0000, 46.5001, vw, 0, -1, 400.0, 400.0, -1); //bulkheadlight
            pFabricaObjeto[id][122] = CreateDynamicObject(19835, 2123.6699, -2269.8530, 21.5901, 0.0000, 0.0000, -48.0000, vw, 0, -1, 400.0, 400.0, -1); //CoffeeCup1
            pFabricaObjeto[id][123] = CreateDynamicObject(1714, 2125.3288, -2272.4392, 19.7063, 0.0000, 0.0000, -66.4999, vw, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
            pFabricaObjeto[id][124] = CreateDynamicObject(1714, 2127.0224, -2274.3525, 19.6863, 0.0000, 0.0000, -45.9000, vw, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
            pFabricaObjeto[id][125] = CreateDynamicObject(2464, 2124.5100, -2271.9343, 20.6326, 0.0000, 0.0000, 55.4000, vw, 0, -1, 400.0, 400.0, -1); //MODEL_BOX1
            pFabricaObjeto[id][126] = CreateDynamicObject(1514, 2125.7678, -2274.1979, 20.7568, 0.0000, 0.0000, -45.4000, vw, 0, -1, 400.0, 400.0, -1); //DYN_FF_TILL
            pFabricaObjeto[id][127] = CreateDynamicObject(11705, 2127.2314, -2275.6721, 20.4634, 0.0000, 0.0000, 164.8999, vw, 0, -1, 400.0, 400.0, -1); //BlackTelephone1
            pFabricaObjeto[id][128] = CreateDynamicObject(19328, 2125.1950, -2279.2255, 21.9789, 0.0000, 0.0000, 134.7001, vw, 0, -1, 400.0, 400.0, -1); //7_11_sign03
            SetDynamicObjectMaterial(pFabricaObjeto[id][128], 0, 3083, "billbox", "Sprunk_postersign1", 0xFFFFFFFF);
            pFabricaObjeto[id][129] = CreateDynamicObject(11705, 2124.8527, -2273.2495, 20.4634, 0.0000, 0.0000, 150.2999, vw, 0, -1, 400.0, 400.0, -1); //BlackTelephone1
        
            pFabricaBot[id][0] = CreateDynamicActor(172, 2127.4165,-2274.7019,20.7183,118.0853, 1, 100.0, vw, 0, -1, 200.0, -1, 0);
            pFabricaBot[id][1] = CreateDynamicActor(194, 2132.1030,-2282.1411,20.7113,46.2483, 1, 100.0, vw, 0, -1, 200.0, -1, 0);
        }

        // Conce
        case 3:
        {
            pFabricaObjeto[id][0] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][1] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][2] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][3] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][4] = CreateDynamicObject(2912, 1197.0620, 1254.4895, 1036.8979, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //temp_crate1
            pFabricaObjeto[id][5] = CreateDynamicObject(19545, 1179.1971, 1283.2331, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][5], 0, 12978, "ce_payspray", "sf_spray_floor2", 0xFFFFFFFF);
            pFabricaObjeto[id][6] = CreateDynamicObject(3474, 1192.7828, 1201.6922, 1040.1672, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Freightcrane1
            pFabricaObjeto[id][7] = CreateDynamicObject(19545, 1194.0738, 1220.7937, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][7], 0, 12978, "ce_payspray", "sf_spray_floor2", 0xFFFFFFFF);
            pFabricaObjeto[id][8] = CreateDynamicObject(19545, 1149.3160, 1220.7937, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][8], 0, 12978, "ce_payspray", "sf_spray_floor2", 0xFFFFFFFF);
            pFabricaObjeto[id][9] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][10] = CreateDynamicObject(19545, 1134.3457, 1220.7937, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][10], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][11] = CreateDynamicObject(19545, 1164.3170, 1283.2331, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][11], 0, 12978, "ce_payspray", "sf_spray_floor2", 0xFFFFFFFF);
            pFabricaObjeto[id][12] = CreateDynamicObject(19545, 1119.4775, 1220.7937, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][12], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][13] = CreateDynamicObject(19545, 1119.4775, 1283.2331, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][13], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][14] = CreateDynamicObject(19545, 1149.3968, 1283.2331, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][14], 0, 12978, "ce_payspray", "sf_spray_floor2", 0xFFFFFFFF);
            pFabricaObjeto[id][15] = CreateDynamicObject(19545, 1149.4167, 1283.2331, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][15], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][16] = CreateDynamicObject(19545, 1164.2552, 1220.7937, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][16], 0, 12978, "ce_payspray", "sf_spray_floor1", 0xFFFFFFFF);
            pFabricaObjeto[id][17] = CreateDynamicObject(19545, 1201.3575, 1220.8238, 1041.2701, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][17], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][18] = CreateDynamicObject(3474, 1192.7828, 1227.1523, 1040.1672, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Freightcrane1
            pFabricaObjeto[id][19] = CreateDynamicObject(19545, 1134.4272, 1283.2331, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][19], 0, 14706, "labig2int2", "wood14S", 0xFFFFFFFF);
            pFabricaObjeto[id][20] = CreateDynamicObject(19545, 1182.3088, 1189.8038, 1041.2701, 0.0000, 90.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][20], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][21] = CreateDynamicObject(19467, 1193.4914, 1198.0318, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][22] = CreateDynamicObject(19545, 1201.3575, 1283.2331, 1041.2701, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][22], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][23] = CreateDynamicObject(19545, 1120.0000, 1313.3044, 1041.2701, 0.0000, 90.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][23], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][24] = CreateDynamicObject(19545, 1132.3269, 1283.1239, 1043.9300, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][24], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][25] = CreateDynamicObject(19545, 1120.0000, 1189.8038, 1041.2701, 0.0000, 90.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][25], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][26] = CreateDynamicObject(19545, 1112.7563, 1220.8238, 1034.6999, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][26], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][27] = CreateDynamicObject(19545, 1193.8381, 1283.2331, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][27], 0, 12978, "ce_payspray", "sf_spray_floor2", 0xFFFFFFFF);
            pFabricaObjeto[id][28] = CreateDynamicObject(3474, 1192.7828, 1251.0528, 1040.1672, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Freightcrane1
            pFabricaObjeto[id][29] = CreateDynamicObject(19464, 1157.6208, 1244.3978, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][29], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][30] = CreateDynamicObject(19545, 1194.3636, 1283.2434, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][30], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][31] = CreateDynamicObject(19545, 1182.2297, 1313.3044, 1041.2701, 0.0000, 90.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][31], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][32] = CreateDynamicObject(19467, 1191.6518, 1198.0318, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][33] = CreateDynamicObject(19464, 1157.6208, 1238.4781, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][33], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][34] = CreateDynamicObject(19464, 1157.6208, 1232.6081, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][34], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][35] = CreateDynamicObject(1379, 1163.6257, 1202.0919, 1041.8841, 0.0000, 180.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //MagnoCrane_02
            pFabricaObjeto[id][36] = CreateDynamicObject(19467, 1164.3712, 1264.9001, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][37] = CreateDynamicObject(19467, 1193.4914, 1202.5423, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][38] = CreateDynamicObject(1380, 1163.6501, 1259.4764, 1054.0954, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //MagnoCrane_01
            pFabricaObjeto[id][39] = CreateDynamicObject(19467, 1193.4914, 1207.0218, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][40] = CreateDynamicObject(1380, 1163.6501, 1216.9659, 1054.0954, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //MagnoCrane_01
            pFabricaObjeto[id][41] = CreateDynamicObject(19467, 1193.4914, 1211.4818, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][42] = CreateDynamicObject(19467, 1193.4914, 1215.9720, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][43] = CreateDynamicObject(19467, 1193.4914, 1220.4516, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][44] = CreateDynamicObject(19467, 1193.4914, 1224.9516, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][45] = CreateDynamicObject(19467, 1193.4914, 1229.4215, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][46] = CreateDynamicObject(19467, 1193.4914, 1233.8813, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][47] = CreateDynamicObject(19467, 1193.4914, 1238.3513, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][48] = CreateDynamicObject(19467, 1193.4914, 1242.8310, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][49] = CreateDynamicObject(19467, 1193.4914, 1247.2911, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][50] = CreateDynamicObject(19467, 1193.4914, 1251.7607, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][51] = CreateDynamicObject(19467, 1193.4914, 1256.2508, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][52] = CreateDynamicObject(19467, 1193.4914, 1260.6905, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][53] = CreateDynamicObject(19467, 1193.4914, 1265.1306, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][54] = CreateDynamicObject(19467, 1193.4914, 1269.5804, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][55] = CreateDynamicObject(19467, 1193.4914, 1274.0106, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][56] = CreateDynamicObject(19467, 1193.4914, 1276.6400, 1036.9083, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][57] = CreateDynamicObject(19467, 1191.6518, 1202.5317, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][58] = CreateDynamicObject(19467, 1191.6518, 1207.0017, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][59] = CreateDynamicObject(19467, 1191.6518, 1211.5013, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][60] = CreateDynamicObject(19467, 1191.6518, 1215.9818, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][61] = CreateDynamicObject(19467, 1191.6518, 1220.4514, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][62] = CreateDynamicObject(19467, 1191.6518, 1224.8812, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][63] = CreateDynamicObject(19467, 1191.6518, 1229.3214, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][64] = CreateDynamicObject(19467, 1191.6518, 1233.7912, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][65] = CreateDynamicObject(19467, 1191.6518, 1238.2314, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][66] = CreateDynamicObject(19467, 1191.6518, 1242.6910, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][67] = CreateDynamicObject(19467, 1191.6518, 1247.1705, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][68] = CreateDynamicObject(19467, 1191.6518, 1251.5804, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][69] = CreateDynamicObject(19467, 1191.6518, 1256.0205, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][70] = CreateDynamicObject(19467, 1191.6518, 1260.4704, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][71] = CreateDynamicObject(19467, 1191.6518, 1264.9001, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][72] = CreateDynamicObject(19467, 1191.6518, 1269.3696, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][73] = CreateDynamicObject(19467, 1191.6518, 1273.8193, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][74] = CreateDynamicObject(19467, 1190.1119, 1276.1285, 1036.8983, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][75] = CreateDynamicObject(19467, 1191.1711, 1278.1804, 1036.9083, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][76] = CreateDynamicObject(19464, 1157.6208, 1250.3275, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][76], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][77] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][78] = CreateDynamicObject(3091, 1187.2740, 1263.0948, 1037.4543, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //imy_track_barrier
            pFabricaObjeto[id][79] = CreateDynamicObject(19464, 1169.6113, 1244.5079, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][79], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][80] = CreateDynamicObject(19464, 1169.6113, 1238.6280, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][80], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][81] = CreateDynamicObject(19464, 1169.6113, 1226.9287, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][81], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][82] = CreateDynamicObject(19464, 1169.6113, 1232.7983, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][82], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][83] = CreateDynamicObject(19464, 1157.6208, 1226.7381, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][83], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][84] = CreateDynamicObject(3675, 1171.1418, 1250.6682, 1036.8360, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //laxrf_refinerypipe
            SetDynamicObjectMaterial(pFabricaObjeto[id][84], 0, 17562, "coast_apts", "sl_concslabgrey_64", 0xFFFFFFFF);
            pFabricaObjeto[id][85] = CreateDynamicObject(3675, 1156.0521, 1250.6682, 1036.8360, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //laxrf_refinerypipe
            SetDynamicObjectMaterial(pFabricaObjeto[id][85], 0, 17562, "coast_apts", "sl_concslabgrey_64", 0xFFFFFFFF);
            pFabricaObjeto[id][86] = CreateDynamicObject(3675, 1156.0521, 1242.0782, 1036.8360, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //laxrf_refinerypipe
            SetDynamicObjectMaterial(pFabricaObjeto[id][86], 0, 17562, "coast_apts", "sl_concslabgrey_64", 0xFFFFFFFF);
            pFabricaObjeto[id][87] = CreateDynamicObject(3675, 1171.1623, 1241.6483, 1036.8360, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //laxrf_refinerypipe
            SetDynamicObjectMaterial(pFabricaObjeto[id][87], 0, 17562, "coast_apts", "sl_concslabgrey_64", 0xFFFFFFFF);
            pFabricaObjeto[id][88] = CreateDynamicObject(3675, 1171.1623, 1233.3181, 1036.8360, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //laxrf_refinerypipe
            SetDynamicObjectMaterial(pFabricaObjeto[id][88], 0, 17562, "coast_apts", "sl_concslabgrey_64", 0xFFFFFFFF);
            pFabricaObjeto[id][89] = CreateDynamicObject(3675, 1156.0329, 1233.3181, 1036.8360, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //laxrf_refinerypipe
            SetDynamicObjectMaterial(pFabricaObjeto[id][89], 0, 17562, "coast_apts", "sl_concslabgrey_64", 0xFFFFFFFF);
            pFabricaObjeto[id][90] = CreateDynamicObject(3675, 1156.0329, 1225.3979, 1036.8360, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //laxrf_refinerypipe
            SetDynamicObjectMaterial(pFabricaObjeto[id][90], 0, 17562, "coast_apts", "sl_concslabgrey_64", 0xFFFFFFFF);
            pFabricaObjeto[id][91] = CreateDynamicObject(3675, 1171.1925, 1225.3979, 1036.8360, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //laxrf_refinerypipe
            SetDynamicObjectMaterial(pFabricaObjeto[id][91], 0, 17562, "coast_apts", "sl_concslabgrey_64", 0xFFFFFFFF);
            pFabricaObjeto[id][92] = CreateDynamicObject(19464, 1169.6113, 1250.3475, 1039.3868, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][92], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][93] = CreateDynamicObject(3091, 1187.6938, 1239.6241, 1037.4543, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //imy_track_barrier
            pFabricaObjeto[id][94] = CreateDynamicObject(3091, 1188.0539, 1214.4045, 1037.4543, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //imy_track_barrier
            pFabricaObjeto[id][95] = CreateDynamicObject(1392, 1159.1102, 1251.1527, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][96] = CreateDynamicObject(1392, 1159.1102, 1249.2430, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][97] = CreateDynamicObject(1392, 1159.1102, 1247.3435, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][98] = CreateDynamicObject(1392, 1159.1102, 1245.4635, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][99] = CreateDynamicObject(1392, 1159.1102, 1225.0228, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][100] = CreateDynamicObject(1392, 1159.1102, 1226.9527, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][101] = CreateDynamicObject(1392, 1159.1102, 1228.8221, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][102] = CreateDynamicObject(1392, 1159.1102, 1230.7120, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][103] = CreateDynamicObject(1392, 1168.1003, 1230.7120, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][104] = CreateDynamicObject(1392, 1168.1003, 1228.7923, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][105] = CreateDynamicObject(1392, 1168.1003, 1226.8924, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][106] = CreateDynamicObject(1392, 1168.1003, 1224.9925, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][107] = CreateDynamicObject(1392, 1168.1003, 1251.1628, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][108] = CreateDynamicObject(1392, 1168.1003, 1249.2829, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][109] = CreateDynamicObject(1392, 1168.1003, 1247.3830, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][110] = CreateDynamicObject(1392, 1168.1003, 1245.5129, 1036.9775, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //TwrCrane_L_04
            pFabricaObjeto[id][111] = CreateDynamicObject(934, 1158.5860, 1237.9613, 1038.0166, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //GENERATOR_BIG
            pFabricaObjeto[id][112] = CreateDynamicObject(934, 1168.7662, 1237.9613, 1038.0166, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //GENERATOR_BIG
            pFabricaObjeto[id][113] = CreateDynamicObject(19467, 1164.3712, 1260.4101, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][114] = CreateDynamicObject(19467, 1162.4813, 1264.9001, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][115] = CreateDynamicObject(19545, 1149.3968, 1220.7641, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][115], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][116] = CreateDynamicObject(19467, 1162.4813, 1260.4298, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][117] = CreateDynamicObject(19467, 1162.4813, 1255.9499, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][118] = CreateDynamicObject(19467, 1162.4813, 1251.4498, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][119] = CreateDynamicObject(19467, 1162.4813, 1246.9698, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][120] = CreateDynamicObject(19467, 1162.4813, 1242.4897, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][121] = CreateDynamicObject(19467, 1162.4813, 1238.0500, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][122] = CreateDynamicObject(19467, 1162.4813, 1233.6207, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][123] = CreateDynamicObject(19467, 1162.4813, 1229.1506, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][124] = CreateDynamicObject(19467, 1162.4813, 1224.6809, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][125] = CreateDynamicObject(19467, 1162.4813, 1220.2110, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][126] = CreateDynamicObject(19467, 1162.4813, 1215.7508, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][127] = CreateDynamicObject(19467, 1164.3712, 1255.9604, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][128] = CreateDynamicObject(19467, 1164.3712, 1251.5102, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][129] = CreateDynamicObject(19467, 1164.3712, 1247.0406, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][130] = CreateDynamicObject(19467, 1164.3712, 1242.5714, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][131] = CreateDynamicObject(19467, 1164.3712, 1238.0915, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][132] = CreateDynamicObject(19467, 1164.3712, 1233.6422, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][133] = CreateDynamicObject(19467, 1164.3712, 1229.1827, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][134] = CreateDynamicObject(19467, 1164.3712, 1224.7530, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][135] = CreateDynamicObject(19467, 1164.3712, 1220.3236, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][136] = CreateDynamicObject(19467, 1164.3712, 1215.9831, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][137] = CreateDynamicObject(19467, 1164.3712, 1215.7508, 1036.9083, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][138] = CreateDynamicObject(5681, 1173.9713, 1246.2021, 1042.9271, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //carwashalphas_lae
            pFabricaObjeto[id][139] = CreateDynamicObject(5681, 1173.9713, 1237.3819, 1042.9271, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //carwashalphas_lae
            pFabricaObjeto[id][140] = CreateDynamicObject(5681, 1173.9713, 1228.8221, 1042.9271, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //carwashalphas_lae
            pFabricaObjeto[id][141] = CreateDynamicObject(5681, 1173.9713, 1222.9217, 1042.9271, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //carwashalphas_lae
            pFabricaObjeto[id][142] = CreateDynamicObject(19464, 1160.0703, 1249.1379, 1041.8470, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][142], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][143] = CreateDynamicObject(19464, 1160.0703, 1243.1882, 1041.8470, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][143], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][144] = CreateDynamicObject(19464, 1160.0703, 1237.2580, 1041.8470, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][144], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][145] = CreateDynamicObject(19464, 1160.0703, 1231.4283, 1041.8470, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][145], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][146] = CreateDynamicObject(19464, 1160.0803, 1227.0378, 1041.8570, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][146], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][147] = CreateDynamicObject(19464, 1165.1700, 1227.0378, 1041.8470, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][147], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][148] = CreateDynamicObject(19464, 1165.1499, 1249.1379, 1041.8470, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][148], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][149] = CreateDynamicObject(19464, 1165.1499, 1243.2176, 1041.8470, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][149], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][150] = CreateDynamicObject(19464, 1165.1499, 1237.2679, 1041.8470, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][150], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][151] = CreateDynamicObject(19464, 1165.1499, 1231.6683, 1041.8370, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][151], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][152] = CreateDynamicObject(19464, 1167.1601, 1227.0378, 1041.8370, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][152], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][153] = CreateDynamicObject(19464, 1167.1601, 1233.0345, 1041.8270, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][153], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][154] = CreateDynamicObject(19464, 1167.1601, 1238.9079, 1041.8270, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][154], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][155] = CreateDynamicObject(19464, 1167.1601, 1244.8476, 1041.8270, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][155], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][156] = CreateDynamicObject(19464, 1167.1601, 1249.1678, 1041.8270, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //wall104
            SetDynamicObjectMaterial(pFabricaObjeto[id][156], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][157] = CreateDynamicObject(10814, 1174.1147, 1318.5030, 1041.0123, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //apfuel2_SFSe
            pFabricaObjeto[id][158] = CreateDynamicObject(17055, 1163.2181, 1229.2939, 1044.0687, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //cw_fueldrum03
            pFabricaObjeto[id][159] = CreateDynamicObject(17055, 1163.2181, 1247.7142, 1044.0687, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //cw_fueldrum03
            pFabricaObjeto[id][160] = CreateDynamicObject(17055, 1163.2181, 1238.8038, 1044.0687, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //cw_fueldrum03
            pFabricaObjeto[id][161] = CreateDynamicObject(16342, 1163.6324, 1201.8741, 1045.5400, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //dam_genturbine04
            pFabricaObjeto[id][162] = CreateDynamicObject(19467, 1186.6811, 1278.1804, 1036.9083, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][163] = CreateDynamicObject(19467, 1182.1721, 1278.1804, 1036.9083, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][164] = CreateDynamicObject(19467, 1177.6921, 1278.1804, 1036.9083, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][165] = CreateDynamicObject(19467, 1173.2021, 1278.1804, 1036.9083, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][166] = CreateDynamicObject(19467, 1168.7030, 1278.1804, 1036.9083, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][167] = CreateDynamicObject(19467, 1164.7534, 1278.1804, 1036.9083, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][168] = CreateDynamicObject(19467, 1185.6223, 1276.1285, 1036.8983, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][169] = CreateDynamicObject(19467, 1181.1826, 1276.1285, 1036.8983, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][170] = CreateDynamicObject(19467, 1176.7126, 1276.1285, 1036.8983, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][171] = CreateDynamicObject(19467, 1172.2729, 1276.1285, 1036.8983, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][172] = CreateDynamicObject(19467, 1167.8132, 1276.1285, 1036.9183, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][173] = CreateDynamicObject(19467, 1164.3712, 1269.3602, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][174] = CreateDynamicObject(19467, 1164.3712, 1273.8103, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][175] = CreateDynamicObject(19467, 1166.5627, 1276.1285, 1036.8983, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][176] = CreateDynamicObject(19467, 1162.4813, 1269.4001, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][177] = CreateDynamicObject(19467, 1162.4813, 1273.8098, 1036.8983, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][178] = CreateDynamicObject(19467, 1162.4813, 1276.6302, 1036.9183, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //vehicle_barrier01
            pFabricaObjeto[id][179] = CreateDynamicObject(19545, 1141.9359, 1254.5963, 1044.4199, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][179], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][180] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][181] = CreateDynamicObject(19545, 1179.3646, 1220.7641, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][181], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][182] = CreateDynamicObject(19545, 1164.4027, 1283.2434, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][182], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][183] = CreateDynamicObject(19545, 1194.3636, 1220.7641, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][183], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][184] = CreateDynamicObject(19545, 1164.3751, 1220.7641, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][184], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][185] = CreateDynamicObject(3474, 1192.7828, 1274.7933, 1040.1672, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Freightcrane1
            pFabricaObjeto[id][186] = CreateDynamicObject(19545, 1179.3939, 1283.2434, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][186], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][187] = CreateDynamicObject(18075, 1179.5622, 1287.2103, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][188] = CreateDynamicObject(18075, 1179.5622, 1268.7401, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][189] = CreateDynamicObject(19545, 1179.1944, 1220.7937, 1036.9101, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][189], 0, 12978, "ce_payspray", "sf_spray_floor2", 0xFFFFFFFF);
            pFabricaObjeto[id][190] = CreateDynamicObject(18075, 1179.5622, 1252.1687, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][191] = CreateDynamicObject(18075, 1179.5622, 1236.3291, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][192] = CreateDynamicObject(18075, 1179.5622, 1220.4090, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][193] = CreateDynamicObject(18075, 1179.5622, 1202.4189, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][194] = CreateDynamicObject(930, 1160.8393, 1212.9829, 1037.3640, 0.0000, 0.0000, -41.0000, vw, 5, -1, 400.0, 400.0, -1); //O2_Bottles
            pFabricaObjeto[id][195] = CreateDynamicObject(19545, 1141.9259, 1316.6728, 1046.8203, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][195], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][196] = CreateDynamicObject(19545, 1110.6754, 1284.5339, 1042.8999, 0.0000, 90.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][196], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][197] = CreateDynamicObject(19545, 1141.9359, 1192.2650, 1044.4199, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][197], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][198] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][199] = CreateDynamicObject(19545, 1134.6866, 1283.2331, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][199], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][200] = CreateDynamicObject(19545, 1119.8070, 1283.2331, 1048.5316, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][200], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][201] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][202] = CreateDynamicObject(3259, 1179.5848, 1191.1920, 1018.9254, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //refcondens1
            pFabricaObjeto[id][203] = CreateDynamicObject(2971, 1195.7617, 1205.1899, 1036.8962, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //k_smashboxes
            pFabricaObjeto[id][204] = CreateDynamicObject(3761, 1200.5683, 1201.8486, 1038.8823, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //industshelves
            pFabricaObjeto[id][205] = CreateDynamicObject(1438, 1196.0155, 1198.0571, 1036.9011, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //DYN_BOX_PILE_2
            pFabricaObjeto[id][206] = CreateDynamicObject(1081, 1195.3166, 1204.6655, 1038.2917, 0.0000, 0.0000, -144.1000, vw, 5, -1, 400.0, 400.0, -1); //wheel_sr4
            pFabricaObjeto[id][207] = CreateDynamicObject(1083, 1195.8247, 1203.9890, 1037.3907, 0.0000, 0.0000, -92.8000, vw, 5, -1, 400.0, 400.0, -1); //wheel_lr2
            pFabricaObjeto[id][208] = CreateDynamicObject(1084, 1194.9272, 1199.1330, 1037.3797, 0.0000, 0.0000, 154.6999, vw, 5, -1, 400.0, 400.0, -1); //wheel_lr5
            pFabricaObjeto[id][209] = CreateDynamicObject(3573, 1145.9852, 1235.4586, 1039.5538, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //lasdkrtgrp1
            pFabricaObjeto[id][210] = CreateDynamicObject(3573, 1145.9852, 1219.9488, 1039.5538, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //lasdkrtgrp1
            pFabricaObjeto[id][211] = CreateDynamicObject(1096, 1201.2270, 1199.3216, 1041.3746, 0.0000, 0.0000, -179.1999, vw, 5, -1, 400.0, 400.0, -1); //wheel_gn3
            pFabricaObjeto[id][212] = CreateDynamicObject(1083, 1201.2048, 1204.0991, 1041.3310, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //wheel_lr2
            pFabricaObjeto[id][213] = CreateDynamicObject(1084, 1201.2275, 1201.7932, 1041.3597, 0.0000, 0.0000, 180.0000, vw, 5, -1, 400.0, 400.0, -1); //wheel_lr5
            pFabricaObjeto[id][214] = CreateDynamicObject(970, 1188.5477, 1197.7099, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][214], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][215] = CreateDynamicObject(970, 1188.5477, 1201.8498, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][215], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][216] = CreateDynamicObject(970, 1188.5477, 1205.6595, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][216], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][217] = CreateDynamicObject(3761, 1200.5683, 1227.2486, 1038.8823, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //industshelves
            pFabricaObjeto[id][218] = CreateDynamicObject(1066, 1200.6053, 1226.7336, 1040.3962, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //exh_c_j
            pFabricaObjeto[id][219] = CreateDynamicObject(1066, 1200.6053, 1226.7336, 1037.2263, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //exh_c_j
            pFabricaObjeto[id][220] = CreateDynamicObject(1046, 1200.9364, 1228.0804, 1037.4270, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //exh_a_f
            pFabricaObjeto[id][221] = CreateDynamicObject(1046, 1200.9364, 1228.0804, 1038.9770, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //exh_a_f
            pFabricaObjeto[id][222] = CreateDynamicObject(1020, 1200.4527, 1227.6855, 1040.9377, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //exh_b_l
            pFabricaObjeto[id][223] = CreateDynamicObject(2900, 1200.5721, 1224.9071, 1040.8940, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //temp_cardbox
            pFabricaObjeto[id][224] = CreateDynamicObject(2972, 1200.5649, 1228.1330, 1040.8546, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //k_cargo4
            pFabricaObjeto[id][225] = CreateDynamicObject(11745, 1200.5522, 1229.4952, 1038.6378, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //HoldAllEdited1
            pFabricaObjeto[id][226] = CreateDynamicObject(2974, 1197.3017, 1231.5128, 1036.5030, 0.0000, 0.0000, 51.5998, vw, 5, -1, 400.0, 400.0, -1); //k_cargo1
            pFabricaObjeto[id][227] = CreateDynamicObject(2973, 1196.3524, 1223.7099, 1036.6687, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //k_cargo2
            pFabricaObjeto[id][228] = CreateDynamicObject(3761, 1200.5683, 1251.0288, 1038.8823, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //industshelves
            pFabricaObjeto[id][229] = CreateDynamicObject(1141, 1201.1273, 1250.1538, 1041.3352, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //rbmp_a_s
            pFabricaObjeto[id][230] = CreateDynamicObject(1141, 1201.1273, 1253.4542, 1040.5852, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //rbmp_a_s
            SetDynamicObjectMaterial(pFabricaObjeto[id][230], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][231] = CreateDynamicObject(1148, 1200.9726, 1251.8005, 1039.0096, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //rbmp_c_l
            SetDynamicObjectMaterial(pFabricaObjeto[id][231], 0, 1355, "break_s_bins", "CJ_RED_LEATHER", 0xFFFFFFFF);
            pFabricaObjeto[id][232] = CreateDynamicObject(1148, 1201.0742, 1251.4339, 1041.3890, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //rbmp_c_l
            SetDynamicObjectMaterial(pFabricaObjeto[id][232], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][233] = CreateDynamicObject(1157, 1201.0705, 1249.2889, 1037.4464, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fbmp_c_st
            SetDynamicObjectMaterial(pFabricaObjeto[id][233], 0, 1355, "break_s_bins", "CJ_RED_LEATHER", 0xFFFFFFFF);
            SetDynamicObjectMaterial(pFabricaObjeto[id][233], 1, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][234] = CreateDynamicObject(1157, 1201.0705, 1248.3791, 1038.9964, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fbmp_c_st
            SetDynamicObjectMaterial(pFabricaObjeto[id][234], 0, 1355, "break_s_bins", "CJ_RED_LEATHER", 0xFFFFFFFF);
            pFabricaObjeto[id][235] = CreateDynamicObject(923, 1196.6800, 1247.8901, 1037.7585, 0.0000, 0.0000, -128.8000, vw, 5, -1, 400.0, 400.0, -1); //Packing_carates2
            pFabricaObjeto[id][236] = CreateDynamicObject(970, 1188.5477, 1223.1595, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][236], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][237] = CreateDynamicObject(2912, 1197.0620, 1253.7794, 1036.8979, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //temp_crate1
            pFabricaObjeto[id][238] = CreateDynamicObject(2912, 1197.0620, 1253.0992, 1036.8979, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //temp_crate1
            pFabricaObjeto[id][239] = CreateDynamicObject(970, 1188.5477, 1227.2994, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][239], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][240] = CreateDynamicObject(970, 1188.5477, 1231.1092, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][240], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][241] = CreateDynamicObject(1157, 1197.5671, 1252.7386, 1038.0860, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fbmp_c_st
            SetDynamicObjectMaterial(pFabricaObjeto[id][241], 0, 16640, "a51", "concreteyellow256 copy", 0xFFFFFFFF);
            pFabricaObjeto[id][242] = CreateDynamicObject(970, 1188.5477, 1247.0687, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][242], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][243] = CreateDynamicObject(970, 1188.5477, 1251.1987, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][243], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][244] = CreateDynamicObject(970, 1188.5477, 1254.9980, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][244], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][245] = CreateDynamicObject(970, 1188.5477, 1270.7889, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][245], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][246] = CreateDynamicObject(970, 1188.5577, 1273.9686, 1037.4012, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //fencesmallb
            SetDynamicObjectMaterial(pFabricaObjeto[id][246], 0, 3474, "freightcrane", "yellowcabchev_256", 0xFFFFFFFF);
            pFabricaObjeto[id][247] = CreateDynamicObject(3761, 1200.5683, 1275.0085, 1038.8823, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //industshelves
            pFabricaObjeto[id][248] = CreateDynamicObject(930, 1195.7696, 1279.4725, 1037.3597, 0.0000, 0.0000, -32.7999, vw, 5, -1, 400.0, 400.0, -1); //O2_Bottles
            pFabricaObjeto[id][249] = CreateDynamicObject(1687, 1190.1495, 1272.8066, 1037.6673, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //gen_roofbit1
            pFabricaObjeto[id][250] = CreateDynamicObject(934, 1195.7778, 1272.5577, 1038.0992, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //GENERATOR_BIG
            pFabricaObjeto[id][251] = CreateDynamicObject(964, 1200.6689, 1272.7602, 1040.8264, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //CJ_METAL_CRATE
            pFabricaObjeto[id][252] = CreateDynamicObject(2983, 1200.4552, 1277.4641, 1041.3122, 90.0000, 180.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //will_valve
            pFabricaObjeto[id][253] = CreateDynamicObject(2983, 1200.4552, 1275.4139, 1041.3122, 90.0000, 180.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //will_valve
            pFabricaObjeto[id][254] = CreateDynamicObject(16094, -1101.4471, -991.5280, 131.2315, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //des_a51infenc
            pFabricaObjeto[id][255] = CreateDynamicObject(18075, 1159.8823, 1287.2103, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][256] = CreateDynamicObject(18075, 1159.8823, 1268.7098, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][257] = CreateDynamicObject(18075, 1159.8823, 1251.2198, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][258] = CreateDynamicObject(18075, 1159.8823, 1235.3094, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][259] = CreateDynamicObject(18075, 1159.8823, 1220.1988, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][260] = CreateDynamicObject(18075, 1159.8823, 1201.9387, 1048.4255, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //lightD
            pFabricaObjeto[id][261] = CreateDynamicObject(19545, 1141.9259, 1316.6921, 1031.9101, 0.0000, 90.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][261], 0, 2188, "kbblackjack", "chip_tray_gry", 0xFFFFFFFF);
            pFabricaObjeto[id][262] = CreateDynamicObject(19545, 1134.4162, 1283.2331, 1042.9217, 0.0000, 0.0000, 0.0000, vw, 5, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
            SetDynamicObjectMaterial(pFabricaObjeto[id][262], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
            pFabricaObjeto[id][263] = CreateDynamicObject(1569, 1141.9825, 1283.6925, 1036.9084, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //ADAM_V_DOOR
            pFabricaObjeto[id][264] = CreateDynamicObject(1569, 1141.9825, 1286.6721, 1036.9084, 0.0000, 0.0000, -90.0000, vw, 5, -1, 400.0, 400.0, -1); //ADAM_V_DOOR
            pFabricaObjeto[id][265] = CreateDynamicObject(2567, 1143.0837, 1277.9613, 1038.8192, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][266] = CreateDynamicObject(2567, 1143.0837, 1272.7419, 1038.8192, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][267] = CreateDynamicObject(2567, 1143.0837, 1267.5323, 1038.8192, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //ab_warehouseShelf
            pFabricaObjeto[id][268] = CreateDynamicObject(2567, 1145.3841, 1272.7032, 1038.8192, 0.0000, 0.0000, 90.0000, vw, 5, -1, 400.0, 400.0, -1); //ab_warehouseShelf
        }
    }
    return 1;
}

stock RemoverObjetoFabrica(id){
    for(new i=0; i < 269; i++){
        DestroyDynamicObjectEx(pFabricaObjeto[id][i]);
    }
    for(new i=0; i < 2; i++){
        DestroyDynamicActorEx(pFabricaObjeto[id][i]);
    }
    return 1;
}

stock ConfigurarMesasFabrica(id)
{
    new vw = PegarFabricaVw(id);

    if(pFabrica[id][FabricaTipo] != 3)
    {
        pFabricaTexto[id][0] = CreateDynamic3DTextLabel("Mesa Etapa 1\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 2146.9045, -2265.5725, 12.7749, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 0, -1, 16.0, -1);
        pFabricaTexto[id][1] = CreateDynamic3DTextLabel("Mesa Etapa 2\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 2148.8195, -2267.4768, 12.7749, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 0, -1, 16.0, -1);
        pFabricaTexto[id][2] = CreateDynamic3DTextLabel("Mesa Etapa 3\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 2150.8547, -2269.5014, 12.7749, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 0, -1, 16.0, -1);

        pFabricaTexto[id][3] = CreateDynamic3DTextLabel("Mesa de Preparo\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 2161.9594, -2261.7885, 12.7600, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 0, -1, 16.0, -1);
        pFabricaTexto[id][4] = CreateDynamic3DTextLabel("Mesa de Verificação\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 2167.5781, -2256.3222, 12.7600, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 0, -1, 16.0, -1);
        
        pFabricaTexto[id][5] = CreateDynamic3DTextLabel("Liquidos\n{FFFFFF}Aperte {CCCCCC}'N'{FFFFFF} para usar", 0xFFA50080, 2154.8591,-2250.3179,13.2972, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 0, -1, 16.0, -1);
        pFabricaTexto[id][6] = CreateDynamic3DTextLabel("Empacotamento\n{FFFFFF}Aperte {CCCCCC}'N'{FFFFFF} para usar", 0xFFA50080, 2162.9751,-2237.7522,13.3713, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 0, -1, 16.0, -1);
        pFabricaTexto[id][7] = CreateDynamic3DTextLabel("Pedidos\n{FFFFFF}Aperte {CCCCCC}'N'{FFFFFF} para usar", 0xFFA50080, 2179.1050,-2249.7874,20.6746, 150.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 0, -1, 151.0, -1);
    }
    else
    {
        pFabricaTexto[id][0] = CreateDynamic3DTextLabel("Etapa 1\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 1186.9625,1201.7100,1037.9102, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 5, -1, 16.0, -1);
        pFabricaTexto[id][1] = CreateDynamic3DTextLabel("Etapa 2\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 1187.2439,1227.5432,1037.9102, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 5, -1, 16.0, -1);
        pFabricaTexto[id][2] = CreateDynamic3DTextLabel("Etapa 3\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 1187.1711,1251.1036,1037.9102, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 5, -1, 16.0, -1);
        pFabricaTexto[id][3] = CreateDynamic3DTextLabel("Etapa 4\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 1187.3713,1272.7625,1037.9102, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 5, -1, 16.0, -1);
        pFabricaTexto[id][4] = CreateDynamic3DTextLabel("Etapa 5\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para usar", 0xFFA50080, 1159.8416,1213.9882,1037.9102, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 5, -1, 16.0, -1);
        pFabricaTexto[id][5] = CreateDynamic3DTextLabel("Pedidos\n{FFFFFF}Aperte {CCCCCC}'N'{FFFFFF} para usar", 0xFFA50080, 1198.3597,1276.8523,1037.9102, 150.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, 5, -1, 151.0, -1);   
    }

    return 1; 
}

stock RemoverMesasFabrica(id){
    for(new i=0; i < 8; i++){
        DestroyDynamic3DTextLabelEx(pFabricaTexto[id][i]);
    }
    return 1;
}