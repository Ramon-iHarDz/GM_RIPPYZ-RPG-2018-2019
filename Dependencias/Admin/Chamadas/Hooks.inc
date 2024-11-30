#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    if(pAdmin[playerid][AdminUp] == false){
        pAdmin[playerid][UpdateAdmin] = SetTimerEx("AdminUpdate", 1000, true, "d", playerid);
        pAdmin[playerid][AdminUp] = true;
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pAdmin[playerid][AdminUp] == true) KillTimer(pAdmin[playerid][UpdateAdmin]);
    new Limpar[AdminInfo];
    pAdmin[playerid] = Limpar; 
    return 1;
}

function RemoverEspiao(playerid)
{
    if(pAdmin[playerid][VerComandos] == true) pAdmin[playerid][VerComandos] = false;
    pAdmin[playerid][Espiando] = false;
    pAdmin[playerid][AntigoState] = 0;
    TogglePlayerSpectating(playerid, 0);
    SetPlayerPos(playerid, pAdmin[playerid][aPos][0], pAdmin[playerid][aPos][1], pAdmin[playerid][aPos][2]);
    SetPlayerFacingAngle(playerid, pAdmin[playerid][aPos][3]);
    SetPlayerInterior(playerid, pAdmin[playerid][InteriorADM]);
    SetPlayerVirtualWorld(playerid, pAdmin[playerid][VirtualWorldADM]);
    return 1;
}

function AdminUpdate(playerid) 
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "AdminUpdate", 1)) return 1;
    if(pAdmin[playerid][Espiando] == true)
    {
        if(!IsPlayerConnected(pAdmin[playerid][EspiandoID]))
        {
            SendClientMessage(playerid, 0xFFFF00FF, "| ADMIN | Jogador(a) que voc� estava telando saiu do servidor.");
            RemoverEspiao(playerid);
            return 1;
        }

        if(IsPlayerInAnyVehicle(pAdmin[playerid][EspiandoID]) && pAdmin[playerid][AntigoState] != GetPlayerState(pAdmin[playerid][EspiandoID])){
            PlayerSpectateVehicle(playerid, GetPlayerVehicleID(pAdmin[playerid][EspiandoID]), SPECTATE_MODE_NORMAL);
            pAdmin[playerid][AntigoState] = GetPlayerState(pAdmin[playerid][EspiandoID]);
        }
        else if(!IsPlayerInAnyVehicle(pAdmin[playerid][EspiandoID]) && pAdmin[playerid][AntigoState] != GetPlayerState(pAdmin[playerid][EspiandoID])){
            PlayerSpectatePlayer(playerid, pAdmin[playerid][EspiandoID], SPECTATE_MODE_NORMAL);
            pAdmin[playerid][AntigoState] = GetPlayerState(pAdmin[playerid][EspiandoID]);
        }

        if(!IsPlayerStreamedIn(pAdmin[playerid][EspiandoID], playerid))
        {
            SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(pAdmin[playerid][EspiandoID]));
            PlayerSpectatePlayer(playerid, pAdmin[playerid][EspiandoID], SPECTATE_MODE_NORMAL);
            SetPlayerInterior(playerid, GetPlayerInterior(pAdmin[playerid][EspiandoID]));
        }
    }
    return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    //Deletar Veiculo do admin ao sair dele
    if(pAdmin[playerid][CarroAdmin] > 0){
        if(vehicleid != pAdmin[playerid][CarroAdmin]) return 1;
        RemovePlayerFromVehicle(playerid);
        DestroyVehicleEx(pAdmin[playerid][CarroAdmin]);
        pAdmin[playerid][CarroAdmin] = 0;
    }
    return 1;
}

hook OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if(Jogador[playerid][Admin] < 1) return 0;
    MapAndreas_FindZ_For2DCoord(fX, fY, fZ);
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new bect = GetPlayerVehicleID(playerid);
        RemovePlayerFromVehicle(playerid);
        SetVehiclePos(bect, fX, fY, fZ+0.5);
        SetVehicleVirtualWorld(bect, GetPlayerVirtualWorld(playerid));
        LinkVehicleToInterior(bect, GetPlayerInterior(playerid));
        SetPlayerPos(playerid, fX, fY, fZ+0.5);
        PutPlayerInVehicle(playerid, bect, 0);
    }
    else
    {
        SetPlayerPos(playerid, fX, fY, fZ+0.5);
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        Jogador[playerid][uInterior] = 0;
        Jogador[playerid][uInteriorEx] = 0;
        SetPVarInt(playerid, "InteriorPersonalizadoID", 0);
    }
    return 0;
}

hook OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
    if(Jogador[playerid][Admin] < 2) return 1;
    if(!IsPlayerConnected(clickedplayerid)) return 1;
    new id = clickedplayerid, Tab[1500], faqnome[90];
    strcat(Tab, "Atitudes [{32CD32}+{FFFFFF}]\n");
    if(Jogador[id][Logado] == true)
    {
        if(Jogador[id][Admin] > 0 && Jogador[playerid][Admin] < 6) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Voc� n�o tem permiss�o para visualizar esse(a) jogador(a)");
        strcatEx(Tab, "Usu�rio: {DEB887}%s\n", PegarNick(id));
        strcatEx(Tab, "Level: {DEB887}%d\n", Jogador[id][Level]);
        strcatEx(Tab, "Skin: {DEB887}%d\n", Jogador[id][Skin]);
        strcatEx(Tab, "Profiss�o: {DEB887}%s\n", Jogador[id][Profissao]); 
        strcatEx(Tab, "Tempo UP: {DEB887}%s\n", SegundosParaMinutosEx(Jogador[id][TempoUp]));
        strcatEx(Tab, "Estrelas: {DEB887}%d\n", Jogador[id][Estrelas]);
        strcatEx(Tab, "Registro: {1E90FF}%s\n", ConverterSegundosEx(gettime()-Jogador[id][Registro]));
        strcatEx(Tab, "Dinheiro [M�o]: {32CD32}%s\n", DinheiroSeparar(Jogador[id][Dinheiro]));
        strcatEx(Tab, "Dinheiro [Banco]: {32CD32}%s\n", DinheiroSeparar(Jogador[id][DinheiroBanco]));
        strcatEx(Tab, "Coins: {DAA520}%s\n", DinheiroSeparar(Jogador[id][Coins]));
        strcatEx(Tab, "Avisos: {FFFF00}%d/3\n", Jogador[id][Avisos]);
        strcatEx(Tab, "Fps: {DEB887}%d\n", GetPlayerFPS(id));
        strcatEx(Tab, "Ping: {DEB887}%d\n", GetPlayerPing(id));
        if(Jogador[playerid][Admin] == 7) strcatEx(Tab, "Login: {32CD32}%d\n", (GetPVarInt(id, "LoginEtap2") - GetPVarInt(id, "LoginEtap1")));
        if(Jogador[id][Vip] > gettime()) strcatEx(Tab, "Vip: {00BFFF}%s\n", ConverterSegundos(Jogador[id][Vip]));   
        else strcat(Tab, "Vip: {FE2E2E}Sem VIP\n");
        strcatEx(Tab, "IP: {1E90FF}%s\n", PegarIP(id));
        strcatEx(Tab, "Serial: {1E90FF}%s\n", PegarHWID(id));
        strcatEx(Tab, "Sexo: %s\n", JogadorSexo(1, id));
        if(strcmp(Jogador[id][Discord], "*")) strcatEx(Tab, "Discord: {1E90FF}Vinculado(a) [%s]\n", Jogador[id][Discord]);
        else strcat(Tab, "Discord: {FE2E2E}N�o Vinculado(a)\n");
        strcatEx(Tab, "Email: {3CB371}%s\n", Jogador[id][Email]);
    }
    else
    {
        strcatEx(Tab, "IP: {1E90FF}%s\n", PegarIP(id));
        strcatEx(Tab, "Serial: {1E90FF}%s\n", PegarHWID(id));
    }
    
    format(faqnome, sizeof(faqnome), "{1E90FF}Usu�rio %s[%d]", PegarNick(id), id);
    SetPVarInt(playerid, "TabInfoID", id);
    Dialog_Show(playerid, AdminTabInfo, DIALOG_STYLE_LIST, faqnome, Tab, "Selecionar", "Fechar");
    return 1;
}

hook OnPlayerText(playerid, text[])
{
    if(Jogador[playerid][Logado] == false) return 0;
    new Query[290];
    format(Query, sizeof(Query), "INSERT INTO `logchat` (`Nome`, `Query`, `Tempo`) VALUES ('%s', '%s', %d)", EscapeString(PegarNick(playerid)), EscapeString(text), gettime());
    mysql_query(IDConexao, Query, false);
    return 1;
}

hook OnPlayerCommandReceived(playerid, cmdtext[])
{
    if(Jogador[playerid][Logado] == false) return 0;
    new Query[500];
    format(Query, sizeof(Query), "INSERT INTO `logcomandos` (`Nome`, `Query`, `Tempo`) VALUES ('%s', '%s', %d)", EscapeString(PegarNick(playerid)), EscapeString(cmdtext), gettime());
    mysql_query(IDConexao, Query, false);

    format(Query, sizeof(Query), "| ADMIN | %s[%d] digitou ( {00BFFF}%s{FFFFFF} )", PegarNick(playerid), playerid, cmdtext);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] < 2) continue;
        if(pAdmin[i][VerComandos] == false) continue;
        if(pAdmin[i][VerCID] != playerid) continue;
        SendClientMessage(i, -1, Query);
    }
    return 1;  
}

function RespawnTempo()
{
    if(EstadoRespawn == 0)
    {
        MostrarRVS();
        TextDrawSetString(RespawnAdmin[0], ConverterTexto("Respawn de ve�culos em 30 segundos"));
        SetTimer("OcultarRVSPos", 5000, false);
        SetTimer("RespawnTempo", 20000, false); 
        EstadoRespawn = 1;
        RespawnAtivo = true;
    }
    else if(EstadoRespawn == 1)
    {
        MostrarRVS();
        TextDrawSetString(RespawnAdmin[0], ConverterTexto("Respawn de ve�culos em 10 segundos"));
        SetTimer("OcultarRVSPos", 5000, false);
        SetTimer("RespawnTempo", 10000, false);
        TempoRespawnAdmin = 5;
        EstadoRespawn = 2;    
    }
    else if(EstadoRespawn == 2)
    {
        if(TempoRespawnAdmin == 5){
            MostrarRVS();
        }
        new MensagemRespawn[90];
        if(TempoRespawnAdmin == 1) format(MensagemRespawn, sizeof(MensagemRespawn), "Respawn de ve�culos em %d segundo", TempoRespawnAdmin);
        else format(MensagemRespawn, sizeof(MensagemRespawn), "Respawn de ve�culos em %d segundos", TempoRespawnAdmin);
        TextDrawSetString(RespawnAdmin[0], ConverterTexto(MensagemRespawn));
        if(TempoRespawnAdmin == 1){
            SetTimer("OcultarRVSPos", 1000, false);
            EstadoRespawn = 3;
        }
        SetTimer("RespawnTempo", 2000, false);
        TempoRespawnAdmin--;
    }
    else if(EstadoRespawn == 3)
    {
        new bool:veiculo[MAX_VEHICLES];
        for(new j=0; j < MAX_VEHICLES; j++)
        {
            if(VeiculoServer[j][VeiculoOn] == false) continue; 
            veiculo[j] = false;
            for(new i=0; i < MAX_PLAYERS; i++)
            {
                if(!IsPlayerInAnyVehicle(i) || !IsPlayerConnected(i)) continue;
                if(!IsPlayerInVehicle(i, j)) continue;
                veiculo[j] = true;
                break;
            }
            if(veiculo[j]) continue;
            if(IsTrailerAttachedToVehicle(j)) continue;
            SetVehicleToRespawn(j);
            if(VeiculoServer[j][VeiculoRegenerar] == true)
            {
                VeiculoServer[j][vQuebrado] = false;
                SetVehicleHealth(j, VeiculoServer[j][VidaMaxima]);
            }
            else if(VeiculoServer[j][vQuebrado] == true) SetVehicleHealth(j, 390);
            if(GetVehicleVirtualWorld(j) != VeiculoServer[j][vVirtual]) SetVehicleVirtualWorld(j, VeiculoServer[j][vVirtual]);
            LinkVehicleToInterior(j, VeiculoServer[j][vInterior]);
        }
        MostrarRVS();
        TextDrawSetString(RespawnAdmin[0], ConverterTexto("Ve�culos Respawnados"));
        SetTimer("OcultarRVS", 6000, false); 
    }
    return 1;
}

stock GetEmptyVehicleSeat(vehicleid)
{
    new bool:Seat[4] = false;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(!IsPlayerInVehicle(i, vehicleid)) continue;
        if(GetPlayerVehicleSeat(i) == 0) Seat[0] = true;
        else if(GetPlayerVehicleSeat(i) == 1) Seat[1] = true;
        else if(GetPlayerVehicleSeat(i) == 2) Seat[2] = true;
        else if(GetPlayerVehicleSeat(i) == 3) Seat[3] = true;
    }

    for(new i=0; i < sizeof(Seat); i++)
    {
        if(Seat[i] == false) return i;
    }
    return -1;
} 

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    // Sistema de Rebocar
    if(newkeys == KEY_LOOK_BEHIND && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
        if(GetPlayerVirtualWorld(playerid) != 0) return 1;
        if(Jogador[playerid][Admin] < 1) return 1;
        if(pAdmin[playerid][CarroAdmin] < 1) return 1;
        if(GetPlayerVehicleID(playerid) != pAdmin[playerid][CarroAdmin]) return 1;
        if(GetVehicleModel(pAdmin[playerid][CarroAdmin]) != 525) return 1;

        if(IsTrailerAttachedToVehicle(pAdmin[playerid][CarroAdmin])){
   			DetachTrailerFromVehicle(pAdmin[playerid][CarroAdmin]);
            return Y_HOOKS_BREAK_RETURN_1;
   		}

		new Float:pX, Float:pY, Float:pZ,
            Float:vX, Float:vY, Float:vZ;
		GetVehiclePos(pAdmin[playerid][CarroAdmin], pX, pY, pZ);
        for(new i=0; i < MAX_VEHICLES; i++)
        {
            if(pAdmin[playerid][CarroAdmin] == i) continue;
            GetVehiclePos(i, vX, vY, vZ);
            if(floatabs(pX-vX) < 6.0 && floatabs(pY-vY) < 6.0 && floatabs(pZ-vZ) < 6.0)
   			{
                if(IsVehicleOccupied(i)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse ve�culo tem um(a) motorista");
   				if(!IsApenasCarro(GetVehicleModel(i))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Voc� n�o pode rebocar");
                AttachTrailerToVehicle(i, pAdmin[playerid][CarroAdmin]);
   				SendClientMessage(playerid, 0xFFFF00FF, "| ADMIN | Voc� rebocou um ve�culo");
                return Y_HOOKS_BREAK_RETURN_1;
            }
        }
	}
    return 1;
}

stock GerarCoins(const Nikcc[], valor)
{
    new CodigoCoins[30],
        Enviar[268],
        inta;
    switch(random(2))
    {
        case 0: inta = 28;
        case 1: inta = 27;
        case 2: inta = 26;
        case 3: inta = 25;
    }
    format(CodigoCoins, 30, GetRandomString(inta));
    format(Enviar, sizeof(Enviar), "INSERT INTO `codigocoins` (`Criado`, `Data`, `Codigo`, `Coins`) VALUES ('%s', %d, '%s', %d)", EscapeString(Nikcc), gettime(), CodigoCoins, valor);
    mysql_query(IDConexao, Enviar, false);
    return (CodigoCoins);
}