#include <YSI_Coding\y_hooks>

new TransporteMensagem;

hook OnGameModeInit()
{
    TransporteMensagem = CreateDynamicRectangle(2161, -2288.5, 2240, -2213.5, 0, 0, -1); 
    CreateDynamicPickup(1239, 1, 2208.8042,-2278.7266,13.5547, 0, 0, -1, 90.0);    
    CreateDynamic3DTextLabel("{00BFFF}Transportador\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para alugar/devolver", -1, 2208.8042,-2278.7266,13.5547, 40.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid == TransporteMensagem) MostrarMensagemBaixo(playerid, ConverterTexto("Área de ~g~Transportes~w~, cuidado."));
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{   
    if(areaid == TransporteMensagem) OcultarMensagemBaixo(playerid);
    return 1;
}