Dialog:EstrelasPrefeitura(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new precoss = 0,
        slc = 0;
    new cc = 1;
    for(new i=0; i < Jogador[playerid][Estrelas]; i++)
    {
        precoss = 400*cc;  
        cc++;
        if(listitem != slc){
            slc++;
            continue;
        }
        if(i >= 50) break;
        if(Jogador[playerid][Dinheiro] < precoss) return SendClientMessage(playerid, 0xFF4500FF, "| EROO | Você não tem dinheiro sucifiente!");
        new Mensagem[128];
        Jogador[playerid][Dinheiro] -= precoss;
        Jogador[playerid][Estrelas] -= i+1;
        format(Mensagem, sizeof(Mensagem), "| PREFEITURA | Você removeu %d estrela(s) por {32CD32}$%s", i+1, DinheiroSeparar(precoss));
        SendClientMessage(playerid, -1, Mensagem);
        break;

    }
    return 0;
}