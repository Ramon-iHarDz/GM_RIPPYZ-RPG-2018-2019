#define MAX_MOCHILA_ARMAS (10)

stock FiltrarMochila(const Type[])
{
    if(!strcmp(Type, "Arma")) return 0;
    return -1;
}

Dialog:MochilaS(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarInt(playerid, "MochilaID", listitem);

    new Dialog[16];
    strcat(Dialog, "Retirar\n");
    strcat(Dialog, "Guardar");
    Dialog_Show(playerid, MochilaEx, DIALOG_STYLE_TABLIST, "{FF0000}Mochila", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:RetirarArmaMochila(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[128],
        Cache:Conectar;
    format(Enviar, sizeof(Enviar), "SELECT * FROM `mochila` WHERE `Nome` = '%s' AND `Tipo` = 'Arma'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema verificar arma selecionada");

    new ArmaID,
        BalasQnt,
        id;
    cache_get_value_name_int(listitem, "ID", id);
    cache_get_value_name_int(listitem, "ModeloID", ArmaID);
    cache_get_value_name_int(listitem, "Quantidade", BalasQnt);
    cache_delete(Conectar);
    format(Enviar, sizeof(Enviar), "DELETE FROM `mochila` WHERE `ID` = %d", id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao pegar arma selecionada");
    GivePlayerWeapon(playerid, ArmaID, BalasQnt);
    format(Enviar, sizeof(Enviar), "| MOCHILA | Você pegou uma %s da sua mochila", PegarArmaNome(ArmaID));
    SendClientMessage(playerid, 0xFFFF00FF, Enviar);
    CallRemoteFunction("OnPlayerMochila", "dddd", playerid, ArmaID, BalasQnt, 1);
    return 1;
}


Dialog:MochilaEx(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "MochilaID"),
        Enviar[168],
        DialogEx[1500],
        Cache:Conectar;
    
    switch(listitem)
    {
        case 0: // Retirar
        {
            switch(id)
            {
                // Armas
                case 0:
                {
                    format(Enviar, sizeof(Enviar), "SELECT * FROM `mochila` WHERE `Nome` = '%s' AND `Tipo` = 'Arma'", EscapeString(PegarNick(playerid)));
                    Conectar = mysql_query(IDConexao, Enviar);
                    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema visualizar suas armas");

                    new Love = cache_num_rows();
                    if(Love < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua mochila está vazia");
                    
                    new ArmaID,
                        BalasQnt;
                    strcat(DialogEx, "Slot\tArma\tMunições\n");
                    for(new i=0; i < Love; i++)
                    {
                        cache_get_value_name_int(i, "ModeloID", ArmaID);
                        cache_get_value_name_int(i, "Quantidade", BalasQnt);
                        strcatEx(DialogEx, "{32CD32}%d\t{FFA500}%s\t{00BFFF}%d\n", i+1, PegarArmaNome(ArmaID), BalasQnt);
                    }
                    cache_delete(Conectar);
                    Dialog_Show(playerid, RetirarArmaMochila, DIALOG_STYLE_TABLIST_HEADERS, "{FFA500}Mochila", DialogEx, "Retirar", "Fechar");
                }
            }
        }
        case 1: // Aguardar
        {
            switch(id)
            {
                // Armas
                case 0:
                {
                    if(GetPlayerWeapon(playerid) == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está segurando nenhuma arma");
                    if(GetPVarInt(playerid, "RecebeuArmas") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está em uma área de D.M e não pode guardar armas");
                    format(Enviar, sizeof(Enviar), "SELECT * FROM `mochila` WHERE `Nome` = '%s' AND `Tipo` = 'Arma'", EscapeString(PegarNick(playerid)));
                    Conectar = mysql_query(IDConexao, Enviar);
                    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema verificar suas armas");

                    new Love = cache_num_rows();
                    if(Love >= MAX_MOCHILA_ARMAS) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua mochila já está lotada");
                    cache_delete(Conectar);

                    new ArmaID,
                        BalasQant;
                    GetPlayerWeaponData(playerid, GetWeaponSlot(GetPlayerWeapon(playerid)), ArmaID, BalasQant); 
                    format(Enviar, sizeof(Enviar), "INSERT INTO `mochila` (`Nome`, `Tipo`, `ModeloID`, `Quantidade`) VALUES ('%s', 'Arma', %d, %d)", EscapeString(PegarNick(playerid)), ArmaID, BalasQant);
                    mysql_query(IDConexao, Enviar, false);
                    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao guardar sua arma");
                    RemoverArma(playerid, GetPlayerWeapon(playerid));
                    format(Enviar, sizeof(Enviar), "| MOCHILA | Você guardou uma %s na sua mochila", PegarArmaNome(ArmaID));
                    SendClientMessage(playerid, 0xFFFF00FF, Enviar);
                    CallRemoteFunction("OnPlayerMochila", "dddd", playerid, ArmaID, BalasQant, 0);
                }
            }   
        }
    }

    return 1;
}

CMD:mochila(playerid)
{
    if(Jogador[playerid][Mochila] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui mochila");
    if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode abrir sua mochila em um veículo");

    new Dialog[90];
    strcat(Dialog, "Armas");
    Dialog_Show(playerid, MochilaS, DIALOG_STYLE_TABLIST, "{FF0000}Mochila", Dialog, "Selecionar", "Fechar");
    return 1;
}
