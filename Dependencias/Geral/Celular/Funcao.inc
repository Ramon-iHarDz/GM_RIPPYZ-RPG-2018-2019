stock PegarOperadora(playerid)
{
    new Opp[6];
    switch(Jogador[playerid][Operadora])
    {
        case 0: Opp = "N/A";
        case 1: Opp = "Oi";
        case 2: Opp = "Claro";
        case 3: Opp = "Vivo";
        case 4: Opp = "Tim";
    }
    return(Opp);
}

// 9.1111.2222

stock NumeroSeparar(aaNumero)
{
    new temp[100], counter = -1;
    valstr(temp, aaNumero);
    for(new i=0; i < strlen(temp); i++)
    {
        if(counter == -1){
            strins(temp, ".", i+1);
            counter = 0;
            continue;
        }

        counter++;
        if(counter == 6){
            strins(temp, ".", i);
            counter = 0;
        }
    }
    return temp;
}

/*LocalAgenda(playerid, &partir, bool:Inverso, slot)
{
    if(partir < 0) partir++;
    new Infoas[30] = "N/A",
        mdss[11]
    ;
    format(mdss, 11, "Agenda%d", slot);

    if(partir >= MAX_NUMEROS){
        Infoas = "~r~Sem Espaço";
        SetPVarInt(playerid, mdss, -2);
        return(Infoas);
    }

    new oldii = -1,
        Msgg[128]
    ;
    if(Inverso == true)
    {
        for(new i=partir; i > 0; i--)
        {
            format(Msgg, sizeof(Msgg), "Ident: p: %d - i: %d - pEx: %d - Atv?: %d - %s - %s", partir, i, partir-1, pAgenda[playerid][i][aUsada], pAgenda[playerid][i][Contato], pAgenda[playerid][i-1][Contato]);
            SendClientMessageToAll(-1, Msgg);
            if(pAgenda[playerid][i][aUsada] == false) continue;
            oldii = i;
            partir = i-1;
            format(Infoas, 30, pAgenda[playerid][i][Contato]);
            break;
        }
    }
    else
    {
        for(new i=partir; i < MAX_NUMEROS; i++)
        {
            if(pAgenda[playerid][i][aUsada] == false) continue;
            format(Infoas, 30, pAgenda[playerid][i][Contato]);
            oldii = i;
            partir = i+1;
            break;
        }
    }
    SetPVarInt(playerid, mdss, oldii);
    if(slot == 3){
        if(IdentificacaoFix(playerid)) partir++;
    }
    return(Infoas);
}*/

stock LocalAgenda(playerid, &partir, slot)
{
    new Infoas[30] = "N/A",
        mdss[11]
    ;
    format(mdss, 11, "Agenda%d", slot);

    if(partir >= MAX_NUMEROS){
        Infoas = "~r~Sem Espaço";
        SetPVarInt(playerid, mdss, -2);
        return(Infoas);
    }

    new oldii = -1;

    if(pAgenda[playerid][partir][aUsada] == true){
        format(Infoas, 30, pAgenda[playerid][partir][Contato]);
        oldii = partir;
    }
    partir++;
    if(partir < 0) partir = 0;
    if(partir > MAX_NUMEROS) partir = MAX_NUMEROS;
    SetPVarInt(playerid, mdss, oldii);
    return(Infoas);
}

stock AtualizarAgenda(playerid, bool:Inverso) 
{
    new idp = GetPVarInt(playerid, "ApartirAgenda");

    if(Inverso == true){
        if(idp == 0) return 1;  
    }

    if(Inverso == false){
        new mdsss[8],
            cuznsad;
        
        for(new i=1; i < 6; i++){
            format(mdsss, sizeof(mdsss), "Agenda%d", i);
            if(GetPVarInt(playerid, mdsss) == -1 || 
            GetPVarInt(playerid, mdsss) == -2) cuznsad++;
            if(cuznsad > 1) return 1;
        }
    } 

    new Textdraw1 = 3,
        Textdraw2 = 6,
        Textdraw3 = 9,
        Textdraw4 = 12,
        Textdraw5 = 15;

    if(Inverso == true)
    {
        //IdEx1 = 3;
        //IdEx3 = 1;
        //Textdraw1 = 10;
        //Textdraw3 = 8;
        // idp -= 6;
        idp -= 10;
    }

    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][Textdraw1], ConverterTexto(LocalAgenda(playerid, idp, 1)));
    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][Textdraw2], ConverterTexto(LocalAgenda(playerid, idp, 2)));
    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][Textdraw3], ConverterTexto(LocalAgenda(playerid, idp, 3)));
    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][Textdraw4], ConverterTexto(LocalAgenda(playerid, idp, 4)));
    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][Textdraw5], ConverterTexto(LocalAgenda(playerid, idp, 5)));
    
    SetPVarInt(playerid, "AgendaReverb", Inverso);
    if(idp < 0) idp = 0;
    SetPVarInt(playerid, "ApartirAgenda", idp);
    if(idp == 0) AtualizarAgenda(playerid, false); 

    new Mssg[7];
    format(Mssg, sizeof(Mssg), "%d/%d", idp, MAX_NUMEROS);
    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][0], Mssg); 
    return 1;
}

/*IdentificacaoFix(playerid)
{
    new mdsss[8],
        Cotadooor
    ;
    for(new i=1; i < 4; i++){
        format(mdsss, sizeof(mdsss), "Agenda%d", i);
        if(GetPVarInt(playerid, mdsss) == -1) Cotadooor++;
    }
    if(Cotadooor >= 3) return true;
    return false;
}*/

/*AtualizarAgenda(playerid, bool:Inverso) 
{
    new idp = GetPVarInt(playerid, "ApartirAgenda");

    if(Inverso == true){
        if(idp == 0) return 1;  
    }

    if(Inverso == false){
        new mdsss[8],
            cuznsad
        ;
        for(new i=1; i < 4; i++){
            format(mdsss, sizeof(mdsss), "Agenda%d", i);
            if(GetPVarInt(playerid, mdsss) == -1 || 
            GetPVarInt(playerid, mdsss) == -2) cuznsad++;
            if(cuznsad > 1) return 1;
        }
    } 

    new Textdraw1 = 8,
        Textdraw2 = 9,
        Textdraw3 = 10,

        IdEx1 = 1,
        IdEx2 = 2,
        IdEx3 = 3
    ;

    if(Inverso == true)
    {
        IdEx1 = 3;
        IdEx3 = 1;
        Textdraw1 = 10;
        Textdraw3 = 8;
    }

    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][Textdraw1], ConverterTexto(LocalAgenda(playerid, idp, Inverso, IdEx1)));
    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][Textdraw2], ConverterTexto(LocalAgenda(playerid, idp, Inverso, IdEx2)));
    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][Textdraw3], ConverterTexto(LocalAgenda(playerid, idp, Inverso, IdEx3)));

    new bool:ErroNnn;
    if(Inverso == false){
        new dvalor = GetPVarInt(playerid, "AntigoValorAgenda"),
            PontaValor = PontaEx(dvalor, idp);
        if(PontaValor < 3){
            if(PontaValor == 1 || PontaValor == 2){
                idp = dvalor;
                idp -= 1;
            }else idp = dvalor;
            ErroNnn = true; 
        }
    }
    SetPVarInt(playerid, "AntigoValorAgenda", idp);

    new Mensagem[30];
    if(ErroNnn == true) format(Mensagem, sizeof(Mensagem), "( ERRO ) Resultado: %d - M: %d", idp, playerid);
    else format(Mensagem, sizeof(Mensagem), "Resultado: %d - M: %d", idp, playerid);
    SendClientMessageToAll(-1, Mensagem);

    SetPVarInt(playerid, "AgendaReverb", Inverso);
    if(idp < 0) idp = 0;
    SetPVarInt(playerid, "ApartirAgenda", idp);
    if(idp == 0) AtualizarAgenda(playerid, false); 
    return 1;
}*/

stock MostrarDialogContato(playerid, id)
{
    new Dialog[228];
    strcat(Dialog, "Opção\tInformação\n");
    strcatEx(Dialog, "{FFFFFF}Alterar Contato\t{CCCCCC}%s\n", pAgenda[playerid][id][Contato]);
    strcatEx(Dialog, "{FFFFFF}Número\t{DAA520}%s\n", NumeroSeparar(pAgenda[playerid][id][aNumero]));
    strcat(Dialog, "{FA8072}Excluir\n");
    strcat(Dialog, "{32CD32}Ligar");
    Dialog_Show(playerid, ContatoOpcao, DIALOG_STYLE_TABLIST_HEADERS, pAgenda[playerid][id][aNome], Dialog, "Selecionar", "Fechar");
    return 1;
}

stock SelecinarContato(playerid, slot)
{
    new mdss[11],
        id;
    
    format(mdss, 11, "Agenda%d", slot);
    SetPVarInt(playerid, "SlotTextdraw", slot);
    id = GetPVarInt(playerid, mdss);
    SetPVarInt(playerid, "SlotAtualAgenda", id); 

    if(id == -2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há espaço para adicionar número aqui");
    else if(id == -1) return Dialog_Show(playerid, AdicionarNumeroAgenda, DIALOG_STYLE_INPUT, "{FF0000}Agenda", "Coloque o número abaixo para adicionar", "Adicionar", "Fechar");

    MostrarDialogContato(playerid, id);
    return 1;
}

stock AtualizarAgendaTextdraw(playerid, slot)
{
    new id = GetPVarInt(playerid, "SlotAtualAgenda"), 
        Enviar[90],
        diasn;
    if(pAgenda[playerid][id][aUsada] == false) format(Enviar, 90, "N/A");
    else format(Enviar, 90, pAgenda[playerid][id][Contato]);

    switch(slot)
    {
        case 1: diasn = 3;
        case 2: diasn = 6;
        case 3: diasn = 9;
        case 4: diasn = 12;
        case 5: diasn = 15;
    }
    PlayerTextDrawSetString(playerid, CelularAgenda[playerid][diasn], ConverterTexto(Enviar));
    return 1;
}

stock PegarLocalAgenda(playerid)
{
    for(new i=0; i < MAX_NUMEROS; i++){
        if(pAgenda[playerid][i][aUsada] == true) continue;
        return i;
    }
    return -1;
}

stock ProcurarNomeAgenda(playerid, const Nomeee[])
{
    for(new i=0; i < MAX_NUMEROS; i++){
        if(pAgenda[playerid][i][aUsada] == false) continue;
        if(!strcmp(pAgenda[playerid][i][aNome], Nomeee)) return i;
    }
    return -1;
}

stock InformacaoLigacao(playerid, id, bool:Ligandoaaa)
{
    new lvove = ProcurarNomeAgenda(playerid, PegarNick(id));
    if(Ligandoaaa == true){
        PlayerTextDrawSetString(playerid, LigacaoAndamento[playerid][0], ConverterTexto(pAgenda[playerid][lvove][Contato]));
        return 1;
    }
    if(lvove == -1) PlayerTextDrawSetString(playerid, CelularChamando[playerid][0], ConverterTexto("Desconhecido(a)"));
    else PlayerTextDrawSetString(playerid, CelularChamando[playerid][0], ConverterTexto(pAgenda[playerid][lvove][Contato]));
    return 1;
}

stock RequestCelular(playerid)
{
    if(GetPVarInt(playerid, "EmLigacao") > 0) OcultarNotificacaoChamada(playerid);
    MostrarCelular(playerid);
    if(GetPVarInt(playerid, "EmLigacao") > 0){
        new id = GetPVarInt(playerid, "LigacaoID");
        MostrarCelularChamada(playerid);
        InformacaoLigacao(playerid, id, false);
        return 1;
    }
    MostrarHome(playerid);
    return 1;
}

stock EnviarLigacao(playerid, id)
{
    if(GetPVarInt(id, "EmLigacao") > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ligação Pendente");
    if(Jogador[playerid][Creditos] <= 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem créditos");

    SetPVarInt(playerid, "EmLigacao", 1);
    SetPVarInt(id, "EmLigacao", 1);

    SetPVarInt(playerid, "LigacaoID", id);
    SetPVarInt(id, "LigacaoID", playerid);

    if(GetPVarInt(id, "CerulaAberto") == 0)
    {
        MostrarNotificacaoCelular(id, "CELULAR TOCANDO");
        PlayerPlaySound(id, 6401, 0.0, 0.0, 0.0);
        //    MostrarCelular(id);
        //    SelectTextDraw(id, 0xFF8C00FF);
        //    SetPVarInt(id, "CerulaAberto", 1);
    }
    
    else if(GetPVarInt(id, "CerulaAberto") == 1){
        if(!strcmp(pCelularEx[id][PagMostrarCelular], "*")) OcultarHome(id);
        else CallRemoteFunction(pCelularEx[id][PagOcultarCelular], "d", id);
        MostrarCelularChamada(id);
        InformacaoLigacao(id, playerid, false);
    }
    
    AdicionarRecente(playerid, Jogador[id][pNumero], PegarNick(id));
    AdicionarRecente(id, Jogador[playerid][pNumero], PegarNick(playerid));

    // Quem está ligando
    OcultarCelularAgenda(playerid);
    MostrarCelularLigacao(playerid);
    InformacaoLigacao(playerid, id, true);
    
    new ttmp = SetTimerEx("CancelarChamadaa", 30000, false, "d", playerid);
    SetPVarInt(playerid, "ChamadTempp", ttmp);
    SetPVarInt(playerid, "Chadsamm", 1); 

    return 1;
}

function CancelarChamadaa(playerid)
{
    new id = GetPVarInt(playerid, "LigacaoID");
    RecusarChamada(playerid, false);
    RecusarChamada(id, false);
    SetPVarInt(playerid, "Chadsamm", 0);
    return 1;
}

stock RecusarChamada(playerid, bool:Saindo = false)
{
    if(GetPVarInt(playerid, "Chadsamm") == 1){
        new id = GetPVarInt(playerid, "ChamadTempp");
        KillTimer(id);
        SetPVarInt(playerid, "Chadsamm", 0);
    }

    PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);

    if(GetPVarInt(playerid, "EmLigacao") == 0) return 1;
    if(GetPVarInt(playerid, "EmLigacao") == 2){
        new id = GetPVarInt(playerid, "Temporizadooor");
        KillTimer(id);
    }
    if(GetPVarInt(playerid, "EmLigacao") > 0 && GetPVarInt(playerid, "EuChamando") == 0){
        if(GetPVarInt(playerid, "EmLigacao") == 1) OcultarChamada(playerid);
        else if(GetPVarInt(playerid, "EmLigacao") == 2) OcultarLigacaoCelular(playerid);
    }
    if(GetPVarInt(playerid, "EuChamando") == 1){
        OcultarLigacaoCelular(playerid);
        SetPVarInt(playerid, "EuChamando", 0); 
    }
    if(Saindo == false && GetPVarInt(playerid, "CerulaAberto") == 1) MostrarCelularRecente(playerid);
    if(GetPVarInt(playerid, "CerulaAberto") == 0) OcultarNotificacaoChamada(playerid);
    SetPVarInt(playerid, "EmLigacao", 0);
    return 1;
}

stock AtenderLigacaoCelular(playerid)
{
    if(GetPVarInt(playerid, "EmLigacao") == 0) return 1;

    if(GetPVarInt(playerid, "Chadsamm") == 1){
        new id = GetPVarInt(playerid, "ChamadTempp");
        KillTimer(id);
        SetPVarInt(playerid, "Chadsamm", 0);
    }
    
    PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
    DeletePVar(playerid, "TempoEmLigacao");

    new id = SetTimerEx("AtualizarTempoLigacao", 1000, true, "d", playerid);
    SetPVarInt(playerid, "Temporizadooor", id);
    SetPVarInt(playerid, "EmLigacao", 2);

    if(GetPVarInt(playerid, "EuChamando") == 1) return 1;
    OcultarChamada(playerid);
    MostrarCelularLigacao(playerid);
    return 1;
}

stock ContatoAgenda(playerid, num)
{
    for(new i=0; i < MAX_NUMEROS; i++)
    {
        if(pAgenda[playerid][i][aUsada] == false) continue;
        if(pAgenda[playerid][i][aNumero] != num) continue; 
        return true;
    }
    return false;
}

stock VerificarNumero(playerid, num, &typin)
{
    new Nomasd[30] = "Desconhecido";
    typin = 0;

    for(new i=0; i < MAX_NUMEROS; i++)
    {
        if(pAgenda[playerid][i][aUsada] == false) continue;
        if(pAgenda[playerid][i][aNumero] != num) continue;
        format(Nomasd, sizeof(Nomasd), "%s", pAgenda[playerid][i][Contato]);
        typin = 1;
        break;
    }
    return(Nomasd);
}

stock AtualizarRecentes(playerid)
{
    new msgf[30],
        typin,
        faix[30];
    
    for(new i=0; i < 5; i++)
    {
        typin = 0;
        if(rCelular[playerid][i][rNumero] == 0) format(msgf, 30, "~r~N/A");
        else format(msgf, sizeof(msgf), "%s", VerificarNumero(playerid, rCelular[playerid][i][rNumero], typin));
        
        switch(typin)
        {
            case 0: faix = "hud:radar_enemyattack";
            case 1: faix = "hud:radar_gangb";
        }
        switch(i)
        {
            case 0:
            {
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][1], faix); 
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][2], ConverterTexto(msgf));
            }
            case 1:
            {
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][4], faix);
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][5], ConverterTexto(msgf));
            }
            case 2:
            {
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][7], faix);
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][8], ConverterTexto(msgf));
            }
            case 3:
            {
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][10], faix);
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][11], ConverterTexto(msgf));
            }
            case 4:
            {
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][13], faix);
                PlayerTextDrawSetString(playerid, CelularRecente[playerid][14], ConverterTexto(msgf));
            }
        }
    }
    return 1;
}

Dialog:AdicionarContatoRecente(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "AddRecente");
    new i = PegarLocalAgenda(playerid); 
    if(i == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem espaço na sua agenda");

    new Enviar[228];
    strcat(Enviar, "INSERT INTO `celular` ");
    strcat(Enviar, "(`Nome`, `Numero`, `NumeroNome`, `Contato`, `Data`) VALUES ");
    strcatEx(Enviar, "('%s', %d, '%s', '%s', %d)", EscapeString(PegarNick(playerid)), rCelular[playerid][id][rNumero], EscapeString(rCelular[playerid][id][rNome]), EscapeString(rCelular[playerid][id][rNome]), gettime());
    mysql_query(IDConexao, Enviar, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Houve um problema ao adicionar esse número");
    
    stringclear(Enviar);
    format(pAgenda[playerid][i][Contato], 30, rCelular[playerid][id][rNome]);
    format(pAgenda[playerid][i][aNome], 30, rCelular[playerid][id][rNome]);
    pAgenda[playerid][i][aNumero] = rCelular[playerid][id][rNumero];
    pAgenda[playerid][i][aUsada] = true;

    format(Enviar, sizeof(Enviar), "| AGENDA | Você adicionou o contato do(a) jogador(a) {fc520f}%s{FFFFFF} na sua agenda", rCelular[playerid][id][rNome]);
    SendClientMessage(playerid, -1, Enviar);
    AtualizarRecentes(playerid);
    return 1;
}

stock SelecionarRecentes(playerid, slot)
{
    if(rCelular[playerid][slot][rNumero] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há nenhum contato aqui");
    if(ContatoAgenda(playerid, rCelular[playerid][slot][rNumero])){
        OcultarCelularRecente(playerid);
        MostrarCelularAgenda(playerid);
        return 1;
    }

    new Dialog[140];
    SetPVarInt(playerid, "AddRecente", slot);
    format(Dialog, sizeof(Dialog), "{FFFFFF}Deseja adicionar o número {CCCCCC}%s{FFFFFF} do(a) {CCCCCC}%s{FFFFFF} na sua agenda?", NumeroSeparar(rCelular[playerid][slot][rNumero]), rCelular[playerid][slot][rNome]);
    Dialog_Show(playerid, AdicionarContatoRecente, DIALOG_STYLE_MSGBOX, rCelular[playerid][slot][rNome], Dialog, "Adicionar", "Cancelar");
    return 1;
}

stock AdicionarRecente(playerid, num, const nma[])
{
    rCelular[playerid][rRecente[playerid]][rNumero] = num;
    format(rCelular[playerid][rRecente[playerid]][rNome], 30, nma);
    rRecente[playerid]++;
    if(rRecente[playerid] > 4) rRecente[playerid] = 0;
    return 1;
}