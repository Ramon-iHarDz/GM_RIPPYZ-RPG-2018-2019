stock VerificarCarroForte(vehicleid)
{
    for(new i=0; i < sizeof(CFSpawn); i++){
        if(CarroF[i] != vehicleid) continue;
        return true;
    }
    return false;
}

stock VerificarCarregandoCF(id)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(pCF[i][CarregandoCF] == 0) continue;
        if(pCF[i][CFID] == id) return true;

    }
    return false;
}

stock VerificarPertoCaixa(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 80.0, 596.7069, -1287.5359, 15.6685) ||
    IsPlayerInRangeOfPoint(playerid, 80.0, -2660.4138, 375.7323, 4.1390) ||
    IsPlayerInRangeOfPoint(playerid, 80.0, 2370.0889, 2470.1936, 10.6719)) return true;

    for(new i=0; i < MAX_CAIXAS; i++){
        if(pCaixa[i][Conectado] == false) continue;
        if(IsPlayerInRangeOfPoint(playerid, 60.0, pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ])) return true;
    }
    return false;
}

stock EnviarAssaltoCF(playerid)
{
    SetPVarInt(playerid, "Carff", 0);
    DestroyDynamicRaceCPEx(pCF[playerid][CPCaixa]);
    DestroyDynamicMapIconEx(pCF[playerid][CFIcone]);
    DestroyDynamic3DTextLabelEx(pCF[playerid][CFTextoID]);
    Jogador[playerid][Trabalhando] = false;
    pCF[playerid][CarregandoCF] = 0;
    if(pCF[playerid][CFMaleta] == true){
        RemovePlayerAttachedObject(playerid, 9);
        pCF[playerid][CFMaleta] = false;
    }
    return true;
}