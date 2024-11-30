#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamicPickup(1010, 1, -2055.3425,455.6263,35.1719, 0, 0, -1, 120.0, -1, 0);
    // CreateDynamic3DTextLabel("{00BFFF}CarMax\n{FFFFFF}Venda já seu veículo conosco", -1, -2055.3425,455.6263,35.1719, 60.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 60.0, -1, 0);
    CreateDynamicMapIcon(-2055.3425,455.6263,35.1719, 55, -1, 0, 0, -1, 120.0, MAPICON_LOCAL, -1, 0);
    return 1;
}

