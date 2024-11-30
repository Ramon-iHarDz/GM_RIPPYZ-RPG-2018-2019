#include <YSI_Coding\y_hooks>

#define MAX_CARNES 12

enum CarnesInfo
{
    Float:CarneX,
    Float:CarneY,
    Float:CarneZ,

    Text3D:CarneTexto,
    CarneID,
    bool:CarneUsada,
    CarneTempo,
    CarneTimer
};

enum AcougueiroInfo
{
    CarneProcesso,
    CarnePrancha,
    CarneKg,
    JogadorCarne,
    Text3D:CarneTextoJogador
};

new Carne[MAX_CARNES][CarnesInfo];
new pAcougueiro[MAX_PLAYERS][AcougueiroInfo];

new CarneP[][CarnesInfo] = 
{
    {962.45441, 2140.74121, 1016.40002},
    {962.52063, 2123.59668, 1016.40002},
    {962.61261, 2127.19165, 1016.40002},
    {962.57098, 2130.57690, 1016.40002},
    {962.60278, 2134.02612, 1016.40002},
    {955.93213, 2140.33252, 1016.40002},
    {962.60876, 2137.28076, 1016.40002},
    {956.05341, 2137.22095, 1016.40002},
    {955.96759, 2134.01367, 1016.40002},
    {955.93860, 2130.13062, 1016.40002},
    {955.99298, 2126.41748, 1016.40002},
    {955.98541, 2122.84229, 1016.40002}
};


hook OnGameModeInit()
{
    CreateDynamicPickup(1239, 1, 1227.9802,181.7840,20.3766, 0, 0, -1, 120.0, -1);
    CreateDynamicMapIcon(1227.9802,181.7840,20.3766, 57, -1, 0, 0, -1, 120.0, MAPICON_LOCAL, -1);
    CreateDynamic3DTextLabel("Açougue{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para entrar", 0xFFFF00FF, 1227.9802,181.7840,20.3766, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 17.0, -1);

    CreateDynamicPickup(1239, 1, 948.6057,2104.0791,1011.0234, 406, 1, -1, 120.0, -1);
    CreateDynamic3DTextLabel("Açougue{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para sair", 0xFFFF00FF, 948.6057,2104.0791,1011.0234, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 406, 1, -1, 17.0, -1);

    CreateDynamic3DTextLabel("Açougue{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para colocar a carne", 0xFFFF00FF, 942.3400,2117.6887,1011.0303, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 406, 1, -1, 17.0, -1);
    CreateDynamic3DTextLabel("Açougue{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para pegar a caixa com carne", 0xFFFF00FF, 942.3800,2137.5266,1011.0234, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 406, 1, -1, 17.0, -1);
    CreateDynamic3DTextLabel("Açougue - Estoque{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para colocar a caixa", 0xFFFF00FF, 935.5947,2143.8000,1011.0234, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 406, 1, -1, 17.0, -1);


    for(new i=0; i < MAX_CARNES; i++){
        Carne[i][CarneID] = CreateDynamicObject(2589, CarneP[i][CarneX], CarneP[i][CarneY], CarneP[i][CarneZ], 0.0, 0.0, 0.0, 406, 1, -1, 90.0, 90.0, -1);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamic3DTextLabelEx(pAcougueiro[playerid][CarneTextoJogador]);
    if(pAcougueiro[playerid][CarneProcesso] == 1){
        new id = pAcougueiro[playerid][JogadorCarne];
        Carne[id][CarneUsada] = false;
    }
    if(pAcougueiro[playerid][CarneProcesso] == 3 || pAcougueiro[playerid][CarneProcesso] == 4) DestroyDynamicObjectEx(pAcougueiro[playerid][CarnePrancha]);

    new fddac[AcougueiroInfo];
    pAcougueiro[playerid] = fddac;
    return 1;
}

hook OnDynamicObjectMoved(objectid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(objectid != pAcougueiro[i][CarnePrancha]) continue;
        pAcougueiro[i][CarneProcesso] = 4;
        SendClientMessage(i, 0xFFA500FF, "| AÇOUGUE | Sua carne foi processada, vá pegar ela no final da esteira");
        break;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK)
    {
        // Entrada
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1227.9802,181.7840,20.3766))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1; 
            Jogador[playerid][uInteriorEx] = 406;
            GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
            SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);
            SetPlayerInterior(playerid, 1);
            SetPlayerVirtualWorld(playerid, 406);
            SetPlayerPos(playerid, 948.6057,2104.0791,1011.0234); 
        }

        // Saida
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 948.6057,2104.0791,1011.0234))
        {
            if(Jogador[playerid][uInteriorEx] != 406) return 1;
            if(GetPlayerInterior(playerid) != 1 || GetPlayerVirtualWorld(playerid) != 406) return 1;
            Jogador[playerid][uInteriorEx] = 0;
            SetPlayerInterior(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerPos(playerid, 1227.9802,181.7840,20.3766);
        }
    }

    else if(newkeys == KEY_YES)
    {
        // Começo Prancha
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 942.3400,2117.6887,1011.0303))
        {
            if(Jogador[playerid][uInteriorEx] != 406) return 1;
            if(GetPlayerInterior(playerid) != 1 && GetPlayerVirtualWorld(playerid) != 406) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Açougueiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pAcougueiro[playerid][CarneProcesso] != 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode fazer esse processo agora");
            pAcougueiro[playerid][CarneProcesso] = 3;
            RemovePlayerAttachedObject(playerid, 9);
            ApplyAnimation(playerid, "CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
            pAcougueiro[playerid][CarnePrancha] = CreateDynamicObject(2804, 942.4865, 2119.7739, 1011.2726, 0.0000, 0.0000, float(random(360)), 406, 1, -1, 90.0, 90.0, -1);
            MoveDynamicObject(pAcougueiro[playerid][CarnePrancha], 942.4865, 2135.3603, 1011.2726, 1.0); 
        }

        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 942.3800,2137.5266,1011.0234))
        {
            if(Jogador[playerid][uInteriorEx] != 406) return 1;
            if(GetPlayerInterior(playerid) != 1 && GetPlayerVirtualWorld(playerid) != 406) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Açougueiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pAcougueiro[playerid][CarneProcesso] != 4) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode fazer esse processo agora");
            pAcougueiro[playerid][CarneProcesso] = 5;
            DestroyDynamicObjectEx(pAcougueiro[playerid][CarnePrancha]);

            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
            SetPlayerAttachedObject(playerid, 9, 1220, 3, 0.1310, -0.4270, -0.1290, -7.3999, 3.4000, 29.9000, 0.5850, 0.5280, 0.6530, 0xFFFFFFFF, 0xFFFFFFFF);
            SendClientMessage(playerid, 0xFFA500FF, "| AÇOUGUE | Coloque a caixa no estoque de carnes");
        }

        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 935.5947,2143.8000,1011.0234))
        {
            if(Jogador[playerid][uInteriorEx] != 406) return 1;
            if(GetPlayerInterior(playerid) != 1 && GetPlayerVirtualWorld(playerid) != 406) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Açougueiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pAcougueiro[playerid][CarneProcesso] != 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode fazer esse processo agora");

            RemovePlayerAttachedObject(playerid, 9);
            ApplyAnimation(playerid, "CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);

            CarneProntas++;

            new Mensagem[128],
                Recibo = random(600-400)+400;
            Jogador[playerid][Dinheiro] += Recibo;
            pAcougueiro[playerid][CarneProcesso] = 0;

            format(Mensagem, sizeof(Mensagem), "| AÇOUGUE | Você recebeu {32CD32}$%s{FFFFFF} por {FFA500}%dkg{FFFFFF} de carne", DinheiroSeparar(Recibo), pAcougueiro[playerid][CarneKg]);
            SendClientMessage(playerid, -1, Mensagem);
        }
    }

    return 1;
}

function CortandoCarne(playerid)
{
    new i = GetPVarInt(playerid, "JOJAJUS");

    DestroyDynamicObjectEx(Carne[i][CarneID]);
    DestroyDynamic3DTextLabelEx(pAcougueiro[playerid][CarneTextoJogador]);
    Carne[i][CarneTempo] = 180;
    Carne[i][CarneUsada] = false;
    Carne[i][CarneTexto] = CreateDynamic3DTextLabel("Carne Retirada{FFFFFF}\nAguardando", 0xFFA500FF, CarneP[i][CarneX], CarneP[i][CarneY], CarneP[i][CarneZ], 13.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 406, 1, -1, 14.0, -1);
    Carne[i][CarneTimer] = SetTimerEx("RegenerarCarne", 1000, true, "d", i);

    pAcougueiro[playerid][CarneProcesso] = 2;
    TogglePlayerControllable(playerid, 1);

    ClearAnimations(playerid);
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
    SetPlayerAttachedObject(playerid, 9, 2804, 6, 0.0410, 0.0320, -0.1419, 89.0999, 0.0000, -150.7999, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);

    SendClientMessage(playerid, 0xFFA500FF, "| AÇOUGUE | Leve a carne até a prancha para ser processada");
    return 1;
}

function RegenerarCarne(id)
{
    new Mensagem[55];
    Carne[id][CarneTempo]--;
    format(Mensagem, sizeof(Mensagem), "Carne{FFFFFF}\nCarne chegando em {32CD32}%s", SegundosParaMinutosEx(Carne[id][CarneTempo]));
    UpdateDynamic3DTextLabelText(Carne[id][CarneTexto], -1, Mensagem);

    if(Carne[id][CarneTempo] <= 0){
        DestroyDynamic3DTextLabelEx(Carne[id][CarneTexto]);
        Carne[id][CarneID] = CreateDynamicObject(2589, CarneP[id][CarneX], CarneP[id][CarneY], CarneP[id][CarneZ], 0.0, 0.0, 0.0, 406, 1, -1, 90.0, 90.0, -1);
        KillTimer(Carne[id][CarneTimer]);
    }
    return 1;
}

CMD:cortarcarne(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Açougueiro")) return 0;
    if(Jogador[playerid][uInteriorEx] != 406) return 1;
    if(GetPlayerInterior(playerid) != 1 && GetPlayerVirtualWorld(playerid) != 406) return 1;
    if(pAcougueiro[playerid][CarneProcesso] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está fazendo o processo das carnes.");

    for(new i=0; i < MAX_CARNES; i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 6.0, CarneP[i][CarneX], CarneP[i][CarneY], CarneP[i][CarneZ])) continue;
        if(Carne[i][CarneTempo] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ainda não há carne aqui, espere chegar");
        if(Carne[i][CarneUsada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa carne já está sendo utilizada");
        
        TogglePlayerControllable(playerid, 0);

        new Mensagem[65];
        format(Mensagem, sizeof(Mensagem), "%s[%d]{FFFFFF} está cortando essa carne", PegarNick(playerid), playerid);
        pAcougueiro[playerid][CarneTextoJogador] = CreateDynamic3DTextLabel(Mensagem, 0xFFA500FF, CarneP[i][CarneX], CarneP[i][CarneY], 1010.02032+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 406, 1, -1, 11.0, -1);

        Carne[i][CarneUsada] = true;
        pAcougueiro[playerid][CarneProcesso] = 1;
        pAcougueiro[playerid][JogadorCarne] = i; 
        pAcougueiro[playerid][CarneKg] = random(60-30)+30;

        format(Mensagem, sizeof(Mensagem), "| AÇOUGUE | Você está cortando uma carne de {FFA500}%dkg", pAcougueiro[playerid][CarneKg]);
        SendClientMessage(playerid, -1, Mensagem);

        SetPVarInt(playerid, "JOJAJUS", i);

        CriarProgresso(playerid, "Cortando Carne, aguarde.", "CortandoCarne", 700);
        break;
    }
    return 1;
}