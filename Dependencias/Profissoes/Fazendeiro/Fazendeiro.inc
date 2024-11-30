#include <YSI_Coding\y_hooks>

#define     MAX_PLANTIO_FAZENDA     (10)

enum JogadorFazendeiro{
    bool:FazSegurando,
    FazStatus,
    FazVehID,
    FazContagem,
    Text3D:FazTexto
};

enum PlantioJogador{
    plantioTimer,
    plantioStatus,
    plantioRelogio,

    Text3D:plantioTexto,
    plantioObjeto,
    plantioObjetoVeh,
    bool:plantioFeno,
    bool:plantioEntrega,

    Float:plantioX,
    Float:plantioY,
    Float:plantioZ
};

new pFazendeiro[MAX_PLAYERS][JogadorFazendeiro];
new pPlantio[MAX_PLAYERS][MAX_PLANTIO_FAZENDA][PlantioJogador];

new FazendaZero;
new Float:zones_points_0[] = {
	-231.0,102.0,-243.0,81.0,-257.0,43.0,-268.0,4.0,-276.0,-31.0,-273.0,-63.0,-256.0,-75.0,-218.0,-86.0,-182.0,-85.0,-168.0,-60.0,
	-124.0,59.0,-231.0,102.0
};

hook OnGameModeInit(){
    FazendaZero = CreateDynamicPolygon(zones_points_0, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(zones_points_0), 0, 0, -1);
    CreateDynamicPickup(1239, 1, -112.9224,-15.4921,3.1172, 0, 0, -1, 70.0, -1);
    CreateDynamic3DTextLabel("Fazendeiro\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", 0xdaa520FF, -112.9224,-15.4921,3.1172, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    
    CreateDynamicPickup(1239, 1, 577.3505,1223.5079,11.7113, 0, 0, -1, 70.0, -1);
    CreateDynamic3DTextLabel("Fazendeiro\n{FFFFFF}Aperte 'Y' para entregar", 0xdaa520FF, 577.3505,1223.5079,11.7113, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid){
    if(areaid == FazendaZero) MostrarMensagemBaixo(playerid, ConverterTexto("~r~Fazenda~w~ - Área de Plantio"));
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid){
    if(areaid == FazendaZero) OcultarMensagemBaixo(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason){
    new asdsada[PlantioJogador];
    for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
        if(pPlantio[playerid][i][plantioStatus] == 1) KillTimer(pPlantio[playerid][i][plantioTimer]);
        DestroyDynamic3DTextLabelEx(pPlantio[playerid][i][plantioTexto]);
        DestroyDynamicObjectEx(pPlantio[playerid][i][plantioObjeto]);
        DestroyDynamicObjectEx(pPlantio[playerid][i][plantioObjetoVeh]);
        pPlantio[playerid][i] = asdsada;
    }
    DestroyVehicleEx(pFazendeiro[playerid][FazVehID]);
    DestroyDynamic3DTextLabelEx(pFazendeiro[playerid][FazTexto]);
    new asdaaa[JogadorFazendeiro];
    pFazendeiro[playerid] = asdaaa;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        // Alugar
        if(IsPlayerInRangeOfPoint(playerid, 2.0, -112.9224,-15.4921,3.1172))
        {
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Fazendeiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pFazendeiro[playerid][FazStatus] > 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");
            if(ProgressoFazenda(playerid) > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");

            if(GetPVarInt(playerid, "DKLASKDLSADAS") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            SetPVarInt(playerid, "DKLASKDLSADAS", gettime()+3);

            if(pFazendeiro[playerid][FazStatus] < 1)
            {
                enum FoxSay{
                    Float:fsX,
                    Float:fsY,
                    Float:fsZ,
                    Float:fsA
                };
                new FoxVeh[][FoxSay] =
                {
                    {-108.1785,-8.6740,3.1045,69.5901},
                    {-106.5159,-4.2428,3.1125,70.0615},
                    {-105.0012,0.5496,3.1118,69.1825},
                    {-102.9361,5.2063,3.1045,68.2021},
                    {-101.4487,9.8907,3.1119,68.4070},
                    {-99.6479,14.6311,3.1110,70.6306}
                };
                new i = random(sizeof(FoxVeh));
                pFazendeiro[playerid][FazVehID] = CreateVehicleEx(playerid, 478, FoxVeh[i][fsX], FoxVeh[i][fsY], FoxVeh[i][fsZ], FoxVeh[i][fsA], 1, 1, 360, 0);
                VeiculoServer[pFazendeiro[playerid][FazVehID]][Tranca] = 1;
                MarcarPosicao(playerid, FoxVeh[i][fsX], FoxVeh[i][fsY], FoxVeh[i][fsZ]);
                pFazendeiro[playerid][FazStatus] = 1;
                Jogador[playerid][Trabalhando] = true;
                SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Seu veículo foi marcado no mapa");
                return 1;
            }
            DestroyVehicleEx(pFazendeiro[playerid][FazVehID]);
            VeiculoServer[pFazendeiro[playerid][FazVehID]][Tranca] = 0;
            Jogador[playerid][Trabalhando] = false;
            VerificarMarcacao(playerid);
            SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você devolveu seu veículo");
        }

        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 577.3505,1223.5079,11.7113))
        {
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Fazendeiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(FenoCrescimento(playerid) > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem sementes na Fazenda");
            //if(pFazendeiro[playerid][FazSegurando] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está segurando um feno");
            if(FenoVeiculo(playerid) < 1) return 1;

            for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
                if(pPlantio[playerid][i][plantioFeno] == false) continue;   
                pPlantio[playerid][i][plantioFeno] = false;
                pPlantio[playerid][i][plantioEntrega] = false;
                DestroyDynamicObjectEx(pPlantio[playerid][i][plantioObjetoVeh]);
            }

            new Mensagem[128],
                sadsa = (350*pFazendeiro[playerid][FazContagem]);
            Jogador[playerid][Dinheiro] += sadsa;
            format(Mensagem, sizeof(Mensagem), "| FAZENDEIRO | Você entregou {daa520}%d{FFFFFF} e recebeu {32CD32}$%s{FFFFFF} pelas entregas", pFazendeiro[playerid][FazContagem], DinheiroSeparar(sadsa));
            SendClientMessage(playerid, -1, Mensagem);
            pFazendeiro[playerid][FazContagem] = 0;
        }
    }

    // Colher
    else if(newkeys == KEY_CTRL_BACK)
    {
        if(!IsPlayerInDynamicArea(playerid, FazendaZero)) return 1;
        for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
            if(pPlantio[playerid][i][plantioStatus] < 1) continue;
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, pPlantio[playerid][i][plantioX], pPlantio[playerid][i][plantioY], pPlantio[playerid][i][plantioZ])) continue;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(pFazendeiro[playerid][FazSegurando] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está segurando, coloque em seu veículo");
            if(pPlantio[playerid][i][plantioStatus] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa esperar um pouco");

            pFazendeiro[playerid][FazSegurando] = true;
            pFazendeiro[playerid][FazTexto] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'N'{FFFFFF} para colocar", -1, 0.0000, -4.0999, -0.9000, 15.0, INVALID_PLAYER_ID, pFazendeiro[playerid][FazVehID], 0, 0, 0, playerid, 16.0, -1);

            pPlantio[playerid][i][plantioStatus] = 0;
            DestroyDynamic3DTextLabelEx(pPlantio[playerid][i][plantioTexto]);
            DestroyDynamicObjectEx(pPlantio[playerid][i][plantioObjeto]);

            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
            SetPlayerAttachedObject(playerid, 8, 2060, 1, 0.1590, 0.4410, 0.0100, 0.0000, 96.9000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
            break;            
        }    
    }

    else if(newkeys == KEY_NO)
    {
        if(!AtrasVeiculo(playerid, pFazendeiro[playerid][FazVehID], 2.2)) return 1;
        if(pFazendeiro[playerid][FazSegurando] == true) 
        {
            if(GetPVarInt(playerid, "BlockFeno") == 1) return 1;
            pFazendeiro[playerid][FazSegurando] = false;
            DestroyDynamic3DTextLabelEx(pFazendeiro[playerid][FazTexto]);
            RemovePlayerAttachedObject(playerid, 8);
            AdicionarFeno(playerid);
        }
    }
    return 1;
}

stock ProgressoFazenda(playerid){
    new qweq;
    for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
        if(pPlantio[playerid][i][plantioStatus] < 1) continue;
        qweq++;
    }
    return qweq;
}

stock FenoVeiculo(playerid){
    new qweq;
    for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
        if(pPlantio[playerid][i][plantioFeno] == false) continue;
        qweq++;
    }
    return qweq;
}

stock FenoCrescimento(playerid){
    new qweq;
    for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
        if(pPlantio[playerid][i][plantioStatus] != 1) continue;
        qweq++;
    }
    return qweq;
}

stock AdicionarFeno(playerid){
    new Float:Rasand[3],
        id;
    for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
        if(pPlantio[playerid][i][plantioFeno] == true) continue;
        switch(i)
        {
            case 0: {Rasand[0] = 0.3799; Rasand[1] = -1.5199; Rasand[2] = 0.0899;}
            case 1: {Rasand[0] = -0.4599; Rasand[1] = -1.5199; Rasand[2] = 0.0899;}
            case 2: {Rasand[0] = -0.4599; Rasand[1] = -1.9799; Rasand[2] = 0.0899;}
            case 3: {Rasand[0] = 0.3799; Rasand[1] = -1.9799; Rasand[2] = 0.0899;}
            case 4: {Rasand[0] = 0.3799; Rasand[1] = -2.3099; Rasand[2] = 0.0899;}
            case 5: {Rasand[0] = -0.4300; Rasand[1] = -2.3099; Rasand[2] = 0.0899;}
            case 6: {Rasand[0] = -0.4300; Rasand[1] = -2.1599; Rasand[2] = 0.2499;}
            case 7: {Rasand[0] = 0.3799; Rasand[1] = -2.1599; Rasand[2] = 0.2499;}
            case 8: {Rasand[0] = 0.3799; Rasand[1] = -1.6600; Rasand[2] = 0.2499;}
            case 9: {Rasand[0] = -0.4499; Rasand[1] = -1.6600; Rasand[2] = 0.2499;}
        }
        id = i;
        break;
    }

    ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
    pPlantio[playerid][id][plantioFeno] = true;
    pPlantio[playerid][id][plantioObjetoVeh] = CreateDynamicObject(2060, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, -1, 50.0, 50.0, -1);
    AttachDynamicObjectToVehicle(pPlantio[playerid][id][plantioObjetoVeh], pFazendeiro[playerid][FazVehID], Rasand[0], Rasand[1], Rasand[2], 0.0, 0.0, 0.0);
    return 1;
}

stock Feno(playerid){
    for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
        if(pPlantio[playerid][i][plantioEntrega] == true) continue;
        return i;
    }
    return -1;
}

stock FenoPlantado(playerid){ 
    new dasda;
    for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
        if(pPlantio[playerid][i][plantioEntrega] == false) continue;
        dasda++;
    }
    return dasda;
}

function PlantioTempoFazenda(playerid, id)
{
    new Mensagem[75];
    pPlantio[playerid][id][plantioRelogio]++;
    format(Mensagem, sizeof(Mensagem), "Semente (ID: %d - %s)\n{FFFFFF}Crescimento: {daa520}%d%s", id, PegarNick(playerid), pPlantio[playerid][id][plantioRelogio], "%");
    UpdateDynamic3DTextLabelText(pPlantio[playerid][id][plantioTexto], 0xdaa520FF, Mensagem);
    if(pPlantio[playerid][id][plantioRelogio] < 100) return 1;
    format(Mensagem, sizeof(Mensagem), "Semente (ID: %d - %s)\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para recolher", id, PegarNick(playerid));
    UpdateDynamic3DTextLabelText(pPlantio[playerid][id][plantioTexto], 0xdaa520FF, Mensagem);
    KillTimer(pPlantio[playerid][id][plantioTimer]);
    pPlantio[playerid][id][plantioStatus] = 2; 
    return 1;
}

function LimparPlantAnimFaz(playerid)
{
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid);
    return 1;
}

CMD:plantarsemente(playerid){
    if(strcmp(Jogador[playerid][Profissao], "Fazendeiro")) return 0;
    if(pFazendeiro[playerid][FazStatus] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem um veículo alugado");
    if(!IsPlayerInDynamicArea(playerid, FazendaZero)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na Fazenda");
    if(Feno(playerid) == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já plantou o máximo de sementes");
    if(GetPlayerSpeed(playerid) > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa estar parado(a)");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode plantar");
    if(Jogador[playerid][SementeFazenda] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui sementes, vá até uma utilitários");

    new id = Feno(playerid),
        Float:PosPlant[3];
    GetPlayerPos(playerid, PosPlant[0], PosPlant[1], PosPlant[2]);

    for(new i=0; i < MAX_PLANTIO_FAZENDA; i++){
        if(pPlantio[playerid][i][plantioStatus] < 1) continue;
        if(IsPlayerInRangeOfPoint(playerid, 3.0, pPlantio[playerid][i][plantioX], pPlantio[playerid][i][plantioY], pPlantio[playerid][i][plantioZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode plantar perto de uma semente");  
    }

    TogglePlayerControllable(playerid, 0);
    ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
    SetTimerEx("LimparPlantAnimFaz", 3000, false, "d", playerid);

    new Mensagem[75];
    pPlantio[playerid][id][plantioX] = PosPlant[0];
    pPlantio[playerid][id][plantioY] = PosPlant[1];
    pPlantio[playerid][id][plantioZ] = PosPlant[2];
    pPlantio[playerid][id][plantioStatus] = 1;
    pPlantio[playerid][id][plantioRelogio] = 0;
    pPlantio[playerid][id][plantioEntrega] = true;
    pFazendeiro[playerid][FazContagem]++;
    Jogador[playerid][SementeFazenda]--;

    format(Mensagem, sizeof(Mensagem), "Semente (ID: %d - %s)\n{FFFFFF}Crescimento: {daa520}%d%s", id, PegarNick(playerid), pPlantio[playerid][id][plantioRelogio], "%");
    pPlantio[playerid][id][plantioTexto] = CreateDynamic3DTextLabel(Mensagem, 0xdaa520FF, PosPlant[0], PosPlant[1], PosPlant[2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 16.0, -1);
    pPlantio[playerid][id][plantioObjeto] = CreateDynamicObject(19473, PosPlant[0], PosPlant[1], PosPlant[2]-1.5, 0.0, 0.0, float(random(360)), 0, 0, -1, 110.0, 110.0, -1);
    pPlantio[playerid][id][plantioTimer] = SetTimerEx("PlantioTempoFazenda", 1000, true, "dd", playerid, id);
    return 1;
}

CMD:feno(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Fazendeiro")) return 0;
    EnviarGps(playerid, 577.3505,1223.5079,11.7113);
    return 1;
}