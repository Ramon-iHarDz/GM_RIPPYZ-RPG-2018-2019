#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    if(vDados[playerid][SetVeh] == false)
    {
        KillTimer(vDados[playerid][UpdateVeiculo]);
        new Limpar[ConfigVeiculo];
        vDados[playerid] = Limpar;
    }
    return 1;
}

hook OnVehicleSpawn(vehicleid)
{
    if(VeiculoServer[vehicleid][vQuebrado] == true) SetVehicleHealth(vehicleid, 390);
    return 1;
}

hook OnVehicleDeath(vehicleid, killerid)
{
    if(VeiculoServer[vehicleid][vQuebrado] == false)
    {
        for(new i=0; i < MAX_PLAYERS; i++)
        {
            if(!IsPlayerConnected(i)) continue;
            if(Jogador[i][Logado] == false) continue;
            if(GetPlayerState(i) != PLAYER_STATE_DRIVER) continue;
            if(GetPlayerVehicleID(i) != vehicleid) continue;
            new Float:jPos[3];
            new engine, lights, alarm, doors, bonnet, boot, objective;
            GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
            SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_OFF, VEHICLE_PARAMS_OFF, alarm, doors, bonnet, boot, objective); 
            GetVehiclePos(vehicleid, jPos[0], jPos[1], jPos[2]);
            SetPlayerPos(i, jPos[0], jPos[1], jPos[2]+2);
            SetPVarInt(i, "Anomaly", gettime()+20); 
            break;
        }
        VeiculoServer[vehicleid][vQuebrado] = true;
    }
    return 1;
}

function VeiculoUpdateExx(playerid)
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "VeiculoUpdateExx", 1)) return 1;

    //Atualizar Velocimetro
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && cDados[playerid][VeloHab] == true)
    {
        if(VeiculoServer[GetPlayerVehicleID(playerid)][VeiculoOn] == false) return 1;

        // Variaveis e Stings
        new VelocidadeMostrar[90],
            Float:VidaBV;

        format(VelocidadeMostrar, sizeof(VelocidadeMostrar), "~r~%d~w~_Km/h", GetPlayerSpeed(playerid));
        PlayerTextDrawSetString(playerid, VelocimetroRC[playerid][1], VelocidadeMostrar);

        format(VelocidadeMostrar, sizeof(VelocidadeMostrar), "%s:_~g~%0.1fL", PegarGasolina(GetPlayerVehicleID(playerid)), VeiculoServer[GetPlayerVehicleID(playerid)][Gasolina]);
        PlayerTextDrawSetString(playerid, VelocimetroRC[playerid][2], VelocidadeMostrar);

        format(VelocidadeMostrar, sizeof(VelocidadeMostrar), "~y~%0.1f~w~_Km", VeiculoServer[GetPlayerVehicleID(playerid)][Kilometros]);
        PlayerTextDrawSetString(playerid, VelocimetroRC[playerid][3], VelocidadeMostrar);

        // Verificar estado do veículo
        GetVehicleHealth(GetPlayerVehicleID(playerid), VidaBV);
        if(VidaBV <= 390)
        {
            new engine, lights, alarm, doors, bonnet, boot, objective;
            GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
            SetVehicleParamsEx(GetPlayerVehicleID(playerid), VEHICLE_PARAMS_OFF, VEHICLE_PARAMS_OFF, alarm, doors, bonnet, boot, objective); 
            VeiculoServer[GetPlayerVehicleID(playerid)][vQuebrado] = true;
            
            new Float:jPos[3];
            GetVehiclePos(GetPlayerVehicleID(playerid), jPos[0], jPos[1], jPos[2]);
            SetPlayerPos(playerid, jPos[0], jPos[1], jPos[2]+2);
            SetPVarInt(playerid, "Anomaly", gettime()+20); 
            SendClientMessage(playerid, 0xFF4500FF, "| VEÍCULO | Esse veículo parou de funcionar");
        }
    }

    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
        Jogador[playerid][uVeiculo] = GetPlayerVehicleID(playerid);
        if(IsVehicleBicicleta(GetPlayerVehicleID(playerid))) return 1;
        if(IsVehicleLandVehicle(GetPlayerVehicleID(playerid)) || IsVehicleMoto(GetPlayerVehicleID(playerid))){
            Jogador[playerid][PodeRadar] = true;
        }
        cDados[playerid][VeloHab] = true;
        vDados[playerid][KmA] = 0;
        vDados[playerid][KmD] = 0;
        SetPVarInt(playerid, "DKASLDA", 1);
        MostrarVelocimetro(playerid);
    }

    else if(oldstate == PLAYER_STATE_DRIVER)
    {
        if(IsVehicleBicicleta(Jogador[playerid][uVeiculo])) return 1;
        Jogador[playerid][PodeRadar] = false;
        cDados[playerid][VeloHab] = false;
        if(GetPVarInt(playerid, "DKASLDA") == 1){
            OcultarVelocimetro(playerid);
            SetPVarInt(playerid, "DKASLDA", 0);
        }
    }
    return 1;
}

hook OnVehicleDamageStatusUp(vehicleid, playerid)
{
    if(VeiculoServer[vehicleid][AntiFurar] == false) return 1;
    // Obtenha o status de danos de todos os componentes
    new paineis, portas, luzzes, pneus;
    GetVehicleDamageStatus(vehicleid, paineis, portas, luzzes, pneus);

    // Defina os pneus para 0, o que significa que nenhum está estourado
    pneus = 0; 

    // Atualizar o status de danos do veículo com pneus não estourados
    UpdateVehicleDamageStatus(vehicleid, paineis, portas, luzzes, pneus);
    return 1; 
}