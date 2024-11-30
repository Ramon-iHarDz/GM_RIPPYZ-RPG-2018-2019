#include <YSI_Coding\y_hooks>
#define     MAX_JASON   (20)

enum JogadorJason
{
    bool:EntrouJason,
    bool:JasonMatar,
    JasonID,

    Text3D:TextoJason
};

new jasonporta;
new Jason[MAX_JASON][JogadorJason];

stock ConfigurarJason(playerid) 
{
    jasonporta = CreateDynamicObject(19302, 217.8168, 116.5220, 999.2616, 0.0000, 0.0000, 0.0000, 2022, 10, -1, 30.0, 30.0, -1);

    SetPlayerInterior(playerid, 10);
    SetPlayerVirtualWorld(playerid, 2022);
    SetPlayerPos(playerid, 216.4311,122.9083,999.0156);

    EventoEstado = 1;
    EventoID = 5;

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) %s %s criou um evento de Jason ( /IrEvento )", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessageToAll(0xFF8C00FF, Mensagem);
    return 1;
}

stock ColocarJason(playerid)
{
    new id = PegarJasonID();
    if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais vagas no evento");

    Jason[id][EntrouJason] = true;
    Jason[id][JasonMatar] = false; 
    Jason[id][JasonID] = playerid;

    Jogador[playerid][uInteriorEx] = 2144;
    GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);

    ResetPlayerWeapons(playerid);
    SetPlayerHealth(playerid, 10.0);
    SetPlayerArmour(playerid, 0.0);
    SetPlayerInterior(playerid, 10);
    SetPlayerVirtualWorld(playerid, 2022);
    SetPlayerPos(playerid, 216.4311,122.9083,999.0156);
    return 1;
}

stock FinalizarJason()
{
    DestroyDynamicObject(jasonporta);
    for(new i=0; i < MAX_JASON; i++){
        if(Jason[i][EntrouJason] == false) continue;
        RetirarJason(Jason[i][JasonID], i);
    }
    return 1;
}

stock RetirarJason(playerid, id)
{
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);

    DestroyDynamic3DTextLabelEx(Jason[id][TextoJason]);

    new dasd[JogadorJason];
    Jason[id] = dasd;
    return 1;
}

stock PegarJasonID()
{   
    for(new i=0; i < MAX_JASON; i++){
        if(Jason[i][EntrouJason] == true) continue;
        return i;
    }
    return -1;
}

stock PegarJogadorJason(playerid)
{
    for(new i=0; i < MAX_JASON; i++){
        if(Jason[i][EntrouJason] == false) continue;
        if(Jason[i][JasonID] != playerid) continue;
        return i;
    }
    return -1;
}

stock IniciarJason() 
{
    EventoEstado = 2;
    new id = -1,
        i;
    
    while(id == -1)
    {
        i = random(MAX_JASON);
        if(Jason[i][EntrouJason] == false) continue;
        Jason[i][TextoJason] = CreateDynamic3DTextLabel("Jason", 0xFF0000FF, 0.0, 0.0, 0.7, 29.0, Jason[i][JasonID], INVALID_VEHICLE_ID, 0, -1, -1, -1, 30.0, -1);
        GivePlayerWeapon(Jason[i][JasonID], 9, 1);
        SetPlayerPos(Jason[i][JasonID], 222.0844,114.7722,999.0156);
        Jason[i][JasonMatar] = true;
        GameTextForPlayer(Jason[i][JasonID], ConverterTexto("~r~Jason!"), 1000, 3);
        id = i;
    }

    SetTimerEx("JasonSair", 1000, false, "d", 10);
    return 1;
}

function JasonSair(xTempo)
{
    xTempo--;
    new Msg[10],
        MsgEx[17];
    format(Msg, sizeof(Msg), "~r~%d", xTempo);
    format(MsgEx, sizeof(MsgEx), "~r~Saindo em %d", xTempo);
    for(new i=0; i < MAX_JASON; i++){
        if(Jason[i][EntrouJason] == false) continue;
        if(Jason[i][JasonMatar] == false) GameTextForPlayer(Jason[i][JasonID], ConverterTexto(Msg), 1000, 3);
        else GameTextForPlayer(Jason[i][JasonID], ConverterTexto(MsgEx), 1000, 3);
    }
    if(xTempo > 0) SetTimerEx("JasonSair", 1000, false, "d", xTempo);
    else
    {
        DestroyDynamicObjectEx(jasonporta);
        EventoEstado = 3;
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    new id = PegarJogadorJason(playerid);
    if(id == -1) return 1;
    RetirarJason(playerid, id);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if(GetPVarInt(playerid, "LASLDALSDA") == 1){
        new id = PegarJogadorJason(playerid);
        RetirarJason(playerid, id);
        SetPVarInt(playerid, "LASLDALSDA", 0);
    }
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    new id = PegarJogadorJason(playerid);
    if(id == -1) return 1;
    SetPVarInt(playerid, "LASLDALSDA", 1);
    return 1;
}

hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
    new id = PegarJogadorJason(playerid);
    if(id == -1) return 1;
    if(Jason[id][JasonMatar] == true) return 1;
    SetPlayerHealth(damagedid, 10.0);
    return 1;
}