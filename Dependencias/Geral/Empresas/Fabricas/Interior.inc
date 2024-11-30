#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    // CreateDynamicObject(987, 2535.54980, -1272.01416, 1047.28247,   0.00000, 0.00000, -91.00000, vwid, 2, -1, 150.0, 150.0, -1);
    // CreateDynamicObject(5422, 2577.71729, -1290.02307, 1045.00000,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    
    // Exterior
    CreateDynamicObject(3037, -1855.64673, 110.04860, 16.28290,   0.00000, 0.00000, 90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(11714, -1840.24866, 110.11530, 15.34890,   0.00000, 0.00000, 90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1819.85339, 170.54466, 15.70310,   0.00000, 0.00000, 270.60001, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1822.70911, 173.32297, 15.70310,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1827.94507, 173.32300, 15.70310,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1833.18115, 173.32300, 15.70310,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1838.41724, 173.32300, 15.70310,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1843.65320, 173.32300, 15.70310,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1848.88916, 173.32300, 15.70310,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1854.12524, 173.32300, 15.70310,   0.00000, 0.00000, 0.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(967, -1820.39514, 156.43378, 14.05891,   0.00000, 0.00000, 3.10317, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1817.44922, -5.75090, 15.70310,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1817.44922, -0.51490, 15.70310,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1817.44922, 4.72110, 15.70310,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(1411, -1817.44922, 9.95710, 15.70310,   0.00000, 0.00000, -90.00000, -1, 0, -1, 450.0, 450.0, -1);
    CreateDynamicObject(11714, 2447.51416, -2121.62695, 13.72626,   0.00000, 0.00000, 90.00000, -1, 0, -1, 450.0, 450.0, -1);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 922, 2565.6250, -1292.9609, 1044.0156, 0.25);
    RemoveBuildingForPlayer(playerid, 1499, 2577.8516, -1291.4063, 1043.1172, 0.25);
    RemoveBuildingForPlayer(playerid, 1499, 2577.8359, -1288.3984, 1043.1172, 0.25);
    return 1;
}

stock CarregarObjetosFabrica(id, vwid)
{
    FabricaOBJ[id][0] = CreateDynamicObject(987, 2535.54980, -1272.01416, 1047.28247,   0.00000, 0.00000, -91.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][1] = CreateDynamicObject(5422, 2577.71729, -1290.02307, 1045.00000,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][2] = CreateDynamicObject(19893, 2542.70361, -1302.65979, 1044.07617,   0.00000, 0.00000, -90.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][3] = CreateDynamicObject(19893, 2542.71875, -1304.57947, 1044.07617,   0.00000, 0.00000, -91.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][4] = CreateDynamicObject(1811, 2541.35522, -1304.60852, 1043.69995,   0.00000, 0.00000, -181.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][5] = CreateDynamicObject(1811, 2561.16406, -1304.50098, 1043.69995,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][6] = CreateDynamicObject(2059, 2558.91528, -1282.75476, 1044.08997,   0.00000, 0.00000, -105.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][7] = CreateDynamicObject(2059, 2558.70361, -1300.91235, 1044.08997,   0.00000, 0.00000, -2.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][8] = CreateDynamicObject(1329, 2551.24072, -1305.82813, 1052.00000,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][9] = CreateDynamicObject(1329, 2559.03369, -1280.21460, 1043.59998,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][10] = CreateDynamicObject(19835, 2542.73633, -1302.10803, 1044.15002,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][11] = CreateDynamicObject(19835, 2542.80493, -1304.00024, 1044.15002,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][12] = CreateDynamicObject(19893, 2551.50195, -1282.87927, 1044.07617,   0.00000, 0.00000, 90.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][13] = CreateDynamicObject(19893, 2559.43140, -1304.56848, 1044.07617,   0.00000, 0.00000, 90.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][14] = CreateDynamicObject(19835, 2559.42822, -1303.82410, 1044.15002,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][15] = CreateDynamicObject(19835, 2559.44263, -1302.09143, 1044.15002,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][16] = CreateDynamicObject(1811, 2560.96411, -1284.79675, 1043.69995,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][17] = CreateDynamicObject(1811, 2541.30859, -1302.71814, 1043.69995,   0.00000, 0.00000, 182.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][18] = CreateDynamicObject(2059, 2551.23633, -1303.07043, 1044.08997,   0.00000, 0.00000, -30.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][19] = CreateDynamicObject(2610, 2570.79663, -1281.09973, 1043.56006,   0.00000, 0.00000, -88.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][20] = CreateDynamicObject(2610, 2570.77783, -1280.17542, 1043.90002,   0.00000, 0.00000, -88.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][21] = CreateDynamicObject(2610, 2570.78687, -1280.63660, 1043.56006,   0.00000, 0.00000, -88.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][22] = CreateDynamicObject(2063, 2537.59399, -1307.12415, 1044.00000,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][23] = CreateDynamicObject(2063, 2532.41748, -1307.15649, 1044.00000,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][24] = CreateDynamicObject(2063, 2534.99707, -1307.13489, 1044.00000,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][25] = CreateDynamicObject(19893, 2559.46411, -1302.57813, 1044.07617,   0.00000, 0.00000, 90.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][26] = CreateDynamicObject(19893, 2559.43872, -1282.66479, 1044.07617,   0.00000, 0.00000, 90.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][27] = CreateDynamicObject(1811, 2553.11768, -1302.37378, 1043.69995,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][28] = CreateDynamicObject(1811, 2561.13818, -1302.33350, 1043.69995,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][29] = CreateDynamicObject(1811, 2569.39990, -1289.94421, 1043.69995,   0.00000, 0.00000, 182.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][30] = CreateDynamicObject(1329, 2559.00317, -1306.97778, 1043.59998,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][31] = CreateDynamicObject(2605, 2570.23169, -1290.09229, 1043.50000,   0.00000, 0.00000, -88.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][32] = CreateDynamicObject(14444, 2552.38965, -1299.85217, 1059.80469,   356.85840, 0.00000, 3.14159, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][33] = CreateDynamicObject(1811, 2553.00806, -1284.68677, 1043.69995,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][34] = CreateDynamicObject(922, 2565.71802, -1306.86584, 1044.00000,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][35] = CreateDynamicObject(19893, 2551.57422, -1304.50195, 1044.07617,   0.00000, 0.00000, 90.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][36] = CreateDynamicObject(19893, 2551.58667, -1302.60303, 1044.07617,   0.00000, 0.00000, 90.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][37] = CreateDynamicObject(1811, 2553.10913, -1304.54126, 1043.69995,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][38] = CreateDynamicObject(1811, 2553.13770, -1302.37402, 1043.69995,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][39] = CreateDynamicObject(2059, 2551.09277, -1305.04968, 1044.08997,   0.00000, 0.00000, -2.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][40] = CreateDynamicObject(2059, 2559.01733, -1303.48120, 1044.08997,   0.00000, 0.00000, -2.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][41] = CreateDynamicObject(2059, 2559.31396, -1300.90649, 1044.08997,   0.00000, 0.00000, -2.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][42] = CreateDynamicObject(19835, 2551.50415, -1301.98474, 1044.15002,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][43] = CreateDynamicObject(19835, 2551.51880, -1303.92407, 1044.15002,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][44] = CreateDynamicObject(1329, 2542.69580, -1307.06042, 1043.59998,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][45] = CreateDynamicObject(1329, 2551.05249, -1307.04724, 1043.59998,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][46] = CreateDynamicObject(1811, 2552.94946, -1282.82837, 1043.69995,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][47] = CreateDynamicObject(1811, 2560.89355, -1282.60767, 1043.69995,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][48] = CreateDynamicObject(1329, 2551.19653, -1280.24023, 1043.59998,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][49] = CreateDynamicObject(19893, 2551.50537, -1284.75195, 1044.07617,   0.00000, 0.00000, 90.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][50] = CreateDynamicObject(19893, 2559.49243, -1284.76270, 1044.07617,   0.00000, 0.00000, 90.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][51] = CreateDynamicObject(2059, 2551.03638, -1300.87451, 1044.08997,   0.00000, 0.00000, -30.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][52] = CreateDynamicObject(2059, 2550.81372, -1286.07739, 1044.08997,   0.00000, 0.00000, -30.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][53] = CreateDynamicObject(2059, 2551.42017, -1286.06421, 1044.08997,   0.00000, 0.00000, -30.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][54] = CreateDynamicObject(2059, 2551.05835, -1283.67712, 1044.08997,   0.00000, 0.00000, -30.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][55] = CreateDynamicObject(2059, 2559.58008, -1286.17126, 1044.08997,   0.00000, 0.00000, -30.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][56] = CreateDynamicObject(2059, 2559.58008, -1286.17126, 1044.08997,   0.00000, 0.00000, -30.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][57] = CreateDynamicObject(2059, 2558.77051, -1286.39063, 1044.08997,   0.00000, 0.00000, -30.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][58] = CreateDynamicObject(2059, 2559.00586, -1284.53381, 1044.08997,   0.00000, 0.00000, -105.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][59] = CreateDynamicObject(2059, 2558.91528, -1282.75476, 1044.08997,   0.00000, 0.00000, -105.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][60] = CreateDynamicObject(922, 2565.46558, -1280.60217, 1044.00000,   0.00000, 0.00000, 0.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][61] = CreateDynamicObject(2605, 2570.37964, -1294.83655, 1043.50000,   0.00000, 0.00000, -88.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][62] = CreateDynamicObject(2605, 2570.37964, -1294.83655, 1043.50000,   0.00000, 0.00000, -88.00000, vwid, 2, -1, 150.0, 150.0, -1);
    FabricaOBJ[id][63] = CreateDynamicObject(1811, 2569.64648, -1294.83972, 1043.69995,   0.00000, 0.00000, 182.00000, vwid, 2, -1, 150.0, 150.0, -1);
    return 1;
}

stock ColocarProducaoFabrica(id, vwid)
{
    FabricaText[id][0] = CreateDynamic3DTextLabel("{1E90FF}Produção\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para iniciar", -1, 2544.3262,-1295.9891,1044.1250, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vwid, 2, -1, 20.0, -1);
    FabricaText[id][1] = CreateDynamic3DTextLabel("{1E90FF}Produção\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para iniciar", -1, 2556.0674,-1290.6074,1044.1250, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vwid, 2, -1, 20.0, -1);
    FabricaText[id][2] = CreateDynamic3DTextLabel("{1E90FF}Produção\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para iniciar", -1, 2544.4932,-1283.4766,1044.1250, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vwid, 2, -1, 20.0, -1);
    FabricaText[id][3] = CreateDynamic3DTextLabel("{1E90FF}Produção\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para iniciar", -1, 2542.1394,-1303.8527,1044.1250, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vwid, 2, -1, 20.0, -1);
    FabricaText[id][4] = CreateDynamic3DTextLabel("{1E90FF}Produção\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para iniciar", -1, 2557.7732,-1295.9276,1044.1250, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vwid, 2, -1, 20.0, -1);
    FabricaText[id][5] = CreateDynamic3DTextLabel("{1E90FF}Fábrica\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para visualizar", -1, 2569.4436,-1289.2560,1044.1250, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vwid, 2, -1, 35.0, -1);
    return 1;
}

stock RemoverObjetosFabrica(id)
{
    for(new i=0; i < 64; i++)
    {
        DestroyDynamicObjectEx(FabricaOBJ[id][i]);
    }
    return 1;
}

stock RemoverProducaoFabrica(id)
{
    for(new i=0; i < 6; i++)
    {
        DestroyDynamic3DTextLabel(FabricaText[id][i]);
    }
    return 1;
}