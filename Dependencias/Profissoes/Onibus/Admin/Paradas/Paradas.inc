#include <YSI_Coding\y_hooks>

enum CriadorParada
{
    bool:CriandoParada,
    bool:SetandoRange,
    poRange,
    ObParada
};

new fParada[MAX_PLAYERS][CriadorParada];

hook OnGameModeInit()
{  
    CarregarParadas();
    return 1;
}

function CarregarParadas()
{
    new Cache:Conectar,
        ParadasQT,
        id;
    
    Conectar = mysql_query(IDConexao, "SELECT * FROM `paradas`");
    if(mysql_errno(IDConexao) != 0)
    {
        print("[Rippzy:Paradas] Não foi possivel conectar com as paradas de onibus");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Paradas] Paradas de onibus sendo carregadas com sucesso!");
    ParadasQT = cache_num_rows();
    if(ParadasQT > 0)
    {
        for(new i=0; i < ParadasQT; i++)
        {
            cache_get_value_name_int(i, "ParadaID", id);
            oParada[id][ParadaID] = id;

            // Int
            cache_get_value_name_int(i, "RangeParada", oParada[id][RangeParada]);

            // Posição
            cache_get_value_name_float(i, "PosicaoX", oParada[id][pPosX]);
            cache_get_value_name_float(i, "PosicaoY", oParada[id][pPosY]);
            cache_get_value_name_float(i, "PosicaoZ", oParada[id][pPosZ]);

            // Rotação
            cache_get_value_name_float(i, "RotX", oParada[id][pCamX]);
            cache_get_value_name_float(i, "RotY", oParada[id][pCamY]);
            cache_get_value_name_float(i, "RotZ", oParada[id][pCamZ]);

            // Adicionar Parada
            AdicionarParada(id);
        }
    }
    cache_delete(Conectar);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(fParada[playerid][CriandoParada] == false) return 1;
    DestroyDynamicObjectEx(fParada[playerid][ObParada]);
    new Configg[CriadorParada];
    fParada[playerid] = Configg;
    return 1;
}

hook OnPlayerDinamicoObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(GetPVarInt(playerid, "CriaandaParar") == 0) return 1;
    if(response == EDIT_RESPONSE_CANCEL){
        SetPVarInt(playerid, "CriaandaParar", 0);
	    DestroyDynamicObjectEx(fParada[playerid][ObParada]);
        fParada[playerid][CriandoParada] = false;
	}
	
	else if(response == EDIT_RESPONSE_FINAL)
	{
        SetPVarInt(playerid, "CriaandaParar", 0);
	    DestroyDynamicObjectEx(fParada[playerid][ObParada]);
        fParada[playerid][CriandoParada] = false;

	    new Mensagem[90],
			id = PegarParadaID(),
            Enviar[300]
		;

        format(Enviar, sizeof(Enviar), "INSERT INTO `paradas` (`ParadaID`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `RotX`, `RotY`, `RotZ`) VALUES (%d, %f, %f, %f, %f, %f, %f)", id, x, y, z, rx, ry, rz);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um problema ao registrar essa parada de ônibus");

	    format(Mensagem, sizeof(Mensagem), "| PARADA | Você criou uma parada ( ID: {FE2E2E}%d{FFFFFF} )", id);
		SendClientMessage(playerid, -1, Mensagem);
		
	  	oParada[id][pColocado] = true;
	  	oParada[id][ParadaID] = id;
        oParada[id][RangeParada] = 0;
	  	
	  	// Posição
	  	oParada[id][pPosX] = x;
	  	oParada[id][pPosY] = y;
	  	oParada[id][pPosZ] = z;
	  	
	  	// Rotação
	  	oParada[id][pCamX] = rx;
	  	oParada[id][pCamY] = ry;
	  	oParada[id][pCamZ] = rz;
		
		AdicionarParada(id);
        //oParada[id][NpcParada][0] = CreateActor(random(154), fX-float(random(3)), fY, fZ, float(random(360)));
	}
    return 1;
}

CMD:criarparada(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    if(fParada[playerid][SetandoRange] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode criar um range agora");
    if(fParada[playerid][CriandoParada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está criando uma parada");
    SetPVarInt(playerid, "CriaandaParar", 1);
    new Float:mPos[3];
	GetPlayerPos(playerid, mPos[0], mPos[1], mPos[2]); 
	fParada[playerid][ObParada] = CreateDynamicObject(1257, mPos[0], mPos[1], mPos[2], 0.0, 0.0, 0.0, 0, 0, -1, 100.0, 100.0);
    EditDynamicObject(playerid, fParada[playerid][ObParada]);
    fParada[playerid][CriandoParada] = true;
    return 1;
}

CMD:removerparada(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new bool:Achoubb = false,
        Mensagem[200]
    ;

    for(new i=1; i < MAX_PARADAS; i++)
    {
        if(oParada[i][pColocado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, oParada[i][pPosX], oParada[i][pPosY], oParada[i][pPosZ])) continue;
        Achoubb = true;

        format(Mensagem, sizeof(Mensagem), "DELETE FROM `paradas` WHERE `ParadaID` = %d", i);
        mysql_query(IDConexao, Mensagem, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao deletar essa parada!");

        DestroyDynamicObjectEx(oParada[i][ObjetoParada]);
        // DestroyDynamicMapIconEx(oParada[i][MapIconParada]);

        oParada[i][pColocado] = false;
        SendClientMessage(playerid, -1, "| AVISO | Ponto de ônibus removido com sucesso!");

        for(new r=1; r < MAX_ROTAS; r++)
	    {
		    for(new h=0; h < MAX_ROTASID; h++)
		    {
		        if(oRota[r][h][RotaAtiva] == false) continue;
		        if(oRota[r][h][ParadaSel] != i) continue;

                format(Mensagem, sizeof(Mensagem), "DELETE FROM `onibusrotas` WHERE `ParadaID` = %d AND `RotaID` = %d AND `RotaEx`", i, r, h);
                mysql_query(IDConexao, Mensagem, false);
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve ao fazer limpaza na lista!");

	     	    format(Mensagem, sizeof(Mensagem), "| AVISO | Essa parada foi removida da lista ( {FF4500}%s / %s / %d{FFFFFF} )", oRota[r][h][NomeDaRota], oRota[r][h][pDestino]);
	     	    SendClientMessage(playerid, -1, Mensagem);
	     	
                // Resetar essa variavel
                //new Configg[RotasInfo];
                //oRota[r][h] = Configg;
		    }
	    }
    }

    if(Achoubb == false) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de uma parada de ônibus");
    return 1;
}

CMD:paradarange(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    if(fParada[playerid][CriandoParada] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode setar o range, termine de setar a parada!");
    if(fParada[playerid][SetandoRange] == false)
    {
        new bool:Haospa = false;
        for(new i=0; i < MAX_PARADAS; i++)
        {
            if(oParada[i][pColocado] == false) continue;
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, oParada[i][pPosX], oParada[i][pPosY], oParada[i][pPosZ])) continue;
            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "| PARADA | Você está editando o range da parada {FE2E2E}%d", i);
            SendClientMessage(playerid, -1, Mensagem);
            fParada[playerid][poRange] = i;
            fParada[playerid][SetandoRange] = true;
            Haospa = true;
        }
        if(Haospa == false) SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de uma parada de ônibus");
        return 1;
    }

    new id = fParada[playerid][poRange], 
        Float:fD[3],
        Mensagem[128]
    ;
    GetPlayerPos(playerid, fD[0], fD[1], fD[2]);
    new BackParada = GetDistanceBetweenPoints(fD[0], fD[1], fD[2], oParada[id][pPosX], oParada[id][pPosY], oParada[id][pPosZ]);

    format(Mensagem, sizeof(Mensagem), "UPDATE `paradas` SET `RangeParada` = %d WHERE `ParadaID` = %d", BackParada, id);
    mysql_query(IDConexao, Mensagem, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao atualizar o range!");

    format(Mensagem, sizeof(Mensagem), "| PARADA | Você setou o range {FE2E2E}%d{FFFFFF} na parada {FE2E2E}%d", BackParada, id);    
    SendClientMessage(playerid, -1, Mensagem);

    fParada[playerid][SetandoRange] = false;
    oParada[id][RangeParada] = BackParada;

    DestroyDynamicObjectEx(oParada[id][ObjetoParada]);
    // DestroyDynamicMapIconEx(oParada[id][MapIconParada]);
    AdicionarParada(id);
    return 1;
}