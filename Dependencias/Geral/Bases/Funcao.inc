enum MesasBase
{
    Float:bMesaX,
    Float:bMesaY,
    Float:bMesaZ,
    Float:bMesaRX,
    Float:bMesaRY,
    Float:bMesaRZ,
    Text3D:bMesaTexto,
    bool:bMesaUsado,
    bool:bMesaSpawn,
    mMesaID
};

new MesaBase[][MesasBase] =
{
    {2161.84082, -2259.64258, 12.72490,   0.00000, 0.00000, 45.00000},
    {2159.35034, -2262.09058, 12.72490,   0.00000, 0.00000, 45.00000},
    {2164.31494, -2257.18359, 12.72490,   0.00000, 0.00000, 45.00000},
    {2166.84839, -2254.73218, 12.72490,   0.00000, 0.00000, 45.00000},
    {2160.76318, -2248.94580, 12.72490,   0.00000, 0.00000, 45.00000},
    {2158.28760, -2251.32715, 12.72490,   0.00000, 0.00000, 45.00000},
    {2155.85620, -2253.77881, 12.72490,   0.00000, 0.00000, 45.00000},
    {2153.49268, -2256.07324, 12.72490,   0.00000, 0.00000, 45.00000}
};
new mBase[MAX_BASES][sizeof(MesaBase)][MesasBase];

stock AdicionarMesaBase(id)
{
    new Mensagem[90];
    for(new i=0; i < sizeof(MesaBase); i++)
    {
        if(mBase[id][i][bMesaSpawn] == true) continue;
        mBase[id][i][mMesaID] = CreateDynamicObject(941, MesaBase[i][bMesaX], MesaBase[i][bMesaY], MesaBase[i][bMesaZ], MesaBase[i][bMesaRX], MesaBase[i][bMesaRY], MesaBase[i][bMesaRZ], BaseVw(id), 0, -1, 160.0, 160.0, -1);
        format(Mensagem, sizeof(Mensagem), "Base Produção ({FFA500}ID: %d{FFFFFF})\nAperte {CCCCCC}'Y'{FFFFFF} para produzir", i+1);
        mBase[id][i][bMesaTexto] = CreateDynamic3DTextLabel(Mensagem, -1, MesaBase[i][bMesaX], MesaBase[i][bMesaY], MesaBase[i][bMesaZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BaseVw(id), 0, -1, 11.0, -1);
        mBase[id][i][bMesaSpawn] = true;
    }
    return 1;
}

stock RemoverMesaBase(id)
{
    for(new i=0; i < sizeof(MesaBase); i++)
    {
        if(mBase[id][i][bMesaSpawn] == false) continue;
        DestroyDynamicObjectEx(mBase[id][i][mMesaID]);
        DestroyDynamic3DTextLabelEx(mBase[id][i][bMesaTexto]);
        mBase[id][i][bMesaSpawn] = false;
    } 
    return 1;
}

stock GerarVencimento(dias)
{
    new DateBT = (gettime()+ (dias * 86400));
    return DateBT;
}

stock TrancaBase(id)
{
    new msggg[39];
    switch(Base[id][BaseStatus])
    {
        case 0: msggg = "{FFFFFF}Destrancada";
        case 1: msggg = "{FF0000}Trancada{FFFFFF}";
        case 2: msggg = "{FF0000}Trancada com Senha{FFFFFF}";
    }
    return (msggg);
}

stock CargoBase(id)
{
    new AinFds[15];
    switch(id)
    {
        case 0: AinFds = "Membro";
        case 1: AinFds = "Lider";
        case 2: AinFds = "Fundador(a)";
    }
    return (AinFds);
}

stock PosicaoBase(id, const NickBB[])
{
    for(new i=0; i < MAX_MEMBROS; i++)
    {
        if(bMembro[id][i][TemMembro] == false) continue;
        if(strcmp(bMembro[id][i][bNome], NickBB)) continue;
        return i;
    }
    return 1;
}

stock BasePermissao(id, const NickBB[])
{
    if(Jogador[PegarIdPeloNick(NickBB)][Admin] >= 4){
        return 2;
    }
    for(new i=0; i < MAX_MEMBROS; i++)
    {
        if(bMembro[id][i][TemMembro] == false) continue;
        if(strcmp(bMembro[id][i][bNome], NickBB)) continue;
        return bMembro[id][i][BaseCargo];
    }
    return -1;
}

stock vMembroBase(const Nicnbb[], id)
{
    if(Base[id][BaseColocada] == false) return false;
    for(new i=0; i < MAX_MEMBROS; i++) 
    {
        if(bMembro[id][i][TemMembro] == false) continue;
        if(strcmp(bMembro[id][i][bNome], Nicnbb)) continue; 
        return true;
    }
    return false;   
}

stock DarArmaBase(playerid)
{
    GivePlayerWeapon(playerid, 26, 250);
    // GivePlayerWeapon(playerid, 31, 800);
    GivePlayerWeapon(playerid, 24, 100);
    GivePlayerWeapon(playerid, 28, 900);
    SendClientMessage(playerid, 0xFFA500FF, "| BASE | Você recebeu as armas free da base");
    return 1;
}

stock RespawnBase(playerid)
{
    new id = GetPVarInt(playerid, "VoltarBase");
    if(Base[id][BaseArma] == true && Base[id][BaseDM] == true)
    {
        SetPVarInt(playerid, "RecebeuArmas", 1);
        DarArmaBase(playerid);
    }
    if(Jogador[playerid][BaseID] == id) SetPlayerPos(playerid, Base[id][BaseX], Base[id][BaseY], Base[id][BaseZ]);
    else Hospital(2, playerid);
    SetPVarInt(playerid, "VoltarBase", 0);
    return 1;
}

stock PegarBaseID()
{
    for(new i=1; i < MAX_BASES; i++)
    {
        if(Base[i][BaseColocada] == true) continue;
        return i;
    }
    return -1;
}

stock VeiculoBaseEspaco(id)
{
    for(new i=0; i < MAX_BASEVEH; i++)
    {
        if(vBase[id][i][VeiculoModeloBase] != 0) continue;
        return i;
    }
    return -1;
}

stock StatusInvasao(id, bool:textdr = false)
{
    new Mensagem[25];
    if(textdr == true){
        if(Base[id][BaseInvasao] == true) Mensagem = "Invasão: ~r~Liberada~w~";
    }else{
        if(Base[id][BaseInvasao] == true) Mensagem = "{7FFF00}Ativado";
        else Mensagem = "{ff2d19}Desativado";
    }
    return(Mensagem);
}

stock StatusDM(id, bool:textdr = false)
{
    new Mensagem[25];
    if(textdr == true){
        if(Base[id][BaseDM] == true) Mensagem = "DM: ~r~Liberado~w~";
    }else{
        if(Base[id][BaseDM] == true) Mensagem = "{7FFF00}Ativado";
        else Mensagem = "{ff2d19}Desativado";
    }
    return(Mensagem);
}

stock StatusArmas(id)
{
    new dasdsa[20];
    if(Base[id][BaseArma] == true) dasdsa = "{7FFF00}Ativado";
    else dasdsa = "{ff2d19}Desativado";
    return (dasdsa);
}

stock AtualizarBaseInfo(playerid, id)
{
    new Mensagem[100],
        Inac[40],
        ccas,
        NameBS[30];

    if(!strcmp(Base[id][BaseNome], "*")) NameBS = "N/A";
    else format(NameBS, 30, Base[id][BaseNome]);

    // Invasao: Liberada / DM: Liberado
    format(Mensagem, sizeof(Mensagem), "Base %s (ID:%d) [", NameBS, id);
    format(Inac, 40, StatusInvasao(id, true));
    if(!isnull(Inac)){
        ccas++;
        strcatEx(Mensagem, "%s", Inac);
    }
    format(Inac, 40, StatusDM(id, true));
    if(!isnull(Inac)){
        if(ccas > 0) strcatEx(Mensagem, " / %s", Inac);
        else strcatEx(Mensagem, "%s", Inac);
        ccas++;
    }
    if(ccas == 0) strcat(Mensagem, "N/A");
    if(Base[id][BaseDM] == true && GetPVarInt(playerid, "BaseDMM") == 0){
        MostrarArenaKD(playerid, " Base");
        AtualizarBaseVM(playerid);
        SetPVarInt(playerid, "BaseDMM", 1);
    }else if(Base[id][BaseDM] == false && GetPVarInt(playerid, "BaseDMM") == 1){
        OcultarBaseInfo(playerid);
        SetPVarInt(playerid, "BaseDMM", 0);
    }

    if(Base[id][BaseInvasao] == false && GetPVarInt(playerid, "BaseInvasao") == 1 && Jogador[playerid][BaseID] != id)
    {
        SetPVarInt(playerid, "BaseInvasao", 0);
        SetPlayerPos(playerid, Base[id][BaseForaX], Base[id][BaseForaY], Base[id][BaseForaZ]);
        SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Você foi retirado(a) da base");
    }
    else if(Base[id][BaseInvasao] == true && GetPVarInt(playerid, "BaseInvasao") == 0) SetPVarInt(playerid, "BaseInvasao", 1);

    if(GetPVarInt(playerid, "RecebeuArmas") == 1 && Base[id][BaseDM] == false){
        ResetPlayerWeapons(playerid);
        SetPVarInt(playerid, "RecebeuArmas", 0);
    }
    else if(GetPVarInt(playerid, "RecebeuArmas") == 0 && Base[id][BaseDM] == true && Base[id][BaseArma] == true){
        DarArmaBase(playerid);
        SetPVarInt(playerid, "RecebeuArmas", 1);
    }

    strcat(Mensagem, "]");
    PlayerTextDrawSetString(playerid, BaseIf[playerid][0], ConverterTexto(Mensagem));
    return 1;
}

stock AtualizarBaseVM(playerid)
{
    new Mensagem[90];
    format(Mensagem, sizeof(Mensagem), "%s", DinheiroSeparar(Jogador[playerid][VitimasBase]));
    PlayerTextDrawSetString(playerid, ArenaKD[playerid][6], ConverterTexto(Mensagem)); 
    format(Mensagem, sizeof(Mensagem), "%s", DinheiroSeparar(Jogador[playerid][MortesBase]));
    PlayerTextDrawSetString(playerid, ArenaKD[playerid][7], ConverterTexto(Mensagem));
    return 1;
}

stock AtualizarInfoBase(id)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "BasePerm") != id) continue;
        AtualizarBaseInfo(i, id);
    }
    return 1;
}

stock MembrosBase(id)
{
    new ddd;
    for(new i=0; i < MAX_MEMBROS; i++)
    {
        if(bMembro[id][i][TemMembro] == false) continue;
        ddd++;
    }
    return ddd;
}

stock VeiculosBase(id)
{
    new ddd;
    for(new i=0; i < MAX_BASEVEH; i++)
    {
        if(vBase[id][i][SlotDataBase] == false) continue;
        if(vBase[id][i][VeiculoModeloBase] == 0) continue;
        ddd++;
    }
    return ddd;
}

stock BaseFundador(id)
{
    new Fkas[30];
    for(new i=0; i < MAX_MEMBROS; i++)
    {
        if(bMembro[id][i][TemMembro] == false) continue;
        if(bMembro[id][i][BaseCargo] != 2) continue;
        format(Fkas, 30, bMembro[id][i][bNome]);
        break;
    }
    return Fkas;
}

function TrazerPortaoBase(id)
{
    Base[id][PortaoAberto] = false;
    if(Base[id][TrazerPortao] == true) Base[id][TrazerPortao] = false;
    MoveDynamicObject(Base[id][BasePortaoID], Base[id][BasePortaoX], Base[id][BasePortaoY], Base[id][BasePortaoZ], 2.0);
    return 1;
}

stock AbrirPortaoBase(id, bool:FecharNovamente = true, Seggg = 8000)
{
    Base[id][PortaoAberto] = true;
    if(Base[id][TrazerPortao] == true) KillTimer(Base[id][TimerPortao]);
    if(FecharNovamente == true){
        Base[id][TrazerPortao] = true;
        Base[id][TimerPortao] = SetTimerEx("TrazerPortaoBase", Seggg, false, "d", id);
    }
    MoveDynamicObject(Base[id][BasePortaoID], Base[id][BasePortaoX], Base[id][BasePortaoY], Base[id][BasePortaoZ]-6.0, 2.0);
    return 1;
}

/*stock PortaoBase(id)
{
    if(!strcmp(Base[id][BaseNome], "*")) MoveDynamicObject(Base[id][BasePortaoID], Float:x, Float:y, Float:z, 1.5);
    return 1;
}*/

stock AtualizarBase(id)
{
    DestroyDynamic3DTextLabelEx(Base[id][BaseTexto]);
    DestroyDynamicObjectEx(Base[id][BasePortaoID]);
    DestroyDynamicMapIconEx(Base[id][BaseIcone]);
    DestroyDynamicPickupEx(Base[id][BasePickup]);
    DestroyDynamicAreaEx(Base[id][BaseArea]);
    CarregarBase(id);
    return 1;
}

stock EntrarBase(playerid, id) // REVISAR
{
    // if(pMorreu[playerid][EstaCaido] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está ferido(a)");

    //Setar algumas informações
    Jogador[playerid][uInteriorEx] = 9;
    GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
    SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);
    SetPVarInt(playerid, "InteriorPersonalizadoID", id);

    new vw = id;
    vw++;
    vw = (vw*vw);

    //Setando dentro da base
    TogglePlayerControllable(playerid, 0);
    SetPlayerVirtualWorld(playerid, vw);
    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, 2120.1702,-2273.7041,20.6719);
    SetTimerEx("Destravar", 3000, false, "d", playerid);
    return 1;
}

stock BaseVw(id)
{
    new vw = id;
    vw++;
    vw = (vw*vw);
    return vw;
}

stock RemoverBaseInfo(id)
{
    if(Base[id][TrazerPortao] == true) KillTimer(Base[id][TimerPortao]);
    DestroyDynamic3DTextLabelEx(Base[id][BaseTexto]);
    DestroyDynamicObjectEx(Base[id][BasePortaoID]);
    DestroyDynamicMapIconEx(Base[id][BaseIcone]);
    DestroyDynamicPickupEx(Base[id][BasePickup]);
    DestroyDynamicAreaEx(Base[id][BaseArea]);
    RemoverMesaBase(id);
    RemoverObjetoBase(id);
    SqlRemoverBase(id, true);

    for(new i=0; i < MAX_BASEVEH; i++){
        if(vBase[id][i][VeiculoColocado] == true) DestroyVehicleEx(vBase[id][i][VeiculoBaseID]);
        new Fdsc[BaseVeiculo];
        vBase[id][i] = Fdsc;
    }

    for(new i=0; i < MAX_MEMBROS; i++){
        new Fdsc[MembroBase];
        bMembro[id][i] = Fdsc;
    }

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][BaseID] != id) continue;
        Jogador[i][BaseID] = 0;
    }

    new asdas[BaseInfo];
    Base[id] = asdas;
    return 1;
}

stock LimparBaseInfo(id)
{
    for(new i=0; i < MAX_BASEVEH; i++){
        if(vBase[id][i][VeiculoColocado] == true) DestroyVehicleEx(vBase[id][i][VeiculoBaseID]);
        vBase[id][i][VeiculoColocado] = false;
        vBase[id][i][BaseCor1] = 0;
        vBase[id][i][BaseCor2] = 0;
        vBase[id][i][VeiculoModeloBase] = 0;
    }

    for(new i=0; i < MAX_MEMBROS; i++){
        new Fdsc[MembroBase];
        bMembro[id][i] = Fdsc;
    }

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][BaseID] != id) continue;
        Jogador[i][BaseID] = 0;
    }

    Base[id][BaseDM] = false;
    Base[id][BaseInvasao] = false;
    Base[id][BaseArma] = false;
    format(Base[id][BaseNome], 30, "*");
    stringclear(Base[id][BaseTag]);
    Base[id][BaseTagCor] = HexToInt("FFFFFFFF");
    Base[id][BaseCofre] = 0;
    Base[id][BaseVencimento] = 0;
    Base[id][BaseStatus] = 0;
    Base[id][BaseDesconto] = 0;
    AbrirPortaoBase(id, false);
    return 1;
}

stock PrecisaRenovar(id, d)
{
    new dat = Base[id][BaseVencimento];
    dat -= (d*86400);
    if(gettime() > dat) return true;
    return false;
}

stock SqlRemoverBase(i, bool:any = false)
{
    new Enviar[300];
    format(Enviar, sizeof(Enviar), "DELETE FROM `basemembros` WHERE `BaseID` = %d", i);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) printf("[Rippzy:Base] Houve um erro ao remover os membros (ID: %d)", i);

    if(any == true)
    {
        format(Enviar, sizeof(Enviar), "DELETE FROM `baseveiculos` WHERE `BaseID` = %d", i);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) printf("[Rippzy:Base] Houve um erro ao remover os veículos (ID: %d)", i);

        format(Enviar, sizeof(Enviar), "DELETE FROM `bases` WHERE `Numero` = %d", i);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) printf("[Rippzy:Base] Houve um erro ao remover base (ID: %d)", i);
    }
    else
    {
        format(Enviar, sizeof(Enviar), "UPDATE `baseveiculos` SET `Modelo` = 0, `Cor1` = 0, `Cor2` = 0, `Conectado` = 0 WHERE `BaseID` = %d", i);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) printf("[Rippzy:Base] Houve um erro ao atualizar os veículos (ID: %d)", i);

        format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Vencimento` = 0, `Desconto` = 0, `Cofre` = 0, `Invasao` = 0, `DM` = 0, `Status` = 0, `Nome` = '*', `TagCor` = %d, `Senha` = '*' WHERE `Numero` = %d", HexToInt("FFFFFFFF"), i);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) printf("[Rippzy:Base] Houve um erro ao liberar base (ID: %d)", i);
    }
    return 1;
}

stock ReiniciarBase()
{
    print("[Rippzy:Base] Salvando Base.");
    for(new i=0; i < MAX_BASES; i++)
    {
        if(Base[i][BaseColocada] == false) continue;
        if(!strcmp(Base[i][BaseNome], "*")) continue;
        if(gettime() > Base[i][BaseVencimento]) SqlRemoverBase(i);
    }
    print("[Rippzy:Base] Bases salvas com sucesso.");
    return 1;
} 