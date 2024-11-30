#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicObject(3402, -380.35110, -1421.63867, 24.73510,   0.00000, 0.00000, 0.00000, -1, 0, -1, 250.0, 250.0, -1);
    CreateDynamicObject(17057, -380.46545, -1418.56104, 28.10456,   0.00000, 0.00000, 0.00000, -1, 0, -1, 250.0, 250.0, -1);
    CreateDynamicObject(2115, -386.18729, -1417.56665, 24.73738,   0.00000, 0.00000, 0.00000, -1, 0, -1, 250.0, 250.0, -1);
    CreateDynamicObject(341, -385.69720, -1417.54028, 25.74640,   0.00000, 24.05000, 339.82321, -1, 0, -1, 250.0, 250.0, -1);
    CreateDynamicObject(341, -385.80246, -1417.31946, 25.74640,   0.00000, 24.05000, 214.15288, -1, 0, -1, 250.0, 250.0, -1);
    CreateDynamicObject(19793, -386.46011, -1417.36084, 25.75630,   0.50000, 90.00000, 0.00000, -1, 0, -1, 250.0, 250.0, -1);
    CreateDynamicObject(19793, -385.75516, -1417.89160, 25.61230,   0.50000, 0.00000, 0.00000, -1, 0, -1, 250.0, 250.0, -1);
    CreateDynamicObject(14872, -366.68900, -1430.85181, 24.72004,   0.00000, 0.00000, 0.00000, -1, 0, -1, 250.0, 250.0, -1);
    return 1;
} 

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 785, -445.6875, -1517.4688, 13.2656, 0.25);
    RemoveBuildingForPlayer(playerid, 791, -445.6875, -1517.4688, 13.2656, 0.25);
    RemoveBuildingForPlayer(playerid, 735, -410.7031, -1520.8203, 20.4141, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -448.0938, -1442.9531, 23.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 735, -461.9766, -1459.5703, 15.1172, 0.25);
    RemoveBuildingForPlayer(playerid, 800, -467.6875, -1421.5469, 18.1250, 0.25);
    RemoveBuildingForPlayer(playerid, 800, -454.7891, -1421.3438, 19.5000, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -425.9531, -1432.7813, 25.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 735, -420.5547, -1459.5703, 21.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 17000, -406.9141, -1448.9688, 24.6406, 0.25);
    RemoveBuildingForPlayer(playerid, 3276, -384.2344, -1455.8281, 25.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 17005, -391.1406, -1432.9922, 32.4297, 0.25);
    RemoveBuildingForPlayer(playerid, 17006, -394.9609, -1433.9688, 32.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 17298, -366.6719, -1422.6875, 30.3750, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -372.1797, -1434.6094, 25.5156, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -369.1953, -1434.6094, 25.5156, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -366.2031, -1434.6094, 25.4375, 0.25);
    RemoveBuildingForPlayer(playerid, 1454, -363.2109, -1434.6094, 25.3984, 0.25);
    RemoveBuildingForPlayer(playerid, 790, -396.6484, -1482.0078, 29.6484, 0.25);
    return 1;
}