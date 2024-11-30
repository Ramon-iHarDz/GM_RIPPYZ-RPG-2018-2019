#include <YSI_Coding\y_hooks>

#define     MAX_ENTREGAS_PIZZA     (3)

enum VeiculoInfoPizza{
    Float:PizzaX,
    Float:PizzaY,
    Float:PizzaZ,
    Float:PizzaA
};

enum PizzaBoyInfo{
    PizzaVeiculoID,
    PizzaStatus
};

enum EntregasPizza{
    bool:PizzaAtiva,
    PizzaCasa,
    PizzaCheck,
    PizzaMap,
    PizzaNpc
};

new pPizza[MAX_PLAYERS][PizzaBoyInfo];
new PizzaEntregas[MAX_PLAYERS][MAX_ENTREGAS_PIZZA][EntregasPizza];

new PizzaFloat[][VeiculoInfoPizza] =
{
    {219.6471,-170.7451,1.1775,90.0000},
    {219.6737,-173.2632,1.1778,90.0000},
    {219.7149,-175.7367,1.1770,90.0000},
    {219.7621,-178.2080,1.1771,90.0000},
    {219.7592,-180.6986,1.1770,90.0000},
    {196.5284,-154.7546,1.1771,180.0000},
    {199.5865,-154.7393,1.1769,180.0000},
    {202.3175,-154.6775,1.1765,180.0000}
};

hook OnGameModeInit(){
    CreateDynamic3DTextLabel("Pizza Delivery{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para pegar os pedidos", 0xDAA520FF, 213.1851,-183.1838,1.5781, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamic3DTextLabel("Pizza Delivery{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", 0xDAA520FF, 207.9778,-180.3981,1.5781, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);

    CreateDynamicPickup(1582, 1, 213.1851,-183.1838,1.5781, 0, 0, -1, 50.0, -1); // Pizza
    CreateDynamicPickup(1239, 1, 207.9778,-180.3981,1.5781, 0, 0, -1, 50.0, -1); // Pickup
    return 1;
}

hook OnPlayerDisconnect(playerid, reason){
    DestroyVehicleEx(pPizza[playerid][PizzaVeiculoID]);
    new caslac[EntregasPizza];
    for(new i=0; i < MAX_ENTREGAS_PIZZA; i++){
        DestroyDynamicCPEx(PizzaEntregas[playerid][i][PizzaCheck]);
        DestroyDynamicActorEx(PizzaEntregas[playerid][i][PizzaNpc]);
        DestroyDynamicMapIconEx(PizzaEntregas[playerid][i][PizzaMap]);
        PizzaEntregas[playerid][i] = caslac;
    }
    new dasda[PizzaBoyInfo];
    pPizza[playerid] = dasda;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys){
    if(newkeys == KEY_YES){
        
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 207.9778,-180.3981,1.5781)) // Alugar as motos
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Pizza Delivery")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(GetPVarInt(playerid, "DKSLAKDLADSA") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            if(pPizza[playerid][PizzaStatus] > 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");
            SetPVarInt(playerid, "DKSLAKDLADSA", gettime()+8);
            if(pPizza[playerid][PizzaStatus] < 1){
                new i = random(sizeof(PizzaFloat));
                pPizza[playerid][PizzaVeiculoID] = CreateVehicleEx(playerid, 448, PizzaFloat[i][PizzaX], PizzaFloat[i][PizzaY], PizzaFloat[i][PizzaZ], PizzaFloat[i][PizzaA], 1, 1, 360, 0);
                VeiculoServer[pPizza[playerid][PizzaVeiculoID]][Tranca] = 1;
                pPizza[playerid][PizzaStatus] = 1;
                Jogador[playerid][Trabalhando] = true;
                MarcarPosicao(playerid, PizzaFloat[i][PizzaX], PizzaFloat[i][PizzaY], PizzaFloat[i][PizzaZ]);
                SendClientMessage(playerid, 0xFFA500FF, "| INFO | Sua moto foi marcada no mapa");
                return 1;
            }
            DestroyVehicleEx(pPizza[playerid][PizzaVeiculoID]);
            VerificarMarcacao(playerid);
            pPizza[playerid][PizzaStatus] = 0;
            Jogador[playerid][Trabalhando] = false;
        }

        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 213.1851,-183.1838,1.5781)) // Iniciar Pedidos
        {
            if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Pizza Delivery")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pPizza[playerid][PizzaStatus] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem uma moto alugada");
            if(pPizza[playerid][PizzaStatus] > 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já pegou os pedidos");
        
            new CapEntrega = 0,
                cUID,
                bool:pdd = false;
                
            enum ReferenciaLocal{
                Float:RFX,
                Float:RFY,
                Float:RFZ
            };

            new RefereceLocal[][ReferenciaLocal] =
            {
                {2314.6733,-1390.1865,24.0420},
                {1731.4609,-2114.1238,13.3828},
                {361.9704,-1435.9763,34.2730}
            };
            new SourceRefect = random(sizeof(RefereceLocal));

            while(CapEntrega < MAX_ENTREGAS_PIZZA)
            {
                cUID = random(MAX_CASAS);
                if(pCasa[cUID][Colocado] == false) continue;
                if(GetDistanceBetweenPoints(RefereceLocal[SourceRefect][RFX],RefereceLocal[SourceRefect][RFY], RefereceLocal[SourceRefect][RFZ], pCasa[cUID][cPosicaoX], pCasa[cUID][cPosicaoY], pCasa[cUID][cPosicaoZ]) > 1410.9) continue;
                if(VerificarApartamento(cUID)) continue;
                pdd = false;
                for(new o=0; o < MAX_ENTREGAS_PIZZA; o++)
                {   
                    if(PizzaEntregas[playerid][o][PizzaAtiva] == true) continue;
                    for(new p=0; p < MAX_ENTREGAS_PIZZA; p++)
                    {
                        if(PizzaEntregas[playerid][p][PizzaCasa] != cUID) continue;
                        pdd = true;
                        break;
                    }
            
                    if(pdd == true) break;
                    
                    new Float:Jjp[2];
                    Jjp[0] = pCasa[cUID][cPosicaoX];
                    Jjp[1] = pCasa[cUID][cPosicaoY];
                    GetXY(Jjp[0], Jjp[1], pCasa[cUID][cPosicaoA], 1.4, 180.0);

                    pPizza[playerid][PizzaStatus] = 2;
                    PizzaEntregas[playerid][o][PizzaCheck] = CreateDynamicCP(Jjp[0], Jjp[1], pCasa[cUID][cPosicaoZ], 1.0, 0, 0, playerid, 100.0);
                    PizzaEntregas[playerid][o][PizzaMap] = CreateDynamicMapIcon(pCasa[cUID][cPosicaoX], pCasa[cUID][cPosicaoY], pCasa[cUID][cPosicaoZ], 60, -1, 0, 0, playerid, 999999.0, MAPICON_GLOBAL);
                    PizzaEntregas[playerid][o][PizzaNpc] = CreateDynamicActor(random(299), pCasa[cUID][cPosicaoX], pCasa[cUID][cPosicaoY], pCasa[cUID][cPosicaoZ], pCasa[cUID][cPosicaoA], 1, 100.0, 0, 0, -1, 90.0, -1, 0);
                    PizzaEntregas[playerid][o][PizzaAtiva] = true;
                    PizzaEntregas[playerid][o][PizzaCasa] = cUID;
                    CapEntrega++;
                    break;
                }
            }
            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "| DELIVERY | Você tem {00BFFF}%d{FFFFFF} para fazer, vá até os locais marcado no mapa.", CapEntrega);
            SendClientMessage(playerid, -1, Mensagem);
        }
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid){
    for(new i=0; i < MAX_ENTREGAS_PIZZA; i++){
        if(PizzaEntregas[playerid][i][PizzaCheck] != checkpointid) continue;
        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
        if(GetPlayerVehicleID(playerid) != pPizza[playerid][PizzaVeiculoID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em sua moto alugada");
        TogglePlayerControllable(playerid, 0);
        SetPVarInt(playerid, "PizzaID", i);
        CriarProgresso(playerid, "Entregando Pizza.", "PizzaEntregaType", 60); 
        break;
    }
    return 1;
}

function PizzaEntregaType(playerid){
    new id = GetPVarInt(playerid, "PizzaID"),
        Mensagem[70],
        Receb = random(450-300)+300;

    PizzaEntregas[playerid][id][PizzaAtiva] = false;
    DestroyDynamicCPEx(PizzaEntregas[playerid][id][PizzaCheck]);
    DestroyDynamicActorEx(PizzaEntregas[playerid][id][PizzaNpc]);
    DestroyDynamicMapIconEx(PizzaEntregas[playerid][id][PizzaMap]);
    Jogador[playerid][Dinheiro] += Receb;
    TogglePlayerControllable(playerid, 1);

    format(Mensagem, sizeof(Mensagem), "| DELIVERY | Você recebeu {32CD32}$%d{FFFFFF} pela entrega", Receb);
    SendClientMessage(playerid, -1, Mensagem);
    if(RestantePizza(playerid) < 1){
        pPizza[playerid][PizzaStatus] = 1;
        SendClientMessage(playerid, 0xFFA500FF, "| DELIVERY | Você concluiu suas entregas, volte para HQ");    
    }
    return 1;
}

stock RestantePizza(playerid){
    new qqqa;
    for(new i=0; i < MAX_ENTREGAS_PIZZA; i++){
        if(PizzaEntregas[playerid][i][PizzaAtiva] == false) continue;
        qqqa++;
    }
    return qqqa;
}