#include <YSI_Coding\y_hooks>
#include "../Dependencias/Modos/Arena/Modulos/ArenaTxd"

enum ArenaSpawnInfo
{
    Float:aSpawnX,
    Float:aSpawnY,
    Float:aSpawnZ
};

new FavelaSpawn[][ArenaSpawnInfo] =
{
    {2176.1335,-987.1352,64.4688},
    {2203.0591,-994.6201,63.9297},
    {2223.3623,-1005.4202,60.7584},
    {2223.4990,-1043.6686,57.8962},
    {2235.2383,-1069.5583,41.5938},
    {2243.3733,-1085.8602,41.6016},
    {2225.3152,-1093.2390,29.2792},
    {2191.1697,-1087.8510,40.5912},
    {2159.0134,-1057.3846,63.4219},
    {2125.3970,-979.3644,58.8995},
    {2110.0647,-1000.7100,60.4598},
    {2097.6987,-969.9008,52.8289},
    {2066.8376,-992.5394,48.8004}
};

new CanyonSpawn[][ArenaSpawnInfo] =
{
    {-789.2451,2399.8284,156.6775},
    {-808.4221,2352.5493,150.1019},
    {-843.5538,2300.1040,153.4453},
    {-800.3315,2322.9646,143.3216},
    {-813.8056,2381.1204,152.8186},
    {-817.6077,2422.9744,156.8739},
    {-786.0588,2433.4473,157.1331},
    {-772.9762,2422.7041,157.0904},
    {-775.1641,2410.3447,157.0736},
    {-761.4195,2431.4836,157.0109},
    {-802.7017,2446.3445,157.0112},
    {-810.5393,2386.3306,153.4836},
    {-804.1878,2357.3801,150.7566},
    {-821.4024,2335.5632,148.2176},
    {-843.1961,2303.0244,153.3410}
};

hook OnPlayerLeaveDynArea(playerid, areaid)
{
    if(pModo[playerid][Jogando] == false) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(pModo[playerid][ModoAtl] != 2) return 1;
    new id = pModo[playerid][Sala];
    if(areaid == pArena[id][AreaArena]){
        RespawnarArena(playerid);
        SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você saiu do limite do mapa");
    }
    return 1;
}

Dialog:SenhaArenaLogin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new id = GetPVarInt(playerid, "ArenaDSenha");
    if(strcmp(pArena[id][SenhaArena], inputtext)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Senha incorreta!");
    ColocarArena(playerid, id);
    return 1;
}

Dialog:ArenaDialog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = listitem;
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está procurado(a)");
    if(!strcmp(pArena[id][ArenaDono], "*")) return CriarArena(playerid, id);
    if(strcmp(pArena[id][SenhaArena], "*"))
    {
        SetPVarInt(playerid, "ArenaDSenha", id);
        Dialog_Show(playerid, SenhaArenaLogin, DIALOG_STYLE_INPUT, "{FF0000}Arena - Senha", "Coloque abaixo a senha dessa arena", "Confirmar", "Cancelar");
        return 1;
    }
    ColocarArena(playerid, id);
    return 0;
}

Dialog:SenhaArenaSec(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 20) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Senha muito grande!");
    SetPVarString(playerid, "SenhaDaArena", inputtext);
    SelecionarArenaKity(playerid);
    return 1;
}

Dialog:SenhaArenaCriar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, SenhaArenaSec, DIALOG_STYLE_INPUT, "{FF0000}Senha", "Coloque uma senha abaixo", "Confirmar", "Fechar");
        case 1:
        {
            SetPVarString(playerid, "SenhaDaArena", "*");
            SelecionarArenaKity(playerid);
        }
    }
    return 1;
}

stock VerificarSelecaoArmas(playerid)
{
    new Satr[20],
        Conct = 0
    ;
    for(new i=0; i < 5; i++){
        format(Satr, sizeof(Satr), "ArenaArma%d", i);
        if(GetPVarInt(playerid, Satr) == 0) continue;
        Conct++;
    }

    if(Conct == 0) return false;
    return true;
}

stock VerificarArmaArena(playerid, id)
{
    new Satr[20];
    for(new i=0; i < 5; i++){
        format(Satr, sizeof(Satr), "ArenaArma%d", i);
        if(GetPVarInt(playerid, Satr) == id) return true;  
    }
    return false;
}

Dialog:ArmaArenaSec(playerid, response, listitem, inputtext[])
{
    if(!response){
        SelecionarArenaKity(playerid);
        return 1;
    }

    new arid;
    switch(listitem)
    {
        case 0: arid = 0;
        case 1: arid = 4;
        case 2: arid = 16;
        case 3: arid = 23;
        case 4: arid = 24;
        case 5: arid = 25;
        case 6: arid = 26;
        case 7: arid = 27;
        case 8: arid = 28;
        case 9: arid = 29;
        case 10: arid = 30;
        case 11: arid = 31;
        case 12: arid = 32;
        case 13: arid = 34;
    }

    if(arid != 0){
        if(VerificarArmaArena(playerid, arid)){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa arma já está sendo utilizada no slot");
            SelecionarArenaKity(playerid);
            return 1;
        }
    }
    new id = GetPVarInt(playerid, "SlotArmaArena"),
        Satr[20]
    ;
    format(Satr, sizeof(Satr), "ArenaArma%d", id);
    SetPVarInt(playerid, Satr, arid);
    SelecionarArenaKity(playerid);
    return 1;
}

Dialog:CriarArenaIDD(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[500];
    switch(listitem)
    {
        case 0..4:
        {
            SetPVarInt(playerid, "SlotArmaArena", listitem);
            strcat(Dialog, "{FF0000}Remover Arma{FFFFFF}\n");
            strcat(Dialog, "1. Knife\n");
            strcat(Dialog, "2. Grenades\n");
            strcat(Dialog, "3. Silenced pistol\n");
            strcat(Dialog, "4. Desert Eagle\n");
            strcat(Dialog, "5. Shotgun\n");
            strcat(Dialog, "6. Sawn-off Shotgun\n");
            strcat(Dialog, "7. Combat Shotgun\n");
            strcat(Dialog, "8. Micro Uzi\n");
            strcat(Dialog, "9. Mp5\n");
            strcat(Dialog, "10. AK47\n");
            strcat(Dialog, "11. M4\n");
            strcat(Dialog, "12. Tec 9\n");
            strcat(Dialog, "13. Sniper Rifle");
            Dialog_Show(playerid, ArmaArenaSec, DIALOG_STYLE_TABLIST, "{FF0000}Armário de Armas", Dialog, "Selecionar", "Cancelar");
        }
        case 5:
        {
            if(!VerificarSelecaoArmas(playerid)){
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Selecione no mínimo 1 arma");
                SelecionarArenaKity(playerid);
                return 1;
            }
            for(new i=0; i < sizeof(ArenasID); i++){
                strcatEx(Dialog, "%d\t%s\n", i+1, ArenasID[i][ArenaNomeH]);
            }
            Dialog_Show(playerid, CriarArenaSala, DIALOG_STYLE_TABLIST, "{FF0000}Mapa", Dialog, "Selecionar", "Cancelar");
        }
    }
    return 1;
}

Dialog:CriarArenaSala(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "CriacaoArenaID");
    if(strcmp(pArena[id][ArenaDono], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa sala já foi criada");
    format(pArena[id][ArenaDono], 70, PegarNick(playerid));
    GetPVarString(playerid, "SenhaDaArena", pArena[id][SenhaArena], 70);

    pArmaArena[id][ArmaA1] = GetPVarInt(playerid, "ArenaArma0");
    pArmaArena[id][ArmaA2] = GetPVarInt(playerid, "ArenaArma1");
    pArmaArena[id][ArmaA3] = GetPVarInt(playerid, "ArenaArma2");
    pArmaArena[id][ArmaA4] = GetPVarInt(playerid, "ArenaArma3");
    pArmaArena[id][ArmaA5] = GetPVarInt(playerid, "ArenaArma4");

    pArena[id][KitID] = GetPVarInt(playerid, "ArenaArmaID");

    pArena[id][MapaID] = listitem;

    switch(listitem)
    {
        case 0: pArena[id][AreaArena] = CreateDynamicRectangle(2272.5425,-1157.9462, 2023.3782,-907.6179, id+id+2, 0, -1);
        case 1: pArena[id][AreaArena] = CreateDynamicRectangle(-632.8879,2305.6819, -910.4321,2487.3486, id+id+2, 0, -1);
    }
    

    /*pArena[id][ArenaTexto1] = CreateDynamic3DTextLabel("{FA8072}Ponto de Cura{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para usar", -1, 2246.0239,-1088.6815,41.6016, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, id+id+2, 0, -1, 20.0, -1);
    pArena[id][ArenaTexto2] = CreateDynamic3DTextLabel("{FA8072}Ponto de Cura{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para usar", -1, 2149.1069,-985.5192,62.8368, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, id+id+2, 0, -1, 20.0, -1);
    pArena[id][ArenaTexto3] = CreateDynamic3DTextLabel("{FA8072}Ponto de Cura{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para usar", -1, 2150.7166,-1106.1227,25.3360, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, id+id+2, 0, -1, 20.0, -1);

    pArena[id][ArenaPick1] = CreateDynamicPickup(1240, 1, 2246.0239,-1088.6815,41.6016, id+id+2, 0, -1, 70.0, -1);
    pArena[id][ArenaPick2] = CreateDynamicPickup(1240, 1, 2149.1069,-985.5192,62.8368, id+id+2, 0, -1, 70.0, -1);
    pArena[id][ArenaPick3] = CreateDynamicPickup(1240, 1, 2150.7166,-1106.1227,25.3360, id+id+2, 0, -1, 70.0, -1);*/

    ColocarArena(playerid, id);

    new Mensagem[128];
    new StatusJA[80];

    if(!strcmp(pArena[id][SenhaArena], "*")) strcat(StatusJA, "Destrancada");
    else strcatEx(StatusJA, "Trancada - Senha: %s", pArena[id][SenhaArena]);

    format(Mensagem, sizeof(Mensagem), "| ARENA | Você criou uma arena id {FFA500}%d{FFFFFF} com kit {FFA500}%d{FFFFFF} e {00BFFF}%s", id, GetPVarInt(playerid, "ArenaArmaID")+1, StatusJA);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

stock CriarArena(playerid, id)
{

    new Satr[20];
    for(new i=0; i < 5; i++){
        format(Satr, sizeof(Satr), "ArenaArma%d", i);
        SetPVarInt(playerid, Satr, 0);
    }

    SetPVarInt(playerid, "CriacaoArenaID", id);
    new Dialog[100];
    strcat(Dialog, "Com Senha\n");
    strcat(Dialog, "Sem Senha");
    Dialog_Show(playerid, SenhaArenaCriar, DIALOG_STYLE_TABLIST, "{FF0000}Arena", Dialog, "Selecionar", "Cancelar");
    return 1;
}

stock SelecionarArenaKity(playerid)
{
    new Dialog[400];

    if(GetPVarInt(playerid, "ArenaArma0") == 0) strcat(Dialog, "{FFFFFF}1. Selecionar Arma\n");
    else strcatEx(Dialog, "{FFFFFF}1. {FFFF00}%s\n", PegarArmaNome(GetPVarInt(playerid, "ArenaArma0")));
    
    if(GetPVarInt(playerid, "ArenaArma1") == 0) strcat(Dialog, "{FFFFFF}2. Selecionar Arma\n");
    else strcatEx(Dialog, "{FFFFFF}2. {FFFF00}%s\n", PegarArmaNome(GetPVarInt(playerid, "ArenaArma1")));

    if(GetPVarInt(playerid, "ArenaArma2") == 0) strcat(Dialog, "{FFFFFF}3. Selecionar Arma\n");
    else strcatEx(Dialog, "{FFFFFF}3. {FFFF00}%s\n", PegarArmaNome(GetPVarInt(playerid, "ArenaArma2")));

    if(GetPVarInt(playerid, "ArenaArma3") == 0) strcat(Dialog, "{FFFFFF}4. Selecionar Arma\n");
    else strcatEx(Dialog, "{FFFFFF}4. {FFFF00}%s\n", PegarArmaNome(GetPVarInt(playerid, "ArenaArma3")));

    if(GetPVarInt(playerid, "ArenaArma4") == 0) strcat(Dialog, "{FFFFFF}5. Selecionar Arma\n");
    else strcatEx(Dialog, "{FFFFFF}5. {FFFF00}%s\n", PegarArmaNome(GetPVarInt(playerid, "ArenaArma4")));

    strcat(Dialog, "{00FF00}Confirmar");
    Dialog_Show(playerid, CriarArenaIDD, DIALOG_STYLE_TABLIST, "{FF0000}Selecionar", Dialog, "Selecionar", "Cancelar");
    return 1;
}

stock ColocarArena(playerid, arena)
{
    if(pArena[arena][MapaID] >= 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sessão selecionada está lotada.");
    if(pArena[arena][MapaID] == 0)
    {
        new spawnid = random(sizeof(FavelaSpawn));
        SetPlayerFacingAngle(playerid, float(random(360)));
        SetPlayerPos(playerid, FavelaSpawn[spawnid][aSpawnX], FavelaSpawn[spawnid][aSpawnY], FavelaSpawn[spawnid][aSpawnZ]);
    }
    else if(pArena[arena][MapaID] == 1)
    {
        new spawnid = random(sizeof(CanyonSpawn));
        SetPlayerFacingAngle(playerid, float(random(360)));
        SetPlayerPos(playerid, CanyonSpawn[spawnid][aSpawnX], CanyonSpawn[spawnid][aSpawnY], CanyonSpawn[spawnid][aSpawnZ]);
    }
    
    pArena[arena][Jogadores]++;

    //Setando Dependencias
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, arena+arena+2);
    pModo[playerid][ModoAtl] = 2;
    pModo[playerid][Sala] = arena;
    pModo[playerid][Jogando] = true;
    RemoverAcessorios(playerid);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ARENA | %s[%d] entrou nessa sessão", PegarNick(playerid), playerid);

    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(pModo[i][Jogando] == false) continue;
        if(pModo[i][ModoAtl] != 2) continue;
        if(pModo[i][Sala] != arena) continue;
        SendClientMessage(i, 0xCCCCCCFF, Mensagem);
    }

    //GangZoneShowForPlayer(playerid, pArena[arena][AreaArenaEx], 0xFFFF0060);
    SetPlayerHealth(playerid, 100.0);
    SetPlayerArmour(playerid, 0);
    ResetPlayerWeapons(playerid);
    DarArmaArena(playerid);
    MostrarArenaKD(playerid);
    AtualizarVM(playerid);
    SendClientMessage(playerid, 0xfc520fFF, "| AVISO | Para sair da arena ( /SairArena )"); 
    return 1;
}

stock TirarJogadorArena(playerid)
{
    new id = pModo[playerid][Sala];
    pArena[id][Jogadores]--;
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ARENA | %s saiu da sessão ( Restante: %d )", PegarNick(playerid), pArena[id][Jogadores]);

    SetPVarInt(playerid, "SemHospital", gettime()+10);

    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(pModo[i][Jogando] == false) continue;
        if(i == playerid) continue;
        if(pModo[i][ModoAtl] != 2) continue;
        if(pModo[i][Sala] != id) continue;
        SendClientMessage(i, 0xfc520fFF, Mensagem);   
    }

    VerificarAcessorios(playerid);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerPos(playerid, 2689.7722,-1694.5941,9.8919);
    pModo[playerid][Jogando] = false;
    pModo[playerid][Sala] = 0;
    pModo[playerid][ModoAtl] = 0;
    pModo[playerid][TempoEntrar] = gettime()+60;
    SetPlayerHealth(playerid, 100);
    SetPlayerArmour(playerid, 0);
    ResetPlayerWeapons(playerid);  
    OcultarArenaKD(playerid);

    if(!strcmp(pArena[id][ArenaDono], PegarNick(playerid))) VerificarArena(id);
    return 1;
}

stock AtualizarVM(playerid)
{
    new Mensagem[90];
    format(Mensagem, sizeof(Mensagem), "%s", DinheiroSeparar(Jogador[playerid][VitimasArena]));
    PlayerTextDrawSetString(playerid, ArenaKD[playerid][6], ConverterTexto(Mensagem)); 
    format(Mensagem, sizeof(Mensagem), "%s", DinheiroSeparar(Jogador[playerid][MortesArena]));
    PlayerTextDrawSetString(playerid, ArenaKD[playerid][7], ConverterTexto(Mensagem));
    return 1;
}

stock VerificarArena(id)
{
    new bool:TemGente = false;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(pModo[i][Jogando] == false) continue;
        if(pModo[i][ModoAtl] != 2) continue;
        if(pModo[i][Sala] != id) continue;
        format(pArena[id][ArenaDono], 70, PegarNick(i));
        SendClientMessage(i, 0xFF4500FF, "| AVISO | Você agora é o novo(a) dono(a) dessa sala");
        TemGente = true;
        break;
    }
    if(TemGente == false) ResetarArena(id);
    return 1;
}

stock ResetarArena(id)
{
    DestroyDynamicAreaEx(pArena[id][AreaArena]);

    /*DestroyDynamicPickupEx(pArena[id][ArenaPick1]);
    DestroyDynamicPickupEx(pArena[id][ArenaPick2]);
    DestroyDynamicPickupEx(pArena[id][ArenaPick3]);

    DestroyDynamic3DTextLabelEx(pArena[id][ArenaTexto1]);
    DestroyDynamic3DTextLabelEx(pArena[id][ArenaTexto2]);
    DestroyDynamic3DTextLabelEx(pArena[id][ArenaTexto3]);*/

    pArmaArena[id][ArmaA1] = 0;
    pArmaArena[id][ArmaA2] = 0;
    pArmaArena[id][ArmaA3] = 0;
    pArmaArena[id][ArmaA4] = 0;
    pArmaArena[id][ArmaA5] = 0;

    format(pArena[id][ArenaDono], 70, "*");
    format(pArena[id][SenhaArena], 80, "*");
    return 1;
}

stock DarArmaArena(playerid)
{
    ResetPlayerWeapons(playerid); 
    new id = pModo[playerid][Sala];
    if(pArmaArena[id][ArmaA1] != 0) GivePlayerWeapon(playerid, pArmaArena[id][ArmaA1], 99999);
    if(pArmaArena[id][ArmaA2] != 0) GivePlayerWeapon(playerid, pArmaArena[id][ArmaA2], 99999);
    if(pArmaArena[id][ArmaA3] != 0) GivePlayerWeapon(playerid, pArmaArena[id][ArmaA3], 99999);
    if(pArmaArena[id][ArmaA4] != 0) GivePlayerWeapon(playerid, pArmaArena[id][ArmaA4], 99999);
    if(pArmaArena[id][ArmaA5] != 0) GivePlayerWeapon(playerid, pArmaArena[id][ArmaA5], 99999);
    return 1;
}

stock RespawnarArena(playerid) 
{
    new id = pModo[playerid][Sala];
    SetPlayerFacingAngle(playerid, float(random(360)+1));  
    if(pArena[id][MapaID] == 0)
    {
        new spawnid = random(sizeof(FavelaSpawn));
        SetPlayerPos(playerid, FavelaSpawn[spawnid][aSpawnX], FavelaSpawn[spawnid][aSpawnY], FavelaSpawn[spawnid][aSpawnZ]);
    }
    else if(pArena[id][MapaID] == 1)
    {
        new spawnid = random(sizeof(CanyonSpawn));
        SetPlayerPos(playerid, CanyonSpawn[spawnid][aSpawnX], CanyonSpawn[spawnid][aSpawnY], CanyonSpawn[spawnid][aSpawnZ]);
    }

    DarArmaArena(playerid);
    SetPlayerVirtualWorld(playerid, id+id+2);
    SetPlayerInterior(playerid, 0);
    // SetPlayerArmour(playerid, 100.0);
    //SetPlayerHealth(playerid, 99999);
    //SendClientMessage(playerid, 0xfc520fFF, "| AVISO | Você ficará invulnerável durante 5 segundos!");
    //SetTimerEx("VoltarAoNormal", 5000, false, "d", playerid);
    return 1;
}

stock UsarKitArena(playerid, tempo)
{
    if(pModo[playerid][TempoCurar] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode usar");
    new Float:Vihda;
    GetPlayerHealth(playerid, Vihda);
    if(Vihda > 60) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda mais de 60 de vida");
    pModo[playerid][TempoCurar] = gettime()+tempo;
    SetPlayerHealth(playerid, 100);
    SendClientMessage(playerid, 0xFFA500FF, "| CURA | Você regenerou sua vida em um ponto de cura");
    return 1;
}

CMD:expulsar(playerid, params[])
{
    new salaid = pModo[playerid][Sala];
    if(Jogador[playerid][Admin] < 1)
    {
        if(pModo[playerid][Jogando] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está jogando");
        if(pModo[playerid][ModoAtl] != 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está jogando na arena");
        if(strcmp(pArena[salaid][ArenaDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é o dono(a) dessa sala");
    }

    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Expulsar [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar em si mesmo");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está logado(a)");
    if(pModo[id][Jogando] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está jogando");
    if(pModo[id][ModoAtl] != 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não está jogando na arena");
    
    if(Jogador[playerid][Admin] < 2){
        if(pModo[id][Sala] != salaid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não está jogando na sua sala");
    }

    if(Jogador[playerid][Admin] < 2){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode expulsar um admin");
    }

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ARENA | O(A) Jogador(a) %s foi expulso(a) da arena por %s", PegarNick(id), PegarNick(playerid));
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(pModo[i][Jogando] == false) continue;
        if(pModo[i][ModoAtl] != 2) continue;
        if(pModo[i][Sala] != salaid) continue;
        SendClientMessage(i, 0xFFA500FF, Mensagem);   
    }
    TirarJogadorArena(id);
    return 1;
}

/*hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    If(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(pModo[playerid][Jogando] == false) return 1;
        if(pModo[playerid][ModoAtl] != 2) return 1;
        new id = pModo[playerid][Sala];
        if(pArena[id][MapaID] == 0)
        {
            if(GetPlayerVirtualWorld(playerid) != id+id+2 || GetPlayerInterior(playerid) != 0) return 1;
            if(!IsPlayerInRangeOfPoint(playerid, 2.0, 2246.0239,-1088.6815,41.6016) && 
            !IsPlayerInRangeOfPoint(playerid, 2.0, 2149.1069,-985.5192,62.8368) &&
            !IsPlayerInRangeOfPoint(playerid, 2.0, 2150.7166,-1106.1227,25.3360)) return 1;
            UsarKitArena(playerid, 35);
        }

    }*
    return 1;
}*/