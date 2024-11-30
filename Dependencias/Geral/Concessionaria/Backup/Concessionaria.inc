#include <YSI_Coding\y_hooks>

enum ConcePlayer
{
    //Conce
    Lista,
    Atual,
    CarroIDConce,
    VirtualWorld,
    bool:VendoCarros,

    //Teste Drive
    bool:Testando,
    Float:Pos[4],
    VeiculoID,
    Tempo
};

new pConce[MAX_PLAYERS][ConcePlayer];

hook OnGameModeInit()
{
    for(new i=0; i < sizeof(ConceLocal); i++)
    {
        CreateDynamicMapIcon(ConceLocal[i][ConcePosicaoX], ConceLocal[i][ConcePosicaoY], ConceLocal[i][ConcePosicaoZ], 12, -1, 0, 0, -1, 90.0, MAPICON_LOCAL, -1, 0);
        CreateDynamicPickup(1239, 1, ConceLocal[i][ConcePosicaoX], ConceLocal[i][ConcePosicaoY], ConceLocal[i][ConcePosicaoZ], 0, 0, -1, 40.0, -1, 0);
        CreateDynamic3DTextLabel("{00FF00}Concessionária\n{FFFFFF}Aperte 'Y' para visualizar", -1, ConceLocal[i][ConcePosicaoX], ConceLocal[i][ConcePosicaoY], ConceLocal[i][ConcePosicaoZ], 40.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 40.0, -1, 0);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    for(new i=0; i < sizeof(ConceLocal); i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, ConceLocal[i][ConcePosicaoX], ConceLocal[i][ConcePosicaoY], ConceLocal[i][ConcePosicaoZ])) continue;
        if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0) return 1;
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
        if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
        // if(pMorreu[playerid][EstaCaido] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está ferido(a)");
        
        SetPVarInt(playerid, "ConceS", 0);
        if(IsPlayerInRangeOfPoint(playerid, 5.0, -1262.8848, 40.7986, 14.1391)) SetPVarInt(playerid, "ConceS", 1);

        pConce[playerid][Atual] = 0;
        pConce[playerid][Lista] = i;
        pConce[playerid][VendoCarros] = true;

        if(GetPVarInt(playerid, "ConceS") == 1) pConce[playerid][CarroIDConce] = CreateVehicleEx(-1, AeroConceInfo[0][Modelo], ConceLocal[i][VeiculoSpecX], ConceLocal[i][VeiculoSpecY], ConceLocal[i][VeiculoSpecZ], ConceLocal[i][VeiculoSpecA], 1, 1, -1, 0);
        else pConce[playerid][CarroIDConce] = CreateVehicleEx(-1, VeiculoConceInfo[0][Modelo], ConceLocal[i][VeiculoSpecX], ConceLocal[i][VeiculoSpecY], ConceLocal[i][VeiculoSpecZ], ConceLocal[i][VeiculoSpecA], 1, 1, -1, 0);
        pConce[playerid][VirtualWorld] = playerid*playerid+1;

        SetPlayerVirtualWorld(playerid, pConce[playerid][VirtualWorld]);
        SetVehicleVirtualWorld(pConce[playerid][CarroIDConce], pConce[playerid][VirtualWorld]);

        SetPlayerCameraPos(playerid, ConceLocal[i][CameraPX], ConceLocal[i][CameraPY], ConceLocal[i][CameraPZ]);
        SetPlayerCameraLookAt(playerid, ConceLocal[i][CameraCX], ConceLocal[i][CameraCY], ConceLocal[i][CameraCZ], CAMERA_MOVE);

        MostrarConce(playerid);
        ConceUpdate(playerid);
        break;
    }
    return 1;
}

stock ConceUpdate(playerid)
{
    new id = pConce[playerid][Lista],
        vehid = pConce[playerid][Atual],
        ValorExZ[128];

    DestroyVehicleEx(pConce[playerid][CarroIDConce]);

    if(GetPVarInt(playerid, "ConceS") == 1) pConce[playerid][CarroIDConce] = CreateVehicleEx(-1, AeroConceInfo[vehid][Modelo], ConceLocal[id][VeiculoSpecX], ConceLocal[id][VeiculoSpecY], ConceLocal[id][VeiculoSpecZ], ConceLocal[id][VeiculoSpecA], 1, 1, -1, 0);
    else pConce[playerid][CarroIDConce] = CreateVehicleEx(-1, VeiculoConceInfo[vehid][Modelo], ConceLocal[id][VeiculoSpecX], ConceLocal[id][VeiculoSpecY], ConceLocal[id][VeiculoSpecZ], ConceLocal[id][VeiculoSpecA], 1, 1, -1, 0);
    SetVehicleVirtualWorld(pConce[playerid][CarroIDConce], pConce[playerid][VirtualWorld]);

    if(GetPVarInt(playerid, "ConceS") == 1)
    {
        format(ValorExZ, sizeof(ValorExZ), "$%s", DinheiroSeparar(AeroConceInfo[vehid][Valor]));
        PlayerTextDrawSetString(playerid, ConceT[playerid][16], AeroConceInfo[vehid][Nome]);
        PlayerTextDrawSetString(playerid, ConceT[playerid][17], AeroConceInfo[vehid][Categoria]);
        PlayerTextDrawSetPreviewModel(playerid, ConceT[playerid][4], AeroConceInfo[vehid][Modelo]);
    }
    else
    {
        format(ValorExZ, sizeof(ValorExZ), "$%s", DinheiroSeparar(VeiculoConceInfo[vehid][Valor]));
        PlayerTextDrawSetString(playerid, ConceT[playerid][16], VeiculoConceInfo[vehid][Nome]);
        PlayerTextDrawSetString(playerid, ConceT[playerid][17], VeiculoConceInfo[vehid][Categoria]);
        PlayerTextDrawSetPreviewModel(playerid, ConceT[playerid][4], VeiculoConceInfo[vehid][Modelo]);
    }
    PlayerTextDrawSetString(playerid, ConceT[playerid][18], ValorExZ);
    PlayerTextDrawShow(playerid, ConceT[playerid][4]);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == ConceT[playerid][15]) //Trás
    {  
        if(pConce[playerid][Atual] == 0) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Não há mais veículos para trás, vá para frente!");
        pConce[playerid][Atual]--;
        ConceUpdate(playerid);
    }

    else if(playertextid == ConceT[playerid][14])//Frente
    {
        if(GetPVarInt(playerid, "ConceS") == 1 && pConce[playerid][Atual] == sizeof(AeroConceInfo)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Não há mais veículos para frente, vá para trás!");
        else if(pConce[playerid][Atual] == sizeof(VeiculoConceInfo)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Não há mais veículos para frente, vá para trás!");
        pConce[playerid][Atual]++;
        ConceUpdate(playerid);
    }

    else if(playertextid == ConceT[playerid][6]) //Cancelar
    { 
        OcultarConce(playerid);
        DestroyVehicleEx(pConce[playerid][CarroIDConce]); 
        SetPlayerVirtualWorld(playerid, 0);
        SetCameraBehindPlayer(playerid);   
        pConce[playerid][VendoCarros] = false;
    }

    else if(playertextid == ConceT[playerid][7]) //Comprar
    { 
        OcultarConce(playerid);
        DestroyVehicleEx(pConce[playerid][CarroIDConce]);
        SetPlayerVirtualWorld(playerid, 0);
        SetCameraBehindPlayer(playerid);
        Dialog_Show(playerid, ConfirmarCompraCarro, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", "Você realmente deseja comprar esse veículo?", "Sim", "Não");
    }

    else if(playertextid == ConceT[playerid][5]) //Test Drive
    {
        if(GetPVarInt(playerid, "ConceS") == 1) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode testar um avião/helicoptero!"); 
        new Enviar[90];
        if(Jogador[playerid][Vip] > gettime()) format(Enviar, sizeof(Enviar), "{CCCCCC}Você deseja realmente fazer o test-drive?");
        else format(Enviar, sizeof(Enviar), "{CCCCCC}Você pagará {00FF00}$900{CCCCCC} para fazer o test-drive, deseja continuar?");
        Dialog_Show(playerid, DialogTestDrive, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", Enviar, "Sim", "Não");
    }
    return 0;
}