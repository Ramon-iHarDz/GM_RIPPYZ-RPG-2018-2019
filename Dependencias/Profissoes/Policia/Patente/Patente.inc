enum PatentePolic
{
    PriNC,
    PatenteNC[30]
};

new PoliciaPatente[][PatentePolic] =
{
    {0, "Aluno Soldado"},
    {250, "Soldado"},
    {400, "Cabo"},
    {600, "Terceiro Sargento"},
    {800, "Segundo Sargento"},
    {1000, "Primeiro Sargento"},
    {1250, "SubTenente"},
    {1300, "Aspirante A Oficial"},
    {1500, "Segundo Tenente"},
    {1700, "Primeiro Tenente"},
    {2000, "Capitão"},
    {2500, "Major"},
    {3000, "Tenente Coronel"},
    {3500, "Coronel"},
    {5000, "Comandante Geral"}
};

stock PegarPatente(lv)
{
    new id;
    for(new i=0; i < sizeof(PoliciaPatente); i++)
    {
        if(PoliciaPatente[i][PriNC] > lv) break;
        else id = i;
    }
    new LASDSA[30];
    format(LASDSA, sizeof(LASDSA), PoliciaPatente[id][PatenteNC]);
    return (LASDSA);
}

stock UparPolicia(playerid)
{
    for(new i=0; i < sizeof(PoliciaPatente); i++)
    {
        if(Jogador[playerid][Prisoes] != PoliciaPatente[i][PriNC]) continue;
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| PATENTE | O(A) Policial %s[%d] foi promovido(a) para %s", PegarNick(playerid), playerid, PoliciaPatente[i][PatenteNC]);
        for(new d=0; d < MAX_PLAYERS; d++)
        {
            if(!IsPlayerConnected(d)) continue;
            if(Jogador[d][Logado] == false) continue;
            if(!IsPolicia(d)) continue;
            if(d == playerid) MostrarMedalhaUp(playerid);
            SendClientMessage(d, 0x1E90FFFF, Mensagem);
        }
        break;
    }
    return 1;
}

stock MostrarMedalhaUp(playerid) 
{
    MostrarMedalha(playerid);
    PlayerTextDrawSetString(playerid, PoliciaMedalha[playerid][2], PegarPatente(Jogador[playerid][Prisoes]));
    SetTimerEx("OcultarMedalhaAuto", 5000, false, "d", playerid);
    return 1;
}

function OcultarMedalhaAuto(playerid)
{
    OcultarMedalha(playerid);
    return 1;
}