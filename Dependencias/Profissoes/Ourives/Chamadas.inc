function Cavando(playerid)
{
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "{1E90FF}Pedra %s[%d]\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para pegar", PegarNick(playerid), playerid);

    TogglePlayerControllable(playerid, 1);

    ClearAnimations(playerid);
    pOurives[playerid][PedraOuroID] = CreateDynamicObject(2936, pOurives[playerid][OuroPosX], pOurives[playerid][OuroPosY], pOurives[playerid][OuroPosZ], 0.0, 0.0, 0.0, 0, 0, -1, 100.0, 100.0, -1);
    pOurives[playerid][TextoOID][0] = CreateDynamic3DTextLabel(Mensagem, -1, pOurives[playerid][OuroPosX], pOurives[playerid][OuroPosY], pOurives[playerid][OuroPosZ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.0, -1);
    pOurives[playerid][TextoOID][1] = CreateDynamic3DTextLabel("Aperta {CCCCCC}'H'{FFFFFF} para pegar uma caixa", -1, 0.0000, -4.0999, -0.9000, 15.0, INVALID_PLAYER_ID, pOurives[playerid][VeiculoOID], 0, 0, 0, playerid, 10.0, -1);
    SendClientMessage(playerid, 0xFFFF00FF, "| OURIVES | Você achou algo na pedra, pegue uma caixa atrás do veículo");
    pOurives[playerid][CavandoStatus] = 2;
    return 1;
} 

stock VerificarTrabalhoOuro(playerid)
{
    for(new i=0; i < 5; i++)
    {
        if(pOCaixa[playerid][i][TemCaixa] == false) continue;
        return true;
    }
    return false;
}

stock RestamOuros(playerid)
{
    new Contt = 0;
    for(new i=0; i < 5; i++)
    {
        if(pOCaixa[playerid][i][TemCaixa] == true) continue;
        Contt++;
    }
    return Contt;
}

stock ResetarCaixasOuro(playerid)
{
    for(new i=0; i < 5; i++)
    {
        if(pOCaixa[playerid][i][TemCaixa] == false) continue;
        DestroyDynamicObjectEx(pOCaixa[playerid][i][CaixaOID]);
        pOCaixa[playerid][i][TemCaixa] = false;
    }
    return 1;
}

stock RetirarMaisUmOuro(playerid)
{
    for(new i=0; i < 5; i++){
        if(pOCaixa[playerid][i][TemCaixa] == false) continue;
        pOCaixa[playerid][i][TemCaixa] = false;
        break;
    }
    return 1;
}

stock VerificarPedrasOuro(playerid)
{
    new kaka = 0;
    for(new i=0; i < 5; i++){
        if(pOCaixa[playerid][i][TemCaixa] == false) continue;
        kaka++;
    }
    return kaka;
}

stock VericarEspacoOuro(playerid)
{
    for(new i=0; i < 5; i++){
        if(pOCaixa[playerid][i][TemCaixa] == true) continue;
        return i;
    }
    return -1; 
}