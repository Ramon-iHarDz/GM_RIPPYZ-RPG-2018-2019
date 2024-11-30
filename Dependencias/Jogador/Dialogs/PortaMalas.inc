#include <YSI_Coding\y_hooks>
#define     MAX_PORTAMALAS_ARMAS   (10)

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_NO) return 1;

    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][PortaMalas] == false) continue;
        if(!AtrasVeiculo(playerid, pVeiculo[playerid][i][MeuVeiculoID], 2.0)) return 1;

        SetPVarInt(playerid, "PortaSlot", i);

        new Dialog[6];
        strcat(Dialog, "Armas");
        Dialog_Show(playerid, PortaOpcao, DIALOG_STYLE_TABLIST, "{FFA500}Porta Malas", Dialog, "Selecionar", "Fechar");
        break;
    }

    return 1;
}

Dialog:PortaOpcao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarInt(playerid, "PortaOpcao", listitem);

    new Dialog[16];
    strcat(Dialog, "Retirar\n");
    strcat(Dialog, "Guardar");
    Dialog_Show(playerid, PortaOpcaoEx, DIALOG_STYLE_TABLIST, "{FFA500}Porta Malas", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:PortaOpcaoEx(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new id = GetPVarInt(playerid, "PortaSlot"),
        tipo = GetPVarInt(playerid, "PortaOpcao"),
        Enviar[168],
        DialogEx[1500],
        Cache:Conectar;
    
    switch(listitem)
    {
        // Guardar
        case 0:
        {
            switch(tipo)
            {
                // Armas
                case 0:
                {
                    format(Enviar, sizeof(Enviar), "SELECT * FROM `portamalas` WHERE `Nome` = '%s' AND `Tipo` = 'Arma' AND `Slot` = %d", EscapeString(PegarNick(playerid)), id);
                    Conectar = mysql_query(IDConexao, Enviar);
                    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema visualizar suas armas");

                    new Love = cache_num_rows();
                    if(Love < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo está vázio");
                    
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
                    Dialog_Show(playerid, RetirarArmaPorta, DIALOG_STYLE_TABLIST_HEADERS, "{FFA500}Porta Malas", DialogEx, "Retirar", "Fechar");
                }
            }
        }

        // Retirar
        case 1:
        {
            switch(tipo)
            {
                // Armas
                case 0:
                {
                    if(GetPlayerWeapon(playerid) == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está segurando nenhuma arma");
                    if(GetPVarInt(playerid, "RecebeuArmas") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está em uma área de D.M e não pode guardar armas");
                    format(Enviar, sizeof(Enviar), "SELECT * FROM `portamalas` WHERE `Nome` = '%s' AND `Tipo` = 'Arma'", EscapeString(PegarNick(playerid)));
                    Conectar = mysql_query(IDConexao, Enviar);
                    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema verificar suas armas");

                    new Love = cache_num_rows();
                    if(Love >= MAX_PORTAMALAS_ARMAS) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Porta malas já está lotado");
                    cache_delete(Conectar);

                    new ArmaID,
                        BalasQant;
                    GetPlayerWeaponData(playerid, GetWeaponSlot(GetPlayerWeapon(playerid)), ArmaID, BalasQant); 
                    format(Enviar, sizeof(Enviar), "INSERT INTO `portamalas` (`Nome`, `Tipo`, `ModeloID`, `Quantidade`, `Slot`) VALUES ('%s', 'Arma', %d, %d, %d)", EscapeString(PegarNick(playerid)), ArmaID, BalasQant, id);
                    mysql_query(IDConexao, Enviar, false);
                    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao guardar sua arma");
                    RemoverArma(playerid, GetPlayerWeapon(playerid));
                    format(Enviar, sizeof(Enviar), "| VEÍCULO | Você guardou uma %s no porta malas", PegarArmaNome(ArmaID));
                    SendClientMessage(playerid, 0xFFFF00FF, Enviar);
                }
            }
        }
    }
    return 1;
}


Dialog:RetirarArmaPorta(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[148],
        Cache:Conectar;
    new idx = GetPVarInt(playerid, "PortaSlot");
    format(Enviar, sizeof(Enviar), "SELECT * FROM `portamalas` WHERE `Nome` = '%s' AND `Tipo` = 'Arma' AND `Slot` = %d", EscapeString(PegarNick(playerid)), idx);
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema verificar arma selecionada");

    new ArmaID,
        BalasQnt,
        id;
    cache_get_value_name_int(listitem, "ID", id);
    cache_get_value_name_int(listitem, "ModeloID", ArmaID);
    cache_get_value_name_int(listitem, "Quantidade", BalasQnt);
    cache_delete(Conectar);
    format(Enviar, sizeof(Enviar), "DELETE FROM `portamalas` WHERE `ID` = %d", id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao pegar arma selecionada");
    GivePlayerWeapon(playerid, ArmaID, BalasQnt);
    format(Enviar, sizeof(Enviar), "| VEÍCULO | Você pegou uma %s do porta malas", PegarArmaNome(ArmaID));
    SendClientMessage(playerid, 0xFFFF00FF, Enviar);
    return 1;
}