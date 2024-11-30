#include <YSI_Coding\y_hooks>

new PlayerText:DepositoBanco[MAX_PLAYERS][6];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 6; i++){
        DepositoBanco[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarBancoDeposito(playerid)
{
    DepositoBanco[playerid][0] = CreatePlayerTextDraw(playerid, 319.281372, 192.283432, "Depositar");
    PlayerTextDrawLetterSize(playerid, DepositoBanco[playerid][0], 0.383144, 1.366664);
    PlayerTextDrawAlignment(playerid, DepositoBanco[playerid][0], 2);
    PlayerTextDrawColor(playerid, DepositoBanco[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, DepositoBanco[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, DepositoBanco[playerid][0], 255);
    PlayerTextDrawFont(playerid, DepositoBanco[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, DepositoBanco[playerid][0], 1);

    DepositoBanco[playerid][1] = CreatePlayerTextDraw(playerid, 248.750000, 226.816818, "box");
    PlayerTextDrawLetterSize(playerid, DepositoBanco[playerid][1], 0.000000, 1.289999);
    PlayerTextDrawTextSize(playerid, DepositoBanco[playerid][1], 394.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, DepositoBanco[playerid][1], 1);
    PlayerTextDrawColor(playerid, DepositoBanco[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, DepositoBanco[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, DepositoBanco[playerid][1], 107);
    PlayerTextDrawSetShadow(playerid, DepositoBanco[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, DepositoBanco[playerid][1], 255);
    PlayerTextDrawFont(playerid, DepositoBanco[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, DepositoBanco[playerid][1], 1);

    DepositoBanco[playerid][2] = CreatePlayerTextDraw(playerid, 248.750000, 226.616806, "box");
    PlayerTextDrawLetterSize(playerid, DepositoBanco[playerid][2], 0.000000, 1.216999);
    PlayerTextDrawTextSize(playerid, DepositoBanco[playerid][2], 260.882080, 0.000000);
    PlayerTextDrawAlignment(playerid, DepositoBanco[playerid][2], 1);
    PlayerTextDrawColor(playerid, DepositoBanco[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, DepositoBanco[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, DepositoBanco[playerid][2], 107);
    PlayerTextDrawSetShadow(playerid, DepositoBanco[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, DepositoBanco[playerid][2], 255);
    PlayerTextDrawFont(playerid, DepositoBanco[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, DepositoBanco[playerid][2], 1);

    DepositoBanco[playerid][3] = CreatePlayerTextDraw(playerid, 249.931198, 226.800079, "hud:radar_cash");
    PlayerTextDrawTextSize(playerid, DepositoBanco[playerid][3], 10.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, DepositoBanco[playerid][3], 1);
    PlayerTextDrawColor(playerid, DepositoBanco[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, DepositoBanco[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, DepositoBanco[playerid][3], 255);
    PlayerTextDrawFont(playerid, DepositoBanco[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, DepositoBanco[playerid][3], 0);

    DepositoBanco[playerid][4] = CreatePlayerTextDraw(playerid, 266.374969, 226.883407, "Coloque_o_valor");
    PlayerTextDrawLetterSize(playerid, DepositoBanco[playerid][4], 0.266732, 1.133330);
    PlayerTextDrawTextSize(playerid, DepositoBanco[playerid][4], 387.699920, 12.0000);
    PlayerTextDrawAlignment(playerid, DepositoBanco[playerid][4], 1);
    PlayerTextDrawColor(playerid, DepositoBanco[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, DepositoBanco[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, DepositoBanco[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, DepositoBanco[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, DepositoBanco[playerid][4], 61);
    PlayerTextDrawFont(playerid, DepositoBanco[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, DepositoBanco[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, DepositoBanco[playerid][4], true);

    DepositoBanco[playerid][5] = CreatePlayerTextDraw(playerid, 294.375000, 257.399658, "Confirmar");
    PlayerTextDrawLetterSize(playerid, DepositoBanco[playerid][5], 0.306723, 1.039998);
    PlayerTextDrawTextSize(playerid, DepositoBanco[playerid][5], 345.209838, 12.0000);
    PlayerTextDrawAlignment(playerid, DepositoBanco[playerid][5], 1);
    PlayerTextDrawColor(playerid, DepositoBanco[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, DepositoBanco[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, DepositoBanco[playerid][5], 8388660);
    PlayerTextDrawSetShadow(playerid, DepositoBanco[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, DepositoBanco[playerid][5], 61);
    PlayerTextDrawFont(playerid, DepositoBanco[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, DepositoBanco[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, DepositoBanco[playerid][5], true);

    for(new i=0; i < 6; i++){
        PlayerTextDrawShow(playerid, DepositoBanco[playerid][i]);
    }

    DeletePVar(playerid, "ValorDeposito");
    SetPVarString(playerid, "BankFechar", "OcultarBancoDeposito");
    SetPVarString(playerid, "BankMostrar", "MostrarBancoHome");

    return 1;
}

function OcultarBancoDeposito(playerid)
{
    for(new i=0; i < 6; i++){
        PlayerTextDrawDestroy(playerid, DepositoBanco[playerid][i]);
        DepositoBanco[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == DepositoBanco[playerid][4]) Dialog_Show(playerid, DepositoDialog, DIALOG_STYLE_INPUT, "{FF0000}Deposito", "Coloque abaixo o valor na qual deseja depositar", "Confirmar", "Cancelar");
    else if(playertextid == DepositoBanco[playerid][5])
    {
        new Valor = GetPVarInt(playerid, "ValorDeposito");
        if(Valor == 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Selecione um valor!");
        if(Valor > Jogador[playerid][Dinheiro]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não possui todo esse valor!");

        new rrD = Jogador[playerid][DinheiroBanco];
        rrD += Valor;

        if(!EnviarLogDinheiro(playerid, -1, Valor, "Depositou Dinheiro")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao depositar o dinheiro"); 
        if(!AtualizarSaldoBancario(playerid, rrD)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao depositar o dinheiro [0x1]"); 

        Jogador[playerid][DinheiroBanco] += Valor;
        Jogador[playerid][Dinheiro] -= Valor;
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| AVISO | Você depositou {32CD32}$%s{FFFFFF} reais na sua conta bancária", DinheiroSeparar(Valor));
        SendClientMessage(playerid, -1, Mensagem);
        OcultarBanco(playerid);
    }
    return 0;
}