#include <YSI_Coding\y_hooks>

enum LotericaJogador
{
    LoteriaAposta1,
    LoteriaAposta2
};

enum LoteriaSystem
{
    NumeroLoteric,
    PrecoLoteric,
    TimerLoteric,
    TempoLoteric
};

new Loterica[LoteriaSystem];
new pLoterica[MAX_PLAYERS][LotericaJogador];

hook OnGameModeInit(){

    new Cache:Conectar;
    print("[Rippzy:Loterica] Carregando banco de dados da loterica\n");
    Conectar = mysql_query(IDConexao, "SELECT * FROM `loterica` WHERE `Type` = 'Loteria'", true);
    if(mysql_errno(IDConexao) != 0){
        print("[Rippzy:Loterica] Não foi possivel conectar com o banco de dados da loterica [0x1]\n");
        SendRconCommand("exit");
    }
    cache_get_value_name_int(0, "Valor", Loterica[PrecoLoteric]);
    cache_get_value_name_int(0, "Numero", Loterica[NumeroLoteric]);
    printf("[Rippzy:Loterica] Loteria carregada com sucesso ( Informacoes | Preco: %d / Numero: %d )\n", Loterica[PrecoLoteric], Loterica[NumeroLoteric]);    
    cache_delete(Conectar);
    if(Loterica[NumeroLoteric] == -1) EnviarLoterica();
    Loterica[TempoLoteric] = 7200;
    Loterica[TimerLoteric] = SetTimer("ResultadoLoteria", 1000, true);

    // Bots
    CreateDynamicActor(150, 1557.3722,-1178.8275,24.0940,76.0658, 1, 70.0, 0, 0, -1, 150.0, -1, 0);
    CreateDynamicActor(71, 1540.8483,-1180.8643,24.0940,278.4747, 1, 70.0, 0, 0, -1, 150.0, -1, 0);
    CreateDynamicActor(187, 1551.8522,-1197.0714,23.7677,16.3752, 1, 70.0, 0, 0, -1, 150.0, -1, 0);
    CreateDynamicActor(141, 1543.0547,-1197.0205,23.7686,27.9205, 1, 70.0, 0, 0, -1, 150.0, -1, 0);
    CreateDynamicActor(150, 1537.9347,-1197.0205,23.7686,350.2915, 1, 70.0, 0, 0, -1, 150.0, -1, 0);
    CreateDynamicActor(150, 1556.3090,-1197.0267,23.7685,24.9272, 1, 70.0, 0, 0, -1, 150.0, -1, 0);
    CreateDynamicActor(random(311), 1527.8256,-1175.8322,24.0940,90.5742, 1, 70.0, 0, 0, -1, 150.0, -1, 0);
    CreateDynamicActor(random(311), 1529.6163,-1173.4558,24.0940,356.4919, 1, 70.0, 0, 0, -1, 150.0, -1, 0);

    CreateDynamicMapIcon(1544.6781,-1180.8154,24.0939, 52, -1, 0, 0, -1, 70.0, MAPICON_LOCAL, -1);
    CreateDynamic3DTextLabel("Lotérica{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para abrir o menu", 0x32CD32FF, 1554.5042,-1178.3738,24.0940, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamic3DTextLabel("Impostos{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para abrir o menu", 0x32CD32FF, 1551.4120,-1194.7886,23.8074, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamic3DTextLabel("Saques{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para abrir o menu", 0x32CD32FF, 1542.6412,-1194.9069,23.8054, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason){
    new dasdsa[LotericaJogador];
    pLoterica[playerid] = dasdsa;
    return 1;
}

stock EnviarLoterica()
{
    new HouveGanhador = -1,
        Query[248],
        AntigoVlr = Loterica[PrecoLoteric];
        
    Loterica[TempoLoteric] = 7200;

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(HouveGanhador == -1){
            if(pLoterica[i][LoteriaAposta1] == Loterica[NumeroLoteric] || 
            pLoterica[i][LoteriaAposta2] == Loterica[NumeroLoteric]){
                HouveGanhador = i;
                Jogador[i][DinheiroBanco] += Loterica[PrecoLoteric];
            }
        }
        pLoterica[i][LoteriaAposta1] = 0;
        pLoterica[i][LoteriaAposta2] = 0;
    }

    ExibirLoteriaInfo();
    if(HouveGanhador != -1)
    {
        format(Query, sizeof(Query), "Numero: ~b~%d", Loterica[NumeroLoteric]);
        TextDrawSetString(LoteriaDraw[3], ConverterTexto(Query));

        format(Query, sizeof(Query), "Ganhador(a): ~y~%s", PegarNick(HouveGanhador));
        TextDrawSetString(LoteriaDraw[4], ConverterTexto(Query));

        format(Query, sizeof(Query), "~g~R$%s", DinheiroSeparar(Loterica[PrecoLoteric]));
        TextDrawSetString(LoteriaDraw[5], ConverterTexto(Query));

        // Resetar Loterica
        Loterica[PrecoLoteric] = random(50000-40000)+40000;

        stringclear(Query);
        strcatEx(Query, "**- Número:** %d\n", Loterica[NumeroLoteric]);
        strcatEx(Query, "**- Ganhador(a):** %s\n", PegarNick(HouveGanhador));
        strcatEx(Query, "**- Prêmio:** R$%s\n", DinheiroSeparar(Loterica[PrecoLoteric]));

    }
    else
    {
        format(Query, sizeof(Query), "Numero: ~b~%d", Loterica[NumeroLoteric]);
        TextDrawSetString(LoteriaDraw[3], ConverterTexto(Query));

        format(Query, sizeof(Query), "Ganhador(a): ~r~N/A");
        TextDrawSetString(LoteriaDraw[4], ConverterTexto(Query));

        // Gerar um novo valor
        new rnd = random(50000-40000)+40000;
        Loterica[PrecoLoteric] += rnd;

        format(Query, sizeof(Query), "~g~R$%s~w~ + ~g~R$%s", DinheiroSeparar(AntigoVlr), DinheiroSeparar(rnd));
        TextDrawSetString(LoteriaDraw[5], ConverterTexto(Query));

        stringclear(Query);
        strcatEx(Query, "**- Número:** %d\n", Loterica[NumeroLoteric]);
        strcat(Query, "**- Ganhador(a):** N/A\n");
        strcatEx(Query, "**- Acumulado:** R$%s + R$%s\n", DinheiroSeparar(AntigoVlr), DinheiroSeparar(rnd));
    }
    strcat(Query, "\n<:googlemaps:822329178523041803> Faça já sua aposta e tente sua sorte.");

    Loterica[NumeroLoteric] = random(1000);
    if(Loterica[NumeroLoteric] == 0) Loterica[NumeroLoteric]++;

    SetTimer("OcultarLoteriaInfo", 9000, false);

    format(Query, sizeof(Query), "UPDATE `loterica` SET `Numero` = %d, `Valor` = %d WHERE `Type` = 'Loteria'", Loterica[NumeroLoteric], Loterica[PrecoLoteric]);
    mysql_query(IDConexao, Query, false);
    return 1;
}

function ResultadoLoteria(){
    Loterica[TempoLoteric]--;
    if(Loterica[TempoLoteric] <= 0) EnviarLoterica();
    return 1;
}

CMD:loteria(playerid){
    if(Jogador[playerid][Admin] < 7) return 0;
    new Dialog[90];
    strcat(Dialog, "Aposta Jogadores\n");
    strcat(Dialog, "Informações da Loteria\n");
    strcat(Dialog, "Forçar Loteria\n");
    Dialog_Show(playerid, LoteriaInfo, DIALOG_STYLE_TABLIST, "{FF0000}Loteria", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:LoteriaInfo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[2000];
    switch(listitem)
    {
        case 0:
        {
            new dda;
            strcat(Dialog, "ID\tJogador(a)\tAposta 1\tAposta 2\n");
            for(new i=0; i < MAX_PLAYERS; i++){
                if(!IsPlayerConnected(i)) continue;
                if(Jogador[i][Logado] == false) continue;
                dda++;
                strcatEx(Dialog, "%d\t{FFA500}%s[%d]\t%d\t%d\n", dda, PegarNick(i), i, pLoterica[i][LoteriaAposta1], pLoterica[i][LoteriaAposta2]);
            }
            Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{32CD32}Lotérica", Dialog, "Fechar", #);
        }
        case 1:
        {
            strcatEx(Dialog, "{FFFFFF}Preço: {32CD32}R$%s\n", DinheiroSeparar(Loterica[PrecoLoteric]));
            strcatEx(Dialog, "{FFFFFF}Número: {FFA500}%d", Loterica[NumeroLoteric]);
            Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_MSGBOX, "{32CD32}Lotérica", Dialog, "Fechar", #);
        }
        case 2: EnviarLoterica();
    }
    return 1;
}

function Aposta1(playerid, keypad, const NumeroKeypad[])
{
    if(isnull(NumeroKeypad)) return 0;
    new id;
    sscanf(NumeroKeypad, "d", id);
    if(id > 1000 || id <= 0){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode colocar um valor entre 1 e 1000");
        return 0;
    }
    new Query[5];
    format(Query, sizeof(Query), "%d", id);
    PlayerTextDrawSetString(playerid, ApostaMenu[playerid][6], ConverterTexto(Query));
    SetPVarInt(playerid, "ApostaNv1", id); 

    OcultarKeypad(playerid);
    MostrarApostaMenu(playerid);
    AtualizarLoteric(playerid);
    return 1;
}

function Aposta2(playerid, keypad, const NumeroKeypad[])
{
    if(isnull(NumeroKeypad)) return 0;
    new id;
    sscanf(NumeroKeypad, "d", id);
    if(id > 1000 || id <= 0){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode colocar um valor entre 1 e 1000");
        return 0;
    }
    new Query[5];
    format(Query, sizeof(Query), "%d", id);
    PlayerTextDrawSetString(playerid, ApostaMenu[playerid][7], ConverterTexto(Query));
    SetPVarInt(playerid, "ApostaNv2", id);

    OcultarKeypad(playerid);
    MostrarApostaMenu(playerid);
    AtualizarLoteric(playerid);
    return 1;
}

Dialog:LoteriaMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new Query[20];
            MostrarApostaMenu(playerid);
            format(Query, sizeof(Query), "R$%s", DinheiroSeparar(Loterica[PrecoLoteric]));
            PlayerTextDrawSetString(playerid, ApostaMenu[playerid][4], ConverterTexto(Query)); 
        }
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
        if(Dialog_Opened(playerid)) return 1;
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1554.5042,-1178.3738,24.0940))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            new Dialog[90];
            strcat(Dialog, "Loteria");
            Dialog_Show(playerid, LoteriaMenu, DIALOG_STYLE_TABLIST, "{FF0000}Lotérica", Dialog, "Selecionar", "Fechar");
        }

        // Impostos
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 1551.4120,-1194.7886,23.8074))
        {
            new Dialog[128];
            strcat(Dialog, "Casa\n");
            strcat(Dialog, "Empresa\n");
            strcat(Dialog, "Fábrica\n");
            strcat(Dialog, "Concessionária");
            Dialog_Show(playerid, ImpostosMenu, DIALOG_STYLE_TABLIST, "{FF0000}Lotérica", Dialog, "Selecionar", "Fechar");
        }

        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 1542.6412,-1194.9069,23.8054))
        {
            new Dialog[90];
            strcat(Dialog, "Concessionária\n");
            Dialog_Show(playerid, SaquesLoterica, DIALOG_STYLE_TABLIST, "{FF0000}Lotérica", Dialog, "Selecionar", "Fechar");
        }
    }
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == ApostaMenu[playerid][6]){
        OcultarApostaMenu(playerid);  
        Keypad(playerid, true, "Aposta1", "LotericaCancelar", "Loteria");
    }
    else if(playertextid == ApostaMenu[playerid][7]){
        OcultarApostaMenu(playerid);  
        Keypad(playerid, true, "Aposta2", "LotericaCancelar", "Loteria");  
    }

    // Cancelar
    else if(playertextid == ApostaMenu[playerid][10]){
        DeletePVar(playerid, "ApostaNv1");
        DeletePVar(playerid, "ApostaNv2");
        OcultarApostaMenu(playerid);  
    }

    // Enviar Aposta
    else if(playertextid == ApostaMenu[playerid][8])
    {
        if(GetPVarInt(playerid, "ApostaNv1") == 0 && GetPVarInt(playerid, "ApostaNv2") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não apostou nada");
        if(pLoterica[playerid][LoteriaAposta1] > 0 || pLoterica[playerid][LoteriaAposta1] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem uma aposta pendende, aguarde.");
        new Ctnt;
        if(GetPVarInt(playerid, "ApostaNv1") != 0) Ctnt += 1000;
        if(GetPVarInt(playerid, "ApostaNv2") != 0) Ctnt += 1000;
        if(Jogador[playerid][Dinheiro] < Ctnt) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
        Jogador[playerid][Dinheiro] -= Ctnt;
        
        if(GetPVarInt(playerid, "ApostaNv1") != 0){
            pLoterica[playerid][LoteriaAposta1] = GetPVarInt(playerid, "ApostaNv1");
            DeletePVar(playerid, "ApostaNv1");
        }

        if(GetPVarInt(playerid, "ApostaNv2") != 0){
            pLoterica[playerid][LoteriaAposta2] = GetPVarInt(playerid, "ApostaNv2");
            DeletePVar(playerid, "ApostaNv2");
        }

        new Mensagem[60];
        format(Mensagem, sizeof(Mensagem), "| LOTERIA | Você apostou e gastou {32CD32}R$%s", DinheiroSeparar(Ctnt));
        SendClientMessage(playerid, -1, Mensagem);
        SendClientMessage(playerid, -1, "| LOTERIA | Não deslogue do servidor até que saia o resultado.");
        OcultarApostaMenu(playerid);
    }
    return 0;
}

stock AtualizarLoteric(playerid)
{
    new Query[8];
    if(GetPVarInt(playerid, "ApostaNv1") != 0){
        format(Query, sizeof(Query), "%d", GetPVarInt(playerid, "ApostaNv1"));
        PlayerTextDrawSetString(playerid, ApostaMenu[playerid][6], ConverterTexto(Query)); 
    }

    if(GetPVarInt(playerid, "ApostaNv2") != 0){
        format(Query, sizeof(Query), "%d", GetPVarInt(playerid, "ApostaNv2"));
        PlayerTextDrawSetString(playerid, ApostaMenu[playerid][7], ConverterTexto(Query));
    }
    return 1;
}

function LotericaCancelar(playerid)
{
    MostrarApostaMenu(playerid);
    AtualizarLoteric(playerid);
    return 1;
}

Dialog:ImpostosMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new CasaD = -1;
            for(new i=0; i < MAX_CASAS; i++)
            {
                if(pCasa[i][Colocado] == false) continue;
                if(strcmp(pCasa[i][cDono], PegarNick(playerid))) continue;
                CasaD = i;
                break;
            }
            if(CasaD == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma casa");
            new Dialog[128];
            strcat(Dialog, "Impostos\n");
            strcat(Dialog, "Lixos");
            Dialog_Show(playerid, PrefMenuCasa, DIALOG_STYLE_TABLIST, "Casa", Dialog, "Selecionar", "Fechar");
        }
        case 1:
        { 
            new EmpresaD = -1;
            for(new i=0; i < MAX_EMPRESAS; i++)
            {
                if(pEmpresa[i][Colocado] == false) continue;
                if(strcmp(pEmpresa[i][eDono], PegarNick(playerid))) continue;
                EmpresaD = i;
                break;
            }
            if(EmpresaD == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma empresa");
            if(pEmpresa[EmpresaD][eImpostos] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui impostos pendentes, volte outro dia");
        
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "{CCCCCC}Você tem {FFFFFF}%d{CCCCCC} imposto(s) no valor de {32CD32}$%s", pEmpresa[EmpresaD][eImpostos], DinheiroSeparar(PrecoEmpresaImpostos(EmpresaD)));
            Dialog_Show(playerid, PagarEmpresaImpostos, DIALOG_STYLE_MSGBOX, "{FF0000}Impostos", Enviar, "Pagar", "Fechar");
        }
        case 2:
        {
            new FabricaD = -1;
            for(new i=0; i < MAX_FABRICAS; i++)
            {
                if(pFabrica[i][Colocado] == false) continue;
                if(strcmp(pFabrica[i][fDono], PegarNick(playerid))) continue;
                FabricaD = i;
                break;
            }
            if(FabricaD == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma fábrica");
            if(pFabrica[FabricaD][FabricaImposto] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui impostos pendentes, volte outro dia");
        
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "{CCCCCC}Você tem {FFFFFF}%d{CCCCCC} imposto(s) no valor de {32CD32}$%s", pFabrica[FabricaD][FabricaImposto], DinheiroSeparar(PrecoFabricaImpostos(FabricaD)));
            Dialog_Show(playerid, PagarFabricaImpostos, DIALOG_STYLE_MSGBOX, "{FF0000}Impostos", Enviar, "Pagar", "Fechar");
        }
        case 3:
        {
            new id = PegarMinhaConce(playerid);
            if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma concessionária");
            if(Concessionaria[id][ImpostosConce] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui impostos pendentes, volte outro dia");
            new Enviar[128];
            format(Enviar, sizeof(Enviar), "{CCCCCC}Você tem {FFFFFF}%d{CCCCCC} imposto(s) no valor de {32CD32}$%s", Concessionaria[id][ImpostosConce], DinheiroSeparar(PrecoConceImpostos(id)));
            Dialog_Show(playerid, PagarConceImpostos, DIALOG_STYLE_MSGBOX, "{FF0000}Impostos", Enviar, "Pagar", "Fechar");
        }
    }
    return 0;
}

Dialog:PrefMenuCasa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new CasaD = -1;
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(strcmp(pCasa[i][cDono], PegarNick(playerid))) continue;
        CasaD = i;
        break;
    }
    if(CasaD == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma casa");
    new Enviar[128];
    switch(listitem)
    {
        // Impostos
        case 0:
        {
            if(pCasa[CasaD][Impostos] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui impostos pendentes, volte outro dia");
            format(Enviar, sizeof(Enviar), "{CCCCCC}Você tem {FFFFFF}%d{CCCCCC} imposto(s) no valor de {32CD32}$%s", pCasa[CasaD][Impostos], DinheiroSeparar(PrecoCasaImpostos(CasaD)));
            Dialog_Show(playerid, PagarCasaImpostos, DIALOG_STYLE_MSGBOX, "{FF0000}Impostos", Enviar, "Pagar", "Fechar");
        }

        // Lixos
        case 1:
        {
            if(pCasa[CasaD][LixoF] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua casa não tem lixos, volte outro dia");
            new Precc = (150*pCasa[CasaD][LixoF]);
            format(Enviar, sizeof(Enviar), "Você tem %d lixo(s), para remover tudo custará $%s", pCasa[CasaD][LixoF], DinheiroSeparar(Precc));
            Dialog_Show(playerid, LixosMenu, DIALOG_STYLE_MSGBOX, "{FF0000}Lixos", Enviar, "Selecionar", "Fechar");
        }
    }

    return 1;
}


Dialog:PagarCasaImpostos(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new CasaD = -1;
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(strcmp(pCasa[i][cDono], PegarNick(playerid))) continue;
        CasaD = i;
        break;
    }
    if(Jogador[playerid][Dinheiro] < PrecoCasaImpostos(CasaD)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "UPDATE `casas` SET `Impostos` = 0 WHERE `Numero` = %d", pCasa[CasaD][Numero]);
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao pagar os impostos");
    Jogador[playerid][Dinheiro] -= PrecoCasaImpostos(CasaD);
    format(Mensagem, sizeof(Mensagem), "| IMPOSTOS | Você pagou %d imposto(s) por {32CD32}$%s", pCasa[CasaD][Impostos], DinheiroSeparar(PrecoCasaImpostos(CasaD)));
    SendClientMessage(playerid, -1, Mensagem);
    pCasa[CasaD][Impostos] = 0;
    return 0;
}

Dialog:PagarEmpresaImpostos(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new EmpresaD = -1;
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        if(!strcmp(pEmpresa[i][eDono], "*")) continue;
        if(strcmp(pEmpresa[i][eDono], PegarNick(playerid))) continue;
        EmpresaD = i;
        break;
    }
    if(Jogador[playerid][Dinheiro] < PrecoEmpresaImpostos(EmpresaD)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "UPDATE `empresas` SET `Impostos` = 0 WHERE `Numero` = %d", EmpresaD);
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao pagar os impostos");
    Jogador[playerid][Dinheiro] -= PrecoEmpresaImpostos(EmpresaD);
    format(Mensagem, sizeof(Mensagem), "| IMPOSTOS | Você pagou %d imposto(s) por {32CD32}$%s", pEmpresa[EmpresaD][eImpostos], DinheiroSeparar(PrecoEmpresaImpostos(EmpresaD)));
    SendClientMessage(playerid, -1, Mensagem);
    pEmpresa[EmpresaD][eImpostos] = 0;
    return 0;
}

Dialog:PagarFabricaImpostos(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new FabricaD = -1;
    for(new i=0; i < MAX_FABRICAS; i++)
    {
        if(pFabrica[i][Colocado] == false) continue;
        if(strcmp(pFabrica[i][fDono], PegarNick(playerid))) continue;
        FabricaD = i;
        break;
    }
    if(Jogador[playerid][Dinheiro] < PrecoFabricaImpostos(FabricaD)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "UPDATE `fabricas` SET `Impostos` = 0 WHERE `Numero` = %d", FabricaD);
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao pagar os impostos");
    Jogador[playerid][Dinheiro] -= PrecoFabricaImpostos(FabricaD);
    format(Mensagem, sizeof(Mensagem), "| IMPOSTOS | Você pagou %d imposto(s) por {32CD32}$%s", pFabrica[FabricaD][FabricaImposto], DinheiroSeparar(PrecoFabricaImpostos(FabricaD)));
    SendClientMessage(playerid, -1, Mensagem);
    pFabrica[FabricaD][FabricaImposto] = 0;
    return 0;
}

Dialog:PagarConceImpostos(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = PegarMinhaConce(playerid);
    if(Jogador[playerid][Dinheiro] < PrecoConceImpostos(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "UPDATE `concessionaria` SET `Impostos` = 0 WHERE `Numero` = %d", id);
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao pagar os impostos");
    Jogador[playerid][Dinheiro] -= PrecoConceImpostos(id);
    format(Mensagem, sizeof(Mensagem), "| IMPOSTOS | Você pagou %d imposto(s) por {32CD32}$%s", Concessionaria[id][ImpostosConce], DinheiroSeparar(PrecoConceImpostos(id)));
    SendClientMessage(playerid, -1, Mensagem);
    Concessionaria[id][ImpostosConce] = 0;
    return 0;
}

Dialog:LixosMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new CasaD = -1;
    for(new i=0; i < MAX_CASAS; i++)
    {
        if(pCasa[i][Colocado] == false) continue;
        if(strcmp(pCasa[i][cDono], PegarNick(playerid))) continue;
        CasaD = i;
        break;
    }
    if(CasaD == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma casa");
    if(pCasa[CasaD][LixoF] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua casa não tem lixos, volte outro dia");

    new Precc = (150*pCasa[CasaD][LixoF]);
    if(Jogador[playerid][Dinheiro] < Precc) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `casas` SET `LixoF`=0 WHERE `Numero`=%d", CasaD);
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao pagar, entre em contato com um desenvolvedor!");  
    pCasa[CasaD][LixoF] = 0;
    Jogador[playerid][Dinheiro] -= Precc;
    AtualizarCasa(CasaD);
    SendClientMessage(playerid, 0xFFFF00FF, "| PAGAMENTO | Foi enviada uma equipe até sua residência para remover os lixos");
    return 1;
}

Dialog:SaquesLoterica(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new id = PegarMinhaConce(playerid);
            if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma concessionária");
            if(Concessionaria[id][CofreConce] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro em sua concessionária para sacar");

            new Query[128];
            format(Query, sizeof(Query), "UPDATE `concessionaria` SET `Cofre` = 0 WHERE `Numero` = %d", id);
            mysql_query(IDConexao, Query, false);
            if(mysql_errno(IDConexao) != 0) return 1;

            new cuc = Concessionaria[id][CofreConce];
            Jogador[playerid][Dinheiro] += Concessionaria[id][CofreConce];
            Concessionaria[id][CofreConce] = 0;
            format(Query, sizeof(Query), "| LOTERICA | Você sacou {32CD32}$%s{FFFFFF} da sua concessionária", DinheiroSeparar(cuc));
            SendClientMessage(playerid, -1, Query);

        }
    }
    return 1;
}