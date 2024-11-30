#include <YSI_Coding\y_hooks>

enum PosicaoTestDrive
{
    Float:PosX,
    Float:PosY,
    Float:PosZ,
    Float:PosA
};

new VeiculoTestDrive[][PosicaoTestDrive] = 
{
    {-1870.3561, -757.0324, 31.6502, 91.2717},
    {-1871.0740, -760.0204, 31.6502, 89.6447},
    {-1871.9340, -762.8520, 31.6503, 90.7775},
    {-1871.6593, -765.9374, 31.6502, 91.0313},
    {-1871.4180, -769.0068, 31.6503, 89.8436},
    {-1871.6251, -771.9344, 31.6503, 91.1241},
    {-1871.8850, -775.0292, 31.6503, 91.1290},
    {-1871.8254, -777.9717, 31.6499, 89.4779}
};

Dialog:DialogTestDrive(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(pConce[playerid][Testando] == true) return Kick(playerid);

    //Remover dependencias da Concessionaria 
    DestroyVehicleEx(pConce[playerid][CarroIDConce]);
    SetPlayerVirtualWorld(playerid, 0);
    SetCameraBehindPlayer(playerid);
    OcultarConce(playerid);

    //Sistema de VIP com beneficio
    if(Jogador[playerid][Vip] > gettime()) SendClientMessage(playerid, 0xfc520fFF, "| AVISO | Você é um(a) jogador(a) por tanto não pagará pelo test-drive");
    else if(Jogador[playerid][Dinheiro] < 900) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro para fazer o test-drive");
    
    pConce[playerid][VendoCarros] = false;
    if(Jogador[playerid][Vip] > gettime())
    {
        pConce[playerid][Tempo] = 300;
        SendClientMessage(playerid, -1, "| AVISO | Você ganhou {00FF00}+2 minutos{FFFFFF} por ser um usuário VIP");
    }
    else
    {
        Jogador[playerid][Dinheiro] -= 900;
        pConce[playerid][Tempo] = 180;
    }

    //Iniciar o test-drive
    new idspawn = random(sizeof(VeiculoTestDrive)),
        vehid = pConce[playerid][Atual];

    GetPlayerPos(playerid, pConce[playerid][Pos][0], pConce[playerid][Pos][1], pConce[playerid][Pos][2]);
    pConce[playerid][VeiculoID] = CreateVehicleEx(playerid, VeiculoConceInfo[vehid][Modelo], VeiculoTestDrive[idspawn][PosX], VeiculoTestDrive[idspawn][PosY], VeiculoTestDrive[idspawn][PosZ], VeiculoTestDrive[idspawn][PosA], 1, 1, 60, 0);
    cAC[playerid][VeiculoPermitido] = pConce[playerid][VeiculoID];
    SetPlayerPos(playerid, VeiculoTestDrive[idspawn][PosX], VeiculoTestDrive[idspawn][PosY], VeiculoTestDrive[idspawn][PosZ]);
    PutPlayerInVehicle(playerid, pConce[playerid][VeiculoID], 0);   
    DisableRemoteVehicleCollisions(playerid, 1);  

    //Dependencias
    pConce[playerid][Testando] = true;
    MostrarTestDrive(playerid);
    SetTimerEx("TempoTestDriverr", 1000, false, "d", playerid);
    return 0;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pConce[playerid][VendoCarros] == true) DestroyVehicleEx(pConce[playerid][CarroIDConce]);   
    if(pConce[playerid][Testando] == true) DestroyVehicleEx(pConce[playerid][VeiculoID]);
    
    new tmp[ConcePlayer];
    pConce[playerid] = tmp;
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(pConce[playerid][Testando] == true && oldstate == PLAYER_STATE_DRIVER && newstate == PLAYER_STATE_ONFOOT){
        RemoverTestDrive(playerid, 1);
    }
    return 1;   
}

function TempoTestDriverr(playerid)
{
    if(pConce[playerid][Testando] == true)
    {
        if(Jogador[playerid][Preso] != 0) return RemoverTestDrive(playerid, 0);
        if(!IsPlayerInRangeOfPoint(playerid, 150.0, -1891.8013, -864.5792, 31.6147))
        {
            SendClientMessage(playerid, 0xfc520fFF, "| TEST-DRIVE | Você saiu do range permitido do test-drive!");
            RemoverTestDrive(playerid, 1);
            return 1;
        }

        new Float:CarroVidaaah;
        GetVehicleHealth(pConce[playerid][VeiculoID], CarroVidaaah);
        if(CarroVidaaah < 600)
        {
            SendClientMessage(playerid, 0xfc520fFF, "| TEST-DRIVE | Você quebrou o veículo do test-drive!");   
            RemoverTestDrive(playerid, 1);
            return 1;
        }

        if(pConce[playerid][Tempo] > 0)
        {
            pConce[playerid][Tempo]--;
            new Stt[70];
            format(Stt, sizeof(Stt), "Tempo: %s", SegundosParaMinutos(pConce[playerid][Tempo]));
            PlayerTextDrawSetString(playerid, TestDrive[playerid][1], Stt); 
            SetTimerEx("TempoTestDriverr", 1000, false, "d", playerid);
            return 1;
        }
        SendClientMessage(playerid, 0x00BFFFFF, "| TEST-DRIVE | Acabou o tempo do teste do veículo!");
        RemoverTestDrive(playerid, 1);
    }
    return 1;
}

stock RemoverTestDrive(playerid, modo)
{
    if(pConce[playerid][Testando] == false) return 1;
    OcultarTestDrive(playerid);
    pConce[playerid][Testando] = false;
    DestroyVehicleEx(pConce[playerid][VeiculoID]);
    if(modo == 1)
    {
        SetPlayerPos(playerid, pConce[playerid][Pos][0], pConce[playerid][Pos][1], pConce[playerid][Pos][2]);
        SetPlayerFacingAngle(playerid, pConce[playerid][Pos][3]);   
    }
    DisableRemoteVehicleCollisions(playerid, 0);
    return 1;
}

CMD:sairteste(playerid)
{
    if(pConce[playerid][Testando] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está em um test-drive");
    RemoverTestDrive(playerid, 1);
    return 1;
}