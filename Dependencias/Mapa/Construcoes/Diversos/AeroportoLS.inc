#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicObject(16098,1887.6284200,-2648.1181600,17.4337000,0.0000000,0.0000000,91.0000000, -1, 0, -1, 450.0, 450.0, -1); //
    CreateDynamicObject(16098,1821.5504200,-2648.1181600,17.4337000,0.0000000,0.0000000,90.0000000, -1, 0, -1, 450.0, 450.0, -1); //
    CreateDynamicObject(16098,1755.0983900,-2648.1181600,17.4337000,0.0000000,0.0000000,90.0000000, -1, 0, -1, 450.0, 450.0, -1); //
    CreateDynamicObject(1290,1788.8149400,-2639.8867200,18.4766000,356.8584000,0.0000000,-3.1252000, -1, 0, -1, 450.0, 450.0, -1); //
    CreateDynamicObject(10814,1640.0671400,-2676.8034700,16.1545000,0.0000000,0.0000000,178.0000000, -1, 0, -1, 450.0, 450.0, -1); //
    CreateDynamicObject(1290,1720.9241900,-2639.8867200,18.4765600,356.8584000,0.0000000,-3.1251500, -1, 0, -1, 450.0, 450.0, -1); //
    CreateDynamicObject(1290,1630.1224400,-2656.9882800,18.4765600,356.8584000,0.0000000,-3.1251500, -1, 0, -1, 450.0, 450.0, -1); //
    CreateDynamicObject(1290,1646.1116900,-2657.5727500,18.4765600,356.8584000,0.0000000,-3.1251500, -1, 0, -1, 450.0, 450.0, -1); //
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 3672, 1889.6563, -2666.0078, 18.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3672, 1822.7344, -2666.0078, 18.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3672, 1682.7266, -2666.0078, 18.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3672, 1617.2813, -2666.0078, 18.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3672, 1754.1719, -2666.0078, 18.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3629, 1617.2813, -2666.0078, 18.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 1290, 1649.0625, -2641.4063, 18.4766, 0.25); // não faz parte do aero porto
    RemoveBuildingForPlayer(playerid, 3629, 1682.7266, -2666.0078, 18.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3629, 1754.1719, -2666.0078, 18.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3629, 1822.7344, -2666.0078, 18.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3629, 1889.6563, -2666.0078, 18.8828, 0.25);
   	RemoveBuildingForPlayer(playerid, 3350, -429.0547, 2237.8359, 41.2109, 0.25);

    // Grades
    RemoveBuildingForPlayer(playerid, 3769, 1961.4453, -2216.1719, 14.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1949.3438, -2227.5156, 13.6563, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1944.0625, -2227.5156, 13.6563, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1954.6172, -2227.4844, 13.6875, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1965.1719, -2227.4141, 13.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1959.8984, -2227.4453, 13.7266, 0.25);
    RemoveBuildingForPlayer(playerid, 3625, 1961.4453, -2216.1719, 14.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1975.7266, -2227.4141, 13.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1970.4453, -2227.4141, 13.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1981.0000, -2227.4141, 13.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1996.8281, -2227.3828, 13.7891, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1991.5547, -2227.4141, 13.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 1986.2813, -2227.4141, 13.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 1412, 2002.1094, -2227.3438, 13.8281, 0.25);
    return 1;
}