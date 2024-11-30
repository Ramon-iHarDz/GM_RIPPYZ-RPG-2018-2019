CMD:voips(playerid)
{
    if(!strcmp(Jogador[playerid][Discord], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem uma conta do discord vinculada");
    new Dialog[200];
    strcat(Dialog, "Salas Públicas\n");
    if(Jogador[playerid][Admin] > 0)
    {
        strcat(Dialog, "Salas Administração");
    }
    Dialog_Show(playerid, VoipMenu, DIALOG_STYLE_TABLIST, "{FF0000}Salas", Dialog, "Entrar", "Fechar");
    return 1;
}

Dialog:VoipMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[128];
    switch(listitem)
    {
        case 0:
        {
            strcat(Dialog, "Voip #1\n");
            strcat(Dialog, "Voip #2\n");
            strcat(Dialog, "Voip #3\n");
            strcat(Dialog, "Voip #4");  
            Dialog_Show(playerid, VoipPublico, DIALOG_STYLE_TABLIST, "{FF0000}Voip", Dialog, "Entrar", "Fechar"); 
        }
        case 1:
        {
            strcat(Dialog, "Voip Administração\n");
            strcat(Dialog, "Voip Reunião");
            Dialog_Show(playerid, VoipAdmin, DIALOG_STYLE_TABLIST, "{FF0000}Voip Admin's", Dialog, "Entrar", "Fechar");   
        }
    }
    return 1;
}

Dialog:VoipPublico(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    return 1;
}

Dialog:VoipAdmin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    return 1;
}