#include <YSI_Coding\y_hooks>

CMD:acheck(playerid)
{
    if(GetPVarInt(playerid, "CriacaoCorrida") != 4) return 0;
    if(cChecks >= 150) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você pode adicionar mais");
    GetPlayerPos(playerid, aCheck[playerid][cChecks][0], aCheck[playerid][cChecks][1], aCheck[playerid][cChecks][2]);
    cChecks += 1;

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você adicionou +1 checkpoint ( {FF4500}%d{FFFFFF} )", cChecks);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

CMD:fcheck(playerid)
{
    if(GetPVarInt(playerid, "CriacaoCorrida") != 4) return 0;
    if(cChecks < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa colocar no mínimo 3 checkpoints");
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você finalizou o trajeto com %d checkpoints", cChecks);
    GetPlayerPos(playerid, aCheck[playerid][cChecks][0], aCheck[playerid][cChecks][1], aCheck[playerid][cChecks][2]);
    cChecks += 1;
    SetPVarInt(playerid, "CriacaoCorrida", 5);
    ConfigurarCorrida(playerid);
    return 1;
}

CMD:cloc(playerid)
{
    if(GetPVarInt(playerid, "CriacaoCorrida") != 2) return 0;
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo um veículo");
    if(GetVehicleModel(GetPlayerVehicleID(playerid)) != CorridaModelo){
        new Fdsa[100];
        format(Fdsa, sizeof(Fdsa), "| ERRO | Você não está no veículo modelo ( {FF4500}%d{FFFFFF} )", CorridaModelo);
        SendClientMessage(playerid, 0xFF4500FF, Fdsa);
        return 1;
    }
    GetVehiclePos(GetPlayerVehicleID(playerid), AoVeiculos[playerid][CoVeiculos][0], AoVeiculos[playerid][CoVeiculos][1], AoVeiculos[playerid][CoVeiculos][2]);
    GetVehicleZAngle(GetPlayerVehicleID(playerid), AoVeiculos[playerid][CoVeiculos][3]);
    CoVeiculos += 1;
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você adicionou +1 slot e +1 veículo ( {FF4500}%d{FFFFFF} )", CoVeiculos);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

CMD:floc(playerid)
{
    if(GetPVarInt(playerid, "CriacaoCorrida") != 2) return 0;
    if(CoVeiculos < 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa colocar no mínimo 2 veículos");
    new Mensagem[80];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você configurou os veículos ( {FF4500}%d{FFFFFF} Slots )", CoVeiculos);
    SendClientMessage(playerid, -1, Mensagem);
    SetPVarInt(playerid, "CriacaoCorrida", 3);
    ConfigurarCorrida(playerid);
    return 1;
}

Dialog:ModeloCorridaSec(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque um ID válido");
    if(id < 400 || id > 611) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Modelo Inválido");
    if(CorridaModelo == 0) SetPVarInt(playerid, "CriacaoCorrida", 1);
    VeiculoPers = false;
    CorridaModelo = id;
    new Mensagem[90];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você selecionou o veículo {FF4500}%d", id);
    SendClientMessage(playerid, -1, Mensagem);
    ConfigurarCorrida(playerid);
    return 1;
}

Dialog:ModeloModificado(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(CorridaModelo == 0) SetPVarInt(playerid, "CriacaoCorrida", 1);
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você criou uma corrida {FF4500}%s", SetarCorridaPers(listitem));
    SendClientMessage(playerid, -1, Mensagem);
    ConfigurarCorrida(playerid);
    return 1;
}


Dialog:SelecionarCarroCorrida(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, ModeloCorridaSec, DIALOG_STYLE_INPUT, "{FF0000}Modelo", "Coloque o modelo do veículo abaixo", "Confirmar", "Fechar");
        case 1:
        {
            new Dialog[25];
            strcat(Dialog, "Motoqueiro Fantasma");
            Dialog_Show(playerid, ModeloModificado, DIALOG_STYLE_TABLIST, "{FF0000}Modos", Dialog, "Selecionar", "Fechar");
        }
    }
    return 1;
}

Dialog:MenuCorrida(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            if(GetPVarInt(playerid, "CriacaoCorrida") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não selecionou um modelo de veículo");
            else if(GetPVarInt(playerid, "CriacaoCorrida") == 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está configurando os veículos");
            else if(GetPVarInt(playerid, "CriacaoCorrida") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não configurou os veículos");
            else if(GetPVarInt(playerid, "CriacaoCorrida") == 4) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está configurando o trajeto");
            else if(GetPVarInt(playerid, "CriacaoCorrida") == 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já configurou o trajeto!");
            SetPVarInt(playerid, "CriacaoCorrida", 4);
            MostrarCorridaAdmin(playerid);
        }
        case 1:
        {
            if(GetPVarInt(playerid, "CriacaoCorrida") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não selecionou um modelo de veículo");
            else if(GetPVarInt(playerid, "CriacaoCorrida") == 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está configurando os veículos");
            else if(GetPVarInt(playerid, "CriacaoCorrida") != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já configurou os veículos");
            SetPVarInt(playerid, "CriacaoCorrida", 2);
            MostrarCorridaAdmin(playerid);
        }
        case 2:
        {
            new Dialog[60];
            strcat(Dialog, "Selecionar Modelo\n");
            strcat(Dialog, "Personalizada");
            Dialog_Show(playerid, SelecionarCarroCorrida, DIALOG_STYLE_TABLIST, "{FF0000}Veículo", Dialog, "Selecionar", "Fechar");
        }
        case 3:
        {
            if(VeiculoFanstasma == true) VeiculoFanstasma = false;
            else VeiculoFanstasma = true;
            ConfigurarCorrida(playerid);
        }
        case 4: MostrarCorridaAdmin(playerid);
        case 5:
        {
            if(CorridaModelo == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não configurou um modelo de veículo");
            if(GetPVarInt(playerid, "UltimaConfigg") == 1){
                EnviarAdminCorrida(playerid, true);
                SetPVarInt(playerid, "UltimaConfigg", 0);
            }else EnviarAdminCorrida(playerid);
        }
        case 6:
        {
            CancelarCriacao(playerid);
            ResetarCorrida();
        }
    }
    return 1;
}

Dialog:ConfigCorrida(playerid, response, listitem, inputtext[])
{
    AdminCriando = playerid;
    if(!response)
    {
        VeiculoPers = false;
        SlotVeiculoPers = 0;
        CorridaConfig = false;
        VeiculoFanstasma = false;
        CorridaSlot = 0;
        CorridaCheck = 0;
        CorridaModelo = 0;
        CoVeiculos = 0;
        cChecks = 0;
        ConfigurarCorrida(playerid); 
        return 1;
    }
    SetPVarInt(playerid, "CriacaoCorrida", 5);
    SetPVarInt(playerid, "UltimaConfigg", 1);
    ConfigurarCorrida(playerid);
    return 1;
}


stock MostrarCorridaAdmin(playerid)
{
    new Dialog[190];
    strcat(Dialog, "/Acheck - Para adicionar checkpoints\n");
    strcat(Dialog, "/Fcheck - Para colocar o checkpoint final\n\n");
    strcat(Dialog, "/Cloc - Para adicionar spawn do veículo\n");
    strcat(Dialog, "/FLoc - Para finalizar a config do veículo");
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_MSGBOX, "{FF0000}Corrida Comandos", Dialog, "Fechar", "");
    return 1;
}

stock ConfigurarCorridaEvent(playerid) 
{
    AdminCriando = playerid;
    SetPVarInt(playerid, "ConfigurandoCorridaGG", 1);
    SetPlayerVirtualWorld(playerid, 4871);
    if(CorridaConfig == true) return Dialog_Show(playerid, ConfigCorrida, DIALOG_STYLE_MSGBOX, "{FF0000}Configuração", "Deseja usar a última configuração dessa corrida?", "Sim", "Não");
    ConfigurarCorrida(playerid);   
    return 1;
}

stock ConfigurarCorrida(playerid)
{
    new Dialog[550];
    if(cChecks > 0) strcatEx(Dialog, "{FFFFFF}Checkpoins: {32CD32}Configurado: [ %d Checks ]{FFFFFF}\n", cChecks);
    else strcat(Dialog, "{FFFFFF}Checkpoins: {FF0000}Não Configurado{FFFFFF}\n");

    if(CoVeiculos > 0) strcatEx(Dialog, "Spawn Veículos: {32CD32}Configurado: [ %d Slots ]{FFFFFF}\n", CoVeiculos);
    else strcat(Dialog, "{FFFFFF}Spawn Veículos: {FF0000}Não Configurado{FFFFFF}\n");
    
    if(CorridaModelo != 0) strcatEx(Dialog, "Veículo Modelo: {32CD32}%s [ ID: %d ]{FFFFFF}\n", GetVehicleNameByModel(CorridaModelo), CorridaModelo);
    else strcat(Dialog, "Veículo Modelo: {FF0000}N/A{FFFFFF}\n");

    strcatEx(Dialog, "Veículo Fantasma: %s\n", VeiculoFanstasma ? ("{32CD32}Ativado") : ("{FF4500}Desativado"));

    strcat(Dialog, "{FFFFFF}Comandos\n");
    strcat(Dialog, "{00FF00}Confirmar\n");
    strcat(Dialog, "{FF0000}Cancelar");
    Dialog_Show(playerid, MenuCorrida, DIALOG_STYLE_TABLIST, "{FF0000}Menu Corrida", Dialog, "Selecionar", "Fechar");
    return 1;
}

stock CancelarCriacao(playerid)
{
    if(AdminCriando != playerid) return 1;
    if(GetPVarInt(playerid, "ConfigurandoCorridaGG") == 0) return 1;
    if(cChecks> 0){
        for(new i=0; i < cChecks; i++){
            aCheck[playerid][i][0] = 0.0;
            aCheck[playerid][i][1] = 0.0;
            aCheck[playerid][i][2] = 0.0;
        }
    } 

    if(CoVeiculos > 0){
        for(new i=0; i < CoVeiculos; i++){
            AoVeiculos[playerid][i][0] = 0.0;
            AoVeiculos[playerid][i][1] = 0.0;
            AoVeiculos[playerid][i][2] = 0.0;
            AoVeiculos[playerid][i][3] = 0.0;
        }
    }

    if(EventoEstado == 0){
        VeiculoPers = false;
        SlotVeiculoPers = 0;
        CorridaSlot = 0;
        CorridaCheck = 0;
        VeiculoFanstasma = false;
        CorridaModelo = 0;
        CoVeiculos = 0;
        cChecks = 0;
    }

    AdminCriando = -1;
    SetPlayerVirtualWorld(playerid, 0);
    SetPVarInt(playerid, "ConfigurandoCorridaGG", 0);
    SetPVarInt(playerid, "CriacaoCorrida", 0);
    SetPVarInt(playerid, "UltimaConfigg", 0);
    return 1;
}

stock ResetarCorrida()
{
    AdminCriando = -1;
    EventoEstado = 0;
    EventoID = 0;
    PosicaoGanhou = 0;
    RetirarCorrida(-1);
    return 1;
}

stock EnviarAdminCorrida(playerid, bool:caindaaaa = false)
{
    if(caindaaaa == false)
    {
        if(GetPVarInt(playerid, "CriacaoCorrida") != 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Configure a corrida antes de iniciar!");
        CorridaConfig = true;
        CorridaSlot = CoVeiculos;
        CorridaCheck = cChecks;

        for(new i=0; i < CorridaSlot; i++){
            VeiculoCorrida[i][CorridaUsad] = true;
            VeiculoCorrida[i][CorridaVX] = AoVeiculos[playerid][i][0];
            VeiculoCorrida[i][CorridaVY] = AoVeiculos[playerid][i][1];
            VeiculoCorrida[i][CorridaVZ] = AoVeiculos[playerid][i][2];
            VeiculoCorrida[i][CorridaVA] = AoVeiculos[playerid][i][3];
        }

        for(new i=0; i < CorridaCheck; i++){
            CheckCorrida[i][CheckUsad] = true;
            CheckCorrida[i][CheckVX] = aCheck[playerid][i][0];
            CheckCorrida[i][CheckVY] = aCheck[playerid][i][1];
            CheckCorrida[i][CheckVZ] = aCheck[playerid][i][2];
        }
    }

    PosicaoGanhou = 0;
    EventoEstado = 1;
    EventoID = 3;
    CancelarCriacao(playerid);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) %s %s criou um evento de Corrida com %d vagas ( /IrEvento )", CargoAdmin(2, playerid), PegarNick(playerid), CorridaSlot);
    SendClientMessageToAll(0xFF8C00FF, Mensagem);
    return 1;
}

stock EntrarCorrida(playerid)
{
    for(new i=0; i < CorridaSlot; i++){
        if(pCorrida[i][VagaC] == false) continue;
        if(pCorrida[i][JogadorC] == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já entrou no evento");
    }
    new bool:Vg = false,
        id;
    
    for(new i=0; i < CorridaSlot; i++){
        if(pCorrida[i][VagaC] == true) continue;
        pCorrida[i][VagaC] = true;
        pCorrida[i][GanhouC] = false;
        pCorrida[i][PosicaoC] = 0;
        pCorrida[i][JogadorC] = playerid;
        pCorrida[i][VeiculoC] = CreateVehicleEx(playerid, CorridaModelo, VeiculoCorrida[i][CorridaVX], VeiculoCorrida[i][CorridaVY], VeiculoCorrida[i][CorridaVZ], VeiculoCorrida[i][CorridaVA], random(360), random(360), -1, 0);
        SetVehicleVirtualWorld(pCorrida[i][VeiculoC], 4871);
        VeiculoCorridaMod(i);
        id = i;
        Vg = true;
        break;
    }
    if(Vg == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais vagas nesse evento");
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| CORRIDA | Você entrou na corrida e sua posição é {00BFFF}%d", id+1);
    SendClientMessage(playerid, -1, Mensagem);

    Jogador[playerid][uInteriorEx] = 2144;
    GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 4871);
    SetPlayerPos(playerid, VeiculoCorrida[id][CorridaVX], VeiculoCorrida[id][CorridaVY], VeiculoCorrida[id][CorridaVZ]);
    PutPlayerInVehicle(playerid, pCorrida[id][VeiculoC], 0);
    TogglePlayerControllable(playerid, 0);
    if(VeiculoFanstasma == true) DisableRemoteVehicleCollisions(playerid, 1);
    PlayerPlaySound(playerid, 1062, 0.0, 0.0, 0.0);
    return 1;
}

stock IniciarCorrida()
{
    for(new i=0; i < CorridaSlot; i++)
    {
        if(pCorrida[i][VagaC] == false) continue;  
        if(!IsPlayerConnected(pCorrida[i][JogadorC])) continue;
        TogglePlayerControllable(pCorrida[i][JogadorC], 1);
        
        pCorrida[i][CheckpointC] = CreateDynamicRaceCP(0, CheckCorrida[0][CheckVX], CheckCorrida[0][CheckVY], CheckCorrida[0][CheckVZ], CheckCorrida[1][CheckVX], CheckCorrida[1][CheckVY], CheckCorrida[1][CheckVZ], 4.0, 4871, 0, pCorrida[i][JogadorC], 999999.9, -1);
        pCorrida[i][MapCorridaC] = CreateDynamicMapIcon(CheckCorrida[0][CheckVX], CheckCorrida[0][CheckVY], CheckCorrida[0][CheckVZ], 0, 0x00FF00FF, 4871, 0, pCorrida[i][JogadorC], 99999.9, MAPICON_GLOBAL, -1);
        SetTimerEx("VerificarCorrida", 1000, false, "dd", pCorrida[i][JogadorC], i);
    }
    return 1;
}

stock SendClientMessageCorrida(const Mensagem[])
{
    for(new i=0; i < CorridaSlot; i++)
    {
        if(pCorrida[i][VagaC] == false) continue;
        SendClientMessage(pCorrida[i][JogadorC], -1, Mensagem); 
    }
    return 1;
}

hook OnPlayerEnterDynRaceCP(playerid, checkpointid)
{
    if(checkpointid == INVALID_STREAMER_ID) return 1;
    for(new i=0; i < CorridaSlot; i++)
    {
        if(pCorrida[i][VagaC] == false) continue;
        if(pCorrida[i][JogadorC] != playerid) continue;
        DestroyDynamicRaceCPEx(pCorrida[i][CheckpointC]);
        DestroyDynamicMapIconEx(pCorrida[i][MapCorridaC]);
        PlayerPlaySound(pCorrida[i][JogadorC], 1056, 0.0, 0.0, 0.0);
        pCorrida[i][PosicaoC] += 1;
        if(pCorrida[i][PosicaoC] >= CorridaCheck)
        {
            PosicaoGanhou += 1;
            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "| CORRIDA | Você chegou na %d posição", PosicaoGanhou);
            SendClientMessage(playerid, -1, Mensagem);

            format(Mensagem, sizeof(Mensagem), "| CORRIDA | O(A) Jogador(a) {FFA500}%s[%d]{FFFFFF} chegou na {00BFFF}%d{FFFFFF} posição", PegarNick(playerid), playerid, PosicaoGanhou);
            SendClientMessageCorrida(Mensagem);
            RetirarCorrida(i);
            return 1;
        }
        new ContaMT = pCorrida[i][PosicaoC];
        ContaMT += 1;
        if(ContaMT >= CorridaCheck)
        {
            pCorrida[i][CheckpointC] = CreateDynamicRaceCP(1, CheckCorrida[pCorrida[i][PosicaoC]][CheckVX], CheckCorrida[pCorrida[i][PosicaoC]][CheckVY], CheckCorrida[pCorrida[i][PosicaoC]][CheckVZ], 0.0, 0.0, 0.0, 4.0, 4871, 0, playerid, 99999.9, -1);
            pCorrida[i][MapCorridaC] = CreateDynamicMapIcon(CheckCorrida[pCorrida[i][PosicaoC]][CheckVX], CheckCorrida[pCorrida[i][PosicaoC]][CheckVY], CheckCorrida[pCorrida[i][PosicaoC]][CheckVZ], 0, 0xFFFF00FF, 4871, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
        }
        else
        {
            pCorrida[i][CheckpointC] = CreateDynamicRaceCP(0, CheckCorrida[pCorrida[i][PosicaoC]][CheckVX], CheckCorrida[pCorrida[i][PosicaoC]][CheckVY], CheckCorrida[pCorrida[i][PosicaoC]][CheckVZ], CheckCorrida[ContaMT][CheckVX], CheckCorrida[ContaMT][CheckVY], CheckCorrida[ContaMT][CheckVZ], 4.0, 4871, 0, playerid, 99999.9, -1);
            pCorrida[i][MapCorridaC] = CreateDynamicMapIcon(CheckCorrida[pCorrida[i][PosicaoC]][CheckVX], CheckCorrida[pCorrida[i][PosicaoC]][CheckVY], CheckCorrida[pCorrida[i][PosicaoC]][CheckVZ], 0, 0x00FF00FF, 4871, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
        }
        break;
    }
    return 1;
}

function IniciarContagemCorrida(c)
{
    if(c == 0)
    {
        IniciarCorrida();
        return 1;
    }
    new Contd[20];
    format(Contd, sizeof(Contd), "~r~%d", c);
    for(new i=0; i < CorridaSlot; i++)
    {
        if(pCorrida[i][VagaC] == false) continue;  
        if(!IsPlayerConnected(pCorrida[i][JogadorC])) continue;
        GameTextForPlayer(pCorrida[i][JogadorC], Contd, 5000, 4);
        PlayerPlaySound(pCorrida[i][JogadorC], 1056, 0.0, 0.0, 0.0);
    }
    c--;
    SetTimerEx("IniciarContagemCorrida", 1000, false, "d", c);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    CancelarCriacao(playerid);
    if(EventoID != 3) return 1;
    for(new i=0; i < CorridaSlot; i++){
        if(pCorrida[i][VagaC] == false) continue;
        if(pCorrida[i][JogadorC] != playerid) continue;
        RetirarCorrida(i);
        break;
    }

    return 1;
}

stock RetirarCorrida(id)
{
    if(id == -1)
    {
        new Fdasd[CorridaInfo];
        for(new i=0; i < CorridaSlot; i++)
        {
            if(pCorrida[i][VagaC] == false) continue;
            if(pCorrida[i][GanhouC] == false){
                RemoverCoridaMod(i);
                DestroyVehicleEx(pCorrida[i][VeiculoC]);
            } 
            pCorrida[i][GanhouC] = false;
            pCorrida[i][VagaC] = false;
            Jogador[pCorrida[i][JogadorC]][uInteriorEx] = 0;
            if(VeiculoFanstasma == true) DisableRemoteVehicleCollisions(pCorrida[i][JogadorC], 0);
            DestroyDynamicRaceCPEx(pCorrida[i][CheckpointC]);
            DestroyDynamicMapIconEx(pCorrida[i][MapCorridaC]);
            SetPlayerVirtualWorld(pCorrida[i][JogadorC], 0);
            TogglePlayerControllable(pCorrida[i][JogadorC], 1);
            SetPlayerPos(pCorrida[i][JogadorC], Jogador[pCorrida[i][JogadorC]][uInteriorExP][0], Jogador[pCorrida[i][JogadorC]][uInteriorExP][1], Jogador[pCorrida[i][JogadorC]][uInteriorExP][2]);
            pCorrida[i] = Fdasd;
        }
        return 1;
    }

    if(pCorrida[id][VagaC] == false) return 1;
    if(pCorrida[id][GanhouC] == false){
        RemoverCoridaMod(id);
        DestroyVehicleEx(pCorrida[id][VeiculoC]);
    }
    pCorrida[id][GanhouC] = false;
    pCorrida[id][VagaC] = false;
    Jogador[pCorrida[id][JogadorC]][uInteriorEx] = 0;
    if(VeiculoFanstasma == true) DisableRemoteVehicleCollisions(pCorrida[id][JogadorC], 0);
    DestroyDynamicRaceCPEx(pCorrida[id][CheckpointC]);
    DestroyDynamicMapIconEx(pCorrida[id][MapCorridaC]);
    SetPlayerVirtualWorld(pCorrida[id][JogadorC], 0);
    TogglePlayerControllable(pCorrida[id][JogadorC], 1);
    // SetPlayerPos(pCorrida[id][JogadorC], Jogador[pCorrida[id][JogadorC]][uInteriorExP][0], Jogador[pCorrida[id][JogadorC]][uInteriorExP][1], Jogador[pCorrida[id][JogadorC]][uInteriorExP][2]);

    new Fdassdd[CorridaInfo];
    pCorrida[id] = Fdassdd;
    return 1;
}

stock RespawnarCorrida(playerid, id)
{
    if(pCorrida[id][VagaC] == false) return 1;
    if(pCorrida[id][PosicaoC] == 0){
        RetirarCorrida(id);
        SendClientMessage(playerid, 0xFF4500FF, "| EVENTO | Você voltou para seu último checkpoint");
        return 1;
    }
    RemoverCoridaMod(id);
    DestroyVehicleEx(pCorrida[id][VeiculoC]);
    new cpad = pCorrida[id][PosicaoC];
    cpad -= 1;
    pCorrida[id][VeiculoC] = CreateVehicleEx(playerid, CorridaModelo, CheckCorrida[cpad][CheckVX], CheckCorrida[cpad][CheckVY], CheckCorrida[cpad][CheckVZ], random(360), random(360), random(360), -1, 0);
    SetVehicleVirtualWorld(pCorrida[id][VeiculoC], 4871);
    PutPlayerInVehicle(playerid, pCorrida[id][VeiculoC], 0);
    VeiculoCorridaMod(id);
    SendClientMessage(playerid, 0xFF4500FF, "| EVENTO | Você voltou para seu último checkpoint");
    return 1;
}

function VerificarCorrida(playerid, id)
{
    if(!IsPlayerConnected(playerid)) return 1;
    if(pCorrida[id][VagaC] == false) return 1;
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) return SetTimerEx("VerificarCorrida", 1000, false, "dd", playerid, id);
    RespawnarCorrida(playerid, id);
    SetTimerEx("VerificarCorrida", 1000, false, "dd", playerid, id);
    return 1;
}

stock RemoverCoridaMod(id)
{
    if(VeiculoPers == false) return 1;
    switch(SlotVeiculoPers)
    {
        case 0:
        {
            DestroyDynamicObjectEx(pCorrida[id][pO1]);
            RemovePlayerAttachedObject(pCorrida[id][JogadorC], 9);
        }
    }
    return 1;
}

stock VeiculoCorridaMod(id)
{
    if(VeiculoPers == false) return 1;
    switch(SlotVeiculoPers)
    {
        case 0:
        {
            pCorrida[id][pO1] = CreateDynamicObject(18694, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4871, 0, -1, 90.0, 90.0, -1);
            AttachDynamicObjectToVehicle(pCorrida[id][pO1], pCorrida[id][VeiculoC], 0.3000, -0.5000, -1.7999, 0.0000, 0.0000, 180.0000);
            SetPlayerAttachedObject(pCorrida[id][JogadorC], 9, 6865, 2, 0.0529, -0.0519, -0.0060, -177.7999, 90.4000, 43.0000, 0.1619, 0.2009, 0.1420, 0xFFFFFFFF, 0xFFFFFFFF);
        }
    }
    return 1;
}

stock SetarCorridaPers(id)
{
    new NomePers[30];
    VeiculoPers = true;
    SlotVeiculoPers = id;
    switch(id)
    {
        case 0:
        {
            CorridaModelo = 463;
            NomePers = "Motoqueiro Fantasma";
        }
    }
    return (NomePers);
}