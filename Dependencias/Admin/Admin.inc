new PaginasAdmin[MAX_PLAYERS];
new ComandosCap[MAX_PLAYERS];

enum ComandosInfo{
    Comando[128],
    Descricao[128],
    Perm
};

new MacroAdmin[][ComandosInfo] = 
{
    {"Olá. Seja Bem-vindo(a) á Rippzy RP"},
    {"Aperte 'G' em meu veículo que irei te instruir"},
    {"Vou te levar no hospital para você pegar um plano de saúde"},
    {"Aperte 'Y' e selecione o Plano de Saúde"},
    {"Irei te levar na Agência de Empregos para você pegar sua profissão"},
    {"Vá até a maleta e use /trabalhar, após isso me siga"},
    {"Aperte 'Y' no pickup e selecione a bike"},
    {"Utilize o comando /entregas e siga os Ícone no mapa"}
};

new ComandosAdminLista[][ComandosInfo] =
{
    {"/Voips", "Para entrar em outros voip's do discord", 1},
    {"/Macro", "Macros admins com determinadas mensagens pre-definadas", 1},
    {"/Kick [ID] [Motivo]", "Para expulsar um(a) Jogador(a)", 2},
    {"/Ban [ID] [Motivo]", "Para banir um(a) Jogador(a)", 3},
    {"/TempBan [ID] [Tempo] [Motivo]", "Para banir um(a) determinado(a) Jogador(a) Temporariamente", 3},
    {"/BanIp [IP]", "Para banir um determinado endereï¿½o de IP", 3},
    {"/BanirNick [Nick] [Motivo]", "Para banir uma conta offline", 3},
    {"/BanirSerial [Nick] [Serial]", "Para banir um determinado serial", 3},
    {"/BanVoip [ID] [Motivo]", "Para banir um(a) determinado(a) jogador(a) do VOIP", 3},
    {"/TempBanVoip [ID] [Tempo] [Motivo]", "Para banir um(a) determinado(a) jogador(a) do VOIP Temporariamente", 3},
    {"/Desbanir [Nick]", "Para desbanir um(a) determinado(a) jogador(a) pelo nick", 3},
    {"/DesbanIp [IP]", "Para desbanir um determinado endereï¿½o de IP", 3},
    {"/DesbanirSerial [Nick]", "Para desbanir um determinado serial", 3},
    {"/DesbanirVoip [ID]", "Para desbanir um(a) determinado(a) jogador(a) do VOIP", 3},
    {"/Editarban [Nick]", "Para alterar para banimento para temporï¿½rio", 4},
    {"/AgendarPunicao [Nick] [Tempo] [Motivo]", "Para punir uma determnada conta offline", 2},
    {"/Punir [ID] [Tempo] [Motivo]", "Para punir um(a) determinado(a) jogador(a)", 2},
    {"/Soltar [ID]", "Para soltar um(a) determinado(a) jogador(a) da prisï¿½o", 3},
    {"/Olhar [ID]", "Para telar um(a) determinado(a) jogador(a)", 2},
    {"/Avisar [ID] [Motivo]", "Para aplicar uma aviso em um(a) determinado(a) jogador(a)", 2},
    {"/Alertar [ID] [Mensagem]", "Para enviar alerta na tela de um(a) determinado(a) jogador(a)", 2},
    {"/SetTag [ID] [TagID]", "Para setar ou alterar personalizada", 5},
    {"/SetAdm [ID] [Cargo]", "Para setar ou alterar de admin", 5},
    {"/SetEmprego [ID] [Profissao]", "Para alterar a Profissão de um(a) determinado(a) jogador(a)", 4},
    {"/Empregos", "Para visualizar todas as profissï¿½es", 2},
    {"/SetSenha [ID]", "Para Regisrar senha admin", 5},
    {"/SetSexo [ID] [Sexo]", "Para alterar o sexo", 5},
    {"/Ir [ID]", "Para ir atï¿½ a posiï¿½ï¿½o de um(a) determinado(a) jogador(a)", 1},
    {"/Trazer [ID]", "Para puxar um(a) determinado(a) jogador(a) atï¿½ Você", 2},
    {"/Global [Mensagem]", "Para enviar mensagem no chat global", 2},
    {"/Cnn", "Para mostrar mensagem na tela de todos os jogadores {FF0000}com seu nome", 2},
    {"/Ann", "Para mostrar mensagem na tela de todos os jogadores {FF0000}sem seu nome", 2},
    {"/D [ID] [Resposta]", "Para responder a dï¿½vida de um(a) determinado(a) jogador(a)", 1},
    {"/DarVip [ID] [Dias]", "Para dar {FF0000}VIP{FFFFFF} para um(a) determinado(a) jogador(a)", 5},
    {"/RemoverVip [ID] [Dias]", "Para dar {FF0000}VIP{FFFFFF} para um(a) determinado(a) jogador(a)", 5},
    {"/Novatos", "Para visualizar lista de jogadores(as) novatos(as)", 1},
    {"/Cv [Modelo] [Cor1] [Cor2]", "Para criar um determinado veículo", 1},
    {"/SetSkin [ID] [Skin]", "Para alterar skin de um(a) determinado(a) jogador(a)", 4},
    {"/Ac [Mensagem]", "Para falar no chat da adminsitração", 1},
    {"/Ejetar [ID]", "Para ejetar um(a) determinado(a) jogador(a)", 1},
    {"/Injetar [ID]", "Para colocar um(a) determinado(a) jogador(a) em seu veículo", 2},
    {"/DarTapa [ID] [Altura]", "Para dar tapa em um(a) determinado(a) jogador(a) ({FFA500}Max: 2000{FFFFFF})", 3},
    {"/DarArma [ID] [Arma] [Muniï¿½ï¿½es]", "Para dar arma a um(a) determinado(a) jogador(a)", 3},
    {"/Camuflar", "Para se camuflar", 2},
    {"/Cheat", "Para desativar ou ativar notificaï¿½ï¿½es de cheat enviadas pelo servidor", 4},
    {"/Online [Nick]", "Para verificar tem um(a) jogador(a) com um determinado nick logado(a)", 3},
    {"/vTrazer [Veiculo-ID]", "Para puxar um veículo atï¿½ sua posiï¿½ï¿½o", 2},
    {"/vIr [Veiculo-ID]", "Para teleportar atï¿½ um determinado veículo", 3},
    //{"/VerVeiculo", "Para visualizar informaï¿½ï¿½es de um determinado veiculo ({FFA500}Obs: Tem que esta perto dele{FFFFFF})", 2},
    {"/PuxarTodos", "Para puxar todos os jogadores conectado atï¿½ sua posiï¿½ï¿½o", 5},
    {"/DarCoins [ID] [Quantidade]", "Para setar coins na conta de um(a) determinado(a) jogador(a)", 5},
    {"/DarLevel [ID] [Quantidade]", "Para setar leveis na conta de um(a) determinado(a) jogador(a)", 6},
    {"/DarGrana [ID] [Quantidade]", "Para setar dinheiro na conta de um(a) determinado(a) jogador(a)", 5},
    {"/DarGranaSuja [ID] [Quantidade]", "Para setar dinheiro na conta de um(a) determinado(a) jogador(a)", 6},
    {"/DarProcurado [ID] [Quantidade]", "Para dar estrela(s) de procurado para um(a) determinado(a) jogador(a)", 5},
    {"/rCoins [ID] [Quantidade]", "Para remover uma quantia de coins do jogador", 5},
    {"/rProcurado [ID] [Quantidade]", "Para remover estrelas de procurado do jogador", 5},
    {"/rLevel [ID] [Quantidade]", "Para remover uma quantia de level do jogador", 6},
    {"/rGrana [ID] [Quantidade]", "Para remover uma quantia de dinheiro do jogador", 5},
    {"/rGranaSuja [ID] [Quantidade]", "Para remover uma quantia de dinheiro do jogador", 7},
    {"/Congelar [ID]", "Para congelar um jogador", 2},
    {"/Descongelar [ID]", "Para descongelar um jogador", 2},
    {"/LimparChat", "Para limpar o chat global", 2},
    {"/CriarCaixa", "Para criar um caixa eletrï¿½nico", 7},
    {"/CriarRadar [Velocidade]", "Para criar um radar", 7},
    {"/CriarCasa [InteriorMax] [Dinheiro do Jogo] [Coins]", "Para criar uma casa", 7},
    {"/CriarEmpresa [Preï¿½o]", "Para criar uma casa", 7},
    {"/LiberarCasa [ID]", "Para liberar uma casa", 5},
    {"/LiberarEmpresa [ID]", "Para liberar uma empresa", 5},
    {"/LiberarBase [ID]", "Para liberar uma determinada base", 5},
    {"/EditarCasa [ID]", "Para editar uma determinada casa", 7},
    {"/EditarEmpresa [ID]", "Para editar uma determinada empresa", 7},
    {"/EditarBase [ID]", "Para editar uma determinada base", 7},
    {"/RemoverReforma [ID]", "Para remover uma casa de reforma ou remover tempo para vender", 7},
    {"/RemoverCaixa", "Para remover um caixa eletrï¿½nico ({FFA500}Obs: Você precisa estar perto do caixa{FFFFFF})", 7},
    {"/RemoverRadar", "Para remover um radar ({FFA500}Obs: Você precisa estar perto do radar{FFFFFF})", 7},
    {"/RemoverCasa [ID]", "Para remover uma determinada casa do servidor", 7},
    {"/RemoverEmpresa [ID]", "Para remover uma determinada empresa do servidor", 7},
    {"/RemoverBase [ID]", "Para remover uma determinada base do servidor", 7},
    {"/Ghost", "Para ficar no modo passivo(a) ({FFA500}Passa por dentro de outros jogadores{FFFFFF})", 1},
    {"/ForcarAFK [ID]", "Para forçar anti-afk em um(a) determinado(a) jogador(a) ({FFA500}não abuse{FFFFFF})", 3},
    {"/RemoverAFK [ID]", "Para remover anti-afk em um(a) determinado(a) jogador(a) ({FFA500}não abuse{FFFFFF})", 4},
    {"/RespawnarVeiculos", "Para respawnar todos os veículos sem ocupantes em 30 segundos", 2},
    {"/Rveh", "Para respawnar um determinado veículo ({FFA500}Obs: Você precisa está perto do veículo{FFFFFF})", 2},
    {"/Reiniciar", "Para reinciar o servidor ({FFA500}Apenas em casos grave{FFFFFF})", 6},
    {"/ExpulsarTodos", "Para expulsar todos os jogadores ({FFA500}Apenas em casos grave{FFFFFF})", 6},
    {"/VerComandos [ID]", "Para visualizar comandos digitado por um(a) determinado(a) jogador(a)", 3},
    {"/VerTelegram", "Para visualizar trocas de telegram entre jogadores(as)", 2},
    {"/VerTelefone", "Para visualizar ligaï¿½ï¿½es entre jogadores(as)", 2},
    {"/ForcarComando [ID] [Comando]", "Para forçar comando em um(a) determinado(a) jogador(a)", 3}, 
    {"/ForcarTexto [ID] [Texto]", "Para forçar o(a) jogador(a) a falar um determinado texto", 3},
    {"/rforcartexto [Range] [Texto]", "Para forçar jogadores a falar um determinado texto em certo range", 7},
    {"/AcessorioAdm", "Para escolher um acessï¿½rio", 3},
    {"/CheckArmas [ID]", "Para checar armas de um(a) determinado(a) jogador(a)", 2},
    {"/Cornick [Cor]", "Para mudar sua cor", 2},
    {"/IrCasa [Casa-id]", "Para ir atï¿½ uma determinada casa", 5},
    {"/IrEmpresa [Empresa-id]", "Para ir atï¿½ uma determinada empresa", 5},
    {"/eIr [Interior]", "Para teleportar em um interior de empresa", 7},
    {"/AbrirServidor", "Para destrancar o servidor", 5},
    {"/FecharServidor [Senha]", "Para trancar o servidor com senha", 5},
    {"/Presos", "Para visualizar lista de presos", 2},
    {"/Recompensar [ID] [Recompensar]", "Para recompensar um(a) determinado(a) jogador(a)", 6},
    {"/AjudaRota", "Para obter todas as informaï¿½ï¿½es de criaï¿½ï¿½es de paradas e rotas", 7},
    {"/SetWhtl [Nome] [Hwid]", "Para registrar um(a) jogador(a) na whitelist", 5},
    {"/Whtl", "Para ativar ou desativar a whitelist", 6},
    {"/RemoverWhtl [Nome]", "Para revogar o acesso de um(a) determinado(a) jogador(a)", 5},
    {"/Vida [ID]", "Para regenerar a vida de um(a) determinado(a) jogador(a)", 2},
    {"/RegenerarStatus [ID]", "Para regenarar o status de um(a) determinado(a) jogador(a)", 4},
    {"/Explodir [ID]", "Para explodir um(a) determinado(a) jogador(a)", 3},
    {"/ScanEmail [Email]", "Para visualizar usuï¿½rio que está utilizando esse email", 3},
    {"/ScanNick [Nome]", "Para pegar informaï¿½ï¿½es de uma determinada conta com nick", 3},
    {"/ScanIP [Ip]", "Para visualizar conta(s) que possui um determinado IP", 3},
    {"/Aconsertar", "Para consertar um veículo quebrado ({FFA500}Obs: Você precisa está perto do veículo{FFFFFF})", 3},
    {"/RevogarCodigo [Código]", "Para revogar um determinado Código", 6},
    {"/ConsultarAcesso [Usuï¿½rio]", "Para consultar um acesso de um(a) jogador(a) pelo nick", 6},
    {"/ConsultarCodigo [Código]", "Para consultar um determinado Código", 6},
    {"/GerarCodigo [Dias]", "Para gerar um Código de acesso com dias", 6},
    {"/CriarAir", "Para criar um airdrop na sua localizaï¿½ï¿½o", 4},
    {"/Eventos", "Para se informar sobre os comandos de eventos", 4},
    {"/CameraLivre", "Para entrar no modo drone", 4},
    {"/CriarTelefone", "Para criar um telefone apéblico", 7},
    {"/RemoverTelefone", "Para remover um telefone apéblico", 7},
    {"/God", "Para ficar invulnerï¿½vel", 1},
    {"/AlterarClima", "Para gerar um clima aleï¿½torio", 7},
    {"/IpEmail", "Para alterar a host de email", 7},
    {"/SetVw [ID]", "Para trocar de Virtual World", 7},
    {"/SetInterior [ID]", "Para trocar de Interior", 7},
    {"/SetPos [X] [Y] [Z] [A]", "Para teleportar atï¿½ uma determinada posiï¿½ï¿½o", 7},
    {"/TrocarCargo", "Para alterar seu cargo atual", 7},
    {"/Deteccao", "Para visualizar os {FFA500}10 ï¿½ltimos{FFFFFF} avisos da Isabella", 3},
    {"/Teleportes", "Para teleportar atï¿½ um determinado local", 1},
    {"/CriarEnquete [Mensagem]", "Para criar uma enquete", 4},
    {"/GerarCoins [Coins]", "Para gerar um Código coins", 6},
    {"/EmailCoins [Email] [Código-Coins]", "Para enviar por email o Código do coins", 6},
    {"/EnviarCodigo [Email]", "Para enviar Código de recuperaï¿½ï¿½o/registro para um e-mail", 4},
    {"/DVeh [veículo-ID]", "Para forçar um delete de um determinado veículo", 5},
    {"/Crashar [ID]", "Para crashar um determinado jogador", 6},
    {"/CriarBike", "Para criar um ponto de bicicletas", 7},
    {"/RemoverBike", "Para remover um ponto de bicicleta", 7},
    {"/DeslogarConta [Nick]", "Para deslogar uma conta conectada bugada", 2},
    {"/DeslogarTodos", "Para deslogar todas as contas bugadas ({FFA500}Apenas em casos de bugs{FFFFFF})", 5},
    {"/Fake [Nick]", "Para alterar seu nick para um falso", 4},
    {"/Mutar [ID] [Tempo] [Motivo]", "Para mutar um(a) determinado(a) jogador(a)", 2},
    {"/Desmutar [ID]", "Para desmutar um(a) determinado(a) jogador(a)", 2},
    {"/EspiarChat [Profissão]", "Para espiar o chat de uma determinada Profissão", 2},
    {"/EspiarChatBase [Base-ID]", "Para espiar o chat base", 2},
    {"/Clm [Horas] [Minutos]", "Para personalizar a hora do servidor", 7},
    {"/DarColete [ID] [Quantidade]", "Para setar colete para um(a) determinado jogador(a)", 4},
    {"/DarVida [ID] [Quantidade]", "Para setar vida para um(a) determinado jogador(a)", 4},
    {"/RemoverArmas [ID]", "Para remover as armas de um(a) determinado jogador(a)", 3},
    {"/ID [Nick]", "Para pegar um ID pelo Nick", 2},
    {"/Regiao [Ip]", "Para verificar a regiï¿½o de eu IP", 2},
    {"/SalvarContas", "Para salvar todas as contas online", 5},
    //{"/Hack", "Para ativar/desativar features para admins", 2},
    {"/ForcarUP", "Para forçar um UP de Level no(a) jogador(a)", 7},
    {"/Painel", "Para gerenciar algumas opções do servidor", 5},
    {"/BloquearInfo [ID]", "Para bloquear alguns cmd's admins em um(a) determinado(a) jogador(a)", 7},
    {"/iAdmin [ID]", "Para visualizar o'que o admin está fazendo", 7},
    {"/LimparArmas", "Para remover todas as armas dropadas no chï¿½o", 3},
    {"/ServidorNome [Texto]", "Para alterar o nome do servidor no Launcher do Samp", 7},
    {"/Loteria", "Para tomar determinadas atitudes com a lotï¿½rica", 7}
};  

CMD:login(playerid)
{
    if(Jogador[playerid][TempAdmin] < 1) return 0;
    if(!strcmp(Jogador[playerid][SenhaAdmin], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua conta não foi registrada!");
    //if(!strcmp(Jogador[playerid][Discord], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem uma conta do discord vinculada");
    if(pAdmin[playerid][LogadoAdm] == false)
    {
        Dialog_Show(playerid, AdminLogin, DIALOG_STYLE_PASSWORD, "{FFA500}adminsitração", "{FFFFFF}Coloque sua senha admin abaixo!", "Confirmar", "Fechar");     
    } 
    else if(pAdmin[playerid][LogadoAdm] == true)
    {
        if(pAdmin[playerid][CarroAdmin] > 0) DestroyVehicleEx(pAdmin[playerid][CarroAdmin]);
        if(pAdmin[playerid][Espiando] == true) RemoverEspiao(playerid);
        if(pAdmin[playerid][ModoGhost] == true) DisableRemoteVehicleCollisions(playerid, 0);
        if(pAdmin[playerid][FalsoPlayer] == true) SetPlayerName(playerid, PegarNick(playerid));

        //RemovePlayerAttachedObject(playerid, 7);
        //RemovePlayerAttachedObject(playerid, 8);

        new Deletar[AdminInfo];
        pAdmin[playerid] = Deletar;

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| ADMIN | O(A) %s %s deslogou-se", CargoAdmin(2, playerid), PegarNick(playerid));
        for(new i=0; i < MAX_PLAYERS; i++)
        {
            if(i == playerid) continue;
            if(!IsPlayerConnected(i)) continue;
            if(Jogador[i][Admin] < 1) continue;
            SendClientMessage(i, 0xe2b960FF, Mensagem);
        }

        SendClientMessage(playerid, 0xe2b960FF, "| ADMIN | Você saiu do modo admin!");
        Jogador[playerid][Admin] = 0;
        pAdmin[playerid][LogadoAdm] = false;
    }
    return 1;
}

CMD:comandosadm(playerid)
{
    if(Jogador[playerid][Admin] < 1) return 0;
    new ComandosDialog[2000];

    ComandosCap[playerid] = 0;
    PaginasAdmin[playerid] = 0;

    strcat(ComandosDialog, "Comando\tDescriï¿½ï¿½o\n");
    for(new i=PaginasAdmin[playerid]; i < sizeof(ComandosAdminLista); i++){
        if(ComandosCap[playerid] >= 10 && ComandosCap[playerid] < sizeof(ComandosAdminLista)){
            strcat(ComandosDialog, "{FF0000}Prï¿½xima apégina");
            break;
        }
        PaginasAdmin[playerid]++;
        if(Jogador[playerid][Admin] >= ComandosAdminLista[i][Perm]){
            strcatEx(ComandosDialog, "{36cf85}%s\t{FFFFFF}%s\n", ComandosAdminLista[i][Comando], ComandosAdminLista[i][Descricao]);
            ComandosCap[playerid]++;
        }
    }
    Dialog_Show(playerid, ComandosAdmin, DIALOG_STYLE_TABLIST_HEADERS, "{FF4500}Comandos Admin", ComandosDialog, "Selecionar", "Fechar"); 
    return 1;
}

CMD:kick(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id,
        motivo[70]
    ;
    if(sscanf(params, "ds[70]", id, motivo)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /kick [ID] [Motivo]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar em si mesmo!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    //if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)!");
    if(Jogador[playerid][Admin] < 4){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode expulsar um mebro da equipe!");
    }
    KickF(id, playerid, motivo);
    return 1;
}

CMD:banirnick(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new Nick[70], 
        banmotivo[70],
        Mensagem[128];
    if(sscanf(params, "s[70]s[70]", Nick, banmotivo)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /BanirNick [Nick] [Motivo]");
    if(!strcmp(PegarNick(playerid), Nick)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode se punir"); 
    if(IsPlayerConnected(PegarIdPeloNick(Nick))){
        format(Mensagem, sizeof(Mensagem), "| AVISO | Esse jogador jï¿½ está online ( %s[%d] )", Nick, PegarIdPeloNick(Nick));
        SendClientMessage(playerid, 0xfc520fFF, Mensagem);
        return 1;
    }

    new Enviar[300],
        Cache:Conectar,
        ContaQ,
        AdmQQ
    ;

    format(Enviar, sizeof(Enviar), "SELECT * FROM `rippzyrpg` WHERE `Nome` = '%s'", EscapeString(Nick));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao verificar o jogador"); 
    ContaQ = cache_num_rows();
    if(ContaQ > 0) cache_get_value_name_int(0, "Admin", AdmQQ);
    cache_delete(Conectar);
    if(ContaQ < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa conta não existe"); 
    if(Jogador[playerid][Admin] != 7){
        if(AdmQQ > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode banir uma conta admin"); 
    }
    
    format(Enviar, sizeof(Enviar), "SELECT * FROM `banimentos` WHERE `Nome` = '%s'", EscapeString(Nick));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao verificar o banimento desse jogador"); 
    ContaQ = cache_num_rows();
    cache_delete(Conectar);

    if(ContaQ > 0)
    {
        format(Enviar, sizeof(Enviar), "UPDATE `banimentos` SET `Banido` = 1, `Tempo` = %d, `Data` = %d, `Admin` = '%s', `Motivo` = '%s', `Ip` = '%s' WHERE `Nome` = '%s'", 1, gettime(), EscapeString(PegarNick(playerid)), EscapeString(banmotivo), "0.0", EscapeString(Nick));
        mysql_query(IDConexao, Enviar, false);  
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | não foi possï¿½vel atualizar o banimento"); 
    }
    else
    {
        format(Enviar, sizeof(Enviar), "INSERT INTO `banimentos` (`Nome`, `Banido`, `Tempo`, `Data`, `Admin`, `Motivo`, `Ip`) VALUES ('%s', '%d', '%d', '%d', '%s', '%s', '%s')", EscapeString(Nick), 1, 1, gettime(), EscapeString(PegarNick(playerid)), EscapeString(banmotivo), "0.0");
        mysql_query(IDConexao, Enviar, false);  
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | não foi possï¿½vel registrar o banimento");
    }

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você baniu a conta do(a) {FE2E2E}%s{FFFFFF} ( Motivo: {FE2E2E}%s{FFFFFF} )", Nick, banmotivo);
    SendClientMessage(playerid, 0xFFFFFFFF, Mensagem);
    return 1;
}

CMD:ban(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id, motivo[70];
    if(sscanf(params, "ds[70]", id, motivo)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /ban [ID] [Motivo]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se banir!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)!");
    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode banir um mebro da equipe!");
    }
    BanF(id, playerid, motivo, 1);
    return 1;  
}

CMD:banip(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new Baip[20];
    if(sscanf(params, "s[70]", Baip)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /banip [IP]");
    BanirIp(Baip);
    new rconenviar[60];
    format(rconenviar, sizeof(rconenviar), "| BANIMENTO | Você baniu o endereï¿½o de IP ( %s )", Baip);
    SendClientMessage(playerid, 0xFF0000FF, rconenviar);
    return 1;
}

CMD:desbanip(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new Baip[20];
    if(sscanf(params, "s[70]", Baip)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Desbanip [IP]");
    new rconenviar[128];
    format(rconenviar, sizeof(rconenviar), "unbanip %s", Baip);
    SendRconCommand(rconenviar);
    SendRconCommand("reloadbans");
    format(rconenviar, sizeof(rconenviar), "| BANIMENTO | Você desbaniu o endereï¿½o de IP ( %s )", Baip);
    SendClientMessage(playerid, 0xFF0000FF, rconenviar);
    return 1;
}

CMD:editarban(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new Alvo[70], Dias;
    if(sscanf(params, "s[70]d", Alvo, Dias)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /EditarBan [Nick] [Dias]");

    new Cache:Conectar,
        Enviar[128],
        TipoBan,
        BanStatus;
    format(Enviar, sizeof(Enviar), "SELECT * FROM `banimentos` WHERE `Nome` = '%s'", EscapeString(Alvo));
    Conectar = mysql_query(IDConexao, Enviar);
    new TemQnt = cache_num_rows();
    if(TemQnt > 0)
    {
        cache_get_value_name_int(0, "Tempo", TipoBan);
        cache_get_value_name_int(0, "Banido", BanStatus); 
    }
    cache_delete(Conectar);
    if(TemQnt < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | não hï¿½ registro de banimentos desse jogador(a)");
    if(BanStatus == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) atualmente não se encontra banido(a)");
    if(TipoBan > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) jï¿½ está no banimento temporï¿½rio");
    new NovoDias = (Dias * 24 * 60 * 60) + gettime();
    format(Enviar, sizeof(Enviar), "UPDATE `banimentos` SET `Tempo` = %d WHERE `Nome` = '%s'", NovoDias, EscapeString(Alvo));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno() != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao alterar o banimento");
    format(Enviar, sizeof(Enviar), "| ADMIN | Você alterou o banimento do(a) jogador(a) %s para temporï¿½rio ( Dias: %d )", Alvo, Dias);
    SendClientMessage(playerid, 0x00BFFFFF, Enviar);
    return 1;
}

CMD:tempban(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id, 
        motivo[70],
        tempo;
    if(sscanf(params, "dds[70]", id, tempo, motivo)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /TempBan [ID] [Tempo] [Motivo]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode se banir!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)!");
    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode banir um mebro da equipe!");
    }
    BanF(id, playerid, motivo, tempo);
    return 1;
}

CMD:desbanir(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new Nick[30];
    if(sscanf(params, "s[30]", Nick)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Desbanir [Nick]");
    new Cache:Conectar,
        Formatacao[128];
    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `banimentos` WHERE `Nome` = '%s'", EscapeString(Nick));
    Conectar = mysql_query(IDConexao, Formatacao);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Falha ao verificar usuï¿½rio!");
    if(cache_num_rows() < 1){
        cache_delete(Conectar);
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse usuï¿½rio não está banido!");
        return 1;
    }
    new BanSattu;
    cache_get_value_name_int(0, "Banido", BanSattu);
    cache_delete(Conectar);
    if(BanSattu == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse usuï¿½rio não está banido!");
    format(Formatacao, sizeof(Formatacao), "UPDATE `banimentos` SET `Banido` = 0 WHERE `Nome` = '%s'", EscapeString(Nick));
    mysql_query(IDConexao, Formatacao, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Falha ao desbanir usuï¿½rio!");
    format(Formatacao, sizeof(Formatacao), "| ADMIN | Você desbaniu o(a) %s", Nick);
    SendClientMessage(playerid, 0xFF0000FF, Formatacao);
    return 1;
}

CMD:setadm(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id,
        cargo;
    if(sscanf(params, "dd", id, cargo)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /SetAdm [ID] [Admin]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(cargo > 7 || cargo < 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Cargo Inválido");
    if(Jogador[playerid][Admin] != 7){
        if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode alterar seu prï¿½prio cargo");
        if(Jogador[id][TempAdmin] > Jogador[playerid][TempAdmin]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode colocar em um cargo maior que o seu");
    }

    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Admin`=%d WHERE `Nome`='%s'", cargo, EscapeString(PegarNick(id)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um erro ao alterar o admin, fale com o(a) desenvolvedor(a)");

    if(Jogador[id][Admin] > 0){
        Jogador[id][Admin] = cargo;
    }
    Jogador[id][TempAdmin] = cargo;

    new Mensagem[128];
    if(cargo == 0)
    {
        if(pAdmin[id][CarroAdmin] > 0) DestroyVehicleEx(pAdmin[id][CarroAdmin]);
        if(pAdmin[id][Espiando] == true) RemoverEspiao(id);
        if(pAdmin[id][ModoGhost] == true) DisableRemoteVehicleCollisions(playerid, 0);
        if(pAdmin[playerid][FalsoPlayer] == true) SetPlayerName(playerid, PegarNick(playerid));

        //RemovePlayerAttachedObject(playerid, 7);
        //RemovePlayerAttachedObject(playerid, 8);

        new Deletar[AdminInfo];
        pAdmin[playerid] = Deletar;
        SendClientMessage(id, 0xFFFF00FF, "| ADMIN | Seu cargo foi removido");
    }
    else
    {
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Seu novo cargo: %s", CargoAdmin(1, id));
        SendClientMessage(id, -1, Mensagem);
    }
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você alterou o cargo do(a) %s[%d] para %s", PegarNick(id), id, CargoAdmin(1, id));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

CMD:settag(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id, tagid;
    if(sscanf(params, "dd", id, tagid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /SetTag [ID] [TagID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][TagPersonalizada] == tagid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) jï¿½ possui essa tag");
    Jogador[id][TagPersonalizada] = tagid;
    return 1;
}

CMD:setsenha(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /SetSenha [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    Dialog_Show(id, SenhaAdminRegistro, DIALOG_STYLE_INPUT, "{FF4500}Registro Admin", "{FFFFFF}Adicione uma senha para seu cargo de admin", "Confirmar", "Fechar"); 
    return 1;
}

CMD:ir(playerid, params[])
{
    if(Jogador[playerid][Admin] < 1) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /ir [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar em si mesmo!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(GetPVarInt(id, "BloquearInfo") == 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | está com as informaï¿½ï¿½es bloqueadas.");

    if(Jogador[id][Admin] > 0){
        if(GetPlayerState(id) == PLAYER_STATE_SPECTATING) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode ir atï¿½ esse admin agora, aguarde um pouco.");
    }

    new Float:Pos[4];
    GetPlayerPos(id, Pos[0], Pos[1], Pos[2]);
    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(id));
    SetPlayerInterior(playerid, GetPlayerInterior(id));
    SetPlayerPos(playerid, Pos[0]+1, Pos[1], Pos[2]);

    SetPVarInt(playerid, "InteriorPersonalizadoID", GetPVarInt(id, "InteriorPersonalizadoID"));
    Jogador[playerid][uInteriorExP][0] = Jogador[id][uInteriorExP][0];
    Jogador[playerid][uInteriorExP][1] = Jogador[id][uInteriorExP][1];
    Jogador[playerid][uInteriorExP][2] = Jogador[id][uInteriorExP][2];
    Jogador[playerid][uInteriorExP][3] = Jogador[id][uInteriorExP][3];
    Jogador[playerid][uInteriorEx] = Jogador[id][uInteriorEx];
    Jogador[playerid][uInterior] = Jogador[id][uInterior];

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | O(A) %s %s foi atï¿½ sua posiï¿½ï¿½o", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você foi atï¿½ o(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:trazer(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /ir [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar em si mesmo!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(GetPVarInt(id, "BloquearInfo") == 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | está com as informaï¿½ï¿½es bloqueadas.");

    if(Jogador[id][Admin] > 0){
        if(GetPlayerState(id) == PLAYER_STATE_SPECTATING) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode trazer esse admin agora, aguarde um pouco.");
    }

    new Float:Pos[4];
    GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    SetPlayerVirtualWorld(id, GetPlayerVirtualWorld(playerid));
    SetPlayerInterior(id, GetPlayerInterior(playerid));
    SetPlayerPos(id, Pos[0]+1, Pos[1], Pos[2]);


    SetPVarInt(id, "InteriorPersonalizadoID", GetPVarInt(playerid, "InteriorPersonalizadoID"));
    Jogador[id][uInteriorExP][0] = Jogador[playerid][uInteriorExP][0];
    Jogador[id][uInteriorExP][1] = Jogador[playerid][uInteriorExP][1];
    Jogador[id][uInteriorExP][2] = Jogador[playerid][uInteriorExP][2];
    Jogador[id][uInteriorExP][3] = Jogador[playerid][uInteriorExP][3];
    Jogador[id][uInteriorEx] = Jogador[playerid][uInteriorEx];
    Jogador[id][uInterior] = Jogador[playerid][uInterior];


    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | O(A) %s %s puxou Você", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você puxou o(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:global(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new Mensagem[128];
    if(sscanf(params, "s[128]", Mensagem)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Global [Mensagem]");
    new GlobalMensagem[128];
    format(GlobalMensagem, sizeof(GlobalMensagem), "* %s %s: %s", CargoAdmin(2, playerid), PegarNick(playerid), Mensagem);
    SendClientMessageToAll(0x1E90FFFF, GlobalMensagem);
    return 1;
}

CMD:d(playerid, params[])
{
    if(Jogador[playerid][Admin] < 1) return 0;
    new id,
        resposta[90];
    if(sscanf(params, "ds[90]", id, resposta)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /d [ID] [Resposta]");
    if(strlen(resposta) > 59) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Resposta muito grande");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar em si mesmo!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");

    PlayerPlaySound(playerid, 1056, 0.0, 0.0, 0.0);
    PlayerPlaySound(id, 1056, 0.0, 0.0, 0.0);

    new MensagemDaDuvida[500];
    format(MensagemDaDuvida, sizeof(MensagemDaDuvida), "| RESPOSTA | %s %s respondeu ( %s )", CargoAdmin(2, playerid), PegarNick(playerid), resposta);
    SendClientMessage(id, 0x40E0D0FF, MensagemDaDuvida);

    format(MensagemDaDuvida, sizeof(MensagemDaDuvida), "| RESPOSTA | Você respondeu o(a) jogador(a) %s[%d] ( %s )", PegarNick(id), id, resposta);
    SendClientMessage(playerid, 0x40E0D0FF, MensagemDaDuvida);

    format(MensagemDaDuvida, sizeof(MensagemDaDuvida), "| RESPOSTA | %s %s respondeu ao jogador(a) %s[%d] ( %s )", CargoAdmin(2, playerid), PegarNick(playerid), PegarNick(id), id, resposta);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(i == playerid) continue;
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] < 1) continue;
        SendClientMessage(i, 0x40E0D0FF, MensagemDaDuvida);
    }
    return 1;
}

CMD:darvip(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id,
        dias;
    if(sscanf(params, "dd", id, dias)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /DarVip [ID] [Dias]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você ativou %d dias de VIP na conta do(a) %s[%d]", dias, PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    AtivarVIP(id, dias);
    return 1;
}

CMD:removervip(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id,
        dias;
    if(sscanf(params, "dd", id, dias)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /DarVip [ID] [Dias]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");

    new Simulado = Jogador[playerid][Vip];
    Simulado -= (Jogador[playerid][Vip] > 0 ? (dias * 86400) : (gettime() + (dias * 86400)));

    new Query[128];
    format(Query, sizeof(Query), "UPDATE `rippzyrpg` SET `Vip` = %d WHERE `Nome` = '%s'", EscapeString(PegarNick(id)));
    mysql_query(IDConexao, Query, false);

    if(Simulado < 0) Jogador[playerid][Vip] = 0;
    else Jogador[playerid][Vip] = Simulado;

    format(Query, sizeof(Query), "| ADDMIN | Você removeu %d dia(s) de VIP do(a) jogador(a) %s[%d]", dias, PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Query);
    return 1;
}

CMD:darprocurado(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id, qnt;
    if(sscanf(params, "dd", id, qnt)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /DarProcurado [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    new Mensagem[128];
    Jogador[id][Estrelas] += qnt;
    if(Jogador[id][Estrelas] > MaximoEstrelas) Jogador[id][Estrelas] = MaximoEstrelas;
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você adicionou %d estrela(s) na conta de %s[%d]", qnt, PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:rprocurado(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id, qnt;
    if(sscanf(params, "dd", id, qnt)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /rProcurado [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    new Mensagem[128];
    Jogador[id][Estrelas] -= qnt;
    if(Jogador[id][Estrelas] < 1) Jogador[id][Estrelas] = 0;
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você removeu %d estrela(s) na conta de %s[%d]", qnt, PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:novatos(playerid)
{
    if(Jogador[playerid][Admin] < 1) return 0;
    new Dialog[2000];
    new Contador = 0;
    strcat(Dialog, "Nick\tLevel\tTempo de Registro\n");
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Level] > 10) continue;
        strcatEx(Dialog, "{FFFFFF}Nick: {00BFFF}%s[%d]\t{FFFFFF}Level: {FFD700}%d\t{FFFFFF}Registro: {00FF00}%s\n", PegarNick(i), i, Jogador[i][Level], ConverterSegundosEx(gettime()-Jogador[i][Registro]));
        Contador++;
    }
    new LAo[128];
    format(LAo, sizeof(LAo), "{FF0000}Novatos [%d]", Contador);
    Dialog_Show(playerid, ListaDeNovatos, DIALOG_STYLE_TABLIST_HEADERS, LAo, Dialog, "Fechar", #); 
    return 1;
}

CMD:cv(playerid, params[])
{
    if(Jogador[playerid][Admin] < 1) return 0;
	new CarroID, Cor1, Cor2;
	if(sscanf(params, "ddd", CarroID, Cor1, Cor2)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /cv [Modelo] [Cor1] [Cor2]");
    // if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você precisa estar fora de um veículo ou algo do genï¿½ro!");
    if(CarroID < 400 || CarroID > 611) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | não existe veiculo com esse id!");

    if(pAdmin[playerid][CarroAdmin] > 0){
        if(IsPlayerInAnyVehicle(playerid)) RemovePlayerFromVehicle(playerid);
        DestroyVehicleEx(pAdmin[playerid][CarroAdmin]);
    }

    new Float:cPos[4];
	GetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
	GetPlayerFacingAngle(playerid, cPos[3]);
    pAdmin[playerid][CarroAdmin] = CreateVehicleEx(playerid, CarroID, cPos[0], cPos[1]-3, cPos[2], cPos[3], Cor1, Cor2, -1, 0);
    SetVehicleVirtualWorld(pAdmin[playerid][CarroAdmin], GetPlayerVirtualWorld(playerid));
    LinkVehicleToInterior(pAdmin[playerid][CarroAdmin], GetPlayerInterior(playerid));
    SetVehicleNumberPlate(pAdmin[playerid][CarroAdmin], "RC-Admin");
    PutPlayerInVehicle(playerid, pAdmin[playerid][CarroAdmin] , 0);
    VeiculoServer[pAdmin[playerid][CarroAdmin]][AntiRadar] = true;
    VeiculoServer[pAdmin[playerid][CarroAdmin]][AntiFurar] = true;
	return 1;
}

CMD:avisar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id,
        motivo[70];
    
    if(sscanf(params, "ds[70]", id, motivo)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Avisar [ID] [Motivo]");
    if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar em si mesmo!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode avisar um membro da equipe!");
    }
    Jogador[id][Avisos]++;
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| SERVIDOR | Jogador(a) %s foi avisado por %s %s ( Motivo: %s ) ( %d/3 )", PegarNick(id), CargoAdmin(2, playerid), PegarNick(playerid), motivo, Jogador[id][Avisos]);
    SendClientMessageToAll(0xf03629FF, Mensagem);
    if(Jogador[id][Avisos] >= 3)
    {
        CatalogarPrisao(id, 50, motivo, PegarNick(playerid), 0);
        if(Jogador[id][Preso] == 0) MostrarRelogioPrisao(id);
        new TempoJ = Jogador[id][Preso];
        new TempoRemake = (50 * 60);
        TempoJ += TempoRemake;
        Jogador[id][Preso] = TempoJ;
        Jogador[id][uInterior] = Departamento(id);
        ColocarNaCadeia(id);
        Jogador[id][Avisos] = 0;
        format(Mensagem, sizeof(Mensagem), "| SERVIDOR | Jogador(a) %s foi preso por 50 minutos ( 3/3 )", PegarNick(id));
        SendClientMessageToAll(0xf03629FF, Mensagem);   
    }
    return 1;
}

CMD:setskin(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;   
    new id,
        skin;
    if(sscanf(params, "dd", id, skin)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /SetSkin [ID] [Skin]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(skin > 311 || skin < 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Skin Invï¿½lida!");
    Jogador[id][Skin] = skin;
    SetPlayerSkin(id, skin);

    new Formatacao[128];
    format(Formatacao, sizeof(Formatacao), "| ADMIN | Você alterou a skin do(a) %s[%d] para %d", PegarNick(id), id, skin);
    SendClientMessage(playerid, 0x00BFFFFF, Formatacao);

    format(Formatacao, sizeof(Formatacao), "| ADMIN | Sua skin foi alterada para %d por %s %s", skin, CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Formatacao);
    return 1;
}

CMD:ac(playerid, params[])
{
    if(Jogador[playerid][Admin] < 1) return 0;
    new Mensagem[228];
    if(sscanf(params, "s[128]", Mensagem)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Ac [Mensagem]");
    
    new ChatAdm[228];
    format(ChatAdm, sizeof(ChatAdm), "| CHAT-ADMIN | %s %s[%d]: %s", CargoAdmin(2, playerid), PegarNick(playerid), playerid, Mensagem);
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Admin] < 1) continue;
        SendClientMessage(i, 0x7CFC00FF, ChatAdm);
    }
    return 1;
}

CMD:rcoins(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id,
        coins;
    if(sscanf(params, "dd", id, coins)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /rCoins [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(coins > Jogador[id][Coins]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não tem toda essa quantia de coins!");
    Jogador[id][Coins] -= coins;
    new mensagem[128];
    format(mensagem, sizeof(mensagem), "| INFO | %s %s removeu %s coins da sua conta", CargoAdmin(2, playerid), PegarNick(playerid), DinheiroSeparar(coins));
    SendClientMessage(id, 0x00BFFFFF, mensagem);
    format(mensagem, sizeof(mensagem), "| ADMIN | Você removeu %s coins de %s[%d]", DinheiroSeparar(coins), PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, mensagem);
    return 1;
}

CMD:rlevel(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new id,
        dd
    ;
    if(sscanf(params, "dd", id, dd)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /rLevel [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(dd > Jogador[id][Level]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não tem toda essa quantia de level!");
    Jogador[id][Level] -= dd;
    new mensagem[128];
    format(mensagem, sizeof(mensagem), "| INFO | %s %s removeu %s leveis da sua conta", CargoAdmin(2, playerid), PegarNick(playerid), DinheiroSeparar(dd));
    SendClientMessage(id, 0x00BFFFFF, mensagem);
    format(mensagem, sizeof(mensagem), "| ADMIN | Você removeu %s leveis de %s[%d]", DinheiroSeparar(dd), PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, mensagem);
    return 1;
}

CMD:rgrana(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id,
        quantia;
    if(sscanf(params, "dd", id, quantia)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /rGrana [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(quantia > Jogador[id][Dinheiro]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não tem toda essa quantia de grana!");
    Jogador[id][Dinheiro] -= quantia;
    new mensagem[128];
    format(mensagem, sizeof(mensagem), "| INFO | %s %s removeu %s de dinheiro da sua conta", CargoAdmin(2, playerid), PegarNick(playerid), DinheiroSeparar(quantia));
    SendClientMessage(id, 0x00BFFFFF, mensagem);
    format(mensagem, sizeof(mensagem), "| ADMIN | Você removeu %s de dinheiro de %s[%d]", DinheiroSeparar(quantia), PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, mensagem);
    return 1;
}

CMD:rgranasuja(playerid, params[])
{
    if(Jogador[playerid][Admin] < 7) return 0;
    new id,
        quantia
    ;
    if(sscanf(params, "dd", id, quantia)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /rGranaSuja [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(quantia > Jogador[id][DinheiroSujo]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não tem toda essa quantia de grana!");
    Jogador[id][DinheiroSujo] -= quantia;
    new mensagem[128];
    format(mensagem, sizeof(mensagem), "| INFO | %s %s removeu %s de dinheiro sujo da sua conta", CargoAdmin(2, playerid), PegarNick(playerid), DinheiroSeparar(quantia));
    SendClientMessage(id, 0x00BFFFFF, mensagem);
    format(mensagem, sizeof(mensagem), "| ADMIN | Você removeu %s de dinheiro sujo de %s[%d]", DinheiroSeparar(quantia), PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, mensagem);
    return 1;
}

CMD:darcoins(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id,
        coins
    ;
    if(sscanf(params, "dd", id, coins)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /DarCoins [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    Jogador[id][Coins] += coins;
    new mensagem[128];
    format(mensagem, sizeof(mensagem), "| INFO | %s %s adicionou %s coins na sua conta", CargoAdmin(2, playerid), PegarNick(playerid), DinheiroSeparar(coins));
    SendClientMessage(id, 0x00BFFFFF, mensagem);
    format(mensagem, sizeof(mensagem), "| ADMIN | Você deu %s coins para %s[%d]", DinheiroSeparar(coins), PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, mensagem);
    return 1;
}

CMD:darlevel(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new id,
        level
    ;
    if(sscanf(params, "dd", id, level)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /DarLevel [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    Jogador[id][Level] += level;
    new mensagem[128];
    format(mensagem, sizeof(mensagem), "| INFO | %s %s adicionou %s leveis na sua conta", CargoAdmin(2, playerid), PegarNick(playerid), DinheiroSeparar(level));
    SendClientMessage(id, 0x00BFFFFF, mensagem);
    format(mensagem, sizeof(mensagem), "| ADMIN | Você deu %s leveis para %s[%d]", DinheiroSeparar(level), PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, mensagem);
    return 1;
}

CMD:ejetar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 1) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Ejetar [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    RemovePlayerFromVehicle(id);
    new Float:Pos[3];
    GetPlayerPos(id, Pos[0], Pos[1], Pos[2]);
    SetPlayerPos(id,  Pos[0], Pos[1], Pos[2]+5.0);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | %s %s ejetou Você", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você ejetou %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:injetar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id;
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está dirigindo um veículo");
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Injetar [ID]");
    if(id == playerid) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode se puxar!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(GetPlayerState(id) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) precisa está a apé");
    new mid = GetPlayerVehicleID(playerid);
    if(GetEmptyVehicleSeat(mid) == -1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse veículo não tem espaço");
    
    new Float:kp[3];
    GetVehiclePos(mid, kp[0], kp[1], kp[2]);
    SetPlayerPos(id, kp[0], kp[1], kp[2]);
    PutPlayerInVehicle(id, mid, GetEmptyVehicleSeat(mid));
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você puxou %s[%d] para seu veículo", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| INFO | %s %s puxou Você para o veículo dele(a)", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:dartapa(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id, altura;
    if(sscanf(params, "dd", id, altura)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /dartapa [ID] [Altura]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(altura > 2000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Altura definida está muito alta!");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(id, x,y,z);
    SetPlayerPos(id, x,y,z+altura);
    new String[128];
    format(String, sizeof(String), "| ADMIN | %s %s deu um taapéo em Você de %d de altura", CargoAdmin(2, playerid), PegarNick(playerid), altura);
    SendClientMessage(id, 0x00BFFFFF, String);
    format(String, sizeof(String), "| ADMIN | Você deu um tapa de %d altura no %s[%d]",  altura, PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, String);
    return 1;
}

CMD:agendarpunicao(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new Nick[70], motivoban[70], tempo, Mensagem[300];
    if(sscanf(params, "s[70]ds[70]", Nick, tempo, motivoban)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /AgendarPunicao [Nick] [Tempo] [Motivo]"); 
    if(!strcmp(PegarNick(playerid), Nick)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode se punir"); 
    if(IsPlayerConnected(PegarIdPeloNick(Nick))){
        format(Mensagem, sizeof(Mensagem), "| AVISO | Esse jogador jï¿½ está online ( %s[%d] )", Nick, PegarIdPeloNick(Nick));
        SendClientMessage(playerid, 0xfc520fFF, Mensagem);
        return 1;
    }

    new Enviar[400],
        Cache:Conectar,
        ContaQ,
        EADM,
        TempoPrisaoOld;
 
    // Verificar se conta admin existe
    format(Enviar, sizeof(Enviar), "SELECT * FROM `rippzyrpg` WHERE `Nome` = '%s'", EscapeString(Nick));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | não foi possï¿½vel fazer verificaï¿½ï¿½o"); 
    ContaQ = cache_num_rows();
    if(ContaQ > 0) cache_get_value_name_int(0, "Admin", EADM);
    cache_delete(Conectar);
    if(ContaQ < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa conta não existe"); 

    // Anti Banir ADM
    if(Jogador[playerid][Admin] != 7){
        if(EADM > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode punir uma conta admin"); 
    }

    // Verificar Prisï¿½o
    format(Enviar, sizeof(Enviar), "SELECT * FROM `presos` WHERE `Nome` = '%s'", EscapeString(Nick));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | não foi possï¿½vel fazer verificaï¿½ï¿½o prisï¿½o");
    ContaQ = cache_num_rows();
    if(ContaQ > 0) cache_get_value_name_int(0, "Tempo", TempoPrisaoOld);
    cache_delete(Conectar);
    
    new TempoJ = TempoPrisaoOld;
    new TempoRemake = (60*tempo);
    TempoJ += TempoRemake; 

    if(ContaQ > 0)
    {
        format(Enviar, sizeof(Enviar), "UPDATE `presos` SET `Tempo` = %d, `TempoAtual` = %d, `Admin` = '%s', `Motivo` = '%s', `Cadeia` = %d WHERE `Nome` = '%s'", tempo, TempoJ, EscapeString(PegarNick(playerid)), EscapeString(motivoban), 0, EscapeString(Nick));
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Falha ao efetuar puniï¿½ï¿½o");  
    }
    else
    {
        format(Enviar, sizeof(Enviar), "INSERT INTO `presos` (`Nome`, `Tempo`, `TempoAtual`, `Admin`, `Motivo`, `Cadeia`) VALUES ('%s', %d, %d, '%s', '%s', %d)", EscapeString(Nick), tempo, TempoJ, EscapeString(PegarNick(playerid)), EscapeString(motivoban), 0);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Falha ao enviar puniï¿½ï¿½o");  
    }

    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `UltimoInterior` = 11 WHERE `Nome` = '%s'", EscapeString(Nick));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Falha ao efetuar na conta");  

    // EnviarLogPrisao(PegarNick(playerid), Nick, tempo, motivoban);

    format(Mensagem, sizeof(Mensagem), "| RC-ADMIN | %s %s agendou prisï¿½o do(a) jogador(a) %s por %d minutos ( Motivo: %s )", CargoAdmin(2, playerid), PegarNick(playerid), Nick, tempo, motivoban);   
    SendClientMessageToAll(0xbafa25FF, Mensagem);
    return 1;
}

CMD:punir(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id,
        tempo,
        motivo[70];
    if(sscanf(params, "dds[70]", id, tempo, motivo)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Punir [ID] [Tempo] [Motivo]"); 
    if(tempo < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use tempo maior que 1");
    if(id == playerid) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar em Você!");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode punir um membro da equipe!");
    }

    Jogador[id][uInterior] = Departamento(id);
    Jogador[id][uInteriorEx] = 0;
    CatalogarPrisao(id, tempo, motivo, PegarNick(playerid), 0); 
    // EnviarLogPrisao(PegarNick(playerid), PegarNick(id), tempo, motivo);

    new Mensagem[200];
    if(Jogador[id][Preso] > 0) format(Mensagem, sizeof(Mensagem), "| RC-ADMIN | %s %s prendeu o(a) jogador(a) %s por mais %d minutos ( Motivo: %s )", CargoAdmin(2, playerid), PegarNick(playerid), PegarNick(id), tempo, motivo);   
    else format(Mensagem, sizeof(Mensagem), "| RC-ADMIN | %s %s prendeu o(a) jogador(a) %s por %d minutos ( Motivo: %s )", CargoAdmin(2, playerid), PegarNick(playerid), PegarNick(id), tempo, motivo);   
    SendClientMessageToAll(0xbafa25FF, Mensagem);  
    if(Jogador[id][Preso] == 0) MostrarRelogioPrisao(id);
    Jogador[id][Preso] = TempoCadeia(id, tempo); 
    Jogador[playerid][CadeiaEstilo] = 0;
    
    ColocarNaCadeia(id);
    return 1;
}

CMD:soltar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Soltar [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][Preso] == 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador não está preso(a)");
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você foi solto(a) pelo(a) %s %s", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0xFFFF00FF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você soltou o(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
    RemoverDaCadeia(id);
    Jogador[id][Preso] = 0;
    return 1;
}

CMD:olhar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    if(pAdmin[playerid][Espiando] == false)
    {
        new id;
        if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Olhar [ID]");
        if(id == playerid) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode se espiar");
        if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
        if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
        if(GetPVarInt(id, "BloquearInfo") == 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | está com as informaï¿½ï¿½es bloqueadas.");

        if(Jogador[playerid][Admin] < 4){
            if(Jogador[id][Admin] > 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando em um membro da equipe");
        }

        GetPlayerPos(playerid, pAdmin[playerid][aPos][0], pAdmin[playerid][aPos][1], pAdmin[playerid][aPos][2]);
        GetPlayerFacingAngle(playerid, pAdmin[playerid][aPos][3]);
        pAdmin[playerid][InteriorADM] = GetPlayerInterior(playerid);
        pAdmin[playerid][VirtualWorldADM] = GetPlayerVirtualWorld(playerid);
        TogglePlayerSpectating(playerid, 1);
        pAdmin[playerid][EspiandoID] = id;
        pAdmin[playerid][Espiando] = true; 

        if(pAdmin[playerid][VerComandos] == false){
            pAdmin[playerid][VerCID] = id;
            pAdmin[playerid][VerComandos] = true;
        }

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Você está telando o(a) jogador(a) %s[%d]", PegarNick(id), id);
        SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
        return 1;
    }
    RemoverEspiao(playerid);
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você saiu do modo espiï¿½o!");
    return 1;
}

CMD:vtrazer(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /vtrazer [Veiculo-ID]");
    if(!IsValidVehicle(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse veículo não existe!");
    new Float:mPos[3];
    GetPlayerPos(playerid, mPos[0], mPos[1], mPos[2]);
    SetVehicleVirtualWorld(id, GetPlayerVirtualWorld(playerid));
    LinkVehicleToInterior(id, GetPlayerInterior(playerid));
    SetVehiclePos(id, mPos[0]+3.0, mPos[1], mPos[2]);
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você puxou o veículo para sua posiï¿½ï¿½o!");
    return 1;
}

CMD:vir(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /vir [Veiculo-ID]");
    if(!IsValidVehicle(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse veículo não existe!");
    new Float:mPos[3];
    GetVehiclePos(id, mPos[0], mPos[1], mPos[2]);
    SetPlayerPos(playerid, mPos[0]+2.0, mPos[1], mPos[2]);
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você foi atï¿½ um veículo");
    return 1;
}

CMD:puxartodos(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new Float:mPos[3];
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| SERVIDOR | %s %s puxou todos para posiï¿½ï¿½o dele!", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    GetPlayerPos(playerid, mPos[0], mPos[1], mPos[2]);
    for(new i=0; i < MAX_PLAYERS; i++){
        if(i == playerid) continue;
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[playerid][Admin] < 1) continue;
        SetPlayerPos(i, mPos[0], mPos[1], mPos[2]+4.0);
        SendClientMessage(i, 0x00BFFFFF, Mensagem);
    }
    return 1;
}

CMD:dararma(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id, 
        arma, 
        municao;
    if(sscanf(params, "ddd", id, arma, municao)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Dararma [ID] [Arma-id] [Munição]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)!");
    //if(municao > 9999) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Servidor não suporta esse tanto de Munição!");
    if(Jogador[playerid][Admin] < 2){
        if(arma == 38 || arma == 39 || arma == 36 || arma == 35 || arma == 44) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não permissão para pegar essa arma!");
    }
    if(arma == 38 || arma == 39 || arma == 36 || arma == 35 || arma == 44){
        if(Jogador[id][Admin] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode dar essa arma para esse jogador(a)");
    }
    GivePlayerWeapon(id, arma, municao);
    new ArmaNome[90],
        String[128];
    GetWeaponName(arma, ArmaNome, sizeof(ArmaNome));
    format(String, sizeof(String), "| ADMIN | Você deu uma %s com %d bala(a) para %s[%d]", ArmaNome, municao, PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, String);
    format(String, sizeof(String), "| ARMA | %s %s te deu uma %s com %d bala(s)", CargoAdmin(2, playerid), PegarNick(playerid), ArmaNome, municao);
    SendClientMessage(id, 0x00BFFFFF, String);
    return 1;
}

CMD:empregos(playerid)
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new Dialog[2500];
    strcat(Dialog, "ID\tCategoria\tProfissão\tLevel\n");
    for(new i=0; i < sizeof(pAgencia); i++)
    {
        strcatEx(Dialog, "{FFFFFF}%d.\t{00BFFF}%s\t{00BFFF}%s\t{FE2E2E}%d\n", pAgencia[i][ProfID], pAgencia[i][Categoria], pAgencia[i][ProfissaoNome], pAgencia[i][Level]);
    }
    Dialog_Show(playerid, SemFuncaonalidade, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Profissï¿½es", Dialog, "Fechar", "");
    return 1;
}

CMD:setemprego(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new id, ProfSelect[70];
    if(sscanf(params, "ds[70]", id, ProfSelect)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /SetEmprego [ID] [Profissão]");
    if(Jogador[playerid][Admin] < 6){
        if(id != playerid) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode alterar Profissão de outro(a) jogador(a)");
    }
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(!strcmp(Jogador[id][Profissao], ProfSelect, true)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse jogador jï¿½ se encontra nessa Profissão");
    if(!SetPlayerEmprego(id, ProfSelect)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa Profissão não existe");

    new Mensagem[128];
    
    if(id == playerid)
    {
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Sua Profissão foi alterada para {fc520f}%s", ProfSelect);
        SendClientMessage(playerid, -1, Mensagem);    
        return 1;
    }
    format(Mensagem, sizeof(Mensagem), "| ADMIN | %s %s alterou sua Profissão para %s", CargoAdmin(2, playerid), PegarNick(playerid), ProfSelect);
    SendClientMessage(id, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você alterou a Profissão de %s[%d] para %s", PegarNick(id), id, ProfSelect);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:dargrana(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id,
        grana;
    if(sscanf(params, "dd", id, grana)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /DarGrana [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    Jogador[id][Dinheiro] += grana;
    new mensagem[128];
    format(mensagem, sizeof(mensagem), "| INFO | %s %s adicionou %s de dinheiro na sua conta", CargoAdmin(2, playerid), PegarNick(playerid), DinheiroSeparar(grana));
    SendClientMessage(id, 0x00BFFFFF, mensagem);
    format(mensagem, sizeof(mensagem), "| ADMIN | Você deu %s dinheiro para %s[%d]", DinheiroSeparar(grana), PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, mensagem);
    return 1;
}

CMD:dargranasuja(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new id,
        grana;
    if(sscanf(params, "dd", id, grana)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /DarGranaSuja [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    Jogador[id][DinheiroSujo] += grana;
    new mensagem[128];
    format(mensagem, sizeof(mensagem), "| INFO | %s %s adicionou %s de dinheiro sujo na sua conta", CargoAdmin(2, playerid), PegarNick(playerid), DinheiroSeparar(grana));
    SendClientMessage(id, 0x00BFFFFF, mensagem);
    format(mensagem, sizeof(mensagem), "| ADMIN | Você deu %s dinheiro sujo para %s[%d]", DinheiroSeparar(grana), PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, mensagem);
    return 1;
}

CMD:congelar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Congelar [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[playerid][Admin] != 7 && Jogador[playerid][Admin] != 6){
        if(Jogador[id][Admin] > 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar em um membro da equipe!");
    }
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | %s %s congelou Você", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você congelou %s", PegarNick(id));
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    TogglePlayerControllable(id, 0);
    return 1;
}

CMD:descongelar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Descongelar [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | %s %s descongelou Você", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você descongelou %s", PegarNick(id));
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    TogglePlayerControllable(id, 1);
    return 1;
}

CMD:limparchat(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    for(new i=0; i < 100; i++){
        SendClientMessageToAll(-1, " ");
    }

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| CHAT-ADMIN | %s %s limpou o chat global", CargoAdmin(2, playerid), PegarNick(playerid));

    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] < 2) continue;
        SendClientMessage(i, 0x00BFFFFF, Mensagem);
    }
    return 1;
}

CMD:cnn(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new Mensagem[128];
    if(sscanf(params, "s[128]", Mensagem)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Cnn [Mensagem]");

    if(AlertaAdminStt == true){
        KillTimer(TempoAlertaAdmin);
        OcultarAdminAlerta();
        AlertaAdminStt = false;
    }
    MostrarAdminAlerta();

    new String[200];
    if(Jogador[playerid][Admin] == 7) format(String, sizeof(String), "~g~%s ~w~%s", CargoAdmin(2, playerid), PegarNick(playerid));
    else if(Jogador[playerid][Admin] == 6) format(String, sizeof(String), "~r~%s ~w~%s", CargoAdmin(2, playerid), PegarNick(playerid));
    else if(Jogador[playerid][Admin] == 5) format(String, sizeof(String), "~p~%s ~w~%s", CargoAdmin(2, playerid), PegarNick(playerid));
    else if(Jogador[playerid][Admin] == 4) format(String, sizeof(String), "~b~%s ~w~%s", CargoAdmin(2, playerid), PegarNick(playerid));
    else if(Jogador[playerid][Admin] == 3 || Jogador[playerid][Admin] == 2) format(String, sizeof(String), "~y~%s ~w~%s", CargoAdmin(2, playerid), PegarNick(playerid));

    TextDrawSetString(AlertaAdmin[1], ConverterTexto(String));
    TextDrawSetString(AlertaAdmin[2], ConverterTexto(Mensagem)); 
    
    TempoAlertaAdmin = SetTimer("OcultarAdminAlerta", 8000, false); 
    AlertaAdminStt = true;
    return 1;
}

CMD:ann(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new Mensagem[128];
    if(sscanf(params, "s[128]", Mensagem)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Ann [Mensagem]");

    if(AlertaAdminStt == true){
        KillTimer(TempoAlertaAdmin);
        OcultarAdminAlerta();
        AlertaAdminStt = false;
    }
    MostrarAdminAlerta();
    TextDrawSetString(AlertaAdmin[1], ConverterTexto("Alerta"));
    TextDrawSetString(AlertaAdmin[2], ConverterTexto(Mensagem));
    TempoAlertaAdmin = SetTimer("OcultarAdminAlerta", 8000, false);
    AlertaAdminStt = true;
    return 1;
}

CMD:raviso(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new id, quant;
    if(sscanf(params, "dd", id, quant)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /rAviso [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][Avisos] < quant) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | não tem toda essa quantia");
    Jogador[id][Avisos] -= quant;
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Avisos removidos");
    return 1;
}

CMD:respawnarveiculos(playerid)
{
    if(Jogador[playerid][Admin] < 2) return 0;
    if(RespawnAtivo == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Um respawn jï¿½ está em andamento, aguarde.");
    EstadoRespawn = 0;
    RespawnTempo();
    return 1;
}

CMD:rveh(playerid)
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new Float:Tes[3],
        bool:Erromsg = false
    ;
    for(new i=0; i < MAX_VEHICLES; i++)
    {
        if(VeiculoServer[i][VeiculoOn] == false) continue;
        GetVehiclePos(i, Tes[0], Tes[1], Tes[2]);
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, Tes[0], Tes[1], Tes[2])) continue;

        if(IsTrailerAttachedToVehicle(i)){
   			DetachTrailerFromVehicle(i);
   		}

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Você respawnou o veículo id %d", i);
        SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
        if(VeiculoServer[i][VeiculoRegenerar] == true) SetVehicleHealth(i, VeiculoServer[i][VidaMaxima]);
        SetVehiclePos(i, VeiculoServer[i][PosicaoCarX], VeiculoServer[i][PosicaoCarY], VeiculoServer[i][PosicaoCarZ]);
        SetVehicleZAngle(i, VeiculoServer[i][PosicaoCarA]);
        Erromsg = true; 
        break;
    }

    if(Erromsg == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está perto de nenhum veículo");
    return 1;
}

CMD:ghost(playerid)
{
    if(Jogador[playerid][Admin] < 1) return 0;
    if(pAdmin[playerid][ModoGhost] == false){
        DisableRemoteVehicleCollisions(playerid, 1);
        SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você entrou no modo ghost");
        pAdmin[playerid][ModoGhost] = true;
        return 1;
    }
    pAdmin[playerid][ModoGhost] = false;
    DisableRemoteVehicleCollisions(playerid, 0);
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você saiu no modo ghost");
    return 1;
}

CMD:vercomandos(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /VerComandos [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");

    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][TempAdmin] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode visualizar da equipe!");
    }

    new Mensagem[128];
    if(pAdmin[playerid][VerComandos] == false){
        pAdmin[playerid][VerCID] = id;
        pAdmin[playerid][VerComandos] = true;
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Você está visualizando os comandos de %s[%d]", PegarNick(id), id);
        SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
        return 1;
    }
    pAdmin[playerid][VerComandos] = false;
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você não está mais visualizando os comandos");
    return 1;
}

CMD:forcarcomando(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id, ComandoEnv[128];
    if(sscanf(params, "ds[128]", id, ComandoEnv)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /ForcarComando [ID] [Comando]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");

    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando em um membro da equipe");
    }

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você forcou o comando {00BFFF}%s{FFFFFF} em {00BFFF}%s[%d]", ComandoEnv, PegarNick(id), id);
    SendClientMessage(playerid, -1, Mensagem);
    CallRemoteFunction("OnPlayerCommandText", "is", id, ComandoEnv);
    return 1;
}

CMD:forcartexto(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id, ComandoEnv[128];
    if(sscanf(params, "ds[128]", id, ComandoEnv)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /ForcarTexto [ID] [Texto]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");

    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando em um membro da equipe");
    }

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você forcou o(a) jogador(a) a falar {00BFFF}%s{FFFFFF} em {00BFFF}%s[%d]", ComandoEnv, PegarNick(id), id);
    SendClientMessage(playerid, -1, Mensagem);
    CallRemoteFunction("OnPlayerText", "is", id, ComandoEnv);
    return 1;
}

CMD:rforcartexto(playerid, params[]){
    if(Jogador[playerid][Admin] < 7) return 0;
    new Float:rRange, ComandoEnv[128];
    if(sscanf(params, "fs[128]", rRange, ComandoEnv)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /rForcarTexto [Range] [Texto]");

    new Mensagem[128],
        Float:Nhs[3];
    GetPlayerPos(playerid, Nhs[0], Nhs[1], Nhs[2]);
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você forcou todos a {00BFFF}%0.2f{FFFFFF} range a falarem {00BFFF}%s", rRange, ComandoEnv);
    SendClientMessage(playerid, -1, Mensagem);

    for(new i=0; i < MAX_PLAYERS; i++){
        if(i == playerid) continue;
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(!IsPlayerInRangeOfPoint(i, rRange, Nhs[0], Nhs[1], Nhs[2])) continue;
        CallRemoteFunction("OnPlayerText", "is", i, ComandoEnv);
    }
    return 1;
}

CMD:macro(playerid)
{
    if(Jogador[playerid][Admin] < 1) return 0;
    new Dialog[500];
    for(new i=0; i < sizeof(MacroAdmin); i++){
        strcatEx(Dialog, "%s\n", MacroAdmin[i][Comando]);
    }
    Dialog_Show(playerid, MacroAdmin, DIALOG_STYLE_TABLIST, "{FF0000}Macro", Dialog, "Enviar", "Fechar");
    return 1;
}

CMD:forcarafk(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /ForcarAFK [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][EstadoAFK] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse jogador(a) jï¿½ está ausente");
    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode forçar em um membro da equipe!");
    }
    IniciarAntiAFK(id);
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você forï¿½ou o anti-afk no jogador %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:removerafk(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /RemoverAfk [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][EstadoAFK] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse jogador(a) não está ausente");
    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode forçar em um membro da equipe!");
    }
    
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você removeu o anti-afk no jogador %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);

    RemoverAFK(id, playerid);
    return 1;
}

CMD:checkarmas(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /CheckArmas [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    
    new Dialog[600],
        cArmaNome[32],
        cArmaID,
        cBalaID;
    strcat(Dialog, "Slot\tArma\tBalas\n");
    for(new i=0; i < 12; i++)
    {
        GetPlayerWeaponData(id, i, cArmaID, cBalaID);
        GetWeaponName(cArmaID, cArmaNome, sizeof(cArmaNome));
        strcatEx(Dialog, "{FFFFFF}%d.\t{FF0000}%s[%d]\t{FF8C00}%d\n", i, cArmaNome, cArmaID, cBalaID);
    }
    Dialog_Show(playerid, ArmasinfoAdmin, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Check Armas", Dialog, "Fechar", "");
    return 1;
}

CMD:cornick(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new cor;
    if(sscanf(params, "h", cor)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /CorNick [html]");
    SetPlayerColor(playerid, cor);
    SetPlayerMarkerForPlayer(playerid, 1, (GetPlayerColor(1) & 0xFFFFFF00));
    return 1;
}

CMD:online(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new Alvo[70];
    if(sscanf(params, "s[70]", Alvo)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Online [Nick]");
    
    new bool:TemNn = false;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(strcmp(PegarNick(i), Alvo)) continue;
        new Mensagem[100];
        format(Mensagem, sizeof(Mensagem), "| ADMIN | {FF8C00}%s[%d]{FFFFFF} está online", PegarNick(i), i);
        SendClientMessage(playerid, -1, Mensagem);
        TemNn = true;
    }
    if(TemNn == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse jogador(a) não está online");
    return 1; 
}

CMD:cheat(playerid)
{
    if(Jogador[playerid][Admin] < 4) return 0;
    if(pAdmin[playerid][AntiNotificacao] == false){
        SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você desativou as notificaï¿½ï¿½es do Anti Cheater");
        pAdmin[playerid][AntiNotificacao] = true;
        return 1;
    }
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você ativou as notificaï¿½ï¿½es do Anti Cheater");
    pAdmin[playerid][AntiNotificacao] = false;
    return 1;
}

CMD:reiniciar(playerid)
{
    if(Jogador[playerid][Admin] < 6) return 0;
    SendRconCommand("password asdasuhhdasasdyuoied");
    
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        Kick(i);
    }

    // Salvar Casas / Empresa etc..
    ReiniciarCasa(false); 
    ReiniciarEmpresa(false);
    ReiniciarConcessionaria(false);
    ReiniciarFabrica(false);
    ReiniciarBase();
    SendRconCommand("gmx");
    return 1;
}

CMD:expulsartodos(playerid)
{
    if(Jogador[playerid][Admin] < 6) return 0;
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Admin] > 0) continue;
        Kick(i);
    }
    return 1;
}

CMD:ircasa(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /IrCasa [ID]");
    if(pCasa[id][Colocado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa não existe no servidor");
    SetPlayerPos(playerid, pCasa[id][cPosicaoX], pCasa[id][cPosicaoY], pCasa[id][cPosicaoZ]);
    new Mensagem[100];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você teletransportou para casa {FF8C00}%d", id);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

CMD:irempresa(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /IrEmpresa [ID]");
    if(pEmpresa[id][Colocado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa empresa não existe no servidor");
    SetPlayerPos(playerid, pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ]);
    new Mensagem[100];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você teletransportou para empresa {FF8C00}%d", id);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

CMD:setsexo(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id, sexo;
    if(sscanf(params, "dd", id, sexo)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /SetSexo [ID] [Sexo]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][Sexo] == sexo) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) jï¿½ possui esse sexo");
    
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Sexo`=%d WHERE `Nome`='%s'", sexo, EscapeString(PegarNick(id)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema!");

    Jogador[id][Sexo] = sexo;
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você alterou o sexo do(a) jogador(a) {FF8C00}%s[%d]{FFFFFF} para %s", PegarNick(id), id, JogadorSexo(1, id));
    SendClientMessage(playerid, -1, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| INFO | Seu sexo foi alterado para %s{FFFFFF} por %s %s", JogadorSexo(1, id), CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, -1, Mensagem);
    return 1;
}

CMD:abrirservidor(playerid)
{
    if(Jogador[playerid][Admin] < 5) return 0;
    SendRconCommand("password 0");
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você retirou a senha do servidor");
    return 1;
}

CMD:fecharservidor(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new SenhaEE[50];
    if(sscanf(params, "s[50]", SenhaEE)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /FecharServidor [Senha]");
    if(strlen(SenhaEE) <= 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Coloque uma senha maior");
    new Enviar[128];
    format(Enviar, sizeof(Enviar),"password %s", SenhaEE);
    SendRconCommand(Enviar);
    format(Enviar, sizeof(Enviar), "| ADMIN | Você trancou o servidor ( Senha: {FE2E2E}%s{FFFFFF} )", SenhaEE);
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}

CMD:whtl(playerid)
{
    if(Jogador[playerid][Admin] < 6) return 0;
    if(Whitelist == false)
    {
        mysql_query(IDConexao, "UPDATE `whitelist` SET `Hwid` = 'Ativado' WHERE `Nome` = 'Sistema'", false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao ativar a whitelist");
        Whitelist = true;
        SendClientMessage(playerid, -1, "| ADMIN | Você ativou a whitelist!");
        return 1;
    }
    mysql_query(IDConexao, "UPDATE `whitelist` SET `Hwid` = 'Desativado' WHERE `Nome` = 'Sistema'", false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao desativar a whitelist");
    Whitelist = false;
    SendClientMessage(playerid, -1, "| ADMIN | Você desativou a whitelist");
    return 1;
}

CMD:removerwhtl(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new uNome[70];
    if(sscanf(params, "s[70]", uNome)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /RemoverWhtl [Nome]");
    
    new Cache:Conectar,
        Enviar[128],
        ValorWH;
    
    format(Enviar, sizeof(Enviar), "SELECT * FROM `whitelist` WHERE `Nome` = '%s'", EscapeString(uNome));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema na verificaï¿½ï¿½o!");
    ValorWH = cache_num_rows();
    cache_delete(Conectar);
    if(ValorWH < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse(a) usuï¿½rio(a) não existe");


    format(Enviar, sizeof(Enviar), "DELETE FROM `whitelist` WHERE `Nome` = '%s'", EscapeString(uNome));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao revogar o acesso");
    format(Enviar, sizeof(Enviar), "| ADMIN | Você revogou o acesso do(a) {fc520f}%s{FFFFFF} com sucesso!", uNome);
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}

CMD:setwhtl(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new uNome[70], uHwid[50];
    if(sscanf(params, "s[70]s[50]", uNome, uHwid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /SetWhtl [Nick] [Hwid]");
    
    new Cache:Conectar,
        Enviar[300];
    format(Enviar, sizeof(Enviar), "SELECT * FROM `whitelist` WHERE `Nome` = '%s'", EscapeString(uNome));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao fazer o hwid!");
    new cocoa = cache_num_rows();
    cache_delete(Conectar);
    if(cocoa > 0)
    {
        format(Enviar, sizeof(Enviar), "UPDATE `whitelist` SET `Hwid` = '%s' WHERE `Nome` = '%s'", EscapeString(uHwid), EscapeString(uNome));
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao atualizar o hwid!");
        format(Enviar, sizeof(Enviar), "| ADMIN | Foi atualizado o hwid do(a) %s ( {FF8C00}%s{FFFFFF} )", uNome, uHwid);
        SendClientMessage(playerid, -1, Enviar);
        return 1;   
    }

    format(Enviar, sizeof(Enviar), "INSERT INTO `whitelist` (`Nome`, `Hwid`) VALUES ('%s', '%s')", EscapeString(uNome), EscapeString(uHwid));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao criar esse registro!");
    format(Enviar, sizeof(Enviar), "| ADMIN | Usuï¿½rio(a) {FF8C00}%s{FFFFFF} foi registrado(a) ( {FF8C00}%s{FFFFFF} )", uNome, uHwid);
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}

CMD:vida(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Vida [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    SetPlayerHealth(id, 100.0);
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| INFO | %s %s regenerou sua vida", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você regenerou a vida do(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:explodir(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Explodir [id]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] == 7) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando em um desenvolvedor");
    }

    new Float:vfPos[3],
        Mensagem[128]
    ;
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você explodiu o(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);

    if(IsPlayerInAnyVehicle(id))
    {
        new vid = GetPlayerVehicleID(id);
        SetPlayerHealth(id, 10.0);
        GetVehiclePos(vid, vfPos[0], vfPos[1], vfPos[2]); 
        SetVehicleHealth(vid, 0);
        CreateExplosion(vfPos[0], vfPos[1], vfPos[2], 12, 20);
        return 1;
    }
    SetPlayerHealth(id, 10.0);
    GetPlayerPos(id, vfPos[0], vfPos[1], vfPos[2]), 
    CreateExplosion(vfPos[0], vfPos[1], vfPos[2], 12, 20);
    return 1;
}

CMD:scanemail(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new sEmail[90];
    if(sscanf(params, "s[90]", sEmail)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /ScanEmail [Email]");

    if(!VerificarEmail(sEmail)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Formato de email Inválido");

    new Cache:Conectar,
        Enviar[128];
    format(Enviar, sizeof(Enviar), "SELECT * FROM `rippzyrpg` WHERE `email` = '%s'", EscapeString(sEmail));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um erro ao procurar esse email");
    if(cache_num_rows() > 0)
    {
        new Mensagem[228], Titular[70];
        cache_get_value(0, "Nome", Titular, 70);
        cache_delete(Conectar);
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Email {00FF00}%s{FFFFFF} está no nome de {FE2E2E}%s{FFFFFF}", sEmail, Titular);
        SendClientMessage(playerid, -1, Mensagem);
        return 1;
    }
    cache_delete(Conectar);
    SendClientMessage(playerid, 0xfc520fFF, "| ERRO | não foi encontrado nenhum usuï¿½rio(a) com esse email");
    return 1;
}

CMD:scanip(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new jIp[20];
    if(sscanf(params, "s[20]", jIp)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /ScanIP [Ip]");
    
    new Cache:Conectar,
        Enviar[128]
    ;
    format(Enviar, sizeof(Enviar), "SELECT * FROM `rippzyrpg` WHERE `Ip` = '%s'", EscapeString(jIp));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um erro ao procurar esse IP");
    if(cache_num_rows() > 0)
    {
        new jIps = cache_num_rows(),
            Dialog[1000],
            jNickIP[70],
            UltimoLGN
        ;
        strcat(Dialog, "ID\tNick\tLogin\n");
        for(new i=0; i < jIps; i++)
        {
            cache_get_value(i, "Nome", jNickIP, 70);
            cache_get_value_name_int(i, "UltimoLogin", UltimoLGN);
            strcatEx(Dialog, "{FFFFFF}%d.\t{FF8C00}%s\t{00BFFF}%s\n", i, jNickIP, ConverterSegundosEx(gettime()-UltimoLGN));
        }
        cache_delete(Conectar);
        Dialog_Show(playerid, SemFDuncaoaoa, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}ScanIP", Dialog, "Fechar", "");
        return 1;
    }
    SendClientMessage(playerid, 0xfc520fFF, "| ERRO | não foi encontrado nenhuma conta que possui esse IP registrado");
    cache_delete(Conectar);
    return 1;
}

CMD:scannick(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new NickPA[70];
    if(sscanf(params, "s[70]", NickPA)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /ScanNick [Nome]");
    
    new Cache:Conectar,
        Enviar[128];
    format(Enviar, sizeof(Enviar), "SELECT * FROM `rippzyrpg` WHERE `Nome` = '%s'", EscapeString(NickPA));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um erro ao procurar esse nome");
    if(cache_num_rows() > 0)
    {
        new Dialog[1000],
            ProPA[70],
            EmailPA[70],
            IpPA[30],
            DiscordPA[25],
            LevelPA,
            DinheiroPA,
            DinheiroBancoPA,
            CoinsPA,
            ExpPA,
            UltimoLGN,
            TempoG;

        cache_get_value(0, "Profissao", ProPA, 70);
        cache_get_value(0, "Ip", IpPA, 30);
        cache_get_value(0, "Email", EmailPA, 30);
        cache_get_value(0, "Discord", DiscordPA, 20);
        cache_get_value_name_int(0, "Level", LevelPA);
        cache_get_value_name_int(0, "Dinheiro", DinheiroPA);
        cache_get_value_name_int(0, "DinheiroBanco", DinheiroBancoPA);
        cache_get_value_name_int(0, "Coins", CoinsPA);
        cache_get_value_name_int(0, "Experiencia", ExpPA);
        cache_get_value_name_int(0, "UltimoLogin", UltimoLGN);
        cache_get_value_name_int(0, "TempoUp", TempoG);
        cache_delete(Conectar);

        new ips[30],
            ips1[30],
            ips2[30];
        // GetIPCountry(IpPA, ips, sizeof(ips));
        // GetIPISP(IpPA, ips1, sizeof(ips1));
        // GetIPCity(IpPA, ips2, sizeof(ips2));
        
        strcatEx(Dialog, "Nome: {FF8C00}%s\n", NickPA);
        strcatEx(Dialog, "Level: {00BFFF}%d\n", LevelPA);
        strcatEx(Dialog, "Experiï¿½ncia: {00BFFF}%d\n", ExpPA);
        strcatEx(Dialog, "Profissão: {FF8C00}%s\n", ProPA);
        strcatEx(Dialog, "Tempo UP: {FF8C00}%s\n", SegundosParaMinutosEx(TempoG));
        strcatEx(Dialog, "Dinheiro: {32CD32}$%s\n", DinheiroSeparar(DinheiroPA));
        strcatEx(Dialog, "Dinheiro Banco: {FF8C00}$%s\n", DinheiroSeparar(DinheiroBancoPA));
        strcatEx(Dialog, "Coins: {FFFF00}$%s\n", DinheiroSeparar(CoinsPA));

        if(strcmp(DiscordPA, "*")) strcatEx(Dialog, "Discord: {00BFFF}%s\n", DiscordPA);
        else strcat(Dialog, "Discord: {FF0000}não Vinculado\n");

        strcatEx(Dialog, "Ip: {00BFFF}%s\n", IpPA);
        strcatEx(Dialog, "Paï¿½s: {FFA500}%s\n", ips);
        strcatEx(Dialog, "Operadora: {FFA500}%s\n", ips1);
        strcatEx(Dialog, "Cidade: {FFA500}%s\n", ips2); 
        strcatEx(Dialog, "Email: {00FF00}%s\n", EmailPA);
        strcatEx(Dialog, "ï¿½ltimo Login: {FF0000}%s", ConverterSegundosEx(gettime()-UltimoLGN));
        Dialog_Show(playerid, SemFDuncaoaoa, DIALOG_STYLE_TABLIST, "{FF0000}Procura Admin", Dialog, "Fechar", "");
        return 1;
    }
    SendClientMessage(playerid, 0xfc520fFF, "| ERRO | não foi encontrado nenhuma conta que possui esse nick registrado");
    cache_delete(Conectar);
    return 1;
}

CMD:aconsertar(playerid)
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new Float:tesA[3],
        bool:Prer = false;
    GetPlayerPos(playerid, tesA[0], tesA[1], tesA[2]);
    for(new i=0; i < MAX_VEHICLES; i++)
    {
        if(VeiculoServer[i][VeiculoOn] == false) continue;
        if(!IsVehicleInRangeOfPoint(i, 3.0, tesA[0], tesA[1], tesA[2])) continue;
        if(VeiculoServer[i][vQuebrado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse veículo não está quebrado");
        VeiculoServer[i][vQuebrado] = false;
        SetVehicleHealth(i, VeiculoServer[i][VidaMaxima]);
        SendClientMessage(playerid, 0xFFFF00FF, "| ADMIN | veículo consertado com sucesso!");
        Prer = true;
        break;
    }
    if(Prer == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está perto de nenhum veículo");
    return 1;
}

CMD:gerarcodigo(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new TDias;
    if(sscanf(params, "d", TDias)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /GerarCodigo [Dias]");
    if(TDias < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Coloque um valor acima de 0");

    new Enviar[400],  

        // Partes do Código
        Parte1[20],
        Parte2[20],
        Parte3[20],
        Parte4[20],
        FCodigo[70];
    format(Parte1, 20, GetRandomString(4));
    format(Parte2, 20, GetRandomString(4));
    format(Parte3, 20, GetRandomString(4));
    format(Parte4, 20, GetRandomString(4));
    format(FCodigo, sizeof(FCodigo), "%s-%s-%s-%s", Parte1, Parte2, Parte3, Parte4);

    format(Enviar, sizeof(Enviar), "INSERT `acessocodigo` (`Codigo`, `Admin`, `Geracao`, `Ativado`, `UsadoPor`, `Dias`) VALUES ('%s', '%s', %d, %d, '%s', %d)", FCodigo, EscapeString(PegarNick(playerid)), gettime(), 0, "*", TDias);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao gerar o Código");

    format(Enviar, sizeof(Enviar), "| Código | Você gerou um Código ( {FF8C00}%s{FFFFFF} ) por {00BFFF}%d{FFFFFF} dia(s)", FCodigo, TDias);
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}

CMD:consultarcodigo(playerid, params[])
{ 
    if(Jogador[playerid][Admin] < 6) return 0;
    new PCodigo[80];
    if(sscanf(params, "s[80]", PCodigo)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /ConsultarCodigo [Código]");
 
    new Cache:Conectar,
        Enviar[300]
    ;
    format(Enviar, sizeof(Enviar), "SELECT * FROM `acessocodigo` WHERE `Codigo` = '%s'", EscapeString(PCodigo));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao efetuar consulta!");

    new bool:Gamb = false;
    if(cache_num_rows() > 0)
    {
        new UsadoPor[70],
            TAtivado,
            Geracao,
            TDias,
            TAdmin[70],
            Dialog[400]
        ;

        Gamb = true;
        cache_get_value(0, "UsadoPor", UsadoPor, 70);
        cache_get_value(0, "Admin", TAdmin, 70);
        cache_get_value_name_int(0, "Geracao", Geracao);
        cache_get_value_name_int(0, "Ativado", TAtivado);
        cache_get_value_name_int(0, "Dias", TDias);

        strcatEx(Dialog, "{FFFFFF}Gerado por {FF6347}%s\n", TAdmin);
        strcatEx(Dialog, "{FFFFFF}Data de Geração: {FF6347}%s\n", GetDateFromTime(Geracao));

        if(!strcmp(UsadoPor, "*")) strcat(Dialog, "{FFFFFF}Ativado por {FF4500}( não Ativo )\n");
        else strcatEx(Dialog, "{FFFFFF}Ativado por {FF0000}%s\n", UsadoPor);

        if(TAtivado == 0) strcat(Dialog, "{FFFFFF}Data Ativação: {FF4500}N/A\n");
        else strcatEx(Dialog, "{FFFFFF}Data Ativação: {32CD32}%s\n", GetDateFromTime(TAtivado));

        strcatEx(Dialog, "{FFFFFF}Dia(s) do Código: {FF4500}%d", TDias);
        Dialog_Show(playerid, NenhumaFunc, DIALOG_STYLE_TABLIST, "{FF0000}Consulta do Código", Dialog, "Fechar", "");

    }
    cache_delete(Conectar);
    if(Gamb == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse Código não existe!");

    return 1;
}

CMD:consultaracesso(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new PNick[80];
    if(sscanf(params, "s[80]", PNick)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /ConsultarAcesso [Usuï¿½rio]");
 
    new Cache:Conectar,
        Enviar[300]
    ;
    format(Enviar, sizeof(Enviar), "SELECT * FROM `acessocodigo` WHERE `UsadoPor` = '%s'", EscapeString(PNick));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao efetuar consulta!");

    new bool:Gamb = false;
    if(cache_num_rows() > 0)
    {
        new PCodigo[70];
        cache_get_value(0, "Codigo", PCodigo, 70);
        Gamb = true;
        format(Enviar, sizeof(Enviar), "| ACESSO | Usuï¿½rio(a) {00BFFF}%s{FFFFFF} possui o Código ( {FF4500}%s{FFFFFF} )", PNick, PCodigo);
        SendClientMessage(playerid, -1, Enviar);
    }
    cache_delete(Conectar);
    if(Gamb == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse usuï¿½rio não existe");
    return 1;
}

CMD:revogarcodigo(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0; 
    new PCodigo[80];
    if(sscanf(params, "s[80]", PCodigo)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /RevogarCodigo [Código]");

    new Enviar[200],
        Cache:Conectar,
        UsadoPor[70]
    ;

    format(Enviar, sizeof(Enviar), "SELECT * FROM `acessocodigo` WHERE `Codigo` = '%s'", EscapeString(PCodigo));
    Conectar = mysql_query(IDConexao, Enviar);

    new bool:moba = false;
    if(cache_num_rows() > 0)
    {
        moba = true;
        cache_get_value(0, "UsadoPor", UsadoPor, 70);
    }
    cache_delete(Conectar);
    if(moba == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse Código não existe");

    format(Enviar, sizeof(Enviar), "DELETE FROM `acessocodigo` WHERE `Codigo` = '%s'", EscapeString(PCodigo));
    mysql_query(IDConexao, Enviar, false);

    format(Enviar, sizeof(Enviar), "DELETE FROM `whitelist` WHERE `Nome` = '%s'", EscapeString(UsadoPor));
    mysql_query(IDConexao, Enviar, false);

    if(IsPlayerConnected(PegarIdPeloNick(UsadoPor)))
    {
        format(Enviar, sizeof(Enviar), "| AVISO | Seu acesso foi revogado(a) por {fc520f}%s", PegarNick(playerid));
        SendClientMessage(PegarIdPeloNick(UsadoPor), -1, Enviar);

        format(Enviar, sizeof(Enviar), "| AVISO | O(A) Jogador(a) {fc520f}%s[%d]{FFFFFF} estava online e foi expulso(a)", UsadoPor, PegarIdPeloNick(UsadoPor));
        SendClientMessage(playerid, -1, Enviar);
        SetTimerEx("KickEx", 1000, false, "d", PegarIdPeloNick(UsadoPor));
    }

    format(Enviar, sizeof(Enviar), "| AVISO | Código ( {fc520f}%s{FFFFFF} ) revogado", PCodigo);
    SendClientMessage(playerid, -1, Enviar);
    return 1;
}

CMD:recompensar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new recomp[90], id;
    if(sscanf(params, "ds[90]", id, recomp)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Recompensar [ID] [Recompensa]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");

    new Enviar[300];
    format(Enviar, sizeof(Enviar), "INSERT `recompensas` (`NomeAtual`, `Nome`, `Recompensa`, `Data`) VALUES ('%s', '%s', '%s', %d)", EscapeString(PegarNick(id)), EscapeString(PegarNick(id)), EscapeString(recomp), gettime());
    mysql_query(IDConexao, Enviar, false);

    format(Enviar, sizeof(Enviar), "| RECOMPENSA | O(A) Jogador(a) %s[%d] foi recompensado(a) pelo(a) %s", PegarNick(id), id, CargoAdmin(2, playerid), PegarNick(playerid), recomp);
    SendClientMessageToAll(0xfc520fFF, Enviar);
    return 1; 
}

CMD:regenerarstatus(playerid, params[])
{   
    if(Jogador[playerid][Admin] < 4) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /RegenerarStatus [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| INFO | %s %s regenerou seu status", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você renegerou o status do(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);

    Jogador[id][Fome] = 100;
    Jogador[id][Sede] = 100;
    Jogador[id][Saude] = 100;
    Jogador[id][Sono] = 100;
    Jogador[id][Vicio] = 100;
    Jogador[id][Doenca] = 0;
    AtualizarStatus(id);
    return 1;
}

/*CMD:criarevento(playerid)
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new Dialog[200];
    strcat(Dialog, "Corrida\n");
    strcat(Dialog, "Drive By\n");
    strcat(Dialog, "Surf\n");
    strcat(Dialog, "Esconde Esconde\n");
    strcat(Dialog, "AirDrop");
    Dialog_Show(playerid, EventosAdmin, DIALOG_STYLE_TABLIST, "{FF0000}Eventos", Dialog, "Selecionar", "Fechar");
    return 1;
}*/

CMD:vertelefone(playerid)
{
    if(Jogador[playerid][Admin] < 2) return 0; 
    if(pAdmin[playerid][VerLigacoes] == false)
    {
        SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você está visualizando as ligaï¿½ï¿½es trocadas entre jogadores(as)");
        pAdmin[playerid][VerLigacoes] = true;
        return 1;
    }
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você não está mais visualizando as ligaï¿½ï¿½es");
    pAdmin[playerid][VerLigacoes] = false;
    return 1;
}

CMD:vertelegram(playerid)
{
    if(Jogador[playerid][Admin] < 2) return 0; 
    if(pAdmin[playerid][VerTelegram] == false)
    {
        SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você está visualizando as ligaï¿½ï¿½es trocadas entre jogadores(as)");
        pAdmin[playerid][VerTelegram] = true;
        return 1;
    }
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você não está mais visualizando as ligaï¿½ï¿½es");
    pAdmin[playerid][VerTelegram] = false;
    return 1;
}

CMD:god(playerid)
{
    if(Jogador[playerid][Admin] < 1) return 0; 
    SetPlayerHealth(playerid, 999999.9);
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você agora está invulnerï¿½vel");
    return 1;
}

CMD:camuflar(playerid)
{
    if(Jogador[playerid][Admin] < 2) return 0; 
    if(pAdmin[playerid][Camuflado] == false){
        pAdmin[playerid][Camuflado] = true;
        SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você agora está camuflado(a)"); 
        //RemovePlayerAttachedObject(playerid, 7);
        //RemovePlayerAttachedObject(playerid, 8);
        return 1;
    }
    pAdmin[playerid][Camuflado] = false;
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Você agora não está camuflado(a)"); 
    //SetPlayerAttachedObject(playerid, 7, 19518, 1, -0.039999, -0.182998, 0.126999, -40.4, -0.90003, 0.126999, 3.865, 1.008, 0.465999, 0xFF000000, 0xFF000000);
    //SetPlayerAttachedObject(playerid, 8, 19518, 1, -0.027, -0.182999, -0.147999, 42.4, -2.90001, 2.29991, 3.846, 1, 0.401002, 0xFF000000, 0xFF000000);
    return 1;
}

CMD:alertar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id, aler[90];
    if(sscanf(params, "ds[90]", id, aler)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Alertar [ID] [Mensagem]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não logado(a)");

    PlayerPlaySound(playerid, 1056, 0.0, 0.0, 0.0);
    PlayerPlaySound(id, 1056, 0.0, 0.0, 0.0);

    new Mensagem[168];
    format(Mensagem, sizeof(Mensagem), "%s", aler);
    GameTextForPlayer(id, ConverterTexto(Mensagem), 6000, 3);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Alerta enviado para %s[%d] ( %s )", PegarNick(id), id, aler);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    if(Jogador[playerid][Admin] != 7){
        format(Mensagem, sizeof(Mensagem), "| ADMIN | %s[%d] Enviou um alerta para %s[%d] > %s", PegarNick(playerid), playerid, PegarNick(id), id, aler);
        for(new i=0; i < MAX_PLAYERS; i++){
            if(!IsPlayerConnected(i)) continue;
            if(Jogador[i][Logado] == false) continue;
            if(Jogador[i][Admin] != 7) continue;
            SendClientMessage(i, 0x00BFFFFF, Mensagem);
        }
    }
    return 1;
}

CMD:ipemail(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new Dialog[140],
        fsad[70]
    ;
    format(fsad, sizeof(fsad), "%s:%s", IpEmail, PortaEmail);
    strcatEx(Dialog, "{FFFFFF}Ip: {00BFFF}%s\n", IpEmail);
    strcatEx(Dialog, "{FFFFFF}Porta: {00BFFF}%s\n", PortaEmail);
    strcatEx(Dialog, "{FFFFFF}Senha: {00BFFF}%s\n", SenhaEmail);
    strcatEx(Dialog, "{FFFF00}%s", fsad);
    Dialog_Show(playerid, AlterarEmail, DIALOG_STYLE_TABLIST, "{FF0000}Configuração Host", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:setvw(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /SetVw [ID]");
    SetPlayerVirtualWorld(playerid, id);
    return 1;
}

CMD:setinterior(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /SetInterior [ID]");
    SetPlayerInterior(playerid, id);
    return 1;
}

CMD:setpos(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new Float:x, Float:y, Float:z, Float:a;
    if(sscanf(params, "ffff", x, y, z, a)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /SetPos [X] [Y] [Z] [A]");
    SetPlayerFacingAngle(playerid, a);
    SetPlayerPos(playerid, x, y, z);
    return 1;
}

CMD:trocarcargo(playerid)
{
    if(GetPVarInt(playerid, "PodeAlterarCargo") == 0){
        if(Jogador[playerid][Admin] != 7) return 0;
    }

    new Dialog[95];
    strcat(Dialog, "Aprendiz\n"); 
    strcat(Dialog, "Ajudante\n");
    strcat(Dialog, "Moderador(a)\n");
    strcat(Dialog, "Administrador(a)\n");
    strcat(Dialog, "Coordenador(a)\n");
    strcat(Dialog, "Diretor(a)\n");
    strcat(Dialog, "Desenvolvedor(a)");
    Dialog_Show(playerid, SelecionarAdminCar, DIALOG_STYLE_TABLIST, "{FF0000}Cargo Admin", Dialog, "Alterar", "Fechar");
    return 1;
}

CMD:exrusso(playerid)
{
    if(Jogador[playerid][TempAdmin] != 7) return 0;
    SetPVarInt(playerid, "LiberarForceLogin", 1);
    return 1;
}

CMD:deteccao(playerid)
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new Dialog[1150],
        Mensagem[20]
    ;
    strcat(Dialog, "Jogador(a)\tMotivo\tData\tTipo\n");
    for(new i=0; i < 10; i++)
    {
        if(isnull(dAC[i][MotivoDD])) continue;
        switch(dAC[i][TipoDD])
        {
            case 0: format(Mensagem, sizeof(Mensagem), "Notificaï¿½ï¿½o");
            case 1: format(Mensagem, sizeof(Mensagem), "Banimento");
            case 2: format(Mensagem, sizeof(Mensagem), "Kick");
        }
        strcatEx(Dialog, "{FFFFFF}%s[%d]\t{00BFFF}%s\t{FFA500}%s\t{FFFF00}%s\n", dAC[i][DetectName], dAC[i][DetectID], dAC[i][MotivoDD], GetDateFromTime(dAC[i][HoraDD]), Mensagem);
    }
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Detecï¿½ï¿½o Recentes", Dialog, "Fechar", "");
    return 1;
}

CMD:teleportes(playerid)
{
    if(Jogador[playerid][Admin] < 1) return 0;
    new Dialog[128];
    strcat(Dialog, "Agï¿½ncia de Empregos [Los Santos]\n");
    strcat(Dialog, "Spawn [Los Santos]");
    Dialog_Show(playerid, Teleportt, DIALOG_STYLE_TABLIST, "{FF0000}Teleportes", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:enviarcodigo(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new Mensagem[128];
    if(sscanf(params, "s[128]", Mensagem)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /EnviarCodigo [Email]");
    
    new Cache:Conectar,
        Enviar[128];
    format(Enviar, sizeof(Enviar), "SELECT * FROM `rippzyrpg` WHERE `email` = '%s'", EscapeString(Mensagem));
    Conectar = mysql_query(IDConexao, Enviar, true);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um erro na conexï¿½o");
    if(cache_num_rows() < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nenhuma conta encontrada");
    new Codex[70];
    cache_get_value(0, "Codigo", Codex, 70);
    cache_delete(Conectar);

    new NodeMail[228];
    strcatEx(NodeMail, "paramsadm:%s", PegarNick(playerid));
    strcatEx(NodeMail, "#Codex:%s", Codex);
    SendEmail("Codigo", Mensagem, "Conclusï¿½o seu Código", NodeMail, true, "admin.html"); 

    format(NodeMail, sizeof(NodeMail), "| ADMIN | Código de recuperaï¿½ï¿½o enviado para %s", Mensagem);
    SendClientMessage(playerid, -1, NodeMail);
    return 1;
}

CMD:gerarcoins(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new coinx;
    if(sscanf(params, "d", coinx)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /GerarCoins [Coins]");
    if(coinx < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coins Inválido");

    new lasd[35],
        Mensagem[90];
    strcat(lasd, GerarCoins(PegarNick(playerid), coinx));
    
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você gerou um Código %s com $%s coins", lasd, DinheiroSeparar(coinx));
    SendClientMessage(playerid, 0xF4A460FF, Mensagem);
    return 1;
}

CMD:emailcoins(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new EmailX[90],
        CodigoX[30];
    if(sscanf(params, "s[90]s[30]", EmailX, CodigoX)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /EmailCoins [Email] [Código-Coins]");
    
    new Cache:Conectar,
        Enviar[268];
    format(Enviar, sizeof(Enviar), "SELECT * FROM `codigocoins` WHERE `Codigo` = '%s'", EscapeString(CodigoX));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao fazer a consulta.");
    if(cache_num_rows() < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse Código não existe");
    new Coinx;
    cache_get_value_name_int(0, "Coins", Coinx);
    cache_delete(Conectar);

    format(Enviar, sizeof(Enviar), "UPDATE `codigocoins` SET `email` = '%s' WHERE `Codigo` = '%s'", EscapeString(EmailX), EscapeString(CodigoX));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao fazer a consulta [0x1].");

    stringclear(Enviar);
    strcatEx(Enviar, "CodeX:%s", CodigoX);
    strcatEx(Enviar, "#CoinsX:%s", DinheiroSeparar(Coinx));
    SendEmail("Coins", EmailX, "Seus Coins", Enviar, true, "ativacao.html"); 
    
    format(Enviar, sizeof(Enviar), "| ADMIN | Você enviou o Código %s no email do(a) %s", CodigoX, EmailX);
    SendClientMessage(playerid, 0xDEB887FF, Enviar);
    return 1;
}

CMD:dveh(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /DVeh [veículo-ID]");
    DestroyVehicleEx(id);    
    return 1;
}

CMD:crashar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Crashar [id]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Admin] == 7) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode crashar um(a) desenvolvedor(a)");

    new Mensagem[80];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você enviou um crash para o(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);

    ApplyAnimation(id, "DAN_LOOP_A", "DANCING", 40.0, 1, 0, 0, 0, -1);
    //GameTextForPlayer(id, "$!#{]{]ï¿½ï¿½**&~w", 1000, 6);
    return 1;
}

CMD:deslogarconta(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new ContaNick[30];
    if(sscanf(params, "s[30]", ContaNick)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /DeslogarConta [Nick]");
    if(IsPlayerConnected(PegarIdPeloNick(ContaNick))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) está online no servidor");

    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Logado` = 0 WHERE `Nome` = '%s'", EscapeString(ContaNick));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema");

    format(Enviar, sizeof(Enviar), "| ADMIN | Você deslogou a conta %s", ContaNick);
    SendClientMessage(playerid, 0x00BFFFFF, Enviar);
    return 1;
}

CMD:deslogartodos(playerid, params[])
{
    if(Jogador[playerid][Admin] < 5) return 0;
    mysql_query(IDConexao, "UPDATE `rippzyrpg` SET `Logado` = 0", false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema");
    SendClientMessage(playerid, 0x00BFFFFF, "| ADMIN | Todas as contas foram deslogadas");
    return 1;
}

CMD:fake(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    if(pAdmin[playerid][FalsoPlayer] == true){
        SetPlayerName(playerid, PegarNick(playerid));
        pAdmin[playerid][FalsoPlayer] = false;
        SendClientMessage(playerid, 0x00BFFFFF, "| FAKE | Você voltou para seu nome original");
        return 1;
    }

    new NickFalso[30];
    if(sscanf(params, "s[30]", NickFalso)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Fake [Nick]");

    new Mensagem[90];
    SetPlayerName(playerid, NickFalso);
    pAdmin[playerid][FalsoPlayer] = true;
    format(Mensagem, sizeof(Mensagem), "| FAKE | Você alterou seu nome para %s", NickFalso);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:mutar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id, mutetmp, mtv[30];
    if(sscanf(params, "dds[30]", id, mutetmp, mtv)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Mutar [ID] [Tempo] [Motivo]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode mutar um membro da equipe");
    }

    Jogador[id][Mutado] = (Jogador[id][Mutado] > 0 ? (mutetmp * 60) : (gettime() + (mutetmp * 60)));

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| RC-ADMIN | O(A) Jogador(a) %s foi mutado(a) por %d minutos pelo(a) %s %s ( Motivo: %s )", PegarNick(id), mutetmp, CargoAdmin(2, playerid), PegarNick(playerid), mtv);
    SendClientMessageToAll(0x3CB371FF, Mensagem);
    return 1;
}

CMD:desmutar(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Desmutar [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(gettime() > Jogador[id][Mutado]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está mutado(a)");
    Jogador[id][Mutado] = 0;

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| RC-ADMIN | Você foi desmutado por %s %s", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você desmutou o(a) jogador(a) %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:espiarchat(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new prof[60];
    if(sscanf(params, "s[60]", prof)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /EspiarChat [Profissão]");
    if(!ProfissaoExiste(prof)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa Profissão não existe");

    new Mensagem[90];
    format(pAdmin[playerid][EspiandoProf], 60, prof);
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você está espiando o chat da Profissão/cargo %s", prof);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:clm(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    if(Horapers == true){
        Horapers = false;
        return 1;
    }
    new hr, mr;
    if(sscanf(params, "dd", hr, mr)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Clm [Hora] [Minutos]");
    HorasSyncMic = mr;
    HorasSync = hr;
    Horapers = true;
    return 1;
}

CMD:darcolete(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;

    new id, val;
    if(sscanf(params, "dd", id, val)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /DarColete [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");

    SetPlayerArmour(id, val);

    new Mensagem[60];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | O(A) %s %s lhe deu %d de colete", CargoAdmin(2, playerid), PegarNick(playerid), val);
    SendClientMessage(id, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você deu %d de colete para %s[%d]", val, PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);

    return 1;
}

CMD:darvida(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;

    new id, val;
    if(sscanf(params, "dd", id, val)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /DarVida [ID] [Quantidade]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");

    SetPlayerHealth(id, val);

    new Mensagem[60];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | O(A) %s %s lhe deu %d de vida", CargoAdmin(2, playerid), PegarNick(playerid), val);
    SendClientMessage(id, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você deu %d de vida para %s[%d]", val, PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);

    return 1;
}

CMD:removerarmas(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0; 
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /RemoverArmas [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    ResetPlayerWeapons(id);

    new Mensagem[60];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | O(A) %s %s removeu suas armas", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você removeu as armas de %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:msc(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new saf[128];
    if(sscanf(params, "s[128]", saf)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Msc [URL]");
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        PlayAudioStreamForPlayer(i, saf);
    }
    return 1;
}

CMD:id(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new Nic[30];
    if(sscanf(params, "s[30]", Nic)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /ID [Nome]");
    new id = PegarIdPeloNickEx(Nic);
    if(id == INVALID_PLAYER_ID) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não encontrado");

    new Mensagem[90];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | O(A) Jogador(a) {FF4500}%s{FFFFFF} possui o ID: {FF4500}%d", PegarNick(id), id);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

CMD:regiao(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new ip[11];
    if(sscanf(params, "s[11]", ip)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Regiao [Ip]");

    new ips[30],
        ips1[30],
        ips2[30],
        Dialog[168];
    //GetIPCountry(ip, ips, sizeof(ips));
    //GetIPISP(ip, ips1, sizeof(ips1));
    //GetIPCity(ip, ips2, sizeof(ips2));

    strcatEx(Dialog, "País: {FFA500}%s\n", ips);
    strcatEx(Dialog, "Operadora: {FFA500}%s\n", ips1);
    strcatEx(Dialog, "Cidade: {FFA500}%s", ips2); 
    Dialog_Show(playerid, SemFucnao, DIALOG_STYLE_TABLIST, ip, Dialog, "Fechar", "");
    return 1;
}

CMD:salvarcontas(playerid)
{
    if(Jogador[playerid][Admin] < 5) return 0;
    TirarBackup();
    return 1;
}

CMD:espiarchatbase(playerid, params[])
{
    if(Jogador[playerid][Admin] < 2) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /EspiarChatBase [Base-ID]");
    if(Base[id][BaseColocada] == false && id != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa base não existe.");
    SetPVarInt(playerid, "AdminEspiarChatBase", id);    
    return 1;
}

CMD:forcarup(playerid, params[])
{
    if(Jogador[playerid][Admin] < 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /ForcarUp [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    DarSalario(id);
    return 1;
}

CMD:vidacarro(playerid, params[])
{
    if(Jogador[playerid][Admin] < 6) return 0;
    new id, Float:Fad;
    if(sscanf(params, "df", id, Fad)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /VidaCarro [ID] [Vida]");
    
    SetVehicleHealth(id, Fad);

    new Mensagem[90];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você alterou a vida do veículo %d para %0.2f", id, Fad);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:bloquearinfo(playerid, params[])
{
    if(Jogador[playerid][Admin] < 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /BloquearInfo [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");

    new Mensagem[128];
    SetPVarInt(id, "BloquearInfo", GetPVarInt(id, "BloquearInfo") ? (false) : (true));
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você trocou o jogador para: %s",  GetPVarInt(id, "BloquearInfo") ? ("Bloqueado(a)") : ("Desbloqueado(a)"));
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

CMD:iadmin(playerid, params[])
{
    if(Jogador[playerid][Admin] < 7) return 0;
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /iAdmin [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");

    new Dialog[2000];
    strcat(Dialog, "Oapéï¿½o\tAdicional\n");
    strcatEx(Dialog, "Admin\t{FFA500}%s\n", PegarNick(id));
    if(pAdmin[id][Espiando] == false) strcat(Dialog, "Telando\t{FF4500}N/A\n");
    else strcatEx(Dialog, "Telando\t{1E90FF}%s[%d]\n", PegarNick(pAdmin[id][EspiandoID]), pAdmin[id][EspiandoID]);
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Informaï¿½ï¿½es", Dialog, "Fechar", #);
    return 1;
}

CMD:servidornome(playerid, params[])
{
    if(Jogador[playerid][Admin] < 7) return 0;
    new Msg[40];
    if(sscanf(params, "s[30]", Msg)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /ServidorNome [Texto]");
    if(strlen(Msg) > 29) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você sï¿½ pode colocar atï¿½ 29 caracteres");

    new Enviar[90];
    format(Enviar, sizeof(Enviar), "hostname Rippzy RP RPG ï¿½ | %s", Msg);
    SendRconCommand(Enviar);

    format(Enviar, sizeof(Enviar), "| SERVIDOR | Nome do servidor foi alterado para %s", Msg);
    SendClientMessage(playerid, 0x00BFFFFF, Enviar);
    return 1;
}

CMD:logs(playerid, params[])
{
    if(Jogador[playerid][Admin] < 4) return 0;
    new Dialog[50];
    strcat(Dialog, "Procurar por Jogador(a)\n");
    strcat(Dialog, "Procurar por Todos");
    Dialog_Show(playerid, MenuLogs, DIALOG_STYLE_TABLIST, "{e2b960}Logs", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:banirserial(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new Serc[41 + 1],
        Jnick[30];
    if(sscanf(params, "s[30]s[42]", Jnick, Serc)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /BanirSerial [Nome] [Serial]");
    new Query[268],
        Cache:Conectar;
    format(Query, sizeof(Query), "SELECT * FROM `serial` WHERE `serial` = '%s'", EscapeString(Serc));
    Conectar = mysql_query(IDConexao, Query);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um erro na consulta");

    if(cache_num_rows() > 0){
        cache_delete(Conectar);
        cache_get_value(0, "Nome", Jnick, 30);
        cache_get_value(0, "Serial", Serc, 42);
        format(Query, sizeof(Query), "| ADMIN | %s está banido Serial ( %s )", Jnick, Serc);
        SendClientMessage(playerid, 0xFF4500FF, Query);
        return 1;
    }
    format(Query, sizeof(Query), "INSERT INTO `serial` (`Nome`, `serial`, `Data`) VALUES ('%s', '%s', %d)", EscapeString(Jnick), EscapeString(Serc), gettime());
    mysql_query(IDConexao, Query, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao banir o serial");

    format(Query, sizeof(Query), "| ADMIN | Você baniu o serial %s do(a) jogador(a) %s", Serc, Jnick);
    SendClientMessage(playerid, 0xFF4500FF, Query);
    return 1;
}

CMD:desbanirserial(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new Serc[41 + 1];
    if(sscanf(params, "s[42]", Serc)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /DesbanirSerial [Serial]");

    new Query[268],
        Cache:Conectar;
    format(Query, sizeof(Query), "SELECT * FROM `serial` WHERE `serial` = '%s'", EscapeString(Serc));
    Conectar = mysql_query(IDConexao, Query);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um erro na consulta");
    if(cache_num_rows() < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | não hï¿½ banimentos nesse serial");
    
    new Jnick[30];
    cache_get_value(0, "Nome", Jnick, 30);
    cache_get_value(0, "Serial", Serc, 42);
    cache_delete(Conectar);

    format(Query, sizeof(Query), "DELETE FROM `serial` WHERE `serial` = '%s'", EscapeString(Serc));
    mysql_query(IDConexao, Query, false);

    format(Query, sizeof(Query), "| ADMIN | Você desbaniu o serial %s do(a) jogador(a) %s", Serc, Jnick);
    SendClientMessage(playerid, 0xFF4500FF, Query);
    return 1;
}

CMD:banvoip(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id, motivo[30];
    if(sscanf(params, "ds[30]", id, motivo)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /BanVoip [ID] [Motivo]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][MutadoVoip] == -1 || Jogador[id][MutadoVoip] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) jï¿½ está banido(a) do VOIP");

    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode punir um membro da equipe");
    }

    Jogador[id][MutadoVoip] = -1;
    // // VerificarTags(id);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| VOIP-BAN | %s %s baniu o(a) jogador(a) %s do VOIP ( Motivo: %s )", CargoAdmin(2, playerid), PegarNick(playerid), PegarNick(id), motivo);
    SendClientMessageToAll(0xf03629FF, Mensagem);
    return 1;
}

CMD:tempbanvoip(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id, tempovv, motivo[30];
    if(sscanf(params, "dds[30]", id, tempovv, motivo)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /BanVoip [ID] [Dias] [Motivo]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][MutadoVoip] == -1 || Jogador[id][MutadoVoip] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) jï¿½ está banido(a) do VOIP");

    if(Jogador[playerid][Admin] != 7){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode punir um membro da equipe");
    }

    Jogador[id][MutadoVoip] = gettime()+(86400*tempovv);
    // // VerificarTags(id);

    new Mensagem[158];
    format(Mensagem, sizeof(Mensagem), "| VOIP-BAN | %s %s baniu o(a) jogador(a) %s do VOIP por %d dia(s) ( Motivo: %s )", CargoAdmin(2, playerid), PegarNick(playerid), PegarNick(id), tempovv, motivo);
    SendClientMessageToAll(0xf03629FF, Mensagem);
    return 1;
}

CMD:desbanirvoip(playerid, params[])
{
    if(Jogador[playerid][Admin] < 3) return 0;
    new id;
    if(sscanf(params, "dds[30]", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /DesbanirVoip [ID]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    if(Jogador[id][MutadoVoip] != -1 && Jogador[id][MutadoVoip] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não está banido(a) do VOIP");

    Jogador[id][MutadoVoip] = 0;
    // // VerificarTags(id);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você desbaniu o(a) %s[%d] do VOIP", PegarNick(id), id);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| ADMIN | Você foi desbanido(a) do VOIP por %s %s", CargoAdmin(2, playerid), PegarNick(playerid));
    SendClientMessage(id, 0x00BFFFFF, Mensagem);
    return 1;
}