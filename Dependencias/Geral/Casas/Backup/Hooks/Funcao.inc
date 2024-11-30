function VerificarMorador(const MoradorNome[], casa){
    for(new i=0; i < MAX_MORADOR; i++){
        if(!strcmp(MoradorNome, pMorador[casa][i][Morador])) return true;
    }
    return false;
}

function VerificarSeTemMorador(id)
{
    for(new i=0; i < MAX_MORADOR; i++){
        if(strcmp(pMorador[id][i][Morador], "*")) return true;
    } 
    return false;
}

function PegarInteriorCasa(id)
{
    new iid = pCasa[id][cInterior];
    iid -= 1;
    return pInterior[iid][Interior];
}

function PegarVirtualCasa(id)
{
    new vw = id;
    vw++;
    vw = (vw*vw); 
    return vw;
}

function MinhaCasaID(playerid)
{
    new bsda[30];
    format(bsda, 30, PegarNick(playerid));
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(!strcmp(pCasa[i][cDono], "*")) continue;
        if(!strcmp(pCasa[i][cDono], bsda)) return i;
        else
        {
            for(new o=0; o < MAX_MORADOR; o++)
            {
                if(!strcmp(pMorador[i][o][Morador], "*")) continue;
                if(!strcmp(pMorador[i][o][Morador], bsda)) return i; 
            }
        }
    }
    return -1;
}

function MinhaCasaIDEx(playerid)
{
    new bsda[30];
    format(bsda, 30, PegarNick(playerid));
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(!strcmp(pCasa[i][cDono], "*")) continue;
        if(!strcmp(pCasa[i][cDono], bsda)) return i;
    }
    return -1;
}

function CasaID()
{
    for(new i=1; i < MAX_CASAS; i++){
        if(pCasa[i][Colocado] == true) continue;
        return i;
    }
    return 1;
}

stock PegarCasaStatus(sts)
{
    new CadeadoI[128];
    if(sts == 0) CadeadoI = "{FFFFFF}Destrancada";
    else if(sts == 1) CadeadoI = "{FF0000}Trancada com Senha";
    else if(sts == 2) CadeadoI = "{FF0000}Trancada";
    return CadeadoI;
}

function AtualizarCasa(id)
{
    DestroyDynamic3DTextLabelEx(pCasa[id][cTexto]);
    DestroyDynamicMapIconEx(pCasa[id][cMapa]);
    DestroyDynamicPickupEx(pCasa[id][cPickup]);
    DestroyDynamicObjectEx(pCasa[id][LixoOb]);
    AdicionarCasa(id);
    return 1;
}

function VerificarSeTemCasa(playerid)
{
    new bsda[30];
    format(bsda, 30, PegarNick(playerid));
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(!strcmp(pCasa[i][cDono], "*")) continue;
        if(!strcmp(pCasa[i][cDono], bsda)) return true;
        else
        {
            for(new o=0; o < MAX_MORADOR; o++)
            {
                if(!strcmp(pMorador[i][o][Morador], "*")) continue;
                if(!strcmp(pMorador[i][o][Morador], bsda)) return true; 
            }
        }
    }
    return false;
}

function MoraNessaCasa(playerid, id)
{
    new bsda[30];
    format(bsda, 30, PegarNick(playerid));
    if(!strcmp(pCasa[id][cDono], bsda)) return true;
    for(new o=0; o < MAX_MORADOR; o++)
    {
        if(!strcmp(pMorador[id][o][Morador], "*")) continue;
        if(!strcmp(pMorador[id][o][Morador], bsda)) return true; 
    }
    return false;
}

function EntrarCasa(playerid, i)
{
    if(cAC[playerid][Travado] == true) return 1;
    //if(pMorreu[playerid][EstaCaido] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está ferido(a)");

    //Setar algumas informações
    Jogador[playerid][uInteriorEx] = 1;
    GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
    SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);
    SetPVarInt(playerid, "InteriorPersonalizadoID", i);

    new iid = pCasa[i][cInterior],
        vw = i,
        Mensagem[128];
    vw++;
    vw = (vw*vw);
    iid -= 1;

    //Setando dentro da casa
    TogglePlayerControllable(playerid, 0);
    SetPlayerVirtualWorld(playerid, vw);
    SetPlayerInterior(playerid, pInterior[iid][Interior]);
    SetPlayerPos(playerid, pInterior[iid][cInterX], pInterior[iid][cInterY], pInterior[iid][cInterZ]);
    SetPlayerFacingAngle(playerid, pInterior[iid][cInterA]);
    SetTimerEx("Destravar", 3000, false, "d", playerid);

    if(!strcmp(pCasa[i][cDono], PegarNick(playerid))) format(Mensagem, sizeof(Mensagem), "| CASA | Bem-Vindo(a) a sua casa {FF8C00}%d", i);
    else if(!strcmp(pCasa[i][cDono], "*")) format(Mensagem, sizeof(Mensagem), "| CASA | Você entrou na casa id {FF8C00}%d{FFFFFF} que não possui dono(a)", i);
    else format(Mensagem, sizeof(Mensagem), "| CASA | Você entrou na casa de {FF8C00}%s", pCasa[i][cDono]);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

function PrecoCasaImpostos(id)
{
    new IntA = pCasa[id][cInterior],
        foced;
    IntA -= 1;
    foced = (pInterior[IntA][ImpostoInterior]*pCasa[id][Impostos]);
    return foced;
}

stock InteriorUpgrade(playerid, id, listitem, &InteriorFinal, &ValorReal, bool:VendaChoose = false)
{
    if(pCasa[id][cPreco] > 0 && pCasa[id][cCoins] < 1) SetPVarInt(playerid, "MultiPlicacacoaDaCasa", pCasa[id][cPreco]);
    else if(pCasa[id][cPreco] < 1 && pCasa[id][cCoins] > 0) SetPVarInt(playerid, "MultiPlicacacoaDaCasa", (pCasa[id][cCoins]+250000));
    else SetPVarInt(playerid, "MultiPlicacacoaDaCasa", (pCasa[id][cCoins] + pCasa[id][cPreco]));

    new OutroValor,
        UpSelecionado;

    for(new i=1; i < pCasa[id][cInteriorMax]+1; i++)  
    {
        if(VendaChoose == false)
        {
            if(i > pCasa[id][cInterior])
            {
                if(UpSelecionado != listitem){
                    UpSelecionado++;
                    continue;
                }  
                new Cambiarra = UpSelecionado += 1;
                OutroValor = GetPVarInt(playerid, "MultiPlicacacoaDaCasa");
                ValorReal = OutroValor*Cambiarra;
                InteriorFinal = i;
                break;
            }
        }
        else
        {
            if(UpSelecionado != listitem){
                UpSelecionado++;
                continue;
            }  
            new Cambiarra = UpSelecionado += 1;
            OutroValor = GetPVarInt(playerid, "MultiPlicacacoaDaCasa");
            ValorReal = OutroValor*Cambiarra;
            InteriorFinal = i;
            break;
        }
    }
    return 1;
}

function ReiniciarCasa(bool:modo)
{
    new Enviar[300],
        llbr;
    print("[Rippzy:Casa] Salvando Casa.");
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(!strcmp(pCasa[i][cDono], "*")) continue;
        
        //String
        new LiberacaoMotivo[50] = "*";

        //Adicionar Lixos e Impostos
        if(modo == true)
        {
            pCasa[i][LixoD]++;
            pCasa[i][Impostos]++;

            if(pCasa[i][Impostos] >= 7) LiberacaoMotivo = "Impostos Atrasados";
            else if(pCasa[i][LixoD] >= 8) LiberacaoMotivo = "Lixos Acumulado [Dentro]";
            else if(pCasa[i][LixoF] >= 8) LiberacaoMotivo = "Lixos Acumulado [Fora]";
        }

        if(strcmp(LiberacaoMotivo, "*"))
        {
            llbr++;
            RemoverMoveisAdmin(i);
            format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Dono`='*', `jPreco` = 0, `Morador1`='*', `Morador2`='*', `Morador3`='*', `Morador4`='*', `LixoF`=0, `LixoD`=0, `Interior`=1, `Mensagem`='*', `Senha`='*', `Impostos`=0, `Tranca`=0 WHERE `Numero` = %d", pCasa[i][Numero]);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) printf("[ RC-Casa ] Houve um problema ao remover a casa %d", pCasa[i][Numero]);

            format(Enviar, sizeof(Enviar), "INSERT INTO `logcasa` (`CasaID`, `Motivo`, `Tempo`) VALUES (%d, '%s', %d)", i, LiberacaoMotivo, gettime());
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) printf("[ RC-Casa ] Houve um problema ao salvar a log da casa %d", pCasa[i][Numero]);
        }
        else
        {
            format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Impostos`=%d, `LixoD`=%d WHERE `Numero`=%d", pCasa[i][Impostos], pCasa[i][LixoD], pCasa[i][Numero]);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) printf("[ RC-Casa ] Houve um problema ao salvar a casa número %d", pCasa[i][Numero]);
        }

        if(modo == true && !strcmp(LiberacaoMotivo, "*"))
        {
            format(Enviar, sizeof(Enviar), "UPDATE `moveis` SET `Status` = 0 WHERE `Casa` = %d", pCasa[i][Numero]);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) printf("[ RC-Casa ] Houve um problema remover status dos móveis da casa número %d", pCasa[i][Numero]);
        }
    }
    printf("[Rippzy:Casa] Casas salvas com sucesso. ( Liberadas: %d )", llbr);
    return 1;
} 

function DebugCasa(playerid)
{
    RemoveBuildingForPlayer(playerid, 14720, 216.5547, 1292.2188, 1081.1172, 0.25);
    RemoveBuildingForPlayer(playerid, 14719, 218.7422, 1290.8203, 1082.8672, 0.25);
    RemoveBuildingForPlayer(playerid, 2524, 225.1563, 1085.5313, 1086.8125, 0.25);
    RemoveBuildingForPlayer(playerid, 2526, 227.4766, 1087.1875, 1086.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 2525, 225.1563, 1087.2734, 1086.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 2528, 232.6328, 1110.5938, 1079.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 2523, 232.6563, 1108.8281, 1079.9922, 0.25);
    RemoveBuildingForPlayer(playerid, 2520, 234.6016, 1109.3828, 1079.9453, 0.25);
    RemoveBuildingForPlayer(playerid, 2522, 235.6016, 1112.2422, 1079.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 2523, 234.7188, 1117.4609, 1083.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 2528, 234.6172, 1119.2266, 1083.9766, 0.25);
    RemoveBuildingForPlayer(playerid, 2520, 237.3438, 1119.1641, 1083.9609, 0.25);
    RemoveBuildingForPlayer(playerid, 2522, 234.6953, 1120.1563, 1083.9297, 0.25);
    RemoveBuildingForPlayer(playerid, 14721, 240.4609, 1114.3906, 1083.2891, 0.25);
    RemoveBuildingForPlayer(playerid, 2524, 252.3594, 1247.9922, 1083.2422, 0.25);
    RemoveBuildingForPlayer(playerid, 2525, 252.5703, 1249.2109, 1083.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 2526, 253.7656, 1249.1797, 1083.2344, 0.25);
    RemoveBuildingForPlayer(playerid, 2523, 249.6953, 1291.7813, 1079.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 2528, 249.5938, 1293.5469, 1079.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 2520, 252.3203, 1293.4844, 1079.2344, 0.25);
    RemoveBuildingForPlayer(playerid, 2522, 249.6719, 1294.4766, 1079.2031, 0.25);
    RemoveBuildingForPlayer(playerid, 2523, 284.5078, 1480.5156, 1079.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 2528, 284.4063, 1482.2813, 1079.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 2522, 284.4844, 1484.4219, 1079.1953, 0.25);
    RemoveBuildingForPlayer(playerid, 2520, 287.1328, 1483.4297, 1079.2266, 0.25);
    RemoveBuildingForPlayer(playerid, 14704, 450.9844, 1406.5781, 1084.2891, 0.25);
    RemoveBuildingForPlayer(playerid, 14705, 451.7734, 1409.4141, 1084.7422, 0.25);
    RemoveBuildingForPlayer(playerid, 2520, 445.3125, 1410.6328, 1083.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 2528, 444.2188, 1413.0391, 1083.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 2523, 444.3203, 1414.0000, 1083.3359, 0.25);
    RemoveBuildingForPlayer(playerid, 2522, 447.9766, 1414.2656, 1083.2813, 0.25);
    RemoveBuildingForPlayer(playerid, 14742, 2451.9063, -1701.1875, 1014.8594, 0.25);
    RemoveBuildingForPlayer(playerid, 14763, 2447.7500, -1694.2578, 1014.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 14741, 2447.4219, -1693.4531, 1012.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 14740, 2447.0234, -1686.9922, 1014.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 14761, 2449.9609, -1690.8438, 1014.0547, 0.25);
    RemoveBuildingForPlayer(playerid, 14745, 2460.2422, -1695.1016, 1012.9453, 0.25);
    RemoveBuildingForPlayer(playerid, 2527, -64.8281, 1355.4609, 1079.1719, 0.25);
    RemoveBuildingForPlayer(playerid, 2526, -64.1875, 1353.5781, 1079.1797, 0.25);
    RemoveBuildingForPlayer(playerid, 2525, -62.7734, 1356.4844, 1079.1953, 0.25);
    RemoveBuildingForPlayer(playerid, 14757, 154.2656, 1369.5234, 1084.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 2516, -37.8047, 1410.5156, 1083.4063, 0.25);
    RemoveBuildingForPlayer(playerid, 2517, -37.3828, 1408.5781, 1083.4375, 0.25);
    RemoveBuildingForPlayer(playerid, 2739, -34.8203, 1409.3359, 1083.4063, 0.25);
    RemoveBuildingForPlayer(playerid, 2514, -34.8125, 1409.6250, 1083.4063, 0.25);
    RemoveBuildingForPlayer(playerid, 1739, 149.2266, 1381.5234, 1083.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 1739, 149.2266, 1380.5469, 1083.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 1739, 151.5469, 1380.5469, 1083.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 1739, 151.5469, 1381.5234, 1083.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 2117, 150.4297, 1381.6016, 1082.8516, 0.25);
    RemoveBuildingForPlayer(playerid, 1739, 149.2266, 1382.7422, 1083.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 1739, 151.5469, 1382.6563, 1083.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 2117, 150.4297, 1383.5938, 1082.8516, 0.25);
    RemoveBuildingForPlayer(playerid, 1739, 151.5469, 1383.7500, 1083.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 1739, 149.2266, 1383.8203, 1083.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 2023, 2305.5547, -1212.6406, 1048.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 1768, 2305.8281, -1210.3750, 1048.0000, 0.25);
    RemoveBuildingForPlayer(playerid, 1818, 2308.8438, -1208.9141, 1048.0078, 0.25);
    RemoveBuildingForPlayer(playerid, 1717, 2305.7813, -1207.8125, 1048.0078, 0.25);
    RemoveBuildingForPlayer(playerid, 1764, 2310.9844, -1209.1797, 1048.0078, 0.25);
    RemoveBuildingForPlayer(playerid, 2100, 2311.5547, -1206.6719, 1048.0234, 0.25);
    RemoveBuildingForPlayer(playerid, 15052, 2313.8438, -1212.7344, 1049.5547, 0.25);
    RemoveBuildingForPlayer(playerid, 15056, 2313.8438, -1212.7344, 1049.5234, 0.25);
    RemoveBuildingForPlayer(playerid, 1567, 2231.2969, -1111.4609, 1049.8594, 0.25);
    RemoveBuildingForPlayer(playerid, 15039, 2232.3438, -1106.7422, 1049.7500, 0.25);
    RemoveBuildingForPlayer(playerid, 15038, 2235.2891, -1108.1328, 1051.2656, 0.25);
    RemoveBuildingForPlayer(playerid, 15032, 2278.5547, -1136.6250, 1051.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 15036, 2278.5859, -1135.2266, 1051.0313, 0.25);
    RemoveBuildingForPlayer(playerid, 15051, 2279.9375, -1135.8203, 1049.7656, 0.25);
    RemoveBuildingForPlayer(playerid, 1764, 2286.1250, -1138.4766, 1049.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 1567, 2286.6875, -1138.4219, 1049.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 15037, 2280.5703, -1137.7422, 1050.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 2099, 2281.1953, -1136.0156, 1049.8828, 0.25);
    return 1;
}

function PrepararCasa()
{
    print("[Rippzy:Interior] Removendo móveis de Interiores");

    // Interior ( 1 ) 
    CreateDynamicObject(15034, 2233.24219, -1111.08594, 1051.62500,   0.00000, 0.00000, 0.00000, -1, 6, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1535, 2232.92969, -1115.67969, 1049.86719,   0.00000, 0.00000, 0.00000, -1, 6, -1, 160.0, 160.0, -1);

    // Interior ( 2 )
    CreateDynamicObject(14709, 222.72656, 1150.16406, 1083.07813,   0.00000, 0.00000, 0.00000, -1, 5, -1, 160.0, 160.0, -1);

    // Interior ( 3 )
    CreateDynamicObject(1535, 2282.17603, -1140.72119, 1049.71863,   0.00000, 0.00000, 0.00000, -1, 19, -1, 160.0, 160.0, -1);
    CreateDynamicObject(15031, 2279.93750, -1135.82031, 1049.72644,   0.00000, 0.00000, 0.00000, -1, 19, -1, 160.0, 160.0, -1);

    // Interior ( 4 )
    CreateDynamicObject(1498, -68.06250, 1350.77344, 1079.20313,   0.00000, 0.00000, 180.00000, -1, 7, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14755, -68.66406, 1343.54688, 1080.46094,   0.00000, 0.00000, 0.00000, -1, 7, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, -66.53906, 1355.72656, 1079.19531,   0.00000, 0.00000, -90.0000, -1, 7, -1, 160.0, 160.0, -1);

    // Interior ( 5 )
    CreateDynamicObject(14718, 220.12500, 1291.62500, 1081.13281,   0.00000, 0.00000, 0.00000, -1, 2, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 219.07031, 1287.03125, 1081.13281,   0.00000, 0.00000, 90.0000, -1, 2, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1498, 222.36719, 1286.62500, 1081.12500,   0.00000, 0.00000, 0.00000, -1, 2, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 227.89844, 1289.18750, 1081.13281,   0.00000, 0.00000, 90.0000, -1, 2, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 221.10938, 1292.54688, 1081.13281,   0.00000, 0.00000, 90.0000, -1, 2, -1, 160.0, 160.0, -1);

    // Interior ( 6 )
    CreateDynamicObject(1498, 227.21094, 1240.73438, 1081.12500,   0.00000, 0.00000, -90.0000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14717, 222.82813, 1245.83594, 1082.87500,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);

    // Interior ( 7 )
    CreateDynamicObject(1498, 2469.26563, -1697.52344, 1012.50000,   0.00000, 0.00000, -90.0000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 2458.45313, -1696.89063, 1012.50000,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1734, 2452.03125, -1702.02344, 1015.96875,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14762, 2446.91406, -1690.98438, 1014.48438,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14744, 2458.01563, -1695.93750, 1014.28906,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14746, 2451.96875, -1702.14063, 1014.28906,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14743, 2458.01563, -1695.93750, 1014.28906,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 2457.04688, -1697.53906, 1012.50000,   0.00000, 0.00000, -90.0000, -1, 3, -1, 160.0, 160.0, -1);

    // Interior ( 8 )
    CreateDynamicObject(1506, -43.33594, 1405.03125, 1083.42969,   0.00000, 0.00000, 0.00000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14756, -42.57813, 1405.77344, 1085.42969,   0.00000, 0.00000, -90.00000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, -40.41406, 1408.36719, 1083.42969,   0.00000, 0.00000, 90.0000, -1, 9, -1, 160.0, 160.0, -1);

    // Interior ( 9 )
    CreateDynamicObject(1498, 377.57813, 1418.09375, 1080.33594,   0.00000, 0.00000, -90.0000, -1, 16, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 372.03125, 1415.45313, 1080.33594,   0.00000, 0.00000, 0.00000, -1, 16, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 366.62500, 1419.11719, 1080.33594,   0.00000, 0.00000, 0.00000, -1, 16, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 359.68750, 1412.08594, 1080.33594,   0.00000, 0.00000, 0.00000, -1, 16, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14710, 367.84375, 1420.55469, 1081.84375,   0.00000, 0.00000, 0.00000, -1, 16, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 367.64844, 1426.67188, 1080.33594,   0.00000, 0.00000, 0.00000, -1, 16, -1, 160.0, 160.0, -1);

    // Interior ( 10 )
    CreateDynamicObject(1498, 387.64844, 1472.51563, 1079.18750,   0.00000, 0.00000, -90.0000, -1, 17, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14711, 378.55469, 1464.31250, 1080.78906,   0.00000, 0.00000, 0.00000, -1, 17, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 380.67188, 1470.06250, 1079.17188,   0.00000, 0.00000, 0.00000, -1, 17, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 372.82031, 1466.21094, 1079.17188,   0.00000, 0.00000, 0.00000, -1, 17, -1, 160.0, 160.0, -1);

    // Interior ( 11 )
    CreateDynamicObject(1498, 294.36719, 1471.80469, 1079.24219,   0.00000, 0.00000, 0.00000, -1, 18, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 293.69531, 1474.58594, 1079.28125,   0.00000, 0.00000, -90.0000, -1, 18, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 297.27344, 1474.75000, 1079.28125,   0.00000, 0.00000, -90.0000, -1, 18, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 297.28906, 1481.50000, 1079.28125,   0.00000, 0.00000, -90.0000, -1, 18, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 288.14063, 1481.24219, 1079.28125,   0.00000, 0.00000, -90.0000, -1, 18, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 294.57031, 1482.87500, 1079.28125,   0.00000, 0.00000, 0.00000, -1, 18, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14714, 295.14063, 1479.96875, 1081.06250,   0.00000, 0.00000, 0.00000, -1, 18, -1, 160.0, 160.0, -1);

    // Interior ( 12 )
    CreateDynamicObject(1498, 260.00000, 1236.78125, 1083.23438,   0.00000, 0.00000, 0.00000, -1, 10, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 258.57813, 1247.10156, 1083.27344,   0.00000, 0.00000, -90.0000, -1, 10, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14712, 257.79688, 1244.47656, 1084.82813,   0.00000, 0.00000, 0.00000, -1, 10, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 256.26563, 1250.87500, 1083.27344,   0.00000, 0.00000, 0.00000, -1, 10, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 255.71875, 1246.96094, 1083.27344,   0.00000, 0.00000, 90.0000, -1, 10, -1, 160.0, 160.0, -1);

    // Interior ( 13 )
    CreateDynamicObject(1498, 260.26563, 1283.84375, 1079.24219,   0.00000, 0.00000, 0.00000, -1, 5, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 262.16406, 1291.30469, 1079.28125,   0.00000, 0.00000, 90.0000, -1, 5, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 259.78906, 1286.64063, 1079.28125,   0.00000, 0.00000, 90.0000, -1, 5, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 262.16406, 1286.97656, 1079.28125,   0.00000, 0.00000, 90.0000, -1, 5, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14713, 255.86719, 1288.90625, 1081.06250,   0.00000, 0.00000, 0.00000, -1, 5, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 253.35938, 1291.69531, 1079.28125,   0.00000, 0.00000, 90.0000, -1, 5, -1, 160.0, 160.0, -1);

    // Interior ( 14 )
    CreateDynamicObject(14748, 24.41406, 1408.00000, 1085.42969,   0.00000, 0.00000, -90.00000, -1, 6, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14749, 22.48438, 1413.22656, 1085.82813,   0.00000, 0.00000, -90.0000, -1, 6, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1506, 23.60938, 1402.91406, 1083.44531,   0.00000, 0.00000, -180.00000, -1, 6, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14752, 33.60938, 1413.41406, 1085.30469,   0.00000, 0.00000, -90.00000, -1, 6, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14747, 25.29688, 1411.27344, 1085.30469,   0.00000, 0.00000, -90.0000, -1, 6, -1, 160.0, 160.0, -1);

    // Interior ( 15 )
    CreateDynamicObject(1491, 446.17188, 1409.75000, 1083.29688,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1491, 449.59375, 1401.05469, 1083.29688,   0.00000, 0.00000, -90.0000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1491, 444.63281, 1400.66406, 1083.29688,   0.00000, 0.00000, 90.0000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1491, 444.63281, 1406.86719, 1083.29688,   0.00000, 0.00000, 90.0000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1506, 446.28906, 1396.62500, 1083.28125,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1491, 452.78125, 1409.69531, 1083.29688,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14701, 447.42969, 1407.10156, 1085.37500,   0.00000, 0.00000, 0.00000, -1, 3, -1, 160.0, 160.0, -1);

    // Interior ( 16 )
    CreateDynamicObject(1506, 24.75781, 1339.75000, 1083.35938,   0.00000, 0.00000, 180.00000, -1, 11, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14751, 34.53906, 1343.42188, 1085.82813,   0.00000, 0.00000, 0.00000, -1, 11, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 32.45313, 1343.09375, 1087.86719,   0.00000, 0.00000, 90.00000, -1, 11, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14750, 27.30469, 1349.10156, 1089.87500,   0.00000, 0.00000, 0.00000, -1, 11, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1502, 28.59375, 1345.91406, 1087.86719,   0.00000, 0.00000, 0.00000, -1, 11, -1, 160.0, 160.0, -1);


    // Interior ( 17 )
    CreateDynamicObject(14708, 235.21094, 1113.21094, 1081.75781,   0.00000, 0.00000, -90.00000, -1, 6, -1, 160.0, 160.0, -1);

    // Interior ( 18 )
    CreateDynamicObject(14706, 233.91406, 1075.82813, 1086.41406,   0.00000, 0.00000, 0.00000, -1, 7, -1, 160.0, 160.0, -1);

    // Interior ( 19 )
    CreateDynamicObject(1506, 138.76563, 1365.48438, 1082.85156,   0.00000, 0.00000, 0.00000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1506, 141.78906, 1365.50781, 1082.85156,   0.00000, 0.00000, 180.00000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14764, 139.52344, 1365.56250, 1084.73438,   0.00000, 0.00000, 0.00000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1491, 138.14844, 1382.32813, 1082.85938,   0.00000, 0.00000, -90.0000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1491, 146.34375, 1382.32813, 1082.84375,   0.00000, 0.00000, -90.0000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1491, 139.51563, 1382.00781, 1087.36719,   0.00000, 0.00000, 0.00000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1491, 149.66406, 1377.85938, 1087.35156,   0.00000, 0.00000, 0.00000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(1491, 149.66406, 1382.00781, 1087.36719,   0.00000, 0.00000, 0.00000, -1, 9, -1, 160.0, 160.0, -1);
    CreateDynamicObject(14758, 139.52344, 1365.56250, 1084.73438,   0.00000, 0.00000, 0.00000, -1, 9, -1, 160.0, 160.0, -1);

    print("[Rippzy:Interior] Móveis de casas foram removidos com sucesso.");

    return 1;
}