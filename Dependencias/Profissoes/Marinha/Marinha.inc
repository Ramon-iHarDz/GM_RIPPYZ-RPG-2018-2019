#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    for(new i=0; i < sizeof(MariExec); i++)
    {
        MariID[i] = CreateVehicleEx(-1, MariExec[i][MariModelo], MariExec[i][MariX], MariExec[i][MariY], MariExec[i][MariZ], MariExec[i][MariA], 1, 1, 160, 0);
        VeiculoServer[MariID[i]][Tranca] = 1;
        VeiculoServer[MariID[i]][AntiFurar] = true;
        VeiculoServer[MariID[i]][VidaMaxima] = 20000.0;
        VeiculoServer[MariID[i]][AntiRadar] = true;
        VeiculoServer[MariID[i]][VeiculoRegenerar] = true;
        SetVehicleHealth(MariID[i], VeiculoServer[MariID[i]][VidaMaxima]);
        format(VeiculoServer[MariID[i]][LocalVerificacao], 90, "MarinhaVeh");
    }
    return 1;
}

function MarinhaVeh(playerid, vehicleid)
{
    if(Jogador[playerid][Admin] > 1) return true;
    for(new i=0; i < sizeof(MariExec); i++)
    {
        if(MariID[i] != vehicleid) continue;
        if(strcmp(Jogador[playerid][Profissao], "Marinha")){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é da marinha");
            return false;
        }
        if(pPolicia[playerid][PegouUniformePolicia] == false){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está fardado(a)");
            return false;
        }
        if(Jogador[playerid][Estrelas] > 0){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            return false;
        }
        break;
    }
    return true; 
}

stock UltimoVeiculoMarinha(playerid)
{
    for(new i=0; i < sizeof(MariExec); i++){
        if(MariID[i] != Jogador[playerid][uVeiculo]) continue;
        return true;
    }
    return false;
}