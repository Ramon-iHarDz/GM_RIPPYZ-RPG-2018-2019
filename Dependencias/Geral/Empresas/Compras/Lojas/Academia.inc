Dialog:AcademiaPlano(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Mensagem[128],
        EsN[20],
        id = GetPVarInt(playerid, "InteriorPersonalizadoID");

    if(listitem != 5 && pTempo[playerid][TrocarLuta] > gettime()){
        format(Mensagem, sizeof(Mensagem), "| ERRO | Você só pode trocar ou contratar um plano em %s", ConverterSegundos(pTempo[playerid][TrocarLuta]));
        SendClientMessage(playerid, 0xFF4500FF, Mensagem); 
        return 1;
    }

    switch(listitem)
    {
        case 0: Jogador[playerid][Luta] = 5, EsN = "Boxe";
        case 1: Jogador[playerid][Luta] = 6, EsN = "KungFu";
        case 2: Jogador[playerid][Luta] = 7, EsN = "Knee Head";
        case 3: Jogador[playerid][Luta] = 15, EsN = "Grab Kick";
        case 4: Jogador[playerid][Luta] = 16, EsN = "Cotovelada";
        case 5: Jogador[playerid][Luta] = 4, EsN = "N/A";
    }
    pTempo[playerid][TrocarLuta] = gettime()+86400;
    if(listitem == 5)
    {
        SetPlayerFightingStyle(playerid, Jogador[playerid][Luta]);
        Jogador[playerid][Luta] = 0;
        format(Mensagem, sizeof(Mensagem), "| ACADEMIA | Você cancelou seu plano da academia");
    }
    else
    {
        SetPlayerFightingStyle(playerid, Jogador[playerid][Luta]);
        EnviarDinheiroEmpresaEx(id, 350);
        format(Mensagem, sizeof(Mensagem), "| ACADEMIA | Você contratou o plano {00BFFF}%s{FFFFFF} por {32CD32}$950{FFFFFF}/mês", EsN);
    }
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}