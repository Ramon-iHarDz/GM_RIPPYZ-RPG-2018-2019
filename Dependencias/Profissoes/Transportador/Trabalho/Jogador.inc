#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, 2208.8042,-2278.7266,13.5547)) return 1;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(strcmp(Jogador[playerid][Profissao], "Transportador")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
        if(VerificarEntrega(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não concluiu as entregas!");
        if(GetPVarInt(playerid, "AntiFLoodTransportea") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco!");
        if(pTransportador[playerid][ComDupla] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Encerre seu serviço com sua dupla ( /dupla )");
        if(pTransportador[playerid][PegouVeiculo] == false)
        {
            if(Jogador[playerid][CarteiraC] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar um caminhão ( Habilitação: C )");
            new id = random(sizeof(TransporteSpawn));
            pTransportador[playerid][VeiculoTransID] = CreateVehicleEx(playerid, 414, TransporteSpawn[id][TrSpawnX], TransporteSpawn[id][TrSpawnY], TransporteSpawn[id][TrSpawnZ], TransporteSpawn[id][TrSpawnA], 500, 1, 120, 0);
            MarcarPosicao(playerid, TransporteSpawn[id][TrSpawnX], TransporteSpawn[id][TrSpawnY], TransporteSpawn[id][TrSpawnZ]);
            VeiculoServer[pTransportador[playerid][VeiculoTransID]][Tranca] = 1;
            pTransportador[playerid][PegouVeiculo] = true;
            Jogador[playerid][Trabalhando] = true;
            SetPVarInt(playerid, "AntiFLoodTransportea", gettime()+20);
            SendClientMessage(playerid, 0xFFFF00FF, "| TRANSPORTADORA | Seu veículo foi marcado no mapa");
            return 1;
        }
        Jogador[playerid][Trabalhando] = false;
        pTransportador[playerid][PegouVeiculo] = false;
        VerificarMarcacao(playerid);
        DestroyVehicleEx(pTransportador[playerid][VeiculoTransID]); 
        SetPVarInt(playerid, "AntiFLoodTransportea", gettime()+20);
        SendClientMessage(playerid, 0xFFFF00FF, "| TRANSPORTADORA | Você devolveu seu veículo");
    }
    return 1;
}