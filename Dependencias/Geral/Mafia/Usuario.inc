Dialog:DrogasMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Mensagem[128];
    switch(listitem)
    {
        case 0:
        {
            if(Jogador[playerid][Maconha] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem maconha");   
            Jogador[playerid][Maconha] -= 1;
            if(Jogador[playerid][VicioEstilo] == 0) Jogador[playerid][VicioEstilo] = 1;
            format(Mensagem, sizeof(Mensagem), "| DROGA | Você usou maconha ( %d/20 )", Jogador[playerid][Maconha]);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
        }
        case 1:
        {
            if(Jogador[playerid][Crack] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem crack");   
            Jogador[playerid][Crack] -= 1;
            if(Jogador[playerid][VicioEstilo] == 0) Jogador[playerid][VicioEstilo] = 2;
            format(Mensagem, sizeof(Mensagem), "| DROGA | Você usou crack ( %d/20 )", Jogador[playerid][Crack]);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
        }
        case 2:
        {
            if(Jogador[playerid][Cocaina] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem cocaina");   
            Jogador[playerid][Cocaina] -= 1;
            if(Jogador[playerid][VicioEstilo] == 0) Jogador[playerid][VicioEstilo] = 3;
            format(Mensagem, sizeof(Mensagem), "| DROGA | Você usou cocaina ( %d/20 )", Jogador[playerid][Cocaina]);
            SetPlayerDrunkLevel(playerid, GetPlayerDrunkLevel(playerid)+1000);
        }
        case 3:
        {
            if(Jogador[playerid][Lsd] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem lsd");   
            Jogador[playerid][Lsd] -= 1;
            if(Jogador[playerid][VicioEstilo] == 0) Jogador[playerid][VicioEstilo] = 4;
            format(Mensagem, sizeof(Mensagem), "| DROGA | Você usou lsd ( %d/20 )", Jogador[playerid][Lsd]);
            SetPlayerDrunkLevel(playerid, GetPlayerDrunkLevel(playerid)+1000);
        }
    }
    SendClientMessage(playerid, 0xFF6347FF, Mensagem);
    return 1;
}

CMD:drogas(playerid)
{
    new Dialog[300];
    strcat(Dialog, "Opção\tAdicional\n");
    strcatEx(Dialog, "Maconha\t{FFA500}%d\n", Jogador[playerid][Maconha]);
    strcatEx(Dialog, "Crack\t{FFA500}%d\n", Jogador[playerid][Crack]);
    strcatEx(Dialog, "Cocaina\t{FFA500}%d\n", Jogador[playerid][Cocaina]);
    strcatEx(Dialog, "Lsd\t{FFA500}%d", Jogador[playerid][Lsd]);
    Dialog_Show(playerid, DrogasMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Drogas", Dialog, "Selecionar", "Fechar");
    return 1;
}