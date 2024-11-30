#include <YSI_Coding\y_hooks>

hook OnPlayerOb_RCObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
    new id = GetPVarInt(playerid, "SelecionadoAID"); 
    if(!response)
    {
        RemovePlayerAttachedObject(playerid, index);
        if(pAcessorio[playerid][id][Ativado] == true) SetPlayerAttachedObject(playerid, index, pAcessorio[playerid][id][AcessorioObj], pAcessorio[playerid][id][Bone], pAcessorio[playerid][id][AOffsetX], pAcessorio[playerid][id][AOffsetY], pAcessorio[playerid][id][AOffsetZ], pAcessorio[playerid][id][ARotX], pAcessorio[playerid][id][ARotY], pAcessorio[playerid][id][ARotZ], pAcessorio[playerid][id][AScaleX], pAcessorio[playerid][id][AScaleY], pAcessorio[playerid][id][AScaleZ], 0xFFFFFFFF, 0xFFFFFFFF);
        SendClientMessage(playerid, 0xFFFF00FF, "| ACESSÓRIO | Você cancelou o edit do acessório");
        return 1;
    }
    
    if(fScaleX > 2.00 || fScaleZ > 2.00 || fScaleY > 2.00 || fOffsetX > 2.00 || fOffsetY > 2.00 || fOffsetZ > 2.00)
    {
        RemovePlayerAttachedObject(playerid, id);
        if(pAcessorio[playerid][id][Ativado] == true) pAcessorio[playerid][id][Ativado] = false;
        SendClientMessage(playerid, 0xFF4500FF, "| ACESSÓRIO | Acessório muito longe ou muito longo, reajuste-o");
        return 1;
    }

    new Enviar[300];
    strcat(Enviar, "UPDATE `acessorios` SET ");
    strcatEx(Enviar, "`Bone`=%d ,`OffsetX`=%f, `OffsetY`=%f, `OffsetZ`=%f, `RotX`=%f, `RotY`=%f, `RotZ`=%f, `ScaleX`=%f, `ScaleY`=%f, `ScaleZ`=%f", boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
    strcatEx(Enviar, " WHERE `Nome`='%s' AND `Slot` = %d", EscapeString(PegarNick(playerid)), id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0)
    {
        RemovePlayerAttachedObject(playerid, index);
        if(pAcessorio[playerid][id][Ativado] == true) SetPlayerAttachedObject(playerid, index, pAcessorio[playerid][id][AcessorioObj], pAcessorio[playerid][id][Bone], pAcessorio[playerid][id][AOffsetX], pAcessorio[playerid][id][AOffsetY], pAcessorio[playerid][id][AOffsetZ], pAcessorio[playerid][id][ARotX], pAcessorio[playerid][id][ARotY], pAcessorio[playerid][id][ARotZ], pAcessorio[playerid][id][AScaleX], pAcessorio[playerid][id][AScaleY], pAcessorio[playerid][id][AScaleZ], 0xFFFFFFFF, 0xFFFFFFFF);
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um erro ao salvar esse acessório, entre em contato com um desenvolvedor");     
        return 1;
    }
    RemovePlayerAttachedObject(playerid, index);

    //Int
    pAcessorio[playerid][id][Bone] = boneid;

    //Floats
    pAcessorio[playerid][id][AOffsetX] = fOffsetX;
    pAcessorio[playerid][id][AOffsetY] = fOffsetY;
    pAcessorio[playerid][id][AOffsetZ] = fOffsetZ;

    pAcessorio[playerid][id][ARotX] = fRotX;
    pAcessorio[playerid][id][ARotY] = fRotY;
    pAcessorio[playerid][id][ARotZ] = fRotZ;

    pAcessorio[playerid][id][AScaleX] = fScaleX;
    pAcessorio[playerid][id][AScaleY] = fScaleY;
    pAcessorio[playerid][id][AScaleZ] = fScaleZ;
    SendClientMessage(playerid, 0xFFFF00FF, "| ACESSÓRIO | Você salvou seu acessório com sucesso");   

    if(pAcessorio[playerid][id][Ativado] == false){   
        if(EspacoEquiparAcessorio(playerid)){
            format(Enviar, sizeof(Enviar), "UPDATE `acessorios` SET `Ativado` = 1 WHERE `Nome`= '%s' AND `Slot` = %d", EscapeString(PegarNick(playerid)), id);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return 1;
            pAcessorio[playerid][id][Ativado] = true;
            pAcessorio[playerid][id][IndexAcessorio] = index;  
        }
    }
    if(pAcessorio[playerid][id][Ativado] == true) SetPlayerAttachedObject(playerid, index, pAcessorio[playerid][id][AcessorioObj], pAcessorio[playerid][id][Bone], pAcessorio[playerid][id][AOffsetX], pAcessorio[playerid][id][AOffsetY], pAcessorio[playerid][id][AOffsetZ], pAcessorio[playerid][id][ARotX], pAcessorio[playerid][id][ARotY], pAcessorio[playerid][id][ARotZ], pAcessorio[playerid][id][AScaleX], pAcessorio[playerid][id][AScaleY], pAcessorio[playerid][id][AScaleZ], 0xFFFFFFFF, 0xFFFFFFFF);
    return 0;
}

stock InvSlotID(playerid)
{
    for(new i=0; i < MAX_ACESSORIOS; i++)
    {
        if(IsPlayerAttachedObjectSlotUsed(playerid, i)) continue;
        return i;
    }
    return -1;
}

Dialog:AcessorioPos(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new boneid = listitem+1;
    new id = GetPVarInt(playerid, "SelecionadoAID"),
        idx = InvSlotID(playerid);
    
    if(pAcessorio[playerid][id][Ativado] == false){
        if(idx == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais espaços para adicionar acessórios");
    }
    
    SendClientMessage(playerid, -1, "| DICA | Aperte {00BFFF}ESPAÇO{FFFFFF} para rotacionar a câmera");
    SendClientMessage(playerid, -1, "| DICA | Após configurar clique no botão de {00BFFF}'salvar'{FFFFFF} para salvar acessório");
    
    if(pAcessorio[playerid][id][Bone] == boneid)
    {
        if(pAcessorio[playerid][id][Ativado] == true){
            RemovePlayerAttachedObject(playerid, pAcessorio[playerid][id][IndexAcessorio]);
            idx = pAcessorio[playerid][id][IndexAcessorio];
        }
        SetPlayerAttachedObject(playerid, idx, pAcessorio[playerid][id][AcessorioObj], boneid, pAcessorio[playerid][id][AOffsetX], pAcessorio[playerid][id][AOffsetY], pAcessorio[playerid][id][AOffsetZ], pAcessorio[playerid][id][ARotX], pAcessorio[playerid][id][ARotY], pAcessorio[playerid][id][ARotZ], pAcessorio[playerid][id][AScaleX], pAcessorio[playerid][id][AScaleY], pAcessorio[playerid][id][AScaleZ], 0xFFFFFFFF, 0xFFFFFFFF);
        EditAttachedObject(playerid, idx);
    }
    else
    {
        if(pAcessorio[playerid][id][Ativado] == true){
            RemovePlayerAttachedObject(playerid, pAcessorio[playerid][id][IndexAcessorio]);
            idx = pAcessorio[playerid][id][IndexAcessorio];
        }
        pAcessorio[playerid][id][AScaleX] = 1.0;
        pAcessorio[playerid][id][AScaleY] = 1.0;
        pAcessorio[playerid][id][AScaleZ] = 1.0;
        SetPlayerAttachedObject(playerid, idx, pAcessorio[playerid][id][AcessorioObj], boneid, pAcessorio[playerid][id][AOffsetX], pAcessorio[playerid][id][AOffsetY], pAcessorio[playerid][id][AOffsetZ], pAcessorio[playerid][id][ARotX], pAcessorio[playerid][id][ARotY], pAcessorio[playerid][id][ARotZ], pAcessorio[playerid][id][AScaleX], pAcessorio[playerid][id][AScaleY], pAcessorio[playerid][id][AScaleZ], 0xFFFFFFFF, 0xFFFFFFFF);
        EditAttachedObject(playerid, idx);
    }
    return 1;
}

Dialog:NomeAcessorioAlterar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nome muito longo");
    
    new Enviar[128],
        id = GetPVarInt(playerid, "SelecionadoAID");
    
    format(Enviar, sizeof(Enviar), "UPDATE `acessorios` SET `AcessorioNome`='%s' WHERE `Nome`='%s' AND `Slot`=%d", EscapeString(inputtext), EscapeString(PegarNick(playerid)), id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao alterar o nome desse acessório!");

    format(Enviar, sizeof(Enviar), "| ACESSÓRIO | Nome do acessório {FF0000}%s{FFFFFF} foi alterado para {FF4500}%s", pAcessorio[playerid][id][AcessorioNome], inputtext);
    SendClientMessage(playerid, -1, Enviar);
    format(pAcessorio[playerid][id][AcessorioNome], 90, inputtext);
    return 1;
}

Dialog:AcessorioExcluir(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[128],
        id = GetPVarInt(playerid, "SelecionadoAID");
    
    format(Enviar, sizeof(Enviar), "DELETE FROM `acessorios` WHERE `Nome`='%s' AND `Slot`=%d", EscapeString(PegarNick(playerid)), id);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao excluir esse acessório, solicite contato com um desenvolvedor!");
    if(pAcessorio[playerid][id][Ativado] == true) RemovePlayerAttachedObject(playerid, pAcessorio[playerid][id][IndexAcessorio]);
    new dsada[AcessoriosJogador];
    pAcessorio[playerid][id] = dsada;
    SendClientMessage(playerid, 0xFFD700FF, "| ACESSÓRIO | Acessório excluido com sucesso");
    return 1;
}


Dialog:AcessorioMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "SelecionadoAID");

    switch(listitem)
    {
        case 0:
        {
            new Enviar[90];
            if(pAcessorio[playerid][id][Ativado] == false)
            {
                if(!EspacoEquiparAcessorio(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem mais espaço em seu corpo para acessórios");
                if(pAcessorio[playerid][id][Bone] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Configure o acessório antes de coloca-lo em você");
                new idx = InvSlotID(playerid);
                if(idx == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há espaço para adicionar mais acessórios");

                format(Enviar, sizeof(Enviar), "UPDATE `acessorios` SET `Ativado` = 1 WHERE `Nome` = '%s' AND `Slot` = %d", EscapeString(PegarNick(playerid)), id);
                mysql_query(IDConexao, Enviar, false);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao adicionar esse acessório em você");

                SetPlayerAttachedObject(playerid, idx, pAcessorio[playerid][id][AcessorioObj], pAcessorio[playerid][id][Bone], pAcessorio[playerid][id][AOffsetX], pAcessorio[playerid][id][AOffsetY], pAcessorio[playerid][id][AOffsetZ], pAcessorio[playerid][id][ARotX], pAcessorio[playerid][id][ARotY], pAcessorio[playerid][id][ARotZ], pAcessorio[playerid][id][AScaleX], pAcessorio[playerid][id][AScaleY], pAcessorio[playerid][id][AScaleZ], 0xFFFFFFFF, 0xFFFFFFFF);
                pAcessorio[playerid][id][Ativado] = true; 
                pAcessorio[playerid][id][IndexAcessorio] = idx;
                SendClientMessage(playerid, 0xf5b342FF, "| ACESSÓRIO | Acessório adicionado com sucesso");
                return 1;
            }
            format(Enviar, sizeof(Enviar), "UPDATE `acessorios` SET `Ativado` = 0 WHERE `Nome` = '%s' AND `Slot` = %d", EscapeString(PegarNick(playerid)), id);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao remover esse acessório em você");

            RemovePlayerAttachedObject(playerid, pAcessorio[playerid][id][IndexAcessorio]);
            pAcessorio[playerid][id][Ativado] = false;
            SendClientMessage(playerid, 0xf5b342FF, "| ACESSÓRIO | Acessório retirado com sucesso");
        }

        case 1:
        {
            //if(pAcessorio[playerid][id][Ativado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Conecte o acessorio para configura-lo");
            new Dialog[600];
            strcat(Dialog, "{FFFFFF}Coluna\n");
            strcat(Dialog, "{FFFFFF}Cabeça\n");
            strcat(Dialog, "{FFFFFF}Braço esquerdo\n");
            strcat(Dialog, "{FFFFFF}Braço direito\n");
            strcat(Dialog, "{FFFFFF}Mão esquerda\n");
            strcat(Dialog, "{FFFFFF}Mão direita\n");
            strcat(Dialog, "{FFFFFF}Coxa esquerda\n");
            strcat(Dialog, "{FFFFFF}Coxa direita\n");
            strcat(Dialog, "{FFFFFF}Pé esquerdo\n");
            strcat(Dialog, "{FFFFFF}Pé direito\n");
            strcat(Dialog, "{FFFFFF}Panturrilha direita\n");
            strcat(Dialog, "{FFFFFF}Panturrilha esquerda\n");
            strcat(Dialog, "{FFFFFF}Antebraço esquerdo\n");
            strcat(Dialog, "{FFFFFF}Antebraço direito\n");
            strcat(Dialog, "{FFFFFF}Clavícula esquerda (ombro)\n");
            strcat(Dialog, "{FFFFFF}Clavícula direito (ombro)\n");
            strcat(Dialog, "{FFFFFF}Pescoço\n");
            strcat(Dialog, "{FFFFFF}Mandíbula");
            Dialog_Show(playerid, AcessorioPos, DIALOG_STYLE_LIST, "{FF0000}Configurar Acessório", Dialog, "Selecionar", "Fechar");
        }
        case 2: Dialog_Show(playerid, NomeAcessorioAlterar, DIALOG_STYLE_INPUT, "{FF0000}Acessório Nome", "{CCCCCC}Coloque o nome do seu acessorio", "Confirmar", "Fechar");    
        case 3: Dialog_Show(playerid, AcessorioExcluir, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", "{CCCCCC}Você realmente deseja excluir esse acessório?", "Confirmar", "Fechar");     
    }
    return 0;
}

Dialog:ConfigAcessorio(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = listitem;
    if(pAcessorio[playerid][id][AcessorioObj] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem acessório nesse slot");
    new Dialog[300];

    if(pAcessorio[playerid][id][Ativado] == true) strcat(Dialog, "{FFFFFF}Remover Acessório\n");
    else if(pAcessorio[playerid][id][Ativado] == false) strcat(Dialog, "{FFFFFF}Adicionar Acessório\n");
    strcat(Dialog, "{FFFFFF}Configurar Acessório\n");
    strcat(Dialog, "{FFFFFF}Alterar Nome\n");
    strcat(Dialog, "{FF0000}Excluir Acessório");
    SetPVarInt(playerid, "SelecionadoAID", id);
    Dialog_Show(playerid, AcessorioMenu, DIALOG_STYLE_LIST, "{FF0000}Menu Acessório", Dialog, "Selecionar", "Fechar");
    return 0;
}

Dialog:AdminObjeto(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    new objetoid,
        bool:temespaco;
    if(sscanf(inputtext, "d", objetoid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Objeto ID inválido!");
    if(objetoid < 1 || objetoid == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | ID Inválido");

    for(new i=0; i < MAX_ACESSORIOSINV; i++)
    {
        if(pAcessorio[playerid][i][AcessorioObj] == 0)
        {
            new Enviar[400];
            format(Enviar, sizeof(Enviar), "INSERT INTO `acessorios` (`Nome`, `Slot`, `AcessorioNome`, `ModeloID`, `ScaleX`, `ScaleY`, `ScaleZ`) VALUES ('%s', %d, '%s', %d, %f, %f, %f)", EscapeString(PegarNick(playerid)), i, GetObjectName(objetoid), objetoid, 1.0, 1.0, 1.0);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um erro ao adicionar esse acessorio em sua conta");
            pAcessorio[playerid][i][AcessorioObj] = objetoid;
            format(pAcessorio[playerid][i][AcessorioNome], 90, GetObjectName(objetoid));
            format(Enviar, sizeof(Enviar), "| ADMIN | Acessório {00BFFF}%s[%d]{FFFFFF} foi adicionado em sua conta, Use: /Acessorios", GetObjectName(objetoid), objetoid);
            SendClientMessage(playerid, -1, Enviar);
            temespaco = true;
            break;
        }
    }

    if(temespaco == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem espaço sucifiente para mais acessórios!");
    return 0;
}

CMD:acessorios(playerid)
{
    new Dialog[1800];
    strcat(Dialog, "Slot\tNome\tStatus\n");
    for(new i=0; i < MAX_ACESSORIOSINV; i++)
    {
        if(pAcessorio[playerid][i][AcessorioObj] == 0){
            strcatEx(Dialog, "{FF4500}%d.\t{FFFFFF}N/A\t{FF0000}Desativado\n", i, pAcessorio[playerid][i][AcessorioNome]); 
            continue ;
        }
        if(pAcessorio[playerid][i][Ativado] == false) strcatEx(Dialog, "{FF4500}%d.\t{00BFFF}%s\t{FF0000}Desativado\n", i, pAcessorio[playerid][i][AcessorioNome]);
        else strcatEx(Dialog, "{FF4500}%d.\t{00BFFF}%s\t{00FF00}Ativado\n", i, pAcessorio[playerid][i][AcessorioNome]);
    }
    Dialog_Show(playerid, ConfigAcessorio, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Acessórios", Dialog, "Selecionar", "Fechar");
    return 1;
}

CMD:acessorioadm(playerid)
{
    if(Jogador[playerid][Admin] < 3) return 0;
    Dialog_Show(playerid, AdminObjeto, DIALOG_STYLE_INPUT, "{FF0000}Admin Acessórios", "{CCCCCC}Coloque ID de um objeto para adiciona-lo", "Confirmar", "Fechar");
    return 1;
}

stock EspacoEquiparAcessorio(playerid)
{
    new EspacoA;
    for(new i=0; i < MAX_ACESSORIOSINV; i++)
    {
        if(pAcessorio[playerid][i][Ativado] == false) continue;
        EspacoA++;
        if(EspacoA >= MAX_ACESSORIOS) return false;
    }
    return true;
}