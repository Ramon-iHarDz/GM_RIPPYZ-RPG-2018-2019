enum InfoUp
{
    LevelNC,
    MensagemNC[90]
};

new LevelUP[][InfoUp] = 
{
    {10, "*"},
    {100, "recebeu 2 dias de VIP e $20.000"},
    {300, "recebeu 3 dias de VIP e $40.000"},
    {500, "recebeu 5 dias de VIP e $60.000"},
    {800, "recebeu 8 dias de VIP e $70.000"},
    {1000, "recebeu 10 dias de VIP e $90.000"},
    {1500, "recebeu 15 dias de VIP e $100.000"}
};

stock DarRecompensaUP(playerid)
{
    new id = -1;
    for(new i=0; i < sizeof(LevelUP); i++)
    {
        if(LevelUP[i][LevelNC] != Jogador[playerid][Level]) continue;
        id = i;
        break;
    }
    if(id == -1) return 1;
    if(strcmp(LevelUP[id][MensagemNC], "*"))
    {
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| RECOMPENSA | O(A) Jogador(a) %s[%d] alcançou o level %d e %s", PegarNick(playerid), playerid, LevelUP[id][LevelNC], LevelUP[id][MensagemNC]);
        SendClientMessageToAll(0x00FFFFFF, Mensagem);
    }

    switch(id)
    {
        case 0: AtivarVIP(playerid, 1);  
        case 1:
        {
            AtivarVIP(playerid, 2);
            Jogador[playerid][Dinheiro] += 20000;
        }
        case 2:
        {
            AtivarVIP(playerid, 3);
            Jogador[playerid][Dinheiro] += 40000;
        }
        case 3:
        {
            AtivarVIP(playerid, 5);
            Jogador[playerid][Dinheiro] += 60000;
        }
        case 4:
        {
            AtivarVIP(playerid, 8);
            Jogador[playerid][Dinheiro] += 70000;
        }
        case 5:
        {
            AtivarVIP(playerid, 10);
            Jogador[playerid][Dinheiro] += 90000;
        }
        case 6:
        {
            AtivarVIP(playerid, 15);
            Jogador[playerid][Dinheiro] += 100000;
        }
    }
    return 1;
}