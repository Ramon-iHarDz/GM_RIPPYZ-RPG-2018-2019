#include <YSI_Coding\y_hooks>

enum TransCarne
{
    Float:vCarneX,
    Float:vCarneY,
    Float:vCarneZ,
    Float:vCarneA
};

enum TransPlayer
{
    bool:CarneVeiculo,
    bool:CaixaAcou,
    CarneVID,

    Float:Mkj[3],

    CheckCarne,
    MapCarne,
    Text3D:Jkas,
    CarneCaixa
};


new pTCarne[MAX_PLAYERS][TransPlayer];
new CarroCarne[][TransCarne] = 
{
    {790.1711,-608.9578,16.7745,358.3954},
    {820.1164,-609.0778,16.7772,358.7904},
    {830.0659,-608.6512,16.7763,359.8996}
};

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Transportador de Carne{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para alugar", 0xFFFF00FF, 797.5157,-616.5657,16.3359, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1239, 1, 797.5157,-616.5657,16.3359, 0, 0, -1, 100.0, -1);

    CreateDynamic3DTextLabel("Transportador de Carne{FFFFFF}\nAperte {CCCCCC}'Y'{FFFFFF} para pegar caixa", 0xFFFF00FF, 1218.4352,186.1265,20.3521, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 16.0, -1);
    CreateDynamicPickup(1239, 1, 1218.4352,186.1265,20.3521, 0, 0, -1, 100.0, -1);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyDynamicCPEx(pTCarne[playerid][CheckCarne]);
    DestroyDynamicMapIconEx(pTCarne[playerid][MapCarne]);
    DestroyDynamic3DTextLabelEx(pTCarne[playerid][Jkas]);
    DestroyDynamicObjectEx(pTCarne[playerid][CarneCaixa]);
    if(pTCarne[playerid][CarneVeiculo] == true) DestroyVehicleEx(pTCarne[playerid][CarneVID]);

    new asdf[TransPlayer];
    pTCarne[playerid] = asdf;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_YES)
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 797.5157,-616.5657,16.3359))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(strcmp(Jogador[playerid][Profissao], "Transportador de Carne")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não precisa estar a pé");
            if(GetPVarInt(playerid, "askdlaksSA") > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda está em serviço");
            if(GetPVarInt(playerid, "DASKDJKSAJDA") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            SetPVarInt(playerid, "DASKDJKSAJDA", gettime()+10);
            if(pTCarne[playerid][CarneVeiculo] == false)
            {
                new asd = random(sizeof(CarroCarne));
                pTCarne[playerid][CarneVID] = CreateVehicleEx(playerid, 422, CarroCarne[asd][vCarneX], CarroCarne[asd][vCarneY], CarroCarne[asd][vCarneZ], CarroCarne[asd][vCarneA], 1, 1, 360, 0);
                VeiculoServer[pTCarne[playerid][CarneVID]][Tranca] = 1;
                // format(VeiculoServer[pTCarne[playerid][CarneVID]][LocalVerificacao], 90, "CaixaVerificarAcougue");
                pTCarne[playerid][CarneVeiculo] = true;
                Jogador[playerid][Trabalhando] = true;
                MarcarPosicao(playerid, CarroCarne[asd][vCarneX], CarroCarne[asd][vCarneY], CarroCarne[asd][vCarneZ]);
                SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você alugou um veículo");
                return 1;
            }
            VerificarMarcacao(playerid);
            pTCarne[playerid][CarneVeiculo] = false;
            Jogador[playerid][Trabalhando] = false;
            DestroyVehicleEx(pTCarne[playerid][CarneVID]);
            SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Você devolveu seu veículo");
        }

        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 1218.4352,186.1265,20.3521))
        {
            if(!IsPlayerInDynamicArea(playerid, AreaCarne)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na área de açougue");
            if(strcmp(Jogador[playerid][Profissao], "Transportador de Carne")) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            if(pTCarne[playerid][CarneVeiculo] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem um caminhão de açougueiro alugado");  
            if(pTCarne[playerid][CaixaAcou] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está segurando uma caixa");
            if(!IsVehicleInRangeOfPoint(pTCarne[playerid][CarneVID], 90.0, 1218.4352,186.1265,20.3521)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu veículo está muito longe de você");
            if(GetPVarInt(playerid, "DJASKLDJKLSA") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já pegou uma caixa");
            if(CarneProntas < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há caixas para pegar no momento, aguarde.");
            SetPVarInt(playerid, "DJASKLDJKLSA", 1);
            pTCarne[playerid][CaixaAcou] = true;
            pTCarne[playerid][Jkas] = CreateDynamic3DTextLabel("Aperte 'H' para colocar uma caixa", -1, 0.0000, -4.0999, -0.9000, 10.0, INVALID_PLAYER_ID, pTCarne[playerid][CarneVID], 0, 0, 0, playerid, 11.0, -1);
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
            SetPlayerAttachedObject(playerid, 9, 1220, 3, 0.1310, -0.4270, -0.1290, -7.3999, 3.4000, 29.9000, 0.5850, 0.5280, 0.6530, 0xFFFFFFFF, 0xFFFFFFFF);
        }
    }

    else if(newkeys == KEY_CTRL_BACK)
    {
        if(AtrasVeiculo(playerid, pTCarne[playerid][CarneVID], 2.0))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não precisa estar a pé"); 
            if(pTCarne[playerid][CaixaAcou] == false)
            {
                if(GetPVarInt(playerid, "askdlaksSA") == 0) return 1;
                if(GetPVarInt(playerid, "DKASLDLAS") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já pegou uma caixa"); 
                if(!IsPlayerInRangeOfPoint(playerid, 90.0, pTCarne[playerid][Mkj][0], pTCarne[playerid][Mkj][1], pTCarne[playerid][Mkj][2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está longe do local de entregas."); 
                SetPVarInt(playerid, "dasdasdas", 0); 
                DestroyDynamic3DTextLabelEx(pTCarne[playerid][Jkas]);
                DestroyDynamicObjectEx(pTCarne[playerid][CarneCaixa]);
                SetPVarInt(playerid, "DKASLDLAS", 1);

                ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 1, 0, 0, 1, 1, 1);
                SetPlayerAttachedObject(playerid, 9, 1220, 3, 0.1310, -0.4270, -0.1290, -7.3999, 3.4000, 29.9000, 0.5850, 0.5280, 0.6530, 0xFFFFFFFF, 0xFFFFFFFF);
                return 1;
            }
            pTCarne[playerid][CaixaAcou] = false;
            new Float:Lksa[3];
            switch(random(1))
            {
                case 0: {Lksa[0] = 2781.5310; Lksa[1] = -2448.8547; Lksa[2] = 13.6352;}
                case 1: {Lksa[0] = -1702.3127; Lksa[1] = 15.9721; Lksa[2] = 3.5547;}
            }

            CarneProntas -= 1;

            ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
            RemovePlayerAttachedObject(playerid, 9);
            DestroyDynamic3DTextLabelEx(pTCarne[playerid][Jkas]);
            pTCarne[playerid][CheckCarne] = CreateDynamicCP(Lksa[0], Lksa[1], Lksa[2], 1.0, 0, 0, playerid, 120.0, -1);
            pTCarne[playerid][MapCarne] = CreateDynamicMapIcon(Lksa[0], Lksa[1], Lksa[2], 51, -1, 0, 0, playerid, 99999.9, MAPICON_GLOBAL, -1);
            pTCarne[playerid][CarneCaixa] = CreateDynamicObject(1271, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, -1, 160.0, 160.0, -1);
            AttachDynamicObjectToVehicle(pTCarne[playerid][CarneCaixa], pTCarne[playerid][CarneVID], 0.0000, -1.5000, 0.1000, 0.0000, 0.0000, 0.000);


            pTCarne[playerid][Mkj][0] = Lksa[0];
            pTCarne[playerid][Mkj][1] = Lksa[1];
            pTCarne[playerid][Mkj][2] = Lksa[2];
            SetPVarInt(playerid, "askdlaksSA", 1);
            SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Vá até o porto para entregar a caixa");
        }
    }

    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    if(checkpointid != pTCarne[playerid][CheckCarne]) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa estar a pé");
    if(GetPVarInt(playerid, "DKASLDLAS") == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está segurando uma caixa, pegue-a atrás do veículo");
    SetPVarInt(playerid, "DKASLDLAS", 0);
    SetPVarInt(playerid, "askdlaksSA", 0);
    SetPVarInt(playerid, "DJASKLDJKLSA", 0);
    DestroyDynamicCPEx(pTCarne[playerid][CheckCarne]);
    DestroyDynamicMapIconEx(pTCarne[playerid][MapCarne]);

    ApplyAnimation(playerid,"CARRY", "putdwn", 4.0, 0, 0, 0, 0, 0);
    RemovePlayerAttachedObject(playerid, 9);

    new Mensagem[128],
        asda = random(1300-1000)+1000;
    Jogador[playerid][Dinheiro] += asda;
    format(Mensagem, sizeof(Mensagem), "| TRANSPORTE | Você recebeu {32CD32}$%s{FFFFFF} por entregar carnes no porto", DinheiroSeparar(asda));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_ONFOOT)
    {
        if(GetPVarInt(playerid, "askdlaksSA") == 0) return 1;
        if(GetPVarInt(playerid, "dasdasdas") == 1) return 1;
        if(Jogador[playerid][uVeiculo] != pTCarne[playerid][CarneVID]) return 1;
        if(!IsPlayerInRangeOfPoint(playerid, 90.0, pTCarne[playerid][Mkj][0], pTCarne[playerid][Mkj][1], pTCarne[playerid][Mkj][2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está longe do local de entregas."); 
        pTCarne[playerid][Jkas] = CreateDynamic3DTextLabel("Aperte 'H' para pegar uma caixa", -1, 0.0000, -4.0999, -0.9000, 10.0, INVALID_PLAYER_ID, pTCarne[playerid][CarneVID], 0, 0, 0, playerid, 11.0, -1);
        SetPVarInt(playerid, "dasdasdas", 1);
    }

    if(oldstate == PLAYER_STATE_ONFOOT)
    {
        if(GetPVarInt(playerid, "dasdasdas") == 0) return 1;
        SetPVarInt(playerid, "dasdasdas", 0); 
        DestroyDynamic3DTextLabelEx(pTCarne[playerid][Jkas]);
    }
    return 1;
}

CMD:acougue(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Transportador de Carne")) return 0;
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
    if(GetPlayerVehicleID(playerid) != pTCarne[playerid][CarneVID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em seu veículo alugado");
    MarcarPosicao(playerid, 1218.4352,186.1265,20.3521);
    SendClientMessage(playerid, 0xFFFF00FF, "| INFO | Foi marcado em seu mapa o local para pegar as caixas");
    return 1;
}