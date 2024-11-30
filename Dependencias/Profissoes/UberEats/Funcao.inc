enum UberEatsJogador
{
    bool:UberMoto,
    UberVid,
    BauID,
    DelayAlg,
    DinheiroUberTotal,
    CappaMoney,
    bool:ComEntrega,
    bool:BikeUber,

    // 
    Text3D:TextoUbb,
    bool:TextoVis, 
    uVehB
};

enum UberEntregas
{
    bool:EntregaAtiva,
    CheckAtiva,
    MapaAtiva,
    CasaUUber
};

new UberEntrega[MAX_PLAYERS][4][UberEntregas];
new mUber[MAX_PLAYERS][UberEatsJogador];

stock UberEntregaCasa(playerid)
{
    new CapEntrega = 0,
        cUID,
        Mensagem[128],
        bool:pdd = false;

    enum ReferenciaLocal{
        Float:RFX,
        Float:RFY,
        Float:RFZ
    };

    new RefereceLocal[][ReferenciaLocal] =
    {
        {2314.6733,-1390.1865,24.0420},
        {1731.4609,-2114.1238,13.3828},
        {361.9704,-1435.9763,34.2730}
    };
    new SourceRefect = random(sizeof(RefereceLocal));

    while(CapEntrega < 3)
    {
        cUID = random(MAX_CASAS);
        if(pCasa[cUID][Colocado] == false) continue;
        if(GetDistanceBetweenPoints(RefereceLocal[SourceRefect][RFX],RefereceLocal[SourceRefect][RFY], RefereceLocal[SourceRefect][RFZ], pCasa[cUID][cPosicaoX], pCasa[cUID][cPosicaoY], pCasa[cUID][cPosicaoZ]) > 1410.9) continue;
        if(VerificarApartamento(cUID)) continue;
        pdd = false;
        for(new o=1; o < 4; o++)
        {   
            if(UberEntrega[playerid][o][EntregaAtiva] == true) continue;
            for(new p=0; p < 4; p++)
            {
                if(UberEntrega[playerid][p][CasaUUber] != cUID) continue;
                pdd = true;
                break;
            }
            
            if(pdd == true) break;
            UberEntrega[playerid][o][CheckAtiva] = CreateDynamicCP(pCasa[cUID][cPosicaoX], pCasa[cUID][cPosicaoY], pCasa[cUID][cPosicaoZ], 1.0, 0, 0, playerid, 100.0);
            UberEntrega[playerid][o][MapaAtiva] = CreateDynamicMapIcon(pCasa[cUID][cPosicaoX], pCasa[cUID][cPosicaoY], pCasa[cUID][cPosicaoZ], 60, -1, 0, 0, playerid, 999999.0, MAPICON_GLOBAL);
            UberEntrega[playerid][o][EntregaAtiva] = true;
            UberEntrega[playerid][o][CasaUUber] = cUID;
            CapEntrega++;
            break;
        }
    }

    /*for(new i=0; i < 9999; i++)
    {
        cUID = random(MAX_CASAS);
        if(pCasa[cUID][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 990.0, pCasa[cUID][cPosicaoX], pCasa[cUID][cPosicaoY], pCasa[cUID][cPosicaoZ])) continue;
        if(VerificarApartamento(cUID)) continue;
        pdd = false;
        for(new o=1; o < 4; o++)
        {   
            if(UberEntrega[playerid][o][EntregaAtiva] == true) continue;
            for(new p=0; p < 4; p++)
            {
                if(UberEntrega[playerid][p][CasaUUber] != cUID) continue;
                pdd = true;
                break;
            }
            
            if(pdd == true) break;
            UberEntrega[playerid][o][CheckAtiva] = CreateDynamicCP(pCasa[cUID][cPosicaoX], pCasa[cUID][cPosicaoY], pCasa[cUID][cPosicaoZ], 1.0, 0, 0, playerid, 100.0);
            UberEntrega[playerid][o][MapaAtiva] = CreateDynamicMapIcon(pCasa[cUID][cPosicaoX], pCasa[cUID][cPosicaoY], pCasa[cUID][cPosicaoZ], 60, -1, 0, 0, playerid, 999999.0, MAPICON_GLOBAL);
            UberEntrega[playerid][o][EntregaAtiva] = true;
            UberEntrega[playerid][o][CasaUUber] = cUID;
            CapEntrega++;
            break;
        }
        if(CapEntrega >= 3) break;
    }*/
    if(CapEntrega <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nenhuma casa foi informada pela empresa, tente novamente!");
    else
    {
        mUber[playerid][CappaMoney] = CapEntrega;
        format(Mensagem, sizeof(Mensagem), "| ENTREGA | Você tem {00BFFF}%d{FFFFFF} entrega(s) para fazer, siga o(s) ponto(s) no mapa", CapEntrega);
        SendClientMessage(playerid, -1, Mensagem);
    }
    return 1;
}

stock EntregandoUber(playerid)
{
    for(new i=0; i < 4; i++){
        if(UberEntrega[playerid][i][EntregaAtiva] == false) continue;
        return true;
    }
    return false;
}

stock ResetarUber(playerid)
{
    for(new i=0; i < 4; i++){
        UberEntrega[playerid][i][EntregaAtiva] = false;
    }
    return 1;
}

stock VerificarInterior(interiorid)
{
    for(new i=0; i < sizeof(iEmpresa); i++){
        if(iEmpresa[i][eListaID] != interiorid) continue;
        if(strcmp(iEmpresa[i][Tipo], "Lanchonetes")) continue;
        return true;        
    }
    return false;
}