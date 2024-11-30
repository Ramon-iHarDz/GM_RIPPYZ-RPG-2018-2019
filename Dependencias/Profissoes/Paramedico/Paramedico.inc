#include <YSI_Coding\y_hooks>

enum AmbuInfoLocal
{
    Float:AmbuPosX,
    Float:AmbuPosY,
    Float:AmbuPosZ,
    Float:AmbuPosA
}

new AmbulanciaSpawn[][AmbuInfoLocal] =
{
    {-2571.9175,622.1801,14.6020,269.7316},
    {-2571.1162,627.5264,14.6025,270.9887},
    // {-2572.0764,632.4645,14.6083,269.5320},
    {-2546.7910,658.1085,14.6072,90.9463},
    // {-2546.2307,652.7789,14.6082,90.3552},
    {-2545.7473,647.7730,14.6085,89.9032},
    // {-2546.0801,637.6088,14.6027,90.2861},
    {-2546.0481,632.6171,14.6020,91.7141},
    // {-2546.4419,627.3430,14.6021,89.6706},
    {-2588.6909,658.1520,14.6025,270.7737},
    {-2589.4253,652.9669,14.6020,270.2754},
    {-2588.8091,632.5268,14.6020,270.4930},
    {-2589.0415,627.3152,14.6083,270.7952}
};

new Ambulac[sizeof(AmbulanciaSpawn)];

hook OnGameModeInit()
{
    for(new i=0; i < sizeof(AmbulanciaSpawn); i++){
        Ambulac[i] = CreateVehicleEx(-1, 416, AmbulanciaSpawn[i][AmbuPosX], AmbulanciaSpawn[i][AmbuPosY], AmbulanciaSpawn[i][AmbuPosZ], AmbulanciaSpawn[i][AmbuPosA], 1, 7, -1, 0);
        VeiculoServer[Ambulac[i]][AntiRadar] = true;
        format(VeiculoServer[Ambulac[i]][LocalVerificacao], 90, "AmbulanciaVeric");
    }
    return 1;
}

function AmbulanciaVeric(playerid, id)
{
    for(new i=0; i < sizeof(AmbulanciaSpawn); i++)
    {
        if(Ambulac[i] != id) continue;
        if(strcmp(Jogador[playerid][Profissao], "Paramédico")){
            SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem permissão");
            return false;
        }
        break;
    }
    return true;
}

stock UltimoAmbulancia(playerid)
{
    for(new i=0; i < sizeof(AmbulanciaSpawn); i++){
        if(Ambulac[i] == Jogador[playerid][uVeiculo]) return true;
    }
    return false;
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
    //if(pParamedico[playerid][KitNaMao] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Pegue a maleta de primeiros socorros atrás da ambulância");
    if(!UltimoAmbulancia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é uma ambulância");

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
    //if(pParamedico[playerid][PegouParaFarda] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem farda");
    //if(pParamedico[playerid][PegouAmbu] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está sem uma ambulância");
    if(!UltimoAmbulancia(playerid)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Seu último veículo não é uma ambulância");
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
    // if(!IsVehicleInRangeOfPoint(pParamedico[playerid][AmbuID], 60.0, Biua[0], Biua[1], Biua[2])) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Sua ambulância não está perto");

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