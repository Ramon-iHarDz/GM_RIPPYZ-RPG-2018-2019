#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    new DSADLKAS[518];
    DSADLKAS[0] = CreateDynamicObject(19378, 2637.3867, -1697.5539, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[0], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[1] = CreateDynamicObject(1280, 2577.6157, -1704.3828, 1015.9171, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[2] = CreateDynamicObject(19378, 2612.7199, -1721.4553, 90.0000, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[2], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[3] = CreateDynamicObject(19378, 2654.4370, -1711.8260, 1015.7659, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[3], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[4] = CreateDynamicObject(2754, 2619.5517, -1725.4613, 1016.4953, 0.0000, 360.0000, -89.9001, 1064, 1, -1, 300.0, 300.0, -1); //OTB_machine
    DSADLKAS[5] = CreateDynamicObject(1280, 2610.8200, -1752.1118, 1015.9071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[6] = CreateDynamicObject(10930, 2602.6616, -1705.2336, 1015.5604, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //roadsSFSE24
    DSADLKAS[7] = CreateDynamicObject(19381, 2638.8359, -1711.8459, 1015.5026, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[7], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    DSADLKAS[8] = CreateDynamicObject(19381, 2587.4296, -1652.9150, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[8], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[9] = CreateDynamicObject(4603, 2562.8464, -1711.9991, 1035.8198, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //sky4plaz2_LAn
    DSADLKAS[10] = CreateDynamicObject(792, 2595.2084, -1648.3481, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[11] = CreateDynamicObject(792, 2595.2084, -1654.8901, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[12] = CreateDynamicObject(792, 2595.2084, -1661.7314, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[13] = CreateDynamicObject(792, 2595.2084, -1668.3612, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[14] = CreateDynamicObject(792, 2595.2084, -1675.1429, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[15] = CreateDynamicObject(792, 2595.2084, -1681.8138, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[16] = CreateDynamicObject(792, 2595.2084, -1688.3740, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[17] = CreateDynamicObject(792, 2595.2084, -1695.1152, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[18] = CreateDynamicObject(792, 2595.2084, -1701.6855, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[19] = CreateDynamicObject(792, 2595.2084, -1728.3459, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[20] = CreateDynamicObject(792, 2595.2084, -1735.0764, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[21] = CreateDynamicObject(792, 2595.2084, -1741.8470, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[22] = CreateDynamicObject(792, 2595.2084, -1748.3680, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[23] = CreateDynamicObject(792, 2595.2084, -1755.1297, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[24] = CreateDynamicObject(792, 2595.2084, -1761.8015, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[25] = CreateDynamicObject(1280, 2610.8200, -1665.3808, 1015.9071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[26] = CreateDynamicObject(1297, 2597.7255, -1731.7104, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[27] = CreateDynamicObject(1280, 2610.8200, -1678.6510, 1015.9071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[28] = CreateDynamicObject(1297, 2597.7255, -1738.4106, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[29] = CreateDynamicObject(1297, 2597.7255, -1745.1112, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[30] = CreateDynamicObject(1297, 2597.7255, -1751.7309, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[31] = CreateDynamicObject(1297, 2597.7255, -1758.4908, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[32] = CreateDynamicObject(1297, 2597.7255, -1698.3509, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[33] = CreateDynamicObject(792, 2610.0993, -1761.8015, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[34] = CreateDynamicObject(1297, 2597.7255, -1691.7314, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[35] = CreateDynamicObject(1297, 2597.7255, -1685.0111, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[36] = CreateDynamicObject(1297, 2597.7255, -1678.3608, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[37] = CreateDynamicObject(1297, 2597.7255, -1671.7109, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[38] = CreateDynamicObject(1297, 2597.7255, -1665.0605, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[39] = CreateDynamicObject(1297, 2597.7255, -1658.4399, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[40] = CreateDynamicObject(1297, 2597.7255, -1651.7092, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[41] = CreateDynamicObject(792, 2610.0993, -1754.9908, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[42] = CreateDynamicObject(792, 2610.0993, -1748.3016, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[43] = CreateDynamicObject(792, 2610.0993, -1741.8006, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[44] = CreateDynamicObject(792, 2610.0993, -1735.0096, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[45] = CreateDynamicObject(792, 2610.0993, -1728.5599, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[46] = CreateDynamicObject(792, 2610.0993, -1661.8288, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[47] = CreateDynamicObject(19378, 2617.9865, -1702.2767, 1020.9863, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[47], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    DSADLKAS[48] = CreateDynamicObject(792, 2610.0993, -1695.1175, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[49] = CreateDynamicObject(792, 2610.0993, -1688.5288, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[50] = CreateDynamicObject(792, 2610.0993, -1681.9189, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[51] = CreateDynamicObject(792, 2610.0993, -1675.1892, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[52] = CreateDynamicObject(792, 2610.0993, -1668.5185, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[53] = CreateDynamicObject(792, 2610.0993, -1655.3686, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[54] = CreateDynamicObject(1297, 2607.5048, -1752.0113, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[55] = CreateDynamicObject(792, 2610.0993, -1648.6783, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[56] = CreateDynamicObject(1297, 2607.5048, -1758.4908, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[57] = CreateDynamicObject(1297, 2607.5048, -1745.2607, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[58] = CreateDynamicObject(1297, 2607.5048, -1731.9803, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[59] = CreateDynamicObject(1297, 2607.5048, -1738.6202, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[60] = CreateDynamicObject(2257, 2625.3278, -1716.5228, 1017.9989, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //Frame_Clip_4
    DSADLKAS[61] = CreateDynamicObject(1297, 2607.5048, -1651.9864, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[62] = CreateDynamicObject(1297, 2607.5048, -1691.9698, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[63] = CreateDynamicObject(1297, 2607.5048, -1685.3087, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[64] = CreateDynamicObject(1297, 2607.5048, -1678.6180, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[65] = CreateDynamicObject(1297, 2607.5048, -1672.0074, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[66] = CreateDynamicObject(1297, 2607.5048, -1665.3276, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[67] = CreateDynamicObject(1297, 2607.5048, -1658.7773, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[68] = CreateDynamicObject(19378, 2623.0312, -1721.4553, 1015.7659, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[68], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[69] = CreateDynamicObject(19378, 2617.6088, -1726.0061, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[69], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[70] = CreateDynamicObject(19378, 2627.0593, -1726.0061, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[70], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[71] = CreateDynamicObject(19378, 2627.7661, -1716.6451, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[71], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[72] = CreateDynamicObject(19378, 2638.9609, -1711.9066, 1020.9863, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[72], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    DSADLKAS[73] = CreateDynamicObject(11245, 2560.8684, -1722.1418, 1029.3039, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //sfsefirehseflag
    DSADLKAS[74] = CreateDynamicObject(11245, 2560.8684, -1706.7600, 1029.3039, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //sfsefirehseflag
    DSADLKAS[75] = CreateDynamicObject(19378, 2637.3759, -1716.6451, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[75], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[76] = CreateDynamicObject(19378, 2647.0083, -1716.6451, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[76], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[77] = CreateDynamicObject(19378, 2656.6091, -1716.6451, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[77], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[78] = CreateDynamicObject(19378, 2656.6091, -1697.5539, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[78], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[79] = CreateDynamicObject(19378, 2646.9890, -1697.5539, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[79], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[80] = CreateDynamicObject(19378, 2627.7651, -1697.5539, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[80], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[81] = CreateDynamicObject(1280, 2577.9367, -1723.7530, 1015.9071, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[82] = CreateDynamicObject(19378, 2621.8093, -1697.5539, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[82], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[83] = CreateDynamicObject(19378, 2617.4060, -1697.5539, 1015.7659, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[83], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[84] = CreateDynamicObject(1280, 2586.6000, -1723.7530, 1015.9071, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[85] = CreateDynamicObject(19378, 2654.4370, -1702.2336, 1015.7659, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[85], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[86] = CreateDynamicObject(1341, 2595.0131, -1721.1009, 1016.5568, 0.0000, 0.0000, 32.0998, 1064, 1, -1, 300.0, 300.0, -1); //icescart_prop
    DSADLKAS[87] = CreateDynamicObject(19825, 2619.9592, -1697.6938, 1018.8690, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //SprunkClock1
    DSADLKAS[88] = CreateDynamicObject(1280, 2585.7150, -1704.3828, 1015.9171, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[89] = CreateDynamicObject(1280, 2569.4257, -1723.7530, 1015.9071, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[90] = CreateDynamicObject(19381, 2617.8623, -1711.8459, 1015.5026, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[90], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    DSADLKAS[91] = CreateDynamicObject(1280, 2561.0136, -1723.7530, 1015.9071, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[92] = CreateDynamicObject(1280, 2561.0136, -1704.3828, 1015.9171, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[93] = CreateDynamicObject(19381, 2617.8493, -1721.4565, 1015.5026, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[93], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    DSADLKAS[94] = CreateDynamicObject(1280, 2610.8200, -1651.8015, 1015.9071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[95] = CreateDynamicObject(3935, 2574.4875, -1713.9300, 1018.6798, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //statue
    DSADLKAS[96] = CreateDynamicObject(1341, 2584.6875, -1640.2458, 1016.5568, 0.0000, 0.0000, -23.9999, 1064, 1, -1, 300.0, 300.0, -1); //icescart_prop
    DSADLKAS[97] = CreateDynamicObject(19381, 2587.4296, -1662.5255, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[97], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[98] = CreateDynamicObject(19381, 2587.4296, -1643.3050, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[98], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[99] = CreateDynamicObject(19381, 2577.0185, -1643.3050, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[99], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[100] = CreateDynamicObject(19381, 2566.5476, -1643.3050, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[100], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[101] = CreateDynamicObject(19381, 2566.5476, -1652.8747, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[101], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[102] = CreateDynamicObject(19381, 2566.5476, -1662.4648, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[102], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[103] = CreateDynamicObject(19381, 2577.0373, -1662.4648, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[103], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[104] = CreateDynamicObject(19381, 2577.0373, -1652.8857, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[104], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[105] = CreateDynamicObject(4690, 2558.5590, -1648.3728, 1023.8460, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //skyscrapn202
    DSADLKAS[106] = CreateDynamicObject(974, 2578.0964, -1665.1461, 1016.5573, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //tall_fence
    DSADLKAS[107] = CreateDynamicObject(19381, 2587.4296, -1633.7154, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[107], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[108] = CreateDynamicObject(19381, 2576.9699, -1633.7154, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[108], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[109] = CreateDynamicObject(19381, 2566.5197, -1633.7154, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[109], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[110] = CreateDynamicObject(19381, 2566.5197, -1624.1053, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[110], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[111] = CreateDynamicObject(19381, 2576.9909, -1624.1053, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[111], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[112] = CreateDynamicObject(19381, 2587.4504, -1624.1053, 1015.4647, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[112], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[113] = CreateDynamicObject(19325, 2612.6870, -1713.3684, 1017.1430, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[114] = CreateDynamicObject(19325, 2612.6870, -1706.7281, 1017.1430, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[115] = CreateDynamicObject(1341, 2572.8127, -1627.8985, 1016.5568, 0.0000, 0.0000, 29.0000, 1064, 1, -1, 300.0, 300.0, -1); //icescart_prop
    DSADLKAS[116] = CreateDynamicObject(19325, 2612.6870, -1700.0887, 1017.1430, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[117] = CreateDynamicObject(1280, 2594.4384, -1678.3924, 1015.9071, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[118] = CreateDynamicObject(19325, 2612.6870, -1700.0887, 1021.2631, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[119] = CreateDynamicObject(1280, 2594.4384, -1691.8331, 1015.9071, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[120] = CreateDynamicObject(19325, 2612.6870, -1713.3713, 1021.2631, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[121] = CreateDynamicObject(1280, 2594.4384, -1665.0821, 1015.9071, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[122] = CreateDynamicObject(19325, 2612.6870, -1706.7292, 1021.2631, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[123] = CreateDynamicObject(19381, 2628.3544, -1711.8459, 1015.5026, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[123], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    DSADLKAS[124] = CreateDynamicObject(1280, 2594.4384, -1651.8015, 1015.9071, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[125] = CreateDynamicObject(19381, 2628.3364, -1702.2641, 1015.5026, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[125], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    DSADLKAS[126] = CreateDynamicObject(1280, 2594.4384, -1738.4416, 1015.9071, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[127] = CreateDynamicObject(1280, 2594.4384, -1751.9023, 1015.9071, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[128] = CreateDynamicObject(19381, 2617.8522, -1702.2641, 1015.5026, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[128], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    DSADLKAS[129] = CreateDynamicObject(19381, 2638.8359, -1702.2657, 1015.5026, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[129], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    DSADLKAS[130] = CreateDynamicObject(1280, 2610.8200, -1692.0810, 1015.9071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[131] = CreateDynamicObject(1280, 2610.8200, -1738.7917, 1015.9071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[132] = CreateDynamicObject(19378, 2649.4599, -1702.2767, 1020.9863, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[132], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    DSADLKAS[133] = CreateDynamicObject(1886, 2626.8291, -1698.3531, 1021.0307, 27.1000, 0.0000, -46.8997, 1064, 1, -1, 300.0, 300.0, -1); //shop_sec_cam
    DSADLKAS[134] = CreateDynamicObject(19378, 2617.9492, -1721.5373, 1020.9863, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[134], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    DSADLKAS[135] = CreateDynamicObject(3935, 2585.5485, -1630.7309, 1017.1240, 0.0000, 0.0000, -51.5998, 1064, 1, -1, 300.0, 300.0, -1); //statue
    DSADLKAS[136] = CreateDynamicObject(1671, 2651.4953, -1711.6301, 1016.0031, 0.0000, 0.0000, 134.7998, 1064, 1, -1, 300.0, 300.0, -1); //swivelchair_A
    DSADLKAS[137] = CreateDynamicObject(1886, 2628.3835, -1715.8813, 1020.9149, 23.8999, 0.0000, 129.3000, 1064, 1, -1, 300.0, 300.0, -1); //shop_sec_cam
    DSADLKAS[138] = CreateDynamicObject(19834, 2621.8132, -1718.9499, 1015.5927, 90.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[138], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[139] = CreateDynamicObject(19893, 2625.1467, -1716.2164, 1016.4840, 0.0000, 0.0000, -164.6000, 1064, 1, -1, 300.0, 300.0, -1); //LaptopSAMP1
    DSADLKAS[140] = CreateDynamicObject(4564, 2569.7570, -1785.3291, 1124.8072, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //LAskyscrap2_LAn
    DSADLKAS[141] = CreateDynamicObject(10930, 2602.6616, -1825.1837, 1015.7005, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //roadsSFSE24
    DSADLKAS[142] = CreateDynamicObject(19381, 2556.4226, -1807.6661, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[142], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[143] = CreateDynamicObject(19381, 2587.8100, -1759.7264, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[143], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[144] = CreateDynamicObject(19381, 2587.8100, -1769.2762, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[144], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[145] = CreateDynamicObject(19381, 2587.8100, -1778.8863, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[145], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[146] = CreateDynamicObject(19381, 2587.8100, -1788.4967, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[146], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[147] = CreateDynamicObject(19381, 2587.8100, -1798.1169, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[147], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[148] = CreateDynamicObject(19381, 2587.8100, -1807.7165, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[148], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[149] = CreateDynamicObject(19381, 2556.4226, -1817.3055, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[149], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[150] = CreateDynamicObject(19381, 2587.8100, -1817.2960, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[150], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[151] = CreateDynamicObject(19381, 2577.3203, -1817.2960, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[151], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[152] = CreateDynamicObject(19381, 2577.3203, -1807.6661, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[152], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[153] = CreateDynamicObject(19381, 2566.8815, -1807.6661, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[153], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[154] = CreateDynamicObject(19381, 2566.8930, -1817.3055, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[154], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[155] = CreateDynamicObject(19381, 2577.3408, -1759.7264, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[155], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[156] = CreateDynamicObject(19381, 2577.3408, -1750.1362, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[156], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[157] = CreateDynamicObject(19381, 2581.7016, -1750.1362, 1015.5347, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[157], 0, 8391, "ballys01", "ws_floortiles4", 0xFFFFFFFF);
    DSADLKAS[158] = CreateDynamicObject(1280, 2594.4384, -1638.5908, 1015.8571, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[159] = CreateDynamicObject(974, 2581.9670, -1756.8231, 1015.9014, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //tall_fence
    DSADLKAS[160] = CreateDynamicObject(792, 2595.2084, -1768.3027, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[161] = CreateDynamicObject(792, 2595.2084, -1775.0332, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[162] = CreateDynamicObject(792, 2595.2084, -1788.3541, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[163] = CreateDynamicObject(792, 2595.2084, -1781.6435, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[164] = CreateDynamicObject(792, 2595.2084, -1794.9354, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[165] = CreateDynamicObject(792, 2595.2084, -1801.7655, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[166] = CreateDynamicObject(792, 2595.2084, -1808.3763, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[167] = CreateDynamicObject(792, 2595.2084, -1815.1162, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[168] = CreateDynamicObject(792, 2595.2084, -1821.6468, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[169] = CreateDynamicObject(792, 2595.2084, -1828.3474, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[170] = CreateDynamicObject(792, 2595.2084, -1835.0782, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[171] = CreateDynamicObject(792, 2595.2084, -1841.8194, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[172] = CreateDynamicObject(792, 2595.2084, -1848.5200, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[173] = CreateDynamicObject(792, 2595.2084, -1855.0200, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[174] = CreateDynamicObject(792, 2595.2084, -1861.8009, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[175] = CreateDynamicObject(792, 2595.2084, -1868.3215, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[176] = CreateDynamicObject(792, 2595.2084, -1875.0013, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[177] = CreateDynamicObject(792, 2595.2084, -1881.8420, 1016.0186, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[178] = CreateDynamicObject(792, 2610.0993, -1768.4527, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[179] = CreateDynamicObject(792, 2610.0993, -1775.3032, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[180] = CreateDynamicObject(792, 2610.0993, -1782.0937, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[181] = CreateDynamicObject(792, 2610.0993, -1788.7441, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[182] = CreateDynamicObject(792, 2610.0993, -1795.3243, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[183] = CreateDynamicObject(792, 2610.0993, -1802.0550, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[184] = CreateDynamicObject(792, 2610.0993, -1808.6147, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[185] = CreateDynamicObject(792, 2610.0993, -1815.1850, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[186] = CreateDynamicObject(1297, 2607.5048, -1765.2707, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[187] = CreateDynamicObject(792, 2610.0993, -1822.1048, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[188] = CreateDynamicObject(792, 2610.0993, -1828.6357, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[189] = CreateDynamicObject(792, 2610.0993, -1835.5067, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[190] = CreateDynamicObject(792, 2610.0993, -1842.1169, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[191] = CreateDynamicObject(792, 2610.0993, -1848.7076, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[192] = CreateDynamicObject(792, 2610.0993, -1855.3878, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[193] = CreateDynamicObject(792, 2610.0993, -1862.1778, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[194] = CreateDynamicObject(792, 2610.0993, -1868.5882, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[195] = CreateDynamicObject(792, 2610.0993, -1875.1883, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[196] = CreateDynamicObject(792, 2610.0993, -1882.0589, 1015.9785, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[197] = CreateDynamicObject(1297, 2607.5048, -1771.9110, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[198] = CreateDynamicObject(1297, 2607.5048, -1778.6705, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[199] = CreateDynamicObject(1297, 2607.5048, -1785.3607, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[200] = CreateDynamicObject(1297, 2607.5048, -1792.0306, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[201] = CreateDynamicObject(1297, 2607.5048, -1798.8509, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[202] = CreateDynamicObject(1297, 2607.5048, -1805.3912, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[203] = CreateDynamicObject(1297, 2607.5048, -1811.9405, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[204] = CreateDynamicObject(1297, 2607.5048, -1818.7508, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[205] = CreateDynamicObject(1297, 2607.5048, -1825.2508, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[206] = CreateDynamicObject(1297, 2607.5048, -1832.0008, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[207] = CreateDynamicObject(1297, 2607.5048, -1838.6711, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[208] = CreateDynamicObject(1297, 2607.5048, -1845.3623, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[209] = CreateDynamicObject(1297, 2607.5048, -1852.0224, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[210] = CreateDynamicObject(1297, 2607.5048, -1858.6727, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[211] = CreateDynamicObject(1297, 2607.5048, -1865.3536, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[212] = CreateDynamicObject(1297, 2607.5048, -1872.1346, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[213] = CreateDynamicObject(1297, 2607.5048, -1878.6943, 1018.8092, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[214] = CreateDynamicObject(19325, 2627.5871, -1700.9575, 1017.5330, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[215] = CreateDynamicObject(1297, 2597.7255, -1765.1909, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[216] = CreateDynamicObject(1297, 2597.7255, -1771.7513, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[217] = CreateDynamicObject(1297, 2597.7255, -1778.3918, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[218] = CreateDynamicObject(1297, 2597.7255, -1785.1224, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[219] = CreateDynamicObject(1297, 2597.7255, -1791.6926, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[220] = CreateDynamicObject(19325, 2627.5871, -1700.9575, 1021.6527, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[221] = CreateDynamicObject(1297, 2597.7255, -1798.4123, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[222] = CreateDynamicObject(1297, 2597.7255, -1805.1324, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[223] = CreateDynamicObject(1297, 2597.7255, -1811.7032, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[224] = CreateDynamicObject(1297, 2597.7255, -1818.3642, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[225] = CreateDynamicObject(1297, 2597.7255, -1824.9851, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[226] = CreateDynamicObject(1297, 2597.7255, -1844.9963, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[227] = CreateDynamicObject(1297, 2597.7255, -1831.6953, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[228] = CreateDynamicObject(1297, 2597.7255, -1838.3557, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[229] = CreateDynamicObject(1297, 2597.7255, -1851.6865, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[230] = CreateDynamicObject(1297, 2597.7255, -1858.2369, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[231] = CreateDynamicObject(1297, 2597.7255, -1865.0471, 1018.7091, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[232] = CreateDynamicObject(1297, 2597.7255, -1871.7270, 1018.7492, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[233] = CreateDynamicObject(1297, 2597.7255, -1878.2872, 1018.8493, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[234] = CreateDynamicObject(1280, 2594.4384, -1625.3507, 1015.7968, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[235] = CreateDynamicObject(10930, 2602.6916, -1585.3537, 1015.4102, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //roadsSFSE24
    DSADLKAS[236] = CreateDynamicObject(792, 2595.2084, -1641.7888, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[237] = CreateDynamicObject(792, 2595.2084, -1635.1383, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[238] = CreateDynamicObject(792, 2595.2084, -1628.5078, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[239] = CreateDynamicObject(792, 2595.2084, -1621.6666, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[240] = CreateDynamicObject(792, 2595.2084, -1615.1164, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[241] = CreateDynamicObject(792, 2595.2084, -1608.4564, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[242] = CreateDynamicObject(792, 2595.2084, -1601.8463, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[243] = CreateDynamicObject(1297, 2597.7255, -1645.1993, 1018.6190, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[244] = CreateDynamicObject(792, 2595.2084, -1595.0760, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[245] = CreateDynamicObject(792, 2595.2084, -1588.3961, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[246] = CreateDynamicObject(792, 2595.2084, -1581.7860, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[247] = CreateDynamicObject(792, 2595.2084, -1575.1352, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[248] = CreateDynamicObject(792, 2595.2084, -1568.4554, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[249] = CreateDynamicObject(792, 2595.2084, -1561.7252, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[250] = CreateDynamicObject(792, 2595.2084, -1555.1650, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[251] = CreateDynamicObject(792, 2595.2084, -1548.5544, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[252] = CreateDynamicObject(792, 2595.2084, -1541.8542, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[253] = CreateDynamicObject(792, 2595.2084, -1535.2242, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[254] = CreateDynamicObject(792, 2595.2084, -1528.4138, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    //DSADLKAS[255] = CreateDynamicObject(2877, 2617.1162, -1705.1450, 1016.0379, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //CJ_BINCO_DOOR
    //SetDynamicObjectMaterial(DSADLKAS[255], 0, 16640, "a51", "a51_glass", 0xFFFFFFFF);
    DSADLKAS[256] = CreateDynamicObject(1297, 2597.7255, -1638.4691, 1018.6190, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[257] = CreateDynamicObject(1297, 2597.7255, -1631.8581, 1018.6190, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[258] = CreateDynamicObject(1297, 2597.7255, -1625.1682, 1018.6190, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[259] = CreateDynamicObject(1297, 2597.7255, -1618.5179, 1018.6190, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[260] = CreateDynamicObject(1297, 2597.7255, -1611.8071, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[261] = CreateDynamicObject(1297, 2597.7255, -1605.2270, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[262] = CreateDynamicObject(1297, 2597.7255, -1598.4665, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[263] = CreateDynamicObject(1297, 2597.7255, -1591.8968, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[264] = CreateDynamicObject(1297, 2597.7255, -1585.1871, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[265] = CreateDynamicObject(1297, 2597.7255, -1578.3767, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[266] = CreateDynamicObject(1297, 2597.7255, -1571.7666, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[267] = CreateDynamicObject(1297, 2597.7255, -1565.0261, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[268] = CreateDynamicObject(1297, 2597.7255, -1558.4265, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[269] = CreateDynamicObject(1297, 2597.7255, -1551.7860, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[270] = CreateDynamicObject(1297, 2597.7255, -1545.1350, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[271] = CreateDynamicObject(1297, 2597.7255, -1538.5544, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[272] = CreateDynamicObject(1297, 2597.7255, -1531.5644, 1018.5390, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[273] = CreateDynamicObject(792, 2610.0993, -1642.1180, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[274] = CreateDynamicObject(1297, 2607.5048, -1632.1756, 1018.6389, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[275] = CreateDynamicObject(792, 2610.0993, -1635.3978, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[276] = CreateDynamicObject(792, 2610.0993, -1628.8070, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[277] = CreateDynamicObject(792, 2610.0993, -1622.1070, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[278] = CreateDynamicObject(792, 2610.0993, -1615.4864, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[279] = CreateDynamicObject(792, 2610.0993, -1608.7562, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[280] = CreateDynamicObject(792, 2610.0993, -1602.1457, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[281] = CreateDynamicObject(792, 2610.0993, -1595.4758, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[282] = CreateDynamicObject(792, 2610.0993, -1588.7652, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[283] = CreateDynamicObject(792, 2610.0993, -1582.1549, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[284] = CreateDynamicObject(792, 2610.0993, -1575.6245, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[285] = CreateDynamicObject(792, 2610.0993, -1568.7043, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[286] = CreateDynamicObject(792, 2610.0993, -1562.0056, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[287] = CreateDynamicObject(792, 2610.0993, -1555.4360, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[288] = CreateDynamicObject(792, 2610.0993, -1548.7469, 1015.8983, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[289] = CreateDynamicObject(792, 2610.0993, -1542.0362, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[290] = CreateDynamicObject(792, 2610.0993, -1535.3160, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[291] = CreateDynamicObject(792, 2610.0993, -1528.6562, 1015.7883, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //aw_streettree1
    DSADLKAS[292] = CreateDynamicObject(1297, 2607.5048, -1645.3957, 1018.7091, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[293] = CreateDynamicObject(1297, 2607.5048, -1638.8458, 1018.6389, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[294] = CreateDynamicObject(1297, 2607.5048, -1625.4150, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[295] = CreateDynamicObject(1297, 2607.5048, -1618.9139, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[296] = CreateDynamicObject(1297, 2607.5048, -1612.1738, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[297] = CreateDynamicObject(1297, 2607.5048, -1605.4233, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[298] = CreateDynamicObject(1297, 2607.5048, -1598.8723, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[299] = CreateDynamicObject(1297, 2607.5048, -1592.1219, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[300] = CreateDynamicObject(1297, 2607.5048, -1585.5909, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[301] = CreateDynamicObject(1297, 2607.5048, -1578.5904, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[302] = CreateDynamicObject(1297, 2607.5048, -1572.2298, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[303] = CreateDynamicObject(1297, 2607.5048, -1565.5185, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[304] = CreateDynamicObject(1297, 2607.5048, -1559.1081, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[305] = CreateDynamicObject(1297, 2607.5048, -1552.2187, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[306] = CreateDynamicObject(1297, 2607.5048, -1545.4178, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[307] = CreateDynamicObject(1297, 2607.5048, -1538.8773, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[308] = CreateDynamicObject(1297, 2607.5048, -1532.1269, 1018.5288, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lamppost1
    DSADLKAS[309] = CreateDynamicObject(1280, 2610.8200, -1638.7613, 1015.9071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[310] = CreateDynamicObject(1280, 2610.8200, -1625.3415, 1015.8170, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[311] = CreateDynamicObject(1280, 2610.8200, -1612.0609, 1015.8170, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[312] = CreateDynamicObject(1280, 2610.8200, -1598.9104, 1015.8170, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[313] = CreateDynamicObject(1280, 2610.8200, -1585.4195, 1015.7769, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[314] = CreateDynamicObject(1280, 2610.8200, -1572.1789, 1015.7769, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[315] = CreateDynamicObject(1280, 2610.8200, -1558.9283, 1015.7570, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[316] = CreateDynamicObject(1280, 2610.8200, -1545.5987, 1015.7570, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[317] = CreateDynamicObject(1280, 2610.8200, -1532.1776, 1015.7570, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[318] = CreateDynamicObject(1280, 2594.4384, -1611.9704, 1015.7368, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[319] = CreateDynamicObject(1280, 2594.4384, -1598.5804, 1015.7368, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[320] = CreateDynamicObject(1280, 2594.4384, -1585.2600, 1015.7368, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[321] = CreateDynamicObject(1280, 2594.4384, -1571.9195, 1015.7368, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[322] = CreateDynamicObject(1557, 2612.6865, -1708.6251, 1015.6032, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //Gen_doorEXT19
    DSADLKAS[323] = CreateDynamicObject(1280, 2594.4384, -1558.6091, 1015.7368, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[324] = CreateDynamicObject(1280, 2594.4384, -1545.2591, 1015.7368, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[325] = CreateDynamicObject(1280, 2594.4384, -1531.7883, 1015.7368, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[326] = CreateDynamicObject(1557, 2612.6264, -1708.6251, 1015.6032, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //Gen_doorEXT19
    DSADLKAS[327] = CreateDynamicObject(1557, 2612.6865, -1705.6142, 1015.6032, 360.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //Gen_doorEXT19
    DSADLKAS[328] = CreateDynamicObject(974, 2589.3283, -1620.8894, 1016.0795, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //tall_fence
    DSADLKAS[329] = CreateDynamicObject(974, 2562.6960, -1620.8894, 1016.0795, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //tall_fence
    DSADLKAS[330] = CreateDynamicObject(974, 2569.3554, -1620.8894, 1016.0795, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //tall_fence
    DSADLKAS[331] = CreateDynamicObject(974, 2576.0156, -1620.8894, 1016.0795, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //tall_fence
    DSADLKAS[332] = CreateDynamicObject(974, 2582.6672, -1620.8894, 1016.0795, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //tall_fence
    DSADLKAS[333] = CreateDynamicObject(19834, 2618.9104, -1719.1472, 1015.3624, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[333], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[334] = CreateDynamicObject(19834, 2620.7121, -1724.7727, 1015.5927, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[334], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[335] = CreateDynamicObject(1280, 2594.4384, -1765.1523, 1016.0272, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[336] = CreateDynamicObject(1280, 2594.4384, -1778.4327, 1016.0272, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[337] = CreateDynamicObject(19834, 2620.7121, -1722.4714, 1015.5927, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[337], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[338] = CreateDynamicObject(1280, 2594.4384, -1791.7030, 1016.0272, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[339] = CreateDynamicObject(1280, 2594.4384, -1805.0832, 1016.0272, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[340] = CreateDynamicObject(19834, 2620.7121, -1720.1800, 1015.5927, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[340], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[341] = CreateDynamicObject(1280, 2594.4384, -1818.4239, 1016.0272, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[342] = CreateDynamicObject(19834, 2618.3876, -1722.5102, 1015.5927, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[342], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[343] = CreateDynamicObject(1280, 2594.4384, -1831.7641, 1016.0272, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[344] = CreateDynamicObject(1280, 2594.4384, -1845.1938, 1016.0272, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[345] = CreateDynamicObject(1280, 2594.4384, -1858.3642, 1016.0272, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[346] = CreateDynamicObject(1280, 2594.4384, -1871.7436, 1016.0272, 0.0000, 0.0000, -180.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[347] = CreateDynamicObject(19834, 2618.3876, -1724.8116, 1015.5927, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[347], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[348] = CreateDynamicObject(1280, 2610.8200, -1778.7325, 1015.9071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[349] = CreateDynamicObject(1280, 2610.8200, -1765.3525, 1015.9071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[350] = CreateDynamicObject(1280, 2610.8200, -1792.0930, 1015.9672, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[351] = CreateDynamicObject(19834, 2618.3876, -1720.1800, 1015.5927, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[351], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[352] = CreateDynamicObject(1280, 2610.8200, -1805.3736, 1015.9672, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[353] = CreateDynamicObject(1280, 2610.8200, -1818.5433, 1015.9672, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[354] = CreateDynamicObject(1280, 2610.8200, -1832.0035, 1015.9672, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[355] = CreateDynamicObject(19834, 2617.1506, -1718.9499, 1015.5927, 90.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[355], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[356] = CreateDynamicObject(1280, 2610.8200, -1845.3636, 1015.9672, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[357] = CreateDynamicObject(1280, 2610.8200, -1858.5637, 1015.9672, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[358] = CreateDynamicObject(1280, 2610.8200, -1872.0051, 1015.9672, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //parkbench1
    DSADLKAS[359] = CreateDynamicObject(19834, 2616.0554, -1720.1800, 1015.5927, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[359], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[360] = CreateDynamicObject(19834, 2616.0554, -1722.5102, 1015.5927, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[360], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[361] = CreateDynamicObject(19834, 2621.8132, -1718.9499, 1015.5927, 90.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[361], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[362] = CreateDynamicObject(19325, 2627.5871, -1713.2596, 1017.5330, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[363] = CreateDynamicObject(2953, 2613.5183, -1721.2032, 1016.4589, 0.0000, 0.0000, -25.7000, 1064, 1, -1, 300.0, 300.0, -1); //kmb_paper_code
    DSADLKAS[364] = CreateDynamicObject(19378, 2617.9492, -1711.9066, 1020.9863, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[364], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    DSADLKAS[365] = CreateDynamicObject(19834, 2616.0554, -1724.8403, 1015.5927, 90.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[365], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[366] = CreateDynamicObject(19325, 2627.5871, -1713.2596, 1021.6428, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[367] = CreateDynamicObject(19834, 2619.4809, -1718.9499, 1015.5927, 90.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[367], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[368] = CreateDynamicObject(19834, 2614.8310, -1718.9499, 1015.5927, 90.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[368], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[369] = CreateDynamicObject(19834, 2613.9604, -1718.9499, 1015.5927, 90.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //PoliceLineTape1
    SetDynamicObjectMaterial(DSADLKAS[369], 0, 5168, "lashops6_las2", "yellow2_128", 0xFFFFFFFF);
    DSADLKAS[370] = CreateDynamicObject(19438, 2620.7021, -1725.5310, 1015.9067, 38.8998, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall078
    SetDynamicObjectMaterial(DSADLKAS[370], 0, 10101, "2notherbuildsfe", "sl_vicwall02", 0xFFFFFFFF);
    DSADLKAS[371] = CreateDynamicObject(3657, 2616.5883, -1698.0731, 1016.0581, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[372] = CreateDynamicObject(3657, 2631.8010, -1699.0024, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[373] = CreateDynamicObject(19444, 2653.9162, -1712.8033, 1020.5750, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[373], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[374] = CreateDynamicObject(3657, 2623.2321, -1698.0731, 1016.0581, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[375] = CreateDynamicObject(2208, 2613.1809, -1721.1418, 1015.5910, 0.0000, 0.0000, -89.9999, 1064, 1, -1, 300.0, 300.0, -1); //MED_OFFICE7_UNIT_1
    SetDynamicObjectMaterial(DSADLKAS[375], 0, 16271, "des_factory", "dish_cylinder_a", 0xFFFFFFFF);
    DSADLKAS[376] = CreateDynamicObject(3533, 2627.6860, -1707.0760, 1019.0927, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //trdpillar01
    SetDynamicObjectMaterial(DSADLKAS[376], 0, 10023, "bigwhitesfe", "archgrnd3_SFE", 0xFFFFFFFF);
    DSADLKAS[377] = CreateDynamicObject(1892, 2627.5085, -1709.4243, 1015.5784, 0.0000, 0.0000, 88.6996, 1064, 1, -1, 300.0, 300.0, -1); //security_gatsh
    DSADLKAS[378] = CreateDynamicObject(1892, 2627.5937, -1705.8043, 1015.5784, 0.0000, 0.0000, 88.6996, 1064, 1, -1, 300.0, 300.0, -1); //security_gatsh
    DSADLKAS[379] = CreateDynamicObject(2229, 2650.8737, -1710.7364, 1015.0100, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[380] = CreateDynamicObject(2229, 2649.9929, -1707.8260, 1015.0100, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[381] = CreateDynamicObject(19381, 2649.2866, -1711.8459, 1015.5026, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[381], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    DSADLKAS[382] = CreateDynamicObject(1744, 2623.1066, -1718.4801, 1016.3273, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //MED_SHELF
    DSADLKAS[383] = CreateDynamicObject(638, 2627.0307, -1701.0638, 1016.2274, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //kb_planter+bush
    DSADLKAS[384] = CreateDynamicObject(2754, 2617.2246, -1725.4654, 1016.4953, 0.0000, 360.0000, -89.9001, 1064, 1, -1, 300.0, 300.0, -1); //OTB_machine
    DSADLKAS[385] = CreateDynamicObject(2754, 2621.8569, -1725.4575, 1016.4953, 0.0000, 360.0000, -89.9001, 1064, 1, -1, 300.0, 300.0, -1); //OTB_machine
    DSADLKAS[386] = CreateDynamicObject(949, 2620.8178, -1698.1048, 1016.2142, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Plant_Pot_4
    DSADLKAS[387] = CreateDynamicObject(1744, 2623.1066, -1721.8701, 1016.3273, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //MED_SHELF
    DSADLKAS[388] = CreateDynamicObject(949, 2619.1665, -1698.1048, 1016.2142, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Plant_Pot_4
    DSADLKAS[389] = CreateDynamicObject(1416, 2625.6381, -1716.1805, 1015.9097, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //DYN_UNIT
    DSADLKAS[390] = CreateDynamicObject(2002, 2619.9860, -1698.1429, 1015.5717, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //water_coolnu
    DSADLKAS[391] = CreateDynamicObject(1416, 2624.9775, -1716.1805, 1015.9097, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //DYN_UNIT
    DSADLKAS[392] = CreateDynamicObject(949, 2614.1140, -1698.1048, 1016.2142, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Plant_Pot_4
    DSADLKAS[393] = CreateDynamicObject(949, 2625.7307, -1698.1048, 1016.2142, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Plant_Pot_4
    DSADLKAS[394] = CreateDynamicObject(19325, 2650.4880, -1706.6383, 1020.6985, -89.4999, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[395] = CreateDynamicObject(19325, 2650.4880, -1705.5677, 1020.7074, -89.4999, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[396] = CreateDynamicObject(19325, 2650.4880, -1705.5677, 1020.7074, -89.4999, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[397] = CreateDynamicObject(19325, 2650.4880, -1709.5798, 1020.6726, -89.4999, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[398] = CreateDynamicObject(3657, 2631.8010, -1702.4029, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[399] = CreateDynamicObject(3657, 2631.8010, -1711.6826, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[400] = CreateDynamicObject(19325, 2650.4880, -1710.7509, 1020.6633, -89.4999, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[401] = CreateDynamicObject(19325, 2612.6870, -1720.0100, 1017.1430, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[402] = CreateDynamicObject(19325, 2612.6870, -1726.6510, 1017.1430, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[403] = CreateDynamicObject(19325, 2612.6870, -1726.6510, 1021.2634, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[404] = CreateDynamicObject(19325, 2612.6870, -1720.0102, 1021.2634, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[405] = CreateDynamicObject(19897, 2625.6022, -1716.2060, 1016.4973, 0.0000, 0.0000, -22.6000, 1064, 1, -1, 300.0, 300.0, -1); //CigarettePack2
    DSADLKAS[406] = CreateDynamicObject(2258, 2616.7482, -1697.6754, 1018.8095, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Frame_Clip_5
    DSADLKAS[407] = CreateDynamicObject(2258, 2623.6203, -1697.6754, 1018.8095, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Frame_Clip_5
    DSADLKAS[408] = CreateDynamicObject(19378, 2638.9587, -1702.2767, 1020.9863, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[408], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    DSADLKAS[409] = CreateDynamicObject(19897, 2625.8723, -1716.0257, 1016.4973, 0.0000, 0.0000, 52.3997, 1064, 1, -1, 300.0, 300.0, -1); //CigarettePack2
    DSADLKAS[410] = CreateDynamicObject(3657, 2631.8010, -1715.0843, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[411] = CreateDynamicObject(1359, 2623.6799, -1716.1427, 1016.2338, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //CJ_BIN1
    DSADLKAS[412] = CreateDynamicObject(19897, 2625.9208, -1716.3542, 1016.4973, 0.0000, 0.0000, 113.9999, 1064, 1, -1, 300.0, 300.0, -1); //CigarettePack2
    DSADLKAS[413] = CreateDynamicObject(3657, 2634.5737, -1702.4029, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[414] = CreateDynamicObject(18874, 2624.6508, -1716.1534, 1016.4702, 0.0000, 0.0000, -157.5000, 1064, 1, -1, 300.0, 300.0, -1); //MobilePhone10
    DSADLKAS[415] = CreateDynamicObject(19378, 2628.4619, -1702.2767, 1020.9863, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[415], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    DSADLKAS[416] = CreateDynamicObject(1466, 2652.8129, -1698.4272, 1016.6516, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //DYN_SCAFFOLD_5
    DSADLKAS[417] = CreateDynamicObject(18075, 2645.0065, -1707.0488, 1020.8112, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lightD
    DSADLKAS[418] = CreateDynamicObject(18075, 2634.8530, -1707.0488, 1020.8112, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lightD
    DSADLKAS[419] = CreateDynamicObject(18075, 2618.2395, -1707.4405, 1020.8579, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lightD
    DSADLKAS[420] = CreateDynamicObject(3657, 2634.5437, -1711.6833, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[421] = CreateDynamicObject(18075, 2618.2395, -1719.2535, 1020.8579, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lightD
    DSADLKAS[422] = CreateDynamicObject(1886, 2613.3244, -1725.2408, 1021.0039, 22.9999, 0.0000, 143.5000, 1064, 1, -1, 300.0, 300.0, -1); //shop_sec_cam
    DSADLKAS[423] = CreateDynamicObject(19378, 2628.4580, -1711.9066, 1020.9863, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[423], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    DSADLKAS[424] = CreateDynamicObject(3657, 2634.5437, -1715.0732, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[425] = CreateDynamicObject(3657, 2636.9860, -1702.4029, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[426] = CreateDynamicObject(3657, 2636.9660, -1711.7041, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[427] = CreateDynamicObject(3657, 2639.5285, -1702.4029, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[428] = CreateDynamicObject(3657, 2636.9660, -1715.0948, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[429] = CreateDynamicObject(3657, 2642.3012, -1702.4029, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[430] = CreateDynamicObject(1569, 2654.3159, -1701.7486, 1015.5438, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //ADAM_V_DOOR
    DSADLKAS[431] = CreateDynamicObject(3657, 2639.5285, -1711.7041, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[432] = CreateDynamicObject(3657, 2639.5285, -1715.0953, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[433] = CreateDynamicObject(3657, 2642.3713, -1711.7132, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[434] = CreateDynamicObject(3657, 2636.9860, -1699.0024, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[435] = CreateDynamicObject(3657, 2642.3713, -1715.1134, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[436] = CreateDynamicObject(3657, 2634.5737, -1699.0024, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[437] = CreateDynamicObject(3657, 2639.5285, -1699.0024, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[438] = CreateDynamicObject(3657, 2642.3012, -1699.0024, 1016.0875, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //airseata_LAS
    DSADLKAS[439] = CreateDynamicObject(19381, 2649.2736, -1702.2646, 1015.5026, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall029
    SetDynamicObjectMaterial(DSADLKAS[439], 0, 16640, "a51", "ws_stationfloor", 0xFFFFFFFF);
    DSADLKAS[440] = CreateDynamicObject(2229, 2650.8737, -1708.4364, 1015.0100, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[441] = CreateDynamicObject(19786, 2622.9904, -1721.3575, 1018.3375, 0.0000, 0.0000, -90.3000, 1064, 1, -1, 300.0, 300.0, -1); //LCDTVBig1
    SetDynamicObjectMaterial(DSADLKAS[441], 0, 2640, "cj_coin_op_2", "CJ_TV1", 0xFFFFFFFF);
    DSADLKAS[442] = CreateDynamicObject(2180, 2650.4880, -1706.5067, 1015.5737, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //MED_OFFICE5_DESK_3
    SetDynamicObjectMaterial(DSADLKAS[442], 0, 2964, "k_pool", "pool_table_cloth", 0xFFFFFFFF);
    DSADLKAS[443] = CreateDynamicObject(2229, 2649.9929, -1705.5256, 1015.0100, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[444] = CreateDynamicObject(2229, 2650.8737, -1706.1446, 1015.0100, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[445] = CreateDynamicObject(2180, 2650.4880, -1704.1866, 1015.5737, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //MED_OFFICE5_DESK_3
    SetDynamicObjectMaterial(DSADLKAS[445], 0, 2964, "k_pool", "pool_table_cloth", 0xFFFFFFFF);
    DSADLKAS[446] = CreateDynamicObject(2001, 2613.2331, -1725.1363, 1015.5847, 0.0000, 0.0000, -36.2999, 1064, 1, -1, 300.0, 300.0, -1); //nu_plant_ofc
    DSADLKAS[447] = CreateDynamicObject(2180, 2650.4880, -1708.7866, 1015.5737, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //MED_OFFICE5_DESK_3
    SetDynamicObjectMaterial(DSADLKAS[447], 0, 2964, "k_pool", "pool_table_cloth", 0xFFFFFFFF);
    DSADLKAS[448] = CreateDynamicObject(2229, 2649.9929, -1710.1175, 1015.0100, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[449] = CreateDynamicObject(2229, 2649.9929, -1712.3962, 1015.0100, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[450] = CreateDynamicObject(19790, 2638.9978, -1712.9493, 1020.2432, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Cube5mx5m
    SetDynamicObjectMaterial(DSADLKAS[450], 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
    DSADLKAS[451] = CreateDynamicObject(2180, 2650.4880, -1711.0766, 1015.5737, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //MED_OFFICE5_DESK_3
    SetDynamicObjectMaterial(DSADLKAS[451], 0, 2964, "k_pool", "pool_table_cloth", 0xFFFFFFFF);
    DSADLKAS[452] = CreateDynamicObject(2229, 2650.8737, -1713.0073, 1015.0100, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[453] = CreateDynamicObject(19790, 2643.9589, -1712.9493, 1020.2432, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Cube5mx5m
    SetDynamicObjectMaterial(DSADLKAS[453], 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
    DSADLKAS[454] = CreateDynamicObject(19790, 2634.0449, -1712.9493, 1020.2432, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Cube5mx5m
    SetDynamicObjectMaterial(DSADLKAS[454], 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
    DSADLKAS[455] = CreateDynamicObject(19790, 2648.9211, -1701.6781, 1020.2432, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Cube5mx5m
    SetDynamicObjectMaterial(DSADLKAS[455], 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
    DSADLKAS[456] = CreateDynamicObject(19790, 2648.9211, -1712.9493, 1020.2432, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Cube5mx5m
    SetDynamicObjectMaterial(DSADLKAS[456], 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
    DSADLKAS[457] = CreateDynamicObject(19790, 2643.9804, -1701.6781, 1020.2432, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Cube5mx5m
    SetDynamicObjectMaterial(DSADLKAS[457], 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
    DSADLKAS[458] = CreateDynamicObject(2164, 2654.3173, -1710.0168, 1015.5556, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //MED_OFFICE_UNIT_5
    DSADLKAS[459] = CreateDynamicObject(2007, 2653.8471, -1707.0423, 1015.5791, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //filing_cab_nu01
    DSADLKAS[460] = CreateDynamicObject(19790, 2639.0285, -1701.6781, 1020.2432, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Cube5mx5m
    SetDynamicObjectMaterial(DSADLKAS[460], 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
    DSADLKAS[461] = CreateDynamicObject(19790, 2634.0659, -1701.6781, 1020.2432, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Cube5mx5m
    SetDynamicObjectMaterial(DSADLKAS[461], 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
    DSADLKAS[462] = CreateDynamicObject(19444, 2652.3259, -1712.8033, 1020.5452, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[462], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[463] = CreateDynamicObject(19444, 2653.9162, -1712.8033, 1017.2252, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[463], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[464] = CreateDynamicObject(19444, 2650.7851, -1712.8033, 1020.5750, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[464], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[465] = CreateDynamicObject(19444, 2650.7836, -1703.4416, 1020.6046, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[465], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[466] = CreateDynamicObject(1569, 2651.8137, -1712.8481, 1015.5438, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //ADAM_V_DOOR
    DSADLKAS[467] = CreateDynamicObject(19789, 2651.3410, -1707.2458, 1020.7448, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Cube1mx1m
    SetDynamicObjectMaterial(DSADLKAS[467], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    DSADLKAS[468] = CreateDynamicObject(1569, 2651.8137, -1712.7480, 1015.5438, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //ADAM_V_DOOR
    DSADLKAS[469] = CreateDynamicObject(2229, 2649.9929, -1703.2347, 1015.0100, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[470] = CreateDynamicObject(19444, 2652.3151, -1703.4416, 1020.6046, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[470], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[471] = CreateDynamicObject(2229, 2650.8737, -1703.8454, 1015.0100, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //SWANK_SPEAKER
    DSADLKAS[472] = CreateDynamicObject(19444, 2650.0844, -1705.0920, 1020.1663, 90.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[472], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[473] = CreateDynamicObject(2167, 2654.3198, -1704.5992, 1015.5623, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //MED_OFFICE_UNIT_7
    DSADLKAS[474] = CreateDynamicObject(19444, 2653.8955, -1703.4416, 1020.6046, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[474], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[475] = CreateDynamicObject(19444, 2652.3452, -1703.4416, 1017.2252, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[475], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[476] = CreateDynamicObject(19279, 2635.7312, -1701.7147, 1020.3220, -136.3000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //LCSmallLight1
    DSADLKAS[477] = CreateDynamicObject(2007, 2653.8471, -1708.0327, 1015.5791, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //filing_cab_nu01
    DSADLKAS[478] = CreateDynamicObject(19279, 2645.8378, -1712.9245, 1020.3280, -136.3000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //LCSmallLight1
    DSADLKAS[479] = CreateDynamicObject(19279, 2640.7944, -1712.9245, 1020.3280, -136.3000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //LCSmallLight1
    DSADLKAS[480] = CreateDynamicObject(2007, 2653.8471, -1706.0515, 1015.5791, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //filing_cab_nu01
    DSADLKAS[481] = CreateDynamicObject(19279, 2635.7312, -1712.9245, 1020.3280, -136.3000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //LCSmallLight1
    DSADLKAS[482] = CreateDynamicObject(2007, 2653.8471, -1709.0229, 1015.5791, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //filing_cab_nu01
    DSADLKAS[483] = CreateDynamicObject(19444, 2650.8051, -1703.4216, 1017.2252, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[483], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[484] = CreateDynamicObject(19444, 2653.8955, -1703.4416, 1017.2252, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[484], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[485] = CreateDynamicObject(19792, 2650.3881, -1705.0284, 1016.3770, 0.0000, 0.0000, -33.0000, 1064, 1, -1, 300.0, 300.0, -1); //SAMPKeycard1
    DSADLKAS[486] = CreateDynamicObject(19279, 2640.9135, -1701.7147, 1020.3220, -136.3000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //LCSmallLight1
    DSADLKAS[487] = CreateDynamicObject(19279, 2645.9255, -1701.7147, 1020.3220, -136.3000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //LCSmallLight1
    DSADLKAS[488] = CreateDynamicObject(7313, 2618.0908, -1725.8415, 1019.7473, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //vgsN_scrollsgn01
    SetDynamicObjectMaterial(DSADLKAS[488], 0, 14846, "genintintpoliceb", "coptop_pink", 0xFFFFFFFF);
    DSADLKAS[489] = CreateDynamicObject(19444, 2650.8051, -1712.8233, 1017.2252, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[489], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[490] = CreateDynamicObject(19444, 2652.3554, -1712.8033, 1017.2252, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[490], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[491] = CreateDynamicObject(19786, 2636.9550, -1697.5955, 1018.4071, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //LCDTVBig1
    DSADLKAS[492] = CreateDynamicObject(19893, 2650.4306, -1707.0124, 1016.3540, 0.0000, 0.0000, 90.0000, 1064, 1, -1, 300.0, 300.0, -1); //LaptopSAMP1
    DSADLKAS[493] = CreateDynamicObject(19893, 2650.4306, -1709.8735, 1016.3540, 0.0000, 0.0000, 132.8000, 1064, 1, -1, 300.0, 300.0, -1); //LaptopSAMP1
    DSADLKAS[494] = CreateDynamicObject(19894, 2650.4628, -1711.2092, 1016.3800, 0.0000, 0.0000, 52.8997, 1064, 1, -1, 300.0, 300.0, -1); //LaptopSAMP2
    DSADLKAS[495] = CreateDynamicObject(19786, 2636.9550, -1716.5943, 1018.4071, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //LCDTVBig1
    DSADLKAS[496] = CreateDynamicObject(1671, 2651.4787, -1704.6184, 1016.0031, 0.0000, 0.0000, -60.7999, 1064, 1, -1, 300.0, 300.0, -1); //swivelchair_A
    DSADLKAS[497] = CreateDynamicObject(19894, 2650.5019, -1704.5437, 1016.3800, 0.0000, 0.0000, 131.1999, 1064, 1, -1, 300.0, 300.0, -1); //LaptopSAMP2
    DSADLKAS[498] = CreateDynamicObject(1671, 2651.5476, -1707.0294, 1016.0031, 0.0000, 0.0000, -90.6997, 1064, 1, -1, 300.0, 300.0, -1); //swivelchair_A
    DSADLKAS[499] = CreateDynamicObject(1671, 2651.5175, -1709.2893, 1016.0031, 0.0000, 0.0000, -136.6999, 1064, 1, -1, 300.0, 300.0, -1); //swivelchair_A
    DSADLKAS[500] = CreateDynamicObject(19378, 2649.4599, -1711.9068, 1020.9863, 0.0000, 90.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall026
    SetDynamicObjectMaterial(DSADLKAS[500], 0, 14534, "ab_wooziea", "dt_office_roof", 0xFFFFFFFF);
    DSADLKAS[501] = CreateDynamicObject(19444, 2650.0844, -1708.5527, 1020.1666, 90.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[501], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[502] = CreateDynamicObject(2259, 2653.8637, -1712.0268, 1017.7642, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //Frame_Clip_6
    DSADLKAS[503] = CreateDynamicObject(19444, 2650.0844, -1711.1334, 1020.1666, 90.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall084
    SetDynamicObjectMaterial(DSADLKAS[503], 0, 1675, "wshxrefhse", "greygreensubuild_128", 0xFFFFFFFF);
    DSADLKAS[504] = CreateDynamicObject(2267, 2654.3183, -1707.4787, 1018.1384, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //Frame_WOOD_3
    DSADLKAS[505] = CreateDynamicObject(19325, 2650.4880, -1710.7495, 1020.6642, -89.4999, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //lsmall_window01
    DSADLKAS[506] = CreateDynamicObject(19801, 2634.7485, -1702.9189, 1015.7039, 8.1997, -0.5999, 6.4000, 1064, 1, -1, 300.0, 300.0, -1); //Balaclava1
    DSADLKAS[507] = CreateDynamicObject(11706, 2646.3356, -1716.1097, 1015.5297, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //SmallWasteBin1
    DSADLKAS[508] = CreateDynamicObject(2826, 2631.8374, -1698.2292, 1015.9489, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //GB_novels04
    DSADLKAS[509] = CreateDynamicObject(2824, 2639.6735, -1714.4487, 1015.9630, 0.0000, 0.0000, 88.8001, 1064, 1, -1, 300.0, 300.0, -1); //GB_novels02
    DSADLKAS[510] = CreateDynamicObject(19835, 2650.5629, -1704.1302, 1016.4655, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //CoffeeCup1
    DSADLKAS[511] = CreateDynamicObject(2886, 2654.3886, -1699.6805, 1017.1151, 0.0000, 0.0000, -90.0000, 1064, 1, -1, 300.0, 300.0, -1); //sec_keypad
    DSADLKAS[512] = CreateDynamicObject(2257, 2645.2187, -1697.6867, 1018.2163, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Frame_Clip_4
    DSADLKAS[513] = CreateDynamicObject(2271, 2644.3532, -1716.0605, 1017.8402, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //Frame_WOOD_1
    DSADLKAS[514] = CreateDynamicObject(2258, 2648.4541, -1697.6612, 1018.0916, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //Frame_Clip_5
    DSADLKAS[515] = CreateDynamicObject(2256, 2646.0498, -1716.5279, 1018.2064, 0.0000, 0.0000, 180.0000, 1064, 1, -1, 300.0, 300.0, -1); //Frame_Clip_3
    DSADLKAS[516] = CreateDynamicObject(1550, 2654.0058, -1703.9422, 1015.9588, 0.0000, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //CJ_MONEY_BAG
    DSADLKAS[517] = CreateDynamicObject(19438, 2618.3803, -1725.5310, 1015.9067, 38.8998, 0.0000, 0.0000, 1064, 1, -1, 300.0, 300.0, -1); //wall078
    SetDynamicObjectMaterial(DSADLKAS[517], 0, 10101, "2notherbuildsfe", "sl_vicwall02", 0xFFFFFFFF);
    
    // Npcs
    new id;
    id = CreateDynamicActor(random(311), 2639.6909,-1702.1033,1016.9533,267.2349, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
    id = CreateDynamicActor(random(311), 2636.9995,-1711.4753,1016.9481,268.3375, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
    id = CreateDynamicActor(random(311), 2639.7244,-1715.2029,1016.9547,269.8569, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
    id = CreateDynamicActor(random(311), 2642.5784,-1710.8666,1016.9551,270.2719, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);

    // Funcionários
    id = CreateDynamicActor(211, 2625.2241,-1715.4656,1016.5886,179.1788, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);

    // Caixas
    id = CreateDynamicActor(17, 2651.2229,-1711.0284,1016.5886,93.1363, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "PED","IDLE_CHAT",4.0,1,0,0,1,1);
    id = CreateDynamicActor(141, 2651.2083,-1707.6006,1016.5886,78.8022, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "PED","IDLE_CHAT",4.0,1,0,0,1,1);

    // Cara da Reforma
    CreateDynamicActor(260, 2650.8550,-1698.6456,1016.5886,306.6568, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);

    // Seguranças
    id = CreateDynamicActor(71, 2615.2729,-1718.4008,1016.5886,341.8157, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "DEALER","DEALER_IDLE",4.0,1,0,0,0,0);
    id = CreateDynamicActor(71, 2628.9395,-1710.4839,1016.5886,31.1454, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "DEALER","DEALER_IDLE",4.0,1,0,0,0,0);
    id = CreateDynamicActor(71, 2649.9934,-1715.0953,1016.5886,61.1887, 1, 100.0, 1064, 1, -1, 300.0, -1, 0);
    ApplyDynamicActorAnimation(id, "DEALER","DEALER_IDLE",4.0,1,0,0,0,0);
    return 1;
}