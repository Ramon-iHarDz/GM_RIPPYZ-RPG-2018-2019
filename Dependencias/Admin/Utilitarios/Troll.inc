#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{

    return 1;
}

CMD:troll(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Troll [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
 
    strcat(Dialog, "Enviar Speed-Hack\n");
    strcat(Dialog, "Parar Instantaneamente\n");
    strcat(Dialog, "Trocar para Carona");
    return 1;
}

/*SetPlayerSpeed(playerid, speed)
{
	if(speed < 1) speed = 1;
	new Float:vX, Float:vY, Float:vZ;
	if(GetPlayerVelocity(playerid, vX, vY, vZ))
	{
		new cur_speed = floatround(VectorSize(vX, vY, 0.0) * 179.28625);
		if(cur_speed <= 0)
		{
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			new Float:newVelX = floatcos((angle -= 270.0), degrees) * speed / 179.28625;
			SetPlayerVelocity(playerid, newVelX, floattan(angle, degrees) * newVelX, 0.0);
		}
		else
		{
			new Float:vMultiplier = float(speed) / float(cur_speed);
			SetPlayerVelocity(playerid, vX * vMultiplier, vY * vMultiplier, vZ * vMultiplier);
		}
		return 1;
	}
	return 0;
}*/