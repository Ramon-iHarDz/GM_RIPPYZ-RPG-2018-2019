CMD:criarair(playerid)
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new Dialog[1600];
    strcat(Dialog, "Opções\n");
    for(new i=0; i < sizeof(ItensAir); i++){
        strcatEx(Dialog, "%s\n", ItensAir[i][ItemNome]);
    }
    Dialog_Show(playerid, AirDropSoltar, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Opções Presentes", Dialog, "Soltar", "Cancelar");
    return 1;
}

Dialog:AirDropSoltar(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;

    new id = PegarAirID(),  
        Float:APDM[3],
        Mensagem[148];

    AirdropsJg++;
    AirDrop[id][AirDropLancado] = true;
    AirDrop[id][AirDropItem] = listitem;

    new SkinAirIDD = random(sizeof(SkinAir));
    GetPlayerPos(playerid, APDM[0], APDM[1], APDM[2]);
    
    AirDrop[id][aPosX] = APDM[0];
    AirDrop[id][aPosY] = APDM[1];
    AirDrop[id][aPosZ] = APDM[2];

    AirDrop[id][AirDropCaixa] = CreateDynamicObject(18849, APDM[0], APDM[1], APDM[2]+350.0, 0.0, 0.0, 0.0, 0, 0, -1, 190.0, 190.0, -1, 0);
    AirDrop[id][AirDropIcone] = CreateDynamicMapIcon(APDM[0], APDM[1], APDM[2], 5, -1, 0, 0, -1, 9999999.9, MAPICON_GLOBAL, -1, 0);
    SetDynamicObjectMaterial(AirDrop[id][AirDropCaixa], 0, SkinAir[SkinAirIDD][ModeloSkin], SkinAir[SkinAirIDD][TexturaAir], SkinAir[SkinAirIDD][TexturaEAir], 0xFFFFFFFF);
    MoveDynamicObject(AirDrop[id][AirDropCaixa], APDM[0], APDM[1], APDM[2]-0.4, 2.0);

    format(Mensagem, sizeof(Mensagem), "| AIRDROP | Um airdrop está caindo na região de {FF8C00}%s", GetPlayerZone(playerid));
    SendClientMessageToAll(-1, Mensagem);
    stringclear(Mensagem);
    return 0;
}

stock PegarAirID()
{
    for(new i=0; i < MAX_AIRDROP; i++){
        if(AirDrop[i][AirDropLancado] == true) continue;
        return i;
    }
    return -1;
}