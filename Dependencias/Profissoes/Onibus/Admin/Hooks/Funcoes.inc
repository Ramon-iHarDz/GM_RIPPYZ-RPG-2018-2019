



// Sistema das Paradas //
stock PegarParadaID()
{
	for(new i=1; i < MAX_PARADAS; i++){
	    if(oParada[i][pColocado] == true) continue;
	    return i;
	}
	return 1;
}

AdicionarParada(parada)
{
	// if(oParada[parada][RangeParada] == 0) oParada[parada][MapIconParada] = CreateDynamicMapIcon(oParada[parada][pPosX], oParada[parada][pPosY], oParada[parada][pPosZ], 0, 0xFF0000FF, 0, 0, -1, 600.0, MAPICON_GLOBAL);
    // else oParada[parada][MapIconParada] = CreateDynamicMapIcon(oParada[parada][pPosX], oParada[parada][pPosY], oParada[parada][pPosZ], 56, -1, 0, 0, -1, 500.0, MAPICON_LOCAL);

	oParada[parada][ObjetoParada] = CreateDynamicObject(1257, oParada[parada][pPosX], oParada[parada][pPosY], oParada[parada][pPosZ], oParada[parada][pCamX], oParada[parada][pCamY], oParada[parada][pCamZ], 0, 0, -1, 128.0, 128.0);
    oParada[parada][pColocado] = true;
    return 1;    
}


// Sistema das Rotas //
stock PegarRotaID()
{
	for(new i=1; i < MAX_ROTAS; i++)
	{
		if(oRota[i][0][RotaAtiva] == true || oRota[i][0][Setando] == true) continue;
		return i;
	}
	return -1;
}

stock VerificarRota(id, atual)
{
	for(new i=0; i < MAX_ROTAS; i++)
	{
		if(i != id) continue;
		for(new h=0; h < MAX_ROTASID; h++)
		{
			if(h < atual) continue;
			if(oRota[i][h][RotaAtiva] == false) continue;
			return h;
		}
	}
	return -1;
}