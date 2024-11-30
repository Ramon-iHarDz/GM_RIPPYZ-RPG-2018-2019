#include <YSI_Coding\y_hooks>

#define     MAX_VACAS   (13)

enum LeiteS 
{
    Float:LeiteX,
    Float:LeiteY,
    Float:LeiteZ,
    Float:LeiteA
};

enum VacaInfo
{
    bool:VacaUsada,
    VacaObjeto,
    Text3D:VacaTexto
};

enum LeiteiroJogador
{
    bool:AlgVeh,
    AlgId,

    LeiteStatus,
    VacaID,

    Text3D:TextoLeite,
    LataoLeite,
    CheckVaca,
    MapVaca
};

new VacaInf[][LeiteS] =
{
    {-7.0988,51.7060,3.1172,59.8552}, // Vaca 1
    {-23.8557,58.6742,3.1172,246.4629}, // Vaca 2
    {-32.3913,40.7527,3.1172,186.3849}, // Vaca 3
    {-32.9390,24.0713,3.1172,27.7448}, // Vaca 4
    {-24.2287,27.9253,3.1172,309.4937}, // Vaca 5
    {-11.8600,45.8284,3.1172,315.6940}, // Vaca 6
    {-21.1707,43.7904,3.1172,124.1689}, // Vaca 7
    {-42.7633,19.2389,3.1172,314.1974}, // Vaca 8
    {-26.9185,3.8002,3.1094,45.2766}, // Vaca 9
    {-34.1113,-2.2126,3.1094,113.9066}, // Vaca 10
    {-32.6373,-10.9412,3.1094,55.5390}, // Vaca 11
    {-41.8824,-16.1894,3.1172,110.4858}, // Vaca 12
    {-39.3186,-28.5797,3.1172,343.9561} // Vaca 13
};

new LeiteCarro[][LeiteS] =
{
    {-45.8621,81.2826,2.9519,254.5392},
    {-47.2103,76.0249,2.9310,254.9072},
    {-48.4246,71.1299,2.9360,254.6968},
    {-49.7343,66.3481,2.9382,254.3741},
    {-58.7569,71.6222,2.9371,254.3950},
    {-57.5361,76.3962,2.9362,254.7441},
    {-56.2153,81.1691,2.9355,255.2549},
    {-54.9998,86.0938,2.9331,255.2268}
};

new pLeite[MAX_PLAYERS][LeiteiroJogador];
new Vaca[MAX_VACAS][VacaInfo];

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Leiteiro{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", 0xFFFF00FF, -21.5200,74.1944,3.1096, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1239, 1, -21.5200,74.1944,3.1096, 0, 0, -1, 100.0, -1);
    
    new Mensagem[78];
    for(new i=0; i < MAX_VACAS; i++) 
    {
        VacaInf[i][LeiteZ] -= 1.0;
        Vaca[i][VacaObjeto] = CreateDynamicObject(19833, VacaInf[i][LeiteX], VacaInf[i][LeiteY], VacaInf[i][LeiteZ], 0.0, 0.0, float(random(360)), 0, 0, -1, 350.0, 350.0, -1);
        format(Mensagem, sizeof(Mensagem), "Vaca (ID: %d){32CD32}\nDisponível{FFFFFF}\nUse: {CCCCCC}/TirarLeite", i+1);
        Vaca[i][VacaTexto] = CreateDynamic3DTextLabel(Mensagem, 0xFFA500FF, VacaInf[i][LeiteX], VacaInf[i][LeiteY], VacaInf[i][LeiteZ], 13.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 14.0, -1);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyVehicleEx(pLeite[playerid][AlgId]);
    DestroyDynamicObjectEx(pLeite[playerid][LataoLeite]);
    DestroyDynamic3DTextLabelEx(pLeite[playerid][TextoLeite]);
    DestroyDynamicCPEx(pLeite[playerid][CheckVaca]);
    DestroyDynamicMapIconEx(pLeite[playerid][MapVaca]);

    if(pLeite[playerid][LeiteStatus] == 1 || pLeite[playerid][LeiteStatus] == 2 || pLeite[playerid][LeiteStatus] == 3){
        new id = pLeite[playerid][VacaID];
        VacaReg(id);
        Vaca[id][VacaUsada] = false;
    }
    new asdsa[LeiteiroJogador];
    pLeite[playerid] = asdsa;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, -21.5200,74.1944,3.1096))
        {
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Leiteiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pLeite[playerid][LeiteStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não acabou o serviço");
            if(GetPVarInt(playerid, "DASLKDDASDASAL") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            SetPVarInt(playerid, "DASLKDDASDASAL", gettime()+10);

            if(pLeite[playerid][AlgVeh] == false)
            {
                new i = random(sizeof(LeiteCarro));
                pLeite[playerid][AlgId] = CreateVehicleEx(playerid, 543, LeiteCarro[i][LeiteX], LeiteCarro[i][LeiteY], LeiteCarro[i][LeiteZ], LeiteCarro[i][LeiteA], 2, 2, 450, 0);
                VeiculoServer[pLeite[playerid][AlgId]][Tranca] = 1;
                pLeite[playerid][AlgVeh] = true;
                Jogador[playerid][Trabalhando] = true;
                MarcarPosicao(playerid, LeiteCarro[i][LeiteX], LeiteCarro[i][LeiteY], LeiteCarro[i][LeiteZ]);
                SendClientMessage(playerid, 0xFFFF00FF, "| FAZENDA | Você alugou um veículo");
                return 1;
            }
            DestroyVehicleEx(pLeite[playerid][AlgId]);
            VerificarMarcacao(playerid);
            pLeite[playerid][AlgVeh] = false;
            Jogador[playerid][Trabalhando] = false;
            SendClientMessage(playerid, 0xFFFF00FF, "| FAZENDA | Você devolveu um veículo");
        }
    }

    else if(newkeys == KEY_CTRL_BACK)
    {
        if(pLeite[playerid][LeiteStatus] == 2)
        {
            new id = pLeite[playerid][VacaID];
            new Float:Vaco[3];
            GetDynamicObjectPos(Vaca[id][VacaObjeto], Vaco[0], Vaco[1], Vaco[2]);
            GetXY(Vaco[0], Vaco[1], VacaInf[id][LeiteA], 1.5, 90.0);
            if(!IsPlayerInRangeOfPoint(playerid, 2.0, Vaco[0], Vaco[1], Vaco[2])) return 1;
            pLeite[playerid][LeiteStatus] = 3;
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
            SetPlayerAttachedObject(playerid, 9, 3632, 1, 0.2119, 0.5190, -0.0379, 0.0000, 6.7000, 0.0000, 0.6860, 0.6159, 0.6409, 0xFFFFFFFF, 0xFFFFFFFF);

            DestroyDynamicObjectEx(pLeite[playerid][LataoLeite]);
            DestroyDynamic3DTextLabelEx(pLeite[playerid][TextoLeite]);
            pLeite[playerid][TextoLeite] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'H'{FFFFFF} para colocar", -1, 0.0000, -4.0999, -0.9000, 10.0, INVALID_PLAYER_ID, pLeite[playerid][AlgId], 0, 0, 0, playerid, 11.0, -1);
        }
        else if(AtrasVeiculo(playerid, pLeite[playerid][AlgId], 2.0))
        {
            ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
            RemovePlayerAttachedObject(playerid, 9);
            
            if(pLeite[playerid][LeiteStatus] == 3)
            {
                new id = pLeite[playerid][VacaID],
                    Mensagem[128],
                    i = PegarUTL();
                VacaReg(id);
                Vaca[id][VacaUsada] = false;
                pLeite[playerid][LeiteStatus] = 4;
                
                DestroyDynamic3DTextLabelEx(pLeite[playerid][TextoLeite]);
                format(Mensagem, sizeof(Mensagem), "| FAZENDEIRO | Você precisa ir até a loja de utilitários %d para entregar o leite", i);
                SendClientMessage(playerid, 0xFFA500FF, Mensagem);

                pLeite[playerid][VacaID] = i;
                pLeite[playerid][LataoLeite] = CreateDynamicObject(3632, 0.0, 0.0, -5.0, 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0, -1);
                AttachDynamicObjectToVehicle(pLeite[playerid][LataoLeite], pLeite[playerid][AlgId], 0.0000, -2.0000, 0.3000, 0.0000, 0.0000, 0.0000);
                pLeite[playerid][CheckVaca] = CreateDynamicCP(pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ], 1.0, 0, 0, playerid, 90.0, -1);
                pLeite[playerid][MapVaca] = CreateDynamicMapIcon(pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ], 60, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
            }

            else if(pLeite[playerid][LeiteStatus] == 4)
            {
                if(GetPVarInt(playerid, "VAPOVAC") == 0) return 1;
                DestroyDynamicObjectEx(pLeite[playerid][LataoLeite]);
                DestroyDynamic3DTextLabelEx(pLeite[playerid][TextoLeite]);
                pLeite[playerid][LeiteStatus] = 5;

                ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
                SetPlayerAttachedObject(playerid, 9, 3632, 1, 0.2119, 0.5190, -0.0379, 0.0000, 6.7000, 0.0000, 0.6860, 0.6159, 0.6409, 0xFFFFFFFF, 0xFFFFFFFF);
                SendClientMessage(playerid, 0xFFA500FF, "| FAZENDEIRO | Siga até o checkpoint para colocar o galão");
            }
        }
    }

    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(pLeite[playerid][CheckVaca] != checkpointid) return 1;
    if(pLeite[playerid][LeiteStatus] != 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está segurando o galão");
    
    DestroyDynamicCPEx(pLeite[playerid][CheckVaca]);
    DestroyDynamicMapIconEx(pLeite[playerid][MapVaca]);

    SetPVarInt(playerid, "VAPOVAC", 0);

    ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
    RemovePlayerAttachedObject(playerid, 9);
    pLeite[playerid][LeiteStatus] = 0;

    new Mensagem[128],
        ransd = random(2000-1400)+1400;
    Jogador[playerid][Dinheiro] += ransd;
    format(Mensagem, sizeof(Mensagem), "| FAZENDEIRO | Você recebeu {32CD32}$%s{FFFFFF} pela entrega de {FFA500}%dL{FFFFFF} de leite", DinheiroSeparar(ransd), random(10-5)+5);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate != PLAYER_STATE_ONFOOT) return 1;
    if(pLeite[playerid][LeiteStatus] != 4) return 1;
    if(GetPVarInt(playerid, "VAPOVAC") == 1) return 1;
    if(pLeite[playerid][AlgId] != Jogador[playerid][uVeiculo]) return 1;

    new id = pLeite[playerid][VacaID];
    if(!IsPlayerInRangeOfPoint(playerid, 50.0, pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ])) return 1;
    SetPVarInt(playerid, "VAPOVAC", 1);
    pLeite[playerid][TextoLeite] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'H'{FFFFFF} para pegar", -1, 0.0000, -4.0999, -0.9000, 10.0, INVALID_PLAYER_ID, pLeite[playerid][AlgId], 0, 0, 0, playerid, 11.0, -1);
    return 1;
}

stock VacaReg(id)
{
    new Mensagem[80];
    format(Mensagem, sizeof(Mensagem), "Vaca (ID: %d){32CD32}\nDisponível{FFFFFF}\nUse: {CCCCCC}/TirarLeite", id+1);
    UpdateDynamic3DTextLabelText(Vaca[id][VacaTexto], 0xFFA500FF, Mensagem);
    return 1; 
}

stock PegarUTL()
{
    new id = -1,
        i;
    while(id == -1)
    {
        i = random(MAX_EMPRESAS);
        if(pEmpresa[i][Colocado] == false) continue;
        if(pEmpresa[i][eInterior] != 31 && pEmpresa[i][eInterior] != 30 && pEmpresa[i][eInterior] != 1) continue;
        id = i;
    }
    return id;
}

function TirandoLeite(playerid)
{
    new id = pLeite[playerid][VacaID];
    pLeite[playerid][LeiteStatus] = 2;
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid, 1);

    new Float:Vaco[3];
    GetDynamicObjectPos(Vaca[id][VacaObjeto], Vaco[0], Vaco[1], Vaco[2]);
    GetXY(Vaco[0], Vaco[1], VacaInf[id][LeiteA], 1.5, 90.0);
    pLeite[playerid][LataoLeite] = CreateDynamicObject(3632, Vaco[0], Vaco[1], Vaco[2], 0.0, 0.0, float(random(360)), 0, 0, -1, 90.0, 90.0, -1);
    pLeite[playerid][TextoLeite] = CreateDynamic3DTextLabel("Aperte {CCCCCC}'H'{FFFFFF} para pegar", -1, Vaco[0], Vaco[1], Vaco[2], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, playerid, 11.0, -1);

    SendClientMessage(playerid, 0xFFA500FF, "| FAZENDEIRO | Coloque o latão com leite no veículo");
    return 1;
}

CMD:tirarleite(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Leiteiro")) return 0;
    if(pLeite[playerid][LeiteStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já iniciou um serviço");

    for(new i=0; i < MAX_VACAS; i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, VacaInf[i][LeiteX], VacaInf[i][LeiteY], VacaInf[i][LeiteZ])) continue;
        if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) continue;
        if(pLeite[playerid][AlgVeh] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhum veículo alugado");
        if(Vaca[i][VacaUsada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar essa vaca");
        Vaca[i][VacaUsada] = true;

        new Mensagem[90];
        format(Mensagem, sizeof(Mensagem), "Vaca (ID: %d)\n{FFA500}%s[%d]", i+1, PegarNick(playerid), playerid);
        UpdateDynamic3DTextLabelText(Vaca[i][VacaTexto], -1, Mensagem);

        TogglePlayerControllable(playerid, 0);
        ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
        pLeite[playerid][LeiteStatus] = 1;
        pLeite[playerid][VacaID] = i;
        CriarProgresso(playerid, "Tirando leite, aguarde.", "TirandoLeite", 700);
        return 1;
    }
    SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de nenhuma vaca");
    return 1;
}