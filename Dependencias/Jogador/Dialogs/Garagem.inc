#include <YSI_Coding\y_hooks>

Dialog:MenuVeiculo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(pVeiculo[playerid][listitem][MeuVeiculoModelo] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse slot não possui veículos!");
    SetPVarInt(playerid, "VeiculoStts", listitem);
    new Dialog[400];
    strcat(Dialog, "Conectar/Desconectar\n");
    strcat(Dialog, "Trancar/Destrancar\n");
    strcat(Dialog, "Portas Menu\n");
    strcat(Dialog, "Alterar Pintura\n");
    strcat(Dialog, "Salvar Posição\n");
    strcat(Dialog, "Localizar Veículo\n");
    strcat(Dialog, "Remover Tunagens\n");
    strcat(Dialog, "Vender Veículo");
    Dialog_Show(playerid, MenuVeh, DIALOG_STYLE_TABLIST, "{FF0000}Seu veículo", Dialog, "Selecionar", "Fechar");
    return 0;
}

Dialog:VehColorDialog(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new lista = GetPVarInt(playerid, "DialogColorMenu");
    new id = GetPVarInt(playerid, "VeiculoStts");
    new cor;
    if(sscanf(inputtext, "d", cor)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Coloque apenas números!");   

    if(lista == 1)
    {
        SetPVarInt(playerid, "DialogColorMenu", 2);
        SetPVarInt(playerid, "CorVehVeh1", cor);
        Dialog_Show(playerid, VehColorDialog, DIALOG_STYLE_INPUT, "{FF0000}Cor Veículo", "Coloque abaixo uma cor secundaria!", "Selecionar", "Fechar");  
    }
    if(lista == 2)
    {
        new cor2 = GetPVarInt(playerid, "CorVehVeh1");
        new VeiculoIDD = pVeiculo[playerid][id][MeuVeiculoModelo];
        pVeiculo[playerid][id][Cor1Veh] = cor2;
        pVeiculo[playerid][id][Cor2Veh] = cor;

        VeiculoServer[VeiculoIDD][Cor1VeiculoEx] = cor2;
        VeiculoServer[VeiculoIDD][Cor1VeiculoEx] = cor;

        ChangeVehicleColor(pVeiculo[playerid][id][MeuVeiculoID], cor2, cor);
        SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Veiculo pintado com sucesso!");
    }
    return 0;
}

Dialog:VeiculoPortas(playerid, response, listitem, inputtext[])
{
    new id = GetPVarInt(playerid, "VeiculoStts");
    new vehidd = pVeiculo[playerid][id][MeuVeiculoID];
    new Motor, Luzes, Alerme, Portas, Capo, portamalas, ob;
    GetVehicleParamsEx(vehidd, Motor, Luzes, Alerme, Portas, Capo, portamalas, ob);
    switch(listitem)
    {
        case 0:
        {
            if(Capo == VEHICLE_PARAMS_OFF) SetVehicleParamsEx(vehidd, Motor, Luzes, Alerme, Portas, VEHICLE_PARAMS_ON, portamalas, ob);
            else SetVehicleParamsEx(vehidd, Motor, Luzes, Alerme, Portas, VEHICLE_PARAMS_OFF, portamalas, ob);
        }
        case 1:
        {
            if(pVeiculo[playerid][id][PortaMalas] == false)
            { 
                if(!IsApenasCarro(pVeiculo[playerid][id][MeuVeiculoID])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse veículo não tem porta malas");
                SetVehicleParamsEx(vehidd, Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_ON, ob);
                new Float:OPs[3];
                GetVehiclePartPos(vehidd, VEH_PART_TRUNK, OPs[0], OPs[1], OPs[2]);
                pVeiculo[playerid][id][PortaMalasText] = CreateDynamic3DTextLabel("Porta Malas\n{FFFFFF}Aperte {CCCCCC}'N'{FFFFFF} para visualizar", 0x1C1C1CFF, 0.0000, -4.0999, -0.9000, 10.0, INVALID_PLAYER_ID, vehidd, 0, 0, 0, playerid, 11.0, -1);
                pVeiculo[playerid][id][PortaMalas] = true;
            }
            else
            {
                SetVehicleParamsEx(vehidd, Motor, Luzes, Alerme, Portas, Capo, VEHICLE_PARAMS_OFF, ob);
                pVeiculo[playerid][id][PortaMalas] = false;
                DestroyDynamic3DTextLabelEx(pVeiculo[playerid][id][PortaMalasText]);
            }
        }
    }
    return 0;
}

Dialog:MenuVeh(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new id = GetPVarInt(playerid, "VeiculoStts");
    switch(listitem)
    {
        case 0:
        {
            if(pVeiculo[playerid][id][VehConectado] == false)
            {
                new quantidade = 0;
                for(new i=0; i < MAX_SLOT_VEH; i++){
                    if(pVeiculo[playerid][i][VehConectado] == true) quantidade++;
                }
                if(quantidade >= 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já tem o máximo de veículos conectado!");
                if(pVeiculo[playerid][id][Patio] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo está no pátio policial");

                SendClientMessage(playerid, -1, "| INFO | Você conectou seu veículo!");
                pVeiculo[playerid][id][MeuVeiculoID] = CreateVehicleEx(playerid, pVeiculo[playerid][id][MeuVeiculoModelo], pVeiculo[playerid][id][vPosX], pVeiculo[playerid][id][vPosY], pVeiculo[playerid][id][vPosZ], pVeiculo[playerid][id][vPosA], pVeiculo[playerid][id][Cor1Veh], pVeiculo[playerid][id][Cor2Veh], -1, 0);
                pVeiculo[playerid][id][VehConectado] = true;
                VeiculoServer[pVeiculo[playerid][id][MeuVeiculoID]][Tranca] = pVeiculo[playerid][id][Tranca];
                VeiculoServer[pVeiculo[playerid][id][MeuVeiculoID]][Gasolina] = pVeiculo[playerid][id][GasolinaEx];
                VeiculoServer[pVeiculo[playerid][id][MeuVeiculoID]][Kilometros] = pVeiculo[playerid][id][KilometrosEx];
                VeiculoServer[pVeiculo[playerid][id][MeuVeiculoID]][PlacaEx] = pVeiculo[playerid][id][Placa];
                VeiculoServer[pVeiculo[playerid][id][MeuVeiculoID]][ApreendidoEx] = pVeiculo[playerid][id][Apreendido];
                SetVehicleNumberPlate(pVeiculo[playerid][id][MeuVeiculoID], pVeiculo[playerid][id][Placa]);
                if(pVeiculo[playerid][id][vVida] <= 390){
                    VeiculoServer[pVeiculo[playerid][id][MeuVeiculoID]][vQuebrado] = true;
                    SetVehicleHealth(pVeiculo[playerid][id][MeuVeiculoID], 390);
                }
                else SetVehicleHealth(pVeiculo[playerid][id][MeuVeiculoID], pVeiculo[playerid][id][vVida]);
                TunarMeuVeiculo(playerid, id, pVeiculo[playerid][id][MeuVeiculoID]);
                
            }
            else if(pVeiculo[playerid][id][VehConectado] == true)
            {
                if(pVeiculo[playerid][id][VeiculoUber] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse veículo está cadastrado em serviço na uber");
                SendClientMessage(playerid, -1, "| INFO | Você desconectou seu veículo!");
                new vehid = pVeiculo[playerid][id][MeuVeiculoID],
                    Float:vvVida;
                
                if(pVeiculo[playerid][id][PortaMalas] == true){
                    pVeiculo[playerid][id][PortaMalas] = false;
                    DestroyDynamic3DTextLabelEx(pVeiculo[playerid][id][PortaMalasText]);
                }
            
                VersSom(playerid);
                GetVehicleHealth(vehid, vvVida);
                pVeiculo[playerid][id][GasolinaEx] = VeiculoServer[vehid][Gasolina];
                pVeiculo[playerid][id][KilometrosEx] = VeiculoServer[vehid][Kilometros];
                pVeiculo[playerid][id][vVida] = vvVida; 

                RemoverTunagemVeiculo(playerid, id, pVeiculo[playerid][id][MeuVeiculoID]); 

                // RemovePlayerFromVehicle(playerid);
                DestroyVehicleEx(pVeiculo[playerid][id][MeuVeiculoID]);
                pVeiculo[playerid][id][VehConectado] = false;  
            }
        }
        case 1:
        {
            if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está conectado");
            new idveeh = pVeiculo[playerid][id][MeuVeiculoID],
                Float:cDPos[3];
            if(pVeiculo[playerid][id][TemTranca] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não possui tranca");
            GetVehiclePos(idveeh, cDPos[0], cDPos[1], cDPos[2]);
            if(!IsPlayerInRangeOfPoint(playerid, 5.0, cDPos[0], cDPos[1], cDPos[2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto do seu veículo");
            if(pVeiculo[playerid][id][Tranca] == 0)
            {
                SendClientMessage(playerid, -1, "| INFO | Você trancou seu veículo!");
                pVeiculo[playerid][id][Tranca] = 1;  
                VeiculoServer[idveeh][Tranca] = 1;

            }
            else if(pVeiculo[playerid][id][Tranca] == 1)
            {
                SendClientMessage(playerid, -1, "| INFO | Você destrancou seu veículo!");
                VerificarMarcacao(playerid);
                pVeiculo[playerid][id][Tranca] = 0;  
                VeiculoServer[idveeh][Tranca] = 0;
            }
        }
        case 2:
        {
            if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está conectado");
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo!");
            if(GetPlayerVehicleID(playerid) != pVeiculo[playerid][id][MeuVeiculoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo!");
            new Dialog[200];
            strcat(Dialog, "Capo ( {FF0000}Abrir/Fechar{FFFFFF} )\n");
            strcat(Dialog, "Porta Malas ( {FF0000}Abrir/Fechar{FFFFFF} )");
            Dialog_Show(playerid, VeiculoPortas, DIALOG_STYLE_TABLIST, "{FF0000}Menu Portas", Dialog, "Selecionar", "Fechar");  
        }
        case 3:
        {
            if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está conectado");
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo!");
            if(GetPlayerVehicleID(playerid) != pVeiculo[playerid][id][MeuVeiculoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo!");
            SetPVarInt(playerid, "DialogColorMenu", 1);
            Dialog_Show(playerid, VehColorDialog, DIALOG_STYLE_INPUT, "{FF0000}Cor Veículo", "Coloque abaixo uma cor primaria!", "Selecionar", "Fechar");  
        } 
        case 4:
        {
            if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está conectado");
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo!");
            if(GetPlayerVehicleID(playerid) != pVeiculo[playerid][id][MeuVeiculoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo!");
            // if(GetVehicleSpeed(pVeiculo[playerid][id][MeuVeiculoID]) > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa estar parado(a)");
            new Float:cPos[4];
            new idc = pVeiculo[playerid][id][MeuVeiculoID];
            GetVehiclePos(idc, cPos[0], cPos[1], cPos[2]);
            GetVehicleZAngle(idc, cPos[3]);

            pVeiculo[playerid][id][vPosX] = cPos[0];
            pVeiculo[playerid][id][vPosY] = cPos[1];
            pVeiculo[playerid][id][vPosZ] = cPos[2];
            pVeiculo[playerid][id][vPosA] = cPos[3];

            VeiculoServer[idc][PosicaoCarX] = cPos[0];
            VeiculoServer[idc][PosicaoCarY] = cPos[1];
            VeiculoServer[idc][PosicaoCarZ] = cPos[2];
            VeiculoServer[idc][PosicaoCarA] = cPos[3];
            SendClientMessage(playerid, -1, "| INFO | Veículo salvo nessa posição com sucesso!");
        }
        case 5:
        {
            if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está conectado");
            new Float:cPos[4];
            new idc = pVeiculo[playerid][id][MeuVeiculoID];
            GetVehiclePos(idc, cPos[0], cPos[1], cPos[2]);
            MarcarPosicao(playerid, cPos[0], cPos[1], cPos[2]);
            SendClientMessage(playerid, -1, "| INFO | Seu veículo foi marcado no mapa");
        }
        case 6:
        {
            if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo não está conectado");
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo!");
            if(GetPlayerVehicleID(playerid) != pVeiculo[playerid][id][MeuVeiculoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo!");     

            new Enviar[128];
            format(Enviar, sizeof(Enviar), "DELETE FROM `tunagens` WHERE `Nome` = '%s' AND `Slot` = %d", EscapeString(PegarNick(playerid)), id);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao remover as tunagens!");

            new dsada[TuningVehh];
            for(new i=0; i < 18; i++){
                pTunagem[playerid][id][i] = dsada;
            }

            PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
            SendClientMessage(playerid, -1, "| INFO | Você removeu todas as tunagens do seu veículo");
        }
        case 7:
        {
            if(pVeiculo[playerid][id][VehConectado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| GARAGEM | Conecte seu veículo antes de vender");
            new Float:EucPos[3],
                Float:VehcPos[3];
            GetVehiclePos(pVeiculo[playerid][id][MeuVeiculoID], VehcPos[0], VehcPos[1], VehcPos[2]);
            GetPlayerPos(playerid, EucPos[0], EucPos[1], EucPos[2]);
            new distancia = GetDistanceBetweenPoints(VehcPos[0], VehcPos[1], VehcPos[2], EucPos[0], EucPos[1], EucPos[2]);
            if(distancia > 20.0) return SendClientMessage(playerid, 0xFF4500FF, "| GARAGEM | Você não está perto do seu veículo");
            SetPVarInt(playerid, "SLAD", id);
            Dialog_Show(playerid, VenderVeiculoConfirm, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", "Você realmente deseja vender seu veículo?", "Vender", "Cancelar");
        }
    }
    return 1;
}

Dialog:VenderVeiculoConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "SLAD"),
        ConexaoSQLLL[128];
    RemoverVeiculoSQL(playerid, id);
    Jogador[playerid][Dinheiro] += pVeiculo[playerid][id][Preco];
            
    DestroyVehicleEx(pVeiculo[playerid][id][MeuVeiculoID]);
    format(ConexaoSQLLL, sizeof(ConexaoSQLLL), "| GARAGEM | Você vendeu seu veículo por {32CD32}$%s", DinheiroSeparar(pVeiculo[playerid][id][Preco]));
    SendClientMessage(playerid, -1, ConexaoSQLLL);
            
    new sadas[PlayerVeiculoInfo];
    pVeiculo[playerid][id] = sadas;
    return 1;
}

stock RemoverVeiculoSQL(playerid, id, bool:tta=false){
    new ConexaoSQLLL[128];
    format(ConexaoSQLLL, sizeof(ConexaoSQLLL), "DELETE FROM `veiculos` WHERE `Slot` = %d AND `Nome` = '%s'", id, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, ConexaoSQLLL, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao realizar a venda desse veículo");

    format(ConexaoSQLLL, sizeof(ConexaoSQLLL), "DELETE FROM `portamalas` WHERE `Slot` = %d AND `Nome` = '%s'", id, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, ConexaoSQLLL, false);
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao realizar a venda desse veículo [0x1]");
    
    if(tta == true){
        new sadas[PlayerVeiculoInfo];
        pVeiculo[playerid][id] = sadas;
    }
    return 1;
}