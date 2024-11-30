#include <YSI_Coding\y_hooks>

new PlayerText:BancoTransferencia[MAX_PLAYERS][9];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 9; i++){
        BancoTransferencia[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarBancoTransferencia(playerid)
{
    BancoTransferencia[playerid][0] = CreatePlayerTextDraw(playerid, 243.750000, 199.483444, "box");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][0], 0.000000, 1.449000);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][0], 397.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][0], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][0], 120);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][0], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][0], 1);

    BancoTransferencia[playerid][1] = CreatePlayerTextDraw(playerid, 243.750000, 225.383514, "box");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][1], 0.000000, 1.449000);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][1], 397.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][1], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][1], 120);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][1], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][1], 1);

    BancoTransferencia[playerid][2] = CreatePlayerTextDraw(playerid, 244.084915, 199.216659, "box");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][2], 0.000000, 1.426063);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][2], 256.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][2], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][2], 72);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][2], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][2], 1);

    BancoTransferencia[playerid][3] = CreatePlayerTextDraw(playerid, 296.574951, 257.016052, "Confirmar");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][3], 0.275157, 0.993330);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][3], 341.199951, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][3], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][3], 8388687);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][3], 61);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, BancoTransferencia[playerid][3], true);

    BancoTransferencia[playerid][4] = CreatePlayerTextDraw(playerid, 242.574996, 199.683288, "hud:radar_gangb");
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][4], 14.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][4], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][4], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][4], 0);

    BancoTransferencia[playerid][5] = CreatePlayerTextDraw(playerid, 244.084915, 225.416549, "box");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][5], 0.000000, 1.426063);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][5], 256.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][5], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][5], 72);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][5], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][5], 1);

    BancoTransferencia[playerid][6] = CreatePlayerTextDraw(playerid, 244.474990, 226.083175, "hud:radar_cash");
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][6], 12.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][6], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][6], 255);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][6], 0);

    BancoTransferencia[playerid][7] = CreatePlayerTextDraw(playerid, 262.149719, 200.166641, "Adicionar_nome_para_transferir");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][7], 0.203766, 1.185830);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][7], 389.199707, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][7], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][7], 61);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, BancoTransferencia[playerid][7], true);

    BancoTransferencia[playerid][8] = CreatePlayerTextDraw(playerid, 261.849731, 226.466522, "Adicionar_valor");
    PlayerTextDrawLetterSize(playerid, BancoTransferencia[playerid][8], 0.218918, 1.115829);
    PlayerTextDrawTextSize(playerid, BancoTransferencia[playerid][8], 387.899719, 12.0000);
    PlayerTextDrawAlignment(playerid, BancoTransferencia[playerid][8], 1);
    PlayerTextDrawColor(playerid, BancoTransferencia[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, BancoTransferencia[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, BancoTransferencia[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, BancoTransferencia[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, BancoTransferencia[playerid][8], 61);
    PlayerTextDrawFont(playerid, BancoTransferencia[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, BancoTransferencia[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, BancoTransferencia[playerid][8], true);

    for(new i=0; i < 9; i++){
        PlayerTextDrawShow(playerid, BancoTransferencia[playerid][i]);
    }

    SetPVarString(playerid, "BankFechar", "OcultarBancoTransferencia");
    SetPVarString(playerid, "BankMostrar", "MostrarBancoHome");

    return 1;
}

function OcultarBancoTransferencia(playerid)
{
    for(new i=0; i < 9; i++){
        PlayerTextDrawDestroy(playerid, BancoTransferencia[playerid][i]);
        BancoTransferencia[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == BancoTransferencia[playerid][7]) Dialog_Show(playerid, BancoNomeTransferencia, DIALOG_STYLE_INPUT, "{FF0000}Banco", "Coloque abaixo o nome do jogador(a)", "Confirmar", "Cancelar");
    else if(playertextid == BancoTransferencia[playerid][8]) Dialog_Show(playerid, BancoValorTransferencia, DIALOG_STYLE_INPUT, "{FF0000}Banco", "Coloque o valor que você quer transferir", "Confirmar", "Cancelar");
    else if(playertextid == BancoTransferencia[playerid][3])
    {
        if(Jogador[playerid][Level] < 50) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você só pode transferir a partir do level 50 ");
        if(pTempo[playerid][TransferirBanco] > gettime()){
            new hjh[128];
            format(hjh, sizeof(hjh), "| ERRO | Você precisa esperar %s para transferir", ConverterSegundos(pTempo[playerid][TransferirBanco]));
            SendClientMessage(playerid, 0xFF4500FF, hjh);
            return 1;
        }

        new UsuarioTrans[70],
            ValorTrans; 
        GetPVarString(playerid, "UsuarioBancoTrans", UsuarioTrans, sizeof(UsuarioTrans));
        ValorTrans = GetPVarInt(playerid, "ValorTransferencia");
        if(isnull(UsuarioTrans)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não selecionou um jogador(a) para transferir");
        if(!strcmp(UsuarioTrans, PegarNick(playerid), true)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode enviar dinheiro para si mesmo");
        if(ValorTrans == 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não colocou um valor para transferir");
        if(Jogador[playerid][DinheiroBanco] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem saldo no banco");
        if(ValorTrans > Jogador[playerid][DinheiroBanco]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem esse saldo no banco");
        if(!IsPlayerConnected(PegarIdPeloNick(UsuarioTrans))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não foi encontrado(a)");
        new id = PegarIdPeloNick(UsuarioTrans);
        if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Jogador(a) não está conectado(a)");
        if(Jogador[id][Level] < 50) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse(a) jogador(a) ainda não possui level 50 para transferir");
        // if(pTempo[id][TransferirBanco] > gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse(a) jogador(a) ainda não pode receber transferências");

        new esID = Jogador[id][DinheiroBanco],
            esJogador = Jogador[playerid][DinheiroBanco];
        esID += ValorTrans;
        esJogador -= ValorTrans;

        if(!EnviarLogDinheiro(playerid, id, ValorTrans, "Enviou Dinheiro")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao enviar o dinheiro"); 
        if(!AtualizarSaldoBancario(playerid, esJogador)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao transferir o dinheiro [0x1]"); 
        if(!AtualizarSaldoBancario(id, esID)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao transferir o dinheiro [0x2]"); 

        Jogador[id][DinheiroBanco] += ValorTrans;
        Jogador[playerid][DinheiroBanco] -= ValorTrans;
        pTempo[playerid][TransferirBanco] = gettime()+1800;

        new Mensagem[228];
        format(Mensagem, sizeof(Mensagem), "| TRANSFERÊNCIA | {FFFF00}%s[%d]{FFFFFF} transferiu {32CD32}$%s{FFFFFF} para sua conta bancária", PegarNick(playerid), playerid, DinheiroSeparar(ValorTrans));
        SendClientMessage(id, -1, Mensagem);

        format(Mensagem, sizeof(Mensagem), "| TRANSFERÊNCIA | Você transferiu {32CD32}$%s{FFFFFF} para conta bancária de {FFFF00}%s[%d]", DinheiroSeparar(ValorTrans), PegarNick(id), id);
        SendClientMessage(playerid, -1, Mensagem);

        OcultarBanco(playerid);
    }
    return 0;
}