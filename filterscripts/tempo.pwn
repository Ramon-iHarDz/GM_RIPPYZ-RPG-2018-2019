#include <a_samp>
#include <sscanf2>
#include <zcmd>

CMD:tempo(playerid, params[])
{
    new hora, id;
    if(sscanf(params, "dd", hora, id)) return 0;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        SetPlayerTime(i, hora, id);
    }
    return 1;
}

CMD:limpar(playeriod)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        RemoveBuildingForPlayer(i, 617, 1147.3672, 2722.9844, 9.4375, 0.25);
        RemoveBuildingForPlayer(i, 621, 1121.8438, 2732.4375, 9.8281, 0.25);
        RemoveBuildingForPlayer(i, 645, 1133.2109, 2741.0938, 9.8203, 0.25);
        RemoveBuildingForPlayer(i, 645, 1130.4219, 2784.9219, 9.8203, 0.25);
        RemoveBuildingForPlayer(i, 622, 1157.2344, 2783.4063, 9.8203, 0.25);
        RemoveBuildingForPlayer(i, 647, 1129.9609, 2784.0234, 11.2891, 0.25);
        RemoveBuildingForPlayer(i, 647, 1127.1328, 2783.3672, 11.2891, 0.25);
        RemoveBuildingForPlayer(i, 645, 1122.1250, 2788.0234, 9.3281, 0.25);
        RemoveBuildingForPlayer(i, 647, 1128.5859, 2786.9453, 11.2891, 0.25);
        RemoveBuildingForPlayer(i, 617, 1120.7266, 2810.2188, 9.4375, 0.25);
    }
    return 1;
}