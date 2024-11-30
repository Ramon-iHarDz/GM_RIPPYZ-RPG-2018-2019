#include <YSI_Coding\y_hooks>

#define MAX_MESAS 22

enum AreasProducao
{
    MesaID,
    Float:MesaX,
    Float:MesaY,
    Float:MesaZ,

    MesaObjeto,
    MesaCheckPoint,
    Text3D:MesaDraw,
    bool:MesaUsada,
    MesaUsadaID
};

enum ProducaoJogador
{
    bool:ProducaoIniciar,
    bool:ProducaoCaixa,
    CheckPointProducao,
    MapProducao
};

new MesaCriacao[][AreasProducao] =
{
    {1, 1267.0677,-15.0999,1001.0280},
    {3, 1271.8204,-15.0708,1001.0257},
    {5, 1276.5519,-15.0265,1001.0234},
    {13, 1281.2130,-15.0591,1001.0156},
    {14, 1285.9113,-15.0457,1001.0156},
    {0, 1290.6350,-14.9661,1001.0226},
    {6, 1267.0695,-28.7662,1001.0280},
    {8, 1271.8696,-28.6967,1001.0257},
    {10, 1276.4581,-28.6842,1001.0234},
    {21, 1281.2209,-28.5889,1001.0211},
    {19, 1285.8252,-28.6429,1001.0211},
    {17, 1290.6146,-28.4443,1001.0226}
};

new Debugg[MAX_MESAS];
new pMesa[MAX_MESAS][AreasProducao];
new pProducao[MAX_PLAYERS][ProducaoJogador];
 
hook OnGameModeInit() 
{
    CreateDynamicPickup(1239, 1, -1827.7117,1537.7666,7.1875, 0, 0, -1, 100.0, -1);
    CreateDynamicPickup(1239, 1, 1292.4006,7.3249,1001.0078, 2638, 18, -1, 100.0, -1);

    CreateDynamic3DTextLabel("Entrada{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para entrar", 0xFFFF00FF, -1827.7117,1537.7666,7.1875, 19.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 20.0, -1);
    CreateDynamic3DTextLabel("Saída{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para entrar", 0xFFFF00FF, 1292.4006,7.3249,1001.0078, 19.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 2638, 18, -1, 20.0, -1);
    
    CreateDynamicPickup(1239, 1, 1251.3125,-25.2658,1001.0347, 2638, 18, -1, 100.0, -1);
    CreateDynamicPickup(1239, 1, 1251.2965,-9.7702,1001.0347, 2638, 18, -1, 100.0, -1);
    CreateDynamic3DTextLabel("Caixas{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para pegar", 0x00BFFFFF, 1251.3125,-25.2658,1001.0347, 19.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 2638, 18, -1, 20.0, -1);
    CreateDynamic3DTextLabel("Caixas{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para pegar", 0x00BFFFFF, 1251.2965,-9.7702,1001.0347, 19.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 2638, 18, -1, 20.0, -1);
    
    CreateDynamicPickup(1239, 1, 1273.5618,-56.0208,1002.5040, 2638, 18, -1, 100.0, -1);
    CreateDynamic3DTextLabel("Embalagens{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para embalar", 0x00BFFFFF, 1273.5618,-56.0208,1002.5040, 19.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 2638, 18, -1, 20.0, -1);
    
    new Mensagem[60];
    for(new i=0; i < sizeof(MesaCriacao); i++)
    {
        format(Mensagem, sizeof(Mensagem), "Mesa ID: {FFFF00}%d\n{FFA500}Disponível", i);
        pMesa[i][MesaDraw] = CreateDynamic3DTextLabel(Mensagem, -1, MesaCriacao[i][MesaX], MesaCriacao[i][MesaY], MesaCriacao[i][MesaZ], 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 2638, 18, -1, 20.0, -1);
        pMesa[i][MesaCheckPoint] = CreateDynamicCP(MesaCriacao[i][MesaX], MesaCriacao[i][MesaY], MesaCriacao[i][MesaZ], 1.0, 2638, 18, -1, 1.0, -1);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < sizeof(MesaCriacao); i++)
    {
        if(pMesa[i][MesaUsada] == false) continue;
        if(pMesa[i][MesaUsadaID] != playerid) continue;
        new Mensagem[70];
        format(Mensagem, sizeof(Mensagem), "Mesa ID: {FFFF00}%d\n{FFA500}Disponível", i);
        UpdateDynamic3DTextLabelText(pMesa[GetPVarInt(playerid, "MesaIDD")][MesaDraw], -1, Mensagem);
        DestroyDynamicObjectEx(pMesa[i][MesaObjeto]);
        pMesa[i][MesaUsada] = false;
        break;
    }

    DestroyDynamicMapIconEx(pProducao[playerid][MapProducao]);
    DestroyDynamicCPEx(pProducao[playerid][CheckPointProducao]);

    new Fdas[ProducaoJogador];
    pProducao[playerid] = Fdas;
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    for(new i=0; i < sizeof(MesaCriacao); i++)
    {
        if(pMesa[i][MesaUsada] == false) continue;
        if(pMesa[i][MesaUsadaID] != playerid) continue;
        new Mensagem[80];
        format(Mensagem, sizeof(Mensagem), "Mesa ID: {FFFF00}%d\n{FFA500}Disponível", i);
        UpdateDynamic3DTextLabelText(pMesa[GetPVarInt(playerid, "MesaIDD")][MesaDraw], -1, Mensagem);
        DestroyDynamicObjectEx(pMesa[i][MesaObjeto]);
        pMesa[i][MesaUsada] = false;
        break;
    }

    SetPVarInt(playerid, "PassoFinalProd", 0);
    SetPVarInt(playerid, "PodePegarSYstem", 0);
    pProducao[playerid][ProducaoIniciar] = false;
    if(pProducao[playerid][ProducaoCaixa] == true) RemovePlayerAttachedObject(playerid, 9);

    DestroyDynamicMapIconEx(pProducao[playerid][MapProducao]);
    DestroyDynamicCPEx(pProducao[playerid][CheckPointProducao]);

    new Fdas[ProducaoJogador];
    pProducao[playerid] = Fdas;

    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid == pProducao[playerid][CheckPointProducao])
    {
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
        new Mensagem[128],
            Ganxo;

        switch(GetPVarInt(playerid, "ProducaoX"))
        {
            case 0: Ganxo = random(2000-1000)+1000;
            case 1: Ganxo = random(4000-3000)+3000;
            case 2: Ganxo = random(13000-10000)+10000;
        }

        format(Mensagem, sizeof(Mensagem), "| PRODUÇÃO | Você entregou as drogas e recebeu {FFA500}$%s", DinheiroSeparar(Ganxo));
        SendClientMessage(playerid, -1, Mensagem);

        SetPVarInt(playerid, "BlockKASDKA", 0);
        Jogador[playerid][Dinheiro] += Ganxo;
        pProducao[playerid][ProducaoIniciar] = false;
        
        DestroyDynamicMapIconEx(pProducao[playerid][MapProducao]);
        DestroyDynamicCPEx(pProducao[playerid][CheckPointProducao]);
        return 1;
    }

    for(new i=0; i < sizeof(MesaCriacao); i++)
    {
        if(pMesa[i][MesaCheckPoint] != checkpointid) continue;
        if(pMesa[i][MesaUsada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa mesa está ocupada, vá para outra.");
        /*{
            if(pMesa[i][MesaUsadaID] != playerid && pProducao[playerid][ProducaoIniciar] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em sua mesa, vá até ela");
            else if(pMesa[i][MesaUsadaID] != playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa mesa está ocupada, vá para outra.");
            if(pProducao[playerid][ProducaoCaixa] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pegou a caixa, vá até o canto do armazém");
            pProducao[i][ProducaoCaixa] = false;
            TogglePlayerControllable(playerid, 0);
            RemovePlayerAttachedObject(playerid, 9);
            ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
            CriarProgresso(playerid, "Embalando, aguarde.", "DrogaCaixa", 400);
            return 1;
        }*/
        if(pProducao[playerid][ProducaoIniciar] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode iniciar outra produção");

        SetPVarInt(playerid, "MesaIDD", i);

        new Dialog[128];
        strcat(Dialog, "Tipo\tTempo\n");
        strcat(Dialog, "Leve\tRápido\n");
        strcat(Dialog, "Media\tLento\n");
        strcat(Dialog, "Pesada\tSuper Lenta");
        Dialog_Show(playerid, DrogaProducao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Drogas", Dialog, "Produzir", "Fechar");
        break;
    }
    return 1;
}

Dialog:DrogaProducao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(pMesa[GetPVarInt(playerid, "MesaIDD")][MesaUsada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode iniciar nessa mesa");

    new DrogaV[7],
        Mensagem[90],
        id,
        Float:MesaP[3],
        DrogaModel;

    TogglePlayerControllable(playerid, 0);
    SetPVarInt(playerid, "ProducaoX", listitem);

    switch(listitem)
    {
        case 0: DrogaModel = 1578;
        case 1: DrogaModel = 1575;
        case 2: DrogaModel = 1580;
    }

    pProducao[playerid][ProducaoIniciar] = true;
    pMesa[GetPVarInt(playerid, "MesaIDD")][MesaUsada] = true;
    pMesa[GetPVarInt(playerid, "MesaIDD")][MesaUsadaID] = playerid; 
    
    id = MesaCriacao[GetPVarInt(playerid, "MesaIDD")][MesaID];
    GetDynamicObjectPos(Debugg[id], MesaP[0], MesaP[1], MesaP[2]);
    pMesa[GetPVarInt(playerid, "MesaIDD")][MesaObjeto] = CreateDynamicObject(DrogaModel, MesaP[0], MesaP[1], 1000.85773, 0.0, 0.0, float(random(360)), 2638, 18, -1, 100.0, 100.0, -1);
    
    format(Mensagem, sizeof(Mensagem), "Mesa ID: {FFFF00}%d\n{FFFFFF}Ocupada: {FFA500}%s[%d]", GetPVarInt(playerid, "MesaIDD"), PegarNick(playerid), playerid);
    UpdateDynamic3DTextLabelText(pMesa[GetPVarInt(playerid, "MesaIDD")][MesaDraw], -1, Mensagem);

    switch(listitem)
    {
        case 0: CriarProgresso(playerid, "Produzindo Droga Leve", "DrogaFeita", 1*1000); 
        case 1: CriarProgresso(playerid, "Produzindo Droga Media", "DrogaFeita", 3*1000);
        case 2: CriarProgresso(playerid, "Produzindo Droga Pesada", "DrogaFeita", 4*1000);
    }

    switch(listitem)
    {
        case 0: DrogaV = "Leve";
        case 1: DrogaV = "Media";
        case 2: DrogaV = "Pesada";
    }
    format(Mensagem, sizeof(Mensagem), "| PRODUÇÃO | Você está produzindo uma droga do tipo %s, aguarde.", DrogaV);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

function DrogaFeita(playerid)
{
    for(new i=0; i < sizeof(MesaCriacao); i++)
    {
        if(pMesa[i][MesaUsada] == false) continue;
        if(pMesa[i][MesaUsadaID] != playerid) continue;
        new Mensagem[80];
        format(Mensagem, sizeof(Mensagem), "Mesa ID: {FFFF00}%d\n{FFA500}Disponível", i);
        UpdateDynamic3DTextLabelText(pMesa[GetPVarInt(playerid, "MesaIDD")][MesaDraw], -1, Mensagem);
        DestroyDynamicObjectEx(pMesa[i][MesaObjeto]);
        pMesa[i][MesaUsada] = false;
        break;
    }
    TogglePlayerControllable(playerid, 1);
    SetPVarInt(playerid, "PodePegarSYstem", 1);
    SendClientMessage(playerid, 0x00BFFFFF, "| PRODUÇÃO | Você precisa pegar uma caixa, vá até o canto do armazém.");
    return 1;
}

/*function DrogaCaixa(playerid)
{
    for(new i=0; i < sizeof(MesaCriacao); i++)
    {
        if(pMesa[i][MesaUsada] == false) continue;
        if(pMesa[i][MesaUsadaID] != playerid) continue;
        new Mensagem[80];
        format(Mensagem, sizeof(Mensagem), "Mesa ID: {FFFF00}%d\n{FFA500}Disponível", i);
        UpdateDynamic3DTextLabelText(pMesa[GetPVarInt(playerid, "MesaIDD")][MesaDraw], -1, Mensagem);
        DestroyDynamicObjectEx(pMesa[i][MesaObjeto]);
        pMesa[i][MesaUsada] = false;
        break;
    }
    TogglePlayerControllable(playerid, 1);
    pProducao[playerid][ProducaoCaixa] = false;
    SendClientMessage(playerid, 0x00BFFFFF, "| PRODUÇÃO | Você colocou as drogas na caixa, vá até o canto superior do armazém.");
    SetPVarInt(playerid, "PassoFinalProd", 1);
    return 1;
}*/

function DrogaFinalizada(playerid)
{
    new DrugsStars,
        Float:Kkpasd[3];
    switch(GetPVarInt(playerid, "ProducaoX"))
    {
        case 0: DrugsStars = random(7-6)+6;
        case 1: DrugsStars = random(10-8)+8;
        case 2: DrugsStars = random(25-15)+15;
    }

    switch(random(2))
    {
        case 0: // LV - Aero
        {
            Kkpasd[0] = 263.5235;
            Kkpasd[1] = 2895.7500;
            Kkpasd[2] = 10.5314;
        }
        case 1: // LV
        {
            Kkpasd[0] = 397.8492;
            Kkpasd[1] = 1157.5980;
            Kkpasd[2] = 8.3481;
        }
        case 2:
        {
            Kkpasd[0] = 2186.3970;
            Kkpasd[1] = -997.7495;
            Kkpasd[2] = 66.4688;   
        }
    }

    Jogador[playerid][Estrelas] += DrugsStars;
    TogglePlayerControllable(playerid, 1);
    
    pProducao[playerid][CheckPointProducao] = CreateDynamicCP(Kkpasd[0], Kkpasd[1], Kkpasd[2], 1.0, 0, 0, playerid, 25.0, -1);
    pProducao[playerid][MapProducao] = CreateDynamicMapIcon(Kkpasd[0], Kkpasd[1], Kkpasd[2], 0, 0xFFFF00FF, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
    pTempo[playerid][HobbieProdutor] = gettime()+(2*3600);
    
    SendClientMessage(playerid, 0xFFFF00FF, "| PRODUÇÃO | Siga o ícone no mapa para entregar essa droga.");
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        // Entrada
        if(IsPlayerInRangeOfPoint(playerid, 2.0, -1827.7117,1537.7666,7.1875))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(Jogador[playerid][Level] < 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode entrar no armazém a partir do level 10");
            if(IsPolicia(playerid) && Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você trabalha para o governo, sua entrada foi bloqueada.");
            if(pTempo[playerid][HobbieProdutor] > gettime() && Jogador[playerid][Admin] < 1){
                new Mensagem[59];
                format(Mensagem, sizeof(Mensagem), "| ERRO | Você só pode entrar aqui em %s", ConverterSegundos(pTempo[playerid][HobbieProdutor]));
                SendClientMessage(playerid, 0xFF4500FF, Mensagem);
                return 1;
            }
            Jogador[playerid][uInteriorEx] = 2638;
            GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
            SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);

            SetPlayerInterior(playerid, 18);
            SetPlayerVirtualWorld(playerid, 2638);
            SetPlayerPos(playerid, 1292.4006,7.3249,1001.0078); 
        }

        // Saída
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 1292.4006,7.3249,1001.0078))
        {
            if(GetPlayerVirtualWorld(playerid) != 2638 || GetPlayerInterior(playerid) != 18) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            Jogador[playerid][uInteriorEx] = 0;
            SetPlayerInterior(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerPos(playerid, -1827.7117,1537.7666,7.1875);
        }
    }

    else if(newkeys == KEY_YES)
    {
        // Pegar Caixa
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1251.3125,-25.2658,1001.0347) || 
        IsPlayerInRangeOfPoint(playerid, 2.0, 1251.2965,-9.7702,1001.0347))
        {
            if(GetPlayerVirtualWorld(playerid) != 2638 || GetPlayerInterior(playerid) != 18) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(pProducao[playerid][ProducaoIniciar] == false) return 1;
            if(GetPVarInt(playerid, "PodePegarSYstem") == 0) return 1;
            if(pProducao[playerid][ProducaoCaixa] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está segurando uma caixa.");
            pProducao[playerid][ProducaoCaixa] = true;
            
            SendClientMessage(playerid, 0x00BFFFFF, "| PRODUÇÃO | Vá até a parte superior do armazém para embalar as drogas.");

            SetPVarInt(playerid, "PodePegarSYstem", 0); 
            SetPVarInt(playerid, "PassoFinalProd", 1);
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
            SetPlayerAttachedObject(playerid, 9, 1271, 5, 0.1239, 0.1259, 0.1679, 5.8000, 8.8000, -2.8000, 0.6019, 0.4830, 0.6969, 0xFFFFFFFF, 0xFFFFFFFF);
        }

        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 1273.5618,-56.0208,1002.5040))
        {
            if(GetPlayerVirtualWorld(playerid) != 2638 || GetPlayerInterior(playerid) != 18) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(pProducao[playerid][ProducaoIniciar] == false) return 1;
            if(GetPVarInt(playerid, "PassoFinalProd") == 0) return 1;
            if(GetPVarInt(playerid, "BlockKASDKA") == 1) return 1;
            SetPVarInt(playerid, "BlockKASDKA", 1);
            pProducao[playerid][ProducaoCaixa] = false;
            TogglePlayerControllable(playerid, 0);
            RemovePlayerAttachedObject(playerid, 9);
            ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
            CriarProgresso(playerid, "Embalando Drogas, aguarde.", "DrogaFinalizada", 400);
        }
    }

    return 1;
}