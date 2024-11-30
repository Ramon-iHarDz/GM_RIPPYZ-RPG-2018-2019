#include <YSI_Coding\y_hooks>
#define     MAX_PEGADIOS     (10)

enum PedagioInfo
{
    bool:Colocado,
    bool:PedagioAberto,

    // Pedagio
    Float:PedagioX,
    Float:PedagioY,
    Float:PedagioZ,
    Text3D:PedagioTexto,
    PedagioPreco,
    PedagioObjeto,

    // Objeto Pedagio
    Float:ObjetoPedagioX,
    Float:ObjetoPedagioY,
    Float:ObjetoPedagioZ,

    Float:ObjetoPedagioRX,
    Float:ObjetoPedagioRY,
    Float:ObjetoPedagioRZ

};
new Pedagio[MAX_PEGADIOS][PedagioInfo];

hook OnGameModeInit()
{
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "PedagioStt") == 1) DestroyDynamicObject(GetPVarInt(playerid, "PedagioID"));
    return 1;
}

stock AdicionarPedagio(id)
{
    Pedagio[id][PedagioObjeto] = CreateDynamicObject(971, Pedagio[id][ObjetoPedagioX], Pedagio[id][ObjetoPedagioY], Pedagio[id][ObjetoPedagioZ], Pedagio[id][ObjetoPedagioRX], Pedagio[id][ObjetoPedagioRY], Pedagio[id][ObjetoPedagioRZ], 0, 0, -1, 300.0, 300.0, -1);
    Pedagio[id][PedagioTexto] = CreateDynamic3DTextLabel("Pedágio\n{FFFFFF}Use o comando {FFA500}/PegarPedagio{FFFFFF} para pagar", 0x32CD32FF, Pedagio[id][PedagioX], Pedagio[id][PedagioY], Pedagio[id][PedagioZ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    Pedagio[id][Colocado] = true;
    return 1;
}

stock GetPedagio()
{
    for(new i=0; i < MAX_PEGADIOS; i++){
        if(Pedagio[i][Colocado] == true) continue;
        return i;
    }
    return false;
}

function FecharPedagio(id)
{
    MoveDynamicObject(Pedagio[id][PedagioObjeto], Pedagio[id][ObjetoPedagioX], Pedagio[id][ObjetoPedagioY], Pedagio[id][ObjetoPedagioZ], 3.0);
    Pedagio[id][PedagioAberto] = false;
    return 1;
}

hook OnPlayerEditDynObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(GetPVarInt(playerid, "PedagioStt") == 0) return 1;
    switch(response)
    {
        case EDIT_RESPONSE_CANCEL:
        {
            SetPVarInt(playerid, "PedagioStt", 0);
            DestroyDynamicObject(objectid);
        }
        case EDIT_RESPONSE_FINAL:
        {
            SetPVarInt(playerid, "PedagioStt", 0);
            DestroyDynamicObject(objectid);

            SetPVarFloat(playerid, "PX", x);
            SetPVarFloat(playerid, "PY", y);
            SetPVarFloat(playerid, "PZ", z);

            SetPVarFloat(playerid, "PRX", rx);
            SetPVarFloat(playerid, "PRY", ry);
            SetPVarFloat(playerid, "PRZ", rz);
        }
    }
    return 1;
}

CMD:pagarpedagio(playerid)
{
    if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
    for(new i=0; i < MAX_PEGADIOS; i++)
    {
        if(Pedagio[i][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 8.0, Pedagio[i][PedagioX], Pedagio[i][PedagioY], Pedagio[i][PedagioZ])) continue;
        if(Pedagio[i][PedagioAberto] == true) return 1;
        if(Jogador[playerid][Dinheiro] < Pedagio[i][PedagioPreco]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
        Jogador[playerid][Dinheiro] -= Pedagio[i][PedagioPreco];
        Pedagio[i][PedagioAberto] = true;

        MoveDynamicObject(Pedagio[i][PedagioObjeto], Pedagio[i][ObjetoPedagioX], Pedagio[i][ObjetoPedagioY], Pedagio[i][ObjetoPedagioZ]-1.2, 3.0);

        new Mensagem[45];
        format(Mensagem, sizeof(Mensagem), "| PEDAGIO | Você pagou $%s pelo pedagio", DinheiroSeparar(Pedagio[i][PedagioPreco]));
        SendClientMessage(playerid, 0x32CD32FF, Mensagem);

        SetTimerEx("FecharPedagio", 4000, false, "d", i);
        break;
    }
    return 1;
}

Dialog:PedagioAdmin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new Float:Nop[3];
    GetPlayerPos(playerid, Nop[0], Nop[1], Nop[2]);
    switch(listitem)
    {
        case 0:
        {
            SetPVarFloat(playerid, "PedagioX", Nop[0]);
            SetPVarFloat(playerid, "PedagioY", Nop[1]);
            SetPVarFloat(playerid, "PedagioZ", Nop[2]);
        }
        case 1:
        {
            new id;
            SetPVarInt(playerid, "PedagioStt", 1);
            id = CreateDynamicObject(971, Nop[0], Nop[1], Nop[2], 0.0, 0.0, 0.0, 0, 0, -1, 90.0, 90.0, -1);
            SetPVarInt(playerid, "PedagioID", id);
            EditDynamicObject(playerid, id);
        }
        case 2:
        {
            new id = GetPedagio(),
                Enviar[300];
            format(Enviar, sizeof(Enviar), "INSERT INTO `Pedagio` (`PosicaoX`, `PosicaoY`, `PosicaoZ`, `ObjetoPosicaoX`, `ObjetoPosicaoY`, `ObjetoPosicaoZ`, `ObjetoPosicaoRX`, `ObjetoPosicaoRY`, `ObjetoPosicaoRZ`) VALUES (%f, %f, %f, %f, %f, %f, %f, %f, %f)", GetPVarFloat(playerid, "PedagioX"), GetPVarFloat(playerid, "PedagioY"), GetPVarFloat(playerid, "PedagioZ"), GetPVarFloat(playerid, "PX"), GetPVarFloat(playerid, "PY"), GetPVarFloat(playerid, "PZ"), GetPVarFloat(playerid, "PRX"), GetPVarFloat(playerid, "PRY"), GetPVarFloat(playerid, "PRZ"));
            mysql_query(IDConexao, Enviar, false);

            Pedagio[id][PedagioX] = GetPVarFloat(playerid, "PedagioX");
            Pedagio[id][PedagioY] = GetPVarFloat(playerid, "PedagioY");
            Pedagio[id][PedagioZ] = GetPVarFloat(playerid, "PedagioZ");

            Pedagio[id][ObjetoPedagioX] = GetPVarFloat(playerid, "PX");
            Pedagio[id][ObjetoPedagioY] = GetPVarFloat(playerid, "PY");
            Pedagio[id][ObjetoPedagioZ] = GetPVarFloat(playerid, "PZ");

            Pedagio[id][ObjetoPedagioRX] = GetPVarFloat(playerid, "PRX");
            Pedagio[id][ObjetoPedagioRY] = GetPVarFloat(playerid, "PRY");
            Pedagio[id][ObjetoPedagioRZ] = GetPVarFloat(playerid, "PRZ");
            AdicionarPedagio(id);
        }
    }

    return 1;
}

CMD:criarpedagio(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 1;

    new Dialog[90];
    strcat(Dialog, "Posicao Pagar\n");
    strcat(Dialog, "Posicao Portao\n");
    strcat(Dialog, "Criar Pedagio");
    Dialog_Show(playerid, PedagioAdmin, DIALOG_STYLE_TABLIST, "Criar Pedagio", Dialog, "Selecionar", "Fechar");
    return 1;
}