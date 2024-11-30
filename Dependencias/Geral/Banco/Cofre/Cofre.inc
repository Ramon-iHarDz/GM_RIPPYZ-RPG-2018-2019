#include <YSI_Coding\y_hooks>

enum Jaolg
{
    Text3D:CofreTexto,
    bool:CofreAssalto,
    Float:CofreX,
    Float:CofreY,
    Float:CofreZ
};

enum LaserXinax
{
    LaserObjeto,
    Float:LaserX,
    Float:LaserY,
    Float:LaserZ,
    Float:LaserRX,
    Float:LaserRY,
    Float:LaserRZ
};

new bool:AssaltandoCofre;
new bool:BancoAssaltado;
new bool:CofreBloqueado;
new bool:PoliciaPodeEntrar;
new BloquearRoubo;
new AreaCofre;
new PortaCofre;
new AlarmeTempo;
new bool:AlarmeAtivado;
new Text3D:AvisoExplosao;
new Text3D:TextoExplosao;
new CofreInfo[8][Jaolg];
new Chinax[18][LaserXinax];
new KeyPadRoubo;

new RouboQuant[MAX_PLAYERS];
new RouboInff[MAX_PLAYERS][2];

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Keypad{FFFFFF}\nUse: /Invadir", 0xe2b960FF, 2136.1179,1607.1724,994.2933, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 17.0, -1);
    TextoExplosao = CreateDynamic3DTextLabel("Porta Cofre{FFFFFF}\nUse: /ExplodirPorta", 0xe2b960FF, 2144.1748,1626.1620,993.6882, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 17.0, -1);

    PortaCofre = CreateDynamicObject(19799, 2145.1948, 1627.0108, 994.2637, 0.0000, 180.0000, 180.0000, 1064, 1, -1, 190.0, 190.0, -1); //CaligulasVaultDoor

    CreateDynamic3DTextLabel("Cofre{FFFFFF}\nAperta {CCCCCC}'F'{FFFFFF} para entrar", 0xFFFF00FF, 2653.7871,-1700.9834,1016.5886, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 17.0, -1);
    CreateDynamicPickup(1239, 1, 2653.7871,-1700.9834,1016.5886, 1064, 1, -1, 90.0, -1);

    CreateDynamic3DTextLabel("Cofre{FFFFFF}\nAperta {CCCCCC}'F'{FFFFFF} para sair", 0xFFFF00FF, 2147.7395,1603.8732,1006.1677, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 17.0, -1);
    CreateDynamicPickup(1239, 1, 2147.7395,1603.8732,1006.1677, 1064, 1, -1, 90.0, -1);
    AreaCofre = CreateDynamicRectangle(2129.9536,1612.4541, 2159.2881,1644.7728, 1064, 1, -1);
    
    new Float:Aols[6];
    for(new i=0; i < 8; i++)
    {
        switch(i)
        {
            case 0: {Aols[0] = 2146.4199; Aols[1] = 1641.2258; Aols[2] = 993.5761;}
            case 1: {Aols[0] = 2146.6514; Aols[1] = 1637.1547; Aols[2] = 993.5761;}
            case 2: {Aols[0] = 2146.6252; Aols[1] = 1633.2739; Aols[2] = 993.5761;}
            case 3: {Aols[0] = 2146.6174; Aols[1] = 1629.2941; Aols[2] = 993.5761;}
            case 4: {Aols[0] = 2141.5300; Aols[1] = 1629.2450; Aols[2] = 993.5761;}
            case 5: {Aols[0] = 2141.4426; Aols[1] = 1633.1936; Aols[2] = 993.5761;}
            case 6: {Aols[0] = 2141.5562; Aols[1] = 1637.1865; Aols[2] = 993.5761;}
            case 7: {Aols[0] = 2141.4861; Aols[1] = 1641.1251; Aols[2] = 993.5761;}
        }
        CofreInfo[i][CofreX] = Aols[0];
        CofreInfo[i][CofreY] = Aols[1];
        CofreInfo[i][CofreZ] = Aols[2];
    }

    for(new i=0; i < 18; i++)
    {
        switch(i)
        {
            case 0: {Aols[0] = 2129.4501; Aols[1] = 1612.3421; Aols[2] = 993.5938; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 0.0;}
            case 1: {Aols[0] = 2129.4501; Aols[1] = 1612.3421; Aols[2] = 995.0944; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 0.0;}
            case 2: {Aols[0] = 2129.4501; Aols[1] = 1612.3421; Aols[2] = 996.5346; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 0.0;}
            case 3: {Aols[0] = 2158.9096; Aols[1] = 1612.3421; Aols[2] = 993.5938; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 180.0000;}
            case 4: {Aols[0] = 2158.9096; Aols[1] = 1612.3421; Aols[2] = 995.0941; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 180.0000;}
            case 5: {Aols[0] = 2158.9096; Aols[1] = 1612.3421; Aols[2] = 996.5345; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 180.0000;}
            case 6: {Aols[0] = 2129.4501; Aols[1] = 1617.5343; Aols[2] = 993.5938; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 0.0;}
            case 7: {Aols[0] = 2129.4501; Aols[1] = 1617.5626; Aols[2] = 996.5346; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 0.0;}
            case 8: {Aols[0] = 2129.4501; Aols[1] = 1617.4932; Aols[2] = 995.0944; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 0.0;}
            case 9: {Aols[0] = 2158.9096; Aols[1] = 1617.5637; Aols[2] = 996.5345; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 180.0000;}
            case 10: {Aols[0] = 2158.9096; Aols[1] = 1617.4952; Aols[2] = 995.0941; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 180.0000;}
            case 11: {Aols[0] = 2158.9096; Aols[1] = 1617.5327; Aols[2] = 993.5938; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 180.0000;}
            case 12: {Aols[0] = 2158.9096; Aols[1] = 1622.6340; Aols[2] = 993.5938; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 180.0000;}
            case 13: {Aols[0] = 2158.9096; Aols[1] = 1622.6552; Aols[2] = 995.0941; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 180.0000;}
            case 14: {Aols[0] = 2158.9096; Aols[1] = 1622.6850; Aols[2] = 996.5345; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 180.0000;}
            case 15: {Aols[0] = 2129.4501; Aols[1] = 1622.6325; Aols[2] = 993.5938; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 0.0;}
            case 16: {Aols[0] = 2129.4501; Aols[1] = 1622.6517; Aols[2] = 995.0944; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 0.0;}
            case 17: {Aols[0] = 2129.4501; Aols[1] = 1622.6822; Aols[2] = 996.5346; Aols[3] = 0.0; Aols[4] = 0.0; Aols[5] = 0.0;}

        }
        Chinax[i][LaserX] = Aols[0];
        Chinax[i][LaserY] = Aols[1];
        Chinax[i][LaserZ] = Aols[2];
        Chinax[i][LaserRX] = Aols[3];
        Chinax[i][LaserRY] = Aols[4];
        Chinax[i][LaserRZ] = Aols[5];
    }
    CriarLaser();
    return 1;
}

stock CriarLaser()
{
    for(new i=0; i < 18; i++){
        Chinax[i][LaserObjeto] = CreateDynamicObject(18643, Chinax[i][LaserX], Chinax[i][LaserY], Chinax[i][LaserZ], Chinax[i][LaserRX], Chinax[i][LaserRY], Chinax[i][LaserRZ], 1064, 1, -1, 190.0, 190.0, -1); //LaserPointer1
    }
    return 1;
}

stock DeletarLaser()
{
    for(new i=0; i < 18; i++){
        DestroyDynamicObjectEx(Chinax[i][LaserObjeto]);
    }
    return 1;  
}

hook OnPlayerPreso(playerid, pm)
{
    if(GetPVarInt(playerid, "EfetuandoRouboCOF") == 1){
        SetPVarInt(playerid, "EfetuandoRouboCOF", 0);
        TogglePlayerControllable(playerid, 1);
        RemovePlayerAttachedObject(playerid, 7);
        PararProgresso(playerid);
        AssaltandoCofre = false;
    }
    if(GetPVarInt(playerid, "Mochhila") == 0) return 1;
    CancelarRouboBanco(playerid);
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(GetPVarInt(playerid, "EfetuandoRouboCOF") == 1){
        SetPVarInt(playerid, "EfetuandoRouboCOF", 0);
        TogglePlayerControllable(playerid, 1);
        RemovePlayerAttachedObject(playerid, 7);
        PararProgresso(playerid);
        AssaltandoCofre = false;
    }
    if(GetPVarInt(playerid, "Mochhila") == 0) return 1;
    CancelarRouboBanco(playerid);
    return 1;
}

function DesativarAlarme()
{
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "DentroCofre") == 0){
            if(!IsPolicia(i)) continue;
            if(pPolicia[i][PegouUniformePolicia] == false) continue;
            SendClientMessage(i, 0x1E90FFFF, "| CENTRAL | Acesso ao interior do cofre foi liberado. Vocês tem 5 minutos para verificarem tudo");
            continue;
        }
        if(GetPVarInt(i, "AlarmeTocando") == 0) continue;
        SetPVarInt(i, "AlarmeTocando", 0);
        PlayerPlaySound(i, 0, 0.0, 0.0, 0.0);
        SendClientMessage(i, -1, "| CHEFÃO | O Banco foi bloqueado por {e2b960}5 minutos{FFFFFF} até os policias verificarem o cofre");
    }
    AlarmeAtivado = false;
    BloquearRoubo = 300;
    PoliciaPodeEntrar = true;
    SetTimerEx("RouboTempo", 1000, false, "d", 0);
    return 1;
}

function RouboTempo(id)
{
    BloquearRoubo--;
    if(BloquearRoubo > 0) return SetTimerEx("RouboTempo", 1000, false, "d", id);
    PoliciaPodeEntrar = false;
    ExpulsarCofre(id);
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid != AreaCofre) return 1;
    if(BancoAssaltado == true) return 1;
    if(AlarmeAtivado == true) return 1;
    if(PoliciaPodeEntrar == true) return 1;
    if(!PodeAssaltar(playerid)) return 1;
    AlarmeAtivado = true;
    AlarmeTempo = SetTimer("DesativarAlarme", 120000, false);

    new Picpy;
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "DentroCofre") == 0) continue;
        if(GetPVarInt(i, "EfetuandoRouboCOF") == 1){
            SetPVarInt(i, "EfetuandoRouboCOF", 0);
            TogglePlayerControllable(i, 1);
            RemovePlayerAttachedObject(i, 7);
            PararProgresso(i);
            AssaltandoCofre = false;
        }
        PlayerPlaySound(i, 3401, 0.0, 0.0, 0.0);
        SetPVarInt(i, "AlarmeTocando", 1);
        Picpy++;
    }
    EnviarAvisoAssalto(Picpy);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "EfetuandoRouboCOF") == 1) AssaltandoCofre = false;
    DestroyDynamicMapIconEx(RouboInff[playerid][0]);
    DestroyDynamicCPEx(RouboInff[playerid][1]);
    RouboQuant[playerid] = 0;
    return 1;
}

stock CancelarRouboBanco(playerid)
{
    SetPVarInt(playerid, "Mochhila", 0);
    RemovePlayerAttachedObject(playerid, 7);
    DestroyDynamicMapIconEx(RouboInff[playerid][0]);
    DestroyDynamicCPEx(RouboInff[playerid][1]);
    if(GetPVarInt(playerid, "AlarmeTocando") == 1){
        PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
        SetPVarInt(playerid, "AlarmeTocando", 0);   
    }
    SetPVarInt(playerid, "DentroCofre", 0);
    RouboQuant[playerid] = 0;
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != RouboInff[playerid][1]) return 1;
    DestroyDynamicMapIconEx(RouboInff[playerid][0]);
    DestroyDynamicCPEx(RouboInff[playerid][1]);

    SetPVarInt(playerid, "Mochhila", 0);
    RemovePlayerAttachedObject(playerid, 7);

    new CofMoney = random(6000-4000)+4000;
    new Toly = (CofMoney*RouboQuant[playerid]);
    new Mensagem[128];
    Jogador[playerid][Dinheiro] += Toly;
    Jogador[playerid][Estrelas] += 7;

    format(Mensagem, sizeof(Mensagem), "| MÁFIA | Você recebeu {FFA500}$%s{FFFFFF} por {e2b960}%d{FFFFFF} cofre(s) roubado(s)", DinheiroSeparar(Toly), RouboQuant[playerid]);
    RouboQuant[playerid] = 0;
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_SECONDARY_ATTACK) return 1;

    // Banco
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 2653.7871,-1700.9834,1016.5886))
    {
        if(GetPlayerVirtualWorld(playerid) != 1064 || GetPlayerInterior(playerid) != 1) return 1;
        if(CofreBloqueado == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Cofre está passando por uma perícia, você não pode entrar agora");
        if(!PodeAssaltar(playerid)){
            if(PoliciaPodeEntrar == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode entrar agora no cofre");
        }
        if(PodeAssaltar(playerid)){
            if(BancoAssaltado == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Cofre foi fechado pelas autoridades, você não pode entrar no momento, aguarde do lado de fora.");
        }

        SetPVarInt(playerid, "DentroCofre", 1);
        if(!IsPolicia(playerid)){
            if(PoliciaPatrulha() < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode entrar no cofre com 3 policiais em patrulha");
            Jogador[playerid][Estrelas] += 1;
        }
        if(BancoAssaltado == true){
            PlayerPlaySound(playerid, 3401, 0.0, 0.0, 0.0);
            SetPVarInt(playerid, "AlarmeTocando", 1);
        }
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2147.7395,1603.8732,1006.1677);
        SetTimerEx("Destravar", 3000, false, "d", playerid);
    }

    // Cofre
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 2147.7395,1603.8732,1006.1677))
    {
        if(GetPlayerVirtualWorld(playerid) != 1064 || GetPlayerInterior(playerid) != 1) return 1;
        
        SetPVarInt(playerid, "DentroCofre", 0);
        if(GetPVarInt(playerid, "AlarmeTocando") == 1){
            PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
            SetPVarInt(playerid, "AlarmeTocando", 0);   
        }
        TogglePlayerControllable(playerid, 0);
        SetPlayerPos(playerid, 2653.7871,-1700.9834,1016.5886);
        SetTimerEx("Destravar", 3000, false, "d", playerid);
    }
    return 1;
}

function ExpulsarCofre(CofreBlock)
{
    if(CofreBlock == 1) CofreBloqueado = true;
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "DentroCofre") == 0) continue;
        SetPVarInt(i, "DentroCofre", 0);
        if(GetPVarInt(i, "AlarmeTocando") == 1){
            PlayerPlaySound(i, 0, 0.0, 0.0, 0.0);
            SetPVarInt(i, "AlarmeTocando", 0);   
        }
        TogglePlayerControllable(i, 0);
        SetPlayerPos(i, 2653.7871,-1700.9834,1016.5886);
        SetTimerEx("Destravar", 3000, false, "d", i);
    }
    return 1;
}

function RegenerarBanco(explo)
{
    for(new i=0; i < 8; i++){
        DestroyDynamic3DTextLabelEx(CofreInfo[i][CofreTexto]);
        CofreInfo[i][CofreAssalto] = false;
    }
    TextoExplosao = CreateDynamic3DTextLabel("Porta Cofre{FFFFFF}\nUse: /ExplodirPorta", 0xe2b960FF, 2144.1748,1626.1620,993.6882, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 17.0, -1);
    switch(explo)
    {
        case 0:
        {
            KeyPadRoubo = gettime()+1800;
            new Float:Flsad[3];
            GetDynamicObjectPos(PortaCofre, Flsad[0], Flsad[1], Flsad[2]);
            MoveDynamicObject(PortaCofre, Flsad[0], Flsad[1], Flsad[2]-0.001, 1.0, -1000.0, -1000.0, 180.0);
            CriarLaser();
        }
        case 1:
        {
            PortaCofre = CreateDynamicObject(19799, 2145.1948, 1627.0108, 994.2637, 0.0000, 180.0000, 180.0000, 1064, 1, -1, 190.0, 190.0, -1); //CaligulasVaultDoor   
        }
    }
    BancoAssaltado = false;
    CofreBloqueado = false;
    return 1;
}

function TocarAlarme()
{
    new Picsa;
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "DentroCofre") == 0) continue;
        PlayerPlaySound(i, 3401, 0.0, 0.0, 0.0);
        SetPVarInt(i, "AlarmeTocando", 1);
        SendClientMessage(i, -1, "| MÁFIA | Você tem {e2b960}10 minutos{FFFFFF} até que os policiais invadam o cofre");
        Picsa++;
    }
    EnviarAvisoAssalto(Picsa);
    SetTimer("EntrarCofre", 600000, false);
    return 1;
}

function ExplosaoPorta()
{
    DestroyDynamic3DTextLabelEx(AvisoExplosao);
    AbrirCofre(true);
    return 1;
}

function EntrarCofre()
{
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "DentroCofre") == 0){
            if(!IsPolicia(i)) continue;
            if(pPolicia[i][PegouUniformePolicia] == false) continue;
            SendClientMessage(i, 0x1E90FFFF, "| CENTRAL | Acesso ao interior do cofre foi liberado. Vocês tem 5 minutos para verificarem tudo");
            continue;
        }
        if(GetPVarInt(i, "AlarmeTocando") == 0) continue;
        SetPVarInt(i, "AlarmeTocando", 0);
        PlayerPlaySound(i, 0, 0.0, 0.0, 0.0);
        SendClientMessage(i, -1, "| CHEFÃO | Acesso ao interior do cofre foi aberto para os policias");
    }
    BloquearRoubo = 300;
    PoliciaPodeEntrar = true;
    SetTimerEx("RouboTempo", 1000, false, "d", 1);
    return 1;
}

function AssaltoPorta(playerid)
{
    if(AlarmeAtivado == true){
        AlarmeAtivado = false;
        KillTimer(AlarmeTempo);
    }
    BloquearRoubo = 0;
    BancoAssaltado = true;
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid, 1);
    SetPVarInt(playerid, "EfetuandoRouboCOF", 0);

    ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
    RemovePlayerAttachedObject(playerid, 7);

    DestroyDynamic3DTextLabel(TextoExplosao);
    switch(GetPVarInt(playerid, "TipoRoubo"))
    {
        case 0:
        {
            Jogador[playerid][Raspberry] -= 1;
            AbrirCofre(false);
        }
        case 1:
        {
            Jogador[playerid][Dinamites] -= 1;
            AvisoExplosao = CreateDynamic3DTextLabel("Bomba{FFFFFF}\nBomba explodindo em {FFA500}10 segundos", 0xe2b960FF, 2144.1748,1626.1620,993.6882, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 21.0, -1);
            SetTimer("ExplosaoPorta", 10000, false);
        }
    }

    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "DentroCofre") == 0) continue;
        Jogador[i][Estrelas] += 30;
        if(GetPVarInt(playerid, "TipoRoubo") == 1) SendClientMessage(i, -1, "| MÁFIA | Você tem {e2b960}10 minutos{FFFFFF} até que os policiais invadam o cofre");
        else SendClientMessage(i, -1, "| MÁFIA | Você tem {FFA500}01:30{FFFFFF} até que o alarme toque");
    }
    return 1;
}

stock EnviarAvisoAssalto(Picsa)
{
    new Mensagem[75];
    format(Mensagem, sizeof(Mensagem), "| CENTRAL | O Cofre do banco está sendo invadido por %d assaltante(s)", Picsa);
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "DentroCofre") == 1) continue;
        if(!IsPolicia(i)) continue;
        if(pPolicia[i][PegouUniformePolicia] == false) continue;
        SendClientMessage(i, 0x1E90FFFF, Mensagem);
    }
    // format(Mensagem, sizeof(Mensagem), "| NOTÍCIAS | Banco está sendo invadido por %d assaltante(s)", Picsa);
    // SendClientMessageToAll(0x7FFF00FF, Mensagem);
    return 1;
}

stock PodeAssaltar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Assaltante") && strcmp(Jogador[playerid][Profissao], "Terrorista")) return false;
    return true;
}

stock AbrirCofre(bool:Explosao)
{
    for(new i=0; i < 8; i++){
        CofreInfo[i][CofreTexto] = CreateDynamic3DTextLabel("Cofre{FFFFFF}\nUse: /Roubar para assaltar", 0xe2b960FF, CofreInfo[i][CofreX], CofreInfo[i][CofreY], CofreInfo[i][CofreZ], 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 17.0, -1);
    }

    if(Explosao == false)
    {
        DeletarLaser();
        new Float:Flsad[3];
        GetDynamicObjectPos(PortaCofre, Flsad[0], Flsad[1], Flsad[2]);
        MoveDynamicObject(PortaCofre, Flsad[0], Flsad[1], Flsad[2]+0.001, 2.0, -1000.0, -1000.0, 90.0);
        SetTimer("TocarAlarme", 78000, false);
    }
    else
    {
        DestroyDynamicObjectEx(PortaCofre);
        CreateExplosion(2144.1748,1626.1620,993.6882, 3, 2.0);
        SetTimer("EntrarCofre", 600000, false);
    }
    SetTimerEx("RegenerarBanco", 3600000, false, "d", Explosao);
    return 1;
}

CMD:invadir(playerid)
{
    if(GetPVarInt(playerid, "DentroCofre") == 0) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, 2136.1179,1607.1724,994.2933)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto do keypad"); 
    if(!PodeAssaltar(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(AlarmeAtivado == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O Alarme foi ativado, exploda a porta do cofre");
    if(BancoAssaltado == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O Banco já foi assaltado");
    if(AssaltandoCofre == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O Cofre já está sendo invádido, aguarde.");
    if(Jogador[playerid][Raspberry] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem Raspberry para hackear o sistema");
    if(BloquearRoubo > 0){
        new Mensagem[90];
        format(Mensagem, sizeof(Mensagem), "| ERRO | Você não pode roubar agora, aguarde %s", SegundosParaMinutosEx(BloquearRoubo));
        SendClientMessage(playerid, 0xFF4500FF, Mensagem);
        return 1;
    }
    if(KeyPadRoubo > gettime())
    {
        new Mensagem[90];
        format(Mensagem, sizeof(Mensagem), "| ERRO | Você não pode roubar agora, aguarde %s", SegundosParaMinutosEx(KeyPadRoubo));
        SendClientMessage(playerid, 0xFF4500FF, Mensagem);
        return 1;
    }

    TogglePlayerControllable(playerid, 0);
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
    SetPlayerAttachedObject(playerid, 7, 19893, 6, 0.0000, -0.0360, -0.1459, -105.5000, 1.2000, -102.8999, 1.2460, 1.0000, 1.1810, 0xFFFFFFFF, 0xFFFFFFFF); 
    SetPVarInt(playerid, "EfetuandoRouboCOF", 1);
    SetPVarInt(playerid, "TipoRoubo", 0);
    AssaltandoCofre = true;
    CriarProgresso(playerid, "Hackeando sistema, aguarde.", "AssaltoPorta", 800);
    return 1;
}

CMD:explodirporta(playerid)
{
    if(GetPVarInt(playerid, "DentroCofre") == 0) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, 2144.1748,1626.1620,993.6882)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto da porta do cofre"); 
    if(!PodeAssaltar(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(BancoAssaltado == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O Banco já foi assaltado");
    if(AssaltandoCofre == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O Cofre já está sendo invádido, aguarde.");
    if(Jogador[playerid][Dinamites] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem Dinamites para hackear o sistema");
    if(BloquearRoubo > 0){
        new Mensagem[90];
        format(Mensagem, sizeof(Mensagem), "| ERRO | Você não pode roubar agora, aguarde %s", SegundosParaMinutosEx(BloquearRoubo));
        SendClientMessage(playerid, 0xFF4500FF, Mensagem);
        return 1;
    }

    SetPVarInt(playerid, "EfetuandoRouboCOF", 1);
    SetPVarInt(playerid, "TipoRoubo", 1);
    AssaltandoCofre = true;
    ClearAnimations(playerid);
    TogglePlayerControllable(playerid, 0);
    ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
    CriarProgresso(playerid, "Colocando bomba, aguarde.", "AssaltoPorta", 50);
    return 1;
}

function AssaltoCofreGG(playerid)
{
    SetPVarInt(playerid, "Aslar", 0);
    ClearAnimations(playerid, 1);
    TogglePlayerControllable(playerid, 1);
    if(RouboQuant[playerid] == 0)
    {
        RouboInff[playerid][0] = CreateDynamicMapIcon(-2818.5698,-1582.1786,141.3575, 56, -1, -1, -1, playerid, 999999.9, MAPICON_GLOBAL, -1);
        RouboInff[playerid][1] = CreateDynamicCP(-2818.5698,-1582.1786,141.3575, 1.0, 0, 0, playerid, 90.0, -1);
    }
    RouboQuant[playerid]++;
    Jogador[playerid][Estrelas] += 1;
    return 1;
}

CMD:roubar(playerid)
{
    if(GetPVarInt(playerid, "DentroCofre") == 0) return 0;
    for(new i=0; i < 8; i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, CofreInfo[i][CofreX], CofreInfo[i][CofreY], CofreInfo[i][CofreZ])) continue;
        if(GetPVarInt(playerid, "Aslar") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
        if(BancoAssaltado == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Cofre ainda não foi aberto.");
        if(!PodeAssaltar(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode roubar");
        if(CofreInfo[i][CofreAssalto] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse cofre já foi assaltado");
        CofreInfo[i][CofreAssalto] = true;

        Jogador[playerid][Estrelas] += 1;
        SetPVarInt(playerid, "Aslar", 1);
        if(GetPVarInt(playerid, "Mochhila") == 0){
            SetPVarInt(playerid, "Mochhila", 1);
            SetPlayerAttachedObject(playerid, 7, 11745, 1, 0.0729, -0.1270, -0.0079, 77.5999, 159.6999, 29.3999, 0.8590, 0.7560, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
        }

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "Cofre{FFFFFF}\nAssaltado por {e2b960}%s[%d]", PegarNick(playerid), playerid);
        UpdateDynamic3DTextLabelText(CofreInfo[i][CofreTexto], 0xe2b960FF, Mensagem);
        ClearAnimations(playerid);
        TogglePlayerControllable(playerid, 0);
        ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
        CriarProgresso(playerid, "Roubando, aguarde.", "AssaltoCofreGG", 700);

        if(GetPVarInt(playerid, "AlarmeTocando") == 1){
            format(Mensagem, sizeof(Mensagem), "| CENTRAL | Assaltante identificado(a) como %s[%d]", PegarNick(playerid), playerid);
            for(new d=0; d < MAX_PLAYERS; d++){
                if(!IsPlayerConnected(d)) continue;
                if(Jogador[d][Logado] == false) continue;
                if(GetPVarInt(d, "DentroCofre") == 1) continue;
                if(!IsPolicia(d)) continue;
                if(pPolicia[d][PegouUniformePolicia] == false) continue;
                SendClientMessage(d, 0x1E90FFFF, Mensagem);
            }
        }
        break;
    }
    return 1;
}