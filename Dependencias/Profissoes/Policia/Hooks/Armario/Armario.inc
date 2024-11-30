#include <YSI_Coding\y_hooks>

enum UniformePoliciaInfo
{
    TempoUni,
    pListaP
};

enum SkinPMInfo
{
    SkinModelo,
    SexoPM
};

new ListaSkinPM[][SkinPMInfo] =
{
    {280, 1},
    {281, 1},
    {282, 1},
    {283, 1},
    {284, 1},
    {285, 1},
    {286, 1},
    {288, 1},
    {300, 1},
    {301, 1},
    {302, 1},
    {310, 1},
    {311, 1},
    {302, 1},
    {306, 2},
    {307, 2},
    {309, 2}
};

new pIPolicia[MAX_PLAYERS][UniformePoliciaInfo];

hook OnPlayerDisconnect(playerid, reason)
{
    new Deletar[UniformePoliciaInfo];
    pIPolicia[playerid] = Deletar;
    return 1;
}

CMD:uniforme(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(GetPlayerInterior(playerid) != 6 || GetPlayerVirtualWorld(playerid) != 1300) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 4.0, 218.5183,70.9667,1005.0391)) return 1;
    if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(!strcmp(Jogador[playerid][Profissao], "Corregedoria")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(GetPVarInt(playerid, "EqupandoPM") == 1) return 1;
    SetPVarInt(playerid, "EqupandoPM", 1);
    pIPolicia[playerid][pListaP] = 0;
    MostrarArmarioPolicia(playerid);
    return 1;
}

CMD:equipamentos(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(GetPlayerInterior(playerid) != 6 || GetPlayerVirtualWorld(playerid) != 1300) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 4.0, 218.5183,70.9667,1005.0391)) return 1;
    if(!IsPolicia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está com nenhuma farda");
    if(Jogador[playerid][PorteDeArmas] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem porte de armas");
    if(GetPVarInt(playerid, "ArmPlVst") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco");
    SetPVarInt(playerid, "ArmPlVst", gettime()+15);
    ResetPlayerWeapons(playerid); // Remover Armas
    SetPlayerArmour(playerid, 100.0);

    GivePlayerWeapon(playerid, 3, 1);  

    switch(Jogador[playerid][Prisoes])
    {
        case 0..249:{GivePlayerWeapon(playerid, 22, 300);}
        case 250..399:{GivePlayerWeapon(playerid, 23, 400);}
        case 400..599:{GivePlayerWeapon(playerid, 23, 400); GivePlayerWeapon(playerid, 29, 800);}
        case 600..799:{GivePlayerWeapon(playerid, 24, 400); GivePlayerWeapon(playerid, 29, 800);}
        default:{GivePlayerWeapon(playerid, 24, 400); GivePlayerWeapon(playerid, 31, 900); GivePlayerWeapon(playerid, 29, 800);}
    }
        
    

    
    SendClientMessage(playerid, 0xFFFF00FF, "| VESTIÁRIO | Você se equipou com os utilitários.");
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    //Fechar
    if(playertextid == VestiarioPM[playerid][7]) OcultarArmarioPolicia(playerid);

    //Frente
    else if(playertextid == VestiarioPM[playerid][3])
    {
        if(pIPolicia[playerid][pListaP] >= 16) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais skins para frente!");
        pIPolicia[playerid][pListaP]++;
        PlayerTextDrawSetPreviewModel(playerid, VestiarioPM[playerid][1], ListaSkinPM[pIPolicia[playerid][pListaP]][SkinModelo]);
        PlayerTextDrawShow(playerid, VestiarioPM[playerid][1]);
    }

    //Tras
    else if(playertextid == VestiarioPM[playerid][4])
    {
        if(pIPolicia[playerid][pListaP] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais skins para tras!");
        pIPolicia[playerid][pListaP]--;   
        PlayerTextDrawSetPreviewModel(playerid, VestiarioPM[playerid][1], ListaSkinPM[pIPolicia[playerid][pListaP]][SkinModelo]);
        PlayerTextDrawShow(playerid, VestiarioPM[playerid][1]);
    }

    //Confimar Uniforme
    else if(playertextid == VestiarioPM[playerid][8])
    {
        OcultarArmarioPolicia(playerid);
        if(pPolicia[playerid][PegouUniformePolicia] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está fardado(a)");
        if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
        // OcultarArmarioPolicia(playerid);
        if(pIPolicia[playerid][TempoUni] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco");
        if(Jogador[playerid][Sexo] != ListaSkinPM[pIPolicia[playerid][pListaP]][SexoPM]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode pegar essa farda");
        VerificarSkin(playerid, pIPolicia[playerid][pListaP]);
    }

    //Devolver uniforme
    else if(playertextid == VestiarioPM[playerid][9])
    {
        OcultarArmarioPolicia(playerid);
        if(pPolicia[playerid][PegouUniformePolicia] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhuma farda");
        if(pPolicia[playerid][PegouVeiculoPolicia] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Devolva seu veículo antes de remover sua farda");
        // OcultarArmarioPolicia(playerid);
        if(pIPolicia[playerid][TempoUni] > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco");    
        
        if(pLocalizacao[playerid][Localizando] == true){
            pLocalizacao[playerid][Localizando] = false;
            KillTimer(pLocalizacao[playerid][TemporizadorLoc]);
            DestroyDynamicMapIconEx(pLocalizacao[playerid][MapIconLoc]);
        }

        pPolicia[playerid][PegouUniformePolicia] = false;
        Jogador[playerid][Trabalhando] = false;
        Jogador[playerid][SkinProfissao] = -1;
        SetPlayerSkin(playerid, Jogador[playerid][Skin]);
        ResetPlayerWeapons(playerid); // Remover Armas
        SetPlayerArmour(playerid, 0.0); // Remover Colete
        SendClientMessage(playerid, 0xFFFF00FF, "| VESTIÁRIO | Você removeu sua farda");
        pIPolicia[playerid][TempoUni] = gettime()+15;
    }
    return 0;
}

stock VerificarSkin(playerid, lista)
{
    if(ListaSkinPM[lista][SkinModelo] == 286){
        if(strcmp(Jogador[playerid][Profissao], "Policial Civil")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode pegar essa farda");
    }

    if(ListaSkinPM[lista][SkinModelo] == 285){
        if(strcmp(Jogador[playerid][Profissao], "Bope")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode pegar essa farda");
    }
    
    pPolicia[playerid][PegouUniformePolicia] = true;
    Jogador[playerid][Trabalhando] = true;
    Jogador[playerid][SkinProfissao] = ListaSkinPM[lista][SkinModelo];
    SetPlayerSkin(playerid, ListaSkinPM[lista][SkinModelo]);
    SetPlayerArmour(playerid, 100.0);
    pIPolicia[playerid][TempoUni] = gettime()+15;
    SendClientMessage(playerid, 0xFFFF00FF, "| VESTIÁRIO | Você pegou sua farda");
    return 1;
}