#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CarregarCaixa();
    return 1;
}

forward CarregarCaixa();
public CarregarCaixa() 
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `caixas`");
    if(mysql_errno(IDConexao) != 0)
    {
        print("[Rippzy:Caixas] Não foi possivel estabelecer uma conexão nos caixas!");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Caixas] Sistema de caixa eletronico está sendo carregado.");
    new QuantosTem = cache_num_rows(),
        id;
    if(QuantosTem > 0)
    {
        for(new i=0; i < QuantosTem; i++)
        {
            cache_get_value_name_int(i, "CaixaID", id);
            pCaixa[id][CaixaID] = id;
            cache_get_value_name_float(i, "PosicaoX", pCaixa[id][PosicaoX]);
            cache_get_value_name_float(i, "PosicaoY", pCaixa[id][PosicaoY]);
            cache_get_value_name_float(i, "PosicaoZ", pCaixa[id][PosicaoZ]);
            cache_get_value_name_float(i, "PosicaoRX", pCaixa[id][PosicaoRX]);
            cache_get_value_name_float(i, "PosicaoRY", pCaixa[id][PosicaoRY]);
            cache_get_value_name_float(i, "PosicaoRZ", pCaixa[id][PosicaoRZ]);
            cache_get_value_name_int(i, "CaixaInterior", pCaixa[id][CaixaInterior]);
            cache_get_value_name_int(i, "CaixaVirtualWorld", pCaixa[id][CaixaVW]);
            AdicionarCaixa(id);
        }
    }
    print("[Rippzy:Caixas] Caixas eletronicos carregados com sucesso");
    cache_delete(Conectar);
    return 1;
}

function RecuperarCaixa(id){
    UpdateDynamic3DTextLabelText(pCaixa[id][CaixaTexto], 0xFFA500FF, "Caixa Eletrônico\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para acessar sua conta");
    DestroyDynamicObjectEx(pCaixa[id][CaixaObjeto]);
    pCaixa[id][CaixaObjeto] = CreateDynamicObject(19324, pCaixa[id][PosicaoX], pCaixa[id][PosicaoY], pCaixa[id][PosicaoZ], pCaixa[id][PosicaoRX], pCaixa[id][PosicaoRY], pCaixa[id][PosicaoRZ], pCaixa[id][CaixaVW], pCaixa[id][CaixaInterior], -1, 150.0, 150.0, -1, 0);
    pCaixa[id][Explodido] = 0;
    return 1;
}

hook OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
{

    if(response == EDIT_RESPONSE_CANCEL)
    {
        new id = GetPVarInt(playerid, "CaixaIDCriacao");
        if(id == objectid)
        {
            DestroyObject(objectid);
            SendClientMessage(playerid, 0xFFFF00FF, "| ADMIN | Você cancelou a criação do caixa!");  
            DeletePVar(playerid, "CaixaIDCriacao");
        }
        return 1;
    }

    if(response == EDIT_RESPONSE_FINAL)
    {
        new id = GetPVarInt(playerid, "CaixaIDCriacao");
        if(id == objectid)
        {
            DestroyObject(objectid);
            new CaixaLiberadoH = PegarCaixaID(),
                Mensagem[128],
                Enviar[300];

            format(Enviar, sizeof(Enviar), "INSERT INTO `caixas` (`CaixaID`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `PosicaoRX`, `PosicaoRY`, `PosicaoRZ`, `CaixaVirtualWorld`, `CaixaInterior`) VALUES (%d, %f, %f, %f, %f, %f, %f, %d, %d)", CaixaLiberadoH, fX, fY, fZ, fRotX, fRotY, fRotZ, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao criar esse caixa eletrônico!");

            //Posicao
            pCaixa[CaixaLiberadoH][PosicaoX] = fX;
            pCaixa[CaixaLiberadoH][PosicaoY] = fY;
            pCaixa[CaixaLiberadoH][PosicaoZ] = fZ;

            //Olhada
            pCaixa[CaixaLiberadoH][PosicaoRX] = fRotX;
            pCaixa[CaixaLiberadoH][PosicaoRY] = fRotY;
            pCaixa[CaixaLiberadoH][PosicaoRZ] = fRotZ;

            pCaixa[CaixaLiberadoH][CaixaVW] = GetPlayerVirtualWorld(playerid);
            pCaixa[CaixaLiberadoH][CaixaInterior] = GetPlayerInterior(playerid);
            pCaixa[CaixaLiberadoH][CaixaID] = CaixaLiberadoH;

            AdicionarCaixa(CaixaLiberadoH);

            format(Mensagem, sizeof(Mensagem), "| ADMIN | Você criou o caixa %d com sucesso!", CaixaLiberadoH);
            SendClientMessage(playerid, 0x00FF00FF, Mensagem);
            DeletePVar(playerid, "CaixaIDCriacao");
        }
    	return 1;
	}
	return 0;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        for(new i=1; i < MAX_CAIXAS; i++)
        {
            if(pCaixa[i][Conectado] == false) continue;
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ])) continue;
            if(pCaixa[i][Explodido] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse caixa");
            MostrarBancoSaque(playerid, true);
            break;
        }
    }
    return 1;  
}

stock PegarCaixaID()
{
    for(new i=1; i < MAX_CAIXAS; i++)
    {
        if(pCaixa[i][Conectado] == true) continue;
        return i;
    }
    return false;
}

stock AdicionarCaixa(IdDoCaixa)
{
    pCaixa[IdDoCaixa][CaixaTexto] = CreateDynamic3DTextLabel("Caixa Eletrônico\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para acessar sua conta", 0xFFA500FF, pCaixa[IdDoCaixa][PosicaoX], pCaixa[IdDoCaixa][PosicaoY], pCaixa[IdDoCaixa][PosicaoZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, pCaixa[IdDoCaixa][CaixaVW], pCaixa[IdDoCaixa][CaixaInterior], -1, 20.0, -1, 0);
    pCaixa[IdDoCaixa][CaixaObjeto] = CreateDynamicObject(19324, pCaixa[IdDoCaixa][PosicaoX], pCaixa[IdDoCaixa][PosicaoY], pCaixa[IdDoCaixa][PosicaoZ], pCaixa[IdDoCaixa][PosicaoRX], pCaixa[IdDoCaixa][PosicaoRY], pCaixa[IdDoCaixa][PosicaoRZ], pCaixa[IdDoCaixa][CaixaVW], pCaixa[IdDoCaixa][CaixaInterior], -1, 150.0, 150.0, -1, 0);
    pCaixa[IdDoCaixa][Conectado] = true;
    return 1;
}

CMD:criarcaixa(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new Float:Pos[3];
    new id;
    GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    id = CreateObject(2942, Pos[0]+3, Pos[1], Pos[2], 0.0, 0.0, 0.0, 0.0);
    SetPVarInt(playerid, "CaixaIDCriacao", id);
    EditObject(playerid, id);
    SendClientMessage(playerid, 0xFF4500FF, "| ADMIN | Posicione o caixa e salve-o ou aperte esc para cancelar!");
    return 1;
}

CMD:removercaixa(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    
    for(new i=1; i < MAX_CAIXAS; i++)
    {
        if(pCaixa[i][Conectado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, pCaixa[i][PosicaoX], pCaixa[i][PosicaoY], pCaixa[i][PosicaoZ])) continue;
        
        new Enviar[128];
        format(Enviar, sizeof(Enviar), "DELETE FROM `caixas` WHERE `CaixaID` = %d", pCaixa[i][CaixaID]);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao remover esse caixa!");
                
        new Mensagem[128];
        pCaixa[i][Conectado] = false;
        DestroyDynamicObjectEx(pCaixa[i][CaixaObjeto]);
        DestroyDynamic3DTextLabelEx(pCaixa[i][CaixaTexto]);
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Você deletou o caixa %d", pCaixa[i][CaixaID]);
        SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
        return 1;
    }
    return 1;
}