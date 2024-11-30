#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicMapIcon(561.2976,-1506.6814,14.5479, 34, -1, 0, 0, -1, 120.0, MAPICON_LOCAL, -1);
    CreateDynamicPickup(1239, 1, 561.2976,-1506.6814,14.5479, 0, 0, -1, 40.0, -1);
    CreateDynamic3DTextLabel("{00BFFF}iRippzy{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para entrar", -1, 561.2976,-1506.6814,14.5479, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 20.0, -1);

    CreateDynamic3DTextLabel("{00BFFF}Atendimento{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para comprar", -1, -31.3416,42.2726,1003.8708, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 2612, 4, -1, 40.0, -1);

    new id[2];
    id[0] = CreateDynamicActor(163, 561.8433,-1504.5173,14.5377,87.7683, 1, 100.0, 0, 0, -1, 200.0, -1, 0);
    id[1] = CreateDynamicActor(164, 561.6607,-1509.0081,14.5605,91.2925, 1, 100.0, 0, 0, -1, 200.0, -1, 0);
    ApplyDynamicActorAnimation(id[0], "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);
    ApplyDynamicActorAnimation(id[1], "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);

    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, -31.3416,42.2726,1003.8708) && GetPlayerVirtualWorld(playerid) == 2612 && GetPlayerInterior(playerid) == 4 && Jogador[playerid][uInteriorEx] == 4574)
        {
            new Dialog[160];
            strcat(Dialog, "Opção\tPreço\n");
            strcat(Dialog, "Telefone\t{32CD32}$6.500\n");
            strcat(Dialog, "Notebook\t{32CD32}$9.250\n");
            strcat(Dialog, "Televisão\t{32CD32}$4.100\n");
            strcat(Dialog, "Fone bluetooth\t{32CD32}$4.100\n");
            strcat(Dialog, "Chip\t{32CD32}$180\n");
            Dialog_Show(playerid, iRippzyMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}iRippzy", Dialog, "Comprar", "Fechar");
        }
        return 1;
    }
    if(newkeys != KEY_SECONDARY_ATTACK || GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;

    // Entrada
    if(IsPlayerInRangeOfPoint(playerid, 2.0, 561.2976,-1506.6814,14.5479) && GetPlayerVirtualWorld(playerid) == 0 && GetPlayerInterior(playerid) == 0)
    {
        TogglePlayerControllable(playerid, 0);
        Jogador[playerid][uInteriorEx] = 4574;
        GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
        SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);
        SetPlayerPos(playerid, -31.4049,26.9201,1003.8708);
        SetPlayerInterior(playerid, 4);
        SetPlayerVirtualWorld(playerid, 2612);
        SetTimerEx("Destravar", 3000, false, "d", playerid);
    }

    // Saída
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, -31.4049,26.9201,1003.8708) && GetPlayerVirtualWorld(playerid) == 2612 && GetPlayerInterior(playerid) == 4 && Jogador[playerid][uInteriorEx] == 4574)
    {
        Jogador[playerid][uInteriorEx] = 0;
        SetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
    }

    return 1;
}

Dialog:iRippzyMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new Dialog[300];
    switch(listitem)
    {
        case 0: Dialog_Show(playerid, ComprarTelefone, DIALOG_STYLE_MSGBOX, "{FF0000}Telefone", "Você realmente deseja comprar o telefone?", "Comprar", "Cancelar");
        case 1: return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Opção não disponível");
        case 2: return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Opção não disponível");
        case 3: return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Opção não disponível");
        case 4:
        {
            strcat(Dialog, "Chip Oi\n");
            strcat(Dialog, "Chip Claro\n");
            strcat(Dialog, "Chip Vivo\n");
            strcat(Dialog, "Chip Tim");
            Dialog_Show(playerid, ComprarChip, DIALOG_STYLE_TABLIST, "{FF0000}iRippzy", Dialog, "Comprar", "Cancelar");
        }
    }
    return 1;
}

stock GerarNumeroTelefone(playerid, op)
{
    // 9.7777.8888

    new bool:NumeroOK = false,
        NumeroST[11],
        dfsad[5],
        Enviar[300],
        Cache:Conectar
    ;
    while(NumeroOK == false)
    {
        format(NumeroST, 11, "9");
        for(new i=0; i < 8; i++)
        {
			format(dfsad, sizeof(dfsad), "%d", random(9));
            strins(NumeroST, dfsad, i+1);
        }

        format(Enviar, sizeof(Enviar), "SELECT * FROM `rippzyrpg` WHERE `Numero`=%d", NumeroST);
        Conectar = mysql_query(IDConexao, Enviar);
        if(cache_num_rows() > 0){
            cache_delete(Conectar);
        }
        else NumeroOK = true;
    }
   
    new NumeroConvert;
    sscanf(NumeroST, "d", NumeroConvert);

    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Numero`=%d, `Operadora`=%d WHERE `Nome`='%s'", NumeroConvert, op, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao gerar seu chip e número");
        return false;
    }

    Jogador[playerid][Operadora] = op;
    Jogador[playerid][pNumero] = NumeroConvert;
    stringclear(Enviar);
    strcatEx(Enviar, "{FFFFFF}Número de telefone: {00BFFF}%s\n", NumeroSeparar(Jogador[playerid][pNumero]));
    strcatEx(Enviar, "{FFFFFF}Operadora: {00BFFF}%s{FFFFFF}\n\n", PegarOperadora(playerid));
    strcat(Enviar, "Para visualizar seu número de telefone use {F4A460}/Identidade{FFFFFF}\n");
    strcat(Enviar, "iRippzy, melhor opção para seus periféricos!");
    Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_MSGBOX, "{FF0000}iRippzy", Enviar, "Fechar", "");
    return true;
}

Dialog:ComprarChip(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(Jogador[playerid][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem um celular");
    if(Jogador[playerid][Operadora] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem um CHIP");
    if(Jogador[playerid][Dinheiro] < 180) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    if(!GerarNumeroTelefone(playerid, listitem+1)) return 1;
    Jogador[playerid][Dinheiro] -= 180;
    return 1;
}

Dialog:ComprarTelefone(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(Jogador[playerid][Celular] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem um telefone");
    if(Jogador[playerid][Dinheiro] < 6500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `celular` = 1 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você foi impedido(a) de comprar");
    Jogador[playerid][Celular] = true;
    Jogador[playerid][Dinheiro] -= 6500;
    SendClientMessage(playerid, -1, "| LOJA | Você comprou um celular por {32CD32}$6.500");
    return 1;
}