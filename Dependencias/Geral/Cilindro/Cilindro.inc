#include <YSI_Coding\y_hooks>

enum CilindroJogador
{
    bool:CilindroAtivo,
    CilindroTimer,
    Float:VidaCilindro,
    CilindroTempo
};
new pCilindro[MAX_PLAYERS][CilindroJogador];

hook OnPlayerDisconnect(playerid, reason)
{
    if(pCilindro[playerid][CilindroAtivo] == true) KillTimer(pCilindro[playerid][CilindroTimer]);
    new asjd[CilindroJogador];
    pCilindro[playerid] = asjd;
    return 1;
}

CMD:usarcilindro(playerid)
{
    if(strcmp(Jogador[playerid][Profissao], "Mergulhador")) return 0;
    if(Jogador[playerid][Cilindro] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem cilindro");
    if(Jogador[playerid][Estrelas] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está procurado(a)");
    if(pCilindro[playerid][CilindroAtivo] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já está usando um cilindro");
    if(Jogador[playerid][Trabalhando] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está na trabalhando");
    Jogador[playerid][Cilindro]--;
    
    MostrarCilindro(playerid);
    GetPlayerHealth(playerid, pCilindro[playerid][VidaCilindro]);
    pCilindro[playerid][CilindroAtivo] = true;
    pCilindro[playerid][CilindroTempo] = 240;
    pCilindro[playerid][CilindroTimer] = SetTimerEx("CilindroUpdate", 1000, true, "d", playerid);

    SetPlayerAttachedObject(playerid, 9, 2690, 1, 0.1070, -0.0739, 0.0240, 0.0000, 89.6000, -86.9000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); // CJ_FIRE_EXT attached to the Spine of Kettler
    SetPlayerAttachedObject(playerid, 8, 19472, 2, 0.0090, 0.1260, 0.0070, 10.7000, 90.6000, 85.9999, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); // gasmask01 attached to the Head of Kettler

    new Mensagem[45];
    format(Mensagem, sizeof(Mensagem), "| CILINDRO | Você usou um cilindro ( %d/3 )", Jogador[playerid][Cilindro]);
    SendClientMessage(playerid, 0x00BFFFFF, Mensagem);
    return 1;
}

function CilindroUpdate(playerid)
{
    pCilindro[playerid][CilindroTempo]--;
    if(pCilindro[playerid][CilindroTempo] < 1) return PararCilindro(playerid);
    // if(!IsPlayerInWater(playerid)) return 1;
    SetPlayerHealth(playerid, 99999.9);
    new Mensagem[10];
    format(Mensagem, sizeof(Mensagem), "%s", SegundosParaMinutos(pCilindro[playerid][CilindroTempo]));
    PlayerTextDrawSetString(playerid, CilindroTextDraw[playerid][2], ConverterTexto(Mensagem));
    return 1;
}

stock PararCilindro(playerid)
{
    KillTimer(pCilindro[playerid][CilindroTimer]);
    pCilindro[playerid][CilindroAtivo] = false;
    RemovePlayerAttachedObject(playerid, 9);
    RemovePlayerAttachedObject(playerid, 8);
    SetPlayerHealth(playerid, pCilindro[playerid][VidaCilindro]);
    OcultarCilindro(playerid);
    return 1;
}

stock IsUsandoCilindro(playerid)
{
    return pCilindro[playerid][CilindroAtivo];
}