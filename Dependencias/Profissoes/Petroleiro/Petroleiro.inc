#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    for(new i=0; i < sizeof(BuracoP); i++){
        CreateDynamicObject(2986, BuracoP[i][BpX], BuracoP[i][BpY], BuracoP[i][BpZ], BuracoP[i][BprX], BuracoP[i][BprY], BuracoP[i][BprZ], 0, 0, -1, 160.0, 160.0, -1);
    }

    CreateDynamic3DTextLabel("{00BFFF}Petroleiro\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, -1091.9637,-755.3798,35.9873, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 30.0, -1);
    CreateDynamicPickup(1239, 1, -1091.9637,-755.3798,35.9873, 0, 0, -1, 120.0, -1, 0);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "PetroCarreg") == 1) KillTimer(pPetro[playerid][CargTimer]);
    if(pPetro[playerid][AbasPetro] == true) KillTimer(pPetro[playerid][AbasTimer]);

    if(pPetro[playerid][PetroVeiculo] == true)
    {
        DestroyVehicleEx(pPetro[playerid][PetroCabineID]);
        DestroyVehicleEx(pPetro[playerid][PetroTrasID]);  
    }
    
    DestroyDynamicCPEx(pPetro[playerid][PetroCheck]);
    DestroyDynamicMapIconEx(pPetro[playerid][PetroMapa]);
    DestroyDynamicCPEx(pPetro[playerid][PetroCP]);

    new DelataRRr[PetroleiroInfo];
    pPetro[playerid] = DelataRRr;   
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    // Alugar
    if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, -1091.9637,-755.3798,35.9873))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Petroleiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(pPetro[playerid][AbasteceuPetro] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está ainda está serviço");
            if(GetPVarInt(playerid, "TempPetroDl") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco!");
            SetPVarInt(playerid, "TempPetroDl", gettime()+10);
            if(pPetro[playerid][PetroVeiculo] == false)
            {
                if(Jogador[playerid][CarteiraC] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar um caminhão ( Habilitação: C )");
                pPetro[playerid][PetroVeiculo] = true;
                Jogador[playerid][Trabalhando] = true;
                new rda = random(sizeof(PetroVeiculoS));
                pPetro[playerid][PetroCabineID] = CreateVehicleEx(playerid, 514, PetroVeiculoS[rda][pXAs], PetroVeiculoS[rda][pYAs], PetroVeiculoS[rda][pZAs], PetroVeiculoS[rda][pAAs], random(360), random(360), -1, 0);
                pPetro[playerid][PetroTrasID] = CreateVehicleEx(-1, 584, PetroVeiculoS[rda][pXAs], PetroVeiculoS[rda][pYAs], PetroVeiculoS[rda][pZAs], PetroVeiculoS[rda][pAAs], random(360), random(360), -1, 0);
                MarcarPosicao(playerid, PetroVeiculoS[rda][pXAs], PetroVeiculoS[rda][pYAs], PetroVeiculoS[rda][pZAs]);
                VeiculoServer[pPetro[playerid][PetroCabineID]][Tranca] = 1;
                SetTimerEx("BombaTrailerAtt", 2000, false, "dd", pPetro[playerid][PetroTrasID], pPetro[playerid][PetroCabineID]);
                SendClientMessage(playerid, 0xFFFF00FF, "| PETROLEIRO | Seu caminhão foi colocado na vaga");
                return 1;
            }
            pPetro[playerid][PetroVeiculo] = false;
            Jogador[playerid][Trabalhando] = false;
            DestroyVehicleEx(pPetro[playerid][PetroCabineID]);
            DestroyVehicleEx(pPetro[playerid][PetroTrasID]);
            VerificarMarcacao(playerid);
            SendClientMessage(playerid, 0xFFFF00FF, "| PETROLEIRO | Seu caminhão foi devolvido");
        }
    }

    // Pegar Litrão do Caminhão
    else if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(pPetro[playerid][PetroVeiculo] == false) return 1;
        new Float:PetroTrasF[3];
        GetVehiclePos(pPetro[playerid][PetroTrasID], PetroTrasF[0], PetroTrasF[1], PetroTrasF[2]);
        if(!IsPlayerInRangeOfPoint(playerid, 4.0, PetroTrasF[0], PetroTrasF[1], PetroTrasF[2])) return 1;
        new id = pPetro[playerid][PetroPostoID];
        if(!IsPlayerInRangeOfPoint(playerid, 60.0, BuracoP[id][BpX], BuracoP[id][BpY], BuracoP[id][BpZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto do local de abastecimento");
        if(pPetro[playerid][AbasteceuPetro] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não fez nenhum carregamento");
        if(pPetro[playerid][GalaoPetro] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já pegou o galão");
        pPetro[playerid][GalaoPetro] = true;
        SetPlayerAttachedObject(playerid, 9, 1613, 6, 0.3110, 0.0479, 0.0160, -104.7999, 0.0000, 0.0000, 0.5829, 0.1750, 0.1709, 0xFFFFFFFF, 0xFFFFFFFF); 
        SendClientMessage(playerid, 0xFFFF00FF, "| PETROLEIRO | Você pegou o galão");

    }
    return 1;
}

Dialog:PostoPetro(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarInt(playerid, "AntiCarregamentoPetro", 1);
    SetPVarInt(playerid, "PostoAIDD", listitem);
    new Float:DfA = GetPlayerDistanceFromPoint(playerid, BuracoP[listitem][BpX], BuracoP[listitem][BpY], BuracoP[listitem][BpZ]);
    new Hbsa = DistanciaValor(DfA, 1);
    new Nva = Hbsa;
    new Antes = (Hbsa * 20) / 100;
    Nva -= Antes;
    SetPVarInt(playerid, "ValorGanhoPetro", Nva);
    pPetro[playerid][PetroCheck] = CreateDynamicCP(-1106.9594,-689.6823,32.0078, 5.0, 0, 0, playerid, 100.0, -1);
    pPetro[playerid][PetroMapa] = CreateDynamicMapIcon(-1106.9594,-689.6823,32.0078, 11, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
    return 1;
}

CMD:abastecerposto(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Petroleiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPlayerVehicleID(playerid) != pPetro[playerid][PetroCabineID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo");
    if(GetPVarInt(playerid, "AntiCarregamentoPetro") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já carregou, vá até o ponto na HQ");
    if(pPetro[playerid][AbasteceuPetro] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já carregou o caminhão");

    new Float:DfA,
        Dialog[900],
        Hbsa,
        Antes,
        Nva;
    strcat(Dialog, "ID\tLocal\tPreço\n");
    for(new i=0; i < sizeof(BuracoP); i++){
        DfA = GetPlayerDistanceFromPoint(playerid, BuracoP[i][BpX], BuracoP[i][BpY], BuracoP[i][BpZ]);
        Hbsa = DistanciaValor(DfA, 1);
        Nva = Hbsa;
        Antes = (Hbsa * 20) / 100;
        Nva -= Antes;
        strcatEx(Dialog, "{CCCCCC}%d\t{00BFFF}%s\t{32CD32}$%s\n", i+1, AreaNome(BuracoP[i][BpX], BuracoP[i][BpY], BuracoP[i][BpZ]), DinheiroSeparar(Nva));
    }
    Dialog_Show(playerid, PostoPetro, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Petroleiro", Dialog, "Selecionar", "Cancelar");
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid == pPetro[playerid][PetroCheck])
    {
        TogglePlayerControllable(playerid, 0);
        SetPVarInt(playerid, "PetroCarreg", 1);
        GameTextForPlayer(playerid, "~r~Aguarde", 7000, 4);
        pPetro[playerid][CargTimer] = SetTimerEx("CarregandoTempoPetro", 8000, false, "d", playerid);
    }
    else if(checkpointid == pPetro[playerid][PetroCP])
    {
        TogglePlayerControllable(playerid, 0);
        CriarProgresso(playerid, "Descarregando, aguarde.", "AbastecerPostoPertro", 400);
    }

    return 1;
}

function CarregandoTempoPetro(playerid)
{
    GameTextForPlayer(playerid, "", 500, 3);
    TogglePlayerControllable(playerid, 1);
    SetPVarInt(playerid, "PetroCarreg", 0);
    pPetro[playerid][PetroPostoID] = GetPVarInt(playerid, "PostoAIDD");
    pPetro[playerid][PetroGanho] = GetPVarInt(playerid, "ValorGanhoPetro");

    DestroyDynamicMapIconEx(pPetro[playerid][PetroMapa]);
    SetPVarInt(playerid, "AntiCarregamentoPetro", 0);

    pPetro[playerid][AbasteceuPetro] = true;
    new Mensagem[128];
    pPetro[playerid][PetroCP] = CreateDynamicCP(BuracoP[pPetro[playerid][PetroPostoID]][BpX], BuracoP[pPetro[playerid][PetroPostoID]][BpY], BuracoP[pPetro[playerid][PetroPostoID]][BpZ], 2.0, 0, 0, playerid, 30.0, -1);
    pPetro[playerid][PetroMapa] = CreateDynamicMapIcon(BuracoP[pPetro[playerid][PetroPostoID]][BpX], BuracoP[pPetro[playerid][PetroPostoID]][BpY], BuracoP[pPetro[playerid][PetroPostoID]][BpZ], 55, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);

    format(Mensagem, sizeof(Mensagem), "| PETROLEIRO | Você abasteceu seu caminhão, vá até o posto de %s", AreaNome(BuracoP[pPetro[playerid][PetroPostoID]][BpX], BuracoP[pPetro[playerid][PetroPostoID]][BpY], BuracoP[pPetro[playerid][PetroPostoID]][BpZ]));
    SendClientMessage(playerid, 0xFFFF00FF, Mensagem);

    DestroyDynamicCPEx(pPetro[playerid][PetroCheck]);
    return 1;
}

function AbastecerPostoPertro(playerid)
{
    new Mensagem[128];
    Jogador[playerid][Dinheiro] += pPetro[playerid][PetroGanho];
    format(Mensagem, sizeof(Mensagem), "| PETROLEIRO | Você entregou e recebeu {32CD32}$%s", DinheiroSeparar(pPetro[playerid][PetroGanho]));
    SendClientMessage(playerid, -1, Mensagem);
    pPetro[playerid][AbasPetro] = false;
    pPetro[playerid][AbasteceuPetro] = false;
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicMapIconEx(pPetro[playerid][PetroMapa]);
    DestroyDynamicCPEx(pPetro[playerid][PetroCP]);
    return 1;
}
 
function BombaTrailerAtt(id1, id)
{
 	AttachTrailerToVehicle(id1, id);
	return 1;
}