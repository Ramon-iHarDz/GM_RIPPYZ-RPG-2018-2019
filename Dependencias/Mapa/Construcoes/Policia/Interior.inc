#include <YSI_Coding\y_hooks>

new g_Object[61];
new g_Pickup[1];
new bool:Portao[2];



hook OnGameModeInit()
{
    g_Object[0] = CreateDynamicObject(19430, 250.6389, 69.6324, 1004.4445, -90.0998, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //wall070
    SetObjectMaterial(g_Object[0], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    g_Object[1] = CreateDynamicObject(19430, 250.6389, 66.1524, 1004.4506, -90.0998, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //wall070
    SetObjectMaterial(g_Object[1], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    g_Object[2] = CreateDynamicObject(2930, 250.7299, 64.1967, 1005.0825, 0.0000, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //chinaTgate
    g_Object[3] = CreateDynamicObject(2930, 245.5312, 72.5238, 1005.0545, 0.0000, 0.0000, 90.0000, 1300, 6, -1, 70.0, 70.0, -1); //chinaTgate
    g_Object[4] = CreateDynamicObject(1722, 242.3928, 63.3980, 1002.5883, 0.0000, 0.0000, 270.0000, 1300, 6, -1, 70.0, 70.0, -1); //off_chairnu
    g_Object[5] = CreateDynamicObject(1722, 242.3928, 64.5381, 1002.5883, 0.0000, 0.0000, 270.0000, 1300, 6, -1, 70.0, 70.0, -1); //off_chairnu
    g_Object[6] = CreateDynamicObject(2002, 242.9078, 69.5680, 1002.6126, 0.0000, 0.0000, 90.0000, 1300, 6, -1, 70.0, 70.0, -1); //water_coolnu
    g_Object[7] = CreateDynamicObject(1886, 249.9837, 71.8219, 1010.1251, 27.0000, 0.1999, -38.5998, 1300, 6, -1, 70.0, 70.0, -1); //shop_sec_cam
    g_Object[8] = CreateDynamicObject(2922, 245.1968, 72.3354, 1004.0795, 0.0000, 0.0000, 179.5000, 1300, 6, -1, 70.0, 70.0, -1); //kmb_keypad
    g_Object[9] = CreateDynamicObject(2922, 250.3883, 64.4894, 1004.0795, 0.0000, 0.0000, 91.2001, 1300, 6, -1, 70.0, 70.0, -1); //kmb_keypad
    g_Object[10] = CreateDynamicObject(2922, 250.8983, 64.5112, 1004.0795, 0.0000, 0.0000, -91.7997, 1300, 6, -1, 70.0, 70.0, -1); //kmb_keypad
    g_Object[11] = CreateDynamicObject(2165, 217.2326, 75.8824, 1004.0499, 0.0000, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //MED_OFFICE_DESK_1
    g_Object[12] = CreateDynamicObject(2164, 215.9353, 73.8640, 1004.0178, 0.0000, 0.0000, 179.8999, 1300, 6, -1, 70.0, 70.0, -1); //MED_OFFICE_UNIT_5
    g_Object[13] = CreateDynamicObject(2162, 213.9060, 78.0594, 1004.0106, 0.0000, 0.0000, 89.9000, 1300, 6, -1, 70.0, 70.0, -1); //MED_OFFICE_UNIT_1
    g_Object[14] = CreateDynamicObject(2167, 221.8733, 77.8240, 1004.0059, 0.0000, 0.0000, -90.0999, 1300, 6, -1, 70.0, 70.0, -1); //MED_OFFICE_UNIT_7
    g_Object[15] = CreateDynamicObject(2161, 220.2382, 73.8557, 1004.0117, 0.0000, 0.0000, -179.5000, 1300, 6, -1, 70.0, 70.0, -1); //MED_OFFICE_UNIT_4
    g_Object[16] = CreateDynamicObject(1671, 217.6772, 74.9775, 1004.4780, 0.0000, 0.0000, 149.3000, 1300, 6, -1, 70.0, 70.0, -1); //swivelchair_A
    g_Object[17] = CreateDynamicObject(2051, 219.3733, 72.7776, 1005.7122, 0.0000, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //CJ_TARGET4
    g_Object[18] = CreateDynamicObject(18637, 218.3280, 67.9247, 1004.6176, 76.6999, 0.0000, 94.1998, 1300, 6, -1, 70.0, 70.0, -1); //PoliceShield1
    g_Object[19] = CreateDynamicObject(19922, 217.5897, 67.3553, 1004.0103, 0.0000, 0.0000, 89.6998, 1300, 6, -1, 70.0, 70.0, -1); //MKTable1
    SetObjectMaterial(g_Object[19], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    g_Object[20] = CreateDynamicObject(2737, 216.9299, 67.5740, 1005.9000, 0.0000, 0.0000, 89.5999, 1300, 6, -1, 70.0, 70.0, -1); //POLICE_NB_car
    g_Object[21] = CreateDynamicObject(2615, 216.9490, 67.3556, 1006.0551, 0.0000, 0.0000, 89.0998, 1300, 6, -1, 70.0, 70.0, -1); //POLICE_NB3
    g_Object[22] = CreateDynamicObject(19141, 217.2630, 68.4673, 1004.8654, -36.2000, -90.0000, -134.1000, 1300, 6, -1, 70.0, 70.0, -1); //SWATHelmet1
    g_Object[23] = CreateDynamicObject(334, 217.6992, 68.3880, 1004.7993, 91.4000, -7.0998, -38.7000, 1300, 6, -1, 70.0, 70.0, -1); //nitestick
    g_Object[24] = CreateDynamicObject(11749, 217.9313, 67.9730, 1004.8496, 0.0000, 0.0000, 45.2999, 1300, 6, -1, 70.0, 70.0, -1); //CSHandcuffs1
    g_Object[25] = CreateDynamicObject(2035, 217.4785, 67.2928, 1004.8125, 0.0000, 0.0000, 23.6998, 1300, 6, -1, 70.0, 70.0, -1); //CJ_M16
    g_Object[26] = CreateDynamicObject(19165, 219.4528, 65.8052, 1006.1741, -89.5997, -0.7998, -0.8999, 1300, 6, -1, 70.0, 70.0, -1); //GTASAMap2
    g_Object[27] = CreateDynamicObject(2044, 217.3226, 66.6093, 1004.8342, 0.0000, 0.0000, 56.0998, 1300, 6, -1, 70.0, 70.0, -1); //CJ_MP5K
    g_Object[28] = CreateDynamicObject(19893, 217.9644, 66.8995, 1004.8068, 0.0000, 0.0000, 137.1997, 1300, 6, -1, 70.0, 70.0, -1); //LaptopSAMP1
    g_Object[29] = CreateDynamicObject(348, 217.7010, 66.2528, 1004.8408, -87.0000, 0.0000, -10.5000, 1300, 6, -1, 70.0, 70.0, -1); //desert_eagle
    g_Object[30] = CreateDynamicObject(1672, 217.3495, 67.8031, 1004.8986, 0.0000, 0.0000, 61.5999, 1300, 6, -1, 70.0, 70.0, -1); //Gasgrenade
    g_Object[31] = CreateDynamicObject(1672, 217.3560, 67.5836, 1004.8986, 0.0000, 0.0000, 95.4000, 1300, 6, -1, 70.0, 70.0, -1); //Gasgrenade
    g_Object[32] = CreateDynamicObject(1672, 217.6455, 67.7538, 1004.8272, 1.7000, -87.9999, 15.6000, 1300, 6, -1, 70.0, 70.0, -1); //Gasgrenade
    g_Object[33] = CreateDynamicObject(358, 218.4855, 66.6063, 1004.3659, -23.2000, -85.0000, 86.4999, 1300, 6, -1, 70.0, 70.0, -1); //sniper
    g_Object[34] = CreateDynamicObject(18636, 217.6161, 68.7005, 1004.8468, 0.0000, 0.0000, -27.6000, 1300, 6, -1, 70.0, 70.0, -1); //PoliceCap1
    g_Object[35] = CreateDynamicObject(19775, 218.0630, 68.6154, 1004.8145, -88.6999, 0.6999, 74.4000, 1300, 6, -1, 70.0, 70.0, -1); //PoliceBadge3
    g_Object[36] = CreateDynamicObject(19142, 217.2548, 66.1705, 1005.0678, -2.6998, -92.2998, -40.7999, 1300, 6, -1, 70.0, 70.0, -1); //SWATArmour1
    g_Object[37] = CreateDynamicObject(2961, 242.3856, 65.1924, 1004.0242, 0.0000, 0.0000, -91.9000, 1300, 6, -1, 70.0, 70.0, -1); //fire_break
    g_Object[38] = CreateDynamicObject(11729, 217.1372, 70.0470, 1004.0112, 0.0000, 0.0000, 89.4000, 1300, 6, -1, 70.0, 70.0, -1); //GymLockerClosed1
    g_Object[39] = CreateDynamicObject(11729, 217.1443, 70.7071, 1004.0112, 0.0000, 0.0000, 89.4000, 1300, 6, -1, 70.0, 70.0, -1); //GymLockerClosed1
    g_Object[40] = CreateDynamicObject(11729, 217.1511, 71.3671, 1004.0112, 0.0000, 0.0000, 89.4000, 1300, 6, -1, 70.0, 70.0, -1); //GymLockerClosed1
    g_Object[41] = CreateDynamicObject(11729, 217.1580, 72.0170, 1004.0112, 0.0000, 0.0000, 89.4000, 1300, 6, -1, 70.0, 70.0, -1); //GymLockerClosed1
    g_Object[42] = CreateDynamicObject(2603, 262.9096, 85.6997, 1000.4434, 0.0000, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //Police_Cell_Bed
    g_Object[43] = CreateDynamicObject(2603, 262.9096, 81.1899, 1000.4434, 0.0000, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //Police_Cell_Bed
    g_Object[44] = CreateDynamicObject(2603, 262.9096, 76.6598, 1000.4434, 0.0000, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //Police_Cell_Bed
    g_Object[45] = CreateDynamicObject(2602, 264.9266, 84.9285, 1000.5548, 0.0000, 0.0000, -179.6000, 1300, 6, -1, 70.0, 70.0, -1); //Police_cell_Toilet
    g_Object[46] = CreateDynamicObject(2602, 264.9580, 80.4287, 1000.5548, 0.0000, 0.0000, -179.6000, 1300, 6, -1, 70.0, 70.0, -1); //Police_cell_Toilet
    g_Object[47] = CreateDynamicObject(2602, 264.9891, 75.9287, 1000.5548, 0.0000, 0.0000, -179.6000, 1300, 6, -1, 70.0, 70.0, -1); //Police_cell_Toilet
    g_Object[48] = CreateDynamicObject(2009, 257.4302, 86.9313, 1001.4296, 0.0000, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //officedesk2l
    g_Object[49] = CreateDynamicObject(1671, 258.3432, 87.0669, 1001.8820, 0.0000, 0.0000, -46.4000, 1300, 6, -1, 70.0, 70.0, -1); //swivelchair_A
    g_Object[50] = CreateDynamicObject(19792, 257.4097, 87.8647, 1002.2753, 0.0000, 0.0000, 20.7999, 1300, 6, -1, 70.0, 70.0, -1); //SAMPKeycard1
    g_Object[51] = CreateDynamicObject(2342, 257.3421, 87.1725, 1002.3784, 0.0000, 0.0000, -108.6998, 1300, 6, -1, 70.0, 70.0, -1); //donut_disp
    g_Object[52] = CreateDynamicObject(1886, 258.4197, 82.4207, 1004.9432, 19.0000, 0.0000, -137.9998, 1300, 6, -1, 70.0, 70.0, -1); //shop_sec_cam
    g_Object[53] = CreateDynamicObject(1886, 270.0740, 75.9608, 1003.5822, 15.2999, 0.0000, -158.1997, 1300, 6, -1, 70.0, 70.0, -1); //shop_sec_cam
    g_Object[54] = CreateDynamicObject(2002, 257.7109, 82.3401, 1001.4390, 0.0000, 0.0000, -178.7998, 1300, 6, -1, 70.0, 70.0, -1); //water_coolnu
    g_Object[55] = CreateDynamicObject(3657, 255.0733, 82.2238, 1001.9295, 0.0000, 0.0000, 179.7001, 1300, 6, -1, 70.0, 70.0, -1); //airseata_LAS
    g_Object[56] = CreateDynamicObject(1820, 251.4559, 82.3877, 1001.4193, 0.0000, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //COFFEE_LOW_4
    g_Object[57] = CreateDynamicObject(2827, 251.9718, 82.8859, 1001.9287, 0.0000, 0.0000, 33.2999, 1300, 6, -1, 70.0, 70.0, -1); //GB_novels05
    g_Object[58] = CreateDynamicObject(19421, 252.0807, 82.6020, 1001.9296, 0.0000, 0.0000, 154.5000, 1300, 6, -1, 70.0, 70.0, -1); //headphones01
    g_Object[59] = CreateDynamicObject(19825, 217.7742, 82.8235, 1006.5189, 0.0000, 0.0000, 0.0000, 1300, 6, -1, 70.0, 70.0, -1); //SprunkClock1
    g_Object[60] = CreateDynamicObject(2922, 245.1997, 72.8453, 1004.0795, 0.0000, 0.0000, -2.5999, 1300, 6, -1, 70.0, 70.0, -1); //kmb_keypad
    g_Pickup[0] = CreateDynamicPickup(1314, 1, 253.4617,67.1255,1003.6406, 1300, 6, -1, 80.0, -1); //twoplayer
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys){

    if(newkeys == KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){

        //Portão que dá acesso aos armários etc..
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 245.5313, 72.5238, 1005.0545) && GetPlayerVirtualWorld(playerid) == 1300){
            if(Jogador[playerid][Admin] > 0 || IsPolicia(playerid)){
                if(Portao[0] == false){
                    SetTimerEx("FecharPortao", 5000, false, "dd", 1, playerid);
                    MoveDynamicObject(g_Object[3], 245.5313, 72.5238, 1005.0545+2.6, 2.0);
                    Portao[0] = true;
                }
            }
        }

        //Primeiro portão perto da porta de entrada!
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 250.7300, 64.1967, 1005.0825) && GetPlayerVirtualWorld(playerid) == 1300){
            if(Jogador[playerid][Admin] > 0 || !strcmp(Jogador[playerid][Profissao], "Advogado") || IsPolicia(playerid)){
                if(Portao[1] == false){
                    SetTimerEx("FecharPortao", 5000, false, "dd", 2, playerid);
                    MoveDynamicObject(g_Object[2], 250.7300, 64.1967, 1005.0825+2.6, 2.0);
                    Portao[1] = true; 
                }
            }
        }
    }
    return 1;
}

function FecharPortao(Gate, Objeto)
{
    if(Gate == 1){
        MoveDynamicObject(g_Object[3], 245.5313, 72.5238, 1005.0545, 5.0);
        Portao[0] = false;
    }
    if(Gate == 2){
        MoveDynamicObject(g_Object[2], 250.7300, 64.1967, 1005.0825, 5.0);
        Portao[1] = false;
    }
    return 1;
}