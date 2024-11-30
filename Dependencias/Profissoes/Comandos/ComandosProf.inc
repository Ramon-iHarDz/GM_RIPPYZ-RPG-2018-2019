CMD:radio(playerid, params[])
{
    if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão ao radio policial");
    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está fardado(a)!");
    if(Jogador[playerid][Mutado] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você foi mutado(a) pela administração, aguarde.");

    //if(!strcmp(Jogador[playerid][Profissao], "Desempregado")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    new Enviar[128];
    if(sscanf(params, "s[128]", Enviar)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Radio [Mensagem]");
    new Mensagem[200];
    format(Mensagem, sizeof(Mensagem), "| RADIO | %s[%d] diz: %s", PegarNick(playerid), playerid, Enviar);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(!IsPolicia(i)) continue;
        if(pPolicia[i][PegouUniformePolicia] == false) continue;
        if(GetPVarInt(i, "EventoJogador") > 0) continue;
        SendClientMessage(i, 0x4682B4FF, Mensagem);
    }
    return 1;
}

CMD:cp(playerid, params[])
{
    if(!strcmp(Jogador[playerid][Profissao], "Desempregado")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(IsMafia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(Jogador[playerid][Mutado] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você foi mutado(a) pela administração, aguarde.");
    new Enviar[128];
    if(sscanf(params, "s[128]", Enviar)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Cp [Mensagem]");
    new Mensagem[200],
        id,
        zTagg[20];
    
	if(Jogador[playerid][BaseID] > 0) strcatEx(zTagg, "[%s]", Base[Jogador[playerid][BaseID]][BaseTag]);

    format(Mensagem, sizeof(Mensagem), "| CHAT-PROFISSÃO | %s%s[%d] disse: %s", zTagg, PegarNick(playerid), playerid, Enviar);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "EventoJogador") > 0) continue;
        if(GetPVarInt(i, "ChatProfissaoS") == 1) continue;
        if(strcmp(Jogador[playerid][Profissao], Jogador[i][Profissao])){
            if(strcmp(Jogador[playerid][Profissao], pAdmin[i][EspiandoProf]) || isnull(pAdmin[i][EspiandoProf])) continue;
        }
        
        for(new o=0; o < sizeof(pAgencia); o++){
            if(strcmp(Jogador[playerid][Profissao], pAgencia[o][ProfissaoNome])) continue;
            id = o;
            break;
        }
        SendClientMessage(i, pAgencia[id][CorProfissao], Mensagem);
    }
    return 1;
}

CMD:cm(playerid, params[])
{
    if(!strcmp(Jogador[playerid][Profissao], "Desempregado")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!IsMafia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(Jogador[playerid][Mutado] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você foi mutado(a) pela administração, aguarde.");
    new Enviar[128];
    if(sscanf(params, "s[128]", Enviar)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Cm [Mensagem]");
    new Mensagem[200],
        id,
        zTagg[20];
    
	if(Jogador[playerid][BaseID] > 0) strcatEx(zTagg, "[%s]", Base[Jogador[playerid][BaseID]][BaseTag]);

    format(Mensagem, sizeof(Mensagem), "| CHAT-MAFIA | %s%s[%d] disse: %s", zTagg, PegarNick(playerid), playerid, Enviar);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPVarInt(i, "EventoJogador") > 0) continue;
        if(GetPVarInt(i, "ChatProfissaoS") == 1) continue;
        if(strcmp(Jogador[playerid][Profissao], Jogador[i][Profissao])){
            if(strcmp(Jogador[playerid][Profissao], pAdmin[i][EspiandoProf]) || isnull(pAdmin[i][EspiandoProf])) continue;
        }

        for(new o=0; o < sizeof(pAgencia); o++){
            if(strcmp(Jogador[playerid][Profissao], pAgencia[o][ProfissaoNome])) continue;
            id = o;
            break;
        }
        SendClientMessage(i, pAgencia[id][CorProfissao], Mensagem);
    }
    return 1;
}

stock MostrarComandos(playerid)
{
    new Mensagem[1500];
    strcmp(Mensagem, "Comando - Informações\n");

    //Honestas
    if(!strcmp(Jogador[playerid][Profissao], "Gari"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/IniciarDupla{FFFFFF} - Para ativar o modo dupla\n\n\n");
        strcat(Mensagem, "{FF0000}Modo Dupla:{FFFFFF}\n");
        strcat(Mensagem, "{FF4500}1. Como usar o modo dupla: {FFFF00}Quando o seu parceiro(a) estiver no carona use /IniciarDupla\n");
        strcat(Mensagem, "{FF4500}2. Caso não queria trabalhar em dupla, basta pegar o primeiro lixo que você iniciará sozinho(a)\n");
        strcat(Mensagem, "{FF4500}3. Depois de coletar o lixo, vai aparecer em seu minimapa o simbolo do caminhão para descarregar");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Transportador de Carne"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Acougue{FFFFFF} - Para marcar em seu mapa onde pega as caixas com carne");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Uber Eats"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Entregas{FFFFFF} - Para iniciar entregas");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Uber"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Aceitar [ID]{FFFFFF} - Para aceitar uma corrida\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Policial Militar"))
    {
        strcat(Mensagem, "{4682B4}/Algemar [ID]{FFFFFF} - Para algemar um jogador procurado\n");
        strcat(Mensagem, "{4682B4}/Desalgemar [ID]{FFFFFF} - Para desalgemar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Abordar [ID]{FFFFFF} - Para abordar um jogador procurado\n");
        strcat(Mensagem, "{4682B4}/Prender [ID]{FFFFFF} - Para prender um jogador\n");
        strcat(Mensagem, "{4682B4}/Radio [Mensagem]{FFFFFF} - Para enviar mensagem todos os policias\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Localizar [ID]{FFFFFF} - Para localizar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Deslocalizar{FFFFFF} - Para deslocalizar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Multas{FFFFFF} - Para visualizar as multas\n");
        strcat(Mensagem, "{4682B4}/Multar [ID] [Valor] [Multa]{FFFFFF} - Para multar um jogador\n");
        strcat(Mensagem, "{4682B4}/PrenderArmas [ID]{FFFFFF} - Para prender armas de um jogador\n");
        strcat(Mensagem, "{4682B4}/Procurados{FFFFFF} - Para visualizar procurados(as)\n");
        strcat(Mensagem, "{4682B4}/ArrombarPorta{FFFFFF} - Para arrombar uma porta de casa\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Corregedoria"))
    {
        strcat(Mensagem, "{4682B4}/Localizar [ID]{FFFFFF} - Para localizar um(a) policial\n");
        strcat(Mensagem, "{4682B4}/Deslocalizar{FFFFFF} - Para deslocalizar um(a) policial\n");
        strcat(Mensagem, "{4682B4}/PrenderPolicia [ID] [Tempo] [Motivo]{FFFFFF} - Para prender um(a) policial que esteja cometendo uma infração\n");
        strcat(Mensagem, "{4682B4}/MotivoPrisoes{FFFFFF} - Para ver motivos e tempo de prisões\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Motorista de Ônibus"))
    {
        strcat(Mensagem, "{4682B4}/Rotas{FFFFFF} - Para iniciar uma rota\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Plantador de Maconha"))
    {
        strcat(Mensagem, "{FF6347}/VerIlegal{FFFFFF} - Para ver oque você tem de ilegal\n");
        strcat(Mensagem, "{FF6347}/Beco{FFFFFF} - Para localizar o local de compra\n");
        strcat(Mensagem, "{FF6347}/Boca{FFFFFF} - Para localizar a boca de tráfico\n");
        strcat(Mensagem, "{FF6347}/Traficante{FFFFFF} - Para localizar um traficante\n");
        strcat(Mensagem, "{FF6347}/Plantar{FFFFFF} - Para plantar uma semente\n");
        strcat(Mensagem, "{FF6347}/Colher{FFFFFF} - Para colher uma muda\n");
        strcat(Mensagem, "{FF6347}/Adubo{FFFFFF} - Para dar boost no plantio use o adubo\n");
        strcat(Mensagem, "{FF6347}/Hq{FFFFFF} - Para marcar HQ do seu cargo\n");
        strcat(Mensagem, "{FF6347}/Cm{FFFFFF} - Para enviar mensagem para seu outros(as) do seu cargo\n");
        strcat(Mensagem, "{FF6347}/Regar{FFFFFF} - Para molhar sua muda caso ela precise ( Você precisa de água )\n\n");
        strcat(Mensagem, "{FF0000}Observações:{FFFFFF}\n");
        strcat(Mensagem, "{FF4500}1. O Adubo não é obrigátorio comprar\n");
        strcat(Mensagem, "{FF4500}2. Você precisa sempre ter água com você para regar sua muda ou ela irar morrer\n");
        strcat(Mensagem, "{FF4500}3. {FFFF00}Água você compra em uma loja de utilitários e adubos, sementes etc. no beco\n");
        strcat(Mensagem, "{FF4500}4. Você pode visualizar suas águas e adubos pelo /identidade");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Transportador"))
    {
        strcat(Mensagem, "{4682B4}/Encomendas{FFFFFF} - Para iniciar entregas ( Com ou sem parceiro(a) )\n");
        strcat(Mensagem, "{4682B4}/Dupla{FFFFFF} - Para iniciar ou encerrar uma entrega com amigo(a)\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão\n\n");
        strcat(Mensagem, "{FF0000}Observação:\n");
        strcat(Mensagem, "{FF4500}Caso queira trabalhar em dupla, digite /Dupla antes de /Encomendas");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Lenhador"))
    {
        strcat(Mensagem, "{4682B4}/Derrubar{FFFFFF} - Para derrubar uma árvore\n");
        strcat(Mensagem, "{4682B4}/Lixar{FFFFFF} - Para lixar uma madeira\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Advogado"))
    {
        strcat(Mensagem, "{4682B4}/SoltarPreso [ID]{FFFFFF} - Para soltar um(a) determinado(a) preso(a)\n");
        strcat(Mensagem, "{4682B4}/Presos{FFFFFF} - Para visualizar lista de presos(as)\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Ladrão de Veículos"))
    {
        strcat(Mensagem, "{FF6347}/Cm{FFFFFF} - Para enviar mensagem para seu outros(as) do seu cargo\n");
        strcat(Mensagem, "{FF0000}Objetivo:\n");
        strcat(Mensagem, "{FF4500}Procure por garagens espalhada pelo mapa e roube o veículo lá");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Paramédico"))
    {
        strcat(Mensagem, "{4682B4}/Reviver{FFFFFF} - Para reviver um(a) morto(a)\n");
        strcat(Mensagem, "{4682B4}/Feridos{FFFFFF} - Para visualizar jogadores que precisam de curativos\n");
        strcat(Mensagem, "{4682B4}/Curativo [ID] [Valor]{FFFFFF} - Para enviar uma proposta de curativos\n");
        strcat(Mensagem, "{4682B4}/FazerCurativos{FFFFFF} - Para efetuar os curativos\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão\n\n");
        strcat(Mensagem, "{FF0000}Objetivo:\n");
        strcat(Mensagem, "{FF4500}Quando um(a) jogador(a) estiver morto(a) o mesmo vai aparecer no mapa com ícone de coração\n");
        strcat(Mensagem, "{FF4500}Basta você ir até o local e reviver o(a) mesmo(a)\n\n");
        strcat(Mensagem, "{FF0000}Farda:\n");
        strcat(Mensagem, "{FF4500}Para pegar sua farda entre no dentro do hospital e vá até uma sala nos fundos\n");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Ourives"))
    {
        strcat(Mensagem, "{4682B4}/Cavar{FFFFFF} - Para cavar e procurar uma pedra\n");
        strcat(Mensagem, "{4682B4}/LocalCavar{FFFFFF} - Para marcar o local apropriado para cavar\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão\n\n");
        strcat(Mensagem, "{FF0000}Objetivo:\n");
        strcat(Mensagem, "{FF4500}Você precisa ir até um determinado local e cavar em volta do lago");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Bombeiro"))
    {
        strcat(Mensagem, "{4682B4}/Fogo{FFFFFF} - Para iniciar um trabalho\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Motorista de Carro Forte"))
    {
        strcat(Mensagem, "{4682B4}/Carregar{FFFFFF} - Para iniciar um reabastecimento do seu carro forte\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Assassino"))
    {
        strcat(Mensagem, "{FF6347}/VerIlegal{FFFFFF} - Para ver oque você tem de ilegal\n");
        strcat(Mensagem, "{FF6347}/Contratados{FFFFFF} - Para ver oque os(as) jogadores(as) em contrato\n");
        strcat(Mensagem, "{FF6347}/Boca{FFFFFF} - Para localizar a boca de tráfico\n");
        strcat(Mensagem, "{FF6347}/Traficante{FFFFFF} - Para localizar um traficante\n");
        strcat(Mensagem, "{FF6347}/Hq{FFFFFF} - Para marcar HQ do seu cargo\n");
        strcat(Mensagem, "{FF6347}/Cm{FFFFFF} - Para enviar mensagem para seu outros(as) do seu cargo");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Produtor da Máfia"))
    {
        strcat(Mensagem, "{FF6347}/VerIlegal{FFFFFF} - Para ver oque você tem de ilegal\n");
        strcat(Mensagem, "{FF6347}/Boca{FFFFFF} - Para localizar a boca de tráfico\n");
        strcat(Mensagem, "{FF6347}/Traficante{FFFFFF} - Para localizar um traficante\n");
        strcat(Mensagem, "{FF6347}/Hq{FFFFFF} - Para marcar HQ do seu cargo\n");
        strcat(Mensagem, "{FF6347}/Cm{FFFFFF} - Para enviar mensagem para seu outros(as) do seu cargo\n\n");
        strcat(Mensagem, "1. Você precisa localizar um traficante e comprar as cápsulas ou as peças de armas\n");
        strcat(Mensagem, "2. Após isso retorne para HQ e produza as armas ou munições e entregue");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Assaltante"))
    {
        strcat(Mensagem, "{FF6347}/VerIlegal{FFFFFF} - Para ver oque você tem de ilegal\n");
        strcat(Mensagem, "{FF6347}/Assaltar [ID]{FFFFFF} - Para assaltar um(a) jogador(a)\n");
        strcat(Mensagem, "{FF6347}/AssaltarCarroForte [ID]{FFFFFF} - Para assaltar um Carro Forte\n");
        strcat(Mensagem, "{FF6347}/AssaltarCaixa{FFFFFF} - Para assaltar um Caixa Eletrônico\n");
        strcat(Mensagem, "{FF6347}/RoubarLoja{FFFFFF} - Para assaltar uma lojinha\n");
        strcat(Mensagem, "{FF6347}/Boca{FFFFFF} - Para localizar a boca de tráfico\n");
        strcat(Mensagem, "{FF6347}/Traficante{FFFFFF} - Para localizar um traficante\n");
        strcat(Mensagem, "{FF6347}/Hq{FFFFFF} - Para marcar HQ do seu cargo\n");
        strcat(Mensagem, "{FF6347}/Cm{FFFFFF} - Para enviar mensagem para seu outros(as) do seu cargo");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Petroleiro"))
    {
        strcat(Mensagem, "{4682B4}/AbastecerPosto{FFFFFF} - Para abastecer o posto de gasolina\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Meteorologista"))
    {
        strcat(Mensagem, "{4682B4}/AtivarSatelite{FFFFFF} - Para ativar o satélite\n");
        strcat(Mensagem, "{4682B4}/CarregarDados{FFFFFF} - Para carregar os dados do satélite\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Maquinista"))
    {
        strcat(Mensagem, "{4682B4}/Estacao{FFFFFF} - Para embarcar passageiros(as)\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Piloto"))
    {
        strcat(Mensagem, "{4682B4}/Aeros{FFFFFF} - Para carregar o avião\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/EscadaAviao{FFFFFF} - Para colocar/tirar a escada do AT-400\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para falar no chat profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Exército"))
    {
        strcat(Mensagem, "{4682B4}/Algemar [ID]{FFFFFF} - Para algemar um jogador procurado\n");
        strcat(Mensagem, "{4682B4}/Desalgemar [ID]{FFFFFF} - Para desalgemar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Abordar [ID]{FFFFFF} - Para abordar um jogador procurado\n");
        strcat(Mensagem, "{4682B4}/Acompanhamento [ID]{FFFFFF} - Para iniciar um acompanhamento\n");
        strcat(Mensagem, "{4682B4}/Prender [ID]{FFFFFF} - Para prender um jogador\n");
        strcat(Mensagem, "{4682B4}/Radio [Mensagem]{FFFFFF} - Para enviar mensagem todos os policias\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Localizar [ID]{FFFFFF} - Para localizar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Deslocalizar{FFFFFF} - Para deslocalizar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Procurados{FFFFFF} - Para visualizar procurados(as)\n");
        strcat(Mensagem, "{4682B4}/PrenderArmas [ID]{FFFFFF} - Para prender armas de um jogador\n");
        strcat(Mensagem, "{4682B4}/Multas{FFFFFF} - Para visualizar as multas\n");
        strcat(Mensagem, "{4682B4}/Multar [ID] [Valor] [Multa]{FFFFFF} - Para multar um jogador\n");
        strcat(Mensagem, "{4682B4}/Procurar [ID] [Motivo]{FFFFFF} - Para colocar um jogador na lista de procurados\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");   
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Aeronáutica"))
    {
        strcat(Mensagem, "{4682B4}/Algemar [ID]{FFFFFF} - Para algemar um jogador procurado\n");
        strcat(Mensagem, "{4682B4}/Desalgemar [ID]{FFFFFF} - Para desalgemar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Abordar [ID]{FFFFFF} - Para abordar um jogador procurado\n");
        strcat(Mensagem, "{4682B4}/Acompanhamento [ID]{FFFFFF} - Para iniciar um acompanhamento\n");
        strcat(Mensagem, "{4682B4}/Prender [ID]{FFFFFF} - Para prender um jogador\n");
        strcat(Mensagem, "{4682B4}/Radio [Mensagem]{FFFFFF} - Para enviar mensagem todos os policias\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Localizar [ID]{FFFFFF} - Para localizar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Deslocalizar{FFFFFF} - Para deslocalizar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Procurados{FFFFFF} - Para visualizar procurados(as)\n");
        strcat(Mensagem, "{4682B4}/PrenderArmas [ID]{FFFFFF} - Para prender armas de um jogador\n");
        strcat(Mensagem, "{4682B4}/Multas{FFFFFF} - Para visualizar as multas\n");
        strcat(Mensagem, "{4682B4}/Multar [ID] [Valor] [Multa]{FFFFFF} - Para multar um jogador\n");
        strcat(Mensagem, "{4682B4}/Procurar [ID] [Motivo]{FFFFFF} - Para colocar um jogador na lista de procurados\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");   
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Marinha"))
    {
        strcat(Mensagem, "{4682B4}/Algemar [ID]{FFFFFF} - Para algemar um jogador procurado\n");
        strcat(Mensagem, "{4682B4}/Desalgemar [ID]{FFFFFF} - Para desalgemar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Abordar [ID]{FFFFFF} - Para abordar um jogador procurado\n");
        strcat(Mensagem, "{4682B4}/Acompanhamento [ID]{FFFFFF} - Para iniciar um acompanhamento\n");
        strcat(Mensagem, "{4682B4}/Prender [ID]{FFFFFF} - Para prender um jogador\n");
        strcat(Mensagem, "{4682B4}/Radio [Mensagem]{FFFFFF} - Para enviar mensagem todos os policias\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Localizar [ID]{FFFFFF} - Para localizar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Deslocalizar{FFFFFF} - Para deslocalizar um procurado(a)\n");
        strcat(Mensagem, "{4682B4}/Procurados{FFFFFF} - Para visualizar procurados(as)\n");
        strcat(Mensagem, "{4682B4}/PrenderArmas [ID]{FFFFFF} - Para prender armas de um jogador\n");
        strcat(Mensagem, "{4682B4}/Multas{FFFFFF} - Para visualizar as multas\n");
        strcat(Mensagem, "{4682B4}/Multar [ID] [Valor] [Multa]{FFFFFF} - Para multar um jogador\n");
        strcat(Mensagem, "{4682B4}/Procurar [ID] [Motivo]{FFFFFF} - Para colocar um jogador na lista de procurados\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");   
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Mecânico"))
    {
        strcat(Mensagem, "{4682B4}/MecanicoAceitar [ID] [Preço]{FFFFFF} - Para aceitar um chamado\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Açougueiro"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/CortarCarne{FFFFFF} - Para cortar carne");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Perícia"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Pericia{FFFFFF} - Para iniciar um serviço\n");
        strcat(Mensagem, "{4682B4}/AnalisarCorpo{FFFFFF} - Para analisar um corpo");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Eletricista"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Poste{FFFFFF} - Para iniciar um serviço\n");
        strcat(Mensagem, "{4682B4}/ArrumarPoste{FFFFFF} - Para arrumar o poste\n");
        strcat(Mensagem, "{4682B4}/Escada{FFFFFF} - Para colocar uma escada\n");
        strcat(Mensagem, "{4682B4}/MoverEscada{FFFFFF} - Para mover a escada\n");
        strcat(Mensagem, "{4682B4}/RemoverEscada{FFFFFF} - Para remover a escada");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Leiteiro"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/TirarLeite{FFFFFF} - Para retirar o leite da vaca");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Mergulhador"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Mar{FFFFFF} - Para iniciar o serviço\n");
        strcat(Mensagem, "{4682B4}/UsarCilindro{FFFFFF} - Para usar o cilindro de oxigênio");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Vendedor de Rua"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão\n");
        strcat(Mensagem, "{4682B4}/Estacionar{FFFFFF} - Para estacionar seu veículo e iniciar as vendas");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Terrorista"))
    {
        strcat(Mensagem, "{FF6347}/VerIlegal{FFFFFF} - Para ver oque você tem de ilegal\n");
        strcat(Mensagem, "{FF6347}/Hq{FFFFFF} - Para marcar HQ do seu cargo\n");
        strcat(Mensagem, "{FF6347}/Cm{FFFFFF} - Para enviar mensagem para seu outros(as) do seu cargo\n");
        strcat(Mensagem, "{FF6347}/ArmarBomba{FFFFFF} - Para colocar uma bomba no local\n");
        strcat(Mensagem, "{FF6347}/HomemBomba{FFFFFF} - Para se explodir");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Pizza Delivery"))
    {
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Transportador de Concreto"))
    {
        strcat(Mensagem, "{4682B4}/Concreto{FFFFFF} - Para iniciar uma entrega\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Transportador de Eletrônicos"))
    {
        strcat(Mensagem, "{4682B4}/CarregarEletronico{FFFFFF} - Para iniciar uma entrega\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão");
    }

    else if(!strcmp(Jogador[playerid][Profissao], "Fazendeiro"))
    {
        strcat(Mensagem, "{4682B4}/PlantarSemente{FFFFFF} - Para plantar uma semente\n");
        strcat(Mensagem, "{4682B4}/Feno{FFFFFF} - Para localizar o local de entrega\n");
        strcat(Mensagem, "{4682B4}/Cp [Mensagem]{FFFFFF} - Para enviar mensagem no chat profissão\n");
        strcat(Mensagem, "{4682B4}/Hq{FFFFFF} - Para marcar HQ da sua profissão");
    }
    Dialog_Show(playerid, ListaComandoProfissao, DIALOG_STYLE_MSGBOX, Jogador[playerid][Profissao], Mensagem, "Fechar", "");
    return 1;
}