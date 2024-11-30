stock DarVacina(playerid, horas)
{
    Jogador[playerid][Vacina] += (3600*horas);
    return 1;
}