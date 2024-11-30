/*
native IsVehicleFlyingVehicle(vehicleid);
native IsVehicleLandVehicle(vehicleid);
native IsVehicleBoat(vehicleid);
native IsVehicleBicicleta(vehicleid);
native IsVehicleMoto(vehicleid)
*/

new Boat[] = {472, 473, 493, 484, 430, 453, 452, 446, 454, 595};
new AirVeh[] = {592, 577, 511, 512, 593, 520, 553, 476, 519, 460, 513, 548, 425, 417, 487, 488, 497, 563, 447, 469};
new Bicicleta[] = {481, 509, 510};
new Moto[] = {461, 462, 448, 522, 581, 521, 523, 463, 586, 468, 471};
new Caminhao[] = {403, 406, 407, 408, 414, 416, 427, 433, 443, 455, 456, 498, 508, 514, 515, 524, 573, 578, 428};
new Onibus[] = {431, 437}; 

stock IsVehicleFlyingVehicle(vehicleid)
{
    for(new i=0; i < sizeof(AirVeh); i++)
    {
        if(GetVehicleModel(vehicleid) == AirVeh[i]) return 1;
    }
    return 0;
}

stock IsVehicleBoat(vehicleid)
{
    for(new i=0; i < sizeof(Boat); i++)
    {
        if(GetVehicleModel(vehicleid) == Boat[i]) return 1;
    }
    return 0;
}

stock IsVehicleBicicleta(vehicleid)
{
    for(new i=0; i < sizeof(Bicicleta); i++)
    {
        if(GetVehicleModel(vehicleid) == Bicicleta[i]) return 1;
    }
    return 0;   
}

stock IsVehicleMoto(vehicleid)
{
    for(new i=0; i < sizeof(Moto); i++)
    {
        if(GetVehicleModel(vehicleid) == Moto[i]) return 1;
    }
    return 0;
}

stock IsVehicleLandVehicle(vehicleid)
{
    if(!IsVehicleBoat(vehicleid) && !IsVehicleFlyingVehicle(vehicleid) && !IsVehicleBicicleta(vehicleid)) return 1;
    return 0;
}

stock IsApenasCarro(vehicleid)
{
    if(!IsVehicleBoat(vehicleid) && !IsVehicleFlyingVehicle(vehicleid) && !IsVehicleBicicleta(vehicleid) && !IsVehicleMoto(vehicleid)) return 1;
    return 0;
}

stock IsVehicleCaminhao(vehicleid)
{
    for(new i=0; i < sizeof(Caminhao); i++)
    {
        if(GetVehicleModel(vehicleid) == Caminhao[i]) return 1;
    }
    return 0;
}

stock IsVehicleOnibus(vehicleid)
{
    for(new i=0; i < sizeof(Onibus); i++)
    {
        if(GetVehicleModel(vehicleid) == Onibus[i]) return 1;
    }
    return 0;
} 