#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        // Spawnar um veículo de mecânico
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 313.2029,-18.0681,1.5781))
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Mecânico")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(GetPVarInt(playerid, "ASDASDASDASDA") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            if(pMecanico[playerid][AtendendoMec] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está com um serviço");
            if(pMecanico[playerid][MecanicoAlugado] == false)
            {
                if(Jogador[playerid][CarteiraC] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar um carro ( Habilitação: C )");
                new sidd = random(sizeof(mSpawn));
                pMecanico[playerid][MecanicoID] = CreateVehicleEx(playerid, 525, mSpawn[sidd][cMX], mSpawn[sidd][cMY], mSpawn[sidd][cMZ], mSpawn[sidd][cMA], 4, 4, -1, 0);
                VeiculoServer[pMecanico[playerid][MecanicoID]][Tranca] = 1;
                MarcarPosicao(playerid, mSpawn[sidd][cMX], mSpawn[sidd][cMY], mSpawn[sidd][cMZ]);
                pMecanico[playerid][MecanicoAlugado] = true;
                Jogador[playerid][Trabalhando] = true;
                SetPVarInt(playerid, "ASDASDASDASDA", gettime()+10);
                SendClientMessage(playerid, 0xFFFF00FF, "| MECÂNICA | Seu veículo foi colocado atrás da mecânica");
                return 1;
            }

            if(IsTrailerAttachedToVehicle(pMecanico[playerid][MecanicoID])){
   				DetachTrailerFromVehicle(pMecanico[playerid][MecanicoID]);
   			}

            VerificarMarcacao(playerid);
            SetPVarInt(playerid, "ASDASDASDASDA", gettime()+10);
            pMecanico[playerid][MecanicoAlugado] = false;
            Jogador[playerid][Trabalhando] = false;
            DestroyVehicleEx(pMecanico[playerid][MecanicoID]);
            SendClientMessage(playerid, 0xFFFF00FF, "| MECÂNICA | Você devolveu o veículo para mecânica");
        }
    }


    // Sistema de Rebocar
    if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
        if(GetPlayerVirtualWorld(playerid) != 0) return 1;
        if(strcmp(Jogador[playerid][Profissao], "Mecânico")) return 1;
	    if(pMecanico[playerid][MecanicoAlugado] == false) return 1;
        if(GetPlayerVehicleID(playerid) != pMecanico[playerid][MecanicoID]) return 1;

        if(IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid))){
   			DetachTrailerFromVehicle(GetPlayerVehicleID(playerid));
            return 1;
   		}

	    // SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Tentando rebocar o veículo");

		new Float:pX, Float:pY, Float:pZ,
            Float:vX, Float:vY, Float:vZ;
		GetPlayerPos(playerid, pX, pY, pZ);
        for(new i=0; i < MAX_VEHICLES; i++)
        {
            if(GetPlayerVehicleID(playerid) == i) continue;
            GetVehiclePos(i, vX, vY, vZ);
            if(floatabs(pX-vX) < 5.0 && floatabs(pY-vY) < 5.0 && floatabs(pZ-vZ) < 5.0)
   			{
                if(IsVehicleOccupied(i)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse veículo tem um(a) motorista");
   				if(!IsApenasCarro(GetVehicleModel(i))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode rebocar");
                AttachTrailerToVehicle(i, GetPlayerVehicleID(playerid));
   				SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você rebocou um veículo");
                break;
            }
        }
	}

    return 1;
}