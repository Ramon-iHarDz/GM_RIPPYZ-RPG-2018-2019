#include <YSI_Coding\y_hooks>

#define MAX_TELEFONES 500

enum TelefonesInfo
{
    bool:TColocado,
    TelefoneID,
    Text3D:TelefoneTexto,
    Float:TPosX,
    Float:TPosY,
    Float:TPosZ,
    Float:TPosRotX,
    Float:TPosRotY,
    Float:TPosRotZ
};

new pTelefone[MAX_TELEFONES][TelefonesInfo];

hook OnGameModeInit()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `telefones`");
    if(mysql_errno(IDConexao) != 0)
    {
        print("Erro ao estabelecer conexão com os telefones publicos!");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Telefones] Sistema de telefone publico está sendo carregado!");
    new buzz = cache_num_rows();
    if(buzz > 0)
    {
        new id;
        for(new i=0; i < buzz; i++)
        {
            cache_get_value_name_int(i, "Numero", id);
            cache_get_value_name_float(i, "PosicaoX", pTelefone[id][TPosX]);
            cache_get_value_name_float(i, "PosicaoY", pTelefone[id][TPosY]);
            cache_get_value_name_float(i, "PosicaoZ", pTelefone[id][TPosZ]);

            cache_get_value_name_float(i, "RotacaoX", pTelefone[id][TPosRotX]);
            cache_get_value_name_float(i, "RotacaoY", pTelefone[id][TPosRotY]);
            cache_get_value_name_float(i, "RotacaoZ", pTelefone[id][TPosRotZ]);
            CarregarTelefone(id);
        }
    }
    cache_delete(Conectar);
    print("[Rippzy:Telefones] Telefones Publicos carregados com sucesso!");
    return 1;
}

CarregarTelefone(id)
{
    pTelefone[id][TelefoneID] = CreateDynamicObject(1346, pTelefone[id][TPosX], pTelefone[id][TPosY], pTelefone[id][TPosZ], pTelefone[id][TPosRotX], pTelefone[id][TPosRotY], pTelefone[id][TPosRotZ], 0, 0, -1, 150.0, 150.0, -1);
    SetDynamicObjectMaterial(pTelefone[id][TelefoneID], 0, 1649, "wglass", "carshowwin2", 0xFFFFFFFF);
    pTelefone[id][TelefoneTexto] = CreateDynamic3DTextLabel("Telefone Público\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para usar", 0xDEB887FF, pTelefone[id][TPosX], pTelefone[id][TPosY], pTelefone[id][TPosZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.0, -1);
    pTelefone[id][TColocado] = true;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
    if(newkeys != KEY_YES) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    for(new i=0; i < MAX_TELEFONES; i++)
    {
        if(pTelefone[i][TColocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, pTelefone[i][TPosX], pTelefone[i][TPosY], pTelefone[i][TPosZ])) continue;
        new id = 1;
        if(id == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Orelhões foi desativado pelo desenvolvedor temporariamente");
        Dialog_Show(playerid, Orelhao, DIALOG_STYLE_INPUT, "{FF0000}Orelhão", "{CCCCCC}Coloque abaixo o {FFFFFF}ID{CCCCCC} para quem você quer ligar", "Ligar", "Cancelar");
        break;
    }
    return 1;
}

stock DesligarChamada(playerid)
{
    new id = jTelefone[playerid][Ligando];
    if(jTelefone[playerid][LigacaoS] != 2 && jTelefone[id][LigacaoS] != 3) return false;
    if(jTelefone[id][LigacaoS] == 3) KillTimer(jTelefone[id][LigacaoTimer]);
    if(jTelefone[playerid][LigacaoS] == 3) KillTimer(jTelefone[playerid][LigacaoTimer]);
    jTelefone[playerid][LigacaoS] = 0;
    jTelefone[id][LigacaoS] = 0;
    return true;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(!DesligarChamada(playerid)) return 1;
    new id = jTelefone[playerid][Ligando],
        Mensagem[128]
    ;
    format(Mensagem, sizeof(Mensagem), "| LIGAÇÃO | %s[%d] acabou sofrendo um acidente e a ligação foi desligada", PegarNick(playerid), playerid);
    SendClientMessage(id, 0xFF4500FF, Mensagem);
    return 1;
}

Dialog:Orelhao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você colocou um ID inválido");
    Ligacao(playerid, id, true);
    return 0;
}

function LigacaoVerify(playerid, id, cong)
{
    if(cong == 1) TogglePlayerControllable(playerid, 1);
    jTelefone[playerid][LigacaoS] = 0;
    jTelefone[id][LigacaoS] = 0;
    KillTimer(jTelefone[playerid][LigacaoTimer]);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| LIGAÇÃO | Você não atendeu a ligação do(a) %s[%d]", PegarNick(playerid), playerid);
    SendClientMessage(id, -1, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| LIGAÇÃO | %s[%d] não atendeu sua ligação!", PegarNick(id), id);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(DesligarChamada(playerid)){
        new id = jTelefone[playerid][Ligando];
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| LIGAÇÃO | %s[%d] desconectou-se do servidor", PegarNick(playerid), playerid);
        SendClientMessage(id, 0xFF4500FF, Mensagem);
    }

    new Deletar[TelefonePlayer];
    jTelefone[playerid] = Deletar;
    return 1;
}

hook OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
{
    if(response == EDIT_RESPONSE_CANCEL)
    {
        new id = GetPVarInt(playerid, "TelefoneIDCriacao");
        if(id == objectid){
            DestroyObject(objectid);
            SendClientMessage(playerid, 0xFFFF00FF, "| ADMIN | Você cancelou a criação do telefone");  
        }
        return 1;
    }

    if(response == EDIT_RESPONSE_FINAL)
    {
        new id = GetPVarInt(playerid, "TelefoneIDCriacao");
        if(id == objectid)
        {
            DestroyObject(objectid);
            new TelefoneLiberadoH = PegarOrelhaoID(),
                Mensagem[128],
                Enviar[300]
            ;

            format(Enviar, sizeof(Enviar), "INSERT INTO `telefones` (`Numero`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `RotacaoX`, `RotacaoY`, `RotacaoZ`) VALUES (%d, %f, %f, %f, %f, %f, %f)", TelefoneLiberadoH, fX, fY, fZ, fRotX, fRotY, fRotZ);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao criar esse telefone!");

            //Posicao
            pTelefone[TelefoneLiberadoH][TPosX] = fX;
            pTelefone[TelefoneLiberadoH][TPosY] = fY;
            pTelefone[TelefoneLiberadoH][TPosZ] = fZ;

            //Olhada
            pTelefone[TelefoneLiberadoH][TPosRotY] = fRotX;
            pTelefone[TelefoneLiberadoH][TPosRotZ] = fRotY;
            pTelefone[TelefoneLiberadoH][TPosRotZ] = fRotZ;

            CarregarTelefone(TelefoneLiberadoH);

            format(Mensagem, sizeof(Mensagem), "| ADMIN | Você criou um telefone público com sucesso", TelefoneLiberadoH);
            SendClientMessage(playerid, 0x00FF00FF, Mensagem);
        }
    	return 1;
	}
    return 0;
}

/*CMD:sms(playerid, params[])
{
    if(Jogador[playerid][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui um celular");
    new id = -1, Mensagem[128], nickss[70];
    if(sscanf(params, "ds[128]", id, Mensagem) && sscanf(params, "s[70]s[128]", nickss, Mensagem)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Sms [ID ou Nick] [Mensagem]");
    if(Jogador[playerid][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui um celular");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode enviar mensagem para si mesmo");
    if(Jogador[playerid][Creditos] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui créditos");

    if(id != -1){
        if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) inexistente!");
    }else{
        if(!IsPlayerConnected(PegarIdPeloNickEx(nickss))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) inexistente!");
        id = PegarIdPeloNickEx(nickss);
    }
    
    if(JogadorSms[playerid][id][BloqueadoSms] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você bloqueou esse(a) jogador(a)");
    if(JogadorSms[id][playerid][BloqueadoSms] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) Jogador(a) bloqueou você");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não efetuou login");
    if(Jogador[id][Celular] == false || Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não possui celular");

    new fMensagem[228];
    format(fMensagem, sizeof(fMensagem), "| MENSAGEM | %s[%d] enviou uma mensagem: %s", PegarNick(playerid), playerid, Mensagem);
    SendClientMessage(id, 0xFFA500FF, fMensagem);

    format(fMensagem, sizeof(fMensagem), "| MENSAGEM | Mensagem enviada para %s[%d]: %s ", PegarNick(id), id, Mensagem);
    SendClientMessage(playerid, 0xc98302FF, fMensagem);

    format(fMensagem, sizeof(fMensagem), "| ADMIN-MENSAGEM | %s[%d] enviou mensagem para %s[%d]: %s", PegarNick(playerid), playerid, PegarNick(id), id, Mensagem);

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] < 2) continue;
        if(pAdmin[i][VerMensagens] == false) continue;
        SendClientMessage(i, 0xFFFF00FF, fMensagem);
    }

    Jogador[playerid][Creditos]--;
    PlayerPlaySound(playerid,1149,0.0,0.0,0.0);
    PlayerPlaySound(id,1149,0.0,0.0,0.0);
    return 1;
}

CMD:bloquearsms(playerid, params[])
{
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /BloquearSms [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se bloquear");
    if(Jogador[playerid][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui um celular");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) inexistente!");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não efetuou login");
    if(Jogador[id][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não possui celular");


    new Mensagem[128];
    if(JogadorSms[playerid][id][BloqueadoSms] == true){
        JogadorSms[playerid][id][BloqueadoSms] = false;
        format(Mensagem, sizeof(Mensagem), "| SMS | Você desbloqueou o(a) jogador(a) %s[%d]", PegarNick(id), id);
    }else{
        JogadorSms[playerid][id][BloqueadoSms] = true;
        format(Mensagem, sizeof(Mensagem), "| SMS | Você bloqueou o(a) jogador(a) %s[%d]", PegarNick(id), id);
    }
    SendClientMessage(playerid, 0xc98302FF, Mensagem);
    return 1;
}*/

stock PegarOrelhaoID()
{
    for(new i=0; i < MAX_TELEFONES; i++)
    {
        if(pTelefone[i][TColocado] == true) continue;
        return i;
    }
    return -1;
}

CMD:criartelefone(playerid, params[])
{
    // if(Jogador[playerid][Admin] != 7) return 0;
    new Float:Pos[3],
        id
    ;
    GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    id = CreateObject(1346, Pos[0]+2, Pos[1], Pos[2], 0.0, 0.0, 0.0, 0.0);
    SetPVarInt(playerid, "TelefoneIDCriacao", id);
    EditObject(playerid, id);
    SendClientMessage(playerid, 0xFF4500FF, "| ADMIN | Posicione o telefone e salve-o ou aperte esc para cancelar!");
    return 1;
}

CMD:removertelefone(playerid)
{
    // if(Jogador[playerid][Admin] != 7) return 0;
    for(new i=1; i < MAX_TELEFONES; i++)
    {
        if(pTelefone[i][TColocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, pTelefone[i][TPosX], pTelefone[i][TPosY], pTelefone[i][TPosZ])) continue;
        new Enviar[128];
        format(Enviar, sizeof(Enviar), "DELETE FROM `telefones` WHERE `Numero` = %d", i);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao remover esse telefone!");
                
        new Mensagem[128];
        pTelefone[i][TColocado] = false;
        DestroyDynamicObjectEx(pTelefone[i][TelefoneID]);
        DestroyDynamic3DTextLabelEx(pTelefone[i][TelefoneTexto]);
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Você deletou o telefone público %d", i);
        SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
        break;
    }
    return 1;
}