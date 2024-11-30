enum SpawnBandeiraJogador
{
    Float:JogadorBandX,
    Float:JogadorBandY,
    Float:JogadorBandZ
};

new VermelhoSpawn[][SpawnBandeiraJogador] =
{
    {-1015.5733,1052.3282,1343.0132},
    {-1007.1945,1074.0189,1342.8585},
    {-979.6827,1094.2246,1344.9448},
    {-976.4240,1069.4136,1344.9836},
    {-1002.5301,1041.5222,1342.1777},
    {-1033.8093,1058.4016,1343.9512},
    {-1033.6978,1089.3540,1343.1339},
    {-1012.1866,1093.9255,1341.5209},
    {-995.9808,1100.1074,1343.0205},
    {-999.4843,1080.9506,1342.4055}
};

new AzulSpawn[][SpawnBandeiraJogador] =
{
    {-1109.3269,1028.3292,1343.2556},
    {-1094.4813,1047.1604,1343.1826},
    {-1095.3458,1071.6807,1342.4823},
    {-1106.2615,1088.8456,1341.8438},
    {-1114.3706,1077.1812,1342.2684},
    {-1128.2369,1064.5754,1345.7388},
    {-1130.0684,1042.0896,1345.7277},
    {-1122.3552,1025.4203,1345.0509},
    {-1068.0424,1022.7221,1343.1747},
    {-1073.0199,1063.3085,1343.7043}
};

stock PegarBandeiraStatus(i){
    new mama[20];
    switch(Bandeira[i][BandeiraStatus]){
        case 0: mama = "Aguardando";
        case 1: mama = "Iniciando";
        case 2: mama = "Iniciado";
    }
    return mama;
}

stock PegarIDBandeira(id, playerid){
    for(new i=0; i < MAX_BANDEIRAS_JOGADOR; i++){
        if(pBandeira[id][i][BandeiraPlayer] == false) continue; 
        if(pBandeira[id][i][BandeiraID] != playerid) continue;
        return i;
    }
    return -1;
}

stock PegarVagaBandeira(id){
    for(new i=0; i < MAX_BANDEIRAS_JOGADOR; i++){
        if(pBandeira[i][BandeiraPlayer] == true) continue; 
        return i;
    }
    return -1;
}

stock MostrarEquipe(playerid, id){
    new Dialog[128];
    strcatEx(Dialog, "{FFFFFF}Entrar na Equipe Vermelha: {00CED1}%d/%d\n", Bandeira[id][JogadoresVermelho], (MAX_BANDEIRAS_JOGADOR/2));
    strcatEx(Dialog, "{FFFFFF}Entrar na Equipe Azul: {FFA500}%d/%d\n", Bandeira[id][JogadoresAzul], (MAX_BANDEIRAS_JOGADOR/2));
    Dialog_Show(playerid, EquipeBandeiraSelecionar, DIALOG_STYLE_TABLIST, "{FF0000}Equipes", Dialog, "Selecionar", "Fechar");
    return 1;
}

stock ColocarJogadorBandeira(playerid)
{
    new i = PegarVagaBandeira(id),
        Float:Oasf[3],
        xxa;
    switch(pBandeira[i][id][TimeBandeira])
    {
        case 0:
        {
            xxa = random(sizeof(VermelhoSpawn));
            Oasf[0] = VermelhoSpawn[xxa][JogadorBandX];
            Oasf[1] = VermelhoSpawn[xxa][JogadorBandY];
            Oasf[2] = VermelhoSpawn[xxa][JogadorBandZ];
        }
        case 1:
        {
            xxa = random(sizeof(AzulSpawn));
            Oasf[0] = AzulSpawn[xxa][JogadorBandX];
            Oasf[1] = AzulSpawn[xxa][JogadorBandY];
            Oasf[2] = AzulSpawn[xxa][JogadorBandZ];
        }    
    }
    return 1;
}

Dialog:BandeiraDialog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new i = listitem;
    if(Bandeira[i][BandeiraStatus] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode entrar, a sala está iniciando");
    else if(Bandeira[i][BandeiraStatus] > 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | A sala já iniciou.");
    if(Bandeira[i][Jogador] >= MAX_BANDEIRAS_JOGADOR) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sala está lotada");
    new id = PegarVagaBandeira(id);
    pBandeira[i][id][BandeiraPlayer] = true;
    pBandeira[i][id][BandeiraID] = playerid;
    pBandeira[i][id][BandeiraSala] = i;
    SetPVarInt(playerid, "DASDASDASDSA", i);
    Bandeira[i][Jogador]++;
    MostrarEquipe(playerid, id);
    return 1;
}

Dialog:EquipeBandeiraSelecionar(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    new i = PegarIDBandeira(GetPVarInt(playerid, "DASDASDASDSA"), playerid);
    new id = pBandeira[GetPVarInt(playerid, "DASDASDASDSA")][i][BandeiraSala];
    switch(listitem)
    {
        case 0:
        {
            if(Bandeira[i][JogadoresVermelho] >= (MAX_BANDEIRAS_JOGADOR/2)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Equipe Cheia.");
            Bandeira[i][JogadoresVermelho]++;
            pBandeira[i][id][TimeBandeira] = 0; 

        }
        case 1:
        {
            if(Bandeira[i][JogadoresAzul] >= (MAX_BANDEIRAS_JOGADOR/2)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Equipe Cheia.");
            Bandeira[i][JogadoresAzul]++;
            pBandeira[i][id][TimeBandeira] = 1; 
        }
    }
    ColocarJogadorBandeira(playerid);
    return 1;
}

