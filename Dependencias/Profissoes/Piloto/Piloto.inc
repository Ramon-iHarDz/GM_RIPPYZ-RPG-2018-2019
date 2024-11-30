#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{00BFFF}Piloto\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, 1936.1687,-2639.7766,13.5469, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0,  0, -1);
    CreateDynamicPickup(1239, 1, 1936.1687,-2639.7766,13.5469, 0, 0, -1, 50.0);
    AeroBS = CreateDynamicRectangle(1577, -2660.5, 1933, -2614.5, 0, 0, -1);
    AeroLS = CreateDynamicRectangle(1380, -2614.5, 2134, -2396.5, 0, 0, -1);
    for(new i=0; i < sizeof(AviaoDodo); i++){
        DodoID[i] = CreateVehicleEx(-1, 593, AviaoDodo[i][PPosX], AviaoDodo[i][PPosY], AviaoDodo[i][PPosZ], AviaoDodo[i][PPosA], 1, 1, 360, 0);
        format(VeiculoServer[DodoID[i]][LocalVerificacao], 90, "PilotoDodoVeh");
    }
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid){
    if(areaid == AeroBS) MostrarMensagemBaixo(playerid, ConverterTexto("Mercadorias - ~g~Los Santos"));
    else if(areaid == AeroLS) MostrarMensagemBaixo(playerid, ConverterTexto("Aeroporto Internacional de ~r~Los Santos"));
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid){   
    if(areaid == AeroBS || areaid == AeroLS) OcultarMensagemBaixo(playerid);
    return 1;
}

function PilotoDodoVeh(playerid){
    if(Jogador[playerid][Admin] > 1) return true;
    if(strcmp(Jogador[playerid][Profissao], "Piloto")){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é piloto");
        return false;
    }
    if(pPiloto[playerid][AviaoTipo] != 2){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está fazendo o serviço de cargas");
        return false;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1936.1687,-2639.7766,13.5469))
        {
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Piloto")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(GetPVarInt(playerid, "KDSAK") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            if(pPiloto[playerid][AviaoViagens] != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem entregas para efetuar");
            if(GetPVarInt(playerid, "IniciouTempoAviao") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde.");

            if(pPiloto[playerid][AviaoPiloto] == false){
                new Dialog[90];
                strcat(Dialog, "Tipo\tModelo\n");
                strcat(Dialog, "Voo Comercial\t{FFA500}AT-400\n");
                strcat(Dialog, "Voo Cargas\t{FFA500}Dodo");
                Dialog_Show(playerid, SelecionarTipoPiloto, DIALOG_STYLE_TABLIST_HEADERS, "{1E90FF}Piloto", Dialog, "Selecionar", "Cancelar");
                return 1;
            }

            pPiloto[playerid][AviaoPiloto] = false;
            Jogador[playerid][Trabalhando] = false;
            VerificarMarcacao(playerid);
            if(pPiloto[playerid][AviaoTipo] == 1){
                ConfigEscada(playerid);
                DestroyVehicleEx(pPiloto[playerid][AviaoID]);
                SendClientMessage(playerid, 0xFFFF00FF, "| PILOTO | Você devolveu seu AT-400");
            }
            else SendClientMessage(playerid, 0xFFFF00FF, "| PILOTO | Você deixou saiu de serviço");
        }
    }
    return 1;
}

Dialog:SelecionarTipoPiloto(playerid, response, listitem, inputtext[]){
    if(!response) return 1;

    SetPVarInt(playerid, "KDSAK", gettime()+15);
    Jogador[playerid][Trabalhando] = true;
    pPiloto[playerid][AviaoTipo] = listitem+1;

    switch(listitem)
    {
        case 0:
        {
            new rda = random(sizeof(AviaoPos));
            pPiloto[playerid][AviaoID] = CreateVehicleEx(playerid, 577, AviaoPos[rda][PPosX], AviaoPos[rda][PPosY], AviaoPos[rda][PPosZ], AviaoPos[rda][PPosA], 1, 1, 360, 0);
            VeiculoServer[pPiloto[playerid][AviaoID]][Tranca] = 1;
            
            ConfigEscada(playerid);
            pPiloto[playerid][AviaoPiloto] = true;

            SendClientMessage(playerid, 0xFFFF00FF, "| PILOTO | Você alugou um avião modelo AT-400");
            MarcarPosicao(playerid, AviaoPos[rda][PPosX], AviaoPos[rda][PPosY], AviaoPos[rda][PPosZ]);   
        }
        case 1: SendClientMessage(playerid, 0xFFFF00FF, "| PILOTO | Você agora está trabalhando com cargas, pegue o dodo.");
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "IniciouTempoAviao") == 1) KillTimer(pPiloto[playerid][AviaoTempo]);
    if(pPiloto[playerid][AviaoPiloto] == true) DestroyVehicleEx(pPiloto[playerid][AviaoID]);
    DestroyDynamicMapIconEx(pPiloto[playerid][AviaoMapa]);
    DestroyDynamicRaceCPEx(pPiloto[playerid][AviaoCheck]);
    DestroyDynamicObjectEx(pPiloto[playerid][AviaoEscadaID]);

    new Deletar[JogadorPiloto];
    pPiloto[playerid] = Deletar;
    return 1;
}

hook OnPlayerEnterDynRaceCP(playerid, checkpointid)
{
    if(checkpointid != pPiloto[playerid][AviaoCheck]) return 1;
    if(GetPVarInt(playerid, "IniciouTempoAviao") == 1) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está pilotando nenhum avião");
    if(GetPlayerVehicleID(playerid) != pPiloto[playerid][AviaoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu avião alugado");
    if(GetPlayerSpeed(playerid) > 30) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode descarregar em movimento");
    SetPVarInt(playerid, "IniciouTempoAviao", 1);
    TogglePlayerControllable(playerid, 0);
    GameTextForPlayer(playerid, "~y~Descarregando.", 6000, 4);
    pPiloto[playerid][AviaoTempo] = SetTimerEx("AviaoCheckpoint", 6000, false, "d", playerid);
    return 1;
}

function AviaoCheckpoint(playerid)
{
    SetPVarInt(playerid, "IniciouTempoAviao", 0);
    TogglePlayerControllable(playerid, 1);
    if(pPiloto[playerid][AviaoViagens] == 0){
        switch(pPiloto[playerid][AviaoTipo]){
            case 1: GameTextForPlayer(playerid, "~g~Embarcando_Passageiros.", 3000, 4);
            case 2: GameTextForPlayer(playerid, "~g~Carregado.", 3000, 4);
        }
    }
    else{
        switch(pPiloto[playerid][AviaoTipo]){
            case 1: GameTextForPlayer(playerid, "~g~Desembarcando.", 3000, 4);
            case 2: GameTextForPlayer(playerid, "~g~Descarregado.", 3000, 4);
        }
    } 
    pPiloto[playerid][AviaoViagens] += 1;
    DestroyDynamicMapIconEx(pPiloto[playerid][AviaoMapa]);
    DestroyDynamicRaceCPEx(pPiloto[playerid][AviaoCheck]);

    new Btt,
        Mensagem[128];

    switch(pPiloto[playerid][AviaoTipo]){
        case 1: Btt = 3;
        case 2: Btt = 4;
    }

    if(pPiloto[playerid][AviaoViagens] >= Btt)
    {
        new HAns;
        switch(pPiloto[playerid][AviaoTipo]){
            case 1: {
                HAns = random(4800-3800)+3800;
                format(Mensagem, sizeof(Mensagem), "| PILOTO | Você desembarcou em 2 aeroportos e recebeu {32CD32}$%s", DinheiroSeparar(HAns));
            }
            case 2: {
                HAns = random(5300-4700)+4700;
                format(Mensagem, sizeof(Mensagem), "| PILOTO | Você entregou 3 encomendas e recebeu {32CD32}$%s", DinheiroSeparar(HAns));
            }
        }
        pPiloto[playerid][AviaoViagens] = 0;
        Jogador[playerid][Dinheiro] += HAns;
        SendClientMessage(playerid, -1, Mensagem);
        return 1;
    }

    new Float:LocalAero[3], AeroNomeCR[60], Float:RRG;
    switch(pPiloto[playerid][AviaoTipo]){
        case 1:{
            switch(GerarAeroporto(playerid)){
                case 1: RRG = 5.0, LocalAero[0] = -1248.5760, LocalAero[1] = -144.6538, LocalAero[2] = 14.1484, AeroNomeCR = "San Fierro";
                case 2: RRG = 5.0, LocalAero[0] = 1335.1035, LocalAero[1] = 1343.6421, LocalAero[2] = 10.8203, AeroNomeCR = "Las Venturas";
            }
        }
        case 2:{
            switch(GerarAeroporto(playerid)){
                //case 0: LocalAero[0] = 1864.5227, LocalAero[1] = -2625.6177, LocalAero[2] = 13.5469, AeroNomeCR = "Los Santos";
                case 0: RRG = 3.0, LocalAero[0] = 290.1436, LocalAero[1] = 2513.5657, LocalAero[2] = 16.5896, AeroNomeCR = "Abandonado";
                case 1: RRG = 3.0, LocalAero[0] = -1459.2679, LocalAero[1] = -625.1242, LocalAero[2] = 14.1484, AeroNomeCR = "San Fierro";
                case 2: RRG = 3.0, LocalAero[0] = 1298.6774, LocalAero[1] = 1322.8088, LocalAero[2] = 10.8203, AeroNomeCR = "Las Venturas";
            }
        }
    }
    pPiloto[playerid][AviaoMapa] = CreateDynamicMapIcon(LocalAero[0], LocalAero[1], LocalAero[2], 19, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
    pPiloto[playerid][AviaoCheck] = CreateDynamicRaceCP(1, LocalAero[0], LocalAero[1], LocalAero[2], 0.0, 0.0, 0.0, RRG, 0, 0, playerid, 120.0, -1);
    
    new Slacrlkk = pPiloto[playerid][AviaoViagens];
    Slacrlkk -= 1;
    
    switch(pPiloto[playerid][AviaoTipo]){
        case 1: format(Mensagem, sizeof(Mensagem), "| PILOTO | Você precisa ir no aeroporto {00BFFF}%s{FFFFFF} para desembarcar passageiros ( %d/2 )", AeroNomeCR, Slacrlkk);
        case 2: format(Mensagem, sizeof(Mensagem), "| PILOTO | Você precisa ir no aeroporto {00BFFF}%s{FFFFFF} para descarregar ( %d/3 )", AeroNomeCR, Slacrlkk);
    }
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

stock GerarAeroporto(playerid)
{
    new rda;
    for(new i=0; i < 99999; i++)
    {
        rda = random(3); // Antigo é 4
        if(pPiloto[playerid][AviaoTipo] == 1){
            if(rda == 0) continue;
        }
        switch(rda)
        {
            /*case 0:
            {
                if(GetPVarInt(playerid, "PilotoLS") == 1) continue;
                SetPVarInt(playerid, "PilotoLS", 1);
            }*/
            case 0:
            {
                if(GetPVarInt(playerid, "PilotoAB") == 1) continue;
                SetPVarInt(playerid, "PilotoAB", 1); 
            }
            case 1:
            {
                if(GetPVarInt(playerid, "PilotoSF") == 1) continue;
                SetPVarInt(playerid, "PilotoSF", 1); 
            }
            case 2:
            {
                if(GetPVarInt(playerid, "PilotoLV") == 1) continue;
                SetPVarInt(playerid, "PilotoLV", 1); 
            }
        }
        return rda; 
    }
    return 0;
}

CMD:aeros(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Piloto")) return 0;
    //if(!IsPlayerInDynamicArea(playerid, AeroBS)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no Aeroporto de Bayside");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está pilotando nenhum avião");
    if(pPiloto[playerid][AviaoViagens] != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem mercadorias para entregar");
    if(pPiloto[playerid][AviaoPiloto] == false)
    {
        if(!IsPlayerInDynamicArea(playerid, AeroBS)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na Área de Mercadoria do Aeroporto de Los Santos");
        new bool:dasda;
        for(new i=0; i < sizeof(AviaoDodo); i++){
            if(GetPlayerVehicleID(playerid) != DodoID[i]) continue;
            dasda = true;
            break;
        }
        if(dasda == false){
            if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 593) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem uma avião alugado");
        }
        pPiloto[playerid][AviaoID] = GetPlayerVehicleID(playerid);
    }
    else
    {
        if(pPiloto[playerid][AviaoTipo] == 1){
            if(!IsPlayerInDynamicArea(playerid, AeroLS)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no Aeroporto de Los Santos");
        }
    }

    //if(GetPlayerVehicleID(playerid) != pPiloto[playerid][AviaoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu avião alugado");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode carregar em movimento");
    if(GetPVarInt(playerid, "IniciouTempoAviao") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está carregando, aguarde!");
    SetPVarInt(playerid, "IniciouTempoAviao", 1);
    TogglePlayerControllable(playerid, 0);
    GameTextForPlayer(playerid, "~y~Aguarde.", 6000, 4);
    //SetPVarInt(playerid, "PilotoLS", 0); 
    SetPVarInt(playerid, "PilotoAB", 0); 
    SetPVarInt(playerid, "PilotoSF", 0); 
    SetPVarInt(playerid, "PilotoLV", 0); 
    pPiloto[playerid][AviaoTempo] = SetTimerEx("AviaoCheckpoint", 6000, false, "d", playerid);
    return 1;
}

CMD:escadaaviao(playerid){
    if(strcmp(Jogador[playerid][Profissao], "Piloto")) return 0;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está a pé");
    if(pPiloto[playerid][AviaoPiloto] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está com um avião alugado");
    if(pPiloto[playerid][AviaoTipo] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está trabalhando na linha comercial");
    ConfigEscada(playerid);
    return 1;
}

stock ConfigEscada(playerid){
    if(pPiloto[playerid][AviaoEscada] == false){
        pPiloto[playerid][AviaoEscadaID] = CreateDynamicObject(8615, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, -1, 100.0, 100.0, -1);
        AttachDynamicObjectToVehicle(pPiloto[playerid][AviaoEscadaID], pPiloto[playerid][AviaoID], -3.4500, 21.8100, 0.7699, 1.0000, 0.5000, 267.1999);
        pPiloto[playerid][AviaoEscada]  = true;
        return 1;
    }
    DestroyDynamicObjectEx(pPiloto[playerid][AviaoEscadaID]);
    pPiloto[playerid][AviaoEscada] = false;
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate){
    if(newstate == PLAYER_STATE_PASSENGER || newstate == PLAYER_STATE_DRIVER){
        if(pPiloto[playerid][AviaoEscada] == false) return 1;
        ConfigEscada(playerid);
    }
    return 1;
}