#include <YSI_Coding\y_hooks>

//Config
#define ELEVATOR_SPEED      (5.0)
#define DOORS_SPEED         (3.0)
#define ELEVATOR_WAIT_TIME  (5000)  


//Offets
#define X_DOOR_R_OPENED     (289.542419)
#define X_DOOR_L_OPENED     (286.342407)
#define Y_DOOR_R_OPENED     (-1609.640991)
#define Y_DOOR_L_OPENED     (-1609.076049)

#define X_FDOOR_R_OPENED    (289.492431)
#define X_FDOOR_L_OPENED    (286.292419)
#define Y_FDOOR_R_OPENED    (-1609.870971)
#define Y_FDOOR_L_OPENED    (-1609.306030)

#define GROUND_Z_COORD      (18.755348)     // (33.825077)
#define X_ELEVATOR_POS      (287.942413)
#define Y_ELEVATOR_POS      (-1609.341064)


//Elevador Regras
#define ELEVATOR_STATE_IDLE     (0)
#define ELEVATOR_STATE_WAITING  (1)
#define ELEVATOR_STATE_MOVING   (2)

#define INVALID_FLOOR           (-1)

static FloorNames[14][] =
{
	"{00FF00}Garagem",
	"{FF0000}Terreo",
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
	"{FF0000}12°{FFFFFF} Andar"
};

// Elevator floor Z heights
static Float:FloorZOffsets[14] =
{
    0.0, 		// Car Park
    15.069729,  // Ground Floor
    29.130733,	// First Floor
    33.630733,  // Second Floor = 29.130733 + 4.5
    38.130733,  // Third Floor = 33.630733 + 4.5
    42.630733,  // Fourth Floor = 38.130733 + 4.5
    47.130733,  // Fifth Floor = 42.630733 + 4.5
    51.630733,  // Sixth Floor = 47.130733 + 4.5
    56.130733,  // Seventh Floor = 51.630733 + 4.5
    60.630733,  // Eighth Floor = 56.130733 + 4.5
    65.130733,  // Ninth Floor = 60.630733 + 4.5
    69.630733,  // Tenth Floor = 65.130733 + 4.5
    74.130733,  // Eleventh Floor = 69.630733 + 4.5
    78.630733,  // Twelfth Floor = 74.130733 + 4.5
};


new Obj_Elevator, Obj_ElevatorDoors[2], Obj_FloorDoors[14][2];
new Text3D:Label_Elevator, Text3D:Label_Floors[14];
new ElevatorState;
new	ElevatorFloor;  
new ElevatorQueue[14];
new	FloorRequestedBy[14];
new ElevatorBoostTimer;

new bool:TocandoPraia;
new TempoFDSPraia;


// Public:
forward CallElevator(playerid, floorid);    
forward ShowElevatorDialog(playerid);

// Private:
forward Elevator_Initialize();
forward Elevator_Destroy();

forward Elevator_OpenDoors();
forward Elevator_CloseDoors();
forward Floor_OpenDoors(floorid);
forward Floor_CloseDoors(floorid);

forward Elevator_MoveToFloor(floorid);
forward Elevator_Boost(floorid);      
forward Elevator_TurnToIdle();

forward ReadNextFloorInQueue();
forward RemoveFirstQueueFloor();
forward AddFloorToQueue(floorid);
forward IsFloorInQueue(floorid);
forward ResetElevatorQueue();

forward DidPlayerRequestElevator(playerid);

forward Float:GetElevatorZCoordForFloor(floorid);
forward Float:GetDoorsZCoordForFloor(floorid);

hook OnGameModeInit()
{
	print("[Rippzy:Elevador:Praia] Adicionado elevador na praia!");
	ResetElevatorQueue();
    Elevator_Initialize();
    return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 1226, 265.481, -1581.1, 32.9311, 5.0);
    RemoveBuildingForPlayer(playerid, 6518, 280.297, -1606.2, 72.3984, 250.0);
	return 1;
}

hook OnObjectMoved(objectid)
{
    new Float:x, Float:y, Float:z;
	for(new i; i < sizeof(Obj_FloorDoors); i ++){
		if(objectid == Obj_FloorDoors[i][0]){
		    GetObjectPos(Obj_FloorDoors[i][0], x, y, z);
            if (y < Y_DOOR_L_OPENED - 0.5){
				Elevator_MoveToFloor(ElevatorQueue[0]);
				RemoveFirstQueueFloor();
			}
		}
	}

	if(objectid == Obj_Elevator)  
	{
	    KillTimer(ElevatorBoostTimer);  
	    FloorRequestedBy[ElevatorFloor] = INVALID_PLAYER_ID;
	    Elevator_OpenDoors();
	    Floor_OpenDoors(ElevatorFloor);
	    GetObjectPos(Obj_Elevator, x, y, z);
	    Label_Elevator	= Create3DTextLabel("{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para escolher o andar", -1, X_ELEVATOR_POS + 1.6, Y_ELEVATOR_POS - 1.85, z - 0.4, 4.0, 0, 1);
	    ElevatorState 	= ELEVATOR_STATE_WAITING;
	    SetTimer("Elevator_TurnToIdle", ELEVATOR_WAIT_TIME, 0);
	}

	return 1;
}

Dialog:ElevadorDialogPraia(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(FloorRequestedBy[listitem] != INVALID_PLAYER_ID || IsFloorInQueue(listitem))
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O Elevador já foi chamado");
	else if(DidPlayerRequestElevator(playerid))
		SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já chamou o elevador");
	else
	    CallElevator(playerid, listitem);
	return 0;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (!IsPlayerInAnyVehicle(playerid) && (newkeys & KEY_YES))
	{
	    new Float:pos[3];
	    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	    if (pos[1] > (Y_ELEVATOR_POS - 1.8) && pos[1] < (Y_ELEVATOR_POS + 1.8) && pos[0] < (X_ELEVATOR_POS + 1.8) && pos[0] > (X_ELEVATOR_POS - 1.8))
	    {
	        ShowElevatorDialog(playerid);
	    }
		else
		{
		    if(pos[1] < (Y_ELEVATOR_POS - 1.81) && pos[1] > (Y_ELEVATOR_POS - 3.8) && pos[0] > (X_ELEVATOR_POS + 1.21) && pos[0] < (X_ELEVATOR_POS + 3.8))
		    {
				new i = 13;
				while(pos[2] < GetDoorsZCoordForFloor(i) + 3.5 && i > 0)
				    i --;

				if(i == 0 && pos[2] < GetDoorsZCoordForFloor(0) + 2.0)
				    i = -1;

				if (i <= 12){
				    if (ElevatorState != ELEVATOR_STATE_MOVING){
				        if (ElevatorFloor == i + 1){
	                        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O Elevador já está nesse andar");
	                        return 1;
				        }
				    }
					CallElevator(playerid, i + 1);
					SendClientMessage(playerid, 0xFFFF00FF, "| APARTAMENTO | O Elevador foi chamado, aguarde.");
					return 1;
				}
		    }
		}
	}
	return 1;
}

stock Elevator_Initialize()
{
	Obj_Elevator 			= CreateObject(18755, X_ELEVATOR_POS, Y_ELEVATOR_POS, GROUND_Z_COORD, 0.000000, 0.000000, 80.000000);
	Obj_ElevatorDoors[0] 	= CreateObject(18757, X_ELEVATOR_POS, Y_ELEVATOR_POS, GROUND_Z_COORD, 0.000000, 0.000000, 80.000000);
	Obj_ElevatorDoors[1] 	= CreateObject(18756, X_ELEVATOR_POS, Y_ELEVATOR_POS, GROUND_Z_COORD, 0.000000, 0.000000, 80.000000);
	Label_Elevator = Create3DTextLabel("{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para escolher o andar", -1, X_ELEVATOR_POS + 1.6, Y_ELEVATOR_POS - 1.85, GROUND_Z_COORD - 0.4, 4.0, 0, 1);
	new string[300], Float:z;
	for (new i; i < sizeof(Obj_FloorDoors); i ++)
	{
	    Obj_FloorDoors[i][0] 	= CreateObject(18757, X_ELEVATOR_POS, Y_ELEVATOR_POS - 0.245, GetDoorsZCoordForFloor(i) + 0.05, 0.000000, 0.000000, 80.000000);
		Obj_FloorDoors[i][1] 	= CreateObject(18756, X_ELEVATOR_POS, Y_ELEVATOR_POS - 0.245, GetDoorsZCoordForFloor(i) + 0.05, 0.000000, 0.000000, 80.000000);

		format(string, sizeof(string), "%s\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para chamar o elevador", FloorNames[i]);
		z = GetDoorsZCoordForFloor(i);
		Label_Floors[i] = Create3DTextLabel(string, -1, X_ELEVATOR_POS + 2, Y_ELEVATOR_POS -3, z - 0.2, 10.5, 0, 1);
	}
	Floor_OpenDoors(0);
	Elevator_OpenDoors();
	return 1;
}

stock Elevator_Destroy()
{
	DestroyObject(Obj_Elevator);
	DestroyObject(Obj_ElevatorDoors[0]);
	DestroyObject(Obj_ElevatorDoors[1]);
	Delete3DTextLabel(Label_Elevator);

	for(new i; i < sizeof(Obj_FloorDoors); i ++)
	{
	    DestroyObject(Obj_FloorDoors[i][0]);
		DestroyObject(Obj_FloorDoors[i][1]);
		Delete3DTextLabel(Label_Floors[i]);
	}

	return 1;
}

function PararSomPraia()
{
	TocandoPraia = false;
	for(new i=0; i < MAX_PLAYERS; i++)
	{
		if(!IsPlayerConnected(i)) continue;
		if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "BolinhaAeroBLALA") == 0) continue;
		PlayerPlaySound(i, 1166, 0.0, 0.0, 0.0);
		SetPVarInt(i, "BolinhaAeroBLALA", 0);
    }
	return 1;
}

stock Elevator_OpenDoors()
{
	new Float:x, Float:y, Float:z;
	GetObjectPos(Obj_ElevatorDoors[0], x, y, z);
	MoveObject(Obj_ElevatorDoors[0], X_DOOR_L_OPENED, Y_DOOR_L_OPENED, z, DOORS_SPEED);
	MoveObject(Obj_ElevatorDoors[1], X_DOOR_R_OPENED, Y_DOOR_R_OPENED, z, DOORS_SPEED);
	for(new i=0; i < MAX_PLAYERS; i++)
	{
		if(!IsPlayerConnected(i)) continue;
		if(Jogador[i][Logado] == false) continue;
        if(!IsPlayerInRangeOfPoint(i, 15.0, x, y, z)) continue;
        if(GetPlayerInterior(i) != 0 || GetPlayerVirtualWorld(i) != 0) continue;
        PlayerPlaySound(i, 1165, x, y, z);
		SetPVarInt(i, "BolinhaAeroBLALA", 1);
    }
	TocandoPraia = true;
	TempoFDSPraia = SetTimer("PararSomPraia", 1000, false);
	return 1;
}

stock Elevator_CloseDoors()
{
    if(ElevatorState == ELEVATOR_STATE_MOVING)
	    return 0;

    new Float:x, Float:y, Float:z;
	GetObjectPos(Obj_ElevatorDoors[0], x, y, z);
	MoveObject(Obj_ElevatorDoors[0], X_ELEVATOR_POS, Y_ELEVATOR_POS, z, DOORS_SPEED);
	MoveObject(Obj_ElevatorDoors[1], X_ELEVATOR_POS, Y_ELEVATOR_POS, z, DOORS_SPEED);

	if(TocandoPraia == true) KillTimer(TempoFDSPraia);
	for(new i=0; i < MAX_PLAYERS; i++)
	{
		if(!IsPlayerConnected(i)) continue;
		if(Jogador[i][Logado] == false) continue;
        if(!IsPlayerInRangeOfPoint(i, 15.0, x, y, z)) continue;
        if(GetPlayerInterior(i) != 0 || GetPlayerVirtualWorld(i) != 0) continue;
        PlayerPlaySound(i, 1166, x, y, z);
		SetPVarInt(i, "BolinhaAeroBLALA", 1);
    }
	TocandoPraia = true;
	TempoFDSPraia = SetTimer("PararSomPraia", 1000, false);
	return 1;
}

stock Floor_OpenDoors(floorid)
{
    MoveObject(Obj_FloorDoors[floorid][0], X_FDOOR_L_OPENED, Y_FDOOR_L_OPENED, GetDoorsZCoordForFloor(floorid) + 0.05, DOORS_SPEED);
	MoveObject(Obj_FloorDoors[floorid][1], X_FDOOR_R_OPENED, Y_FDOOR_R_OPENED, GetDoorsZCoordForFloor(floorid) + 0.05, DOORS_SPEED);
	// PlaySoundForPlayersInRange(6401, 50.0, X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid) + 5.0);
	return 1;
}

stock Floor_CloseDoors(floorid)
{
    MoveObject(Obj_FloorDoors[floorid][0], X_ELEVATOR_POS, Y_ELEVATOR_POS - 0.245, GetDoorsZCoordForFloor(floorid) + 0.05, DOORS_SPEED);
	MoveObject(Obj_FloorDoors[floorid][1], X_ELEVATOR_POS, Y_ELEVATOR_POS - 0.245, GetDoorsZCoordForFloor(floorid) + 0.05, DOORS_SPEED);
	
	// PlaySoundForPlayersInRange(6401, 50.0, X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid) + 5.0);

	return 1;
}

stock Elevator_MoveToFloor(floorid)
{
	ElevatorState = ELEVATOR_STATE_MOVING;
	ElevatorFloor = floorid;
	MoveObject(Obj_Elevator, X_ELEVATOR_POS, Y_ELEVATOR_POS, GetElevatorZCoordForFloor(floorid), 0.25);
    MoveObject(Obj_ElevatorDoors[0], X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid), 0.25);
    MoveObject(Obj_ElevatorDoors[1], X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid), 0.25);
    Delete3DTextLabel(Label_Elevator);
	ElevatorBoostTimer = SetTimerEx("Elevator_Boost", 2000, 0, "i", floorid);
	return 1;
}

public Elevator_Boost(floorid)
{
	StopObject(Obj_Elevator);
	StopObject(Obj_ElevatorDoors[0]);
	StopObject(Obj_ElevatorDoors[1]);
	
	MoveObject(Obj_Elevator, X_ELEVATOR_POS, Y_ELEVATOR_POS, GetElevatorZCoordForFloor(floorid), ELEVATOR_SPEED);
    MoveObject(Obj_ElevatorDoors[0], X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid), ELEVATOR_SPEED);
    MoveObject(Obj_ElevatorDoors[1], X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid), ELEVATOR_SPEED);

	return 1;
}

public Elevator_TurnToIdle()
{
	ElevatorState = ELEVATOR_STATE_IDLE;
	ReadNextFloorInQueue();

	return 1;
}

stock RemoveFirstQueueFloor()
{
	for(new i; i < sizeof(ElevatorQueue) - 1; i ++)
	    ElevatorQueue[i] = ElevatorQueue[i + 1];

	ElevatorQueue[sizeof(ElevatorQueue) - 1] = INVALID_FLOOR;

	return 1;
}

stock AddFloorToQueue(floorid)
{
	new slot = -1;
	for(new i; i < sizeof(ElevatorQueue); i ++)
	{
	    if(ElevatorQueue[i] == INVALID_FLOOR)
	    {
	        slot = i;
	        break;
	    }
	}

	if(slot != -1)
	{
	    ElevatorQueue[slot] = floorid;
	    if(ElevatorState == ELEVATOR_STATE_IDLE)
	        ReadNextFloorInQueue();

	    return 1;
	}

	return 0;
}

stock ResetElevatorQueue()
{
	for(new i; i < sizeof(ElevatorQueue); i ++)
	{
	    ElevatorQueue[i] 	= INVALID_FLOOR;
	    FloorRequestedBy[i] = INVALID_PLAYER_ID;
	}

	return 1;
}

stock IsFloorInQueue(floorid)
{
	for(new i; i < sizeof(ElevatorQueue); i ++)
	    if(ElevatorQueue[i] == floorid)
	        return 1;

	return 0;
}

stock ReadNextFloorInQueue()
{
	if(ElevatorState != ELEVATOR_STATE_IDLE || ElevatorQueue[0] == INVALID_FLOOR)
	    return 0;

	Elevator_CloseDoors();
	Floor_CloseDoors(ElevatorFloor);

	return 1;
}

stock DidPlayerRequestElevator(playerid)
{
	for(new i; i < sizeof(FloorRequestedBy); i ++)
	    if(FloorRequestedBy[i] == playerid)
	        return 1;

	return 0;
}

stock ShowElevatorDialog(playerid)
{
	new string[700];
	for(new i; i < sizeof(ElevatorQueue); i ++)
	{
	    if(FloorRequestedBy[i] != INVALID_PLAYER_ID)
	        strcat(string, "{FF0000}");

	    strcat(string, FloorNames[i]);
	    strcat(string, "\n");
	}
	Dialog_Show(playerid, ElevadorDialogPraia, DIALOG_STYLE_LIST, "{FF0000}Apartamento", string, "Selecionar", "Fechar");
	return 1;
}

stock CallElevator(playerid, floorid)
{
	if(FloorRequestedBy[floorid] != INVALID_PLAYER_ID || IsFloorInQueue(floorid))
	    return 0;

	FloorRequestedBy[floorid] = playerid;
	AddFloorToQueue(floorid);
	return 1;
}

stock Float:GetElevatorZCoordForFloor(floorid)
{
    return (GROUND_Z_COORD + FloorZOffsets[floorid]);
}

stock Float:GetDoorsZCoordForFloor(floorid)
{
	return (GROUND_Z_COORD + FloorZOffsets[floorid]);
}

