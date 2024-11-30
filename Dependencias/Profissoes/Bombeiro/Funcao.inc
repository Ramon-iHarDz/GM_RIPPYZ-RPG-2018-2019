stock VerificarEspacoBombeiro(playerid)
{
    new JhGa = 0;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(pBombeiroDupla[playerid][i][EmDuplaBombeiro] == false) continue;
        JhGa++;
    }
    if(JhGa > 2) return false;
    return true;
}

stock RetirarBombeiro(playerid)
{   
    pBombeiro[playerid][BombeiraDupla] = false;
    new id = pBombeiro[playerid][DonoBombeiro];

    if(pBombeiro[playerid][ApagandoFogo] == true)
    {
        DestroyDynamicMapIconEx(pBombeiro[playerid][BombeiroIcone]);
        pBombeiro[playerid][ApagandoFogo] = false;
    }
    if(playerid == id)
    {
        ResetarFogo(playerid);
        ResetarTrabalhoBombeiro(playerid);
        return 1;
    }
    pBombeiroDupla[id][playerid][EmDuplaBombeiro] = false;
    return 1;
}

stock ResetarFogo(playerid)
{
    for(new i=0; i < MAX_FOGOS; i++)
    {
        if(pFogo[playerid][i][FogoAtivo] == false) continue; 
        DestroyDynamic3DTextLabelEx(pFogo[playerid][i][TextoFogo]);
        DestroyDynamicObjectEx(pFogo[playerid][i][FogoID]);
        pFogo[playerid][i][PorcentagemFogo] = 0;
        pFogo[playerid][i][FogoAtivo] = false;
    }
    return 1;
}

stock ResetarTrabalhoBombeiro(playerid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(pBombeiroDupla[playerid][i][EmDuplaBombeiro] == false) continue;
        pBombeiroDupla[playerid][i][EmDuplaBombeiro] = false;
        pBombeiro[i][BombeiraDupla] = false;
        if(pBombeiro[i][ApagandoFogo] == true)
        {
            DestroyDynamicMapIconEx(pBombeiro[i][BombeiroIcone]);
            pBombeiro[i][ApagandoFogo] = false;
        }
    }
    return 1;
}

stock ApagandoFogoBombeiro(playerid)
{
    new Cgah = 0;
    for(new i=0; i < MAX_FOGOS; i++)
    {
        if(pFogo[playerid][i][PorcentagemFogo] < 1) continue;
        Cgah++;
    } 
    if(Cgah > 0) return true;
    return false;
}

stock PegarEmpresaBombeiro()
{
    new id;
    for(new i=0; i < 999999; i++)
    {
        id = random(MAX_EMPRESAS);
        if(pEmpresa[id][Colocado] == false) continue;
        return id;
    }
    return -1;
}

stock SeAindaTemFogo(playerid)
{
    new id = pBombeiro[playerid][DonoBombeiro],
        Contaasda = 0
    ;
    for(new i=0; i < MAX_FOGOS; i++)
    {
        if(pFogo[id][i][PorcentagemFogo] < 1) continue;
        Contaasda++;
    }
    if(Contaasda > 0) return true;
    return false;
}

stock FinalizarFogo(playerid)
{
    if(pBombeiro[playerid][ApagandoFogo] == true) DestroyDynamicMapIconEx(pBombeiro[playerid][BombeiroIcone]);
    pBombeiro[playerid][ApagandoFogo] = false;
    ResetarFogo(playerid);
    new Mensagem[128],
        VPreco = random(900-700)+700;
    format(Mensagem, sizeof(Mensagem), "| BOMBEIRO | Fogo pelo local foi controlado pela equipe e você recebeu $%s", DinheiroSeparar(VPreco));
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);
    Jogador[playerid][Dinheiro] += VPreco;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(pBombeiroDupla[playerid][i][EmDuplaBombeiro] == false) continue;
        SendClientMessage(i, 0xFFA500FF, Mensagem);
        if(pBombeiro[i][ApagandoFogo] == true) DestroyDynamicMapIconEx(pBombeiro[i][BombeiroIcone]);
        pBombeiro[i][ApagandoFogo] = false;
        Jogador[i][Dinheiro] += VPreco;
    }
    return 1;
}

stock IniciarFogo(playerid)
{
    new id = PegarEmpresaBombeiro();
    if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nenhuma empresa foi encontrada pegando fogo!");
    
    new Float:X,
	    Float:Y,
        Casda = 0,
        Mensagem[128]
	;

    FrentePosicao(pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoA], float(random(5-2)+2), X, Y);
    for(new i=0; i < MAX_FOGOS; i++)
    {
        pFogo[playerid][i][PorcentagemFogo] = 100;
        pFogo[playerid][i][FogoAtivo] = true;
        if(random(100) > 49) Y+=float(random(9));
		else Y-=float(random(9));

        pFogo[playerid][i][FogoX] = X;
        pFogo[playerid][i][FogoY] = Y;
        pFogo[playerid][i][FogoZ] = pEmpresa[id][ePosicaoZ];

        format(Mensagem, sizeof(Mensagem), "Equipe do(a) bombeiro(a) %s[%d]\n{FFFFFF}Fogo Controlado {CCCCCC}%d / 0", PegarNick(playerid), playerid, pFogo[playerid][i][PorcentagemFogo]);
        pFogo[playerid][i][FogoID] = CreateDynamicObject(18692, X, Y, pEmpresa[id][ePosicaoZ]-2, 0.0, 0.0, 0.0, 0, 0, -1, 80.0, 80.0, -1, 0);
        pFogo[playerid][i][TextoFogo] = CreateDynamic3DTextLabel(Mensagem, 0xFFA500FF, X, Y, pEmpresa[id][ePosicaoZ], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 15.0, -1, 0);  
        Casda++;
        if(Casda > 3) break;
    }

    format(Mensagem, sizeof(Mensagem), "| BOMBEIRO | Está acontecendo um incêndio na empresa id %d, vá até o local", id);
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);
    
    // Informações
    pBombeiro[playerid][ApagandoFogo] = true;
    pBombeiro[playerid][BombeiroIcone] = CreateDynamicMapIcon(pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ], 20, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(pBombeiroDupla[playerid][i][EmDuplaBombeiro] == false) continue;
        SendClientMessage(i, 0xFFA500FF, Mensagem);

        pBombeiro[i][ApagandoFogo] = true;
        pBombeiro[i][BombeiroIcone] = CreateDynamicMapIcon(pEmpresa[id][ePosicaoX], pEmpresa[id][ePosicaoY], pEmpresa[id][ePosicaoZ], 20, -1, 0, 0, i, 999999.9, MAPICON_GLOBAL, -1);
    }

    return 1;
}