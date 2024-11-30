#include <YSI_Coding\y_hooks>

new DelayDuvida[MAX_PLAYERS];
new DelayDuvidaVip[MAX_PLAYERS];

new DelayAjuda[MAX_PLAYERS];
new DelayAjudaVip[MAX_PLAYERS];

new ReporteDelay[MAX_PLAYERS];

CMD:admins(playerid)
{
    //if(Jogador[playerid][Admin] < 1) return 0;
    new Lista[900];
    new Contador = 0;
    strcat(Lista, "Admin\tCargo\tStatus\n");
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Admin] < 1) continue;
        if(pAdmin[i][Camuflado] == true && Jogador[playerid][Admin] > 1)
        {
            strcatEx(Lista, "%s\t%s\t{DC143C}Camuflado(a)\n", PegarNick(i), CargoAdmin(1, i)); 
            Contador++; 
        }
        else if(pAdmin[i][Camuflado] == false)
        {
            strcatEx(Lista, "%s\t%s\t{00FF00}Online\n", PegarNick(i), CargoAdmin(1, i));
            Contador++;   
        }
    }

    new Teste[128];
    format(Teste, sizeof(Teste), "Administrador(es): {00FA9A}%d", Contador);
    if(Contador > 0) Dialog_Show(playerid, AdminsOnline, DIALOG_STYLE_TABLIST_HEADERS, Teste, Lista, "Confirmar", #);  
    else Dialog_Show(playerid, AdminsOnline, DIALOG_STYLE_MSGBOX, Teste, "{FF0000}Não há administradores online nesse momento!", "Fechar", #); 
    return 1;
}

CMD:duvida(playerid, params[])
{
    if(Jogador[playerid][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando!");
    new Mensagem[90];
    if(sscanf(params, "s[90]", Mensagem)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Duvida [Mensagem]");
    if(strlen(Mensagem) > 55) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Mensagem muito longa!");

    new DuvidaMensagem[300],
        Contador = 0,
        bool:VipVerificacao = false;

    if(Jogador[playerid][Vip] > gettime()){
        if(DelayDuvidaVip[playerid] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Dúvida VIP está congestionada, aguarde um pouco.");
        format(DuvidaMensagem, sizeof(DuvidaMensagem), "| DÚVIDA-VIP | O(A) Jogador(a) {FF8C00}%s[%d]{FFFFFF} perguntou ( {e82741}%s{FFFFFF} )", PegarNick(playerid), playerid, Mensagem);
        VipVerificacao = true;
    }
    else{
        if(DelayDuvida[playerid] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Dúvida está congestionada, aguarde um pouco.");
        format(DuvidaMensagem, sizeof(DuvidaMensagem), "| DÚVIDA | O(A) Jogador(a) {FF8C00}%s[%d]{FFFFFF} perguntou ( {ff1232}%s{FFFFFF} )", PegarNick(playerid), playerid, Mensagem);
    }


    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Admin] < 1) continue;
        SendClientMessage(i, -1, DuvidaMensagem);
        Contador++;
    }  
 
    if(Contador > 0){
        SendClientMessage(playerid, -1, "| DÚVIDA | Sua dúvida foi enviada com sucesso!");
        if(VipVerificacao == true) DelayDuvidaVip[playerid] = gettime()+60;
        else DelayDuvida[playerid] = gettime()+65;
    }
    else SendClientMessage(playerid, -1, "| ERRO | Não há administradores, sua dúvida não foi enviada.");
    return 1;
}

CMD:bug(playerid, params[])
{
    new Mensagem[128];
    if(sscanf(params, "s[128]", Mensagem)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /bug [Pedido de Ajuda]");
    if(strlen(Mensagem) > 80) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu pedido de ajuda está muito grande!");
    
    new HelpMensagem[300],
        Contador = 0,
        bool:VipVerificacao = false;

    if(Jogador[playerid][Vip] > gettime()){
        if(DelayAjudaVip[playerid] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco antes de enviar!");
        format(HelpMensagem, sizeof(HelpMensagem), "| BUG-VIP | O(A) Jogador(a) {FF8C00}%s[%d]{FFFFFF} está pedindo ajuda ( {7221ff}%s{FFFFFF} )", PegarNick(playerid), playerid, Mensagem);
        VipVerificacao = true;
    }
    else
    {
        if(DelayAjuda[playerid] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco antes de enviar!");
        format(HelpMensagem, sizeof(HelpMensagem), "| BUG | O(A) Jogador(a) {FF8C00}%s[%d]{FFFFFF} está pedindo ajuda ( {9457ff}%s{FFFFFF} )", PegarNick(playerid), playerid, Mensagem);
    }

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Admin] < 1) continue;
        SendClientMessage(i, -1, HelpMensagem);
        Contador++;
    }  
 
    if(Contador > 0)
    {
        SendClientMessage(playerid, -1, "| BUG | Seu pedido de ajuda foi enviado com sucesso!");
        if(VipVerificacao == true) DelayAjudaVip[playerid] = gettime()+20;
        else DelayAjuda[playerid] = gettime()+30;
    }
    else SendClientMessage(playerid, -1, "| ERRO | Não há administradores online no momento, seu pedido de ajuda foi cancelado");
    return 1;
}

CMD:relatorio(playerid, params[])
{
    if(Jogador[playerid][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando!");
    new id, relatorio[228];
    if(sscanf(params, "ds[128]", id, relatorio)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Relatorio [ID] [Motivo]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se reportar!");
    if(Jogador[id][Admin] > 0 && pAdmin[id][FalsoPlayer] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode reportar um membro da equipe!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não encontrado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)!");
    if(ReporteDelay[playerid] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
    if(strlen(relatorio) > 50) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu relatório está muito longo");

    new MensagemRelatorio[300];
    new Contador = 0;

    ReporteDelay[playerid] = gettime()+30;

    format(MensagemRelatorio, sizeof(MensagemRelatorio), "| RELATÓRIO | O(A) Jogador(a) {FF0000}%s[%d]{FFFFFF} reportou {FF0000}%s[%d]{FFFFFF} ( Motivo: {f27522}%s{FFFFFF} )", PegarNick(playerid), playerid, PegarNick(id), id, relatorio);
    for(new i; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Admin] < 2) continue;
        SendClientMessage(i, -1, MensagemRelatorio);
        Contador++;  
    }

    if(Contador > 0) SendClientMessage(playerid, -1, "| RELATÓRIO | Seu relatório foi enviado com sucesso");
    else SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há administradores online no momento");
    return 1;
}

CMD:creditos(playerid)
{
    new Dialog[800];
    strcat(Dialog, "\t\tAgradecimentos\n\n");
    strcat(Dialog, "{FFFFFF}Kettler e LinzYh ( {FF4500}Construções no Mapa{FFFFFF} )\n");
    strcat(Dialog, "{FFFFFF}Nelson ( {FF4500}Ajuda na organização do código{FFFFFF} )\n");
    strcat(Dialog, "{FFFFFF}Isabella ( {FF4500}Proteção contra cheaters{FFFFFF} )\n");
    strcat(Dialog, "{FFFFFF}Masked ( {FF4500}Template do Email{FFFFFF} )\n");
    strcat(Dialog, "{FFFFFF}Foolish ( {FF4500}Correções no Mysql{FFFFFF} )\n");
    strcat(Dialog, "{FFFFFF}Paulo e MichaelS ( {FF4500}Adicionarem casas/empresas pelo Servidor{FFFFFF} )\n");
    strcat(Dialog, "{FFFFFF}Cowboy ( {FF4500}Posicionamento de câmeras nas concessionárias{FFFFFF} )\n");
    strcat(Dialog, "{FFFFFF}Kannario ( {FF4500}Assessoria de comunicação{FFFFFF} )\n");
    strcat(Dialog, "{FFFFFF}Klaus, Desper e MarcosL ( {FF4500}Por reportar problemas no beta/desenvolvimento{FFFFFF} )\n\n");
    strcat(Dialog, "{FFFFFF}( Servidor desenvolvido e fundado por {00BFFF}blueN{FFFFFF} )");
    Dialog_Show(playerid, CreditosRippzypp, DIALOG_STYLE_MSGBOX, "{FFFFFF}Créditos", Dialog, "Fechar", #);
    return 1;
}

CMD:identidade(playerid)
{
    new Identidade[900];
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Nome: {32CD32}%s\n", PegarNick(playerid));
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Level: {32CD32}%s\n", DinheiroSeparar(Jogador[playerid][Level]));
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Experiência: {32CD32}%d\n", Jogador[playerid][Experiencia]);
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Profissão: {32CD32}%s\n", Jogador[playerid][Profissao]);
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Doença: {FA8072}%s\n", Doencas[Jogador[playerid][Doenca]][DoencaNome]); 
    // strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Dinheiro Sujo: {fc031c}$%s\n", DinheiroSeparar(Jogador[playerid][DinheiroSujo]));
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Sexo: %s\n", JogadorSexo(1, playerid));
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Skin: {32CD32}%d\n", Jogador[playerid][Skin]);
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Vacina: {32CD32}%s\n", SegundosParaMinutos(Jogador[playerid][Vacina])); 
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Vip: %s\n", IsVip(playerid) ? ("{32CD32}Sim") : ("{FF4500}Não"));
    if(strcmp(Jogador[playerid][Casado], "*")) strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Casado(a): %s\n", Jogador[playerid][Casado]);
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Coins: {32CD32}%s\n", DinheiroSeparar(Jogador[playerid][Coins]));
    if(Jogador[playerid][pNumero] != 0) strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Número: {32CD32}%s\n", NumeroSeparar(Jogador[playerid][pNumero]));
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Aviso(s): {FF0000}%d\n", Jogador[playerid][Avisos]);
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Registro(s): {00FF00}%s\n", ConverterSegundosEx(gettime()-Jogador[playerid][Registro]));
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Email: {00FF00}%s\n\n", Jogador[playerid][Email]);
    /*strcat(Identidade, "{FFFFFF}Diversos:\n");
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Adubos: {32CD32}%d\n", Jogador[playerid][Adubos]);
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Águas: {32CD32}%d\n", Jogador[playerid][Agua]);
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Kit de Reparos: {32CD32}%d\n", Jogador[playerid][KitReparos]);
    strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Kit Médico: {32CD32}%d\n", Jogador[playerid][KitMedico]);
    //strcatEx(Identidade, "{1C1C1C}» {FFFFFF}Caixas: {32CD32}%d", Jogador[playerid][PandoraCaixa]);*/
    Dialog_Show(playerid, IdentidadeRipzRC, DIALOG_STYLE_MSGBOX, "{FF0000}Sua Identidade", Identidade, "Fechar", #);
    return 1;
}

CMD:recompensas(playerid)
{
    new Enviar[128],
        Cache:Conectar;
    format(Enviar, sizeof(Enviar), "SELECT * FROM `recompensas` WHERE `Nome` = '%s'", PegarNick(playerid));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não foi possível carregar suas recompensas!");
    new Contador = cache_num_rows();
    if(Contador < 1)
    {
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui recompensas!");
        cache_delete(Conectar);
        return 1;
    }

    new Dialog[900],
        NomeRecompensa[70],
        Recompensa[128],
        Data;
    strcat(Dialog, "Nome\tRecompensa\tData\n");
    for(new i=0; i < Contador; i++)
    {
        cache_get_value(i, "Nome", NomeRecompensa, 70);
        cache_get_value(i, "Recompensa", Recompensa, 128);
        cache_get_value_name_int(i, "Data", Data);
        strcatEx(Dialog, "{00FF00}%s\t%s\t{FF0000}%s\n", NomeRecompensa, Recompensa, GetDateFromTime(Data));
    }
    cache_delete(Conectar);
    Dialog_Show(playerid, RecompensaRippzyDia, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Recompensas", Dialog, "Fechar", #);
    return 1;
}

CMD:profissao(playerid)
{
    if(IsMafia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão, Use: /Anotacao");
    MostrarComandos(playerid);
    return 1;
}

CMD:anotacao(playerid)
{
    if(!IsMafia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão, Use: /Profissao");
    MostrarComandos(playerid);
    return 1;
}

CMD:garagem(playerid)
{
    new Dialog[1500];
    strcat(Dialog, "Veículo\tPlaca\tEstado\n");  
    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0)
        {
            if(pVeiculo[playerid][i][VehConectado] == true) strcatEx(Dialog, "%d. {FFFFFF}Veículo: {FF0000}%s\t{FF4500}%s\t{00FF00}Conectado\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]), pVeiculo[playerid][i][Placa]);
            else if(pVeiculo[playerid][i][Patio] > 0) strcatEx(Dialog, "%d. {FFFFFF}Veículo: {FF0000}%s\t{FF4500}%s\t{FFFF00}Apreendido\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]), pVeiculo[playerid][i][Placa]);
            else if(pVeiculo[playerid][i][VehConectado] == false) strcatEx(Dialog, "%d. {FFFFFF}Veículo: {FF0000}%s\t{FF4500}%s\t{FF0000}Desconectado\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]), pVeiculo[playerid][i][Placa]);    
        }
        else strcatEx(Dialog, "%d. {FFFFFF}Veículo: {FF0000}N/A\n", i);   
        if(i == 2){
            if(Jogador[playerid][Vip] < gettime()){
                break;
            }
        }
    }
    Dialog_Show(playerid, MenuVeiculo, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Seus Veículos", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:ajuda(playerid)
{
    new Dialog[400];
    strcat(Dialog, "{FFFFFF}Comandos\n");
    strcat(Dialog, "Casa\n");
    strcat(Dialog, "Empresa\n");
    strcat(Dialog, "Bases\n");
    strcat(Dialog, "Veículo\n");
    strcat(Dialog, "Utilitários\n");
    strcat(Dialog, "Arena/Modos\n");
    strcat(Dialog, "Vip e Nitro\n");
    strcat(Dialog, "Telefone Público\n");
    strcat(Dialog, "Ranks\n");
    strcat(Dialog, "Contato\n");
    strcat(Dialog, "Hobbies\n");
    Dialog_Show(playerid, AjudaMenu, DIALOG_STYLE_TABLIST, "{FF0000}Ajuda", Dialog, "Selecionar", "Fechar"); 
    return 1;
}

CMD:meulevel(playerid)
{
    new Dialog[200];
    strcatEx(Dialog, "{FFFFFF}Level: {00BFFF}%d\n", Jogador[playerid][Level]);
    strcatEx(Dialog, "{FFFFFF}Experiência: {FF8C00}%d", Jogador[playerid][Experiencia]);
    Dialog_Show(playerid, SeuLevelInfo, DIALOG_STYLE_MSGBOX, "{FF0000}Seu Level", Dialog, "Fechar", "");
    return 1;
}

CMD:vantagensvip(playerid)
{
    new Dialog[1000];
    strcat(Dialog, "{FF0000}Comandos:\n");
    strcat(Dialog, "{f76d23}/Jetpack{FFFFFF} - Para pegar uma jetpack\n");
    strcat(Dialog, "{f76d23}/Pintar{FFFFFF} - Para alterar a cor de um veículo\n");
    strcat(Dialog, "{f76d23}/Virar{FFFFFF} - Para descapotar o veículo\n");
    strcat(Dialog, "{f76d23}/Continuar{FFFFFF} - Para retornar para sua última posição\n");
    strcat(Dialog, "{f76d23}/Reparar{FFFFFF} - Para reparar seu veículo em qualquer lugar\n\n");
    strcat(Dialog, "{FFFF00}Geral:\n");
    strcat(Dialog, "{FFFFFF}1. Não paga pelo test-drive e ganha {FFFF00}+2 minutos{FFFFFF} para testar\n");
    strcat(Dialog, "{FFFFFF}2. Nos modos de jogo você ganha {FFFF00}+3 armas{FFFFFF} diferente para combater o inimigo\n");
    strcat(Dialog, "{FFFFFF}3. {00BFFF}+7 Slots{FFFFFF} para veículos no {f76d23}/garagem\n");
    strcat(Dialog, "{FFFFFF}4. Cada UP com será com {00BFFF}5 de experiência\n");
    strcat(Dialog, "{FFFFFF}Mais informações poderá ser encontrada no discord.");
    Dialog_Show(playerid, Vantagensvipmenue, DIALOG_STYLE_MSGBOX, "{FF0000}Vantagens VIP", Dialog, "Fechar", "");
    return 1;
}

CMD:vantagensnitro(playerid)
{
    new Dialog[1000];
    strcat(Dialog, "{FF0000}Comandos:\n");
    strcat(Dialog, "{f76d23}/Jetpack{FFFFFF} - Para pegar uma jetpack\n");
    strcat(Dialog, "{f76d23}/Virar{FFFFFF} - Para descapotar o veículo\n\n");
    strcat(Dialog, "{FFFF00}Geral:\n");
    strcat(Dialog, "{FFFFFF}1. Você tem acesso algumas áreas exclusivas do mapa\n");
    strcat(Dialog, "{FFFFFF}2. Você acesso para comprar acessórios na loja de skins");
    Dialog_Show(playerid, Vantagensvipmenue, DIALOG_STYLE_MSGBOX, "{FF0000}Vantagens Nitro", Dialog, "Fechar", "");
    return 1;
}


CMD:mudarnick(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5){
        if(Jogador[playerid][Coins] < 8000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem 8.000 de coins");
    }

    new Dialog[300];
    strcat(Dialog, "{FFFFFF}Você está alterando seu nick\n");
    strcatEx(Dialog, "Você tem {FFFF00}$%s{FFFFFF} de coins, depois que alterar ficará com {FF0000}$%s\n\n", DinheiroSeparar(Jogador[playerid][Coins]), DinheiroSeparar(Jogador[playerid][Coins]-8000));
    strcat(Dialog, "{FFFF00}Coloque abaixo seu novo nick que deseja utilizar");
    Dialog_Show(playerid, RegistrarNovoNick, DIALOG_STYLE_INPUT, "{FF0000}Alterar Nick", Dialog, "Confirmar", "Cancelar");
    return 1;
}

CMD:mudarsenha(playerid, params[])
{
    Dialog_Show(playerid, RegistraNovaSenha, DIALOG_STYLE_INPUT, "{FF0000}Alterar Senha", "Coloque abaixo sua nova senha", "Confirmar", "Cancelar");
    return 1;
}

CMD:coresid(playerid)
{
    ShowVehColorListForPlayer(playerid);
    return 1;
}

CMD:verilegal(playerid)
{
    new Dialog[700];
    strcatEx(Dialog, "{FF6347}Drogas: {FFFFFF}%d\n", Jogador[playerid][Drogas]);
    strcatEx(Dialog, "{FF6347}Vasos: {FFFFFF}%d\n", Jogador[playerid][Vasos]);
    strcatEx(Dialog, "{FF6347}Sementes: {FFFFFF}%d\n", Jogador[playerid][Sementes]);
    strcatEx(Dialog, "{FF6347}LockPicks: {FFFFFF}%d\n", Jogador[playerid][LockPick]);
    strcatEx(Dialog, "{FF6347}Cápsulas: {FFFFFF}%d\n", Jogador[playerid][Capsulas]);
    strcatEx(Dialog, "{FF6347}Peças: {FFFFFF}%d\n", Jogador[playerid][Pecas]);
    strcatEx(Dialog, "{FF6347}Dinamites: {FFFFFF}%d", Jogador[playerid][Dinamites]);
    Dialog_Show(playerid, FialozDSA1SD, DIALOG_STYLE_MSGBOX, "{FF0000}Ilegal", Dialog, "Fechar", "");
    return 1;
}

CMD:beco(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Plantador de Maconha")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    EnviarGps(playerid, 2445.4421,-1970.0737,13.5469);
    SendClientMessage(playerid, -1, "| MAFIA | Foi marcado em seu mapa o beco");
    return 1;
}

CMD:hq(playerid)
{
    if(!strcmp(Jogador[playerid][Profissao], "Desempregado")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem profissão");
    for(new i=0; i < sizeof(pAgencia); i++)
    {
        if(strcmp(Jogador[playerid][Profissao], pAgencia[i][ProfissaoNome])) continue;
        EnviarGps(playerid, pAgencia[i][HQx], pAgencia[i][HQy], pAgencia[i][HQz]);
        SendClientMessage(playerid, -1, "| GPS | Foi marcado em seu mapa a sua HQ");
        break;
    }
    return 1;
}

CMD:gp(playerid, params[])
{
    if(Jogador[playerid][TagPersonalizada] != 6) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    new MsgAA[70];
    if(sscanf(params, "s[70]", MsgAA)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Gp [Mensagem]");

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| CHAT-GIRL | %s[%d] disse: %s", PegarNick(playerid), playerid, MsgAA);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][TagPersonalizada] != 6 && Jogador[i][Admin] < 2) continue;
        SendClientMessage(i, 0xFF69B4FF, Mensagem);
    }

    return 1;
}

CMD:transferir(playerid, params[])
{
    if(Jogador[playerid][Level] < 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode transferir a partir do level 10");
    if(pTempo[playerid][TransferirMao] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode transferir, aguarde");
    new id, 
        vtrans
    ;
    if(sscanf(params, "dd", id, vtrans)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Transferir [ID] [Valor]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode transferir para si mesmo");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe!");
    if(vtrans > 5000 || vtrans < 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você pode transferir até $5.000");
    if(Jogador[playerid][Dinheiro] < vtrans) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem toda essa quantia na mão");
    if(Jogador[id][Level] < 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não transferir dinheiro para um(a) jogador(a) abaixo do level 5");

    // ApplyAnimation(playerid, "DEALER", "shop_pay", 4.1, 0, 0, 0, 0, 0, 1);
    // ApplyAnimation(id, "DEALER", "shop_pay", 4.1, 0, 0, 0, 0, 0, 1);

    pTempo[playerid][TransferirMao] = gettime()+300;
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| TRANSFERÊNCIA | Você recebeu $%s do(a) jogador(a) %s[%d]", DinheiroSeparar(vtrans), PegarNick(playerid), playerid);
    SendClientMessage(id, 0xFFFF00FF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| TRANSFERÊNCIA | Você enviou $%s para o(a) jogador(a) %s[%d]", DinheiroSeparar(vtrans), PegarNick(id), id);
    SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
    Jogador[playerid][Dinheiro] -= vtrans;
    Jogador[id][Dinheiro] += vtrans;
    return 1;
}

stock MostrarRadio(playerid)
{
    new DialogRadio[528];
    strcat(DialogRadio, "Rádio\n");
    strcat(DialogRadio, "Rádio Hunter\n");
    strcat(DialogRadio, "Rádio 80s\n");
    strcat(DialogRadio, "Rádio 90s\n");
    strcat(DialogRadio, "Rádio Kpop\n");
    strcat(DialogRadio, "Rádio Brega-Funk\n");
    strcat(DialogRadio, "Rádio Funk JP\n");
    strcat(DialogRadio, "Rádio Sertanejo\n");
    strcat(DialogRadio, "Rádio Funk Perfect\n");
    strcat(DialogRadio, "Rádio DJ Alok\n");
    strcat(DialogRadio, "Rádio Funk de Quebrada\n");
    strcat(DialogRadio, "Rádio Trap\n");
    strcat(DialogRadio, "Rádio Sad\n");
    strcat(DialogRadio, "Rádio Hitz\n");
    strcat(DialogRadio, "Rádio Rippzy\n");
    strcat(DialogRadio, "+ {FF0000}Desligar rádio\n");
    Dialog_Show(playerid, Radio, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}MP4", DialogRadio, "Selecionar", "Fechar");
    return 1;
}

CMD:t(playerid, params[])
{
    if(Jogador[playerid][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem celular");
    if(Jogador[playerid][Operadora] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem chip");
    if(GetPVarInt(playerid, "adasdasdasdasndma") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está com seu telegram bloqueado");

    new id, Mensagem[90];
    if(sscanf(params, "ds[90]", id, Mensagem)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /t [ID] [Mensagem]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode enviar para sí mesmo");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não tem celular");
    if(Jogador[id][Operadora] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não tem chip");
    if(Jogador[id][Preso] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) está preso(a)");
    if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode mandar telegram para admin");
    if(GetPVarInt(id, "adasdasdasdasndma") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Está com o telegram bloqueado");

    new Enviar[168];
    format(Enviar, sizeof(Enviar), "| TELEGRAM | Você enviou para %s[%d]: %s", PegarNick(id), id, Mensagem);
    SendClientMessage(playerid, 0x5d97f5FF, Enviar);

    format(Enviar, sizeof(Enviar), "| TELEGRAM | O(A) Jogador(a) %s[%d] enviou para você: %s", PegarNick(playerid), playerid, Mensagem);
    SendClientMessage(id, 0x5d97f5FF, Enviar);

    format(Enviar, sizeof(Enviar), "| TELEGRAM-ADMIN | O(A) Jogador(a) %s[%d] enviou para %s[%d]: %s", PegarNick(playerid), playerid, PegarNick(id), id, Mensagem);

    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] < 1) continue;
        if(pAdmin[i][VerTelegram] == false) continue;
        SendClientMessage(i, 0x5d97f5FF, Enviar);
    }
    return 1;
}

CMD:bloqueartelegram(playerid)
{
    if(Jogador[playerid][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem celular");
    if(GetPVarInt(playerid, "adasdasdasdasndma") == 0){
        SetPVarInt(playerid, "adasdasdasdasndma", 1);
        SendClientMessage(playerid, 0x5d97f5FF, "| TELEGRAM | Você bloqueou seu telegram");
        return 1;
    }
    SetPVarInt(playerid, "adasdasdasdasndma", 0);
    SendClientMessage(playerid, 0x5d97f5FF, "| TELEGRAM | Você desbloqueou seu telegram");
    return 1;
}

CMD:continuar(playerid)
{
    //if(Jogador[playerid][Vip] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(GetPVarInt(playerid, "TempoDoContinuar") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar esse comando");
    if(GetPVarInt(playerid, "TempoDoContinuar") < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode mais usar esse comando");
    SetPVarInt(playerid, "TempoDoContinuar", gettime()); 
    if(Jogador[playerid][uInterior] > 0) ForceSaida(playerid);
    else SetPlayerPos(playerid, Jogador[playerid][PosicaoX], Jogador[playerid][PosicaoY], Jogador[playerid][PosicaoZ]);
    SetPlayerFacingAngle(playerid,  Jogador[playerid][PosicaoA]);
    SendClientMessage(playerid, -1, "| CONTINUAR | Você voltou para sua última posição do seu último login.");
    return 1;
}

CMD:usarlockpick(playerid)
{
    if(Jogador[playerid][LockPick] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem lockpick's");
    if(GetPVarInt(playerid, "LASDLASLDSALDASL") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa aguardar um pouco");

    new Float:Cbe[3],
        bool:alod;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        for(new d=0; d < MAX_SLOT_VEH; d++)
        {
            if(pVeiculo[i][d][VehConectado] == false) continue;
            GetVehiclePos(pVeiculo[i][d][MeuVeiculoID], Cbe[0], Cbe[1], Cbe[2]);
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, Cbe[0], Cbe[1], Cbe[2])) continue;
            if(i == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode destrancar seu veículo");
            if(VeiculoServer[pVeiculo[i][d][MeuVeiculoID]][Tranca] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse veículo não está trancado");
        
            SetPVarInt(playerid, "LASDLASLDSALDASL", gettime()+120);
            Jogador[playerid][LockPick]--;
            Jogador[playerid][Estrelas] += 3;

            new Mensagem[168];
            format(Mensagem, sizeof(Mensagem), "| CENTRAL | %s[%d] está tentando destrancar um veículo em %s", PegarNick(playerid), playerid, GetPlayerZone(playerid));
            for(new p=0; p < MAX_PLAYERS; p++){
                if(!IsPlayerConnected(p)) continue;
                if(Jogador[p][Logado] == false) continue;
                if(!IsPolicia(p)) continue;
                if(pPolicia[p][PegouUniformePolicia] == false) continue;
                SendClientMessage(p, 0x1E90FFFF, Mensagem);
            }
            new rd = random(100);
            if(rd > 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu lockpick quebrou, tente novamente.");
            VeiculoServer[pVeiculo[i][d][MeuVeiculoID]][Tranca] = 0;
            SendClientMessage(playerid, 0xFFFF00FF, "| DESTRANCADO | Você destrancou o veículo.");
            alod = true;
            break;
        }
        if(alod == true) break;
    }
    if(alod == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode destrancar esse veículo");
    return 1;
}

CMD:utilitarios(playerid)
{
    new Dialog[400];
    strcatEx(Dialog, "{FFFFFF}Kit Reparos: {FFA500}%d\n", Jogador[playerid][KitReparos]);
    strcatEx(Dialog, "{FFFFFF}Kit Médicos: {FFA500}%d\n", Jogador[playerid][KitMedico]);
    strcatEx(Dialog, "{FFFFFF}Lockpick: {FFA500}%d\n", Jogador[playerid][LockPick]);
    strcatEx(Dialog, "{FFFFFF}Cilindro: {FFA500}%d\n", Jogador[playerid][Cilindro]);
    strcatEx(Dialog, "{FFFFFF}Água: {FFA500}%d", Jogador[playerid][Agua]);
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_MSGBOX, "{FF0000}Informações", Dialog, "Fechar", #);
    return 1;
}