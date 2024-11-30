#include <YSI_Coding\y_hooks>
#define 	MAX_ARMACHAO	(1000)

enum DropArmas
{
	bool:ArmaDropada,

	ArmaDropBalas,
	ArmaDropModelo,
	ArmaDropID,
	Text3D:ArmaDropTexto,
	ArmaVirtual,
	ArmaInterior,

	Float:ArmaX,
	Float:ArmaY,
	Float:ArmaZ
};

new aDrop[MAX_ARMACHAO][DropArmas];

stock PegarArmaChaoID()
{
	for(new i=0; i < MAX_ARMACHAO; i++){
		if(aDrop[i][ArmaDropada] == true) continue;
		return i;
	}
	return -1;
}

stock ArmaPerto(Float:x, Float:y, Float:z)
{
	for(new i=0; i < MAX_ARMACHAO; i++){
		if(aDrop[i][ArmaDropada] == false) continue;
		if(GetDistanceBetweenPoints(x, y, z, aDrop[i][ArmaX], aDrop[i][ArmaY], aDrop[i][ArmaZ]) < 7) return true;
	}
	return false;
}

stock PegarModeloArma(modl)
{
	new id;
	switch(modl)
	{
		case 2: id = 333;
		case 3: id = 334;
		case 4: id = 335;
		case 5: id = 336;
		case 6: id = 337;
		case 7: id = 338;
		case 8: id = 339;
		case 10: id = 321;
		case 11: id = 322;
		case 12: id = 324;
		case 13: id = 324;
		case 14: id = 325;
		case 15: id = 326;
		case 16: id = 342;
		case 17: id = 343;
		case 18: id = 344;
		case 22: id = 346;
		case 23: id = 347;
		case 24: id = 348;
		case 25: id = 349;
		case 26: id = 350;
		case 27: id = 351;
		case 28: id = 352;
		case 29: id = 353;
		case 30: id = 355;
		case 31: id = 356;
		case 32: id = 372;
		case 33: id = 357;
		case 34: id = 358;
		case 35: id = 359;
		case 36: id = 360;
		case 37: id = 361;
		case 38: id = 362;
		case 39: id = 363;
		case 40: id = 364;
		case 41: id = 365;
		case 42: id = 366;
		case 43: id = 367;
		case 44: id = 369;
		case 45: id = 369;
		case 46: id = 371;
		default: id = -1;
	}
	return id;
}

Dialog:ArmasMenu(playerid, response, listitem, inputtext[])
{
	if(!response) return 1;
	new cArmaID,
        cBalaID;
	GetPlayerWeaponData(playerid, listitem, cArmaID, cBalaID);
	if(cArmaID == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem armas nesse slot");
	new id = PegarArmaChaoID();
	if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode dropar arma no momento");

	new cArmaNome[32],
        Mensagem[128],
		Float:Goda[3];
	GetPlayerPos(playerid, Goda[0], Goda[1], Goda[2]);
	if(ArmaPerto(Goda[0], Goda[1], Goda[2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode dropar perto de uma arma");

	GetWeaponName(cArmaID, cArmaNome, sizeof(cArmaNome));
	RemoverArma(playerid, cArmaID);

	aDrop[id][ArmaDropada] = true;
	aDrop[id][ArmaX] = Goda[0];
	aDrop[id][ArmaY] = Goda[1];
	aDrop[id][ArmaZ] = Goda[2];
	aDrop[id][ArmaDropBalas] = cBalaID;
	aDrop[id][ArmaDropModelo] = cArmaID;

	aDrop[id][ArmaVirtual] = GetPlayerVirtualWorld(playerid);
	aDrop[id][ArmaInterior] = GetPlayerInterior(playerid);

	format(Mensagem, sizeof(Mensagem), "Arma {FFA500}%s{FFFFFF} : {1E90FF}%d{FFFFFF} Bala(s)\nUse: {CCCCCC}'/PegarArma'{FFFFFF} para pegar", cArmaNome, cBalaID);
	aDrop[id][ArmaDropTexto] = CreateDynamic3DTextLabel(Mensagem, -1, Goda[0], Goda[1], Goda[2]-0.7, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), -1, 16.0, -1);

	new modla = PegarModeloArma(cArmaID);
	if(modla != -1){
		aDrop[id][ArmaDropID] = CreateDynamicObject(modla, Goda[0], Goda[1], Goda[2]-0.7, 0.0, 0.0, float(random(360)), GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), -1, 80.0, 80.0, -1);
	}

	format(Mensagem, sizeof(Mensagem), "| ARMA | Você dropou a arma %s no chão com %d bala(s)", cArmaNome, cBalaID);
	SendClientMessage(playerid, 0xFFFF00FF, Mensagem);

	return 1;
}

CMD:pegararma(playerid)
{
	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
	for(new i=0; i < MAX_ARMACHAO; i++){
		if(aDrop[i][ArmaDropada] == false) continue;
		if(!IsPlayerInRangeOfPoint(playerid, 3.0, aDrop[i][ArmaX], aDrop[i][ArmaY], aDrop[i][ArmaZ])) continue;
		if(GetPlayerInterior(playerid) != aDrop[i][ArmaInterior] || GetPlayerVirtualWorld(playerid) != aDrop[i][ArmaVirtual]) return 1;
		aDrop[i][ArmaDropada] = false;

		new Mensagem[128],
			cArmaNome[32];

		DestroyDynamic3DTextLabelEx(aDrop[i][ArmaDropTexto]);
		DestroyDynamicObjectEx(aDrop[i][ArmaDropID]);

		GetWeaponName(aDrop[i][ArmaDropModelo], cArmaNome, sizeof(cArmaNome));
		format(Mensagem, sizeof(Mensagem), "| ARMA | Você pegou arma %s no chão com %d bala(s)", cArmaNome, aDrop[i][ArmaDropBalas]);
		SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
		GivePlayerWeapon(playerid, aDrop[i][ArmaDropModelo], aDrop[i][ArmaDropBalas]);
		break;
	}
	return 1;
}

CMD:armas(playerid)
{
	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode usar esse comando a pé");
    if(GetPlayerSpeed(playerid) > 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando em movimento");

	new Dialog[1000],
        cArmaNome[32],
        cArmaID,
        cBalaID;
    strcat(Dialog, "Slot\tArma\tBalas\n");
    for(new i=0; i < 12; i++)
    {
        GetPlayerWeaponData(playerid, i, cArmaID, cBalaID);
		GetWeaponName(cArmaID, cArmaNome, sizeof(cArmaNome));
		if(cArmaID < 1) strcatEx(Dialog, "%d.\t{FF4500}Nenhuma Arma\n", i+1);
		else strcatEx(Dialog, "%d.\t{00BFFF}%s\t{FFA500}%d\n", i+1, cArmaNome, cBalaID);
    }
    Dialog_Show(playerid, ArmasMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Armas", Dialog, "Selecionar", "Fechar");
	return 1;
}

CMD:limpararmas(playerid)
{
    if(Jogador[playerid][Admin] < 3) return 0;
    for(new i=0; i < MAX_ARMACHAO; i++){
		if(aDrop[i][ArmaDropada] == false) continue;
		aDrop[i][ArmaDropada] = false;
		DestroyDynamic3DTextLabelEx(aDrop[i][ArmaDropTexto]);
		DestroyDynamicObjectEx(aDrop[i][ArmaDropID]);
    }
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você removeu todas as armas dropadas no chão");
    return 1;
}