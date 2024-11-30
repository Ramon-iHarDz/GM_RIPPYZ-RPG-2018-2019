#include <YSI_Coding\y_hooks>

enum BarcoMergulhoInf
{
    Float:BarcoMergulhadoX,
    Float:BarcoMergulhadoY,
    Float:BarcoMergulhadoZ,
    Float:BarcoMergulhadoA
};

enum JogadorMergulhador
{
    bool:MergulhadorAlugado,
    BarcoID,
    mStatus,

    // Informações
    MergulhoMap,
    MergulhoObjeto,
    MergulhoCheck,
    Text3D:MergulhoTexto
};
new pMergulhador[MAX_PLAYERS][JogadorMergulhador];
new BarcoMergulho[][BarcoMergulhoInf] = 
{
    {2782.6489,-2570.7974,0.1309,271.5639},
    {2780.5090,-2577.9519,0.5510,273.0025},
    {2770.4553,-2586.2698,0.5036,180.2312},
    {2761.3357,-2586.3789,0.4621,180.6665},
    {2752.5745,-2586.0522,0.4700,176.6842},
    {2743.1506,-2586.3623,0.4852,179.3324},
    {2733.8884,-2586.5239,0.1828,180.4790},
    {2723.9692,-2586.0605,0.1473,173.1498}
};

hook OnGameModeInit()
{
    CreateDynamicPickup(1239, 1, 2759.8257,-2569.2905,13.3321, 0, 0, -1, 90.0, -1);
    CreateDynamic3DTextLabel("Mergulhador{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", 0xFFA500FF, 2759.8257,-2569.2905,13.3321, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, 2759.8257,-2569.2905,13.3321)) return 1;
    if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
    if(strcmp(Jogador[playerid][Profissao], "Mergulhador")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pMergulhador[playerid][mStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");
    else
    {
        if(Jogador[playerid][Cilindro] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem cilindro");
        if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    }
    if(GetPVarInt(playerid, "asfdadazws") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
    SetPVarInt(playerid, "asfdadazws", gettime()+8);
    if(pMergulhador[playerid][MergulhadorAlugado] == false)
    {
        new i = random(sizeof(BarcoMergulho));
        pMergulhador[playerid][MergulhadorAlugado] = true;
        pMergulhador[playerid][BarcoID] = CreateVehicleEx(playerid, 472, BarcoMergulho[i][BarcoMergulhadoX], BarcoMergulho[i][BarcoMergulhadoY], BarcoMergulho[i][BarcoMergulhadoZ], BarcoMergulho[i][BarcoMergulhadoA], 110, 128, 500, 0); 
        MarcarPosicao(playerid, BarcoMergulho[i][BarcoMergulhadoX], BarcoMergulho[i][BarcoMergulhadoY], BarcoMergulho[i][BarcoMergulhadoZ]);
        VeiculoServer[pMergulhador[playerid][BarcoID]][Tranca] = 1;
        Jogador[playerid][Trabalhando] = true;
        SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você alugou um barco de Mergulhador");
        return 1;
    }
    Jogador[playerid][Trabalhando] = false;
    pMergulhador[playerid][MergulhadorAlugado] = false;
    DestroyVehicleEx(pMergulhador[playerid][BarcoID]);
    VerificarMarcacao(playerid);
    SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você devolveu o barco de Mergulhador");
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyVehicleEx(pMergulhador[playerid][BarcoID]);
    DestroyDynamicMapIconEx(pMergulhador[playerid][MergulhoMap]);
    DestroyDynamicObjectEx(pMergulhador[playerid][MergulhoObjeto]);
    DestroyDynamic3DTextLabelEx(pMergulhador[playerid][MergulhoTexto]);
    DestroyDynamicCPEx(pMergulhador[playerid][MergulhoCheck]);

    new dasa[JogadorMergulhador];
    pMergulhador[playerid] = dasa;
    return 1;
}

CMD:mar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Mergulhador")) return 0;
    if(pMergulhador[playerid][MergulhadorAlugado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem um barco de Mergulhador alugado");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPlayerVehicleID(playerid) != pMergulhador[playerid][BarcoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo seu barco");
    if(pMergulhador[playerid][mStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está em serviço");
    else
    {
        if(!IsPlayerInRangeOfPoint(playerid, 80.0, 2738.6284,-2604.4607,-1.0023)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na HQ");
    }
    if(Jogador[playerid][Cilindro] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem cilindro");
    pMergulhador[playerid][mStatus] = 1;
    switch(random(62))
    {
        case 0: {SetPVarFloat(playerid, "mX", -515.5477); SetPVarFloat(playerid, "mY", 881.1807); SetPVarFloat(playerid, "mZ", -39.2467);}
        case 1: {SetPVarFloat(playerid, "mX", -565.3637); SetPVarFloat(playerid, "mY", 806.4043); SetPVarFloat(playerid, "mZ", -47.9478);}
        case 2: {SetPVarFloat(playerid, "mX", -511.0777); SetPVarFloat(playerid, "mY", 930.0910); SetPVarFloat(playerid, "mZ", -31.1267);}
        case 3: {SetPVarFloat(playerid, "mX", -545.8679); SetPVarFloat(playerid, "mY", 930.0910); SetPVarFloat(playerid, "mZ", -31.1267);}
        case 4: {SetPVarFloat(playerid, "mX", -545.8679); SetPVarFloat(playerid, "mY", 877.1608); SetPVarFloat(playerid, "mZ", -23.7367);}
        case 5: {SetPVarFloat(playerid, "mX", -545.8679); SetPVarFloat(playerid, "mY", 858.3408); SetPVarFloat(playerid, "mZ", -43.3767);}
        case 6: {SetPVarFloat(playerid, "mX", -571.4279); SetPVarFloat(playerid, "mY", 858.3408); SetPVarFloat(playerid, "mZ", -37.1166);}
        case 7: {SetPVarFloat(playerid, "mX", -561.7980); SetPVarFloat(playerid, "mY", 879.8810); SetPVarFloat(playerid, "mZ", -33.8566);}
        case 8: {SetPVarFloat(playerid, "mX", -524.3881); SetPVarFloat(playerid, "mY", 961.3110); SetPVarFloat(playerid, "mZ", -33.8566);}
        case 9: {SetPVarFloat(playerid, "mX", -521.9117); SetPVarFloat(playerid, "mY", 870.6432); SetPVarFloat(playerid, "mZ", -44.5180);}
        case 10: {SetPVarFloat(playerid, "mX", -530.8385); SetPVarFloat(playerid, "mY", 904.4112); SetPVarFloat(playerid, "mZ", -33.8566);}
        case 11: {SetPVarFloat(playerid, "mX", -530.8385); SetPVarFloat(playerid, "mY", 858.5411); SetPVarFloat(playerid, "mZ", -33.8566);}
        case 12: {SetPVarFloat(playerid, "mX", -559.7185); SetPVarFloat(playerid, "mY", 862.9110); SetPVarFloat(playerid, "mZ", -33.8566);}
        case 13: {SetPVarFloat(playerid, "mX", -976.8980); SetPVarFloat(playerid, "mY", 323.2199); SetPVarFloat(playerid, "mZ", -33.6671);}
        case 14: {SetPVarFloat(playerid, "mX", -942.4580); SetPVarFloat(playerid, "mY", 323.2199); SetPVarFloat(playerid, "mZ", -36.5571);}
        case 15: {SetPVarFloat(playerid, "mX", -955.5281); SetPVarFloat(playerid, "mY", 295.2099); SetPVarFloat(playerid, "mZ", -32.8371);}
        case 16: {SetPVarFloat(playerid, "mX", -938.0180); SetPVarFloat(playerid, "mY", 301.6199); SetPVarFloat(playerid, "mZ", -32.8371);}
        case 17: {SetPVarFloat(playerid, "mX", -800.3877); SetPVarFloat(playerid, "mY", 201.2833); SetPVarFloat(playerid, "mZ", -44.8791);}
        case 18: {SetPVarFloat(playerid, "mX", -951.9480); SetPVarFloat(playerid, "mY", 307.0099); SetPVarFloat(playerid, "mZ", -17.5271);}
        case 19: {SetPVarFloat(playerid, "mX", -990.9380); SetPVarFloat(playerid, "mY", 300.6799); SetPVarFloat(playerid, "mZ", -25.7671);}
        case 20: {SetPVarFloat(playerid, "mX", -800.3877); SetPVarFloat(playerid, "mY", 377.5732); SetPVarFloat(playerid, "mZ", -44.8791);}
        case 21: {SetPVarFloat(playerid, "mX", -985.1380); SetPVarFloat(playerid, "mY", 278.1599); SetPVarFloat(playerid, "mZ", -35.8971);}
        case 22: {SetPVarFloat(playerid, "mX", -921.1778); SetPVarFloat(playerid, "mY", 278.1599); SetPVarFloat(playerid, "mZ", -53.8171);}
        case 23: {SetPVarFloat(playerid, "mX", -903.5978); SetPVarFloat(playerid, "mY", 300.5999); SetPVarFloat(playerid, "mZ", -60.9871);}
        case 24: {SetPVarFloat(playerid, "mX", -626.3473); SetPVarFloat(playerid, "mY", 377.5732); SetPVarFloat(playerid, "mZ", -55.3390);}
        case 25: {SetPVarFloat(playerid, "mX", -903.5978); SetPVarFloat(playerid, "mY", 255.5399); SetPVarFloat(playerid, "mZ", -61.6371);}
        case 26: {SetPVarFloat(playerid, "mX", -903.5978); SetPVarFloat(playerid, "mY", 237.1899); SetPVarFloat(playerid, "mZ", -51.5171);}
        case 27: {SetPVarFloat(playerid, "mX", -626.3473); SetPVarFloat(playerid, "mY", 499.3030); SetPVarFloat(playerid, "mZ", -53.0889);}
        case 28: {SetPVarFloat(playerid, "mX", -917.4679); SetPVarFloat(playerid, "mY", 249.6499); SetPVarFloat(playerid, "mZ", -46.4271);}
        case 29: {SetPVarFloat(playerid, "mX", -725.5373); SetPVarFloat(playerid, "mY", 499.3030); SetPVarFloat(playerid, "mZ", -48.4789);}
        case 30: {SetPVarFloat(playerid, "mX", -929.7001); SetPVarFloat(playerid, "mY", 350.9633); SetPVarFloat(playerid, "mZ", -33.0881);}
        case 31: {SetPVarFloat(playerid, "mX", -906.2398); SetPVarFloat(playerid, "mY", 336.6734); SetPVarFloat(playerid, "mZ", -52.9481);}
        case 32: {SetPVarFloat(playerid, "mX", -1147.7202); SetPVarFloat(playerid, "mY", 957.2471); SetPVarFloat(playerid, "mZ", -21.6575);}
        case 33: {SetPVarFloat(playerid, "mX", -1156.5104); SetPVarFloat(playerid, "mY", 973.6072); SetPVarFloat(playerid, "mZ", -21.6575);}
        case 34: {SetPVarFloat(playerid, "mX", -988.7180); SetPVarFloat(playerid, "mY", 845.4505); SetPVarFloat(playerid, "mZ", -27.2351);}
        case 35: {SetPVarFloat(playerid, "mX", -1166.7404); SetPVarFloat(playerid, "mY", 964.4270); SetPVarFloat(playerid, "mZ", -31.8675);}
        case 36: {SetPVarFloat(playerid, "mX", -1058.0386); SetPVarFloat(playerid, "mY", 764.5202); SetPVarFloat(playerid, "mZ", -27.2351);}
        case 37: {SetPVarFloat(playerid, "mX", -1157.6805); SetPVarFloat(playerid, "mY", 952.7570); SetPVarFloat(playerid, "mZ", -36.4775);}
        case 38: {SetPVarFloat(playerid, "mX", -1144.2207); SetPVarFloat(playerid, "mY", 952.7570); SetPVarFloat(playerid, "mZ", -29.6475);}
        case 39: {SetPVarFloat(playerid, "mX", -1068.8486); SetPVarFloat(playerid, "mY", 917.1002); SetPVarFloat(playerid, "mZ", -18.3251);}
        case 40: {SetPVarFloat(playerid, "mX", -1129.8986); SetPVarFloat(playerid, "mY", 868.9400); SetPVarFloat(playerid, "mZ", -19.0751);}
        case 41: {SetPVarFloat(playerid, "mX", -1129.8986); SetPVarFloat(playerid, "mY", 868.9400); SetPVarFloat(playerid, "mZ", -19.0751);}
        case 42: {SetPVarFloat(playerid, "mX", -1121.9398); SetPVarFloat(playerid, "mY", 957.2471); SetPVarFloat(playerid, "mZ", -37.4775);}
        case 43: {SetPVarFloat(playerid, "mX", -1121.9398); SetPVarFloat(playerid, "mY", 977.5072); SetPVarFloat(playerid, "mZ", -37.4775);}
        case 44: {SetPVarFloat(playerid, "mX", -1130.3398); SetPVarFloat(playerid, "mY", 967.7371); SetPVarFloat(playerid, "mZ", -33.4275);}
        case 45: {SetPVarFloat(playerid, "mX", -1130.3398); SetPVarFloat(playerid, "mY", 941.8472); SetPVarFloat(playerid, "mZ", -34.6075);}
        case 46: {SetPVarFloat(playerid, "mX", -1181.4202); SetPVarFloat(playerid, "mY", 941.8472); SetPVarFloat(playerid, "mZ", -34.6075);}
        case 47: {SetPVarFloat(playerid, "mX", -1183.7202); SetPVarFloat(playerid, "mY", 982.0073); SetPVarFloat(playerid, "mZ", -34.6075);}
        case 48: {SetPVarFloat(playerid, "mX", -1149.0498); SetPVarFloat(playerid, "mY", 982.0073); SetPVarFloat(playerid, "mZ", -43.5076);}
        case 49: {SetPVarFloat(playerid, "mX", -1925.0172); SetPVarFloat(playerid, "mY", 1753.2185); SetPVarFloat(playerid, "mZ", -21.4425);}
        case 50: {SetPVarFloat(playerid, "mX", -1913.5670); SetPVarFloat(playerid, "mY", 1747.6384); SetPVarFloat(playerid, "mZ", -33.1825);}
        case 51: {SetPVarFloat(playerid, "mX", -1907.3572); SetPVarFloat(playerid, "mY", 1768.9481); SetPVarFloat(playerid, "mZ", -41.5225);}
        case 52: {SetPVarFloat(playerid, "mX", -1897.3673); SetPVarFloat(playerid, "mY", 1755.8282); SetPVarFloat(playerid, "mZ", -48.2625);}
        case 53: {SetPVarFloat(playerid, "mX", -1923.3571); SetPVarFloat(playerid, "mY", 1755.8282); SetPVarFloat(playerid, "mZ", -53.2525);}
        case 54: {SetPVarFloat(playerid, "mX", -1913.4372); SetPVarFloat(playerid, "mY", 1755.8282); SetPVarFloat(playerid, "mZ", -45.9725);}
        case 55: {SetPVarFloat(playerid, "mX", -1924.1671); SetPVarFloat(playerid, "mY", 1782.1787); SetPVarFloat(playerid, "mZ", -45.9725);}
        case 56: {SetPVarFloat(playerid, "mX", -1888.8563); SetPVarFloat(playerid, "mY", 1774.2684); SetPVarFloat(playerid, "mZ", -54.2225);}
        case 57: {SetPVarFloat(playerid, "mX", -1888.8563); SetPVarFloat(playerid, "mY", 1741.4082); SetPVarFloat(playerid, "mZ", -54.2225);}
        case 58: {SetPVarFloat(playerid, "mX", -1905.6971); SetPVarFloat(playerid, "mY", 1741.4082); SetPVarFloat(playerid, "mZ", -54.2225);}
        case 59: {SetPVarFloat(playerid, "mX", -1936.8970); SetPVarFloat(playerid, "mY", 1741.4082); SetPVarFloat(playerid, "mZ", -54.2225);}
        case 60: {SetPVarFloat(playerid, "mX", -1936.8970); SetPVarFloat(playerid, "mY", 1760.1680); SetPVarFloat(playerid, "mZ", -62.8825);}
        case 61: {SetPVarFloat(playerid, "mX", -1928.3471); SetPVarFloat(playerid, "mY", 1760.1680); SetPVarFloat(playerid, "mZ", -69.8525);}
        case 62: {SetPVarFloat(playerid, "mX", -1892.0074); SetPVarFloat(playerid, "mY", 1760.1680); SetPVarFloat(playerid, "mZ", -69.8525);}
    }
    pMergulhador[playerid][MergulhoMap] = CreateDynamicMapIcon(GetPVarFloat(playerid, "mX"), GetPVarFloat(playerid, "mY"), GetPVarFloat(playerid, "mZ"), 0, 0xFFFF00FF, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    pMergulhador[playerid][MergulhoObjeto] = CreateDynamicObject(19918, GetPVarFloat(playerid, "mX"), GetPVarFloat(playerid, "mY"), GetPVarFloat(playerid, "mZ"), float(random(360)), float(random(360)), float(random(360)), 0, 0, -1, 120.0, 120.0, -1);
    pMergulhador[playerid][MergulhoTexto] = CreateDynamic3DTextLabel("Caixa{FFFFFF}\nUse: {CCCCCC}/AnalisarMar", 0xFFFF00FF, GetPVarFloat(playerid, "mX"), GetPVarFloat(playerid, "mY"), GetPVarFloat(playerid, "mZ"), 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, playerid, 31.0, -1);
    SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você precisa seguir o ponto marcado no mapa");
    return 1;
}

CMD:analisarmar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Mergulhador")) return 0;
    if(pMergulhador[playerid][mStatus] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode fazer esse processo agora");
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, GetPVarFloat(playerid, "mX"), GetPVarFloat(playerid, "mY"), GetPVarFloat(playerid, "mZ"))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está longe do local");
    if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está longe do local");
    if(!IsVehicleInRangeOfPoint(pMergulhador[playerid][BarcoID], 1000.0, GetPVarFloat(playerid, "mX"), GetPVarFloat(playerid, "mY"), GetPVarFloat(playerid, "mZ"))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu barco não está perto do local");
    if(!IsUsandoCilindro(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está utilizando o cilindro");
    pMergulhador[playerid][mStatus] = 2;
    TogglePlayerControllable(playerid, 0);
    CriarProgresso(playerid, "Analisando Caixa", "AnaliseCaixaMergu", 1*1000); 
    return 1;
}

function AnaliseCaixaMergu(playerid)
{
    DestroyDynamicMapIconEx(pMergulhador[playerid][MergulhoMap]);
    DestroyDynamicObjectEx(pMergulhador[playerid][MergulhoObjeto]);
    DestroyDynamic3DTextLabelEx(pMergulhador[playerid][MergulhoTexto]);

    TogglePlayerControllable(playerid, 1);
    pMergulhador[playerid][mStatus] = 3;

    pMergulhador[playerid][MergulhoMap] = CreateDynamicMapIcon(2738.6284,-2604.4607,-1.0023, 9, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    pMergulhador[playerid][MergulhoCheck] = CreateDynamicCP(2738.6284,-2604.4607,-1.0023, 4.0, 0, 0, playerid, 60.0, -1);
    pMergulhador[playerid][MergulhoObjeto] = CreateDynamicObject(19918, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, -1, 60.0, 60.0, -1);
    AttachDynamicObjectToVehicle(pMergulhador[playerid][MergulhoObjeto], pMergulhador[playerid][BarcoID], 0.0000, -2.2199, 0.0299, 0.0000, 0.0000, 0.0000);
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pMergulhador[playerid][MergulhoCheck]) return 1;
    DestroyDynamicCPEx(pMergulhador[playerid][MergulhoCheck]);
    DestroyDynamicMapIconEx(pMergulhador[playerid][MergulhoMap]);
    DestroyDynamicObjectEx(pMergulhador[playerid][MergulhoObjeto]);
    pMergulhador[playerid][mStatus] = 0;

    new Mensagem[75],
        das = random(9500-4500)+4500;
    Jogador[playerid][Dinheiro] += das;
    format(Mensagem, sizeof(Mensagem), "| MERGULHADOR | Você entregou a caixa nas docas e recebeu {32CD32}$%s", DinheiroSeparar(das));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}