function OnPlayerVoip(playerid, type)
{
    switch(type)
    {
        // Local
        case 0:
        {
            if(Jogador[playerid][MutadoVoip] > gettime() || Jogador[playerid][MutadoVoip] == -1) return false;
            if(Jogador[playerid][Preso] != 0 && Jogador[playerid][CadeiaEstilo] == 0) return false;
            

        }

        // Global
        case 1:
        {
            if(Jogador[playerid][Admin] < 3) return false;
        }
    }
    return true;
}