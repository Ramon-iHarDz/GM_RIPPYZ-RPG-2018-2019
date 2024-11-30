#include <YSI_Coding\y_hooks>

enum AeronauticaPlayer
{
    bool:AeroRoupa
};

new pAero[MAX_PLAYERS][AeronauticaPlayer];

hook OnGameModeInit()
{
    CreateDynamicPickup(1239, 1, -1346.3986,498.0270,18.2344, 0, 0, -1, 90.0, -1);
    CreateDynamic3DTextLabel("Aeronáutica{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para pegar a farda", 0xFFFF00FF, -1346.3986,498.0270,18.2344, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 17.0, -1);

    for(new i=0; i < sizeof(AeroExec); i++)
    {
        AeroID[i] = CreateVehicleEx(-1, AeroExec[i][AeroModelo], AeroExec[i][AeroX], AeroExec[i][AeroY], AeroExec[i][AeroZ], AeroExec[i][AeroA], 1, 1, 160, 0);
        VeiculoServer[AeroID[i]][Tranca] = 1;
        VeiculoServer[AeroID[i]][AntiFurar] = true;
        VeiculoServer[AeroID[i]][VidaMaxima] = 35000.0;
        VeiculoServer[AeroID[i]][AntiRadar] = true;
        VeiculoServer[AeroID[i]][VeiculoRegenerar] = true;
        SetVehicleHealth(AeroID[i], VeiculoServer[AeroID[i]][VidaMaxima]);
        format(VeiculoServer[AeroID[i]][LocalVerificacao], 90, "AeronauticaVeh");
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    pAero[playerid][AeroRoupa] = false;
    return 1;
}

function AeronauticaVeh(playerid, vehicleid)
{
    if(Jogador[playerid][Admin] > 1) return true;
    if(strcmp(Jogador[playerid][Profissao], "Aeronáutica")){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é da aeronáutica");
        return false;
    }
    if(pAero[playerid][AeroRoupa] == false){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está fardado(a)");
        return false;
    }
    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){
        if(Jogador[playerid][Estrelas] > 0){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            return false;
        }
    }
    return true; 
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, -1346.3986,498.0270,18.2344)) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
    if(strcmp(Jogador[playerid][Profissao], "Aeronáutica")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas");
    if(GetPVarInt(playerid, "Ajdkas") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
    SetPVarInt(playerid, "Ajdkas", gettime()+10);
    if(pAero[playerid][AeroRoupa] == false)
    {
        RemoverAcessorios(playerid);
        pAero[playerid][AeroRoupa] = true;
        Jogador[playerid][Trabalhando] = true;
        pPolicia[playerid][PegouUniformePolicia] = true;

        Jogador[playerid][SkinProfissao] = 287;
        SetPlayerSkin(playerid, 287);

        GivePlayerWeapon(playerid, 31, 2000);
        GivePlayerWeapon(playerid, 29, 3000);
        GivePlayerWeapon(playerid, 24, 900);
        GivePlayerWeapon(playerid, 3, 1);

        SetPlayerAttachedObject(playerid, 0, 19141, 2, 0.0859, 0.0419, 0.0049, 0.0000, 0.0000, 10.1999, 1.0759, 1.1880, 1.1040, 0xFFFFFFFF, 0xFFFFFFFF); // SWATHelmet1
        SetPlayerAttachedObject(playerid, 1, 19472, 2, -0.0079, 0.1310, 0.0069, 0.0000, 82.7001, 96.0999, 1.0000, 1.2759, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); // gasmask01
        SendClientMessage(playerid, 0xFFFF00FF, "| AERONÁUTICA | Você pegou equipou com a farda da aeronáutica");
        return 1;
    }
    RemovePlayerAttachedObject(playerid, 0);
    RemovePlayerAttachedObject(playerid, 1);

    RemoverArma(playerid, 31);
    RemoverArma(playerid, 3);
    RemoverArma(playerid, 29);
    RemoverArma(playerid, 24);

    Jogador[playerid][SkinProfissao] = -1;
    SetPlayerSkin(playerid, Jogador[playerid][Skin]);

    VerificarAcessorios(playerid);
    pAero[playerid][AeroRoupa] = false;
    Jogador[playerid][Trabalhando] = false;
    pPolicia[playerid][PegouUniformePolicia] = false;
    SendClientMessage(playerid, 0xFFFF00FF, "| AERONÁUTICA | Você removeu os equipamentos da aeronáutica");
    return 1;
}

stock UltimoVeiculoAeronautica(playerid)
{
    for(new i=0; i < sizeof(AeroExec); i++){
        if(AeroID[i] != Jogador[playerid][uVeiculo]) continue;
        return true;
    }
    return false;
}