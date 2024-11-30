
stock AmongMapaNome(id)
{
    new MapN[20];
    switch(id)
    {
        case 0: MapN = "Casa do Maddog";
        case 1: MapN = "Motel Jefferson";
    }
    return (MapN);
}

stock ConfigurarAmong(playerid)
{
    new Dialog[180];
    strcatEx(Dialog, "{FFFFFF}Vagas: {00BFFF}%d\n", AmongVaga);
    strcatEx(Dialog, "{FFFFFF}Impostores: {FF0000}%d\n", AmongImpostor);
    strcatEx(Dialog, "{FFFFFF}Mapa: {FFA500}%s\n", AmongMapaNome(AmongMapa));
    strcat(Dialog, "{00FF00}Confirmar");
    Dialog_Show(playerid, AdminConfigAmong, DIALOG_STYLE_TABLIST, "{FF0000}Among US", Dialog, "Selecionar", "Fechar");
    return 1;
}


// Dialogs
Dialog:AdminConfigAmong(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, ConfigVagasAmong, DIALOG_STYLE_INPUT, "{FF0000}Vagas", "Coloque abaixo o tanto de vagas", "Selecionar", "Fechar");
        case 1: Dialog_Show(playerid, ConfigImpostoresAmong, DIALOG_STYLE_INPUT, "{FF0000}Impostores", "Coloque abaixo o tanto de impostores", "Selecionar", "Fechar");
        case 2:
        {
            new Dialog[90];
            for(new i=0; i < 2; i++)
            {
                strcatEx(Dialog, "%s\n", AmongMapaNome(i));
            }
            Dialog_Show(playerid, ConfigMapaAmong, DIALOG_STYLE_TABLIST, "{FF0000}Mapa", Dialog, "Selecionar", "Fechar");
        }
        case 3:
        {
            PrepararAmong();
            new Mensagem[128];
            EventoEstado = 1;
            EventoID = 2;
            format(Mensagem, sizeof(Mensagem), "| EVENTO | O(A) %s %s criou um evento de Among Us ( /IrEvento )", CargoAdmin(2, playerid), PegarNick(playerid));
            SendClientMessageToAll(0xFF8C00FF, Mensagem);
            // EnviarAmong(0);
        }
    }
    return 1;
}

Dialog:ConfigVagasAmong(playerid, response, listitem, inputtext[])
{  
    if(!response) return ConfigurarAmong(playerid);
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque apenas números");
    if(id < 2 || id > MAX_AMONG) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | mínimo ( 2 ) - Máximo ( 11 )");
    AmongVaga = id;
    ConfigurarAmong(playerid);
    return 1;
}

Dialog:ConfigImpostoresAmong(playerid, response, listitem, inputtext[])
{
    if(!response) return ConfigurarAmong(playerid);
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque apenas números");
    if(id < 1 || id > 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | mínimo ( 1 ) - Máximo ( 2 )");
    AmongImpostor = id;
    ConfigurarAmong(playerid);
    return 1;
}

Dialog:ConfigMapaAmong(playerid, response, listitem, inputtext[])
{
    if(!response) return ConfigurarAmong(playerid);
    AmongMapa = listitem;
    ConfigurarAmong(playerid);
    return 1;
}