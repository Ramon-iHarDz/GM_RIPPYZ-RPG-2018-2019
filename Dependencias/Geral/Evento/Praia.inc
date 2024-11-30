#include <YSI_Coding\y_hooks>
new Priaa;

hook OnGameModeInit()
{
    Priaa = CreateDynamicRectangle(108, -2105.5, 479, -1719.5, 0, 0, -1);

    CreateDynamicObject(19342, 287.34201, -1841.80090, 2.97600,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19342, 267.91800, -1800.16064, 3.91780,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19342, 214.42909, -1806.86475, 3.98240,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19342, 233.27319, -1839.82483, 3.02010,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19342, 188.77209, -1864.63318, 2.54440,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19342, 264.72891, -1866.70435, 2.14940,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19342, 223.97220, -1873.43494, 1.72750,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19342, 339.51541, -1839.35400, 3.09920,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19342, 321.77109, -1865.83472, 2.38490,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19342, 289.01779, -1872.83887, 5.86410,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19341, 316.71301, -1842.63831, 3.18050,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19341, 351.83981, -1871.76709, 2.83680,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19341, 296.71619, -1815.25488, 3.94180,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19341, 225.45230, -1856.24146, 2.79830,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19341, 200.40076, -1872.85950, 5.90970,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19341, 228.95039, -1784.76221, 3.93130,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19341, 173.73399, -1791.71179, 3.75090,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3461, 308.42831, -1812.85962, 4.93760,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3461, 308.42831, -1817.07056, 4.83360,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3461, 330.87241, -1817.36682, 4.84100,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3461, 337.42441, -1817.36682, 4.84100,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19336, 321.51898, -1853.64124, 26.01455,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19336, 184.92133, -1800.01501, 35.96191,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19337, 272.48462, -1804.96448, 22.67194,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19338, 218.12256, -1868.45886, 42.29970,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19335, 265.87018, -1846.11646, 27.60646,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(19341, 321.43353, -1853.64783, 26.74484,   0.00000, 0.00000, 5.27459);
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid != Priaa) return 1;
    MostrarTextoEvento(playerid);
    ResetPlayerWeapons(playerid);
    PlayAudioStreamForPlayer(playerid, "http://66.70.177.195:8048/stream");
    SetPVarInt(playerid, "NoEvento", 1);
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{
    if(areaid != Priaa) return 1;
    OcultarTextoEvento(playerid);
    SetPVarInt(playerid, "NoEvento", 0);
    StopAudioStreamForPlayer(playerid);
    return 1;
}

hook OnPlayerMochila(playerid, arma, bala, type)
{
    if(GetPVarInt(playerid, "NoEvento") == 0) return 1;
    switch(type)
    {
        case 1:
        {
            ResetPlayerWeapons(playerid);
            SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você não pode usar armas no evento");
        }
    }
    return 1;
}

hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
    if(damagedid == INVALID_PLAYER_ID) return 1;
    if(GetPVarInt(playerid, "NoEvento") == 1){
        TogglePlayerControllable(playerid, 0);
        SetTimerEx("Destravar", 3000, false, "d", playerid);
        SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você não pode fazer D.M");
    }
    return 1;
}