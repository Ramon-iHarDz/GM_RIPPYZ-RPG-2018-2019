#include <YSI_Coding\y_hooks>
#define     MAX_QUARTOS     (8)

enum QuartoInfo
{
    Float:QuartoX,
    Float:QuartoY,
    Float:QuartoZ,
    bool:QuartoUsado
};

new QuartoPos[][QuartoInfo] =
{
    {2271.2656,1662.5176,1084.2344},
    {2271.2378,1652.6279,1084.2344},
    {2271.2327,1642.1438,1084.2344},
    {2271.2964,1633.5337,1084.2344},
    {2266.1611,1633.4568,1084.2344},
    {2266.1323,1642.1792,1084.2344},
    {2266.1355,1652.5919,1084.2344},
    {2266.0999,1662.5931,1084.2344}
};

new Text3D:HotelText[MAX_EMPRESAS][8];
new PickHotel[MAX_EMPRESAS][8];


stock CarregarHotel(id, vwid)
{
    new Aloasd[95];
    for(new i=0; i < MAX_QUARTOS; i++)
    {
        format(Aloasd, sizeof(Aloasd), "{FFA500}Quarto (ID: %d) - Disponível\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar", i+1);
        HotelText[id][i] = CreateDynamic3DTextLabel(Aloasd, -1, QuartoPos[i][QuartoX], QuartoPos[i][QuartoY], QuartoPos[i][QuartoZ], 13.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, vwid, 1, -1, 14.0, -1);
        PickHotel[id][i] = CreateDynamicPickup(1239, 1, QuartoPos[i][QuartoX], QuartoPos[i][QuartoY], QuartoPos[i][QuartoZ], vwid, 1, -1, 90.0, -1);
    }
    return 1;
}

stock RemoverHotelQuarto(id)
{
    for(new i=0; i < MAX_QUARTOS; i++){
        DestroyDynamic3DTextLabelEx(HotelText[id][i]);
    }
    for(new i=0; i < MAX_QUARTOS; i++){
        DestroyDynamicPickupEx(PickHotel[id][i]);
    }
    return 1;
}

stock VoltarQuartoNormal(id, i)
{
    QuartoPos[i][QuartoUsado] = false;
    new Aloasd[95];
    format(Aloasd, sizeof(Aloasd), "{FFA500}Quarto (ID: %d) - Disponível\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar", i+1);
    UpdateDynamic3DTextLabelText(HotelText[id][i], -1, Aloasd);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "QuartoDormindo") == 0) return 1;
    new id = GetPVarInt(playerid, "QuartoID");
    VoltarQuartoNormal(GetPVarInt(playerid, "InteriorPersonalizadoID"), id);
    return 1;
}

hook OnPlayerAcordou(playerid)
{
    if(GetPVarInt(playerid, "QuartoDormindo") == 0) return 1;
    SetPVarInt(playerid, "QuartoDormindo", 0);
    new id = GetPVarInt(playerid, "QuartoID");
    SetPlayerInterior(playerid, 1);
    SetPlayerPos(playerid, GetPVarFloat(playerid, "QuartoForaX"), GetPVarFloat(playerid, "QuartoForaY"), GetPVarFloat(playerid, "QuartoForaZ"));
    VoltarQuartoNormal(GetPVarInt(playerid, "InteriorPersonalizadoID"), id);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys != KEY_YES) return 1;
    for(new i=0; i < MAX_QUARTOS; i++)
    {
        if(!IsPlayerInRangeOfPoint(playerid, 2.0, QuartoPos[i][QuartoX], QuartoPos[i][QuartoY], QuartoPos[i][QuartoZ])) continue;
        new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
        if(GetPlayerVirtualWorld(playerid) != PegarEmpresaVw(id) || GetPlayerInterior(playerid) != 1) return 1;
        if(Jogador[playerid][uInteriorEx] != 2) return 1;
        if(QuartoPos[i][QuartoUsado] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse quarto já está sendo usado");
        if(Jogador[playerid][Dinheiro] < 1500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem $1.500 para alugar um quarto");
        if(Jogador[playerid][Sono] > 30) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não está com sono");
        Jogador[playerid][Dinheiro] -= 1500;
        EnviarDinheiroEmpresa(id, 1500);

        new Aloasd[90];
        format(Aloasd, sizeof(Aloasd), "Quarto (ID: %d)\n{FFA500}%s[%d]", i+1, PegarNick(playerid), playerid);
        UpdateDynamic3DTextLabelText(HotelText[id][i], -1, Aloasd);

        new Float:Laos[3];
        GetPlayerPos(playerid, Laos[0], Laos[1], Laos[2]);
        SetPVarFloat(playerid, "QuartoForaX", Laos[0]);
        SetPVarFloat(playerid, "QuartoForaY", Laos[1]);
        SetPVarFloat(playerid, "QuartoForaZ", Laos[2]);
        SetPVarInt(playerid, "QuartoDormindo", 1);
        SetPVarInt(playerid, "QuartoID", i);

        SetPlayerInterior(playerid, 1);
        SetPlayerPos(playerid, 2218.2725,-1076.2798,1050.4844);
        break;
    }
    return 1;
}

CMD:dormir(playerid)
{
    if(GetPVarInt(playerid, "QuartoDormindo") != 1 && Jogador[playerid][uInteriorEx] != 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está em um hotel ou na sua casa.");
    if(Jogador[playerid][Sono] > 30) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda não está com sono");

    if(Jogador[playerid][uInteriorEx] == 1){
        new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
        if(!VerificarMorador(PegarNick(playerid), id) && strcmp(pCasa[id][cDono], PegarNick(playerid))) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não mora nessa casa");
    }
    else
    {
        if(!IsPlayerInRangeOfPoint(playerid, 8.0, 2208.1543,-1071.9855,1050.4766)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está perto da cama");
    }
    EnviarSono(playerid);
    return 1;
}