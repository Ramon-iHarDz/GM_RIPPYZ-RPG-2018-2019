CMD:broadcast(playerid)
{
    if(Jogador[playerid][TagPersonalizada] != 1 && 
    Jogador[playerid][TagPersonalizada] != 2 && 
    Jogador[playerid][TagPersonalizada] != 5 &&
    Jogador[playerid][Admin] != 7) return 0;
    new Dialog[300];
    strcat(Dialog, "1. Anunciar Live\n");
    strcat(Dialog, "2. Anunciar Evento\n");
    strcat(Dialog, "3. Consultar Código\n");
    strcat(Dialog, "4. Limpar Chat\n");
    strcat(Dialog, "5. Desbloquear Tempo de Profissão\n");
    if(Jogador[playerid][Admin] == 7) strcat(Dialog, "6. Isabella Mensagem");
    Dialog_Show(playerid, BroadMenu, DIALOG_STYLE_TABLIST, "{FF0000}BroadCast", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:BroadMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, BroadLive, DIALOG_STYLE_INPUT, "{FF0000}Mensagem", "Adicione uma mensagem abaixo", "Enviar", "Fechar");
        case 1: Dialog_Show(playerid, BroadEvento, DIALOG_STYLE_INPUT, "{FF0000}Mensagem", "Adicione uma mensagem abaixo", "Enviar", "Fechar");
        case 2: Dialog_Show(playerid, BroadCodigo, DIALOG_STYLE_INPUT, "{FF0000}Código", "Coloque seu código abaixo", "Consultar", "Fechar");
        case 3:
        {
            for(new i=0; i < 100; i++){
                SendClientMessage(playerid, -1, " ");
            }
        }
        case 4:
        {
            pTempo[playerid][TrocaProfissao] = 0;
            SendClientMessage(playerid, 0xFFFF00FF, "| BROADCAST | Você removeu o tempo de espera para trocar de profissão");
        }
        case 5: Dialog_Show(playerid, BroadIsabella, DIALOG_STYLE_INPUT, "{FF0000}Mensagem", "Adicione uma mensagem abaixo", "Enviar", "Fechar");
        
    }
    return 1;
}

Dialog:BroadLive(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;

    if(GetPVarInt(playerid, "BroadUse") > gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Aguarde um pouco antes de usar!");
    SetPVarInt(playerid, "BroadUse", gettime()+900);

    if(AlertaAdminStt == true){
        KillTimer(TempoAlertaAdmin);
        OcultarAdminAlerta();
        AlertaAdminStt = false;
    }
    MostrarAdminAlerta();

    new String[200];
    new Msggg[228];
    if(Jogador[playerid][TagPersonalizada] == 1) format(String, sizeof(String), "~r~YouTuber ~w~%s", PegarNick(playerid));
    else if(Jogador[playerid][TagPersonalizada] == 2) format(String, sizeof(String), "~p~Locutor(a) ~w~%s", PegarNick(playerid));
    else if(Jogador[playerid][TagPersonalizada] == 5) format(String, sizeof(String), "~p~Streamer ~w~%s", PegarNick(playerid));
    format(Msggg, sizeof(Msggg), "~r~[Ao Vivo]:~w~ %s", inputtext);
    TextDrawSetString(AlertaAdmin[1], ConverterTexto(String));
    TextDrawSetString(AlertaAdmin[2], ConverterTexto(Msggg));
    TempoAlertaAdmin = SetTimer("OcultarAdminAlerta", 8000, false); 
    AlertaAdminStt = true;
    return 1;
}

Dialog:BroadEvento(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;

    if(GetPVarInt(playerid, "BroadUse") > gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Aguarde um pouco antes de usar!");
    SetPVarInt(playerid, "BroadUse", gettime()+900);

    if(AlertaAdminStt == true){
        KillTimer(TempoAlertaAdmin);
        OcultarAdminAlerta();
        AlertaAdminStt = false;
    }
    MostrarAdminAlerta();

    new String[100];
    new Msggg[228];
    if(Jogador[playerid][TagPersonalizada] == 1) format(String, sizeof(String), "~r~YouTuber ~w~%s", PegarNick(playerid));
    else if(Jogador[playerid][TagPersonalizada] == 2) format(String, sizeof(String), "~p~Locutor(a) ~w~%s", PegarNick(playerid));
    else if(Jogador[playerid][TagPersonalizada] == 5) format(String, sizeof(String), "~p~Streamer ~w~%s", PegarNick(playerid));
    format(Msggg, sizeof(Msggg), "~y~[Evento]:~w~ %s", inputtext);
    TextDrawSetString(AlertaAdmin[1], ConverterTexto(String));
    TextDrawSetString(AlertaAdmin[2], ConverterTexto(Msggg));
    TempoAlertaAdmin = SetTimer("OcultarAdminAlerta", 8000, false); 
    AlertaAdminStt = true;
    return 1;
}

Dialog:BroadIsabella(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;

    if(AlertaAdminStt == true){
        KillTimer(TempoAlertaAdmin);
        OcultarAdminAlerta();
        AlertaAdminStt = false;
    }
    MostrarAdminAlerta();
    TextDrawSetString(AlertaAdmin[2], ConverterTexto("~b~Administradora ~w~Isabella"));
    TextDrawSetString(AlertaAdmin[1], ConverterTexto(inputtext));
    TempoAlertaAdmin = SetTimer("OcultarAdminAlerta", 8000, false);  
    AlertaAdminStt = true;
    return 1;
}

Dialog:BroadCodigo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;

    new Query[128],
        Cache:Conectar;
    format(Query, sizeof(Query), "SELECT * FROM `codigocupom` WHERE `Codigo` = '%s'", EscapeString(inputtext));
    Conectar = mysql_query(IDConexao, Query, true);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema.");
    if(cache_num_rows() < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse código não existe");

    new Usos,
        Maximo,
        Ponte[15];
    cache_get_value_name_int(0, "Usos", Usos);
    cache_get_value_name_int(0, "Maximo", Maximo);
    cache_delete(Conectar);

    if(Maximo == 0) strcat(Ponte, "Infinito");
    else strcatEx(Ponte, "%d", Maximo);

    stringclear(Query);
    strcat(Query, "Opção\tAdicional\n");
    strcatEx(Query, "Código\t{FFA500}%s\n", inputtext);
    strcatEx(Query, "Usos\t{FFA500}%d | %s\n", Usos, Ponte);
    strcat(Query, "{FF0000}Visualizar Recentes");
    SetPVarString(playerid, "Querry", inputtext);
    Dialog_Show(playerid, BroadUsuario, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Apoie-me", Query, "Selecionar", "Fechar");
    return 1;
}

Dialog:BroadUsuario(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(listitem != 2) return 1;
    new Query[128],
        Codex[30],
        Cache:Conectar;
    GetPVarString(playerid, "Querry", Codex, 30);
    
    format(Query, sizeof(Query), "SELECT * FROM `cupom` WHERE `Codigo` = '%s'", EscapeString(Codex));
    Conectar = mysql_query(IDConexao, Query, true);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema.");
    if(cache_num_rows() < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nenhuma ativação foi efetuada até o momento.");
    new qq = 1,
        aass = cache_num_rows(),
        Dialog[2000],
        Gasd[30],
        datt;
    aass--;
    for(new i=0; i < cache_num_rows(); i++)
    {
        cache_get_value(aass, "Nome", Gasd, 30);
        cache_get_value_name_int(aass, "Ativacao", datt);

        strcatEx(Dialog, "%d.\t{FFA500}%s\t{00BFFF}%s\n", qq, Gasd, GetDateFromTimeEx(datt));
        qq++;
        aass--;
        if(qq >= 50) break;
    }
    cache_delete(Conectar);
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Usuários", Dialog, "Fechar", #);
    return 1;
}