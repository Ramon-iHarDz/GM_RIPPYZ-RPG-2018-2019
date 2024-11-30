#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "EmLigacao") > 0){

        new id;
        if(GetPVarInt(playerid, "Chadsamm") == 1){
            id = GetPVarInt(playerid, "ChamadTempp");
            KillTimer(id);
        }
        id = GetPVarInt(playerid, "LigacaoID");
        RecusarChamada(playerid);
        RecusarChamada(id);
    }
    
    for(new i=0; i < 4; i++){
        CelularChamando[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    for(new i=0; i < 2; i++){
        LigacaoAndamento[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    return 1;
}

function MostrarCelularLigacao(playerid)
{
    LigacaoAndamento[playerid][0] = CreatePlayerTextDraw(playerid, 456.225189, 331.783843, "00:00");
    PlayerTextDrawLetterSize(playerid, LigacaoAndamento[playerid][0], 0.310980, 1.477500);
    PlayerTextDrawAlignment(playerid, LigacaoAndamento[playerid][0], 2);
    PlayerTextDrawColor(playerid, LigacaoAndamento[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, LigacaoAndamento[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, LigacaoAndamento[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, LigacaoAndamento[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, LigacaoAndamento[playerid][0], 80);
    PlayerTextDrawFont(playerid, LigacaoAndamento[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, LigacaoAndamento[playerid][0], 1);

    LigacaoAndamento[playerid][1] = CreatePlayerTextDraw(playerid, 448.660308, 355.083312, "ld_chat:thumbdn");
    PlayerTextDrawTextSize(playerid, LigacaoAndamento[playerid][1], 15.000000, 14.000000);
    PlayerTextDrawAlignment(playerid, LigacaoAndamento[playerid][1], 1);
    PlayerTextDrawColor(playerid, LigacaoAndamento[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, LigacaoAndamento[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, LigacaoAndamento[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, LigacaoAndamento[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, LigacaoAndamento[playerid][1], 255);
    PlayerTextDrawFont(playerid, LigacaoAndamento[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, LigacaoAndamento[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, LigacaoAndamento[playerid][1], true);

    for(new i=0; i < 2; i++){
        PlayerTextDrawShow(playerid, LigacaoAndamento[playerid][i]);
    }

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarLigacaoCelular");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarHome");
    return 1;
}

function MostrarCelularChamada(playerid)
{
    CelularChamando[playerid][0] = CreatePlayerTextDraw(playerid, 456.519500, 322.250091, "Desconhecido");
    PlayerTextDrawLetterSize(playerid, CelularChamando[playerid][0], 0.281463, 1.273333);
    PlayerTextDrawAlignment(playerid, CelularChamando[playerid][0], 2);
    PlayerTextDrawColor(playerid, CelularChamando[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, CelularChamando[playerid][0], 0);
    PlayerTextDrawBoxColor(playerid, CelularChamando[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, CelularChamando[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, CelularChamando[playerid][0], 80);
    PlayerTextDrawFont(playerid, CelularChamando[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, CelularChamando[playerid][0], 1);

    CelularChamando[playerid][1] = CreatePlayerTextDraw(playerid, 446.117858, 342.833312, "hud:radar_gangy");
    PlayerTextDrawTextSize(playerid, CelularChamando[playerid][1], 19.000000, 18.000000);
    PlayerTextDrawAlignment(playerid, CelularChamando[playerid][1], 1);
    PlayerTextDrawColor(playerid, CelularChamando[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, CelularChamando[playerid][1], 0);
    PlayerTextDrawBoxColor(playerid, CelularChamando[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, CelularChamando[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularChamando[playerid][1], 255);
    PlayerTextDrawFont(playerid, CelularChamando[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, CelularChamando[playerid][1], 0);

    CelularChamando[playerid][2] = CreatePlayerTextDraw(playerid, 427.718139, 381.232910, "ld_chat:thumbup");
    PlayerTextDrawTextSize(playerid, CelularChamando[playerid][2], 16.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, CelularChamando[playerid][2], 1);
    PlayerTextDrawColor(playerid, CelularChamando[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, CelularChamando[playerid][2], 0);
    PlayerTextDrawBoxColor(playerid, CelularChamando[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, CelularChamando[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularChamando[playerid][2], 255);
    PlayerTextDrawFont(playerid, CelularChamando[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, CelularChamando[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, CelularChamando[playerid][2], true);

    CelularChamando[playerid][3] = CreatePlayerTextDraw(playerid, 466.917541, 381.232910, "ld_chat:thumbdn");
    PlayerTextDrawTextSize(playerid, CelularChamando[playerid][3], 16.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, CelularChamando[playerid][3], 1);
    PlayerTextDrawColor(playerid, CelularChamando[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, CelularChamando[playerid][3], 0);
    PlayerTextDrawBoxColor(playerid, CelularChamando[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, CelularChamando[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, CelularChamando[playerid][3], 255);
    PlayerTextDrawFont(playerid, CelularChamando[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, CelularChamando[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, CelularChamando[playerid][3], true);

    for(new i=0; i < 4; i++){
        PlayerTextDrawShow(playerid, CelularChamando[playerid][i]);
    }

    format(pCelularEx[playerid][PagOcultarCelular], 30, "OcultarChamada");
    format(pCelularEx[playerid][PagMostrarCelular], 30, "MostrarHome");
    return 1;
}

function OcultarChamada(playerid)
{
    for(new i=0; i < 4; i++){
        PlayerTextDrawDestroy(playerid, CelularChamando[playerid][i]);
        CelularChamando[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function OcultarLigacaoCelular(playerid)
{
    for(new i=0; i < 2; i++){
        PlayerTextDrawDestroy(playerid, LigacaoAndamento[playerid][i]);
        LigacaoAndamento[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function AtualizarTempoLigacao(playerid)
{
    if(GetPVarInt(playerid, "TempoEmLigacao") == 0) SetPVarInt(playerid, "JOIASDA", 0);
    SetPVarInt(playerid, "TempoEmLigacao", GetPVarInt(playerid, "TempoEmLigacao")+1);
    if(GetPVarInt(playerid, "EuChamando") == 1)
    {
        if(GetPVarInt(playerid, "JOIASDA") > GetPVarInt(playerid, "TempoEmLigacao"))
        {
            Jogador[playerid][Creditos]--;
            SetPVarInt(playerid, "JOIASDA", GetPVarInt(playerid, "JOIASDA")+20);
            if(Jogador[playerid][Creditos] <= 0)
            {
                new id = GetPVarInt(playerid, "LigacaoID");
                RecusarChamada(playerid);
                RecusarChamada(id);
                SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seus créditos acabaram");
            }
        }
    }
    PlayerTextDrawSetString(playerid, LigacaoAndamento[playerid][0], SegundosParaMinutos(GetPVarInt(playerid, "TempoEmLigacao"))); 
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    // Atender
    if(playertextid == CelularChamando[playerid][2]){
        new id = GetPVarInt(playerid, "LigacaoID");  
        AtenderLigacaoCelular(playerid);
        AtenderLigacaoCelular(id);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // Recusar
    else if(playertextid == CelularChamando[playerid][3]){
        new id = GetPVarInt(playerid, "LigacaoID");
        RecusarChamada(playerid);
        RecusarChamada(id);
        return Y_HOOKS_BREAK_RETURN_1;
    }

    // Desligar Ligação
    else if(playertextid == LigacaoAndamento[playerid][1]){
        new id = GetPVarInt(playerid, "LigacaoID");
        RecusarChamada(playerid);
        RecusarChamada(id); 
        return Y_HOOKS_BREAK_RETURN_1; 
    }
    return 0;
}