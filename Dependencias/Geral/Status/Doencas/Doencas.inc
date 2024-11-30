#include <YSI_Coding\y_hooks>

enum DoencaJogador
{
    bool:IniciouBusca,
    TempoDoenca
};

new pDoenca[MAX_PLAYERS][DoencaJogador];

hook OnPlayerSpawn(playerid)
{
    if(pDoenca[playerid][IniciouBusca] == false)
    {
        pDoenca[playerid][TempoDoenca] = SetTimerEx("BuscarDoenca", 5000, true, "d", playerid);
        pDoenca[playerid][IniciouBusca] = true;
        if(Jogador[playerid][Doenca] == 0 && Jogador[playerid][Level] > 5){
            new ChanceDeDoenca = random(30000);
            if(ChanceDeDoenca <= 50) Jogador[playerid][Doenca] = random(sizeof(Doencas));
        }
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pDoenca[playerid][IniciouBusca] == true) KillTimer(pDoenca[playerid][TempoDoenca]);
    new Deletar[DoencaJogador];
    pDoenca[playerid] = Deletar;
    return 1;
}

function BuscarDoenca(playerid)
{
    if(Jogador[playerid][Doenca] == 0) return 1;
    if(Jogador[playerid][Admin] > 0) return 1;
    new Float:mPos[3],
        DoencaID = Jogador[playerid][Doenca]
    ;
    GetPlayerPos(playerid, mPos[0], mPos[1], mPos[2]);
    new Chance = random(3000);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Doenca] > 0) continue;
        if(Jogador[i][Vacina] > 0) continue;
        if(Jogador[i][Level] < 5) continue;
        if(Jogador[i][Admin] > 0) continue;
        if(!IsPlayerInRangeOfPoint(i, Doencas[DoencaID][RaioTransmissao], mPos[0], mPos[1], mPos[2])) continue;
        if(Chance > Doencas[DoencaID][Contaminacao]) continue;
        Jogador[i][Doenca] = DoencaID;
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| DOENÇA | O(A) Jogador(a) %s passou {FF8C00}%s{FFFFFF} para você", PegarNick(playerid), Doencas[DoencaID][DoencaNome]);
        SendClientMessage(i, -1, Mensagem);
    }
    return 1;
}