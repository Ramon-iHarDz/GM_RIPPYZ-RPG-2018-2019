new bool:EnqueteCriar,
    VotosEnquete[2];

CMD:criarenquete(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new Mensagem[90];
    if(sscanf(params, "s[90]", Mensagem)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /CriarEnquete [Mensagem]");
    if(EnqueteCriar == true) OcultarEnquete();
    
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        SetPVarInt(i, "VotouAAA", 0);
    }
    
    VotosEnquete[0] = 0;
    VotosEnquete[1] = 0;
    EnqueteCriar = true;
    MostrarEnquete(playerid, Mensagem);
    return 1;
}

CMD:fecharenquete(playerid)
{
    if(Jogador[playerid][Admin] < 4) return 0;
    if(EnqueteCriar == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há nenhuma enquete aberta.");
    EnqueteCriar = false;
    OcultarEnquete();
    return 1;
}

CMD:votar(playerid)
{
    if(EnqueteCriar == false) return 0;
    if(GetPVarInt(playerid, "VotouAAA") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já votou");
    if(GetPVarInt(playerid, "EscEvento") > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está fazendo outra coisa, portanto não poderá votar.");
    SelectTextDraw(playerid, 0xFFA500FF);
    return 1;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == EnqueteInf[8]) AtualizarVotos(playerid, 0);
    else if(clickedid == EnqueteInf[9]) AtualizarVotos(playerid, 1);
    return 0;
}

stock AtualizarVotos(playerid, votod)
{
    if(GetPVarInt(playerid, "VotouAAA") == 1) return 1; 
    SetPVarInt(playerid, "VotouAAA", 1);
    new Msggg[15];
    switch(votod)
    {
        case 0:
        {
            VotosEnquete[0]++;
            format(Msggg, sizeof(Msggg), "Sim (%d)", VotosEnquete[votod]);
            TextDrawSetString(EnqueteInf[6], ConverterTexto(Msggg));
        }
        case 1:
        {
            VotosEnquete[1]++;
            format(Msggg, sizeof(Msggg), "Não (%d)", VotosEnquete[votod]);
            TextDrawSetString(EnqueteInf[7], ConverterTexto(Msggg));
        }
    }
    CancelSelectTextDraw(playerid);
    return true;
}