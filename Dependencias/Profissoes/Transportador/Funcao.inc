stock VerificarEntrega(playerid)
{
    for(new i=0; i < 4; i++)
    {
        if(pTransporte[playerid][i][EntregaAtiva] == false) continue;
        return true;
    }
    return false;
}