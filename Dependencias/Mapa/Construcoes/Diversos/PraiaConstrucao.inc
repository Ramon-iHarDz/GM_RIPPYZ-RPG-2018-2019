#include <YSI_Coding\y_hooks>



hook OnGameModeInit()
{
    new praiah_Object[34];
    praiah_Object[0] = CreateDynamicObject(19632, 254.1090, -1820.7750, 3.0229, 0.0000, 0.0000, 134.89980, -1, 0, -1, 200.0, 200.0, -1, 0); //FireWood1
    praiah_Object[1] = CreateDynamicObject(1432, 257.0587, -1817.0385, 3.2603, 0.0000, 0.0000, -162.40000, -1, 0, -1, 200.0, 200.0, -1, 0); //DYN_TABLE_2
    praiah_Object[2] = CreateDynamicObject(1432, 250.7446, -1817.0189, 3.2303, 0.0000, 0.0000, 27.79990, -1, 0, -1, 200.0, 200.0, -1, 0); //DYN_TABLE_2
    praiah_Object[3] = CreateDynamicObject(1432, 250.7695, -1823.2048, 3.0503, 0.0000, 0.0000, 153.19990, -1, 0, -1, 200.0, 200.0, -1, 0); //DYN_TABLE_2
    praiah_Object[4] = CreateDynamicObject(1432, 257.0968, -1823.5148, 3.0603, 0.0000, 0.0000, 88.80000, -1, 0, -1, 200.0, 200.0, -1, 0); //DYN_TABLE_2
    praiah_Object[5] = CreateDynamicObject(19632, 253.9106, -1820.7738, 3.0229, 0.0000, 0.0000, -139.49970, -1, 0, -1, 200.0, 200.0, -1, 0); //FireWood1
    praiah_Object[6] = CreateDynamicObject(19632, 254.1235, -1820.5924, 3.0229, 0.0000, 0.0000, -139.49970, -1, 0, -1, 200.0, 200.0, -1, 0); //FireWood1
    praiah_Object[7] = CreateDynamicObject(19632, 253.9394, -1820.6051, 3.0229, 0.0000, 0.0000, 134.89980, -1, 0, -1, 200.0, 200.0, -1, 0); //FireWood1
    praiah_Object[8] = CreateDynamicObject(2858, 250.7022, -1823.2813, 3.6505, 0.0000, 0.0000, 30.29990, -1, 0, -1, 200.0, 200.0, -1, 0); //gb_kitchtakeway03
    praiah_Object[9] = CreateDynamicObject(11722, 250.9913, -1816.7677, 3.9809, 0.0000, 0.0000, 35.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //SauceBottle1
    praiah_Object[10] = CreateDynamicObject(2768, 250.6636, -1816.8707, 3.8894, 0.0000, 0.0000, -146.90000, -1, 0, -1, 200.0, 200.0, -1, 0); //CJ_CB_BURG
    praiah_Object[11] = CreateDynamicObject(2768, 250.5554, -1817.3211, 3.8894, 0.0000, 0.0000, -24.90000, -1, 0, -1, 200.0, 200.0, -1, 0); //CJ_CB_BURG
    praiah_Object[12] = CreateDynamicObject(2769, 251.1643, -1817.0357, 3.8656, 0.0000, 0.0000, 94.10000, -1, 0, -1, 200.0, 200.0, -1, 0); //CJ_CJ_BURG2
    praiah_Object[13] = CreateDynamicObject(2703, 250.4288, -1817.3088, 3.9406, -38.0000, -166.8999, -93.10000, -1, 0, -1, 200.0, 200.0, -1, 0); //CJ_BURG_1
    praiah_Object[14] = CreateDynamicObject(19580, 257.0934, -1817.1265, 3.8795, 0.0000, 0.0000, 40.99990, -1, 0, -1, 200.0, 200.0, -1, 0); //Pizza1
    praiah_Object[15] = CreateDynamicObject(1486, 257.3379, -1816.7919, 4.0075, 0.0000, 0.0000, -105.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //DYN_BEER_1
    praiah_Object[16] = CreateDynamicObject(1486, 256.6765, -1817.0100, 3.9075, 90.0000, -144.2999, -25.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //DYN_BEER_1
    praiah_Object[17] = CreateDynamicObject(1486, 256.9527, -1817.4549, 4.0075, 0.0000, 0.0000, -178.30000, -1, 0, -1, 200.0, 200.0, -1, 0); //DYN_BEER_1
    praiah_Object[18] = CreateDynamicObject(1342, 245.4867, -1820.5167, 4.0906, 0.0000, 0.0000, 0.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //noodlecart_prop
    praiah_Object[19] = CreateDynamicObject(1340, 253.9318, -1827.7265, 3.9565, 0.0000, 0.0000, 90.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //chillidogcart
    praiah_Object[20] = CreateDynamicObject(1341, 254.5599, -1813.4313, 4.2323, 0.0000, 0.0000, -90.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //icescart_prop
    praiah_Object[21] = CreateDynamicObject(2857, 256.9966, -1823.5880, 3.6706, 0.0000, 0.0000, 170.50020, -1, 0, -1, 200.0, 200.0, -1, 0); //gb_kitchtakeway02
    praiah_Object[22] = CreateDynamicObject(1215, 259.4024, -1825.8646, 3.4184, 0.0000, 0.0000, 0.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //bollardlight
    praiah_Object[23] = CreateDynamicObject(1215, 247.8325, -1825.8646, 3.4384, 0.0000, 0.0000, 0.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //bollardlight
    praiah_Object[24] = CreateDynamicObject(1215, 247.8325, -1815.0704, 3.7684, 0.0000, 0.0000, 0.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //bollardlight
    praiah_Object[25] = CreateDynamicObject(1215, 259.2427, -1815.0704, 3.7284, 0.0000, 0.0000, 0.00000, -1, 0, -1, 200.0, 200.0, -1, 0); //bollardlight
    praiah_Object[26] = CreateDynamicObject(2233, 247.6318, -1826.2656, 2.8857, 0.0000, 0.0000, 116.90000, -1, 0, -1, 200.0, 200.0, -1, 0); //SWANK_SPEAKER_4
    praiah_Object[27] = CreateDynamicObject(2233, 247.0432, -1825.1071, 2.9157, 0.0000, 0.0000, 116.90000, -1, 0, -1, 200.0, 200.0, -1, 0); //SWANK_SPEAKER_4
    praiah_Object[28] = CreateDynamicObject(2233, 247.3739, -1814.9598, 3.2057, 0.0000, 0.0000, 42.20000, -1, 0, -1, 200.0, 200.0, -1, 0); //SWANK_SPEAKER_4
    praiah_Object[29] = CreateDynamicObject(2233, 248.3444, -1814.0799, 3.2157, 0.0000, 0.0000, 42.20000, -1, 0, -1, 200.0, 200.0, -1, 0); //SWANK_SPEAKER_4
    praiah_Object[30] = CreateDynamicObject(2233, 259.3435, -1814.5616, 3.2357, 0.0000, 0.0000, -45.29980, -1, 0, -1, 200.0, 200.0, -1, 0); //SWANK_SPEAKER_4
    praiah_Object[31] = CreateDynamicObject(2233, 260.2994, -1815.5267, 3.2357, 0.0000, 0.0000, -45.29980, -1, 0, -1, 200.0, 200.0, -1, 0); //SWANK_SPEAKER_4
    praiah_Object[32] = CreateDynamicObject(2233, 260.0180, -1825.8811, 2.8957, 0.0000, 0.0000, -131.99990, -1, 0, -1, 200.0, 200.0, -1, 0); //SWANK_SPEAKER_4
    praiah_Object[33] = CreateDynamicObject(2233, 259.0075, -1827.0048, 2.8657, 0.0000, 0.0000, -131.99990, -1, 0, -1, 200.0, 200.0, -1, 0); //SWANK_SPEAKER_4
    return 1;
}