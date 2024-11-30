#include <YSI_Coding\y_hooks>

stock TocarRadio(playerid, const RadioUrl[], const RadioNome[])
{
    new Mensagem[128];
    StopAudioStreamForPlayer(playerid);
    SetPVarInt(playerid, "SomRadioBlock", 1);
    PlayAudioStreamForPlayer(playerid, RadioUrl);
    format(Mensagem, sizeof(Mensagem), "| MP3 | Tocando agora: {FF8C00}%s", RadioNome);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:Radio(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: TocarRadio(playerid, "https://live.hunter.fm/pop_high", "Hunter"); 
        case 1: TocarRadio(playerid, "https://live.hunter.fm/80s_high", "80s");
        case 2: TocarRadio(playerid, "https://live.hunter.fm/90s_high", "90s");
        case 3: TocarRadio(playerid, "http://167.114.64.181:8325/stream", "Kpop");
        case 4: TocarRadio(playerid, "http://192.99.34.83:8070/stream", "Brega-Funk");
        case 5: TocarRadio(playerid, "http://51.161.13.49:8078/stream", "Funk JP");
        case 6: TocarRadio(playerid, "http://185.33.21.111/sertanejo_128", "Sertanejo");
        case 7: TocarRadio(playerid, "http://192.99.34.83:8100/stream", "Funk Perfect");
        case 8: TocarRadio(playerid, "http://51.161.13.49:8222/stream", "DJ Alok");
        case 9: TocarRadio(playerid, "http://51.161.13.49:9060/stream", "Funk de Quebrada");
        case 10: TocarRadio(playerid, "http://51.161.13.49:8090/stream", "Trap");
        case 11: TocarRadio(playerid, "http://51.89.173.53:8024/stream", "Sad");
        case 12: TocarRadio(playerid, "http://216.235.89.134:80/1power ", "Hitz");
        case 13: TocarRadio(playerid, "http://66.70.177.195:8048/stream", "Rippzy");
        case 14:
        {
            StopAudioStreamForPlayer(playerid);
            SetPVarInt(playerid, "SomRadioBlock", 0);
            SendClientMessage(playerid, -1, "| MP3 | Você desligou a rádio!");
        }
    }
    return 0;
}

Dialog:RegistrarNovoNick(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new NovoNickY[70];
    if(sscanf(inputtext, "s[70]", NovoNickY)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nick Inválido!");
    if(strlen(NovoNickY) > 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nick muito grande");
    else if(strlen(NovoNickY) < 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nick muito curto");
    if(CaracterEspecial(NovoNickY)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar caracteres especiais!");
    if(TemEspaco(NovoNickY)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu nick não pode ter espaços");

    new Enviar[800],
        Cache:Conectar;

    format(Enviar, sizeof(Enviar), "SELECT * FROM `rippzyrpg` WHERE `Nome` = '%s'", EscapeString(NovoNickY));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar seu nick");
    new JaExiste = cache_num_rows();
    cache_delete(Conectar);
    if(JaExiste > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse nick já está registrado");

    // Alterar o Nick da Conta
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar seu nick");

    if(Jogador[playerid][Admin] < 5){
        Jogador[playerid][Coins] -= 8000;
    }
    
    // Casa
    new kappaid = 0,
        bool:kasp;
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(!strcmp(pCasa[i][cDono], PegarNick(playerid))) kappaid = 1;
        else if(VerificarMorador(PegarNick(playerid), i)) kappaid = 2;

        if(kappaid == 1)
        {
            format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Dono` = '%s' WHERE `Dono` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar suas propriedades");
            format(pCasa[i][cDono], 90, NovoNickY);
            AtualizarCasa(i);
            kappaid = 0;
            break;
        }
        else if(kappaid == 2)
        {
            for(new o=0; o < MAX_MORADOR; o++)
            {
                if(pMorador[i][o][TemMorador] == false) continue;
                if(strcmp(pMorador[i][o][Morador], PegarNick(playerid))) continue;
                format(Enviar, sizeof(Enviar), "UPDATE `Moradores` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
                mysql_query(IDConexao, Enviar, false);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar sua moradia");
                format(pMorador[i][o][Morador], 90, NovoNickY);
                kappaid = 0;
                kasp = true;
                break;
            }
        }
        if(kasp == true) break;
    }

    // Empresas
    kasp = false;
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        for(new o=0; o < MAX_FUNCIONARIOS; o++)
        {
            if(pFuncionario[i][o][TemFunc] == false) continue;
            if(strcmp(pFuncionario[i][o][Funcionario], PegarNick(playerid))) continue;
            
            format(Enviar, sizeof(Enviar), "UPDATE `empresafuncionarios` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar seu emprego");
            format(pFuncionario[i][o][Funcionario], 30, NovoNickY);

            if(!strcmp(pEmpresa[i][eDono], PegarNick(playerid)))
            {
                format(Enviar, sizeof(Enviar), "UPDATE `empresas` SET `Dono` = '%s' WHERE `Dono` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
                mysql_query(IDConexao, Enviar, false);
                if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar sua empresa");
                format(pEmpresa[i][eDono], 30, PegarNick(playerid));
                AtualizarEmpresa(i);
            }
            kasp = true;
            break;
        }
        if(kasp == true) break;
    }

    // Fábricas
    kasp = false;
    for(new i=0; i < MAX_FABRICAS; i++)
    {
        if(pFabrica[i][Colocado] == false) continue;
        for(new o=0; o < MAX_FUNCIONARIOSFAB; o++)
        {
            if(pFuncionarioFab[i][o][TemFunc] == false) continue;
            if(strcmp(pFuncionarioFab[i][o][Funcionario], PegarNick(playerid))) continue;
            
            format(Enviar, sizeof(Enviar), "UPDATE `fabricafuncionarios` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar seu emprego na fábrica");
            format(pFuncionario[i][o][Funcionario], 30, NovoNickY);

            if(!strcmp(pFabrica[i][fDono], PegarNick(playerid)))
            {
                format(Enviar, sizeof(Enviar), "UPDATE `fabricas` SET `Dono` = '%s' WHERE `Dono` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
                mysql_query(IDConexao, Enviar, false);
                if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar sua fábrica");
                format(pFabrica[i][fDono], 30, NovoNickY);
                AtualizarFabrica(i);
            }
            kasp = true;
            break;
        }
        if(kasp == true) break;
    }

    // Recompensas
    format(Enviar, sizeof(Enviar), "UPDATE `recompensas` SET `NomeAtual` = '%s' WHERE `NomeAtual` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar suas recompensas");

    // Presos
    format(Enviar, sizeof(Enviar), "UPDATE `presos` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar suas prisões");

    // Banimentos
    format(Enviar, sizeof(Enviar), "UPDATE `banimentos` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar seus banimentos");

    // Habilitações
    format(Enviar, sizeof(Enviar), "UPDATE `carteiras` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar seus habilitações");

    // Veículos
    format(Enviar, sizeof(Enviar), "UPDATE `veiculos` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar seus veículos");

    // Acessórios
    format(Enviar, sizeof(Enviar), "UPDATE `acessorios` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar seus acessórios");

    // Tunagaens
    format(Enviar, sizeof(Enviar), "UPDATE `tunagens` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar suas tunagens");

    // Bases
    // format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Dono` = '%s' WHERE `Dono` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    // mysql_query(IDConexao, Enviar, false);
    // if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar sua base");

    // Tempos
    format(Enviar, sizeof(Enviar), "UPDATE `tempos` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar seus tempos");

    // Mochila
    format(Enviar, sizeof(Enviar), "UPDATE `mochila` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar sua mochila");

    // Sua Agenda - Celular
    format(Enviar, sizeof(Enviar), "UPDATE `celular` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar seu celular");

    // Agenda de Outros - Celular
    format(Enviar, sizeof(Enviar), "UPDATE `celular` SET `NumeroNome` = '%s' WHERE `NumeroNome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar os contatos");

    // Móveis
    format(Enviar, sizeof(Enviar), "UPDATE `moveis` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar seus móveis");

    // Whitelist
    format(Enviar, sizeof(Enviar), "UPDATE `whitelist` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar sua whitelist");

    // Porta Malas
    format(Enviar, sizeof(Enviar), "UPDATE `portamalas` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar seu porta malas");

    // Cupons
    format(Enviar, sizeof(Enviar), "UPDATE `cupom` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar seu cupons");
 
    if(strcmp(Jogador[playerid][Casado], "*")){
        format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Casado` = '%s' WHERE `Casado` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar seu casamento");
        for(new i=0; i < MAX_PLAYERS; i++){
            if(!IsPlayerConnected(i)) continue;
            if(Jogador[i][Logado] == false) continue;
            if(strcmp(Jogador[i][Casado], PegarNick(playerid))) continue;
            format(Jogador[i][Casado], 30, PegarNick(playerid));
        }
    }

    // Concessionária
    format(Enviar, sizeof(Enviar), "UPDATE `concessionaria` SET `Dono` = '%s' WHERE `Dono` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    for(new i=0; i < MAX_CONCESSIONARIA; i++){
        if(Concessionaria[i][Colocado] == false) continue;
        if(strcmp(Concessionaria[i][ConceDono], PegarNick(playerid))) continue;
        format(Concessionaria[i][ConceDono], 30, EscapeString(NovoNickY));
        AtualizarConcessionaria(i);
    }


    // Agenda Telefonica
    for(new i=0; i < MAX_PLAYERS; i++){
        if(Jogador[i][Logado] == false) continue;
        for(new o=0; o < MAX_NUMEROS; o++){
            if(pAgenda[i][o][aUsada] == false) continue;
            if(strcmp(pAgenda[i][o][aNome], PegarNick(playerid))) continue;
            format(pAgenda[i][o][aNome], 30, NovoNickY);
        }
    }

    // Bases
    if(Jogador[playerid][BaseID] > 0)
    {
        new id = Jogador[playerid][BaseID];
        for(new i=0; i < MAX_MEMBROS; i++)
        {
            if(bMembro[id][i][TemMembro] == false) continue;
            if(strcmp(bMembro[id][i][bNome], PegarNick(playerid))) continue;
            format(bMembro[id][i][bNome], 30, NovoNickY);
            if(bMembro[id][i][BaseCargo] == 2) AtualizarBase(id);
            break;
        }
        format(Enviar, sizeof(Enviar), "UPDATE `basemembros` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar você na base");
    }

    format(Enviar, sizeof(Enviar), "UPDATE `lognick` SET `Nome` = '%s' WHERE `Nome` = '%s'", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar suas conexões [0x1]");

    format(Enviar, sizeof(Enviar), "INSERT INTO `lognick` (`Nome`, `NomeSalvo`, `Tempo`) VALUES ('%s', '%s', %d)", EscapeString(NovoNickY), EscapeString(PegarNick(playerid)), gettime());
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao verificar suas conexões [0x2]");

    // VerificarTags(playerid);

    // Enviar mensagem para todos
    format(Enviar, sizeof(Enviar), "| NICK | O(A) Jogador(a) {FFFF00}%s{FFFFFF} mudou seu nick para ( {FE2E2E}%s{FFFFFF} )", EscapeString(PegarNick(playerid)), NovoNickY);
    SendClientMessageToAll(-1, Enviar);
    format(Enviar, sizeof(Enviar), "| NICK | Seu antigo nick {FF0000}%s{FFFFFF} não existe mais", PegarNick(playerid));
    SendClientMessage(playerid, -1, Enviar);
    format(Jogador[playerid][Nome], 90, NovoNickY);
    SetPlayerName(playerid, NovoNickY);
    return 0;
}

Dialog:RegistraNovaSenha(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new NovaSenhaRegi[90];
    if(sscanf(inputtext, "s[90]", NovaSenhaRegi)) return 1;

    if(strlen(NovaSenhaRegi) > 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua senha está muito grande!");
    if(CaracterEspecial(NovaSenhaRegi)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar caracteres especias!");

    new Mensagem[228];
    new SenhaR[90];

    // Encripitar Senha
    new SaltRG[11];
    format(SaltRG, sizeof(SaltRG), GetRandomString(10));
    SHA256_PassHash(NovaSenhaRegi, SaltRG, SenhaR, 90);

    format(Mensagem, sizeof(Mensagem), "UPDATE `rippzyrpg` SET `Senha`='%s', `Salt`='%s' WHERE `Nome`='%s'", SenhaR, SaltRG, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao alterar sua senha!");

    format(Mensagem, sizeof(Mensagem), "| ALTERAÇÃO | Sua senha foi alterada para {FE2E2E}%s", NovaSenhaRegi);
    SendClientMessage(playerid, -1, Mensagem);

    return 1;
}

Dialog:VipCorAlterar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(!IsHexNumber(inputtext)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa cor é inválida");
    if(strlen(inputtext) > 6 || strlen(inputtext) < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa cor é inválida");
    new CorFomar[70];
    format(CorFomar, sizeof(CorFomar), "%sFF", inputtext);
    Jogador[playerid][CorVIP] = HexToInt(CorFomar);

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| VIP | Você alterou a cor da sua tag ( {%06x}VIP{FFFFFF} )", StrToHex(IntToHex(Jogador[playerid][CorVIP])) >>> 8);
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}