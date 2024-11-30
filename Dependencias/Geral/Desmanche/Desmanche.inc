#include <YSI_Coding\y_hooks>

enum JogadorDesmanche
{
    DesmancheStatus,
    DesmancheVeiculoID,
    DesmanchePreco,
    bool:DesmancheAguardo,
    Text3D:DesmancheTexto
};

new pDesmanche[MAX_PLAYERS][JogadorDesmanche];

hook OnGameModeInit(){
    CreateDynamic3DTextLabel("Desmanche{FFFFFF}\nAperte {CCCCCC}'N'{FFFFFF} para desmanchar\nObservação: {FF4500}Você precisa estar no veículo", 0xFFFF00FF, -1717.9353, 12.4277, 3.4447, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1239, 1, -1717.9353, 12.4277, 3.4447, 0, 0, -1, 90.0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason){
    if(pDesmanche[playerid][DesmancheStatus] > 0) DestroyVehicleEx(pDesmanche[playerid][DesmancheVeiculoID]);
    new psad[JogadorDesmanche];
    pDesmanche[playerid] = psad;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_NO)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, -1717.9353, 12.4277, 3.4447))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo.");
            
            new id = GetPlayerVehicleID(playerid),
                bool:alod;

            for(new i=0; i < MAX_PLAYERS; i++)
            {
                if(!IsPlayerConnected(i)) continue;
                if(Jogador[i][Logado] == false) continue;
                for(new d=0; d < MAX_SLOT_VEH; d++)
                {
                    if(pVeiculo[i][d][VehConectado] == false) continue;
                    if(pVeiculo[i][d][MeuVeiculoID] != id) continue;
                    if(!IsApenasCarro(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode desmanchar esse veículo");
                    if(i == playerid) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode desmanchar seu veículo");

                    pDesmanche[playerid][DesmancheStatus] = 1;
                    pDesmanche[playerid][DesmancheVeiculoID] = id;
                    pDesmanche[playerid][DesmanchePreco] = pVeiculo[i][d][Preco];

                    // Dependências
                    new askdas = pDesmanche[playerid][DesmanchePreco],
                        dasdsa = pDesmanche[playerid][DesmanchePreco];
                    new RodaCidade = (askdas * 30) / 100,
                        Query[128];

                    dasdsa -= RodaCidade;
                    dasdsa += random(20000-10000)+10000; 
                    
                    pVeiculo[i][d][VehConectado] = false;
                    pVeiculo[i][d][Patio] = dasdsa;
                    format(Query, sizeof(Query), "UPDATE `veiculos` SET `Patio`=%d WHERE `Nome`='%s' AND `Slot`=%d", dasdsa, EscapeString(PegarNick(i)), d);
                    mysql_query(IDConexao, Query, false);

                    SetPlayerPos(playerid, -1707.6843,7.9064,3.5489);
                    SetVehicleVirtualWorld(id, playerid+playerid+1);
                    SetVehicleZAngle(id, 41.0181);
                    SetVehiclePos(id, -1702.0412, 5.0975, 4.0675);
                    SetPlayerVirtualWorld(playerid, playerid+playerid+1);
                    

                    format(VeiculoServer[id][LocalVerificacao], 90, "VerificarDesmanche");
                    SetVehicleParamsCarWindows(id, true, true, true, true);

                    pDesmanche[playerid][DesmancheTexto] = CreateDynamic3DTextLabel("Use: {CCCCCC}'/Desmanchar'{FFFFFF} para pegar as peças da porta", 0xFFFFFFFF, -1703.1097,3.9142,3.5547, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, playerid+playerid+1, 0, playerid, 16.0, -1);

                    SendClientMessage(playerid, 0xFFFF00FF, "| DESMANCHE | Você iniciou o desmanche de veículo, siga os passos");
                    alod = true;
                    break;
                }
                if(alod == true) break;
            }
            if(alod == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode desmanchar esse veículo");
            return 1;
        }
    }
    return 1;
}

function VerificarDesmanche(playerid){
    return false;
}

function EtapaDesmanche1(playerid){
    TogglePlayerControllable(playerid, 1);
    DestroyDynamic3DTextLabelEx(pDesmanche[playerid][DesmancheTexto]);
    pDesmanche[playerid][DesmancheTexto] = CreateDynamic3DTextLabel("Use: {CCCCCC}'/Desmanchar'{FFFFFF} para pegar as peças da porta", 0xFFFFFFFF, -1700.2366,6.2487,3.5547, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, playerid+playerid+1, 0, playerid, 16.0, -1);
    pDesmanche[playerid][DesmancheStatus] = 2;
    pDesmanche[playerid][DesmancheAguardo] = false;
    SendClientMessage(playerid, 0xFFFF00FF, "| DESMANCHE | Vá até o outro lado para remover as peças");
    return 1;
}

function EtapaDesmanche2(playerid){
    TogglePlayerControllable(playerid, 1);
    DestroyDynamic3DTextLabelEx(pDesmanche[playerid][DesmancheTexto]);
    pDesmanche[playerid][DesmancheTexto] = CreateDynamic3DTextLabel("Use: {CCCCCC}'/Desmanchar'{FFFFFF} para pegar as peças do motor", 0xFFFFFFFF, -1704.0292,7.1835,3.5489, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, playerid+playerid+1, 0, playerid, 16.0, -1);
    pDesmanche[playerid][DesmancheStatus] = 3;
    pDesmanche[playerid][DesmancheAguardo] = false;
    SendClientMessage(playerid, 0xFFFF00FF, "| DESMANCHE | Vá até o motor para remover as peças");
    return 1;
}

function EtapaDesmanche3(playerid){
    TogglePlayerControllable(playerid, 1);
    DestroyDynamic3DTextLabelEx(pDesmanche[playerid][DesmancheTexto]);
    pDesmanche[playerid][DesmancheStatus] = 0;
    pDesmanche[playerid][DesmancheAguardo] = false;
    DestroyVehicleEx(pDesmanche[playerid][DesmancheVeiculoID]);
    SetPlayerVirtualWorld(playerid, 0);
    new Mensagem[128],
        askdas = pDesmanche[playerid][DesmanchePreco];
    new RodaCidade = (askdas * 30) / 100;
    pDesmanche[playerid][DesmanchePreco] -= RodaCidade;
    Jogador[playerid][Dinheiro] += pDesmanche[playerid][DesmanchePreco];
    Jogador[playerid][Estrelas] += random(18-14)+14;
    format(Mensagem, sizeof(Mensagem), "| DESMANCHE | Você recebeu {32CD32}R$%s{FFFFFF} pelo desmanche do veículo", DinheiroSeparar(RodaCidade));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

CMD:desmanchar(playerid)
{
    if(pDesmanche[playerid][DesmancheStatus] < 1) return 0;
    if(pDesmanche[playerid][DesmancheAguardo] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode desmanchar esse veículo");
    
    switch(pDesmanche[playerid][DesmancheStatus])
    {
        case 1:
        {
            if(!IsPlayerInRangeOfPoint(playerid, 1.0, -1703.1097,3.9142,3.5547)) return 1;
            pDesmanche[playerid][DesmancheAguardo] = true;
            TogglePlayerControllable(playerid, 0);
            CriarProgresso(playerid, "Retirando Peças da Porta, aguarde.", "EtapaDesmanche1", 600); 
        }
        case 2:
        {
            if(!IsPlayerInRangeOfPoint(playerid, 1.0, -1700.2366,6.2487,3.5547)) return 1;
            pDesmanche[playerid][DesmancheAguardo] = true;
            TogglePlayerControllable(playerid, 0);
            CriarProgresso(playerid, "Retirando Peças da Porta, aguarde.", "EtapaDesmanche2", 700);  
        }
        case 3:
        {
            if(!IsPlayerInRangeOfPoint(playerid, 1.0, -1704.0292,7.1835,3.5489)) return 1;
            pDesmanche[playerid][DesmancheAguardo] = true;
            TogglePlayerControllable(playerid, 0);
            CriarProgresso(playerid, "Retirando Peças do Motor, aguarde.", "EtapaDesmanche3", 800); 
        }
    }
    return 1;
}