#include <YSI_Coding\y_hooks>

Dialog:PainelAdmin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: {EmailFunc = EmailFunc ? (false) : (true);}
        case 1: {RegistroFunc = RegistroFunc ? (false) : (true);}
        case 2: {LoginFunc = LoginFunc ? (false) : (true);}
        case 3: {CaixaFunc = CaixaFunc ? (false) : (true);}
    }
    return 1;
}

CMD:painel(playerid)
{
    if(Jogador[playerid][Admin] < 5) return 1;
    new Dialog[2000];
    strcat(Dialog, "Opção\tStatus\n");
    strcatEx(Dialog, "Código Registro [Chat]\t%s\n", EmailFunc ? ("{32CD32}Ativado") : ("{FF0000}Desativado"));
    strcatEx(Dialog, "Bloquear Registro\t%s\n", RegistroFunc ? ("{32CD32}Ativado") : ("{FF0000}Desativado"));
    strcatEx(Dialog, "Bloquear Login\t%s\n", LoginFunc ? ("{32CD32}Ativado") : ("{FF0000}Desativado"));
    strcatEx(Dialog, "Voip Box\t%s\n", CaixaFunc ? ("{32CD32}Ativado") : ("{FF0000}Desativado"));
    Dialog_Show(playerid, PainelAdmin, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Painel", Dialog, "Selecionar", "Fechar");
    return 1;
}