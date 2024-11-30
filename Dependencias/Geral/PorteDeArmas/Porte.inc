#include <YSI_Coding\y_hooks>

enum JogadorTreinamento
{
    bool:FazendoTreino,
    bool:ProvaEstande,
    TempoTreino,
    TimerTreino,
    AlvoAcertos,
    AcertosAtuais
};

enum EstandeTreino
{
    bool:AlvoAtiravel,
    bool:AlvoQuebrado,
    AlvoID
};

new JogadorTreino[MAX_PLAYERS][JogadorTreinamento];
new Estande[MAX_PLAYERS][10][EstandeTreino];
new cptiros;

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Escola de Tiros{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para entrar", 0xFFA500FF, -1942.8262,456.9880,35.1719, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicMapIcon(-1942.8262,456.9880,35.1719, 6, -1, 0, 0, -1, 120.0, MAPICON_LOCAL, -1);
    CreateDynamicPickup(1239, 1, -1942.8262,456.9880,35.1719, 0, 0, -1, 60.0, -1);

    CreateDynamic3DTextLabel("Escola de Tiros{FFFFFF}\nAperte {CCCCCC}'F'{FFFFFF} para sair", 0xFFA500FF, 285.3849,-41.3685,1001.5156, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 543, 1, -1, 11.0, -1);
    CreateDynamicPickup(1239, 1, 285.3849,-41.3685,1001.5156, 543, 1, -1, 30.0, -1);
    cptiros = CreateDynamicCP(295.1141,-38.0647,1001.5156, 1.0, 543, 1, -1, 20.0, -1); 
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(JogadorTreino[playerid][FazendoTreino] == true) KillTimer(JogadorTreino[playerid][TimerTreino]);

    for(new i=0; i < 10; i++){
        DestroyDynamicObjectEx(Estande[playerid][i][AlvoID]);
        new fasdc[EstandeTreino];
        Estande[playerid][i] = fasdc;
    }

    new fasddc[JogadorTreinamento];
    JogadorTreino[playerid] = fasddc;
    return 1;
}

stock RegenerarAlvos(playerid, bool:rege = false, tasd = -1)
{
    enum Ratfs
    {
        Float:AlvoX,
        Float:AlvoY,
        Float:AlvoZ
    };

    new AlvoConfig[][Ratfs] =
    {
        {298.58521, -9.40300, 1002.40338},
        {287.56091, -10.39290, 1002.57538},
        {289.39581, -8.56430, 1001.71539},
        {292.63571, -13.24510, 1002.74738},
        {295.37970, -11.29140, 1001.54340}
    };

    if(tasd != -1)
    {
        switch(tasd)
        {
            case 9: Estande[playerid][9][AlvoID] = CreateDynamicObject(1588, AlvoConfig[0][AlvoX], AlvoConfig[0][AlvoY], AlvoConfig[0][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
            case 8: Estande[playerid][8][AlvoID] = CreateDynamicObject(1588, AlvoConfig[1][AlvoX], AlvoConfig[1][AlvoY], AlvoConfig[1][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
            case 7: Estande[playerid][7][AlvoID] = CreateDynamicObject(1588, AlvoConfig[2][AlvoX], AlvoConfig[2][AlvoY], AlvoConfig[2][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
            case 6: Estande[playerid][6][AlvoID] = CreateDynamicObject(1588, AlvoConfig[3][AlvoX], AlvoConfig[3][AlvoY], AlvoConfig[3][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
            case 5: Estande[playerid][5][AlvoID] = CreateDynamicObject(1588, AlvoConfig[4][AlvoX], AlvoConfig[4][AlvoY], AlvoConfig[4][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
        }
        return 1;
    }

    if(rege == true)
    {
        Estande[playerid][9][AlvoAtiravel] = true;
        Estande[playerid][8][AlvoAtiravel] = true;
        Estande[playerid][7][AlvoAtiravel] = true;
        Estande[playerid][6][AlvoAtiravel] = true;
        Estande[playerid][5][AlvoAtiravel] = true;  

        Estande[playerid][4][AlvoID] = CreateDynamicObject(3025, 298.68900, -9.30555, 1004.12341, 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
        Estande[playerid][3][AlvoID] = CreateDynamicObject(3025, 287.68417, -10.32292, 1004.12341, 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
        Estande[playerid][2][AlvoID] = CreateDynamicObject(3025, 289.47568, -8.45054, 1004.12341, 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
        Estande[playerid][1][AlvoID] = CreateDynamicObject(3025, 292.64209, -13.12318, 1004.12341, 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
        Estande[playerid][0][AlvoID] = CreateDynamicObject(3025, 295.52444, -11.11795, 1004.12341, 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1); 
    }

    Estande[playerid][9][AlvoQuebrado] = false;
    Estande[playerid][8][AlvoQuebrado] = false;
    Estande[playerid][7][AlvoQuebrado] = false;
    Estande[playerid][6][AlvoQuebrado] = false;
    Estande[playerid][5][AlvoQuebrado] = false;

    Estande[playerid][9][AlvoID] = CreateDynamicObject(1588, AlvoConfig[0][AlvoX], AlvoConfig[0][AlvoY], AlvoConfig[0][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
    Estande[playerid][8][AlvoID] = CreateDynamicObject(1588, AlvoConfig[1][AlvoX], AlvoConfig[1][AlvoY], AlvoConfig[1][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
    Estande[playerid][7][AlvoID] = CreateDynamicObject(1588, AlvoConfig[2][AlvoX], AlvoConfig[2][AlvoY], AlvoConfig[2][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
    Estande[playerid][6][AlvoID] = CreateDynamicObject(1588, AlvoConfig[3][AlvoX], AlvoConfig[3][AlvoY], AlvoConfig[3][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
    Estande[playerid][5][AlvoID] = CreateDynamicObject(1588, AlvoConfig[4][AlvoX], AlvoConfig[4][AlvoY], AlvoConfig[4][AlvoZ], 0.0, 0.0, 0.0, (542+playerid)+1, 1, playerid, 90.0, 90.0, -1);
    return 1;
}

hook OnPlayerShootDynObject(playerid, weaponid, objectid, Float:x, Float:y, Float:z)
{
    if(JogadorTreino[playerid][FazendoTreino] == false) return 1;
    if(weaponid != GetPVarInt(playerid, "ProgressStand"))
    {
        for(new i=0; i < 10; i++)
        {
            if(Estande[playerid][i][AlvoID] != objectid) continue;
            DestroyDynamicObjectEx(Estande[playerid][i][AlvoID]);
            RegenerarAlvos(playerid, false, i);
            break;
        }
        return 1;
    }
    for(new i=0; i < 10; i++)
    {
        if(Estande[playerid][i][AlvoID] != objectid) continue;
        if(Estande[playerid][i][AlvoAtiravel] == false) return 1;
        if(Estande[playerid][i][AlvoQuebrado] == true) return 1;
        Estande[playerid][i][AlvoQuebrado] = true;
        DestroyDynamicObjectEx(Estande[playerid][i][AlvoID]);
        JogadorTreino[playerid][AlvoAcertos]++;
        JogadorTreino[playerid][AcertosAtuais]++;
        PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0); 
        if(JogadorTreino[playerid][AlvoAcertos] >= 60)
        {
            JogadorTreino[playerid][FazendoTreino] = false;
            KillTimer(JogadorTreino[playerid][TimerTreino]);
            OcultarTreinamento(playerid);
            RemoverArma(playerid, GetPVarInt(playerid, "ProgressStand"));

            for(new d=0; d < 10; d++){
                DestroyDynamicObjectEx(Estande[playerid][d][AlvoID]);
                new fasdc[EstandeTreino];
                Estande[playerid][d] = fasdc;
            }

            new Mensagem[128],
                Soma = gettime()+(30*86400);
            
            if(JogadorTreino[playerid][ProvaEstande] == true)
            {
                format(Mensagem, sizeof(Mensagem), "UPDATE `rippzyrpg` SET `PorteDeArmas`=%d WHERE `Nome` = '%s'", Soma, EscapeString(PegarNick(playerid)));
                mysql_query(IDConexao, Mensagem, false);
                Jogador[playerid][PorteDeArmas] = Soma;

                format(Mensagem, sizeof(Mensagem), "| PORTE | Você precisa retornar %s para renovar o seu porte", GetDateFromTimeEx(Jogador[playerid][PorteDeArmas]));
                SendClientMessage(playerid, 0xFFA500FF, Mensagem);
            }

            SetPlayerVirtualWorld(playerid, 543);
            SetPlayerPos(playerid, 285.3849,-41.3685,1001.5156); 
            return 1;    
        }
        else if(JogadorTreino[playerid][AcertosAtuais] >= 5)
        {
            JogadorTreino[playerid][AcertosAtuais] = 0;
            RegenerarAlvos(playerid);
        }

        new Mensagem[25];
        format(Mensagem, sizeof(Mensagem), "Progresso: %d/60", JogadorTreino[playerid][AlvoAcertos]); 
        PlayerTextDrawSetString(playerid, PorteMod[playerid][4], ConverterTexto(Mensagem));

        format(Mensagem, sizeof(Mensagem), "Alvos: %d/5", JogadorTreino[playerid][AcertosAtuais]);
        PlayerTextDrawSetString(playerid, PorteMod[playerid][3], ConverterTexto(Mensagem));
        break;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_SECONDARY_ATTACK || GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;


    // Dentro do Local
    if(IsPlayerInRangeOfPoint(playerid, 3.0, 285.3849,-41.3685,1001.5156))
    {
        if(Jogador[playerid][uInteriorEx] != 543) return 1;
        if(GetPlayerInterior(playerid) != 1 && GetPlayerVirtualWorld(playerid) != 543) return 1;
        Jogador[playerid][uInteriorEx] = 0;
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerPos(playerid, -1942.8262,456.9880,35.1719);
    }

    // Local de Fora 
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, -1942.8262,456.9880,35.1719))
    {
            
        if(GetPlayerInterior(playerid) != 0 && GetPlayerVirtualWorld(playerid) != 0) return 1;
        // if(strcmp(Jogador[playerid][Profissao], "Meteorologista") && Jogador[playerid][Admin] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        // if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
        Jogador[playerid][uInteriorEx] = 543;
        GetPlayerPos(playerid, Jogador[playerid][uInteriorExP][0], Jogador[playerid][uInteriorExP][1], Jogador[playerid][uInteriorExP][2]);
        SetPlayerFacingAngle(playerid, Jogador[playerid][uInteriorExP][3]);

        SetPlayerInterior(playerid, 1);
        SetPlayerVirtualWorld(playerid, 543);
        SetPlayerPos(playerid, 285.3849,-41.3685,1001.5156); 
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(cptiros != checkpointid) return 1;

    new Dialog[228];
    strcat(Dialog, "Opção\tAdicional\n");

    if(Jogador[playerid][PorteDeArmas] > gettime()) strcatEx(Dialog, "Porte de Armas\t{FFA500}%s\n", ConverterSegundos(Jogador[playerid][PorteDeArmas]));
    else if(Jogador[playerid][PorteDeArmas] < gettime() && Jogador[playerid][PorteDeArmas] != 0) strcat(Dialog, "Porte de Armas\t{32CD32}R$30.000 [Renovar]\n");
    else strcat(Dialog, "Porte de Armas\t{32CD32}R$20.000\n");
    strcat(Dialog, "Treinamento\t{32CD32}R$2.500");
    Dialog_Show(playerid, OpcaoEstande, DIALOG_STYLE_TABLIST_HEADERS, "Estande", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:OpcaoEstande(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            if(Jogador[playerid][PorteDeArmas] > gettime())
            {
                new Mensagem[128];
                format(Mensagem, sizeof(Mensagem), "| ERRO | Você tem %s de porte de armas", ConverterSegundos(Jogador[playerid][PorteDeArmas]));
                SendClientMessage(playerid, 0xFF4500FF, Mensagem);
                return 1;
            }

            new Mensagem[128],
                Soma = gettime()+(30*86400);

            format(Mensagem, sizeof(Mensagem), "UPDATE `rippzyrpg` SET `PorteDeArmas`=%d WHERE `Nome` = '%s'", Soma, EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Mensagem, false);
            Jogador[playerid][PorteDeArmas] = Soma;

            format(Mensagem, sizeof(Mensagem), "| PORTE | Você precisa retornar %s para renovar o seu porte", GetDateFromTimeEx(Jogador[playerid][PorteDeArmas]));
            SendClientMessage(playerid, 0xFFA500FF, Mensagem);
        }
        case 1:
        {
            if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas");
            new Dialog[300];
            strcat(Dialog, "ID\tArma\tTempo\tPreço\n");
            strcat(Dialog, "1.\t{00BFFF}M4\t{FFA500}02:00\t{32CD32}R$2.500\n");
            strcat(Dialog, "2.\t{00BFFF}AK\t{FFA500}02:00\t{32CD32}R$2.000\n");
            strcat(Dialog, "3.\t{00BFFF}MP5\t{FFA500}02:30\t{32CD32}R$2.000\n");
            strcat(Dialog, "4.\t{00BFFF}Desert\t{FFA500}03:00\t{32CD32}R$1.500\n");
            strcat(Dialog, "5.\t{00BFFF}Silenced 9mm\t{FFA500}02:30\t{32CD32}R$1.300");
            Dialog_Show(playerid, TreinamentoOpcao, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Treinamento", Dialog, "Selecionar", "Fechar");
        }
    }
    return 1;
}

Dialog:TreinamentoOpcao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            if(Jogador[playerid][Dinheiro] < 2500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
            Jogador[playerid][Dinheiro] -= 2500;
            SendClientMessage(playerid, 0xFFA500FF, "| TREINAMENTO | Você pagou R$2.500 por 02:00 com M4");
            SetEstande(playerid, 120, 31, 250);
        }
        case 1:
        {
            if(Jogador[playerid][Dinheiro] < 2000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
            Jogador[playerid][Dinheiro] -= 2000;
            SendClientMessage(playerid, 0xFFA500FF, "| TREINAMENTO | Você pagou R$2.000 por 02:00 com AK");
            SetEstande(playerid, 120, 30, 210);
        }
        case 2:
        {
            if(Jogador[playerid][Dinheiro] < 2000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
            Jogador[playerid][Dinheiro] -= 2000;
            SendClientMessage(playerid, 0xFFA500FF, "| TREINAMENTO | Você pagou R$2.000 por 02:30 com MP5");
            SetEstande(playerid, 120, 29, 190);
        }
        case 3:
        {
            if(Jogador[playerid][Dinheiro] < 1500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
            Jogador[playerid][Dinheiro] -= 1500;
            SendClientMessage(playerid, 0xFFA500FF, "| TREINAMENTO | Você pagou R$1.500 por 03:00 com DESERT");
            SetEstande(playerid, 180, 24, 190);
        }
        case 4:
        {
            if(Jogador[playerid][Dinheiro] < 1300) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
            Jogador[playerid][Dinheiro] -= 1300;
            SendClientMessage(playerid, 0xFFA500FF, "| TREINAMENTO | Você pagou R$1.300 por 02:30 com Silenced 9mm");
            SetEstande(playerid, 150, 23, 100);
        }
    }
    return 1;
}

Dialog:PorteTeste(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(Jogador[playerid][Dinheiro] < 20000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    Jogador[playerid][Dinheiro] -= 20000;
    SetEstande(playerid, 150, 24, 75, true);
    return 1;
}

stock SetEstande(playerid, tempo, armaid, balass, bool:Pfv = false)
{
    new fasddc[JogadorTreinamento];
    JogadorTreino[playerid] = fasddc;

    JogadorTreino[playerid][ProvaEstande] = Pfv;

    SetPVarInt(playerid, "ProgressStand", armaid);

    GivePlayerWeapon(playerid, armaid, balass);
    JogadorTreino[playerid][FazendoTreino] = true;

    RegenerarAlvos(playerid, true);
    MostrarTreinamento(playerid);

    JogadorTreino[playerid][TempoTreino] = tempo;
    JogadorTreino[playerid][TimerTreino] = SetTimerEx("AtualizarTreinamento", 1000, true, "d", playerid);

    SetPlayerVirtualWorld(playerid, (542+playerid)+1);
    SetPlayerPos(playerid, 293.6704,-24.9079,1001.5156);
    return 1;
}

function AtualizarTreinamento(playerid)
{
    JogadorTreino[playerid][TempoTreino]--;
    if(JogadorTreino[playerid][TempoTreino] < 1)
    {
        for(new i=0; i < 10; i++){
            DestroyDynamicObjectEx(Estande[playerid][i][AlvoID]);
            new fasdc[EstandeTreino];
            Estande[playerid][i] = fasdc;
        }
        KillTimer(JogadorTreino[playerid][TimerTreino]);
        OcultarTreinamento(playerid);
        if(JogadorTreino[playerid][ProvaEstande] == true) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você foi reprovado(a), tente novamente mais tarde");
        else SendClientMessage(playerid, 0xFFA500FF, "| AVISO | Seu tempo no estande acabou");
        RemoverArma(playerid, GetPVarInt(playerid, "ProgressStand"));
        SetPlayerVirtualWorld(playerid, 543);
        SetPlayerPos(playerid, 285.3849,-41.3685,1001.5156); 
        return 1;
    }

    new Mensagem[15];
    format(Mensagem, sizeof(Mensagem), "Tempo: %s", SegundosParaMinutosEx(JogadorTreino[playerid][TempoTreino]));
    PlayerTextDrawSetString(playerid, PorteMod[playerid][5], ConverterTexto(Mensagem));
    return 1;
}