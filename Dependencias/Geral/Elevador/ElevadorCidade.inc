#include <YSI_Coding\y_hooks>

// Configuração
#define ELEVADOR_SPEED      (5.0)   
#define PORTAS_SPEED        (5.0)   
#define ELEVADOR_DELAY      (5000)  

// Private:
#define X_PORTAS_FECHADA        (1786.627685)
#define X_PORTAS_R_ABERTAS      (1785.027685)
#define X_PORTAS_L_ABERTAS      (1788.227685)
#define CHAO_Z_COORD          	(14.511476)
#define ELEVADOR_OFFSET         (0.059523)

// Regras
#define ELEVADOR_ESTADO_DESATIVADO        (0)
#define ELEVADOR_ESTADO_AGUARDANDO  (1)
#define ELEVEADOR_ESTADO_MOVENDO    (2)
#define ANDAR_INVALIDO               (-1)


new FloorNames[21][] =
{
	"{FF0000}1°{FFFFFF} Andar",
	"{FF0000}2°{FFFFFF} Andar",
	"{FF0000}3°{FFFFFF} Andar",
	"{FF0000}4°{FFFFFF} Andar",
	"{FF0000}5°{FFFFFF} Andar",
	"{FF0000}6°{FFFFFF} Andar",
	"{FF0000}7°{FFFFFF} Andar",
	"{FF0000}8°{FFFFFF} Andar",
	"{FF0000}9°{FFFFFF} Andar",
	"{FF0000}10°{FFFFFF} Andar",
	"{FF0000}11°{FFFFFF} Andar",
	"{FF0000}12°{FFFFFF} Andar",
	"{FF0000}13°{FFFFFF} Andar",
	"{FF0000}14°{FFFFFF} Andar",
	"{FF0000}15°{FFFFFF} Andar",
	"{FF0000}16°{FFFFFF} Andar",
	"{FF0000}17°{FFFFFF} Andar",
	"{FF0000}18°{FFFFFF} Andar",
	"{FF0000}19°{FFFFFF} Andar",
	"{FF0000}20°{FFFFFF} Andar",
	"{FF0000}21°{FFFFFF} Andar"
};

new Float:AndarZOffsets[21] =
{
    0.0,		// 0.0,
    8.5479,		// 8.5479,
    13.99945,   // 8.5479 + (5.45155 * 1.0),
    19.45100,   // 8.5479 + (5.45155 * 2.0),
    24.90255,   // 8.5479 + (5.45155 * 3.0),
    30.35410,   // 8.5479 + (5.45155 * 4.0),
    35.80565,   // 8.5479 + (5.45155 * 5.0),
    41.25720,   // 8.5479 + (5.45155 * 6.0),
    46.70875,   // 8.5479 + (5.45155 * 7.0),
    52.16030,   // 8.5479 + (5.45155 * 8.0),
    57.61185,   // 8.5479 + (5.45155 * 9.0),
    63.06340,   // 8.5479 + (5.45155 * 10.0),
    68.51495,   // 8.5479 + (5.45155 * 11.0),
    73.96650,   // 8.5479 + (5.45155 * 12.0),
    79.41805,   // 8.5479 + (5.45155 * 13.0),
    84.86960,   // 8.5479 + (5.45155 * 14.0),
    90.32115,   // 8.5479 + (5.45155 * 15.0),
    95.77270,   // 8.5479 + (5.45155 * 16.0),
    101.22425,  // 8.5479 + (5.45155 * 17.0),
    106.67580,	// 8.5479 + (5.45155 * 18.0),
    112.12735	// 8.5479 + (5.45155 * 19.0)
};


new Obj_Elevador, Obj_ElevadorPortas[2],
	Obj_FloorPortas[21][2],
    Text3D:Texto_Elevador, 
    Text3D:Texto_Floors[21],
    ElevadorEstado,
	ElevadorAndar,
    ElevadorFila[21],  	
	AndarChamadoPor[21],
    ElevadorImpulsoTempo
;

//Forward
forward Float:PegarElevadorZCoordParaAndar(floorid);
forward Float:PegarPortasZCoordParaAndar(floorid);
forward Elevador_Inicializacao();
forward DestruirElevador();
forward Elevador_AbrirPortas();
forward Elevador_FecharPortas();
forward Floor_AbrirPortas(floorid);
forward Floor_FecharPortas(floorid);
forward Elevador_MovendoParaFloor(floorid);
forward Elevador_Impulso(floorid);
forward Elevador_Desativar();
forward RemoverPrimeiroFilaAndar();
forward AdicionarPisoNaFila(floorid);
forward ResetElevadorFila();
forward LerProximoAndarNaFila();
forward DidJogadorRequerElevador(playerid);
forward MostrarDialogElevador(playerid);
forward ChamarElevador(playerid, floorid);
forward PisoNaFila(floorid);

hook OnGameModeInit()
{
	print("[Rippzy:Elevador:Cidade] Adicionado elevador na cidade");
	ResetElevadorFila();
	Elevador_Inicializacao();
	return 1;
}

hook OnObjectMoved(objectid)
{
    new Float:x, Float:y, Float:z;
	for(new i; i < sizeof(Obj_FloorPortas); i ++)
	{
		if(objectid == Obj_FloorPortas[i][0])
		{
		    GetObjectPos(Obj_FloorPortas[i][0], x, y, z);

		    if(x < X_PORTAS_L_ABERTAS - 0.5)  
		    {
				Elevador_MovendoParaFloor(ElevadorFila[0]);
				RemoverPrimeiroFilaAndar();
			}
		}
	}

	if(objectid == Obj_Elevador)  
	{
	    KillTimer(ElevadorImpulsoTempo); 
	    AndarChamadoPor[ElevadorAndar] = INVALID_PLAYER_ID;

	    Elevador_AbrirPortas();
	    Floor_AbrirPortas(ElevadorAndar);

	    GetObjectPos(Obj_Elevador, x, y, z);
	    Texto_Elevador	= Create3DTextLabel("{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para escolher o andar", 0xCCCCCCAA, 1784.9822, -1302.0426, z - 0.9, 4.0, 0, 1);

	    ElevadorEstado 	= ELEVADOR_ESTADO_AGUARDANDO;
	    SetTimer("Elevador_Desativar", ELEVADOR_DELAY, 0);
	}

	return 1;
}

Dialog:ElevadorDialogCidade(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(AndarChamadoPor[listitem] != INVALID_PLAYER_ID || PisoNaFila(listitem))
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O Elevador já foi chamado");
	else if(DidJogadorRequerElevador(playerid))
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já chamou o elevador!");
	else
	    ChamarElevador(playerid, listitem);
    return 0;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(!IsPlayerInAnyVehicle(playerid) && (newkeys & KEY_YES))
	{
	    new Float:pos[3];
	    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	    if(pos[1] < -1301.4 && pos[1] > -1303.2417 && pos[0] < 1786.2131 && pos[0] > 1784.1555)  
	        MostrarDialogElevador(playerid);
		else 
		{
		    if(pos[1] > -1301.4 && pos[1] < -1299.1447 && pos[0] < 1785.6147 && pos[0] > 1781.9902)
		    {
				new i=20;
				while(pos[2] < PegarPortasZCoordParaAndar(i) + 3.5 && i > 0)
				    i --;

				if(i == 0 && pos[2] < PegarPortasZCoordParaAndar(0) + 2.0)
				    i = -1;

				if(i <= 19)
				{
					ChamarElevador(playerid, i + 1);
					SendClientMessage(playerid, 0xFFFF00FF, "| APARTAMENTO | Elevador foi chamado");
				}
		    }
		}
	}

	return 1;
}

stock Elevador_Inicializacao()
{
	Obj_Elevador 			= CreateObject(18755, 1786.678100, -1303.459472, CHAO_Z_COORD + ELEVADOR_OFFSET, 0.000000, 0.000000, 270.000000);
	Obj_ElevadorPortas[0] 	= CreateObject(18757, X_PORTAS_FECHADA, -1303.459472, CHAO_Z_COORD, 0.000000, 0.000000, 270.000000);
	Obj_ElevadorPortas[1] 	= CreateObject(18756, X_PORTAS_FECHADA, -1303.459472, CHAO_Z_COORD, 0.000000, 0.000000, 270.000000);

	Texto_Elevador          = Create3DTextLabel("{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para escolher o andar", -1, 1784.9822, -1302.0426, 13.6491, 4.0, 0, 1);

	new string[300],
		Float:z;

	for(new i; i < sizeof(Obj_FloorPortas); i ++)
	{
	    Obj_FloorPortas[i][0] 	= CreateObject(18757, X_PORTAS_FECHADA, -1303.171142, PegarPortasZCoordParaAndar(i), 0.000000, 0.000000, 270.000000);
		Obj_FloorPortas[i][1] 	= CreateObject(18756, X_PORTAS_FECHADA, -1303.171142, PegarPortasZCoordParaAndar(i), 0.000000, 0.000000, 270.000000);

		format(string, sizeof(string), "%s\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para chamar o elevador", FloorNames[i]);

		if(i == 0)
		    z = 13.4713;
		else
		    z = 13.4713 + 8.7396 + ((i-1) * 5.45155);

		Texto_Floors[i]         = Create3DTextLabel(string, 0xCCCCCCAA, 1783.9799, -1300.7660, z, 10.5, 0, 1);
	}

	Floor_AbrirPortas(0);
	Elevador_AbrirPortas();

	return 1;
}

stock DestruirElevador()
{
	DestroyObject(Obj_Elevador);
	DestroyObject(Obj_ElevadorPortas[0]);
	DestroyObject(Obj_ElevadorPortas[1]);
	Delete3DTextLabel(Texto_Elevador);

	for(new i; i < sizeof(Obj_FloorPortas); i ++)
	{
	    DestroyObject(Obj_FloorPortas[i][0]);
		DestroyObject(Obj_FloorPortas[i][1]);
		Delete3DTextLabel(Texto_Floors[i]);
	}

	return 1;
}

stock Elevador_AbrirPortas()
{
	new Float:x, Float:y, Float:z;

	GetObjectPos(Obj_ElevadorPortas[0], x, y, z);
	MoveObject(Obj_ElevadorPortas[0], X_PORTAS_L_ABERTAS, y, z, PORTAS_SPEED);
	MoveObject(Obj_ElevadorPortas[1], X_PORTAS_R_ABERTAS, y, z, PORTAS_SPEED);

	for(new d=0; d < MAX_PLAYERS; d++){
        if(!IsPlayerInRangeOfPoint(d, 15.0, x, y, z)) continue;
        if(Jogador[d][Logado] == false) continue;
        if(GetPlayerInterior(d) != 0 || GetPlayerVirtualWorld(d) != 0) continue;
        PlayerPlaySound(d, 6002, 0.0, 0.0, 0.0);
    }

	return 1;
}

stock Elevador_FecharPortas()
{
    if(ElevadorEstado == ELEVEADOR_ESTADO_MOVENDO)
	    return 0;

    new Float:x, Float:y, Float:z;
	GetObjectPos(Obj_ElevadorPortas[0], x, y, z);
	MoveObject(Obj_ElevadorPortas[0], X_PORTAS_FECHADA, y, z, PORTAS_SPEED);
	MoveObject(Obj_ElevadorPortas[1], X_PORTAS_FECHADA, y, z, PORTAS_SPEED);
	return 1;
}

stock Floor_AbrirPortas(floorid)
{
    MoveObject(Obj_FloorPortas[floorid][0], X_PORTAS_L_ABERTAS, -1303.171142, PegarPortasZCoordParaAndar(floorid), PORTAS_SPEED);
	MoveObject(Obj_FloorPortas[floorid][1], X_PORTAS_R_ABERTAS, -1303.171142, PegarPortasZCoordParaAndar(floorid), PORTAS_SPEED);
	// PlaySoundForPlayersInRange(6401, 50.0, X_PORTAS_FECHADA, -1303.171142, PegarPortasZCoordParaAndar(floorid) + 5.0);
	return 1;
}

stock Floor_FecharPortas(floorid)
{
    MoveObject(Obj_FloorPortas[floorid][0], X_PORTAS_FECHADA, -1303.171142, PegarPortasZCoordParaAndar(floorid), PORTAS_SPEED);
	MoveObject(Obj_FloorPortas[floorid][1], X_PORTAS_FECHADA, -1303.171142, PegarPortasZCoordParaAndar(floorid), PORTAS_SPEED);
	// PlaySoundForPlayersInRange(6401, 50.0, X_PORTAS_FECHADA, -1303.171142, PegarPortasZCoordParaAndar(floorid) + 5.0);
	return 1;
}

stock Elevador_MovendoParaFloor(floorid)
{
	ElevadorEstado = ELEVEADOR_ESTADO_MOVENDO;
	ElevadorAndar = floorid;
	MoveObject(Obj_Elevador, 1786.678100, -1303.459472, PegarElevadorZCoordParaAndar(floorid), 0.25);
    MoveObject(Obj_ElevadorPortas[0], X_PORTAS_FECHADA, -1303.459472, PegarPortasZCoordParaAndar(floorid), 0.25);
    MoveObject(Obj_ElevadorPortas[1], X_PORTAS_FECHADA, -1303.459472, PegarPortasZCoordParaAndar(floorid), 0.25);
    Delete3DTextLabel(Texto_Elevador);
	ElevadorImpulsoTempo = SetTimerEx("Elevador_Impulso", 2000, 0, "i", floorid);
	return 1;
}

public Elevador_Impulso(floorid)
{
	StopObject(Obj_Elevador);
	StopObject(Obj_ElevadorPortas[0]);
	StopObject(Obj_ElevadorPortas[1]);
	
	MoveObject(Obj_Elevador, 1786.678100, -1303.459472, PegarElevadorZCoordParaAndar(floorid), ELEVADOR_SPEED);
    MoveObject(Obj_ElevadorPortas[0], X_PORTAS_FECHADA, -1303.459472, PegarPortasZCoordParaAndar(floorid), ELEVADOR_SPEED);
    MoveObject(Obj_ElevadorPortas[1], X_PORTAS_FECHADA, -1303.459472, PegarPortasZCoordParaAndar(floorid), ELEVADOR_SPEED);

	return 1;
}

public Elevador_Desativar()
{
	ElevadorEstado = ELEVADOR_ESTADO_DESATIVADO;
	LerProximoAndarNaFila();

	return 1;
}

stock RemoverPrimeiroFilaAndar()
{
	for(new i; i < sizeof(ElevadorFila) - 1; i ++)
	    ElevadorFila[i] = ElevadorFila[i + 1];

	ElevadorFila[sizeof(ElevadorFila) - 1] = ANDAR_INVALIDO;
	return 1;
}


stock AdicionarPisoNaFila(floorid)
{
	new slot = -1;
	for(new i; i < sizeof(ElevadorFila); i ++)
	{
	    if(ElevadorFila[i] == ANDAR_INVALIDO)
	    {
	        slot = i;
	        break;
	    }
	}

	if(slot != -1)
	{
	    ElevadorFila[slot] = floorid;
	    if(ElevadorEstado == ELEVADOR_ESTADO_DESATIVADO)
	        LerProximoAndarNaFila();

	    return 1;
	}

	return 0;
}

stock ResetElevadorFila()
{
	for(new i; i < sizeof(ElevadorFila); i ++){
	    ElevadorFila[i] 	= ANDAR_INVALIDO;
	    AndarChamadoPor[i] = INVALID_PLAYER_ID;
	}

	return 1;
}

stock PisoNaFila(floorid)
{
	for(new i; i < sizeof(ElevadorFila); i ++)
	    if(ElevadorFila[i] == floorid)
	        return 1;

	return 0;
}

stock LerProximoAndarNaFila()
{
	if(ElevadorEstado != ELEVADOR_ESTADO_DESATIVADO || ElevadorFila[0] == ANDAR_INVALIDO)
	    return 0;

	Elevador_FecharPortas();
	Floor_FecharPortas(ElevadorAndar);
	return 1;
}

stock DidJogadorRequerElevador(playerid)
{
	for(new i; i < sizeof(AndarChamadoPor); i ++)
	    if(AndarChamadoPor[i] == playerid)
	        return 1;

	return 0;
}

stock MostrarDialogElevador(playerid)
{
	new string[700];
	for(new i; i < sizeof(ElevadorFila); i ++)
	{
	    if(AndarChamadoPor[i] != INVALID_PLAYER_ID)
	        strcat(string, "{FF0000}");

	    strcat(string, FloorNames[i]);
	    strcat(string, "\n");
	}
    Dialog_Show(playerid, ElevadorDialogCidade, DIALOG_STYLE_LIST, "{FF0000}Apartamento", string, "Selecionar", "Fechar");
	return 1;
}

stock ChamarElevador(playerid, floorid)
{
	if(AndarChamadoPor[floorid] != INVALID_PLAYER_ID || PisoNaFila(floorid))
	    return 0;

	AndarChamadoPor[floorid] = playerid;
	AdicionarPisoNaFila(floorid);
	return 1;
}

stock Float:PegarElevadorZCoordParaAndar(floorid)
    return (CHAO_Z_COORD + AndarZOffsets[floorid] + ELEVADOR_OFFSET); 

stock Float:PegarPortasZCoordParaAndar(floorid)
	return (CHAO_Z_COORD + AndarZOffsets[floorid]);
