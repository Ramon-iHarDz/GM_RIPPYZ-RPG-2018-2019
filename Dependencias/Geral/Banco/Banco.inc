#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{00FF00}Banco\n{FFFFFF}Aperte 'Y' para acessar o banco", 0xFFFFFFFF, 2649.2930,-1711.6107,1016.5886, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 40.0, -1, 0);
    CreateDynamic3DTextLabel("{00FF00}Banco\n{FFFFFF}Aperte 'Y' para acessar o banco", 0xFFFFFFFF, 2649.5005,-1706.9734,1016.5886, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 40.0, -1, 0);
    // CreateDynamic3DTextLabel("{00FF00}Banco - Apostas\n{FFFFFF}Aperte 'Y' para visualizar", 0xFFFFFFFF, 2619.5559,-1724.1345,1016.5886, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1064, 1, -1, 40.0, -1, 0);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
    if(newkeys == KEY_YES)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 2649.2930,-1711.6107,1016.5886) && GetPlayerInterior(playerid) == 1 && GetPlayerVirtualWorld(playerid) == 1064
            || IsPlayerInRangeOfPoint(playerid, 3.0, 2649.5005,-1706.9734,1016.5886) && GetPlayerInterior(playerid) == 1 && GetPlayerVirtualWorld(playerid) == 1064){
            MostrarBancoCapa(playerid);
            MostrarBancoHome(playerid);
        }
    }
    return 1;  
}

stock EnviarLogDinheiro(playerid, id, valoratl, const MsgLog[])
{
    new EnviarLog[338]; 
    if(id == -1) format(EnviarLog, sizeof(EnviarLog), "INSERT INTO `logdinheiro` (`Nome`, `Para`, `Data`, `Valor`, `Mensagem`) VALUES ('%s', '%s', %d, %d, '%s')", EscapeString(PegarNick(playerid)), "Rippzy City", gettime(), valoratl, EscapeString(MsgLog));
    else format(EnviarLog, sizeof(EnviarLog), "INSERT INTO `logdinheiro` (`Nome`, `Para`, `Data`, `Valor`, `Mensagem`) VALUES ('%s', '%s', %d, %d, '%s')", EscapeString(PegarNick(playerid)), EscapeString(PegarNick(id)), gettime(), valoratl, EscapeString(MsgLog));
    mysql_query(IDConexao, EnviarLog, false);
    if(mysql_errno(IDConexao) != 0) return false;
    return true;
}

stock AtualizarSaldoBancario(playerid, novosaldo)
{
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `DinheiroBanco` = %d WHERE `Nome` = '%s'", novosaldo, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return false;
    return true;
}