#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    print("[Rippzy:Conexao] Todos os sistemas estão sendo inicializados!");
    print("[Rippzy:Conexao] Conexão com o banco de dados efetuada com sucesso!");

    IDConexao = mysql_connect_file();
    if(!IDConexao || mysql_errno() != 0) 
    {
        print("[Rippzy:Conexao] Não foi possivel conectar com o banco de dados!");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Conexao] Conexão estabelecida com sucesso.");

    new Cache:Conectar, Enviar[128];
    Conectar = mysql_query(IDConexao, "SELECT * FROM `whitelist` WHERE `Nome` = 'Sistema'");
    cache_get_value(0, "Hwid", Enviar, 50);
    cache_delete(Conectar);

    if(!strcmp(Enviar, "Desativado")) Whitelist = false;
    else Whitelist = true;

    new NomeServidor[90], 
        NomeDoMapa[90], 
        LinguaDoServidor[90], 
        VersaoDoServidor[90],
        bool:rollback;
    
    Conectar = mysql_query(IDConexao, "SELECT * FROM `servidor`");
    cache_get_value(0, "hostname", NomeServidor, 90);
    cache_get_value(0, "mapname", NomeDoMapa, 90);
    cache_get_value(0, "language", LinguaDoServidor, 90);
    cache_get_value(0, "versao", VersaoDoServidor, 90);
    cache_get_value_name_int(0, "rollback", rollback);
    cache_delete(Conectar);

    if(!strcmp(VersaoDoServidor, "Brasil RPG - DEV")) ServidorBeta = true;

    Conectar = mysql_query(IDConexao, "SELECT * FROM `email`");
    cache_get_value(0, "Ip", IpEmail, 20);
    cache_get_value(0, "Porta", PortaEmail, 10);
    cache_get_value(0, "Senha", SenhaEmail, 20); 
    cache_delete(Conectar);
    
    format(Enviar, sizeof(Enviar), "hostname %s", NomeServidor);
    SendRconCommand(Enviar);
    format(Enviar, sizeof(Enviar), "mapname %s", NomeDoMapa);
    SendRconCommand(Enviar);
    format(Enviar, sizeof(Enviar), "language %s", LinguaDoServidor);
    SendRconCommand(Enviar);
    SetGameModeText(VersaoDoServidor);

    // Houve um problema com a reinicialização (Enviar Alerta para o Discord)
    if(rollback == true){
        rollback = false;
        mysql_query(IDConexao, "UPDATE `servidor` SET `rollback` = 0", false);
    }
    else mysql_query(IDConexao, "UPDATE `servidor` SET `rollback` = 1", false);

    if(ServidorBeta == false){
        SendRconCommand("password 0");
    }

    UsePlayerPedAnims();
    ShowPlayerMarkers(PLAYER_MARKERS_MODE_STREAMED);
    LimitPlayerMarkerRadius(60.0);
    ManualVehicleEngineAndLights();
    DisableInteriorEnterExits();
    EnableStuntBonusForAll(0);
    MapAndreas_Init(MAP_ANDREAS_MODE_FULL);
    Streamer_SetTickRate(10);
    return 1;
}

hook OnGameModeExit()
{
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        Kick(i);
    }
    mysql_query(IDConexao, "UPDATE `servidor` SET `rollback` = 0", false); 
	print("[Rippzy:Conexao] Conexão com o banco de dados foi finalizada com sucesso!");
	mysql_close(IDConexao);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    Streamer_ToggleIdleUpdate(playerid, true);
    return 1;
}