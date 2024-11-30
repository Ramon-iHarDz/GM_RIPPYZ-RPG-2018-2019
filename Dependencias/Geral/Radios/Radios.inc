#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Rádio{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para anunciar", 0xFFA500FF, -2002.6700,-1020.0964,32.1719, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1239, 1, -2002.6700,-1020.0964,32.1719, 0, 0, -1, 90.0, -1);
    CreateDynamicMapIcon(-2002.6700,-1020.0964,32.1719, 48, -1, 0, 0, -1, 60.0, MAPICON_LOCAL, -1);
    
    CreateDynamic3DTextLabel("Rádio{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para anunciar", 0xFFA500FF, 2810.9124,1987.4006,10.8203, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1239, 1, 2810.9124,1987.4006,10.8203, 0, 0, -1, 90.0, -1);
    CreateDynamicMapIcon(2810.9124,1987.4006,10.8203, 48, -1, 0, 0, -1, 60.0, MAPICON_LOCAL, -1);
    

    CreateDynamic3DTextLabel("Rádio{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para anunciar", 0xFFA500FF, 1616.1407,-1897.1450,13.5491, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1239, 1, 1616.1407,-1897.1450,13.5491, 0, 0, -1, 90.0, -1);
    CreateDynamicMapIcon(1616.1407,-1897.1450,13.5491, 48, -1, 0, 0, -1, 60.0, MAPICON_LOCAL, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, -2002.6700,-1020.0964,32.1719) 
    && !IsPlayerInRangeOfPoint(playerid, 2.0, 2810.9124,1987.4006,10.8203)
    && !IsPlayerInRangeOfPoint(playerid, 2.0, 1616.1407,-1897.1450,13.5491)) return 1;
    if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;

    new Dialog[250];
    strcat(Dialog, "Vende-se Casa\n");
    strcat(Dialog, "Vende-se Empresa\n");
    strcat(Dialog, "Procuro por Funcionários\n");
    strcat(Dialog, "Procuro por Vagas de Empregos\n");
    strcat(Dialog, "Vende-se Veículo");
    Dialog_Show(playerid, RadioEletric, DIALOG_STYLE_TABLIST, "{FF0000}Rádio", Dialog, "Anunciar", "Fechar");
    return 1;
}

Dialog:RadioEletric(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(pTempo[playerid][AnunciarRadio] > gettime()){
        new ALAss[90];
        format(ALAss, sizeof(ALAss), "| ERRO | Você só pode anunciar em %s", ConverterSegundos(pTempo[playerid][AnunciarRadio]));
        SendClientMessage(playerid, 0xFF4500FF, ALAss);
        return 1;
    }

    if(Jogador[playerid][Dinheiro] < 1500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem $1.500 para anunciar");
    new Mensagem[128],
        AnuncAA[35];

    switch(listitem)
    {
        case 0:
        {
            new id = MinhaCasaID(playerid);
            if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma casa");
            if(strcmp(pCasa[id][cDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é dono(a) da casa");
            AnuncAA = "Vende-se Casa";
        }
        case 1:
        {
            new id = MinhaEmpresaID(playerid);
            if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma empresa");
            if(strcmp(pEmpresa[id][eDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é dono(a) da empresa");
            AnuncAA = "Vende-se Empresa";
        }
        case 2:
        {
            new id = MinhaEmpresaID(playerid);
            if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui uma empresa");
            if(strcmp(pEmpresa[id][eDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não é dono(a) da empresa");
            AnuncAA = "Procuro por Funcionários(as)";
        }
        case 3: AnuncAA = "Procuro por Vagas de Empregos";
        case 4: AnuncAA = "Vende-se Veículo";
    }
    format(Mensagem, sizeof(Mensagem), "| ANÚNCIO | O(A) Jogador(a) {FFA500}%s[%d]{FFFFFF} anunciou {A9A9A9}%s", PegarNick(playerid), playerid, AnuncAA);
    SendClientMessageToAll(-1, Mensagem);

    Jogador[playerid][Dinheiro] -= 1500;
    pTempo[playerid][AnunciarRadio] = gettime()+3600;
    return 1;
}