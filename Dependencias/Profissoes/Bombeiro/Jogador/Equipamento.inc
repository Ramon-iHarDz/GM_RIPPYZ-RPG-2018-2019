#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1736.8679,2110.6042,12.2891))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Bombeiro") && Jogador[playerid][Admin] < 1 && !IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            Jogador[playerid][uInteriorEx] = 7181;
            GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
            TogglePlayerControllable(playerid, 0);
            SetPlayerVirtualWorld(playerid, 7181);
            SetPlayerInterior(playerid, 5);
            SetPlayerPos(playerid, 2419.7173,-1174.6919,1028.5454);
            SetTimerEx("Destravar", 2000, false, "d", playerid);
        }

        else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2419.7173,-1174.6919,1028.5454))
        {
            if(GetPlayerInterior(playerid) != 5 && GetPlayerVirtualWorld(playerid) != 7181) return 1;
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
            Jogador[playerid][uInteriorEx] = 0;
            SetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
        }
    }

    else if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1760.4283,2080.2722,10.8203))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Bombeiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(ApagandoFogoBombeiro(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não concluiu seu serviço!");
            if(pBombeiro[playerid][ApagandoFogo] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");

            if(GetPVarInt(playerid, "DelayBombeiroVeh") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco");
            SetPVarInt(playerid, "DelayBombeiroVeh", gettime()+15);

            if(pBombeiro[playerid][BombeiroVeiculo] == false)
            {
                if(pBombeiro[playerid][BombeiroRoupa] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está com a farda");
                new rdm = random(sizeof(BSpawn));
                pBombeiro[playerid][BombeiroVeiculoID] = CreateVehicleEx(playerid, 407, BSpawn[rdm][BSpawnX], BSpawn[rdm][BSpawnY], BSpawn[rdm][BSpawnZ], BSpawn[rdm][BSpawnA], 3, 3, 560, 1);
                pBombeiro[playerid][BombeiroVeiculo] = true;
                VeiculoServer[pBombeiro[playerid][BombeiroVeiculoID]][AntiRadar] = true;
                VeiculoServer[pBombeiro[playerid][BombeiroVeiculoID]][Tranca] = 1;
                MarcarPosicao(playerid, BSpawn[rdm][BSpawnX], BSpawn[rdm][BSpawnY], BSpawn[rdm][BSpawnZ]);
                return 1;
            }
            VerificarMarcao(playerid);
            DestroyVehicleEx(pBombeiro[playerid][BombeiroVeiculoID]);
            pBombeiro[playerid][BombeiroVeiculo] = false;
        }

        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 2435.9607,-1164.3899,1028.5453))
        {
            if(GetPlayerInterior(playerid) != 5 && GetPlayerVirtualWorld(playerid) != 7181) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Bombeiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(ApagandoFogoBombeiro(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não concluiu seu serviço!");
            if(pBombeiro[playerid][ApagandoFogo] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");
            
            if(GetPVarInt(playerid, "DelayBombeiroRR") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco");
            SetPVarInt(playerid, "DelayBombeiroRR", gettime()+15);
            
            if(pBombeiro[playerid][BombeiroRoupa] == false)
            {
                new SkinS;
                switch(random(2))
                {
                    case 0: SkinS = 279;
                    case 1: SkinS = 278;
                    case 2: SkinS = 277;
                }
                GivePlayerWeapon(playerid, 42, 9999);
                SetPlayerSkin(playerid, SkinS);
                Jogador[playerid][SkinProfissao] = SkinS; 
                Jogador[playerid][Trabalhando] = true;
                pBombeiro[playerid][BombeiroRoupa] = true;
                return 1;
            }

            if(pBombeiro[playerid][BombeiroVeiculo] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Devolva seu veículo do bombeiro antes de devolver seu uniforme");
            RemoverArma(playerid, 42);
            SetPlayerSkin(playerid, Jogador[playerid][Skin]);
            Jogador[playerid][SkinProfissao] = -1; 
            pBombeiro[playerid][BombeiroRoupa] = false;
            Jogador[playerid][Trabalhando] = false;
        }
    }
    return 1;
}