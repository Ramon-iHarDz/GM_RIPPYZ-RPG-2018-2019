#include <YSI_Coding\y_hooks>

Dialog:SenhaEntrarCasa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;

    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, pCasa[i][cPosicaoX], pCasa[i][cPosicaoY], pCasa[i][cPosicaoZ])) continue;
        if(isnull(pCasa[i][cSenha])) return 1;
        if(strcmp(pCasa[i][cSenha], inputtext)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Senha incorreta!");
        EntrarCasa(playerid, i);
        break;
    } 
    return 0;
} 

Dialog:ColocarSenhaCasa(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) < 2) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Senha muito curta");
    if(strlen(inputtext) > 24) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Senha muito grande");
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
    new Cache:Conectar,
        Enviar[90]
    ;
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Tranca` = 1, `Senha` = '%s' WHERE `Numero` = %d", EscapeString(inputtext), casaid);
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao alterar sua casa!");
    cache_delete(Conectar);
    new Mensagem[90];
    format(Mensagem, sizeof(Mensagem), "| CASA | Você alterou sua casa para %s{FFFFFF} sua casa ( %s )", PegarCasaStatus(listitem), inputtext);
    SendClientMessage(playerid, -1, Mensagem);
    pCasa[casaid][cTranca] = 1;
    format(pCasa[casaid][cSenha], 90, inputtext);
    AtualizarCasa(casaid);
    return 0;
}

Dialog:TrancaCasa(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(pCasa[casaid][cTranca] == listitem) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Sua casa já está com essa permissão");
    
    if(listitem == 1){
        Dialog_Show(playerid, ColocarSenhaCasa, DIALOG_STYLE_INPUT, "{FF0000}Senha", "Coloque uma senha abaixo", "Confirmar", "Cancelar");
        return 1;
    }

    new Cache:Conectar,
        Enviar[90]
    ;
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Tranca` = %d WHERE `Numero` = %d", listitem, casaid);
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao alterar sua casa!");
    cache_delete(Conectar);
    new Mensagem[90];
    format(Mensagem, sizeof(Mensagem), "| CASA | Você alterou sua casa para %s{FFFFFF} sua casa", PegarCasaStatus(listitem));
    SendClientMessage(playerid, -1, Mensagem);
    pCasa[casaid][cTranca] = listitem;
    AtualizarCasa(casaid);
    return 0;
}

Dialog:MensagemCasa(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) < 2) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Mensagem muito curta");
    if(strlen(inputtext) > 35) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Mensagem muito grande");

    new Cache:Conectar,
        Enviar[90]
    ;
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Mensagem` = '%s' WHERE `Numero` = %d", EscapeString(inputtext), casaid);
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao alterar sua casa!");
    cache_delete(Conectar);
    format(pCasa[casaid][cMensagem], 90, inputtext);
    format(Enviar, sizeof(Enviar), "| CASA | Você alterou o nome da sua casa para {FFFFFF}%s", inputtext);
    SendClientMessage(playerid, 0xCCCCCCFF, Enviar);
    AtualizarCasa(casaid);
    return 1;
}

Dialog:MoradorAdicionar(playerid, response, listitem, inputtext[]){
    if(!response) return 1;

    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Coloque o ID do novo morador(a)");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não encontrado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não efetuou login");

    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
    new iid = pCasa[casaid][cInterior],
        vw = casaid
    ;
    vw++;
    vw = (vw*vw);
    iid -= 1;

    if(GetPlayerVirtualWorld(playerid) != vw && Jogador[id][uInteriorEx] != 1 && GetPlayerInterior(id) != pInterior[iid][Interior]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não está na sua casa");
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, pInterior[iid][cInterX], pInterior[iid][cInterY], pInterior[iid][cInterZ])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não está perto da porta");
    
    new listaah = GetPVarInt(playerid, "MoradorID");
    switch(listaah)
    {
        case 0:
        {
            new Cache:Conectar,
                Enviar[128]
            ;
            format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Morador1` = '%s' WHERE `Numero` = %d", EscapeString(PegarNick(id)), casaid);
            Conectar = mysql_query(IDConexao, Enviar);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao adicionar esse morador!");
            cache_delete(Conectar);
            format(Enviar, sizeof(Enviar), "| CASA | Você agora está morando na casa do(a) %s", PegarNick(playerid));
            SendClientMessage(id, 0xFFFF00FF, Enviar);
            format(Enviar, sizeof(Enviar), "| CASA | %s agora está morando na sua casa", PegarNick(id));
            SendClientMessage(playerid, 0xFFFF00FF, Enviar);
            format(pCasa[casaid][Morador1], 90, PegarNick(id));
        }
        case 1:
        {
            new Cache:Conectar,
                Enviar[128]
            ;
            format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Morador2` = '%s' WHERE `Numero` = %d", EscapeString(PegarNick(id)), casaid);
            Conectar = mysql_query(IDConexao, Enviar);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao adicionar esse morador!");
            cache_delete(Conectar);
            format(Enviar, sizeof(Enviar), "| CASA | Você agora está morando na casa do(a) %s", PegarNick(playerid));
            SendClientMessage(id, 0xFFFF00FF, Enviar);
            format(Enviar, sizeof(Enviar), "| CASA | %s agora está morando na sua casa", PegarNick(id));
            SendClientMessage(playerid, 0xFFFF00FF, Enviar);
            format(pCasa[casaid][Morador2], 90, PegarNick(id));
        }
        case 2:
        {
            new Cache:Conectar,
                Enviar[128]
            ;
            format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Morador3` = '%s' WHERE `Numero` = %d", EscapeString(PegarNick(id)), casaid);
            Conectar = mysql_query(IDConexao, Enviar);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao adicionar esse morador!");
            cache_delete(Conectar);
            format(Enviar, sizeof(Enviar), "| CASA | Você agora está morando na casa do(a) %s", PegarNick(playerid));
            SendClientMessage(id, 0xFFFF00FF, Enviar);
            format(Enviar, sizeof(Enviar), "| CASA | %s agora está morando na sua casa", PegarNick(id));
            SendClientMessage(playerid, 0xFFFF00FF, Enviar);
            format(pCasa[casaid][Morador3], 90, PegarNick(id));
        }
        case 3:
        {
            new Cache:Conectar,
                Enviar[128]
            ;
            format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Morador4` = '%s' WHERE `Numero` = %d", EscapeString(PegarNick(id)), casaid);
            Conectar = mysql_query(IDConexao, Enviar);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao adicionar esse morador!");
            cache_delete(Conectar);
            format(Enviar, sizeof(Enviar), "| CASA | Você agora está morando na casa do(a) %s", PegarNick(playerid));
            SendClientMessage(id, 0xFFFF00FF, Enviar);
            format(Enviar, sizeof(Enviar), "| CASA | %s agora está morando na sua casa", PegarNick(id));
            SendClientMessage(playerid, 0xFFFF00FF, Enviar);
            format(pCasa[casaid][Morador4], 90, PegarNick(id));
        }
    }
    
    return 0;
}

Dialog:OpcaoMorador(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");

    new lid = GetPVarInt(playerid, "MoradorID");
    switch(lid)
    {
        case 0:
        {
            if(strcmp(pCasa[casaid][Morador1], "*"))
            {
                new Cache:Conectar,
                    Enviar[90]
                ;
                format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Morador1` = '*' WHERE `Numero` = %d", casaid);
                Conectar = mysql_query(IDConexao, Enviar);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao remover esse morador!");
                cache_delete(Conectar);
                if(IsPlayerConnected(PegarIdPeloNick(pCasa[casaid][Morador1]))){
                    format(Enviar, sizeof(Enviar), "| CASA | Você foi removido(a) da casa %d por %s", casaid, PegarNick(playerid));
                    SendClientMessage(PegarIdPeloNick(pCasa[casaid][Morador1]), 0xFFFF00FF, Enviar);
                }
                format(Enviar, sizeof(Enviar), "| CASA | Você removeu a moradia do(a) %s", pCasa[casaid][Morador1]);
                SendClientMessage(playerid, 0xFFFF00FF, Enviar);
                format(pCasa[casaid][Morador1], 90, "*");
                AtualizarCasa(casaid);
                return 1;
            }
            SetPVarInt(playerid, "MoradorID", 0);
            Dialog_Show(playerid, MoradorAdicionar, DIALOG_STYLE_INPUT, "{FF0000}Morador", "Coloque o ID do(a) novo(a) morador(a) abaixo", "Confirmar", "Fechar");
        }
        case 1:
        {
            if(strcmp(pCasa[casaid][Morador2], "*")){
                new Cache:Conectar,
                    Enviar[90]
                ;
                format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Morador2` = '*' WHERE `Numero` = %d", casaid);
                Conectar = mysql_query(IDConexao, Enviar);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao remover esse morador!");
                cache_delete(Conectar);
                if(IsPlayerConnected(PegarIdPeloNick(pCasa[casaid][Morador2]))){
                    format(Enviar, sizeof(Enviar), "| CASA | Você foi removido(a) da casa %d por %s", casaid, PegarNick(playerid));
                    SendClientMessage(PegarIdPeloNick(pCasa[casaid][Morador2]), 0xFFFF00FF, Enviar);
                }
                format(Enviar, sizeof(Enviar), "| CASA | Você removeu a moradia do(a) %s", pCasa[casaid][Morador2]);
                SendClientMessage(playerid, 0xFFFF00FF, Enviar);
                format(pCasa[casaid][Morador2], 90, "*");
                AtualizarCasa(casaid);
                return 1;
            }
            SetPVarInt(playerid, "MoradorID", 1);
            Dialog_Show(playerid, MoradorAdicionar, DIALOG_STYLE_INPUT, "{FF0000}Morador", "Coloque o ID do(a) novo(a) morador(a) abaixo", "Confirmar", "Fechar");
        }
        case 2:
        {
            if(strcmp(pCasa[casaid][Morador3], "*")){
                new Cache:Conectar,
                    Enviar[90]
                ;
                format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Morador3` = '*' WHERE `Numero` = %d", casaid);
                Conectar = mysql_query(IDConexao, Enviar);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao remover esse morador!");
                cache_delete(Conectar);
                if(IsPlayerConnected(PegarIdPeloNick(pCasa[casaid][Morador3]))){
                    format(Enviar, sizeof(Enviar), "| CASA | Você foi removido(a) da casa %d por %s", casaid, PegarNick(playerid));
                    SendClientMessage(PegarIdPeloNick(pCasa[casaid][Morador3]), 0xFFFF00FF, Enviar);
                }
                format(Enviar, sizeof(Enviar), "| CASA | Você removeu a moradia do(a) %s", pCasa[casaid][Morador3]);
                SendClientMessage(playerid, 0xFFFF00FF, Enviar);
                format(pCasa[casaid][Morador3], 90, "*");
                AtualizarCasa(casaid);
                return 1;
            }
            SetPVarInt(playerid, "MoradorID", 2);
            Dialog_Show(playerid, MoradorAdicionar, DIALOG_STYLE_INPUT, "{FF0000}Morador", "Coloque o ID do(a) novo(a) morador(a) abaixo", "Confirmar", "Fechar");
        }
        case 3:
        {
            if(strcmp(pCasa[casaid][Morador4], "*")){
                new Cache:Conectar,
                    Enviar[90]
                ;
                format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Morador4` = '*' WHERE `Numero` = %d", casaid);
                Conectar = mysql_query(IDConexao, Enviar);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao remover esse morador!");
                cache_delete(Conectar);
                if(IsPlayerConnected(PegarIdPeloNick(pCasa[casaid][Morador4]))){
                    format(Enviar, sizeof(Enviar), "| CASA | Você foi removido(a) da casa %d por %s", casaid, PegarNick(playerid));
                    SendClientMessage(PegarIdPeloNick(pCasa[casaid][Morador4]), 0xFFFF00FF, Enviar);
                }
                format(Enviar, sizeof(Enviar), "| CASA | Você removeu a moradia do(a) %s", pCasa[casaid][Morador4]);
                SendClientMessage(playerid, 0xFFFF00FF, Enviar);
                format(pCasa[casaid][Morador4], 90, "*");
                AtualizarCasa(casaid);
                return 1;
            }
            SetPVarInt(playerid, "MoradorID", 3);
            Dialog_Show(playerid, MoradorAdicionar, DIALOG_STYLE_INPUT, "{FF0000}Morador", "Coloque o ID do(a) novo(a) morador(a) abaixo", "Confirmar", "Fechar");
        }
    }

    return 0;
}

Dialog:MoradorCasa(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID"),
        Dialog[90]
    ;
    if(strcmp(PegarNick(playerid), pCasa[casaid][cDono])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão");

    switch(listitem){
        case 0:{
            if(strcmp(pCasa[casaid][Morador1], "*")){
                strcat(Dialog, "Remover Morador(a)\n");
            }
            else {
                strcat(Dialog, "Adicionar Morador(a)\n");
            }
            SetPVarInt(playerid, "MoradorID", 0);
        }
        case 1:{
            if(strcmp(pCasa[casaid][Morador2], "*")){
                strcat(Dialog, "Remover Morador(a)\n");
            }
            else {
                strcat(Dialog, "Adicionar Morador(a)\n");
            }
            SetPVarInt(playerid, "MoradorID", 1);
        }
        case 2:{
            if(strcmp(pCasa[casaid][Morador3], "*")){
                strcat(Dialog, "Remover Morador(a)\n");
            }
            else{
                strcat(Dialog, "Adicionar Morador(a)\n");
            }
            SetPVarInt(playerid, "MoradorID", 2);
        }
        case 3:{
            if(strcmp(pCasa[casaid][Morador4], "*")){
                strcat(Dialog, "Remover Morador(a)\n");
            }
            else {
                strcat(Dialog, "Adicionar Morador(a)\n");
            }
            SetPVarInt(playerid, "MoradorID", 3);
        }
    }
    Dialog_Show(playerid, OpcaoMorador, DIALOG_STYLE_TABLIST, "{FF0000}Menu Morador", Dialog, "Selecionar", "Fechar");
    return 0;
}

Dialog:ConfirmarVendaCasa(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strcmp(Jogador[playerid][Codigo], inputtext)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Código Inválido!");
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
    new Cache:Conectar,
        Enviar[300]
    ;

    new ReformaTotal = (gettime() + (15 * 24 * 60 * 60));

    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Dono`= '*', `LixoF` = 0, `LixoD` = 0, `Impostos` = 0, `Mensagem` = '*', `Interior` = 1, `Reforma` = %d, `Tranca` = 0, `Morador1` = '*', `Morador2` = '*', `Morador3` = '*', `Morador4` = '*' WHERE `Numero` = %d", ReformaTotal, casaid);
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao vender essa casa!");
    cache_delete(Conectar);

    format(Enviar, sizeof(Enviar), "| CASA | {fc520f}%s[%d]{CCCCCC} vendeu sua casa id {fc520f}%d", pCasa[casaid][cDono], playerid, casaid);
    SendClientMessageToAll(0xCCCCCCFF, Enviar);

    Jogador[playerid][Dinheiro] += pCasa[casaid][cPreco];

    format(pCasa[casaid][cDono], 90, "*");
    format(pCasa[casaid][cSenha], 90, "*");
    format(pCasa[casaid][Morador1], 90, "*");
    format(pCasa[casaid][Morador2], 90, "*");
    format(pCasa[casaid][Morador3], 90, "*");
    format(pCasa[casaid][Morador4], 90, "*");

    pCasa[casaid][cReforma] = ReformaTotal;
    pCasa[casaid][cInterior] = 1;
    pCasa[casaid][cTranca] = 0; 
    if(pCasa[casaid][LixoF] > 0) DestroyObject(pCasa[casaid][LixoOb]); 
    pCasa[casaid][LixoF] = 0;
    pCasa[casaid][LixoD] = 0;
    pCasa[casaid][Impostos] = 0;
    AtualizarCasa(casaid);
    cmd_saircasa(playerid);
    return 0;
}

Dialog:UparCasa(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");

    if(pCasa[casaid][cPreco] > 0 && pCasa[casaid][cCoins] < 1) SetPVarInt(playerid, "MultiPlicacacoaDaCasa", pCasa[casaid][cPreco]);
    else if(pCasa[casaid][cPreco] < 1 && pCasa[casaid][cCoins] > 0) SetPVarInt(playerid, "MultiPlicacacoaDaCasa", (pCasa[casaid][cCoins] + 90000));
    else SetPVarInt(playerid, "MultiPlicacacoaDaCasa", pCasa[casaid][cPreco]);

    new InteriorFinal = listitem+2,
        ValorReal,
        OutroValor
    ;

    //Simular um valor
    for(new i=1; i < pCasa[casaid][cInteriorMax]; i++){
        if(i >= pCasa[casaid][cInterior]){
            OutroValor = GetPVarInt(playerid, "MultiPlicacacoaDaCasa")+100000;
            SetPVarInt(playerid, "MultiPlicacacoaDaCasa", OutroValor);
            if(i == listitem+1){
                ValorReal = OutroValor;
                break;
            }
        }
    }

    if(pCasa[casaid][cInterior] > 1 && InteriorFinal <= pCasa[casaid][cInterior]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode selecionar esse interior!");
    if(Jogador[playerid][Dinheiro] < ValorReal) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente!");

    new Cache:Conectar,
        Enviar[128]
    ;
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `Interior` = %d WHERE `Numero` = %d", InteriorFinal, casaid);
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao upar sua casa, solicite um desenvolvedor para resolver!");
    cache_delete(Conectar);

    Jogador[playerid][Dinheiro] -= ValorReal;
    new AntigoIntt = pCasa[casaid][cInterior];
    pCasa[casaid][cInterior] = InteriorFinal;

    format(Enviar, sizeof(Enviar), "| CASA | Você upou sua casa para o interior {00BFFF}%d{FFFFFF} e gastou {00FF00}$%s{FFFFFF} na reforma", InteriorFinal, DinheiroSeparar(ValorReal));
    SendClientMessage(playerid, -1, Enviar);

    format(Enviar, sizeof(Enviar), "| CASA | {00BFFF}%s[%d]{FFFFFF} upou essa casa para o interior {00BFFF}%d", PegarNick(playerid), playerid, InteriorFinal);
    new EstaIn;

    new iid = AntigoIntt,
        vw = casaid
    ;
    vw++;
    vw = (vw*vw);
    iid -= 1;

    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i) && Jogador[i][Logado] == false) continue;
        if(GetPlayerVirtualWorld(i) != vw && Jogador[i][uInteriorEx] != 1 && GetPlayerInterior(i) != pInterior[iid][Interior]) continue;
        if(!IsPlayerInRangeOfPoint(i, 3.0, pInterior[iid][cInterX], pInterior[iid][cInterY], pInterior[iid][cInterZ])) continue;

        EstaIn = InteriorFinal;
        EstaIn -= 1;

        SetPlayerInterior(i, pInterior[EstaIn][Interior]);
        SetPlayerPos(i, pInterior[EstaIn][cInterX], pInterior[EstaIn][cInterY], pInterior[EstaIn][cInterZ]);
        SetPlayerFacingAngle(i, pInterior[EstaIn][cInterA]);
        if(i != playerid) SendClientMessage(i, -1, Enviar);
    }
    AtualizarCasa(casaid); 
    return 0;
}

Dialog:VendaEscolha(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, ConfirmarVendaCasa, DIALOG_STYLE_INPUT, "{FF0000}Confirmação", "Coloque abaixo o código da sua conta para confimar", "Selecionar", "Fechar");   
        //case 1: Dialog_Show(playerid, ConfirmarVendaCasa, DIALOG_STYLE_INPUT, "{00FF00}Venda", "Coloque abaixo o preço que você está pedindo", "Selecionar", "Fechar");   
    }
    return 0;
}

Dialog:MenuCasa(playerid, response, listitem, inputtext[]){
    if(!response) return 1;
    new casaid = GetPVarInt(playerid, "InteriorPersonalizadoID");
    new Dialog[1200];
    switch(listitem)
    {
        case 0:
        {
            if(strcmp(PegarNick(playerid), pCasa[casaid][cDono])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão");
            strcat(Dialog, "Destrancar\n");
            strcat(Dialog, "Trancar com Senha\n");
            strcat(Dialog, "Trancar");
            Dialog_Show(playerid, TrancaCasa, DIALOG_STYLE_TABLIST, "{FF0000}Tranca", Dialog, "Selecionar", "Fechar");
        }
        case 1:
        {
            if(strcmp(PegarNick(playerid), pCasa[casaid][cDono])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão");
            Dialog_Show(playerid, MensagemCasa, DIALOG_STYLE_INPUT, "{FF0000}Mensagem", "Altere a mensagem da sua casa", "Selecionar", "Fechar");
        }
        case 2:
        {
            if(pCasa[casaid][LixoD] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem lixo dentro de casa");
            pCasa[casaid][LixoF] += pCasa[casaid][LixoD];
            pCasa[casaid][LixoD] = 0;
            SendClientMessage(playerid, 0xFFFF00FF, "| CASA | Você retirou os lixo(s) de entro de casa");
            AtualizarCasa(casaid);
        }
        case 3:
        {
            if(pCasa[casaid][cInterior] < 3) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa casa precisa ser level 3 para suportar moradores");
            if(pCasa[casaid][cInterior] >= 3){
                strcat(Dialog, "Lista\tNome\n");
                if(strcmp(pCasa[casaid][Morador1], "*")) strcatEx(Dialog, "1. Morador(a)\t{fc520f}%s\n", pCasa[casaid][Morador1]);
                else strcat(Dialog, "1. Morador(a)\t{FF0000}N/A\n");
            }

            if(pCasa[casaid][cInterior] >= 5){
                if(strcmp(pCasa[casaid][Morador2], "*")) strcatEx(Dialog, "2. Morador(a)\t{fc520f}%s\n", pCasa[casaid][Morador2]);
                else strcat(Dialog, "2. Morador(a)\t{FF0000}N/A\n");
            }

            if(pCasa[casaid][cInterior] >= 10){
                if(strcmp(pCasa[casaid][Morador3], "*")) strcatEx(Dialog, "3. Morador(a)\t{fc520f}%s\n", pCasa[casaid][Morador3]);
                else strcat(Dialog, "3. Morador(a)\t{FF0000}N/A\n");
            }

            if(pCasa[casaid][cInterior] >= 11){
                if(strcmp(pCasa[casaid][Morador4], "*")) strcatEx(Dialog, "4. Morador(a)\t{fc520f}%s\n", pCasa[casaid][Morador4]);
                else strcat(Dialog, "4. Morador(a)\t{FF0000}N/A\n");
            }
            Dialog_Show(playerid, MoradorCasa, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Moradores(as)", Dialog, "Selecionar", "Fechar");
        }
        case 4:
        {
            if(strcmp(PegarNick(playerid), pCasa[casaid][cDono])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão");
            new OutroValor;
            
            if(pCasa[casaid][cPreco] > 0 && pCasa[casaid][cCoins] < 1) SetPVarInt(playerid, "MultiPlicacacoaDaCasa", pCasa[casaid][cPreco]);
            else if(pCasa[casaid][cPreco] < 1 && pCasa[casaid][cCoins] > 0) SetPVarInt(playerid, "MultiPlicacacoaDaCasa", (pCasa[casaid][cCoins] + 90000));
            else SetPVarInt(playerid, "MultiPlicacacoaDaCasa", pCasa[casaid][cPreco]);
            
            strcat(Dialog, "Upgrade\tPreço\n");
            for(new i=1; i < pCasa[casaid][cInteriorMax]; i++)
            {
                if(i >= pCasa[casaid][cInterior])
                {
                    OutroValor = GetPVarInt(playerid, "MultiPlicacacoaDaCasa")+100000;
                    SetPVarInt(playerid, "MultiPlicacacoaDaCasa", OutroValor);   

                    if(Jogador[playerid][Dinheiro] >= OutroValor) strcatEx(Dialog, "{00FF00}»{FFFFFF} Interior %d\t{00FF00}$%s\n", i+1, DinheiroSeparar(OutroValor));
                    else strcatEx(Dialog, "{FF0000}»{FFFFFF} Interior %d\t{FF0000}$%s\n", i+1, DinheiroSeparar(OutroValor));
                }
                else strcatEx(Dialog, "{FFFF00}»{FFFFFF} Interior %d\t{FF0000}N/A\n", i+1);
            }
            Dialog_Show(playerid, UparCasa, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Upgrade Interior", Dialog, "Selecionar", "Fechar");
        }
        case 5:
        {
            if(strcmp(PegarNick(playerid), pCasa[casaid][cDono])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão");
            if(pCasa[casaid][cReforma] > gettime()){
                new Mensagem[70];
                format(Mensagem, sizeof(Mensagem), "| ERRO | Você só pode vender sua casa em %s", ConverterSegundos(pCasa[casaid][cReforma]));
                SendClientMessage(playerid, 0xfc520fFF, Mensagem);
                return 1;
            }
            if(strcmp(pCasa[casaid][Morador1], "*") && strcmp(pCasa[casaid][Morador2], "*") && 
            strcmp(pCasa[casaid][Morador3], "*") && strcmp(pCasa[casaid][Morador4], "*")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Retire todos os moradores(as) da sua casa");
            if(pCasa[casaid][LixoD] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Retire primeiro o lixo de dentro da sua casa");
            if(pCasa[casaid][LixoF] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Retire primeiro o lixo de fora da sua casa");
            if(pCasa[casaid][Impostos] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Pague os impostos antes de vender!");
            
            strcat(Dialog, "{FFFFFF}Vender para Servidor\n");
            strcat(Dialog, "{FFFFFF}Definir Preço");
            Dialog_Show(playerid, VendaEscolha, DIALOG_STYLE_TABLIST, "{00FF00}Venda", Dialog, "Selecionar", "Fechar");   
        }
    }

    return 0;
}