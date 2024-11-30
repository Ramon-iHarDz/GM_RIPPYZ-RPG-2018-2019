#include <YSI_Coding\y_hooks>

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER){
        pPolicia[playerid][UltimoPolicia] = GetPlayerVehicleID(playerid);
    }
    return 1;
}

/*hook OnPlayerClickTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == PainelPolicial[playerid][7]) OcultarPainelPolicial(playerid);
    return 1;
}*/

function Desalgemar(playerid)
{  
    TogglePlayerControllable(playerid, 1);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    pAbordado[playerid][Algemado] = false;
    pAbordado[playerid][SeRendeu] = false;
    SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Passou 3 minutos e você foi liberado(a)");
    return 1;
}

function CancelarAbordagem(playerid)
{
    pAbordado[playerid][Abordado] = false;
    pAbordado[playerid][Acompanhando] = false;
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| CENTRAL | O(A) Jogador %s[%d] escapou da polícia", PegarNick(playerid), playerid);
    SendClientMessageToAll(0x1E90FFFF, Mensagem);
    return 1;
}

function AceitarAbordagem(playerid)
{
    new id = pAbordado[playerid][APolicial],
        Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| CENTRAL | O(A) Policial %s[%d] iniciou um acompanhamento ao jogador(a) %s[%d]", PegarNick(id), id, PegarNick(playerid), playerid);
    SendClientMessageToAll(0x1E90FFFF, Mensagem);
    OcultarAbordagem(playerid);
    if(!IsMafia(playerid)) Jogador[playerid][Estrelas] += 1;
    else Jogador[playerid][Estrelas] += 5;
    pAbordado[playerid][Abordado] = false;
    pAbordado[playerid][Acompanhando] = true;
    pAbordado[playerid][TempoAbordado] = SetTimerEx("CancelarAbordagem", 240000, false, "d", playerid);
    return 1;
}

stock InformarPainelPM(playerid)
{
    new Mensagem[2000];
    new Contagem = 0;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0) continue;
        if(Jogador[i][CadeiaEstilo] != 0) continue;
        if(Jogador[i][Estrelas] < 1) continue;

        if(Contagem == 0) strcatEx(Mensagem, "%s[%d] %d Estrela(s) ~r~/~w~", PegarNick(i), i, Jogador[i][Estrelas]);
        else
        {
            if(Contagem == 2) strcatEx(Mensagem, " %s[%d] %d Estrela(s)~n~", PegarNick(i), i, Jogador[i][Estrelas]);
            else strcatEx(Mensagem, " %s[%d] %d Estrela(s) ~r~/~w~", PegarNick(i), i, Jogador[i][Estrelas]);
        }

        Contagem++;
        if(Contagem >= 3) Contagem = 0;
    }
    PlayerTextDrawSetString(playerid, PainelPolicial[playerid][10], ConverterTexto(Mensagem)); 

    format(Mensagem, sizeof(Mensagem), "Suas_Prisoes:~n~~r~%d", Jogador[playerid][Prisoes]);
    PlayerTextDrawSetString(playerid, PainelPolicial[playerid][8], ConverterTexto(Mensagem));
    return 1;
}

stock VerificarPolicia(playerid)
{
    if(VeiculoPoliceVeh(playerid)) return true;
    if(UltimoVeiculoExercito(playerid)) return true;
    if(UltimoVeiculoAeronautica(playerid)) return true;
    if(UltimoVeiculoMarinha(playerid)) return true;
    return false;
}

stock PoliciaPatrulha()
{
    new Cont;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(!IsPolicia(i)) continue;
        if(!strcmp(Jogador[i][Profissao], "Corregedoria")) continue;
        if(pPolicia[i][PegouUniformePolicia] == false) continue;
        Cont++;
    }
    return Cont;
}