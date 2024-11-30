#include <YSI_Coding\y_hooks>

enum LenhadorJogador
{
    bool:LenhaVeiuloPeg,
    LenhaVeiculoID,
    LenhaStatus,
    LenhaID,
    Text3D:LenhaTexto,
    LenhaMap,
    LenhaCp,
    LenhaObjeto
};

new LenhadorMensagem;
new pLenha[MAX_PLAYERS][LenhadorJogador];

hook OnGameModeInit()
{
    LenhadorMensagem = CreateDynamicRectangle(-382.1227,-1480.5509, -468.2939,-1596.8207, 0, 0, -1); 
    CreateDynamicPickup(1239, 1, -367.0769,-1440.5814,25.7266, 0, 0, -1, 100.0, -1);
    CreateDynamic3DTextLabel("Lenhador\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", 0xFFA500FF, -367.0769,-1440.5814,25.7266, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);

    CreateDynamic3DTextLabel("Lenhador\n{FFFFFF}Use: {CCCCCC}/Lixar{FFFFFF} para lixar o madeira", 0xFFA500FF, -96.6894,-45.3234,3.1094, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamic3DTextLabel("Lenhador\n{FFFFFF}Use: {CCCCCC}/Lixar{FFFFFF} para lixar o madeira", 0xFFA500FF, -95.6920,-42.5476,3.1172, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamic3DTextLabel("Lenhador\n{FFFFFF}Use: {CCCCCC}/Lixar{FFFFFF} para lixar o madeira", 0xFFA500FF, -94.6915,-39.8360,3.1172, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    new Olasd[25];
    for(new i=0; i < MAX_LENHA; i++)
    {
        format(Olasd, sizeof(Olasd), "Lenhador ({FFA500}ID: %d{FFFFFF})", i+1);
        Lenha[i][LenhaText] = CreateDynamic3DTextLabel(Olasd, -1, LenhaLoad[i][LenhaLPosX], LenhaLoad[i][LenhaLPosY], LenhaLoad[i][LenhaLPosZ]+4, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 17.0, -1);
        Lenha[i][LenhaObjet] = CreateDynamicObject(654, LenhaLoad[i][LenhaLPosX], LenhaLoad[i][LenhaLPosY], LenhaLoad[i][LenhaLPosZ], LenhaLoad[i][LenhaLRotX], LenhaLoad[i][LenhaLRotY], LenhaLoad[i][LenhaLRotZ], -1, 0, -1, 500.0, 500.0, -1);
    }
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid == LenhadorMensagem) MostrarMensagemBaixo(playerid, ConverterTexto("Área de ~r~Lenhador~w~, cuidado."));
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{   
    if(areaid == LenhadorMensagem) OcultarMensagemBaixo(playerid);
    return 1;
}

function RegenerarLenha(i)
{
    Lenha[i][LenhaQuebrada]--;
    new Mensagem[60];
    format(Mensagem, sizeof(Mensagem), "Lenhador (ID: %d)\n{FFA500}Tempo: %s", i+1, SegundosParaMinutos(Lenha[i][LenhaQuebrada]));
    UpdateDynamic3DTextLabelText(Lenha[i][LenhaText], -1, Mensagem);
    if(Lenha[i][LenhaQuebrada] > 0) SetTimerEx("RegenerarLenha", 1000, false, "d", i);
    else
    {
        format(Mensagem, sizeof(Mensagem), "Lenhador ({FFA500}ID: %d{FFFFFF})", i+1);
        UpdateDynamic3DTextLabelText(Lenha[i][LenhaText], -1, Mensagem);  
        DestroyDynamicObjectEx(Lenha[i][LenhaObjet]); 
        Lenha[i][LenhaObjet] = CreateDynamicObject(654, LenhaLoad[i][LenhaLPosX], LenhaLoad[i][LenhaLPosY], LenhaLoad[i][LenhaLPosZ], LenhaLoad[i][LenhaLRotX], LenhaLoad[i][LenhaLRotY], LenhaLoad[i][LenhaLRotZ], -1, 0, -1, 500.0, 500.0, -1);
    }
    return 1;
}

stock RegenerarLenhador(i)
{
    new Mensagem[60];
    format(Mensagem, sizeof(Mensagem), "Lenhador ({FFA500}ID: %d{FFFFFF})\n{FFA500}Tempo: 00:00", i+1);
    UpdateDynamic3DTextLabelText(Lenha[i][LenhaText], -1, Mensagem);
    Lenha[i][LenhaQuebrada] = 78;
    Lenha[i][LenhaUsando] = false;
    SetTimerEx("RegenerarLenha", 1000, false, "d", i);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamicObjectEx(pLenha[playerid][LenhaObjeto]);
    DestroyVehicleEx(pLenha[playerid][LenhaVeiculoID]);
    DestroyDynamic3DTextLabelEx(pLenha[playerid][LenhaTexto]);
    DestroyDynamicCPEx(pLenha[playerid][LenhaCp]);
    DestroyDynamicMapIconEx(pLenha[playerid][LenhaMap]);
    if(pLenha[playerid][LenhaStatus] == 1 || pLenha[playerid][LenhaStatus] == 2) RegenerarLenhador(pLenha[playerid][LenhaID]);
    
    new DSADASdsa[LenhadorJogador];
    pLenha[playerid] = DSADASdsa;
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_ONFOOT)
    {
        if(pLenha[playerid][LenhaStatus] != 4) return 1;
        if(GetPVarInt(playerid, "LKDLASKDLSAKDA") == 1) return 1;
        if(!IsPlayerInRangeOfPoint(playerid, 60.0, -73.5589,-50.1399,3.1172)) return 1;
        SetPVarInt(playerid, "LKDLASKDLSAKDA", 1);
        pLenha[playerid][LenhaTexto] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'H'{FFFFFF} para colocar", -1, 0.0000, -4.0999, -0.9000, 16.0, INVALID_PLAYER_ID, pLenha[playerid][LenhaVeiculoID], 0, 0, 0, playerid, 17.0, -1);
    }
    else if(newstate == PLAYER_STATE_DRIVER)
    {
        if(pLenha[playerid][LenhaStatus] != 4) return 1;
        if(GetPVarInt(playerid, "LKDLASKDLSAKDA") == 0) return 1;
        SetPVarInt(playerid, "LKDLASKDLSAKDA", 0);
        DestroyDynamic3DTextLabelEx(pLenha[playerid][LenhaTexto]);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, -367.0769,-1440.5814,25.7266))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Lenhador")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(GetPVarInt(playerid, "asdasdasdasAacz") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            if(pLenha[playerid][LenhaStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem serviço");
            SetPVarInt(playerid, "asdasdasdasAacz", gettime()+10);
            if(pLenha[playerid][LenhaVeiuloPeg] == false)
            {
                new i = random(sizeof(VeiculoLLoad));
                pLenha[playerid][LenhaVeiculoID] = CreateVehicleEx(playerid, 424, VeiculoLLoad[i][LenhaVehX], VeiculoLLoad[i][LenhaVehY], VeiculoLLoad[i][LenhaVehZ], VeiculoLLoad[i][LenhaVehA], random(360), random(360), 460, 0);
                VeiculoServer[pLenha[playerid][LenhaVeiculoID]][Tranca] = 1;
                pLenha[playerid][LenhaVeiuloPeg] = true;
                Jogador[playerid][Trabalhando] = true;
                SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você alugou um veículo");
                MarcarPosicao(playerid, VeiculoLLoad[i][LenhaVehX], VeiculoLLoad[i][LenhaVehY], VeiculoLLoad[i][LenhaVehZ]);
                return 1;
            }
            SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você devolveu o veículo");
            DestroyVehicleEx(pLenha[playerid][LenhaVeiculoID]);
            pLenha[playerid][LenhaVeiuloPeg] = false;
            Jogador[playerid][Trabalhando] = false;
            VerificarMarcacao(playerid);
        }
        else if(pLenha[playerid][LenhaStatus] == 2)
        {
            new id = pLenha[playerid][LenhaID];
            if(!IsPlayerInRangeOfPoint(playerid, 2.0, LenhaLoad[id][LenhaLPosX], LenhaLoad[id][LenhaLPosY], LenhaLoad[id][LenhaLPosZ])) return 1;
            RegenerarLenhador(id);
            pLenha[playerid][LenhaStatus] = 3;
            pLenha[playerid][LenhaTexto] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'H'{FFFFFF} para colocar", -1, 0.0000, -4.0999, -0.9000, 16.0, INVALID_PLAYER_ID, pLenha[playerid][LenhaVeiculoID], 0, 0, 0, playerid, 17.0, -1);
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
            SetPlayerAttachedObject(playerid, 9, 684, 1, 0.2490, 0.6249, 0.0119, 91.8000, 0.0000, -3.5999, 0.6789, 0.3740, 0.6610, 0xFFFFFFFF, 0xFFFFFFFF);
        }
    }
    else if(newkeys == KEY_CTRL_BACK)
    {
        if(AtrasVeiculo(playerid, pLenha[playerid][LenhaVeiculoID], 2.0))
        {
            if(pLenha[playerid][LenhaStatus] == 3)
            {
                pLenha[playerid][LenhaStatus] = 4;
                DestroyDynamic3DTextLabelEx(pLenha[playerid][LenhaTexto]);
                RemovePlayerAttachedObject(playerid, 9);
                ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
                pLenha[playerid][LenhaObjeto] = CreateDynamicObject(684, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0, -1);
                AttachDynamicObjectToVehicle(pLenha[playerid][LenhaObjeto], pLenha[playerid][LenhaVeiculoID], 0.0000, -0.5099, 1.1599, 0.0000, 0.0000, 0.0000);
                pLenha[playerid][LenhaMap] = CreateDynamicMapIcon(-96.6894,-45.3234,3.1094, 56, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
            }
            else if(pLenha[playerid][LenhaStatus] == 4)
            {
                if(!IsPlayerInRangeOfPoint(playerid, 60.0, -96.6894,-45.3234,3.1094)) return 1;
                if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
                pLenha[playerid][LenhaStatus] = 5;
                DestroyDynamicObjectEx(pLenha[playerid][LenhaObjeto]);
                ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
                SetPlayerAttachedObject(playerid, 9, 684, 1, 0.2490, 0.6249, 0.0119, 91.8000, 0.0000, -3.5999, 0.6789, 0.3740, 0.6610, 0xFFFFFFFF, 0xFFFFFFFF);
            }
        }
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pLenha[playerid][LenhaCp]) return 1;
    if(pLenha[playerid][LenhaStatus] != 7) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está segurando a madeira");
    pLenha[playerid][LenhaStatus] = 0;
    SetPVarInt(playerid, "LKDLASKDLSAKDA", 0);
    RemovePlayerAttachedObject(playerid, 9);
    ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
    DestroyDynamic3DTextLabelEx(pLenha[playerid][LenhaTexto]);
    DestroyDynamicCPEx(pLenha[playerid][LenhaCp]);
    DestroyDynamicMapIconEx(pLenha[playerid][LenhaMap]);

    new Mensagem[128],
        DinheLenha = random(1000-750)+750;
    Jogador[playerid][Dinheiro] += DinheLenha;
    format(Mensagem, sizeof(Mensagem), "| LENHADOR | Você recebeu {32CD32}$%s{FFFFFF} pela entrega", DinheiroSeparar(DinheLenha));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

function LenhaEtp1(playerid)
{
    TogglePlayerControllable(playerid, 1);
    new Mensagem[128],
        i = pLenha[playerid][LenhaID];
    format(Mensagem, sizeof(Mensagem), "Lenhador (ID: %d)\n{FFA500}%s[%d]\nAperte {CCCCCC}'Y'{FFA500} para pegar", i+1, PegarNick(playerid), playerid);
    UpdateDynamic3DTextLabelText(Lenha[i][LenhaText], -1, Mensagem);
    DestroyDynamicObjectEx(Lenha[i][LenhaObjet]); 
    Lenha[i][LenhaObjet] = CreateDynamicObject(832, LenhaLoad[i][LenhaLPosX], LenhaLoad[i][LenhaLPosY], LenhaLoad[i][LenhaLPosZ], LenhaLoad[i][LenhaLRotX], LenhaLoad[i][LenhaLRotY], LenhaLoad[i][LenhaLRotZ], 0, 0, -1, 500.0, 500.0, -1);   
    pLenha[playerid][LenhaStatus] = 2;
    SendClientMessage(playerid, 0xFFFF00FF, "| LENHADOR | Você precisa pegar a madeira e colocar no veículo");
    return 1;
}

CMD:derrubar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Lenhador")) return 0;
    if(pLenha[playerid][LenhaVeiuloPeg] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não alugou um veículo de lenhador");
    if(pLenha[playerid][LenhaStatus] != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode destruir agora");

    new id = -1;
    for(new i=0; i < MAX_LENHA; i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 7.0, LenhaLoad[i][LenhaLPosX], LenhaLoad[i][LenhaLPosY], LenhaLoad[i][LenhaLPosZ])) continue;
        if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) continue;
        if(Lenha[i][LenhaUsando] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode derrubar essa árvore.");
        if(Lenha[i][LenhaQuebrada] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode derrubar essa árvore pois ela está quebrada.");

        id = i;
        TogglePlayerControllable(playerid, 0);
        pLenha[playerid][LenhaStatus] = 1;
        pLenha[playerid][LenhaID] = i;

        new Mensagem[60];
        format(Mensagem, sizeof(Mensagem), "Lenhador (ID: %d)\n{FFA500}%s[%d]", i+1, PegarNick(playerid), playerid);
        UpdateDynamic3DTextLabelText(Lenha[i][LenhaText], -1, Mensagem);

        CriarProgresso(playerid, "Destruindo Árvore, aguarde.", "LenhaEtp1", 850);
        break;
    }
    if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de uma árvore");
    return 1;
}

function LenhaEtp2(playerid)
{
    DestroyDynamicMapIconEx(pLenha[playerid][LenhaMap]);
    TogglePlayerControllable(playerid, 1);
    pLenha[playerid][LenhaCp] = CreateDynamicCP(-73.5589,-50.1399,3.1172, 1.0, 0, 0, playerid, 30.0, -1);
    pLenha[playerid][LenhaMap] = CreateDynamicMapIcon(-73.5589,-50.1399,3.1172, 56, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
    
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
    SetPlayerAttachedObject(playerid, 9, 19793, 5, 0.1210, 0.0530, 0.1470, 0.0000, -70.3000, -9.0999, 1.0000, 1.3159, 1.5690, 0xFFFFFFFF, 0xFFFFFFFF); 

    pLenha[playerid][LenhaStatus] = 7;
    return 1;
}

CMD:lixar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Lenhador")) return 0;
    if(pLenha[playerid][LenhaVeiuloPeg] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não alugou um veículo de lenhador");
    if(pLenha[playerid][LenhaStatus] != 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode lixar agora");
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, -96.6894,-45.3234,3.1094) &&
    !IsPlayerInRangeOfPoint(playerid, 2.0, -95.6920,-42.5476,3.1172) && 
    !IsPlayerInRangeOfPoint(playerid, 2.0, -94.6915,-39.8360,3.1172)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está nas mesas");

    pLenha[playerid][LenhaStatus] = 6;
    RemovePlayerAttachedObject(playerid, 9);
    TogglePlayerControllable(playerid, 0);
    CriarProgresso(playerid, "Você está lixando a madeira.", "LenhaEtp2", 700);
    return 1;
}