#include <YSI_Coding\y_hooks>

hook OnGameModeInit(){
    new k_MarSushiCao[13];
    k_MarSushiCao[0] = CreateObject(1364, -2017.0371, 488.2399, 34.9752, 0.0000, 0.0000, 90.0000); //CJ_BUSH_PROP
    k_MarSushiCao[1] = CreateObject(1364, -2017.0374, 479.4602, 34.9752, 0.0000, 0.0000, 90.0000); //CJ_BUSH_PROP
    k_MarSushiCao[2] = CreateObject(1364, -2022.8631, 493.7901, 34.9752, 0.0000, 0.0000, 180.0000); //CJ_BUSH_PROP
    k_MarSushiCao[3] = CreateObject(1364, -2032.5566, 493.7999, 34.9752, 0.0000, 0.0000, 180.0000); //CJ_BUSH_PROP
    k_MarSushiCao[4] = CreateObject(1341, -2017.1265, 484.3081, 35.1487, 0.0000, 0.0000, 0.0000); //icescart_prop
    k_MarSushiCao[5] = CreateObject(1341, -2028.0900, 493.6856, 35.1487, 0.0000, 0.0000, 90.0000); //icescart_prop
    k_MarSushiCao[6] = CreateObject(1341, -2037.3436, 483.5078, 35.1487, 0.0000, 0.0000, 178.8999); //icescart_prop
    k_MarSushiCao[7] = CreateObject(714, -2027.3857, 485.2239, 33.6898, 0.0000, 0.0000, 0.0000); //veg_bevtree2
    k_MarSushiCao[8] = CreateObject(1364, -2037.3485, 479.4602, 34.9752, 0.0000, 0.0000, 270.0000); //CJ_BUSH_PROP
    k_MarSushiCao[9] = CreateObject(1364, -2037.3485, 488.2399, 34.9752, 0.0000, 0.0000, 270.0000); //CJ_BUSH_PROP
    k_MarSushiCao[10] = CreateObject(1364, -2032.5566, 473.5201, 34.9752, 0.0000, 0.0000, 0.0000); //CJ_BUSH_PROP
    k_MarSushiCao[11] = CreateObject(1364, -2022.8631, 473.5201, 34.9752, 0.0000, 0.0000, 0.0000); //CJ_BUSH_PROP
    k_MarSushiCao[12] = CreateObject(1341, -2027.3293, 473.5456, 35.1487, 0.0000, 0.0000, 270.0000); //icescart_prop
    return 1;
}