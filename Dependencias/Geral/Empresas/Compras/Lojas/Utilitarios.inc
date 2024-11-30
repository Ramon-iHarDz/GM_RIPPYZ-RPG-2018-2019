Dialog:UtilitariosMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    switch(listitem)
    {
        /*// Comprar Celular
        case 0:
        {
            if(Jogador[playerid][Celular] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já tem um celular");
            if(Jogador[playerid][Dinheiro] < 2500) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `celular` = 1 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");
            Jogador[playerid][Celular] = true;
            Jogador[playerid][Dinheiro] -= 2500;
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou um celular por R$2.500");
            EnviarDinheiroEmpresa(id, 2500); 
        }*/

        // Créditos 
        case 0:
        {
            if(Jogador[playerid][Creditos] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você ainda possui créditos");
            new Dialog[300];
            strcat(Dialog, "200 Créditos\tR$800\n");
            strcat(Dialog, "300 Créditos\tR$1.000\n");
            strcat(Dialog, "500 Créditos\tR$2.500");
            Dialog_Show(playerid, CompraDeSms, DIALOG_STYLE_TABLIST, "{FF0000}Compra de SMS", Dialog, "Comprar", "Cancelar");
        }

        // Mochila
        case 1:
        {
            if(Jogador[playerid][Mochila] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui uma Mochila");
            if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de mochilas nessa empresa");
            if(Jogador[playerid][Dinheiro] < 30000)  return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");

            pEmpresa[id][eEstoque]--;
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `mochila` = 1 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");
            Jogador[playerid][Mochila] = 1;
            Jogador[playerid][Dinheiro] -= 30000;
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou uma Mochila por R$30.000");
            EnviarDinheiroEmpresa(id, 5000); 
        }

        // Gps
        case 2:
        {
            if(Jogador[playerid][Gps] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui um GPS");
            if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de gps nessa empresa");
            if(Jogador[playerid][Dinheiro] < 5000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            pEmpresa[id][eEstoque]--;

            new Enviar[128];
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Gps` = 1 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");
            Jogador[playerid][Gps] = true;
            Jogador[playerid][Dinheiro] -= 5000;
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou um GPS por R$5.000");
            EnviarDinheiroEmpresa(id, 5000); 
        }

        // MP3
        case 3:
        {
            if(Jogador[playerid][MP4] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui um MP3");
            if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de MP3 nessa empresa");
            if(Jogador[playerid][Dinheiro] < 3000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            
            pEmpresa[id][eEstoque]--;
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Mp4` = 1 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");
            Jogador[playerid][MP4] = true;
            Jogador[playerid][Dinheiro] -= 3000;
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou um MP3 por R$3.000");
            EnviarDinheiroEmpresa(id, 3000); 
        }

        // Sementes
        case 4:
        {
            if(Jogador[playerid][SementeFazenda] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você ainda possui sementes");
            if(Jogador[playerid][Dinheiro] < 3000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            Jogador[playerid][SementeFazenda] += 20;
            Jogador[playerid][Dinheiro] -= 3000;
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou 20 Sementes por R$3.000");
            EnviarDinheiroEmpresa(id, 3000); 
        }

        // Água
        case 5: Dialog_Show(playerid, AguaEmpresaComprar, DIALOG_STYLE_INPUT, "{FF0000}Loja de Utilitários", "{FFFFFF}Coloque abaixo a quantidade de água que você quer comprar, Cada água custa {32CD32}$30", "Comprar", "Fechar");
        case 6: Dialog_Show(playerid, CompraDeKitUtl, DIALOG_STYLE_INPUT, "{FF0000}Kit Reparos", "Coloque abaixo quantos kits você deseja comprar", "Comprar", "Cancelar");   
        case 7:
        {
            if(Jogador[playerid][RelogioUP] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui um Relogio UP");
            if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de Relogio UP nessa empresa");
            if(Jogador[playerid][Dinheiro] < 20000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            
            pEmpresa[id][eEstoque]--;
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `RelogioUP` = 1 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");
            Jogador[playerid][RelogioUP] = true;
            Jogador[playerid][Dinheiro] -= 20000;
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou um Relogio UP por R$20.000");
            EnviarDinheiroEmpresa(id, 20000);   
        }
        case 8:
        {
            if(Jogador[playerid][GalaoGasolina] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui um Galão de Combustível");
            if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de Galão nessa empresa");
            if(Jogador[playerid][Dinheiro] < 2000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            
            pEmpresa[id][eEstoque]--;
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Gasolina` = 1 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");
            Jogador[playerid][GalaoGasolina] = true;
            Jogador[playerid][Dinheiro] -= 2000;
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou um Galão de Combustível por R$2.000");
            EnviarDinheiroEmpresa(id, 2000);   
        }
        case 9:
        {
            if(Jogador[playerid][Dinheiro] < 1100) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            GivePlayerWeapon(playerid, 43, 50);
            Jogador[playerid][Dinheiro] -= 1100;
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou uma Câmera Fotográfica por R$1.100");
            EnviarDinheiroEmpresa(id, 1100);      
        }
        case 10: Dialog_Show(playerid, RaspberryComprar, DIALOG_STYLE_INPUT, "{FF0000}Loja de Utilitários", "{FFFFFF}Coloque abaixo quantos Raspberry você deseja", "Comprar", "Fechar");
        case 11:
        {
            new Dialog[700];
            for(new i=0; i < MAX_SLOT_VEH; i++)
            {
                if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0) 
                {
                    if(pVeiculo[playerid][i][VehConectado] == true) strcatEx(Dialog, "%d.\t%s\t{00FF00}Conectado\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
                    else strcatEx(Dialog, "%d.\t%s\t{FF0000}Deconectado\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
                }
                else strcatEx(Dialog, "%d.\t{FF0000}Nenhum Veículo\t{00FF00}N/A\n", i);  
            }
            Dialog_Show(playerid, ComprarTranca, DIALOG_STYLE_TABLIST, "{FF0000}Utilitários", Dialog, "Selecionar", "Fechar");  
        }
    }
    return 0;
}

Dialog:CompraDeKitUtl(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][KitReparos] >= 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de kits ( 5 )");
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de kit's nessa empresa");

    new Somazinha,
        PrecoX;

    if(Quantidade >= 5) Somazinha = Ponta(Jogador[playerid][KitReparos], Quantidade, 5);
    else Somazinha = Quantidade;
    PrecoX = 1500*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    EnviarDinheiroEmpresa(id, PrecoX); 
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    pEmpresa[id][eEstoque] -= 1;
    Jogador[playerid][KitReparos] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| LOJA | Você comprou {00BFFF}%d{FFFFFF} kits(s) por {32CD32}R$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:RaspberryComprar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Raspberry] >= 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de Raspberry(s) ( 5 )");
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de raspberry nessa empresa");

    new Somazinha,
        PrecoX;

    if(Quantidade >= 5) Somazinha = Ponta(Jogador[playerid][Raspberry], Quantidade, 5);
    else Somazinha = Quantidade;
    PrecoX = 1500*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    EnviarDinheiroEmpresa(id, PrecoX); 
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    pEmpresa[id][eEstoque] -= 1;
    Jogador[playerid][Raspberry] += Somazinha;  
    format(Mensagem, sizeof(Mensagem), "| LOJA | Você comprou {00BFFF}%d{FFFFFF} Raspberry(s) por {32CD32}R$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);

    return 1;
}

Dialog:CompraDeSms(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    switch(listitem)
    {
        case 0:
        {
            if(Jogador[playerid][Dinheiro] < 800) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Creditos` = 200 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");
            
            Jogador[playerid][Dinheiro] -= 800;
            Jogador[playerid][Creditos] = 200;
            EnviarDinheiroEmpresa(id, 800);
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou 200 créditos por R$800");
        }
        case 1:
        {
            if(Jogador[playerid][Dinheiro] < 1000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Creditos` = 300 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");

            Jogador[playerid][Dinheiro] -= 1000;
            Jogador[playerid][Creditos] = 300;
            EnviarDinheiroEmpresa(id, 1000);
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou 300 créditos por R$1.000");
        }
        case 2:
        {
            if(Jogador[playerid][Dinheiro] < 2500) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Creditos` = 500 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");

            Jogador[playerid][Dinheiro] -= 2500;
            Jogador[playerid][Creditos] = 500;
            EnviarDinheiroEmpresa(id, 2500);
            SendClientMessage(playerid, 0x32CD32FF, "| LOJA | Você comprou 500 créditos por R$2.500");
        }
    }
    return 0;
}

Dialog:AguaEmpresaComprar(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Quantidade;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(sscanf(inputtext, "d", Quantidade)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma quantidade inválida");
    if(Quantidade <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você adicionou uma valor inválido");
    if(Jogador[playerid][Agua] >= 20) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de águas ( 20 )");
    if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de água nessa empresa");

    new Somazinha,
        PrecoX;

    if(Quantidade >= 20) Somazinha = Ponta(Jogador[playerid][Agua], Quantidade, 20);
    else Somazinha = Quantidade;
    PrecoX = 30*Somazinha;
    if(Jogador[playerid][Dinheiro] < PrecoX) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= PrecoX;
    Jogador[playerid][Agua] += Somazinha;  
    pEmpresa[id][eEstoque] -= 1;
    EnviarDinheiroEmpresa(id, PrecoX);
    format(Mensagem, sizeof(Mensagem), "| LOJA | Você comprou {00BFFF}%d{FFFFFF} garrafa(s) de água(s) por {32CD32}R$%s", Somazinha, DinheiroSeparar(PrecoX));
    SendClientMessage(playerid, -1, Mensagem);
    return 0;
}


Dialog:ComprarTranca(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = listitem;
    if(pVeiculo[playerid][id][MeuVeiculoModelo] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há nenhum veículo nesse slot");
    if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Veículo não conectado!");
    if(pVeiculo[playerid][id][TemTranca] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse veículo já possui tranca");
    if(Jogador[playerid][Dinheiro] < 5000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui toda essa quantia em dinheiro");
    new idx = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(pEmpresa[idx][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de trancas nessa empresa");

    //new Float:EucPos[3],
    //    Float:VehcPos[3];
    //GetVehiclePos(pVeiculo[playerid][id][MeuVeiculoID], VehcPos[0], VehcPos[1], VehcPos[2]);
    //GetPlayerPos(playerid, EucPos[0], EucPos[1], EucPos[2]);
    //new distancia = GetDistanceBetweenPoints(VehcPos[0], VehcPos[1], VehcPos[2], EucPos[0], EucPos[1], EucPos[2]);
    //if(distancia > 60.0) return SendClientMessage(playerid, 0xFF4500FF, "| MECÂNICA | Traga seu veículo para mais perto da mecânica");
    Jogador[playerid][Dinheiro] -= 5000;
    pEmpresa[idx][eEstoque] -= 1;
    EnviarDinheiroEmpresa(idx, 5000);
    pVeiculo[playerid][id][TemTranca] = true;
    SendClientMessage(playerid, -1, "| LOJA | Você comprou uma tranca para seu veículo por {32CD32}$5.000");
    return 1;
}