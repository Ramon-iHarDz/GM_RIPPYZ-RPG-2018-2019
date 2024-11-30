#include <YSI_Coding\y_hooks>

enum GasolinaInfo
{
    VehModelo,
    GasTipo[90]
};

new pGas[][GasolinaInfo] =
{
    //Caminhões e Veiculos de Transporte
    {403, "Diesel"},
    {406, "Diesel"},
    {407, "Diesel"},
    {408, "Diesel"},
    {414, "Diesel"},
    {427, "Diesel"},
    {431, "Diesel"},
    {433, "Diesel"},
    {437, "Diesel"},
    {443, "Diesel"},
    {455, "Diesel"},
    {456, "Diesel"},
    {498, "Diesel"},
    {508, "Diesel"},
    {514, "Diesel"},
    {515, "Diesel"},
    {524, "Diesel"},
    {573, "Diesel"},
    {578, "Diesel"},
    {416, "Diesel"},
    {428, "Diesel"},
    {537, "Diesel"},
    {538, "Diesel"},


    //Aviões
    {593, "Avgas"},
    {592, "Avgas"},
    {577, "Avgas"},
    {553, "Avgas"},
    {520, "Avgas"},
    {519, "Avgas"},
    {513, "Avgas"},
    {512, "Avgas"},
    {511, "Avgas"},
    {476, "Avgas"},
    {460, "Avgas"},
    {460, "Avgas"},

    //Heli
    {417, "Avgas"},
    {425, "Avgas"},
    {469, "Avgas"},
    {487, "Avgas"},
    {488, "Avgas"},
    {497, "Avgas"},
    {548, "Avgas"},
    {563, "Avgas"}, 
    {563, "Avgas"}
};

enum JogadorGaz
{
    bool:Encerrar,
    TempoGasss
};
new JGaz[MAX_PLAYERS][JogadorGaz];

hook OnPlayerConnect(playerid)
{
    if(JGaz[playerid][Encerrar] == false){
        JGaz[playerid][TempoGasss] = SetTimerEx("Quilometro", 500, true, "d", playerid); 
        JGaz[playerid][Encerrar] = true;   
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(JGaz[playerid][Encerrar] == true){
        KillTimer(JGaz[playerid][TempoGasss]);
    }
    new sadas[JogadorGaz];
    JGaz[playerid] = sadas;
    return 1;
}

stock PegarGasolina(veiculid)
{
    new Gazzz[70] = "Gasolina";
    for(new i=0; i < sizeof(pGas); i++){
        if(GetVehicleModel(veiculid) == pGas[i][VehModelo]){
            if(!strcmp(pGas[i][GasTipo], "Diesel")) Gazzz = "Diesel";
            else if(!strcmp(pGas[i][GasTipo], "Avgas")) Gazzz = "Avgas";
            break;
        }
    }
    return(Gazzz);
}

stock SuporteGasolina(const GasolinaVer[])
{
    new ValorGazMax = 60;
    if(!strcmp(GasolinaVer, "Diesel")) ValorGazMax = 300;
    else if(!strcmp(GasolinaVer, "Avgas")) ValorGazMax = 400;
    return ValorGazMax;
}

function Quilometro(playerid)
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "QuilometroTrav", 1)) return 1;
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new id = GetPlayerVehicleID(playerid);
        if(IsVehicleBicicleta(id)) return 1;
        if(GetVehicleSpeed(id) > 5)
        {
            // Gasolina acabou
            if(VeiculoServer[id][Gasolina] <= 0)
            {
                new engine, lights, alarm, doors, bonnet, boot, objective;
                GetVehicleParamsEx(id, engine, lights, alarm, doors, bonnet, boot, objective);
                SetPVarInt(playerid, "Anomaly", gettime()+10);
                SetVehicleParamsEx(id, VEHICLE_PARAMS_OFF, VEHICLE_PARAMS_OFF, alarm, doors, bonnet, boot, objective); 
                new Float:jPos[3];
                GetVehiclePos(GetPlayerVehicleID(playerid), jPos[0], jPos[1], jPos[2]);
                SetPlayerPos(playerid, jPos[0], jPos[1], jPos[2]+2);
                SendClientMessage(playerid, 0xFF4500FF, "| VEÍCULO | Esse veículo está sem gasolina");
                return 1;
            }

            // Descer gasossa
            if(VeiculoServer[id][Gasolina] > 0.0)
            {
                vDados[playerid][KmA] += 1;
                vDados[playerid][KmD] += 1;
                if(vDados[playerid][KmA] >= (2*4))
                {
                    VeiculoServer[id][Gasolina] -= 0.1;
                    vDados[playerid][KmA] = 0;

                    if(VeiculoServer[id][Gasolina] == 2.0) AlertaGasolina(playerid);
                    else if(VeiculoServer[id][Gasolina] == 1.5) AlertaGasolina(playerid);
                    else if(VeiculoServer[id][Gasolina] == 1.0) AlertaGasolina(playerid);
                    else if(VeiculoServer[id][Gasolina] == 0.5) AlertaGasolina(playerid);
                }

                if(vDados[playerid][KmD] >= (2*1)){
                    VeiculoServer[id][Kilometros] += 0.1;
                    vDados[playerid][KmD] = 0;
                }
            }

        }
    }

    if(GetPVarInt(playerid, "JaPegouJert") == 1 && GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_USEJETPACK)
    {
        OcultarJetPack(playerid);
        SetPVarInt(playerid, "JaPegouJert", 0); 
    }

    else if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
    {
        if(GetPVarInt(playerid, "JaPegouJert") == 0){
            MostrarJetPack(playerid);
            SetPVarInt(playerid, "JaPegouJert", 1);
            vDados[playerid][GaA] = 0;  
        }

        if(GetPlayerSpeed(playerid) > 0)
        {
            if(Jogador[playerid][GasJetpack] <= 0){
                new Float:Los[3];
                GetPlayerPos(playerid, Los[0], Los[1], Los[2]);
                SetPlayerPos(playerid, Los[0], Los[1], Los[2]+1);
                SendClientMessage(playerid, 0xFF4500FF, "| JETPACK | Você não tem gás para sua jetpack");
                return 1;
            }

            if(Jogador[playerid][GasJetpack] > 0)
            {
                vDados[playerid][GaA] += 1;
                if(vDados[playerid][GaA] >= (2*14)){
                    Jogador[playerid][GasJetpack] -= 1;
                    vDados[playerid][GaA] = 0;
                }
            }
        } 
        new GasStr[90];
        if(Jogador[playerid][GasJetpack] < 6) format(GasStr, sizeof(GasStr), "Gás: ~r~%d m³", Jogador[playerid][GasJetpack]);
        else if(Jogador[playerid][GasJetpack] < 11) format(GasStr, sizeof(GasStr), "Gás: ~y~%d m³", Jogador[playerid][GasJetpack]);
        else format(GasStr, sizeof(GasStr), "Gás: ~g~%d m³", Jogador[playerid][GasJetpack]);
        PlayerTextDrawSetString(playerid, GasN[playerid][0], ConverterTexto(GasStr));
    } 
    return 1;
}

stock VerificarGasolina(vehicleid)
{
    if(VeiculoServer[vehicleid][Gasolina] <= 0.2) return false;
    return true;
}

stock AlertaGasolina(playerid)
{
    PlayerPlaySound(playerid, 1056, 0.0, 0.0, 0.0);
    SendClientMessage(playerid, 0xFF4500FF, "| GASOLINA | Sua gasolina está acabando, procure um posto para abastecer");
    return 1;
}