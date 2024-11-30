#include <YSI_Coding\y_hooks>

enum EletricPos
{
    Float:ElX,
    Float:ElY,
    Float:ElZ,
    Float:ElA
};

enum JogadorEletric
{
    bool:VehAleg,
    VehID,
    PosteStatus,
    PosteID,

    Text3D:PosteTexto,
    MapPoste,
    EscadaPoste,
    FerramentasCax,
    ParticulaPoste,
    
    ConeEx1,
    ConeEx2,
    ConeEx3
};
new pEletric[MAX_PLAYERS][JogadorEletric];
new EletPos[][EletricPos] = 
{
    {1338.2551,325.2522,19.7668,64.9316},
    {1341.8191,332.9075,19.7889,67.7914},
    {1351.8085,355.9160,19.7584,65.1351},
    {1355.1543,363.3575,19.7623,64.8552}
};


hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Eletricista{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", 0xFFFF00FF, 1336.8738,319.3459,20.2155, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1239, 1, 1336.8738,319.3459,20.2155, 0, 0, -1, 100.0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamic3DTextLabelEx(pEletric[playerid][PosteTexto]);
    DestroyDynamicMapIconEx(pEletric[playerid][MapPoste]);
    DestroyDynamicObjectEx(pEletric[playerid][EscadaPoste]);
    DestroyDynamicObjectEx(pEletric[playerid][FerramentasCax]);
    DestroyDynamicObjectEx(pEletric[playerid][ParticulaPoste]);
    DestroyVehicleEx(pEletric[playerid][VehID]);
    RemoverCones(playerid);

    new lsadsa[JogadorEletric];
    pEletric[playerid] = lsadsa;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        // Alugar
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1336.8738,319.3459,20.2155))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Eletricista")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(GetPVarInt(playerid, "DASNASDAZZA") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            if(pEletric[playerid][VehAleg] == false)
            {
                new i = random(sizeof(EletPos));
                pEletric[playerid][VehID] = CreateVehicleEx(playerid, 552, EletPos[i][ElX], EletPos[i][ElY], EletPos[i][ElZ], EletPos[i][ElA], 1, 1, 490, 0);
                VeiculoServer[pEletric[playerid][VehID]][Tranca] = 1;
                pEletric[playerid][VehAleg] = true;
                Jogador[playerid][Trabalhando] = true;
                MarcarPosicao(playerid, EletPos[i][ElX], EletPos[i][ElY], EletPos[i][ElZ]);
                SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você alugou um veículo");
                return 1;
            }
            VerificarMarcacao(playerid);
            DestroyVehicleEx(pEletric[playerid][VehID]);
            Jogador[playerid][Trabalhando] = false;
            pEletric[playerid][VehAleg] = false;
            SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você devolveu o seu veículo");
        }
    }
    return 1;
}

stock GetXYPoste(id, &Float:x, &Float:y, Float:distance)
{
    new Float:a;
    x = Poste[id][PosteX];
    y = Poste[id][PosteY];
    a = Poste[id][PosteRZ];
	// a += 90;
    x += ( distance * floatsin( -a+180, degrees ));
    y += ( distance * floatcos( -a+180, degrees ));
}

stock GetPosteID(model)
{
    new postemode,
        id = -1,
        i;
    
    switch(model)
    {
        case 1: postemode = 1308;
        case 0: postemode = -1;
    }

    while(id == -1)
    {
        i = random(MAX_POSTES);
        if(Poste[i][PosteColocado] == false) continue;

        if(postemode == -1){
            if(Poste[i][PosteModelo] != 1308) continue;
        }else{
            if(Poste[i][PosteModelo] != postemode) continue;   
        }
        id = i;
    }
    return id;
}

stock ReceberReparo(playerid)
{
    new Mensagem[128],
        asdsa = random(3100-2100)+2100;
    Jogador[playerid][Dinheiro] += asdsa;
    format(Mensagem, sizeof(Mensagem), "| ELETRICISTA | Você reparou um poste e recebeu {32CD32}$%s", DinheiroSeparar(asdsa));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

function ArrumandoPoste(playerid)
{
    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid);
    DestroyDynamic3DTextLabelEx(pEletric[playerid][PosteTexto]);
    DestroyDynamicMapIconEx(pEletric[playerid][MapPoste]); 
    DestroyDynamicObjectEx(pEletric[playerid][FerramentasCax]); 
    DestroyDynamicObjectEx(pEletric[playerid][ParticulaPoste]);

    if(GetPVarInt(playerid, "PodeEscada") == 0){
        DestroyDynamicObjectEx(pEletric[playerid][EscadaPoste]);
        pEletric[playerid][PosteStatus] = 0;
        ReceberReparo(playerid);
        return 1;
    }
    pEletric[playerid][PosteStatus] = 3;
    SendClientMessage(playerid, 0xFFFF00FF, "| ELETRICISTA | Retire a escada para receber pelo serviço");
    return 1;
}

CMD:poste(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Eletricista")) return 0;
    if(pEletric[playerid][PosteStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");
    if(pEletric[playerid][VehAleg] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você alugou nenhum veículo");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPlayerVehicleID(playerid) != pEletric[playerid][VehID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo alugado");
     
    new id = GetPosteID(random(1)),
        Mensagem[128];
    pEletric[playerid][PosteID] = id;
    pEletric[playerid][PosteStatus] = 1;
    
    SetPVarFloat(playerid, "MocaAltura", 0.0);
    SetPVarInt(playerid, "PosteEscada", 0);
    SetPVarInt(playerid, "PodeEscada", 0);
    SetPVarInt(playerid, "KDLASKDLSA", 0);

    if(Poste[id][PosteModelo] == 1308)
    {
        SetPVarInt(playerid, "PodeEscada", 1);
        SetPVarFloat(playerid, "MocaAltura", 7.0);
    }

    pEletric[playerid][MapPoste] = CreateDynamicMapIcon(Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ]+GetPVarFloat(playerid, "MocaAltura"), 27, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
    pEletric[playerid][ParticulaPoste] = CreateDynamicObject(18742, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ]+3+GetPVarFloat(playerid, "MocaAltura"), 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0, -1);

    format(Mensagem, sizeof(Mensagem), "Poste Quebrado{FFFFFF}\nAguardando eletricista {FFA500}%s[%d]", PegarNick(playerid), playerid);
    pEletric[playerid][PosteTexto] = CreateDynamic3DTextLabel(Mensagem, 0xFFFF00FF, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ]+GetPVarFloat(playerid, "MocaAltura"), 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 16.0, -1);

    format(Mensagem, sizeof(Mensagem), "| POSTE | Você precisa ir no poste localizado em {FFA500}%s{FFFFFF} para fazer uns reparos", AreaNome(Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ]));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

hook OnPlayerEditDynObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(GetPVarInt(playerid, "PodeEscada") == 0) return 1;

    switch(response)
    {
        case EDIT_RESPONSE_CANCEL:
        {
            SetPVarInt(playerid, "ColcondoEscada", 0);
            SetPVarInt(playerid, "PosteEscada", 0);
            DestroyDynamicObjectEx(pEletric[playerid][EscadaPoste]);
        }
        case EDIT_RESPONSE_FINAL:
        {
            SetPVarInt(playerid, "ColcondoEscada", 0);
            new id = pEletric[playerid][PosteID];
            if(GetDistanceBetweenPoints(x, y, z, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ]) > 8)
            {
                SetPVarInt(playerid, "PosteEscada", 0);
                DestroyDynamicObjectEx(pEletric[playerid][EscadaPoste]);
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou a escada muito longe do poste");
                return 1;
            }
            SetPVarInt(playerid, "PosteEscada", 1);
            SetDynamicObjectPos(objectid, x, y, z);
            SetDynamicObjectRot(objectid, rx, ry, rz);
        }
    }

    return 1;
}

stock CriarCones(playerid)
{
    new Float:Lka[4],
        Float:Rsc[2];
    GetVehiclePos(pEletric[playerid][VehID], Lka[0], Lka[1], Lka[2]);
	GetVehicleZAngle(pEletric[playerid][VehID], Lka[3]);
	Rsc[0] = Lka[0];
	Rsc[1] = Lka[1];
	GetXY(Lka[0], Lka[1], Lka[3], 4.0, 0.0);
	pEletric[playerid][ConeEx1] = CreateDynamicObject(1238, Lka[0], Lka[1], Lka[2]-0.6, 0.0, 0.0, 0.0);
	Lka[0] = Rsc[0];
	Lka[1] = Rsc[1];
	GetXY(Lka[0], Lka[1], Lka[3], -2.0, 90.0);
	pEletric[playerid][ConeEx2] = CreateDynamicObject(1238, Lka[0], Lka[1], Lka[2]-0.6, 0.0, 0.0, 0.0);
	Lka[0] = Rsc[0];
	Lka[1] = Rsc[1];
	GetXY(Lka[0], Lka[1], Lka[3], -2.0, 90.0);
	pEletric[playerid][ConeEx3] = CreateDynamicObject(1238, Lka[0]-2, Lka[1], Lka[2]-0.6, 0.0, 0.0, 0.0);
    return 1;
}

stock RemoverCones(playerid)
{
    DestroyDynamicObjectEx(pEletric[playerid][ConeEx1]);
    DestroyDynamicObjectEx(pEletric[playerid][ConeEx2]);
    DestroyDynamicObjectEx(pEletric[playerid][ConeEx3]);
    return 1;
}

CMD:escada(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Eletricista")) return 0;
    if(pEletric[playerid][PosteStatus] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não precisa da escada");
    if(GetPVarInt(playerid, "PosteEscada") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já colocou a escada");
    if(GetPVarInt(playerid, "PodeEscada") != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não precisa colocar escada");
    if(GetPVarInt(playerid, "ColcondoEscada") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está colocando a escada");

    new id = pEletric[playerid][PosteID];
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto do poste");
    if(!IsVehicleInRangeOfPoint(pEletric[playerid][VehID], 90.0, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está perto do poste");

    SetPVarInt(playerid, "ColcondoEscada", 1);
    pEletric[playerid][EscadaPoste] = CreateDynamicObject(1437, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ], 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0, -1);
    EditDynamicObject(playerid, pEletric[playerid][EscadaPoste]);

    if(GetPVarInt(playerid, "KDLASKDLSA") == 0){
        CriarCones(playerid);
        SetPVarInt(playerid, "KDLASKDLSA", 1);
    }
    

    SendClientMessage(playerid, 0xFFFF00FF, "| ELETRICISTA | Posicione e escada para subir até o ponto do problema.");
    return 1;
}

CMD:moverescada(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Eletricista")) return 0;
    if(pEletric[playerid][PosteStatus] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não precisa da escada");
    if(GetPVarInt(playerid, "PodeEscada") != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não precisa mover a escada");
    if(GetPVarInt(playerid, "PosteEscada") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não colocou nenhuma escada");
    if(GetPVarInt(playerid, "ColcondoEscada") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está posicionando a escada");

    new id = pEletric[playerid][PosteID];
    if(!IsPlayerInRangeOfPoint(playerid, 5.0, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto do poste");
    if(!IsVehicleInRangeOfPoint(pEletric[playerid][VehID], 90.0, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está perto do poste");

    SetPVarInt(playerid, "ColcondoEscada", 1);
    EditDynamicObject(playerid, pEletric[playerid][EscadaPoste]);
    return 1;
}

CMD:removerescada(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Eletricista")) return 0;
    if(GetPVarInt(playerid, "PosteEscada") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não colocou nenhuma escada");
    if(pEletric[playerid][PosteStatus] != 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode remover a escada");
    // if(GetPlayerSurfingObjectID(playerid) == pEletric[playerid][EscadaPoste]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa descer da escada");

    pEletric[playerid][PosteStatus] = 0;
    DestroyDynamicObjectEx(pEletric[playerid][EscadaPoste]);
    ReceberReparo(playerid);
    RemoverCones(playerid);
    return 1;
}

CMD:arrumarposte(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Eletricista")) return 0;
    if(pEletric[playerid][PosteStatus] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não precisa arrumar");
    if(GetPVarInt(playerid, "ColcondoEscada") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está colocando a escada");
    new id = pEletric[playerid][PosteID];

    if(Poste[id][PosteModelo] == 1308){
        if(GetPVarInt(playerid, "PosteEscada") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não colocou a escada");
        if(GetPVarInt(playerid, "ColcondoEscada") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está posicionando a escada");
    }

    if(!IsPlayerInRangeOfPoint(playerid, 5.0, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ]+GetPVarFloat(playerid, "MocaAltura"))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto do poste");
    if(!IsVehicleInRangeOfPoint(pEletric[playerid][VehID], 90.0, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está perto do poste");
    // if(GetPlayerSurfingObjectID(playerid) != pEletric[playerid][EscadaPoste]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na escada");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando agora");

    // ColocarEscada(playerid, id);
    TogglePlayerControllable(playerid, 0);
    ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
    new Float:Olas[4];
    GetPlayerPos(playerid, Olas[0], Olas[1], Olas[2]);
    GetPlayerFacingAngle(playerid, Olas[3]);

    GetXY(Olas[0], Olas[1], Olas[3], 0.5);

    if(GetPVarInt(playerid, "PosteEscada") == 0){
        pEletric[playerid][FerramentasCax] = CreateDynamicObject(19921, Olas[0], Olas[1], Olas[2]-1, 0.0, 0.0, float(random(360)), 0, 0, -1, 90.0, 90.0, -1);
        pEletric[playerid][EscadaPoste] = CreateDynamicObject(1238, Poste[id][PosteX], Poste[id][PosteY], Poste[id][PosteZ]-4, 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0, -1);
    }

    pEletric[playerid][PosteStatus] = 2;
    CriarProgresso(playerid, "Arrumando Poste, aguarde.", "ArrumandoPoste", 700);
    return 1;
}

stock ColocarEscada(playerid, id)
{
    new Float:Fdss[2];
	if(Poste[id][PosteRZ] >= 270.0 || Poste[id][PosteRZ] <= 95.0)
	{
		GetXYPoste(id, Fdss[0], Fdss[1], -3.3);
		Fdss[1] -= 1.1;
		if(Poste[id][PosteRZ] <= 95.0) Fdss[0] += 1.5;
		else Fdss[0] -= float(1);
	}
	else if(Poste[id][PosteRZ] > 95.0 || Poste[id][PosteRZ] < 270.0)
	{
		GetXYPoste(id, Fdss[0], Fdss[1], 1.0);
		Fdss[1] -= 3.2;
		if(Poste[id][PosteRZ] < 270.0) Fdss[0] -= 1.5;
		else Fdss[0] -= 0.5;
	}
	pEletric[playerid][EscadaPoste] = CreateDynamicObject(1437, Fdss[0], Fdss[1], Poste[id][PosteZ]-4, Poste[id][PosteRX]-20.0, Poste[id][PosteRY], Poste[id][PosteRZ]+180, 0, 0, -1, 120.0, 120.0, -1);
    return 1;
}