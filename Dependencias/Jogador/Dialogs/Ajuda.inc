Dialog:AjudaMenu(playerid, response, listitem, inputtext[])
{  
    if(!response) return 1; 
    new Dialog[2000];
    switch(listitem)
    {
        case 0:
        {
            strcat(Dialog, "{f76d23}/Admins{FFFFFF} - Para visualizar administradores online no momento\n");
            strcat(Dialog, "{f76d23}/Configuracao{FFFFFF} - Para configurar seu jogo\n");
            strcat(Dialog, "{f76d23}/Garagem{FFFFFF} - Para configurar ou conectar seu veículo pessoal\n");
            strcat(Dialog, "{f76d23}/Acessorios{FFFFFF} - Para personalizar seu personagem com acessórios\n");
            //strcat(Dialog, "{f76d23}/Discord{FFFFFF} - Para vincular sua conta do servidor com o discord\n");
            strcat(Dialog, "{f76d23}/MeuLevel{FFFFFF} - Para visualizar seu level\n");
            strcat(Dialog, "{f76d23}/Profissao{FFFFFF} - Para visualizar informações da sua profissão\n");
            strcat(Dialog, "{f76d23}/Contratar [ID]{FFFFFF} - Para colocar um contrato de um(a) determinado(a) jogador(a)\n");
            strcat(Dialog, "{f76d23}/Gps{FFFFFF} - Para visualizar locais do mapa [Apenas para leveis menor que 6]\n");
            strcat(Dialog, "{f76d23}/Paramedicos - /Advogados{FFFFFF} - Para visualizar lista membros da profissão online\n");
            strcat(Dialog, "{f76d23}/190 [Mensagem] - /192 [Mensagem]{FFFFFF} - Para chamar um serviço médico ou polícial\n");
            strcat(Dialog, "{f76d23}/Identidade{FFFFFF} - Para visualizar suas informações\n");
            strcat(Dialog, "{f76d23}/Recompensas{FFFFFF} - Para visualizar recompensas ganha no servidor\n");
            strcat(Dialog, "{f76d23}/Relatorio{FFFFFF} - Para reportar um determinado jogador\n");
            strcat(Dialog, "{f76d23}/Duvida{FFFFFF} - Para fazer uma pergunta para um administrador\n");
            strcat(Dialog, "{f76d23}/Bug{FFFFFF} - Para pedir há um administrador para desbuga-lo\n");
            strcat(Dialog, "{f76d23}/CoresID{FFFFFF} - Para visualizar os ID's das cores\n");
            strcat(Dialog, "{f76d23}/MudarSenha{FFFFFF} - Para alterar sua senha\n");
            strcat(Dialog, "{f76d23}/MudarNick{FFFFFF} - Para alterar seu nick\n");
            strcat(Dialog, "{f76d23}/Loja{FFFFFF} - Para comprar ou ativar seus coins\n"); 
            strcat(Dialog, "{f76d23}/Utilitarios{FFFFFF} - Para visualizar seus utilitários\n");
            strcat(Dialog, "{f76d23}/VantagensVip{FFFFFF} - Para visualizar vantagens do VIP\n");
            strcat(Dialog, "{f76d23}/VantagensNitro{FFFFFF} - Para visualizar vantagens do Nitro Boost\n");
            strcat(Dialog, "{f76d23}/Live{FFFFFF} - Para ocultar/mostrar o status\n");
            strcat(Dialog, "{f76d23}/Transferir [ID] [Valor]{FFFFFF} - Para transferir dinheiro para um(a) jogador(a)\n");
            strcat(Dialog, "{f76d23}/Ausentes{FFFFFF} - Para visualizar jogadores(as) ausentes\n");
            strcat(Dialog, "{f76d23}/Creditos{FFFFFF} - Para visualizar usuários que ajudaram no desenvolvimento do servidor");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Comandos", Dialog, "Fechar", "");
        }
        case 1:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/ComprarCasa{FFFFFF} - Para comprar a casa\n");
            strcat(Dialog, "{f76d23}/Moveis{FFFFFF} - Para visualizar seus móveis\n");
            strcat(Dialog, "{f76d23}/MenuCasa{FFFFFF} - Para configurar sua casa ( Mensagem, Moradores etc.. )\n\n");
            strcat(Dialog, "{FF0000}Observações:\n");
            strcat(Dialog, "{FFFFFF}1. Após à compra da casa ela ficará bloqueada de ser vendida por 7 dias\n");
            strcat(Dialog, "{FFFFFF}2. Conforme que você vai upando o interior da casa, ela vai suportando mais moradores(as) até totalizar 6 moradores(as)\n");
            strcat(Dialog, "{FFFFFF}3. Caso deixe acumular muitos lixos ou impostos, sua casa será liberada para o servidor\n\n");
            strcat(Dialog, "{FF0000}Impotos e Lixos:\n");
            strcat(Dialog, "{FFFFFF}Para remover o lixo vá até HQ de gari e pague para removerem o lixo\n");
            strcat(Dialog, "{FFFFFF}Para pagar os impostos vá até a prefeitura");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Casas", Dialog, "Fechar", "");
        }
        case 2:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/MenuEmpresa{FFFFFF} - Para visualizar as informações da empresa\n");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Empresas", Dialog, "Fechar", "");   
        }
        case 3:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}! [Mensagem]{FFFFFF} - Para enviar mensagem no chat-base\n");
            strcat(Dialog, "{f76d23}/Menubase{FFFFFF} - Para visualizar as informações e configurações\n");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Bases", Dialog, "Fechar", "");   
        }
        case 4:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/Garagem{FFFFFF} - Para visualizar todos seus veículos\n\n");
            strcat(Dialog, "{FF0000}Comprar de Veículos\n");
            strcat(Dialog, "{FFFFFF}Use {f76d23}/Gps{FFFFFF} > {00BFFF}Escolha sua região{FFFFFF} > {00BFFF}Concessionária 1 ou 2\n");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Veículos", Dialog, "Fechar", "");   
        }
        case 5:
        {
            strcat(Dialog, "{FFFFFF}Celular\n");
            strcat(Dialog, "Mochila\n");
            strcat(Dialog, "Sacos\n");
            strcat(Dialog, "Gps\n");
            strcat(Dialog, "MP4/Som Veículo\n");
            strcat(Dialog, "Acessórios\n");
            strcat(Dialog, "Galão de Gasolina\n");
            strcat(Dialog, "Água\n");
            strcat(Dialog, "Kit de Reparos\n");
            strcat(Dialog, "Lockpick\n");
            strcat(Dialog, "Dinamite\n");
            Dialog_Show(playerid, DialogUtiliHelp, DIALOG_STYLE_TABLIST, "{FF0000}Utilitários", Dialog, "Fechar", "");   
        }
        case 6:
        {
            strcat(Dialog, "{FF0000}Arenas\n");
            strcat(Dialog, "{FFFFFF}Para acessar uma arena você precisa ser {f76d23}level 20{FFFFFF} no mínimo\n");
            strcat(Dialog, "{FF0000}Modos\n");
            strcat(Dialog, "{FFFFFF}Para acessar um modo você precisa ser {f76d23}level 10{FFFFFF} no mínimo\n");
            strcat(Dialog, "{FFFFFF}Obs: Mapas são trocados a cada 5 minutos após finalização da partida\n\n");
            strcat(Dialog, "{FFFFFF}Você pode acessar esses modos de jogo indo até uma das {00BFFF}3 arenas{FFFFFF} espalhadas pelo mapa\n\n");
            strcat(Dialog, "{FF0000}Comandos\n");
            strcat(Dialog, "{FFFFFF}/ArenaExpulsar [ID] - Para expulsar um(a) determinado(a) jogador(a) da arena\n");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Arenas", Dialog, "Fechar", "");       
        }
        case 7:
        {   
            strcat(Dialog, "{FFFFFF}Vip\n");
            strcat(Dialog, "{FFFFFF}Nitro Boost");
            Dialog_Show(playerid, DialogAjudaNitroVIP, DIALOG_STYLE_TABLIST, "{FF0000}Nitro e VIP", Dialog, "Fechar", ""); 
        }
        case 8: return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Desativado pela desenvolvedor");
        case 9:
        {
            strcat(Dialog, "{FF0000}Ajuda\n");
            strcat(Dialog, "{CCCCCC}/TopGrana{FFFFFF} - Para visualizar os Top's Granas\n");
            strcat(Dialog, "{CCCCCC}/TopLevel{FFFFFF} - Para visualizar os Top's Leveis\n");
            strcat(Dialog, "{CCCCCC}/TopCoins{FFFFFF} - Para visualizar os Top's Coins\n");
            strcat(Dialog, "{CCCCCC}/TopProcurados{FFFFFF} - Para visualizar os Top's Procurados\n");
            strcat(Dialog, "{CCCCCC}/TopPrisoes{FFFFFF} - Para visualizar os Top's Prisões\n");
            strcat(Dialog, "{CCCCCC}/TopArena{FFFFFF} - Para visualizar os Top's Arena\n");
            strcat(Dialog, "{CCCCCC}/TopVips{FFFFFF} - Para visualizar os Top's Vips\n");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Rank's", Dialog, "Fechar", "");  
        }
        case 10:
        {
            strcat(Dialog, "{FFFFFF}Discord: {FFA500}discord.gg/knNHxTy\n");
            strcat(Dialog, "{FFFFFF}Instagram: {FFA500}@rippzycity\n");
            strcat(Dialog, "{FFFFFF}Site: {FF0000}Em breve\n");
            strcat(Dialog, "{FFFFFF}Fórum: {FF0000}Em breve\n");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Contato", Dialog, "Fechar", "");      
        }
        case 11:
        {
            strcat(Dialog, "Uber\n");
            strcat(Dialog, "Assaltante\n");
            strcat(Dialog, "Produtor da Máfia\n");
            Dialog_Show(playerid, DialogHobbieAjuda, DIALOG_STYLE_TABLIST, "{FF0000}Hobbie", Dialog, "Selecionar", "Fechar");      
        }
    }
    return 1;
}

Dialog:DialogHobbieAjuda(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[1000];
    switch(listitem)
    {
        case 0:
        {
            strcat(Dialog, "{FFFFFF}/IniciarUber - {e2b960}Para iniciar/parar o trabalho\n");
            strcat(Dialog, "{FFFFFF}/Aceitar [ID] - {e2b960}Para aceitar um chamado\n\n");
            strcat(Dialog, "{FF4500}Observação: Para cancelar use o /Celular > Uber > Cancelar");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Uber", Dialog, "Fechar", "");    
        }
        case 1:
        {
            strcat(Dialog, "{FFFFFF}/AssaltarCaixa - {e2b960}Para explodir um determinado caixa eletrônico\n");
            strcat(Dialog, "{FFFFFF}/Assaltar [ID] - {e2b960}Para assaltar um(a) jogador(a)");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Assaltante", Dialog, "Fechar", "");    
        }
        case 2:
        {
            strcat(Dialog, "{FFFFFF}Você precisa localizar o local no GPS na Aba 'Máfia'\n");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Produtor da Máfia", Dialog, "Fechar", "");    
        }
    }
    return 1;
}

Dialog:DialogUtiliHelp(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[1000];
    switch(listitem)
    {
        case 0:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/Celular{FFFFFF} - Para abrir o celular\n");
            strcat(Dialog, "{f76d23}/t{FFFFFF} - Para enviar um telegram\n");
            strcat(Dialog, "{f76d23}/BloquearTelegram{FFFFFF} - Para bloquear o telegram");
            //strcat(Dialog, "{f76d23}/Sms [ID ou Nick] [Mensagem]{FFFFFF} - Você pode enviar mensagem para um(a) jogador(a)\n");
            //strcat(Dialog, "{f76d23}/Ligar [ID ou Nick] - Para fazer uma ligação para um(a) determinado(a) jogador(a)\n");
            //strcat(Dialog, "{f76d23}/BloquerSms [ID]{FFFFFF} - Para bloquear SMS de um(a) determinado(a) jogador(a)\n");
            //strcat(Dialog, "{f76d23}/Atender - Para atender uma ligação\n");
            //strcat(Dialog, "{f76d23}/Desligar - Para desligar uma ligação\n\n");
            //strcat(Dialog, "{FF0000}Observação\n");
            //strcat(Dialog, "{FFFFFF}Você precisa de créditos para enviar mensagens");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Celular", Dialog, "Fechar", "");     
        }
        case 1:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/Mochila{FFFFFF} - Para abrir a mochila");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Mochila", Dialog, "Fechar", "");      
        }
        case 2: SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa opção não foi adicionada pelo desenvolvedor");
        case 3:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/Gps{FFFFFF} - Para localizar um determinado local do mapa\n\n");
            strcat(Dialog, "{FF0000}Observação\n");
            strcat(Dialog, "{FFFFFF}Você pode localizar apenas locais públicos pelo mapa");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Gps", Dialog, "Fechar", "");  
        }
        case 4:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/Radios{FFFFFF} - Para escutar rádios a qualquer momento\n");
            strcat(Dialog, "{f76d23}/Som{FFFFFF} - Para ligar rádio em seu veículo ( Todos perto escutam )\n\n");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Rádio/Música", Dialog, "Fechar", "");  
        }
        case 5:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/Acessorios{FFFFFF} - Para adicionar ou modificar um acessórios\n\n");
            strcat(Dialog, "{FF0000}Observação\n");
            strcat(Dialog, "{FFFFFF}Você pode comprar acessórios em lojas de skins");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Acessórios", Dialog, "Fechar", "");  
        }
        case 6: 
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/Reabastecer{FFFFFF} - Para reabastecer um veículo sem gasolina\n\n");
            strcat(Dialog, "{FF0000}Observação\n");
            strcat(Dialog, "{FFFFFF}Você pode comprar o galão de combustível em lojas de utiliários");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Galão de Gasolina", Dialog, "Fechar", "");       
        }
        case 7:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/Regar{FFFFFF} - Caso você seja plantador(a) você pode regar suas mudas");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Água", Dialog, "Fechar", "");  
        }
        case 8:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/Consertar{FFFFFF} - Caso um veículo perto de você esteja quebrado você pode repara-lo");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Água", Dialog, "Fechar", "");  
        }
        case 9:
        {
            strcat(Dialog, "{FF0000}Comandos:\n");
            strcat(Dialog, "{f76d23}/UsarLockpick{FFFFFF} - Para destrancar um determinado veículo trancado");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Lockpick", Dialog, "Fechar", "");    
        }
        case 10:
        {
            strcat(Dialog, "{FF0000}Observação\n");
            strcat(Dialog, "{FFFFFF}Dinamites podem ser usadas para explodir caixas, cofre de bancos e fazer atentados.");
            Dialog_Show(playerid, DialogFalsa, DIALOG_STYLE_MSGBOX, "{FF0000}Dinamites", Dialog, "Fechar", "");    
        }
    }
    return 1;
}

Dialog:DialogAjudaNitroVIP(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: cmd_comandosvip(playerid); 
        case 1: cmd_comandosnitro(playerid); 
    }
    return 1;
}