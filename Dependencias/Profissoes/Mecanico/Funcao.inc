#include <YSI_Coding\y_hooks> 

enum CarroMecanicoSpawm
{
    Float:cMX,
    Float:cMY,
    Float:cMZ,
    Float:cMA
};

new mSpawn[][CarroMecanicoSpawm] = 
{
    {333.4537, -9.1628, 1.3687, 93.6892},
    {333.6064, -14.9802, 1.3598, 92.4255},
    {333.8227, -21.7144, 1.3590, 91.2884},
    {333.9656, -27.6611, 1.3471, 91.0013}
};

new MecanicaBlackList[] =
{
    406, 407, 408, 409, 414, 416,
    417, 423, 425, 427, 428, 431,
    432, 433, 437, 443, 444, 446,
    455, 456, 498, 499, 508, 514,
    515, 524, 525, 544, 556, 557,
    609
};

stock VerificarMBlock(modelo)
{
    for(new i=0; i < sizeof(MecanicaBlackList); i++)
    {
        if(MecanicaBlackList[i] != modelo) continue;
        return true;
    }
    return false;
}

stock VerificarMecanica(id)
{
    new fda[40];
    if(id == 2) fda = "Alteração de Pintura";
    else if(id == 1) fda = "Reparação de Veículo";
    return fda;
}