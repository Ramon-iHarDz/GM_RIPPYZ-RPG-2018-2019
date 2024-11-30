#include <YSI_Coding\y_hooks>

enum VeiculoBombeiroSpawn
{
    Float:BSpawnX,
    Float:BSpawnY,
    Float:BSpawnZ,
    Float:BSpawnA
};

new BSpawn[][VeiculoBombeiroSpawn] =
{
    {1770.0167,2077.8274,11.0551,180.9219},
    {1763.5898,2077.7654,11.0554,181.2667},
    {1757.0953,2077.8228,11.0543,180.6753},
    {1750.8538,2077.8140,11.0562,180.1702},
    {1741.8420,2067.2339,11.0559,257.2407},
    {1741.5856,2081.5273,11.0554,270.7470},
    {1730.7606,2081.3875,11.0570,270.7467}
};

enum BombeiroJogador
{
    bool:BombeiroRoupa,
    BombeiroStatus,
    BombeiroVeiculoID,
    BombeiroBar,

    BombeiroFogo,
    BombeiroIcone,
    BombeiroCasa,
    Text3D:BombeiroTexto
};

new pBombeiro[MAX_PLAYERS][BombeiroJogador];

hook OnGameModeInit()
{
    CreateDynamicPickup(1239, 1, 1760.4283,2080.2722,10.8203, 0, 0, -1, 90.0);
    CreateDynamic3DTextLabel("{00BFFF}Corpo de Bombeiros\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, 1760.4283,2080.2722,10.8203, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);
    
    CreateDynamicPickup(1239, 1, 1736.8679,2110.6042,12.2891, 0, 0, -1, 90.0);
    CreateDynamic3DTextLabel("{FFFF00}Corpo de Bombeiros", -1, 1736.8679,2110.6042,12.2891, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1);
    
    CreateDynamic3DTextLabel("{00BFFF}Equipamentos\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para se equipar", -1, 2435.9607,-1164.3899,1028.5453, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 7181, 5, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamic3DTextLabelEx(pBombeiro[playerid][BombeiroTexto]);
    DestroyDynamicMapIconEx(pBombeiro[playerid][BombeiroIcone]);
    DestroyDynamicObjectEx(pBombeiro[playerid][BombeiroFogo]);
    DestroyVehicleEx(pBombeiro[playerid][BombeiroVeiculoID]);

    new Delatar[BombeiroJogador];
    pBombeiro[playerid] = Delatar; 
    return 1;
}

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
            if(GetPlayerInterior(playerid) != 5 || GetPlayerVirtualWorld(playerid) != 7181) return 1;
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
            Jogador[playerid][uInteriorEx] = 0;
            SetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
        }
    }

    else if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1760.4283,2080.2722,10.8203)) //Veh
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Bombeiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(pBombeiro[playerid][BombeiroStatus] > 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");

            if(GetPVarInt(playerid, "DelayBombeiroVeh") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco");
            SetPVarInt(playerid, "DelayBombeiroVeh", gettime()+15);

            if(pBombeiro[playerid][BombeiroStatus] < 1)
            {
                if(pBombeiro[playerid][BombeiroRoupa] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está com a farda");
                new rdm = random(sizeof(BSpawn));
                pBombeiro[playerid][BombeiroVeiculoID] = CreateVehicleEx(playerid, 407, BSpawn[rdm][BSpawnX], BSpawn[rdm][BSpawnY], BSpawn[rdm][BSpawnZ], BSpawn[rdm][BSpawnA], 3, 3, 560, 1);
                VeiculoServer[pBombeiro[playerid][BombeiroVeiculoID]][AntiRadar] = true;
                VeiculoServer[pBombeiro[playerid][BombeiroVeiculoID]][Tranca] = 1;
                MarcarPosicao(playerid, BSpawn[rdm][BSpawnX], BSpawn[rdm][BSpawnY], BSpawn[rdm][BSpawnZ]);
                pBombeiro[playerid][BombeiroStatus] = 1;
                return 1;
            }
            VerificarMarcacao(playerid);
            DestroyVehicleEx(pBombeiro[playerid][BombeiroVeiculoID]);
            pBombeiro[playerid][BombeiroStatus] = 0;
        }

        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 2435.9607,-1164.3899,1028.5453)) // Farda
        {
            if(GetPlayerInterior(playerid) != 5 || GetPlayerVirtualWorld(playerid) != 7181) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Bombeiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
            if(pBombeiro[playerid][BombeiroStatus] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Devolva o veículo");
            if(pBombeiro[playerid][BombeiroStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");
            
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

            RemoverArma(playerid, 42);
            SetPlayerSkin(playerid, Jogador[playerid][Skin]);
            Jogador[playerid][SkinProfissao] = -1; 
            pBombeiro[playerid][BombeiroRoupa] = false;
            Jogador[playerid][Trabalhando] = false;
        }
    }
    else if(HOLDING(KEY_FIRE))
    {
        if(pBombeiro[playerid][BombeiroStatus] != 2) return 1;
        if(GetPlayerWeapon(playerid) != 42) return 1; 
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
        if(pBombeiro[playerid][BombeiroRoupa] == false) return 1;

        new id = pBombeiro[playerid][BombeiroCasa];
        if(!IsPlayerInRangeOfPoint(playerid, 4.0, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ])) return 1;
        if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
        if(!IsVehicleInRangeOfPoint(pBombeiro[playerid][BombeiroVeiculoID], 50.0, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo do bombeiro não está perto do local");

        new Msgg[50];
        format(Msgg, sizeof(Msgg), "Fogo\n{FFFFFF}Chamas em {daa520}%d", pBombeiro[playerid][BombeiroBar]);
        UpdateDynamic3DTextLabelText(pBombeiro[playerid][BombeiroTexto], 0xFFA500FF, Msgg);
        pBombeiro[playerid][BombeiroBar]--;
        if(pBombeiro[playerid][BombeiroBar] > 0) return 1;

        new Mensagem[128],
            Qaad = random(2500-2000)+2000;
        format(Mensagem, sizeof(Mensagem), "| BOMBEIRO | Você recebeu {32CD32}$%s{FFFFFF} pelo serviço prestado", DinheiroSeparar(Qaad));
        SendClientMessage(playerid, -1, Mensagem);

        Jogador[playerid][Dinheiro] += Qaad;
        DestroyDynamic3DTextLabelEx(pBombeiro[playerid][BombeiroTexto]);
        DestroyDynamicMapIconEx(pBombeiro[playerid][BombeiroIcone]);
        DestroyDynamicObjectEx(pBombeiro[playerid][BombeiroFogo]);
        pBombeiro[playerid][BombeiroStatus] = 1;
    }
    return 1;
}

CMD:fogo(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Bombeiro")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
    if(pBombeiro[playerid][BombeiroRoupa] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está com a farda");
    if(pBombeiro[playerid][BombeiroStatus] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está com um veículo de bombeiro");
    if(Jogador[playerid][uVeiculo] != pBombeiro[playerid][BombeiroVeiculoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo de bombeiro");
    if(pBombeiro[playerid][BombeiroStatus] > 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem um serviço para fazer");
    IniciarFogo(playerid); 
    return 1;
}

stock IniciarFogo(playerid)
{
    new id,
        i;
    while(id == 0)
    {
        i = random(MAX_CASAS);
        if(pCasa[i][Colocado] == false) continue;
        new Msgg[90];
        pBombeiro[playerid][BombeiroBar] = 100;
        format(Msgg, sizeof(Msgg), "Fogo\n{FFFFFF}Chamas em {daa520}%d\n{FFFF00}Observação: Apague o fogo com o extintor", pBombeiro[playerid][BombeiroBar]);
        pBombeiro[playerid][BombeiroFogo] = CreateDynamicObject(18692, pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ]-2, 0.0, 0.0, 0.0, 0, 0, -1, 80.0, 80.0, -1, 0);
        pBombeiro[playerid][BombeiroTexto] = CreateDynamic3DTextLabel(Msgg, 0xFFA500FF, pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ]+1.4, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 15.0, -1, 0);  
        pBombeiro[playerid][BombeiroIcone] = CreateDynamicMapIcon(pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ], 20, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
        pBombeiro[playerid][BombeiroStatus] = 2;
        pBombeiro[playerid][BombeiroCasa] = i;
        id = i;
    }
    return 1;
}