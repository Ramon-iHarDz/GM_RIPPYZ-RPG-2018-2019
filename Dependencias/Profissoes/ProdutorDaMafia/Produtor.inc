#include <YSI_Coding\y_hooks>

enum MesaProduto
{
    Float:ProdMesX,
    Float:ProdMesY,
    Float:ProdMesZ,
    Float:ProdMesRX,
    Float:ProdMesRY,
    Float:ProdMesRZ,
    
    Text3D:ProdMesTexto,
    bool:ProdOcupada
};

enum JogadorProduto
{
    ProdStatus,
    ProdEstilo,
    ProdMesa,
    ProdCheck,
    ProdMap,
    ProObjeto,
    ProdTexto[20]
};

new MesaMafia[][MesaProduto] =
{
    {-2157.44531, -248.04688, 35.99219,   0.00000, 0.00000, 0.00000},
    {-2161.01563, -248.04688, 35.99219,   0.00000, 0.00000, 0.00000},
    {-2164.32813, -248.04688, 35.99219,   0.00000, 0.00000, 0.00000},
    {-2167.96875, -248.04688, 35.99219,   0.00000, 0.00000, 0.00000},
    {-2171.50000, -248.04688, 35.99219,   0.00000, 0.00000, 0.00000},
    {-2175.05469, -248.04688, 35.99219,   0.00000, 0.00000, 0.00000},
    {-2161.0273,    -250.4863, 35.9852,     0.0000, 0.0000, 0.0000},
    {-2157.3437,    -250.4863, 35.9852,     0.0000, 0.0000, 0.0000},
    {-2178.5419,    -248.0263, 35.9852,     0.0000, 0.0000, 0.0000},
    {-2164.2905,    -250.4863, 35.9852,     0.0000, 0.0000, 0.0000},
    {-2167.9721,    -250.4863, 35.9852,     0.0000, 0.0000, 0.0000},
    {-2171.4956,    -250.4863, 35.9852,     0.0000, 0.0000, 0.0000},
    {-2175.0388,    -250.4863, 35.9852,     0.0000, 0.0000, 0.0000},
    {-2178.4812,    -250.4863, 35.9852,     0.0000, 0.0000, 0.0000}
};

new mProducao[sizeof(MesaMafia)][MesaProduto];
new pProdutor[MAX_PLAYERS][JogadorProduto];

hook OnGameModeInit()
{
    new Mensagem[75];
    for(new i=0; i < sizeof(MesaMafia); i++){
        CreateDynamicObject(941, MesaMafia[i][ProdMesX], MesaMafia[i][ProdMesY], MesaMafia[i][ProdMesZ], MesaMafia[i][ProdMesRX], MesaMafia[i][ProdMesRY], MesaMafia[i][ProdMesRZ], -1, 0, -1, 100.0, 100.0, -1);
        format(Mensagem, sizeof(Mensagem), "Produtor ({FFA500}ID: %d{FFFFFF})\nAperte {CCCCCC}'Y'{FFFFFF} para usar", i+1);
        mProducao[i][ProdMesTexto] = CreateDynamic3DTextLabel(Mensagem, -1, MesaMafia[i][ProdMesX], MesaMafia[i][ProdMesY], MesaMafia[i][ProdMesZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 11.0, -1);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamicMapIconEx(pProdutor[playerid][ProdMap]);
    DestroyDynamicCPEx(pProdutor[playerid][ProdCheck]);
    DestroyDynamicObjectEx(pProdutor[playerid][ProObjeto]);
    if(pProdutor[playerid][ProdStatus] == 1) ResetarMesaProducao(pProdutor[playerid][ProdMesa]);

    new olasd[JogadorProduto];
    pProdutor[playerid] = olasd;
    return 1;
}

Dialog:SelecionarProdMafia(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    SetPVarInt(playerid, "OpcaoProd", listitem);

    new Dialog[90];
    strcat(Dialog, "Opção\tAdicional\n");
    switch(listitem)
    {
        case 0:
        {
            if(Jogador[playerid][Capsulas] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem caixa com cápsulas");
            strcat(Dialog, "Munições\n");
        }
        case 1:
        {
            if(Jogador[playerid][Pecas] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem caixa com peças");
            strcat(Dialog, "AK-47\n");
            strcat(Dialog, "M4\n");
            strcat(Dialog, "Sniper rifle\n");
            strcat(Dialog, "Lança Chamas\n");
            strcat(Dialog, "Pistola\n");
            strcat(Dialog, "Espingarda");
        }
    }
    Dialog_Show(playerid, ProdOpcaoMafia, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Opções", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:ProdOpcaoMafia(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "ProdMesa");
    if(mProducao[id][ProdOcupada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar essa mesa");
    mProducao[id][ProdOcupada] = true;

    new Mensagem[128],
        ProdO,
        Putt;
    switch(GetPVarInt(playerid, "OpcaoProd"))
    {
        case 0:
        {
            Putt = 2359;
            Jogador[playerid][Capsulas]--;
            switch(listitem)
            {
                case 0: {format(pProdutor[playerid][ProdTexto], 20, "Munições"); ProdO = 2358;}
            }
        }
        case 1:
        {
            Putt = 2034;
            Jogador[playerid][Pecas]--;
            switch(listitem)
            {
                case 0: {format(pProdutor[playerid][ProdTexto], 20, "AK-47"); ProdO = 355;}
                case 1: {format(pProdutor[playerid][ProdTexto], 20, "M4"); ProdO = 356;}
                case 2: {format(pProdutor[playerid][ProdTexto], 20, "Sniper rifle"); ProdO = 358;}
                case 3: {format(pProdutor[playerid][ProdTexto], 20, "Lança Chamas"); ProdO = 361;}
                case 4: {format(pProdutor[playerid][ProdTexto], 20, "Pistola"); ProdO = 346;}
                case 5: {format(pProdutor[playerid][ProdTexto], 20, "Espingarda"); ProdO = 349;}
            }
        }
    }

    format(Mensagem, sizeof(Mensagem), "Produtor ({FFA500}ID: %d{FFFFFF})\nUsada por {FFA500}%s[%d]", id+1, PegarNick(playerid), playerid);
    UpdateDynamic3DTextLabelText(mProducao[id][ProdMesTexto], -1, Mensagem);

    TogglePlayerControllable(playerid, 0);
    Jogador[playerid][Trabalhando] = true;
    pProdutor[playerid][ProdStatus] = 1;
    pProdutor[playerid][ProdMesa] = id;
    pProdutor[playerid][ProdEstilo] = GetPVarInt(playerid, "OpcaoProd");
    SetPVarInt(playerid, "ArmasTypeEstilo", ProdO);
    pProdutor[playerid][ProObjeto] = CreateDynamicObject(Putt, MesaMafia[id][ProdMesX], MesaMafia[id][ProdMesY], MesaMafia[id][ProdMesZ]+0.5, 0.0, 0.0, float(random(360)), 0, 0, -1, 100.0, 100.0, -1);

    format(Mensagem, sizeof(Mensagem), "Montando %s, aguarde.", pProdutor[playerid][ProdTexto]);
    CriarProgresso(playerid, Mensagem, "AcabouMontagem", 1000);
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pProdutor[playerid][ProdCheck]) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    DestroyDynamicCPEx(pProdutor[playerid][ProdCheck]);
    if(pProdutor[playerid][ProdStatus] == 3) return EnviarProducao(playerid, 1);
    TogglePlayerControllable(playerid, 0);
    ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
    RemovePlayerAttachedObject(playerid, 9);
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "Embalando a(s) %s, aguarde.", pProdutor[playerid][ProdTexto]);
    CriarProgresso(playerid, Mensagem, "AcabouEmbalagem", 700);
    return 1;
}

function AcabouMontagem(playerid)
{
    TogglePlayerControllable(playerid, 1);
    pProdutor[playerid][ProdStatus] = 2;
    ResetarMesaProducao(pProdutor[playerid][ProdMesa]);
    DestroyDynamicObjectEx(pProdutor[playerid][ProObjeto]);
    switch(pProdutor[playerid][ProdEstilo])
    {
        case 0: {pProdutor[playerid][ProdCheck] = CreateDynamicCP(-2155.2571,-264.4355,36.5156, 1.0, 0, 0, playerid, 60.0, -1);}
        case 1: {pProdutor[playerid][ProdCheck] = CreateDynamicCP(-2158.6917,-264.2849,36.5156, 1.0, 0, 0, playerid, 60.0, -1);}
    }
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
    SetPlayerAttachedObject(playerid, 9, GetPVarInt(playerid, "ArmasTypeEstilo"), 1, -0.0280, 0.4540, -0.1349, -82.8999, 23.9999, -81.8999, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
    return 1;
}

function AcabouEmbalagem(playerid)
{
    TogglePlayerControllable(playerid, 1);
    pProdutor[playerid][ProdStatus] = 3;

    new Mensagem[148];
    switch(pProdutor[playerid][ProdEstilo])
    {
        case 0:
        {
            format(Mensagem, sizeof(Mensagem), "| INFO | Você precisa ir até {e2b960}Boca de Tráfico{FFFFFF} para entregar a(s) {FFA500}%s", pProdutor[playerid][ProdTexto]);
            Jogador[playerid][Estrelas] += 4;
        }
        case 1:
        {
            switch(random(1))
            {
                case 0:
                {
                    format(Mensagem, sizeof(Mensagem), "| INFO | Você precisa ir até {e2b960}Las Venturas{FFFFFF} para entregar a {FFA500}%s", pProdutor[playerid][ProdTexto]);
                    pProdutor[playerid][ProdCheck] = CreateDynamicCP(-412.6227,2217.3596,42.4297, 1.0, 0, 0, playerid, 60.0, -1);
                    pProdutor[playerid][ProdMap] = CreateDynamicMapIcon(-412.6227,2217.3596,42.4297, 19, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
                }
                case 1:
                {
                    format(Mensagem, sizeof(Mensagem), "| INFO | Você precisa ir até {e2b960}Los Santos{FFFFFF} para entregar a {FFA500}%s", pProdutor[playerid][ProdTexto]);
                    pProdutor[playerid][ProdCheck] = CreateDynamicCP(2354.8726,-655.9608,128.0547, 1.0, 0, 0, playerid, 60.0, -1);
                    pProdutor[playerid][ProdMap] = CreateDynamicMapIcon(2354.8726,-655.9608,128.0547, 19, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);
                }
            }
            Jogador[playerid][Estrelas] += 5;
        }
    }
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

stock ResetarMesaProducao(id)
{
    mProducao[id][ProdOcupada] = false;
    new Mensagem[75];
    format(Mensagem, sizeof(Mensagem), "Produtor ({FFA500}ID: %d{FFFFFF})\nAperte {CCCCCC}'Y'{FFFFFF} para usar", id+1);
    UpdateDynamic3DTextLabelText(mProducao[id][ProdMesTexto], -1, Mensagem);
    return 1;
}

stock EnviarProducao(playerid, id)
{
    pProdutor[playerid][ProdStatus] = 0;
    new Mensagem[128],
        fola;
    switch(id)
    {
        case 0:
        {
            fola = random(5000-4000)+4000;
        }
        case 1:
        {
            fola = random(7000-6000)+6000;
            DestroyDynamicMapIconEx(pProdutor[playerid][ProdMap]);
        }
    }
    Jogador[playerid][Trabalhando] = false;
    Jogador[playerid][Dinheiro] += fola;
    format(Mensagem, sizeof(Mensagem), "| MÁFIA | Você entregou {FFA500}%s{FFFFFF} e recebeu {32CD32}$%s", pProdutor[playerid][ProdTexto], DinheiroSeparar(fola));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

Dialog:ProducaoFuncaoCargo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(pProdutor[playerid][ProdStatus] != 3) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nada para entregar");
    if(pProdutor[playerid][ProdEstilo] != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua entrega não é aqui, vá para outro ponto");
    EnviarProducao(playerid, 0);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        for(new i=0; i < sizeof(MesaMafia); i++)
        {
            if(!IsPlayerInRangeOfPoint(playerid, 2.0, MesaMafia[i][ProdMesX], MesaMafia[i][ProdMesY], MesaMafia[i][ProdMesZ])) continue;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) continue;
            //if(strcmp(Jogador[playerid][Profissao], "Produtor da Máfia")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(Jogador[playerid][Level] < 10) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa de level 10");
            if(mProducao[i][ProdOcupada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode usar essa mesa");
            if(pProdutor[playerid][ProdStatus] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já inicou uma produção");

            SetPVarInt(playerid, "ProdMesa", i);

            new Dialog[55];
            strcat(Dialog, "Produção de Balas\n");
            strcat(Dialog, "Produção de Armamentos");
            Dialog_Show(playerid, SelecionarProdMafia, DIALOG_STYLE_TABLIST, "{FF0000}Produção", Dialog, "Selecionar", "Fechar");
            break;
        }
    }
    return 1;
}

Dialog:MafiaProducaoCompra(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            if(Jogador[playerid][Capsulas] > 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de cápsulas");
            if(Jogador[playerid][Dinheiro] < 1000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
            Jogador[playerid][Dinheiro] -= 1000;
            Jogador[playerid][Capsulas]++;
            SendClientMessage(playerid, -1, "| MÁFIA | Você comprou 1 caixa de cápsulas por {32CD32}$1.000");
        }
        case 1:
        {
            if(Jogador[playerid][Capsulas] > 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de cápsulas");
            if(Jogador[playerid][Dinheiro] < 1900) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
            Jogador[playerid][Dinheiro] -= 1900;
            Jogador[playerid][Pecas]++;
            SendClientMessage(playerid, -1, "| MÁFIA | Você comprou 1 caixa com peças de armas por {32CD32}$1.900");
        }
    }
    return 1;
}