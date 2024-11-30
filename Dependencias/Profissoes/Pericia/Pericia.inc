#include <YSI_Coding\y_hooks>

enum ImlCarro
{
    Float:ImlX,
    Float:ImlY,
    Float:ImlZ,
    Float:ImlA
};

enum ImlJogador
{
    bool:ImlAlugado,
    ImlVeiculo,

    //
    ImlVw,
    ImlInt,
    ImlEstado,
    ImlIcon,
    ImlCorpoID,
    ImlCasaID,
    Text3D:ImlTexto
};

new pIml[MAX_PLAYERS][ImlJogador];
new ImlPos[][ImlCarro] =
{
    {-2429.4421,515.0424,30.0508,216.3451},
    {-2425.3076,517.9287,30.0466,224.5150},
    {-2422.2075,521.6377,30.0399,226.5984},
    {-2418.7729,524.6688,30.0469,231.7397},
    {-2416.1384,528.1912,30.0405,238.3155},
    {-2414.7148,531.8973,30.0484,247.9357},
    {-2413.0654,535.6526,30.0441,257.4524},
    {-2413.1604,539.7939,30.0435,269.8408}
};

hook OnGameModeInit()
{
    CreateDynamicPickup(1239, 1, -2447.3113,523.0349,30.3500, 0, 0, -1, 90.0, -1);
    CreateDynamic3DTextLabel("Iml{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", 0xFFA500FF, -2447.3113,523.0349,30.3500, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 17.0, -1);
    
    CreateDynamicPickup(1239, 1, -2454.8911,503.9386,30.0778, 0, 0, -1, 90.0, -1);
    CreateDynamic3DTextLabel("Iml{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para entregar o corpo", 0xFFA500FF, -2454.8911,503.9386,30.0778, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 17.0, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        // Alugar
        if(IsPlayerInRangeOfPoint(playerid, 2.0, -2447.3113,523.0349,30.3500))
        {
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Perícia")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(GetPVarInt(playerid, "fdasdasdsa") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            if(pIml[playerid][ImlEstado] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você tem um serviço para concluir");
            if(pIml[playerid][ImlAlugado] == false)
            {
                new i = random(sizeof(ImlPos));
                pIml[playerid][ImlVeiculo] = CreateVehicleEx(playerid, 482, ImlPos[i][ImlX], ImlPos[i][ImlY], ImlPos[i][ImlZ], ImlPos[i][ImlA], 0, 0, 360, 0);
                MarcarPosicao(playerid, ImlPos[i][ImlX], ImlPos[i][ImlY], ImlPos[i][ImlZ]);
                VeiculoServer[pIml[playerid][ImlVeiculo]][Tranca] = 1;
                pIml[playerid][ImlAlugado] = true;
                Jogador[playerid][Trabalhando] = true;
                SetPVarInt(playerid, "fdasdasdsa", gettime()+10);
                SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Seu veículo foi colocado no pátio");
                return 1;
            }
            VerificarMarcacao(playerid);
            DestroyVehicleEx(pIml[playerid][ImlVeiculo]);
            pIml[playerid][ImlAlugado] = false;
            Jogador[playerid][Trabalhando] = false;
            SetPVarInt(playerid, "fdasdasdsa", gettime()+10);
            SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Seu veículo foi devolvido ao pátio");
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, -2454.8911, 503.9386, 30.0778))
        {
            if(pIml[playerid][ImlEstado] != 5) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Perícia")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            DestroyDynamicMapIconEx(pIml[playerid][ImlIcon]);
            ApplyAnimation(playerid, "CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
            RemovePlayerAttachedObject(playerid, 9);
            pIml[playerid][ImlEstado] = 0;
            new Mensagem[128],
                Ganho = random(1800-1300)+1300;
            Jogador[playerid][Dinheiro] += Ganho; 
            format(Mensagem, sizeof(Mensagem), "| PERÍCIA | Você recebeu {32CD32}$%s{FFFFFF} por entregar um corpo no IML", DinheiroSeparar(Ganho));
            SendClientMessage(playerid, -1, Mensagem);
        }
    }

    else if(newkeys == KEY_CTRL_BACK)
    {
        if(AtrasVeiculo(playerid, pIml[playerid][ImlVeiculo], 2.0))
        {
            if(pIml[playerid][ImlEstado] == 3)
            {
                if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
                if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
                ApplyAnimation(playerid, "CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
                RemovePlayerAttachedObject(playerid, 9);
                DestroyDynamic3DTextLabelEx(pIml[playerid][ImlTexto]);

                pIml[playerid][ImlEstado] = 4;
                pIml[playerid][ImlIcon] = CreateDynamicMapIcon(-2454.8911, 503.9386, 30.0778, 56, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
                SendClientMessage(playerid, 0xFFA500FF, "| PERÍCIA | Leve o corpo até o IML, siga o ícone no mapa");
            }
            else if(pIml[playerid][ImlEstado] == 4)
            {
                if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
                if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
                if(!IsPlayerInRangeOfPoint(playerid, 120.0, -2454.8911, 503.9386, 30.0778)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no IML");
                pIml[playerid][ImlEstado] = 5;
                DestroyDynamic3DTextLabelEx(pIml[playerid][ImlTexto]);
                ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
                SetPlayerAttachedObject(playerid, 9, 19944, 6, 0.0000, -0.0179, -0.2129, -106.5000, 0.0000, -3.4999, 0.6840, 0.7079, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
                SendClientMessage(playerid, 0xFFA500FF, "| PERÍCIA | Leve o corpo até a porta do IML");
            }
        }
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(oldstate == PLAYER_STATE_DRIVER)
    {
        if(pIml[playerid][ImlEstado] != 4) return 1;
        if(Jogador[playerid][uVeiculo] != pIml[playerid][ImlVeiculo]) return 1;
        if(!IsPlayerInRangeOfPoint(playerid, 120.0, -2454.8911, 503.9386, 30.0778)) return 1;
        pIml[playerid][ImlTexto] = CreateDynamic3DTextLabel("Perícia\nAperte {CCCCCC}'H'{FFFFFF} para pegar o corpo", -1, 0.0000, -4.0999, -0.9000, 10.0, INVALID_PLAYER_ID, pIml[playerid][ImlVeiculo], 0, 0, 0, playerid, 11.0, -1);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamicActorEx(pIml[playerid][ImlCorpoID]);
    DestroyDynamic3DTextLabelEx(pIml[playerid][ImlTexto]);
    DestroyDynamicMapIconEx(pIml[playerid][ImlIcon]);
    if(pIml[playerid][ImlAlugado] == true) DestroyVehicleEx(pIml[playerid][ImlVeiculo]);

    new fdsac[ImlJogador];
    pIml[playerid] = fdsac;
    return 1;
}

stock PegarCasaCorpo()
{
    new id = -1,
        i;
    while(id == -1)
    {
        i = random(MAX_CASAS);
        if(pCasa[i][Colocado] == false) continue; 
        if(VerificarApartamento(i)) continue;
        if(pCasa[i][cInterior] == 20) continue;
        id = i;
    }
    return id;
}

stock GetXYIml(id, &Float:x, &Float:y, Float:distance)
{
    new Float:a;
    x = pCasa[id][cPosicaoX];
    y = pCasa[id][cPosicaoY];
    a = pCasa[id][cPosicaoA];
	// a += 90;
    x += ( distance * floatsin( -a+180, degrees ));
    y += ( distance * floatcos( -a+180, degrees ));
}

CMD:pericia(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Perícia")) return 0;
    if(pIml[playerid][ImlAlugado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem um veículo do IML");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPlayerVehicleID(playerid) != pIml[playerid][ImlVeiculo]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo do IML");
    if(pIml[playerid][ImlEstado] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem um corpo para analisar, siga o mapa");
    new id = PegarCasaCorpo();
    pIml[playerid][ImlEstado] = 1;
    PericiaCorpo(playerid, id);
    return 1;
}

CMD:analisarcorpo(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Perícia")) return 0;
    if(pIml[playerid][ImlEstado] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em fazendo nenhum serviço");
    if(pIml[playerid][ImlEstado] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não precisa analisar um corpo");
    
    new Float:union[3];
    GetDynamicActorPos(pIml[playerid][ImlCorpoID], union[0], union[1], union[2]);
    if(!IsPlayerInRangeOfPoint(playerid, 4.5, union[0], union[1], union[2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe do corpo");
    new id = GetPVarInt(playerid, "PermEntrCasa");
    if(!IsVehicleInRangeOfPoint(pIml[playerid][ImlVeiculo], 70.0, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo do IML não está perto da casa");
    if(GetPlayerInterior(playerid) != pIml[playerid][ImlInt]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na casa correta.");
    if(GetPlayerVirtualWorld(playerid) != pIml[playerid][ImlVw]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na casa correta.");
    if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Saia do veículo para analisar o corpo");
    
    pIml[playerid][ImlEstado] = 2;

    TogglePlayerControllable(playerid, 0);
    ClearAnimations(playerid, 1);
    ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 1, 0);
    CriarProgresso(playerid, "Analisando corpo, aguarde.", "AnaliseCorpoF", 1000);
    return 1;
}

function AnaliseCorpoF(playerid)
{
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid, 1);
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
    SetPlayerAttachedObject(playerid, 9, 19944, 6, 0.0000, -0.0179, -0.2129, -106.5000, 0.0000, -3.4999, 0.6840, 0.7079, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);

    DestroyDynamicActorEx(pIml[playerid][ImlCorpoID]);
    DestroyDynamic3DTextLabelEx(pIml[playerid][ImlTexto]);
    DestroyDynamicMapIconEx(pIml[playerid][ImlIcon]);
    pIml[playerid][ImlTexto] = CreateDynamic3DTextLabel("IML\nAperte {CCCCCC}'H'{FFFFFF} para colocar o corpo", -1, 0.0000, -4.0999, -0.9000, 10.0, INVALID_PLAYER_ID, pIml[playerid][ImlVeiculo], 0, 0, 0, playerid, 11.0, -1);

    SetPVarInt(playerid, "PermEntrCasa", 0);

    pIml[playerid][ImlEstado] = 3;
    SendClientMessage(playerid, 0xFFA500FF, "| PERÍCIA | Coloque o corpo dentro do veículo IML");
    return 1;
}

stock PericiaCorpo(playerid, id)
{
    new Mensagem[228],
        Float:Ghas[3];

    pIml[playerid][ImlVw] = PegarVirtualCasa(id);
    pIml[playerid][ImlInt] = PegarInteriorCasa(id);

    new ia = pCasa[id][cInterior];
    ia -= 1;
    switch(ia)
    {
        case 0:
        {
            switch(random(1))
            {
                case 0: {Ghas[0] = 2228.7012; Ghas[1] = -1112.9530; Ghas[2] = 1050.8828;}
                case 1: {Ghas[0] = 2233.1072; Ghas[1] = -1108.3606; Ghas[2] = 1050.8828;}
            }
        }
        case 1:
        {
            switch(random(2))
            {
                case 0: {Ghas[0] = 221.6758; Ghas[1] = 1143.3723; Ghas[2] = 1082.6094;}
                case 1: {Ghas[0] = 219.7218; Ghas[1] = 1157.7372; Ghas[2] = 1082.6094;}
                case 2: {Ghas[0] = 226.1266; Ghas[1] = 1150.8297; Ghas[2] = 1082.6168;}
            }
        }
        case 2: {Ghas[0] = 221.6758; Ghas[1] = 1143.3723; Ghas[2] = 1082.6094;}
        case 3:
        {
            switch(random(3))
            {
                case 0: {Ghas[0] = -68.7776; Ghas[1] = 1353.9952; Ghas[2] = 1080.2109;}
                case 1: {Ghas[0] = -64.2439; Ghas[1] = 1355.1172; Ghas[2] = 1080.2109;}
                case 2: {Ghas[0] = -68.9669; Ghas[1] = 1363.1284; Ghas[2] = 1080.2109;}
                case 3: {Ghas[0] = -60.3416; Ghas[1] = 1364.5200; Ghas[2] = 1080.2109;}
            }    
        }
        case 4: {Ghas[0] = 223.1924; Ghas[1] = 1288.7908; Ghas[2] = 1082.1328;}
        case 5:
        {
            switch(random(2))
            {
                case 0: {Ghas[0] = 223.2730; Ghas[1] = 1240.0280; Ghas[2] = 1082.1406;}
                case 1: {Ghas[0] = 230.5377; Ghas[1] = 1245.8507; Ghas[2] = 1082.1406;}
                case 2: {Ghas[0] = 219.5434; Ghas[1] = 1248.2205; Ghas[2] = 1082.1406;}
            }    
        }
        case 6:
        {
            switch(random(2))
            {
                case 0: {Ghas[0] = 2464.9878; Ghas[1] = -1698.2195; Ghas[2] = 1013.5078;}
                case 1: {Ghas[0] = 2451.7192; Ghas[1] = -1700.6771; Ghas[2] = 1013.5078;}
                case 2: {Ghas[0] = 2449.8025; Ghas[1] = -1690.8329; Ghas[2] = 1013.5078;}
            }    
        }
        case 7:
        {
            switch(random(3))
            {
                case 0: {Ghas[0] = -42.5626; Ghas[1] = 1407.6908; Ghas[2] = 1084.4297;}
                case 1: {Ghas[0] = -49.5589; Ghas[1] = 1408.9137; Ghas[2] = 1084.4297;}
                case 2: {Ghas[0] = -49.9080; Ghas[1] = 1399.1521; Ghas[2] = 1084.4297;}
                case 3: {Ghas[0] = -37.9304; Ghas[1] = 1409.1218; Ghas[2] = 1084.4370;}
            }    
        }
        case 8:
        {
            switch(random(5))
            {
                case 0: {Ghas[0] = 374.6964; Ghas[1] = 1417.3578; Ghas[2] = 1081.3281;}
                case 1: {Ghas[0] = 372.7795; Ghas[1] = 1410.9966; Ghas[2] = 1081.3359;}
                case 2: {Ghas[0] = 366.3726; Ghas[1] = 1423.0924; Ghas[2] = 1081.3359;}
                case 3: {Ghas[0] = 367.7570; Ghas[1] = 1430.3564; Ghas[2] = 1081.3359;}
                case 4: {Ghas[0] = 364.4746; Ghas[1] = 1410.1863; Ghas[2] = 1081.3281;}
                case 5: {Ghas[0] = 360.1760; Ghas[1] = 1415.2396; Ghas[2] = 1081.3281;}
            }
        }
        case 9:
        {
            switch(random(3))
            {
                case 0: {Ghas[0] = 378.3858; Ghas[1] = 1471.6534; Ghas[2] = 1080.1875;}
                case 1: {Ghas[0] = 373.6648; Ghas[1] = 1463.1564; Ghas[2] = 1080.1875;}
                case 2: {Ghas[0] = 381.5901; Ghas[1] = 1465.7842; Ghas[2] = 1080.1949;}
                case 3: {Ghas[0] = 381.8228; Ghas[1] = 1456.9167; Ghas[2] = 1080.1875;}
            }    
        }
        case 10:
        {
            switch(random(5))
            {
                case 0: {Ghas[0] = 295.4719; Ghas[1] = 1477.2195; Ghas[2] = 1080.2578;}
                case 1: {Ghas[0] = 293.8873; Ghas[1] = 1486.7832; Ghas[2] = 1080.2578;}
                case 2: {Ghas[0] = 300.3886; Ghas[1] = 1481.8552; Ghas[2] = 1080.2578;}
                case 3: {Ghas[0] = 301.8743; Ghas[1] = 1473.9313; Ghas[2] = 1080.2578;}
                case 4: {Ghas[0] = 291.0404; Ghas[1] = 1474.7500; Ghas[2] = 1080.2578;}
                case 5: {Ghas[0] = 291.9265; Ghas[1] = 1480.8800; Ghas[2] = 1080.2578;}
            }  
        }
        case 11:
        {
            switch(random(3))
            {
                case 0: {Ghas[0] = 260.6718; Ghas[1] = 1239.9917; Ghas[2] = 1084.2578;}
                case 1: {Ghas[0] = 262.0445; Ghas[1] = 1246.6512; Ghas[2] = 1084.2578;}
                case 2: {Ghas[0] = 257.2203; Ghas[1] = 1248.6539; Ghas[2] = 1084.2578;}
            }
        }
        case 12:
        {
            switch(random(3))
            {
                case 0: {Ghas[0] = 261.0132; Ghas[1] = 1286.7327; Ghas[2] = 1080.2578;}
                case 1: {Ghas[0] = 264.7498; Ghas[1] = 1292.8019; Ghas[2] = 1080.2578;}
                case 2: {Ghas[0] = 256.3203; Ghas[1] = 1289.4409; Ghas[2] = 1080.2578;}
                case 3: {Ghas[0] = 264.9660; Ghas[1] = 1287.0803; Ghas[2] = 1080.2578;}
            } 
        }
        case 13:
        {
            switch(random(3))
            {
                case 0: {Ghas[0] = 22.8048; Ghas[1] = 1406.9214; Ghas[2] = 1084.4297;}
                case 1: {Ghas[0] = 30.0669; Ghas[1] = 1412.9384; Ghas[2] = 1084.4297;}
                case 2: {Ghas[0] = 23.9936; Ghas[1] = 1416.9617; Ghas[2] = 1084.4297;}
                case 3: {Ghas[0] = 18.4249; Ghas[1] = 1406.4684; Ghas[2] = 1084.4297;}
            }
        }
        case 14:
        {
            switch(random(5))
            {
                case 0: {Ghas[0] = 447.0479; Ghas[1] = 1398.8121; Ghas[2] = 1084.3120;}
                case 1: {Ghas[0] = 452.2804; Ghas[1] = 1407.9187; Ghas[2] = 1084.3080;}
                case 2: {Ghas[0] = 454.5517; Ghas[1] = 1414.5297; Ghas[2] = 1084.3080;}
                case 3: {Ghas[0] = 440.1273; Ghas[1] = 1408.8141; Ghas[2] = 1084.3047;}
                case 4: {Ghas[0] = 440.7053; Ghas[1] = 1401.4294; Ghas[2] = 1084.3047;}
                case 5: {Ghas[0] = 453.9315; Ghas[1] = 1400.5760; Ghas[2] = 1084.3080;}
            }  
        }
        case 15:
        {
            switch(random(5))
            {
                case 0: {Ghas[0] = 20.2588; Ghas[1] = 1341.7863; Ghas[2] = 1084.3750;}
                case 1: {Ghas[0] = 31.6529; Ghas[1] = 1349.1541; Ghas[2] = 1084.3750;}
                case 2: {Ghas[0] = 22.5900; Ghas[1] = 1349.1074; Ghas[2] = 1084.3750;}
                case 3: {Ghas[0] = 26.0718; Ghas[1] = 1344.8218; Ghas[2] = 1088.8750;}
                case 4: {Ghas[0] = 34.2044; Ghas[1] = 1343.7075; Ghas[2] = 1088.8750;}
                case 5: {Ghas[0] = 27.4587; Ghas[1] = 1348.9800; Ghas[2] = 1088.8750;}
            }   
        }
        case 16:
        {
            switch(random(6))
            {
                case 0: {Ghas[0] = 228.4110; Ghas[1] = 1110.5303; Ghas[2] = 1080.9922;}
                case 1: {Ghas[0] = 237.6883; Ghas[1] = 1117.7755; Ghas[2] = 1080.9922;}
                case 2: {Ghas[0] = 238.5109; Ghas[1] = 1112.4213; Ghas[2] = 1080.9922;}
                case 3: {Ghas[0] = 244.6955; Ghas[1] = 1114.9526; Ghas[2] = 1080.9995;}
                case 4: {Ghas[0] = 245.0089; Ghas[1] = 1109.5623; Ghas[2] = 1080.9922;}
                case 5: {Ghas[0] = 241.1671; Ghas[1] = 1118.8822; Ghas[2] = 1084.9922;}
                case 6: {Ghas[0] = 233.7272; Ghas[1] = 1113.3719; Ghas[2] = 1085.0071;}
            }    
        }
        case 17:
        {
            switch(random(4))
            {
                case 0: {Ghas[0] = 234.2693; Ghas[1] = 1069.1487; Ghas[2] = 1084.1937;}
                case 1: {Ghas[0] = 226.8258; Ghas[1] = 1079.8508; Ghas[2] = 1087.8185;}
                case 2: {Ghas[0] = 244.9411; Ghas[1] = 1080.3870; Ghas[2] = 1084.1875;}
                case 3: {Ghas[0] = 233.7479; Ghas[1] = 1079.9851; Ghas[2] = 1084.2415;}
            }    
        }
        case 18:
        {
            switch(random(4))
            {
                case 0: {Ghas[0] = 140.5047; Ghas[1] = 1368.6853; Ghas[2] = 1083.8633;}
                case 1: {Ghas[0] = 140.1016; Ghas[1] = 1378.8031; Ghas[2] = 1088.3672;}
                case 2: {Ghas[0] = 150.2408; Ghas[1] = 1371.2889; Ghas[2] = 1083.8594;}
                case 3: {Ghas[0] = 150.4261; Ghas[1] = 1382.0082; Ghas[2] = 1083.8594;}
                case 4: {Ghas[0] = 139.8133; Ghas[1] = 1383.8186; Ghas[2] = 1083.8672;}
            }   
        }
    }

    SetPVarInt(playerid, "PermEntrCasa", id);
    pIml[playerid][ImlCorpoID] = CreateDynamicActor(random(299), Ghas[0], Ghas[1], Ghas[2], float(random(360)), 1, 100.0, pIml[playerid][ImlVw], pIml[playerid][ImlInt], -1, 100.0, -1, 0);
    ApplyDynamicActorAnimation(pIml[playerid][ImlCorpoID], "PED", "KO_skid_front", 4.1, 0, 1, 1, 1, 0);
    pIml[playerid][ImlIcon] = CreateDynamicMapIcon(pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ], 19, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
    format(Mensagem, sizeof(Mensagem), "Morto(a)\n{FFFFFF}Aguardando o(a) agente {FFA500}%s[%d]{FFFFFF} da Perícia", PegarNick(playerid), playerid);
    pIml[playerid][ImlTexto] = CreateDynamic3DTextLabel(Mensagem, 0xB22222FF, Ghas[0], Ghas[1], Ghas[2], 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, pIml[playerid][ImlVw], pIml[playerid][ImlInt], -1, 17.0, -1);
    format(Mensagem, sizeof(Mensagem), "| PERÍCIA | Você precisa ir até {FFA500}%s{FFFFFF} para analisar um corpo dentro de uma casa id %d, siga o ícone no mapa", AreaNome(pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ]), id);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}