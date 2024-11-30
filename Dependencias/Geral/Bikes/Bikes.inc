#include <YSI_Coding\y_hooks>
#define     MAX_BIKES   (100)

enum BikeJogador
{
    bool:BikeAlugada,
    BikeTimer,
    BikeID,
    BikeTempo,
    Text3D:PlayerBikeTexto
};

enum BikesInfo
{
    bool:BikeColocada,
    Float:BikeX,
    Float:BikeY,
    Float:BikeZ,
    Float:BikeA,
    Text3D:BikeTexto,
    BikeIcon
};

new Bike[MAX_BIKES][BikesInfo];
new JogadorBike[MAX_PLAYERS][BikeJogador];

hook OnGameModeInit()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `bikes`", true);
    if(mysql_errno(IDConexao) != 0)
    {
        print("Não foi possivel conectar com o banco de dadoas das bikes");
        SendRconCommand("exit");
        return 1;
    }

    new cach = cache_num_rows(),
        idd;
    
    if(cach > 0)
    {
        for(new i=0; i < cach; i++)
        {
            cache_get_value_name_int(i, "Numero", idd);
            cache_get_value_name_float(i, "X", Bike[idd][BikeX]);
            cache_get_value_name_float(i, "Y", Bike[idd][BikeY]);
            cache_get_value_name_float(i, "Z", Bike[idd][BikeZ]);
            cache_get_value_name_float(i, "A", Bike[idd][BikeA]);
            // CarregarPontoBike(idd);
        }
    }
    cache_delete(Conectar);
    return true;
}

CarregarPontoBike(id)
{
    new Mensagem[95];
    format(Mensagem, sizeof(Mensagem), "Ponto de Bicicleta ( {FFA500}ID: %d{FFFFFF} )\nAperte {CCCCCC}'Y'{FFFFFF} para alugar", id);
    Bike[id][BikeTexto] = CreateDynamic3DTextLabel(Mensagem, -1, Bike[id][BikeX], Bike[id][BikeY], Bike[id][BikeZ], 12.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 13.0, -1);
    Bike[id][BikeIcon] = CreateDynamicPickup(1239, 1, Bike[id][BikeX], Bike[id][BikeY], Bike[id][BikeZ], 0, 0, -1, 90.0, -1);
    Bike[id][BikeColocada] = true;
    return true;
}

stock GetBikeID()
{
    for(new i=0; i < MAX_BIKES; i++)
    {
        if(Bike[i][BikeColocada] == true) continue;
        return i;
    }
    return -1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(JogadorBike[playerid][BikeAlugada] == true) KillTimer(JogadorBike[playerid][BikeTimer]);
    DestroyDynamic3DTextLabelEx(JogadorBike[playerid][PlayerBikeTexto]);
    DestroyVehicleEx(JogadorBike[playerid][BikeID]);

    new LoveRC[BikeJogador];
    JogadorBike[playerid] = LoveRC;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return true;
    for(new i=0; i < MAX_BIKES; i++)
    {
        if(Bike[i][BikeColocada] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, Bike[i][BikeX], Bike[i][BikeY], Bike[i][BikeZ])) continue;
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
        if(JogadorBike[playerid][BikeAlugada] == true)
        {
            Dialog_Show(playerid, DevolverBike, DIALOG_STYLE_MSGBOX, "{FF0000}Bicicleta", "Você realmente deseja devolver sua bicicleta alugada?", "Confirmar", "Fechar");
            return true;
        }
        if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
        if(Jogador[playerid][Level] > 5){
            if(Jogador[playerid][Dinheiro] < 1500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
        }
        SetPVarInt(playerid, "XDBIKEFDC", i);
        Dialog_Show(playerid, AlugarBike, DIALOG_STYLE_MSGBOX, "{FF0000}Bicicleta", "Você deseja alugar uma bicicleta por 05:00 minutos", "Confirmar", "Fechar");
        break;
    }
    return true;
}

Dialog:DevolverBike(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(JogadorBike[playerid][BikeAlugada] == false) return 1;
    KillTimer(JogadorBike[playerid][BikeTimer]);
    DestroyDynamic3DTextLabelEx(JogadorBike[playerid][PlayerBikeTexto]);
    DestroyVehicleEx(JogadorBike[playerid][BikeID]);
    JogadorBike[playerid][BikeAlugada] = false;
    SendClientMessage(playerid, 0xFFFF00FF, "| BICICLETA | Você devolveu a bicicleta");
    return 1;
}

Dialog:AlugarBike(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(Jogador[playerid][Level] > 5){
        Jogador[playerid][Dinheiro] -= 1500;
    }

    new Mensagem[128],
        i = GetPVarInt(playerid, "XDBIKEFDC");
    JogadorBike[playerid][BikeAlugada] = true;
    JogadorBike[playerid][BikeTempo] = 300;
    format(Mensagem, sizeof(Mensagem), "Bicicleta do(a) jogador(a) {00BFFF}%s[%d]{FFFFFF}\nTempo: {FFA500}%s", PegarNick(playerid), playerid, SegundosParaMinutosEx(JogadorBike[playerid][BikeTempo]));
    JogadorBike[playerid][BikeID] = CreateVehicleEx(playerid, 510, Bike[i][BikeX], Bike[i][BikeY], Bike[i][BikeZ], Bike[i][BikeA], random(999), random(999), 360, 0);
    JogadorBike[playerid][PlayerBikeTexto] = CreateDynamic3DTextLabel(Mensagem, -1, 0.0, 0.0, 0.0, 10.0, INVALID_PLAYER_ID, JogadorBike[playerid][BikeID], 0, 0, 0, -1, 11.0, -1);
    JogadorBike[playerid][BikeTimer] = SetTimerEx("AtualizarBike", 1000, true, "d", playerid);

    PutPlayerInVehicle(playerid, JogadorBike[playerid][BikeID], 0);

    if(Jogador[playerid][Level] > 5) SendClientMessage(playerid, -1, "| BICICLETA | Você alugou uma bike por {32CD32}$1.500");
    else SendClientMessage(playerid, -1, "| BICICLETA | Você tem bicicleta grátis até o {00BFFF}level 5");
    return 1;
}

function AtualizarBike(playerid)
{
    new Mensagem[128];
    JogadorBike[playerid][BikeTempo]--;
    format(Mensagem, sizeof(Mensagem), "Bicicleta do(a) jogador(a) {00BFFF}%s[%d]{FFFFFF}\nTempo: {FFA500}%s", PegarNick(playerid), playerid, SegundosParaMinutosEx(JogadorBike[playerid][BikeTempo]));
    UpdateDynamic3DTextLabelText(JogadorBike[playerid][PlayerBikeTexto], -1, Mensagem);

    if(JogadorBike[playerid][BikeTempo] <= 0)
    {
        SendClientMessage(playerid, 0xFFFF00FF, "| BICICLETA | Seu tempo acabou e sua bicicleta foi devolvida");
        if(JogadorBike[playerid][BikeAlugada] == true) KillTimer(JogadorBike[playerid][BikeTimer]);
        DestroyDynamic3DTextLabelEx(JogadorBike[playerid][PlayerBikeTexto]);
        DestroyVehicleEx(JogadorBike[playerid][BikeID]);
        JogadorBike[playerid][BikeAlugada] = false;
        return true;
    }
    return true;
}

CMD:criarbike(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    
    new id = GetBikeID();
    if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Limite de bikes já foi atingido");

    new Float:nma[4],
        Enviar[128];
    GetPlayerPos(playerid, nma[0], nma[1], nma[2]);
    GetPlayerFacingAngle(playerid, nma[3]);

    format(Enviar, sizeof(Enviar), "INSERT INTO `bikes` (`Numero`, `X`, `Y`, `Z`, `A`) VALUES (%d, %f, %f, %f, %f)", id, nma[0], nma[1], nma[2], nma[3]);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao adicionar esse ponto");

    Bike[id][BikeX] = nma[0];
    Bike[id][BikeY] = nma[1];
    Bike[id][BikeZ] = nma[2];
    Bike[id][BikeA] = nma[3];

    CarregarPontoBike(id);
    format(Enviar, sizeof(Enviar), "| ADMIN | Você criou um ponto de bicicleta ID: %d", id);
    SendClientMessage(playerid, 0x00BFFFFF, Enviar);
    return 1;
}

CMD:removerbike(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /RemoverBike [ID]");
    if(Bike[id][BikeColocada] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse ponto não existe");

    new Enviar[70];
    format(Enviar, sizeof(Enviar), "DELETE FROM `bikes` WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao remover esse ponto");

    Bike[id][BikeColocada] = false;
    DestroyDynamic3DTextLabelEx(Bike[id][BikeTexto]);
    DestroyDynamicPickupEx(Bike[id][BikeIcon]);
    return 1;
}