#include <YSI_Coding\y_hooks>

enum JogadorSkateInfo
{
	bool:UsandoSkate,
    bool:Atividade,
	SkateObjeto
};
new JogadorSkate[MAX_PLAYERS][JogadorSkateInfo];

hook OnPlayerDisconnect(playerid, reason){
    DestroyDynamicObjectEx(JogadorSkate[playerid][SkateObjeto]);
    new dsad[JogadorSkateInfo];
    JogadorSkate[playerid] = dsad;
    return 1;
}

CMD:usarskate(playerid){
    if(Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Liberado apenas para admin, aguarde.");
	if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode utilizar o skate dentro de um veículo");
	ApplyAnimation(playerid, "CARRY","null",0,0,0,0,0,0,0);
	ApplyAnimation(playerid, "SKATE","null",0,0,0,0,0,0,0);
	ApplyAnimation(playerid, "CARRY","crry_prtial",4.0,0,0,0,0,0);
    PlayerPlaySound(playerid, 21000, 0, 0, 0);
    if(JogadorSkate[playerid][UsandoSkate] == false)
    {
        JogadorSkate[playerid][UsandoSkate] = true;
        SetPlayerAttachedObject(playerid, 6, 19878,6, -0.055999, 0.013000, 0.000000, -84.099983, 0.000000, -106.099998, 1.000000, 1.000000, 1.000000);
        SetPlayerArmedWeapon(playerid, 0);
        return 1;
    }
    JogadorSkate[playerid][UsandoSkate] = false;
    DestroyDynamicObjectEx(JogadorSkate[playerid][SkateObjeto]);
    RemovePlayerAttachedObject(playerid, 6);
	return 1;
}
 
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(JogadorSkate[playerid][UsandoSkate] == false || GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
	if(newkeys & KEY_HANDBRAKE)
    {
		ApplyAnimation(playerid, "SKATE","skate_sprint", 4.1, 1, 1, 1, 1, 1, 1);
        if(JogadorSkate[playerid][Atividade] == false)
        {
            JogadorSkate[playerid][Atividade] = true;
            RemovePlayerAttachedObject(playerid, 6);
            DestroyDynamicObjectEx(JogadorSkate[playerid][SkateObjeto]); 
            JogadorSkate[playerid][SkateObjeto] = CreateDynamicObject(19878, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), -1, 300.0, 300.0, -1);
            AttachDynamicObjectToPlayer(JogadorSkate[playerid][SkateObjeto], playerid, -0.2, 0, -0.9, 0, 0, 90);
        }
	}
	if(oldkeys & KEY_HANDBRAKE)
    {
		ApplyAnimation(playerid, "CARRY","crry_prtial",4.0,0,0,0,0,0);
        if(JogadorSkate[playerid][Atividade] == true)
        {
            JogadorSkate[playerid][Atividade] = false;
		    DestroyDynamicObjectEx(JogadorSkate[playerid][SkateObjeto]); 
		    SetPlayerAttachedObject(playerid, 6, 19878, 6, -0.055999, 0.013000, 0.000000, -84.099983, 0.000000, -106.099998, 1.000000, 1.000000, 1.000000);
        }
    }
	return true;
}