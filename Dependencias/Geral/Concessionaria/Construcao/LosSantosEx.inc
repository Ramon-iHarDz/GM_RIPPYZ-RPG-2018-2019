#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid){
    RemoveBuildingForPlayer(playerid, 4719, 1760.1641, -1127.2734, 43.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 4748, 1760.1641, -1127.2734, 43.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1215, 1806.5781, -1142.8438, 23.6094, 50.00);
	RemoveBuildingForPlayer(playerid, 4718, 1760.1641, -1127.2734, 43.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1227, 1789.7734, -1116.0625, 23.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 1227, 1789.9063, -1112.6406, 23.8906, 0.25);
    return 1;
}

hook OnGameModeInit(){
    new aldksadaaa[478];
    aldksadaaa[0] = CreateDynamicObject(19380, 1716.5200, -1111.7637, 18.4793, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[0], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[1] = CreateDynamicObject(19380, 1716.5200, -1118.1429, 18.4793, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[1], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[2] = CreateDynamicObject(19380, 1721.2697, -1132.4334, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[2], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[3] = CreateDynamicObject(19380, 1716.5200, -1127.6928, 18.4793, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[3], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[4] = CreateDynamicObject(19380, 1761.0799, -1127.6928, 18.4793, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[4], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[5] = CreateDynamicObject(19380, 1761.0799, -1118.1416, 18.4793, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[5], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[6] = CreateDynamicObject(19380, 1730.8516, -1132.4334, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[6], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[7] = CreateDynamicObject(19380, 1740.4406, -1132.4334, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[7], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[8] = CreateDynamicObject(19380, 1750.0415, -1132.4334, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[8], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[9] = CreateDynamicObject(19380, 1756.3520, -1132.4334, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[9], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[10] = CreateDynamicObject(19380, 1761.0899, -1111.7597, 18.4793, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[10], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[11] = CreateDynamicObject(19380, 1742.7117, -1117.9317, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[11], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[12] = CreateDynamicObject(19380, 1716.5200, -1102.1440, 18.4793, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[12], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[13] = CreateDynamicObject(19380, 1761.0897, -1102.1440, 18.4793, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[13], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[14] = CreateDynamicObject(19380, 1742.7117, -1111.8808, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[14], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[15] = CreateDynamicObject(19380, 1753.1115, -1111.8808, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[15], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[16] = CreateDynamicObject(19380, 1721.8509, -1127.5236, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[16], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[17] = CreateDynamicObject(19380, 1721.8509, -1118.0341, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[17], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[18] = CreateDynamicObject(19380, 1721.8509, -1111.8713, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[18], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[19] = CreateDynamicObject(19380, 1732.2523, -1111.8913, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[19], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[20] = CreateDynamicObject(19380, 1732.2523, -1121.5211, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[20], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[21] = CreateDynamicObject(19380, 1732.2523, -1127.5214, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[21], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[22] = CreateDynamicObject(19380, 1742.6912, -1127.5214, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[22], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[23] = CreateDynamicObject(19380, 1753.1022, -1127.5214, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[23], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[24] = CreateDynamicObject(19380, 1753.1022, -1117.9317, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[24], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[25] = CreateDynamicObject(19380, 1721.2497, -1097.2426, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[25], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[26] = CreateDynamicObject(19380, 1730.8791, -1097.2426, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[26], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[27] = CreateDynamicObject(19380, 1740.5089, -1097.2426, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[27], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[28] = CreateDynamicObject(19380, 1721.8509, -1102.2609, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[28], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[29] = CreateDynamicObject(19380, 1750.1289, -1097.2426, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[29], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[30] = CreateDynamicObject(19380, 1756.3305, -1097.2426, 18.4793, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[30], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[31] = CreateDynamicObject(19380, 1732.2996, -1102.3110, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[31], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[32] = CreateDynamicObject(19380, 1742.7893, -1102.3112, 23.6568, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[32], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[33] = CreateDynamicObject(19380, 1753.2391, -1102.3112, 23.6668, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[33], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[34] = CreateDynamicObject(19380, 1755.8200, -1102.1311, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[34], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[35] = CreateDynamicObject(19380, 1745.4185, -1102.1311, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[35], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[36] = CreateDynamicObject(19380, 1734.9897, -1102.1311, 23.6668, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[36], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[37] = CreateDynamicObject(19380, 1724.8698, -1102.1311, 23.6568, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[37], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[38] = CreateDynamicObject(19380, 1721.8697, -1102.1311, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[38], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[39] = CreateDynamicObject(19380, 1755.8200, -1111.7204, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[39], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[40] = CreateDynamicObject(19380, 1755.8197, -1120.9604, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[40], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[41] = CreateDynamicObject(19380, 1755.8200, -1127.5107, 23.6468, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[41], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[42] = CreateDynamicObject(19380, 1718.1508, -1131.0836, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[42], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[43] = CreateDynamicObject(19380, 1718.1508, -1121.5242, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[43], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[44] = CreateDynamicObject(19380, 1718.1508, -1111.9954, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[44], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[45] = CreateDynamicObject(19380, 1718.1508, -1102.4260, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[45], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[46] = CreateDynamicObject(19380, 1718.1508, -1098.9952, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[46], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[47] = CreateDynamicObject(19380, 1728.5708, -1098.9952, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[47], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[48] = CreateDynamicObject(19380, 1738.9904, -1098.9952, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[48], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[49] = CreateDynamicObject(19380, 1749.2502, -1098.9952, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[49], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[50] = CreateDynamicObject(19380, 1759.1192, -1098.9952, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[50], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[51] = CreateDynamicObject(19380, 1728.5502, -1131.0836, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[51], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[52] = CreateDynamicObject(19380, 1738.9801, -1131.0836, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[52], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[53] = CreateDynamicObject(19380, 1749.4000, -1131.0836, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[53], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[54] = CreateDynamicObject(19380, 1759.1204, -1131.0836, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[54], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[55] = CreateDynamicObject(19380, 1759.1204, -1121.5637, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[55], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[56] = CreateDynamicObject(19380, 1759.1204, -1112.1436, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[56], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[57] = CreateDynamicObject(19380, 1759.1204, -1107.6735, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[57], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[58] = CreateDynamicObject(19380, 1730.8793, -1132.4334, 25.9392, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[58], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[59] = CreateDynamicObject(19380, 1721.3198, -1132.4334, 25.9392, 0.0000, 180.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[59], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[60] = CreateDynamicObject(3858, 1753.7752, -1132.5358, 26.6611, 0.0000, 0.0000, -134.8996, -1, 0, -1, 400.0, 400.0, -1); //ottosmash1
    aldksadaaa[61] = CreateDynamicObject(14411, 1742.8004, -1132.6387, 20.4644, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //carter-stairs04
    SetDynamicObjectMaterial(aldksadaaa[61], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[62] = CreateDynamicObject(14411, 1733.8602, -1132.4886, 20.4744, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //carter-stairs04
    SetDynamicObjectMaterial(aldksadaaa[62], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[63] = CreateDynamicObject(19380, 1761.0803, -1127.7250, 25.9392, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[63], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[64] = CreateDynamicObject(19433, 1761.0828, -1133.3359, 24.7698, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[64], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[65] = CreateDynamicObject(19380, 1761.0803, -1101.9744, 25.9392, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[65], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[66] = CreateDynamicObject(3858, 1761.1362, -1114.9562, 26.5611, 0.0000, 0.0000, 135.1001, -1, 0, -1, 400.0, 400.0, -1); //ottosmash1
    aldksadaaa[67] = CreateDynamicObject(19380, 1761.1003, -1126.9843, 25.9392, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[67], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[68] = CreateDynamicObject(19380, 1761.1003, -1103.3137, 25.9392, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[68], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[69] = CreateDynamicObject(19433, 1746.5025, -1133.3359, 24.7698, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[69], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[70] = CreateDynamicObject(19433, 1746.5125, -1133.3359, 27.7298, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[70], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[71] = CreateDynamicObject(19433, 1761.0935, -1133.3359, 27.7298, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[71], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[72] = CreateDynamicObject(3858, 1753.7152, -1097.2390, 26.6611, 0.0000, 0.0000, -134.8996, -1, 0, -1, 400.0, 400.0, -1); //ottosmash1
    aldksadaaa[73] = CreateDynamicObject(19380, 1741.8602, -1097.2424, 25.9392, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[73], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[74] = CreateDynamicObject(19545, 1738.4785, -1113.9738, 31.2110, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(aldksadaaa[74], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[75] = CreateDynamicObject(19791, 1712.2357, -1096.5008, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[75], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[76] = CreateDynamicObject(19545, 1738.4785, -1128.9726, 31.2110, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(aldksadaaa[76], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[77] = CreateDynamicObject(19545, 1738.4785, -1098.9954, 31.2110, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //Plane62_5x15Conc1
    SetDynamicObjectMaterial(aldksadaaa[77], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[78] = CreateDynamicObject(19791, 1764.7261, -1096.5008, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[78], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[79] = CreateDynamicObject(19791, 1764.7261, -1131.4702, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[79], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[80] = CreateDynamicObject(19433, 1748.3226, -1133.3369, 29.3898, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[80], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[81] = CreateDynamicObject(19463, 1744.8421, -1132.4605, 26.4589, 90.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall103
    SetDynamicObjectMaterial(aldksadaaa[81], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[82] = CreateDynamicObject(19433, 1751.7528, -1133.3369, 29.3898, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[82], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[83] = CreateDynamicObject(19433, 1755.2330, -1133.3369, 29.3898, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[83], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[84] = CreateDynamicObject(19433, 1758.6127, -1133.3369, 29.3998, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[84], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[85] = CreateDynamicObject(19433, 1759.3532, -1133.3369, 29.3898, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[85], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[86] = CreateDynamicObject(19463, 1742.6323, -1132.4705, 26.4589, 90.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall103
    SetDynamicObjectMaterial(aldksadaaa[86], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[87] = CreateDynamicObject(19791, 1712.2357, -1131.4810, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[87], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[88] = CreateDynamicObject(19791, 1722.2148, -1131.4810, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[88], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[89] = CreateDynamicObject(19791, 1732.2138, -1131.4810, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[89], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[90] = CreateDynamicObject(638, 1747.9564, -1133.2935, 23.4245, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
    aldksadaaa[91] = CreateDynamicObject(19791, 1742.2042, -1131.4810, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[91], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[92] = CreateDynamicObject(19791, 1752.2042, -1131.4810, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[92], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[93] = CreateDynamicObject(19791, 1758.4348, -1131.3409, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[93], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[94] = CreateDynamicObject(19791, 1764.7261, -1106.4699, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[94], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[95] = CreateDynamicObject(638, 1751.6779, -1133.2935, 23.4245, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
    aldksadaaa[96] = CreateDynamicObject(638, 1755.6688, -1133.2935, 23.4245, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
    aldksadaaa[97] = CreateDynamicObject(19791, 1764.7261, -1116.4094, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[97], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[98] = CreateDynamicObject(19380, 1732.3508, -1097.2424, 25.9392, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[98], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[99] = CreateDynamicObject(19791, 1764.5660, -1124.4094, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[99], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[100] = CreateDynamicObject(638, 1759.6497, -1133.2935, 23.4245, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
    aldksadaaa[101] = CreateDynamicObject(19791, 1722.2062, -1096.5008, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[101], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[102] = CreateDynamicObject(19791, 1751.9039, -1096.5008, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[102], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[103] = CreateDynamicObject(19791, 1732.1256, -1096.5008, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[103], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[104] = CreateDynamicObject(19791, 1741.9749, -1096.5008, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[104], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[105] = CreateDynamicObject(19791, 1757.0444, -1096.6209, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[105], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[106] = CreateDynamicObject(19791, 1712.2357, -1121.6318, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[106], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[107] = CreateDynamicObject(19791, 1712.2357, -1111.6822, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[107], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[108] = CreateDynamicObject(19791, 1712.3858, -1103.8624, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[108], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[109] = CreateDynamicObject(19791, 1722.2148, -1121.6608, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[109], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[110] = CreateDynamicObject(19791, 1732.2147, -1121.6608, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[110], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[111] = CreateDynamicObject(19791, 1742.1330, -1121.6608, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[111], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[112] = CreateDynamicObject(19791, 1752.0327, -1121.6608, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[112], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[113] = CreateDynamicObject(19791, 1758.0125, -1121.6608, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[113], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[114] = CreateDynamicObject(19791, 1758.0125, -1111.9409, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[114], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[115] = CreateDynamicObject(3858, 1716.4669, -1105.4255, 26.5611, 0.0000, 0.0000, 135.1001, -1, 0, -1, 400.0, 400.0, -1); //ottosmash1
    aldksadaaa[116] = CreateDynamicObject(19791, 1748.0931, -1111.9409, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[116], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[117] = CreateDynamicObject(19791, 1738.1533, -1111.9409, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[117], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[118] = CreateDynamicObject(19791, 1728.1837, -1111.9409, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[118], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[119] = CreateDynamicObject(19791, 1719.5139, -1111.9409, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[119], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[120] = CreateDynamicObject(19791, 1719.5139, -1104.7104, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[120], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[121] = CreateDynamicObject(19791, 1729.4824, -1104.7104, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[121], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[122] = CreateDynamicObject(19791, 1739.3417, -1104.7104, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[122], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[123] = CreateDynamicObject(3858, 1716.4769, -1115.5573, 26.5611, 0.0000, 0.0000, 135.1001, -1, 0, -1, 400.0, 400.0, -1); //ottosmash1
    aldksadaaa[124] = CreateDynamicObject(19380, 1716.5095, -1127.2036, 26.3492, 90.0000, 180.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[124], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[125] = CreateDynamicObject(19791, 1749.1514, -1104.7104, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[125], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[126] = CreateDynamicObject(19791, 1757.5017, -1104.7104, 31.2581, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Cube10mx10m
    SetDynamicObjectMaterial(aldksadaaa[126], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    aldksadaaa[127] = CreateDynamicObject(19463, 1716.5317, -1113.2111, 26.4589, 90.0000, 90.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall103
    SetDynamicObjectMaterial(aldksadaaa[127], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[128] = CreateDynamicObject(19463, 1716.5317, -1109.7319, 26.4589, 90.0000, 90.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall103
    SetDynamicObjectMaterial(aldksadaaa[128], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[129] = CreateDynamicObject(19463, 1716.5317, -1098.9117, 26.4589, 90.0000, 90.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall103
    SetDynamicObjectMaterial(aldksadaaa[129], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[130] = CreateDynamicObject(19463, 1718.2316, -1097.2309, 26.4589, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall103
    SetDynamicObjectMaterial(aldksadaaa[130], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[131] = CreateDynamicObject(3858, 1724.7840, -1097.1894, 26.6311, 0.0000, 0.0000, 44.9001, -1, 0, -1, 400.0, 400.0, -1); //ottosmash1
    aldksadaaa[132] = CreateDynamicObject(10281, 1726.3693, -1133.3952, 27.1828, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //michsign_sfe
    aldksadaaa[133] = CreateDynamicObject(19447, 1756.3077, -1132.4483, 31.0325, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall087
    SetDynamicObjectMaterial(aldksadaaa[133], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[134] = CreateDynamicObject(19447, 1751.2473, -1132.4483, 31.0325, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall087
    SetDynamicObjectMaterial(aldksadaaa[134], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[135] = CreateDynamicObject(19447, 1746.8083, -1097.2376, 31.0325, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall087
    SetDynamicObjectMaterial(aldksadaaa[135], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[136] = CreateDynamicObject(19447, 1756.3477, -1097.2376, 31.0325, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall087
    SetDynamicObjectMaterial(aldksadaaa[136], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[137] = CreateDynamicObject(1491, 1739.8016, -1132.4195, 23.6799, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //Gen_doorINT01
    SetDynamicObjectMaterial(aldksadaaa[137], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    aldksadaaa[138] = CreateDynamicObject(19447, 1724.1866, -1097.2376, 31.0325, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall087
    SetDynamicObjectMaterial(aldksadaaa[138], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[139] = CreateDynamicObject(19447, 1716.5264, -1104.2692, 31.0325, 0.0000, 180.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall087
    SetDynamicObjectMaterial(aldksadaaa[139], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[140] = CreateDynamicObject(19447, 1716.5565, -1118.9893, 31.0325, 0.0000, 180.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall087
    SetDynamicObjectMaterial(aldksadaaa[140], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[141] = CreateDynamicObject(19447, 1761.0769, -1118.9893, 31.0325, 0.0000, 180.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall087
    SetDynamicObjectMaterial(aldksadaaa[141], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[142] = CreateDynamicObject(19447, 1761.0869, -1110.2390, 31.0325, 0.0000, 180.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall087
    SetDynamicObjectMaterial(aldksadaaa[142], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[143] = CreateDynamicObject(18075, 1723.1635, -1105.0930, 31.2444, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    aldksadaaa[144] = CreateDynamicObject(18075, 1723.1635, -1124.4934, 31.2444, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    aldksadaaa[145] = CreateDynamicObject(18075, 1734.0919, -1124.4934, 31.2444, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    aldksadaaa[146] = CreateDynamicObject(18075, 1734.0050, -1105.0930, 31.2444, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    aldksadaaa[147] = CreateDynamicObject(18075, 1744.5146, -1105.0930, 31.2444, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    aldksadaaa[148] = CreateDynamicObject(18075, 1755.4042, -1105.0930, 31.2444, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    aldksadaaa[149] = CreateDynamicObject(18075, 1755.4042, -1105.0930, 31.2444, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    aldksadaaa[150] = CreateDynamicObject(19380, 1738.2902, -1134.5933, 18.8992, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[150], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[151] = CreateDynamicObject(18075, 1744.5146, -1124.4940, 31.2444, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    aldksadaaa[152] = CreateDynamicObject(18075, 1755.4042, -1124.3940, 31.2444, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //lightD
    aldksadaaa[153] = CreateDynamicObject(1491, 1736.7718, -1132.4395, 23.6799, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Gen_doorINT01
    SetDynamicObjectMaterial(aldksadaaa[153], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    aldksadaaa[154] = CreateDynamicObject(19380, 1769.5920, -1121.5239, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[154], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[155] = CreateDynamicObject(19380, 1769.5920, -1112.3643, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[155], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[156] = CreateDynamicObject(19325, 1733.4624, -1132.4298, 24.1159, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    aldksadaaa[157] = CreateDynamicObject(19325, 1743.0938, -1132.4298, 24.1159, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    aldksadaaa[158] = CreateDynamicObject(19380, 1769.5920, -1131.0836, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[158], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[159] = CreateDynamicObject(19380, 1769.5920, -1102.7943, 23.0068, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[159], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[160] = CreateDynamicObject(19380, 1769.5920, -1099.0040, 23.0268, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall028
    SetDynamicObjectMaterial(aldksadaaa[160], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[161] = CreateDynamicObject(19433, 1774.0627, -1132.4458, 24.7698, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[161], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[162] = CreateDynamicObject(19433, 1762.9423, -1132.4458, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[162], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[163] = CreateDynamicObject(19325, 1741.6043, -1132.4298, 28.2359, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    aldksadaaa[164] = CreateDynamicObject(19325, 1734.9635, -1132.4298, 28.2359, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    aldksadaaa[165] = CreateDynamicObject(19325, 1734.9635, -1132.4298, 32.3559, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    aldksadaaa[166] = CreateDynamicObject(19325, 1741.6048, -1132.4298, 32.3559, 0.0000, 0.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //lsmall_window01
    aldksadaaa[167] = CreateDynamicObject(19433, 1766.4223, -1132.4458, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[167], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[168] = CreateDynamicObject(19433, 1769.8924, -1132.4458, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[168], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[169] = CreateDynamicObject(19433, 1773.1522, -1132.4458, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[169], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[170] = CreateDynamicObject(19433, 1774.0627, -1132.4758, 26.4498, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[170], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[171] = CreateDynamicObject(19433, 1762.9423, -1126.5382, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[171], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[172] = CreateDynamicObject(19433, 1762.9423, -1129.3560, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[172], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[173] = CreateDynamicObject(19433, 1766.4223, -1129.3553, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[173], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[174] = CreateDynamicObject(19433, 1762.9423, -1123.5284, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[174], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[175] = CreateDynamicObject(19433, 1766.4223, -1126.5351, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[175], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[176] = CreateDynamicObject(19433, 1769.8924, -1132.4458, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[176], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[177] = CreateDynamicObject(19433, 1769.8924, -1132.4458, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[177], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[178] = CreateDynamicObject(19433, 1766.4223, -1123.5249, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[178], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[179] = CreateDynamicObject(19433, 1769.8924, -1129.3560, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[179], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[180] = CreateDynamicObject(19433, 1769.8924, -1126.5361, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[180], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[181] = CreateDynamicObject(19433, 1769.8924, -1123.5256, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[181], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[182] = CreateDynamicObject(19433, 1773.1522, -1129.3543, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[182], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[183] = CreateDynamicObject(19433, 1773.1522, -1126.5340, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[183], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[184] = CreateDynamicObject(19433, 1773.1522, -1123.5240, 28.7398, 90.0000, 90.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[184], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[185] = CreateDynamicObject(19433, 1774.0627, -1129.3552, 26.4498, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[185], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[186] = CreateDynamicObject(19433, 1774.0627, -1126.5249, 26.4498, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[186], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[187] = CreateDynamicObject(19433, 1774.0627, -1123.5145, 26.4498, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[187], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[188] = CreateDynamicObject(19433, 1774.0627, -1129.3453, 24.7698, 0.0000, 180.0000, 89.5999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[188], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[189] = CreateDynamicObject(19433, 1774.0822, -1126.5450, 24.7698, 0.0000, 180.0000, 89.5999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[189], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[190] = CreateDynamicObject(19433, 1774.1033, -1123.5147, 24.7698, 0.0000, 180.0000, 89.5999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[190], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[191] = CreateDynamicObject(18070, 1737.2227, -1102.4375, 24.2157, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //GAP_COUNTER
    aldksadaaa[192] = CreateDynamicObject(19786, 1731.0843, -1097.3112, 26.8188, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
    aldksadaaa[193] = CreateDynamicObject(970, 1736.8901, -1134.5799, 24.1363, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //fencesmallb
    SetDynamicObjectMaterial(aldksadaaa[193], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[194] = CreateDynamicObject(19786, 1743.3936, -1097.3220, 26.8188, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
    aldksadaaa[195] = CreateDynamicObject(19367, 1732.0865, -1132.3240, 29.1230, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall015
    SetDynamicObjectMaterial(aldksadaaa[195], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[196] = CreateDynamicObject(19367, 1732.1059, -1132.3243, 25.6929, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall015
    SetDynamicObjectMaterial(aldksadaaa[196], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[197] = CreateDynamicObject(19367, 1729.0458, -1132.3243, 25.6929, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall015
    SetDynamicObjectMaterial(aldksadaaa[197], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[198] = CreateDynamicObject(19367, 1729.0458, -1132.3243, 29.1630, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall015
    SetDynamicObjectMaterial(aldksadaaa[198], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[199] = CreateDynamicObject(19367, 1722.8061, -1132.3243, 29.1630, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall015
    SetDynamicObjectMaterial(aldksadaaa[199], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[200] = CreateDynamicObject(19367, 1719.7457, -1132.3243, 29.1630, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall015
    SetDynamicObjectMaterial(aldksadaaa[200], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[201] = CreateDynamicObject(19367, 1719.7457, -1132.3243, 25.6829, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall015
    SetDynamicObjectMaterial(aldksadaaa[201], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[202] = CreateDynamicObject(1514, 1738.3424, -1104.2213, 24.9737, 0.0000, 0.0000, 19.5000, -1, 0, -1, 400.0, 400.0, -1); //DYN_FF_TILL
    aldksadaaa[203] = CreateDynamicObject(19367, 1722.7963, -1132.3243, 25.6829, 0.0000, 180.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall015
    SetDynamicObjectMaterial(aldksadaaa[203], 0, 14383, "burg_1", "mp_diner_woodwall", 0xFFFFFFFF);
    aldksadaaa[204] = CreateDynamicObject(19893, 1736.9614, -1104.1002, 24.7347, 0.0000, 0.0000, 175.3999, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    aldksadaaa[205] = CreateDynamicObject(19786, 1725.8325, -1132.3856, 27.8069, 0.0000, 0.0000, -179.8000, -1, 0, -1, 400.0, 400.0, -1); //LCDTVBig1
    aldksadaaa[206] = CreateDynamicObject(2059, 1734.3492, -1102.6842, 24.7372, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //CJ_GUNSTUFF1
    aldksadaaa[207] = CreateDynamicObject(970, 1741.0201, -1134.5799, 24.1363, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //fencesmallb
    SetDynamicObjectMaterial(aldksadaaa[207], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[208] = CreateDynamicObject(10281, 1737.2401, -1098.1647, 27.1828, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //michsign_sfe
    aldksadaaa[209] = CreateDynamicObject(970, 1735.5498, -1134.5999, 24.1363, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //fencesmallb
    SetDynamicObjectMaterial(aldksadaaa[209], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    aldksadaaa[210] = CreateDynamicObject(1080, 1732.9346, -1132.1551, 24.5725, 180.0000, 180.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //wheel_sr5
    aldksadaaa[211] = CreateDynamicObject(1083, 1730.6225, -1132.1333, 24.5818, 180.0000, 180.0000, -93.6000, -1, 0, -1, 400.0, 400.0, -1); //wheel_lr2
    aldksadaaa[212] = CreateDynamicObject(1084, 1728.2521, -1132.1483, 24.6124, 180.0000, 180.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //wheel_lr5
    aldksadaaa[213] = CreateDynamicObject(1083, 1719.9644, -1132.1004, 26.9872, 0.0000, 0.0000, 86.7000, -1, 0, -1, 400.0, 400.0, -1); //wheel_lr2
    aldksadaaa[214] = CreateDynamicObject(1083, 1732.8952, -1132.1159, 29.9772, 0.0000, 0.0000, 86.7000, -1, 0, -1, 400.0, 400.0, -1); //wheel_lr2
    aldksadaaa[215] = CreateDynamicObject(1084, 1728.5162, -1131.9489, 29.8685, 0.0000, 0.0000, -95.8999, -1, 0, -1, 400.0, 400.0, -1); //wheel_lr5
    aldksadaaa[216] = CreateDynamicObject(11701, 1732.7243, -1132.1729, 27.0779, -0.8000, -91.2999, -89.1999, -1, 0, -1, 400.0, 400.0, -1); //AmbulanceLights1
    aldksadaaa[217] = CreateDynamicObject(11701, 1728.3634, -1132.1635, 27.1372, -0.8000, -91.2999, -89.1999, -1, 0, -1, 400.0, 400.0, -1); //AmbulanceLights1
    aldksadaaa[218] = CreateDynamicObject(19967, 1723.6390, -1132.2382, 27.0113, 0.0000, 0.0000, -179.9001, -1, 0, -1, 400.0, 400.0, -1); //SAMPRoadSign20
    aldksadaaa[219] = CreateDynamicObject(19959, 1723.7839, -1132.2524, 24.0374, 0.0000, 0.0000, -179.4000, -1, 0, -1, 400.0, 400.0, -1); //SAMPRoadSign12
    aldksadaaa[220] = CreateDynamicObject(19966, 1722.8575, -1132.2178, 23.0603, 0.0000, 0.0000, -179.8000, -1, 0, -1, 400.0, 400.0, -1); //SAMPRoadSign19
    aldksadaaa[221] = CreateDynamicObject(19964, 1721.2623, -1132.2406, 25.4910, 0.0000, 0.0000, 179.8999, -1, 0, -1, 400.0, 400.0, -1); //SAMPRoadSign17
    aldksadaaa[222] = CreateDynamicObject(19956, 1722.6212, -1132.2259, 26.4039, 0.0000, 0.0000, -177.2000, -1, 0, -1, 400.0, 400.0, -1); //SAMPRoadSign9
    aldksadaaa[223] = CreateDynamicObject(19976, 1719.7631, -1132.2552, 25.9921, 0.0000, 0.0000, -179.9000, -1, 0, -1, 400.0, 400.0, -1); //SAMPRoadSign29
    aldksadaaa[224] = CreateDynamicObject(1084, 1723.6517, -1132.1483, 28.0424, 180.0000, 180.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //wheel_lr5
    aldksadaaa[225] = CreateDynamicObject(1083, 1722.4367, -1132.1203, 26.9818, 180.0000, 180.0000, -93.6000, -1, 0, -1, 400.0, 400.0, -1); //wheel_lr2
    aldksadaaa[226] = CreateDynamicObject(1080, 1722.8850, -1132.1551, 24.5725, 180.0000, 180.0000, -90.0000, -1, 0, -1, 400.0, 400.0, -1); //wheel_sr5
    aldksadaaa[227] = CreateDynamicObject(11701, 1721.3649, -1132.1999, 26.5473, 0.0000, -89.4000, -94.0000, -1, 0, -1, 400.0, 400.0, -1); //AmbulanceLights1
    aldksadaaa[228] = CreateDynamicObject(1096, 1719.7946, -1132.1097, 25.0427, 0.0000, 0.0000, 89.6000, -1, 0, -1, 400.0, 400.0, -1); //wheel_gn3
    aldksadaaa[229] = CreateDynamicObject(1096, 1730.5447, -1132.1850, 27.5027, 0.0000, 0.0000, 89.6000, -1, 0, -1, 400.0, 400.0, -1); //wheel_gn3
    aldksadaaa[230] = CreateDynamicObject(19433, 1757.9528, -1126.1075, 22.0198, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[230], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[231] = CreateDynamicObject(19433, 1752.5529, -1124.9476, 22.0198, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[231], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[232] = CreateDynamicObject(19433, 1757.9528, -1124.9868, 22.0198, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[232], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[233] = CreateDynamicObject(19433, 1752.5529, -1126.1075, 22.0198, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[233], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[234] = CreateDynamicObject(19433, 1757.9528, -1120.8878, 21.9998, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[234], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[235] = CreateDynamicObject(19433, 1752.4926, -1119.7077, 21.9928, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[235], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[236] = CreateDynamicObject(19433, 1757.2413, -1124.2674, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[236], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[237] = CreateDynamicObject(19433, 1755.8311, -1124.2674, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[237], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[238] = CreateDynamicObject(19433, 1754.3410, -1124.2674, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[238], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[239] = CreateDynamicObject(19433, 1753.3807, -1124.2674, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[239], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[240] = CreateDynamicObject(19433, 1753.2606, -1126.9781, 21.9998, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[240], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[241] = CreateDynamicObject(19433, 1754.7708, -1126.9781, 21.9998, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[241], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[242] = CreateDynamicObject(19433, 1756.2210, -1126.9781, 21.9998, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[242], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[243] = CreateDynamicObject(19433, 1757.2413, -1126.9781, 21.9998, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[243], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[244] = CreateDynamicObject(19433, 1755.7840, -1112.5422, 21.9997, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[244], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[245] = CreateDynamicObject(19433, 1754.7092, -1112.4919, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[245], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[246] = CreateDynamicObject(3785, 1738.2862, -1134.3532, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[247] = CreateDynamicObject(19433, 1757.9528, -1119.7080, 21.9997, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[247], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[248] = CreateDynamicObject(19433, 1757.2413, -1121.7176, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[248], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[249] = CreateDynamicObject(19433, 1755.6513, -1121.7176, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[249], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[250] = CreateDynamicObject(19433, 1754.1013, -1121.7176, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[250], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[251] = CreateDynamicObject(19433, 1753.2214, -1121.7176, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[251], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[252] = CreateDynamicObject(19433, 1753.2214, -1118.9975, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[252], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[253] = CreateDynamicObject(19433, 1754.7712, -1118.9975, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[253], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[254] = CreateDynamicObject(19433, 1757.0811, -1118.9975, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[254], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[255] = CreateDynamicObject(19433, 1755.9407, -1118.9975, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[255], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[256] = CreateDynamicObject(19433, 1752.4926, -1120.9980, 21.9928, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[256], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[257] = CreateDynamicObject(19433, 1749.2606, -1117.6683, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[257], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[258] = CreateDynamicObject(19433, 1749.2606, -1115.1086, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[258], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[259] = CreateDynamicObject(19433, 1750.8308, -1115.1086, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[259], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[260] = CreateDynamicObject(19433, 1752.3614, -1115.1086, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[260], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[261] = CreateDynamicObject(19433, 1753.1414, -1115.1086, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[261], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[262] = CreateDynamicObject(19433, 1753.1414, -1117.6685, 21.9997, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[262], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[263] = CreateDynamicObject(19433, 1751.5620, -1117.6685, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[263], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[264] = CreateDynamicObject(19433, 1750.4114, -1117.6685, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[264], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[265] = CreateDynamicObject(19433, 1753.8714, -1115.8270, 21.9998, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[265], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[266] = CreateDynamicObject(19433, 1753.8714, -1116.9576, 21.9998, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[266], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[267] = CreateDynamicObject(19433, 1748.5114, -1115.8270, 22.0098, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[267], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[268] = CreateDynamicObject(19433, 1748.5114, -1116.9577, 22.0098, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[268], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[269] = CreateDynamicObject(19433, 1749.0115, -1124.0380, 22.0097, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[269], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[270] = CreateDynamicObject(19433, 1747.6817, -1124.0380, 22.0097, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[270], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[271] = CreateDynamicObject(19433, 1746.1608, -1124.0380, 22.0097, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[271], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[272] = CreateDynamicObject(19433, 1745.1707, -1124.0380, 22.0097, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[272], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[273] = CreateDynamicObject(19433, 1744.4405, -1123.3280, 22.0097, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[273], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[274] = CreateDynamicObject(19433, 1744.4405, -1122.0074, 22.0097, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[274], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[275] = CreateDynamicObject(19433, 1749.7502, -1122.0074, 22.0097, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[275], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[276] = CreateDynamicObject(19433, 1749.7502, -1123.3182, 22.0097, 0.0000, 0.0000, 180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[276], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[277] = CreateDynamicObject(19433, 1748.9908, -1121.2980, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[277], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[278] = CreateDynamicObject(19433, 1747.7009, -1121.2980, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[278], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[279] = CreateDynamicObject(19433, 1746.5704, -1121.2980, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[279], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[280] = CreateDynamicObject(19433, 1745.2299, -1121.2980, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[280], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[281] = CreateDynamicObject(19433, 1745.9578, -1113.9537, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[281], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[282] = CreateDynamicObject(19433, 1745.2454, -1113.2656, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[282], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[283] = CreateDynamicObject(19433, 1749.0942, -1109.2811, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[283], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[284] = CreateDynamicObject(19433, 1752.1469, -1107.0996, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[284], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[285] = CreateDynamicObject(19433, 1752.7950, -1107.7254, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[285], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[286] = CreateDynamicObject(19433, 1756.3240, -1104.0715, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[286], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[287] = CreateDynamicObject(948, 1773.9069, -1125.1232, 23.0536, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Plant_Pot_10
    aldksadaaa[288] = CreateDynamicObject(19433, 1749.8063, -1109.9685, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[288], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[289] = CreateDynamicObject(19433, 1755.6763, -1103.4453, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[289], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[290] = CreateDynamicObject(19433, 1750.7998, -1103.6290, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[290], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[291] = CreateDynamicObject(19433, 1750.0083, -1102.8645, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[291], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[292] = CreateDynamicObject(19433, 1746.4099, -1106.5911, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[292], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[293] = CreateDynamicObject(19433, 1747.2010, -1107.3551, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[293], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[294] = CreateDynamicObject(948, 1773.9069, -1128.0338, 23.0536, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Plant_Pot_10
    aldksadaaa[295] = CreateDynamicObject(948, 1773.9069, -1130.9543, 23.0536, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //Plant_Pot_10
    aldksadaaa[296] = CreateDynamicObject(638, 1761.5029, -1099.7869, 23.4373, 0.0000, 0.0000, -179.4000, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
    aldksadaaa[297] = CreateDynamicObject(638, 1761.5604, -1105.2570, 23.4373, 0.0000, 0.0000, -179.4000, -1, 0, -1, 400.0, 400.0, -1); //kb_planter+bush
    aldksadaaa[298] = CreateDynamicObject(19433, 1758.4327, -1108.6364, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[298], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[299] = CreateDynamicObject(19433, 1757.6842, -1107.9134, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[299], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[300] = CreateDynamicObject(19433, 1753.9606, -1111.7692, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[300], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[301] = CreateDynamicObject(19433, 1756.7668, -1111.5175, 21.9997, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[301], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[302] = CreateDynamicObject(19433, 1757.7774, -1110.4635, 21.9997, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[302], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[303] = CreateDynamicObject(19433, 1758.5185, -1109.6906, 21.9997, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[303], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[304] = CreateDynamicObject(19433, 1756.5992, -1107.8492, 21.9997, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[304], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[305] = CreateDynamicObject(19433, 1755.5399, -1108.9537, 21.9997, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[305], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[306] = CreateDynamicObject(19433, 1754.5361, -1110.0003, 21.9997, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[306], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[307] = CreateDynamicObject(19433, 1753.8718, -1110.6932, 21.9997, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[307], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[308] = CreateDynamicObject(19433, 1749.7283, -1111.0698, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[308], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[309] = CreateDynamicObject(19433, 1748.6483, -1112.1962, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[309], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[310] = CreateDynamicObject(19433, 1747.5478, -1113.3439, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[310], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[311] = CreateDynamicObject(19433, 1746.9736, -1113.9426, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[311], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[312] = CreateDynamicObject(19433, 1745.1763, -1112.2189, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[312], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[313] = CreateDynamicObject(19433, 1746.2218, -1111.1290, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[313], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[314] = CreateDynamicObject(19433, 1747.2877, -1110.0172, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[314], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[315] = CreateDynamicObject(19433, 1748.0283, -1109.2452, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[315], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[316] = CreateDynamicObject(19433, 1752.0561, -1106.0279, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[316], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[317] = CreateDynamicObject(19433, 1753.1223, -1104.9162, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[317], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[318] = CreateDynamicObject(19433, 1754.1324, -1103.8627, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[318], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[319] = CreateDynamicObject(19433, 1754.5893, -1103.3867, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[319], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[320] = CreateDynamicObject(19433, 1756.4306, -1105.1660, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[320], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[321] = CreateDynamicObject(19433, 1755.3510, -1106.2916, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[321], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[322] = CreateDynamicObject(19433, 1754.3127, -1107.3745, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[322], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[323] = CreateDynamicObject(19433, 1753.9045, -1107.8002, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[323], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[324] = CreateDynamicObject(19433, 1749.7651, -1105.7722, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[324], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[325] = CreateDynamicObject(19433, 1750.8386, -1104.6525, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[325], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[326] = CreateDynamicObject(19433, 1748.6646, -1106.9201, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[326], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[327] = CreateDynamicObject(19433, 1748.2354, -1107.3677, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[327], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[328] = CreateDynamicObject(19433, 1746.4022, -1105.5953, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[328], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[329] = CreateDynamicObject(19433, 1746.4084, -1105.5596, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[329], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[330] = CreateDynamicObject(19433, 1747.4886, -1104.4329, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[330], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[331] = CreateDynamicObject(19433, 1748.4305, -1103.4514, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[331], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[332] = CreateDynamicObject(19433, 1748.9775, -1102.8812, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[332], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[333] = CreateDynamicObject(19433, 1746.1156, -1126.7580, 22.0197, 0.0000, 0.0000, 144.8002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[333], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[334] = CreateDynamicObject(19433, 1750.6353, -1129.9454, 22.0197, 0.0000, 0.0000, 144.8002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[334], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[335] = CreateDynamicObject(19433, 1749.8741, -1131.0239, 22.0197, 0.0000, 0.0000, 144.8002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[335], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[336] = CreateDynamicObject(19433, 1745.3896, -1127.7873, 22.0197, 0.0000, 0.0000, 144.8002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[336], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[337] = CreateDynamicObject(19433, 1745.4482, -1128.9287, 22.0197, 0.0000, 0.0000, 54.3002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[337], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[338] = CreateDynamicObject(19433, 1746.6748, -1129.8104, 22.0197, 0.0000, 0.0000, 54.3002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[338], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[339] = CreateDynamicObject(19433, 1747.9018, -1130.6917, 22.0197, 0.0000, 0.0000, 54.3002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[339], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[340] = CreateDynamicObject(19433, 1748.7884, -1131.3286, 22.0197, 0.0000, 0.0000, 54.3002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[340], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[341] = CreateDynamicObject(19433, 1750.4597, -1128.9337, 22.0197, 0.0000, 0.0000, 54.3002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[341], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[342] = CreateDynamicObject(19433, 1749.2572, -1128.0700, 22.0197, 0.0000, 0.0000, 54.3002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[342], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[343] = CreateDynamicObject(19433, 1748.0874, -1127.2294, 22.0197, 0.0000, 0.0000, 54.3002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[343], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[344] = CreateDynamicObject(19433, 1747.1365, -1126.5463, 22.0197, 0.0000, 0.0000, 54.3002, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[344], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[345] = CreateDynamicObject(19433, 1730.1224, -1114.5655, 22.0097, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[345], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[346] = CreateDynamicObject(19433, 1721.7509, -1113.9770, 22.0497, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[346], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[347] = CreateDynamicObject(19433, 1730.1279, -1113.1872, 22.0097, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[347], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[348] = CreateDynamicObject(19433, 1729.3885, -1112.4671, 22.0097, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[348], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[349] = CreateDynamicObject(19433, 1727.7886, -1112.4671, 22.0097, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[349], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[350] = CreateDynamicObject(19433, 1720.2409, -1113.9770, 22.0497, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[350], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[351] = CreateDynamicObject(19433, 1718.7110, -1113.9770, 22.0497, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[351], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[352] = CreateDynamicObject(19433, 1717.8818, -1113.9770, 22.0497, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[352], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[353] = CreateDynamicObject(19433, 1726.2089, -1112.4671, 22.0097, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[353], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[354] = CreateDynamicObject(19433, 1717.8818, -1111.3658, 22.0497, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[354], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[355] = CreateDynamicObject(19433, 1725.3184, -1112.4671, 22.0097, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[355], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[356] = CreateDynamicObject(19433, 1724.5585, -1113.1770, 22.0097, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[356], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[357] = CreateDynamicObject(19433, 1719.3818, -1111.3658, 22.0497, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[357], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[358] = CreateDynamicObject(19433, 1720.8619, -1111.3658, 22.0497, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[358], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[359] = CreateDynamicObject(19433, 1721.7816, -1111.3658, 22.0497, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[359], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[360] = CreateDynamicObject(19433, 1724.5585, -1114.4866, 22.0098, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[360], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[361] = CreateDynamicObject(19433, 1722.5384, -1113.2667, 22.0398, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[361], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[362] = CreateDynamicObject(19433, 1725.2689, -1115.3271, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[362], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[363] = CreateDynamicObject(19433, 1722.5384, -1112.0760, 22.0398, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[363], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[364] = CreateDynamicObject(19433, 1717.1583, -1112.0760, 22.0398, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[364], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[365] = CreateDynamicObject(19433, 1726.8588, -1115.3271, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[365], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[366] = CreateDynamicObject(19433, 1728.4589, -1115.3271, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[366], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[367] = CreateDynamicObject(19433, 1717.1583, -1113.2567, 22.0398, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[367], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[368] = CreateDynamicObject(19433, 1729.4097, -1115.3271, 22.0098, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[368], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[369] = CreateDynamicObject(19433, 1717.1583, -1107.8959, 22.0197, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[369], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[370] = CreateDynamicObject(19433, 1723.0043, -1104.1877, 22.0198, 0.0000, 0.0000, 137.5999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[370], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[371] = CreateDynamicObject(19433, 1723.8607, -1103.2500, 22.0198, 0.0000, 0.0000, 137.5999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[371], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[372] = CreateDynamicObject(19433, 1717.1583, -1106.7161, 22.0197, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[372], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[373] = CreateDynamicObject(19433, 1723.9244, -1102.1210, 22.0198, 0.0000, 0.0000, 47.8999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[373], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[374] = CreateDynamicObject(19433, 1722.7586, -1106.7161, 22.0197, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[374], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[375] = CreateDynamicObject(19433, 1722.7586, -1107.7266, 22.0197, 0.0000, 0.0000, -180.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[375], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[376] = CreateDynamicObject(19433, 1717.9302, -1108.6079, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[376], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[377] = CreateDynamicObject(19433, 1721.9897, -1104.2304, 22.0198, 0.0000, 0.0000, 47.8999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[377], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[378] = CreateDynamicObject(19433, 1720.8176, -1103.1711, 22.0198, 0.0000, 0.0000, 47.8999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[378], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[379] = CreateDynamicObject(19433, 1719.6522, -1102.1181, 22.0198, 0.0000, 0.0000, 47.8999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[379], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[380] = CreateDynamicObject(19433, 1718.9772, -1101.5080, 22.0198, 0.0000, 0.0000, 47.8999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[380], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[381] = CreateDynamicObject(19433, 1722.7430, -1101.0556, 22.0198, 0.0000, 0.0000, 47.8999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[381], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[382] = CreateDynamicObject(19433, 1721.5776, -1100.0025, 22.0198, 0.0000, 0.0000, 47.8999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[382], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[383] = CreateDynamicObject(19433, 1718.9371, -1100.4953, 22.0198, 0.0000, 0.0000, -42.1999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[383], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[384] = CreateDynamicObject(19433, 1719.4503, -1108.6079, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[384], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[385] = CreateDynamicObject(19433, 1721.0402, -1108.6079, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[385], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[386] = CreateDynamicObject(19433, 1722.0401, -1105.9875, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[386], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[387] = CreateDynamicObject(19433, 1727.0095, -1099.3458, 22.0198, 0.0000, 0.0000, 123.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[387], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[388] = CreateDynamicObject(19433, 1719.8840, -1099.4512, 22.0198, 0.0000, 0.0000, -42.1999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[388], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[389] = CreateDynamicObject(19433, 1720.9091, -1099.3989, 22.0198, 0.0000, 0.0000, 47.8999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[389], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[390] = CreateDynamicObject(19433, 1722.0401, -1108.6079, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[390], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[391] = CreateDynamicObject(19433, 1729.2412, -1104.9964, 22.0198, 0.0000, 0.0000, 124.5000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[391], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[392] = CreateDynamicObject(19433, 1720.5006, -1105.9875, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[392], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[393] = CreateDynamicObject(19433, 1718.9699, -1105.9875, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[393], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[394] = CreateDynamicObject(19433, 1717.8789, -1105.9875, 22.0298, 0.0000, 0.0000, 90.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[394], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[395] = CreateDynamicObject(19433, 1730.3620, -1104.2260, 22.0198, 0.0000, 0.0000, 124.5000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[395], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[396] = CreateDynamicObject(19433, 1728.1429, -1099.4575, 22.0198, 0.0000, 0.0000, -146.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[396], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[397] = CreateDynamicObject(19433, 1728.2371, -1104.7806, 22.0198, 0.0000, 0.0000, -146.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[397], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[398] = CreateDynamicObject(19433, 1729.0292, -1100.7773, 22.0198, 0.0000, 0.0000, -146.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[398], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[399] = CreateDynamicObject(19433, 1729.8079, -1118.6398, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[399], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[400] = CreateDynamicObject(19433, 1729.9105, -1102.0888, 22.0198, 0.0000, 0.0000, -146.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[400], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[401] = CreateDynamicObject(19433, 1730.6361, -1103.1679, 22.0198, 0.0000, 0.0000, -146.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[401], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[402] = CreateDynamicObject(19433, 1727.3452, -1103.4525, 22.0198, 0.0000, 0.0000, -146.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[402], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[403] = CreateDynamicObject(19433, 1726.4643, -1102.1409, 22.0198, 0.0000, 0.0000, -146.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[403], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[404] = CreateDynamicObject(19433, 1725.7559, -1101.0867, 22.0198, 0.0000, 0.0000, -146.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[404], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[405] = CreateDynamicObject(19433, 1726.0284, -1122.5535, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[405], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[406] = CreateDynamicObject(19433, 1725.9204, -1100.0556, 22.0198, 0.0000, 0.0000, 123.1000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[406], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[407] = CreateDynamicObject(19433, 1731.4794, -1111.0549, 22.0198, 0.0000, 0.0000, 155.4999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[407], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[408] = CreateDynamicObject(19433, 1725.3160, -1121.8657, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[408], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[409] = CreateDynamicObject(19433, 1729.0950, -1117.9522, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[409], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[410] = CreateDynamicObject(19433, 1731.9979, -1109.9174, 22.0198, 0.0000, 0.0000, 155.4999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[410], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[411] = CreateDynamicObject(19433, 1726.5177, -1107.4196, 22.0198, 0.0000, 0.0000, 155.4999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[411], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[412] = CreateDynamicObject(19433, 1728.9765, -1107.5888, 22.0198, 0.0000, 0.0000, 65.9999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[412], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[413] = CreateDynamicObject(19433, 1727.5235, -1106.9425, 22.0198, 0.0000, 0.0000, 65.9999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[413], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[414] = CreateDynamicObject(19433, 1729.9156, -1119.7387, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[414], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[415] = CreateDynamicObject(19433, 1730.4205, -1108.2314, 22.0198, 0.0000, 0.0000, 65.9999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[415], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[416] = CreateDynamicObject(19433, 1731.7186, -1108.8089, 22.0198, 0.0000, 0.0000, 65.9999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[416], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[417] = CreateDynamicObject(19433, 1730.5065, -1111.4337, 22.0198, 0.0000, 0.0000, 65.9999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[417], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[418] = CreateDynamicObject(19433, 1728.8150, -1120.8863, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[418], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[419] = CreateDynamicObject(19433, 1727.7421, -1122.0051, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[419], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[420] = CreateDynamicObject(19433, 1729.0529, -1110.7869, 22.0198, 0.0000, 0.0000, 65.9999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[420], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[421] = CreateDynamicObject(19433, 1727.1406, -1122.6333, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[421], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[422] = CreateDynamicObject(19433, 1725.2709, -1120.8403, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[422], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[423] = CreateDynamicObject(19433, 1727.6091, -1110.1447, 22.0198, 0.0000, 0.0000, 65.9999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[423], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[424] = CreateDynamicObject(19433, 1726.3115, -1109.5675, 22.0198, 0.0000, 0.0000, 65.9999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[424], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[425] = CreateDynamicObject(19433, 1726.1986, -1119.8731, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[425], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[426] = CreateDynamicObject(19433, 1725.9656, -1108.6315, 22.0198, 0.0000, 0.0000, 155.4999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[426], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[427] = CreateDynamicObject(19433, 1727.2160, -1118.8121, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[427], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[428] = CreateDynamicObject(19433, 1728.0537, -1117.9390, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[428], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[429] = CreateDynamicObject(19433, 1727.0548, -1126.3331, 21.9897, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[429], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[430] = CreateDynamicObject(19433, 1728.1140, -1125.2287, 21.9897, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[430], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[431] = CreateDynamicObject(19433, 1729.2080, -1124.0878, 21.9897, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[431], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[432] = CreateDynamicObject(19433, 1729.4023, -1123.8854, 21.9897, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[432], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[433] = CreateDynamicObject(19433, 1728.8137, -1128.2126, 21.9897, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[433], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[434] = CreateDynamicObject(19433, 1731.2574, -1125.6647, 21.9897, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[434], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[435] = CreateDynamicObject(19433, 1730.2052, -1126.7619, 21.9897, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[435], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[436] = CreateDynamicObject(19433, 1729.1391, -1127.8734, 21.9897, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[436], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[437] = CreateDynamicObject(19433, 1726.9594, -1126.4331, 21.9897, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[437], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[438] = CreateDynamicObject(19433, 1731.3531, -1124.5261, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[438], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[439] = CreateDynamicObject(19433, 1730.5473, -1123.7479, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[439], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[440] = CreateDynamicObject(19433, 1727.6859, -1128.3529, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[440], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[441] = CreateDynamicObject(19433, 1718.9046, -1120.4538, 22.0298, 0.0000, 0.0000, -141.6999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[441], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[442] = CreateDynamicObject(19433, 1726.8802, -1127.5749, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[442], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[443] = CreateDynamicObject(19433, 1724.3197, -1125.5761, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[443], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[444] = CreateDynamicObject(19433, 1723.4771, -1124.7623, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[444], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[445] = CreateDynamicObject(19433, 1719.7718, -1121.5529, 22.0298, 0.0000, 0.0000, -141.6999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[445], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[446] = CreateDynamicObject(19433, 1724.6608, -1117.6917, 22.0298, 0.0000, 0.0000, -141.6999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[446], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[447] = CreateDynamicObject(19433, 1719.7122, -1128.6605, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[447], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[448] = CreateDynamicObject(19433, 1723.7926, -1116.5920, 22.0298, 0.0000, 0.0000, -141.6999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[448], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[449] = CreateDynamicObject(19433, 1722.7742, -1116.4575, 22.0298, 0.0000, 0.0000, -51.2999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[449], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[450] = CreateDynamicObject(19433, 1723.2858, -1127.6931, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[450], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[451] = CreateDynamicObject(19433, 1720.5545, -1129.4747, 22.0298, 0.0000, 0.0000, -134.0000, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[451], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[452] = CreateDynamicObject(19433, 1721.5328, -1117.4512, 22.0298, 0.0000, 0.0000, -51.2999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[452], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[453] = CreateDynamicObject(19433, 1720.2923, -1118.4461, 22.0298, 0.0000, 0.0000, -51.2999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[453], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[454] = CreateDynamicObject(19433, 1719.0351, -1119.4519, 22.0298, 0.0000, 0.0000, -51.2999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[454], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[455] = CreateDynamicObject(19433, 1720.7937, -1121.6948, 22.0298, 0.0000, 0.0000, -51.2999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[455], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[456] = CreateDynamicObject(19433, 1722.0268, -1120.7070, 22.0298, 0.0000, 0.0000, -51.2999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[456], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[457] = CreateDynamicObject(19433, 1723.2597, -1119.7187, 22.0298, 0.0000, 0.0000, -51.2999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[457], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[458] = CreateDynamicObject(19433, 1724.4852, -1118.7373, 22.0298, 0.0000, 0.0000, -51.2999, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[458], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[459] = CreateDynamicObject(19433, 1724.3444, -1126.5883, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[459], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[460] = CreateDynamicObject(19433, 1722.2749, -1128.7471, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[460], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[461] = CreateDynamicObject(19433, 1721.5760, -1129.4758, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[461], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[462] = CreateDynamicObject(19433, 1719.6478, -1127.6136, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[462], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[463] = CreateDynamicObject(19433, 1720.6650, -1126.5527, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[463], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[464] = CreateDynamicObject(19433, 1721.7171, -1125.4552, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[464], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[465] = CreateDynamicObject(19433, 1722.4165, -1124.7263, 22.0197, 0.0000, 0.0000, 136.2001, -1, 0, -1, 400.0, 400.0, -1); //wall073
    SetDynamicObjectMaterial(aldksadaaa[465], 0, 14569, "traidman", "darkgrey_carpet_256", 0xFFFFFFFF);
    aldksadaaa[466] = CreateDynamicObject(3785, 1750.1558, -1134.3532, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[467] = CreateDynamicObject(3785, 1757.1564, -1134.3532, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[468] = CreateDynamicObject(3785, 1726.4456, -1134.3532, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[469] = CreateDynamicObject(3785, 1711.9251, -1134.3532, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[470] = CreateDynamicObject(3785, 1711.9251, -1121.4533, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[471] = CreateDynamicObject(3785, 1711.9251, -1107.9030, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[472] = CreateDynamicObject(3785, 1711.9251, -1094.2918, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[473] = CreateDynamicObject(3785, 1723.3353, -1094.2918, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[474] = CreateDynamicObject(3785, 1753.8157, -1094.2918, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[475] = CreateDynamicObject(3785, 1765.7264, -1094.2918, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[476] = CreateDynamicObject(3785, 1765.7264, -1113.3319, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    aldksadaaa[477] = CreateDynamicObject(3785, 1765.7264, -1134.4432, 31.1249, 0.0000, 90.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //bulkheadlight
    return 1;
}