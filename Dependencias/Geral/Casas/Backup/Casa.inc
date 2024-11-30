#include <YSI_Coding\y_hooks>
#include "../Dependencias/Geral/Casas/Hooks/CasaAdmin"

enum InfoInterior
{
    Interior,
    Float:cInterX,
    Float:cInterY,
    Float:cInterZ,
    Float:cInterA,
    ImpostoInterior
};

new pInterior[][InfoInterior] =
{
    {6, 2233.7029,-1114.7916,1050.8828,1.9379, 450}, //Interior Nível 1 
    {5, 221.9710,1140.2482,1082.6094,359.5769, 540}, // Interior Nível 2
    {19, 2282.9478,-1139.6548,1050.7264,0.6923, 600}, // Interior Nível 3
    {7, -68.7670,1351.2029,1080.2109,357.7915, 620}, // Interior Nível 4
    {2, 223.1135,1287.2272,1082.1406,358.4871, 800}, // Interior Nível 5
    {3, 226.6159,1239.8516,1082.1406,90.4183, 880}, // Interior Nível 6
    {3, 2468.7388,-1698.3387,1013.5078,90.7346, 900}, // Interior Nível 7
    {9, -42.5661,1405.6401,1084.4297,0.0100, 1000}, // Interior Nível 8
    {16, 377.1524,1417.3621,1081.3281,88.3598, 1100}, // Interior Nível 9
    {17, 387.1646,1471.7759,1080.1875,88.6483, 1300}, // Interior Nível 10
    {18, 295.1254,1472.4249,1080.2578,0.1220, 1350}, // Interior Nível 11
    {10, 260.7043,1237.4232,1084.2578,0.2793, 1400}, // Interior Nível 12
    {5, 261.0482,1284.4684,1080.2578,359.4326, 1440}, // Interior Nível 13
    {6, 22.7810,1403.3274,1084.4370,0.2787, 2100}, // Interior Nível 14
    {3, 447.0945,1397.2451,1084.3047,359.0193, 2150}, // Interior Nível 15
    {11, 23.9862,1340.1664,1084.3750,358.8939, 2300}, // Interior Nível 16
    {6, 226.3006,1114.2443,1080.9929,271.6493, 3600}, // Interior Nível 17
    {7, 234.1620,1063.8716,1084.2120,359.7274, 4600}, // Interior Nível 18
    {9, 140.3164,1366.0815,1083.8594,359.7274, 4650}, // Interior Nível 19
    {5, 1298.9603,-796.4469,1084.0078,1.3484, 25000} //Interior Nível 20
};

/*new pInterior[][InfoInterior] =
{
    {5, 2233.7029,-1114.7916,1050.8828,1.9379}, //Interior Nível 1
    {11, 2282.9878,-1139.7954,1050.8984,359.0314}, //Interior Nível 2
    {6, 2308.7053,-1212.7179,1049.0234,3.7093}, //Interior Nível 3
    {8, -42.5682,1405.7821,1084.4297,3.8557}, //Interior Nível 4
    {4, 221.9005,1140.7317,1082.6094,3.8634}, //Interior Nível 5
    {1, 223.1307,1287.3887,1082.1406,4.1529}, //Interior Nível 6
    {2, 2468.5125,-1698.3209,1013.5078,90.4275}, //Interior Nível 7
    {9, 260.7769,1237.5443,1084.2578,4.0095}, //Interior Nível 8
    {6, -68.8812,1351.5284,1080.2109,4.0143}, //Interior Nível 9
    {2, 2237.5806,-1081.2382,1049.0234,355.8103}, //Interior Nível 10
    {8, 2365.2581,-1135.3011,1050.8750,3.5637}, //Interior Nível 11
    {10, 2270.0640,-1210.3915,1047.5625,93.3387}, //Interior Nível 12
    {5, 226.7311,1114.3441,1080.9951,272.7614}, //Interior Nível 13
    {6, 2196.2671,-1204.4041,1049.0234,88.9462}, //Interior Nível 14
    {8, 2807.6548,-1174.4388,1025.5703,4.4241}, //Interior Nível 15
    {3, 2496.0706,-1692.4565,1014.7422,181.2083}, //Interior Nível 16
    {9, 2317.7234,-1026.3516,1050.2178,1.0632}, //Interior Nível 17
    {5, 140.3529,1366.3253,1083.8594,1.8444}, //Interior Nível 18
    {12, 2324.3716,-1148.8890,1050.7101,3.2471}, //Interior Nível 19
    {5, 1298.9603,-796.4469,1084.0078,1.3484} //Interior Nível 20
};*/

hook OnGameModeInit()
{
    PrepararCasa();
    CarregarCasa();
    return 1;
}

function CarregarCasa()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `casas`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Casa] Não foi possivel conectar com o banco de dados das casas!\n");
        SendRconCommand("exit");
    }
    new CasasDis = cache_num_rows();
    printf("[Rippzy:Casa] Sistema de casas está sendo carregado. ( %d Casas )", CasasDis);
    if(CasasDis < 1) return 1;
    new id;
    for(new i=0; i < CasasDis; i++)
    {
        cache_get_value_name_int(i, "Numero", id); //Id cas casas

        //Stings
        cache_get_value(i, "Dono", pCasa[id][cDono], 30);
        cache_get_value(i, "Mensagem", pCasa[id][cMensagem], 90);
        cache_get_value(i, "Senha", pCasa[id][cSenha], 90);

        //Moradores
        cache_get_value(i, "Morador0", pMorador[id][0][Morador], 30);
        cache_get_value(i, "Morador1", pMorador[id][1][Morador], 30);
        cache_get_value(i, "Morador2", pMorador[id][2][Morador], 30);
        cache_get_value(i, "Morador3", pMorador[id][3][Morador], 30);
        cache_get_value(i, "Morador4", pMorador[id][4][Morador], 30);
        cache_get_value(i, "Morador5", pMorador[id][5][Morador], 30);

        //Int
        cache_get_value_name_int(i, "Tranca", pCasa[id][cTranca]);
        cache_get_value_name_int(i, "Bloqueada", pCasa[id][cBloqueada]);
        cache_get_value_name_int(i, "Impostos", pCasa[id][Impostos]);
        cache_get_value_name_int(i, "Reforma", pCasa[id][cReforma]);
        cache_get_value_name_int(i, "LixoF", pCasa[id][LixoF]);
        cache_get_value_name_int(i, "LixoD", pCasa[id][LixoD]);
        cache_get_value_name_int(i, "Preco", pCasa[id][cPreco]);
        cache_get_value_name_int(i, "Coins", pCasa[id][cCoins]);
        cache_get_value_name_int(i, "JPreco", pCasa[id][cJPreco]);
        cache_get_value_name_int(i, "Interior", pCasa[id][cInterior]);
        cache_get_value_name_int(i, "InteriorMax", pCasa[id][cInteriorMax]);

        //Float
        cache_get_value_name_float(i, "PosicaoX", pCasa[id][cPosicaoX]);
        cache_get_value_name_float(i, "PosicaoY", pCasa[id][cPosicaoY]);
        cache_get_value_name_float(i, "PosicaoZ", pCasa[id][cPosicaoZ]);
        cache_get_value_name_float(i, "PosicaoA", pCasa[id][cPosicaoA]);
        pCasa[id][Numero] = id;
        AdicionarCasa(id);

    }
    cache_delete(Conectar);
    print("[Rippzy:Casa] Casas carregadas com sucesso!");
    return 1;
}

AdicionarCasa(id)
{
    //Strings
    new Mensagem[350];

    //Vendendo
    if(!strcmp(pCasa[id][cDono], "*") || pCasa[id][cJPreco] > 0)
    {
        if(pCasa[id][cJPreco] > 0) strcatEx(Mensagem, "{FF0000}Casa %s ID: %d\n", pCasa[id][cDono], id);   
        else strcatEx(Mensagem, "{FFFFFF}Casa: %d\n", id);
        strcatEx(Mensagem, "{FFFFFF}Interior %d / %d\n", pCasa[id][cInterior], pCasa[id][cInteriorMax]);

        if(pCasa[id][cJPreco] > 0){
            if(strcmp(pCasa[id][cMensagem], "*")) strcatEx(Mensagem, "{FFFFFF}%s\n", pCasa[id][cMensagem]);
            strcatEx(Mensagem, "{FFFFFF}Vendendo por {32CD32}$%s\n", DinheiroSeparar(pCasa[id][cJPreco]));
        } 
        else if(pCasa[id][cPreco] > 0 && pCasa[id][cCoins] > 0){
            strcat(Mensagem, "{FFFFFF}Mensagem: Casa sendo vendida por coins\n");
            strcatEx(Mensagem, "{FFFFFF}Coins: {FFFF00}$%s\n", DinheiroSeparar(pCasa[id][cCoins]));
            strcat(Mensagem, "{1E90FF}+\n");
            strcatEx(Mensagem, "{FFFFFF}Dinheiro: {32CD32}$%s\n", DinheiroSeparar(pCasa[id][cPreco]));
        }
        else if(pCasa[id][cPreco] > 0 && pCasa[id][cCoins] < 1) strcatEx(Mensagem, "{FFFFFF}Preço: {32CD32}$%s\n", DinheiroSeparar(pCasa[id][cPreco]));
        else if(pCasa[id][cPreco] < 1 && pCasa[id][cCoins] > 0) strcatEx(Mensagem, "{FFFFFF}Coins: {FFFF00}$%s\n", DinheiroSeparar(pCasa[id][cCoins]));
        
        strcat(Mensagem, "{1E90FF}/comprarcasa");
        pCasa[id][cPickup] = CreateDynamicPickup(1273, 1, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ], 0, 0, -1, 39.0);
        pCasa[id][cMapa] = CreateDynamicMapIcon(pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ], 31, -1, 0, 0, -1, 39.0, MAPICON_LOCAL);
    }
        

    //Comprada 
    else
    {
        strcatEx(Mensagem, "{FF0000}Casa %s ID: %d\n", pCasa[id][cDono], id);   
        strcatEx(Mensagem, "{FFFFFF}Interior %d / %d\n", pCasa[id][cInterior], pCasa[id][cInteriorMax]);
        if(strcmp(pCasa[id][cMensagem], "*")) strcatEx(Mensagem, "{FFFFFF}%s\n", pCasa[id][cMensagem]);
        if(pCasa[id][LixoF] > 0){
            strcatEx(Mensagem, "{FFA500}%d Lixo(s) Acumulado(s)\n", pCasa[id][LixoF]);
            pCasa[id][LixoOb] = CreateDynamicObject(1264, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ]-1.3, 0.0, 0.0, 0.0, 0, 0, -1, 60.0, 60.0, -1);
        }
        strcatEx(Mensagem, "%s\n", PegarCasaStatus(pCasa[id][cTranca]));
        strcatEx(Mensagem, "{1E90FF}/entrarcasa", 0);
        pCasa[id][cPickup] = CreateDynamicPickup(19522, 1, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ], 0, 0, -1, 39.0);
        pCasa[id][cMapa] = CreateDynamicMapIcon(pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ], 32, -1, 0, 0, -1, 39.0, MAPICON_LOCAL);
    }


    //Setar Informações
    pCasa[id][Colocado] = true;
    pCasa[id][cTexto] = CreateDynamic3DTextLabel(Mensagem, -1, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0 && newkeys == KEY_SECONDARY_ATTACK){
        for(new i=0; i < MAX_CASAS; i++){
            if(pCasa[i][Colocado] == false) continue;
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ])) continue;
            cmd_entrarcasa(playerid);
            break;
        }
        return 1;
    }

    if(Jogador[playerid][uInteriorEx] == 1){
        if(GetPVarInt(playerid, "InteriorPersonalizadoID") != 0 && GetPlayerVirtualWorld(playerid) > 0 && newkeys == KEY_SECONDARY_ATTACK){
            cmd_saircasa(playerid);
        }
    }
    return 1;
}

CMD:entrarcasa(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(Jogador[playerid][uInteriorEx] != 0) return 1;
    if(GetPlayerInterior(playerid) != 0 && GetPlayerVirtualWorld(playerid) != 0) return 1;
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ])) continue;

        if(pCasa[i][PortaArrombada] > gettime()) EntrarCasa(playerid, i);
        else if(pCasa[i][cTranca] == 0) EntrarCasa(playerid, i);
        else if(VerificarMorador(PegarNick(playerid), i) || !strcmp(pCasa[i][cDono], PegarNick(playerid)) || GetPVarInt(playerid, "PermEntrCasa") == i || Jogador[playerid][Admin] > 0) EntrarCasa(playerid, i);
        else if(pCasa[i][cTranca] == 2) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode acessar essa casa!");
        else if(pCasa[i][cTranca] == 1) Dialog_Show(playerid, SenhaEntrarCasa, DIALOG_STYLE_INPUT, "{FF0000}Acesso", "{FFFFFF}Coloque a senha dessa casa para acessá-la", "Confirmar", "Fechar");
        break;
    }   
    return 1;
}


CMD:saircasa(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    if(Dialog_IsOpened(playerid)) return 1;
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(casaid != 0 && Jogador[playerid][uInteriorEx] == 1 && GetPlayerVirtualWorld(playerid) > 0){
        for(new i=0; i < sizeof(pInterior); i++){
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, pInterior[i][cInterX], pInterior[i][cInterY], pInterior[i][cInterZ])) continue;
            TogglePlayerControllable(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
            SetPlayerPos(playerid, pCasa[casaid][cPosicaoX], pCasa[casaid][cPosicaoY], pCasa[casaid][cPosicaoZ]);
            SetPlayerFacingAngle(playerid, pCasa[casaid][cPosicaoA]);
            SetTimerEx("Destravar", 3000, false, "d", playerid);
            Jogador[playerid][uInteriorEx] = 0;
            SetPVarInt(playerid, "InteriorPersonalizadoID", 0);
            break;
        }
        
    }
    return 1;
}

CMD:comprarcasa(playerid) 
{
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(!strcmp(PegarNick(playerid), pCasa[i][cDono])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já é proprietário(a) de uma casa no servidor!");
        if(VerificarMorador(PegarNick(playerid), i)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você é morador de uma casa");
    }

    new bool:cPerto = false,
        Dialog[700];
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 4.0, pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ])) continue;
        if(strcmp(pCasa[i][cDono], "*") && pCasa[i][cJPreco] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa já possui proprietário(a)");
        if(Jogador[playerid][Level] < 30) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você precisa de level 30 para comprar essa casa");
        if(pCasa[i][cReforma] > gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa ainda está bloqueada");
        if(pCasa[i][cJPreco] < 1)
        {
            if(Jogador[playerid][Dinheiro] < pCasa[i][cPreco]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não possui dinheiro sucifiente para comprar essa casa");
            if(Jogador[playerid][Coins] < pCasa[i][cCoins]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não possui coins sucifiente para comprar essa casa");
        }
        else if(Jogador[playerid][Dinheiro] < pCasa[i][cJPreco]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não possui dinheiro sucifiente para comprar essa casa");
        if(pCasa[i][cBloqueada] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa foi bloqueada pelo desenvolvedor");
        
        if(strcmp(pCasa[i][cDono], "*")){
            if(!IsPlayerConnected(PegarIdPeloNick(pCasa[i][cDono]))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Proprietário(a) dessa casa não se encontra online");
        }

        SetPVarInt(playerid, "CasaIDTartaruga", i);

        if(pCasa[i][cJPreco] > 0) strcatEx(Dialog, "{FFFFFF}Valor {32CD32}$%s\n", DinheiroSeparar(pCasa[i][cJPreco]));
        else
        {
            if(pCasa[i][cPreco] > 0) strcatEx(Dialog, "{FFFFFF}Valor {32CD32}$%s\n", DinheiroSeparar(pCasa[i][cPreco]));
            if(pCasa[i][cCoins] > 0) strcatEx(Dialog, "{FFFFFF}Valor ( {CCCCCC}Coins{FFFFFF} ) {32CD32}$%s\n", DinheiroSeparar(pCasa[i][cCoins]));
        }

        strcat(Dialog, "{FFFFFF}Você realmente deseja comprar essa casa?");
        Dialog_Show(playerid, ComprarCasaConfimacao, DIALOG_STYLE_MSGBOX, "{00BFFF}Compra Casa", Dialog, "Comprar", "Cancelar");
        cPerto = true; 
        break;
    }
    if(cPerto == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está perto de uma casa");
    return 1;
}

CMD:menucasa(playerid)
{
    if(Jogador[playerid][uInteriorEx] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em uma casa!");
    new bool:Port = false;
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(casaid != 0 && Jogador[playerid][uInteriorEx] == 1 && GetPlayerVirtualWorld(playerid) > 0)
    {
        for(new i=0; i < sizeof(pInterior); i++)
        {
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, pInterior[i][cInterX], pInterior[i][cInterY], pInterior[i][cInterZ])) continue;
            if(!strcmp(pCasa[casaid][cDono], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa casa não possui proprietário(a)");
            if(strcmp(pCasa[casaid][cDono], PegarNick(playerid)) && !VerificarMorador(PegarNick(playerid), casaid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é morador e nem proprietário(a) dessa casa");

            Port = true;

            new Dialog[400];
            strcat(Dialog, "Opção\tInformação\n");

            //Tranca
            if(pCasa[casaid][cTranca] == 1) strcatEx(Dialog, "%s\t{fc520f}%s\n", PegarCasaStatus(pCasa[casaid][cTranca]), pCasa[casaid][cSenha]);
            else strcatEx(Dialog, "%s\n", PegarCasaStatus(pCasa[casaid][cTranca]));
            
            //Mensagem
            if(!strcmp(pCasa[casaid][cMensagem], "*")) strcat(Dialog, "Mensagem:\t{fc520f}-\n");
            else strcatEx(Dialog, "Mensagem:\t%s\n", pCasa[casaid][cMensagem]);
            
            //Lixo
            strcatEx(Dialog, "Lixo(s)\t{fc520f}%d\n", pCasa[casaid][LixoD]);

            //
            strcat(Dialog, "Moradores(as)\n");
            strcat(Dialog, "Upgrade Interior\n");
            strcat(Dialog, "{00FF00}Venda");
            Dialog_Show(playerid, MenuCasa, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Casa", Dialog, "Selecionar", "Fechar");
            break;
        }
    }
    if(Port == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está longe da porta");
    return 1;
}

