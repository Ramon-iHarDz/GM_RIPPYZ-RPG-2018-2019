#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CarregarGari();
    return 1;
}

function CarregarGari()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `lixos`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Lixo] Falha ao carregar os lixos!");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Lixo] Lixos sendo carregados com sucesso!");
    new Quantidade = cache_num_rows(),
        Identificacao = 1,
        Mensagem[100],
        iid;
    for(new i=0; i < Quantidade; i++)
    {
        cache_get_value_name_int(i, "Bloqueado", iid);
        if(iid == 1) continue;

        cache_get_value_name_float(i, "X", Lixo[Identificacao][PosX]);
        cache_get_value_name_float(i, "Y", Lixo[Identificacao][PosY]);
        cache_get_value_name_float(i, "Z", Lixo[Identificacao][PosZ]);
        cache_get_value_name_int(i, "Model", Lixo[Identificacao][ModeloLixo]);
        cache_get_value_name_int(i, "LixoSuporte", Lixo[Identificacao][LixoMaximo]);
        cache_get_value_name_int(i, "Separacao", Lixo[Identificacao][Separacao]);
        Lixo[Identificacao][LixoAtual] = Lixo[Identificacao][LixoMaximo];

        format(Mensagem, sizeof(Mensagem), "Lixo(s) {6ff542}%d{FFFFFF} / {00FF00}%d\n{FFFFFF}Aperte {CCCCCC}'N'{FFFFFF} para coletar", Lixo[Identificacao][LixoAtual], Lixo[Identificacao][LixoMaximo]);
        Lixo[Identificacao][LixoTexto] = CreateDynamic3DTextLabel(Mensagem, 0xFFFFFFFF, Lixo[Identificacao][PosX], Lixo[Identificacao][PosY], Lixo[Identificacao][PosZ]+1, 18.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
        Lixo[Identificacao][cColocado] = true;
        Identificacao++;
    }
    cache_delete(Conectar);

    CreateDynamic3DTextLabel("Gari\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar um veículo", 0x00BFFFFF, 2109.5657,-2069.0015,13.5544, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 17.0, -1, 0);
    CreateDynamicPickup(1239, 1, 2109.5657,-2069.0015,13.5544, 0, 0, -1, 180.0, -1, 0);
    return 1;
}

CMD:desativarlixo(playerid, params[]){
    if(Jogador[playerid][Admin] < 7) return 0;
    for(new i=0; i < MAX_LIXOS; i++){
        if(Lixo[i][cColocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, Lixo[i][PosX], Lixo[i][PosY], Lixo[i][PosZ])) continue;
        DestroyDynamic3DTextLabelEx(Lixo[i][LixoTexto]);
        new Query[70];
        format(Query, sizeof(Query), "UPDATE `lixos` SET `Bloqueado` = 1 WHERE `Separacao`=%d", Lixo[i][Separacao]);
        mysql_query(IDConexao, Query, false);
        break;
    }
    return 1;
}