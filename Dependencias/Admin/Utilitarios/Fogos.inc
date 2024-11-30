#define MAX_FIREWORK 100
#define NON -1

enum EnumFirework
{
	FW_Owner,
	Float:FW_Pos[4],
	Float:FW_Height,
	Float:FW_Radius,
	FW_Amount,
	FW_RocketsReleased,
	FW_Timer,
	FW_Box
};
new FireworkInfo[MAX_FIREWORK][EnumFirework];

function EmptyFireworkSlot()
{
	for(new i=1; i < MAX_FIREWORK; i++){
        if(FireworkInfo[i][FW_Owner] != NON) return i;
    }
	return 0;
}

CMD:fogos(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
	new Float:height, Float:radius, amount, string[60];
	if(sscanf(params, "ffd", height, radius, amount)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Fogos [Height] [Radius] [Amount]");
	new eid = EmptyFireworkSlot();
	if(!eid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há vagas para fogos, aguarde.");
	GetPlayerPos(playerid, FireworkInfo[eid][FW_Pos][0], FireworkInfo[eid][FW_Pos][1], FireworkInfo[eid][FW_Pos][2]);
	GetPlayerFacingAngle(playerid, FireworkInfo[eid][FW_Pos][3]);

	FireworkInfo[eid][FW_RocketsReleased] =- 2;
	FireworkInfo[eid][FW_Radius] = radius;
	FireworkInfo[eid][FW_Height] = height;
	FireworkInfo[eid][FW_Owner] = playerid;
	FireworkInfo[eid][FW_Pos][0] += (2.0 * floatsin(-FireworkInfo[eid][FW_Pos][3], degrees));
	FireworkInfo[eid][FW_Pos][1] += (2.0 * floatcos(-FireworkInfo[eid][FW_Pos][3], degrees));
	FireworkInfo[eid][FW_Pos][2] -= 0.9;
	FireworkInfo[eid][FW_Box] = CreateObject(3016, FireworkInfo[eid][FW_Pos][0], FireworkInfo[eid][FW_Pos][1], FireworkInfo[eid][FW_Pos][2], 0,0,0);
	format(string, sizeof(string), "| ERRO | Você criou uma caixa ID: %d", eid);
	SendClientMessage(playerid, -1, string);
	return 1;
}

CMD:soltarfogos(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
	new eid;
	if(sscanf(params, "d", eid)) return SendClientMessage(playerid, -1, "| ERRO | Use: /SoltarFogos [ID]");
	if(FireworkInfo[eid][FW_Owner] != playerid) return 1;
	FireworkInfo[eid][FW_Timer] = SetTimerEx("StartFirework", 600, false, "d", eid);
	return 1;
}

function StartFirework(eid)
{
	DestroyObject(FireworkInfo[eid][FW_Box]);
	KillTimer(FireworkInfo[eid][FW_Timer]);
	FireworkInfo[eid][FW_Owner] = NON;

	new Float:distance, Float:Ax, Float:Ay, Float:Az, timdade, object;

	// new Float:dis = 10.0*FireworkInfo[eid][FW_RocketsReleased];
	if(++FireworkInfo[eid][FW_RocketsReleased] == 3){
        FireworkInfo[eid][FW_RocketsReleased] =- 2;
    }

	Ax = FireworkInfo[eid][FW_Pos][0]+(distance * floatsin(-FireworkInfo[eid][FW_Pos][3],degrees));
	Ay = FireworkInfo[eid][FW_Pos][1]+(distance * floatsin(-FireworkInfo[eid][FW_Pos][3],degrees));
	Az = FireworkInfo[eid][FW_Pos][2]+FireworkInfo[eid][FW_Height];

	object = CreateObject(3000,FireworkInfo[eid][FW_Pos][0],FireworkInfo[eid][FW_Pos][1],FireworkInfo[eid][FW_Pos][2],0,0,0);
	timdade = MoveObject(object, Ax, Ay, Az, 20.0);
    SetTimerEx("MakeSphere", timdade, false, "dffff", object, Ax, Ay, Az, FireworkInfo[eid][FW_Radius]);
	return 1;
}

function MakeSphere(nobject,Float:x,Float:y,Float:z,Float:radius)
{
    DestroyObject(nobject);
	new object, type[3]={19282,19283,19284};
	new Float:phi = 0.0,Float:theta = 0.0, timdade;
	new Float:Ax = 0.0,Float:Ay = 0.0,Float:Az = 0.0;
    CreateExplosion(x, y, z, 12, 10.0);
	for(new i; i < 26; i++) // 1 8 8 8 1
    { 
		Ax=x+(radius*floatsin(-phi,degrees)*floatcos(-theta,degrees));
		Ay=y+(radius*floatsin(-phi,degrees)*floatsin(-theta,degrees));
		Az=z+(radius*floatcos(-phi,degrees));

		object = CreateObject(type[random(3)], x, y, z, 0.0, 0.0, theta+45);
		timdade = MoveObject(object, Ax,Ay,Az, 5.0);
        SetTimerEx("FireworkRocketEnd", timdade, false, "d", object);

		//Reset
		theta += 45.0; 
        if(theta == 360.0)
        { 
            Ax = 0.0; 
            Ax = 0.0; 
            Ay = 0.0;
        }
        if((1+i)%8 == 1) phi += 45;
    }
	return 1;
}

function FireworkRocketEnd(object){
    return DestroyObject(object);
}