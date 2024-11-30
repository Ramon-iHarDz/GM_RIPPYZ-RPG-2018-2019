#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid){
    RemoveBuildingForPlayer(playerid, 5933, 1281.4375, -1337.9531, 12.3750, 0.25);
    RemoveBuildingForPlayer(playerid, 5809, 1281.4375, -1337.9531, 12.3750, 0.25);
    RemoveBuildingForPlayer(playerid, 5928, 1309.9141, -1330.1328, 25.1875, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1321.5234, -1374.4297, 12.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1292.0000, -1374.2969, 12.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1300.5859, -1374.2969, 12.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 5704, 1309.9141, -1330.1328, 25.1875, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1329.4766, -1374.4297, 12.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1330.6016, -1340.9844, 6.1094, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1326.6953, -1316.0078, 8.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1327.5938, -1333.6719, 6.1094, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1332.0000, -1309.4297, 8.7266, 0.25);
    return 1;
}

hook OnGameModeInit(){
    new asdasdasdsada[517];
    asdasdasdsada[0] = CreateDynamicObject(19545, 1310.3813, -1353.9471, 12.5383, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[0], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[1] = CreateDynamicObject(19545, 1282.7258, -1322.0566, 12.5684, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[1], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[2] = CreateDynamicObject(19545, 1295.3896, -1353.9471, 12.5383, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[2], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[3] = CreateDynamicObject(19545, 1295.3897, -1322.0566, 12.5783, 0.0000, 0.0998, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[3], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[4] = CreateDynamicObject(19545, 1310.3795, -1322.0566, 12.5684, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[4], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[5] = CreateDynamicObject(19545, 1325.3004, -1322.0566, 12.5584, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[5], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[6] = CreateDynamicObject(19545, 1282.8658, -1353.9887, 12.5883, 0.0000, 0.0000, -0.3998, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[6], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[7] = CreateDynamicObject(19545, 1325.3415, -1353.9471, 12.5383, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[7], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[8] = CreateDynamicObject(19464, 1321.1444, -1351.9676, 15.0691, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[8], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[9] = CreateDynamicObject(19377, 1285.6909, -1337.3837, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[9], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[10] = CreateDynamicObject(19377, 1285.6932, -1327.7625, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[10], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[11] = CreateDynamicObject(19377, 1285.6909, -1347.0131, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[11], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[12] = CreateDynamicObject(19377, 1290.4207, -1351.9433, 8.2629, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[12], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[13] = CreateDynamicObject(19377, 1300.0434, -1351.9433, 8.2629, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[13], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[14] = CreateDynamicObject(19377, 1309.6738, -1351.9433, 8.2629, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[14], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[15] = CreateDynamicObject(19377, 1324.0449, -1347.1831, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[15], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[16] = CreateDynamicObject(14411, 1300.4948, -1352.2080, 10.3309, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //carter-stairs04
    SetDynamicObjectMaterial(asdasdasdsada[16], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[17] = CreateDynamicObject(19377, 1319.3044, -1351.9433, 8.2629, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[17], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[18] = CreateDynamicObject(19377, 1324.0449, -1337.5427, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[18], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[19] = CreateDynamicObject(19377, 1324.0449, -1327.9123, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[19], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[20] = CreateDynamicObject(19377, 1324.0449, -1308.6627, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[20], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[21] = CreateDynamicObject(19377, 1324.0449, -1318.2824, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[21], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[22] = CreateDynamicObject(19377, 1309.6831, -1303.7613, 8.2629, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[22], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[23] = CreateDynamicObject(19377, 1319.3155, -1303.7613, 8.2629, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[23], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[24] = CreateDynamicObject(19377, 1300.0639, -1303.7613, 8.2629, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[24], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[25] = CreateDynamicObject(19377, 1285.6932, -1308.5019, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[25], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[26] = CreateDynamicObject(14411, 1309.9858, -1352.3281, 10.3309, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //carter-stairs04
    SetDynamicObjectMaterial(asdasdasdsada[26], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[27] = CreateDynamicObject(19377, 1285.6932, -1318.1319, 8.2629, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[27], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[28] = CreateDynamicObject(19377, 1290.4343, -1308.9218, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[28], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[29] = CreateDynamicObject(19377, 1290.4343, -1319.3615, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[29], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[30] = CreateDynamicObject(19377, 1290.4343, -1329.8609, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[30], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[31] = CreateDynamicObject(19377, 1290.4343, -1340.3509, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[31], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[32] = CreateDynamicObject(19377, 1290.4343, -1346.6903, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[32], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[33] = CreateDynamicObject(19377, 1300.0548, -1346.6903, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[33], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[34] = CreateDynamicObject(19377, 1300.0548, -1336.2097, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[34], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[35] = CreateDynamicObject(19377, 1300.0548, -1325.7285, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[35], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[36] = CreateDynamicObject(19377, 1300.0548, -1315.2486, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[36], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[37] = CreateDynamicObject(19377, 1300.0548, -1308.9176, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[37], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[38] = CreateDynamicObject(19377, 1309.6862, -1308.9176, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[38], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[39] = CreateDynamicObject(19377, 1319.3059, -1308.9176, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[39], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[40] = CreateDynamicObject(19377, 1319.2958, -1319.4095, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[40], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[41] = CreateDynamicObject(19377, 1309.6761, -1319.4095, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[41], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[42] = CreateDynamicObject(19377, 1309.6761, -1329.9112, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[42], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[43] = CreateDynamicObject(19377, 1319.3061, -1329.9112, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[43], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[44] = CreateDynamicObject(19377, 1319.3061, -1340.3913, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[44], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[45] = CreateDynamicObject(19377, 1319.2961, -1346.6922, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[45], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[46] = CreateDynamicObject(19377, 1309.6672, -1346.6921, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[46], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[47] = CreateDynamicObject(19377, 1309.6672, -1339.4798, 13.5729, 0.0000, 90.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[47], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[48] = CreateDynamicObject(19377, 1290.4443, -1303.7613, 8.2629, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[48], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[49] = CreateDynamicObject(3858, 1324.0275, -1344.7121, 16.4836, 0.0000, 0.0000, 134.8999, -1, 0, -1, 450.0, 450.0, -1); //ottosmash1
    asdasdasdsada[50] = CreateDynamicObject(3858, 1324.0521, -1330.1192, 16.4836, 0.0000, 0.0000, 134.8999, -1, 0, -1, 450.0, 450.0, -1); //ottosmash1
    asdasdasdsada[51] = CreateDynamicObject(3858, 1324.0565, -1315.5328, 16.4836, 0.0000, 0.0000, 134.8999, -1, 0, -1, 450.0, 450.0, -1); //ottosmash1
    asdasdasdsada[52] = CreateDynamicObject(3858, 1312.0255, -1303.7181, 16.4836, 0.0000, 0.0000, 44.9999, -1, 0, -1, 450.0, 450.0, -1); //ottosmash1
    asdasdasdsada[53] = CreateDynamicObject(19464, 1321.1444, -1303.7165, 15.0691, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[53], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[54] = CreateDynamicObject(19464, 1324.0322, -1306.5565, 15.0691, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[54], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[55] = CreateDynamicObject(3858, 1297.4370, -1303.6958, 16.4836, 0.0000, 0.0000, 44.9999, -1, 0, -1, 450.0, 450.0, -1); //ottosmash1
    asdasdasdsada[56] = CreateDynamicObject(19464, 1288.5921, -1303.7165, 15.0691, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[56], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[57] = CreateDynamicObject(19464, 1285.6917, -1306.5565, 15.0691, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[57], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[58] = CreateDynamicObject(3858, 1285.6781, -1315.9423, 16.4836, 0.0000, 0.0000, -44.8000, -1, 0, -1, 450.0, 450.0, -1); //ottosmash1
    asdasdasdsada[59] = CreateDynamicObject(3858, 1285.6823, -1330.6060, 16.4836, 0.0000, 0.0000, -45.0000, -1, 0, -1, 450.0, 450.0, -1); //ottosmash1
    asdasdasdsada[60] = CreateDynamicObject(19464, 1285.5810, -1345.2464, 15.0691, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[60], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[61] = CreateDynamicObject(14411, 1285.1314, -1335.1247, 10.3709, 0.0000, 0.0000, 179.6000, -1, 0, -1, 450.0, 450.0, -1); //carter-stairs04
    SetDynamicObjectMaterial(asdasdasdsada[61], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[62] = CreateDynamicObject(19464, 1324.0322, -1349.1062, 15.0691, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[62], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[63] = CreateDynamicObject(3858, 1315.5441, -1351.9433, 16.4836, 0.0000, 0.0000, -135.4002, -1, 0, -1, 450.0, 450.0, -1); //ottosmash1
    asdasdasdsada[64] = CreateDynamicObject(3858, 1295.1468, -1352.0059, 16.4836, 0.0000, 0.0000, -134.9002, -1, 0, -1, 450.0, 450.0, -1); //ottosmash1
    asdasdasdsada[65] = CreateDynamicObject(19464, 1285.6210, -1349.1062, 15.0691, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[65], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[66] = CreateDynamicObject(19464, 1288.4639, -1351.9676, 15.0691, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[66], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[67] = CreateDynamicObject(19444, 1324.0466, -1322.8657, 15.2252, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[67], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[68] = CreateDynamicObject(19444, 1324.0466, -1332.8946, 18.5852, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[68], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[69] = CreateDynamicObject(19444, 1324.0466, -1322.8657, 18.7052, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[69], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[70] = CreateDynamicObject(1491, 1306.7070, -1352.0108, 13.4939, 0.0000, 0.0000, 180.0000, -1, 0, -1, 450.0, 450.0, -1); //Gen_doorINT01
    SetDynamicObjectMaterial(asdasdasdsada[70], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    asdasdasdsada[71] = CreateDynamicObject(1491, 1303.6877, -1352.0208, 13.4939, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Gen_doorINT01
    SetDynamicObjectMaterial(asdasdasdsada[71], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    asdasdasdsada[72] = CreateDynamicObject(19444, 1285.7020, -1323.0538, 14.8951, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[72], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[73] = CreateDynamicObject(19444, 1324.0466, -1332.8946, 15.1352, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[73], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[74] = CreateDynamicObject(19432, 1302.9007, -1351.9971, 14.5609, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[74], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[75] = CreateDynamicObject(19432, 1302.9007, -1351.9971, 17.7809, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[75], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[76] = CreateDynamicObject(19432, 1307.4927, -1351.9971, 15.2309, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[76], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[77] = CreateDynamicObject(19432, 1307.4927, -1351.9971, 17.7908, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[77], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[78] = CreateDynamicObject(19432, 1304.4727, -1351.9971, 17.7408, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[78], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[79] = CreateDynamicObject(19432, 1306.0726, -1351.9971, 17.7308, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[79], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[80] = CreateDynamicObject(19444, 1285.7020, -1323.0538, 18.3052, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[80], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[81] = CreateDynamicObject(970, 1306.5092, -1354.3419, 13.3067, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fencesmallb
    SetDynamicObjectMaterial(asdasdasdsada[81], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[82] = CreateDynamicObject(19791, 1322.8560, -1353.0568, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[82], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[83] = CreateDynamicObject(18075, 1290.2752, -1335.2531, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[84] = CreateDynamicObject(19432, 1304.8085, -1303.7349, 15.2109, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[84], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[85] = CreateDynamicObject(970, 1302.4089, -1354.3419, 13.3067, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fencesmallb
    SetDynamicObjectMaterial(asdasdasdsada[85], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[86] = CreateDynamicObject(970, 1307.7994, -1354.3419, 13.3067, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fencesmallb
    SetDynamicObjectMaterial(asdasdasdsada[86], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[87] = CreateDynamicObject(19432, 1304.8085, -1303.7349, 18.6609, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[87], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[88] = CreateDynamicObject(19464, 1321.1444, -1351.9676, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[88], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[89] = CreateDynamicObject(19464, 1321.1444, -1303.6668, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[89], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[90] = CreateDynamicObject(19464, 1288.5948, -1303.7169, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[90], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[91] = CreateDynamicObject(19464, 1315.2545, -1351.9676, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[91], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[92] = CreateDynamicObject(19464, 1309.3453, -1351.9676, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[92], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[93] = CreateDynamicObject(19464, 1303.4053, -1351.9676, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[93], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[94] = CreateDynamicObject(19464, 1297.5056, -1351.9676, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[94], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[95] = CreateDynamicObject(19464, 1291.6772, -1351.9676, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[95], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[96] = CreateDynamicObject(19464, 1288.4461, -1351.9876, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[96], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[97] = CreateDynamicObject(19464, 1294.5050, -1303.7169, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[97], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[98] = CreateDynamicObject(19464, 1285.5949, -1349.0083, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[98], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[99] = CreateDynamicObject(19464, 1300.3248, -1303.7169, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[99], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[100] = CreateDynamicObject(19464, 1306.2341, -1303.7169, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[100], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[101] = CreateDynamicObject(19464, 1312.1386, -1303.6868, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[101], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[102] = CreateDynamicObject(19464, 1285.5949, -1343.0882, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[102], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[103] = CreateDynamicObject(19464, 1285.5949, -1337.1583, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[103], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[104] = CreateDynamicObject(19464, 1317.2480, -1303.7169, 20.1391, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[104], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[105] = CreateDynamicObject(19464, 1285.5949, -1331.2181, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[105], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[106] = CreateDynamicObject(19464, 1324.0457, -1349.0083, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[106], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[107] = CreateDynamicObject(19464, 1285.5949, -1325.2780, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[107], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[108] = CreateDynamicObject(19464, 1285.5949, -1319.3679, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[108], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[109] = CreateDynamicObject(19464, 1285.5949, -1313.4377, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[109], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[110] = CreateDynamicObject(19464, 1285.5949, -1307.5169, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[110], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[111] = CreateDynamicObject(19464, 1285.5349, -1306.5867, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[111], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[112] = CreateDynamicObject(19464, 1324.0557, -1343.0980, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[112], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[113] = CreateDynamicObject(19464, 1324.0557, -1337.1578, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[113], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[114] = CreateDynamicObject(19464, 1324.0557, -1331.2280, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[114], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[115] = CreateDynamicObject(19464, 1324.0557, -1325.3581, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[115], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[116] = CreateDynamicObject(19464, 1324.0557, -1319.4488, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[116], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[117] = CreateDynamicObject(19464, 1324.0557, -1313.5787, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[117], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[118] = CreateDynamicObject(19464, 1324.0557, -1307.6384, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[118], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[119] = CreateDynamicObject(19464, 1324.0758, -1306.7181, 20.1391, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall104
    SetDynamicObjectMaterial(asdasdasdsada[119], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[120] = CreateDynamicObject(19544, 1305.4010, -1326.7978, 22.7378, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Sand1
    SetDynamicObjectMaterial(asdasdasdsada[120], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[121] = CreateDynamicObject(14411, 1284.9556, -1344.1027, 10.3709, 0.0000, 0.0000, -1.0999, -1, 0, -1, 450.0, 450.0, -1); //carter-stairs04
    SetDynamicObjectMaterial(asdasdasdsada[121], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[122] = CreateDynamicObject(19544, 1290.4416, -1326.7978, 22.7378, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Sand1
    SetDynamicObjectMaterial(asdasdasdsada[122], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[123] = CreateDynamicObject(19544, 1320.3598, -1326.7978, 22.7378, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Sand1
    SetDynamicObjectMaterial(asdasdasdsada[123], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[124] = CreateDynamicObject(19791, 1312.8471, -1353.0568, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[124], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[125] = CreateDynamicObject(19444, 1285.7020, -1337.1348, 14.8951, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[125], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[126] = CreateDynamicObject(19444, 1285.7020, -1337.1348, 18.3152, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[126], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[127] = CreateDynamicObject(970, 1282.9465, -1338.9500, 13.3067, 0.0000, 0.0000, -90.6999, -1, 0, -1, 450.0, 450.0, -1); //fencesmallb
    SetDynamicObjectMaterial(asdasdasdsada[127], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[128] = CreateDynamicObject(970, 1282.9051, -1342.3405, 13.3067, 0.0000, 0.0000, -90.6999, -1, 0, -1, 450.0, 450.0, -1); //fencesmallb
    SetDynamicObjectMaterial(asdasdasdsada[128], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[129] = CreateDynamicObject(19377, 1305.1032, -1354.3535, 8.2530, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[129], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[130] = CreateDynamicObject(19791, 1302.8677, -1353.0568, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[130], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[131] = CreateDynamicObject(19791, 1287.9965, -1353.0568, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[131], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[132] = CreateDynamicObject(19377, 1282.9603, -1339.6326, 8.2530, 0.0000, 0.0000, -0.3999, -1, 0, -1, 450.0, 450.0, -1); //wall025
    SetDynamicObjectMaterial(asdasdasdsada[132], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[133] = CreateDynamicObject(19791, 1295.8367, -1352.8967, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[133], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[134] = CreateDynamicObject(19791, 1322.8560, -1343.0770, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[134], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[135] = CreateDynamicObject(19791, 1322.8560, -1333.0576, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[135], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[136] = CreateDynamicObject(19791, 1322.8560, -1323.0682, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[136], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[137] = CreateDynamicObject(19791, 1322.8560, -1313.0584, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[137], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[138] = CreateDynamicObject(19791, 1322.8560, -1300.5577, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[138], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[139] = CreateDynamicObject(19791, 1322.7659, -1307.0375, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[139], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[140] = CreateDynamicObject(19791, 1312.8471, -1343.0286, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[140], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[141] = CreateDynamicObject(19791, 1305.1357, -1344.4252, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[141], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[142] = CreateDynamicObject(970, 1282.9711, -1336.9299, 13.3067, 0.0000, 0.0000, -90.6999, -1, 0, -1, 450.0, 450.0, -1); //fencesmallb
    SetDynamicObjectMaterial(asdasdasdsada[142], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    asdasdasdsada[143] = CreateDynamicObject(19791, 1288.0184, -1343.0286, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[143], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[144] = CreateDynamicObject(19791, 1295.7681, -1343.0286, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[144], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[145] = CreateDynamicObject(19791, 1312.8757, -1300.5577, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[145], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[146] = CreateDynamicObject(19791, 1312.8757, -1310.4968, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[146], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[147] = CreateDynamicObject(19791, 1312.8757, -1320.4755, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[147], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[148] = CreateDynamicObject(19791, 1312.8757, -1330.3848, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[148], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[149] = CreateDynamicObject(19791, 1312.8757, -1335.1248, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[149], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[150] = CreateDynamicObject(19791, 1302.9470, -1300.5577, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[150], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[151] = CreateDynamicObject(19791, 1292.9569, -1300.6678, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[151], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[152] = CreateDynamicObject(19791, 1287.9468, -1300.5577, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[152], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[153] = CreateDynamicObject(19791, 1287.9468, -1310.5468, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[153], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[154] = CreateDynamicObject(19791, 1287.9468, -1320.4755, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[154], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[155] = CreateDynamicObject(19791, 1287.9468, -1330.4552, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[155], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[156] = CreateDynamicObject(19791, 1288.1270, -1335.1555, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[156], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[157] = CreateDynamicObject(19791, 1298.0157, -1335.1555, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[157], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[158] = CreateDynamicObject(19791, 1305.1357, -1335.1555, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[158], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[159] = CreateDynamicObject(19791, 1305.1357, -1325.2363, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[159], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[160] = CreateDynamicObject(19791, 1305.1357, -1315.2365, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[160], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[161] = CreateDynamicObject(19791, 1305.1357, -1307.3468, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[161], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[162] = CreateDynamicObject(19791, 1296.0054, -1307.3468, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[162], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[163] = CreateDynamicObject(19791, 1296.0054, -1325.5974, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[163], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[164] = CreateDynamicObject(19791, 1296.0054, -1315.7969, 22.7817, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(asdasdasdsada[164], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    asdasdasdsada[165] = CreateDynamicObject(18075, 1290.2835, -1310.6712, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[166] = CreateDynamicObject(1491, 1285.6446, -1338.5227, 13.5339, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //Gen_doorINT01
    SetDynamicObjectMaterial(asdasdasdsada[166], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    asdasdasdsada[167] = CreateDynamicObject(18075, 1310.4669, -1310.7017, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[168] = CreateDynamicObject(18075, 1320.0777, -1310.7017, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[169] = CreateDynamicObject(18075, 1319.9276, -1335.2531, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[170] = CreateDynamicObject(18075, 1300.3653, -1310.7017, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[171] = CreateDynamicObject(18075, 1320.0777, -1322.9217, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[172] = CreateDynamicObject(18075, 1310.4473, -1322.9217, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[173] = CreateDynamicObject(638, 1302.8448, -1354.7954, 13.1772, 0.0000, 0.0000, 89.7999, -1, 0, -1, 450.0, 450.0, -1); //kb_planter+bush
    asdasdasdsada[174] = CreateDynamicObject(18075, 1300.3566, -1322.9217, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[175] = CreateDynamicObject(18075, 1290.2752, -1322.9217, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[176] = CreateDynamicObject(18075, 1317.1854, -1346.5412, 22.6899, 0.0000, 0.0000, 88.6999, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[177] = CreateDynamicObject(18075, 1300.3764, -1335.2531, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[178] = CreateDynamicObject(18075, 1310.4372, -1335.2531, 22.6899, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[179] = CreateDynamicObject(18075, 1302.8184, -1346.2143, 22.6899, 0.0000, 0.0000, 88.6999, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[180] = CreateDynamicObject(18075, 1290.8902, -1345.9429, 22.6899, 0.0000, 0.0000, 88.6999, -1, 0, -1, 450.0, 450.0, -1); //lightD
    asdasdasdsada[181] = CreateDynamicObject(638, 1282.4908, -1341.7969, 13.2435, 0.0000, 0.0000, -0.5000, -1, 0, -1, 450.0, 450.0, -1); //kb_planter+bush
    asdasdasdsada[182] = CreateDynamicObject(1491, 1285.6646, -1341.5426, 13.5339, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //Gen_doorINT01
    SetDynamicObjectMaterial(asdasdasdsada[182], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    asdasdasdsada[183] = CreateDynamicObject(19444, 1285.5218, -1337.7454, 15.3851, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[183], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[184] = CreateDynamicObject(861, 1282.3013, -1339.6051, 12.4770, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //sand_plant02
    asdasdasdsada[185] = CreateDynamicObject(638, 1282.5286, -1337.4367, 13.2435, 0.0000, 0.0000, -0.5000, -1, 0, -1, 450.0, 450.0, -1); //kb_planter+bush
    asdasdasdsada[186] = CreateDynamicObject(19444, 1285.7220, -1341.3564, 16.8051, 90.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[186], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[187] = CreateDynamicObject(19444, 1285.7220, -1338.6865, 16.7951, 90.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[187], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[188] = CreateDynamicObject(19444, 1285.7020, -1342.3153, 15.3851, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //wall084
    SetDynamicObjectMaterial(asdasdasdsada[188], 0, 14853, "gen_pol_vegas", "grey_carpet_256", 0xFFFFFFFF);
    asdasdasdsada[189] = CreateDynamicObject(984, 1332.6751, -1297.2894, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[190] = CreateDynamicObject(984, 1332.6751, -1310.1003, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[191] = CreateDynamicObject(19121, 1278.4680, -1379.5795, 13.0729, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //BollardLight1
    asdasdasdsada[192] = CreateDynamicObject(984, 1332.6751, -1322.9011, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[193] = CreateDynamicObject(984, 1332.6751, -1335.7031, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[194] = CreateDynamicObject(984, 1332.6751, -1348.5340, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[195] = CreateDynamicObject(984, 1332.6751, -1361.3439, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[196] = CreateDynamicObject(638, 1307.3948, -1354.8115, 13.1772, 0.0000, 0.0000, 89.7999, -1, 0, -1, 450.0, 450.0, -1); //kb_planter+bush
    asdasdasdsada[197] = CreateDynamicObject(984, 1326.2648, -1290.8892, 13.1156, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[198] = CreateDynamicObject(984, 1313.4647, -1290.8892, 13.1156, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[199] = CreateDynamicObject(984, 1300.6538, -1290.8892, 13.1156, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[200] = CreateDynamicObject(984, 1287.8531, -1290.8892, 13.1156, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[201] = CreateDynamicObject(984, 1281.6118, -1290.8892, 13.1156, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[202] = CreateDynamicObject(984, 1275.2609, -1297.2600, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[203] = CreateDynamicObject(861, 1305.1195, -1354.8365, 12.4770, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //sand_plant02
    asdasdasdsada[204] = CreateDynamicObject(984, 1275.2609, -1310.0799, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[205] = CreateDynamicObject(984, 1275.2609, -1322.8696, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[206] = CreateDynamicObject(984, 1275.2609, -1354.7604, 13.1156, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //fenceshit2
    asdasdasdsada[207] = CreateDynamicObject(8843, 1304.8107, -1367.7030, 12.6014, 0.0000, 0.0000, -87.8999, -1, 0, -1, 450.0, 450.0, -1); //arrows01_lvs
    asdasdasdsada[208] = CreateDynamicObject(19432, 1315.5119, -1352.1336, 10.8509, 0.0000, 0.0000, -89.7000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[208], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[209] = CreateDynamicObject(19328, 1315.0698, -1355.5026, 12.5795, -90.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(asdasdasdsada[209], 0, 10778, "airportcpark_sfse", "ws_roadarrow1", 0xFFFFFFFF);
    asdasdasdsada[210] = CreateDynamicObject(19432, 1313.1307, -1352.8436, 10.8409, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[210], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[211] = CreateDynamicObject(19432, 1313.1926, -1354.4522, 10.8409, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[211], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[212] = CreateDynamicObject(19432, 1313.2525, -1356.0109, 10.8409, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[212], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[213] = CreateDynamicObject(19432, 1316.8024, -1352.8428, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[213], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[214] = CreateDynamicObject(19432, 1316.8646, -1354.4409, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[214], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[215] = CreateDynamicObject(19432, 1313.9920, -1352.1413, 10.8509, 0.0000, 0.0000, -89.7000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[215], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[216] = CreateDynamicObject(19432, 1316.9254, -1356.0195, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[216], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[217] = CreateDynamicObject(19432, 1316.9865, -1357.5977, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[217], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[218] = CreateDynamicObject(19432, 1315.9020, -1352.1320, 10.8509, 0.0000, 0.0000, -89.7000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[218], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[219] = CreateDynamicObject(19432, 1313.3193, -1357.7386, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[219], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[220] = CreateDynamicObject(19432, 1317.6628, -1352.1230, 10.8509, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[220], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[221] = CreateDynamicObject(19432, 1313.3109, -1357.5084, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[221], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[222] = CreateDynamicObject(19432, 1320.1687, -1352.8719, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[222], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[223] = CreateDynamicObject(19432, 1319.2636, -1352.1140, 10.8509, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[223], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[224] = CreateDynamicObject(19432, 1320.2293, -1354.4506, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[224], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[225] = CreateDynamicObject(19328, 1318.6002, -1355.5026, 12.5795, -90.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(asdasdasdsada[225], 0, 10778, "airportcpark_sfse", "ws_roadarrow1", 0xFFFFFFFF);
    asdasdasdsada[226] = CreateDynamicObject(19432, 1320.2896, -1355.9986, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[226], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[227] = CreateDynamicObject(19432, 1320.3441, -1357.4689, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[227], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[228] = CreateDynamicObject(19432, 1321.0233, -1352.1140, 10.8509, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[228], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[229] = CreateDynamicObject(19432, 1322.6237, -1352.1140, 10.8509, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[229], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[230] = CreateDynamicObject(19432, 1323.5333, -1352.9019, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[230], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[231] = CreateDynamicObject(19432, 1323.5938, -1354.5015, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[231], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[232] = CreateDynamicObject(19432, 1323.6547, -1356.1008, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[232], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[233] = CreateDynamicObject(19432, 1323.7037, -1357.3422, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[233], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[234] = CreateDynamicObject(19328, 1322.0321, -1355.5026, 12.5795, -90.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(asdasdasdsada[234], 0, 10778, "airportcpark_sfse", "ws_roadarrow1", 0xFFFFFFFF);
    asdasdasdsada[235] = CreateDynamicObject(19432, 1297.4711, -1356.8149, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[235], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[236] = CreateDynamicObject(8843, 1292.1184, -1368.1680, 12.6014, 0.0000, 0.0000, -87.8999, -1, 0, -1, 450.0, 450.0, -1); //arrows01_lvs
    asdasdasdsada[237] = CreateDynamicObject(19432, 1297.5300, -1358.3436, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[237], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[238] = CreateDynamicObject(19432, 1297.3095, -1352.8693, 10.8409, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[238], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[239] = CreateDynamicObject(19432, 1296.4112, -1352.1230, 10.8509, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[239], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[240] = CreateDynamicObject(19432, 1297.3770, -1354.3565, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[240], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[241] = CreateDynamicObject(19432, 1294.8105, -1352.1230, 10.8509, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[241], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[242] = CreateDynamicObject(19432, 1297.4128, -1355.2961, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[242], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[243] = CreateDynamicObject(19432, 1293.9467, -1352.8243, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[243], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[244] = CreateDynamicObject(19432, 1294.0085, -1354.4124, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[244], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[245] = CreateDynamicObject(19432, 1294.0698, -1356.0009, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[245], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[246] = CreateDynamicObject(19432, 1294.1300, -1357.5698, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[246], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[247] = CreateDynamicObject(19432, 1294.1621, -1358.4724, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[247], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[248] = CreateDynamicObject(19432, 1293.0634, -1352.1341, 10.8509, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[248], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[249] = CreateDynamicObject(19328, 1295.7575, -1355.5026, 12.5795, -90.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(asdasdasdsada[249], 0, 10778, "airportcpark_sfse", "ws_roadarrow1", 0xFFFFFFFF);
    asdasdasdsada[250] = CreateDynamicObject(19432, 1291.4635, -1352.1341, 10.8509, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[250], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[251] = CreateDynamicObject(19432, 1290.6771, -1354.4532, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[251], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[252] = CreateDynamicObject(19432, 1290.6164, -1352.8914, 10.8409, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[252], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[253] = CreateDynamicObject(19432, 1290.7376, -1356.0321, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[253], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[254] = CreateDynamicObject(19432, 1290.7961, -1357.5507, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[254], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[255] = CreateDynamicObject(19432, 1290.8442, -1358.5993, 10.8309, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[255], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[256] = CreateDynamicObject(19328, 1292.3769, -1355.5026, 12.5795, -90.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(asdasdasdsada[256], 0, 10778, "airportcpark_sfse", "ws_roadarrow1", 0xFFFFFFFF);
    asdasdasdsada[257] = CreateDynamicObject(19432, 1289.7214, -1352.1890, 10.8509, 0.0000, 0.0000, -89.7000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[257], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[258] = CreateDynamicObject(19432, 1288.1203, -1352.2031, 10.8509, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[258], 0, 14668, "711c", "cj_white_wall2", 0xFFFFFFFF);
    asdasdasdsada[259] = CreateDynamicObject(19432, 1287.2530, -1352.8793, 10.8409, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[259], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[260] = CreateDynamicObject(19432, 1287.3137, -1354.4683, 10.8409, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[260], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[261] = CreateDynamicObject(19432, 1287.3750, -1356.0568, 10.8409, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[261], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[262] = CreateDynamicObject(19432, 1287.4357, -1357.6458, 10.8409, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[262], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[263] = CreateDynamicObject(19432, 1287.4564, -1358.7290, 10.8609, 0.0000, 0.0000, 2.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[263], 0, 10763, "airport1_sfse", "yellowscum64", 0xFFFFFFFF);
    asdasdasdsada[264] = CreateDynamicObject(19328, 1289.0662, -1355.5026, 12.5895, -90.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(asdasdasdsada[264], 0, 10778, "airportcpark_sfse", "ws_roadarrow1", 0xFFFFFFFF);
    asdasdasdsada[265] = CreateDynamicObject(10281, 1305.3740, -1353.1391, 19.4994, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //michsign_sfe
    asdasdasdsada[266] = CreateDynamicObject(10281, 1284.6458, -1340.2187, 19.0389, 0.0000, 0.0000, -90.4999, -1, 0, -1, 450.0, 450.0, -1); //michsign_sfe
    asdasdasdsada[267] = CreateDynamicObject(11711, 1305.1938, -1351.8957, 16.3921, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //ExitSign1
    asdasdasdsada[268] = CreateDynamicObject(11711, 1285.8032, -1340.0250, 16.3421, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //ExitSign1
    asdasdasdsada[269] = CreateDynamicObject(18070, 1305.0135, -1308.4830, 14.0918, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //GAP_COUNTER
    SetDynamicObjectMaterial(asdasdasdsada[269], 0, 6094, "canalsg_law", "ws_sheetwood_clean", 0xFFFFFFFF);
    asdasdasdsada[270] = CreateDynamicObject(3812, 1304.6789, -1304.0758, 19.2581, 0.0000, 0.0000, -94.0000, -1, 0, -1, 450.0, 450.0, -1); //sfxref_aircon13
    asdasdasdsada[271] = CreateDynamicObject(1514, 1305.6809, -1310.2515, 14.8560, 0.0000, 0.0000, 0.1999, -1, 0, -1, 450.0, 450.0, -1); //DYN_FF_TILL
    asdasdasdsada[272] = CreateDynamicObject(19328, 1323.9439, -1322.8737, 15.9752, 0.0000, 0.0000, -90.0000, -1, 0, -1, 450.0, 450.0, -1); //7_11_sign03
    SetDynamicObjectMaterial(asdasdasdsada[272], 0, 10281, "michgar", "michelle_car3", 0xFFFFFFFF);
    asdasdasdsada[273] = CreateDynamicObject(2059, 1307.9036, -1308.4162, 14.6184, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //CJ_GUNSTUFF1
    asdasdasdsada[274] = CreateDynamicObject(3812, 1305.1090, -1351.5974, 19.5281, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //sfxref_aircon13
    asdasdasdsada[275] = CreateDynamicObject(1688, 1321.5323, -1302.6456, 13.5534, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //gen_roofbit2
    asdasdasdsada[276] = CreateDynamicObject(1420, 1288.1447, -1303.1605, 12.5131, 0.0000, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //DYN_AIRCON
    asdasdasdsada[277] = CreateDynamicObject(2257, 1285.7518, -1344.8591, 16.8729, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //Frame_Clip_4
    asdasdasdsada[278] = CreateDynamicObject(19786, 1322.9705, -1351.0374, 17.9734, 12.2999, 0.0000, -140.5000, -1, 0, -1, 450.0, 450.0, -1); //LCDTVBig1
    asdasdasdsada[279] = CreateDynamicObject(1227, 1324.9068, -1305.0526, 13.4062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //dump1
    asdasdasdsada[280] = CreateDynamicObject(1227, 1324.9068, -1307.6724, 13.4062, 0.0000, 0.0000, 90.0000, -1, 0, -1, 450.0, 450.0, -1); //dump1
    asdasdasdsada[281] = CreateDynamicObject(19432, 1314.3063, -1310.0979, 11.9909, 0.0000, 0.0000, 139.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[281], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[282] = CreateDynamicObject(11706, 1309.0021, -1307.7885, 13.6573, 0.0000, 0.0000, 90.4999, -1, 0, -1, 450.0, 450.0, -1); //SmallWasteBin1
    asdasdasdsada[283] = CreateDynamicObject(19432, 1315.2603, -1308.9929, 11.9909, 0.0000, 0.0000, 139.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[283], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[284] = CreateDynamicObject(19432, 1313.2807, -1311.2861, 11.9909, 0.0000, 0.0000, 139.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[284], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[285] = CreateDynamicObject(19432, 1313.0250, -1311.5812, 11.9909, 0.0000, 0.0000, 139.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[285], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[286] = CreateDynamicObject(19432, 1313.0050, -1312.7080, 11.9909, 0.0000, 0.0000, 46.3999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[286], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[287] = CreateDynamicObject(19432, 1313.5988, -1313.2742, 11.9909, 0.0000, 0.0000, 46.3999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[287], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[288] = CreateDynamicObject(19432, 1314.7049, -1313.3231, 11.9909, 0.0000, 0.0000, 139.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[288], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[289] = CreateDynamicObject(19432, 1315.7039, -1312.1651, 11.9909, 0.0000, 0.0000, 139.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[289], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[290] = CreateDynamicObject(19432, 1316.7298, -1310.9769, 11.9909, 0.0000, 0.0000, 139.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[290], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[291] = CreateDynamicObject(19432, 1316.3436, -1309.0173, 11.9909, 0.0000, 0.0000, 46.9999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[291], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[292] = CreateDynamicObject(19432, 1316.9801, -1309.6107, 11.9909, 0.0000, 0.0000, 46.9999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[292], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[293] = CreateDynamicObject(19432, 1316.9736, -1310.6879, 11.9909, 0.0000, 0.0000, -41.6000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[293], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[294] = CreateDynamicObject(19432, 1314.0777, -1318.1312, 11.9309, 0.0000, 0.0000, 46.7000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[294], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[295] = CreateDynamicObject(19432, 1317.7374, -1313.9555, 11.9309, 0.0000, 0.0000, 46.7000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[295], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[296] = CreateDynamicObject(19432, 1316.9595, -1313.2210, 11.9309, 0.0000, 0.0000, 46.7000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[296], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[297] = CreateDynamicObject(19432, 1313.1356, -1316.2480, 11.9208, 0.0000, 0.0000, -41.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[297], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[298] = CreateDynamicObject(19432, 1313.1834, -1317.2875, 11.9309, 0.0000, 0.0000, 46.7000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[298], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[299] = CreateDynamicObject(19432, 1314.1217, -1315.1175, 11.9208, 0.0000, 0.0000, -41.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[299], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[300] = CreateDynamicObject(19432, 1313.9953, -1321.6916, 11.9309, 0.0000, 0.0000, 45.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[300], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[301] = CreateDynamicObject(19432, 1315.1536, -1313.9344, 11.9208, 0.0000, 0.0000, -41.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[301], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[302] = CreateDynamicObject(19432, 1314.7601, -1322.4541, 11.9309, 0.0000, 0.0000, 45.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[302], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[303] = CreateDynamicObject(19432, 1315.8052, -1322.4943, 11.9309, 0.0000, 0.0000, -44.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[303], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[304] = CreateDynamicObject(19432, 1315.8386, -1313.1511, 11.9208, 0.0000, 0.0000, -41.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[304], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[305] = CreateDynamicObject(19432, 1316.9022, -1321.3580, 11.9309, 0.0000, 0.0000, -44.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[305], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[306] = CreateDynamicObject(19432, 1317.7258, -1315.0495, 11.9208, 0.0000, 0.0000, -41.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[306], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[307] = CreateDynamicObject(19432, 1317.9998, -1320.2216, 11.9309, 0.0000, 0.0000, -44.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[307], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[308] = CreateDynamicObject(19432, 1316.6873, -1316.2402, 11.9208, 0.0000, 0.0000, -41.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[308], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[309] = CreateDynamicObject(19432, 1318.7089, -1319.4875, 11.9309, 0.0000, 0.0000, -44.0000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[309], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[310] = CreateDynamicObject(19432, 1318.6961, -1318.4488, 11.9309, 0.0000, 0.0000, -133.8999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[310], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[311] = CreateDynamicObject(19432, 1317.8604, -1317.6446, 11.9309, 0.0000, 0.0000, -133.8999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[311], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[312] = CreateDynamicObject(19432, 1315.6813, -1317.3933, 11.9208, 0.0000, 0.0000, -41.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[312], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[313] = CreateDynamicObject(19432, 1316.7396, -1317.5534, 11.9309, 0.0000, 0.0000, 136.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[313], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[314] = CreateDynamicObject(19432, 1315.6446, -1318.7196, 11.9309, 0.0000, 0.0000, 136.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[314], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[315] = CreateDynamicObject(19432, 1314.5422, -1319.8925, 11.9309, 0.0000, 0.0000, 136.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[315], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[316] = CreateDynamicObject(19432, 1313.8925, -1320.5850, 11.9309, 0.0000, 0.0000, 136.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[316], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[317] = CreateDynamicObject(19432, 1315.1025, -1318.0562, 11.9208, 0.0000, 0.0000, -41.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[317], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[318] = CreateDynamicObject(19432, 1291.1374, -1319.1326, 11.9271, -0.7999, 0.0000, 115.2999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[318], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[319] = CreateDynamicObject(19432, 1292.3579, -1318.5559, 11.9459, -0.7999, 0.0000, 115.2999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[319], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[320] = CreateDynamicObject(19432, 1292.7873, -1317.5944, 11.9522, -0.7999, 0.0000, 26.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[320], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[321] = CreateDynamicObject(19432, 1292.0665, -1316.1660, 11.9299, -0.7999, 0.0000, 26.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[321], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[322] = CreateDynamicObject(19432, 1291.3488, -1314.7465, 11.9577, -0.7999, 0.0000, 26.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[322], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[323] = CreateDynamicObject(19432, 1290.6683, -1313.3984, 11.9366, -0.7999, 0.0000, 26.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[323], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[324] = CreateDynamicObject(19432, 1289.6882, -1313.0495, 11.9451, -0.7999, 0.0000, 115.2999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[324], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[325] = CreateDynamicObject(19432, 1288.2781, -1313.7160, 11.9233, -0.7999, 0.0000, 115.2999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[325], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[326] = CreateDynamicObject(19432, 1290.0174, -1318.9158, 11.9512, -0.7999, 0.0000, 26.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[326], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[327] = CreateDynamicObject(19432, 1289.2915, -1317.4790, 11.9287, -0.7999, 0.0000, 26.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[327], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[328] = CreateDynamicObject(19432, 1288.5699, -1316.0507, 11.9264, -0.7999, 0.0000, 26.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[328], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[329] = CreateDynamicObject(19432, 1287.8983, -1314.7199, 11.9356, -0.7999, 0.0000, 26.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[329], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[330] = CreateDynamicObject(19432, 1296.2418, -1319.0639, 11.9923, -0.7999, 0.0000, 115.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[330], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[331] = CreateDynamicObject(19432, 1297.2651, -1318.5852, 12.0080, -0.7999, 0.0000, 115.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[331], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[332] = CreateDynamicObject(19432, 1297.6191, -1317.6350, 12.0085, -0.7999, 0.0000, 25.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[332], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[333] = CreateDynamicObject(19432, 1296.9411, -1316.1860, 11.9861, -0.7999, 0.0000, 25.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[333], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[334] = CreateDynamicObject(19432, 1296.2624, -1314.7374, 11.9638, -0.7999, 0.0000, 25.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[334], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[335] = CreateDynamicObject(19432, 1295.7750, -1313.6964, 11.9477, -0.7999, 0.0000, 25.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[335], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[336] = CreateDynamicObject(19432, 1294.6418, -1313.4119, 11.9606, -0.7999, 0.0000, -65.1000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[336], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[337] = CreateDynamicObject(19432, 1293.7713, -1313.8146, 11.9740, -0.7999, 0.0000, -65.1000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[337], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[338] = CreateDynamicObject(19432, 1293.2823, -1314.7945, 11.9643, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[338], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[339] = CreateDynamicObject(19432, 1293.9464, -1316.2501, 11.9420, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[339], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[340] = CreateDynamicObject(19432, 1294.5892, -1317.6602, 11.9403, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[340], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[341] = CreateDynamicObject(19432, 1295.1079, -1318.7988, 11.9329, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[341], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[342] = CreateDynamicObject(19432, 1291.7191, -1311.5816, 11.9242, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[342], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[343] = CreateDynamicObject(19432, 1291.0556, -1310.1258, 11.9265, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[343], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[344] = CreateDynamicObject(19432, 1290.4011, -1308.6889, 11.9286, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[344], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[345] = CreateDynamicObject(19432, 1289.9980, -1307.8050, 11.9421, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[345], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[346] = CreateDynamicObject(19432, 1294.2729, -1310.4064, 11.9343, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[346], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[347] = CreateDynamicObject(19432, 1293.6098, -1308.9504, 11.9266, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[347], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[348] = CreateDynamicObject(19432, 1292.9459, -1307.4948, 11.9490, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[348], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[349] = CreateDynamicObject(19432, 1292.5516, -1306.6300, 11.9622, -0.7999, 0.0000, -155.5000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[349], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[350] = CreateDynamicObject(19432, 1291.6347, -1306.2675, 11.9329, -0.7999, 0.0000, 113.2999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[350], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[351] = CreateDynamicObject(19432, 1290.3668, -1306.8133, 11.9337, -0.7999, 0.0000, 113.2999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[351], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[352] = CreateDynamicObject(19432, 1292.7180, -1311.9968, 11.9352, -0.7999, 0.0000, 113.2999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[352], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[353] = CreateDynamicObject(19432, 1293.9851, -1311.4510, 11.9545, -0.7999, 0.0000, 113.2999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[353], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[354] = CreateDynamicObject(19432, 1299.8161, -1312.0435, 11.9508, -0.7999, 0.0000, 25.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[354], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[355] = CreateDynamicObject(19432, 1299.1331, -1310.5858, 11.9283, -0.7999, 0.0000, 25.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[355], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[356] = CreateDynamicObject(19432, 1298.4680, -1309.1638, 11.9264, -0.7999, 0.0000, 25.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[356], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[357] = CreateDynamicObject(19432, 1297.8361, -1307.8140, 11.9256, -0.7999, 0.0000, 25.0999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[357], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[358] = CreateDynamicObject(19432, 1296.8328, -1307.4492, 11.9361, -0.7999, 0.0000, -65.1000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[358], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[359] = CreateDynamicObject(19432, 1295.3995, -1308.1142, 11.9581, -0.7999, 0.0000, -65.1000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[359], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[360] = CreateDynamicObject(19432, 1294.9382, -1309.0987, 11.9485, -0.7999, 0.0000, -156.1001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[360], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[361] = CreateDynamicObject(19432, 1295.5850, -1310.5622, 11.9261, -0.7999, 0.0000, -156.1001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[361], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[362] = CreateDynamicObject(19432, 1296.2340, -1312.0246, 11.9338, -0.7999, 0.0000, -156.1001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[362], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[363] = CreateDynamicObject(19432, 1296.8784, -1313.4786, 11.9416, -0.7999, 0.0000, -156.1001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[363], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[364] = CreateDynamicObject(19432, 1297.8557, -1313.8732, 11.9519, 0.2000, 0.0000, 113.9998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[364], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[365] = CreateDynamicObject(19432, 1299.3084, -1313.2261, 11.9464, 0.2000, 0.0000, 113.9998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[365], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[366] = CreateDynamicObject(19432, 1299.5457, -1313.1199, 11.9455, 0.2000, 0.0000, 113.9998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[366], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[367] = CreateDynamicObject(19432, 1295.6296, -1345.7028, 11.9308, 0.0000, 0.0000, 39.8999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[367], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[368] = CreateDynamicObject(19432, 1314.0998, -1328.0036, 11.9309, 0.0000, 0.0000, -2.4000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[368], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[369] = CreateDynamicObject(19432, 1299.2514, -1341.0072, 11.9309, 0.0000, 0.0000, 39.8999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[369], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[370] = CreateDynamicObject(19432, 1300.0787, -1341.9969, 11.9309, 0.0000, 0.0000, 39.8999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[370], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[371] = CreateDynamicObject(19432, 1314.0585, -1328.9927, 11.9309, 0.0000, 0.0000, -2.4000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[371], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[372] = CreateDynamicObject(19432, 1314.7346, -1329.8972, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[372], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[373] = CreateDynamicObject(19432, 1316.3243, -1329.9302, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[373], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[374] = CreateDynamicObject(19432, 1294.7019, -1344.5928, 11.9308, 0.0000, 0.0000, 39.8999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[374], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[375] = CreateDynamicObject(19432, 1317.9239, -1329.9636, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[375], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[376] = CreateDynamicObject(19432, 1319.5231, -1329.9964, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[376], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[377] = CreateDynamicObject(19432, 1320.4505, -1329.2963, 11.9308, 0.0000, 0.0000, -2.8999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[377], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[378] = CreateDynamicObject(19432, 1298.2338, -1340.8851, 11.9308, 0.0000, 0.0000, -52.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[378], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[379] = CreateDynamicObject(19432, 1320.4975, -1328.3774, 11.9308, 0.0000, 0.0000, -2.8999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[379], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[380] = CreateDynamicObject(19432, 1319.8270, -1327.4658, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[380], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[381] = CreateDynamicObject(19432, 1318.2281, -1327.4163, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[381], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[382] = CreateDynamicObject(19432, 1297.1105, -1341.7376, 11.9208, 0.0000, 0.0000, -52.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[382], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[383] = CreateDynamicObject(19432, 1316.6392, -1327.3673, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[383], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[384] = CreateDynamicObject(19432, 1315.0297, -1327.3168, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[384], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[385] = CreateDynamicObject(19432, 1295.8834, -1342.6684, 11.9208, 0.0000, 0.0000, -52.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[385], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[386] = CreateDynamicObject(19432, 1294.7351, -1343.5393, 11.9208, 0.0000, 0.0000, -52.7999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[386], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[387] = CreateDynamicObject(19432, 1296.6492, -1345.8093, 11.9206, 0.0000, 0.2999, -51.5999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[387], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[388] = CreateDynamicObject(19432, 1314.6483, -1334.0267, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[388], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[389] = CreateDynamicObject(19432, 1316.2379, -1334.0595, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[389], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[390] = CreateDynamicObject(19432, 1317.8273, -1334.0925, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[390], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[391] = CreateDynamicObject(19432, 1319.4169, -1334.1258, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[391], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[392] = CreateDynamicObject(19432, 1319.4764, -1331.3459, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[392], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[393] = CreateDynamicObject(19432, 1297.7625, -1344.9274, 11.9206, 0.0000, 0.2999, -51.5999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[393], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[394] = CreateDynamicObject(19432, 1298.9683, -1343.9721, 11.9206, 0.0000, 0.2999, -51.5999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[394], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[395] = CreateDynamicObject(19432, 1317.8769, -1331.3129, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[395], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[396] = CreateDynamicObject(19432, 1316.2770, -1331.2795, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[396], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[397] = CreateDynamicObject(19432, 1300.0732, -1343.0963, 11.9206, 0.0000, 0.2999, -51.5999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[397], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[398] = CreateDynamicObject(19432, 1314.6774, -1331.2464, 11.9309, 0.0000, 0.0000, -91.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[398], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[399] = CreateDynamicObject(19432, 1313.9350, -1331.9605, 11.9309, 0.0000, 0.0000, -2.4000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[399], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[400] = CreateDynamicObject(19432, 1313.8801, -1333.3000, 11.9309, 0.0000, 0.0000, -2.4000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[400], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[401] = CreateDynamicObject(19432, 1320.3317, -1333.4289, 11.9309, 0.0000, 0.0000, -2.4000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[401], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[402] = CreateDynamicObject(19432, 1320.3684, -1332.0703, 11.9309, 0.0000, 0.0000, 0.2999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[402], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[403] = CreateDynamicObject(2690, 1285.9279, -1323.0164, 15.1536, 0.0000, 0.0000, 88.8999, -1, 0, -1, 450.0, 450.0, -1); //CJ_FIRE_EXT
    asdasdasdsada[404] = CreateDynamicObject(19432, 1293.9989, -1342.0213, 11.9308, 0.0000, 0.0000, -143.2998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[404], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[405] = CreateDynamicObject(19432, 1314.5656, -1335.1147, 11.9309, 0.0000, 0.0000, -92.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[405], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[406] = CreateDynamicObject(19432, 1316.1646, -1335.1759, 11.9309, 0.0000, 0.0000, -92.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[406], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[407] = CreateDynamicObject(19432, 1317.7536, -1335.2366, 11.9309, 0.0000, 0.0000, -92.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[407], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[408] = CreateDynamicObject(19432, 1293.1077, -1340.8270, 11.9308, 0.0000, 0.0000, -143.2998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[408], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[409] = CreateDynamicObject(19432, 1319.3526, -1335.2978, 11.9309, 0.0000, 0.0000, -92.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[409], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[410] = CreateDynamicObject(19432, 1319.2424, -1338.1966, 11.9309, 0.0000, 0.0000, -92.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[410], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[411] = CreateDynamicObject(19432, 1292.0889, -1340.7058, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[411], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[412] = CreateDynamicObject(19432, 1317.6437, -1338.1351, 11.9309, 0.0000, 0.0000, -92.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[412], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[413] = CreateDynamicObject(19432, 1316.0450, -1338.0737, 11.9309, 0.0000, 0.0000, -92.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[413], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[414] = CreateDynamicObject(19432, 1314.4761, -1338.0135, 11.9309, 0.0000, 0.0000, -92.1999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[414], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[415] = CreateDynamicObject(19432, 1288.6202, -1344.2102, 11.9308, 0.0000, 0.0000, -143.2998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[415], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[416] = CreateDynamicObject(19432, 1313.7570, -1335.8057, 11.9309, 0.0000, 0.0000, -3.3999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[416], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[417] = CreateDynamicObject(19432, 1313.6697, -1337.2730, 11.9309, 0.0000, 0.0000, -3.3999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[417], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[418] = CreateDynamicObject(19432, 1320.0230, -1337.4504, 11.9309, 0.0000, 0.0000, -3.3999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[418], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[419] = CreateDynamicObject(19432, 1320.1065, -1336.0430, 11.9309, 0.0000, 0.0000, -3.3999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[419], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[420] = CreateDynamicObject(19432, 1289.5173, -1345.4129, 11.9308, 0.0000, 0.0000, -143.2998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[420], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[421] = CreateDynamicObject(19432, 1290.6470, -1323.8090, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[421], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[422] = CreateDynamicObject(19432, 1292.2464, -1323.8593, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[422], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[423] = CreateDynamicObject(19432, 1290.8702, -1341.6241, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[423], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[424] = CreateDynamicObject(19432, 1289.0572, -1323.7586, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[424], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[425] = CreateDynamicObject(19432, 1289.6563, -1342.5389, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[425], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[426] = CreateDynamicObject(19432, 1288.4774, -1323.7402, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[426], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[427] = CreateDynamicObject(19432, 1288.9057, -1343.1046, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[427], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[428] = CreateDynamicObject(19432, 1288.3864, -1326.6390, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[428], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[429] = CreateDynamicObject(19432, 1289.9869, -1326.6900, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[429], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[430] = CreateDynamicObject(19432, 1290.6397, -1345.4544, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[430], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[431] = CreateDynamicObject(19432, 1291.5863, -1326.7404, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[431], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[432] = CreateDynamicObject(19432, 1292.0867, -1326.7572, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[432], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[433] = CreateDynamicObject(19432, 1291.8937, -1344.5095, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[433], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[434] = CreateDynamicObject(19432, 1292.8640, -1326.0704, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[434], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[435] = CreateDynamicObject(19432, 1293.1474, -1343.5645, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[435], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[436] = CreateDynamicObject(19432, 1292.9310, -1324.5919, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[436], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[437] = CreateDynamicObject(19432, 1293.8022, -1343.0708, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[437], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[438] = CreateDynamicObject(19432, 1287.7125, -1324.4252, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[438], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[439] = CreateDynamicObject(19432, 1287.6448, -1325.9038, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[439], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[440] = CreateDynamicObject(19432, 1289.9515, -1328.0490, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[440], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[441] = CreateDynamicObject(19432, 1292.7333, -1328.9383, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[441], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[442] = CreateDynamicObject(19432, 1292.6737, -1330.2674, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[442], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[443] = CreateDynamicObject(19432, 1287.5185, -1328.6918, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[443], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[444] = CreateDynamicObject(19432, 1287.4652, -1329.8798, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[444], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[445] = CreateDynamicObject(19432, 1288.3425, -1327.9993, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[445], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[446] = CreateDynamicObject(19432, 1291.5418, -1328.0991, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[446], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[447] = CreateDynamicObject(19432, 1292.0518, -1328.1158, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[447], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[448] = CreateDynamicObject(19432, 1291.9315, -1330.9838, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[448], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[449] = CreateDynamicObject(19432, 1290.3519, -1330.9345, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[449], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[450] = CreateDynamicObject(19432, 1288.7534, -1330.8846, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[450], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[451] = CreateDynamicObject(19432, 1288.1534, -1330.8654, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[451], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[452] = CreateDynamicObject(19432, 1287.4545, -1330.1101, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[452], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[453] = CreateDynamicObject(19432, 1291.8945, -1332.1440, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[453], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[454] = CreateDynamicObject(19432, 1291.1779, -1335.1734, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[454], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[455] = CreateDynamicObject(19432, 1290.2954, -1332.0944, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[455], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[456] = CreateDynamicObject(19432, 1288.7164, -1332.0451, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[456], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[457] = CreateDynamicObject(19432, 1288.1462, -1332.0269, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[457], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[458] = CreateDynamicObject(19432, 1291.5559, -1345.8404, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[458], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[459] = CreateDynamicObject(19432, 1287.9899, -1335.0739, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[459], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[460] = CreateDynamicObject(19432, 1289.5891, -1335.1239, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[460], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[461] = CreateDynamicObject(19432, 1291.7574, -1335.1914, 11.9308, 0.0000, 0.0000, -91.8000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[461], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[462] = CreateDynamicObject(19432, 1292.5732, -1332.8967, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[462], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[463] = CreateDynamicObject(19432, 1293.1688, -1347.8815, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[463], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[464] = CreateDynamicObject(19432, 1292.5008, -1334.4859, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[464], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[465] = CreateDynamicObject(19432, 1291.8752, -1348.8574, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[465], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[466] = CreateDynamicObject(19432, 1287.3149, -1334.2508, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[466], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[467] = CreateDynamicObject(19432, 1290.3337, -1346.7630, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[467], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[468] = CreateDynamicObject(19432, 1287.3842, -1332.7224, 11.9308, 0.0000, 0.0000, 177.3998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[468], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[469] = CreateDynamicObject(19432, 1290.3337, -1346.7630, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[469], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[470] = CreateDynamicObject(19432, 1310.8183, -1345.4829, 11.9309, 0.0000, 0.0000, 2.2000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[470], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[471] = CreateDynamicObject(19432, 1310.8796, -1347.0714, 11.9309, 0.0000, 0.0000, 2.2000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[471], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[472] = CreateDynamicObject(19432, 1310.9407, -1348.6499, 11.9309, 0.0000, 0.0000, 2.2000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[472], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[473] = CreateDynamicObject(19432, 1291.8986, -1348.8399, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[473], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[474] = CreateDynamicObject(19432, 1311.0010, -1350.2186, 11.9309, 0.0000, 0.0000, 2.2000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[474], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[475] = CreateDynamicObject(19432, 1314.1296, -1350.0994, 11.9309, 0.0000, 0.0000, 2.2000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[475], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[476] = CreateDynamicObject(19432, 1290.6363, -1349.7906, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[476], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[477] = CreateDynamicObject(19432, 1314.0694, -1348.5202, 11.9309, 0.0000, 0.0000, 2.2000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[477], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[478] = CreateDynamicObject(19432, 1314.0084, -1346.9315, 11.9309, 0.0000, 0.0000, 2.2000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[478], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[479] = CreateDynamicObject(19432, 1313.9473, -1345.3427, 11.9309, 0.0000, 0.0000, 2.2000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[479], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[480] = CreateDynamicObject(19432, 1313.2078, -1344.6528, 11.9208, 0.0000, 0.0000, 91.6000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[480], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[481] = CreateDynamicObject(19432, 1289.0714, -1347.7138, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[481], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[482] = CreateDynamicObject(19432, 1311.6282, -1344.6975, 11.9208, 0.0000, 0.0000, 91.6000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[482], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[483] = CreateDynamicObject(19432, 1311.4981, -1344.7006, 11.9208, 0.0000, 0.0000, 91.6000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[483], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[484] = CreateDynamicObject(19432, 1288.3205, -1348.2795, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[484], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[485] = CreateDynamicObject(19432, 1311.4981, -1344.7006, 11.9208, 0.0000, 0.0000, 91.6000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[485], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[486] = CreateDynamicObject(19432, 1289.9190, -1350.3342, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[486], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[487] = CreateDynamicObject(19432, 1311.8012, -1350.9061, 11.9208, 0.0000, 0.0000, 91.6000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[487], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[488] = CreateDynamicObject(19432, 1288.1881, -1349.2867, 11.9308, 0.0000, 0.0000, 38.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[488], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[489] = CreateDynamicObject(19432, 1313.3812, -1350.8621, 11.9208, 0.0000, 0.0000, 91.6000, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[489], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[490] = CreateDynamicObject(19432, 1317.4472, -1344.1169, 11.9309, 0.0000, 0.0000, -46.9999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[490], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[491] = CreateDynamicObject(19432, 1288.8715, -1350.1614, 11.9308, 0.0000, 0.0000, 38.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[491], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[492] = CreateDynamicObject(19432, 1316.6352, -1344.8741, 11.9309, 0.0000, 0.0000, -46.9999, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[492], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[493] = CreateDynamicObject(19432, 1316.5874, -1345.9034, 11.9309, 0.0000, 0.0000, -136.7998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[493], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[494] = CreateDynamicObject(19432, 1293.2060, -1346.7756, 11.9308, 0.0000, 0.0000, 38.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[494], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[495] = CreateDynamicObject(19432, 1292.6219, -1346.0263, 11.9308, 0.0000, 0.0000, 38.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[495], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[496] = CreateDynamicObject(19432, 1317.6762, -1347.0626, 11.9309, 0.0000, 0.0000, -136.7998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[496], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[497] = CreateDynamicObject(19432, 1318.7788, -1348.2360, 11.9309, 0.0000, 0.0000, -136.7998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[497], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[498] = CreateDynamicObject(19432, 1319.8466, -1349.3732, 11.9309, 0.0000, 0.0000, -136.7998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[498], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[499] = CreateDynamicObject(19432, 1320.8750, -1349.4036, 11.9309, 0.0000, 0.0000, -46.4998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[499], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[500] = CreateDynamicObject(19432, 1298.0318, -1348.8530, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[500], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[501] = CreateDynamicObject(19432, 1321.7382, -1348.5845, 11.9309, 0.0000, 0.0000, -46.4998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[501], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[502] = CreateDynamicObject(19432, 1318.5557, -1344.0549, 11.9309, 0.0000, 0.0000, -136.7998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[502], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[503] = CreateDynamicObject(19432, 1319.6308, -1345.1994, 11.9309, 0.0000, 0.0000, -136.7998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[503], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[504] = CreateDynamicObject(19432, 1320.7261, -1346.3657, 11.9309, 0.0000, 0.0000, -136.7998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[504], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[505] = CreateDynamicObject(19432, 1321.8216, -1347.5318, 11.9309, 0.0000, 0.0000, -136.7998, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[505], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[506] = CreateDynamicObject(19432, 1296.5571, -1346.8967, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[506], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[507] = CreateDynamicObject(19432, 1296.7779, -1349.7980, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[507], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[508] = CreateDynamicObject(19432, 1295.3034, -1347.8411, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[508], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[509] = CreateDynamicObject(19432, 1294.0335, -1348.7989, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[509], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[510] = CreateDynamicObject(19432, 1295.5080, -1350.7551, 11.9308, 0.0000, 0.0000, 127.0001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[510], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[511] = CreateDynamicObject(19432, 1297.5770, -1347.0023, 11.9308, 0.0000, 0.0000, 37.2001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[511], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[512] = CreateDynamicObject(19545, 1325.3415, -1353.9471, 12.5383, -0.2999, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[512], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[513] = CreateDynamicObject(19545, 1310.3813, -1353.9471, 12.5383, -0.2999, 0.0000, 0.0000, -1, 0, -1, 450.0, 450.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(asdasdasdsada[513], 0, 6522, "cuntclub_law2", "helipad_grey1", 0xFFFFFFFF);
    asdasdasdsada[514] = CreateDynamicObject(19432, 1298.2006, -1347.8231, 11.9308, 0.0000, 0.0000, 37.2001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[514], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[515] = CreateDynamicObject(19432, 1294.3771, -1350.7253, 11.9308, 0.0000, 0.0000, 37.2001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[515], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    asdasdasdsada[516] = CreateDynamicObject(19432, 1293.7532, -1349.9047, 11.9308, 0.0000, 0.0000, 37.2001, -1, 0, -1, 450.0, 450.0, -1); //wall072
    SetDynamicObjectMaterial(asdasdasdsada[516], 0, 16640, "a51", "redmetal", 0xFFFFFFFF);
    return 1;
}