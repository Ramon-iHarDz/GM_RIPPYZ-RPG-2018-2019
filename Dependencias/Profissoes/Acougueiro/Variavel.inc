#include <YSI_Coding\y_hooks>

new CarneProntas;
new AreaCarne;

hook OnGameModeInit()
{
    AreaCarne = CreateDynamicRectangle(1210.296875, 170.09375, 1236.296875, 191.09375, 0, 0, -1);
    CarnesRegen();
    SetTimer("CarnesRegen", 7200000, true);
    return 1;
}

function CarnesRegen()
{
    CarneProntas += 1500;
    return 1;
}

hook OnPlayerEnterDynArea(playerid, areaid)
{
    if(areaid != AreaCarne) return 1;
    new Msg[90];
    format(Msg, sizeof(Msg), "Açougue - Carnes disponíveis: ~b~%d", CarneProntas);
    MostrarMensagemBaixo(playerid, ConverterTexto(Msg));
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, areaid)
{
    if(areaid == AreaCarne) OcultarMensagemBaixo(playerid);
    return 1;
}