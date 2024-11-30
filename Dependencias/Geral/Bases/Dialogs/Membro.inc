Dialog:BaseSenha(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new id = GetPVarInt(playerid, "GambiarraSenha");
    if(strcmp(inputtext, Base[id][bSenha])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Senha está incorreta!");
    EntrarBase(playerid, id);
    return 0;
}

Dialog:NomeDaBase(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new Nha[25];
    if(sscanf(inputtext, "s[25]", Nha)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nome inválido, coloque outro!");
    if(strlen(Nha) >= 25) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você pode colocar até 25 caracteres no nome da base");
    SetPVarString(playerid, "NomeDaBase", Nha);
    Dialog_Show(playerid, TagDaBase, DIALOG_STYLE_INPUT, "{FF0000}Tag", "Coloque abaixo a abreviação\nExemplo: RCA ou RCCA\nObservação: Você só pode colocar no máximo 4 caracteres", "Confirmar", "Fechar");
    return 0;
}

Dialog:TagDaBase(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new Nha[15];
    if(sscanf(inputtext, "s[4]", Nha)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nome inválido, coloque outro!");
    if(strlen(Nha) >= 4) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você pode colocar até 4 caracteres no nome da base");
    new id = GetPVarInt(playerid, "IDCompraBase");
    if(strcmp(Base[id][bDono], "*")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa base já foi comprada");

    new Vencio = (gettime() + (30 * 24 * 60 * 60)),
        Enviar[300],
        NomeBS[80]
    ;
    GetPVarString(playerid, "NomeDaBase", NomeBS, 80);
    format(Enviar, sizeof(Enviar), "UPDATE `bases` SET `Vencimento` = %d, `Dono` = '%s', `Tag` = '%s', `Nome` = '%s', `Cor` = -1, `Senha` = '*' WHERE `Numero` = %d", Vencio, EscapeString(PegarNick(playerid)), EscapeString(Nha), EscapeString(NomeBS), id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao comprar!");

    Jogador[playerid][Coins] -= Base[id][bPreco];
    Jogador[playerid][BaseID] = id;

    Base[id][bCofre] = 0;
    Base[id][bEstado] = 0;
    Base[id][bVencimento] = 0;
    Base[id][bTranca] = 0;
    Base[id][bCor] = -1;

    format(Base[id][bDono], 70, PegarNick(playerid));
    format(Base[id][bSenha], 70, "*");
    format(Base[id][bTag], 70, Nha);
    format(Base[id][bNome], 70, NomeBS);

    format(Enviar, sizeof(Enviar), "| BASE | Você comprou a base ( ID: %d ) por $%s de coins", id, DinheiroSeparar(Base[id][bPreco]));
    SendClientMessage(playerid, 0xFFA500FF, Enviar);

    format(Enviar, sizeof(Enviar), "| BASE | Data da próxima renovação ( %s )", GetDateFromTime(Vencio));
    SendClientMessage(playerid, 0xFFA500FF, Enviar);
    AtualizarBase(id);
    return 0;
}