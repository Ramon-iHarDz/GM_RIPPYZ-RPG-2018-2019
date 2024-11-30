#include <YSI_Coding\y_hooks>

enum SomCarro
{
    bool:SomAtivo,
    UrlSom[90],

    vDonoID,
    vSomID,
    vSomVW,
    vSomIT
};

enum JogadorSom
{
    bool:EscutandoSom,
    EscutandoID,
    bool:DonoMusica,
    MusicaID,

    bool:SomCheckDesabilitar,
    TempoCheckSom
};

new vSom[MAX_SOM][SomCarro];
new pSom[MAX_PLAYERS][JogadorSom];

hook OnPlayerSpawn(playerid)
{
    if(pSom[playerid][SomCheckDesabilitar] == false){
        pSom[playerid][TempoCheckSom] = SetTimerEx("CheckSom", 2000, true, "d", playerid);
        pSom[playerid][SomCheckDesabilitar] = true;   
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(pSom[playerid][SomCheckDesabilitar] == true) KillTimer(pSom[playerid][TempoCheckSom]);
    if(pSom[playerid][DonoMusica] == true){
        new i = pSom[playerid][MusicaID];
        vSom[i][SomAtivo] = false;
    }
    pSom[playerid][DonoMusica] = false;
    new aksdsa[JogadorSom];
    pSom[playerid] = aksdsa;
    return 1;
}

hook OnVehicleDeath(vehicleid, killerid)
{ 
    for(new i=0; i < MAX_SOM; i++){
        if(vSom[i][SomAtivo] == false) continue;
        if(vSom[i][vSomID] != vehicleid) continue;
        vSom[i][SomAtivo] = false;
        break;
    }
    return 1;
}

stock VersSom(playerid)
{
    if(pSom[playerid][DonoMusica] == true)
    {
        for(new i=0; i < MAX_SOM; i++)
        {
            if(vSom[i][SomAtivo] == false) continue;
            if(vSom[i][vDonoID] != playerid) continue;  
            vSom[i][SomAtivo] = false;
            break;
        }
    }
    return 1;
}

function CheckSom(playerid)
{
    if(pSom[playerid][EscutandoSom] == false)
    {
        if(GetPVarInt(playerid, "SomRadioBlock") == 1) return 1;
        new Float:Lkas[3];
        for(new i=0; i < MAX_SOM; i++)
        {
            if(vSom[i][SomAtivo] == false) continue;
            GetVehiclePos(vSom[i][vSomID], Lkas[0], Lkas[1], Lkas[2]);
            if(!IsPlayerInRangeOfPoint(playerid, 40.0, Lkas[0], Lkas[1], Lkas[2])) continue;  
            if(GetPlayerInterior(playerid) != vSom[i][vSomIT] || GetPlayerVirtualWorld(playerid) != vSom[i][vSomVW]) continue;
            pSom[playerid][EscutandoSom] = true;
            pSom[playerid][EscutandoID] = i;
            PlayAudioStreamForPlayer(playerid, vSom[i][UrlSom]);
            break;
        }
        return 1;
    }

    new i = pSom[playerid][EscutandoID],
        Float:Lkas[3];
    GetVehiclePos(vSom[i][vSomID], Lkas[0], Lkas[1], Lkas[2]);
    if(!IsPlayerInRangeOfPoint(playerid, 40.0, Lkas[0], Lkas[1], Lkas[2]) || 
    GetPlayerInterior(playerid) != vSom[i][vSomIT] || 
    GetPlayerVirtualWorld(playerid) != vSom[i][vSomVW] || 
    vSom[i][SomAtivo] == false || 
    GetPVarInt(playerid, "SomRadioBlock") == 1) 
    {
        if(vSom[i][vDonoID] == playerid){
            vSom[i][SomAtivo] = false;
            pSom[playerid][DonoMusica] = false;
        }
        StopAudioStreamForPlayer(playerid);
        pSom[playerid][EscutandoSom] = false;
    }
    return 1;
}

Dialog:SomLigarVeiculo(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new RadioCapturada[90];
    switch(listitem)
    {
        case 0: format(RadioCapturada, 90, "http://192.99.34.83:8070/stream");
        case 1: format(RadioCapturada, 90, "http://51.161.13.49:9060/stream");
        case 2: format(RadioCapturada, 90, "http://216.235.89.134/1power");
        case 3: format(RadioCapturada, 90, "http://192.111.151.2:9986/stream");
        case 4: format(RadioCapturada, 90, "http://62.141.38.36:8880/joyhits.mp3");
    }

    for(new i=0; i < MAX_SOM; i++)
    {
        if(vSom[i][SomAtivo] == true) continue;
        format(vSom[i][UrlSom], 90, RadioCapturada);
        vSom[i][vDonoID] = playerid;

        vSom[i][vSomIT] = GetPlayerInterior(playerid);
        vSom[i][vSomVW] = GetPlayerVirtualWorld(playerid);
        
        pSom[playerid][DonoMusica] = true;
        pSom[playerid][MusicaID] = i;

        vSom[i][vSomID] = GetPVarInt(playerid, "DASJDKSAasdas");
        vSom[i][SomAtivo] = true;
        break;
    }
    return 0;
}

CMD:som(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está dirigindo");
    if(!IsApenasCarro(GetPlayerVehicleID(playerid))) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Esse veículo não suporta som");

    if(pSom[playerid][DonoMusica] == true)
    {
        for(new i=0; i < MAX_SOM; i++)
        {
            if(vSom[i][SomAtivo] == false) continue;
            if(vSom[i][vDonoID] != playerid) continue;  
            vSom[i][SomAtivo] = false;
            break;
        }
        return 1;
    }
    

    new bool:SeuVeiculo = false;
    for(new i=0; i < MAX_SLOT_VEH; i++)
    {
        if(pVeiculo[playerid][i][VehConectado] == false) continue;
        if(pVeiculo[playerid][i][MeuVeiculoID] != GetPlayerVehicleID(playerid)) continue;
        if(pVeiculo[playerid][i][TemSom] == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Seu veículo não possui som");
        SeuVeiculo = true;
    }
    if(SeuVeiculo == false) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está em seu veículo");
    SetPVarInt(playerid, "DASJDKSAasdas", GetPlayerVehicleID(playerid));

    new Dialog[350];
    strcat(Dialog, "Rádios\n");
    strcat(Dialog, "Rádio Brega Funk\n");
    strcat(Dialog, "Rádio Funk da Quebrada\n");
    strcat(Dialog, "Rádio Hitz\n");
    strcat(Dialog, "Rádio Trance\n");
    strcat(Dialog, "Rádio Pop");
    Dialog_Show(playerid, SomLigarVeiculo, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Lista", Dialog, "Selecionar", "Cancelar");
    return 1;
}