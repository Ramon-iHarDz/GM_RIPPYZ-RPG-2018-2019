#include <YSI_Coding\y_hooks>

#define MAX_AIRDROP 100

enum AirdropInfo
{
    // Informações de Jogada
    bool:AirDropLancado,
    bool:AirDropLiberado,
    bool:AirDropPegou,

    // Ganhador e Item 
    AirDropGanhador,
    AirDropItem,

    // Informações e Ids
    AirDropCaixa,
    AirDropIcone,
    Text3D:AirDropTexto,

    // Posição
    Float:aPosX,
    Float:aPosY,
    Float:aPosZ
};

enum CaixaPresenteid
{
    CaixaIDO
};

new CaixasAir[][CaixaPresenteid] =
{
    19055,
    19056,
    19058,
    19054,
    19057
};
new AirDrop[MAX_AIRDROP][AirdropInfo];
new AirdropsJg;

hook OnDynObjectMoved(objectid)
{
    if(AirdropsJg < 1) return 1;
    for(new i=0; i < MAX_AIRDROP; i++)
    {
        if(AirDrop[i][AirDropLancado] == false) continue;
        if(AirDrop[i][AirDropLiberado] == true) continue;
        if(AirDrop[i][AirDropCaixa] != objectid) continue;

        new Temppp = random(9-6)+6;
	    new Temc = (Temppp*1000);

        DestroyDynamicObjectEx(AirDrop[i][AirDropCaixa]);
        AirDrop[i][AirDropCaixa] = CreateDynamicObject(CaixasAir[random(sizeof(CaixasAir))][CaixaIDO], AirDrop[i][aPosX], AirDrop[i][aPosY], AirDrop[i][aPosZ]-0.4, 0.0, 0.0, 0.0, 0, 0, -1, 190.0, 190.0, -1, 0);
        
        for(new d=0; d < MAX_PLAYERS; d++){
            if(!IsPlayerConnected(d)) continue;
            if(Jogador[d][Logado] == false) continue;
            if(!IsPlayerInRangeOfPoint(d, 30.0, AirDrop[i][aPosX], AirDrop[i][aPosY], AirDrop[i][aPosZ])) continue;
            if(GetPlayerInterior(d) != 0 || GetPlayerVirtualWorld(d) != 0) continue;
            PlayerPlaySound(d, 1039, AirDrop[i][aPosX], AirDrop[i][aPosY], AirDrop[i][aPosZ]);
        }

        SetTimerEx("LiberarAirDrop", Temc, false, "d", i);
        break;
    }
    return 1;
}

function LiberarAirDrop(id)
{
    AirDrop[id][AirDropLiberado] = true;
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPlayerVirtualWorld(i) != 0 || GetPlayerInterior(i) != 0) continue;
        if(!IsPlayerInRangeOfPoint(i, 30.0, AirDrop[i][aPosX], AirDrop[i][aPosY], AirDrop[i][aPosZ])) continue;
        SendClientMessage(i, 0xFFA500FF, "| AIRDROP | Você já pode abrir esse airdrop.");
    }
    return 1;
}

function ApagarAirDrop(id)
{
    DestroyDynamicMapIconEx(AirDrop[id][AirDropIcone]);
    DestroyDynamicObjectEx(AirDrop[id][AirDropCaixa]);
    DestroyDynamic3DTextLabelEx(AirDrop[id][AirDropTexto]);

    AirdropsJg--;

    new ResetAir[AirdropInfo];
    AirDrop[id] = ResetAir;
    return 1;
}

CMD:abrir(playerid)
{
    if(GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode abrir um airdrop");
    if(GetPlayerInterior(playerid) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode abrir um airdrop");
    new bool:PertoAir = false;
    for(new i=0; i < MAX_AIRDROP; i++)
    {
        if(AirDrop[i][AirDropLancado] == false) continue;
        if(AirDrop[i][AirDropLiberado] == false) continue;   
        if(!IsPlayerInRangeOfPoint(playerid, 20.0, AirDrop[i][aPosX], AirDrop[i][aPosY], AirDrop[i][aPosZ])) continue;
        if(AirDrop[i][AirDropPegou] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse airdrop já foi aberto por outro(a) jogador(a)");
        AirDrop[i][AirDropPegou] = true;
        
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "%s[%d]{FFFFFF} foi o ganhador(a)", PegarNick(playerid), playerid);
        AirDrop[i][AirDropTexto] = CreateDynamic3DTextLabel(Mensagem, 0xFFA500FF, AirDrop[i][aPosX], AirDrop[i][aPosY], AirDrop[i][aPosZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.0, -1, 0);
        format(Mensagem, sizeof(Mensagem), "| AIRDROP | O(A) Jogador(a) {2384fa}%s[%d]{FFFFFF} abriu um airdrop e ganhou {faa023}%s", PegarNick(playerid), playerid, ItensAir[AirDrop[i][AirDropItem]][ItemNome]);
        SendClientMessageToAll(-1, Mensagem);

        DarItemAirDrop(playerid, AirDrop[i][AirDropItem]);
        SetTimerEx("ApagarAirDrop", 20000, false, "d", i);
        PertoAir = true;
        break;
    }
    if(PertoAir == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto de um airdrop");
    return 1;
}