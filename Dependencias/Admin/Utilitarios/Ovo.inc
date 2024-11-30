#define     MAX_OVOS    (40)

enum OvoEvento
{
    bool:OvoColocado,
    OvoObjeto,
    Text3D:OvoTexto,
    Float:OvoPosX,
    Float:OvoPosY,
    Float:OvoPosZ
};

new Ovo[MAX_OVOS][OvoEvento];

stock PegarOvoID()
{
    for(new i=0; i < MAX_OVOS; i++){
        if(Ovo[i][OvoColocado] == true) continue;
        return i;
    }
    return -1;
}

CMD:colocarovo(playerid)
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new id = PegarOvoID();
    if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Já foi adicionado muitos ovos no mapa, espere.");
    Ovo[id][OvoColocado] = true;
    GetPlayerPos(playerid, Ovo[id][OvoPosX], Ovo[id][OvoPosY], Ovo[id][OvoPosZ]);
    Ovo[id][OvoObjeto] = CreateDynamicObject(19344, Ovo[id][OvoPosX], Ovo[id][OvoPosY], Ovo[id][OvoPosZ]-0.7, 0.0, 0.0, random(360), 0, 0, -1, 90.0, 90.0, -1);
    Ovo[id][OvoTexto] = CreateDynamic3DTextLabel("Você encontrou o ovo{FFFFFF}\nUse {CCCCCC}/Ovo{FFFFFF} para abrir", 0xFFD700FF, Ovo[id][OvoPosX], Ovo[id][OvoPosY], Ovo[id][OvoPosZ]-0.7, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 11.0, -1);
    return 1;
}

CMD:ovo(playerid)
{
    for(new i=0; i < MAX_OVOS; i++)
    {
        if(Ovo[i][OvoColocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, Ovo[i][OvoPosX], Ovo[i][OvoPosY], Ovo[i][OvoPosZ])) continue;
        if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;

        new Mensagem[85];
        format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) Jogador(a) {FFD700}%s[%d]{FFFFFF} achou o ovo escondido", PegarNick(playerid), playerid);
        SendClientMessageToAll(-1, Mensagem);

        DestroyDynamicObjectEx(Ovo[i][OvoObjeto]);
        DestroyDynamic3DTextLabelEx(Ovo[i][OvoTexto]);

        Ovo[i][OvoColocado] = false;
        break;
    }
    return 1;
}