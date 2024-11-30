#include <YSI_Coding\y_hooks>

enum JogadorNeon
{
    bool:NeonTem,
    NeonObjeto1,
    NeonObjeto2
};

new pNeon[MAX_VEHICLES][JogadorNeon];

hook OnVehicleDestruido(vehicleid)
{
    if(pNeon[vehicleid][NeonTem] == true){
        DestroyDynamicObjectEx(pNeon[vehicleid][NeonObjeto1]);
        DestroyDynamicObjectEx(pNeon[vehicleid][NeonObjeto2]);
        pNeon[vehicleid][NeonTem] = false;
    } 
    return 1;
}

Dialog:NeonOpcao(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new model,
        nomea[20];
    
    if(pNeon[GetPlayerVehicleID(playerid)][NeonTem] == true){
        DestroyDynamicObjectEx(pNeon[GetPlayerVehicleID(playerid)][NeonObjeto1]);
        DestroyDynamicObjectEx(pNeon[GetPlayerVehicleID(playerid)][NeonObjeto2]);
    }

    switch(listitem)
    {
        case 0: {model = 18648; nomea = "Neon Azul";}
        case 1: {model = 18647; nomea = "Neon Vermelho";}
        case 2: {model = 18649; nomea = "Neon Verde";}
        case 3: {model = 18652; nomea = "Neon Branco";}
        case 4: {model = 18651; nomea = "Neon Rosa";}
        case 5: {model = 18650; nomea = "Neon Amarelo";}
        case 6: return SendClientMessage(playerid, 0xFFFF00FF, "| VIP | Você removeu os neons do veículo");
    }


    new Mensagem[45];
    format(Mensagem, sizeof(Mensagem), "| VIP | Você equipou o %s", nomea);
    pNeon[GetPlayerVehicleID(playerid)][NeonObjeto1] = CreateDynamicObject(model, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1, -1, -1, 80.0, 80.0, -1);
    pNeon[GetPlayerVehicleID(playerid)][NeonObjeto2] = CreateDynamicObject(model, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1, -1, -1, 80.0, 80.0, -1);
    pNeon[GetPlayerVehicleID(playerid)][NeonTem] = true;

    AttachDynamicObjectToVehicle(pNeon[GetPlayerVehicleID(playerid)][NeonObjeto2], GetPlayerVehicleID(playerid), -0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
    AttachDynamicObjectToVehicle(pNeon[GetPlayerVehicleID(playerid)][NeonObjeto1], GetPlayerVehicleID(playerid), 0.8, 0.0, -0.70, 0.0, 0.0, 0.0);
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);
    return 1;
}

CMD:neon(playerid)
{
	if(Jogador[playerid][Vip] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");

    new Horas, Minutos, Segundos;
    gettime(Horas, Minutos, Segundos);
    if(Horas < 17 && Horas > 5) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você só pode colocar os neons a partir das 17:00");

    new Dialog[90];
    strcat(Dialog, "1. Azul\n");
    strcat(Dialog, "2. Vermelho\n");
    strcat(Dialog, "3. Verde\n");
    strcat(Dialog, "4. Branco\n");
    strcat(Dialog, "5. Rosa\n");
    strcat(Dialog, "6. Amarelo\n");
    strcat(Dialog, "{FF0000}Remover Neon\n");
    Dialog_Show(playerid, NeonOpcao, DIALOG_STYLE_TABLIST, "{FF0000}Neon", Dialog, "Selecionar", "Fechar");
	return 1;
}