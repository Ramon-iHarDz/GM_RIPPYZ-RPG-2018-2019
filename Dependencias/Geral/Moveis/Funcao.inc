stock PegarMovel(id)
{
    for(new i=0; i < MAX_MOVEIS; i++)
    {
        if(cMovel[id][i][cMovelObjeto] != 0) continue;
        return i;
    }
    return -1;
}

stock RemoverMovel(id, i)
{
    DestroyDynamicObjectEx(cMovel[id][i][cMovelID]);
    stringclear(cMovel[id][i][cMovelNome]);
    cMovel[id][i][cMovelObjeto] = 0;
    cMovel[id][i][cStatus] = 0;
    cMovel[id][i][cmPreco] = 0;
    cMovel[id][i][cmPrecoCoins] = 0;
    cMovel[id][i][MovelX] = 0.0;
    cMovel[id][i][MovelY] = 0.0;
    cMovel[id][i][MovelZ] = 0.0;
    cMovel[id][i][MovelRx] = 0.0;
    cMovel[id][i][MovelRy] = 0.0;
    cMovel[id][i][MovelRz] = 0.0;
    cMovel[id][i][cAtivado] = false;
    return 1;
}

stock RemoverMoveis(playerid, id)
{
    new Dialog[2000];
    format(Dialog, sizeof(Dialog), "DELETE FROM `moveis` WHERE `Nome` = '%s'", EscapeString(pCasa[id][cDono]));
    mysql_query(IDConexao, Dialog, false);
    if(mysql_errno(IDConexao) != 0) return 1; // Adicionar uma LOG de erro depois.
    stringclear(Dialog);

    for(new i=0; i < MAX_MOVEIS; i++)
    {
        if(cMovel[id][i][cAtivado] == false) continue;
        Jogador[playerid][Coins] += cMovel[id][i][cmPrecoCoins];
        Jogador[playerid][Dinheiro] += cMovel[id][i][cmPreco];
        strcatEx(Dialog, "Móvel %s | Coins: $%s / Dinheiro: $%s\n", cMovel[id][i][cMovelNome], DinheiroSeparar(cMovel[id][i][cmPrecoCoins]), DinheiroSeparar(cMovel[id][i][cmPreco]));
        RemoverMovel(id, i);
    }

    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST, "{FF0000}Seus Móveis", Dialog, "Fechar", "");
    return 1;
}

stock RemoverMoveisAdmin(id)
{
    new Dialog[100];
    format(Dialog, sizeof(Dialog), "DELETE FROM `moveis` WHERE `Nome` = '%s'", EscapeString(pCasa[id][cDono]));
    mysql_query(IDConexao, Dialog, false);
    if(mysql_errno(IDConexao) != 0) return 1; // Adicionar uma LOG de erro depois.
    for(new i=0; i < MAX_MOVEIS; i++)
    {
        if(cMovel[id][i][cAtivado] == false) continue;
        RemoverMovel(id, i);
    }
    return 1;
}

stock DesativarMoveis(id)
{
    new Dialog[100];
    format(Dialog, sizeof(Dialog), "UPDATE `moveis` SET `Ativado` = 0 WHERE `Casa` = %d", id);
    mysql_query(IDConexao, Dialog, false);
    if(mysql_errno(IDConexao) != 0) return 1; // Adicionar uma LOG de erro depois.

    for(new i=0; i < MAX_MOVEIS; i++)
    {
        if(cMovel[id][i][cAtivado] == false) continue;
        DestroyDynamicObjectEx(cMovel[id][i][cMovelID]);
        cMovel[id][i][MovelX] = 0.0;
        cMovel[id][i][MovelY] = 0.0;
        cMovel[id][i][MovelZ] = 0.0;
        cMovel[id][i][MovelRx] = 0.0;
        cMovel[id][i][MovelRy] = 0.0;
        cMovel[id][i][MovelRz] = 0.0;
        cMovel[id][i][cAtivado] = false;
    }
    return 1;
}

stock AdicionarMovelCasa(casa, id, objeto, const ObjetoNomeA[], pcoins, preco, bool:admmm = false)
{
    new sts;
    if(admmm == false) sts = 1;

    new Enviar[330];
    format(Enviar, sizeof(Enviar), "INSERT INTO `moveis` (`Nome`, `ObjetoNome`, `Objeto`, `Casa`, `MaxID`, `Preco`, `Coins`, `Status`) VALUES ('%s', '%s', %d, %d, %d, %d, %d, %d)", EscapeString(pCasa[casa][cDono]), EscapeString(ObjetoNomeA), objeto, casa, id, preco, pcoins, sts);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return 1; // Adicionar LOG de erro depois.

    cMovel[casa][id][cmPreco] = (preco * 8) / 100;
    cMovel[casa][id][cmPrecoCoins] = (pcoins * 8) / 100;
    cMovel[casa][id][cMovelObjeto] = objeto;
    cMovel[casa][id][cStatus] = 1;
    format(cMovel[casa][id][cMovelNome], 30, ObjetoNomeA);
    return 1;
}

stock MoveisEntregue(id)
{
    if(eMoveis[id][MoveisQuantidade] > 0) return false;
    return true;    
}

stock LoadDialogMoveis(playerid, id)
{
    new Dialog[600];
    SetPVarInt(playerid, "AtlBBBBBB", 0); 
    strcat(Dialog, "Slot\tNome\tStatus\n");
    for(new i=GetPVarInt(playerid, "AtlAAAAAA"); i < MAX_MOVEIS; i++)
    {
        if(GetPVarInt(playerid, "AtlBBBBBB") >= 10 && GetPVarInt(playerid, "AtlBBBBBB") < MAX_MOVEIS){
            strcat(Dialog, "{32CD32}Próxima Página");
            break;
        }
        else if(cMovel[id][i][cMovelObjeto] == 0) strcatEx(Dialog, "{FFFFFF}%d.\t%s\t{CCCCCC}N/A\n", i+1, "{FF0000}N/A");
        else if(cMovel[id][i][cStatus] == 1) strcatEx(Dialog, "{FFFFFF}%d.\t%s\t{FFFF00}Aguardando Entrega\n", i+1, cMovel[id][i][cMovelNome]);
        else if(cMovel[id][i][cAtivado] == false) strcatEx(Dialog, "{FFFFFF}%d.\t{FFA500}%s\t{FF0000}Desativado\n", i+1, cMovel[id][i][cMovelNome]);
        else strcatEx(Dialog, "{FFFFFF}%d.\t{FFA500}%s\t{32CD32}Ativado\n", i+1, cMovel[id][i][cMovelNome]);   
        SetPVarInt(playerid, "AtlBBBBBB", GetPVarInt(playerid, "AtlBBBBBB")+1);
        SetPVarInt(playerid, "AtlAAAAAA", GetPVarInt(playerid, "AtlAAAAAA")+1);
    }
    Dialog_Show(playerid, MoveisMenu, DIALOG_STYLE_TABLIST_HEADERS, "{ff0000}Móveis", Dialog, "Selecionar", "Fechar");
    return 1;
}

stock SelecionarMovel(playerid, id, idxx)
{
    new idx = idxx,
        Mensagem[128];
    if(cMovel[id][idx][cMovelObjeto] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhum móvel nesse slot");
    SetPVarInt(playerid, "MovelSlot", idx);
    if(cMovel[id][idx][cAtivado] == true) strcat(Mensagem, "{CCCCCC}Guardar Móvel{FFFFFF}\n");
    else if(cMovel[id][idx][cAtivado] == false) strcat(Mensagem, "{CCCCCC}Adicionar Móvel{FFFFFF}\n");
    strcat(Mensagem, "Puxar Móvel\n");
    strcat(Mensagem, "Posicionar Móvel\n");
    strcat(Mensagem, "{FF0000}Excluir Móvel\n");
    strcat(Mensagem, "{7FFF00}Vender Móvel");
    Dialog_Show(playerid, MovelStatus, DIALOG_STYLE_TABLIST, cMovel[id][idx][cMovelNome], Mensagem, "Selecionar", "Fechar");
    return 1;
}

stock CasaMoveis(id)
{
    new qnt;
    for(new i=0; i < MAX_MOVEIS; i++)
    {
        if(cMovel[id][i][cMovelObjeto] == 0) continue;
        qnt++;
    }
    return qnt;
}