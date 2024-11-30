#include <YSI_Coding\y_hooks>

enum SpawnOnibus
{
    Float:OnibusX,
    Float:OnibusY,
    Float:OnibusZ,
    Float:OnibusA
};

enum MotoristaOnibus
{
    // Onibus
    bool:AlugouOnibus,
    OnibusID,
    DelayOnibusAlugar,

    // Trajeto da rota
    bool:IniciouRota,
    bool:FinalR,
    CidadeEscolhida[70],
    eRotaID,
    eRotaIDEx,
    RotaCheck,
    QuantidadeNpc,
    TotalPassageiros,
    TotalDinheiro,
    PassageirosQueDeram
};

enum NpcsParada
{
    bool:NpcConectado,
    oNpc
};

new ArenasBus[4];
new pNpc[MAX_PLAYERS][6][NpcsParada];
new pOnibus[MAX_PLAYERS][MotoristaOnibus];
new SpawnCoach[][SpawnOnibus] =
{
    {1724.0394,723.2827,10.9536,0.8714},
    {1718.4620,723.5585,10.9536,359.6322},
    {1712.9760,723.1616,10.9566,358.9926},
    {1701.8375,724.2068,10.9538,1.8226},
    {1696.2755,723.6985,10.9536,0.5497},
    {1690.7628,723.6566,10.9537,0.6187},
    {1680.4054,722.3046,10.9537,0.2015},
    {1675.0824,722.0704,10.9536,359.8809},
    {1669.2917,722.0087,10.9556,0.1796},
    {1659.3856,723.1297,10.9537,359.6600},
    {1653.8855,722.6163,10.9536,0.9085},
    {1648.2069,723.1390,10.9537,0.8672},
    {1637.8580,723.1032,10.9536,359.5387},
    {1632.3651,722.7858,10.9536,359.5783},
    {1627.1261,722.6746,10.9537,359.5303},
    {1626.5236,686.1575,10.9537,1.1147},
    {1632.1038,685.8631,10.9536,359.9686},
    {1637.3541,687.2780,10.9513,0.0105},
    {1659.6685,686.7094,10.9536,359.8409},
    {1670.0062,686.8564,10.9536,0.1320},
    {1675.2266,686.3848,10.9536,359.2870},
    {1680.7028,686.8726,10.9536,359.4186},
    {1691.9941,687.2335,10.9528,359.2446},
    {1697.3273,687.4324,10.9535,359.8039},
    {1702.9031,686.2755,10.9539,359.6564},
    {1713.4139,686.6240,10.9536,359.5678},
    {1719.0179,686.3631,10.9536,358.9909},
    {1724.6953,685.9780,10.9535,0.6679}
};

hook OnGameModeInit()
{
    CreateDynamicPickup(1239, 1, 1588.0190,682.2128,10.8203, 0, 0, -1, 90.0); //Alugar Ônibus
    CreateDynamic3DTextLabel("{00FF00}Garagem\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, 1588.0190,682.2128,10.8203, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 95.0);

    ArenasBus[0] = CreateDynamicRectangle(1727.7520,-1859.2991, 1805.9897,-1850.3971, 0, 0, -1); // Los Santos
    ArenasBus[1] = CreateDynamicRectangle(-1986.9456,99.5749, -2000.2328,198.1571, 0, 0, -1); // San Fierro
    ArenasBus[2] = CreateDynamicRectangle(2798.2183,1258.3126, 2851.2307,1377.2244, 0, 0, -1); // Las Venturas
    ArenasBus[3] = CreateDynamicRectangle(1578.2296,782.2898, 1756.9813,663.7387, 0, 0, -1); // Garagem
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{  
    DestroyDynamicRaceCPEx(pOnibus[playerid][RotaCheck]);
    if(pOnibus[playerid][AlugouOnibus] == true){
        RemoverNPC(playerid);
        DestroyVehicleEx(pOnibus[playerid][OnibusID]);
    }

    new Configg[MotoristaOnibus];
    pOnibus[playerid] = Configg;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1588.0190,682.2128,10.8203)) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
    if(strcmp(Jogador[playerid][Profissao], "Motorista de Ônibus")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pOnibus[playerid][DelayOnibusAlugar] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco");
    if(pOnibus[playerid][IniciouRota] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem rotas para acabar!");
    if(pOnibus[playerid][AlugouOnibus] == false)
    {
        if(Jogador[playerid][CarteiraD] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar um ônibus ( Habilitação: D )");
        new id = random(sizeof(SpawnCoach));
        pOnibus[playerid][OnibusID] = CreateVehicleEx(playerid, 437, SpawnCoach[id][OnibusX], SpawnCoach[id][OnibusY], SpawnCoach[id][OnibusZ], SpawnCoach[id][OnibusA], 1, 211, -1, 0);
        VeiculoServer[pOnibus[playerid][OnibusID]][Tranca] = 1;
        VeiculoServer[pOnibus[playerid][OnibusID]][Gasolina] = 300.0;
        pOnibus[playerid][DelayOnibusAlugar] = gettime()+10;
        pOnibus[playerid][AlugouOnibus] = true;
        Jogador[playerid][Trabalhando] = true;
        MarcarPosicao(playerid, SpawnCoach[id][OnibusX], SpawnCoach[id][OnibusY], SpawnCoach[id][OnibusZ]);
        SendClientMessage(playerid, 0xFFFF00FF, "| GARAGEM | Seu veículo foi colocado na garagem!");
        return 1;
    }
    DestroyVehicleEx(pOnibus[playerid][OnibusID]);
    pOnibus[playerid][AlugouOnibus] = false;
    Jogador[playerid][Trabalhando] = false;
    pOnibus[playerid][DelayOnibusAlugar] = gettime()+10;
    VerificarMarcacao(playerid);
    SendClientMessage(playerid, 0xFFFF00FF, "| GARAGEM | Você devolveu o ônibus!");
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    // if(strcmp(Jogador[playerid][Profissao], "Motorista de Ônibus")) return 1;
    if(areaid == ArenasBus[0]) MostrarMensagemBaixo(playerid, "Terminal_de_~r~Los Santos");
    else if(areaid == ArenasBus[1]) MostrarMensagemBaixo(playerid, "Terminal_de_~r~San Fierro");
    else if(areaid == ArenasBus[2]) MostrarMensagemBaixo(playerid, "Terminal_de_~r~Las Venturas");
    else if(areaid == ArenasBus[3]) MostrarMensagemBaixo(playerid, "Garagem_de_~r~Las Venturas");
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{   
    // if(strcmp(Jogador[playerid][Profissao], "Motorista de Ônibus")) return 1;
    if(areaid == ArenasBus[0] || areaid == ArenasBus[1] || areaid == ArenasBus[2] || areaid == ArenasBus[3]){
        OcultarMensagemBaixo(playerid);
    }
    return 1;
}

Dialog:SelecionarRotaJogador(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[2000];

    switch(listitem)
    {
        case 0: format(pOnibus[playerid][CidadeEscolhida], 70, "Los Santos");
        case 1: format(pOnibus[playerid][CidadeEscolhida], 70, "San Fierro");
        case 2: format(pOnibus[playerid][CidadeEscolhida], 70, "Las Venturas");
    }

    strcat(Dialog, "ID\tLocal\tStatus\n");
    for(new i=0; i < MAX_ROTAS; i++)
    {
        if(oRota[i][0][RotaAtiva] == false) continue;
        if(strcmp(oRota[i][0][pDestino], pOnibus[playerid][CidadeEscolhida])) continue;
        strcatEx(Dialog, "{FFFFFF}%d.\t{FE2E2E}%s\t{00FF00}Liberada\n", i, oRota[i][0][NomeDaRota]);
    }
    Dialog_Show(playerid, EscolhendoRotaOnb, DIALOG_STYLE_TABLIST_HEADERS, pOnibus[playerid][CidadeEscolhida], Dialog, "Selecionar", "Fechar");
    return 0;
}

Dialog:EscolhendoRotaOnb(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new RotaNAN = 0;
    for(new i=0; i < MAX_ROTAS; i++)
    {
        if(oRota[i][0][RotaAtiva] == false) continue;
        if(strcmp(oRota[i][0][pDestino], pOnibus[playerid][CidadeEscolhida])) continue;
        if(listitem != RotaNAN){
            RotaNAN++;
            continue;
        }

        // Reset
        pOnibus[playerid][IniciouRota] = true;
        pOnibus[playerid][eRotaID] = i;
        pOnibus[playerid][eRotaIDEx] = 0;

        // String
        new Mensagem[200];

        // Mensagem
        format(Mensagem, sizeof(Mensagem), "| TRANSPORTE | Você iniciou uma rota ( {FF0000}%s - %s{FFFFFF} ), siga o trajeto", pOnibus[playerid][CidadeEscolhida], oRota[i][0][NomeDaRota]);
        SendClientMessage(playerid, -1, Mensagem);

        // Criar CheckPoint
        AdicionarCheck(playerid, i, 0);
        AdicionarNPC(playerid, i, 0);
        break;
    }
    return 0;
}

CMD:rotas(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Motorista de Ônibus")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pOnibus[playerid][AlugouOnibus] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não alugou um ônibus");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo!");
    if(GetPlayerVehicleID(playerid) != pOnibus[playerid][OnibusID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu ônibus");
    if(pOnibus[playerid][IniciouRota] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já iniciou uma rota");

    new Dialog[128];
    strcat(Dialog, "Los Santos\n");
    strcat(Dialog, "San Fierro\n");
    strcat(Dialog, "Las Venturas");
    Dialog_Show(playerid, SelecionarRotaJogador, DIALOG_STYLE_TABLIST, "{FF0000}Cidade", Dialog, "Selecionar", "Fechar");
    return 1;
}


hook OnPlayerEnterDynRaceCP(playerid, checkpointid)
{
    if(checkpointid != pOnibus[playerid][RotaCheck]) return 1;
    if(pOnibus[playerid][FinalR] == true)
    {
        pOnibus[playerid][FinalR] = false;
        RemoverNPC(playerid);
        DestroyDynamicRaceCPEx(pOnibus[playerid][RotaCheck]);
        new Mensagem[200],
            Gerar = random(1500-1000)+1000;

        Jogador[playerid][Dinheiro] += Gerar;
        format(Mensagem, sizeof(Mensagem), "| TERMINAL | Você pegou {FF4500}%d{FFFFFF} passageiros e recebeu {32CD32}$%s{FFFFFF} + {32CD32}$%s", pOnibus[playerid][TotalPassageiros], DinheiroSeparar(pOnibus[playerid][TotalDinheiro]), DinheiroSeparar(Gerar));
        SendClientMessage(playerid, -1, Mensagem);

        pOnibus[playerid][TotalPassageiros] = 0;
        pOnibus[playerid][TotalDinheiro] = 0;
        pOnibus[playerid][IniciouRota] = false;
        return 1;
    }

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo!");
    if(GetPlayerVehicleID(playerid) != pOnibus[playerid][OnibusID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu ônibus");
    TogglePlayerControllable(playerid, 0);
    MostrarEmbarque(playerid);
    SetTimerEx("OnibusDelay", 4000, false, "d", playerid);
    return 1;
}

function OnibusDelay(playerid)
{
    DestroyDynamicRaceCPEx(pOnibus[playerid][RotaCheck]); // Remover CheckPoint
    TogglePlayerControllable(playerid, 1);
    OcultarEmbarque(playerid); 
    RemoverNPC(playerid);
    pOnibus[playerid][eRotaIDEx]++;
    new i = pOnibus[playerid][eRotaID],
        h = pOnibus[playerid][eRotaIDEx],
        Mensagem[200];
    new ParadaValor = random(90-70)+70;
    pOnibus[playerid][TotalDinheiro] += ParadaValor;

    Jogador[playerid][Dinheiro] += ParadaValor;
    format(Mensagem, sizeof(Mensagem), "| PARADA | Você pegou {FF8C00}%d{FFFFFF} passageiros e recebeu {32CD32}$%d{FFFFFF}, siga o próximo ponto", pOnibus[playerid][PassageirosQueDeram], ParadaValor);
    SendClientMessage(playerid, -1, Mensagem); 

    if(VerificarRota(i, h) == -1) // Não há mais rotas, retornar até a hq
    {
        format(Mensagem, sizeof(Mensagem), "| PARADA | Você já passou em todas as paradas, volte para o terminal de {FF4500}%s", oRota[i][0][pDestino]);
        SendClientMessage(playerid, -1, Mensagem);
        pOnibus[playerid][FinalR] = true;
        if(!strcmp(oRota[i][0][pDestino], "Los Santos")) pOnibus[playerid][RotaCheck] = CreateDynamicRaceCP(1, 1760.2894, -1857.1091, 13.4141, 0.0, 0.0, 0.0, 2.0, 0, 0, playerid, 99999.0);
        else if(!strcmp(oRota[i][0][pDestino], "San Fierro")) pOnibus[playerid][RotaCheck] = CreateDynamicRaceCP(1, -1991.2837, 146.6833, 27.5391, 0.0, 0.0, 0.0, 2.0, 0, 0, playerid, 99999.0);
        else if(!strcmp(oRota[i][0][pDestino], "Las Venturas")) pOnibus[playerid][RotaCheck] = CreateDynamicRaceCP(1, 2831.5142,1289.0065,10.7745, 0.0, 0.0, 0.0, 2.0, 0, 0, playerid, 99999.0);
        return 1;
    }
    // format(Mensagem, sizeof(Mensagem), "| PARADA | Você precisa parar em mais {00BFFF}%d{FFFFFF} parada(s)", VerificarRota(i, h));
    // SendClientMessage(playerid, -1, Mensagem); 

    AdicionarCheck(playerid, i, VerificarRota(i, h));
    AdicionarNPC(playerid, i, VerificarRota(i, h));
    return 1;
}

function AdicionarCheck(playerid, iex, ex)
{
    new Float:a, 
        Float:x,
        Float:y,
        Float:z,
        Float:NA[2];
    new id = oRota[iex][ex][ParadaSel];
    new obid = oParada[id][ObjetoParada];
    new Distance = oParada[id][RangeParada];
    new NovaDistance = -negativo(Distance); //timeleft *= -1; <-Solução

    GetDynamicObjectPos(obid, x, y, z);
	GetDynamicObjectRot(obid, NA[0], NA[1], a);

	a+=90;
    x += (NovaDistance * floatsin(-a+180, degrees));
    y += (NovaDistance * floatcos(-a+180, degrees)); 

    pOnibus[playerid][RotaCheck] = CreateDynamicRaceCP(2, x, y, z, 0.0, 0.0, 0.0, 2.0, 0, 0, playerid, 99999.0);
    return 1;
}

stock GetXYParada(id, &Float:x, &Float:y, Float:distance)
{
    new Float:a;
    new Float:NA[2];
    GetDynamicObjectPos(id, x, y, a);
	GetDynamicObjectRot(id, NA[0], NA[1], a);
	a+=90;
    x += ( distance * floatsin( -a+180, degrees ));
    y += ( distance * floatcos( -a+180, degrees ));
}

stock RemoverNPC(playerid)
{  
    for(new i=0; i < 6; i++)
    {
        if(pNpc[playerid][i][NpcConectado] == false) continue;
        DestroyDynamicActorEx(pNpc[playerid][i][oNpc]);
        pNpc[playerid][i][NpcConectado] = false;
    }
    return 1;
}

stock AdicionarNPC(playerid, id, exid)
{
    // Gerar um número de NPC aleatorios
    new Randomico = random(6-2)+2;
    pOnibus[playerid][PassageirosQueDeram] = Randomico;
    pOnibus[playerid][TotalPassageiros] += Randomico;

    // Dependencias
    new idx = oRota[id][exid][ParadaSel];
    new obp = oParada[idx][ObjetoParada];

    for(new i=0; i < Randomico; i++)
    {
        // Salvar Posição
        new Float:Fds[6];

        // Posição / Camera
        GetDynamicObjectPos(obp, Fds[0], Fds[1], Fds[2]);
        GetDynamicObjectRot(obp, Fds[3], Fds[4], Fds[5]);


        // Criação do NPC ( Actor )
        pNpc[playerid][i][oNpc] = CreateDynamicActor(random(271), Fds[0], Fds[1], Fds[2], random(360), 1, 100.0, 0, 0, -1, 250.0);
        pNpc[playerid][i][NpcConectado] = true;


        // Posição Z Angle da Parada + Random de Distancia ( MAX: 3 )
        new Float:X;
        new Float:Y;
        GetXYParada(obp, X, Y, -float(random(2-0)+0));


        // Adicionar uma posição aleatoria nos NPCs ( Aviso: Pode nascer bugado atrás da parada )
        switch(random(3))
        {
            case 0: SetDynamicActorPos(pNpc[playerid][i][oNpc], X-random(2), Y+random(3), Fds[2]);
            case 1: SetDynamicActorPos(pNpc[playerid][i][oNpc], X-random(3), Y-random(2), Fds[2]);
            case 2: SetDynamicActorPos(pNpc[playerid][i][oNpc], X+random(2), Y+random(2), Fds[2]);
            case 3: SetDynamicActorPos(pNpc[playerid][i][oNpc], X-random(3), Y+random(3), Fds[2]);
        }
    }
    return 1;
}