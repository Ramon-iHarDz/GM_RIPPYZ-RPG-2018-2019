#include <YSI_Coding\y_hooks>

enum JogadorBaseProd
{
    BaseProd,
    DrogaObjeto,
    BaseCp,
    BaseMap
};
new sBase[MAX_PLAYERS][JogadorBaseProd];

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(Jogador[playerid][uInteriorEx] != 9) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");

    for(new i=0; i < sizeof(MesaBase); i++)
    {
        if(mBase[id][i][bMesaSpawn] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, MesaBase[i][bMesaX], MesaBase[i][bMesaY], MesaBase[i][bMesaZ])) continue;
        if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != BaseVw(id)) return 1;
        if(sBase[playerid][BaseProd] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está fazendo esse processo");
        if(!vMembroBase(PegarNick(playerid), Jogador[playerid][BaseID])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não faz parte dessa base");
        if(mBase[id][i][bMesaUsado] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar essa mesa");
        if(pTempo[playerid][HobbieProdutor] > gettime()){
            new Mensagem[59];
            format(Mensagem, sizeof(Mensagem), "| ERRO | Você só pode produzir novamente em %s", ConverterSegundos(pTempo[playerid][HobbieProdutor]));
            SendClientMessage(playerid, 0xFF4500FF, Mensagem);
            return 1;
        }

        SetPVarInt(playerid, "BaseMesa", id);
        SetPVarInt(playerid, "BaseMesaID", i);

        new Dialog[40];
        strcat(Dialog, "Droga Leve\n");
        strcat(Dialog, "Droga Média\n");
        strcat(Dialog, "Droga Pesada");
        Dialog_Show(playerid, "BaseDrogaMenu", DIALOG_STYLE_TABLIST, "{FF0000}Drogas", Dialog, "Selecionar", "Fechar");
        break;
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(sBase[playerid][BaseProd] == 1)
    {
        new id = GetPVarInt(playerid, "BaseMesa"),
            idx = GetPVarInt(playerid, "BaseMesaID");
        RegenerarMesaBasE(id, idx);
    }
    DestroyDynamicObjectEx(sBase[playerid][DrogaObjeto]);
    DestroyDynamicCPEx(sBase[playerid][BaseCp]);
    DestroyDynamicMapIconEx(sBase[playerid][BaseMap]);

    new alsd[JogadorBaseProd];
    sBase[playerid] = alsd;
    return 1;
}

Dialog:BaseDrogaMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new id = GetPVarInt(playerid, "BaseMesa"),
        idx = GetPVarInt(playerid, "BaseMesaID"),
        DrogaModel,
        Mensagem[90];

    SetPVarInt(playerid, "DrogaEstiloBase", listitem);
    sBase[playerid][BaseProd] = 1;

    format(Mensagem, sizeof(Mensagem), "Base Produção ({FFA500}ID: %d{FFFFFF})\nSendo utilizada por {FFA500}%s[%d]", id+1, PegarNick(playerid), playerid);
    UpdateDynamic3DTextLabelText(mBase[id][idx][bMesaTexto], -1, Mensagem);

    switch(listitem)
    {
        case 0: DrogaModel = 1578;
        case 1: DrogaModel = 1575;
        case 2: DrogaModel = 1580;
    }
    sBase[playerid][DrogaObjeto] = CreateDynamicObject(DrogaModel, MesaBase[idx][bMesaX], MesaBase[idx][bMesaY], MesaBase[idx][bMesaZ]+0.5, 0.0, 0.0, float(random(360)), BaseVw(id), 0, -1, 120.0, 120.0, -1);
    switch(listitem)
    {
        case 0: CriarProgresso(playerid, "Produzindo Droga Leve", "DrogaFeitaBase", 1*1000); 
        case 1: CriarProgresso(playerid, "Produzindo Droga Media", "DrogaFeitaBase", 3*1000);
        case 2: CriarProgresso(playerid, "Produzindo Droga Pesada", "DrogaFeitaBase", 4*1000);
    }
    TogglePlayerControllable(playerid, 0);
    return 1;
}

stock RegenerarMesaBasE(id, idx)
{
    new Mensagem[85];
    format(Mensagem, sizeof(Mensagem), "Base Produção ({FFA500}ID: %d{FFFFFF})\nAperte {CCCCCC}'Y'{FFFFFF} para produzir", id+1);
    UpdateDynamic3DTextLabelText(mBase[id][idx][bMesaTexto], -1, Mensagem);
    mBase[id][idx][bMesaUsado] = false;
    return 1;
}

function DrogaFeitaBase(playerid)
{
    TogglePlayerControllable(playerid, 1);
    DestroyDynamicObjectEx(sBase[playerid][DrogaObjeto]);
    Jogador[playerid][Estrelas] += 8;
    sBase[playerid][BaseProd] = 2;
    new id = GetPVarInt(playerid, "BaseMesa"),
        idx = GetPVarInt(playerid, "BaseMesaID");
    RegenerarMesaBasE(id, idx);
    sBase[playerid][BaseCp] = CreateDynamicCP(-1835.1647,1429.0175,7.1875, 1.0, 0, 0, playerid, 30.0, -1);
    sBase[playerid][BaseMap] = CreateDynamicMapIcon(-1835.1647,1429.0175,7.1875, 19, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
    SendClientMessage(playerid, -1, "| BASE | Você precisa ir até {e2b960}San Fierro{FFFFFF} para entregar o malote com drogas");
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != sBase[playerid][BaseCp]) return 1;
    DestroyDynamicCPEx(sBase[playerid][BaseCp]);
    DestroyDynamicMapIconEx(sBase[playerid][BaseMap]);
    sBase[playerid][BaseProd] = 0;
    new id = GetPVarInt(playerid, "BaseMesa"),
        i,
        Ganxo,
        Enviar[650];
    i = PosicaoBase(id, PegarNick(playerid));

    switch(GetPVarInt(playerid, "DrogaEstiloBase"))
    {
        case 0: Ganxo = random(2000-1000)+1000;
        case 1: Ganxo = random(4000-3000)+3000;
        case 2: Ganxo = random(7000-6000)+6000;
    }

    new SimBase = Base[id][BaseCofre],
        SimMembro = bMembro[id][i][BaseDeposito];
    SimBase += Ganxo;
    SimMembro += Ganxo;

    strcatEx(Enviar, "UPDATE `bases` SET `Cofre` = %d, `Entregas` = %d WHERE `Numero` = %d; ", SimBase, Base[id][BaseEntregasGeral]+1, id);
    strcatEx(Enviar, "UPDATE `basemembros` SET `Deposito` = %d, `Entregas` = %d WHERE `BaseID` = %d AND `PosicaoID` = %d", SimMembro, bMembro[id][i][BaseEntregas]+1, id, i);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao efetuar a entrega");

    new ffc = Ganxo;
    new prct = (ffc * 65) / 100;
    Ganxo -= prct;

    Jogador[playerid][Dinheiro] += prct;
    Base[id][BaseCofre] += Ganxo;
    bMembro[id][i][BaseEntregas]++;
    Base[id][BaseEntregasGeral]++;
    pTempo[playerid][HobbieProdutor] = gettime()+(2*3600);

    format(Enviar, sizeof(Enviar), "| BASE | Você entregou as drogas em {e2b960}San Fierro{FFFFFF} e recebeu {32CD32}%s{FFFFFF} e sua base recebeu {32CD32}$%s", DinheiroSeparar(prct), DinheiroSeparar(Ganxo));
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}