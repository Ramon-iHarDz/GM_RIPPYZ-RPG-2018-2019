#include <YSI_Coding\y_hooks>

new MafiaCompra,
    CompraMafia
;

new MotosMafia[4];

hook OnGameModeInit()
{
    MafiaCompra = CreateDynamicCP(-2810.1667,-1515.0150,139.2891, 1.0, 0, 0, -1, 90.0, -1);
    CompraMafia = CreateDynamicCP(2445.4421,-1970.0737,13.5469, 1.0, 0, 0, -1, 20.0, -1);

    MotosMafia[0] = CreateVehicleEx(-1, 468, -2824.6238,-1512.3772,138.9557,87.5457, 3, 3, 160, 0);
    MotosMafia[1] = CreateVehicleEx(-1, 468, -2824.6096,-1509.4598,138.9833,87.5461, 3, 3, 160, 0);
    MotosMafia[2] = CreateVehicleEx(-1, 468, -2824.2366,-1504.7925,138.9600,87.5474, 3, 3, 160, 0);
    MotosMafia[3] = CreateVehicleEx(-1, 468, -2824.1047,-1500.5201,138.9874,87.5471, 3, 3, 160, 0);

    VeiculoServer[MotosMafia[0]][VeiculoPublico] = true;
    VeiculoServer[MotosMafia[1]][VeiculoPublico] = true;
    VeiculoServer[MotosMafia[2]][VeiculoPublico] = true;
    VeiculoServer[MotosMafia[3]][VeiculoPublico] = true;
    return 1;
}

Dialog:CompraMafiaBase(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            if(Jogador[playerid][LockPick] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem lockpick");
            if(Jogador[playerid][Dinheiro] < 1250) return  SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente!");
            Jogador[playerid][LockPick] += 5;
            Jogador[playerid][Dinheiro] -= 1250;
            SendClientMessage(playerid, -1, "| MAFIA | Você comprou 5 lockpicks por {32CD32}$1.250");
        }

        case 1:
        {
            if(Jogador[playerid][Dinamites] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem dinamites");
            if(Jogador[playerid][Dinheiro] < 1100) return  SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente!");
            Jogador[playerid][Dinamites] += 5;
            Jogador[playerid][Dinheiro] -= 1100;
            SendClientMessage(playerid, -1, "| MAFIA | Você comprou 5 dinamites por {32CD32}$1.100");
        }
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid == CompraMafia)
    {
        if(strcmp(Jogador[playerid][Profissao], "Plantador de Maconha")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        new Dialog[300];
        strcat(Dialog, "Opção\tPreço\tOpcional\n");
        strcat(Dialog, "Sementes\t{32CD32}$250\n");
        strcat(Dialog, "Vasos\t{32CD32}$100\n");
        strcat(Dialog, "Adubos (Opcional)\t{32CD32}$600\t{00BFFF}Boost no Plantio\n");
        Dialog_Show(playerid, MenuPlantadorMafia, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Compra Mafia", Dialog, "Selecionar", "Fechar");
    }

    else if(checkpointid == MafiaCompra)
    {
        if(!IsMafia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
        new Dialog[300];
        strcat(Dialog, "Item\tPreço\n");
        strcat(Dialog, "{CCCCCC}LockPick\t{32CD32}$1.250\n");
        strcat(Dialog, "{CCCCCC}Dinamites\t{32CD32}$1.100\n");
        Dialog_Show(playerid, CompraMafiaBase, DIALOG_STYLE_TABLIST_HEADERS, "Mafia", Dialog, "Comprar", "Fechar");
    }
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if(ispassenger) return 1;
    new bool:ADKAS = false;
    for(new i=0; i < 4; i++){
        if(MotosMafia[i] != vehicleid) continue;
        ADKAS = true;
        break;
    }

    if(ADKAS == false) return 1;
    if(IsMafia(playerid)) return 1;
    new Float:PosAnti[3];
    TogglePlayerControllable(playerid, 0);
    GetPlayerPos(playerid, PosAnti[0], PosAnti[1], PosAnti[2]);
    SetTimerEx("Destravar", 3000, false, "i", playerid);
    SetPlayerPos(playerid, PosAnti[0], PosAnti[1], PosAnti[2]+0.8);
    SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");
    return 1;
}