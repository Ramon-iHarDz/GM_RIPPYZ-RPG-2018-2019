#include <YSI_Coding\y_hooks>

Dialog:Teleportt(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: EnviarPosicaoAdmin(playerid, 0, 0, 1153.9882, -1772.1722, 16.5992);
        case 1:
        {
            if(Jogador[playerid][Admin] < 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar essa opção, marque no mapa.");
            EnviarPosicaoAdmin(playerid, 0, 0, 1334.4534, -985.1074, 33.8966);
        }
    }
    return 1;
}

Dialog:AdminLogin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;

    new hash[128];
    SHA256_PassHash(inputtext, Jogador[playerid][SaltAdmin], hash, 128);
    if(strcmp(hash, Jogador[playerid][SenhaAdmin])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Senha Incorreta!");
    Jogador[playerid][Admin] = Jogador[playerid][TempAdmin];
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | %s %s logou", CargoAdmin(2, playerid), PegarNick(playerid));

    //SetPlayerAttachedObject(playerid, 7, 19518, 1, -0.039999, -0.182998, 0.126999, -40.4, -0.90003, 0.126999, 3.865, 1.008, 0.465999, 0xFF000000, 0xFF000000);
    //SetPlayerAttachedObject(playerid, 8, 19518, 1, -0.027, -0.182999, -0.147999, 42.4, -2.90001, 2.29991, 3.846, 1, 0.401002, 0xFF000000, 0xFF000000);

    if(GetPVarInt(playerid, "LiberarForceLogin") == 0){
        for(new i=0; i < MAX_PLAYERS; i++){
            if(!IsPlayerConnected(i)) continue;
            if(i == playerid) continue;
            if(Jogador[i][Admin] < 1) continue;
            SendClientMessage(i, 0xe2b960FF, Mensagem);
        }
    }
    pAdmin[playerid][LogadoAdm] = true;
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você entrou no cargo %s", CargoAdmin(2, playerid)); 
    SendClientMessage(playerid, 0xe2b960FF, Mensagem);
    return 0;
}

Dialog:SelecionarAdminCar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarInt(playerid, "PodeAlterarCargo", 1);
    new adsada = listitem+1;
    Jogador[playerid][Admin] = adsada;
    if(adsada == 7) SetPVarInt(playerid, "PodeAlterarCargo", 0);
    return 1;
}

Dialog:SenhaAdminRegistro(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;

    if(strlen(inputtext) > 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Senha muito grande");

    new SaltRG[11],
        SenhaD[128];
    format(SaltRG, sizeof(SaltRG), GetRandomString(10));
    SHA256_PassHash(inputtext, SaltRG, SenhaD, 128);

    new QueryAdm[228];
    format(QueryAdm, sizeof(QueryAdm), "UPDATE `rippzyrpg` SET `SenhaAdmin` = '%s', `SaltAdmin` = '%s' WHERE `Nome` = '%s'", EscapeString(SenhaD), SaltRG, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, QueryAdm, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao registrar sua senha!");
    format(Jogador[playerid][SenhaAdmin], 128, SenhaD);
    format(Jogador[playerid][SaltAdmin], 90, SaltRG);
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Sua conta foi registrada com sucesso ( %s )", inputtext);
    SendClientMessage(playerid, -1, Mensagem);
    return 0;
}

Dialog:ComandosAdmin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(listitem != 10) return 1;
    new ComandosDialog[2000];
    ComandosCap[playerid] = 0;
    strcat(ComandosDialog, "Comando\tDescrição\n");
    for(new i=PaginasAdmin[playerid]; i < sizeof(ComandosAdminLista); i++){
        if(ComandosCap[playerid] >= 10 && ComandosCap[playerid] < sizeof(ComandosAdminLista)){
            strcat(ComandosDialog, "{FF0000}Próxima Página");
            break;
        }
        PaginasAdmin[playerid]++;
        if(Jogador[playerid][Admin] >= ComandosAdminLista[i][Perm]){
            strcatEx(ComandosDialog, "{36cf85}%s\t{FFFFFF}%s\n", ComandosAdminLista[i][Comando], ComandosAdminLista[i][Descricao]);
            ComandosCap[playerid]++;
        }
    }
    Dialog_Show(playerid, ComandosAdmin, DIALOG_STYLE_TABLIST_HEADERS, "{FF4500}Comandos Admin", ComandosDialog, "Selecionar", "Fechar"); 
    return 0; 
}

Dialog:AlterarIp(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `email` SET `Ip`='%s'", EscapeString(inputtext));
    mysql_query(IDConexao, Enviar, false);
    format(IpEmail, 20, inputtext);
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou a IP da host para {00BFFF}%s", inputtext);
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}

Dialog:AlterarPorta(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `email` SET `Porta`='%s'", EscapeString(inputtext));
    mysql_query(IDConexao, Enviar, false);
    format(PortaEmail, 20, inputtext);
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou a PORTA da host para {00BFFF}%s", inputtext);
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}

Dialog:AlterarSenhaEmail(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `email` SET `Senha`='%s'", EscapeString(inputtext));
    mysql_query(IDConexao, Enviar, false);
    format(SenhaEmail, 20, inputtext);
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou a SENHA da host para {00BFFF}%s", inputtext);
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}

Dialog:AlterarEmail(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, AlterarIp, DIALOG_STYLE_INPUT, "{FF0000}Alterar IP", "Coloque abaixo o novo IP", "Enviar", "Cancelar");
        case 1: Dialog_Show(playerid, AlterarPorta, DIALOG_STYLE_INPUT, "{FF0000}Alterar Porta", "Coloque abaixo a nova PORTA", "Enviar", "Cancelar");
        case 2: Dialog_Show(playerid, AlterarSenhaEmail, DIALOG_STYLE_INPUT, "{FF0000}Alterar Senha", "Coloque abaixo a nova SENHA", "Enviar", "Cancelar");
    }
    return 1;
}

Dialog:SelecionarLogTexto(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Cache:Conectar,
        Dialog[2400],
        Query[238],
        QueryString[55],
        NomeMex[30],
        TabName[40];
    GetPVarString(playerid, "LogNome", QueryString, 55);
    switch(GetPVarInt(playerid, "LogListitem"))
    {
        // Comandos
        case 0:
        {
            TabName = "{e2b960}Log de Comandos";
            strcat(Dialog, "Nome\tComando\tHorário\n");
            format(Query, sizeof(Query), "SELECT * FROM `logcomandos` WHERE %s AND `Query` LIKE '%s%s%s'", QueryString, "%", EscapeString(inputtext), "%");
        }

        // Chat
        case 1:
        {
            TabName = "{e2b960}Log de Chat";
            strcat(Dialog, "Nome\tMensagem\tHorário\n");
            format(Query, sizeof(Query), "SELECT * FROM `logchat` WHERE %s AND `Query` LIKE '%s%s%s'", QueryString, "%", EscapeString(inputtext), "%");
        }
    }
    Conectar = mysql_query(IDConexao, Query, true);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema na conexão [0x1]");
    new counta = cache_num_rows(),
        LogComand[128],
        TempoComand,
        Contg;

    // for(new i=counta-1; i >= 0; i--){
    for(new i=counta-1; i >= 0; i--){
        if(Contg >= 20) break;
        Contg++;
        cache_get_value(i, "Nome", NomeMex, 30);
        cache_get_value(i, "Query", LogComand, 128);
        cache_get_value_name_int(i, "Tempo", TempoComand);
        strcatEx(Dialog, "%s\t{e2b960}%s\t{FFA500}%s\n", NomeMex, LogComand, GetDateFromTimeExx(TempoComand));
    }
    cache_delete(Conectar);
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, TabName, Dialog, "Fechar", #);
    return 1;
}

Dialog:SelecionarLogEx(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new Cache:Conectar,
                Dialog[2400],
                Query[128],
                QueryString[55],
                NomeMex[30],
                TabName[40];
            GetPVarString(playerid, "LogNome", QueryString, 55);
            switch(GetPVarInt(playerid, "LogListitem"))
            {
                // Comandos
                case 0:
                {
                    TabName = "{e2b960}Log de Comandos";
                    strcat(Dialog, "Nome\tComando\tHorário\n");
                    format(Query, sizeof(Query), "SELECT * FROM `logcomandos` WHERE %s", QueryString);
                }

                // Chat
                case 1:
                {
                    TabName = "{e2b960}Log de Chat";
                    strcat(Dialog, "Nome\tMensagem\tHorário\n");
                    format(Query, sizeof(Query), "SELECT * FROM `logchat` WHERE %s", QueryString);
                }
            }
            Conectar = mysql_query(IDConexao, Query, true);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema na conexão [0x1]");
            new counta = cache_num_rows(),
                LogComand[128],
                TempoComand,
                Contg;
            
            // for(new i=counta-1; i >= 0; i--){
            for(new i=counta-1; i >= 0; i--){
                if(Contg >= 20) break;
                Contg++;
                cache_get_value(i, "Nome", NomeMex, 30);
                cache_get_value(i, "Query", LogComand, 128);
                cache_get_value_name_int(i, "Tempo", TempoComand);
                strcatEx(Dialog, "%s\t{e2b960}%s\t{FFA500}%s\n", NomeMex, LogComand, GetDateFromTimeExx(TempoComand));
            }
            cache_delete(Conectar);
            Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, TabName, Dialog, "Fechar", #);
        }
        case 1: Dialog_Show(playerid, SelecionarLogTexto, DIALOG_STYLE_INPUT, "{e2b960}Procurar por", "Coloque abaixo oque deseja procurar", "Procurar", "Fechar");
    }
    return 1;
}

Dialog:SelecionarLog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[2400],
        Query[128],
        TabName[40],
        Cache:Conectar,
        QueryString[50],
        NomeMex[30],
        counta;
    GetPVarString(playerid, "LogNome", QueryString, 50);
    switch(listitem)
    {
        // 0 == Comando
        // 1 == Chat
        case 0,1:
        {
            SetPVarInt(playerid, "LogListitem", listitem);
            strcat(Dialog, "Mostrar por Tudo\n");
            strcat(Dialog, "Procurar por Texto");
            Dialog_Show(playerid, SelecionarLogEx, DIALOG_STYLE_TABLIST, "{e2b960}Seleção", Dialog, "Selecionar", "Fechar");
            return 1;
        }

        // Ip
        case 2:
        {
            format(Query, sizeof(Query), "SELECT * FROM `logip` WHERE %s", QueryString);
            Conectar = mysql_query(IDConexao, Query, true);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema na conexão [0x3]");
            TabName = "{e2b960}Log de Ip";
            counta = cache_num_rows();
            new LogComand[30],
                TempoComand,
                Contg;
            
            strcat(Dialog, "Nome\tIp\tHorário\n");
            // for(new i=counta-1; i >= 0; i--){
            for(new i=counta-1; i >= 0; i--){
                if(Contg >= 20) break;
                Contg++;
                cache_get_value(i, "Nome", NomeMex, 30);
                cache_get_value(i, "Ip", LogComand, 30);
                cache_get_value_name_int(i, "Tempo", TempoComand);
                strcatEx(Dialog, "%s\t{e2b960}%s\t{FFA500}%s\n", NomeMex, LogComand, GetDateFromTimeExx(TempoComand));
            }
        }

        // Nick
        case 3:
        {
            format(Query, sizeof(Query), "SELECT * FROM `lognick` WHERE %s", QueryString);
            Conectar = mysql_query(IDConexao, Query, true);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema na conexão [0x4]");
            TabName = "{e2b960}Log de Nick";
            counta = cache_num_rows();
            new LogComand[30],
                TempoComand,
                Contg;
            
            strcat(Dialog, "Nome\tNome\tHorário\n");
            // for(new i=counta-1; i >= 0; i--){
            for(new i=counta-1; i >= 0; i--){
                if(Contg >= 20) break;
                Contg++;
                cache_get_value(i, "Nome", NomeMex, 30);
                cache_get_value(i, "NomeSalvo", LogComand, 30);
                cache_get_value_name_int(i, "Tempo", TempoComand);
                strcatEx(Dialog, "%s\t{e2b960}%s\t{FFA500}%s\n", NomeMex, LogComand, GetDateFromTimeExx(TempoComand));
            }
        }
    }
    cache_delete(Conectar);
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, TabName, Dialog, "Fechar", #);
    return 1;
}

Dialog:MenuLogs(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, SelecionarJogadorLog, DIALOG_STYLE_INPUT, "{e2b960}Nome", "Coloque o nome do(a) jogador(a) abaixo", "Confirmar", "Fechar");
        case 1:
        {
            SetPVarString(playerid, "LogNome", "1");
            ConsultarPainel(playerid);
        }
    }
    return 1;
}

Dialog:SelecionarJogadorLog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Nickk[30];
    if(sscanf(inputtext, "s[30]", Nickk)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não colocou o nick correto");
    new Query[50];
    format(Query, sizeof(Query), "`Nome` = '%s'", EscapeString(Nickk));
    SetPVarString(playerid, "LogNome", Query);
    ConsultarPainel(playerid);
    return 1;
}

stock ConsultarPainel(playerid)
{
    new Dialog[75];
    strcat(Dialog, "Log's de Comandos\n"); 
    strcat(Dialog, "Log's de Chat\n");
    strcat(Dialog, "Log's de Ip's\n");
    strcat(Dialog, "Log's de Nick");
    Dialog_Show(playerid, SelecionarLog, DIALOG_STYLE_TABLIST, "{e2b960}Logs Admin", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:AdminTabInfo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(listitem != 0) return 1;
    new Dialog[168];
    strcat(Dialog, "Expulsar\n");
    strcat(Dialog, "Pegar Ip\n");
    strcat(Dialog, "Pegar Serial\n");
    strcat(Dialog, "Pegar Discord ID\n");
    strcat(Dialog, "Forcar Discord Sync");
    Dialog_Show(playerid, AdminTabInfoEx, DIALOG_STYLE_TABLIST, "{FF0000}Atitudes", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:AdminTabInfoEx(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "TabInfoID"),
        Mensagem[148];

    switch(listitem)
    {
        case 0:
        {
            format(Mensagem, sizeof(Mensagem), "| ADMIN | Você forçou uma expulsão no(a) jogador(a) %s[%d]", PegarNick(id), id);
            SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
            KickF(id, playerid, "Expulsão pelo TAB", true);
        }
        case 1:
        {
            format(Mensagem, sizeof(Mensagem), "| ADMIN | Jogador(a) %s[%d] | Ip: %s", PegarNick(id), id, PegarIP(id));
            SendClientMessage(playerid, 0x00BFFFFF, Mensagem);    
        }
        case 2:
        {
            format(Mensagem, sizeof(Mensagem), "| ADMIN | Jogador(a) %s[%d] | Serial: %s", PegarNick(id), id, PegarHWID(id));
            SendClientMessage(playerid, 0x00BFFFFF, Mensagem);    
        }
        case 3:
        {
            if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
            if(!strcmp(Jogador[id][Discord], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não está vinculado(a) com o discord");
            format(Mensagem, sizeof(Mensagem), "| ADMIN | Jogador(a) %s[%d] | Discord ID: %s", PegarNick(id), id, Jogador[id][Discord]);
            SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
        }
        case 4:
        {
            if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
            if(!strcmp(Jogador[id][Discord], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não está vinculado(a) com o discord");
            format(Mensagem, sizeof(Mensagem), "| ADMIN | Você forçou uma sincronização no(a) jogador(a) %s[%d]", PegarNick(id), id);
            // VerificarTags(id);
            SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
        }
    }
    return 1;
}

Dialog:MacroAdmin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    CallRemoteFunction("OnPlayerText", "is", playerid, MacroAdmin[listitem][Comando]);
    return 1;
}