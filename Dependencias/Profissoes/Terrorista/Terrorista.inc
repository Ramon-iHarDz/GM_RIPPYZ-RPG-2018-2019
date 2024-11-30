#include <YSI_Coding\y_hooks>

enum JogadorTerrorista
{
    BombaIDDD,
    TempoBomba,
    Text3D:TextoBomba,
    bool:BombaPlantadaMafia
};

new pTerrorista[MAX_PLAYERS][JogadorTerrorista];

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamic3DTextLabelEx(pTerrorista[playerid][TextoBomba]);
    DestroyDynamicObjectEx(pTerrorista[playerid][BombaIDDD]);
    if(pTerrorista[playerid][BombaPlantadaMafia] == true) KillTimer(pTerrorista[playerid][TempoBomba]);

    new dasdasdas[JogadorTerrorista];
    pTerrorista[playerid] = dasdasdas;
    return 1;
}

CMD:homembomba(playerid)
{ 
    if(strcmp(Jogador[playerid][Profissao], "Terrorista")) return 0;
    if(pTempo[playerid][Homembomba] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa aguardar.");
    if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se explodir em um veículo");

    pTempo[playerid][Homembomba] = gettime()+600;
    Jogador[playerid][Estrelas] += 10;

    new Float:Loas[3];
    GetPlayerPos(playerid, Loas[0], Loas[1], Loas[2]);
    CreateExplosion(Loas[0], Loas[1], Loas[2], 2, 50.0);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "{32CD32}| TERRORISTA | O(A) Terrorista %s[%d] se explodiu em %s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
    ProxDetector(50.0, playerid, Mensagem, -1,-1,-1,-1,-1);

    format(Mensagem, sizeof(Mensagem), "| CENTRAL | O(A) Terrorista %s[%d] fez um atentado em %s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(!IsPolicia(i)) continue;
        if(pPolicia[i][PegouUniformePolicia] == false) continue;
        SendClientMessage(i, 0x4682B4FF, Mensagem);
    }
    return 1;
}

CMD:armarbomba(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Terrorista")) return 0;
    if(pTempo[playerid][ExplosaoBomba] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa aguardar.");
    if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode armar uma bomba em um veículo");

    pTempo[playerid][ExplosaoBomba] = gettime()+600;
    Jogador[playerid][Estrelas] += 10;

    new Float:Loas[3];
    GetPlayerPos(playerid, Loas[0], Loas[1], Loas[2]);

    new tp = random(15),
        msg[30];
    format(msg, sizeof(msg), "Explosão: %d", tp);

    pTerrorista[playerid][BombaIDDD] = CreateDynamicObject(1252, Loas[0], Loas[1], Loas[2]-0.7, 0.0, 0.0, random(360), 0, 0, -1, 120.0, 120.0, -1);
    pTerrorista[playerid][TextoBomba] = CreateDynamic3DTextLabel(msg, 0xFFFF0060, Loas[0], Loas[1], Loas[2]-0.7, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 11.0, -1); 
    pTerrorista[playerid][TempoBomba] = SetTimerEx("ExplosaoTerrorista", 1000, false, "dfffd", playerid, Loas[0], Loas[1], Loas[2], tp);
    pTerrorista[playerid][BombaPlantadaMafia] = true;
    return 1;
}

function ExplosaoTerrorista(playerid, Float:x, Float:y, Float:z, value)
{
    value--;
    if(value > 0)
    {
        new msg[30];
        format(msg, sizeof(msg), "Explosão: %d", value);
        UpdateDynamic3DTextLabelText(pTerrorista[playerid][TextoBomba], 0xFFFF0060, msg);
        pTerrorista[playerid][TempoBomba] = SetTimerEx("ExplosaoTerrorista", 1000, false, "dfffd", playerid, x, y, z, value);
        return 1;
    }

    pTerrorista[playerid][BombaPlantadaMafia] = false;

    DestroyDynamic3DTextLabelEx(pTerrorista[playerid][TextoBomba]);
    DestroyDynamicObjectEx(pTerrorista[playerid][BombaIDDD]);
    CreateExplosion(x, y, z, 2, 50.0);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "{32CD32}| TERRORISTA | O(A) Terrorista %s[%d]  em %s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
    ProxDetector(50.0, playerid, Mensagem, -1,-1,-1,-1,-1);

    format(Mensagem, sizeof(Mensagem), "| CENTRAL | O(A) Terrorista %s[%d] fez um atentado em %s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(!IsPolicia(i)) continue;
        if(pPolicia[i][PegouUniformePolicia] == false) continue;
        SendClientMessage(i, 0x4682B4FF, Mensagem);
    }
    return 1;
}