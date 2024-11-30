#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    if(pAFK[playerid][IniciouAFK] == false)
    {
        pAFK[playerid][TempoAFK] = SetTimerEx("VerificacaoAFK", 300000, true, "d", playerid);
        pAFK[playerid][IniciouAFK] = true;
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pAFK[playerid][IniciouAFK] == true) KillTimer(pAFK[playerid][TempoAFK]);
    new Deletar[JogadorAFK];
    pAFK[playerid] = Deletar;
    return 1;
}

function VerificacaoAFK(playerid)
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "VerificacaoAFK", 2)) return 1;
    if(Jogador[playerid][Admin] > 0) return 1;
    if(GetPVarInt(playerid, "EventoJogador") > 0) return 1;
    if(Jogador[playerid][EstadoAFK] == true)
    {
        new Enviar[40];
        pAFK[playerid][TempoKickAfk]--;
        format(Enviar, sizeof(Enviar), "Tempo: %s", SegundosParaMinutosEx(pAFK[playerid][TempoKickAfk]));
        PlayerTextDrawSetString(playerid, AntiAFKTXD[playerid][3], ConverterTexto(Enviar));
        pAFK[playerid][TempoFicouAw] += 1;
        if(pAFK[playerid][TempoKickAfk] <= 0)
        {
            Jogador[playerid][EstadoAFK] = false;
            SendClientMessage(playerid, 0xFF4500FF, "| AUSENTE | Você foi expulso(a) por ficar muito tempo ausente");
            SetTimerEx("KickEx", 1000, false, "d", playerid);
        }
        return 1;
    }

    if(!IsPlayerInRangeOfPoint(playerid, 30.0, pAFK[playerid][afkPos][0],  pAFK[playerid][afkPos][1],  pAFK[playerid][afkPos][2])){
        GetPlayerPos(playerid, pAFK[playerid][afkPos][0],  pAFK[playerid][afkPos][1],  pAFK[playerid][afkPos][2]);
        return 1;
    }
    
    IniciarAntiAFK(playerid);
    return 1;
}

stock IniciarAntiAFK(playerid)
{
    GerarAntiAFK(playerid, GetRandomString(random(8-5)+5));
    MostrarAntiAFK(playerid);
    pAFK[playerid][TempoFicouAw] = 0;
    pAFK[playerid][ErrosAFK] = 0;
    pAFK[playerid][TempoKickAfk] = 240;
    Jogador[playerid][EstadoAFK] = true;
    KillTimer(pAFK[playerid][TempoAFK]);
    pAFK[playerid][TempoAFK] = SetTimerEx("VerificacaoAFK", 1000, true, "d", playerid);
    SendClientMessage(playerid, 0xFF4500FF, "| AUSENTE | Você foi bloqueado(a) de upar.");
    return 1;
}

stock RemoverAFK(playerid, admret = 6666)
{
    new Enviar[338];

    new Float:Posicao[4];
    GetPlayerPos(playerid, Posicao[0], Posicao[1], Posicao[2]);
    GetPlayerFacingAngle(playerid, Posicao[3]);

    if(admret != 6666) format(Enviar, sizeof(Enviar), "INSERT INTO `antiafk` (`Nome`, `Tempo`, `Data`, `Admin`, `Codigo`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `PosicaoA`, `Esc`) VALUES ('%s', %d, %d, '%s', '%s', %f, %f, %f, %f, %d)", EscapeString(PegarNick(playerid)), pAFK[playerid][TempoFicouAw], gettime(), EscapeString(PegarNick(admret)), "N/A", Posicao[0], Posicao[1], Posicao[2], Posicao[3], IsPlayerPaused(playerid));
    else format(Enviar, sizeof(Enviar), "INSERT INTO `antiafk` (`Nome`, `Tempo`, `Data`, `Admin`, `Codigo`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `PosicaoA`, `Esc`) VALUES ('%s', %d, %d, '%s', '%s', %f, %f, %f, %f, %d)", EscapeString(PegarNick(playerid)), pAFK[playerid][TempoFicouAw], gettime(), "N/A", "N/A", Posicao[0], Posicao[1], Posicao[2], Posicao[3], IsPlayerPaused(playerid));
    mysql_query(IDConexao, Enviar, false);

    OcultarAntiAFK(playerid);
    KillTimer(pAFK[playerid][TempoAFK]); 
    Jogador[playerid][EstadoAFK] = false;
    SetPVarInt(playerid, "TentarAFK", 0);
    pAFK[playerid][TempoAFK] = SetTimerEx("VerificacaoAFK", 300000, true, "d", playerid);
    SendClientMessage(playerid, -1, "| AUSENTE | Você foi desbloqueado(a) de upar"); 
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == AntiAFKTXD[playerid][10]) MostrarListaAFK(playerid); 
    else if(playertextid == AntiAFKTXD[playerid][12]) 
    {
        if(GetPVarInt(playerid, "TentarAFK") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| AUSENTE | Você não pode tentar novamente.");
        SetPVarInt(playerid, "TentarAFK", 1);
        GerarAntiAFK(playerid, GetRandomString(random(8-5)+5));
        SendClientMessage(playerid, 0xFFFF00FF, "| AFK | Você gerou um novo código, olhe em 'Visualizar Slots'");
    }
    else if(Jogador[playerid][EstadoAFK] == true)
    {
        new Klas[6];
        Klas[0] = 4;
        Klas[1] = 5;
        Klas[2] = 6; 
        Klas[3] = 7;
        Klas[4] = 8;
        Klas[5] = 9;

        for(new i=0; i < 6; i++)
        {
            if(playertextid != AntiAFKTXD[playerid][Klas[i]]) continue;
            if(pAFK[playerid][ErrosAFK] >= 2)
            {
                SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Você foi expulso(a) por não passar o Anti-AFK");
                SetTimerEx("KickEx", 1000, false, "d", playerid);
                return 1;
            }
            if(pAFK[playerid][CodePosEx] != i)
            {
                SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Você selecionou o ID errado, olhe as instruções.");
                pAFK[playerid][ErrosAFK]++;
                return 1;
            }
            RemoverAFK(playerid);
            break;
        }
    }
    return 0;
}

CMD:ausentes(playerid)
{
    new Dialog[1500];
    strcat(Dialog, "Jogador(a)\tTempo\n");
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][EstadoAFK] == false) continue;
        if(Jogador[i][Admin] > 0) continue;
        strcatEx(Dialog, "%s\t%s\n", PegarNick(i), SegundosParaMinutosEx(pAFK[i][TempoKickAfk]));
    }
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Ausentes", Dialog, "Fechar", "");
    return 1;
}