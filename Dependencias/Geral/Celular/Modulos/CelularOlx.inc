#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 6; i++){
        CelularOlx[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function MostrarOlx(playerid)
{
    CelularOlx[playerid][0] = CreatePlayerTextDraw(playerid, 410.895690, 296.733093, "box");
    PlayerTextDrawLetterSize(playerid, CelularOlx[playerid][0], 0.000000, 13.427821);
    PlayerTextDrawTextSize(playerid, CelularOlx[playerid][0], 500.299865, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularOlx[playerid][0], 1);
    PlayerTextDrawColor(playerid, CelularOlx[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularOlx[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CelularOlx[playerid][0], 512819199);
    PlayerTextDrawSetShadow(playerid, CelularOlx[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularOlx[playerid][0], 255);
    PlayerTextDrawFont(playerid, CelularOlx[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CelularOlx[playerid][0], 1);

    CelularOlx[playerid][1] = CreatePlayerTextDraw(playerid, 422.383941, 307.999938, "box");
    PlayerTextDrawLetterSize(playerid, CelularOlx[playerid][1], 0.000000, 1.144950);
    PlayerTextDrawTextSize(playerid, CelularOlx[playerid][1], 490.999847, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularOlx[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularOlx[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CelularOlx[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, CelularOlx[playerid][1], 471604272);
    PlayerTextDrawSetShadow(playerid, CelularOlx[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularOlx[playerid][1], 255);
    PlayerTextDrawFont(playerid, CelularOlx[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CelularOlx[playerid][1], 1);

    CelularOlx[playerid][2] = CreatePlayerTextDraw(playerid, 457.093719, 308.300079, "OLX");
    PlayerTextDrawLetterSize(playerid, CelularOlx[playerid][2], 0.211186, 0.999166);
    PlayerTextDrawTextSize(playerid, CelularOlx[playerid][2], 0.000000, 70.000000);
    PlayerTextDrawAlignment(playerid, CelularOlx[playerid][2], 2);
    PlayerTextDrawColor(playerid, CelularOlx[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularOlx[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, CelularOlx[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CelularOlx[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularOlx[playerid][2], 90);
    PlayerTextDrawFont(playerid, CelularOlx[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CelularOlx[playerid][2], 1);

    CelularOlx[playerid][3] = CreatePlayerTextDraw(playerid, 430.819549, 340.416992, "Anunciar");
    PlayerTextDrawLetterSize(playerid, CelularOlx[playerid][3], 0.369546, 1.529999);
    PlayerTextDrawTextSize(playerid, CelularOlx[playerid][3], 482.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularOlx[playerid][3], 1);
    PlayerTextDrawColor(playerid, CelularOlx[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, CelularOlx[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, CelularOlx[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, CelularOlx[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularOlx[playerid][3], 90);
    PlayerTextDrawFont(playerid, CelularOlx[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, CelularOlx[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, CelularOlx[playerid][3], true);

    CelularOlx[playerid][4] = CreatePlayerTextDraw(playerid, 430.556640, 362.916839, "Anuncios");
    PlayerTextDrawLetterSize(playerid, CelularOlx[playerid][4], 0.369546, 1.529999);
    PlayerTextDrawTextSize(playerid, CelularOlx[playerid][4], 481.400024, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularOlx[playerid][4], 1);
    PlayerTextDrawColor(playerid, CelularOlx[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, CelularOlx[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, CelularOlx[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, CelularOlx[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularOlx[playerid][4], 90);
    PlayerTextDrawFont(playerid, CelularOlx[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, CelularOlx[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, CelularOlx[playerid][4], true);

    CelularOlx[playerid][5] = CreatePlayerTextDraw(playerid, 420.354583, 307.099914, "hud:radar_enemyattack");
    PlayerTextDrawTextSize(playerid, CelularOlx[playerid][5], 12.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, CelularOlx[playerid][5], 1);
    PlayerTextDrawColor(playerid, CelularOlx[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, CelularOlx[playerid][5], 0);
    PlayerTextDrawBoxColor(playerid, CelularOlx[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, CelularOlx[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularOlx[playerid][5], 255);
    PlayerTextDrawFont(playerid, CelularOlx[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, CelularOlx[playerid][5], 0);

    for(new i=0; i < 6; i++){
        PlayerTextDrawShow(playerid, CelularOlx[playerid][i]);
    }

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarOlx");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarHome");
    return 1;
}

function OcultarOlx(playerid)
{
    for(new i=0; i < 6; i++){
        PlayerTextDrawDestroy(playerid, CelularOlx[playerid][i]);
        CelularOlx[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

Dialog:MenuVendaAnunc(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: // Casa
        {
            new id = MinhaCasaID(playerid);
            if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma casa");
            if(strcmp(pCasa[id][cDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é dono(a) da casa");
            SetPVarInt(playerid, "OlxID", id);

            new Dialog[28];
            strcat(Dialog, "Alugando Casa\n");
            strcat(Dialog, "Vendendo Casa");
            Dialog_Show(playerid, VendaCasaOlx, DIALOG_STYLE_TABLIST, "{FF0000}Olx", Dialog, "Selecionar", "Fechar");
        }
        case 1: // Empresa
        {
            new id = MinhaEmpresaID(playerid);
            if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma empresa");
            if(strcmp(pEmpresa[id][eDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é dono(a) da empresa");
            SetPVarInt(playerid, "OlxID", id);

            new Dialog[90];
            strcat(Dialog, "Contratando Funcionário(a)\n");
            strcat(Dialog, "Vendendo Empresa");
            Dialog_Show(playerid, VendaEmpresaOlx, DIALOG_STYLE_TABLIST, "{FF0000}Olx", Dialog, "Selecionar", "Fechar");
        }
        case 2: // Veículos
        {
            new dd = 1;
            if(dd == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Desenvolvedor ainda não ativou essa opção");
            new Dialog[700];
            strcat(Dialog, "ID\tModelo\tStatus\n");
            for(new i=0; i < MAX_SLOT_VEH; i++)
            {
                if(pVeiculo[playerid][i][MeuVeiculoModelo] < 1) strcatEx(Dialog, "%d.\t{FF0000}Nenhum Veículo\t{FF0000}N/A\n", i+1); 
                else if(pVeiculo[playerid][i][VehConectado] == true) strcatEx(Dialog, "%d.\t%s\t{00FF00}Conectado\n", i+1, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
                else strcatEx(Dialog, "%d.\t%s\t{FF0000}Deconectado\n", i+1, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
            }
            Dialog_Show(playerid, VendaVehOlx, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Olx", Dialog, "Selecionar", "Fechar");
        }
    }
    return 1;
}

Dialog:VendaCasaOlx(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 1: Dialog_Show(playerid, AnuncioCasa, DIALOG_STYLE_INPUT, "{FF0000}Olx", "Coloque uma mensagem abaixo informando sobre valores ou algo do gênero", "Selecionar", "Fechar");
    }
    return 1;
}

Dialog:VendaEmpresaOlx(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, AnuncioFuncionario, DIALOG_STYLE_INPUT, "{FF0000}Olx", "Coloque uma mensagem abixo alguma mensagem para seu post", "Selecionar", "Fechar");
        case 1: Dialog_Show(playerid, AnuncioEmpresa, DIALOG_STYLE_INPUT, "{FF0000}Olx", "Coloque uma mensagem abaixo informando sobre valores ou algo do gênero", "Selecionar", "Fechar");
    }
    return 1;
}

Dialog:AnuncioCasa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 128) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Mensagem muito longa. ( Max: 128 )");

    new id = GetPVarInt(playerid, "OlxID");
    if(pCasa[id][cJPreco] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua casa não está a venda");

    pTempo[playerid][AnunciarOlx] = gettime()+(2*3600);
    return 1;
}

Dialog:AnuncioEmpresa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 128) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Mensagem muito longa. ( Max: 128 )");

    new id = GetPVarInt(playerid, "OlxID");
    if(pEmpresa[id][eJPreco] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua empresa não está a venda");

    pTempo[playerid][AnunciarOlx] = gettime()+(2*3600);
    return 1;
}

Dialog:AnuncioFuncionario(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(strlen(inputtext) > 128) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Mensagem muito longa. ( Max: 128 )");

    pTempo[playerid][AnunciarOlx] = gettime()+(2*3600);
    return 1;
}

Dialog:VendaVehOlx(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new id = listitem;
    if(pVeiculo[playerid][id][MeuVeiculoModelo] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhum veículo nesse slot");
    pTempo[playerid][AnunciarOlx] = gettime()+(2*3600);        

    // Notificação no discord

    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == CelularOlx[playerid][3])
    {
        if(pTempo[playerid][AnunciarOlx] > gettime()){
            new Mensagem[45];
            format(Mensagem, sizeof(Mensagem), "| ERRO | Você só pode anunciar em %s", SegundosParaMinutosEx(pTempo[playerid][AnunciarOlx]-gettime()));
            SendClientMessage(playerid, 0xFF4500FF, Mensagem);
            return 1;
        }
        new Dialog[35];
        strcat(Dialog, "Casa\n");
        strcat(Dialog, "Empresa\n");
        strcat(Dialog, "Veículos");
        Dialog_Show(playerid, MenuVendaAnunc, DIALOG_STYLE_TABLIST, "{FF0000}Vendas [OLX]", Dialog, "Selecionar", "Fechar");
    }
    else if(playertextid == CelularOlx[playerid][4]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Visualize o discord para obter essas informações");
    return 1;
}