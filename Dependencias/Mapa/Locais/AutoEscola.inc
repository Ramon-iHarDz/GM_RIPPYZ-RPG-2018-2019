#include <YSI_Coding\y_hooks>

enum JogadorAutoEscola
{
    bool:FazendoProva,
    VeiculoAEscola,
    Acertos,
    AtualEscola,
    AtualPerguntasEscola,
    AutoCheckPoint,
    CategoriaAEscola[70]
};

enum CategoriasInfoAutoEscola
{
    Float:PosicaoCatX,
    Float:PosicaoCatY,
    Float:PosicaoCatZ
};

enum EscolaPergunta
{
    PerguntaEscola[600],
    CertaEscola
};

new PerguntasAutoEscola[][EscolaPergunta] =
{
    {"{FFFFFF}Quando algum veículo de emergência passa por perto de você com as sirenes ligadas você deve:\n\n1. Acelerar, impedindo a passagem\n2. Manter a velocidade e dar prioridade", 2},
    {"{FFFFFF}Antes de mudar de faixa você deve:\n\n1. Ter cuidado e verificar se a passagem está livre\n2. Ignorar e mudar de faixa", 1},
    {"{FFFFFF}Quando você vê uma placa de stop, você deve\n\n1. Parar\n2. Continuar", 1},
    {"{FFFFFF}Um indivíduo está atravessando a rua você deve:\n\n1. Passar por cima\n2. Parar e esperar", 2},
    {"{FFFFFF}Qual a porcentagem de álcool no sangue e considerado crime:\n\n1. 0.05 mg/l\n2. 0.18 mg/l", 1},
    {"{FFFFFF}Você deve acelerar quando o semáfaro está:\n\n1. Verde\n2. Amarelo\n3. Vermelho", 1}
};

new ACategoria[][CategoriasInfoAutoEscola] =
{
    {-1900.4172,-1311.4347,39.0442},
    {-1856.0354,-1235.0361,39.0272},
    {-1913.1140,-1156.3933,28.6582},
    {-1979.1901,-1081.5403,31.5862},
    {-1989.1788,-1172.2128,39.0462},
    {-1913.6661,-1259.1107,39.0495},
    {-1908.4625,-1335.9659,39.9494},
    {-1987.8964,-1296.7343,37.6605},
    {-2064.2874,-1171.2811,31.3619},
    {-2129.4907,-1055.1359,30.2973},
    {-2217.4993,-926.7885,42.0315},
    {-2200.6968,-850.0992,55.7885},
    {-2272.4204,-759.3436,80.1448},
    {-2349.3586,-729.8928,103.8454},
    {-2392.8069,-635.1497,130.2539},
    {-2417.2822,-603.8956,132.1094}
};


new BCategoria[][CategoriasInfoAutoEscola] =
{
    {-1098.8534,-487.8203,32.6690},
    {-1188.6598,-700.9498,53.2071},
    {-1229.8431,-766.0132,63.6096},
    {-1117.6189,-887.0382,73.7211},
    {-887.8398,-1121.8682,98.6660},
    {-900.3286,-1294.9719,116.0139},
    {-949.4916,-1399.0237,128.5900},
    {-1146.8553,-1333.7567,126.6585},
    {-1413.9761,-1411.3749,104.0403},
    {-1496.9478,-1244.6625,100.9278},
    {-1630.3030,-1066.2843,102.3744},
    {-1622.8275,-864.5522,96.5166},
    {-1724.0500,-825.0364,79.6677},
    {-1742.6993,-1005.7263,74.7800},
    {-1641.6876,-1177.9063,70.9146},
    {-1529.5208,-1383.0337,45.2590},
    {-1597.9115,-1406.0443,42.9983},
    {-1719.6752,-1208.0895,53.5053},
    {-1802.8970,-989.1703,50.0872},
    {-1814.0511,-629.4799,16.1805},
    {-1812.5002,-409.2669,15.4268},
    {-1796.8115,-221.2971,17.4233},
    {-1797.6134,-120.4264,5.2114},
    {-1761.4183,-68.1997,7.6752},
    {-1761.8030,123.4534,3.5805},
    {-1739.5638,140.7652,3.2568}
};

new CCategoria[][CategoriasInfoAutoEscola] = 
{
    {-630.5313,2057.9829,60.7720},
    {-814.0856,2043.2622,60.7721},
    {-879.4496,1943.4165,60.8494},
    {-894.3335,1796.8593,60.8696},
    {-1024.7427,1857.0045,61.5285},
    {-1156.4465,1801.4543,40.6546},
    {-1226.6079,1887.0316,42.1002},
    {-1331.0892,2004.0613,54.2165},
    {-1347.3276,2162.3499,48.4804},
    {-1401.1488,2290.1409,55.8781},
    {-1416.6100,2509.8635,62.5828},
    {-1312.0796,2649.0723,50.4830},
    {-1299.5481,2691.3560,50.6505}
};

new DCategoria[][CategoriasInfoAutoEscola] =
{
    {1696.9420,-1163.5095,23.3616},
    {1847.1890,-1183.1703,23.3479},
    {1869.4030,-1085.4125,23.3684},
    {1978.8066,-1054.0143,24.1032},
    {2153.9172,-1119.0768,25.0469},
    {2316.5774,-1156.2740,26.5075},
    {2428.7527,-1088.3994,41.4067},
    {2564.9390,-1058.3119,69.0952},
    {2636.7229,-1049.8141,69.1151},
    {2699.0688,-1089.1353,68.8706},
    {2720.1851,-1229.8759,62.4588},
    {2656.2390,-1253.9578,49.8670},
    {2545.4363,-1254.4525,41.1705},
    {2452.7136,-1253.5922,23.5437},
    {2448.4829,-1372.6669,23.5323},
    {2433.4727,-1441.8063,23.5322},
    {2428.5786,-1559.2028,23.5329},
    {2428.7192,-1728.5629,13.2951},
    {2411.1895,-1840.3762,13.0881},
    {2411.5725,-2012.6313,13.0759},
    {2411.2476,-2117.3105,13.0443},
    {2394.4646,-2126.3120,13.2519}
};

//Auto Escola CheckPoint
new pEscola[MAX_PLAYERS][JogadorAutoEscola];

hook OnGameModeInit(){
    CreateDynamic3DTextLabel("{00BFFF}Auto Escola\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para visualizar", -1, 691.7781, -590.3310, -25.0000, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1001, 1, -1, 35.0, -1, 0);
    return 1; 
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pEscola[playerid][FazendoProva] == true)
    {
        DestroyDynamicRaceCPEx(pEscola[playerid][AutoCheckPoint]);
        DestroyVehicleEx(pEscola[playerid][VeiculoAEscola]);
        new sadas[JogadorAutoEscola];
        pEscola[playerid] = sadas;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 691.7781, -590.3310, -25.0000)) return 1;
    if(GetPlayerInterior(playerid) != 1 && GetPlayerVirtualWorld(playerid) != 1001) return 1;

    new Dialog[700];
    strcat(Dialog, "Categoria\tSituação\tValor\n");

    //Carteira A
    if(Jogador[playerid][CarteiraA] == 0) strcat(Dialog, "{FFFFFF}Motos\t{FF4500}Não Possui\t{00FF00}$800\n");
    if(Jogador[playerid][CarteiraA] == 1) strcat(Dialog, "{FFFFFF}Motos\t{7FFFD4}Normal\t{FF0000}N/A\n");
    if(Jogador[playerid][CarteiraA] == 2) strcat(Dialog, "{FFFFFF}Motos\t{FF0000}Vencida\t{FF0000}N/A\n");
    if(Jogador[playerid][CarteiraA] == 3) strcat(Dialog, "{FFFFFF}Motos\t{FF6347}Retida\t{FF0000}N/A\n");

    //Carteira B
    if(Jogador[playerid][CarteiraB] == 0) strcat(Dialog, "{FFFFFF}Carros\t{FF4500}Não Possui\t{00FF00}$1.100\n");
    if(Jogador[playerid][CarteiraB] == 1) strcat(Dialog, "{FFFFFF}Carros\t{7FFFD4}Normal\t{FF0000}N/A\n");
    if(Jogador[playerid][CarteiraB] == 2) strcat(Dialog, "{FFFFFF}Carros\t{FF0000}Vencida\t{FF0000}N/A\n");
    if(Jogador[playerid][CarteiraB] == 3) strcat(Dialog, "{FFFFFF}Carros\t{FF6347}Retida\t{FF0000}N/A\n");

    //Carteira C
    if(Jogador[playerid][CarteiraC] == 0) strcat(Dialog, "{FFFFFF}Caminhões\t{FF4500}Não Possui\t{00FF00}$1.400\n");
    if(Jogador[playerid][CarteiraC] == 1) strcat(Dialog, "{FFFFFF}Caminhões\t{7FFFD4}Normal\t{FF0000}N/A\n");
    if(Jogador[playerid][CarteiraC] == 2) strcat(Dialog, "{FFFFFF}Caminhões\t{FF0000}Vencida\t{FF0000}N/A\n");
    if(Jogador[playerid][CarteiraC] == 3) strcat(Dialog, "{FFFFFF}Caminhões\t{FF6347}Retida\t{FF0000}N/A\n");

    //Carteira D
    if(Jogador[playerid][CarteiraD] == 0) strcat(Dialog, "{FFFFFF}Ônibus\t{FF4500}Não Possui\t{00FF00}$1.700\n");
    if(Jogador[playerid][CarteiraD] == 1) strcat(Dialog, "{FFFFFF}Ônibus\t{7FFFD4}Normal\t{FF0000}N/A\n");
    if(Jogador[playerid][CarteiraD] == 2) strcat(Dialog, "{FFFFFF}Ônibus\t{FF0000}Vencida\t{00FF00}$9.000\n");
    if(Jogador[playerid][CarteiraD] == 3) strcat(Dialog, "{FFFFFF}Ônibus\t{FF6347}Retida\t{FF0000}N/A\n");

    //Carteira E
    if(Jogador[playerid][CarteiraE] == 0) strcat(Dialog, "{FFFFFF}Carretas\t{FF4500}Não Possui\t{00FF00}$2.100\n");
    if(Jogador[playerid][CarteiraE] == 1) strcat(Dialog, "{FFFFFF}Carretas\t{7FFFD4}Normal\t{FF0000}N/A\n");
    if(Jogador[playerid][CarteiraE] == 2) strcat(Dialog, "{FFFFFF}Carretas\t{FF0000}Vencida\t{FF0000}N/A\n");
    if(Jogador[playerid][CarteiraE] == 3) strcat(Dialog, "{FFFFFF}Carretas\t{FF6347}Retida\t{FF0000}N/A\n");
    Dialog_Show(playerid, AutoEscolaDialog, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Auto Escola", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:AutoEscolaDialog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    if(Jogador[playerid][Trabalhando] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço, devolva sua moto/uniforme ou conclua alguma entrega etc..!");
    switch(listitem)
    {
        case 0: //Categoria A
        {
            if(Jogador[playerid][Level] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode tirar sua habilitação a partir do level 1");
            if(Jogador[playerid][CarteiraA] == 0){
                if(Jogador[playerid][Dinheiro] < 800) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui dinheiro sucifiente");
                Jogador[playerid][Dinheiro] -= 800;
            }
            if(Jogador[playerid][CarteiraA] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já possui essa CNH");
            if(Jogador[playerid][CarteiraA] == 2){
                if(Jogador[playerid][Dinheiro] < 1000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui dinheiro sucifiente");
                Jogador[playerid][Dinheiro] -= 1000;
            }
            if(Jogador[playerid][CarteiraA] == 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Vá até o detran para regularizar sua Carteira de Moto!");
            format(pEscola[playerid][CategoriaAEscola], 128, "CategoriaA");
        }
        case 1: //Categoria B
        {
            if(Jogador[playerid][Level] < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode tirar sua habilitação a partir do level 3");
            if(Jogador[playerid][CarteiraB] == 0){
                if(Jogador[playerid][Dinheiro] < 1100) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui dinheiro sucifiente");
                Jogador[playerid][Dinheiro] -= 1100;
            }
            if(Jogador[playerid][CarteiraB] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já possui essa CNH");
            if(Jogador[playerid][CarteiraB] == 2){
                if(Jogador[playerid][Dinheiro] < 1700) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui dinheiro sucifiente");
                Jogador[playerid][Dinheiro] -= 1700;
            }
            if(Jogador[playerid][CarteiraB] == 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Vá até o detran para regularizar sua Carteira de Carro!");
            format(pEscola[playerid][CategoriaAEscola], 128, "CategoriaB");
        }
        case 2: //Categoria C
        {
            if(Jogador[playerid][Level] < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode tirar sua habilitação a partir do level 3");
            if(Jogador[playerid][CarteiraC] == 0){
                if(Jogador[playerid][Dinheiro] < 1400) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui dinheiro sucifiente");
                Jogador[playerid][Dinheiro] -= 1400;
            }
            if(Jogador[playerid][CarteiraC] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já possui essa CNH");
            if(Jogador[playerid][CarteiraC] == 2){
                if(Jogador[playerid][Dinheiro] < 1900) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui dinheiro sucifiente");
                Jogador[playerid][Dinheiro] -= 1900;
            }
            if(Jogador[playerid][CarteiraC] == 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Vá até o detran para regularizar sua Carteira de Veículos de Carga");
            format(pEscola[playerid][CategoriaAEscola], 128, "CategoriaC");
        }
        case 3: //Categoria D
        {
            if(Jogador[playerid][Level] < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode tirar sua habilitação a partir do level 3");
            if(Jogador[playerid][CarteiraD] == 0){
                if(Jogador[playerid][Dinheiro] < 1700) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui dinheiro sucifiente");
                Jogador[playerid][Dinheiro] -= 1700;
            }
            if(Jogador[playerid][CarteiraD] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já possui essa CNH");
            if(Jogador[playerid][CarteiraD] == 2){
                if(Jogador[playerid][Dinheiro] < 2000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui dinheiro sucifiente");
                Jogador[playerid][Dinheiro] -= 2000;
            }
            if(Jogador[playerid][CarteiraD] == 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Vá até o detran para regularizar sua Carteira de Veiculos de Transporte!");
            format(pEscola[playerid][CategoriaAEscola], 128, "CategoriaD");  
        }
        case 4: //CAtegoria E
        {
            return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Indisponível no momento.");
        }
    }
    pEscola[playerid][Acertos] = 0;
    pEscola[playerid][AtualPerguntasEscola] = 0;
    Dialog_Show(playerid, PerguntasDialogs, DIALOG_STYLE_INPUT, "{FF0000}Auto Escola", PerguntasAutoEscola[pEscola[playerid][AtualPerguntasEscola]][PerguntaEscola], "Confirmar", "Fechar");
    return 0;
}

Dialog:PerguntasDialogs(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new Resposta;
    if(sscanf(inputtext, "d", Resposta) || isnull(inputtext)){
        pEscola[playerid][Acertos] = 0;
        pEscola[playerid][AtualPerguntasEscola] = 0;
        SendClientMessage(playerid, 0xFF4500FF, "| AUTO-ESCOLA | Você foi reprovado(a) por resposta inválida!");
        return 1;
    }
    new PerguntaID = pEscola[playerid][AtualPerguntasEscola];
    if(PerguntasAutoEscola[PerguntaID][CertaEscola] == Resposta){
        pEscola[playerid][Acertos]++;   
    }
    pEscola[playerid][AtualPerguntasEscola]++;
    if(pEscola[playerid][AtualPerguntasEscola] >= sizeof(PerguntasAutoEscola))
    {
        if(pEscola[playerid][Acertos] >= 3)
        {
            pEscola[playerid][Acertos] = 0;
            pEscola[playerid][AtualPerguntasEscola] = 0;      
            SendClientMessage(playerid, 0xFF4500FF, "| AUTO-ESCOLA | Você foi aprovado(a) no teórico, agora vamos para o prático.");   
            AdicionarAutoEscola(playerid);
        }
        else
        {
            pEscola[playerid][Acertos] = 0;
            pEscola[playerid][AtualPerguntasEscola] = 0;
            SendClientMessage(playerid, 0xFF4500FF, "| AUTO-ESCOLA | Você foi reprovado(a), estude e volte depois!"); 
        }
    }
    else
    {
        Dialog_Show(playerid, PerguntasDialogs, DIALOG_STYLE_INPUT, "{FF0000}Auto Escola", PerguntasAutoEscola[pEscola[playerid][AtualPerguntasEscola]][PerguntaEscola], "Confirmar", "Fechar");
    }
    return 0;
}

stock AdicionarAutoEscola(playerid)
{
    if(!strcmp(pEscola[playerid][CategoriaAEscola], "CategoriaA"))
    {
        pEscola[playerid][AtualEscola] = 0;
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        pEscola[playerid][VeiculoAEscola] = CreateVehicleEx(playerid, 468, -1937.7712,-1361.0634,40.4285,238.7671, 6, 6, -1, 0);
        SetPlayerPos(playerid, -1937.7712,-1361.0634,40.4285);
        cAC[playerid][VeiculoPermitido] = pEscola[playerid][VeiculoAEscola];
        PutPlayerInVehicle(playerid, pEscola[playerid][VeiculoAEscola], 0);
        DisableRemoteVehicleCollisions(playerid, 1);
        pEscola[playerid][FazendoProva] = true;
        new Proximo = pEscola[playerid][AtualEscola];
        Proximo++;
        pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(0, ACategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], ACategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], ACategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], ACategoria[Proximo][PosicaoCatX], ACategoria[Proximo][PosicaoCatY], ACategoria[Proximo][PosicaoCatZ], 5.0, 0, 0, playerid, 500.0, -1, 0);
        pEscola[playerid][AtualEscola]++;
        SetTimerEx("AutoEscolaVeri", 2000, false, "d", playerid);
        SendClientMessage(playerid, 0xFFFF00FF, "| AUTO-ESCOLA | Siga todos os pontos marcado em seu mapa, evite bater!");
    }

    else if(!strcmp(pEscola[playerid][CategoriaAEscola], "CategoriaB"))
    {
        pEscola[playerid][AtualEscola] = 0;
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        pEscola[playerid][VeiculoAEscola] = CreateVehicleEx(playerid, 422, -1040.0614,-462.6537,35.4011,22.9189, 6, 6, -1, 0);
        SetPlayerPos(playerid, -1040.0614,-462.6537,35.4011);
        cAC[playerid][VeiculoPermitido] = pEscola[playerid][VeiculoAEscola];
        PutPlayerInVehicle(playerid, pEscola[playerid][VeiculoAEscola], 0);
        DisableRemoteVehicleCollisions(playerid, 1);
        pEscola[playerid][FazendoProva] = true;
        new Proximo = pEscola[playerid][AtualEscola];
        Proximo++;
        pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(0, BCategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], BCategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], BCategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], BCategoria[Proximo][PosicaoCatX], BCategoria[Proximo][PosicaoCatY], BCategoria[Proximo][PosicaoCatZ], 5.0, 0, 0, playerid, 500.0, -1, 0);
        pEscola[playerid][AtualEscola]++;
        SetTimerEx("AutoEscolaVeri", 2000, false, "d", playerid);
        SendClientMessage(playerid, 0xFFFF00FF, "| AUTO-ESCOLA | Siga todos os pontos marcado em seu mapa, evite bater!");
    }

    else if(!strcmp(pEscola[playerid][CategoriaAEscola], "CategoriaC"))
    {
        pEscola[playerid][AtualEscola] = 0;
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        pEscola[playerid][VeiculoAEscola] = CreateVehicleEx(playerid, 455, -510.4170,1965.4153,61.0402,20.2899, 6, 6, -1, 0);
        SetPlayerPos(playerid, -510.4170,1965.4153,61.0402);
        cAC[playerid][VeiculoPermitido] = pEscola[playerid][VeiculoAEscola];
        PutPlayerInVehicle(playerid, pEscola[playerid][VeiculoAEscola], 0);
        DisableRemoteVehicleCollisions(playerid, 1);
        pEscola[playerid][FazendoProva] = true;
        new Proximo = pEscola[playerid][AtualEscola];
        Proximo++;
        pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(0, CCategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], CCategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], CCategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], CCategoria[Proximo][PosicaoCatX], CCategoria[Proximo][PosicaoCatY], CCategoria[Proximo][PosicaoCatZ], 5.0, 0, 0, playerid, 500.0, -1, 0);
        pEscola[playerid][AtualEscola]++;
        SetTimerEx("AutoEscolaVeri", 2000, false, "d", playerid);
        SendClientMessage(playerid, 0xFFFF00FF, "| AUTO-ESCOLA | Siga todos os pontos marcado em seu mapa, evite bater!");
    }

    else if(!strcmp(pEscola[playerid][CategoriaAEscola], "CategoriaD"))
    {
        pEscola[playerid][AtualEscola] = 0;
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        pEscola[playerid][VeiculoAEscola] = CreateVehicleEx(playerid, 437, 1637.1405,-1122.4136,23.6115,180.3311, 6, 6, -1, 0);
        SetPlayerPos(playerid, 1637.1405,-1122.4136,23.6115);
        cAC[playerid][VeiculoPermitido] = pEscola[playerid][VeiculoAEscola];
        PutPlayerInVehicle(playerid, pEscola[playerid][VeiculoAEscola], 0);
        DisableRemoteVehicleCollisions(playerid, 1);
        pEscola[playerid][FazendoProva] = true;
        new Proximo = pEscola[playerid][AtualEscola];
        Proximo++;
        pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(0, DCategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], DCategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], DCategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], DCategoria[Proximo][PosicaoCatX], DCategoria[Proximo][PosicaoCatY], DCategoria[Proximo][PosicaoCatZ], 5.0, 0, 0, playerid, 500.0, -1, 0);
        pEscola[playerid][AtualEscola]++;
        SetTimerEx("AutoEscolaVeri", 2000, false, "d", playerid);
        SendClientMessage(playerid, 0xFFFF00FF, "| AUTO-ESCOLA | Siga todos os pontos marcado em seu mapa, evite bater!");
    }
    return 1;
}

hook OnPlayerEnterDynRaceCP(playerid, checkpointid)
{
    if(checkpointid == pEscola[playerid][AutoCheckPoint])
    {
        if(!strcmp(pEscola[playerid][CategoriaAEscola], "CategoriaA"))
        {
            DestroyDynamicRaceCPEx(pEscola[playerid][AutoCheckPoint]);
            if(pEscola[playerid][AtualEscola] >= sizeof(ACategoria))
            {
                pEscola[playerid][AtualEscola] = 0;
                pEscola[playerid][FazendoProva] = false;
                DisableRemoteVehicleCollisions(playerid, 0);

                for(new i=0; i < sizeof(Pick); i++){
                    if(Pick[i][LocalID] == Jogador[playerid][uInterior]){
                        SetPlayerPos(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
                        Jogador[playerid][uInterior] = 0;
                        break;
                    }
                }

                new Float:VidaPega;
                GetVehicleHealth(pEscola[playerid][VeiculoAEscola], VidaPega);
                DestroyVehicleEx(pEscola[playerid][VeiculoAEscola]);
                
                if(VidaPega < 700) return SendClientMessage(playerid, 0xFF4500FF, "| AUTO-ESCOLA | Você foi reprovado(a) por danificar sua moto!");
                Jogador[playerid][CarteiraA] = 1;
                VerificarCarteiraSQL(playerid);
                SendClientMessage(playerid, -1, "| AUTO-ESCOLA | Sua habilitação de motos foi aprovada com sucesso.");
                return 1;
            }

            new Proximo = pEscola[playerid][AtualEscola],
                MensagemA[128];
            Proximo++;
            if(Proximo >= sizeof(ACategoria))
            {
                pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(1, ACategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], ACategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], ACategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], 0.0, 0.0, 0.0, 5.0, 0, 0, playerid, 500.0, -1, 0);
                format(MensagemA, sizeof(MensagemA), "| AUTO-ESCOLA | Siga para o último checkpoint ( {00BFFF}%d/%d{FFFFFF} )", pEscola[playerid][AtualEscola], sizeof(ACategoria));
                SendClientMessage(playerid, -1, MensagemA);
                PlayerPlaySound(playerid, 1057, 0, 0, 0);
            }
            else
            {
                pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(0, ACategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], ACategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], ACategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], ACategoria[Proximo][PosicaoCatX], ACategoria[Proximo][PosicaoCatY], ACategoria[Proximo][PosicaoCatZ], 5.0, 0, 0, playerid, 500.0, -1, 0);
                format(MensagemA, sizeof(MensagemA), "| AUTO-ESCOLA | Vá até o próximo checkpoint ( {00BFFF}%d/%d{FFFFFF} )", pEscola[playerid][AtualEscola], sizeof(ACategoria));
                SendClientMessage(playerid, -1, MensagemA);
                PlayerPlaySound(playerid, 1057, 0, 0, 0);
            }
            pEscola[playerid][AtualEscola]++;
        }

        else if(!strcmp(pEscola[playerid][CategoriaAEscola], "CategoriaB"))
        {
            DestroyDynamicRaceCPEx(pEscola[playerid][AutoCheckPoint]);
            if(pEscola[playerid][AtualEscola] >= sizeof(BCategoria))
            {
                pEscola[playerid][AtualEscola] = 0;
                pEscola[playerid][FazendoProva] = false;
                DisableRemoteVehicleCollisions(playerid, 0);
            
                for(new i=0; i < sizeof(Pick); i++){
                    if(Pick[i][LocalID] == Jogador[playerid][uInterior]){
                        SetPlayerPos(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
                        Jogador[playerid][uInterior] = 0;
                        break;
                    }
                }

                new Float:VidaPega;
                GetVehicleHealth(pEscola[playerid][VeiculoAEscola], VidaPega);
                DestroyVehicleEx(pEscola[playerid][VeiculoAEscola]);
                if(VidaPega < 700) return SendClientMessage(playerid, 0xFF4500FF, "| AUTO-ESCOLA | Você foi reprovado(a) por danificar seu carro!");
                Jogador[playerid][CarteiraB] = 1;
                VerificarCarteiraSQL(playerid);
                SendClientMessage(playerid, -1, "| AUTO-ESCOLA | Sua habilitação de carros foi aprovada com sucesso.");
                return 1;
            }

            new Proximo = pEscola[playerid][AtualEscola],
                MensagemA[128];
            Proximo++;
            if(Proximo >= sizeof(BCategoria))
            {
                pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(1, BCategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], BCategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], BCategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], 0.0, 0.0, 0.0, 5.0, 0, 0, playerid, 500.0, -1, 0);
                format(MensagemA, sizeof(MensagemA), "| AUTO-ESCOLA | Siga para o último checkpoint ( {00BFFF}%d/%d{FFFFFF} )", pEscola[playerid][AtualEscola], sizeof(BCategoria));
                SendClientMessage(playerid, -1, MensagemA);
                PlayerPlaySound(playerid, 1057, 0, 0, 0);
            }
            else
            {
                pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(0, BCategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], BCategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], BCategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], BCategoria[Proximo][PosicaoCatX], BCategoria[Proximo][PosicaoCatY], BCategoria[Proximo][PosicaoCatZ], 5.0, 0, 0, playerid, 500.0, -1, 0);
                format(MensagemA, sizeof(MensagemA), "| AUTO-ESCOLA | Vá até o próximo checkpoint ( {00BFFF}%d/%d{FFFFFF} )", pEscola[playerid][AtualEscola], sizeof(BCategoria));
                SendClientMessage(playerid, -1, MensagemA);
                PlayerPlaySound(playerid, 1057, 0, 0, 0);
            }
            pEscola[playerid][AtualEscola]++;
        }

        else if(!strcmp(pEscola[playerid][CategoriaAEscola], "CategoriaC"))
        {
            DestroyDynamicRaceCPEx(pEscola[playerid][AutoCheckPoint]);
            if(pEscola[playerid][AtualEscola] >= sizeof(CCategoria))
            {
                pEscola[playerid][AtualEscola] = 0;
                pEscola[playerid][FazendoProva] = false;
                DisableRemoteVehicleCollisions(playerid, 0);

                for(new i=0; i < sizeof(Pick); i++){
                    if(Pick[i][LocalID] == Jogador[playerid][uInterior]){
                        SetPlayerPos(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
                        Jogador[playerid][uInterior] = 0;
                        break;
                    }
                }

                new Float:VidaPega;
                GetVehicleHealth(pEscola[playerid][VeiculoAEscola], VidaPega);
                DestroyVehicleEx(pEscola[playerid][VeiculoAEscola]);
                if(VidaPega < 700) return SendClientMessage(playerid, 0xFF4500FF, "| AUTO-ESCOLA | Você foi reprovado(a) por danificar seu veículo!");
                Jogador[playerid][CarteiraC] = 1;
                VerificarCarteiraSQL(playerid);
                SendClientMessage(playerid, -1, "| AUTO-ESCOLA | Sua habilitação de caminhões foi aprovada com sucesso.");
                return 1;
            }

            new Proximo = pEscola[playerid][AtualEscola],
                MensagemA[128];
            Proximo++;
            if(Proximo >= sizeof(CCategoria))
            {
                pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(1, CCategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], CCategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], CCategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], 0.0, 0.0, 0.0, 5.0, 0, 0, playerid, 500.0, -1, 0);
                format(MensagemA, sizeof(MensagemA), "| AUTO-ESCOLA | Siga para o último checkpoint ( {00BFFF}%d/%d{FFFFFF} )", pEscola[playerid][AtualEscola], sizeof(CCategoria));
                SendClientMessage(playerid, -1, MensagemA);
                PlayerPlaySound(playerid, 1057, 0, 0, 0);
            }
            else
            {
                pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(0, CCategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], CCategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], CCategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], CCategoria[Proximo][PosicaoCatX], CCategoria[Proximo][PosicaoCatY], CCategoria[Proximo][PosicaoCatZ], 5.0, 0, 0, playerid, 500.0, -1, 0);
                format(MensagemA, sizeof(MensagemA), "| AUTO-ESCOLA | Vá até o próximo checkpoint ( {00BFFF}%d/%d{FFFFFF} )", pEscola[playerid][AtualEscola], sizeof(CCategoria));
                SendClientMessage(playerid, -1, MensagemA);
                PlayerPlaySound(playerid, 1057, 0, 0, 0);
            }
            pEscola[playerid][AtualEscola]++;
        }

        else if(!strcmp(pEscola[playerid][CategoriaAEscola], "CategoriaD"))
        {
            DestroyDynamicRaceCPEx(pEscola[playerid][AutoCheckPoint]);
            if(pEscola[playerid][AtualEscola] >= sizeof(DCategoria))
            {
                pEscola[playerid][AtualEscola] = 0;
                pEscola[playerid][FazendoProva] = false;
                DisableRemoteVehicleCollisions(playerid, 0);

                for(new i=0; i < sizeof(Pick); i++){
                    if(Pick[i][LocalID] == Jogador[playerid][uInterior]){
                        SetPlayerPos(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
                        Jogador[playerid][uInterior] = 0;
                        break;
                    }
                }

                new Float:VidaPega;
                GetVehicleHealth(pEscola[playerid][VeiculoAEscola], VidaPega);
                DestroyVehicleEx(pEscola[playerid][VeiculoAEscola]);
                if(VidaPega < 700) return SendClientMessage(playerid, 0xFF4500FF, "| AUTO-ESCOLA | Você foi reprovado(a) por danificar seu veículo!");
                Jogador[playerid][CarteiraD] = 1;
                VerificarCarteiraSQL(playerid);
                SendClientMessage(playerid, -1, "| AUTO-ESCOLA | Sua habilitação de ônibus foi aprovada com sucesso.");
                return 1;
            }

            new Proximo = pEscola[playerid][AtualEscola],
                MensagemA[128];
            Proximo++;
            if(Proximo >= sizeof(DCategoria))
            {
                pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(1, DCategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], DCategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], DCategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], 0.0, 0.0, 0.0, 5.0, 0, 0, playerid, 500.0, -1, 0);
                format(MensagemA, sizeof(MensagemA), "| AUTO-ESCOLA | Siga para o último checkpoint ( {00BFFF}%d/%d{FFFFFF} )", pEscola[playerid][AtualEscola], sizeof(DCategoria));
                SendClientMessage(playerid, -1, MensagemA);
                PlayerPlaySound(playerid, 1057, 0, 0, 0);
            }
            else
            {
                pEscola[playerid][AutoCheckPoint] = CreateDynamicRaceCP(0, DCategoria[pEscola[playerid][AtualEscola]][PosicaoCatX], DCategoria[pEscola[playerid][AtualEscola]][PosicaoCatY], DCategoria[pEscola[playerid][AtualEscola]][PosicaoCatZ], DCategoria[Proximo][PosicaoCatX], DCategoria[Proximo][PosicaoCatY], DCategoria[Proximo][PosicaoCatZ], 5.0, 0, 0, playerid, 500.0, -1, 0);
                format(MensagemA, sizeof(MensagemA), "| AUTO-ESCOLA | Vá até o próximo checkpoint ( {00BFFF}%d/%d{FFFFFF} )", pEscola[playerid][AtualEscola], sizeof(DCategoria));
                SendClientMessage(playerid, -1, MensagemA);
                PlayerPlaySound(playerid, 1057, 0, 0, 0);
            }
            pEscola[playerid][AtualEscola]++;
        }

    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(pEscola[playerid][FazendoProva] == true)
    {
        if(oldstate == PLAYER_STATE_DRIVER && newstate == PLAYER_STATE_ONFOOT)
        {
            pEscola[playerid][AtualEscola] = 0;
            pEscola[playerid][FazendoProva] = false;
            DisableRemoteVehicleCollisions(playerid, 0);
            DestroyVehicleEx(pEscola[playerid][VeiculoAEscola]);
            DestroyDynamicRaceCPEx(pEscola[playerid][AutoCheckPoint]);
            for(new i=0; i < sizeof(Pick); i++){
                if(Pick[i][LocalID] == Jogador[playerid][uInterior]){
                    SetPlayerPos(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
                    Jogador[playerid][uInterior] = 0;
                    break;
                }
            }
            SendClientMessage(playerid, 0xFF4500FF, "| AUTO-ESCOLA | Você foi reprovado(a) - Saiu ou caiu do veículo");
        }
    }
    return 1;
}

function AutoEscolaVeri(playerid)
{
    if(pEscola[playerid][FazendoProva] == true)
    {
        new Float:VidaaHhHhH;
        GetVehicleHealth(pEscola[playerid][VeiculoAEscola], VidaaHhHhH);
        if(VidaaHhHhH < 400.0)
        {
            DestroyDynamicRaceCPEx(pEscola[playerid][AutoCheckPoint]);
            pEscola[playerid][AtualEscola] = 0;
            pEscola[playerid][FazendoProva] = false;
            DisableRemoteVehicleCollisions(playerid, 0);
            DestroyVehicleEx(pEscola[playerid][VeiculoAEscola]);
            for(new i=0; i < sizeof(Pick); i++){
                if(Pick[i][LocalID] == Jogador[playerid][uInterior]){
                    SetPlayerPos(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
                    Jogador[playerid][uInterior] = 0;
                    break;
                }
            }
            SendClientMessage(playerid, 0xFF4500FF, "| AUTO-ESCOLA | Você foi reprovado(a) - Veículo danificado");    
            return 1;
        }
        SetTimerEx("AutoEscolaVeri", 2000, false, "d", playerid);
    }
    return 1;
}

stock VerificarCarteiraSQL(playerid)
{
    new SalvarSQL[128];
    format(SalvarSQL, sizeof(SalvarSQL), "INSERT INTO `carteiras` (`Nome`) VALUES ('%s')", EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, SalvarSQL, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao criar sua habilitação, chame um desenvolvedor(a)");
    return 1;
}