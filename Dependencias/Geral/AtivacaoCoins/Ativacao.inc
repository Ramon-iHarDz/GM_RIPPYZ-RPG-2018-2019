
stock AtivarVIP(playerid, dias, price = 0)
{
    new Simulado = Jogador[playerid][Vip],
        Enviar[128];
    Simulado += (Jogador[playerid][Vip] > 0 ? (dias * 86400) : (gettime() + (dias * 86400)));
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Vip` = %d WHERE `Nome` = '%s'", Simulado, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema na ativar do seu VIP");
    Jogador[playerid][Vip] = Simulado;

    SendClientMessage(playerid, 0x32CD32FF, "+ ================================================== +");
    if(price > 0)
    {
        format(Enviar, sizeof(Enviar), "» Você comprou {00BFFF}%d{FFFFFF} dia(s) de VIP", dias);
        SendClientMessage(playerid, -1, Enviar);
        format(Enviar, sizeof(Enviar), "» Preço do VIP: {FFFF00}$%s{FFFFFF} coins ( Saldo: {32CD32}$%s{FFFFFF} )", DinheiroSeparar(price), DinheiroSeparar(Jogador[playerid][Coins]));
        SendClientMessage(playerid, -1, Enviar);
    }
    format(Enviar, sizeof(Enviar), "» Você ativou {00BFFF}%d{FFFFFF} dia(s) de VIP", dias);
    SendClientMessage(playerid, -1, Enviar);
    format(Enviar, sizeof(Enviar), "» Data de Ativação: {FF8C00}%s", GetDateFromTime(gettime()));
    SendClientMessage(playerid, -1, Enviar);
    SendClientMessage(playerid, 0x32CD32FF, "+ ================================================== +");
    // VerificarTags(playerid);
    return 1;
}

Dialog:ConfirmacaoCompra(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new diasx = GetPVarInt(playerid, "DiasSelect"),
        coinx = GetPVarInt(playerid, "CoinsSelect");
    if(coinx > Jogador[playerid][Coins]) return 1;

    new Enviar[128],
        Simulado = Jogador[playerid][Coins];
    
    Simulado -= coinx;
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Coins` = %d WHERE `Nome` = '%s'", Simulado, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema na compra do seu VIP");
    Jogador[playerid][Coins] = Simulado;
    AtivarVIP(playerid, diasx, coinx);
    return 1;
}

Dialog:TabelaVip(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    new // somacoins = (Jogador[playerid][Coins]/1000),
        Dialog[128],
        sslc;
    new somamoney;

    for(new i=1; i < 31; i++)
	{
		// if(somacoins < i && somacoins < 10) break;
  		if(par(i) != 0 && i != 1) continue;
        
        if(listitem != sslc){
            sslc++;
            continue;
        }
        somamoney = (i*1000);

        if(Jogador[playerid][Coins] < somamoney) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem coins suficiente");
        SetPVarInt(playerid, "DiasSelect", i);
        SetPVarInt(playerid, "CoinsSelect", somamoney); 
        format(Dialog, sizeof(Dialog), "Você tem certeza que quer comprar %d dias de VIP por $%s coins?", i, DinheiroSeparar(somamoney));
        Dialog_Show(playerid, ConfirmacaoCompra, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", Dialog, "Confirmar", "Cancelar");
        break;
    }
    return 1;
}

Dialog:CodigoCoins(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(CaracterEspecial(inputtext)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar caracteres especias");
    if(strlen(inputtext) > 30) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Código Inválido [0x1]");

    new Cache:Conectar,
        Enviar[268];
    format(Enviar, sizeof(Enviar), "SELECT * FROM `codigocoins` WHERE `Codigo` = '%s'", EscapeString(inputtext));
    Conectar = mysql_query(IDConexao, Enviar, true);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao fazer essa consulta.");
    if(cache_num_rows() < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Código Inválido");
    
    new Attv,
        Coinx;
    cache_get_value_name_int(0, "Ativado", Attv);
    cache_get_value_name_int(0, "Coins", Coinx);
    cache_delete(Conectar);
    if(Attv != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse código já foi ativado.");
    new Simulado = Jogador[playerid][Coins];
    Simulado += Coinx;
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Coins` = %d WHERE `Nome` = '%s'", Simulado, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao ativar seus coins.");
    Jogador[playerid][Coins] = Simulado;

    format(Enviar, sizeof(Enviar), "UPDATE `codigocoins` SET `Ativado` = %d, `AtivadoPor` = '%s' WHERE `Codigo` = '%s'", gettime(), EscapeString(PegarNick(playerid)), EscapeString(inputtext));
    mysql_query(IDConexao, Enviar, false);

    SendClientMessage(playerid, 0x32CD32FF, "+ ================================================== +");
    format(Enviar, sizeof(Enviar), "» Você ativou {FFFF00}$%s{FFFFFF} de coins", DinheiroSeparar(Coinx));
    SendClientMessage(playerid, -1, Enviar);
    format(Enviar, sizeof(Enviar), "» Data de Ativação: {FF8C00}%s", GetDateFromTime(gettime()));
    SendClientMessage(playerid, -1, Enviar);
    SendClientMessage(playerid, 0x32CD32FF, "+ ================================================== +");
    return 1;
}

Dialog:CodigoCupom(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(CaracterEspecial(inputtext)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar caracteres especias");
    if(strlen(inputtext) > 30) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Código Inválido [0x1]");

    new Cache:Conectar,
        Enviar[368];

    format(Enviar, sizeof(Enviar), "SELECT * FROM `cupom` WHERE `Nome` = '%s' AND `Codigo` = '%s'", EscapeString(PegarNick(playerid)), EscapeString(inputtext));
    Conectar = mysql_query(IDConexao, Enviar, true);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao fazer essa consulta. [0x1]");
    if(cache_num_rows() > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já ativou esse cupom");
    cache_delete(Conectar);

    format(Enviar, sizeof(Enviar), "SELECT * FROM `codigocupom` WHERE `Codigo` = '%s'", EscapeString(inputtext));
    Conectar = mysql_query(IDConexao, Enviar, true);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao fazer essa consulta.");
    if(cache_num_rows() < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Código Inválido");
    
    
    new id,
        Usos,
        Maximo,
        Criador[30],
        DinheiroCupom,
        CoinsCupom,
        VipCupom,
        LevelUse,
        Recibo[168];

    cache_get_value_name_int(0, "ID", id);
    cache_get_value(0, "Atendente", Criador, 30);
    cache_get_value_name_int(0, "Usos", Usos);
    cache_get_value_name_int(0, "Maximo", Maximo);
    cache_get_value_name_int(0, "Dinheiro", DinheiroCupom);
    cache_get_value_name_int(0, "Coins", CoinsCupom);
    cache_get_value_name_int(0, "Vip", VipCupom);
    cache_get_value_name_int(0, "LevelUse", LevelUse);
    cache_delete(Conectar);

    if(Maximo != 0){
        if(Usos >= Maximo){
            format(Enviar, sizeof(Enviar), "| CUPOM | Você tentou usar o cupom do %s que já foi utilizado %d veze(s)", Criador, Usos);
            SendClientMessage(playerid, 0xFF4500FF, Enviar);
            return 1;
        }
    }

    if(Jogador[playerid][Level] > LevelUse){
        format(Enviar, sizeof(Enviar), "| CUPOM | Você não possui level para utilizar o código do %s, Level necessário é abaixo de %d", Criador, LevelUse);
        SendClientMessage(playerid, 0xFF4500FF, Enviar);
        return 1;    
    }

    format(Enviar, sizeof(Enviar), "INSERT INTO `cupom` (`Nome`, `Codigo`, `Data`, `Atendente`, `Ativacao`) VALUES ('%s', '%s', '%s', '%s', %d)", EscapeString(PegarNick(playerid)), EscapeString(inputtext), GetDateFromTime(gettime()), EscapeString(Criador), gettime());
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao realizar o uso do cupom");

    format(Recibo, sizeof(Recibo), "| APOIADOR | Você utilizou o código do(a) %s e recebeu {FFA500}", Criador);
    if(DinheiroCupom > 0){
        Jogador[playerid][Dinheiro] += DinheiroCupom;
        strcatEx(Recibo, "R$%s Reais, ", DinheiroSeparar(DinheiroCupom));
    }

    if(CoinsCupom > 0){
        Jogador[playerid][Coins] += CoinsCupom;
        strcatEx(Recibo, "R$%s Coins, ", DinheiroSeparar(CoinsCupom));
    }

    if(VipCupom > 0){
        AtivarVIP(playerid, VipCupom);
        strcatEx(Recibo, "%d dia(s) de VIP", VipCupom);
    }
    SendClientMessage(playerid, -1, Recibo);
    pTempo[playerid][UsoApoio] = gettime()+7200;

    Usos++;
    format(Enviar, sizeof(Enviar), "UPDATE `codigocupom` SET `Usos` = %d WHERE `ID` = %d", Usos, id);
    mysql_query(IDConexao, Enviar, false);
    return 1;
}

Dialog:LojaMenuCoins(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, CodigoCoins, DIALOG_STYLE_INPUT, "{FF0000}Ativação", "Coloque o código abaixo.", "Ativar", "Fechar");
        case 1:
        {
            /*new coins = (10000/1000);
            for(new i=2; i < 30; i++)
            {
                if(coins < i) break;
                if(par(i) != 0) continue;
                if(i < 10 && coins < 10) printf("Dias: %d - Price: $%d [Dinheiro Baixo]", i, i*1500);
                else if(i > 9) printf("Dias: %d - Price: $%d [Dinheiro Alto]", i, i*1000);
            }*/
            new somamoney,
                Dialog[650];

            strcat(Dialog, "Dias\tPreço\n");
            for(new i=1; i < 31; i++)
            {
                if(par(i) != 0 && i != 1) continue;

                somamoney = (i*1000);
                if(somamoney > Jogador[playerid][Coins]) strcatEx(Dialog, "{FFFFFF}Dias: {CCCCCC}%d\t{FF0000}$%s\n", i, DinheiroSeparar(somamoney));
                else strcatEx(Dialog, "{FFFFFF}Dias: {CCCCCC}%d\t{32CD32}$%s\n", i, DinheiroSeparar(somamoney));
            }
            Dialog_Show(playerid, TabelaVip, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Comprar VIP", Dialog, "Comprar", "Fechar");
        }
        case 2:
        {
            if(pTempo[playerid][UsoApoio] > gettime()){
                new Mensagem[95];
                format(Mensagem, sizeof(Mensagem), "| ERRO | Você só pode apoiar outro(a) criador(a) em %s", ConverterSegundosEx(pTempo[playerid][UsoApoio]));
                SendClientMessage(playerid, 0xFF4500FF, Mensagem);
                return 1;
            }
            Dialog_Show(playerid, CodigoCupom, DIALOG_STYLE_INPUT, "{FF0000}Apoie-me", "Coloque o código abaixo.", "Ativar", "Fechar");
        }
    }
    return 1;
}

CMD:loja(playerid)
{
    new Dialog[128];
    strcat(Dialog, "1. Ativar Coins\n");
    strcat(Dialog, "2. Comprar VIP\n");
    strcat(Dialog, "3. Apoie um(a) criador(a)");
    Dialog_Show(playerid, LojaMenuCoins, DIALOG_STYLE_TABLIST, "{32CD32}Loja", Dialog, "Comprar", "Fechar");
    return 1;
}