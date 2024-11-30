#include <YSI_Coding\y_hooks>

enum BombaPlayer
{
    bool:DeletBomb,
    bool:EstaNaBomba,
    BombaID,
    BombaTempo,
    bool:Abastecendo,
    Soma,
    Float:Soma1,
    bool:AbastecerSinal
};

enum BombasPosicao
{
    TipoGasolina[80],
    Float:BombaX,
    Float:BombaY,
    Float:BombaZ
};

enum JogadorFMecanico
{
    bool:ConsertandoV,
    ConsertandoT,

    bool:AbastecendoV,
    AbastecendoT
};

new pVMecanico[MAX_PLAYERS][JogadorFMecanico];

new Bomba[][BombasPosicao] =
{
    {"Normal", 2114.8823, 920.3292, 10.8203},
    {"Normal", 616.2808, 1691.0229, 6.5324},
    {"Normal", 71.1960, 1218.5313, 18.3561},
    {"Normal", 2639.6167, 1106.0062, 10.8203},
    {"Normal", 2202.3655, 2475.1648, 10.5474},
    {"Normal", 2146.9944, 2747.8127, 10.5474},
    {"Normal", 1595.8429, 2198.9832, 10.5474},
    {"Normal", 1595.8429, 2198.9832, 10.5474},
    {"Normal", -1328.5967, 2677.5657, 49.7896},
    {"Normal", -1471.5238, 1864.0540, 32.3599},
    {"Normal", -2407.8096, 975.9981, 45.0239},
    {"Normal", -1675.9823, 412.7946, 6.9068},
    {"Normal", 1943.4725, -1773.4291, 13.0954},
    {"Normal", 1004.1082, -938.8526, 41.8853},
    {"Normal", 655.5251, -564.7576, 16.0413},
    {"Normal", 1381.8420, 461.7998, 19.8044},
    {"Normal", -91.8792, -1170.3258, 2.1059},
    {"Normal", -2244.0688, -2560.8960, 31.6263},
    {"Normal", -1606.3562, -2713.7751, 48.2410},
    {"Aviao", 1388.6923, 1769.6042, 10.8203},
    {"Aviao", 255.8743, 2536.7644, 16.8047},
    {"Aviao", -1120.6318, -188.0804, 14.1440},
    {"Aviao", 1533.0397, -2629.1453, 13.5469},
    {"Trem", 1814.2649,-1953.8295,13.5469},
    {"Trem", -1944.3939,57.6755,25.7109}
};

new pBomba[MAX_PLAYERS][BombaPlayer];

hook OnPlayerConnect(playerid)
{
    if(pBomba[playerid][DeletBomb] == false){   
        pBomba[playerid][BombaTempo] = SetTimerEx("BombaAtt", 1000, true, "d", playerid);
        pBomba[playerid][DeletBomb] = true;
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    //if(pVMecanico[playerid][ConsertandoV] == true) KillTimer(pVMecanico[playerid][ConsertandoT]);
    //if(pVMecanico[playerid][AbastecendoV] == true) KillTimer(pVMecanico[playerid][AbastecendoT]);

    new sadas[JogadorFMecanico];
    pVMecanico[playerid] = sadas;

    if(pBomba[playerid][DeletBomb] == true){   
        KillTimer(pBomba[playerid][BombaTempo]);
        new dsada[BombaPlayer];
        pBomba[playerid] = dsada;
    }
    return 1;
}

function BombaAtt(playerid)
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "BombaAtt", 1)) return 1;

    if(pBomba[playerid][EstaNaBomba] == false)
    {
        for(new i=0; i < sizeof(Bomba); i++)
        {
            if(!IsPlayerInRangeOfPoint(playerid, 10.0, Bomba[i][BombaX], Bomba[i][BombaY], Bomba[i][BombaZ])) continue;
            MostrarLocalPosto(playerid);
            pBomba[playerid][BombaID] = i;
            pBomba[playerid][EstaNaBomba] = true;
            break;
        }
        return 1;
    }

    new id = pBomba[playerid][BombaID],
        vehid = GetPlayerVehicleID(playerid),
        engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehid, engine, lights, alarm, doors, bonnet, boot, objective);

    if(!IsPlayerInRangeOfPoint(playerid, 10.0, Bomba[id][BombaX], Bomba[id][BombaY], Bomba[id][BombaZ]) && pBomba[playerid][Abastecendo] == true || 
    engine == 1 && pBomba[playerid][Abastecendo] == true || 
    Jogador[playerid][Dinheiro] <= 10 && pBomba[playerid][Abastecendo] == true || 
    GetPlayerState(playerid) != PLAYER_STATE_DRIVER && pBomba[playerid][Abastecendo] == true ||
    GetPVarInt(playerid, "CancelarAbs") == 1)
    {
        if(pBomba[playerid][Abastecendo] == true)
        {
            if(Jogador[playerid][Dinheiro] <= 10) SendClientMessage(playerid, 0xFFFF00FF, "| POSTO | Você não tem mais dinheiro sucifiente!");
            else if(GetPVarInt(playerid, "CancelarAbs") == 1) SendClientMessage(playerid, 0xFFFF00FF, "| POSTO | Abastecimento cancelado");
            else if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) SendClientMessage(playerid, 0xFFFF00FF, "| POSTO | Você saiu do seu veículo");
            else if(engine == 1) SendClientMessage(playerid, 0xFFFF00FF, "| POSTO | Você ligou o motor do seu veículo e o abastecimento foi cancelado.");
            else SendClientMessage(playerid, 0xFFFF00FF, "| POSTO | Você saiu do local de abastecimento!");
            pBomba[playerid][Abastecendo] = false;
            pBomba[playerid][AbastecerSinal] = false;
            SetPVarInt(playerid, "CancelarAbs", 0);
            OcultarAbastecimento(playerid);
            return 1;
        }
    }


    if(pBomba[playerid][Abastecendo] == true)
    {
        if(pBomba[playerid][AbastecerSinal] == false)
        {
            if(IsVehicleLandVehicle(vehid))
            {
                if(IsVehicleCaminhao(vehid) || IsVehicleOnibus(vehid))
                { 
                    if(VeiculoServer[vehid][Gasolina] > 250)
                    {
                        SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você ainda tem bastante gasolina");
                        pBomba[playerid][Abastecendo] = false;
                        return 1;
                    }
                }
                else
                {
                    if(VeiculoServer[vehid][Gasolina] > 45)
                    {
                        SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você ainda tem bastante gasolina");
                        pBomba[playerid][Abastecendo] = false;
                        return 1;
                    }
                }
                MostrarAbastecimento(playerid);
                pBomba[playerid][AbastecerSinal] = true;
                pBomba[playerid][Abastecendo] = true;
                SendClientMessage(playerid, 0x32CD32FF, "| POSTO | Abastecendo seu veículo, aguarde o abastecimento");
                return 1;
            }
            else if(IsVehicleFlyingVehicle(vehid))
            {
                if(VeiculoServer[vehid][Gasolina] > 300)
                {
                    SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você ainda tem bastante gasolina");
                    pBomba[playerid][Abastecendo] = false;
                    return 1;
                }
                MostrarAbastecimento(playerid);
                pBomba[playerid][AbastecerSinal] = true;
                pBomba[playerid][Abastecendo] = true;
                SendClientMessage(playerid, 0x32CD32FF, "| POSTO | Abastecendo seu veículo, aguarde o abastecimento");
                return 1;
            }
        }


        new Cuznhoooo[128];
        Jogador[playerid][Dinheiro] -= 6;
        pBomba[playerid][Soma] += 6;
        format(Cuznhoooo, sizeof(Cuznhoooo), "Litros:_~y~%0.2fL", pBomba[playerid][Soma1]);
        PlayerTextDrawSetString(playerid, AbastecimentoPosto[playerid][3], Cuznhoooo);
        format(Cuznhoooo, sizeof(Cuznhoooo), "Valor:_~g~$%s", DinheiroSeparar(pBomba[playerid][Soma]));
        PlayerTextDrawSetString(playerid, AbastecimentoPosto[playerid][4], Cuznhoooo);
        
        if(IsVehicleLandVehicle(vehid)) //Se for veículo
        { 
            VeiculoServer[vehid][Gasolina] += 0.8;
            pBomba[playerid][Soma1] += 0.8;
        }
        else if(IsVehicleFlyingVehicle(vehid))
        {
            VeiculoServer[vehid][Gasolina] += 3.5;
            pBomba[playerid][Soma1] += 3.5;
        }


        if(VeiculoServer[vehid][Gasolina] >= SuporteGasolina(PegarGasolina(vehid)))
        {
            VeiculoServer[vehid][Gasolina] = SuporteGasolina(PegarGasolina(vehid));
            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "| POSTO | Você abasteceu {fcd703}%0.1fL{FFFFFF} por {00FF00}$%s", pBomba[playerid][Soma1], DinheiroSeparar(pBomba[playerid][Soma]));
            SendClientMessage(playerid, -1, Mensagem);
            pBomba[playerid][Abastecendo] = false;
            pBomba[playerid][AbastecerSinal] = false;
            OcultarAbastecimento(playerid);
        }

    }

    if(!IsPlayerInRangeOfPoint(playerid, 10.0, Bomba[id][BombaX], Bomba[id][BombaY], Bomba[id][BombaZ])){
        OcultarLocalPosto(playerid);
        pBomba[playerid][EstaNaBomba] = false;
    }
    return 1;
}

CMD:abastecer(playerid)
{
    for(new i=0; i < sizeof(Bomba); i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 20.0, Bomba[i][BombaX], Bomba[i][BombaY], Bomba[i][BombaZ])) continue;
        if(!strcmp(Bomba[i][TipoGasolina], "Normal"))
        {
            new Dialog[128];
            strcat(Dialog, "Abastecer Veículo\n");
            strcat(Dialog, "Abastecer Galão\n");
            strcat(Dialog, "Abastecer Jetpack");
            Dialog_Show(playerid, AbastecimentoInfo, DIALOG_STYLE_TABLIST, "{FF0000}Posto de Gasolina", Dialog, "Selecionar", "Fechar");
            break;
        }
        else if(!strcmp(Bomba[i][TipoGasolina], "Aviao"))
        {
            if(pBomba[playerid][Abastecendo] == true){
                SetPVarInt(playerid, "CancelarAbs", 1);
                return 1;
            }
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está dirigindo ou em um veículo");
            if(!IsVehicleFlyingVehicle(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode abastecer esse veículo nesse local");
            new engine, lights, alarm, doors, bonnet, boot, objective;
            GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
            if(engine == 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Desligue o motor antes de abastecer");
            pBomba[playerid][Soma] = 0;
            pBomba[playerid][Soma1] = 0;
            pBomba[playerid][Abastecendo] = true;
            break;
        }
        else if(!strcmp(Bomba[i][TipoGasolina], "Trem"))
        {
            if(pBomba[playerid][Abastecendo] == true){
                SetPVarInt(playerid, "CancelarAbs", 1);
                return 1;
            }
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está dirigindo ou em um veículo");
            if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 538 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 537) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode abastecer esse veículo nesse local");
            new engine, lights, alarm, doors, bonnet, boot, objective;
            GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
            if(engine == 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Desligue o motor antes de abastecer");
            pBomba[playerid][Soma] = 0;
            pBomba[playerid][Soma1] = 0;
            pBomba[playerid][Abastecendo] = true;
            break;
        }
    }
    return 1;
}

Dialog:GalaoAbastecer(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][GasolinaGalao] >= 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de gasolina no galão ( 10 Litros )");
    
    new Somazinha,
        PrecoX;

    if(Quantidade >= 10) Somazinha = Ponta(Jogador[playerid][GasolinaGalao], Quantidade, 10);
    else Somazinha = Quantidade;
    PrecoX = 6*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    EnviarDinheiroEmpresa(id, PrecoX); 
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    Jogador[playerid][GasolinaGalao] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| POSTO | Você comprou {00BFFF}%d{FFFFFF} litros de gasolina por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:JetpackAbastecer(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][GasJetpack] >= 60) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de gás ( 60 Litros )");
    
    new Somazinha,
        PrecoX;

    if(Quantidade >= 60) Somazinha = Ponta(Jogador[playerid][GasJetpack], Quantidade, 60);
    else Somazinha = Quantidade;
    PrecoX = 20*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    EnviarDinheiroEmpresa(id, PrecoX); 
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    Jogador[playerid][GasJetpack] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| POSTO | Você comprou {00BFFF}%d{FFFFFF} litros de gás por {32CD32}$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:AbastecimentoInfo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            if(pBomba[playerid][Abastecendo] == true){
                SetPVarInt(playerid, "CancelarAbs", 1);
                return 1;
            }
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está dirigindo ou em um veículo");
            if(!IsVehicleLandVehicle(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode abastecer esse veículo nesse local");
            new engine, lights, alarm, doors, bonnet, boot, objective;
            GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
            if(engine == 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Desligue o motor antes de abastecer");
            pBomba[playerid][Soma] = 0;
            pBomba[playerid][Soma1] = 0;
            pBomba[playerid][Abastecendo] = true;
        }
        case 1:
        {
            if(Jogador[playerid][GalaoGasolina] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem galão de gasolina!");
            Dialog_Show(playerid, GalaoAbastecer, DIALOG_STYLE_INPUT, "{FF0000}Galão", "Coloque abaixo o quanto de gasolina você quer comprar\nCada litro custa $6", "Comprar", "Fechar");
        }
        case 2: Dialog_Show(playerid, JetpackAbastecer, DIALOG_STYLE_INPUT, "{FF0000}Gás", "Coloque abaixo o quanto de gás você quer comprar\nCada litro(m³) custa $20", "Comprar", "Fechar");   
    }
    return 1;
}

function ConsertandoVeiculo(playerid)
{
    new veiculo = GetPVarInt(playerid, "CarroFixed");
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid);
    Jogador[playerid][KitReparos]--;
    pVMecanico[playerid][ConsertandoV] = false;
    if(VeiculoServer[veiculo][VeiculoOn] == false) return 1;
    VeiculoServer[veiculo][vQuebrado] = false;
    RepairVehicle(veiculo);
    SetVehicleHealth(veiculo, VeiculoServer[veiculo][VidaMaxima]);
    SendClientMessage(playerid, 0x32CD32FF, "| REPARO | Veículo consertado com sucesso!");
    return 1;
}

function AbastecendoVeiculo(playerid)
{
    new veiculo = GetPVarInt(playerid, "CarroFixedd");
    RemovePlayerAttachedObject(playerid, 5);
    pVMecanico[playerid][AbastecendoV] = false;
    ClearAnimations(playerid); 
    TogglePlayerControllable(playerid, 1);
    VeiculoServer[veiculo][Gasolina] += float(Jogador[playerid][GasolinaGalao]);
    Jogador[playerid][GasolinaGalao] = 0;
    SendClientMessage(playerid, 0x32CD32FF, "| ABASTECIMENTO | Veículo abastecido com sucesso!");
    return 1;
}


CMD:consertar(playerid)
{
    if(pVMecanico[playerid][ConsertandoV] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está reparando, aguarde");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa estar a pé para consertar");
    if(Jogador[playerid][KitReparos] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem kit de reparo");
    
    new Float:tesA[3];
    GetPlayerPos(playerid, tesA[0], tesA[1], tesA[2]);
    
    for(new i=0; i < MAX_VEHICLES; i++)
    {
        if(VeiculoServer[i][VeiculoOn] == false) continue;
        if(!IsVehicleInRangeOfPoint(i, 3.0, tesA[0], tesA[1], tesA[2])) continue;
        if(VeiculoServer[i][vQuebrado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse veículo não está quebrado");
        pVMecanico[playerid][ConsertandoV] = true;
        TogglePlayerControllable(playerid, 0);
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 1, 0);
        CriarProgresso(playerid, "Consertando Veículo", "ConsertandoVeiculo", 500); 
        SetPVarInt(playerid, "CarroFixed", i);
        SendClientMessage(playerid, 0x32CD32FF, "| REPARO | Efetuando reparo, aguarde.");
        break;
    }
    return 1;
}

CMD:reabastecer(playerid)
{
    if(pVMecanico[playerid][AbastecendoV] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está abastecendo, aguarde");
    if(Jogador[playerid][GalaoGasolina] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui um galão de gasolina");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa estar a pé para reabastecer");
    if(Jogador[playerid][GasolinaGalao] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu galão não tem gasolina, vá até um posto para abastecer!");
    
    new Float:tesA[3];
    GetPlayerPos(playerid, tesA[0], tesA[1], tesA[2]);
    
    for(new i=0; i < MAX_VEHICLES; i++)
    {
        if(VeiculoServer[i][VeiculoOn] == false) continue;
        if(!IsVehicleInRangeOfPoint(i, 3.0, tesA[0], tesA[1], tesA[2])) continue;
        if(VeiculoServer[i][Gasolina] > 1.0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse veículo não está sem gasolina");
        pVMecanico[playerid][AbastecendoV] = true;
        TogglePlayerControllable(playerid, 0);
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 1, 0);
        SetPlayerAttachedObject(playerid, 5, 19621, 6, 0.0610, 0.0179, -0.0199, 6.7999, -45.3000, 87.8999, 1.3980, 1.2080, 1.3889, 0xFFFFFFFF, 0xFFFFFFFF); 
        SetPVarInt(playerid, "CarroFixedd", i);
        CriarProgresso(playerid, "Reabastecendo Veículo", "AbastecendoVeiculo", 300); 
        break;
    }
    return 1;
} 