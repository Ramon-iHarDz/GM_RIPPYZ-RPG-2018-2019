#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    if(pMorreu[playerid][EstaCaido] == true) KillTimer(pMorreu[playerid][TimerMorte]);
    if(pParamedico[playerid][PegouAmbu] == true) DestroyVehicleEx(pParamedico[playerid][AmbuID]);
    if(pParamedico[playerid][AmbuComTexto] == true) DestroyDynamic3DTextLabelEx(pParamedico[playerid][AmbuTexto]);
    if(pParamedico[playerid][KitNaMao] == true) RemovePlayerAttachedObject(playerid, 9);
    
    VerificarMortesRemover(playerid);    
    VerificarMortesRemoverEx(playerid);

    if(pMorreu[playerid][MorteStatus] == 1)
    {
        new Mensagem[128];
        new id = pMorreu[playerid][ParamedicoID];
        KillTimer(pParamedico[id][TempoRevivendo]);
        pParamedico[id][Revivendo] = false;
        Jogador[playerid][Dinheiro] -= 5000;
        ClearAnimations(id);
        format(Mensagem, sizeof(Mensagem), "| AVISO | Você estava revivendo %s[%d] que desconectou-se do servidor", PegarNick(playerid), playerid);
        SendClientMessage(id, 0xFF4500FF, Mensagem);
    }

    if(pParamedico[playerid][Revivendo] == true)
    {
        new Mensagem[128];
        new id = pParamedico[playerid][RevivendoID];
        KillTimer(pParamedico[playerid][TempoRevivendo]);
        pMorreu[id][MorteStatus] = 0;

        format(Mensagem, sizeof(Mensagem), "| AVISO | Paramédico(a) %s[%d] que desconectou-se do servidor", PegarNick(playerid), playerid);
        SendClientMessage(id, 0xFF4500FF, Mensagem);
    }

    for(new i=0; i < MAX_PLAYERS; i++){
        new DelatarR[ParamedicoInfo];
        pMedico[playerid][i] = DelatarR;   
    }

    new Delatar[JogadorParamedico];
    pParamedico[playerid] = Delatar; 

    new DelataRRr[MorteInfo];
    pMorreu[playerid] = DelataRRr; 
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
    if(newkeys != KEY_YES) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;

    // Alugar Veículo
    if(IsPlayerInRangeOfPoint(playerid, 3.0, -2558.0691,662.5930,14.4531))
    {
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(strcmp(Jogador[playerid][Profissao], "Paramédico")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        
        if(GetPVarInt(playerid, "DelayRDelaoupah") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
        SetPVarInt(playerid, "DelayRDelaoupah", gettime()+10);
        if(pParamedico[playerid][PegouAmbu] == false)
        {
            if(pParamedico[playerid][PegouParaFarda] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Vá dentro do hospital e se equipe");
            if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            if(Jogador[playerid][CarteiraB] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui CNH para alugar uma ambulância ( Habilitação: B )");
            new rid = random(sizeof(AmbulanciaSpawn));
            pParamedico[playerid][AmbuID] = CreateVehicleEx(playerid, 416, AmbulanciaSpawn[rid][AmbuPosX], AmbulanciaSpawn[rid][AmbuPosY], AmbulanciaSpawn[rid][AmbuPosZ], AmbulanciaSpawn[rid][AmbuPosA], 1, 7, -1, 0);
            VeiculoServer[pParamedico[playerid][AmbuID]][Tranca] = 1;
            VeiculoServer[pParamedico[playerid][AmbuID]][AntiRadar] = true;
            pParamedico[playerid][PegouAmbu] = true;
            MarcarPosicao(playerid, AmbulanciaSpawn[rid][AmbuPosX], AmbulanciaSpawn[rid][AmbuPosY], AmbulanciaSpawn[rid][AmbuPosZ]);
            VerificarMortes(playerid);
            SendClientMessage(playerid, 0xFFFF00FF, "| PARAMÉDICO | Seu veículo foi colocado no estacionamento!");
            return 1;
        }

        if(pParamedico[playerid][AmbuComTexto] == true)
        {
            DestroyDynamic3DTextLabelEx(pParamedico[playerid][AmbuTexto]);
            pParamedico[playerid][AmbuComTexto] = false;
        } 
        if(pParamedico[playerid][KitNaMao] == true)
        {
            RemovePlayerAttachedObject(playerid, 9);
            pParamedico[playerid][KitNaMao] = false;
        }
        VerificarMarcao(playerid);
        VerificarMortesRemover(playerid);
        DestroyVehicleEx(pParamedico[playerid][AmbuID]);
        pParamedico[playerid][PegouAmbu] = false;
        SendClientMessage(playerid, 0xFFFF00FF, "| PARAMÉDICO | Você devolveu seu veículo!");
    }

    // Pegar Farda
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, 1041.8142,50.4494,1000.4590))
    {
        if(GetPlayerVirtualWorld(playerid) != 1299 || GetPlayerInterior(playerid) != 3) return 1;
        if(strcmp(Jogador[playerid][Profissao], "Paramédico")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");   
    
        if(GetPVarInt(playerid, "DelayRDelaoupah") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
        SetPVarInt(playerid, "DelayRDelaoupah", gettime()+10);
        if(pParamedico[playerid][PegouParaFarda] == false)
        {
            if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
            Jogador[playerid][Trabalhando] = true;
            pUber[playerid][UberPegouUniforme] = true;
            if(Jogador[playerid][Sexo] == 1)
            {
                SetPlayerSkin(playerid, 275);
                Jogador[playerid][SkinProfissao] = 275;
            }
            else if(Jogador[playerid][Sexo] == 2)
            {
                SetPlayerSkin(playerid, 308);
                Jogador[playerid][SkinProfissao] = 308;   
            }
            pParamedico[playerid][PegouParaFarda] = true;   
            SendClientMessage(playerid, 0xFFFF00FF, "| PARAMÉDICO | Você pegou sua farda");
            return 1;
        }
        SetPlayerSkin(playerid, Jogador[playerid][Skin]);
        Jogador[playerid][SkinProfissao] = -1;
        Jogador[playerid][Trabalhando] = false;
        pParamedico[playerid][PegouParaFarda] = false;  
        SendClientMessage(playerid, 0xFFFF00FF, "| PARAMÉDICO | Você retirou sua farda");
    }
    return 1;
}