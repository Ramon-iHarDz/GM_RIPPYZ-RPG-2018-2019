#include <YSI_Coding\y_hooks>
//#include "../Dependencias/Profissoes/Policia/Hooks/Veiculos/Modulos/VeiculoTxd"

enum VeiculosPMM
{
    ModeloPM,
    Float:vModeloPMX,
    Float:vModeloPMY,
    Float:vModeloPMZ,
    Float:vModeloPMA,
    vModeloCor1,
    vModeloCor2
};

new PoliciaPMV[][VeiculosPMM] = 
{
    // Los Santos
        //LS PD
    {596, 1558.8674, -1711.1658, 5.6127, 0.5370, 1, 116},
    {596, 1578.5146, -1711.5362, 5.6102, 179.1328, 1, 116},
    {596, 1602.2545, -1700.1250, 5.6109, 89.8572, 1, 116},
    {596, 1602.3355, -1691.9895, 5.5569, 89.9261, 1, 116},
    {596, 1545.5703, -1663.0820, 5.6119, 89.4850, 1, 116},
    {596, 1587.5395, -1711.2648, 5.6113, 359.4539, 1, 116},
        //Rancher
    {490, 1526.5268, -1644.7493, 6.0189, 0.2406, 0, 0},
    {490, 1534.6503, -1644.3952, 6.0185, 179.7454, 0, 0},
    {490, 1538.7395, -1644.3830, 6.0189, 180.8455, 0, 0},
        //Ranger
    {599, 1584.4954, -1671.6070, 6.0926, 268.6025, 116, 1},
    {599, 1584.5350, -1667.5242, 6.1571, 269.1589, 116, 1},
    {599, 1545.6125, -1672.1777, 6.0806, 90.3244, 116, 1},
    {599, 1545.6363, -1676.2980, 6.0791, 91.1741, 116, 1},
        //Enforcer
    {427, 1528.4364, -1688.1221, 6.0227, 90.0314, 0, 1},
    {427, 1529.0317, -1683.7985, 6.0224, 270.0838, 0, 1},
        //Nrg
    {523, 1574.5693, -1604.7281, 12.9476, 182.3719, 116, 116},
    {523, 1572.2684, -1604.7253, 12.9514, 181.0595, 116, 116},
    {523, 1569.9714, -1604.7441, 12.9510, 179.6631, 116, 116},
    {523, 1567.6177, -1604.7587, 12.9518, 180.0481, 116, 116},
    {523, 1564.8934, -1604.6216, 12.9507, 181.8003, 116, 116},
    {523, 1562.0330, -1604.5508, 12.9543, 180.3611, 116, 116},
    {522, 1559.4995, -1604.4814, 12.9534, 179.8804, 116, 116},
    {522, 1556.8596, -1604.4447, 12.9493, 182.7528, 116, 116},
    {522, 1554.3589, -1604.3322, 12.9530, 181.5814, 116, 116},
    {522, 1551.5139, -1604.3198, 12.9522, 176.7488, 116, 116},
        //BlueBerry
    {596, 614.7579,-601.7249,16.9494,271.7495, 1, 116},
    {596, 615.4171,-597.0927,16.9481,272.1284, 1, 116},
    {596, 631.2693,-610.2506,16.0529,359.7049, 1, 116},
    {596, 636.7438,-609.8866,16.0520,359.8698, 1, 116},


    // Las Venturas
        //LV PD
    {598, 2269.1428, 2442.8554, 10.5658, 359.4944, 1, 116},
    {598, 2273.4970, 2460.5451, 10.5653, 358.6411, 1, 116},
    {598, 2282.1586, 2459.4638, 10.5693, 179.6538, 1, 116},
    {598, 2282.1486, 2478.0664, 10.5679, 359.3270, 1, 116},
    {598, 2256.1943, 2477.8901, 10.5657, 177.3846, 1, 116},
        //Helis
    {497, 1566.9553, -1655.9214, 28.5723, 92.7273, 116, 1},
        //Rancher
    {490, 2256.0153, 2442.7553, 10.9514, 0.4565, 0, 0},
    {490, 2251.5708, 2442.6809, 10.9489, 0.2307, 0, 0},
        //Nrg
    {522, 2260.2744, 2459.4904, 10.3827, 177.0384, 116, 116},
    {523, 2255.7600, 2459.4675, 10.3843, 178.9856, 116, 116},
    {522, 2251.8500, 2459.3535, 10.3893, 0.0523, 116, 116},
        //El Quebrados
    {598, -1400.3091, 2650.2434, 55.4028, 90.2713, 1, 116},
    {523, -1399.6068, 2643.9849, 55.4027, 269.7675, 1, 116},
    {598, -1399.9009, 2637.6772, 55.4048, 270.1899, 1, 116},
    {490, -1400.1997, 2631.5728, 55.4708, 90.0228, 1, 116},
    {598, -1400.1166, 2659.6602, 55.4027, 89.9886, 1, 116},
        //Fort Carson
    {598, -210.6451, 1000.3450, 19.3905, 90.7365, 1, 116},
    {598, -210.2680, 994.5917, 19.2752, 91.8446, 1, 116},
    {598, -210.1615, 985.9055, 19.0985, 267.1163, 1, 116},
    {598, -228.3342, 998.4932, 19.2979, 0.1564, 1, 116},

    // San Fierro
        //SF PD
    {597, -1587.6597, 651.5798, 6.9567, 0.0544, 1, 116},
    {597, -1593.6152, 651.5136, 6.9555, 1.1147, 1, 116},
    {597, -1599.5101, 651.4595, 6.9555, 0.7428, 1, 116},
    {597, -1616.6701, 650.7000, 6.9583, 180.2853, 1, 116},
    {597, -1605.8698, 673.6641, 6.9567, 180.5849, 1, 116},
        //Heli
    {497, -1680.8240,705.9131,30.7782,269.8831, 116, 1},
        //Nrg
    {523, -1594.1765, 674.4277, 6.7540, 179.7948, 116, 116},
    {523, -1587.9951, 674.5495, 6.7588, 182.3526, 116, 116},
    {522, -1628.5379, 650.7818, 6.7562, 359.6522, 116, 116},
    {522, -1634.5416, 650.4873, 6.7587, 359.6209, 116, 116},
        //Angel Pine
    {597, -2176.4104,-2367.8748,30.3431,55.5351, 1, 116},
    {597, -2172.7397,-2363.0706,30.3424,230.9667, 1, 116}
};

new IdsPolicia[sizeof(PoliciaPMV)];

hook OnGameModeInit()
{
    new KAPP[2];
    for(new i=0; i < sizeof(PoliciaPMV); i++)
    {
        if(PoliciaPMV[i][ModeloPM] == 522)
        {
            IdsPolicia[i] = CreateVehicleEx(-1, PoliciaPMV[i][ModeloPM], PoliciaPMV[i][vModeloPMX], PoliciaPMV[i][vModeloPMY], PoliciaPMV[i][vModeloPMZ], PoliciaPMV[i][vModeloPMA], PoliciaPMV[i][vModeloCor1], PoliciaPMV[i][vModeloCor2], 360, 1);
            format(VeiculoServer[IdsPolicia[i]][LocalVerificacao], 20, "PoliciaVehVeri");
            VeiculoServer[IdsPolicia[i]][AntiFurar] = true;
            VeiculoServer[IdsPolicia[i]][AntiRadar] = true;
            VeiculoServer[IdsPolicia[i]][VidaMaxima] = 10000;
            SetVehicleHealth(IdsPolicia[i], VeiculoServer[IdsPolicia[i]][VidaMaxima]);

            KAPP[0] = CreateDynamicObject(18633, 0, 0, 0, 0, 0, 0, 0, 0, -1, 90.0, 90.0, -1);
            KAPP[1] = CreateDynamicObject(18646, 0, 0, 0, 0, 0, 0, 0, 0, -1, 90.0, 90.0, -1);
            AttachDynamicObjectToVehicle(KAPP[0], IdsPolicia[i], -0.000000, -0.990000, 0.770000, 268.000000, 179.100006, 0.000000); // Barra
            AttachDynamicObjectToVehicle(KAPP[1], IdsPolicia[i], 0.000000, -0.980000, 0.990000, 0.000000, 0.000000, 0.000000); // Luz
            continue;
        }   
        IdsPolicia[i] = CreateVehicleEx(-1, PoliciaPMV[i][ModeloPM], PoliciaPMV[i][vModeloPMX], PoliciaPMV[i][vModeloPMY], PoliciaPMV[i][vModeloPMZ], PoliciaPMV[i][vModeloPMA], PoliciaPMV[i][vModeloCor1], PoliciaPMV[i][vModeloCor2], 360, 0);
        format(VeiculoServer[IdsPolicia[i]][LocalVerificacao], 20, "PoliciaVehVeri");
        VeiculoServer[IdsPolicia[i]][AntiFurar] = true;
        VeiculoServer[IdsPolicia[i]][AntiRadar] = true;
        VeiculoServer[IdsPolicia[i]][VidaMaxima] = 20000;
        SetVehicleHealth(IdsPolicia[i], VeiculoServer[IdsPolicia[i]][VidaMaxima]);
    }

    CreateDynamic3DTextLabel("Blindagem - Los Santos{FFFFFF}\nUse: /RepararBlindagem", 0x32CD32FF, 1564.5667,-1710.2609,5.8906, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 31.0, -1);
    CreateDynamic3DTextLabel("Blindagem - Las Venturas{FFFFFF}\nUse: /RepararBlindagem", 0x32CD32FF, 2293.0720,2442.6560,10.8203, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 31.0, -1);
    return 1;
}

function PoliciaVehVeri(playerid, vehicleid)
{
    if(Jogador[playerid][Admin] > 1) return true;
    for(new i=0; i < sizeof(PoliciaPMV); i++)
    {
        if(IdsPolicia[i] != vehicleid) continue;
        if(!IsPolicia(playerid)){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            return false;
        }
        if(pPolicia[playerid][PegouUniformePolicia] == false){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está fardado(a)");
            return false;
        }
        if(!VerificarCargoEPM(playerid, vehicleid)){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse veículo");
            return false;
        }
        if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){
            if(Jogador[playerid][Estrelas] > 0){
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
                return false;
            }
        }
        break;
    }
    return true;
}

stock VeiculoPoliceVeh(playerid)
{
    for(new i=0; i < sizeof(PoliciaPMV); i++)
    {
        if(IdsPolicia[i] == Jogador[playerid][uVeiculo]) return true;
    }
    return false;
}

stock VerificarCargoEPM(playerid, id)
{
    switch(GetVehicleModel(id))
    {
        // Nrg, HPV, LVPD, LSPD, SFPD, Ranger
        case 522, 523, 598, 596, 597, 599, 497:{
            if(IsPolicia(playerid)) return true;
        }

        // Enforcer
        case 427:{
            if(!strcmp(Jogador[playerid][Profissao], "Bope")) return true;
        }

        // Rancher
        case 490:{
            if(!strcmp(Jogador[playerid][Profissao], "Força Tática")) return true;   
        }
    }
    return false;
}

function BlindagemDp(playerid)
{
    SetPVarInt(playerid, "DASDDASLDA", 0);
    TogglePlayerControllable(playerid, 1);
    new id = GetPlayerVehicleID(playerid);
    SetVehicleHealth(id, VeiculoServer[id][VidaMaxima]);
    return 1;
}

CMD:repararblindagem(playerid, params[])
{
    if(!IsPlayerInRangeOfPoint(playerid, 6.0, 2293.0720,2442.6560,10.8203) && 
    !IsPlayerInRangeOfPoint(playerid, 6.0, 1564.5667,-1710.2609,5.8906)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em uma área de blindagem");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPVarInt(playerid, "DASDDASLDA") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está fazendo o reparo, aguarde.");
    SetPVarInt(playerid, "DASDDASLDA", 1);
    TogglePlayerControllable(playerid, 0);
    new id = GetPlayerVehicleID(playerid);
    if(VeiculoServer[id][AntiFurar] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse veículo não é blindado");
    CriarProgresso(playerid, "Blindando veículo, aguarde.", "BlindagemDp", 400);
    return 1;
}