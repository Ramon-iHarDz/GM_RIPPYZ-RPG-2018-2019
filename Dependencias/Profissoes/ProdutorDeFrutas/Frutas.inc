#include <YSI_Coding\y_hooks>

enum ArvoresFrutas
{
    Float:FrutaX,
    Float:FrutaY,
    Float:FrutaZ,
    bool:FrutaQuebrada,
    Text3D:ArvoreFrutaTexto,
    ArvoreFrutaID
};

enum JogadorFruteiro
{
    FruteiroStt,
    FruteiroID,

    // Info
    Text3D:FruteiroTexto,
    FruteiroMap,
    FruteiroCheck,
    FruteiroBox,
    FruteiroBoxType
};

new FrutasEx[][ArvoresFrutas] =
{
    {-104.00170, 143.19020, 2.0165},
    {-105.86970, 137.65750, 2.0165},
    {-127.68547, 151.69502, 2.0165},
    {-107.53463, 132.03026, 2.0165},
    {-109.30923, 126.43640, 2.0165},
    {-111.21788, 120.68318, 2.0165},
    {-113.22158, 115.05834, 2.0165},
    {-115.34058, 109.10980, 2.0165},
    {-116.87210, 103.40289, 2.0165},
    {-118.69667, 98.42592, 2.0165},
    {-143.13377, 106.12638, 2.0165},
    {-141.07997, 111.83430, 2.0165},
    {-139.11456, 117.80485, 2.0165},
    {-129.69348, 146.23830, 2.0165},
    {-135.08566, 129.19203, 2.0165},
    {-137.11258, 123.73814, 2.0165},
    {-133.55516, 134.48048, 2.0165},
    {-131.58273, 139.81833, 2.0165},
    {-127.04816, 100.19282, 2.0165},
    {-124.99402, 105.90607, 2.0165},
    {-123.02684, 111.88140, 2.0165},
    {-121.02132, 117.81889, 2.0165},
    {-118.98939, 123.27635, 2.0165},
    {-117.45230, 128.56790, 2.0165},
    {-115.47159, 133.90813, 2.0165},
    {-113.57255, 140.33002, 2.0165},
    {-111.55304, 145.78790, 2.0165},
    {-120.23337, 148.69286, 2.0165},
    {-122.16692, 143.20619, 2.0165},
    {-123.98088, 136.75584, 2.0165},
    {-125.87732, 131.38742, 2.0165},
    {-127.33101, 126.06796, 2.0165},
    {-129.28036, 120.58286, 2.0165},
    {-131.20409, 114.61800, 2.0165},
    {-133.09032, 108.61558, 2.0165},
    {-135.06429, 102.87551, 2.0165}
};

new Frutas[sizeof(FrutasEx)][ArvoresFrutas];
new pFrutas[MAX_PLAYERS][JogadorFruteiro];

hook OnGameModeInit()
{
    new Mensagem[95];
    for(new i=0; i < sizeof(FrutasEx); i++){
        format(Mensagem, sizeof(Mensagem), "Frutífera ( ID: %d ){FFFFFF}\nAperte {CCCCCC}'N'{FFFFFF} para derrubar e colher os frutos", i+1);
        Frutas[i][ArvoreFrutaID] = CreateDynamicObject(792, FrutasEx[i][FrutaX], FrutasEx[i][FrutaY], FrutasEx[i][FrutaZ], 0.0, 0.0, float(random(360)), 0, 0, -1, 150.0, 150.0, -1);
        Frutas[i][ArvoreFrutaTexto] = CreateDynamic3DTextLabel(Mensagem, 0xFFA500FF, FrutasEx[i][FrutaX], FrutasEx[i][FrutaY], FrutasEx[i][FrutaZ]+2, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 11.0, -1);       
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamic3DTextLabelEx(pFrutas[playerid][FruteiroTexto]);
    DestroyDynamicCPEx(pFrutas[playerid][FruteiroCheck]);
    DestroyDynamicMapIconEx(pFrutas[playerid][FruteiroMap]);
    DestroyDynamicObjectEx(pFrutas[playerid][FruteiroBox]);

    if(pFrutas[playerid][FruteiroStt] == 1){
        new id = pFrutas[playerid][FruteiroID];
        Frutas[id][FrutaQuebrada] = false;
    }

    new dasda[JogadorFruteiro];
    pFrutas[playerid] = dasda;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_NO)
    {
        for(new i=0; i < sizeof(FrutasEx); i++)
        {
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, FrutasEx[i][FrutaX], FrutasEx[i][FrutaY], FrutasEx[i][FrutaZ])) continue;
            if(strcmp(Jogador[playerid][Profissao], "Fruteiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(Frutas[i][FrutaQuebrada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode derrubar esse árvore");
            if(pFrutas[playerid][FruteiroStt] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem um processo para fazer.");
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;

            Frutas[i][FrutaQuebrada] = true;
            pFrutas[playerid][FruteiroStt] = 1;
            pFrutas[playerid][FruteiroID] = i;

            TogglePlayerControllable(playerid, 0);

            new Mensagem[60];
            format(Mensagem, sizeof(Mensagem), "%s[%d] está derrubando essa árvore", PegarNick(playerid), playerid);
            pFrutas[playerid][FruteiroTexto] = CreateDynamic3DTextLabel(Mensagem, 0xFFFF0070, FrutasEx[i][FrutaX], FrutasEx[i][FrutaY], FrutasEx[i][FrutaZ]+3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 11.0, -1);

            CriarProgresso(playerid, "Derrubando Frutífera, aguarde.", "FrutiferaDerrubando", 600);
            break;
        }
    }
    return 1;
}

function FrutiferaDerrubando(playerid)
{
    new id = pFrutas[playerid][FruteiroID],
        Mensagem[65];
    format(Mensagem, sizeof(Mensagem), "Frutífera ( ID: %d ){FFFFFF}\nVoltando em {FFA500}04:00", id+1);

    TogglePlayerControllable(playerid, 1);

    pFrutas[playerid][FruteiroStt] = 2;
    DestroyDynamic3DTextLabelEx(pFrutas[playerid][FruteiroTexto]);
    DestroyDynamicObjectEx(Frutas[id][ArvoreFrutaID]);

    switch(random(2))
    {
        case 0: pFrutas[playerid][FruteiroBoxType] = 19636;
        case 1: pFrutas[playerid][FruteiroBoxType] = 19637;
        case 2: pFrutas[playerid][FruteiroBoxType] = 19638;
    }

    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
    SetPlayerAttachedObject(playerid, 8, pFrutas[playerid][FruteiroBoxType], 1, 0.0290, 0.4439, 0.0039, -82.8999, 82.1000, -2.7000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);

    pFrutas[playerid][FruteiroMap] = CreateDynamicMapIcon(-101.8091,-99.6305,3.1172, 56, -1, 0, 0, playerid, 9999.0, MAPICON_GLOBAL, -1);
    pFrutas[playerid][FruteiroCheck] = CreateDynamicCP(-101.8091,-99.6305,3.1172, 1.0, 0, 0, playerid, 30.0, -1);

    UpdateDynamic3DTextLabelText(Frutas[id][ArvoreFrutaTexto], 0xFFA500FF, Mensagem);
    SetTimerEx("RegenerarFruteira", 1000, false, "dd", id, 240);
    SendClientMessage(playerid, 0xFFFF00FF, "| FRUTEIRO | Você precisa levar caixa até o local marcado no mapa");
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pFrutas[playerid][FruteiroCheck]) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    switch(pFrutas[playerid][FruteiroStt])
    {
        case 2:
        {
            DestroyDynamicCPEx(pFrutas[playerid][FruteiroCheck]);
            DestroyDynamicMapIconEx(pFrutas[playerid][FruteiroMap]);
            pFrutas[playerid][FruteiroStt] = 3;
            RemovePlayerAttachedObject(playerid, 8);
            ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);

            pFrutas[playerid][FruteiroBox] = CreateDynamicObject(pFrutas[playerid][FruteiroBoxType], -100.6837, -99.8230, 3.1532, 0.0, 0.0, random(360), 0, 0, -1, 90.0, 90.0, -1);
            MoveDynamicObject(pFrutas[playerid][FruteiroBox], -83.3295, -102.8246, 3.1532, 1.0);
        }
        case 4:
        {
            DestroyDynamicCPEx(pFrutas[playerid][FruteiroCheck]);
            DestroyDynamicMapIconEx(pFrutas[playerid][FruteiroMap]);
            DestroyDynamicObjectEx(pFrutas[playerid][FruteiroBox]);
            pFrutas[playerid][FruteiroStt] = 5;
            pFrutas[playerid][FruteiroMap] = CreateDynamicMapIcon(-62.5563,-24.9556,4.1218, 56, -1, 0, 0, playerid, 120.0, MAPICON_LOCAL, -1);
            pFrutas[playerid][FruteiroCheck] = CreateDynamicCP(-62.5563,-24.9556,4.1218, 1.0, 0, 0, playerid, 30.0, -1);

            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
            SetPlayerAttachedObject(playerid, 8, 1220, 3, 0.1310, -0.4270, -0.1290, -7.3999, 3.4000, 29.9000, 0.5850, 0.5280, 0.6530, 0xFFFFFFFF, 0xFFFFFFFF);
        }
        case 5:
        {
            DestroyDynamicCPEx(pFrutas[playerid][FruteiroCheck]);
            DestroyDynamicMapIconEx(pFrutas[playerid][FruteiroMap]);
            RemovePlayerAttachedObject(playerid, 8);
            ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
            
            pFrutas[playerid][FruteiroStt] = 0;

            new Mensagem[128],
                Galos = random(1800-1000)+1000;
            Jogador[playerid][Dinheiro] += Galos;
            format(Mensagem, sizeof(Mensagem), "| FRUTEIRO | Você recebeu {32CD32}$%s{FFFFFF} pelo processo da fruta", DinheiroSeparar(Galos));
            SendClientMessage(playerid, -1, Mensagem);
        }
    }

    return 1;
}

hook OnDynamicObjectMoved(objectid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(pFrutas[i][FruteiroStt] != 3) continue;
        if(pFrutas[i][FruteiroBox] != objectid) continue;

        pFrutas[i][FruteiroStt] = 4;
        pFrutas[i][FruteiroMap] = CreateDynamicMapIcon(-82.3697,-102.9891,3.1181, 56, -1, 0, 0, i, 120.0, MAPICON_LOCAL, -1);
        pFrutas[i][FruteiroCheck] = CreateDynamicCP(-82.3697,-102.9891,3.1181, 1.0, 0, 0, i, 30.0, -1);
        break;
    }
    return 1;
}

function RegenerarFruteira(id, value)
{
    value--;
    new Mensagem[100];
    if(value > 0)
    {
        format(Mensagem, sizeof(Mensagem), "Frutífera ( ID: %d ){FFFFFF}\nVoltando em {FFA500}%s", id+1, SegundosParaMinutosEx(value));
        UpdateDynamic3DTextLabelText(Frutas[id][ArvoreFrutaTexto], 0xFFA500FF, Mensagem);
        SetTimerEx("RegenerarFruteira", 1000, false, "dd", id, value);
        return 1;
    }
    format(Mensagem, sizeof(Mensagem), "Frutífera ( ID: %d ){FFFFFF}\nAperte {CCCCCC}'N'{FFFFFF} para derrubar e colher os frutos", id+1);
    Frutas[id][FrutaQuebrada] = false;
    Frutas[id][ArvoreFrutaID] = CreateDynamicObject(792, FrutasEx[id][FrutaX], FrutasEx[id][FrutaY], FrutasEx[id][FrutaZ], 0.0, 0.0, float(random(360)), 0, 0, -1, 150.0, 150.0, -1);
    UpdateDynamic3DTextLabelText(Frutas[id][ArvoreFrutaTexto], 0xFFA500FF, Mensagem);
    return 1;
}