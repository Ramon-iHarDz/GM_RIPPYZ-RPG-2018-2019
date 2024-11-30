#include <YSI_Coding\y_hooks>

#define MAX_RADAR 100

enum RadarInfo
{
    RadarID,
    Velocidade,
    RadarModelo,
    Float:PosicaoX,
    Float:PosicaoY,
    Float:PosicaoZ,
    Float:PosicaoRX,
    Float:PosicaoRY,
    Float:PosicaoRZ,
    bool:Conectado,
    Text3D:TextoRadar,
    RadarObjeto1,
    RadarObjeto2,
    RadarVW,
    RadarInterior,
    IconeRadar
};

enum RadarPlayerLog
{
    bool:LimpezaAutorizada,
    TempoRadar,
    TempoMulta,
    VelocidadeCap,
    Float:RadarNoti,
    Float:RadarNoti1,
    Multado
};

new pRadar[MAX_RADAR][RadarInfo];
new jRadar[MAX_PLAYERS][RadarPlayerLog];

hook OnGameModeInit()
{
    CarregarRadar();
    return 1;
}

forward CarregarRadar();
public CarregarRadar()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `radar`");
    if(mysql_errno(IDConexao) != 0)
    {
        print("[Rippzy:Radar] Erro ao estabelecer conexão com os radares!");
        SendRconCommand("exit");
        return 1;
    }
    print("[Rippzy:Radar] Radares carregados com sucesso!");
    new QuantosTem = cache_num_rows(),
        id;

    if(QuantosTem > 0)
    {
        for(new i=0; i < QuantosTem; i++)
        {
            cache_get_value_name_int(i, "RadarID", id);
            pRadar[id][RadarID] = id;
            cache_get_value_name_int(i, "Velocidade", pRadar[id][Velocidade]);
            cache_get_value_name_int(i, "Modelo", pRadar[id][RadarModelo]);
            cache_get_value_name_float(i, "PosicaoX", pRadar[id][PosicaoX]);
            cache_get_value_name_float(i, "PosicaoY", pRadar[id][PosicaoY]);
            cache_get_value_name_float(i, "PosicaoZ", pRadar[id][PosicaoZ]);
            cache_get_value_name_float(i, "PosicaoRX", pRadar[id][PosicaoRX]);
            cache_get_value_name_float(i, "PosicaoRY", pRadar[id][PosicaoRY]);
            cache_get_value_name_float(i, "PosicaoRZ", pRadar[id][PosicaoRZ]);
            cache_get_value_name_int(i, "RadarInterior", pRadar[id][RadarInterior]);
            cache_get_value_name_int(i, "RadarVirtualWorld", pRadar[id][RadarVW]);
            AdicionarRadar(id);
        }
    }
    cache_delete(Conectar);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    if(jRadar[playerid][LimpezaAutorizada] == false){
        jRadar[playerid][TempoRadar] = SetTimerEx("RadarMulta", 1000, true, "d", playerid);
        jRadar[playerid][LimpezaAutorizada] = true;
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(jRadar[playerid][LimpezaAutorizada] == true){  
        KillTimer(jRadar[playerid][TempoRadar]);
    }
    new Deletar[RadarPlayerLog];
    jRadar[playerid] = Deletar;
    return 1;
}

function RadarMulta(playerid)
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "RadarMulta", 1)) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 1;
    if(jRadar[playerid][TempoMulta] > gettime()) return 1;
    if(VeiculoServer[GetPlayerVehicleID(playerid)][AntiRadar] == true) return 1;
    if(!IsVehicleLandVehicle(GetPlayerVehicleID(playerid)) && !IsVehicleMoto(GetPlayerVehicleID(playerid))) return 1;
    if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
    for(new i=0; i < MAX_RADAR; i++)
    {
        if(pRadar[i][Conectado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 24.0, pRadar[i][PosicaoX], pRadar[i][PosicaoY], pRadar[i][PosicaoZ])) continue;
        new VlcD = GetPlayerSpeed(playerid),
            nAw;
        if(VlcD < pRadar[i][Velocidade])
        {
            jRadar[playerid][Multado] = 0; // == 0 Não multado
            nAw = 1;
        }
        else if(VlcD+10 > pRadar[i][Velocidade])
        {
            AdicionarMulta(playerid, VlcD, pRadar[i][Velocidade]);
            nAw = 3;
        }
        else if(VlcD > pRadar[i][Velocidade])
        {
            jRadar[playerid][Multado] = 0; // == 0 Não multado
            nAw = 2;
        }

        jRadar[playerid][VelocidadeCap] = VlcD;
        jRadar[playerid][RadarNoti] = 5.3;
        jRadar[playerid][RadarNoti1] = 4.6;
        jRadar[playerid][TempoMulta] = gettime()+15;
        MostrarRadarBox(playerid);
        MostrarAnimacao(playerid, nAw); 
        break;
    }
    return 1;
}

function MostrarAnimacao(playerid, id)
{
    jRadar[playerid][RadarNoti] += 1.0;
    jRadar[playerid][RadarNoti1] += 1.0;

    PlayerTextDrawTextSize(playerid, RadarRC[playerid][0], jRadar[playerid][RadarNoti], 0.000000);
    PlayerTextDrawTextSize(playerid, RadarRC[playerid][1], jRadar[playerid][RadarNoti1], 0.000000);
    PlayerTextDrawShow(playerid, RadarRC[playerid][0]);
    PlayerTextDrawShow(playerid, RadarRC[playerid][1]);

    if(jRadar[playerid][RadarNoti] >= 91.0 && jRadar[playerid][RadarNoti1] >= 95.6)
    {
        MostrarRadar(playerid);
        new VelocidadeMostrar[90];
        if(id == 1) format(VelocidadeMostrar, sizeof(VelocidadeMostrar), "Velocidade:_~g~%d~w~_Km/h", jRadar[playerid][VelocidadeCap]);
        else if(id == 2) format(VelocidadeMostrar, sizeof(VelocidadeMostrar), "Velocidade:_~y~%d~w~_Km/h", jRadar[playerid][VelocidadeCap]);
        else if(id == 3) format(VelocidadeMostrar, sizeof(VelocidadeMostrar), "Velocidade:_~r~%d~w~_Km/h", jRadar[playerid][VelocidadeCap]);
        PlayerTextDrawSetString(playerid, RadarRC[playerid][2], VelocidadeMostrar);
        SetTimerEx("OcultarRadar", 6000, false, "d", playerid);
    }
    else SetTimerEx("MostrarAnimacao", 10, false, "dd", playerid, id); 
    return 1;
}

stock AdicionarRadar(idradar)
{
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "{FF0000}Radar\n{FFFFFF}Velocidade {FFFF00}%d{FFFFFF} Km/h", pRadar[idradar][Velocidade]);
    pRadar[idradar][TextoRadar] = CreateDynamic3DTextLabel(Mensagem, -1, pRadar[idradar][PosicaoX]+0.4, pRadar[idradar][PosicaoY], pRadar[idradar][PosicaoZ]+2, 80.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, pRadar[idradar][RadarVW], pRadar[idradar][RadarInterior], -1, 80.0, -1, 0);
    pRadar[idradar][RadarObjeto1] = CreateDynamicObject(18880, pRadar[idradar][PosicaoX], pRadar[idradar][PosicaoY], pRadar[idradar][PosicaoZ], pRadar[idradar][PosicaoRX], pRadar[idradar][PosicaoRY], pRadar[idradar][PosicaoRZ], pRadar[idradar][RadarVW], pRadar[idradar][RadarInterior], -1, 150.0, 150.0, -1, 0);
    if(pRadar[idradar][RadarModelo] == 2) pRadar[idradar][RadarObjeto2] = CreateDynamicObject(18880, pRadar[idradar][PosicaoX], pRadar[idradar][PosicaoY], pRadar[idradar][PosicaoZ], pRadar[idradar][PosicaoRX], pRadar[idradar][PosicaoRY], pRadar[idradar][PosicaoRZ]+180, pRadar[idradar][RadarVW], pRadar[idradar][RadarInterior], -1, 150.0, 150.0, -1, 0);
    pRadar[idradar][IconeRadar] = CreateDynamicMapIcon(pRadar[idradar][PosicaoX], pRadar[idradar][PosicaoY], pRadar[idradar][PosicaoZ], 34, -1, 0, 0, -1, 190.0, MAPICON_LOCAL);
    pRadar[idradar][Conectado] = true;
    return 1;
}

stock PegarRadarID()
{
    for(new i=1; i < MAX_RADAR; i++){
        if(pRadar[i][Conectado] == true) continue;
        return i;
    }
    return false;
}

hook OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
{
    if(response == EDIT_RESPONSE_CANCEL)
    {
        new id = GetPVarInt(playerid, "RadarIDCriacao");
        if(id == objectid){
            DestroyObject(objectid);
            SendClientMessage(playerid, 0xFFFF00FF, "| ADMIN | Você cancelou a criação do radar!");  
            DeletePVar(playerid, "RadarIDCriacao");
        }
        return 1;
    }

    if(response == EDIT_RESPONSE_FINAL)
    {
        new id = GetPVarInt(playerid, "RadarIDCriacao");
        if(id == objectid)
        {
            DestroyObject(objectid);
            new RadarLiberadoH = PegarRadarID(),
                Mensagem[128],
                Enviar[300],
                VelocidadeReg = GetPVarInt(playerid, "VelocidadeRadarRegis"),
                DuploMode = GetPVarInt(playerid, "CaoDaChubataMole");

            format(Enviar, sizeof(Enviar), "INSERT INTO `radar` (`RadarID`, `Velocidade`, `PosicaoX`, `PosicaoY`, `PosicaoZ`, `PosicaoRX`, `PosicaoRY`, `PosicaoRZ`, `RadarVirtualWorld`, `RadarInterior`, `Modelo`) VALUES (%d, %d, %f, %f, %f, %f, %f, %f, %d, %d, %d)", RadarLiberadoH, VelocidadeReg, fX, fY, fZ, fRotX, fRotY, fRotZ, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), DuploMode);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao criar esse radar!");

            //Posicao
            pRadar[RadarLiberadoH][PosicaoX] = fX;
            pRadar[RadarLiberadoH][PosicaoY] = fY;
            pRadar[RadarLiberadoH][PosicaoZ] = fZ;

            //Olhada
            pRadar[RadarLiberadoH][PosicaoRX] = fRotX;
            pRadar[RadarLiberadoH][PosicaoRY] = fRotY;
            pRadar[RadarLiberadoH][PosicaoRZ] = fRotZ;

            pRadar[RadarLiberadoH][RadarVW] = GetPlayerVirtualWorld(playerid);
            pRadar[RadarLiberadoH][RadarInterior] = GetPlayerInterior(playerid);
            pRadar[RadarLiberadoH][RadarID] = RadarLiberadoH;
            pRadar[RadarLiberadoH][Velocidade] = VelocidadeReg;
            pRadar[RadarLiberadoH][RadarModelo] = DuploMode;

            AdicionarRadar(RadarLiberadoH);

            format(Mensagem, sizeof(Mensagem), "| ADMIN | Você criou o radar %d com a velocidade %d com sucesso!", RadarLiberadoH, VelocidadeReg);
            SendClientMessage(playerid, 0x00FF00FF, Mensagem);
            DeletePVar(playerid, "RadarIDCriacao");
        }
    	return 1;
	}
    return 0;
}

CMD:criarradar(playerid, params[])
{
    if(Jogador[playerid][Admin] != 7) return 0;
    new velocidadeeee, veduplo;
    if(sscanf(params, "dd", velocidadeeee, veduplo)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /CriarRadar [Velocidade] [Duplo]");
    if(veduplo < 1 && veduplo > 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | 1 = Apenas / 2 = Duplo");
    new Float:Pos[3];
    new id;
    GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    id = CreateObject(18880, Pos[0]+2, Pos[1], Pos[2], 0.0, 0.0, 0.0, 0.0);
    SetPVarInt(playerid, "RadarIDCriacao", id);
    SetPVarInt(playerid, "VelocidadeRadarRegis", velocidadeeee);
    SetPVarInt(playerid, "CaoDaChubataMole", veduplo);
    EditObject(playerid, id);
    SendClientMessage(playerid, 0xFF4500FF, "| ADMIN | Posicione o radar e salve-o ou aperte esc para cancelar!");
    return 1;
}

CMD:removerradar(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    for(new i=1; i < MAX_RADAR; i++)
    {
        if(pRadar[i][Conectado] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, pRadar[i][PosicaoX], pRadar[i][PosicaoY], pRadar[i][PosicaoZ])) continue;
        new Enviar[128];
        format(Enviar, sizeof(Enviar), "DELETE FROM `radar` WHERE `RadarID` = %d", pRadar[i][RadarID]);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ocorreu um erro ao remover esse radar!");
                
        new Mensagem[128];
        pRadar[i][Conectado] = false;
        DestroyDynamicObjectEx(pRadar[i][RadarObjeto1]);
        if(pRadar[i][RadarModelo] == 2) DestroyDynamicObjectEx(pRadar[i][RadarObjeto2]);
        DestroyDynamicMapIcon(pRadar[i][IconeRadar]);
        DestroyDynamic3DTextLabel(pRadar[i][TextoRadar]);
        format(Mensagem, sizeof(Mensagem), "| ADMIN | Você deletou o radar %d", pRadar[i][RadarID]);
        SendClientMessage(playerid, 0xFFFF00FF, Mensagem);
        return 1;
    }

    return 1;
}

stock AdicionarMulta(playerid, minhavelo, radarvelo)
{
    new id = GetPlayerVehicleID(playerid);

    if(IsVehicleMoto(id))
    {
        if(Jogador[playerid][CarteiraA] == 0){
            if(Jogador[playerid][Estrelas] < MaximoEstrelas){
                SendClientMessage(playerid, 0xed7824FF, "| AVISO | Você não possui habilitação portanto foi adicionado 1 estrela de procurado em você");
                Jogador[playerid][Estrelas]++;
            }
            return 1;
        }

        else if(Jogador[playerid][CarteiraA] == 2){
            SendClientMessage(playerid, 0xed7824FF, "| AVISO | Sua habilitação está vencida e sua multa foi cobrada automaticamente do seu banco");
            Jogador[playerid][DinheiroBanco]--;
            return 1;
        }

        else if(Jogador[playerid][CarteiraA] == 3){
            if(Jogador[playerid][Estrelas] < MaximoEstrelas){
                SendClientMessage(playerid, 0xed7824FF, "| AVISO | Sua habilitação está Irregular, foi adicionado 3 estrelas de procurado em você");
                Jogador[playerid][Estrelas] += 3;
                if(Jogador[playerid][Estrelas] > MaximoEstrelas) Jogador[playerid][Estrelas] = MaximoEstrelas;
            }   
            return 1;
        }

        else if(Jogador[playerid][CarteiraA] == 1)
        {
            if(minhavelo > radarvelo+10)
            {
                Jogador[playerid][MultaA]++;
                if(Jogador[playerid][MultaA] >= 10){
                    Jogador[playerid][CarteiraA] = 3;
                    Jogador[playerid][MultaA] = 0;
                    SendClientMessage(playerid, 0xFFFF00FF, "| HABILITAÇÃO | Sua habilitação de moto foi retida por excesso de multa!");
                    SendClientMessage(playerid, 0xFFFF00FF, "| HABILITAÇÃO | Vá até o detran para regularizá-la ou poderá ser preso caso não vá");
                    return 1;
                }
                SendClientMessage(playerid, 0xed7824FF, "| MULTA | Você foi multado(a) por excesso de velocidade!"); 
            }
            else if(minhavelo >= radarvelo) SendClientMessage(playerid, 0xed7824FF, "| AVISO | Você passou muito rápido no radar, tenha cuidado!"); 
        }
        return 1;
        
    }

    else if(IsVehicleLandVehicle(id))
    {
        if(IsVehicleCaminhao(id))
        {
            if(Jogador[playerid][CarteiraC] == 0){
                if(Jogador[playerid][Estrelas] < MaximoEstrelas){
                    SendClientMessage(playerid, 0xed7824FF, "| AVISO | Você não possui habilitação portanto foi adicionado 1 estrela de procurado em você");
                    Jogador[playerid][Estrelas]++;
                }
                return 1;
            }

            else if(Jogador[playerid][CarteiraC] == 2){
                SendClientMessage(playerid, 0xed7824FF, "| AVISO | Sua habilitação está vencida e sua multa foi cobrada automaticamente do seu banco");
                Jogador[playerid][DinheiroBanco]--;
                return 1;
            }

            else if(Jogador[playerid][CarteiraC] == 3){
                if(Jogador[playerid][Estrelas] < MaximoEstrelas){
                    SendClientMessage(playerid, 0xed7824FF, "| AVISO | Sua habilitação está Irregular, foi adicionado 3 estrelas de procurado em você");
                    Jogador[playerid][Estrelas] += 3;
                    if(Jogador[playerid][Estrelas] > MaximoEstrelas) Jogador[playerid][Estrelas] = MaximoEstrelas;
                }   
                return 1;
            }

            else if(Jogador[playerid][CarteiraC] == 1){
                if(minhavelo > radarvelo+10){
                    Jogador[playerid][MultaC]++;
                    if(Jogador[playerid][MultaC] >= 10){
                        Jogador[playerid][CarteiraC] = 3;
                        Jogador[playerid][MultaC] = 0;
                        SendClientMessage(playerid, 0xFFFF00FF, "| HABILITAÇÃO | Sua habilitação de caminhão foi retida por excesso de multa!");
                        SendClientMessage(playerid, 0xFFFF00FF, "| HABILITAÇÃO | Vá até o detran para regularizá-la ou poderá ser preso caso não vá");
                        return 1;
                    }
                    SendClientMessage(playerid, 0xed7824FF, "| MULTA | Você foi multado(a) por excesso de velocidade!"); 
                }
                else if(minhavelo >= radarvelo) SendClientMessage(playerid, 0xed7824FF, "| AVISO | Você passou muito rápido no radar, tenha cuidado!"); 
            }
            return 1;
        }
        else if(IsVehicleOnibus(id))
        {

            if(Jogador[playerid][CarteiraD] == 0){
                if(Jogador[playerid][Estrelas] < MaximoEstrelas){
                    SendClientMessage(playerid, 0xed7824FF, "| AVISO | Você não possui habilitação portanto foi adicionado 1 estrela de procurado em você");
                    Jogador[playerid][Estrelas]++;
                }
                return 1;
            }

            else if(Jogador[playerid][CarteiraD] == 2){
                SendClientMessage(playerid, 0xed7824FF, "| AVISO | Sua habilitação está vencida e sua multa foi cobrada automaticamente do seu banco");
                Jogador[playerid][DinheiroBanco]--;
                return 1;
            }

            else if(Jogador[playerid][CarteiraD] == 3){
                if(Jogador[playerid][Estrelas] < MaximoEstrelas){
                    SendClientMessage(playerid, 0xed7824FF, "| AVISO | Sua habilitação está Irregular, foi adicionado 3 estrelas de procurado em você");
                    Jogador[playerid][Estrelas] += 3;
                    if(Jogador[playerid][Estrelas] > MaximoEstrelas) Jogador[playerid][Estrelas] = MaximoEstrelas;
                }   
                return 1;
            }

            else if(Jogador[playerid][CarteiraD] == 1){
                if(minhavelo > radarvelo+10){
                    Jogador[playerid][MultaD]++;
                    if(Jogador[playerid][MultaD] >= 10){
                        Jogador[playerid][CarteiraD] = 3;
                        Jogador[playerid][MultaD] = 0;
                        SendClientMessage(playerid, 0xFFFF00FF, "| HABILITAÇÃO | Sua habilitação de ônibus foi retida por excesso de multa!");
                        SendClientMessage(playerid, 0xFFFF00FF, "| HABILITAÇÃO | Vá até o detran para regularizá-la ou poderá ser preso caso não vá");
                        return 1;
                    }
                    SendClientMessage(playerid, 0xed7824FF, "| MULTA | Você foi multado(a) por excesso de velocidade!"); 
                }
                else if(minhavelo >= radarvelo) SendClientMessage(playerid, 0xed7824FF, "| AVISO | Você passou muito rápido no radar, tenha cuidado!"); 
            }
            return 1;
        }

        else if(IsApenasCarro(id))
        {
            if(Jogador[playerid][CarteiraB] == 0){
                if(Jogador[playerid][Estrelas] < MaximoEstrelas){
                    SendClientMessage(playerid, 0xed7824FF, "| AVISO | Você não possui habilitação portanto foi adicionado 1 estrela de procurado em você");
                    Jogador[playerid][Estrelas]++;
                }
                return 1;
            }

            else if(Jogador[playerid][CarteiraB] == 2){
                SendClientMessage(playerid, 0xed7824FF, "| AVISO | Sua habilitação está vencida e sua multa foi cobrada automaticamente do seu banco");
                Jogador[playerid][DinheiroBanco]--;
                return 1;
            }

            else if(Jogador[playerid][CarteiraB] == 3){
                if(Jogador[playerid][Estrelas] < MaximoEstrelas){
                    SendClientMessage(playerid, 0xed7824FF, "| AVISO | Sua habilitação está Irregular, foi adicionado 3 estrelas de procurado em você");
                    Jogador[playerid][Estrelas] += 3;
                    if(Jogador[playerid][Estrelas] > MaximoEstrelas) Jogador[playerid][Estrelas] = MaximoEstrelas;
                }   
                return 1;
            }

            else if(Jogador[playerid][CarteiraB] == 1){
                if(minhavelo > radarvelo+10){
                    Jogador[playerid][MultaB]++;
                    if(Jogador[playerid][MultaB] >= 10){
                        Jogador[playerid][CarteiraB] = 3;
                        Jogador[playerid][MultaB] = 0;
                        SendClientMessage(playerid, 0xFFFF00FF, "| HABILITAÇÃO | Sua habilitação de carro foi retida por excesso de multa!");
                        SendClientMessage(playerid, 0xFFFF00FF, "| HABILITAÇÃO | Vá até o detran para regularizá-la ou poderá ser preso caso não vá");
                        return 1;
                    }
                    SendClientMessage(playerid, 0xed7824FF, "| MULTA | Você foi multado(a) por excesso de velocidade!"); 
                }
                else if(minhavelo >= radarvelo) SendClientMessage(playerid, 0xed7824FF, "| AVISO | Você passou muito rápido no radar, tenha cuidado!"); 
            }
            return 1;
        }

    }
    return 1;
}