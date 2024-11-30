#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid){
    RemoveBuildingForPlayer(playerid, 10914, -1706.4766, 13.0156, 7.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 10831, -1706.4766, 13.0156, 7.4063, 0.25);
    return 1;
}

hook OnGameModeInit(){
    new KAKAKAKAAAA[24];
    KAKAKAKAAAA[0] = CreateDynamicObject(12943, -1702.9060, 6.2008, 2.5412, 0.0000, 0.0000, 130.9000, -1, 0, -1, 400.0, 400.0, -1); //sw_SHED07
    KAKAKAKAAAA[1] = CreateDynamicObject(2062, -1711.0144, 8.5745, 3.1136, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //CJ_OilDrum2
    KAKAKAKAAAA[2] = CreateDynamicObject(2957, -1702.3591, -0.5132, 4.0925, 0.0000, 0.0000, -49.0999, -1, 0, -1, 400.0, 400.0, -1); //chinaTgarageDoor
    KAKAKAKAAAA[3] = CreateDynamicObject(2509, -1699.7675, 8.6146, 5.2409, 0.0000, 0.0000, -48.6999, -1, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_6
    KAKAKAKAAAA[4] = CreateDynamicObject(2509, -1698.9030, 7.6305, 5.2409, 0.0000, 0.0000, -48.6999, -1, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_6
    KAKAKAKAAAA[5] = CreateDynamicObject(2509, -1698.0384, 6.6463, 5.2409, 0.0000, 0.0000, -48.6999, -1, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_6
    KAKAKAKAAAA[6] = CreateDynamicObject(2567, -1698.0201, 8.6035, 4.4241, 0.0000, 0.0000, -50.0000, -1, 0, -1, 400.0, 400.0, -1); //ab_warehouseShelf
    KAKAKAKAAAA[7] = CreateDynamicObject(2502, -1708.3146, 6.5604, 2.5511, 0.0000, 0.0000, 131.3999, -1, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_5
    KAKAKAKAAAA[8] = CreateDynamicObject(2502, -1707.4152, 5.5402, 2.5511, 0.0000, 0.0000, 131.3999, -1, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_5
    KAKAKAKAAAA[9] = CreateDynamicObject(19893, -1708.2153, 6.7482, 3.5881, 0.0000, 0.0000, 122.8000, -1, 0, -1, 400.0, 400.0, -1); //LaptopSAMP1
    KAKAKAKAAAA[10] = CreateDynamicObject(19817, -1700.9268, 3.8847, 2.0454, 0.0000, 0.0000, -138.7999, -1, 0, -1, 400.0, 400.0, -1); //CarFixerRamp1
    KAKAKAKAAAA[11] = CreateDynamicObject(1744, -1704.0886, 13.9425, 3.3394, 0.0000, 0.0000, -49.1000, -1, 0, -1, 400.0, 400.0, -1); //MED_SHELF
    KAKAKAKAAAA[12] = CreateDynamicObject(1744, -1702.8172, 12.4761, 3.3394, 0.0000, 0.0000, -49.1000, -1, 0, -1, 400.0, 400.0, -1); //MED_SHELF
    KAKAKAKAAAA[13] = CreateDynamicObject(1744, -1701.5467, 11.0097, 3.3394, 0.0000, 0.0000, -49.1000, -1, 0, -1, 400.0, 400.0, -1); //MED_SHELF
    KAKAKAKAAAA[14] = CreateDynamicObject(2475, -1695.5017, 2.1839, 2.5561, 0.0000, 0.0000, -139.3996, -1, 0, -1, 400.0, 400.0, -1); //CJ_HOBBY_SHELF_3
    KAKAKAKAAAA[15] = CreateDynamicObject(16779, -1702.9869, 5.9869, 8.1680, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //ufo_light02
    KAKAKAKAAAA[16] = CreateDynamicObject(1893, -1700.4034, 3.3388, 8.1865, 0.0000, 0.0000, -47.6999, -1, 0, -1, 400.0, 400.0, -1); //shoplight1
    KAKAKAKAAAA[17] = CreateDynamicObject(1893, -1706.6557, 10.2100, 8.1865, 0.0000, 0.0000, -47.6999, -1, 0, -1, 400.0, 400.0, -1); //shoplight1
    KAKAKAKAAAA[18] = CreateDynamicObject(19898, -1700.5916, 3.8203, 2.5589, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
    KAKAKAKAAAA[19] = CreateDynamicObject(19898, -1703.9519, 11.1903, 2.5689, 0.0000, 0.0000, 112.8000, -1, 0, -1, 400.0, 400.0, -1); //OilFloorStain1
    KAKAKAKAAAA[20] = CreateDynamicObject(19621, -1703.2690, 12.5615, 3.7789, 0.0000, 0.0000, -112.1000, -1, 0, -1, 400.0, 400.0, -1); //OilCan1
    KAKAKAKAAAA[21] = CreateDynamicObject(1098, -1707.3858, 5.8514, 2.9965, 0.0000, 0.0000, 40.2999, -1, 0, -1, 400.0, 400.0, -1); //wheel_gn5
    KAKAKAKAAAA[22] = CreateDynamicObject(1442, -1702.4293, 12.7998, 3.1231, 0.0000, 0.0000, 0.0000, -1, 0, -1, 400.0, 400.0, -1); //DYN_FIREBIN0
    KAKAKAKAAAA[23] = CreateDynamicObject(19425, -1707.9558, 12.1044, 2.5442, 0.0000, 0.0000, 39.2999, -1, 0, -1, 400.0, 400.0, -1); //speed_bump01
    return 1;
}