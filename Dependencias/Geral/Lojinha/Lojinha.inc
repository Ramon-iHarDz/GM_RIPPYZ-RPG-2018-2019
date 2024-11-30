#include <YSI_Coding\y_hooks>

#define     MAX_BOT_LOJA    (4)

enum LojaBotLoc
{
    Float:BotLojaX,
    Float:BotLojaY,
    Float:BotLojaZ,
    Float:BotLojaA
};

new BotSpawnLoja[][LojaBotLoc] =
{
    {-82.5639,1053.2411,19.7453,287.7834},
    {690.5483,1716.1309,6.9938,54.9417},
    {-170.0787,2675.9404,62.7012,110.3287},
    {537.8547,-1789.2446,6.0407,196.2767}
};

enum LojaJogador
{
    RouboLoja,
    LojaTimer,
    RouboLkas,
    BotIDRoubo,
    RouboProg, 
    AssaltoLoc,
    CheckRouboLoja,
    MapRouboLoja
};

new BotLoja[MAX_BOT_LOJA];
new pLoja[MAX_PLAYERS][LojaJogador];


// Globais
new TempoRouboLoja;


hook OnGameModeInit()
{
    new md;
    for(new i=0; i < MAX_BOT_LOJA; i++)
    {
        switch(random(1))
        {
            case 0: md = 124;
            case 1: md = 12;
        }
        BotLoja[i] = CreateDynamicActor(md, BotSpawnLoja[i][BotLojaX], BotSpawnLoja[i][BotLojaY], BotSpawnLoja[i][BotLojaZ], BotSpawnLoja[i][BotLojaA], 1, 100.0, 0, 0, -1, 120.0, -1, 0);
        CreateDynamic3DTextLabel("Aperte {CCCCCC}'N'{FFFFFF} para assaltar", -1, BotSpawnLoja[i][BotLojaX], BotSpawnLoja[i][BotLojaY], BotSpawnLoja[i][BotLojaZ], 8.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 9.0, -1);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        if(pLoja[playerid][RouboLoja] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode cancelar, aguarde.");
        if(pLoja[playerid][RouboLoja] == 2) return PararRouboLoja(playerid);
    }
    else if(newkeys == KEY_NO)
    {
        for(new b=0; b < MAX_BOT_LOJA; b++)
        {
            if(!IsPlayerInRangeOfPoint(playerid, 4.0, BotSpawnLoja[b][BotLojaX], BotSpawnLoja[b][BotLojaY], BotSpawnLoja[b][BotLojaZ])) continue;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(Jogador[playerid][Level] < 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem level 20 para roubar");

            new weaponid = GetPlayerWeapon(playerid);
            if(weaponid == 0 || weaponid == 10 || weaponid == 11 || weaponid == 12 || weaponid == 13 || weaponid == 14
            || weaponid == 16 || weaponid == 17 || weaponid == 43 || weaponid == 42 || weaponid == 41) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está segurando uma arma");

            new Mensagem[128];
            if(TempoRouboLoja > gettime()){
                format(Mensagem, sizeof(Mensagem), "| ERRO | Você só pode roubar uma lojinha em %s", ConverterSegundos(TempoRouboLoja));
                SendClientMessage(playerid, 0xFF4500FF, Mensagem); 
                return 1;
            }
            
            // if(PoliciaPatrulha() < 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode roubar a lojinha com 5 policiais em patrulha");
            format(Mensagem, sizeof(Mensagem), "| ASSALTO | Está acontecendo um assalto a uma loja localizada em %s. Suspeito(a) %s[%d]", AreaNome(BotSpawnLoja[b][BotLojaX], BotSpawnLoja[b][BotLojaY], BotSpawnLoja[b][BotLojaZ]), PegarNick(playerid), playerid);
            for(new i=0; i < MAX_PLAYERS; i++)
            {
                if(!IsPlayerConnected(i)) continue;
                if(Jogador[i][Logado] == false) continue;
                if(!IsPolicia(i)) continue;
                if(!strcmp(Jogador[i][Profissao], "Corregedoria")) continue; 
                if(pPolicia[i][PegouUniformePolicia] == false) continue;
                SendClientMessage(i, 0x1E90FFFF, Mensagem); 
                pLoja[i][AssaltoLoc] = CreateDynamicMapIcon(BotSpawnLoja[b][BotLojaX], BotSpawnLoja[b][BotLojaY], BotSpawnLoja[b][BotLojaZ], 20, -1, 0, 0, i, 99999.9, MAPICON_GLOBAL, -1);
            }

            TogglePlayerControllable(playerid, 0);
            ApplyAnimation(playerid,"PED","gang_gunstand",4.0,1,1,1,1,1);

            SetPlayerAttachedObject(playerid, 7, 11745, 1, 0.0729, -0.1270, -0.0079, 77.5999, 159.6999, 29.3999, 0.8590, 0.7560, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);

            TempoRouboLoja = gettime()+3600;
            pLoja[playerid][RouboLoja] = 1;
            pLoja[playerid][RouboLkas] = 0;
            pLoja[playerid][RouboProg] = 180;
            pLoja[playerid][BotIDRoubo] = b;
            Jogador[playerid][Estrelas] += 5;
            MostrarLojaAssalto(playerid);
            pLoja[playerid][LojaTimer] = SetTimerEx("LojaProgresso", 1000, true, "d", playerid);
            SetTimerEx("LojinhaConfig", 300000, false, "d", b);

            // Animes
            ApplyDynamicActorAnimation(BotLoja[b], "PED", "CROUCH_ROLL_L", 0.0, 0, 0, 0, 0, 0);
            break;
        }
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamicMapIconEx(pLoja[playerid][AssaltoLoc]);
    DestroyDynamicCPEx(pLoja[playerid][CheckRouboLoja]);
    DestroyDynamicMapIconEx(pLoja[playerid][MapRouboLoja]);

    if(pLoja[playerid][RouboLoja] > 0){
        KillTimer(pLoja[playerid][LojaTimer]);
        pLoja[playerid][RouboLoja] = 0;
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| JUIZ | O(A) %s foi penalizado(a) por sair do servidor em uma ação.", PegarNick(playerid));
        SendClientMessageToAll(0x1E90FFFF, Mensagem);
        CatalogarPrisao(playerid, 60, "Sair do servidor em uma ação", "Isabella", 0);
    }

    new ldsada[LojaJogador];
    pLoja[playerid] = ldsada;
    return 1;
}

hook OnPlayerPreso(playerid)
{
    if(pLoja[playerid][RouboLoja] > 0){
        DestroyDynamicMapIconEx(pLoja[playerid][AssaltoLoc]);
        DestroyDynamicCPEx(pLoja[playerid][CheckRouboLoja]);
        KillTimer(pLoja[playerid][LojaTimer]);
        pLoja[playerid][RouboLoja] = 0;
        if(pLoja[playerid][RouboLoja] != 3) OcultarAssaltoLoja(playerid);
    }
    return 1;
}

function LojaProgresso(playerid)
{
    pLoja[playerid][RouboProg]--;
    pLoja[playerid][RouboLkas]++;
    if(pLoja[playerid][RouboProg] < 1) return PararRouboLoja(playerid);
    if(pLoja[playerid][RouboProg] == 170){
        pLoja[playerid][RouboLoja] = 2;
        MostrarParadaRoubo(playerid);
    }

    new adas[16];
    format(adas, sizeof(adas), "Tempo: %s", SegundosParaMinutosEx(pLoja[playerid][RouboProg]));
    PlayerTextDrawSetString(playerid, LojinhaText[playerid][1], adas);
    return 1;
}

function LojinhaConfig(id)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        DestroyDynamicMapIconEx(pLoja[i][AssaltoLoc]);
    }
    ClearDynamicActorAnimations(BotLoja[id]);
    return 1;
}

function AssaltoLojaFinish(playerid)
{
    pLoja[playerid][RouboLoja] = 0;
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pLoja[playerid][CheckRouboLoja]) return 1;
    pLoja[playerid][RouboLoja] = 0;

    DestroyDynamicCPEx(pLoja[playerid][CheckRouboLoja]);
    DestroyDynamicMapIconEx(pLoja[playerid][MapRouboLoja]);

    new Vlr = (50*pLoja[playerid][RouboLkas]),
        Mensagem[128];
    Jogador[playerid][Dinheiro] += Vlr;
    format(Mensagem, sizeof(Mensagem), "| LOJA | Você recebeu {32CD32}$%s{FFFFFF} pelo assalto a lojinha", DinheiroSeparar(Vlr));
    SendClientMessage(playerid, -1, Mensagem);
    RemovePlayerAttachedObject(playerid, 7);
    return 1;
}

stock PararRouboLoja(playerid)
{
    Jogador[playerid][Estrelas] += 3;
    pLoja[playerid][RouboLoja] = 3;
    KillTimer(pLoja[playerid][LojaTimer]);
    OcultarAssaltoLoja(playerid);
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid, 1);

    pLoja[playerid][CheckRouboLoja] = CreateDynamicCP(-1434.8376,-948.6710,201.0126, 1.0, 0, 0, playerid, 90.0, -1);
    pLoja[playerid][MapRouboLoja] = CreateDynamicMapIcon(-1434.8376,-948.6710,201.0126, 36, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);

    SendClientMessage(playerid, 0xFFFF00FF, "| LOJA | Você precisa ir até o ponto marcado no mapa");
    return 1;   
}