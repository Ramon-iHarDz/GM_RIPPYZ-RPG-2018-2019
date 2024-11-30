stock SetPlayerPrisao(playerid)
{
    new Cache:Conectar,
        Mensagem[128];
    
    format(Mensagem, sizeof(Mensagem), "SELECT * FROM `presos` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Mensagem);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    if(cache_num_rows() < 1) return 1;

    new vlasd;
    cache_get_value(0, "Admin", Jogador[playerid][AdminName], 70);
    cache_get_value(0, "Motivo", Jogador[playerid][MotivoCadeia], 70);
    cache_get_value_name_int(0, "Tempo", vlasd);
    cache_get_value_name_int(0, "TempoAtual", Jogador[playerid][Preso]);
    cache_get_value_name_int(0, "Cadeia", Jogador[playerid][CadeiaEstilo]);
    cache_delete(Conectar);

    if(Jogador[playerid][Preso] < 1) return 1;

    MostrarRelogioPrisao(playerid);
    ColocarNaCadeia(playerid);

    if(Jogador[playerid][CadeiaEstilo] == 0) format(Mensagem, sizeof(Mensagem), "| PRISÃO | Você foi preso(a) por %d minutos pelo admin %s ( Motivo: %s )", vlasd, Jogador[playerid][AdminName], Jogador[playerid][MotivoCadeia]);
    else format(Mensagem, sizeof(Mensagem), "| CADEIA | Você foi preso(a) por %s pelo policial %s ( Motivo: %s )", SegundosParaMinutos(vlasd), Jogador[playerid][AdminName], Jogador[playerid][MotivoCadeia]);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

stock ColocarNaCadeia(playerid) 
{
    ResetPlayerWeapons(playerid);
    if(Jogador[playerid][CadeiaEstilo] == 0)
    {
        SetPlayerVirtualWorld(playerid, 525);
        SetPlayerInterior(playerid, 10);
        switch(random(3))
        {
            case 0: SetPlayerPos(playerid, 215.6047, 109.7173, 999.0156);
            case 1: SetPlayerPos(playerid, 219.6784, 109.8559, 999.0156);
            case 2: SetPlayerPos(playerid, 223.6527, 110.1782, 999.0156);
            case 3: SetPlayerPos(playerid, 227.5332, 109.8087, 999.0156);
        }
        return 1;
    }
    SetPlayerVirtualWorld(playerid, 414);  
    SetPlayerInterior(playerid, 6);
    SetPlayerPos(playerid, 263.8827, 77.6007, 1001.0391);
    SendClientMessage(playerid, 0xFFFF00FF, "| PRESO | Para solicitar um advogado ( Use: /Solicitar )");
    return 1;
}

stock RemoverDaCadeia(playerid)
{
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    Jogador[playerid][uInterior] = Departamento(playerid);    

    for(new i=0; i < sizeof(Pick); i++)
    {
        if(Pick[i][LocalID] != Jogador[playerid][uInterior]) continue;
        SetPlayerPos(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
    }
    
    Jogador[playerid][uInterior] = 0;
    if(Jogador[playerid][CadeiaEstilo] == 1){
        Jogador[playerid][Estrelas] = 0;
    }
    Jogador[playerid][CadeiaEstilo] = 0;
    SetPlayerHealth(playerid, 100.0);
    RemoverRelogioPrisao(playerid); 

    new EnviarReq[72];
    format(EnviarReq, sizeof(EnviarReq), "DELETE FROM `presos` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, EnviarReq, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF0000FF, "| ERRO | Aconteceu um problema ao retirar você de cadeia, entre em contato com um desenvolvedor");
    return 1;
}

stock CatalogarPrisao(playerid, aEstrelas, const aPrisao[], const qPrendeu[], PrisaoTipo)
{
    new Cache:Conectar,
        Query[200],
        TempoJ; 
    if(PrisaoTipo == 0) TempoJ = TempoCadeia(playerid, aEstrelas);
    else TempoJ = TempoCadeiaMunicipal(playerid, aEstrelas);
    format(Query, sizeof(Query), "SELECT * FROM `presos` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Query);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    new Contagem = cache_num_rows();
    cache_delete(Conectar);

    if(PrisaoTipo == 1) aEstrelas = TempoJ;
    if(Contagem > 0) 
    {
        format(Query, sizeof(Query), "UPDATE `presos` SET `Tempo` = %d, `TempoAtual` = %d, `Admin` = '%s', `Motivo` = '%s', `Cadeia` = %d WHERE `Nome` = '%s'", aEstrelas, TempoJ, EscapeString(qPrendeu), EscapeString(aPrisao), PrisaoTipo, EscapeString(PegarNick(playerid)));
        mysql_query(IDConexao, Query, false);
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    }
    else
    {
        format(Query, sizeof(Query), "INSERT INTO `presos` (`Nome`, `Tempo`, `TempoAtual`, `Admin`, `Motivo`, `Cadeia`) VALUES ('%s', %d, %d, '%s', '%s', %d)", EscapeString(PegarNick(playerid)), aEstrelas, TempoJ, EscapeString(qPrendeu), EscapeString(aPrisao), PrisaoTipo);
        mysql_query(IDConexao, Query, false);
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    }
    return 1;
}

stock TempoCadeia(playerid, tempo)
{
    new TempoJ = Jogador[playerid][Preso];
    new TempoRemake = (60*tempo);
    TempoJ += TempoRemake;
    return TempoJ;
}

stock TempoCadeiaMunicipal(playerid, tempo)
{
    new TempoJ = Jogador[playerid][Preso];
    new TempoRemake = (180*tempo);
    TempoJ += TempoRemake;
    return TempoJ;
}