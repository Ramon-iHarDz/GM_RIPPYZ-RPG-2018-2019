#include <a_samp>
#include <YSI_Coding\y_hooks>

Dialog:DialogLogin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarString(playerid, "LoginSenha", inputtext);
    new Cu[30];
    new Cu2[30];
    new F[30] = ".";
    for(new i, j = strlen(inputtext); i < j; i++){
        format(Cu, 30, "%s", F);
        strcat(Cu2, Cu);
    }
    PlayerTextDrawSetString(playerid, LoginRC[playerid][10], Cu2);
    return 0;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == LoginRC[playerid][12])
    {
        new SenhaDialog[70];
        GetPVarString(playerid, "LoginSenha", SenhaDialog, sizeof(SenhaDialog));
        if(isnull(SenhaDialog)) return MostrarMensagem(playerid, ConverterTexto("Preencha os Campos!"), 2000);
        if(CaracterEspecial(SenhaDialog)) return MostrarMensagem(playerid, ConverterTexto("Você não pode usar caracteres especiais!"), 2000);
        if(LoginFunc == true) return MostrarMensagem(playerid, ConverterTexto("Login Bloqueado, aguarde."), 2000);

        if(Jogador[playerid][Logado] == true) return 1;
        if(GetPVarInt(playerid, "AntiForceLogin") >= 3){
            SendClientMessage(playerid, 0xFF4500FF, "| SERVIDOR | Você foi kickado(a)");
            SetTimerEx("KickEx", 1000, false, "d", playerid);
            return 1;
        }
        SetPVarInt(playerid, "AntiForceLogin", GetPVarInt(playerid, "AntiForceLogin")+1);
        VerificarLogin(playerid);
    }

    else if(playertextid == LoginRC[playerid][10]) Dialog_Show(playerid, DialogLogin, DIALOG_STYLE_PASSWORD, "{FF4500}Login", "{FFFFFF}Coloque sua senha abaixo!", "Confirmar", "Cancelar");
    else if(playertextid == LoginRC[playerid][14])
    {
        new Formatacao[128],
            Cache:Conectar;
        format(Formatacao, sizeof(Formatacao), "SELECT * FROM `rippzyrpg` WHERE `Nome`='%s'", EscapeString(PegarNick(playerid)));
        Conectar = mysql_query(IDConexao, Formatacao); 
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
        new ExisteH = cache_num_rows();
        cache_delete(Conectar);
        if(ExisteH > 0) return  MostrarMensagem(playerid, ConverterTexto("Essa conta já está registrada!"), 2000);
        OcultarLogin(playerid);
        MostrarRegistro(playerid);
    }

    else if(playertextid == LoginRC[playerid][16])
    {
        new Formatacao[128],
            Cache:Conectar;
        format(Formatacao, sizeof(Formatacao), "SELECT * FROM `rippzyrpg` WHERE `Nome`='%s'", EscapeString(PegarNick(playerid)));
        Conectar = mysql_query(IDConexao, Formatacao); 
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
        new ExisteH = cache_num_rows();
        cache_delete(Conectar);
        if(ExisteH < 1) return MostrarMensagem(playerid, ConverterTexto("Essa conta não está registrada!"), 2000);
        Dialog_Show(playerid, RecuperarInt, DIALOG_STYLE_INPUT, "{FF0000}Código", "Informe o código da sua conta abaixo!", "Confirmar", "Fechar");
    }
    return 0;
}

Dialog:RecuperarInt(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;

    new Mensagem[400],
        Cache:Conectar;
    format(Mensagem, sizeof(Mensagem), "SELECT * FROM `rippzyrpg` WHERE `Nome`='%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Mensagem); 
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);

    new RegistroCode[90],
        EmailCode[90],
        VeriyCode;
    cache_get_value(0, "Codigo", RegistroCode, 70);
    cache_get_value(0, "Email", EmailCode, 80);
    cache_get_value_name_int(0, "Registro", VeriyCode);
    cache_delete(Conectar);
    if(strcmp(RegistroCode, inputtext)){
        SendClientMessage(playerid, 0xFF4500FF, "| SERVIDOR | Código Inválido!");
        SetTimerEx("KickEx", 1000, false, "d", playerid);
        return 1;
    }
    if(VeriyCode == 0) return MostrarMensagem(playerid, ConverterTexto("Sua conta ainda não foi verificada!"), 2000);

    new NovaSenhaCode[90],
        SenhaR[90];
    
    format(RegistroCode, 128, GetRandomString(10)); // Gerar Código
    format(NovaSenhaCode, 128, GetRandomString(20)); // Gerar Senha

    // Encripitar Senha
    new SaltRG[11];
    format(SaltRG, sizeof(SaltRG), GetRandomString(10));
    SHA256_PassHash(NovaSenhaCode, SaltRG, SenhaR, 90);

    format(Mensagem, sizeof(Mensagem), "UPDATE `rippzyrpg` SET `Senha`='%s', `Salt`='%s', `Codigo`='%s' WHERE `Nome`='%s'", SenhaR, SaltRG, RegistroCode, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);

    new NodeMail[228];
    strcatEx(NodeMail, "UserName:%s", PegarNick(playerid));
    strcatEx(NodeMail, "#SenhaCode:%s", NovaSenhaCode);
    strcatEx(NodeMail, "#Code:%s", RegistroCode);
    SendEmail("Recuperação Conta", EmailCode, "Recuperação", NodeMail, true, "recuperacao.html"); 

    format(Mensagem, sizeof(Mensagem), "| RECUPERAÇÃO | Informações enviadas para o email {00FF00}'%s'", EmailCode);
    SendClientMessage(playerid, -1, Mensagem);
    SetTimerEx("KickEx", 1000, false, "d", playerid);
    return 1;
}

stock VerificarLogin(playerid)
{
    new Cache:Conectar,
        Formatacao[400];
    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `banimentos` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);

    if(cache_num_rows() > 0)
    {
        new Banimento;
        cache_get_value_name_int(0, "Banido", Banimento);  
        if(Banimento == 1)
        {
            new TempoBan,
                DataBan,
                AdminR[70],
                MotivoBan[70],
                Dialog[400];

            cache_get_value(0, "Admin", AdminR, 70);
            cache_get_value(0, "Motivo", MotivoBan, 70);
            cache_get_value_name_int(0, "Data", DataBan);
            cache_get_value_name_int(0, "Tempo", TempoBan);
            if(TempoBan == 1 || TempoBan > gettime())
            {
                cache_delete(Conectar);
                OcultarLogin(playerid);
                if(TempoBan == 1) strcatEx(Dialog, "\n\t\t\t{FFFF00}%s banido(a)\n\n", PegarNick(playerid));
                else strcat(Dialog, "\n\t\t\t{FFFF00}Banimento Temporário\n\n"); 
                strcatEx(Dialog, "{FFFFFF}» {FF0000}Você foi banido(a) por {00BFFF}%s\n", AdminR);
                strcatEx(Dialog, "{FFFFFF}» {FF0000}Motivo: {00BFFF}%s\n", MotivoBan);

                if(TempoBan == 1) strcatEx(Dialog, "{FFFFFF}» {FF0000}Data: {FFFFFF}%s\n\n", GetDateFromTime(DataBan));
                else strcatEx(Dialog, "{FFFFFF}» {FF0000}Restante: {FFFFFF}%s\n\n", ConverterSegundos(TempoBan));

                strcat(Dialog, "{FFFFFF}Caso tenha provas que possa justificar seu banimento\n");
                strcat(Dialog, "Entre em contato com um administrador em nosso discord\n");
                strcat(Dialog, "Discord: {00BFFF}https://discord.gg/knNHxTy\n");

                Dialog_Show(playerid, DialogDoBanimento, DIALOG_STYLE_MSGBOX, "{FF4500}Banido(a)", Dialog, "Fechar", #);
                SendClientMessage(playerid, 0xFF0000FF, "| BANIDO | Você está banido(a)");
                SetTimerEx("KickEx", 1000, false, "d", playerid);
                return 1;
            } 

            if(TempoBan != 1)
            {
                format(Formatacao, sizeof(Formatacao), "UPDATE `banimentos` SET `Banido` = 0 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
                mysql_query(IDConexao, Formatacao, false);   
                if(mysql_errno(IDConexao) != 0) return Kick(playerid);
                MostrarMensagem(playerid, ConverterTexto("~r~Desbanido(a)"), 6000);
            }
        }
    }
    cache_delete(Conectar);


    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `rippzyrpg` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    if(cache_num_rows() < 1)
    {
        MostrarMensagem(playerid, ConverterTexto("Usuário não registrado!"), 2000);
        cache_delete(Conectar);
        return 1;
    }

    //Verificar Login do Usuário
    new SenhaDialog[228],
        hash[128],
        bool:Loginnnn;

    cache_get_value(0, "Senha", Jogador[playerid][Senha], 228);
    cache_get_value(0, "Salt", Jogador[playerid][Salt], 90);
    cache_get_value_name_int(0, "Logado", Loginnnn);
    GetPVarString(playerid, "LoginSenha", SenhaDialog, sizeof(SenhaDialog));
    SHA256_PassHash(SenhaDialog, Jogador[playerid][Salt], hash, 128);
    if(strcmp(hash, Jogador[playerid][Senha]))
    {
        MostrarMensagem(playerid, ConverterTexto("Senha Incorreta!"), 2000);
        cache_delete(Conectar);
        return 1;
    } 

    if(Loginnnn == true)
    {
        MostrarMensagem(playerid, ConverterTexto("Conta já logada"), 2000);
        cache_delete(Conectar);
        SetTimerEx("KickEx", 1000, false, "d", playerid);
        return 1;
    }

    new RegistroTempo;
    cache_get_value_name_int(0, "Registro", RegistroTempo);
    if(RegistroTempo == 0)
    {
        cache_delete(Conectar);
        OcultarLogin(playerid);
        MostrarCodigo(playerid);
        return 1;
    }

    OcultarLogin(playerid); 

    //Strings
    cache_get_value(0, "Nome", Jogador[playerid][Nome], 70);
    cache_get_value(0, "SenhaAdmin", Jogador[playerid][SenhaAdmin], 128);
    cache_get_value(0, "SaltAdmin", Jogador[playerid][SaltAdmin], 128);
    cache_get_value(0, "Email", Jogador[playerid][Email], 128);
    cache_get_value(0, "Discord", Jogador[playerid][Discord], 70);
    cache_get_value(0, "Profissao", Jogador[playerid][Profissao], 70);
    cache_get_value(0, "Codigo", Jogador[playerid][Codigo], 70);
    cache_get_value(0, "Casado", Jogador[playerid][Casado], 70);

    //Int
    cache_get_value_name_int(0, "MobileAcesso", Jogador[playerid][MobileAcesso]);
    cache_get_value_name_int(0, "Skin", Jogador[playerid][Skin]);
    cache_get_value_name_int(0, "Vip", Jogador[playerid][Vip]);
    cache_get_value_name_int(0, "Sexo", Jogador[playerid][Sexo]);
    cache_get_value_name_int(0, "Admin", Jogador[playerid][TempAdmin]);
    cache_get_value_name_int(0, "Level", Jogador[playerid][Level]);
    cache_get_value_name_int(0, "Dinheiro", Jogador[playerid][Dinheiro]);
    cache_get_value_name_int(0, "DinheiroBanco", Jogador[playerid][DinheiroBanco]);
    cache_get_value_name_int(0, "DinheiroSujo", Jogador[playerid][DinheiroSujo]);
    cache_get_value_name_int(0, "Cartao", Jogador[playerid][Cartao]);
    cache_get_value_name_int(0, "Coins", Jogador[playerid][Coins]);
    cache_get_value_name_int(0, "Registro", Jogador[playerid][Registro]);
    cache_get_value_name_int(0, "Experiencia", Jogador[playerid][Experiencia]);
    cache_get_value_name_int(0, "TempoUp", Jogador[playerid][TempoUp]);
    cache_get_value_name_int(0, "UltimoLogin", Jogador[playerid][uLogin]);
    cache_get_value_name_int(0, "UltimoInterior", Jogador[playerid][uInterior]);
    cache_get_value_name_int(0, "Estrelas", Jogador[playerid][Estrelas]);
    cache_get_value_name_int(0, "Doenca", Jogador[playerid][Doenca]);
    cache_get_value_name_int(0, "Tag", Jogador[playerid][TagPersonalizada]);
    cache_get_value_name_int(0, "Prisoes", Jogador[playerid][Prisoes]);
    cache_get_value_name_int(0, "VitimasArena", Jogador[playerid][VitimasArena]);
    cache_get_value_name_int(0, "MortesArena", Jogador[playerid][MortesArena]);
    cache_get_value_name_int(0, "VitimasBase", Jogador[playerid][VitimasBase]);
    cache_get_value_name_int(0, "MortesBase", Jogador[playerid][MortesBase]);
    cache_get_value_name_int(0, "Celular", Jogador[playerid][Celular]);
    cache_get_value_name_int(0, "Creditos", Jogador[playerid][Creditos]);
    cache_get_value_name_int(0, "Gps", Jogador[playerid][Gps]);
    cache_get_value_name_int(0, "Mp4", Jogador[playerid][MP4]);
    cache_get_value_name_int(0, "CorVIP", Jogador[playerid][CorVIP]); 
    cache_get_value_name_int(0, "Vacina", Jogador[playerid][Vacina]); 
    cache_get_value_name_int(0, "PlanoDeSaude", Jogador[playerid][PlanoDeSaude]); 
    cache_get_value_name_int(0, "Gasolina", Jogador[playerid][GalaoGasolina]); 
    cache_get_value_name_int(0, "GasolinaGalao", Jogador[playerid][GasolinaGalao]); 
    cache_get_value_name_int(0, "RelogioUP", Jogador[playerid][RelogioUP]);
    cache_get_value_name_int(0, "Contratado", Jogador[playerid][Contratado]);
    cache_get_value_name_int(0, "KitReparos", Jogador[playerid][KitReparos]);
    cache_get_value_name_int(0, "PandoraCaixa", Jogador[playerid][PandoraCaixa]);
    cache_get_value_name_int(0, "Jetpack", Jogador[playerid][GasJetpack]);
    cache_get_value_name_int(0, "Luta", Jogador[playerid][Luta]);
    cache_get_value_name_int(0, "Encomendas", Jogador[playerid][EncomendasPlayer]);
    cache_get_value_name_int(0, "Mochila", Jogador[playerid][Mochila]);
    cache_get_value_name_int(0, "Operadora", Jogador[playerid][Operadora]);
    cache_get_value_name_int(0, "Numero", Jogador[playerid][pNumero]);
    cache_get_value_name_int(0, "PorteDeArmas", Jogador[playerid][PorteDeArmas]);
    cache_get_value_name_int(0, "Raspberry", Jogador[playerid][Raspberry]);
    cache_get_value_name_int(0, "ContaAntiga", Jogador[playerid][ContaAntiga]);
    cache_get_value_name_int(0, "KitMedico", Jogador[playerid][KitMedico]);
    cache_get_value_name_int(0, "VicioType", Jogador[playerid][VicioEstilo]);
    cache_get_value_name_int(0, "Avisos", Jogador[playerid][Avisos]);
    cache_get_value_name_int(0, "Cilindro", Jogador[playerid][Cilindro]); 
    cache_get_value_name_int(0, "SementeFazenda", Jogador[playerid][SementeFazenda]);

    Jogador[playerid][SkinProfissao] = -1;  
    format(Jogador[playerid][uIp], 20, PegarIP(playerid));

    //Float
    cache_get_value_name_float(0, "PosicaoX", Jogador[playerid][PosicaoX]);
    cache_get_value_name_float(0, "PosicaoY", Jogador[playerid][PosicaoY]);
    cache_get_value_name_float(0, "PosicaoZ", Jogador[playerid][PosicaoZ]);
    cache_get_value_name_float(0, "PosicaoA", Jogador[playerid][PosicaoA]);
    cache_get_value_name_float(0, "Fome", Jogador[playerid][Fome]);
    cache_get_value_name_float(0, "Sede", Jogador[playerid][Sede]);
    cache_get_value_name_float(0, "Saude", Jogador[playerid][Saude]);
    cache_get_value_name_float(0, "Sono", Jogador[playerid][Sono]);
    cache_get_value_name_float(0, "Vicio", Jogador[playerid][Vicio]);

    //Tempos
    cache_get_value_name_int(0, "Mutado", Jogador[playerid][Mutado]);
    cache_get_value_name_int(0, "MutadoVoip", Jogador[playerid][MutadoVoip]);

    // VerificarTags(playerid); // Verificar TAG discord
    cache_delete(Conectar);

    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `carteiras` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    if(cache_num_rows() > 0)
    {
        cache_get_value_name_int(0, "CarteiraA", Jogador[playerid][CarteiraA]);  
        cache_get_value_name_int(0, "CarteiraB", Jogador[playerid][CarteiraB]); 
        cache_get_value_name_int(0, "CarteiraC", Jogador[playerid][CarteiraC]); 
        cache_get_value_name_int(0, "CarteiraD", Jogador[playerid][CarteiraD]);
        cache_get_value_name_int(0, "CarteiraE", Jogador[playerid][CarteiraE]);  

        cache_get_value_name_int(0, "MultaA", Jogador[playerid][MultaA]);  
        cache_get_value_name_int(0, "MultaB", Jogador[playerid][MultaB]);  
        cache_get_value_name_int(0, "MultaC", Jogador[playerid][MultaC]);  
        cache_get_value_name_int(0, "MultaD", Jogador[playerid][MultaD]);  
        cache_get_value_name_int(0, "MultaE", Jogador[playerid][MultaE]);  
    }
    cache_delete(Conectar);

    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `tunagens` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    new vezzz = cache_num_rows();
    if(vezzz > 0)
    {
        new idz = 0;
        for(new i=0; i < vezzz; i++)
        {
            cache_get_value_name_int(i, "Slot", idz);  
            cache_get_value_name_int(i, "Mod0", pTunagem[playerid][idz][0][TalentoID]);  
            cache_get_value_name_int(i, "Mod1", pTunagem[playerid][idz][1][TalentoID]);   
            cache_get_value_name_int(i, "Mod2", pTunagem[playerid][idz][2][TalentoID]);  
            cache_get_value_name_int(i, "Mod3", pTunagem[playerid][idz][3][TalentoID]);  
            cache_get_value_name_int(i, "Mod4", pTunagem[playerid][idz][4][TalentoID]);  
            cache_get_value_name_int(i, "Mod5", pTunagem[playerid][idz][5][TalentoID]);  
            cache_get_value_name_int(i, "Mod6", pTunagem[playerid][idz][6][TalentoID]);  
            cache_get_value_name_int(i, "Mod7", pTunagem[playerid][idz][7][TalentoID]);  
            cache_get_value_name_int(i, "Mod8", pTunagem[playerid][idz][8][TalentoID]);  
            cache_get_value_name_int(i, "Mod9", pTunagem[playerid][idz][9][TalentoID]);  
            cache_get_value_name_int(i, "Mod10", pTunagem[playerid][idz][10][TalentoID]);  
            cache_get_value_name_int(i, "Mod11", pTunagem[playerid][idz][11][TalentoID]);  
            cache_get_value_name_int(i, "Mod12", pTunagem[playerid][idz][12][TalentoID]);  
            cache_get_value_name_int(i, "Mod13", pTunagem[playerid][idz][13][TalentoID]);  
            cache_get_value_name_int(i, "Mod14", pTunagem[playerid][idz][14][TalentoID]);  
            cache_get_value_name_int(i, "Mod15", pTunagem[playerid][idz][15][TalentoID]);  
            cache_get_value_name_int(i, "Mod16", pTunagem[playerid][idz][16][TalentoID]);  
            cache_get_value_name_int(i, "Mod17", pTunagem[playerid][idz][17][TalentoID]);  
        }
    }
    cache_delete(Conectar);

    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `veiculos` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    new Quantoos = cache_num_rows();
    if(Quantoos > 0)
    {
        new SlotCap;
        for(new i=0; i < Quantoos; i++)
        {
            cache_get_value_name_int(i, "Slot", SlotCap);  
            cache_get_value_name_float(i, "PosX", pVeiculo[playerid][SlotCap][vPosX]);
            cache_get_value_name_float(i, "PosY", pVeiculo[playerid][SlotCap][vPosY]);
            cache_get_value_name_float(i, "PosZ", pVeiculo[playerid][SlotCap][vPosZ]);
            cache_get_value_name_float(i, "PosA", pVeiculo[playerid][SlotCap][vPosA]);
            cache_get_value_name_float(i, "Gasolina", pVeiculo[playerid][SlotCap][GasolinaEx]);
            cache_get_value_name_float(i, "Kilometros", pVeiculo[playerid][SlotCap][KilometrosEx]);
            cache_get_value_name_float(i, "Vida", pVeiculo[playerid][SlotCap][vVida]);
            cache_get_value_name_int(i, "Cor1", pVeiculo[playerid][SlotCap][Cor1Veh]);
            cache_get_value_name_int(i, "Cor2", pVeiculo[playerid][SlotCap][Cor2Veh]);
            cache_get_value_name_int(i, "Preco", pVeiculo[playerid][SlotCap][Preco]);
            cache_get_value_name_int(i, "Tranca", pVeiculo[playerid][SlotCap][Tranca]);
            cache_get_value_name_int(i, "Modelo", pVeiculo[playerid][SlotCap][MeuVeiculoModelo]);
            cache_get_value_name_int(i, "TemTranca", pVeiculo[playerid][SlotCap][TemTranca]);
            cache_get_value_name_int(i, "Som", pVeiculo[playerid][SlotCap][TemSom]);
            cache_get_value_name_int(i, "Patio", pVeiculo[playerid][SlotCap][Patio]);
            cache_get_value(i, "Placa", pVeiculo[playerid][SlotCap][Placa], 90);
            cache_get_value(i, "Preso", pVeiculo[playerid][SlotCap][Apreendido], 90);
        }
    }
    cache_delete(Conectar); 

    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `acessorios` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    new AcessoriosQuantidade = cache_num_rows(),
        bool:PresoLogin = false,
        bool:TemCasa = false;
    if(AcessoriosQuantidade > 0)
    {
        new id;
        for(new i=0; i < AcessoriosQuantidade; i++)
        {
            //Int
            cache_get_value_name_int(i, "Slot", id);  

            cache_get_value_name_int(i, "Ativado", pAcessorio[playerid][id][Ativado]); 
            cache_get_value_name_int(i, "ModeloID", pAcessorio[playerid][id][AcessorioObj]);  
            cache_get_value_name_int(i, "Bone", pAcessorio[playerid][id][Bone]);  

            //Floats
            cache_get_value_name_float(i, "OffsetX", pAcessorio[playerid][id][AOffsetX]);
            cache_get_value_name_float(i, "OffsetY", pAcessorio[playerid][id][AOffsetY]);
            cache_get_value_name_float(i, "OffsetZ", pAcessorio[playerid][id][AOffsetZ]);

            cache_get_value_name_float(i, "RotX", pAcessorio[playerid][id][ARotX]);
            cache_get_value_name_float(i, "RotY", pAcessorio[playerid][id][ARotY]);
            cache_get_value_name_float(i, "RotZ", pAcessorio[playerid][id][ARotZ]);

            cache_get_value_name_float(i, "ScaleX", pAcessorio[playerid][id][AScaleX]);
            cache_get_value_name_float(i, "ScaleY", pAcessorio[playerid][id][AScaleY]);
            cache_get_value_name_float(i, "ScaleZ", pAcessorio[playerid][id][AScaleZ]);

            //String
            cache_get_value(i, "AcessorioNome", pAcessorio[playerid][id][AcessorioNome], 90);
        }
    }
    cache_delete(Conectar);

    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `mafia` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    new bool:sembo = false;
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    if(cache_num_rows() > 0)
    {
        cache_get_value_name_int(0, "Sacos", Jogador[playerid][Sacos]); 
        cache_get_value_name_int(0, "Agua", Jogador[playerid][Agua]); 
        cache_get_value_name_int(0, "Sementes", Jogador[playerid][Sementes]); 
        cache_get_value_name_int(0, "Adubos", Jogador[playerid][Adubos]); 
        cache_get_value_name_int(0, "Vasos", Jogador[playerid][Vasos]); 
        cache_get_value_name_int(0, "LockPick", Jogador[playerid][LockPick]); 
        cache_get_value_name_int(0, "Dinamites", Jogador[playerid][Dinamites]);
        cache_get_value_name_int(0, "Maconha", Jogador[playerid][Maconha]);
        cache_get_value_name_int(0, "Crack", Jogador[playerid][Crack]);
        cache_get_value_name_int(0, "Cocaina", Jogador[playerid][Cocaina]);
        cache_get_value_name_int(0, "Lsd", Jogador[playerid][Lsd]);
        cache_get_value_name_int(0, "Capsulas", Jogador[playerid][Capsulas]);
        cache_get_value_name_int(0, "Pecas", Jogador[playerid][Pecas]);
    }
    else
    {
        cache_delete(Conectar);
        sembo = true;
        // Caso não tenha criar
        format(Formatacao, sizeof(Formatacao), "INSERT INTO `mafia` (`Nome`) VALUES ('%s')", EscapeString(PegarNick(playerid)));
        mysql_query(IDConexao, Formatacao, false); 
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    }
    if(sembo == false) cache_delete(Conectar);


    new bool:sembod = false;
    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `celular` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    new aisnd = cache_num_rows();
    if(aisnd > 0)
    {
        for(new i=0; i < aisnd; i++)
        {
            cache_get_value_name_int(i, "Numero", pAgenda[playerid][i][aNumero]);
            cache_get_value_name(i, "NumeroNome", pAgenda[playerid][i][aNome], 30);
            cache_get_value_name(i, "Contato", pAgenda[playerid][i][Contato], 30);
            pAgenda[playerid][i][aUsada] = true;
        }   
    }
    if(sembod == false) cache_delete(Conectar); 


    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `tempos` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    sembod = false;
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    if(cache_num_rows() > 0)
    {
        cache_get_value_name_int(0, "Trabalho", pTempo[playerid][TrocaProfissao]); 
        cache_get_value_name_int(0, "RoubarJogador", pTempo[playerid][RoubarJogador]); 
        cache_get_value_name_int(0, "RoubarCaixa", pTempo[playerid][RoubarCaixa]); 
        cache_get_value_name_int(0, "RoubarCarroForte", pTempo[playerid][RoubarCarroForte]);
        cache_get_value_name_int(0, "TransferirMao", pTempo[playerid][TransferirMao]);
        cache_get_value_name_int(0, "TransferirBanco", pTempo[playerid][TransferirBanco]);
        cache_get_value_name_int(0, "TransferirCoins", pTempo[playerid][TransferirCoins]);
        cache_get_value_name_int(0, "TrocarLuta", pTempo[playerid][TrocarLuta]);
        cache_get_value_name_int(0, "AbrirDenuncia", pTempo[playerid][AbrirDenuncia]); 
        cache_get_value_name_int(0, "TransferirCelular", pTempo[playerid][TransferirCelular]);
        cache_get_value_name_int(0, "TrabalharFabrica", pTempo[playerid][TrabalharFabrica]); 
        cache_get_value_name_int(0, "Produtor", pTempo[playerid][HobbieProdutor]);
        cache_get_value_name_int(0, "AnunciarOlx", pTempo[playerid][AnunciarOlx]); 
        cache_get_value_name_int(0, "AnunciarRadio", pTempo[playerid][AnunciarRadio]); 
        cache_get_value_name_int(0, "Apoio", pTempo[playerid][UsoApoio]); 
        cache_get_value_name_int(0, "FabricaProduc", pTempo[playerid][FabricaProduc]);
    }
    else
    {
        cache_delete(Conectar);
        sembod = true;
        // Caso não tenha criar
        format(Formatacao, sizeof(Formatacao), "INSERT INTO `tempos` (`Nome`) VALUES ('%s')", EscapeString(PegarNick(playerid)));
        mysql_query(IDConexao, Formatacao, false); 
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
        pTempo[playerid][TrocaProfissao] = 0;
        pTempo[playerid][TransferirMao] = 0;
    }
    if(sembod == false) cache_delete(Conectar);

    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `basemembros` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Formatacao);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    if(cache_num_rows() > 0)
    {
        new iaia;
        cache_get_value_name_int(0, "BaseID", iaia);
        cache_delete(Conectar);
        Jogador[playerid][BaseID] = iaia;
    }

    format(Formatacao, sizeof(Formatacao), "INSERT INTO `logip` (`Nome`, `Ip`, `Tempo`) VALUES ('%s', '%s', %d)", EscapeString(PegarNick(playerid)), PegarIP(playerid), gettime());
    mysql_query(IDConexao, Formatacao, false); 

    //Setando Informações
    SetPVarInt(playerid, "AntiPunich", 1);
    SetPlayerName(playerid, GetRandomString(strlen(Jogador[playerid][Nome])));
    SetPlayerName(playerid, Jogador[playerid][Nome]);
    SetPlayerVirtualWorld(playerid, 0);
    SetPlayerScore(playerid, Jogador[playerid][Level]);
    SetPlayerEmprego(playerid, Jogador[playerid][Profissao]);
    SetPlayerFightingStyle(playerid, Jogador[playerid][Luta]);
    TogglePlayerControllable(playerid, 1);
    SetSpawnInfo(playerid, 0, Jogador[playerid][SkinProfissao], 1334.4534, -985.1074, 33.8966, 268.4689, 0, 0, 0, 0, 0, 0);
    SpawnPlayer(playerid);

    SetPlayerSkin(playerid, Jogador[playerid][Skin]);
    VerificarAcessorios(playerid);
    SetPVarInt(playerid, "LoginEtap2", GetTickCount());

    //Verificar se o jogador tem casa
    new bool:Falidooh = false;
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(!strcmp(pCasa[i][cDono], PegarNick(playerid), true)) Falidooh = true;
        else if(VerificarMorador(PegarNick(playerid), i)) Falidooh = true;
        if(Falidooh == false) continue;

        new Mensagem[128];
        if(pCasa[i][LixoF] > 2){
            format(Mensagem, sizeof(Mensagem), "| LIXO | Sua casa tem %d lixos acumulados, procure um gari ou vá o lixão para removê-los", pCasa[i][LixoF]);
            SendClientMessage(playerid, 0xfc520fFF, Mensagem);
        }
        if(pCasa[i][LixoD] > 2){
            format(Mensagem, sizeof(Mensagem), "| LIXO | Você tem %d sacos de lixos dentro da sua casa", pCasa[i][LixoD]);
            SendClientMessage(playerid, 0xfc520fFF, Mensagem);
        }
        if(pCasa[i][Impostos] > 2){
            format(Mensagem, sizeof(Mensagem), "| LIXO | Sua casa tem %d impostos pendentes, pegue-o ou sua casa será liberada", pCasa[i][Impostos]);
            SendClientMessage(playerid, 0xfc520fFF, Mensagem);
        }

        if(PresoLogin == false)
        {
            SetPlayerFacingAngle(playerid, pCasa[i][cPosicaoA]);
            SetPlayerPos(playerid, pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ]);
            SetPVarInt(playerid, "TempoDoContinuar", gettime()+30);    
        }
        TemCasa = true;
        break;
    }

    if(TemCasa == false && PresoLogin == false)
    {
        SetPlayerFacingAngle(playerid,  Jogador[playerid][PosicaoA]);
        if(Jogador[playerid][uInterior] > 0) ForceSaida(playerid);
        else SetPlayerPos(playerid, Jogador[playerid][PosicaoX], Jogador[playerid][PosicaoY], Jogador[playerid][PosicaoZ]);
    }

    SetPlayerPrisao(playerid);
    StopAudioStreamForPlayer(playerid);
    // SetTimerEx("Destravar", 3000, false, "d", playerid);

    if(Jogador[playerid][PlanoDeSaude] != 0 && Jogador[playerid][PlanoDeSaude] < gettime()){
        SendClientMessage(playerid, 0xfc520fFF, "| AVISO | Seu plano de saúde expirou-se");
        Jogador[playerid][PlanoDeSaude] = 0;
    }

    if(Jogador[playerid][uLogin] == 0)
    {
        new Mensagem[800];
        strcatEx(Mensagem, "{FFFFFF}Olá %s, Ficamos felizes com sua nova escolha de moradia em {00BFFF}Rippzy City\n", PegarNick(playerid));
        strcat(Mensagem, "{FFFFFF}Contacte um dos nossos administradores atraves do {00FF00}/duvida{FFFFFF} para que você possa conhecer o nosso servidor\n\n");
        strcat(Mensagem, "Comandos:\n");
        strcat(Mensagem, "{00BFFF}/Discord - {FFFFFF}Para sincronizar sua conta do servidor com o nosso discord\n");
        // strcat(Mensagem, "{00BFFF}/Admins - {FFFFFF}Para visualizar se há membros da staff online\n");
        strcat(Mensagem, "{00BFFF}/Ajuda - {FFFFFF}Para visualizar alguns comandos que poderá ser útil no futuro\n\n");
        strcat(Mensagem, "Assinado: {FF0000}Equipe Rippzy");
        Dialog_Show(playerid, MensagemDeBoasVIdasss, DIALOG_STYLE_MSGBOX, "{FFFFFF}Bem-Vindo(a)", Mensagem, "Fechar", #);

        EnviarAlerta(playerid, "Informação", "Seja Bem-Vindo(a)", 9000);

        format(Mensagem, sizeof(Mensagem), "| NOVATO | O(A) Jogador(a) {00BFFF}%s[%d]{FFFFFF} acabou de entrar no servidor, vá até o spawn", PegarNick(playerid), playerid);
        for(new i=0; i < MAX_PLAYERS; i++){
            if(!IsPlayerConnected(i)) continue;
            if(Jogador[i][Logado] == false) continue;
            if(Jogador[i][Admin] < 1) continue;
            SendClientMessage(i, -1, Mensagem);
        }
    }
    else
    { 
        //SendClientMessage(playerid, 0x7FFF00FF, "===================================================================");
        /*if(Jogador[playerid][TempAdmin] > 0){
            format(Formatacao, sizeof(Formatacao), "{00BFFF}»{FFFFFF} Cargo: %s", CargoAdmin(1, playerid));
            SendClientMessage(playerid, 0x87CEFAFF, Formatacao);
        }*/
        format(Formatacao, sizeof(Formatacao), "{00BFFF}»{FFFFFF} Seu último login foi feito há {FF0000}%s", ConverterSegundosEx(gettime()-Jogador[playerid][uLogin]));
        SendClientMessage(playerid, 0x87CEFAFF, Formatacao);
        if(Jogador[playerid][Vip] > gettime()){
            format(Formatacao, sizeof(Formatacao), "{00BFFF}»{FFFFFF} Você tem mais {FFFF00}%s{FFFFFF} de VIP, aproveite!", ConverterSegundos(Jogador[playerid][Vip]));
            SendClientMessage(playerid, 0x87CEFAFF, Formatacao);    
            if(TemCasa == true) SendClientMessage(playerid, 0x00BFFFFF, "| CONTINUAR | Digite '/continuar' para voltar para sua última posição");
        }
        //SendClientMessage(playerid, 0x7FFF00FF, "===================================================================");
    }

    format(Formatacao, sizeof(Formatacao), "UPDATE `rippzyrpg` SET `Logado` = 1, `serial` = '%s' WHERE `Nome` = '%s'", EscapeString(PegarHWID(playerid)), EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Formatacao, false);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    Jogador[playerid][Logado] = true;

    // Serial Banimento
    format(Formatacao, sizeof(Formatacao), "SELECT * FROM `serial` WHERE `serial` = '%s'", EscapeString(PegarHWID(playerid)));
    mysql_query(IDConexao, Formatacao);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    if(cache_num_rows() > 0)
    {
        cache_delete(Conectar);
        /*format(Formatacao, sizeof(Formatacao), "INSERT INTO `serial` (`Nome`, `serial`, `Data`) VALUES ('%s', '%s', %d)", EscapeString(PegarNick(playerid)), EscapeString(PegarHWID(playerid)), gettime());
        mysql_query(IDConexao, Formatacao, false);
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);*/

        BanirIp(PegarIP(playerid));
        BanF(playerid, -1, "Conta Fake - Revisão Discord.", 1, true);
    }
    return 1; 
}

/*CMD:resgatar(playerid)
{
    if(Jogador[playerid][ContaAntiga] == false) return 0;
    new Formatacao[128];
    format(Formatacao, sizeof(Formatacao), "UPDATE `rippzyrpg` SET `ContaAntiga` = 0 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Formatacao, false);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);
    Jogador[playerid][ContaAntiga] = false;
    
    Jogador[playerid][Level] += 1;
    Jogador[playerid][Experiencia] += 3;
    Jogador[playerid][Dinheiro] += 20000;

    SendClientMessage(playerid, 0xFF4500FF, "| RECOMPENSA | Você recebeu +1 level, +3 Experiências e $20.000 pelo problema que aconteceu.");
    return 1;
}*/