#include <YSI_Coding\y_hooks>

enum HotDogSpawn
{
    Float:HotDogX,
    Float:HotDogY,
    Float:HotDogZ,
    Float:HotDogA
};

enum JogadorHotDog
{
    bool:HotDogCar,
    bool:HotDogColocado,
    Text3D:HotDogTexto,
    HotDogID
};

new HotCar[][HotDogSpawn] = 
{
    {2490.2241,-1555.2462,23.9725,0.6207},
    {2485.0205,-1555.1554,23.9437,0.6737},
    {2479.6326,-1555.0697,23.9226,359.8412},
    {2474.0740,-1555.1924,23.9133,0.1016},
    {2468.3416,-1555.1530,23.9070,1.0013},
    {2462.4768,-1555.2511,23.9062,0.8582},
    {2456.6563,-1555.2913,23.9082,1.3598},
    {2451.2520,-1555.2618,23.9030,1.0382},
    {2445.7180,-1555.2239,23.9018,358.9172}
};
new pDog[MAX_PLAYERS][JogadorHotDog];

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Vendedor de Rua\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", 0xFFA500FF, 2478.3179,-1542.9130,24.1575, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1239, 1, 2478.3179,-1542.9130,24.1575, 0, 0, -1, 60.0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyVehicleEx(pDog[playerid][HotDogID]);
    DestroyDynamic3DTextLabelEx(pDog[playerid][HotDogTexto]);
    
    new alsdas[JogadorHotDog];
    pDog[playerid] = alsdas;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 2478.3179,-1542.9130,24.1575))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Vendedor de Rua")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pDog[playerid][HotDogColocado] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está com o veículo estacionado");

            if(GetPVarInt(playerid, "ALDKASKDAMNASD") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            SetPVarInt(playerid, "ALDKASKDAMNASD", gettime()+10);

            if(pDog[playerid][HotDogCar] == false)
            {
                new i = random(sizeof(HotCar));
                pDog[playerid][HotDogID] = CreateVehicleEx(playerid, 588, HotCar[i][HotDogX], HotCar[i][HotDogY], HotCar[i][HotDogZ], HotCar[i][HotDogA], random(360), random(360), 360, 0);
                VeiculoServer[pDog[playerid][HotDogID]][Tranca] = 1;
                format(VeiculoServer[ExeVeh[i]][LocalVerificacao], 90, "HotDogVeiculo");
                MarcarPosicao(playerid, HotCar[i][HotDogX], HotCar[i][HotDogY], HotCar[i][HotDogZ]);
                pDog[playerid][HotDogCar] = true;
                Jogador[playerid][Trabalhando] = true;
                SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você alugou um veículo");
                return 1;
            }
            VerificarMarcacao(playerid);
            pDog[playerid][HotDogCar] = false;
            Jogador[playerid][Trabalhando] = false;
            DestroyVehicleEx(pDog[playerid][HotDogID]);
            SendClientMessage(playerid, 0xFFFF00FF, "| AVISO | Você devolveu o seu veículo");
        }
    }
    else if(newkeys == KEY_NO)
    {
        for(new i=0; i < MAX_PLAYERS; i++)
        {
            if(pDog[i][HotDogColocado] == false) continue;

            new Float:Kals[4];
            GetVehiclePos(pDog[i][HotDogID], Kals[0], Kals[1], Kals[2]);
            GetVehicleZAngle(pDog[i][HotDogID], Kals[3]);
            GetXY(Kals[0], Kals[1], Kals[3], 1.7, 90.0);
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, Kals[0], Kals[1], Kals[2])) continue;
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            
            SetPVarInt(playerid, "HotDogID", i);

            new Dialog[400];
            strcat(Dialog, "Opção\tPreço\n");
            strcat(Dialog, "{FFFF00}~~~Lanches~~~\n");
            strcat(Dialog, "- Cachorro Quente\t{32CD32}R$2\n");
            strcat(Dialog, "- Batata Frita\t{32CD32}R$8\n");
            strcat(Dialog, "- Pastel\t{32CD32}R$3\n");
            strcat(Dialog, "- Coxinha\t{32CD32}R$3\n");
            strcat(Dialog, "- Hambúrguer\t{32CD32}R$10\n");
            strcat(Dialog, "{FFFF00}~~~Bebidas~~~\n");
            strcat(Dialog, "- Coca-Cola\t{32CD32}R$2\n");
            strcat(Dialog, "- Fanta\t{32CD32}R$2\n");
            strcat(Dialog, "- Pepsi\t{32CD32}R$2\n");
            strcat(Dialog, "- Guaraná\t{32CD32}R$2\n");
            strcat(Dialog, "- Água\t{32CD32}R$1");
            Dialog_Show(playerid, LancheFoodTruck, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Vendedor(a)", Dialog, "Comprar", "Fechar");
            break;
        }
    }
    return 1;
}

Dialog:LancheFoodTruck(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "HotDogID");  
    if(pDog[id][HotDogColocado] == false) return 1;

    switch(listitem)
    {
        // Comidas
        case 1: ComidaFood(playerid, 1, "Cachorro Quente", 2);
        case 2: ComidaFood(playerid, 1, "Batata Frita", 8);
        case 3: ComidaFood(playerid, 1, "Pastel", 3);
        case 4: ComidaFood(playerid, 1, "Coxinha", 3);
        case 5: ComidaFood(playerid, 1, "Hambúrguer", 10);

        // Bebidas
        case 7: ComidaFood(playerid, 2, "Coca-Cola", 2);
        case 8: ComidaFood(playerid, 2, "Fanta", 2);
        case 9: ComidaFood(playerid, 2, "Pepsi", 2);
        case 10: ComidaFood(playerid, 2, "Guaraná", 2);
        case 11: ComidaFood(playerid, 2, "Água", 1);
    }

    return 1;
}

stock ComidaFood(playerid, type, const name[], value)
{
    new id = GetPVarInt(playerid, "HotDogID"),
        Mensagem[75];
    format(Mensagem, sizeof(Mensagem), "| VENDEDOR | Você comprou {e2b960}%s{FFFFFF} por {32CD32}R$%d", name, value);
    SendClientMessage(playerid, -1, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| VENDEDOR | %s[%d] comprou %s", PegarNick(playerid), playerid, name);
    SendClientMessage(id, -1, Mensagem);

    Jogador[id][Dinheiro] += value;
    Jogador[playerid][Dinheiro] -= value;

    if(type == 1) ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
    else ApplyAnimation(playerid, "VENDING", "VEND_Drink_P", 3.0, 0, 0, 0, 0, 0);
    EnviarComida(playerid, type, 11.0); 
    return 1;
}

function HotDogVeiculo(playerid)
{
    if(pDog[playerid][HotDogColocado] == true)
    {
        SendClientMessage(playerid, 0xFF4500FF, "| VENDEDOR | Seu veículo está estacionado");
        return false;
    }
    return true;
}

CMD:estacionar(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Vendedor de Rua")) return 0;
    if(pDog[playerid][HotDogCar] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem um veículo alugado");
    
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está dirigindo");
    
    new Float:DASL[3];
    GetPlayerPos(playerid, DASL[0], DASL[1], DASL[2]);
    if(!IsVehicleInRangeOfPoint(pDog[playerid][HotDogID], 15.0, DASL[0], DASL[1], DASL[2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo está longe de você");

    new engine, lights, alarm, doors, bonnet, boot, objective;
	GetVehicleParamsEx(pDog[playerid][HotDogID], engine, lights, alarm, doors, bonnet, boot, objective);
    if(engine == VEHICLE_PARAMS_OFF) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Veículo não está ligado, ligue-o.");


    if(pDog[playerid][HotDogColocado] == false)
    {
        pDog[playerid][HotDogColocado] = true;
        pDog[playerid][HotDogTexto] = CreateDynamic3DTextLabel("Vendedor de Rua{FFFFFF}\nAperte {CCCCCC}'N'{FFFFFF} visualizar o cardápio", 0x32CD32FF, 1.6499, -0.3899, 0.0000, 10.0, INVALID_PLAYER_ID, pDog[playerid][HotDogID], 0, 0, 0, -1, 11.0, -1);
        SendClientMessage(playerid, 0xFFFF00FF, "| VENDEDOR | Você estacionou seu veículo");
    }
    else
    {
        pDog[playerid][HotDogColocado] = false;
        DestroyDynamic3DTextLabelEx(pDog[playerid][HotDogTexto]);
    }
    return 1;
}