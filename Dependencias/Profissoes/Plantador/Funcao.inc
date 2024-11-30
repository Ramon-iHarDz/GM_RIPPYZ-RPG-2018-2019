stock PlantioID(playerid)
{
    for(new i=0; i < 10; i++)
    {
        if(Plantador[playerid][i][Plantado] == true) continue;
        return i;
    }
    return -1;
}

stock AcabarComPlantio(playerid, id)
{
    KillTimer(Plantador[playerid][id][PlantioTempo]);
    DestroyDynamicObjectEx(Plantador[playerid][id][PlantaObj]);
    DestroyDynamicMapIconEx(Plantador[playerid][id][IconePlantio]);
    DestroyDynamic3DTextLabelEx(Plantador[playerid][id][TextoPlantio]);
    Plantador[playerid][id][Plantado] = false;

    new FullFdss[PlantadorInfo];
    Plantador[playerid][id] = FullFdss;
    return 1;
}

function LimparPlantAnim(playerid)
{
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid);
    return 1;
}