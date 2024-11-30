#include <YSI_Coding\y_hooks>

enum GpsInfo
{
    bool:GpsMarcado,
    MapaIconGps,
    Float:GPos[3],
    TempoGps,
    ProfGpsSelect[90]
};

enum ULb
{
    bool:GpsUsando,
    LocalN[90]
};

new Catel[MAX_PLAYERS][sizeof(Pick)][ULb];
new pGps[MAX_PLAYERS][GpsInfo];

CMD:gps(playerid)
{
    if(Jogador[playerid][Level] > 5){
        if(Jogador[playerid][Admin] < 1) return 0;
    }
    if(Jogador[playerid][Level] < 6 && Jogador[playerid][Admin] < 1) SendClientMessage(playerid, 0x32CD32FF, "| GPS | Você tem o GPS até o level 5");
    MostrarGPS(playerid);
    return 1;
}

stock MostrarGPS(playerid)
{
    new Dialog[300];
    strcat(Dialog, "Los Santos\n");
    strcat(Dialog, "San Fierro\n");
    strcat(Dialog, "Las Venturas\n");
    strcat(Dialog, "Máfia\n");
    strcat(Dialog, "Locais de Trabalhos\n");
    strcat(Dialog, "Utilitários\n");
    strcat(Dialog, "Hoteis\n");
    strcat(Dialog, "Hobbies\n");
    strcat(Dialog, "{f5bc42}Minhas Propriedades\n");
    strcat(Dialog, "{FF0000}Desmarcar");
    Dialog_Show(playerid, GpsMenu, DIALOG_STYLE_TABLIST, "{FF0000}Gps", Dialog, "Selecionar", "Fechar");
    return 1;
}

stock LimparCatel(playerid)
{
    new DeletaCCCr[ULb];
    for(new i=0; i < sizeof(Pick); i++){
        Catel[playerid][i] = DeletaCCCr;
    }
    return 1;
}

Dialog:CategoriaGps(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new gpsq = 0,
        CiaLo[90],
        LocLo[90];

    GetPVarString(playerid, "CiaLoc", CiaLo, 90);
    GetPVarString(playerid, "LocLoc", LocLo, 90);
    for(new i=0; i < sizeof(Pick); i++)
    {
        if(strcmp(Pick[i][RegiaoGPS], CiaLo)) continue;
        if(strcmp(Pick[i][MensagemPickup], LocLo)) continue;
        if(gpsq != listitem){
            gpsq++;
            continue;
        }
        EnviarGps(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
        break;
    }
    return 1; 
}

Dialog:GpsLS(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;    

    LimparCatel(playerid);
    new bool:Cnna = false,
        Dialog[1000],
        Anteggg[90],
        gpsq = 0,
        bool:UmaVz = false;
    for(new i=0; i < sizeof(Pick); i++)
    {
        if(strcmp(Pick[i][RegiaoGPS], "Los Santos")) continue;
        if(!strcmp(Anteggg, Pick[i][MensagemPickup]) && UmaVz == true) continue;
        if(UmaVz == false) UmaVz = true;
        if(Cnna == true) Cnna = false;

        for(new j=0; j < sizeof(Pick); j++){
            if(Catel[playerid][j][GpsUsando] == false) continue;
            if(strcmp(Catel[playerid][j][LocalN], Pick[i][MensagemPickup])) continue;
            Cnna = true;
            break;
        }

        if(VerificarGpsMais("Los Santos", Pick[i][MensagemPickup]) > 1 && Cnna == false){
            for(new j=0; j < sizeof(Pick); j++){
                if(Catel[playerid][j][GpsUsando] == true) continue;
                Catel[playerid][j][GpsUsando] = true;
                Cnna = true;
                format(Catel[playerid][j][LocalN], 90, Pick[i][MensagemPickup]);
                format(Anteggg, 90, Pick[i][MensagemPickup]);
                break;
            }
        }

        if(gpsq != listitem)
        {
            gpsq++;
            continue;
        }

        if(Cnna == true)
        {
            SetPVarString(playerid, "CiaLoc", "Los Santos");
            SetPVarString(playerid, "LocLoc", Pick[i][MensagemPickup]);
            strcat(Dialog, "Local\tRegiao\tDistancia\n");
            for(new j=0; j < sizeof(Pick); j++)
            {
                if(strcmp(Pick[j][RegiaoGPS], "Los Santos")) continue;
                if(strcmp(Pick[j][MensagemPickup], Pick[i][MensagemPickup])) continue;
                strcatEx(Dialog, "{CCCCCC}%s\t{00BFFF}%s\t{FF4500}%0.2f\n", Pick[j][MensagemPickup], AreaNome(Pick[j][EntradaX], Pick[j][EntradaY], Pick[j][EntradaZ]), GetPlayerDistanceFromPoint(playerid, Pick[j][EntradaX], Pick[j][EntradaY], Pick[j][EntradaZ]));
            }
            Dialog_Show(playerid, CategoriaGps, DIALOG_STYLE_TABLIST_HEADERS, Pick[i][MensagemPickup], Dialog, "Selecionar", "Fechar");
        }
        else EnviarGps(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
        break;
    }
    return 0;
}

Dialog:GpsSF(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    LimparCatel(playerid);
    new bool:Cnna = false,
        Dialog[1000],
        Anteggg[90],
        gpsq = 0,
        bool:UmaVz = false
    ;
    for(new i=0; i < sizeof(Pick); i++)
    {
        if(strcmp(Pick[i][RegiaoGPS], "San Fierro")) continue;
        if(!strcmp(Anteggg, Pick[i][MensagemPickup]) && UmaVz == true) continue;
        if(UmaVz == false) UmaVz = true;
        if(Cnna == true) Cnna = false;

        for(new j=0; j < sizeof(Pick); j++){
            if(Catel[playerid][j][GpsUsando] == false) continue;
            if(strcmp(Catel[playerid][j][LocalN], Pick[i][MensagemPickup])) continue;
            Cnna = true;
            break;
        }

        if(VerificarGpsMais("San Fierro", Pick[i][MensagemPickup]) > 1 && Cnna == false){
            for(new j=0; j < sizeof(Pick); j++){
                if(Catel[playerid][j][GpsUsando] == true) continue;
                Catel[playerid][j][GpsUsando] = true;
                Cnna = true;
                format(Catel[playerid][j][LocalN], 90, Pick[i][MensagemPickup]);
                format(Anteggg, 90, Pick[i][MensagemPickup]);
                break;
            }
        }

        if(gpsq != listitem)
        {
            gpsq++;
            continue;
        }

        if(Cnna == true)
        {
            SetPVarString(playerid, "CiaLoc", "San Fierro");
            SetPVarString(playerid, "LocLoc", Pick[i][MensagemPickup]);
            strcat(Dialog, "Local\tRegiao\tDistancia\n");
            for(new j=0; j < sizeof(Pick); j++)
            {
                if(strcmp(Pick[j][RegiaoGPS], "San Fierro")) continue;
                if(strcmp(Pick[j][MensagemPickup], Pick[i][MensagemPickup])) continue;
                strcatEx(Dialog, "{CCCCCC}%s\t{00BFFF}%s\t{FF4500}%0.2f\n", Pick[j][MensagemPickup], AreaNome(Pick[j][EntradaX], Pick[j][EntradaY], Pick[j][EntradaZ]), GetPlayerDistanceFromPoint(playerid, Pick[j][EntradaX], Pick[j][EntradaY], Pick[j][EntradaZ]));
            }
            Dialog_Show(playerid, CategoriaGps, DIALOG_STYLE_TABLIST_HEADERS, Pick[i][MensagemPickup], Dialog, "Selecionar", "Fechar");
        }
        else EnviarGps(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
        break;
    }
    return 0;
}

Dialog:GpsLV(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    LimparCatel(playerid);
    new bool:Cnna = false,
        Dialog[1000],
        Anteggg[90],
        gpsq = 0,
        bool:UmaVz = false
    ;
    for(new i=0; i < sizeof(Pick); i++)
    {
        if(strcmp(Pick[i][RegiaoGPS], "Las Venturas")) continue;
        if(!strcmp(Anteggg, Pick[i][MensagemPickup]) && UmaVz == true) continue;
        if(UmaVz == false) UmaVz = true;
        if(Cnna == true) Cnna = false;

        for(new j=0; j < sizeof(Pick); j++){
            if(Catel[playerid][j][GpsUsando] == false) continue;
            if(strcmp(Catel[playerid][j][LocalN], Pick[i][MensagemPickup])) continue;
            Cnna = true;
            break;
        }

        if(VerificarGpsMais("Las Venturas", Pick[i][MensagemPickup]) > 1 && Cnna == false){
            for(new j=0; j < sizeof(Pick); j++){
                if(Catel[playerid][j][GpsUsando] == true) continue;
                Catel[playerid][j][GpsUsando] = true;
                Cnna = true;
                format(Catel[playerid][j][LocalN], 90, Pick[i][MensagemPickup]);
                format(Anteggg, 90, Pick[i][MensagemPickup]);
                break;
            }
        }

        if(gpsq != listitem)
        {
            gpsq++;
            continue;
        }

        if(Cnna == true)
        {
            SetPVarString(playerid, "CiaLoc", "Las Venturas");
            SetPVarString(playerid, "LocLoc", Pick[i][MensagemPickup]);
            strcat(Dialog, "Local\tRegiao\tDistancia\n");
            for(new j=0; j < sizeof(Pick); j++)
            {
                if(strcmp(Pick[j][RegiaoGPS], "Las Venturas")) continue;
                if(strcmp(Pick[j][MensagemPickup], Pick[i][MensagemPickup])) continue;
                strcatEx(Dialog, "{CCCCCC}%s\t{00BFFF}%s\t{FF4500}%0.2f\n", Pick[j][MensagemPickup], AreaNome(Pick[j][EntradaX], Pick[j][EntradaY], Pick[j][EntradaZ]), GetPlayerDistanceFromPoint(playerid, Pick[j][EntradaX], Pick[j][EntradaY], Pick[j][EntradaZ]));
            }
            Dialog_Show(playerid, CategoriaGps, DIALOG_STYLE_TABLIST_HEADERS, Pick[i][MensagemPickup], Dialog, "Selecionar", "Fechar");
        }
        else EnviarGps(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
        break;
    }
    return 0;
}

Dialog:GpsMafia(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: EnviarGps(playerid, -1818.3098, 1144.9598, 45.4528); // Contratação
        case 1: EnviarGps(playerid, 2314.3752,56.4010,26.4809); // Local Venda
        case 2: EnviarGps(playerid, -1717.9353, 12.4277, 3.4447); // Desmanche
        case 3: EnviarGps(playerid, -2148.6252,-242.3781,36.5156); // Produtor da Máfia
    }
    return 1;
}

Dialog:GpsHobbie(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: EnviarGps(playerid, -1827.7117, 1537.7666, 7.1875); // Produção Drogas 
    }
    return 1;
}

Dialog:GosHQMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Contagem = 0;
    new CategoriaS[70];
    new Dialog[900];

    switch(listitem)
    {
        case 0: CategoriaS = "Honestas";
        case 1: CategoriaS = "Transportes"; 
        case 2: CategoriaS = "Governo";
        case 3: CategoriaS = "Serviços Publicos";
        case 4: CategoriaS = "Mafia";    
    }

    strcat(Dialog, "Profissão\tDistância\n");
    for(new i=0; i < sizeof(pAgencia); i++)
    {
        if(strcmp(pAgencia[i][Categoria], CategoriaS)) continue;
        strcatEx(Dialog, "%s\t{00BFFF}%0.2f\n", pAgencia[i][ProfissaoNome], GetPlayerDistanceFromPoint(playerid, pAgencia[i][HQx], pAgencia[i][HQy], pAgencia[i][HQz]));
        Contagem++;
    }

    if(Contagem < 1){
        SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Essa categoria está vázia!");
        return 1;
    }

    new Titulo[70];
    format(Titulo, sizeof(Titulo), "{FF4500}Categoria %s", CategoriaS);
    format(pGps[playerid][ProfGpsSelect], 70, CategoriaS); 
    Dialog_Show(playerid, SelecionarHQLocal, DIALOG_STYLE_TABLIST_HEADERS, Titulo, Dialog, "Selecionar", "Fechar");  
    return 0;
}

Dialog:LocalizarPropriedades(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Float:PosPPR[3],
        idd,
        Mensagem[55];
    switch(listitem)
    {
        case 0:
        {
            idd = MinhaCasaID(playerid);
            if(idd == -1) return 1;
            PosPPR[0] = pCasa[idd][cPosicaoX];
            PosPPR[1] = pCasa[idd][cPosicaoY];
            PosPPR[2] = pCasa[idd][cPosicaoZ];
            format(Mensagem, sizeof(Mensagem), "| GPS | Você está localizando sua casa ( ID: %d )", idd);
        }
        case 1:
        {
            idd = MinhaEmpresaID(playerid);
            if(idd == -1) return 1;
            PosPPR[0] = pEmpresa[idd][ePosicaoX];
            PosPPR[1] = pEmpresa[idd][ePosicaoY];
            PosPPR[2] = pEmpresa[idd][ePosicaoZ];
            format(Mensagem, sizeof(Mensagem), "| GPS | Você está localizando sua empresa ( ID: %d )", idd);
        }
        case 2:
        {
            idd = Jogador[playerid][BaseID];
            if(idd == 0) return 1;
            PosPPR[0] = Base[idd][BaseX];
            PosPPR[1] = Base[idd][BaseY];
            PosPPR[2] = Base[idd][BaseZ];
            format(Mensagem, sizeof(Mensagem), "| GPS | Você está localizando sua base ( ID: %d )", idd);    
        }
        case 3:
        {
            idd = ProcurarFabricaID(PegarNick(playerid));
            if(idd == -1) return 1;
            PosPPR[0] = pFabrica[idd][fPosicaoX];
            PosPPR[1] = pFabrica[idd][fPosicaoY];
            PosPPR[2] = pFabrica[idd][fPosicaoZ];
            format(Mensagem, sizeof(Mensagem), "| GPS | Você está localizando sua fábrica ( ID: %d )", idd);    
        }
    }
    EnviarGps(playerid, PosPPR[0], PosPPR[1], PosPPR[2]);
    SendClientMessage(playerid, 0x32CD32FF, Mensagem);
    return 1;
}

Dialog:SelecionarHQLocal(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Select = 0;
    for(new i=0; i < sizeof(pAgencia); i++)
    {
        if(strcmp(pAgencia[i][Categoria], pGps[playerid][ProfGpsSelect])) continue;
        if(Select == listitem)
        {
            EnviarGps(playerid, pAgencia[i][HQx], pAgencia[i][HQy], pAgencia[i][HQz]);
            SendClientMessage(playerid, 0x32CD32FF, "| GPS | Local da HQ foi marcado em seu mapa");
            break; 
        }
        Select++; 
    }   
    return 1;
}

Dialog:SelecionarUTLGps(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Select = 0;
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        if(pEmpresa[i][eInterior] != 31 && pEmpresa[i][eInterior] != 30 && pEmpresa[i][eInterior] != 1) continue;
        if(Select == listitem)
        {
            EnviarGps(playerid, pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ]);
            SendClientMessage(playerid, 0x32CD32FF, "| GPS | Utiliários foi marcada em seu MAPA"); 
            break;
        }
        Select++; 
    }   
    return 1;
}

Dialog:SelecionarHOTELGps(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Select = 0;
    for(new i=0; i < MAX_EMPRESAS; i++)
    {
        if(pEmpresa[i][Colocado] == false) continue;
        if(pEmpresa[i][eInterior] != 38) continue;
        if(Select == listitem)
        {
            EnviarGps(playerid, pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ]);
            SendClientMessage(playerid, 0x32CD32FF, "| GPS | Hotel foi marcada em seu MAPA"); 
            break;
        }
        Select++; 
    }   
    return 1;
}

stock VerificarGpsMais(const Cia[], const LocalNA[])
{
    new ca = 0;
    for(new i=0; i < sizeof(Pick); i++){
        if(strcmp(Pick[i][RegiaoGPS], Cia)) continue;
        if(strcmp(Pick[i][MensagemPickup], LocalNA)) continue;
        ca++;
    }
    return ca;
}

Dialog:GpsMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new Dialog[1500],
        bool:Cnna = false
    ;

    LimparCatel(playerid);
    switch(listitem)
    {
        case 0:
        {
            strcat(Dialog, "Local\tRegiao\tDistancia\n");
            for(new i=0; i < sizeof(Pick); i++)
            {
                if(strcmp(Pick[i][RegiaoGPS], "Los Santos")) continue;
                if(Cnna == true) Cnna = false;

                for(new j=0; j < sizeof(Pick); j++){
                    if(Catel[playerid][j][GpsUsando] == false) continue;
                    if(strcmp(Catel[playerid][j][LocalN], Pick[i][MensagemPickup])) continue;
                    Cnna = true;
                    break;
                }

                if(Cnna == true) continue;

                if(VerificarGpsMais("Los Santos", Pick[i][MensagemPickup]) > 1)
                {
                    strcatEx(Dialog, "{FFA500}» {FFFFFF}%s\n", Pick[i][MensagemPickup]);
                    for(new j=0; j < sizeof(Pick); j++){
                        if(Catel[playerid][j][GpsUsando] == true) continue;
                        Catel[playerid][j][GpsUsando] = true;
                        format(Catel[playerid][j][LocalN], 90, Pick[i][MensagemPickup]);
                        break;
                    }
                }
                else strcatEx(Dialog, "{CCCCCC}%s\t{00BFFF}%s\t{FF4500}%0.2f\n", Pick[i][MensagemPickup], AreaNome(Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]), GetPlayerDistanceFromPoint(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]));
            }
            Dialog_Show(playerid, GpsLS, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Los Santos", Dialog, "Selecionar", "Cancelar");
        }
        case 1:
        {
            strcat(Dialog, "Local\tRegiao\tDistancia\n");
            for(new i=0; i < sizeof(Pick); i++)
            {
                if(strcmp(Pick[i][RegiaoGPS], "San Fierro")) continue;
                if(Cnna == true) Cnna = false;

                for(new j=0; j < sizeof(Pick); j++){
                    if(Catel[playerid][j][GpsUsando] == false) continue;
                    if(strcmp(Catel[playerid][j][LocalN], Pick[i][MensagemPickup])) continue;
                    Cnna = true;
                    break;
                }

                if(Cnna == true) continue;

                if(VerificarGpsMais("San Fierro", Pick[i][MensagemPickup]) > 1)
                {
                    strcatEx(Dialog, "{FFA500}» {FFFFFF}%s\n", Pick[i][MensagemPickup]);
                    for(new j=0; j < sizeof(Pick); j++){
                        if(Catel[playerid][j][GpsUsando] == true) continue;
                        Catel[playerid][j][GpsUsando] = true;
                        format(Catel[playerid][j][LocalN], 90, Pick[i][MensagemPickup]);
                        break;
                    }
                }
                else strcatEx(Dialog, "{CCCCCC}%s\t{00BFFF}%s\t{FF4500}%0.2f\n", Pick[i][MensagemPickup], AreaNome(Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]), GetPlayerDistanceFromPoint(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]));
            } 
            Dialog_Show(playerid, GpsSF, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}San Fierro", Dialog, "Selecionar", "Cancelar");
        }
        case 2:
        {
            strcat(Dialog, "Local\tRegiao\tDistancia\n");
            for(new i=0; i < sizeof(Pick); i++)
            {
                if(strcmp(Pick[i][RegiaoGPS], "Las Venturas")) continue;
                if(Cnna == true) Cnna = false;

                for(new j=0; j < sizeof(Pick); j++){
                    if(Catel[playerid][j][GpsUsando] == false) continue;
                    if(strcmp(Catel[playerid][j][LocalN], Pick[i][MensagemPickup])) continue;
                    Cnna = true;
                    break;
                }

                if(Cnna == true) continue;

                if(VerificarGpsMais("Las Venturas", Pick[i][MensagemPickup]) > 1)
                {
                    strcatEx(Dialog, "{FFA500}» {FFFFFF}%s\n", Pick[i][MensagemPickup]);
                    for(new j=0; j < sizeof(Pick); j++){
                        if(Catel[playerid][j][GpsUsando] == true) continue;
                        Catel[playerid][j][GpsUsando] = true;
                        format(Catel[playerid][j][LocalN], 90, Pick[i][MensagemPickup]);
                        break;
                    }
                }
                else strcatEx(Dialog, "{CCCCCC}%s\t{00BFFF}%s\t{FF4500}%0.2f\n", Pick[i][MensagemPickup], AreaNome(Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]), GetPlayerDistanceFromPoint(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]));
            } 
            Dialog_Show(playerid, GpsLV, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Las Venturas", Dialog, "Selecionar", "Cancelar");  
        }
        case 3:
        {
            strcat(Dialog, "Local\tRegiao\tDistancia\n");
            strcat(Dialog, "{FF6347}Contratação para Máfia\t{00BFFF}San Fierro\t{FF0000}N/A\n");
            strcat(Dialog, "{FF6347}Boca de Tráfico\t{00BFFF}Los Santos\t{FF0000}N/A\n");
            strcat(Dialog, "{FF6347}Desmanche\t{00BFFF}San Fierro\t{FF0000}N/A\n");
            strcat(Dialog, "{FF6347}Produtor da Máfia\t{00BFFF}San Fierro\t{FF0000}N/A\n");
            Dialog_Show(playerid, GpsMafia, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Máfia", Dialog, "Selecionar", "Cancelar");    
        }
        case 4:
        {
            strcat(Dialog, "{FFFFFF}Categorias\n");
            strcat(Dialog, "{FFFFFF}Honesta\n");
            strcat(Dialog, "{FFFFFF}Transporte\n");
            strcat(Dialog, "{FFFFFF}Governo\n");
            strcat(Dialog, "{FFFFFF}Serviço Público\n");
            strcat(Dialog, "{FFFFFF}Máfia");
            Dialog_Show(playerid, GosHQMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Categoria", Dialog, "Selecionar", "Cancelar");    
        }
        case 5:
        {
            strcat(Dialog, "ID\tTipo\tDistância\n");
            for(new i=0; i < MAX_EMPRESAS; i++)
            {
                if(pEmpresa[i][Colocado] == false) continue;
                if(pEmpresa[i][eInterior] != 31 && pEmpresa[i][eInterior] != 30 && pEmpresa[i][eInterior] != 1) continue;
                strcatEx(Dialog, "ID: %d\t{00BFFF}%s\t{FFFF00}%0.2f\n", i, AreaNome(pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ]), GetPlayerDistanceFromPoint(playerid, pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ]));
            }
            Dialog_Show(playerid, SelecionarUTLGps, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Locais", Dialog, "Selecionar", "Fechar");  
        }
        case 6:
        {
            strcat(Dialog, "ID\tTipo\tDistância\n");
            for(new i=0; i < MAX_EMPRESAS; i++)
            {
                if(pEmpresa[i][Colocado] == false) continue;
                if(pEmpresa[i][eInterior] != 38) continue;
                strcatEx(Dialog, "ID: %d\t{00BFFF}%s\t{FFFF00}%0.2f\n", i, AreaNome(pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ]), GetPlayerDistanceFromPoint(playerid, pEmpresa[i][ePosicaoX], pEmpresa[i][ePosicaoY], pEmpresa[i][ePosicaoZ]));
            }
            Dialog_Show(playerid, SelecionarHOTELGps, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Locais", Dialog, "Selecionar", "Fechar");     
        }
        case 7:
        {
            strcat(Dialog, "{FFFFFF}Hobbie\tLocal\tTipo\n");
            strcat(Dialog, "{FFFFFF}Produtor\t{FFA500}San Fierro\t{FA8072}Desonesta\n");
            Dialog_Show(playerid, GpsHobbie, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Hobbies", Dialog, "Selecionar", "Cancelar");      
        }
        case 8:
        {
            new mcid = MinhaCasaID(playerid),
                meid = MinhaEmpresaID(playerid),
                mebase = Jogador[playerid][BaseID],
                mefab = ProcurarFabricaID(PegarNick(playerid)),
                lols[16],
                lolss[16],
                lolsss[16],
                lolssss[16];
            
            if(mcid == -1) format(lols, sizeof(lols), "ID: {FF0000}N/A");
            else format(lols, sizeof(lols), "ID: %d", mcid);

            if(meid == -1) format(lolss, sizeof(lolss), "ID: {FF0000}N/A");
            else format(lolss, sizeof(lolss), "ID: %d", meid);

            if(mebase == 0) format(lolsss, sizeof(lolsss), "ID: {FF0000}N/A");
            else format(lolsss, sizeof(lolsss), "ID: %d", mebase);

            if(mefab == -1) format(lolssss, sizeof(lolssss), "ID: {FF0000}N/A");
            else format(lolssss, sizeof(lolssss), "ID: %d", mefab);

            strcat(Dialog, "Propriedade\tID\n");
            strcatEx(Dialog, "Casa\t%s\n", lols);
            strcatEx(Dialog, "Empresa\t%s\n", lolss);
            strcatEx(Dialog, "Base\t%s\n", lolsss);
            strcatEx(Dialog, "Fábrica\t%s", lolssss);
            Dialog_Show(playerid, LocalizarPropriedades, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Propriedades", Dialog, "Selecionar", "Fechar");  
        }
        case 9:
        {
            if(pGps[playerid][GpsMarcado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há nenhuma marcação!");
            pGps[playerid][GpsMarcado] = false;
            KillTimer(pGps[playerid][TempoGps]);
            DestroyDynamicMapIconEx(pGps[playerid][MapaIconGps]);
        }
    }
    return 0;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pGps[playerid][GpsMarcado] == true){
        KillTimer(pGps[playerid][TempoGps]);   
        DestroyDynamicMapIconEx(pGps[playerid][MapaIconGps]);
    }
    LimparCatel(playerid);

    new Deletar[GpsInfo];
    pGps[playerid] = Deletar;
    return 1;
}

function VerificarGps(playerid)
{
    if(!IsPlayerInRangeOfPoint(playerid, 20.0, pGps[playerid][GPos][0], pGps[playerid][GPos][1], pGps[playerid][GPos][2])) return 1;
    DestroyDynamicMapIconEx(pGps[playerid][MapaIconGps]);
    pGps[playerid][GpsMarcado] = false;
    KillTimer(pGps[playerid][TempoGps]);
    SendClientMessage(playerid, 0x32CD32FF, "| GPS | Você chegou no ponto marcado no mapa");
    return 1;
}

stock EnviarGps(playerid, Float:X, Float:Y, Float:Z)
{
    if(pGps[playerid][GpsMarcado] == true){
        KillTimer(pGps[playerid][TempoGps]);
        DestroyDynamicMapIconEx(pGps[playerid][MapaIconGps]);
    }

    pGps[playerid][GPos][0] = X;
    pGps[playerid][GPos][1] = Y;
    pGps[playerid][GPos][2] = Z;

    pGps[playerid][GpsMarcado] = true;
    pGps[playerid][MapaIconGps] = CreateDynamicMapIcon(X, Y, Z, 56, -1, 0, 0, playerid, 999999.0, MAPICON_GLOBAL, -1);
    pGps[playerid][TempoGps] = SetTimerEx("VerificarGps", 2000, true, "d", playerid);
    return 1;
}