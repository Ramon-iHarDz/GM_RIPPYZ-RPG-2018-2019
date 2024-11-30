#include <YSI_Coding\y_hooks>

#define MAX_AOBJETOS 500

enum ObjetoPlayer
{
    bool:bObjeto,
    Text3D:TextoAID,
    ObjetoAID
};

new mPObjeto[MAX_PLAYERS][MAX_AOBJETOS][ObjetoPlayer];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < MAX_AOBJETOS; i++)
    {
        if(mPObjeto[playerid][i][bObjeto] == false) continue;
        mPObjeto[playerid][i][bObjeto] = false;
        DestroyDynamic3DTextLabelEx(mPObjeto[playerid][i][TextoAID]);
        DestroyDynamicObjectEx(mPObjeto[playerid][i][ObjetoAID]);
    }
    return 1;
}

hook OnPlayerEditDynObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(GetPVarInt(playerid, "AdicionandoObjets") == 0) return 1;
    new
        Float: oldX,
        Float: oldY,
        Float: oldZ,
        Float: oldRotX,
        Float: oldRotY,
        Float: oldRotZ;

    GetDynamicObjectPos(objectid, oldX, oldY, oldZ);
    GetDynamicObjectRot(objectid, oldRotX, oldRotY, oldRotZ);
    switch(response)
    {
        case EDIT_RESPONSE_FINAL:
        {
            SetPVarInt(playerid, "AdicionandoObjets", 0);
            new i = GetPVarInt(playerid, "aAmidnsObjeto"),
                Mensagem[10];
            format(Mensagem, sizeof(Mensagem), "Objeto[%d]", i);
            DestroyDynamic3DTextLabelEx(mPObjeto[playerid][i][TextoAID]);
            mPObjeto[playerid][i][TextoAID] = CreateDynamic3DTextLabel(Mensagem, 0x00BFFFFF, x, y, z, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), playerid, 15.0, -1);
            SetDynamicObjectPos(objectid, x, y, z);
            SetDynamicObjectRot(objectid, rx, ry, rz);
        }
        case EDIT_RESPONSE_CANCEL:
        {
            SetDynamicObjectPos(objectid, oldX, oldY, oldZ);
            SetDynamicObjectRot(objectid, oldRotX, oldRotY, oldRotZ);
            SetPVarInt(playerid, "AdicionandoObjets", 0);
        }
    }

    return 1;
}

stock GerarObjetoID(playerid)
{
    for(new i=0; i < MAX_AOBJETOS; i++)
    {
        if(mPObjeto[playerid][i][bObjeto] == true) continue;
        return i;   
    }
    return -1;
}

CMD:removerobjeto(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /RemoverObjeto [Objeto-ID]");
    if(mPObjeto[playerid][id][bObjeto] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhum objeto com esse ID");
    mPObjeto[playerid][id][bObjeto] = false;
    DestroyDynamic3DTextLabelEx(mPObjeto[playerid][id][TextoAID]);
    DestroyDynamicObjectEx(mPObjeto[playerid][id][ObjetoAID]);
    return 1;
}

CMD:criarobjeto(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /CriarObjeto [Objeto-ID]");
    new i = GerarObjetoID(playerid);
    if(i == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode mais adicionar objetos");

    new Float:x,
        Float:y,
        Float:z,
        Mensagem[10];

    format(Mensagem, sizeof(Mensagem), "Objeto[%d]", i);
    SetPVarInt(playerid, "aAmidnsObjeto", i);
    GetPlayerPos(playerid, x, y, z);
    mPObjeto[playerid][i][bObjeto] = true;
    mPObjeto[playerid][i][TextoAID] = CreateDynamic3DTextLabel(Mensagem, 0x00BFFFFF, x, y, z, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), playerid, 15.0, -1);
    mPObjeto[playerid][i][ObjetoAID] = CreateDynamicObject(id, x, y, z, 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), -1, 350.0, 350.0, -1);
    EditDynamicObject(playerid, mPObjeto[playerid][i][ObjetoAID]);
    SetPVarInt(playerid, "AdicionandoObjets", 1);
    return 1;
}