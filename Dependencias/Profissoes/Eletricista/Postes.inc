#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `postes`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Poste] Falha ao carregar os postes");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Poste] Postes sendo carregados com sucesso");
    new Quantidade = cache_num_rows(),
        Identificacao = 1;
    for(new i=0; i < Quantidade; i++)
    {
        cache_get_value_name_int(i, "ID", Poste[Identificacao][PosteID]);
        cache_get_value_name_float(i, "X", Poste[Identificacao][PosteX]);
        cache_get_value_name_float(i, "Y", Poste[Identificacao][PosteY]);
        cache_get_value_name_float(i, "Z", Poste[Identificacao][PosteZ]);
        cache_get_value_name_float(i, "RX", Poste[Identificacao][PosteRX]);
        cache_get_value_name_float(i, "RY", Poste[Identificacao][PosteRY]);
        cache_get_value_name_float(i, "RZ", Poste[Identificacao][PosteRZ]);
        cache_get_value_name_int(i, "Model", Poste[Identificacao][PosteModelo]);
        Poste[Identificacao][PosteColocado] = true;
        Identificacao++;
    }
    cache_delete(Conectar);
    print("[Rippzy:Poste] Postes carregados com sucesso.");
    return 1;
}

CMD:removerposte(playerid, params[])
{
    if(Jogador[playerid][Admin] < 7) return 0;
    for(new i=0; i < MAX_POSTES; i++)
    {
        if(Poste[i][PosteColocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 8.0, Poste[i][PosteX], Poste[i][PosteY], Poste[i][PosteZ])) continue;
        
        new Enviar[60];
        format(Enviar, sizeof(Enviar), "DELETE FROM `postes` WHERE `ID` = %d", Poste[i][PosteID]);
        mysql_query(IDConexao, Enviar, false);
        Poste[i][PosteColocado] = false;

        format(Enviar, sizeof(Enviar), "| POSTE | Você deletou o poste %d", i);
        SendClientMessage(playerid, -1, Enviar);
        break;
    }
    return 1;
}