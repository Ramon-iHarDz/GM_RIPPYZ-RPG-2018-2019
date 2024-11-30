#include <YSI_Coding\y_hooks>

hook OnPlayerSpawn(playerid)
{
    if(IsPlayerNPC(playerid)) return 1;
    if(pAcesso[playerid][UmaVezA] == false)
    {
        pAcesso[playerid][UmaVezA] = true;
        new Enviar[200],
            Cache:Conectar
        ;       
        
        format(Enviar, sizeof(Enviar), "SELECT * FROM `acessocodigo` WHERE `UsadoPor` = '%s'", EscapeString(PegarNick(playerid)));
        Conectar = mysql_query(IDConexao, Enviar);
        if(mysql_errno(IDConexao) != 0) return Kick(playerid);
        if(cache_num_rows() > 0)
        {
            cache_get_value_name_int(0, "Restante", pAcesso[playerid][AcessoRestante]);
            if(pAcesso[playerid][AcessoRestante] != 0)
            {
                format(Enviar, sizeof(Enviar), "| ACESSO | Você tem ainda tem %s, aproveite!", ConverterSegundos(pAcesso[playerid][AcessoRestante]));
                SendClientMessage(playerid, 0xFFFF00FF, Enviar);
            }
        }
        cache_delete(Conectar);
        pAcesso[playerid][CodeTempo] = true;
        pAcesso[playerid][CodeTimer] = SetTimerEx("VerificarAcesso", 1000, false, "d", playerid);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pAcesso[playerid][CodeTempo] == true){
        KillTimer(pAcesso[playerid][CodeTimer]);
    }

    new Deletar[AcessoJogador];
    pAcesso[playerid] = Deletar;
    return 1;
}

Dialog:ConfirmarCodigoAcc(playerid, response, listitem, inputtext[])
{
    if(!response) return Kick(playerid);

    new PCodigo[80];
    if(sscanf(inputtext, "s[80]", PCodigo))
    {
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Código não foi reconhecido pelo servidor");
        SetTimerEx("KickEx", 1000, false, "d", playerid);
        return 1;
    }

    new Enviar[500],
        Cache:Conectar
    ;
    format(Enviar, sizeof(Enviar), "SELECT * FROM `acessocodigo` WHERE `Codigo` = '%s'", EscapeString(PCodigo));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return Kick(playerid);

    new bool:moba = false,
        UsadoPor[70],
        TDias,
        Conc = cache_num_rows()
    ;

    if(Conc > 0)
    {
        cache_get_value(0, "UsadoPor", UsadoPor, 70);
        cache_get_value_name_int(0, "Dias", TDias);
    }
    cache_delete(Conectar);

    if(Conc > 0)
    {
        moba = true;
        if(strcmp(UsadoPor, "*"))
        {
            format(Enviar, sizeof(Enviar), "| ERRO | Esse código foi ativado por %s", UsadoPor);
            SendClientMessage(playerid, 0xFF4500FF, Enviar);
            SetTimerEx("KickEx", 1000, false, "d", playerid);
            return 1;
        }

        new DiasConv = (gettime() + (TDias * 24 * 60 * 60));
        format(Enviar, sizeof(Enviar), "UPDATE `acessocodigo` SET `UsadoPor` = '%s', `Ativado` = %d, `Restante` = %d WHERE `Codigo` = '%s'", EscapeString(PegarNick(playerid)), gettime(), DiasConv, EscapeString(PCodigo));
        mysql_query(IDConexao, Enviar, false);

        format(Enviar, sizeof(Enviar), "INSERT `whitelist` (`Nome`, `Hwid`) VALUES ('%s', '%s')", EscapeString(PegarNick(playerid)), EscapeString(PegarHWID(playerid)));
        mysql_query(IDConexao, Enviar, false);


        format(Enviar, sizeof(Enviar), "| CÓDIGO | Você foi confirmado(a), seu código deu {FF4500}%d{FFFFFF} dia(s) de acesso, relogue!", TDias);
        SendClientMessage(playerid, -1, Enviar);
        SetTimerEx("KickEx", 1000, false, "d", playerid);
        return 1;
    }

    if(moba == false)
    {
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Código Inválido!");
        SetTimerEx("KickEx", 1000, false, "d", playerid);
        return 1;
    }

    return 0;
}

stock LoginCodigo(playerid)
{
    new Dialog[280];
    strcat(Dialog, "{FFFFFF}Informe o código abaixo\n");
    strcat(Dialog, "Adicione o código feito esse exemplo: {CCCCCC}XXXX-XXXX-XXXX-XXXX{FFFFFF}\n");
    strcat(Dialog, "Você tem {FF0000}1 minuto{FFFFFF} para informar o código ou será expulso(a)!");
    pAcesso[playerid][CodeTempo] = true;
    pAcesso[playerid][CodeTimer] = SetTimerEx("KickEx", 60000, false, "d", playerid);
    Dialog_Show(playerid, ConfirmarCodigoAcc, DIALOG_STYLE_INPUT, "{FF0000}Código", Dialog, "Confirmar", "Cancelar");
    return 1;
}

function VerificarAcesso(playerid)
{
    if(pAcesso[playerid][AcessoRestante] == 0) return 1;
    if(pAcesso[playerid][AcessoRestante] > gettime()) return 1;

    new Enviar[128];
    format(Enviar, sizeof(Enviar), "DELETE FROM `acessocodigo` WHERE `UsadoPor` = '%s'", EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);

    format(Enviar, sizeof(Enviar), "DELETE FROM `whitelist` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);

    SendClientMessage(playerid, -1, "| ACESSO | Seu acesso foi expirado");
    SetTimerEx("KickEx", 1000, false, "d", playerid);
    return 1;
}