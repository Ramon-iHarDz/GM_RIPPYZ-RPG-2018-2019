#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 4687, 1543.7266, -1187.1250, 31.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 4755, 1562.0391, -1183.2734, 58.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 1266, 1536.0391, -1181.1484, 54.2891, 0.25);
	RemoveBuildingForPlayer(playerid, 4737, 1610.7344, -1201.3672, 36.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 4708, 1543.7266, -1187.1250, 31.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 1260, 1536.0391, -1181.1484, 54.2891, 0.25);
	RemoveBuildingForPlayer(playerid, 4733, 1562.0391, -1183.2734, 58.4141, 0.25);
    return 1;
}

hook OnGameModeInit()
{
    new LotericObject[378];
    LotericObject[0] = CreateDynamicObject(19380, 1560.5185, -1177.4854, 35.5484, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[0], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[1] = CreateDynamicObject(19544, 1558.1632, -1192.0976, 22.8544, 0.0000, -0.9998, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //Plane62_5x15Sand1
    SetDynamicObjectMaterial(LotericObject[1], 0, 12853, "cunte_gas01", "sw_floor1", 0xFFFFFFFF);
    LotericObject[2] = CreateDynamicObject(19439, 1532.1850, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[2], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[3] = CreateDynamicObject(19439, 1535.6745, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[3], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[4] = CreateDynamicObject(19439, 1539.1657, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[4], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[5] = CreateDynamicObject(19439, 1546.1560, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[5], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[6] = CreateDynamicObject(19439, 1542.6560, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[6], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[7] = CreateDynamicObject(19439, 1549.6372, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[7], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[8] = CreateDynamicObject(19439, 1553.1379, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[8], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[9] = CreateDynamicObject(19439, 1556.6386, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[9], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[10] = CreateDynamicObject(19439, 1560.1295, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[10], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[11] = CreateDynamicObject(19325, 1539.4022, -1185.7717, 26.9410, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[11], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[12] = CreateDynamicObject(19544, 1558.1632, -1178.2750, 23.0939, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //Plane62_5x15Sand1
    SetDynamicObjectMaterial(LotericObject[12], 0, 12853, "cunte_gas01", "sw_floor1", 0xFFFFFFFF);
    LotericObject[13] = CreateDynamicObject(19380, 1560.5487, -1177.3868, 28.3283, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[13], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[14] = CreateDynamicObject(19380, 1560.5487, -1187.0056, 28.1583, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[14], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[15] = CreateDynamicObject(19380, 1560.5185, -1187.0056, 35.5484, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[15], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[16] = CreateDynamicObject(19380, 1560.5185, -1194.7467, 35.5484, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[16], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[17] = CreateDynamicObject(19380, 1560.5987, -1194.7467, 25.0883, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[17], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[18] = CreateDynamicObject(19380, 1546.0610, -1200.6770, 17.6583, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[18], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[19] = CreateDynamicObject(19380, 1555.6302, -1200.6770, 17.6583, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[19], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[20] = CreateDynamicObject(19380, 1536.4216, -1200.6770, 17.6483, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[20], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[21] = CreateDynamicObject(19441, 1532.1324, -1199.9881, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[21], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[22] = CreateDynamicObject(19441, 1528.6325, -1199.9881, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[22], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[23] = CreateDynamicObject(19441, 1535.6319, -1199.9881, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[23], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[24] = CreateDynamicObject(19441, 1539.1617, -1199.9881, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[24], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[25] = CreateDynamicObject(19441, 1542.6516, -1199.9881, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[25], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[26] = CreateDynamicObject(19441, 1546.1411, -1199.9881, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[26], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[27] = CreateDynamicObject(19441, 1549.6512, -1199.9881, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[27], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[28] = CreateDynamicObject(19441, 1553.1418, -1199.9881, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[28], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[29] = CreateDynamicObject(19441, 1556.6512, -1199.9881, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[29], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[30] = CreateDynamicObject(19441, 1558.7115, -1199.9781, 22.6266, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[30], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[31] = CreateDynamicObject(19441, 1560.5324, -1199.9488, 21.1566, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[31], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[32] = CreateDynamicObject(19441, 1560.5324, -1199.9681, 17.6166, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall081
    SetDynamicObjectMaterial(LotericObject[32], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[33] = CreateDynamicObject(19380, 1526.9962, -1177.3763, 28.2483, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[33], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[34] = CreateDynamicObject(19380, 1526.9962, -1185.2165, 28.0583, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[34], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[35] = CreateDynamicObject(19380, 1526.9962, -1194.8354, 27.9683, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[35], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[36] = CreateDynamicObject(19380, 1527.0576, -1194.7467, 35.5484, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[36], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[37] = CreateDynamicObject(19380, 1527.0576, -1185.1269, 35.5484, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[37], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[38] = CreateDynamicObject(19380, 1527.0576, -1177.3864, 35.5484, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[38], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[39] = CreateDynamicObject(19380, 1531.7059, -1199.6844, 27.9484, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[39], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[40] = CreateDynamicObject(19380, 1541.3261, -1199.6844, 27.9484, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[40], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[41] = CreateDynamicObject(19380, 1550.9559, -1199.6844, 27.9484, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[41], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[42] = CreateDynamicObject(19380, 1555.7468, -1199.6345, 27.9484, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[42], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[43] = CreateDynamicObject(19380, 1555.7468, -1199.6345, 35.5383, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[43], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[44] = CreateDynamicObject(19380, 1546.1274, -1199.6345, 35.5383, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[44], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[45] = CreateDynamicObject(19380, 1536.5079, -1199.6345, 35.5383, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[45], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[46] = CreateDynamicObject(19380, 1531.7264, -1199.5943, 35.5383, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[46], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[47] = CreateDynamicObject(19544, 1558.2431, -1192.1562, 40.7639, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //Plane62_5x15Sand1
    SetDynamicObjectMaterial(LotericObject[47], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[48] = CreateDynamicObject(19544, 1558.2431, -1180.0854, 40.7639, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //Plane62_5x15Sand1
    SetDynamicObjectMaterial(LotericObject[48], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[49] = CreateDynamicObject(19380, 1550.9555, -1172.6054, 35.5783, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[49], 0, 5710, "cemetery_law", "brickgrey", 0xFFFFFFFF);
    LotericObject[50] = CreateDynamicObject(19380, 1541.3164, -1172.6054, 35.5783, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[50], 0, 5710, "cemetery_law", "brickgrey", 0xFFFFFFFF);
    LotericObject[51] = CreateDynamicObject(19380, 1531.7854, -1172.6054, 35.5783, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[51], 0, 5710, "cemetery_law", "brickgrey", 0xFFFFFFFF);
    LotericObject[52] = CreateDynamicObject(19380, 1560.5644, -1172.6054, 35.5783, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[52], 0, 5710, "cemetery_law", "brickgrey", 0xFFFFFFFF);
    LotericObject[53] = CreateDynamicObject(19380, 1555.8476, -1172.6054, 25.0683, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[53], 0, 5710, "cemetery_law", "brickgrey", 0xFFFFFFFF);
    LotericObject[54] = CreateDynamicObject(19380, 1531.7163, -1172.6054, 25.0683, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[54], 0, 5710, "cemetery_law", "brickgrey", 0xFFFFFFFF);
    LotericObject[55] = CreateDynamicObject(1491, 1545.6789, -1172.5887, 23.0772, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //Gen_doorINT01
    SetDynamicObjectMaterial(LotericObject[55], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    LotericObject[56] = CreateDynamicObject(1491, 1542.6496, -1172.6086, 23.0772, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Gen_doorINT01
    SetDynamicObjectMaterial(LotericObject[56], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    LotericObject[57] = CreateDynamicObject(19325, 1548.9846, -1172.6214, 23.9410, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    LotericObject[58] = CreateDynamicObject(19325, 1548.9846, -1172.6214, 28.0611, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    LotericObject[59] = CreateDynamicObject(19325, 1539.3447, -1172.6214, 23.9410, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    LotericObject[60] = CreateDynamicObject(19325, 1539.3447, -1172.6214, 28.0611, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    LotericObject[61] = CreateDynamicObject(19325, 1539.3447, -1172.6214, 32.1810, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    LotericObject[62] = CreateDynamicObject(19325, 1548.9858, -1172.6214, 32.1810, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    LotericObject[63] = CreateDynamicObject(19464, 1544.0904, -1172.6097, 28.1163, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[63], 0, 5710, "cemetery_law", "brickgrey", 0xFFFFFFFF);
    LotericObject[64] = CreateDynamicObject(640, 1555.5291, -1172.1087, 23.7761, 0.0000, 0.0000, 91.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush2
    LotericObject[65] = CreateDynamicObject(640, 1531.4969, -1172.1180, 23.7761, 0.0000, 0.0000, 91.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush2
    LotericObject[66] = CreateDynamicObject(10244, 1533.8033, -1182.5971, 25.4750, 0.0000, 0.0000, -178.7998, -1, 0, -1, 400.0, 400.0, -1); //vicjump_sfe
    SetDynamicObjectMaterial(LotericObject[66], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[67] = CreateDynamicObject(4735, 1543.9333, -1172.4458, 33.1506, 0.0000, 0.0000, -89.3000, -1, 0, -1, 400.0, 400.0, -1); //billbrdlan2_09
    SetDynamicObjectMaterial(LotericObject[67], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign1", 0xFFFFFFFF);
    LotericObject[68] = CreateDynamicObject(19544, 1558.1632, -1192.1966, 29.0044, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //Plane62_5x15Sand1
    SetDynamicObjectMaterial(LotericObject[68], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[69] = CreateDynamicObject(18075, 1554.1297, -1193.1751, 40.6344, 0.0000, 0.0000, -89.8999, -1, 0, -1, 400.0, 400.0, -1); //lightD
    LotericObject[70] = CreateDynamicObject(3850, 1539.8415, -1184.8873, 29.5062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carshowbann_SFSX
    LotericObject[71] = CreateDynamicObject(3850, 1536.4018, -1184.8868, 29.5062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carshowbann_SFSX
    LotericObject[72] = CreateDynamicObject(3850, 1532.9714, -1184.8868, 29.5062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carshowbann_SFSX
    LotericObject[73] = CreateDynamicObject(3850, 1543.2818, -1184.8873, 29.5062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carshowbann_SFSX
    LotericObject[74] = CreateDynamicObject(3850, 1546.7016, -1184.8873, 29.5062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carshowbann_SFSX
    LotericObject[75] = CreateDynamicObject(3850, 1550.1318, -1184.8873, 29.5062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carshowbann_SFSX
    LotericObject[76] = CreateDynamicObject(3850, 1553.5725, -1184.8873, 29.5062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carshowbann_SFSX
    LotericObject[77] = CreateDynamicObject(3850, 1557.0024, -1184.8873, 29.5062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carshowbann_SFSX
    LotericObject[78] = CreateDynamicObject(3850, 1560.4226, -1184.8873, 29.5062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carshowbann_SFSX
    LotericObject[79] = CreateDynamicObject(18075, 1552.6324, -1192.5097, 28.8827, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    LotericObject[80] = CreateDynamicObject(18075, 1533.4991, -1193.2109, 40.6245, 0.0000, 0.0000, -89.8999, -1, 0, -1, 400.0, 400.0, -1); //lightD
    LotericObject[81] = CreateDynamicObject(18075, 1535.0407, -1192.5097, 28.8827, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    LotericObject[82] = CreateDynamicObject(18075, 1533.4748, -1178.8706, 40.6245, 0.0000, 0.0000, -89.8999, -1, 0, -1, 400.0, 400.0, -1); //lightD
    LotericObject[83] = CreateDynamicObject(18075, 1554.1253, -1178.8347, 40.6245, 0.0000, 0.0000, -89.8999, -1, 0, -1, 400.0, 400.0, -1); //lightD
    LotericObject[84] = CreateDynamicObject(19464, 1531.6026, -1180.4301, 26.0785, 35.0000, 0.0000, 90.9999, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[84], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[85] = CreateDynamicObject(19464, 1536.4428, -1180.3448, 22.6886, 35.0000, 0.0000, 90.9999, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[85], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[86] = CreateDynamicObject(19464, 1529.4698, -1180.4643, 21.3444, 35.0000, 0.0000, 90.9999, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[86], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[87] = CreateDynamicObject(19464, 1536.4941, -1183.3559, 22.6886, 35.0000, 0.0000, 90.9999, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[87], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[88] = CreateDynamicObject(19464, 1532.4710, -1183.4270, 25.5048, 35.0000, 0.0000, 90.9999, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[88], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[89] = CreateDynamicObject(19432, 1527.9017, -1183.4926, 27.0648, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall072
    SetDynamicObjectMaterial(LotericObject[89], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[90] = CreateDynamicObject(19464, 1529.5627, -1183.4776, 21.3518, 35.0000, 0.0000, 90.9999, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[90], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[91] = CreateDynamicObject(19432, 1529.4923, -1183.4926, 27.0648, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall072
    SetDynamicObjectMaterial(LotericObject[91], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[92] = CreateDynamicObject(19432, 1531.0725, -1183.4926, 27.0648, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall072
    SetDynamicObjectMaterial(LotericObject[92], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[93] = CreateDynamicObject(19432, 1529.5112, -1180.4339, 27.4748, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall072
    SetDynamicObjectMaterial(LotericObject[93], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[94] = CreateDynamicObject(19432, 1527.9017, -1183.4926, 24.8148, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall072
    SetDynamicObjectMaterial(LotericObject[94], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[95] = CreateDynamicObject(19432, 1527.9514, -1180.4339, 27.4748, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall072
    SetDynamicObjectMaterial(LotericObject[95], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[96] = CreateDynamicObject(19432, 1527.8813, -1180.4239, 24.6548, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall072
    SetDynamicObjectMaterial(LotericObject[96], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    LotericObject[97] = CreateDynamicObject(2666, 1531.4604, -1181.1101, 23.6716, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[97], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[98] = CreateDynamicObject(2666, 1531.4713, -1182.1500, 23.6716, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[98], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[99] = CreateDynamicObject(2666, 1531.4781, -1182.7999, 23.6716, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[99], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[100] = CreateDynamicObject(2666, 1531.4781, -1182.7999, 24.9067, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[100], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[101] = CreateDynamicObject(2666, 1531.4692, -1181.9992, 24.9067, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[101], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[102] = CreateDynamicObject(2666, 1531.4599, -1181.1292, 24.9067, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[102], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[103] = CreateDynamicObject(2666, 1531.4599, -1181.1292, 26.1266, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[103], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[104] = CreateDynamicObject(2666, 1531.4707, -1182.1595, 26.1266, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[104], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[105] = CreateDynamicObject(2666, 1531.4776, -1182.8094, 26.1266, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[105], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[106] = CreateDynamicObject(2666, 1531.4776, -1182.8094, 27.3367, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[106], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[107] = CreateDynamicObject(2666, 1531.4670, -1181.7696, 27.3367, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[107], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[108] = CreateDynamicObject(2666, 1531.4598, -1181.1395, 27.3367, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[108], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[109] = CreateDynamicObject(2666, 1531.4598, -1181.1395, 28.1366, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[109], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[110] = CreateDynamicObject(2666, 1531.4707, -1182.1397, 28.1366, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[110], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[111] = CreateDynamicObject(2666, 1531.4775, -1182.7998, 28.1366, 0.0000, 0.0000, 90.5998, -1, 0, -1, 400.0, 400.0, -1); //CJ_PIZ_POSTER2
    SetDynamicObjectMaterial(LotericObject[111], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    LotericObject[112] = CreateDynamicObject(19439, 1528.6839, -1186.5096, 22.8819, 8.6998, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall079
    SetDynamicObjectMaterial(LotericObject[112], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[113] = CreateDynamicObject(19325, 1539.4022, -1185.7717, 22.8211, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[113], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[114] = CreateDynamicObject(19325, 1551.2917, -1185.7717, 22.8211, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[114], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[115] = CreateDynamicObject(19325, 1551.2917, -1185.7717, 26.9410, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[115], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[116] = CreateDynamicObject(19380, 1559.3543, -1185.7374, 23.7483, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[116], 0, 5710, "cemetery_law", "brickgrey", 0xFFFFFFFF);
    LotericObject[117] = CreateDynamicObject(19544, 1558.1632, -1192.1966, 29.0545, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //Plane62_5x15Sand1
    SetDynamicObjectMaterial(LotericObject[117], 0, 12853, "cunte_gas01", "sw_floor1", 0xFFFFFFFF);
    LotericObject[118] = CreateDynamicObject(1892, 1544.8380, -1186.0063, 23.0531, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //security_gatsh
    LotericObject[119] = CreateDynamicObject(1892, 1546.4681, -1186.0063, 23.0531, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //security_gatsh
    LotericObject[120] = CreateDynamicObject(1892, 1543.1767, -1186.0063, 23.0531, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //security_gatsh
    LotericObject[121] = CreateDynamicObject(2076, 1544.2580, -1192.0791, 28.2495, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //CJ_MLIGHT10
    LotericObject[122] = CreateDynamicObject(19380, 1531.8841, -1185.7374, 23.7483, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(LotericObject[122], 0, 5710, "cemetery_law", "brickgrey", 0xFFFFFFFF);
    LotericObject[123] = CreateDynamicObject(19329, 1545.3059, -1185.4222, 28.5147, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //7_11_sign04
    SetDynamicObjectMaterial(LotericObject[123], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign1", 0xFFFFFFFF);
    LotericObject[124] = CreateDynamicObject(19443, 1541.1345, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[124], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[125] = CreateDynamicObject(19325, 1557.1848, -1193.6711, 31.1110, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[125], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[126] = CreateDynamicObject(19464, 1542.6289, -1196.5904, 36.6563, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[126], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[127] = CreateDynamicObject(19464, 1551.4206, -1196.6306, 36.6763, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[127], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[128] = CreateDynamicObject(19325, 1557.1745, -1193.6711, 35.2411, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[128], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[129] = CreateDynamicObject(2205, 1555.8791, -1197.2757, 29.0237, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE8_DESK_1
    LotericObject[130] = CreateDynamicObject(19325, 1548.2431, -1193.6711, 31.1110, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[130], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[131] = CreateDynamicObject(19325, 1548.2332, -1193.6711, 35.2411, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[131], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[132] = CreateDynamicObject(19443, 1545.9443, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[132], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[133] = CreateDynamicObject(19443, 1549.1639, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[133], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[134] = CreateDynamicObject(19443, 1547.5539, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[134], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[135] = CreateDynamicObject(19325, 1539.3729, -1193.6711, 31.1110, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[135], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[136] = CreateDynamicObject(19325, 1539.3635, -1193.6711, 35.2411, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[136], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[137] = CreateDynamicObject(19329, 1545.9854, -1193.6740, 34.2149, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //7_11_sign04
    SetDynamicObjectMaterial(LotericObject[137], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign1", 0xFFFFFFFF);
    LotericObject[138] = CreateDynamicObject(19329, 1537.1096, -1193.6740, 34.2149, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //7_11_sign04
    SetDynamicObjectMaterial(LotericObject[138], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign1", 0xFFFFFFFF);
    LotericObject[139] = CreateDynamicObject(19443, 1542.7341, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[139], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[140] = CreateDynamicObject(19329, 1554.9326, -1193.6740, 34.2149, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //7_11_sign04
    SetDynamicObjectMaterial(LotericObject[140], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign1", 0xFFFFFFFF);
    LotericObject[141] = CreateDynamicObject(19464, 1533.7895, -1196.6206, 31.6063, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[141], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[142] = CreateDynamicObject(19443, 1544.3347, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[142], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[143] = CreateDynamicObject(19443, 1560.4144, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[143], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[144] = CreateDynamicObject(19443, 1537.9243, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[144], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[145] = CreateDynamicObject(19443, 1536.3238, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[145], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[146] = CreateDynamicObject(19443, 1550.7741, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[146], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[147] = CreateDynamicObject(19443, 1539.5241, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[147], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[148] = CreateDynamicObject(2169, 1555.8310, -1175.5406, 23.0956, 0.0000, 0.0000, 90.4000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[148], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[149] = CreateDynamicObject(2169, 1555.8448, -1177.4494, 23.0956, 0.0000, 0.0000, 90.4000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[149], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[150] = CreateDynamicObject(2169, 1555.8863, -1183.2801, 23.0956, 0.0000, 0.0000, 90.4000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[150], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[151] = CreateDynamicObject(2169, 1555.8996, -1185.2003, 23.0956, 0.0000, 0.0000, 90.4000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[151], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[152] = CreateDynamicObject(2169, 1555.8734, -1181.3404, 23.0956, 0.0000, 0.0000, 90.4000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[152], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[153] = CreateDynamicObject(2169, 1555.8601, -1179.4001, 23.0956, 0.0000, 0.0000, 90.4000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[153], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[154] = CreateDynamicObject(19325, 1553.6035, -1196.2132, 26.1110, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[154], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[155] = CreateDynamicObject(19325, 1555.6306, -1179.4981, 22.0573, 89.8000, 0.0000, 0.1000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[155], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[156] = CreateDynamicObject(19463, 1552.1098, -1196.1826, 27.2036, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall103
    SetDynamicObjectMaterial(LotericObject[156], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[157] = CreateDynamicObject(19325, 1546.9626, -1196.2132, 26.1110, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[157], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[158] = CreateDynamicObject(19463, 1542.4903, -1196.1826, 27.2036, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall103
    SetDynamicObjectMaterial(LotericObject[158], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[159] = CreateDynamicObject(19325, 1540.3221, -1196.2132, 26.1110, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[159], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[160] = CreateDynamicObject(19325, 1555.6236, -1175.4179, 22.0431, 89.8000, 0.0000, 0.1000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[160], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[161] = CreateDynamicObject(19463, 1535.1712, -1196.1524, 27.2036, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall103
    SetDynamicObjectMaterial(LotericObject[161], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[162] = CreateDynamicObject(19325, 1533.6826, -1196.2132, 26.1110, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[162], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[163] = CreateDynamicObject(1569, 1530.3459, -1199.2086, 22.7453, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //ADAM_V_DOOR
    LotericObject[164] = CreateDynamicObject(19430, 1556.4361, -1180.9746, 23.6770, 0.0000, 0.0000, -91.0998, -1, 0, -1, 400.0, 400.0, -1); //wall070
    SetDynamicObjectMaterial(LotericObject[164], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[165] = CreateDynamicObject(19430, 1556.5656, -1174.1457, 23.6770, 0.0000, 0.0000, -91.0998, -1, 0, -1, 400.0, 400.0, -1); //wall070
    SetDynamicObjectMaterial(LotericObject[165], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[166] = CreateDynamicObject(19430, 1556.5014, -1177.5644, 23.6770, 0.0000, 0.0000, -91.0998, -1, 0, -1, 400.0, 400.0, -1); //wall070
    SetDynamicObjectMaterial(LotericObject[166], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[167] = CreateDynamicObject(2169, 1553.1385, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[167], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[168] = CreateDynamicObject(19464, 1554.7717, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[168], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[169] = CreateDynamicObject(19430, 1556.4016, -1182.7945, 23.6770, 0.0000, 0.0000, -91.0998, -1, 0, -1, 400.0, 400.0, -1); //wall070
    SetDynamicObjectMaterial(LotericObject[169], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[170] = CreateDynamicObject(19464, 1552.5511, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[170], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[171] = CreateDynamicObject(19430, 1556.3708, -1184.4040, 23.6770, 0.0000, 0.0000, -91.0998, -1, 0, -1, 400.0, 400.0, -1); //wall070
    SetDynamicObjectMaterial(LotericObject[171], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[172] = CreateDynamicObject(2169, 1550.9393, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[172], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[173] = CreateDynamicObject(19893, 1555.8231, -1196.4123, 23.5925, 0.0000, 0.0000, 7.1999, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[174] = CreateDynamicObject(19325, 1555.6286, -1183.6457, 22.0848, -89.2998, 4.1999, -176.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    SetDynamicObjectMaterial(LotericObject[174], 0, 2922, "kmb_keypadx", "keypad_glass", 0xFFFFFFFF);
    LotericObject[175] = CreateDynamicObject(19464, 1550.3503, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[175], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[176] = CreateDynamicObject(19464, 1534.9575, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[176], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[177] = CreateDynamicObject(2169, 1548.7381, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[177], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[178] = CreateDynamicObject(19464, 1548.1506, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[178], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[179] = CreateDynamicObject(2169, 1546.5378, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[179], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[180] = CreateDynamicObject(19464, 1545.9500, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[180], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[181] = CreateDynamicObject(2169, 1544.3376, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[181], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[182] = CreateDynamicObject(2169, 1555.3499, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[182], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[183] = CreateDynamicObject(19464, 1543.7496, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[183], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[184] = CreateDynamicObject(2169, 1542.1269, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[184], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[185] = CreateDynamicObject(19464, 1541.5382, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[185], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[186] = CreateDynamicObject(2169, 1539.9165, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[186], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[187] = CreateDynamicObject(19464, 1539.3277, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[187], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[188] = CreateDynamicObject(2169, 1537.7059, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[188], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[189] = CreateDynamicObject(19464, 1537.1275, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[189], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[190] = CreateDynamicObject(2169, 1535.5356, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[190], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[191] = CreateDynamicObject(19789, 1555.7724, -1173.1468, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[191], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[192] = CreateDynamicObject(19464, 1532.7373, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[192], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[193] = CreateDynamicObject(2169, 1533.3349, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[193], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[194] = CreateDynamicObject(19789, 1555.7724, -1174.0666, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[194], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[195] = CreateDynamicObject(19789, 1555.7724, -1174.9964, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[195], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[196] = CreateDynamicObject(2169, 1531.1142, -1196.3288, 22.8057, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE3_DESK_1
    SetDynamicObjectMaterial(LotericObject[196], 0, 1675, "wshxrefhse", "duskyblue_128", 0xFFFFFFFF);
    LotericObject[197] = CreateDynamicObject(19789, 1555.7724, -1175.9063, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[197], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[198] = CreateDynamicObject(19464, 1530.5467, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[198], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[199] = CreateDynamicObject(19789, 1555.7724, -1176.7563, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[199], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[200] = CreateDynamicObject(19789, 1555.7724, -1177.7060, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[200], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[201] = CreateDynamicObject(19789, 1555.7724, -1178.5760, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[201], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[202] = CreateDynamicObject(19789, 1555.7724, -1179.5561, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[202], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[203] = CreateDynamicObject(19789, 1555.7724, -1180.4460, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[203], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[204] = CreateDynamicObject(19464, 1556.8919, -1195.7010, 20.8840, -38.5999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[204], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[205] = CreateDynamicObject(19789, 1555.7724, -1181.3558, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[205], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[206] = CreateDynamicObject(19789, 1555.7724, -1182.0859, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[206], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[207] = CreateDynamicObject(19789, 1555.7724, -1183.0052, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[207], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[208] = CreateDynamicObject(19789, 1555.7724, -1183.8758, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[208], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[209] = CreateDynamicObject(19789, 1555.7724, -1184.5555, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[209], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[210] = CreateDynamicObject(19789, 1555.7724, -1185.1557, 25.3598, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(LotericObject[210], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[211] = CreateDynamicObject(19462, 1556.9561, -1197.7979, 24.1856, 90.4999, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall102
    SetDynamicObjectMaterial(LotericObject[211], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[212] = CreateDynamicObject(19462, 1530.4154, -1197.8597, 24.1602, 87.9000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall102
    SetDynamicObjectMaterial(LotericObject[212], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[213] = CreateDynamicObject(19430, 1556.4698, -1179.2347, 23.6770, 0.0000, 0.0000, -91.0998, -1, 0, -1, 400.0, 400.0, -1); //wall070
    SetDynamicObjectMaterial(LotericObject[213], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(LotericObject[213], 1, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[214] = CreateDynamicObject(1569, 1530.4862, -1199.2086, 22.7453, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //ADAM_V_DOOR
    LotericObject[215] = CreateDynamicObject(19430, 1556.5334, -1175.8852, 23.6770, 0.0000, 0.0000, -91.0998, -1, 0, -1, 400.0, 400.0, -1); //wall070
    SetDynamicObjectMaterial(LotericObject[215], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[216] = CreateDynamicObject(1714, 1555.7497, -1197.2495, 22.7336, 0.0000, 0.0000, 164.8999, -1, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
    LotericObject[217] = CreateDynamicObject(19893, 1553.6334, -1196.4704, 23.5925, 0.0000, 0.0000, -7.0000, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[218] = CreateDynamicObject(19893, 1551.4221, -1196.4305, 23.5925, 0.0000, 0.0000, 33.2000, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[219] = CreateDynamicObject(19893, 1547.1250, -1196.4267, 23.5925, 0.0000, 0.0000, -11.6998, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[220] = CreateDynamicObject(19894, 1544.3055, -1196.3200, 23.5981, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP2
    LotericObject[221] = CreateDynamicObject(19893, 1542.6582, -1196.3834, 23.5781, 0.0000, 0.0000, -18.8999, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[222] = CreateDynamicObject(19893, 1540.3249, -1196.3999, 23.5781, 0.0000, 0.0000, 6.5000, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[223] = CreateDynamicObject(19893, 1538.6018, -1196.4576, 23.5781, 0.0000, 0.0000, -14.3999, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[224] = CreateDynamicObject(1714, 1553.6612, -1197.2651, 22.7336, 0.0000, 0.0000, -179.8999, -1, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
    LotericObject[225] = CreateDynamicObject(1714, 1547.0252, -1197.2685, 22.7336, 0.0000, 0.0000, 164.5000, -1, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
    LotericObject[226] = CreateDynamicObject(1714, 1551.4309, -1197.2685, 22.7336, 0.0000, 0.0000, -169.0998, -1, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
    LotericObject[227] = CreateDynamicObject(1714, 1544.9150, -1197.2602, 22.7336, 0.0000, 0.0000, -170.5998, -1, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
    LotericObject[228] = CreateDynamicObject(1714, 1542.5936, -1197.0809, 22.7336, 0.0000, 0.0000, 172.2998, -1, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
    LotericObject[229] = CreateDynamicObject(1550, 1555.9515, -1199.3569, 23.0585, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //CJ_MONEY_BAG
    LotericObject[230] = CreateDynamicObject(1714, 1540.4499, -1197.1627, 22.7336, 0.0000, 0.0000, -167.3999, -1, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
    LotericObject[231] = CreateDynamicObject(1714, 1538.4062, -1197.2812, 22.7336, 0.0000, 0.0000, 165.5998, -1, 0, -1, 400.0, 400.0, -1); //kb_swivelchair1
    LotericObject[232] = CreateDynamicObject(11706, 1556.4702, -1199.1938, 22.7129, 0.0000, 0.0000, 56.4000, -1, 0, -1, 400.0, 400.0, -1); //SmallWasteBin1
    LotericObject[233] = CreateDynamicObject(1569, 1555.6584, -1174.1820, 22.9946, 0.0000, 0.0000, 90.8000, -1, 0, -1, 400.0, 400.0, -1); //ADAM_V_DOOR
    LotericObject[234] = CreateDynamicObject(19464, 1560.5262, -1179.2077, 31.0951, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[234], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign2", 0xFFFFFFFF);
    LotericObject[235] = CreateDynamicObject(19329, 1555.2648, -1184.4914, 25.8747, 0.0000, 0.0000, 89.9000, -1, 0, -1, 400.0, 400.0, -1); //7_11_sign04
    SetDynamicObjectMaterial(LotericObject[235], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign1", 0xFFFFFFFF);
    LotericObject[236] = CreateDynamicObject(19329, 1555.2524, -1173.8503, 25.8747, 0.0000, 0.0000, 89.9000, -1, 0, -1, 400.0, 400.0, -1); //7_11_sign04
    SetDynamicObjectMaterial(LotericObject[236], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign1", 0xFFFFFFFF);
    LotericObject[237] = CreateDynamicObject(1617, 1526.9199, -1183.2995, 29.1058, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //nt_aircon1_01
    LotericObject[238] = CreateDynamicObject(1617, 1526.9199, -1187.6501, 29.1058, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //nt_aircon1_01
    LotericObject[239] = CreateDynamicObject(1688, 1526.1903, -1181.0197, 24.0149, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //gen_roofbit2
    LotericObject[240] = CreateDynamicObject(2011, 1536.1600, -1186.9061, 22.9531, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //nu_plant2_ofc
    LotericObject[241] = CreateDynamicObject(19940, 1527.2534, -1189.1218, 24.2679, 0.0000, 0.0000, -0.0998, -1, 0, -1, 400.0, 400.0, -1); //MKShelf3
    SetDynamicObjectMaterial(LotericObject[241], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[242] = CreateDynamicObject(1420, 1526.2094, -1183.3559, 22.9778, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //DYN_AIRCON
    LotericObject[243] = CreateDynamicObject(19940, 1527.2496, -1191.0914, 24.2679, 0.0000, 0.0000, -0.0998, -1, 0, -1, 400.0, 400.0, -1); //MKShelf3
    SetDynamicObjectMaterial(LotericObject[243], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[244] = CreateDynamicObject(11706, 1527.3355, -1189.8664, 22.8227, 0.0000, 0.0000, -89.9000, -1, 0, -1, 400.0, 400.0, -1); //SmallWasteBin1
    LotericObject[245] = CreateDynamicObject(2754, 1560.0195, -1187.9721, 23.7749, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //OTB_machine
    LotericObject[246] = CreateDynamicObject(19172, 1532.2795, -1185.8492, 25.5128, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //SAMPPicture1
    SetDynamicObjectMaterial(LotericObject[246], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign2", 0xFFFFFFFF);
    LotericObject[247] = CreateDynamicObject(2754, 1560.0195, -1190.1827, 23.7749, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //OTB_machine
    LotericObject[248] = CreateDynamicObject(1723, 1531.2376, -1187.1656, 22.8575, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //mrk_seating1
    LotericObject[249] = CreateDynamicObject(19426, 1560.5423, -1190.5858, 24.7145, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall066
    SetDynamicObjectMaterialText(LotericObject[249], 0, "Caixas", 90, "Segoe UI", 33, 1, 0xFFFFFFFF, 0x0, 0);
    LotericObject[250] = CreateDynamicObject(19464, 1533.7895, -1196.6206, 36.6563, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[250], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[251] = CreateDynamicObject(2754, 1560.0195, -1192.5427, 23.7749, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //OTB_machine
    LotericObject[252] = CreateDynamicObject(11706, 1560.1988, -1191.3746, 22.8918, 0.0000, 0.0000, -90.8999, -1, 0, -1, 400.0, 400.0, -1); //SmallWasteBin1
    LotericObject[253] = CreateDynamicObject(11706, 1560.2348, -1189.0848, 22.8918, 0.0000, 0.0000, -90.8999, -1, 0, -1, 400.0, 400.0, -1); //SmallWasteBin1
    LotericObject[254] = CreateDynamicObject(1569, 1557.9188, -1199.5754, 22.7178, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //ADAM_V_DOOR
    LotericObject[255] = CreateDynamicObject(2011, 1527.9394, -1186.9061, 22.9531, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //nu_plant2_ofc
    LotericObject[256] = CreateDynamicObject(19440, 1554.5770, -1174.1916, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[256], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[257] = CreateDynamicObject(19940, 1527.2534, -1177.1416, 24.2679, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MKShelf3
    SetDynamicObjectMaterial(LotericObject[257], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[258] = CreateDynamicObject(19440, 1553.0074, -1174.2160, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[258], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[259] = CreateDynamicObject(19440, 1554.6153, -1175.9222, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[259], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[260] = CreateDynamicObject(19440, 1553.0152, -1175.9471, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[260], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[261] = CreateDynamicObject(19440, 1553.0152, -1180.9775, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[261], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[262] = CreateDynamicObject(19440, 1554.6324, -1177.6119, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[262], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[263] = CreateDynamicObject(19440, 1553.0727, -1177.6363, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[263], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[264] = CreateDynamicObject(19440, 1553.0177, -1179.2674, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[264], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[265] = CreateDynamicObject(19440, 1554.5882, -1179.2425, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[265], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[266] = CreateDynamicObject(11711, 1558.6682, -1199.5797, 25.4242, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //ExitSign1
    LotericObject[267] = CreateDynamicObject(19440, 1554.6147, -1180.9527, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[267], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[268] = CreateDynamicObject(19440, 1554.6842, -1182.7612, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[268], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[269] = CreateDynamicObject(19440, 1553.1540, -1182.7851, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[269], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[270] = CreateDynamicObject(19440, 1554.6610, -1184.4410, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[270], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[271] = CreateDynamicObject(19440, 1553.1612, -1184.4643, 21.3570, 0.0000, 0.0000, -89.0999, -1, 0, -1, 400.0, 400.0, -1); //wall080
    SetDynamicObjectMaterial(LotericObject[271], 0, 10810, "ap_build4e", "redwhite_stripe", 0xFFFFFFFF);
    LotericObject[272] = CreateDynamicObject(19357, 1557.4183, -1177.4991, 25.9974, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall005
    SetDynamicObjectMaterial(LotericObject[272], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[273] = CreateDynamicObject(19357, 1557.4183, -1174.2890, 25.9974, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall005
    SetDynamicObjectMaterial(LotericObject[273], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[274] = CreateDynamicObject(1514, 1555.9425, -1185.0540, 24.0091, 0.0000, 0.0000, -90.3000, -1, 0, -1, 400.0, 400.0, -1); //DYN_FF_TILL
    LotericObject[275] = CreateDynamicObject(19357, 1557.4183, -1180.6988, 25.9974, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall005
    SetDynamicObjectMaterial(LotericObject[275], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[276] = CreateDynamicObject(19357, 1557.4183, -1183.9094, 25.9974, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall005
    SetDynamicObjectMaterial(LotericObject[276], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[277] = CreateDynamicObject(19357, 1560.8784, -1183.9094, 25.9974, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall005
    SetDynamicObjectMaterial(LotericObject[277], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[278] = CreateDynamicObject(19357, 1560.8784, -1180.7087, 25.9974, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall005
    SetDynamicObjectMaterial(LotericObject[278], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[279] = CreateDynamicObject(19357, 1560.8784, -1177.4975, 25.9974, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall005
    SetDynamicObjectMaterial(LotericObject[279], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[280] = CreateDynamicObject(19357, 1560.8784, -1174.2961, 25.9974, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall005
    SetDynamicObjectMaterial(LotericObject[280], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    LotericObject[281] = CreateDynamicObject(1514, 1555.9504, -1183.6048, 24.0091, 0.0000, 0.0000, -90.3000, -1, 0, -1, 400.0, 400.0, -1); //DYN_FF_TILL
    LotericObject[282] = CreateDynamicObject(1514, 1555.9593, -1181.8441, 24.0091, 0.0000, 0.0000, -90.3000, -1, 0, -1, 400.0, 400.0, -1); //DYN_FF_TILL
    LotericObject[283] = CreateDynamicObject(1514, 1555.9687, -1180.0942, 24.0091, 0.0000, 0.0000, -90.3000, -1, 0, -1, 400.0, 400.0, -1); //DYN_FF_TILL
    LotericObject[284] = CreateDynamicObject(1514, 1555.9780, -1178.3841, 24.0091, 0.0000, 0.0000, -90.3000, -1, 0, -1, 400.0, 400.0, -1); //DYN_FF_TILL
    LotericObject[285] = CreateDynamicObject(1514, 1555.9865, -1176.7137, 24.0091, 0.0000, 0.0000, -90.3000, -1, 0, -1, 400.0, 400.0, -1); //DYN_FF_TILL
    LotericObject[286] = CreateDynamicObject(1514, 1555.9951, -1175.0233, 24.0091, 0.0000, 0.0000, -90.3000, -1, 0, -1, 400.0, 400.0, -1); //DYN_FF_TILL
    LotericObject[287] = CreateDynamicObject(1671, 1556.7116, -1185.0617, 23.5505, 0.0000, 0.0000, -92.1998, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[288] = CreateDynamicObject(1671, 1556.7641, -1183.6927, 23.5505, 0.0000, 0.0000, -92.1998, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[289] = CreateDynamicObject(1671, 1556.8347, -1181.8437, 23.5505, 0.0000, 0.0000, -88.2998, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[290] = CreateDynamicObject(1671, 1556.7834, -1180.1043, 23.5505, 0.0000, 0.0000, -88.2998, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[291] = CreateDynamicObject(1671, 1556.7712, -1178.3438, 23.5505, 0.0000, 0.0000, -88.2998, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[292] = CreateDynamicObject(1671, 1556.8138, -1176.7423, 23.5505, 0.0000, 0.0000, -88.2998, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[293] = CreateDynamicObject(1671, 1556.7646, -1175.0727, 23.5505, 0.0000, 0.0000, -88.2998, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[294] = CreateDynamicObject(1280, 1526.6279, -1191.4033, 23.1462, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //parkbench1
    LotericObject[295] = CreateDynamicObject(1280, 1526.6279, -1194.9846, 23.1163, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //parkbench1
    LotericObject[296] = CreateDynamicObject(1280, 1526.6279, -1198.3557, 23.1263, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //parkbench1
    LotericObject[297] = CreateDynamicObject(2754, 1527.5791, -1179.3106, 23.9810, 0.0000, 0.0000, -179.1999, -1, 0, -1, 400.0, 400.0, -1); //OTB_machine
    LotericObject[298] = CreateDynamicObject(19786, 1554.4781, -1196.1938, 27.1464, 0.0000, 0.0000, -179.9001, -1, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
    LotericObject[299] = CreateDynamicObject(19328, 1526.8819, -1193.5924, 27.2486, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(LotericObject[299], 0, 1530, "tags_lavagos", "vagos", 0xFFFFFFFF);
    LotericObject[300] = CreateDynamicObject(19786, 1533.0562, -1196.1306, 27.1464, 0.0000, 0.0000, -179.9001, -1, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
    LotericObject[301] = CreateDynamicObject(19786, 1543.8172, -1196.1112, 27.1464, 0.0000, 0.0000, -179.9001, -1, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
    LotericObject[302] = CreateDynamicObject(2754, 1532.9970, -1173.1540, 23.9810, 0.0000, 0.0000, 90.4000, -1, 0, -1, 400.0, 400.0, -1); //OTB_machine
    LotericObject[303] = CreateDynamicObject(2754, 1535.8770, -1173.1336, 23.9810, 0.0000, 0.0000, 90.4000, -1, 0, -1, 400.0, 400.0, -1); //OTB_machine
    LotericObject[304] = CreateDynamicObject(19940, 1527.2534, -1175.2813, 24.2679, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MKShelf3
    SetDynamicObjectMaterial(LotericObject[304], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[305] = CreateDynamicObject(19328, 1527.1424, -1175.7423, 25.7486, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(LotericObject[305], 0, 16434, "des_stwnsigns1", "des_banksign", 0xFFFFFFFF);
    LotericObject[306] = CreateDynamicObject(19940, 1530.2646, -1172.8750, 24.2679, 0.0000, 0.0000, -89.4000, -1, 0, -1, 400.0, 400.0, -1); //MKShelf3
    SetDynamicObjectMaterial(LotericObject[306], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[307] = CreateDynamicObject(19940, 1527.2534, -1173.6606, 24.2679, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //MKShelf3
    SetDynamicObjectMaterial(LotericObject[307], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[308] = CreateDynamicObject(19940, 1528.4150, -1172.8941, 24.2679, 0.0000, 0.0000, -89.4000, -1, 0, -1, 400.0, 400.0, -1); //MKShelf3
    SetDynamicObjectMaterial(LotericObject[308], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[309] = CreateDynamicObject(19426, 1549.2492, -1196.8476, 27.1364, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall066
    SetDynamicObjectMaterial(LotericObject[309], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[310] = CreateDynamicObject(19426, 1538.5373, -1196.8476, 27.1364, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall066
    SetDynamicObjectMaterial(LotericObject[310], 0, 14650, "ab_trukstpc", "mp_CJ_WOOD5", 0xFFFFFFFF);
    LotericObject[311] = CreateDynamicObject(19172, 1532.4685, -1180.2561, 25.6145, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //SAMPPicture1
    SetDynamicObjectMaterial(LotericObject[311], 0, 4682, "dtbuil1_lan2", "LAInside_Tracksign2", 0xFFFFFFFF);
    LotericObject[312] = CreateDynamicObject(638, 1532.4150, -1179.8934, 23.8288, 0.0000, 0.0000, -89.9999, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
    LotericObject[313] = CreateDynamicObject(11706, 1527.4295, -1173.0426, 23.0774, 0.0000, 0.0000, 46.2999, -1, 0, -1, 400.0, 400.0, -1); //SmallWasteBin1
    LotericObject[314] = CreateDynamicObject(11706, 1529.6461, -1180.0373, 23.0557, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //SmallWasteBin1
    LotericObject[315] = CreateDynamicObject(11706, 1534.5361, -1173.0061, 23.0557, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //SmallWasteBin1
    LotericObject[316] = CreateDynamicObject(19443, 1534.7231, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[316], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[317] = CreateDynamicObject(19464, 1542.6289, -1196.5904, 31.6063, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[317], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[318] = CreateDynamicObject(19443, 1557.1927, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[318], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[319] = CreateDynamicObject(19443, 1553.9931, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[319], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[320] = CreateDynamicObject(19443, 1558.7932, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[320], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[321] = CreateDynamicObject(19443, 1552.3850, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[321], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[322] = CreateDynamicObject(19464, 1551.4206, -1196.6306, 31.5764, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall104
    SetDynamicObjectMaterial(LotericObject[322], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[323] = CreateDynamicObject(19443, 1555.5832, -1193.7054, 37.4842, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall083
    SetDynamicObjectMaterial(LotericObject[323], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    LotericObject[324] = CreateDynamicObject(2257, 1556.1617, -1199.4923, 31.9972, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //Frame_Clip_4
    LotericObject[325] = CreateDynamicObject(1671, 1557.2270, -1196.1534, 29.4867, 0.0000, 0.0000, -35.2000, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[326] = CreateDynamicObject(1671, 1555.8426, -1196.2447, 29.4867, 0.0000, 0.0000, 34.6999, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[327] = CreateDynamicObject(19999, 1556.6091, -1198.1585, 29.0351, 0.0000, 0.0000, -168.6997, -1, 0, -1, 400.0, 400.0, -1); //CutsceneChair2
    LotericObject[328] = CreateDynamicObject(2608, 1560.3099, -1196.6424, 30.6235, 0.0000, 0.0000, -91.2998, -1, 0, -1, 400.0, 400.0, -1); //POLCE_SHELF
    LotericObject[329] = CreateDynamicObject(19893, 1556.6314, -1197.5042, 29.9587, 0.0000, 0.0000, -2.5000, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[330] = CreateDynamicObject(2011, 1560.1997, -1194.0794, 29.0478, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //nu_plant2_ofc
    LotericObject[331] = CreateDynamicObject(1808, 1527.6677, -1192.5147, 22.8337, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //CJ_WATERCOOLER2
    LotericObject[332] = CreateDynamicObject(1704, 1552.0780, -1198.2929, 29.0422, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_chair03
    LotericObject[333] = CreateDynamicObject(1808, 1560.2136, -1189.7219, 29.0461, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //CJ_WATERCOOLER2
    LotericObject[334] = CreateDynamicObject(1704, 1552.1021, -1196.3033, 29.0422, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_chair03
    LotericObject[335] = CreateDynamicObject(2205, 1549.0683, -1197.2757, 29.0237, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE8_DESK_1
    LotericObject[336] = CreateDynamicObject(19999, 1549.9290, -1196.6082, 29.0450, 0.0000, 0.0000, -98.8998, -1, 0, -1, 400.0, 400.0, -1); //CutsceneChair2
    LotericObject[337] = CreateDynamicObject(19893, 1549.2843, -1196.5642, 29.9587, 0.0000, 0.0000, 84.5998, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[338] = CreateDynamicObject(2011, 1551.9494, -1199.0205, 29.0277, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //nu_plant2_ofc
    LotericObject[339] = CreateDynamicObject(19786, 1551.2851, -1196.6444, 31.4848, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
    LotericObject[340] = CreateDynamicObject(2283, 1551.5870, -1196.8114, 31.6550, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //Frame_Thick_3
    LotericObject[341] = CreateDynamicObject(2256, 1546.8382, -1199.5101, 32.3390, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //Frame_Clip_3
    LotericObject[342] = CreateDynamicObject(1671, 1548.0620, -1196.6147, 29.4867, 0.0000, 0.0000, 101.3999, -1, 0, -1, 400.0, 400.0, -1); //swivelchair_A
    LotericObject[343] = CreateDynamicObject(1704, 1547.0085, -1199.0368, 28.9622, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_chair03
    LotericObject[344] = CreateDynamicObject(2855, 1555.8194, -1197.2680, 29.9533, 0.0000, 0.0000, 16.5000, -1, 0, -1, 400.0, 400.0, -1); //gb_bedmags05
    LotericObject[345] = CreateDynamicObject(1704, 1545.1583, -1199.0368, 28.9622, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_chair03
    LotericObject[346] = CreateDynamicObject(1723, 1527.7070, -1197.4947, 29.0142, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //mrk_seating1
    LotericObject[347] = CreateDynamicObject(1723, 1533.0975, -1195.4643, 29.0142, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //mrk_seating1
    LotericObject[348] = CreateDynamicObject(2011, 1543.2274, -1199.0178, 29.0238, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //nu_plant2_ofc
    LotericObject[349] = CreateDynamicObject(11705, 1557.2679, -1197.3150, 29.9356, 0.0000, 0.0000, -29.4999, -1, 0, -1, 400.0, 400.0, -1); //BlackTelephone1
    LotericObject[350] = CreateDynamicObject(11705, 1548.9853, -1197.2723, 29.9655, 0.0000, 0.0000, 110.2998, -1, 0, -1, 400.0, 400.0, -1); //BlackTelephone1
    LotericObject[351] = CreateDynamicObject(2855, 1549.0440, -1195.7712, 29.9533, 0.0000, 0.0000, 134.7998, -1, 0, -1, 400.0, 400.0, -1); //gb_bedmags05
    LotericObject[352] = CreateDynamicObject(2610, 1543.1097, -1198.0262, 29.8815, 0.0000, 0.0000, 91.6999, -1, 0, -1, 400.0, 400.0, -1); //CJ_P_FILEING2
    LotericObject[353] = CreateDynamicObject(2610, 1543.0965, -1197.5765, 29.8815, 0.0000, 0.0000, 91.6999, -1, 0, -1, 400.0, 400.0, -1); //CJ_P_FILEING2
    LotericObject[354] = CreateDynamicObject(2610, 1543.0836, -1197.1367, 29.8815, 0.0000, 0.0000, 91.6999, -1, 0, -1, 400.0, 400.0, -1); //CJ_P_FILEING2
    LotericObject[355] = CreateDynamicObject(2610, 1543.0703, -1196.6865, 29.8815, 0.0000, 0.0000, 91.6999, -1, 0, -1, 400.0, 400.0, -1); //CJ_P_FILEING2
    LotericObject[356] = CreateDynamicObject(2610, 1543.0570, -1196.2365, 29.8815, 0.0000, 0.0000, 91.6999, -1, 0, -1, 400.0, 400.0, -1); //CJ_P_FILEING2
    LotericObject[357] = CreateDynamicObject(2610, 1543.0434, -1195.7867, 29.8815, 0.0000, 0.0000, 91.6999, -1, 0, -1, 400.0, 400.0, -1); //CJ_P_FILEING2
    LotericObject[358] = CreateDynamicObject(2173, 1540.4941, -1196.9261, 29.0543, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE_DESK_3
    LotericObject[359] = CreateDynamicObject(2011, 1543.2274, -1194.8072, 29.0238, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //nu_plant2_ofc
    LotericObject[360] = CreateDynamicObject(19999, 1541.2899, -1196.4399, 29.0450, 0.0000, 0.0000, -98.8998, -1, 0, -1, 400.0, 400.0, -1); //CutsceneChair2
    LotericObject[361] = CreateDynamicObject(19893, 1540.6383, -1196.3868, 29.8575, 0.0000, 0.0000, 82.5000, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    LotericObject[362] = CreateDynamicObject(2011, 1534.2464, -1199.0577, 29.0238, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //nu_plant2_ofc
    LotericObject[363] = CreateDynamicObject(2161, 1533.9111, -1196.7080, 29.0139, 0.0000, 0.0000, 90.3999, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE_UNIT_4
    LotericObject[364] = CreateDynamicObject(2161, 1533.9111, -1196.7080, 30.3339, 0.0000, 0.0000, 90.3999, -1, 0, -1, 400.0, 400.0, -1); //MED_OFFICE_UNIT_4
    LotericObject[365] = CreateDynamicObject(19786, 1537.8447, -1199.5343, 31.4848, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
    LotericObject[366] = CreateDynamicObject(1704, 1536.8973, -1194.2662, 29.0321, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_chair03
    LotericObject[367] = CreateDynamicObject(1704, 1538.6773, -1194.2662, 29.0321, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_chair03
    LotericObject[368] = CreateDynamicObject(638, 1537.7170, -1199.2534, 29.7315, 0.0000, 0.0000, 89.8999, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
    LotericObject[369] = CreateDynamicObject(19172, 1542.5035, -1196.6018, 31.6720, 0.0000, 0.0000, -90.0998, -1, 0, -1, 400.0, 400.0, -1); //SAMPPicture1
    LotericObject[370] = CreateDynamicObject(1827, 1530.4193, -1196.3608, 28.8882, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //man_sdr_tables
    LotericObject[371] = CreateDynamicObject(1704, 1531.8375, -1199.0167, 28.9622, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_chair03
    LotericObject[372] = CreateDynamicObject(1704, 1529.6761, -1199.0167, 28.9622, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_chair03
    LotericObject[373] = CreateDynamicObject(1665, 1540.4051, -1196.9964, 29.8831, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //propashtray1
    LotericObject[374] = CreateDynamicObject(1665, 1530.1832, -1196.1866, 29.3356, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //propashtray1
    LotericObject[375] = CreateDynamicObject(19807, 1540.4730, -1195.8034, 29.9353, 0.0000, 0.0000, 82.9999, -1, 0, -1, 400.0, 400.0, -1); //Telephone1
    LotericObject[376] = CreateDynamicObject(2855, 1530.7700, -1196.2198, 29.2996, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //gb_bedmags05
    LotericObject[377] = CreateDynamicObject(19328, 1530.1928, -1199.4726, 32.2585, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(LotericObject[377], 0, 2942, "kmb_atmx", "kmb_atm_sign", 0xFFFFFFFF);
    return 1;
}