enum DiscordJogador
{
    Codigo[70],
    DiscordPlayer[70]
};
new pDiscord[MAX_PLAYERS][DiscordJogador];

/*CMD:discord(playerid)
{
    if(strcmp(Jogador[playerid][Discord], "*")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Voc� j� est� sincronizado(a)!");
    if(Jogador[playerid][Level] < 3) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Voc� precisa ter no m�nimo level 3");
    new Dialog[900];
    strcat(Dialog, "{FFFFFF}Coloque abaixo seu {FF0000}Discord ID\n\n\n");
    strcat(Dialog, "{FFFFFF}Como fa�o para pegar meu discord id?\n\n");
    strcat(Dialog, "{FFFF00}Computador:\n");
    strcat(Dialog, "{00BFFF}1. {FFFFFF}V� nas configura��es do seu discord\n");
    strcat(Dialog, "{00BFFF}2. {FFFFFF}V� em {00BFFF}Apar�ncia{FFFFFF} e {00BFFF}Habilite o Modo Desenvolvedor\n");
    strcat(Dialog, "{00BFFF}3. {FFFFFF}V� no servidor do discord da rippzy city\n");
    strcat(Dialog, "{00BFFF}4. {FFFFFF}Clique com bot�o direito no seu perfil no discord da {00BFFF}Rippzy City\n");
    strcat(Dialog, "{00BFFF}5. {FFFFFF}Clique em Copiar ID\n\n");
    strcat(Dialog, "{FFFF00}Celular Android/IOS:\n");
    strcat(Dialog, "{00BFFF}1. {FFFFFF}V� nas configura��es do seu discord\n");
    strcat(Dialog, "{00BFFF}2. {FFFFFF}V� em {00BFFF}Comportamento{FFFFFF} e {00BFFF}Habilite o Modo Desenvolvedor\n");
    strcat(Dialog, "{00BFFF}3. {FFFFFF}V� no servidor do discord da rippzy city\n");
    strcat(Dialog, "{00BFFF}4. {FFFFFF}Clique com bot�o direito no seu perfil no discord da {00BFFF}Rippzy City\n");
    strcat(Dialog, "{00BFFF}5. {FFFFFF}Clique em Copiar ID\n\n");
    strcat(Dialog, "{FFFFFF}Caso necessite de ajuda, chame um dos nossos adminitradores atrav�s do {FF0000}/duvida\n");
    Dialog_Show(playerid, DiscordSincronizacao, DIALOG_STYLE_INPUT, "{FF0000}Discord", Dialog, "Confirmar", "Cancelar");
    return 1;
}*/

stock VincularDiscord(playerid){
    if(Jogador[playerid][Level] < 3) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Voc� precisa ter no m�nimo level 3");
    new Dialog[900];
    strcat(Dialog, "{FFFFFF}Coloque abaixo seu {FF0000}Discord ID\n\n\n");
    strcat(Dialog, "{FFFFFF}Como fa�o para pegar meu discord id?\n\n");
    strcat(Dialog, "{FFFF00}Computador:\n");
    strcat(Dialog, "{00BFFF}1. {FFFFFF}V� nas configura��es do seu discord\n");
    strcat(Dialog, "{00BFFF}2. {FFFFFF}V� em {00BFFF}Apar�ncia{FFFFFF} e {00BFFF}Habilite o Modo Desenvolvedor\n");
    strcat(Dialog, "{00BFFF}3. {FFFFFF}V� no servidor do discord da rippzy city\n");
    strcat(Dialog, "{00BFFF}4. {FFFFFF}Clique com bot�o direito no seu perfil no discord da {00BFFF}Rippzy City\n");
    strcat(Dialog, "{00BFFF}5. {FFFFFF}Clique em Copiar ID\n\n");
    strcat(Dialog, "{FFFF00}Celular Android/IOS:\n");
    strcat(Dialog, "{00BFFF}1. {FFFFFF}V� nas configura��es do seu discord\n");
    strcat(Dialog, "{00BFFF}2. {FFFFFF}V� em {00BFFF}Comportamento{FFFFFF} e {00BFFF}Habilite o Modo Desenvolvedor\n");
    strcat(Dialog, "{00BFFF}3. {FFFFFF}V� no servidor do discord da rippzy city\n");
    strcat(Dialog, "{00BFFF}4. {FFFFFF}Clique com bot�o direito no seu perfil no discord da {00BFFF}Rippzy City\n");
    strcat(Dialog, "{00BFFF}5. {FFFFFF}Clique em Copiar ID\n\n");
    strcat(Dialog, "{FFFFFF}Caso necessite de ajuda, chame um dos nossos adminitradores atrav�s do {FF0000}/duvida\n");
    Dialog_Show(playerid, DiscordSincronizacao, DIALOG_STYLE_INPUT, "{FF0000}Discord", Dialog, "Confirmar", "Cancelar");
    return 1;  
}