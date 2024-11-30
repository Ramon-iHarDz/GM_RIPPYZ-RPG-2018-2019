#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 9; i++){
        CelularTransferencia[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

Dialog:BancoCelularNome(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    PlayerTextDrawSetString(playerid, CelularTransferencia[playerid][4], ConverterTexto(PegarNick(PegarIdPeloNickEx(inputtext))));
    SetPVarString(playerid, "BancoCelularNome", inputtext);
    return 1;
}

Dialog:BancoCelularValor(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(isnull(inputtext)) return 1;
    if(!ApenasNumeros(inputtext)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Valor Inválido");
    
    new vallor,
        pIINAS[50];
    sscanf(inputtext, "d", vallor);
    if(vallor > 200000) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você só pode transferir até R$200.000");
    format(pIINAS, sizeof(pIINAS), "$%s", DinheiroSeparar(vallor));
    PlayerTextDrawSetString(playerid, CelularTransferencia[playerid][5], ConverterTexto(pIINAS));
    SetPVarInt(playerid, "BancoCelularValor", vallor);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == CelularTransferencia[playerid][4]){
        Dialog_Show(playerid, BancoCelularNome, DIALOG_STYLE_INPUT, "{FF0000}Destinatário", "Coloque abaixo o nome para quem você quer enviar", "Confirmar", "Fechar");
        return 1;
    }
    else if(playertextid == CelularTransferencia[playerid][5]){
        Dialog_Show(playerid, BancoCelularValor, DIALOG_STYLE_INPUT, "{FF0000}Valor", "Coloque abaixo o valor que deseja transferir", "Confirmar", "Fechar");
        return 1;
    }
    else if(playertextid == CelularTransferencia[playerid][8])
    {
        new NomeBC[30],
            ValorBC = GetPVarInt(playerid, "BancoCelularValor");
        if(Jogador[playerid][DinheiroBanco] < ValorBC) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem todo esse valor");
        GetPVarString(playerid, "BancoCelularNome", NomeBC, sizeof(NomeBC));
        if(isnull(NomeBC)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não colocou um destinatário");
        if(ValorBC <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque um valor");
        new id = PegarIdPeloNickEx(NomeBC);
        if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Destinatário não localizado(a) ( Não Conectado(a) )");
        if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Destinatário não está disponível para receber transferencias");
        if(Jogador[id][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Destinatário não possui o aplicativo de transferencia");
        if(id == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode transferir para si mesmo");
        if(pTempo[playerid][TransferirCelular] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não pode transferir, aguarde.");
        if(ValorBC > 30000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode transferir mais de $30.000"); 

        new esID = Jogador[id][DinheiroBanco],
            esJogador = Jogador[playerid][DinheiroBanco];
        esID += ValorBC;
        esJogador -= ValorBC;

        if(!EnviarLogDinheiro(playerid, id, ValorBC, "Transferencia Celular")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao enviar o dinheiro"); 
        if(!AtualizarSaldoBancario(playerid, esJogador)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao transferir o dinheiro [0x1]"); 
        if(!AtualizarSaldoBancario(id, esID)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao transferir o dinheiro [0x2]"); 

        Jogador[id][DinheiroBanco] += ValorBC;
        Jogador[playerid][DinheiroBanco] -= ValorBC;
        pTempo[playerid][TransferirCelular] = gettime()+600;

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| TRANSFERÊNCIA | %s[%d] transferiu {32CD32}$%s{FFFFFF} via aplicativo para você", PegarNick(playerid), playerid, DinheiroSeparar(ValorBC));
        SendClientMessage(id, -1, Mensagem);

        format(Mensagem, sizeof(Mensagem), "| TRANSFERÊNCIA | Você transferiu {32CD32}$%s{FFFFFF} para %s[%d] via aplicativo", DinheiroSeparar(ValorBC), PegarNick(id), id);
        SendClientMessage(playerid, -1, Mensagem);

        OcultarCelularTransferencia(playerid);
        MostrarCelularBanco(playerid);
        return 1;
    }
    return 0;
}

function MostrarCelularTransferencia(playerid) 
{
    CelularTransferencia[playerid][0] = CreatePlayerTextDraw(playerid, 416.500946, 326.833343, "box");
    PlayerTextDrawLetterSize(playerid, CelularTransferencia[playerid][0], 0.000000, 0.963096);
    PlayerTextDrawTextSize(playerid, CelularTransferencia[playerid][0], 495.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularTransferencia[playerid][0], 1);
    PlayerTextDrawColor(playerid, CelularTransferencia[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularTransferencia[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, CelularTransferencia[playerid][0], 180);
    PlayerTextDrawSetShadow(playerid, CelularTransferencia[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularTransferencia[playerid][0], 255);
    PlayerTextDrawFont(playerid, CelularTransferencia[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CelularTransferencia[playerid][0], 1);

    CelularTransferencia[playerid][1] = CreatePlayerTextDraw(playerid, 416.500946, 354.833343, "box");
    PlayerTextDrawLetterSize(playerid, CelularTransferencia[playerid][1], 0.000000, 0.963096);
    PlayerTextDrawTextSize(playerid, CelularTransferencia[playerid][1], 495.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, CelularTransferencia[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularTransferencia[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CelularTransferencia[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, CelularTransferencia[playerid][1], 180);
    PlayerTextDrawSetShadow(playerid, CelularTransferencia[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularTransferencia[playerid][1], 255);
    PlayerTextDrawFont(playerid, CelularTransferencia[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, CelularTransferencia[playerid][1], 1);

    CelularTransferencia[playerid][2] = CreatePlayerTextDraw(playerid, 425.291748, 312.916687, "Destinario");
    PlayerTextDrawLetterSize(playerid, CelularTransferencia[playerid][2], 0.230863, 1.045832);
    PlayerTextDrawAlignment(playerid, CelularTransferencia[playerid][2], 1);
    PlayerTextDrawColor(playerid, CelularTransferencia[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularTransferencia[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, CelularTransferencia[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CelularTransferencia[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularTransferencia[playerid][2], 130);
    PlayerTextDrawFont(playerid, CelularTransferencia[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, CelularTransferencia[playerid][2], 1);

    CelularTransferencia[playerid][3] = CreatePlayerTextDraw(playerid, 425.291748, 341.716491, "Valor");
    PlayerTextDrawLetterSize(playerid, CelularTransferencia[playerid][3], 0.227584, 0.999166);
    PlayerTextDrawAlignment(playerid, CelularTransferencia[playerid][3], 1);
    PlayerTextDrawColor(playerid, CelularTransferencia[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, CelularTransferencia[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, CelularTransferencia[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, CelularTransferencia[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularTransferencia[playerid][3], 120);
    PlayerTextDrawFont(playerid, CelularTransferencia[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, CelularTransferencia[playerid][3], 1);

    CelularTransferencia[playerid][4] = CreatePlayerTextDraw(playerid, 421.691772, 326.416595, "Adicionar");
    PlayerTextDrawLetterSize(playerid, CelularTransferencia[playerid][4], 0.225710, 0.999165);
    PlayerTextDrawTextSize(playerid, CelularTransferencia[playerid][4], 494.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularTransferencia[playerid][4], 1);
    PlayerTextDrawColor(playerid, CelularTransferencia[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, CelularTransferencia[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, CelularTransferencia[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, CelularTransferencia[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularTransferencia[playerid][4], 255);
    PlayerTextDrawFont(playerid, CelularTransferencia[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, CelularTransferencia[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, CelularTransferencia[playerid][4], true);

    CelularTransferencia[playerid][5] = CreatePlayerTextDraw(playerid, 421.691772, 354.316406, "Adicionar");
    PlayerTextDrawLetterSize(playerid, CelularTransferencia[playerid][5], 0.225710, 0.999165);
    PlayerTextDrawTextSize(playerid, CelularTransferencia[playerid][5], 494.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularTransferencia[playerid][5], 1);
    PlayerTextDrawColor(playerid, CelularTransferencia[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, CelularTransferencia[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, CelularTransferencia[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, CelularTransferencia[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularTransferencia[playerid][5], 255);
    PlayerTextDrawFont(playerid, CelularTransferencia[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, CelularTransferencia[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, CelularTransferencia[playerid][5], true);

    CelularTransferencia[playerid][6] = CreatePlayerTextDraw(playerid, 415.358520, 342.249938, "hud:radar_cash");
    PlayerTextDrawTextSize(playerid, CelularTransferencia[playerid][6], 9.000000, 9.000000);
    PlayerTextDrawAlignment(playerid, CelularTransferencia[playerid][6], 1);
    PlayerTextDrawColor(playerid, CelularTransferencia[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, CelularTransferencia[playerid][6], 0);
    PlayerTextDrawBoxColor(playerid, CelularTransferencia[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, CelularTransferencia[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularTransferencia[playerid][6], 255);
    PlayerTextDrawFont(playerid, CelularTransferencia[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, CelularTransferencia[playerid][6], 0);

    CelularTransferencia[playerid][7] = CreatePlayerTextDraw(playerid, 415.358520, 314.350128, "hud:radar_light");
    PlayerTextDrawTextSize(playerid, CelularTransferencia[playerid][7], 9.000000, 9.000000);
    PlayerTextDrawAlignment(playerid, CelularTransferencia[playerid][7], 1);
    PlayerTextDrawColor(playerid, CelularTransferencia[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, CelularTransferencia[playerid][7], 0);
    PlayerTextDrawBoxColor(playerid, CelularTransferencia[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, CelularTransferencia[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularTransferencia[playerid][7], 255);
    PlayerTextDrawFont(playerid, CelularTransferencia[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, CelularTransferencia[playerid][7], 0);

    CelularTransferencia[playerid][8] = CreatePlayerTextDraw(playerid, 451.960205, 373.483337, "~>~");
    PlayerTextDrawLetterSize(playerid, CelularTransferencia[playerid][8], 0.453411, 1.675832);
    PlayerTextDrawTextSize(playerid, CelularTransferencia[playerid][8], 462.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, CelularTransferencia[playerid][8], 1);
    PlayerTextDrawColor(playerid, CelularTransferencia[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, CelularTransferencia[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, CelularTransferencia[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, CelularTransferencia[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularTransferencia[playerid][8], 255);
    PlayerTextDrawFont(playerid, CelularTransferencia[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, CelularTransferencia[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, CelularTransferencia[playerid][8], true);

    for(new i=0; i < 9; i++){
        PlayerTextDrawShow(playerid, CelularTransferencia[playerid][i]);
    }

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarCelularTransferencia");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarCelularBanco");
    return 1;
}

function OcultarCelularTransferencia(playerid)
{
    for(new i=0; i < 9; i++){
        PlayerTextDrawDestroy(playerid, CelularTransferencia[playerid][i]);
        CelularTransferencia[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    DeletePVar(playerid, "BancoCelularNome");
    DeletePVar(playerid, "BancoCelularValor");
    return 1;
}