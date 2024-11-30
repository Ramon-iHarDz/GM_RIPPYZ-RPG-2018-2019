#include <YSI_Coding\y_hooks>

enum rankingEnum
{
    Ranking, 
    Score, 
    Id
};
new playerScores[MAX_PLAYERS][rankingEnum];

hook OnPlayerDisconnect(playerid, reason)
{
    new Deletar[rankingEnum];
    playerScores[playerid] = Deletar;
    return 1;
}

stock GetPlayerHighestScores(array[][Ranking], left, right)
{
    new tempLeft = left, tempRight = right, pivot = array[(left + right) / 2][Score], tempVar;
    while(tempLeft <= tempRight)
    {
        while(array[tempLeft][Score] > pivot) tempLeft++;
        while(array[tempRight][Score] < pivot) tempRight--;
        if(tempLeft <= tempRight)
        {
            tempVar = array[tempLeft][Score], array[tempLeft][Score] = array[tempRight][Score], array[tempRight][Score] = tempVar;
            tempVar = array[tempLeft][Id], array[tempLeft][Id] = array[tempRight][Id], array[tempRight][Id] = tempVar;
            tempLeft++, tempRight--;
        }
    }
    if(left < tempRight) GetPlayerHighestScores(array, left, tempRight);
    if(tempLeft < right) GetPlayerHighestScores(array, tempLeft, right);
}

CMD:toplevel(playerid)
{
    new Deletar[rankingEnum];
    playerScores[playerid] = Deletar;
    new Dialog[900];
    new indexTGN;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0) continue;

        playerScores[indexTGN][Score] = Jogador[i][Level];
        playerScores[indexTGN++][Id] = i;
    }
    GetPlayerHighestScores(playerScores, 0, indexTGN);

    strcat(Dialog, "{FFFFFF}Posição\t{FFFFFF}Nome\t{FFFFFF}Leveis\n");
    for(new i=0; i < 10; ++i)
    {
        if(i < indexTGN) strcatEx(Dialog, "{228B22}%d.\t{FFFFFF}%s\t{FF8C00}%d\n", i+1, PegarNick(playerScores[i][Id]), Jogador[playerScores[i][Id]][Level]);
        else strcatEx(Dialog, "{228B22}%d.\t{FF0000}Ninguém\t{FF0000}N/A\n", i+1);
    }
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Top Leveis", Dialog, "Fechar", "");
    return 1;
}

CMD:topgrana(playerid)
{
    new Deletar[rankingEnum];
    playerScores[playerid] = Deletar;
    new Dialog[900];
    new indexTGN,
        Cunz[MAX_PLAYERS];
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0) continue;

        Cunz[i] = Jogador[i][Dinheiro]+Jogador[i][DinheiroBanco];
        playerScores[indexTGN][Score] = Cunz[i];
        playerScores[indexTGN++][Id] = i;
    }
    GetPlayerHighestScores(playerScores, 0, indexTGN);

    strcat(Dialog, "{FFFFFF}Posição\t{FFFFFF}Nome\t{FFFFFF}Grana\n");
    for(new i; i < 10; ++i)
    {
        if(i < indexTGN) strcatEx(Dialog, "{228B22}%d.\t{FFFFFF}%s\t{FF8C00}R$%s\n", i+1, PegarNick(playerScores[i][Id]), DinheiroSeparar(Cunz[playerScores[i][Id]]));
        else strcatEx(Dialog, "{228B22}%d.\t{FF0000}Ninguém\t{FF0000}N/A\n", i+1);
    }
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Top Grana", Dialog, "Fechar", "");
    return 1;
}

CMD:topprocurados(playerid)
{
    new Deletar[rankingEnum];
    playerScores[playerid] = Deletar;
    new Dialog[900];
    new indexTGN,
        Cunz[MAX_PLAYERS];
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0) continue;
        if(Jogador[i][Preso] > 0) continue;
        if(Jogador[i][Estrelas] < 1) continue;

        Cunz[i] = Jogador[i][Estrelas]; 
        playerScores[indexTGN][Score] = Jogador[i][Estrelas];
        playerScores[indexTGN++][Id] = i;
    }
    GetPlayerHighestScores(playerScores, 0, indexTGN);

    strcat(Dialog, "{FFFFFF}Posição\t{FFFFFF}Nome\t{FFFFFF}Estrelas\n");
    for(new i; i < 10; ++i)
    {
        if(i < indexTGN) strcatEx(Dialog, "{228B22}%d.\t{FFFFFF}%s\t{FF8C00}%d\n", i+1, PegarNick(playerScores[i][Id]), Jogador[Cunz[playerScores[i][Id]]][Estrelas]);
        else strcatEx(Dialog, "{228B22}%d.\t{FF0000}Ninguém\t{FF0000}N/A\n", i+1);
    }
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Top Procurados", Dialog, "Fechar", "");
    return 1;
}

CMD:topcoins(playerid)
{
    new Deletar[rankingEnum];
    playerScores[playerid] = Deletar;
    new Dialog[900];
    new indexTGN;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0) continue;
        if(Jogador[i][Coins] < 1) continue;

        playerScores[indexTGN][Score] = Jogador[i][Coins];
        playerScores[indexTGN++][Id] = i;
    }
    GetPlayerHighestScores(playerScores, 0, indexTGN);

    strcat(Dialog, "{FFFFFF}Posição\t{FFFFFF}Nome\t{FFFFFF}Coins\n");
    for(new i; i < 10; ++i)
    {
        if(i < indexTGN) strcatEx(Dialog, "{228B22}%d.\t{FFFFFF}%s\t{FF8C00}R$%s\n", i+1, PegarNick(playerScores[i][Id]), DinheiroSeparar(Jogador[playerScores[i][Id]][Coins]));
        else strcatEx(Dialog, "{228B22}%d.\t{FF0000}Ninguém\t{FF0000}N/A\n", i+1);
    }
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Top Coins", Dialog, "Fechar", "");
    return 1;
}

CMD:topprisoes(playerid)
{
    new Deletar[rankingEnum];
    playerScores[playerid] = Deletar;
    new Dialog[900];
    new indexTGN;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0) continue;
        if(Jogador[i][Prisoes] < 1) continue;

        playerScores[indexTGN][Score] = Jogador[i][Prisoes];
        playerScores[indexTGN++][Id] = i;
    }
    GetPlayerHighestScores(playerScores, 0, indexTGN);

    strcat(Dialog, "Posição\tNome\tPrisões\tPatente\n");
    for(new i; i < 10; ++i)
    {
        if(i < indexTGN) strcatEx(Dialog, "{228B22}%d.\t{FFFFFF}%s\t{00BFFF}%s\t{CCCCCC}%s\n", i+1, PegarNick(playerScores[i][Id]), DinheiroSeparar(Jogador[playerScores[i][Id]][Prisoes]), PegarPatente(Jogador[playerScores[i][Id]][Prisoes]));
        else strcatEx(Dialog, "{228B22}%d.\t{FF0000}Ninguém\t{FF0000}N/A\n", i+1);
    }
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Top Prisões", Dialog, "Fechar", "");
    return 1;
}

CMD:topvips(playerid)
{
    new Deletar[rankingEnum];
    playerScores[playerid] = Deletar;
    new Dialog[900];
    new indexTGN;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0) continue;
        if(Jogador[i][Vip] < 1) continue;

        playerScores[indexTGN][Score] = Jogador[i][Vip]; 
        playerScores[indexTGN++][Id] = i;
    }
    GetPlayerHighestScores(playerScores, 0, indexTGN);

    strcat(Dialog, "{FFFFFF}Posição\t{FFFFFF}Nome\t{FFFFFF}Tempo\n");
    for(new i; i < 10; ++i)
    {
        if(i < indexTGN) strcatEx(Dialog, "{228B22}%d.\t{FFFFFF}%s\t{00BFFF}%s\n", i+1, PegarNick(playerScores[i][Id]), ConverterSegundos(Jogador[playerScores[i][Id]][Vip]));
        else strcatEx(Dialog, "{228B22}%d.\t{FF0000}Ninguém\t{FF0000}N/A\n", i+1);
    }
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Top Vips", Dialog, "Fechar", "");
    return 1;
}

CMD:toparena(playerid)
{
    new Deletar[rankingEnum];
    playerScores[playerid] = Deletar;
    new Dialog[900];
    new indexTGN;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0) continue;
        if(Jogador[i][VitimasArena] < 1) continue;

        playerScores[indexTGN][Score] = Jogador[i][VitimasArena];
        playerScores[indexTGN++][Id] = i;
    }
    GetPlayerHighestScores(playerScores, 0, indexTGN);

    strcat(Dialog, "{FFFFFF}Posição\t{FFFFFF}Nome\t{FFFFFF}Kills\tMortes\n");
    for(new i; i < 10; ++i)
    {
        if(i < indexTGN) strcatEx(Dialog, "{228B22}%d.\t{FFFFFF}%s\t{00BFFF}%d\t{B22222}%d\n", i+1, PegarNick(playerScores[i][Id]), Jogador[playerScores[i][Id]][VitimasArena], Jogador[playerScores[i][Id]][MortesArena]);
        else strcatEx(Dialog, "{228B22}%d.\t{FF0000}Ninguém\t{FF0000}N/A\t{FF0000}N/A\n", i+1);
    }
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Top Arena", Dialog, "Fechar", "");
    return 1;
}