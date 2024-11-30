new CoresEstrelas[] =
{
    "r",
    "g",
    "b"
};

stock JogarEstrelas(playerid)
{
    Jogador[playerid][Dinheiro] -= 500;
    new Idds[3],
        CoresAA[60]
    ;
    Idds[0] = random(sizeof(CoresEstrelas));
    Idds[1] = random(sizeof(CoresEstrelas));
    Idds[2] = random(sizeof(CoresEstrelas));

    format(CoresAA, sizeof(CoresAA), "~%s~] ~%s~] ~%s~]", CoresEstrelas[Idds[0]], CoresEstrelas[Idds[1]], CoresEstrelas[Idds[2]]);
    GameTextForPlayer(playerid, CoresAA, 4000, 3);

    if(Idds[0] == Idds[1] && Idds[0] == Idds[2]){
        new daskd = random(3500-1000)+1000;
        Jogador[playerid][Dinheiro] += daskd;
        format(CoresAA, sizeof(CoresAA), "| BANCO | Você ganhou {32CD32}$%s{FFFFFF} nas estrelas", DinheiroSeparar(daskd));   
        SendClientMessage(playerid, -1, CoresAA);
        return 1;
    }
    SendClientMessage(playerid, 0xFFFF00FF, "| BANCO | Você perdeu nas estrelas.");
    return 1;
}