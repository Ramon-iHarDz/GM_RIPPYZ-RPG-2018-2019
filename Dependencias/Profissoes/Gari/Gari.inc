#include <YSI_Coding\y_hooks>

#define MAX_LIXOS 999
#define MaximoLixo 250
#define LixoPreco 25

enum GariInfo
{
    //Sistema do Lixo
    bool:UniformeAlugado,
    bool:VeiculoAlugado,
    bool:LixoNaMao,
    bool:ResetLiberado,
    
    //Sistema de Parceiro
    bool:TemParceiro,
    Parceiro,

    //Suas Informações
    IconeMapa,
    CheckMapa,
    LixoColetado,
    Text3D:CaminhaoTexto,
    VeiculoLixo
};

enum Lixos
{
    LixoID,
    ModeloLixo,
    LixoMaximo,
    LixoAtual,
    Float:PosX,
    Float:PosY,
    Float:PosZ,
    Text3D:LixoTexto,
    bool:cColocado
};

enum CaminhoesDeLixoInfo{
    Float:PosicaoX,
    Float:PosicaoY,
    Float:PosicaoZ,
    Float:PosicaoA
};

new pLixo[][CaminhoesDeLixoInfo] =
{
    {-1902.5183, -1619.4965, 22.3069, 271.0214}, //Posicao (1)
    {-1902.5453, -1614.4852, 22.3064, 270.8156}, //Posicao (2)
    {-1902.3158, -1610.0256, 22.2968, 270.1878}, //Posicao (3)
    {-1902.2656, -1605.6533, 22.3041, 270.1587}, //Posicao (4)
    {-1902.3823, -1601.3293, 22.3027, 271.2351} //Posicao (5)
};

new Lixo[MAX_LIXOS][Lixos];
new pGari[MAX_PLAYERS][GariInfo];

hook OnGameModeInit()
{
    SetTimer("CarregarGari", 6000, false);
    return 1;
}

forward CarregarGari();
public CarregarGari()
{
    new Cache:Conectar;
    Conectar = mysql_query(IDConexao, "SELECT * FROM `lixos`");
    if(mysql_errno(IDConexao) != 0){
        print("[MySQL] Falha ao carregar os lixos!");
        SendRconCommand("exit");
        return 1;
    }
    print("[ Rippzy ] Lixos sendo carregados com sucesso!");
    new Quantidade = cache_num_rows();
    new Identificacao = 1;
    new Mensagem[300];
    for(new i=0; i < Quantidade; i++)
    {
        cache_get_value_name_float(i, "X", Lixo[Identificacao][PosX]);
        cache_get_value_name_float(i, "Y", Lixo[Identificacao][PosY]);
        cache_get_value_name_float(i, "Z", Lixo[Identificacao][PosZ]);
        cache_get_value_name_int(i, "Model", Lixo[Identificacao][ModeloLixo]);
        cache_get_value_name_int(i, "LixoSuporte", Lixo[Identificacao][LixoMaximo]);
        Lixo[Identificacao][LixoAtual] = Lixo[Identificacao][LixoMaximo];

        format(Mensagem, sizeof(Mensagem), "Lixo(s) {6ff542}%d{FFFFFF} / {00FF00}%d\n{FFFFFF}Aperte {00FF00}'N'{FFFFFF} para coletar", Lixo[Identificacao][LixoAtual], Lixo[Identificacao][LixoMaximo]);
        Lixo[Identificacao][LixoTexto] = CreateDynamic3DTextLabel(Mensagem, 0xFFFFFFFF, Lixo[Identificacao][PosX], Lixo[Identificacao][PosY], Lixo[Identificacao][PosZ]+1, 18.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
        Lixo[Identificacao][cColocado] = true;
        //printf("[MSQL] Lixo %d foi carregado com sucesso na posicao: %f %f %f", Identificacao, Lixo[Identificacao][PosX], Lixo[Identificacao][PosY], Lixo[Identificacao][PosZ]);
        Identificacao++;
    }
    cache_delete(Conectar);

    CreateDynamic3DTextLabel("{00FF00}Gari\n{FFFFFF}Aperte 'Y' para pegar o uniforme", 0xFFFFFFFF, -1895.0088,-1665.8721,23.0156, 80.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 70.0, -1, 0);
    CreateDynamicPickup(1275, 1, -1895.0088,-1665.8721,23.0156, 0, 0, -1, 180.0, -1, 0);

    CreateDynamic3DTextLabel("{00FF00}Gari\n{FFFFFF}Aperte 'Y' para alugar um veículo", 0xFFFFFFFF, -1904.5817,-1647.7183,21.7500, 80.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 70.0, -1, 0);
    CreateDynamicPickup(1239, 1, -1904.5817,-1647.7183,21.7500, 0, 0, -1, 180.0, -1, 0);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason){

    if(pGari[playerid][TemParceiro] == true)
    {
        new prc = pGari[playerid][Parceiro];
        new String[128];

        if(pGari[prc][LixoNaMao] == true){
            RemovePlayerAttachedObject(prc, 0);
            DestroyDynamic3DTextLabel(pGari[prc][CaminhaoTexto]);
            pGari[prc][LixoNaMao] = false;   
        }

        if(pGari[prc][LixoColetado] > 0){
            pGari[prc][LixoColetado] = 0;
            DestroyDynamicMapIcon(pGari[prc][IconeMapa]);
            DestroyDynamicCP(pGari[prc][CheckMapa]);
        }
        OcultarMenuGari(prc);
        pGari[prc][TemParceiro] = false;
        format(String, sizeof(String), "| AVISO | %s desconectou-se do servidor!", PegarNick(playerid));
        SendClientMessage(prc, 0xfc520fFF, String);
    }
    if(pGari[playerid][VeiculoAlugado] == true) DestroyVehicleEx(pGari[playerid][VeiculoLixo]);
    if(pGari[playerid][LixoNaMao] == true){
        RemovePlayerAttachedObject(playerid, 0);
        DestroyDynamic3DTextLabel(pGari[playerid][CaminhaoTexto]);
    }
    if(pGari[playerid][LixoColetado] > 0){
        DestroyDynamicMapIcon(pGari[playerid][IconeMapa]);
        DestroyDynamicCP(pGari[playerid][CheckMapa]);
    }

    new Limpar[GariInfo];
    pGari[playerid] = Limpar;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){
        if(IsPlayerInRangeOfPoint(playerid, 3.0, -1895.0088, -1665.8721, 23.0156)){ 
            if(strcmp(Jogador[playerid][Profissao], "Gari")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão!");
            if(pGari[playerid][VeiculoAlugado] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Devolva seu veículo antes!");
            if(pGari[playerid][UniformeAlugado] == false){
                Jogador[playerid][SkinProfissao] = 16;
                SetPlayerSkin(playerid, 16);
                pGari[playerid][UniformeAlugado] = true;
                Jogador[playerid][Trabalhando] = true;
                SendClientMessage(playerid, 0xFFFF00FF, "| GARI | Você pegou seu uniforme, procure um(a) parceiro(a)!");
                return 1;
            }
            Jogador[playerid][SkinProfissao] = -1;
            SetPlayerSkin(playerid, Jogador[playerid][Skin]);
            pGari[playerid][UniformeAlugado] = false;  
            Jogador[playerid][Trabalhando] = false;
            SendClientMessage(playerid, 0xFFFF00FF, "| GARI | Você removeu o uniforme!");
        }

        if(IsPlayerInRangeOfPoint(playerid, 3.0, -1904.5817,-1647.7183,21.7500)){ 
            if(strcmp(Jogador[playerid][Profissao], "Gari")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão!");
            if(pGari[playerid][UniformeAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está sem uniforme!");
            if(pGari[playerid][VeiculoAlugado] == false){
                new posid = random(sizeof(pLixo));
                pGari[playerid][VeiculoLixo] = CreateVehicleEx(playerid, 408, pLixo[posid][PosicaoX], pLixo[posid][PosicaoY], pLixo[posid][PosicaoZ], pLixo[posid][PosicaoA], 1, 1, 360, 0);
                pGari[playerid][VeiculoAlugado] = true;
                SendClientMessage(playerid, 0xFFFF00FF, "| GARI | Você alugou o veículo!");
            }
            else{
                DestroyVehicleEx(pGari[playerid][VeiculoLixo]);
                pGari[playerid][VeiculoAlugado] = false;
                SendClientMessage(playerid, 0xFFFF00FF, "| GARI | Você alugou o veículo!");
            }
        }
    }

    if(newkeys == KEY_NO && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){ //Pegar lixo na lixeira
        for(new i=0; i < MAX_LIXOS; i++){
            if(Lixo[i][cColocado] == true){
                if(IsPlayerInRangeOfPoint(playerid, 2.0, Lixo[i][PosX], Lixo[i][PosY], Lixo[i][PosZ])){
                    if(strcmp(Jogador[playerid][Profissao], "Gari")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão!");
                    if(pGari[playerid][LixoColetado] >= MaximoLixo) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Caminhão já está lotado!");
                    if(Lixo[i][LixoAtual] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Essa lata de lixo está vázia!");
                    if(pGari[playerid][UniformeAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está sem uniforme!");
                    //if(pGari[playerid][TemParceiro] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem um parceiro(a)!");
                    if(pGari[playerid][LixoNaMao] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já tem um lixo na mão, coloque-o no caminhão para pegar o outro!");
                    new Float:MinhaX[3];
                    GetPlayerPos(playerid, MinhaX[0], MinhaX[1], MinhaX[2]);
                    if(!IsVehicleInRangeOfPoint(pGari[playerid][VeiculoLixo], 50.0, MinhaX[0], MinhaX[1], MinhaX[2])) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Veículo está muito longe!");
                    if(Lixo[i][LixoAtual] == Lixo[i][LixoMaximo]) SetTimerEx("ResetarLixos", 180000, false, "i", i);
                    Lixo[i][LixoAtual]--;
                    AtualizarLixeira(i);
                    SetPlayerAttachedObject(playerid, 0, 1265, 5, 0.2710, 0.0070, 0.0260, -18.4999, -97.5998, 9.4000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
                    pGari[playerid][CaminhaoTexto] = CreateDynamic3DTextLabel("{FFFFFF}Aperte {00FF00}H{FFFFFF} para colocar o lixo", 0xFFFFFFFF, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, pGari[playerid][VeiculoLixo], 0, 0, 0, playerid, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
                    pGari[playerid][LixoNaMao] = true;
                    break;
                }
            }
        }
    } 

    if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) //Colocar Lixo no Caminhão
    { 
        new Float:cMotoH[3];
        new Float:X, Float:Y;
        GetVehiclePos(pGari[playerid][VeiculoLixo], cMotoH[0], cMotoH[1], cMotoH[2]);
        GetXYBehindOfVehicle(pGari[playerid][VeiculoLixo], X, Y, 4.0);
        if(IsPlayerInRangeOfPoint(playerid, 4.0, X, Y, cMotoH[2]))
        {
            if(pGari[playerid][LixoNaMao] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está com lixo na mão");
            new id = pGari[playerid][Parceiro];
            
            if(pGari[playerid][LixoColetado] < 1){
                pGari[playerid][IconeMapa] = CreateDynamicMapIcon(-1808.5474,-1661.4663,23.2502, 51, 3, 0, 0, playerid, 99999.9, MAPICON_GLOBAL);
                pGari[playerid][CheckMapa] = CreateDynamicCP(-1808.5474,-1661.4663,23.2502, 2.0, 0, 0, playerid, 40.0, -1, 0);
                SendClientMessage(playerid, 0xFFFF00FF, "| MAPA | Localização de descarregamento foi marcada em seu mapa!");
            }

            if(pGari[playerid][LixoColetado] == 0 && pGari[playerid][TemParceiro] == false)
            {
                MostrarGariMenuLixo(playerid);
                new String[20];
                format(String, sizeof(String), "%d/%d", pGari[playerid][LixoColetado], MaximoLixo);
                PlayerTextDrawSetString(playerid, GariMenu[playerid][0], String);
            }

            //Criar checkpoint caso eu tenha um parceiro(a)
            if(pGari[playerid][TemParceiro] == true)
            {
                if(pGari[id][LixoColetado] < 1){
                    pGari[id][IconeMapa] = CreateDynamicMapIcon(-1808.5474,-1661.4663,23.2502, 51, 3, 0, 0, id, 99999.9, MAPICON_GLOBAL);
                    pGari[id][CheckMapa] = CreateDynamicCP(-1808.5474,-1661.4663,23.2502, 2.0, 0, 0, id, 40.0, -1, 0);
                    SendClientMessage(id, 0xFFFF00FF, "| MAPA | Localização de descarregamento foi marcada em seu mapa!");
                }
                pGari[id][LixoColetado]++;
                if(pGari[id][LixoColetado] > MaximoLixo) pGari[id][LixoColetado] = MaximoLixo;
            }
            
            
            pGari[playerid][LixoColetado]++;
            if(pGari[playerid][LixoColetado] > MaximoLixo) pGari[playerid][LixoColetado] = MaximoLixo;

            new String[30];
            if(pGari[playerid][LixoColetado] >= MaximoLixo) format(String, sizeof(String), "~r~%d/%d", pGari[playerid][LixoColetado], MaximoLixo);
            else format(String, sizeof(String), "%d/%d", pGari[playerid][LixoColetado], MaximoLixo);

            RemovePlayerAttachedObject(playerid, 0);
            DestroyDynamic3DTextLabel(pGari[playerid][CaminhaoTexto]);


            //Atualizar Textdraw se eu tiver um parceiro(a)
            if(pGari[playerid][TemParceiro] == true){
                if(pGari[playerid][LixoColetado] >= MaximoLixo){
                    if(pGari[id][LixoNaMao] == true){
                        RemovePlayerAttachedObject(id, 8);
                        DestroyDynamic3DTextLabel(pGari[id][CaminhaoTexto]);
                        pGari[id][LixoNaMao] = false;
                    }
                }
                PlayerTextDrawSetString(id, GariMenu[id][0], String);     
            }

            pGari[playerid][LixoNaMao] = false;
            PlayerTextDrawSetString(playerid, GariMenu[playerid][0], String);
        }
    }
    return 1;
}

stock AtualizarLixeira(LixeiraID)
{
    DestroyDynamic3DTextLabel(Lixo[LixeiraID][LixoTexto]);
    new LixoAA[228];
    format(LixoAA, sizeof(LixoAA), "Lixo(s) {6ff542}%d{FFFFFF} / {00FF00}%d\n{FFFFFF}Aperte {00FF00}'N'{FFFFFF} para coletar", Lixo[LixeiraID][LixoAtual], Lixo[LixeiraID][LixoMaximo]);
    Lixo[LixeiraID][LixoTexto] = CreateDynamic3DTextLabel(LixoAA, 0xFFFFFFFF, Lixo[LixeiraID][PosX], Lixo[LixeiraID][PosY], Lixo[LixeiraID][PosZ]+1, 18.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
    return 1;
}

forward ResetarLixos(LixeiraID);
public ResetarLixos(LixeiraID)
{
    Lixo[LixeiraID][LixoAtual]++;
    AtualizarLixeira(LixeiraID);
    if(Lixo[LixeiraID][LixoAtual] != Lixo[LixeiraID][LixoMaximo]) SetTimerEx("ResetarLixos", 180000, false, "i", LixeiraID);
    return 1;
}

CMD:iniciarcoleta(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Gari")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem permissão!");
    if(pGari[playerid][UniformeAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você está uniforme!");
    if(pGari[playerid][VeiculoAlugado] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não alugou um veículo!");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está dirigindo!");
    if(pGari[playerid][TemParceiro] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já está trabalhando com um(a) parceiro(a)!");
    if(pGari[playerid][LixoColetado] > 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não concluiu o serviço!");
    if(GetPlayerVehicleID(playerid) != pGari[playerid][VeiculoLixo]) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está em seu veículo alugado!");

    new String[128];
    format(String, sizeof(String), "| GARI | Você iniciou serviço com %s[%d]", PegarNick(playerid), playerid);

    new String2[128];
    for(new i=0; i < MAX_PLAYERS; i++){
        if(i != playerid){
            if(IsPlayerConnected(i)){
                if(!strcmp(Jogador[i][Profissao], "Gari")){
                    if(GetPlayerState(i) == PLAYER_STATE_PASSENGER && GetPlayerVehicleID(i) == pGari[playerid][VeiculoLixo])
                    {
                        if(pGari[i][UniformeAlugado] == false)
                        {
                            new String32[128];
                            format(String32, sizeof(String32), "| ERRO | %s[%d] não está utilizando seu uniforme!", PegarNick(i), i);
                            SendClientMessage(playerid, 0xfc520fFF, String32);
                            return 1;
                        }

                        if(pGari[i][TemParceiro] == true)
                        {
                            new String32[128];
                            format(String32, sizeof(String32), "| ERRO | %s[%d] já tem um(a) parceiro(a)!", PegarNick(i), i);
                            SendClientMessage(playerid, 0xfc520fFF, String32);
                            return 1;
                        }

                        if(pGari[i][LixoColetado] > 0)
                        {
                            new String32[128];
                            format(String32, sizeof(String32), "| ERRO | %s[%d] ainda não concluiu o serviço!", PegarNick(i), i);
                            SendClientMessage(playerid, 0xfc520fFF, String32);
                            return 1;
                        }

                        format(String2, sizeof(String2), "| GARI | %s[%d] Iniciou serviço com você", PegarNick(i), i);
                        SendClientMessage(playerid, 0xFFFF00FF, String2);
                        SendClientMessage(i, 0xFFFF00FF, String);

                        pGari[i][VeiculoLixo] = pGari[playerid][VeiculoLixo];

                        pGari[i][TemParceiro] = true;
                        pGari[playerid][TemParceiro] = true;

                        pGari[i][Parceiro] = playerid;
                        pGari[playerid][Parceiro] = i;

                        MostrarGariMenuLixo(i);
                        MostrarGariMenuLixo(playerid);

                        format(String, sizeof(String), "%d/%d", pGari[playerid][LixoColetado], MaximoLixo);
                        PlayerTextDrawSetString(playerid, GariMenu[playerid][0], String);
                        PlayerTextDrawSetString(i, GariMenu[i][0], String);
                        break;
                    }
                }
            }
        }
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid == pGari[playerid][CheckMapa])
    {
        if(pGari[playerid][LixoColetado] < 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem lixo para entregar!!");
        if(pGari[playerid][LixoNaMao] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Coloque o lixo no caminhão para descarregar!");
        new id = pGari[playerid][Parceiro];
        if(pGari[id][LixoNaMao] == true) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Seu(a) parceiro(a) precisa colocar o lixo no caminhão!");

        if(pGari[playerid][TemParceiro] == true)
        {
            DestroyDynamicCP(pGari[id][CheckMapa]);
            DestroyDynamicMapIcon(pGari[id][IconeMapa]);
            pGari[id][LixoColetado] = 0;
        }

        DestroyDynamicCP(pGari[playerid][CheckMapa]);
        DestroyDynamicMapIcon(pGari[playerid][IconeMapa]);

        new ValorTotal,
            ValorCoisado,
            LixosTT
        ;
        if(pGari[playerid][TemParceiro] == true)
        {
            ValorTotal = LixoPreco*pGari[playerid][LixoColetado];
            ValorCoisado = ValorTotal/2;
            LixosTT = pGari[playerid][LixoColetado];
        }
        else
        {
            ValorCoisado = LixoPreco*pGari[playerid][LixoColetado];
            LixosTT = pGari[playerid][LixoColetado];    
        }

        pGari[playerid][LixoColetado] = 0;
        new String[300];
        

        if(pGari[playerid][TemParceiro] == true)
        {
            format(String, sizeof(String), "| GARI | Você e seu(a) parceiro(a) {5DADE2}%s[%d]{FFFFFF} entregaram {5DADE2}%d{FFFFFF} lixo(s) e ganharam {00FF00}$%s{FFFFFF} para cada.", PegarNick(id), id, LixosTT, DinheiroSeparar(ValorCoisado));
            SendClientMessage(playerid, -1, String);

            format(String, sizeof(String), "| GARI | Você e seu(a) parceiro(a) {5DADE2}%s[%d]{FFFFFF} entregaram {5DADE2}%d{FFFFFF} lixo(s) e ganharam {00FF00}$%s{FFFFFF} para cada.", PegarNick(playerid), playerid, LixosTT, DinheiroSeparar(ValorCoisado));
            SendClientMessage(id, -1, String);

            SendClientMessage(playerid, 0xFFFF00FF, "| GARI | Vocês acabaram o serviço, espere outro(a) parceiro(a) ou utilize o comando /coletarlixo novamente!");
            SendClientMessage(id, 0xFFFF00FF, "| GARI | Vocês acabaram o serviço, espere outro(a) parceiro(a) ou utilize o comando /coletarlixo novamente!");
        
            pGari[id][Parceiro] = -1;
            pGari[id][CheckMapa] = -1;
            OcultarMenuGari(id);
        }
        else
        {
            format(String, sizeof(String), "| GARI | Você coletou {5DADE2}%d{FFFFFF} saco(s) de lixo e ganhou {00FF00}$%s", LixosTT, DinheiroSeparar(ValorCoisado));
            SendClientMessage(playerid, -1, String);   
        }

        
        pGari[playerid][Parceiro] = -1;
        pGari[playerid][CheckMapa] = -1;
        OcultarMenuGari(playerid);
        
        new MeuDinheiro,
            TotalS
        ;

        //Entrega do Dinheiro
        if(pGari[playerid][TemParceiro] == true)
        {
            MeuDinheiro = CallRemoteFunction("InformarFS", "is", id, "Dinheiro");
            TotalS = MeuDinheiro += ValorCoisado;
            CallRemoteFunction("ModifyGM", "isd", id, "Dinheiro", TotalS);
        }

        MeuDinheiro = CallRemoteFunction("InformarFS", "is", playerid, "Dinheiro");
        TotalS  = MeuDinheiro += ValorCoisado;
        CallRemoteFunction("ModifyGM", "isd", playerid, "Dinheiro", TotalS);

        
    }
    return 1;
}