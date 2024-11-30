#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    new Cache:Conectar;
    
    // Carregar Membros Base
    print("[Rippzy:Base] Carregando sistema de membros");
    Conectar = mysql_query(IDConexao, "SELECT * FROM `basemembros`", true);
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Base] Não foi possivel carregar os membros bases.");
        SendRconCommand("exit");
        return 1;
    }

    new qpa = cache_num_rows(), 
        id,
        idex,
        idx;

    if(qpa > 0)
    {
        for(new i=0; i < qpa; i++)
        {
            cache_get_value_name_int(i, "BaseID", id);
            cache_get_value_name_int(i, "PosicaoID", idex);
            cache_get_value_name(i, "Nome", bMembro[id][idex][bNome]);
            cache_get_value_name_int(i, "Cargo", bMembro[id][idex][BaseCargo]);
            cache_get_value_name_int(i, "Deposito", bMembro[id][idex][BaseDeposito]);
            cache_get_value_name_int(i, "Entregas", bMembro[id][idex][BaseEntregas]);
            bMembro[id][idex][TemMembro] = true;
        }
    }
    print("[Rippzy:Base] Sistema de membros foi carregado com sucesso");
    cache_delete(Conectar);


    // Carregar Bases
    Conectar = mysql_query(IDConexao, "SELECT * FROM `bases`");
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Base] Não foi possivel conectar com as bases");
        SendRconCommand("exit");
        return 1;
    }

    qpa = cache_num_rows();
    if(qpa > 0)
    {
        for(new i=0; i < qpa; i++)
        {
            // Informações - Integers
            cache_get_value_name_int(i, "Numero", id);
            cache_get_value_name_int(i, "Cofre", Base[id][BaseCofre]);
            cache_get_value_name_int(i, "Vencimento", Base[id][BaseVencimento]);
            cache_get_value_name_int(i, "Status", Base[id][BaseStatus]); 
            cache_get_value_name_int(i, "Valor", Base[id][BaseCoins]);
            cache_get_value_name_int(i, "Invasao", Base[id][BaseInvasao]);
            cache_get_value_name_int(i, "DM", Base[id][BaseDM]);
            cache_get_value_name_int(i, "TagCor", Base[id][BaseTagCor]);
            cache_get_value_name_int(i, "Compra", Base[id][BaseCompra]);
            cache_get_value_name_int(i, "Desconto", Base[id][BaseDesconto]);
            cache_get_value_name_int(i, "Entregas", Base[id][BaseEntregasGeral]); 
            cache_get_value_name_int(i, "BaseAnunciar", Base[id][BaseAnunciar]); 
            cache_get_value_name_int(i, "BloquearRenovacao", Base[id][BloquearRenovacao]);

            // Stings
            cache_get_value_name(i, "Nome", Base[id][BaseNome], 26);
            cache_get_value_name(i, "Tag", Base[id][BaseTag], 10); 
            cache_get_value_name(i, "Senha", Base[id][BaseSenha], 30);

            // Rangers
            cache_get_value_name_float(i, "CimaX", Base[id][CimaX]); // Float
            cache_get_value_name_float(i, "CimaY", Base[id][CimaY]); // Float
            cache_get_value_name_float(i, "BaixoX", Base[id][BaixoX]); // Float
            cache_get_value_name_float(i, "BaixoY", Base[id][BaixoY]); // Float

            // Portão
            cache_get_value_name_float(i, "BasePortaoX", Base[id][BasePortaoX]); // Float
            cache_get_value_name_float(i, "BasePortaoY", Base[id][BasePortaoY]); // Float
            cache_get_value_name_float(i, "BasePortaoZ", Base[id][BasePortaoZ]); // Float
            cache_get_value_name_float(i, "BasePortaoRX", Base[id][BasePortaoRX]); // Float
            cache_get_value_name_float(i, "BasePortaoRY", Base[id][BasePortaoRY]); // Float
            cache_get_value_name_float(i, "BasePortaoRZ", Base[id][BasePortaoRZ]); // Float

            // Fora
            cache_get_value_name_float(i, "BaseForaX", Base[id][BaseForaX]); // Float
            cache_get_value_name_float(i, "BaseForaY", Base[id][BaseForaY]); // Float
            cache_get_value_name_float(i, "BaseForaZ", Base[id][BaseForaZ]); // Float

            // Posição
            cache_get_value_name_float(i, "BaseX", Base[id][BaseX]); // Float
            cache_get_value_name_float(i, "BaseY", Base[id][BaseY]); // Float
            cache_get_value_name_float(i, "BaseZ", Base[id][BaseZ]); // Float
            cache_get_value_name_float(i, "BaseA", Base[id][BaseA]); // Float

            CarregarBase(id, true);
        }
    }
    print("[Rippzy:Base] Sistema de bases foi carregado com sucesso!");
    cache_delete(Conectar);


    // Carregar Veiculos Base
    print("[Rippzy:Base] Carregando sistema de veículos!");
    Conectar = mysql_query(IDConexao, "SELECT * FROM `baseveiculos`", true);
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Base] Não foi possivel carregar os veículos bases.");
        SendRconCommand("exit");
        return 1;
    }

    qpa = cache_num_rows();
    if(qpa > 0)
    {
        for(new i=0; i < qpa; i++)
        {
            cache_get_value_name_int(i, "BaseID", id);
            cache_get_value_name_int(i, "PosicaoID", idx);

            cache_get_value_name_int(i, "Modelo", vBase[id][idx][VeiculoModeloBase]);
            cache_get_value_name_int(i, "Conectado", vBase[id][idx][VeiculoColocado]);

            cache_get_value_name_int(i, "Cor1", vBase[id][idx][BaseCor1]);
            cache_get_value_name_int(i, "Cor2", vBase[id][idx][BaseCor2]);

            cache_get_value_name_float(i, "BaseX", vBase[id][idx][vBaseX]); // Float
            cache_get_value_name_float(i, "BaseY", vBase[id][idx][vBaseY]); // Float
            cache_get_value_name_float(i, "BaseZ", vBase[id][idx][vBaseZ]); // Float
            cache_get_value_name_float(i, "BaseA", vBase[id][idx][vBaseA]); // Float

            vBase[id][idx][SlotDataBase] = true; 
            if(vBase[id][idx][VeiculoColocado] == true && vBase[id][idx][VeiculoModeloBase] != 0)
            {
                vBase[id][idx][VeiculoBaseID] = CreateVehicleEx(-1, vBase[id][idx][VeiculoModeloBase], vBase[id][idx][vBaseX], vBase[id][idx][vBaseY], vBase[id][idx][vBaseZ], vBase[id][idx][vBaseA], vBase[id][idx][BaseCor1], vBase[id][idx][BaseCor2], -1, 0);
                format(VeiculoServer[vBase[id][idx][VeiculoBaseID]][LocalVerificacao], 90, "BaseVeiculoVeric");
            }
        }
    }
    print("[Rippzy:Base] Sistema de veículos foi carregado com sucesso!");

    CreateDynamicPickup(1239, 1, 2120.1702,-2273.7041,20.6719, -1, 14, -1, 120.0, -1);
    CreateDynamic3DTextLabel("Base\n{FFFFFF}Aperte {CCCCCC}'F'{FFFFFF} para sair", 0xFFA500FF, 2120.1702,-2273.7041,20.6719, 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, 14, -1, 16.0, -1);

    return 1;
}

CarregarBase(id, bool:stas = false)
{
    new Mensagem[250],
        Infc[2],
        type;

    if(Base[id][BaseVencimento] != 0)
    {
        Infc[0] = 61;
        Infc[1] = 1239;
        strcatEx(Mensagem, "{CCCCCC}%s\n", Base[id][BaseNome]);
        strcatEx(Mensagem, "{FFA500}Base ID: %d\n", id);
        strcatEx(Mensagem, "{FFA500}Fundador(a): %s\n", BaseFundador(id));
        strcatEx(Mensagem, "{FFA500}Membros: %d/%d\n", MembrosBase(id), MAX_MEMBROS);
        strcatEx(Mensagem, "{FFA500}%s\n", Base[id][BaseTag]);
        strcatEx(Mensagem, "%s\n", TrancaBase(id));
        strcat(Mensagem, "{1E90FF}/EntrarBase");
        type = 0;
    }
    else
    {
        Infc[0] = 62;
        Infc[1] = 1239;
        strcatEx(Mensagem, "{FFA500}Base ID: %d\n", id);
        strcatEx(Mensagem, "{FFFF00}$%s{FFFFFF} Coins\n", DinheiroSeparar(Base[id][BaseCoins]));
        if(Base[id][BaseDesconto] > 0) strcatEx(Mensagem, "{FFA500}Desconto de {FFFF00}$%s{FFA500} coins\n", DinheiroSeparar(Base[id][BaseDesconto]));
        strcat(Mensagem, "{1E90FF}/ComprarBase");
        type = 1;
    }

    Base[id][BaseColocada] = true;
    Base[id][BaseTexto] = CreateDynamic3DTextLabel(Mensagem, -1, Base[id][BaseX], Base[id][BaseY], Base[id][BaseZ], 16.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 20.0, -1);
    Base[id][BasePortaoID] = CreateDynamicObject(19912, Base[id][BasePortaoX], Base[id][BasePortaoY], Base[id][BasePortaoZ], Base[id][BasePortaoRX], Base[id][BasePortaoRY], Base[id][BasePortaoRZ], 0, 0, -1, 200.0, 210.0, -1);
    Base[id][BaseIcone] = CreateDynamicMapIcon(Base[id][BaseX], Base[id][BaseY], Base[id][BaseZ], Infc[0], -1, 0, 0, -1, 110.0, MAPICON_LOCAL, -1);
    Base[id][BasePickup] = CreateDynamicPickup(Infc[1], 1, Base[id][BaseX], Base[id][BaseY], Base[id][BaseZ], 0, 0, -1, 130.0, -1);
    Base[id][BaseArea] = CreateDynamicRectangle(Base[id][CimaX], Base[id][CimaY], Base[id][BaixoX], Base[id][BaixoY], 0, 0, -1);
    
    ColocarBaseObjeto(id);
    AdicionarMesaBase(id);

    if(stas == true)
    {
        switch(type)
        {
            case 0: AbrirPortaoBase(id, true, 500);
            case 1: AbrirPortaoBase(id, false);
        }
    }

    return 1;
}

hook OnPlayerResume(playerid)
{
    if(GetPVarInt(playerid, "BasePermADSA") != INVALID_STREAMER_ID) return 1;
    Streamer_Update(playerid, STREAMER_AREA_TYPE_RECTANGLE);
    return 1;
}

hook OnPlayerText(playerid, text[])
{
    if(strcmp(text, "!", true, 1)) return 1;
    new id = Jogador[playerid][BaseID];
    if(id < 1){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é membro(a) de uma base");
        return Y_HOOKS_BREAK_RETURN_0;   
    }
    if(Jogador[playerid][Mutado] > gettime()){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você foi mutado(a) pela administração, aguarde.");
        return Y_HOOKS_BREAK_RETURN_0;
    }

    if(GetPVarInt(playerid, "DelayBaseee") > gettime()){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
        return Y_HOOKS_BREAK_RETURN_0;
    }
    SetPVarInt(playerid, "DelayBaseee", gettime()+2);

    new Maksd[128],
        Mensagem[128];
    format(Maksd, 128, text);
    strdel(Maksd, 0, 1);

    format(Mensagem, sizeof(Mensagem), "| CHAT-BASE | [%s]%s[%d]: %s", CargoBase(bMembro[id][PosicaoBase(id, PegarNick(playerid))][BaseCargo]), PegarNick(playerid), playerid, Maksd);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][BaseID] != id && GetPVarInt(i, "AdminEspiarChatBase") != id) continue;
        SendClientMessage(i, 0xFFA500FF, Mensagem);
    }
    return Y_HOOKS_BREAK_RETURN_0;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 2120.1702,-2273.7041,20.6719) && Jogador[playerid][uInteriorEx] == 9)
        {
            cmd_sairbase(playerid);
            return 1;
        }
        for(new i=0; i < MAX_BASES; i++)
        {
            if(Base[i][BaseColocada] == false) continue;
            if(IsPlayerInRangeOfPoint(playerid, 2.0, Base[i][BaseX], Base[i][BaseY], Base[i][BaseZ])) return cmd_entrarbase(playerid);
        }
    }

    else if(newkeys == KEY_CTRL_BACK)
    {
        for(new i=0; i < MAX_BASES; i++)
        {
            if(!IsPlayerInRangeOfPoint(playerid, 13.0, Base[i][BasePortaoX], Base[i][BasePortaoY], Base[i][BasePortaoZ])) continue;
            if(Jogador[playerid][BaseID] != i && Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(Base[i][PortaoAberto] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | O portão já está aberto");
            AbrirPortaoBase(i);
            break;
        }
    }

    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(killerid == INVALID_PLAYER_ID) return 1;
    if(GetPVarInt(playerid, "BaseDMM") == 0) return 1;
    if(GetPVarInt(killerid, "BaseDMM") == 0) return 1;
    if(GetPVarInt(playerid, "BasePerm") != GetPVarInt(killerid, "BasePerm")) return 1;
    SetPVarInt(playerid, "VoltarBase", GetPVarInt(playerid, "BasePerm"));

    SetPVarInt(killerid, "KillsAren", GetPVarInt(killerid, "KillsAren")+1);
    if(GetPVarInt(killerid, "KillsAren") == 2) GameTextForPlayer(killerid, "~r~Double Kill", 3000, 4);
    else if(GetPVarInt(killerid, "KillsAren") == 3) GameTextForPlayer(killerid, "~r~Triple Kill", 3000, 4);
    else if(GetPVarInt(killerid, "KillsAren") >= 4) GameTextForPlayer(killerid, "~r~Chain Killer", 3000, 4);
    SetPVarInt(playerid, "KillsAren", 0);

    Jogador[killerid][VitimasBase]++;
    Jogador[playerid][MortesBase]++;
    AtualizarBaseVM(playerid);
    AtualizarBaseVM(killerid);
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(IsPlayerPaused(playerid)) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT && GetPlayerState(playerid) != PLAYER_STATE_PASSENGER && GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 1;
    for(new i=0; i < MAX_BASES; i++)
    {
        if(Base[i][BaseColocada] == false) continue;
        if(Base[i][BaseArea] != areaid) continue;
        if(strcmp(Base[i][BaseNome], "*") && Jogador[playerid][Admin] < 1)
        {
            if(Base[i][BaseInvasao] == false && Jogador[playerid][BaseID] != i)
            {
                SetPlayerPos(playerid, Base[i][BaseForaX], Base[i][BaseForaY], Base[i][BaseForaZ]);
                SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Você não tem permissão para entrar nessa base");
                return 1;
            }

            if(Jogador[playerid][Estrelas] > 0)
            {
                if(Base[i][BaseInvasao] == false){
                    SetPlayerPos(playerid, Base[i][BaseForaX], Base[i][BaseForaY], Base[i][BaseForaZ]);
                    SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Você está procurado(a), portanto não poderá entrar");
                    return 1;
                }
            }
        }

        MostrarBaseInfo(playerid);
        AtualizarBaseInfo(playerid, i);
        SetPVarInt(playerid, "BasePerm", i);
        SetPVarInt(playerid, "BasePermADSA", areaid);
    }
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{
    if(areaid != GetPVarInt(playerid, "BasePermADSA")) return 1;
    if(GetPVarInt(playerid, "BaseDMM") == 1) OcultarArenaKD(playerid); 

    SetPVarInt(playerid, "BasePerm", 0);
    SetPVarInt(playerid, "BaseInvasao", 0);
    SetPVarInt(playerid, "KillsAren", 0);
    SetPVarInt(playerid, "BaseDMM", 0);
    SetPVarInt(playerid, "BasePermADSA", INVALID_STREAMER_ID); 
    if(GetPVarInt(playerid, "RecebeuArmas") == 1)
    {
        ResetPlayerWeapons(playerid);
        SetPVarInt(playerid, "RecebeuArmas", 0);
    } 
    OcultarBaseInfo(playerid); 
    return 1;
}

CMD:entrarbase(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    for(new i=0; i < MAX_BASES; i++)
    {
        if(Base[i][BaseColocada] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, Base[i][BaseX], Base[i][BaseY], Base[i][BaseZ])) continue;
        EntrarBase(playerid, i);
    }
    return 1;
}

CMD:sairbase(playerid)
{
    if(cAC[playerid][Travado] == true) return 1;
    if(Jogador[playerid][uInteriorEx] != 9) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 8.0, 2120.1702,-2273.7041,20.6719)) return 1;

    Jogador[playerid][uInteriorEx] = 0;
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid,Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
    return 1;
}

Dialog:EscolherTagBase(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 6) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode colocar no máximo 6 caracteres");
    if(strlen(inputtext) < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Tem que ter no mínimo 3 caracteres");

    new id = GetPVarInt(playerid, "BaseCompraID");
    if(strcmp(Base[id][BaseNome], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa base já foi comprada");
    
    new VencimentoBaseEx = (gettime() + (30 * 86400));
    new BaseNNA[30],
        Enviar[258];
    GetPVarString(playerid, "NomeCompraBase", BaseNNA, 30);
    
    format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Vencimento` = %d, `Compra` = %d, `Nome` = '%s', `Tag` = '%s', `Senha` = '*', `TagCor` = %d WHERE `Numero` = %d", VencimentoBaseEx, gettime(), EscapeString(BaseNNA), EscapeString(inputtext), HexToInt("FFFFFFFF"), id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao comprar essa base");

    Jogador[playerid][Coins] -= Base[id][BaseCoins];
    format(Base[id][BaseNome], 30, BaseNNA);
    format(Base[id][BaseTag], 30, inputtext);
    Base[id][BaseVencimento] = VencimentoBaseEx;
    Base[id][BaseTagCor] = HexToInt("FFFFFFFF");
    Base[id][BaseCompra] = gettime();

    format(Enviar, sizeof(Enviar), "INSERT INTO `basemembros` (`Nome`, `BaseID`, `PosicaoID`, `Cargo`) VALUES ('%s', %d, %d, %d)", EscapeString(PegarNick(playerid)), id, 0, 2);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao adicionar você na base");
    
    bMembro[id][0][TemMembro] = true;
    bMembro[id][0][BaseCargo] = 2;
    format(bMembro[id][0][bNome], 30, PegarNick(playerid));
    Jogador[playerid][BaseID] = id;
    
    format(Enviar, sizeof(Enviar), "| BASE | Você comprou a base (ID: %d) por $%s coins", id, DinheiroSeparar(Base[id][BaseCoins]));
    SendClientMessage(playerid, 0xFFA500FF, Enviar);

    format(Enviar, sizeof(Enviar), "| BASE | Base registrada como: %s", BaseNNA);
    SendClientMessage(playerid, 0xFFA500FF, Enviar);

    AbrirPortaoBase(id, true, 500);

    AtualizarBase(id);
    return 1;
}

Dialog:EscolherNomeBase(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(CaracterEspecial(inputtext)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar caracteres especias");
    if(strlen(inputtext) > 24) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode colocar no máximo 24 caracteres");
    SetPVarString(playerid, "NomeCompraBase", inputtext);
    Dialog_Show(playerid, EscolherTagBase, DIALOG_STYLE_INPUT, "{FF0000}Tag", "Coloque abaixo a tag para sua base ( Máximo 6 caracteres )", "Confirmar", "Fechar");
    return 1;
}

CMD:comprarbase(playerid)
{
    if(Jogador[playerid][uInteriorEx] != 0) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;

    for(new i=0; i < MAX_BASES; i++)
    {
        if(Base[i][BaseColocada] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, Base[i][BaseX], Base[i][BaseY], Base[i][BaseZ])) continue;
        if(strcmp(Base[i][BaseNome], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode comprar essa base");
        if(Jogador[playerid][Coins] < Base[i][BaseCoins]-Base[i][BaseDesconto]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem coins sucifiente para comprar");
        SetPVarInt(playerid, "BaseCompraID", i);
        Dialog_Show(playerid, EscolherNomeBase, DIALOG_STYLE_INPUT, "{FF0000}Nome", "Coloque abaixo o nome para sua base", "Confirmar", "Fechar");
        break;
    }
    return 1;
}

function BaseVeiculoVeric(playerid, id)
{
    new Mensagem[98];
    for(new i=0; i < MAX_BASES; i++)
    {
        if(Base[i][BaseColocada] == false) continue;
        for(new d=0; d < MAX_BASEVEH; d++)
        {
            if(vBase[i][d][VeiculoColocado] == false) continue;
            if(vBase[i][d][VeiculoBaseID] != id) continue;
            if(Jogador[playerid][BaseID] == i) return true;
            format(Mensagem, sizeof(Mensagem), "| VEÍCULO | Você não pode entrar nesse veículo que pertence a base %s", Base[i][BaseNome]);
            SendClientMessage(playerid, 0xFF4500FF, Mensagem);
            return false;
        }
    }
    return true;
}

hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
    if(GetPVarInt(playerid, "BasePermADSA") == INVALID_STREAMER_ID) return 1;
    PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0); 
    return 1;
}