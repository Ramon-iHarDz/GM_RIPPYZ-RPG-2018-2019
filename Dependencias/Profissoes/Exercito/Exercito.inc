#include <YSI_Coding\y_hooks>

enum AreaRestri
{
    bool:NaArea,
    TempoArea,
    Float:VidaTma
};

new pExercito[MAX_PLAYERS][AreaRestri];
new AreaEx;
new AeronauEx;

hook OnGameModeInit()
{
    for(new i=0; i < sizeof(ESpawn); i++){
        ExeVeh[i] = CreateVehicleEx(-1, ESpawn[i][EModelo], ESpawn[i][ESpawnX], ESpawn[i][ESpawnY], ESpawn[i][ESpawnZ], ESpawn[i][ESpawnA], 1, 1, 160, 0);
        //VeiculoServer[ExeVeh[i]][Tranca] = 1;
        VeiculoServer[ExeVeh[i]][AntiFurar] = true;
        VeiculoServer[ExeVeh[i]][VidaMaxima] = 15000.0;
        VeiculoServer[ExeVeh[i]][AntiRadar] = true;
        VeiculoServer[ExeVeh[i]][VeiculoRegenerar] = true;
        SetVehicleHealth(ExeVeh[i], VeiculoServer[ExeVeh[i]][VidaMaxima]);
        format(VeiculoServer[ExeVeh[i]][LocalVerificacao], 90, "ExercitoVeh");
    }

    CreateDynamicPickup(1239, 1, 290.5349,1940.5509,17.6406, 0, 0, -1, 90.0);
    CreateDynamic3DTextLabel("{00BFFF}Exército{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para se equipar", -1, 290.5349,1940.5509,17.6406, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1);
    AreaEx = CreateDynamicRectangle(-61.05194091796875, 1689.5346145629883, 455.94805908203125, 2142.0068893432617, 0, 0, -1);
    AeronauEx = CreateDynamicRectangle( -1516.03466796875, 408.10400390625, -1166.03466796875, 557.10400390625, 0, 0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pExercito[playerid][NaArea] == true) KillTimer(pExercito[playerid][TempoArea]);
    new Crazzp[AreaRestri];
    pExercito[playerid] = Crazzp;
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid == AreaEx || areaid == AeronauEx){
        if(pExercito[playerid][NaArea] == true) return 1;
        if(strcmp(Jogador[playerid][Profissao], "Exército") && strcmp(Jogador[playerid][Profissao], "Marinha") && strcmp(Jogador[playerid][Profissao], "Aeronáutica") && Jogador[playerid][Admin] < 1){
            GetPlayerHealth(playerid, pExercito[playerid][VidaTma]);
            pExercito[playerid][NaArea] = true;
            pExercito[playerid][TempoArea] = SetTimerEx("AreaRestritaW", 7000, true, "d", playerid);
            MostrarMensagemBaixo(playerid, ConverterTexto("~w~Área ~r~Restrita, saia de perto"));
            PlayerPlaySound(playerid, 1056, 0.0, 0.0, 0.0);
        }
        else MostrarMensagemBaixo(playerid, ConverterTexto("~w~Área ~g~Militar"));
    }
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{   
    if(areaid == AreaEx || areaid == AeronauEx){
        if(pExercito[playerid][NaArea] == true){
            KillTimer(pExercito[playerid][TempoArea]);
            pExercito[playerid][NaArea] = false;
        }
        OcultarMensagemBaixo(playerid);
    }
    return 1;
}

function AreaRestritaW(playerid)
{
    PlayerPlaySound(playerid, 1056, 0.0, 0.0, 0.0);
    pExercito[playerid][VidaTma] -= 25.0;
    if(pExercito[playerid][VidaTma] <= 0){
        EnviarHospital(playerid);
        SendClientMessage(playerid, 0xFFFF00FF, "| ABATE | Você foi abatido(a) pelos militares");
        return 1;
    }
    SetPlayerHealth(playerid, pExercito[playerid][VidaTma]);
    return 1;
}

function ExercitoVeh(playerid, vehicleid)
{
    if(Jogador[playerid][Admin] > 1) return true;
    if(strcmp(Jogador[playerid][Profissao], "Exército")){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é do exército");
        return false;
    }
    if(pSoldado[playerid][ExecFarda] == false){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está fardado(a)");
        return false;
    }
    if(Jogador[playerid][Estrelas] > 0){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
        return false;
    }
    return true;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 290.5349,1940.5509,17.6406)) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(strcmp(Jogador[playerid][Profissao], "Exército")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(GetPVarInt(playerid, "LLsk") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
    SetPVarInt(playerid, "LLsk", gettime()+15);

    if(pSoldado[playerid][ExecFarda] == false)
    {
        if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas");
        if(Jogador[playerid][Sexo] == 1){
            Jogador[playerid][SkinProfissao] = 287;
            SetPlayerSkin(playerid, 287);
        }
        else if(Jogador[playerid][Sexo] == 2){
            Jogador[playerid][SkinProfissao] = 191;
            SetPlayerSkin(playerid, 191);
        }

        GivePlayerWeapon(playerid, 31, 1000);
        GivePlayerWeapon(playerid, 3, 1);  
        pPolicia[playerid][PegouUniformePolicia] = true;
        pSoldado[playerid][ExecFarda] = true;
        Jogador[playerid][Trabalhando] = true;
        SendClientMessage(playerid, 0xFFFF00FF, "| EXÉRCITO | Você pegou sua farda");
        return 1;
    }

    RemoverArma(playerid, 31);
    RemoverArma(playerid, 3);
    
    Jogador[playerid][SkinProfissao] = -1;
    SetPlayerSkin(playerid, Jogador[playerid][Skin]);
    pSoldado[playerid][ExecFarda] = false;
    pPolicia[playerid][PegouUniformePolicia] = false;
    Jogador[playerid][Trabalhando] = false;
    SendClientMessage(playerid, 0xFFFF00FF, "| EXÉRCITO | Você devolveu sua farda");
    return 1;
}

stock UltimoVeiculoExercito(playerid)
{
    for(new i=0; i < sizeof(ESpawn); i++){
        if(ExeVeh[i] != Jogador[playerid][uVeiculo]) continue;
        return true;
    }
    return false;
}