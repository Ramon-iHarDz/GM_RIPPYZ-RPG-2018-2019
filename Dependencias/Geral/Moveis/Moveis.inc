#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CarregarMoveis();
    return 1;
}

function CarregarMoveis()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `moveis`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Moveis] Não foi possivel conectar com o banco de dados das casas!\n");
        SendRconCommand("exit");
    }
    new Rows = cache_num_rows();
    if(Rows < 1) return print("[Rippzy:Moveis] Não foi encontrado nenhum movel na database.");
    printf("[Rippzy:Moveis] Sistema de moveis estão sendo carregado ( %d Moveis )", Rows);
    
    new id,
        idx;

    for(new i=0; i < Rows; i++)
    {
        cache_get_value_name_int(i, "Casa", id); // ID da Casa
        cache_get_value_name_int(i, "MaxID", idx); // ID do Objeto

        // Stings
        cache_get_value(i, "ObjetoNome", cMovel[id][idx][cMovelNome], 30);

        // Integers
        cache_get_value_name_int(i, "Ativado", cMovel[id][idx][cAtivado]);
        cache_get_value_name_int(i, "Objeto", cMovel[id][idx][cMovelObjeto]);
        cache_get_value_name_int(i, "Preco", cMovel[id][idx][cmPreco]);
        cache_get_value_name_int(i, "Coins", cMovel[id][idx][cmPrecoCoins]);
        cache_get_value_name_int(i, "Status", cMovel[id][idx][cStatus]);

        // Posições
        cache_get_value_name_float(i, "PosX", cMovel[id][idx][MovelX]);
        cache_get_value_name_float(i, "PosY", cMovel[id][idx][MovelY]);
        cache_get_value_name_float(i, "PosZ", cMovel[id][idx][MovelZ]);

        cache_get_value_name_float(i, "PosRx", cMovel[id][idx][MovelRx]);
        cache_get_value_name_float(i, "PosRy", cMovel[id][idx][MovelRy]);
        cache_get_value_name_float(i, "PosRz", cMovel[id][idx][MovelRz]);

        if(cMovel[id][idx][cStatus] == 1) eMoveis[id][MoveisQuantidade]++;
        if(cMovel[id][idx][cAtivado] == true){
            cMovel[id][idx][cMovelID] = CreateDynamicObject(cMovel[id][idx][cMovelObjeto], cMovel[id][idx][MovelX], cMovel[id][idx][MovelY], cMovel[id][idx][MovelZ], cMovel[id][idx][MovelRx], cMovel[id][idx][MovelRy], cMovel[id][idx][MovelRz], PegarVirtualCasa(id), PegarInteriorCasa(id) , -1, 120.0, 120.0, -1);
        }
    }
    cache_delete(Conectar);
    print("[Rippzy:Moveis] Sistema de moveis foram carregados com sucesso");
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "ColocandoMovel") == 0) return 1;
    new id = GetPVarInt(playerid, "MovelID");
    DestroyDynamicObjectEx(id);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_SECONDARY_ATTACK) return 1; 

    // Entrada
    if(IsPlayerInRangeOfPoint(playerid, 2.0, -1754.1930,962.8623,24.8828) && GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0 && Jogador[playerid][uInteriorEx] == 0 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        TogglePlayerControllable(playerid, 0);
        Jogador[playerid][uInteriorEx] = 2012;
        GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
        SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);
        SetPlayerPos(playerid, 2020.1019,1296.3578,270.8355);
        SetPlayerInterior(playerid, 7);
        SetPlayerVirtualWorld(playerid, 2012);
        SetTimerEx("Destravar", 3000, false, "d", playerid);
        // Talvez um temporizador
    }

    // Saída
    else if(IsPlayerInRangeOfPoint(playerid, 2.0, 2020.1019,1296.3578,270.8355) && GetPlayerInterior(playerid) == 7 && GetPlayerVirtualWorld(playerid) == 2012 && Jogador[playerid][uInteriorEx] == 2012 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        Jogador[playerid][uInteriorEx] = 0;
        SetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
    }

    return 1;
}

hook OnPlayerEditDynObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(GetPVarInt(playerid, "ColocandoMovel") == 0) return 1;
    new id = GetPVarInt(playerid, "CasaMovel"),
        idx = GetPVarInt(playerid, "MovelSlot");

    switch(response)
    {
        case EDIT_RESPONSE_FINAL:
        {
            SetPVarInt(playerid, "ColocandoMovel", 0);
            SetDynamicObjectPos(cMovel[id][idx][cMovelID], x, y, z);
            SetDynamicObjectRot(cMovel[id][idx][cMovelID], rx, ry, rz);

            SelecionarMovel(playerid, id, idx);

            new Enviar[230];
            format(Enviar, sizeof(Enviar), "UPDATE `moveis` SET `Ativado` = 1, `PosX` = %f, `PosY` = %f, `PosZ` = %f, `PosRx` = %f, `PosRy` = %f, `PosRz` = %f WHERE `Casa` = %d AND `MaxID` = %d", x, y, z, rx, ry, rz, id, idx);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0){
                SendClientMessage(playerid, 0xFF4500FF, "| MÓVEL | Houve um problema ao salvar esse móvel");  
                DestroyDynamicObjectEx(cMovel[id][idx][cMovelID]);
                cMovel[id][idx][cAtivado] = false;
                return 1;
            }

            cMovel[id][idx][MovelX] = x;
            cMovel[id][idx][MovelY] = y;
            cMovel[id][idx][MovelZ] = z;
            cMovel[id][idx][MovelRx] = rx;
            cMovel[id][idx][MovelRy] = ry;
            cMovel[id][idx][MovelRz] = rz;
            cMovel[id][idx][cAtivado] = true;
            SendClientMessage(playerid, 0xFFA500FF, "| MÓVEL | Você salvou a posição do seu móvel");  
        }
        case EDIT_RESPONSE_CANCEL:
        {
            SelecionarMovel(playerid, id, idx);
            SetPVarInt(playerid, "ColocandoMovel", 0);
            SetDynamicObjectPos(cMovel[id][idx][cMovelID], cMovel[id][idx][MovelX], cMovel[id][idx][MovelY], cMovel[id][idx][MovelZ]);
            SetDynamicObjectRot(cMovel[id][idx][cMovelID], cMovel[id][idx][MovelRx], cMovel[id][idx][MovelRy], cMovel[id][idx][MovelRz]); 
            SendClientMessage(playerid, 0xFFA500FF, "| MÓVEL | Você cancelou a posição do móvel"); 
        }
    }

    return 1;
}

CMD:moveis(playerid)
{
    if(GetPVarInt(playerid, "ColocandoMovel") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está editando um móvel, aperta ESC para cancelar.");
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(id == 0 || Jogador[playerid][uInteriorEx] != 1 || GetPlayerVirtualWorld(playerid) < 1) return 1;
    if(!MoraNessaCasa(playerid, id) && Jogador[playerid][Admin] != 7) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");

    SetPVarInt(playerid, "AtlAAAAAA", 0);
    SetPVarInt(playerid, "AtlBBBBBB", 0);
    SetPVarInt(playerid, "CasaMovel", id);

    LoadDialogMoveis(playerid, id);
    return 1;
}

CMD:amoveis(playerid)
{
    if(Jogador[playerid][Admin] < 1) return 0;
    if(GetPVarInt(playerid, "ColocandoMovel") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está editando um móvel, aperta ESC para cancelar.");
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(id == 0 || Jogador[playerid][uInteriorEx] != 1 || GetPlayerVirtualWorld(playerid) < 1) return 1;
    SetPVarInt(playerid, "CasaMovel", id);
    Dialog_Show(playerid, MoveisMenuAdmin, DIALOG_STYLE_INPUT, "{ff0000}Móveis Admin", "Coloque o ID do objeto abaixo", "Confirmar", "Fechar");
    return 1; 
}