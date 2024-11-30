stock RequestLoja(playerid, slot, id)
{
    new Catt[30];
    GetPVarString(playerid, "MoveisCategoria", Catt, 30);
    MostrarLoja(playerid, Catt);
    AtualizarLoja(playerid, slot, id, false);
    return 1;
}

stock AtualizarLoja(playerid, slot, id, bool:Decort, bool:ComprarAA = false) 
{
    new Float:kkpX,
        Float:kkpY,
        Float:kkpZ,
        Float:kkpA,
        Obbds,
        dsal[30],
        Precc,
        PreccCoins;
    SetPVarInt(playerid, "MoveisLoja", id);

    if(slot <= 0 && Decort == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está no inicio, vá para frente.");
    if(Decort == true) slot -= 2;
    if(ComprarAA == true) slot -= 1;

    switch(id)
    {
        case 0: // Camas
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(CamasInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = CamasInto[slot][moPosX];
            kkpY = CamasInto[slot][moPosY];
            kkpZ = CamasInto[slot][moPosZ];
            kkpA = CamasInto[slot][moZoom];
            Obbds = CamasInto[slot][moObjeto];
            Precc = CamasInto[slot][moPreco];
            format(dsal, 30, CamasInto[slot][moNome]);
        }
        case 1: // Abajures
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(AbajuresInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = AbajuresInto[slot][moPosX];
            kkpY = AbajuresInto[slot][moPosY];
            kkpZ = AbajuresInto[slot][moPosZ];
            kkpA = AbajuresInto[slot][moZoom];
            Obbds = AbajuresInto[slot][moObjeto];
            Precc = AbajuresInto[slot][moPreco];
            format(dsal, 30, AbajuresInto[slot][moNome]);
        }
        case 2: // Guarda Roupas
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(GuardaRoupasInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = GuardaRoupasInto[slot][moPosX];
            kkpY = GuardaRoupasInto[slot][moPosY];
            kkpZ = GuardaRoupasInto[slot][moPosZ];
            kkpA = GuardaRoupasInto[slot][moZoom];
            Obbds = GuardaRoupasInto[slot][moObjeto];
            Precc = GuardaRoupasInto[slot][moPreco];
            format(dsal, 30, GuardaRoupasInto[slot][moNome]);
        }
        case 3: // Criado Mudo
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(CriadoMudoInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = CriadoMudoInto[slot][moPosX];
            kkpY = CriadoMudoInto[slot][moPosY];
            kkpZ = CriadoMudoInto[slot][moPosZ];
            kkpA = CriadoMudoInto[slot][moZoom];
            Obbds = CriadoMudoInto[slot][moObjeto];
            Precc = CriadoMudoInto[slot][moPreco];
            format(dsal, 30, CriadoMudoInto[slot][moNome]);
        }
        case 4: // Mesa de Escritório
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(MesasEscritorioInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = MesasEscritorioInto[slot][moPosX];
            kkpY = MesasEscritorioInto[slot][moPosY];
            kkpZ = MesasEscritorioInto[slot][moPosZ];
            kkpA = MesasEscritorioInto[slot][moZoom];
            Obbds = MesasEscritorioInto[slot][moObjeto];
            Precc = MesasEscritorioInto[slot][moPreco];
            format(dsal, 30, MesasEscritorioInto[slot][moNome]);
        }
        case 5: // Cadeira de Escritório
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(CadeirasDeEscritorioInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = CadeirasDeEscritorioInto[slot][moPosX];
            kkpY = CadeirasDeEscritorioInto[slot][moPosY];
            kkpZ = CadeirasDeEscritorioInto[slot][moPosZ];
            kkpA = CadeirasDeEscritorioInto[slot][moZoom];
            Obbds = CadeirasDeEscritorioInto[slot][moObjeto];
            Precc = CadeirasDeEscritorioInto[slot][moPreco];
            format(dsal, 30, CadeirasDeEscritorioInto[slot][moNome]);
        }
        case 6: // Vídeo Games
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(VideoGamesInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = VideoGamesInto[slot][moPosX];
            kkpY = VideoGamesInto[slot][moPosY];
            kkpZ = VideoGamesInto[slot][moPosZ];
            kkpA = VideoGamesInto[slot][moZoom];
            Obbds = VideoGamesInto[slot][moObjeto];
            Precc = VideoGamesInto[slot][moPreco];
            format(dsal, 30, VideoGamesInto[slot][moNome]);
        }
        case 7: // Rádios
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(RadiosInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = RadiosInto[slot][moPosX];
            kkpY = RadiosInto[slot][moPosY];
            kkpZ = RadiosInto[slot][moPosZ];
            kkpA = RadiosInto[slot][moZoom];
            Obbds = RadiosInto[slot][moObjeto];
            Precc = RadiosInto[slot][moPreco];
            format(dsal, 30, RadiosInto[slot][moNome]);
        }
        case 8: // Computador
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(ComputadorInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = ComputadorInto[slot][moPosX];
            kkpY = ComputadorInto[slot][moPosY];
            kkpZ = ComputadorInto[slot][moPosZ];
            kkpA = ComputadorInto[slot][moZoom];
            Obbds = ComputadorInto[slot][moObjeto];
            Precc = ComputadorInto[slot][moPreco];
            format(dsal, 30, ComputadorInto[slot][moNome]);
        } 
        case 9: // Televisão
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(TelevisoesInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = TelevisoesInto[slot][moPosX];
            kkpY = TelevisoesInto[slot][moPosY];
            kkpZ = TelevisoesInto[slot][moPosZ];
            kkpA = TelevisoesInto[slot][moZoom];
            Obbds = TelevisoesInto[slot][moObjeto];
            Precc = TelevisoesInto[slot][moPreco];
            format(dsal, 30, TelevisoesInto[slot][moNome]);
        }
        case 10: // Equipamentos de Treino
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(TreinosInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = TreinosInto[slot][moPosX];
            kkpY = TreinosInto[slot][moPosY];
            kkpZ = TreinosInto[slot][moPosZ];
            kkpA = TreinosInto[slot][moZoom];
            Obbds = TreinosInto[slot][moObjeto];
            Precc = TreinosInto[slot][moPreco];
            format(dsal, 30, TreinosInto[slot][moNome]);
        }
        case 11: // Outros
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(OutrosInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = OutrosInto[slot][moPosX];
            kkpY = OutrosInto[slot][moPosY];
            kkpZ = OutrosInto[slot][moPosZ];
            kkpA = OutrosInto[slot][moZoom];
            Obbds = OutrosInto[slot][moObjeto];
            Precc = OutrosInto[slot][moPreco];
            format(dsal, 30, OutrosInto[slot][moNome]);
        }
        case 12: // Sofas
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(SofasInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = SofasInto[slot][moPosX];
            kkpY = SofasInto[slot][moPosY];
            kkpZ = SofasInto[slot][moPosZ];
            kkpA = SofasInto[slot][moZoom];
            Obbds = SofasInto[slot][moObjeto];
            Precc = SofasInto[slot][moPreco];
            format(dsal, 30, SofasInto[slot][moNome]);
        }
        case 13: // Centros e Mesas
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(CentrosInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = CentrosInto[slot][moPosX];
            kkpY = CentrosInto[slot][moPosY];
            kkpZ = CentrosInto[slot][moPosZ];
            kkpA = CentrosInto[slot][moZoom];
            Obbds = CentrosInto[slot][moObjeto];
            Precc = CentrosInto[slot][moPreco];
            format(dsal, 30, CentrosInto[slot][moNome]);
        }
        case 14: // Quadros
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(QuadrosInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = QuadrosInto[slot][moPosX];
            kkpY = QuadrosInto[slot][moPosY];
            kkpZ = QuadrosInto[slot][moPosZ];
            kkpA = QuadrosInto[slot][moZoom];
            Obbds = QuadrosInto[slot][moObjeto];
            Precc = QuadrosInto[slot][moPreco];
            format(dsal, 30, QuadrosInto[slot][moNome]);
        }
        case 15: // Boxes e Banheiras
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(BoxesInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = BoxesInto[slot][moPosX];
            kkpY = BoxesInto[slot][moPosY];
            kkpZ = BoxesInto[slot][moPosZ];
            kkpA = BoxesInto[slot][moZoom];
            Obbds = BoxesInto[slot][moObjeto];
            Precc = BoxesInto[slot][moPreco];
            format(dsal, 30, BoxesInto[slot][moNome]); 
        }
        case 16: // Pias e Bacias
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(PiasInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = PiasInto[slot][moPosX];
            kkpY = PiasInto[slot][moPosY];
            kkpZ = PiasInto[slot][moPosZ];
            kkpA = PiasInto[slot][moZoom];
            Obbds = PiasInto[slot][moObjeto];
            Precc = PiasInto[slot][moPreco];
            format(dsal, 30, PiasInto[slot][moNome]);
        }
        case 17: // Pias e Bacias
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(BanheiroOutrosInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = BanheiroOutrosInto[slot][moPosX];
            kkpY = BanheiroOutrosInto[slot][moPosY];
            kkpZ = BanheiroOutrosInto[slot][moPosZ];
            kkpA = BanheiroOutrosInto[slot][moZoom];
            Obbds = BanheiroOutrosInto[slot][moObjeto];
            Precc = BanheiroOutrosInto[slot][moPreco];
            format(dsal, 30, BanheiroOutrosInto[slot][moNome]);
        }
        case 18: // Cadeiras
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(CadeirasCozinhaInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = CadeirasCozinhaInto[slot][moPosX];
            kkpY = CadeirasCozinhaInto[slot][moPosY];
            kkpZ = CadeirasCozinhaInto[slot][moPosZ];
            kkpA = CadeirasCozinhaInto[slot][moZoom];
            Obbds = CadeirasCozinhaInto[slot][moObjeto];
            Precc = CadeirasCozinhaInto[slot][moPreco];
            format(dsal, 30, CadeirasCozinhaInto[slot][moNome]);
        }
        case 19: // Cadeiras
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(MesasCozinhaInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = MesasCozinhaInto[slot][moPosX];
            kkpY = MesasCozinhaInto[slot][moPosY];
            kkpZ = MesasCozinhaInto[slot][moPosZ];
            kkpA = MesasCozinhaInto[slot][moZoom];
            Obbds = MesasCozinhaInto[slot][moObjeto];
            Precc = MesasCozinhaInto[slot][moPreco];
            format(dsal, 30, MesasCozinhaInto[slot][moNome]);
        }
        case 20: // Cozinha Eletrônicos
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(EletronicosCozinhaInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = EletronicosCozinhaInto[slot][moPosX];
            kkpY = EletronicosCozinhaInto[slot][moPosY];
            kkpZ = EletronicosCozinhaInto[slot][moPosZ];
            kkpA = EletronicosCozinhaInto[slot][moZoom];
            Obbds = EletronicosCozinhaInto[slot][moObjeto];
            Precc = EletronicosCozinhaInto[slot][moPreco];
            format(dsal, 30, EletronicosCozinhaInto[slot][moNome]); 
        }
        case 21: // Outros - Cozinha
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(OutrosCozinhaInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = OutrosCozinhaInto[slot][moPosX];
            kkpY = OutrosCozinhaInto[slot][moPosY];
            kkpZ = OutrosCozinhaInto[slot][moPosZ];
            kkpA = OutrosCozinhaInto[slot][moZoom];
            Obbds = OutrosCozinhaInto[slot][moObjeto];
            Precc = OutrosCozinhaInto[slot][moPreco];
            format(dsal, 30, OutrosCozinhaInto[slot][moNome]); 
        }
        case 22: // Plantas
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(PlantasInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = PlantasInto[slot][moPosX];
            kkpY = PlantasInto[slot][moPosY];
            kkpZ = PlantasInto[slot][moPosZ];
            kkpA = PlantasInto[slot][moZoom];
            Obbds = PlantasInto[slot][moObjeto];
            Precc = PlantasInto[slot][moPreco];
            PreccCoins = PlantasInto[slot][moPrecoCoins];
            format(dsal, 30, PlantasInto[slot][moNome]);
        }
        case 23: // Outros - Sala
        {
            if(ComprarAA == false && Decort == false && slot >= sizeof(OutrosSalaInto)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você chegou no final, volte.");
            kkpX = OutrosSalaInto[slot][moPosX];
            kkpY = OutrosSalaInto[slot][moPosY];
            kkpZ = OutrosSalaInto[slot][moPosZ];
            kkpA = OutrosSalaInto[slot][moZoom];
            Obbds = OutrosSalaInto[slot][moObjeto];
            Precc = OutrosSalaInto[slot][moPreco];
            PreccCoins = OutrosSalaInto[slot][moPrecoCoins];
            format(dsal, 30, OutrosSalaInto[slot][moNome]);   
        }
    }

    if(ComprarAA == true)
    {
        OcultarLoja(playerid);
        if(Precc > Jogador[playerid][Dinheiro]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
        if(PreccCoins > Jogador[playerid][Coins]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem coins suficiente");
        new MinhaCasa = MinhaCasaIDEx(playerid),
            iiid = PegarMovel(MinhaCasa);
        if(MinhaCasa == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem uma casa");
        if(iiid == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua casa não tem espaço para móveis.");
        if(pCasa[MinhaCasa][cJPreco] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua casa está a venda e você não pode comprar móveis");

        new Mensagem[148];
        format(Mensagem, sizeof(Mensagem), "| LOJA | Você comprou o(a) {00BFFF}%s{FFFFFF} por {32CD32}$%s{FFFFFF}, aguarde até que chegue até sua casa", dsal, DinheiroSeparar(Precc));
        SendClientMessage(playerid, -1, Mensagem);

        eMoveis[MinhaCasa][MoveisQuantidade]++;

        Jogador[playerid][Dinheiro] -= Precc;
        Jogador[playerid][Coins] -= PreccCoins;

        AdicionarMovelCasa(MinhaCasa, iiid, Obbds, dsal, PreccCoins, Precc);  
        return 1;
    }

    slot++;
    SetPVarInt(playerid, "MoveisSlot", slot);
    PlayerTextDrawSetString(playerid, LojaMoveis[playerid][9], ConverterTexto(dsal));
    PlayerTextDrawSetString(playerid, LojaMoveis[playerid][11], DinheiroSeparar(Precc));
    PlayerTextDrawSetPreviewModel(playerid, LojaMoveis[playerid][4], Obbds);
    PlayerTextDrawSetPreviewRot(playerid, LojaMoveis[playerid][4], kkpX, kkpY, kkpZ, kkpA);
    PlayerTextDrawShow(playerid, LojaMoveis[playerid][4]);
    return 1;
}

stock EnviarLoja(playerid, const CatLoja[])
{
    new Dialog[350];
    SetPVarInt(playerid, "MoveisLoja", 0);
    SetPVarInt(playerid, "MoveisSlot", 0);
    SetPVarString(playerid, "MoveisCategoria", CatLoja);

    if(!strcmp(CatLoja, "Quarto")){
        strcat(Dialog, "1. Camas\n");
        strcat(Dialog, "2. Abajures\n");
        strcat(Dialog, "3. Guarda Roupas\n");
        strcat(Dialog, "4. Criados Mudo");
        Dialog_Show(playerid, QuartoLoja, DIALOG_STYLE_TABLIST, "{32CD32}[Loja]: Móveis", Dialog, "Selecionar", "Fechar");
    }

    else if(!strcmp(CatLoja, "Eletrônicos")){
        strcat(Dialog, "1. Mesas de Escritório\n");
        strcat(Dialog, "2. Cadeiras de Escritório\n");
        strcat(Dialog, "3. Video Games\n");
        strcat(Dialog, "4. Rádios e Sons\n");
        strcat(Dialog, "5. Computadores\n");
        strcat(Dialog, "6. Televisões\n");
        strcat(Dialog, "7. Equipamentos de Treinos\n");
        strcat(Dialog, "8. Outros");
        Dialog_Show(playerid, EletronicoLoja, DIALOG_STYLE_TABLIST, "{32CD32}[Loja]: Móveis", Dialog, "Selecionar", "Fechar");  
    }

    else if(!strcmp(CatLoja, "Sala")){
        strcat(Dialog, "1. Sofás\n");
        strcat(Dialog, "2. Centros e Mesas\n");
        strcat(Dialog, "3. Quadros\n");
        strcat(Dialog, "4. Outros");
        Dialog_Show(playerid, SalaLoja, DIALOG_STYLE_TABLIST, "{32CD32}[Loja]: Móveis", Dialog, "Selecionar", "Fechar");
    }

    else if(!strcmp(CatLoja, "Banheiro")){
        strcat(Dialog, "1. Boxes e Banheiras\n");
        strcat(Dialog, "2. Pias e Privadas\n");
        strcat(Dialog, "3. Outros");
        Dialog_Show(playerid, BanheiroLoja, DIALOG_STYLE_TABLIST, "{32CD32}[Loja]: Móveis", Dialog, "Selecionar", "Fechar");
    }

    else if(!strcmp(CatLoja, "Cozinha")){
        strcat(Dialog, "1. Cadeiras\n");
        strcat(Dialog, "2. Mesas\n");
        strcat(Dialog, "3. Eletrônicos\n");
        strcat(Dialog, "4. Outros");
        Dialog_Show(playerid, CozinhaLoja, DIALOG_STYLE_TABLIST, "{32CD32}[Loja]: Móveis", Dialog, "Selecionar", "Fechar");
    }
    else if(!strcmp(CatLoja, "Plantas")) RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 22); // Plantas
    return 1;
}