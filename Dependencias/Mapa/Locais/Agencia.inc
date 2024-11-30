#include <YSI_Coding\y_hooks>

new AgenciaCheck,
    MafiaCheck
;

hook OnGameModeInit()
{
    // Npcs
    CreateDynamicActor(141, 359.7139, 173.6732, 1008.3893, 269.8000, 1, 100.0, 1302, 3, -1, 90.0); // Agência
    new MF = CreateDynamicActor(221, -1819.7426, 1144.9374, 45.4538, 269.3429, 1, 100.0, 0, 0, -1, 90.0); // Mafia
    ApplyDynamicActorAnimation(MF, "COP_AMBIENT", "Coplook_loop", 4.0, 1, 1, 1, 1, -1);

    // Checkpoints
    AgenciaCheck = CreateDynamicCP(362.1339,173.5684,1008.3828, 1.0, 1302, 3, -1, STREAMER_CP_SD, -1, 0);
    MafiaCheck = CreateDynamicCP(-1818.7631,1144.9487,45.4531, 1.0, 0, 0, -1, 20.0, -1, 0); 
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(Agencia[playerid][Pegou] == true)
    {
        DestroyDynamic3DTextLabelEx(Agencia[playerid][MensagemEmprego]);
        DestroyDynamicMapIconEx(Agencia[playerid][LocalMapa]);
        DestroyDynamicPickupEx(Agencia[playerid][Pickup]);
        new Limpar2[AgenciaJogador];
        Agencia[playerid] = Limpar2;
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid == AgenciaCheck)
    {
        new Dialog[300];
        strcat(Dialog, "{FFFFFF}Categorias\n");
        /*strcat(Dialog, "{00BFFF}» {FFFFFF}Honesta\n");
        strcat(Dialog, "{00BFFF}» {FFFFFF}Transporte\n");
        strcat(Dialog, "{00BFFF}» {FFFFFF}Governo\n");
        strcat(Dialog, "{00BFFF}» {FFFFFF}Servidor Público");*/
        strcat(Dialog, "{FFFFFF}Honestas\n");
        strcat(Dialog, "{FFFFFF}Transportes\n");
        strcat(Dialog, "{FFFFFF}Governo\n");
        strcat(Dialog, "{FFFFFF}Serviços Públicos");
        Dialog_Show(playerid, CategoriaEmprego, DIALOG_STYLE_TABLIST_HEADERS, "{FF4500}Categoria de Empregos", Dialog, "Selecionar", "Fechar"); 
    }

    else if(checkpointid == MafiaCheck)
    {
        new Contagem = 0,
            Dialog[2500]
        ;
        strcat(Dialog, "Cargo\tLevel\n");
        for(new i=0; i < sizeof(pAgencia); i++)
        {
            if(strcmp(pAgencia[i][Categoria], "Mafia")) continue;
            strcatEx(Dialog, "{FF6347}%s\t{00BFFF}%d\n", pAgencia[i][ProfissaoNome], pAgencia[i][Level]);
            Contagem++;
        }
        Dialog_Show(playerid, SelecionarEmpregoMafia, DIALOG_STYLE_TABLIST_HEADERS, "Cargos da Mafia", Dialog, "Selecionar", "Fechar");   
    }
    return 1;
}

Dialog:CategoriaEmprego(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Contagem = 0;
    new CategoriaS[70];
    new Dialog[900];
    switch(listitem)
    {
        case 0: CategoriaS = "Honestas";
        case 1: CategoriaS = "Transportes"; 
        case 2: CategoriaS = "Governo";
        case 3: CategoriaS = "Serviços Publicos";  
    }

    strcat(Dialog, "Profissão\tLevel\tSalário\n");
    for(new i=0; i < sizeof(pAgencia); i++)
    {
        if(strcmp(pAgencia[i][Categoria], CategoriaS)) continue;
        strcatEx(Dialog, "%s\t{00BFFF}%d\t{32CD32}$%s\n", pAgencia[i][ProfissaoNome], pAgencia[i][Level], DinheiroSeparar(pAgencia[i][Salario]));
        // if(pAgencia[i][Disponivel] == 1) strcatEx(Dialog, "%s\t{00BFFF}%d\t{32CD32}$%s\t{00FF00}Liberada\n", pAgencia[i][ProfissaoNome], pAgencia[i][Level], DinheiroSeparar(pAgencia[i][Salario]));
        // else if(pAgencia[i][Disponivel] == 0) strcatEx(Dialog, "%s\t{00BFFF}%d\t{32CD32}$%s\t{FF4500}Bloqueada\n", pAgencia[i][ProfissaoNome], pAgencia[i][Level], DinheiroSeparar(pAgencia[i][Salario]));
        Contagem++;
    }

    if(Contagem < 1){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa categoria está vázia!");
        return 1;
    }

    new Titulo[70];
    format(Titulo, sizeof(Titulo), "{FF4500}Categoria %s", CategoriaS);
    format(Agencia[playerid][Selecionado], 70, CategoriaS);
    Dialog_Show(playerid, SelecionarEmprego, DIALOG_STYLE_TABLIST_HEADERS, Titulo, Dialog, "Selecionar", "Fechar");     
    return 0;
}

Dialog:SelecionarEmprego(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Select = 0;
    for(new i=0; i < sizeof(pAgencia); i++)
    {
        if(strcmp(pAgencia[i][Categoria], Agencia[playerid][Selecionado])) continue;
        if(Select == listitem)
        {
            if(!strcmp(pAgencia[i][ProfissaoNome], "Corregedoria")){
                if(Jogador[playerid][Prisoes] < 300) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa de 300 prisões para pegar corregedoria");
            }
            if(pTempo[playerid][TrocaProfissao] > gettime())
            {
                new hjh[128];
                format(hjh, sizeof(hjh), "| ERRO | Você precisa esperar %s para trocar de profissão", ConverterSegundos(pTempo[playerid][TrocaProfissao]));
                SendClientMessage(playerid, 0xFF4500FF, hjh);
                return 1;
            }
            if(Jogador[playerid][Trabalhando] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço, devolva sua moto/uniforme ou conclua alguma entrega etc..!");
            if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            if(Jogador[playerid][Level] < pAgencia[i][Level] && ServidorBeta == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem level suficiente!");
            if(!strcmp(Jogador[playerid][Profissao], pAgencia[i][ProfissaoNome])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está nessa profissão!");
            if(pAgencia[i][Disponivel] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa profissão está bloqueada pelo desenvolvedor!");
            SetPlayerEmprego(playerid, "Desempregado");

            // Caso eu ja tenha selecionado algum
            if(Agencia[playerid][Pegou] == true)
            {
                DestroyDynamic3DTextLabelEx(Agencia[playerid][MensagemEmprego]);
                DestroyDynamicMapIconEx(Agencia[playerid][LocalMapa]);
                DestroyDynamicPickupEx(Agencia[playerid][Pickup]);
            }

            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "{00BFFF}%s\n{FFFFFF}Digite {FF8C00}/Trabalhar{FFFFFF} aqui para confirmar", pAgencia[i][ProfissaoNome]);
            Agencia[playerid][Pegou] = true;
            Agencia[playerid][Pickup] = CreateDynamicPickup(1210, 1, pAgencia[i][HQx], pAgencia[i][HQy], pAgencia[i][HQz], 0, 0, playerid, 70.0);
            Agencia[playerid][LocalMapa] = CreateDynamicMapIcon(pAgencia[i][HQx], pAgencia[i][HQy], pAgencia[i][HQz], 37, -1, 0, 0, playerid, -1, MAPICON_GLOBAL, -1, 0);
            Agencia[playerid][MensagemEmprego] = CreateDynamic3DTextLabel(Mensagem, -1, pAgencia[i][HQx], pAgencia[i][HQy], pAgencia[i][HQz], 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, playerid);
            Agencia[playerid][EmpregoID] = i;
            Agencia[playerid][ComandoAG] = 1;

            format(Mensagem, sizeof(Mensagem), "{FFFFFF}Você foi encaminhado(a) pela agência de empregos ( {00BFFF}%s{FFFFFF} )", pAgencia[i][ProfissaoNome]);
            Dialog_Show(playerid, SemFuiconalidade, DIALOG_STYLE_MSGBOX, "{FF0000}Agência de Empregos", Mensagem, "Fechar", "");
            SendClientMessage(playerid, -1, "| AGÊNCIA | Siga a interrogação marcada no mapa");
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            break;
        }
        Select++; 
    } 
    return 0; 
}

Dialog:SelecionarEmpregoMafia(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Select = 0;
    for(new i=0; i < sizeof(pAgencia); i++)
    {
        if(strcmp(pAgencia[i][Categoria], "Mafia")) continue;
        if(Select == listitem)
        {
            if(pTempo[playerid][TrocaProfissao] > gettime())
            {
                new hjh[128];
                format(hjh, sizeof(hjh), "| ERRO | Você precisa esperar %s para trocar de cargo", ConverterSegundos(pTempo[playerid][TrocaProfissao]));
                SendClientMessage(playerid, 0xFF4500FF, hjh);
                return 1;
            }
            if(Jogador[playerid][Experiencia] > 4) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa upar antes de trocar de profissão");
            if(Jogador[playerid][Trabalhando] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço, devolva sua moto/uniforme ou conclua alguma entrega etc..!");
            if(Jogador[playerid][Level] < pAgencia[i][Level] && ServidorBeta == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem level suficiente!");
            if(!strcmp(Jogador[playerid][Profissao], pAgencia[i][ProfissaoNome])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está nesse cargo!");
            if(pAgencia[i][Disponivel] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa cargo está bloqueada pelo desenvolvedor!");
            SetPlayerEmprego(playerid, "Desempregado");

            // Caso eu ja tenha selecionado algum
            if(Agencia[playerid][Pegou] == true)
            {
                DestroyDynamic3DTextLabelEx(Agencia[playerid][MensagemEmprego]);
                DestroyDynamicMapIconEx(Agencia[playerid][LocalMapa]);
                DestroyDynamicPickupEx(Agencia[playerid][Pickup]);
            }

            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "{FF6347}%s\n{FFFFFF}Digite {FF8C00}/Mafia{FFFFFF} aqui para confirmar", pAgencia[i][ProfissaoNome]);
            Agencia[playerid][Pegou] = true;
            Agencia[playerid][Pickup] = CreateDynamicPickup(1210, 1, pAgencia[i][HQx], pAgencia[i][HQy], pAgencia[i][HQz], 0, 0, playerid, 70.0);
            Agencia[playerid][LocalMapa] = CreateDynamicMapIcon(pAgencia[i][HQx], pAgencia[i][HQy], pAgencia[i][HQz], 19, -1, 0, 0, playerid, -1, MAPICON_GLOBAL, -1, 0);
            Agencia[playerid][MensagemEmprego] = CreateDynamic3DTextLabel(Mensagem, -1, pAgencia[i][HQx], pAgencia[i][HQy], pAgencia[i][HQz], 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, playerid);
            Agencia[playerid][EmpregoID] = i;
            Agencia[playerid][ComandoAG] = 2;

            format(Mensagem, sizeof(Mensagem), "{FFFFFF}Você passou pelo teste na mafia, siga a bandeira vermelha para confirmar {CCCCCC}%s", pAgencia[i][ProfissaoNome]);
            Dialog_Show(playerid, SemFuiconalidade, DIALOG_STYLE_MSGBOX, "{FF0000}Crime", Mensagem, "Fechar", "");
            SendClientMessage(playerid, -1, "| CRIME | Siga a bandeira marcada no mapa");
            PlayerPlaySound(playerid, 1057, 0, 0, 0);
            break;
        }
        Select++;
    } 
    return 0; 
}

CMD:trabalhar(playerid)
{
    if(Agencia[playerid][Pegou] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não foi contratado(a) por nenhuma profissão!");
    new id = Agencia[playerid][EmpregoID];
    if(Agencia[playerid][ComandoAG] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Mafia");
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, pAgencia[id][HQx], pAgencia[id][HQy], pAgencia[id][HQz])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no local encaminhado!");
    
    format(Jogador[playerid][Profissao], 70, pAgencia[id][ProfissaoNome]);
    SetPlayerEmprego(playerid, Jogador[playerid][Profissao]);
    
    if(ServidorBeta == false) pTempo[playerid][TrocaProfissao] = gettime()+3600;

    DestroyDynamic3DTextLabelEx(Agencia[playerid][MensagemEmprego]);
    DestroyDynamicMapIconEx(Agencia[playerid][LocalMapa]);
    DestroyDynamicPickupEx(Agencia[playerid][Pickup]);
    new Limpar2[AgenciaJogador];
    Agencia[playerid] = Limpar2;

    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| PROFISSÃO | Você foi contratado(a) como {00BFFF}%s", pAgencia[id][ProfissaoNome]);
    SendClientMessage(playerid, -1, Mensagem);
    SendClientMessage(playerid, -1, "| PROFISSÃO | Use: /Profissao para visualizar seus comandos!");
    return 1;
}

CMD:mafia(playerid)
{
    if(Agencia[playerid][Pegou] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não foi encaminhado(a) pela mafia");
    new id = Agencia[playerid][EmpregoID];
    if(Agencia[playerid][ComandoAG] != 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Trabalhar");
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, pAgencia[id][HQx], pAgencia[id][HQy], pAgencia[id][HQz])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está no local encaminhado!");
    
    format(Jogador[playerid][Profissao], 70, pAgencia[id][ProfissaoNome]);
    SetPlayerEmprego(playerid, Jogador[playerid][Profissao]);
    
    if(ServidorBeta == false) pTempo[playerid][TrocaProfissao] = gettime()+3600;

    DestroyDynamic3DTextLabelEx(Agencia[playerid][MensagemEmprego]);
    DestroyDynamicMapIconEx(Agencia[playerid][LocalMapa]);
    DestroyDynamicPickupEx(Agencia[playerid][Pickup]);
    new Limpar2[AgenciaJogador];
    Agencia[playerid] = Limpar2;

    new Mensagem[200];
    format(Mensagem, sizeof(Mensagem), "| CRIME | Você foi agora é aliado(a) do(a) mafia ( {FF4500}%s{FFFFFF} )", pAgencia[id][ProfissaoNome]);
    SendClientMessage(playerid, -1, Mensagem);
    SendClientMessage(playerid, -1, "| CRIME | Use: /Anotacao para visualizar seus comandos!");
    return 1;
}