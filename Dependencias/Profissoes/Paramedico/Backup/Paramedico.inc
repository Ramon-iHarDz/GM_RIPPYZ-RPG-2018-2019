#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{00BFFF}Paramédico\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, -2558.0691,662.5930,14.4531, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 30.0, -1);
    CreateDynamicPickup(1239, 1, -2558.0691,662.5930,14.4531, 0, 0, -1, 120.0, -1, 0);

    CreateDynamic3DTextLabel("{00BFFF}Paramédico\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para se equipar ou devolver", -1, 1041.8142,50.4494,1000.4590, 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1299, 3, -1, 20.0, -1);
    CreateDynamicPickup(11736, 1, 1041.8142,50.4494,1000.4590, 1299, 3, -1, 120.0, -1, 0);
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(pMorreu[playerid][EstaCaido] == true) return 1;
    GetPlayerPos(playerid, pMorreu[playerid][MoPosX], pMorreu[playerid][MoPosY], pMorreu[playerid][MoPosZ]);
    GetPlayerFacingAngle(playerid, pMorreu[playerid][MoPosA]);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "SendoCurativado") == 0) return 1;
    new id = GetPVarInt(playerid, "IdPara");
    SetPVarInt(id, "CurandoAA", 0);
    PararProgresso(id);
    TogglePlayerControllable(id, 1);
    ClearAnimations(id);
    return 1;
}


hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
        if(pParamedico[playerid][PegouParaFarda] == false) return 1;
        if(pParamedico[playerid][PegouAmbu] == false) return 1;
        if(GetPlayerVehicleID(playerid) != pParamedico[playerid][AmbuID]) return 1;

        if(pParamedico[playerid][AmbuComTexto] == true)
        {
            DestroyDynamic3DTextLabelEx(pParamedico[playerid][AmbuTexto]);
            pParamedico[playerid][AmbuComTexto] = false;
        } 
        if(pParamedico[playerid][KitNaMao] == true)
        {
            RemovePlayerAttachedObject(playerid, 9);
            pParamedico[playerid][KitNaMao] = false;
        }

    }

    else if(oldstate == PLAYER_STATE_DRIVER)
    {
        if(pParamedico[playerid][PegouParaFarda] == false) return 1;
        if(pParamedico[playerid][PegouAmbu] == false) return 1;
        if(Jogador[playerid][uVeiculo] != pParamedico[playerid][AmbuID]) return 1;

        pParamedico[playerid][AmbuComTexto] = true;
        pParamedico[playerid][AmbuTexto] = CreateDynamic3DTextLabel("{CCCCCC}Ambulância\n{FFFFFF}Aperte {CCCCCC}'H'{FFFFFF} para pegar/devolver a maleta", -1, 0.0000, -4.0999, -0.9000, 20.0, INVALID_PLAYER_ID, pParamedico[playerid][AmbuID], 0, 0, 0, playerid, 20.0, -1);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == KEY_CTRL_BACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(pParamedico[playerid][PegouParaFarda] == false) return 1;
        if(pParamedico[playerid][PegouAmbu] == false) return 1;
        if(pParamedico[playerid][AmbuComTexto] == false) return 1;
        new Float:cMotoH[3],
            Float:X, Float:Y;
        GetVehiclePos(pParamedico[playerid][AmbuID], cMotoH[0], cMotoH[1], cMotoH[2]);
        GetXYBehindOfVehicle(pParamedico[playerid][AmbuID], X, Y, 4.0);
        if(IsPlayerInRangeOfPoint(playerid, 2.0, X, Y, cMotoH[2]))
        {
            if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0) return 1;
            if(GetPVarInt(playerid, "asdasda") > gettime()) return  SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde um pouco.");
            SetPVarInt(playerid, "asdasda", gettime()+10);
            if(pParamedico[playerid][KitNaMao] == false)
            {
                if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
                SetPlayerAttachedObject(playerid, 9, 11738, 5, 0.2869, 0.0000, 0.0110, 0.0000, -97.6000, 0.0000, 1.0590, 1.0000, 1.0760, 0xFFFFFFFF, 0xFFFFFFFF); 
                pParamedico[playerid][KitNaMao] = true;
                SendClientMessage(playerid, 0xFFFF00FF, "| PARAMÉDICO | Você pegou sua maleta de primeiros socorros");
                return 1;
            }   
            RemovePlayerAttachedObject(playerid, 9);
            pParamedico[playerid][KitNaMao] = false;
            SendClientMessage(playerid, 0xFFFF00FF, "| PARAMÉDICO | Você devolveu sua maleta de primeiros socorros");
        }
    }
    return 1;
}

Dialog:ReviverMorte(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    if(pMorreu[playerid][EstaCaido] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está caido(a)");
    if(pMorreu[playerid][MorteStatus] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde o(a) paramédico(a) reviver você");
    RespawnarMorto(playerid, true);
    return 1;
}

stock VerificarParamedico()
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Paramédico")) continue;
        if(pParamedico[i][PegouParaFarda] == false) continue;
        if(pParamedico[i][PegouAmbu] == false) continue;
        return true;
    }
    return false;
}

stock VerificarMortes(playerid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(pMorreu[i][EstaCaido] == false) continue;
        pMedico[playerid][i][SendoUsado] = true;
        pMedico[playerid][i][IconeMorte] = CreateDynamicMapIcon(pMorreu[i][MoPosX], pMorreu[i][MoPosY], pMorreu[i][MoPosZ], 21, -1, 0, 0, playerid, 999999.9, MAPICON_GLOBAL, -1);   
    }
    return 1;
}

stock EnviarMorte(playerid)
{
    new Mensagem[128];
    format(Mensagem, sizeof(Mensagem), "| AVISO | O(A) %s[%d] se feriu ( Localização: %s )", PegarNick(playerid), playerid, AreaNome(pMorreu[playerid][MoPosX], pMorreu[playerid][MoPosY], pMorreu[playerid][MoPosZ]));
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Paramédico")) continue;
        if(pParamedico[i][PegouParaFarda] == false) continue;
        if(pParamedico[i][PegouAmbu] == false) continue;
        pMedico[i][playerid][SendoUsado] = true;
        pMedico[i][playerid][IconeMorte] = CreateDynamicMapIcon(pMorreu[playerid][MoPosX], pMorreu[playerid][MoPosY], pMorreu[playerid][MoPosZ], 21, -1, 0, 0, i, 999999.9, MAPICON_GLOBAL, -1);   
        SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    }
    pMorreu[playerid][EstaCaido] = true;
    pMorreu[playerid][MorteStatus] = 0;
    SendClientMessage(playerid, 0xDAA520FF, "| MORTE | Você se machucou, aguarde um(a) paramédico(a) ou reviva ( /Viver )");
    return 1;
}

stock VerificarMortesRemover(playerid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(pMedico[playerid][i][SendoUsado] == false) continue;
        pMedico[playerid][i][SendoUsado] = false;
        DestroyDynamicMapIconEx(pMedico[playerid][i][IconeMorte]);
    }
    return 1;
}

stock VerificarMortesRemoverEx(playerid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(pMedico[i][playerid][SendoUsado] == false) continue;
        pMedico[i][playerid][SendoUsado] = false;
        DestroyDynamicMapIconEx(pMedico[i][playerid][IconeMorte]);
    }
    return 1;
}

stock RespawnarMorto(playerid, bool:Cobrar = false)
{
    pMorreu[playerid][EstaCaido] = false;
    pMorreu[playerid][MorteStatus] = 0;
    KillTimer(pMorreu[playerid][TimerMorte]);
    OcultarMorte(playerid);

    TogglePlayerControllable(playerid, 1);
    ClearAnimations(playerid);

    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(pMedico[i][playerid][SendoUsado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Paramédico")) continue;
        if(pParamedico[i][PegouParaFarda] == false) continue;
        if(pParamedico[i][PegouAmbu] == false) continue;
        pMedico[i][playerid][SendoUsado] = false;
        DestroyDynamicMapIconEx(pMedico[i][playerid][IconeMorte]);
    }

    if(Cobrar == true)
    {
        Hospital(2, playerid);
        if(Jogador[playerid][PlanoDeSaude] > gettime())
        {
            SendClientMessage(playerid, 0x40E0D0FF, "| HOSPITAL | Seu plano de saúde hospitalar cobriu metade dos custos ( {32CD32}$3.500{40E0D0} )");
            Jogador[playerid][DinheiroBanco] -= 3500;
        }
        else
        {
            SendClientMessage(playerid, 0x40E0D0FF, "| HOSPITAL | Você não tem plano de saúde e teve que pagar {32CD32}$5.000{40E0D0} ao hospital");
            Jogador[playerid][DinheiroBanco] -= 5000;
        }
    }
    return 1;
}

function TempoVida(playerid)
{
    SetPlayerHealth(playerid, 100);
    if(pMorreu[playerid][MorteStatus] == 1) return 1;
    if(pMorreu[playerid][TempoMorte] < 0) return RespawnarMorto(playerid, false);
    
    pMorreu[playerid][TempoMorte]--;
    new Horinha[70];
    format(Horinha, sizeof(Horinha), "Tempo:_~r~%s", SegundosParaMinutosEx(pMorreu[playerid][TempoMorte]));
    PlayerTextDrawSetString(playerid, MorteAviso[playerid][1], Horinha);
    return 1;
}

function RevivendoJogador(playerid, id)
{
    new Mensagem[128],
        DinDin = random(2500-1000)+1000;

    Jogador[playerid][Dinheiro] += DinDin;
    format(Mensagem, sizeof(Mensagem), "| PARAMÉDICO | O(A) Paramédico(a) {00BFFF}%s[%d]{FFFFFF} reviveu você", PegarNick(playerid), playerid);
    SendClientMessage(id, -1, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| PARAMÉDICO | Você reviveu o(a) jogador(a) {00BFFF}%s[%d]{FFFFFF} e ganhou {32CD32}$%s", PegarNick(id), id, DinheiroSeparar(DinDin));
    SendClientMessage(playerid, -1, Mensagem);

    pParamedico[playerid][Revivendo] = false;

    ClearAnimations(playerid);
    RespawnarMorto(id, false);
    return 1;
}

CMD:reviver(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Paramédico") && Jogador[playerid][Admin] < 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão!");

    if(Jogador[playerid][Admin] < 2)
    {
        if(pParamedico[playerid][PegouParaFarda] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está fardado(a)");
        if(pParamedico[playerid][PegouAmbu] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem uma ambulância");
        if(Jogador[playerid][uVeiculo] != pParamedico[playerid][AmbuID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é a ambulância!");
        if(pParamedico[playerid][Revivendo] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está revivendo um(a) ferido(a), aguarde!");
        if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    }

    new bool:PertoH = false;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(pMorreu[i][EstaCaido] == false) continue;
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, pMorreu[i][MoPosX], pMorreu[i][MoPosY], pMorreu[i][MoPosZ])) continue;
        if(pParamedico[playerid][KitNaMao] == false && Jogador[playerid][Admin] < 2) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Pegue o kit de primeiros socorros atrás da ambulância");
        if(pMorreu[i][MorteStatus] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse(a) jogador(a) já está sendo curado(a)");

        new Mensagem[128];
        
        pMorreu[i][MorteStatus] = 1;
        pMorreu[i][ParamedicoID] = playerid;

        pParamedico[playerid][Revivendo] = true;
        pParamedico[playerid][RevivendoID] = i;
        pParamedico[playerid][TempoRevivendo] = SetTimerEx("RevivendoJogador", 20000, false, "dd", playerid, i);

        ClearAnimations(playerid);
        ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);

        format(Mensagem, sizeof(Mensagem), "| PARAMÉDICO | O(A) Paramédico(a) {00BFFF}%s[%d]{FFFFFF} está revivendo você", PegarNick(playerid), playerid);
        SendClientMessage(i, -1, Mensagem);

        format(Mensagem, sizeof(Mensagem), "| PARAMÉDICO | Você está revivendo o(a) jogador(a) {00BFFF}%s[%d]", PegarNick(i), i);
        SendClientMessage(playerid, -1, Mensagem);
        PertoH = true;
        break;
    }
    if(PertoH == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto(a) de um(a) ferido(a)");
    return 1;
}

CMD:viver(playerid)
{
    if(pMorreu[playerid][EstaCaido] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está caido(a)");
    if(pMorreu[playerid][MorteStatus] == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Aguarde o(a) paramédico(a) reviver você");
    Dialog_Show(playerid, ReviverMorte, DIALOG_STYLE_MSGBOX, "{FF0000}Confirmação", "Você realmente deseja reviver e pagar os custos do hospital?", "Sim", "Não");
    return 1; 
}

CMD:paramedicos(playerid) 
{
    new Paramds = 0,
        Dialog[1000];
    
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(strcmp(Jogador[i][Profissao], "Paramédico")) continue;
        if(pParamedico[i][PegouParaFarda] == false) continue;
        if(pParamedico[i][PegouAmbu] == false) continue; 
        strcatEx(Dialog, "{FFFFFF}%s [ {FFFF00}ID: %d{FFFFFF} ]\n", PegarNick(i), i);
        Paramds++;   
    }

    if(Paramds == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há paramédicos trabalhando no momento");
    Dialog_Show(playerid, ParamedicosOnline, DIALOG_STYLE_MSGBOX, "{FF0000}Paramédicos", Dialog, "Fechar", "");
    return 1;
}

CMD:feridos(playerid, params[])
{
    if(strcmp(Jogador[playerid][Profissao], "Paramédico")) return 0;

    new Dialog[1000],
        Float:Fasld;

    strcat(Dialog, "ID\tJogador\tVida\n");
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(Jogador[i][Admin] > 0) continue;
        GetPlayerHealth(i, Fasld);
        if(Fasld > 50.0) continue;
        strcatEx(Dialog, "{CCCCCC}%d\t{DAA520}%s[%d]\t{00BFFF}%0.2f\n", i+1, PegarNick(i), i, Fasld);
    }
    Dialog_Show(playerid, Semfunfc, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Precisando de Curativos", Dialog, "Fechar", "");
    return 1;
}

function CurativosFinalizado(playerid)
{
    new id = GetPVarInt(playerid, "IdPara"),
        Mensagem[128]; 
    SetPlayerHealth(id, 100.0);
    Jogador[id][Dinheiro] -= GetPVarInt(id, "VlrCurativo");
    Jogador[playerid][Dinheiro] += GetPVarInt(id, "VlrCurativo");

    TogglePlayerControllable(playerid, 1);
    TogglePlayerControllable(id, 1);

    ClearAnimations(playerid);
    ClearAnimations(id);

    SetPVarInt(id, "SendoCurativado", 0);
    SetPVarInt(playerid, "CurandoAA", 0);

    format(Mensagem, sizeof(Mensagem), "| PARAMÉDICO | Você recebeu {32CD32}$%s{FFFFFF} pelos curativos em {00BFFF}%s[%d]", DinheiroSeparar(GetPVarInt(id, "VlrCurativo")), PegarNick(id), id);
    SendClientMessage(playerid, -1, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| CURATIVOS | Você pagou {32CD32}$%s{FFFFFF} pelos curativos feito por {00BFFF}%s[%d]", DinheiroSeparar(GetPVarInt(id, "VlrCurativo")), PegarNick(id), id);
    SendClientMessage(id, -1, Mensagem);
    return 1;
}

CMD:aceitarcurativos(playerid)
{
    if(GetPVarInt(playerid, "RecebeuProp") < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não recebeu nenhuma proposta de curativos"); 
    new id = GetPVarInt(playerid, "IdPara");
    if(GetPVarInt(playerid, "AceitouCuraX") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já aceitou a proposta, aguarde o paramédico"); 

    new Mensagem[138];
    format(Mensagem, sizeof(Mensagem), "| PARAMÉDICO | O(A) Jogador(a) {00BFFF}%s[%d]{FFFFFF} aceitou os curativos, faça os curativos nele(a) ( /FazerCurativos )", PegarNick(playerid), playerid);
    SendClientMessage(id, -1, Mensagem);
    SendClientMessage(playerid, 0x32CD32FF, "| CURATIVOS | Você aceitou os curativos, aguarde pelo(a) paramédico(a)");
    SetPVarInt(playerid, "AceitouCuraX", gettime()+120);
    return 1;
}

CMD:fazercurativos(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Paramédico")) return 0;
    if(GetPVarInt(playerid, "RecebeuPropAA") < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não enviou nenhuma proposta de curativos");
    new id = GetPVarInt(playerid, "IdPara");
    if(GetPVarInt(id, "AceitouCuraX") < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Ainda não aceitou os curativos");
    if(pParamedico[playerid][KitNaMao] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Pegue a maleta de primeiros socorros atrás da ambulância");

    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa está a pé");
    if(GetPlayerState(id) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) precisa está a pé");

    SetPVarInt(playerid, "RecebeuPropAA", 0);
    SetPVarInt(id, "RecebeuProp", 0);
    SetPVarInt(id, "AceitouCuraX", 0);

    SetPVarInt(id, "SendoCurativado", 1);
    SetPVarInt(playerid, "CurandoAA", 1);

    ClearAnimations(playerid);
    ClearAnimations(id);

    TogglePlayerControllable(playerid, 0);
    TogglePlayerControllable(id, 0);

    ApplyAnimation(id, "PED", "KO_skid_front", 4.1, 0, 1, 1, 1, 0);
    ApplyAnimation(playerid, "BOMBER", "BOM_Plant_Loop", 4.0, 1, 0, 0, 1, 0);

    CriarProgresso(playerid, "Fazendo Curativos, aguarde.", "CurativosFinalizado", 400);
    return 1;
}

CMD:curativo(playerid, params[])
{
    if(strcmp(Jogador[playerid][Profissao], "Paramédico")) return 0;
    if(GetPVarInt(playerid, "CurandoAA") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está curando um paciente, aguarde.");
    if(GetPVarInt(playerid, "RecebeuPropAA") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já enviou uma proposta, aguarde.");

    new id, valr;
    if(sscanf(params, "dd", id, valr)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Use: /Curativo [ID] [Valor]");
    if(pParamedico[playerid][PegouParaFarda] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    if(pParamedico[playerid][PegouAmbu] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem uma ambulância");
    if(valr > 1500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Valor máximo R$1.500");
    if(valr < 500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Valor mínimo R$500");

    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não logado(a)");
    
    new Distancia = GetDistanceBetweenPlayers(playerid, id);
    if(Distancia > 4) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está muito longe desse(a) jogador(a)");
    if(GetPlayerVirtualWorld(id) != GetPlayerVirtualWorld(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está na mesma cidade que você");

    new Float:Lasd;
    GetPlayerHealth(id, Lasd);
    if(Lasd > 50.0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não precisa de curativos");
    if(Jogador[id][Dinheiro] < valr) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não tem dinheiro sucifiente");

    new Float:Biua[3];
    GetPlayerPos(id, Biua[0], Biua[1], Biua[2]);
    if(!IsVehicleInRangeOfPoint(pParamedico[playerid][AmbuID], 60.0, Biua[0], Biua[1], Biua[2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua ambulância não está perto");

    if(GetPVarInt(id, "SendoCurativado") == 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Já está recebendo curativos");
    if(GetPVarInt(id, "RecebeuProp") > gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Já recebeu uma proposta, aguarde.");
    SetPVarInt(id, "RecebeuProp", gettime()+60);
    SetPVarInt(playerid, "RecebeuPropAA", gettime()+60);

    SetPVarInt(playerid, "IdPara", id);
    SetPVarInt(id, "IdPara", playerid);
    SetPVarInt(id, "VlrCurativo", valr);

    new Mensagem[168];
    format(Mensagem, sizeof(Mensagem), "| PARAMÉDICO | O(A) Paramédico(a) {00BFFF}%s[%d]{FFFFFF} está lhe oferecendo curativos por {FFA500}$%s{FFFFFF} ( /AceitarCurativos )", PegarNick(playerid), playerid, DinheiroSeparar(valr));
    SendClientMessage(id, -1, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| PARAMÉDICO | Você ofereceu curativos para {00BFFF}%s[%d]{FFFFFF} por {FFA500}$%s", PegarNick(id), id, DinheiroSeparar(valr));
    SendClientMessage(playerid, -1, Mensagem);
    return 1;
}