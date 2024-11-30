#include <YSI_Coding\y_hooks>

Dialog:ConfiguracaoMenu(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    switch(listitem)
    {
        case 0: SetPVarInt(playerid, "ChatProfissaoS", GetPVarInt(playerid, "ChatProfissaoS") ? (false) : (true));
        case 1:{
            if(Jogador[playerid][Vip] < gettime() && Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode configurar essa opção");
            Jogador[playerid][BlockChatVip] = Jogador[playerid][BlockChatVip] ? (false) : (true);
        }
        case 2:{
            if(Jogador[playerid][Vip] < gettime() && Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode configurar essa opção");
            SetPVarInt(playerid, "ClimaChuva", GetPVarInt(playerid, "ClimaChuva") ? (false) : (true));
            if(GetPVarInt(playerid, "ClimaChuva") == 1) SetPlayerWeather(playerid, normalclima);
        }
        case 3:{
            if(strcmp(Jogador[playerid][Discord], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já vinculou seu discord com o servidor");
            VincularDiscord(playerid);
        }
    }
    return 1;
}

CMD:configuracao(playerid){
    new Dialog[1500];
    strcat(Dialog, "Opção\tStatus\n");
    strcatEx(Dialog, "{4169E1}» {A9A9A9}Chat Profissão\t%s\n", GetPVarInt(playerid, "ChatProfissaoS") ? ("{f03629}Desativado") : ("{32CD32}Ativado"));
    strcatEx(Dialog, "{4169E1}» {A9A9A9}Chat Vip\t%s\n", Jogador[playerid][BlockChatVip] ? ("{f03629}Desativado") : ("{32CD32}Ativado"));
    strcatEx(Dialog, "{4169E1}» {A9A9A9}Climas\t%s\n", GetPVarInt(playerid, "ClimaChuva") ? ("{f03629}Desativado") : ("{32CD32}Ativado"));
    if(!strcmp(Jogador[playerid][Discord], "*")) strcat(Dialog, "{4169E1}» {A9A9A9}Discord Autenticação\t{FF4500}Sincronizar\n");
    else strcat(Dialog, "{4169E1}» {A9A9A9}Discord Autenticação\t{FFA500}Sincronizado(a)");
    Dialog_Show(playerid, ConfiguracaoMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Configuração", Dialog, "Selecionar", "Fechar");
    return 1;
}