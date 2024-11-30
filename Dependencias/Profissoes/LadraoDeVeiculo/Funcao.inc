stock AtualizarLadrao(playerid, id)
{
    SetPVarInt(playerid, "IDRoubo", id);
    PlayerTextDrawSetString(playerid, RouboVeiculo[playerid][4], GetVehicleNameByModel(RouboLocal[id][RouboVeiculoModelo])); 
    PlayerTextDrawSetPreviewModel(playerid, RouboVeiculo[playerid][3], RouboLocal[id][RouboVeiculoModelo]);
    PlayerTextDrawShow(playerid, RouboVeiculo[playerid][3]);
    return 1;
} 

function PrepararLadraoVeh(playerid)
{
    for(new i=0; i < MAX_LOCALROUBO; i++){
        pLadraoV[playerid][CheckRoubo][i] = CreateDynamicCP(CheckRoubos[i][cRPosX], CheckRoubos[i][cRPosY], CheckRoubos[i][cRPosZ], 1.0, 0, 0, playerid, 20.0, -1);
        // pLadraoV[playerid][MappRoubo][i] = CreateDynamicMapIcon(CheckRoubos[i][cRPosX], CheckRoubos[i][cRPosY], CheckRoubos[i][cRPosZ], 56, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    }
    return 1;
}

function RemoverLadraoVeh(playerid)
{
    for(new i=0; i < MAX_LOCALROUBO; i++){
        DestroyDynamicCPEx(pLadraoV[playerid][CheckRoubo][i]);
        // DestroyDynamicMapIconEx(pLadraoV[playerid][MappRoubo][i]);
    }
    return 1;
}