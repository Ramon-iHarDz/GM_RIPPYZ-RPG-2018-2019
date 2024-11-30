#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicActor(124, 2442.9888,-1970.1599,13.5469,276.1729, 1, 90.0, 0, 0, -1, 30.0);
    MensagemArea = CreateDynamicRectangle(-1215.4655,-1220.2931, -1089.0220,-1151.4414, 0, 0, -1); // Plantador Mensagem
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 10; i++){
        if(Plantador[playerid][i][Plantado] == true) AcabarComPlantio(playerid, i);
    }
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid == MensagemArea) MostrarMensagemBaixo(playerid, ConverterTexto("~w~Plantação de ~r~Maconha"));
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{   
    if(areaid == MensagemArea) OcultarMensagemBaixo(playerid);
    return 1;
}