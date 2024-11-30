#include <YSI_Coding\y_hooks>

Dialog:DialogSenhaRegistro(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarString(playerid, "SenhaRegistro", inputtext);
    new Cu[30];
    new Cu2[30];
    new F[30] = ".";
    for(new i, j = strlen(inputtext); i < j; i++){
        format(Cu, 30, "%s", F);
        strcat(Cu2, Cu);
    }
    PlayerTextDrawSetString(playerid, RegistroText[playerid][10], Cu2);
    return 0;
}

Dialog:DialogEmailRegistro(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarString(playerid, "EmailRegistro", inputtext);
    PlayerTextDrawSetString(playerid, RegistroText[playerid][19], inputtext);
    return 0;
}

Dialog:DialogSexoRegistro(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        SetPVarInt(playerid, "SexoRegistro", 1);
        PlayerTextDrawSetString(playerid, RegistroText[playerid][20], "Masculino"); 
    }
    else if(!response)
    {
        SetPVarInt(playerid, "SexoRegistro", 2);
        PlayerTextDrawSetString(playerid, RegistroText[playerid][20], "Feminino");
    }
    return 0;
}

Dialog:DialogCodigoRegistro(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarString(playerid, "CodigoRegistro", inputtext);
    PlayerTextDrawSetString(playerid, CodigoLogin[playerid][6], inputtext);
    return 0;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == RegistroText[playerid][10]) Dialog_Show(playerid, DialogSenhaRegistro, DIALOG_STYLE_PASSWORD, "{FF4500}Registro", "{FFFFFF}Coloque uma senha de sua preferência", "Confirmar", "Cancelar");
    else if(playertextid == RegistroText[playerid][19]) Dialog_Show(playerid, DialogEmailRegistro, DIALOG_STYLE_INPUT, "{FF4500}Registro", "{FFFFFF}Coloque seu email abaixo", "Confirmar", "Cancelar");    
    else if(playertextid == RegistroText[playerid][20]) Dialog_Show(playerid, DialogSexoRegistro, DIALOG_STYLE_MSGBOX, "{FF4500}Registro", "{FFFFFF}Selecione seu sexo", "Masculino", "Feminino");    
    else if(playertextid == RegistroText[playerid][12])
    {
        if(RegistroFunc == true) return MostrarMensagem(playerid, ConverterTexto("Desativado, aguarde."), 2000);
        new Formatacao[128],
            Cache:Conectar,
            EmailR[128],
            SenhaR[128], 
            SenhaD[128],
            SexoR,
            SkinSelecionada,
            CodigoR[128];

        format(Formatacao, sizeof(Formatacao), "SELECT * FROM `rippzyrpg` WHERE `Nome`='%s'", EscapeString(PegarNick(playerid)));
        Conectar = mysql_query(IDConexao, Formatacao);
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
        new Exiteeh = cache_num_rows();
        cache_delete(Conectar);
        if(Exiteeh > 0){
            SendClientMessage(playerid, 0xFF4500FF, "| AVISO | Essa conta já foi registrada!");
            SetTimerEx("KickEx", 1000, false, "d", playerid);
            return 1;
        }

        GetPVarString(playerid, "SenhaRegistro", SenhaR, sizeof(SenhaR));
        GetPVarString(playerid, "EmailRegistro", EmailR, sizeof(EmailR));
        SexoR = GetPVarInt(playerid, "SexoRegistro");

        format(Formatacao, sizeof(Formatacao), "SELECT * FROM `rippzyrpg` WHERE `email`='%s'", EscapeString(EmailR));
        Conectar = mysql_query(IDConexao, Formatacao);
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
        Exiteeh = cache_num_rows();
        cache_delete(Conectar);

        if(Exiteeh > 0) return MostrarMensagem(playerid, ConverterTexto("Email já está sendo utilizado!"), 2000);
        if(strlen(SenhaR) > 20) return MostrarMensagem(playerid, ConverterTexto("Senha muito grande!"), 2000);
        if(isnull(SenhaR)) return MostrarMensagem(playerid, ConverterTexto("Prencha os campoos!"), 2000);
        if(CaracterEspecial(SenhaR)) return MostrarMensagem(playerid, ConverterTexto("Você não pode usar caracteres especias!"), 2000);
        if(CaracterEspecial(PegarNick(playerid))) return MostrarMensagem(playerid, ConverterTexto("Nick com caracteres especiais, remova."), 2000);
        if(!VerificarEmail(EmailR)) return MostrarMensagem(playerid, ConverterTexto("Email Inválido!"), 2000);
        if(SexoR == 0) return MostrarMensagem(playerid, "Selecione um Sexo!", 2000);

        OcultarRegistro(playerid);
        MostrarCodigo(playerid);

        if(SexoR == 1) SkinSelecionada = 154;
        else if(SexoR == 2) SkinSelecionada = 93;

        // Gerar um código random
        format(CodigoR, 128, GetRandomString(10));

        // Encripitar Senha
        new SaltRG[11];
        format(SaltRG, sizeof(SaltRG), GetRandomString(10));
        SHA256_PassHash(SenhaR, SaltRG, SenhaD, 90);

        new RegistroR[1200];
        strcat(RegistroR, "INSERT INTO `rippzyrpg` ");
        strcat(RegistroR, "(`PosicaoX`, `PosicaoY`, `PosicaoZ`, `PosicaoA`, `Nome`, `SenhaAdmin`, `Sexo`, `Skin`, `email`, `Codigo`, `Dinheiro`, `Registro`, `TempoUp`, `Discord`, `Profissao`, `Sede`, `Fome`, `Saude`, `Sono`, `Vicio`, `CorVIP`, `Jetpack`, `Casado`)");
        strcat(RegistroR, " VALUES ");
        strcatEx(RegistroR, "(%f, %f, %f, %f, ", 1334.4534, -985.1074, 33.8966, 268.4689); //Spawn
        strcatEx(RegistroR, "'%s', '%s', %d, %d, '%s', '%s', %d, %d, %d, '*', 'Desempregado', %f, %f, %f, %f, %f, %d, %d, '*')", EscapeString(PegarNick(playerid)), "*", SexoR, SkinSelecionada, EscapeString(EmailR), CodigoR, 800, 0, 600, 100.0, 100.0, 100.0, 100.0, 100.0, -16776961, 10);
        mysql_query(IDConexao, RegistroR, false); 
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
        stringclear(RegistroR);

        strcat(RegistroR, "UPDATE `rippzyrpg` SET ");
        strcatEx(RegistroR, "`Senha`='%s', `Salt`='%s', `Ip`='%s' ", SenhaD, SaltRG, PegarIP(playerid));
        strcatEx(RegistroR, "WHERE `Nome`='%s'", EscapeString(PegarNick(playerid)));
        mysql_query(IDConexao, RegistroR, false); 
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
        stringclear(RegistroR);

        new NodeMail[400];
        strcatEx(NodeMail, "UserName:%s", PegarNick(playerid));
        strcatEx(NodeMail, "#UserName:%s", PegarNick(playerid));
        strcatEx(NodeMail, "#Password:%s", SenhaR);
        strcatEx(NodeMail, "#Code:%s", CodigoR);
        strcatEx(NodeMail, "#Aipi:%s", PegarIP(playerid));
        SendEmail("Seu Registro", EmailR, "Conclusão do seu registro!", NodeMail, true, "registro.html"); 
        //format(Formatacao, sizeof(Formatacao), "| SERVIDOR | Foi enviado ao email {00FF00}'%s'{FFFFFF} seu código de registro.", EmailR);
        //SendClientMessage(playerid, -1, Formatacao);

        format(Formatacao, sizeof(Formatacao), "| SERVIDOR | Código de Registro: %s", CodigoR);
        SendClientMessage(playerid, -1, Formatacao);

        if(EmailFunc == true){
            format(Formatacao, sizeof(Formatacao), "| CÓDIGO | Estamos passando por problemas nos envios. Seu código é esse: %s", CodigoR);
            SendClientMessage(playerid, 0xFF4500FF, Formatacao);
        }

    }

    // Código
    else if(playertextid == CodigoLogin[playerid][6]) Dialog_Show(playerid, DialogCodigoRegistro, DIALOG_STYLE_INPUT, "{FF4500}Código", "{FFFFFF}Coloque o código abaixo que foi enviado em seu email!", "Confirmar", "Fechar");
    else if(playertextid == CodigoLogin[playerid][8]) 
    {
        new Cache:Conectar,
            CodigoCapturado[128],
            Formatacao[128],
            CodigoD[128];

        format(Formatacao, sizeof(Formatacao), "SELECT * FROM `rippzyrpg` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
        Conectar = mysql_query(IDConexao, Formatacao);
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
        cache_get_value(0, "Codigo", CodigoCapturado, 128);
        cache_delete(Conectar);

        GetPVarString(playerid, "CodigoRegistro", CodigoD, sizeof(CodigoD));
        if(isnull(CodigoD)) return MostrarMensagem(playerid, "Preencha os Campos", 2000);
        if(strcmp(CodigoD, CodigoCapturado)) return MostrarMensagem(playerid, "Codigo Inválido!", 2000);

        format(Formatacao, sizeof(Formatacao), "UPDATE `rippzyrpg` SET `Registro` = %d WHERE `Nome` = '%s'", gettime(), EscapeString(PegarNick(playerid)));
        mysql_query(IDConexao, Formatacao, false);
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);

        MostrarMensagem(playerid, "Registrado(a)", 2000);
        OcultarCodigo(playerid);
        MostrarLogin(playerid); 
    }
    return 0;
}
