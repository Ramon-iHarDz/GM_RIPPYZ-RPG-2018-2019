#include <YSI_Coding\y_hooks>

enum VeiculOS
{
    Modelo,
    Valor,
    Nome[128],
    Categoria[128]
};

new AeroConceInfo[][VeiculOS] =
{
    {511, 350000, "Beagle", "AirPlane"},
    {513, 250000, "Stuntplane", "AirPlane"},
    {519, 8000000, "Shamal", "AirPlane"},
    {593, 200000, "Dodo", "AirPlane"},
    {417, 750000, "Levianthan", "Helicopters"},
    {487, 650000, "Maverick", "Helicopters"},
    //{447, 350000, "Seasparrow", "Helicopters"},
    {469, 380000, "Sparrow", "Helicopters"}
};

new VeiculoConceInfo[][VeiculOS] =
{
    {400, 50000, "Landstalker", "Off Road"}, 
    {401, 75000, "Bravura", "Saloons"},
    {402, 90000, "Buffalo", "Sport Vehicles"},
    {404, 30000, "Perennial", "Station Wagons"},
    {405, 40000, "Sentinel", "Saloons"},
    {409, 95000, "Stretch", "Unique Vehicles"},
    {410, 50000, "Manana", "Saloons"},
    {411, 220000, "Infernus", "Sport Vehicles"},
    {412, 70000, "Voodoo", "Lowriders"},
    {415, 190000, "Cheetah", "Sport Vehicles"},
    {418, 80000, "Moonbeam", "Station Wagons"},
    {419, 80000, "Esperanto", "Saloons"},
    {421, 60000, "Washington", "Saloons"},
    {422, 60000, "Bobcat", "Industrial"},
    {423, 80000, "Mr. Whoopee", "Unique Vehicles"},
    {424, 60000, "BF Injection", "Off Road"},
    {426, 60000, "Premier", "Saloons"},
    {429, 190000, "Banshee", "Sport Vehicles"},
    {434, 120000, "Hotknife", "Unique Vehicles"},
    {436, 70000, "Previon", "Saloons"},
    {437, 450000, "Coach", "Public Service"},
    {439, 80000, "Stallion", "Convertibles"},
    {440, 62000, "Rumpo", "Industrial"},
    {442, 79000, "Romero", "Unique Vehicles"},
    {443, 200000, "Packer", "Industrial"},
    {444, 110000, "Monster", "Off Road"},
    {445, 70000, "Admiral", "Saloons"},
    {451, 200000, "Turismo", "Sport Vehicles"},
    {455, 110000, "Flatbed", "Industrial"},
    {457, 20000, "Caddy", "Unique Vehicles"},
    {458, 30000, "Solair", "Station Wagons"},
    {462, 4000, "Faggio", "Bikes"},
    {463, 80000, "Freeway", "Bikes"},
    {466, 68000, "Glendale", "Saloons"},
    {467, 69000, "Oceanic", "Saloons"},
    {468, 9000, "Sanchez", "Bikes"},
    {471, 45000, "Quad", "Bikes"},
    {474, 59000, "Hermes", "Saloons"},
    {475, 125000, "Sabre", "Sport Vehicles"},
    {477, 130000, "ZR-350", "Sport Vehicles"},
    {480, 95000, "Comet", "Convertibles"},
    {481, 2000, "BMX", "Bikes"},
    {483, 90000, "Camper", "Unique Vehicles"},
    {489, 85000, "Rancher", "Off Road"},
    {491, 89000, "Virgo", "Saloons"},
    {492, 60000, "Greenwood", "Saloons"},
    {494, 150000, "Hotring Racer", "Sport Vehicles"},
    {495, 70000, "Sandking", "Off Road"},
    {496, 30000, "Blista Compact", "Sport Vehicles"},
    {500, 75000, "Mesa", "Off Road"},
    {502, 120000, "Hotring Racer A", "Sport Vehicles"},
    {503, 120000, "Hotring Racer B", "Sport Vehicles"},
    {504, 95000, "Bloodring Banger", "Saloons"},
    {506, 190000, "Super GT", "Sport Vehicles"},
    {508, 250000, "Trailer Ben-10", "Easter Egg"},
    {509, 1000, "Bike", "Bike"},
    {510, 1300, "Mountain Bike", "Bike"},
    {517, 58000, "Majestic", "Saloons"},
    {521, 70000, "FCR-900", "Bikes"},
    {522, 90000, "NRG-500", "Bikes"},
    {526, 65000, "Fortune", "Saloons"},
    {527, 52000, "Cadrona", "Saloons"},
    {529, 50000, "Willard", "Saloons"},
    {533, 52000, "Feltzer", "Convertibles"},
    {534, 50000, "Remington", "Lowriders"},
    {535, 70000, "Slamvan", "Lowriders"},
    {536, 70000, "Blade", "Lowriders"},
    {540, 75000, "Vincent", "Saloons"},
    {541, 190000, "Bullet", "Sport Vehicles"},
    {542, 74000, "Clover", "Sport Vehicles"},
    {543, 55000, "Sadler", "Industrial"},
    {545, 75000, "Hustler", "Unique Vehicles"},
    {546, 45000, "Intruder", "Saloons"},
    {547, 45000, "Primo", "Saloons"},
    {550, 85000, "Sunrise", "Saloons"},
    {551, 40000, "Merit", "Saloons"},
    {554, 58000, "Yosemite", "Industrial"},
    {555, 100000, "Windsor", "Convertibles"},
    {556, 125000, "Monster A", "Off Road"},
    {557, 128000, "Monster B", "Off Road"},
    {558, 110000, "Uranus", "Sport Vehicles"},
    {559, 100000, "Jester", "Sport Vehicles"},
    {560, 110000, "Sultan", "Saloons"},
    {561, 110000, "Stratum", "Wagons"},
    {562, 100000, "Elegy", "Saloons"},
    {565, 90000, "Flash", "Sport Vehicles"},
    {566, 80000, "Tahoma", "Lowriders"},
    {567, 80000, "Savanna", "Lowriders"},
    {568, 80000, "Bandito", "Off Road"},
    {571, 20000, "Kart", "Unique Vehicles"},
    {572, 20000, "Mower", "Unique Vehicles"},
    {573, 80000, "Dune", "Off Road"},
    {575, 50000, "Broadway", "Lowriders"},
    {576, 70000, "Tornado", "Lowriders"},
    {579, 60000, "Huntley", "Off Road"},
    {580, 85000, "Stafford", "Saloons"},
    {581, 20000, "BF-400", "Bikes"},
    {586, 80000, "Wayfarer", "Bikes"},
    {585, 60000, "Emperor", "Saloons"},
    {587, 89000, "Euros", "Sport Vehicles"},
    {589, 60000, "Club", "Sport Vehicles"},
    {600, 80000, "Picador", "Industrial"},
    {603, 90000, "Phoenix", "Sport Vehicles"},
    {602, 80000, "Alpha", "Alpha"}
};

enum LocalConce
{
    //Conce
    Float:ConcePosicaoX,
    Float:ConcePosicaoY,
    Float:ConcePosicaoZ,

    //Veiculo do SPEC
    Float:VeiculoSpecX,
    Float:VeiculoSpecY,
    Float:VeiculoSpecZ,
    Float:VeiculoSpecA,

    //Posicao Apos Comprar
    Float:VeiculoCX,
    Float:VeiculoCY,
    Float:VeiculoCZ,
    Float:VeiculoCA, 

    //Posições da Camera
    Float:CameraPX,
    Float:CameraPY,
    Float:CameraPZ,
    
    Float:CameraCX,
    Float:CameraCY,
    Float:CameraCZ
};

new ConceLocal[][LocalConce] = 
{
    //Los Santos (1)
    {532.6002, -1292.5789, 17.2422, //Posição Conce
    549.5773, -1284.0005, 16.9201, 28.6948, //Posição do veículo espec
    555.0308, -1289.1515, 16.9203, 359.5420, //Posição veículo comprado

    552.740966, -1273.165283, 19.406335, //SetPlayerCameraPos
    551.166320, -1277.867797, 18.768663 //SetPlayerCameraLookAt
    },

    //Los Santos (2)
    {2131.8818, -1150.4889, 24.1525, //Posição Conce
    2133.9985, -1137.2052, 25.3020, 65.7787, //Posição do veículo espec
    2119.3298, -1138.3829, 24.8107, 261.9271, //Posição veículo comprado
    
    2127.737060, -1129.695434, 29.512048, //SetPlayerCameraPos
    2129.780517, -1133.958740, 27.884557 //SetPlayerCameraLookAt
    },

    //San Fierro (1)
    {-1657.9063, 1210.6770, 7.2500, //Posição Conce
    -1656.6278, 1214.4540, 13.3438, 104.0823, //Posição do veículo espec
    -1637.8418, 1211.5955, 6.7111, 224.5173, //Posição veículo comprado
    
    -1664.208618, 1208.140014, 15.582493, //SetPlayerCameraPos
    -1660.497314, 1211.394287, 14.785447 //SetPlayerCameraLookAt
    },

    //San Fierro (2)
    {-1966.3468, 293.8265, 35.4688, //Posição Conce
    -1983.6725, 269.9065, 34.8493, 129.5237, //Posição do veículo espec
    -1990.0885, 257.7909, 34.8472, 265.6456, //Posição veículo comprado
    
    -1993.418701, 264.365753, 39.035240, //SetPlayerCameraPos
    -1989.172119, 266.527252, 37.520671 //SetPlayerCameraLookAt
    }, 

    //Las Venturas (1)
    {1948.4673, 2068.8025, 11.0610, //Posição Conce
    1984.8585, 2047.7086, 10.5246, 105.7928, //Posição do veículo espec
    1940.0790, 2053.7856, 10.5273, 359.3918, //Posição veículo comprado
    
    1972.281616, 2051.937988, 12.613311, //SetPlayerCameraPos
    1976.927612, 2050.144531, 12.168905 //SetPlayerCameraLookAt
    },

    //Las Venturas (2)
    {2200.8113, 1394.2528, 11.0625, //Posição Conce
    2164.6594, 1414.4587, 10.5257, 51.3747, //Posição do veículo espec
    2139.0293, 1398.3423, 10.5108, 180.5377, //Posição veículo comprado
    
    2162.151611, 1422.908203, 13.630149, //SetPlayerCameraPos
    2163.987060, 1418.422363, 12.401874 //SetPlayerCameraLookAt
    },

    //Conce Aero
    {-1262.8848, 40.7986, 14.1391, //Posição Conce
    -1187.3551, 27.1640, 14.3253, 42.5155, //Posição do veículo espec
    -1246.1146, -19.3846, 14.3256, 133.9014, //Posição veículo comprado

    -1207.641235, 24.233110, 24.416191, //Posição do veículo espec
    -1203.076293, 24.437927, 22.386634 //SetPlayerCameraLookAt
    }

};