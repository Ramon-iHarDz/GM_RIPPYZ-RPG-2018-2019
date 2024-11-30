#include <YSI_Coding\y_hooks>

new PlayerText:SaqueBanco[MAX_PLAYERS][6];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 6; i++){
        SaqueBanco[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarBancoSaque(playerid, bool:NoCaixa = false)
{
    if(NoCaixa == true)
    {
        MostrarBancoCapa(playerid);
        PlayerTextDrawSetString(playerid, BancoCapa[playerid][7], "ld_beat:cross");
        SetPVarString(playerid, "BankFechar", "OcultarBancoSaque");
        SetPVarString(playerid, "BankMostrar", "*");
    }
    else
    {
        SetPVarString(playerid, "BankFechar", "OcultarBancoSaque");
        SetPVarString(playerid, "BankMostrar", "MostrarBancoHome");
    }

    SaqueBanco[playerid][0] = CreatePlayerTextDraw(playerid, 319.281372, 192.283432, "Saque");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][0], 0.383144, 1.366664);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][0], 2);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][0], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][0], 3);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][0], 1);

    SaqueBanco[playerid][1] = CreatePlayerTextDraw(playerid, 248.750000, 226.816818, "box");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][1], 0.000000, 1.289999);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][1], 394.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][1], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, SaqueBanco[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, SaqueBanco[playerid][1], 107);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][1], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][1], 1);

    SaqueBanco[playerid][2] = CreatePlayerTextDraw(playerid, 248.750000, 226.616806, "box");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][2], 0.000000, 1.216999);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][2], 260.882080, 0.000000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][2], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, SaqueBanco[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, SaqueBanco[playerid][2], 107);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][2], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][2], 1);

    SaqueBanco[playerid][3] = CreatePlayerTextDraw(playerid, 249.931198, 226.800079, "hud:radar_cash");
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][3], 10.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][3], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][3], 255);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][3], 0);

    SaqueBanco[playerid][4] = CreatePlayerTextDraw(playerid, 266.374969, 226.883407, "Coloque_o_valor");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][4], 0.266732, 1.133330);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][4], 387.699920, 12.0000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][4], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, SaqueBanco[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, SaqueBanco[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][4], 61);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, SaqueBanco[playerid][4], true);

    SaqueBanco[playerid][5] = CreatePlayerTextDraw(playerid, 294.375000, 257.399658, "Confirmar");
    PlayerTextDrawLetterSize(playerid, SaqueBanco[playerid][5], 0.306723, 1.039998);
    PlayerTextDrawTextSize(playerid, SaqueBanco[playerid][5], 345.209838, 12.0000);
    PlayerTextDrawAlignment(playerid, SaqueBanco[playerid][5], 1);
    PlayerTextDrawColor(playerid, SaqueBanco[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, SaqueBanco[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, SaqueBanco[playerid][5], 8388660);
    PlayerTextDrawSetShadow(playerid, SaqueBanco[playerid][5], 1);
    PlayerTextDrawBackgroundColor(playerid, SaqueBanco[playerid][5], 61);
    PlayerTextDrawFont(playerid, SaqueBanco[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, SaqueBanco[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, SaqueBanco[playerid][5], true);

    for(new i=0; i < 6; i++){
        PlayerTextDrawShow(playerid, SaqueBanco[playerid][i]);
    }

    DeletePVar(playerid, "ValorSaque");
    return 1;
}

function OcultarBancoSaque(playerid)
{
    for(new i=0; i < 6; i++){
        PlayerTextDrawDestroy(playerid, SaqueBanco[playerid][i]);
        SaqueBanco[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == SaqueBanco[playerid][4]) Dialog_Show(playerid, SaqueDialog, DIALOG_STYLE_INPUT, "{FF0000}Saque", "Coloque abaixo o valor na qual deseja sacar", "Confirmar", "Cancelar");
    else if(playertextid == SaqueBanco[playerid][5])
    {
        new Valor = GetPVarInt(playerid, "ValorSaque");
        if(Valor == 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Selecione um valor!");
        if(Jogador[playerid][DinheiroBanco] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro suficiente");
        if(Valor > Jogador[playerid][DinheiroBanco]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não possui todo esse valor");

        new rrD = Jogador[playerid][DinheiroBanco];
        rrD -= Valor;

        if(!EnviarLogDinheiro(playerid, -1, Valor, "Retirou Dinheiro")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao retirar o dinheiro"); 
        if(!AtualizarSaldoBancario(playerid, rrD)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Ocorreu um problema ao retirar o dinheiro [0x1]"); 

        Jogador[playerid][DinheiroBanco] -= Valor;
        Jogador[playerid][Dinheiro] += Valor;
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| AVISO | Você sacou {32CD32}$%s{FFFFFF} reais da sua conta bancária", DinheiroSeparar(Valor));
        SendClientMessage(playerid, -1, Mensagem);
        OcultarBanco(playerid);
    }
    return 0;
}