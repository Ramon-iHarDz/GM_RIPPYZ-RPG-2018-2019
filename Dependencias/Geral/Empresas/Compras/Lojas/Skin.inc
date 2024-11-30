#include <YSI_Coding\y_hooks>

enum SkinIndentificacao
{
    SkinID,
    SexoS,
    PrecoSkin,
    Nome[128]
}

new SkinI[][SkinIndentificacao] =
{
	//SkinID - Sexo - PrecoSkin - Nome
	{0, 1, 200, "Sidiney"},
	{1, 1, 800, "The_Truth"},
	{2, 1, 800, "Maccer"},
	{3, 1, 800, "Andre"},
    {4, 1, 800, "Big_Bear_(Margo)"},
    {5, 1, 800, "Big_Bear_(Gordo)"},
    {6, 1, 800, "Emmet"},
    {7, 1, 800, "Luis"},
    {8, 1, 800, "Janitor"},
    {9, 2, 900, "Maria"},
    {10, 2, 700, "Pedestre"},
    {11, 2, 800, "Pedestre"},
    {12, 2, 600, "Pedestre"},
    {13, 2, 300, "Street Girl"},
    {14, 1, 400, "Pedestre"},
    {15, 1, 500, "Mr.Whittaker"},
    {16, 1, 500, "Airport Ground Worker"},
    {17, 1, 800, "Businessman"},
    {18, 1, 800, "Beach Visitor"},
    {19, 1, 400, "DJ"},
    {20, 1, 400, "Rich Guy"},
    {21, 1, 400, "Pedestre"},
    {22, 1, 400, "Pedestre"},
    {23, 1, 900, "BMXer"}, // Kannário
    {24, 1, 700, "Madd Dogg Bodyguard"},
    {25, 1, 700, "Madd Dogg Bodyguard"},
    {26, 1, 300, "Backpacker"},
    {27, 1, 300, "Construction Worker"},
    {28, 1, 500, "Drug Dealer"},
    {29, 1, 500, "Drug Dealer"},
    {30, 1, 500, "Drug Dealer"},
    {31, 2, 400, "Farm-Town inhabitant"},
    {32, 1, 400, "Farm-Town inhabitant"},
    {33, 1, 700, "Farm-Town inhabitant"}, // Cowboy
    {34, 1, 500, "Farm-Town inhabitant"},
    {35, 1, 500, "Gardener"},
    {36, 1, 400, "Golfer"},
    {37, 1, 400, "Golfer"},
    {38, 2, 300, "Pedestre"},
    {39, 2, 500, "Pedestre"},
    {40, 2, 600, "Pedestre"},
    {41, 2, 500, "Pedestre"},
    {42, 1, 700, "Jethro"},
    {43, 1, 600, "Pedestre"},
    {44, 1, 600, "Pedestre"},
    {45, 1, 800, "Beach Visitor"},
    {46, 1, 200, "Pedestre"},
    {47, 1, 600, "Pedestre"},
    {48, 1, 600, "Pedestre"},
    {49, 1, 800, "Snakehead"},
    {50, 1, 600, "Mechanic"},
    {51, 1, 200, "Mountain Biker"},
    {52, 1, 200, "Mountain Biker"},
    {53, 2, 600, "JosefaMariah"},
    {54, 2, 900, "Pedestre"},
    {55, 2, 900, "Pedestre"},
    {56, 2, 900, "Pedestre"},
    {57, 1, 900, "Oriental Ped"},
    {58, 1, 800, "Oriental Ped"},
    {59, 1, 600, "Pedestre"},
    {60, 1, 500, "Pedestre"},
    {61, 1, 600, "Pilot"},
    {62, 1, 700, "Colonel Fuhrberger"},
    {63, 2, 800, "Prostitute"},
    {64, 2, 800, "Prostitute"},
    {65, 2, 800, "Kendl Johnson"},
    {66, 1, 700, "Pool Player"},
    {67, 1, 700, "Pool Player"},
    {68, 1, 600, "Priest/Preacher"},
    {69, 2, 700, "Pedestre"},
    {70, 1, 800, "Scientist"},
    {71, 1, 700, "Security Guard"},
    {72, 1, 600, "Hippy"},
    //{73, 1, 600, "Hippy"}, // Michael
    {75, 2, 800, "Prostitute"},
    {76, 2, 600, "Stewardess"},
    {77, 2, 900, "Homeless"},
    {78, 1, 900, "Homeless"},
    {79, 1, 800, "Homeless"},
    {80, 1, 500, "Boxer"},
    {81, 1, 500, "Boxer"},
    {82, 1, 300, "Elvis"},
    {83, 1, 300, "Elvis"},
    {84, 1, 300, "Elvis"},
    {85, 2, 900, "Prostitute"},
    {86, 1, 900, "Ryder"},
    {87, 2, 800, "Stripper"},
    {88, 2, 600, "Pedestre"},
    {89, 2, 600, "Pedestre"},
    {90, 2, 700, "Jogger"},
    {91, 2, 700, "Rich Woman"},
    {92, 2, 700, "Rollerskater"},
    {93, 2, 700, "Pedestre"},
    {94, 1, 700, "Pedestre"},
    {95, 1, 800, "Pedestre"},
    {96, 1, 200, "Jogger"},
    {97, 1, 900, "Lifeguard"},
    {98, 1, 300, "Pedestre"},
    {99, 1, 300, "Rollerskater"},
    {100, 1, 500, "Biker"},
    //{101, 1, 600, "Pedestre"}, // blueN
    {102, 1, 700, "Balla"},
    {103, 1, 700, "Balla"},
    {104, 1, 700, "Balla"},
    {105, 1, 700, "Grove Street Families"},
    {106, 1, 700, "Grove Street Families"},
    {107, 1, 700, "Grove Street Families"},
    {108, 1, 700, "Los Santos Vagos"},
    {109, 1, 700, "Los Santos Vagos"},
    {110, 1, 700, "Los Santos Vagos"},
    {111, 1, 700, "The Russian Mafia"},
    {112, 1, 700, "The Russian Mafia"},
    {113, 1, 700, "The Russian Mafia"},
    {114, 1, 600, "Los Aztecas"},
    {115, 1, 600, "Los Aztecas"},
    {116, 1, 600, "Los Aztecas"},
    {117, 1, 700, "Triada"},
    {118, 1, 700, "Triada"},
    {119, 1, 500, "Johhny Sindacco"},
    {120, 1, 800, "Triad Boss"}, 
    {121, 1, 100, "Pedestre"},
    {122, 1, 700, "Da Nang Boy"},
    {123, 1, 700, "Da Nang Boy"},
    {124, 1, 500, "The Mafia"},
    // {125, 1, 600, "The Mafia"}, // Paulo
    {126, 1, 600, "The Mafia"},
    {127, 1, 800, "The Mafia"},
    {128, 1, 800, "Farm Inhabitant"},
    {129, 2, 800, "Farm Inhabitant"},
    {130, 2, 800, "Farm Inhabitant"},
    {131, 2, 800, "Farm Inhabitant"},
    {132, 1, 800, "Farm Inhabitant"},
    {133, 1, 800, "Farm Inhabitant"},
    {134, 1, 900, "Homeless"},
    {135, 1, 900, "Homeless"},
    {136, 1, 900, "Homeless"},
    {137, 1, 900, "Homeless"},
    {138, 2, 900, "Beach Visitor"},
    {139, 2, 900, "Beach Visitor"},
    {140, 2, 900, "Beach Visitor"},
    {141, 2, 900, "Businesswoman"},
    {142, 1, 200, "Taxi Driver"},
    {143, 1, 700, "Crack Maker"},
    {144, 1, 700, "Crack Maker"},
    {145, 2, 700, "Crack Maker"},
    {146, 1, 700, "Crack Maker"},
    {147, 1, 800, "Businessman"},
    {148, 2, 800, "Businessman"},
    {149, 1, 800, "Big Smoke"},
    {150, 2, 800, "Businesswoman"},
    {151, 2, 800, "Pedestre"},
    {152, 2, 1000, "Isabella"},
    {153, 1, 700, "Construction Worker"},
    {154, 1, 700, "Iniciante"},
    {155, 1, 700, "Well Stacked Pizza Worker"},
    {156, 1, 700, "Barber"},
    {157, 2, 800, "Hillbilly"},
    {158, 1, 800, "Farmer"},
    {159, 1, 800, "Hillbilly"},
    {160, 1, 800, "Hillbilly"},
    {161, 1, 800, "Farmer"},
    {162, 1, 800, "Hillbilly"},
    {163, 1, 600, "Black Bouncer"},
    {164, 1, 600, "White Bouncer"},
    {165, 1, 800, "Agent"},
    {164, 1, 800, "Agent"},
    {167, 1, 800, "Cluckin' Bell Worker"},
    {168, 1, 800, "Hotdog/Chilli Dog Vendor"},
    {169, 2, 900, "Pedestre"},
    {170, 1, 800, "Pedestre"},
    {171, 1, 800, "Blackjack Dealer"},
    {172, 2, 900, "Casino croupier"},
    {173, 1, 700, "Rifa"},
    {174, 1, 700, "Rifa"},
    {175, 1, 700, "Rifa"},
    {176, 1, 900, "Barber"},
    {177, 1, 900, "Barber"},
    {178, 2, 900, "Whore"},
    {179, 1, 700, "Salesman"},
    {180, 1, 700, "Tattoo Artist"},
    {181, 1, 700, "Punk"},
    {182, 1, 800, "Cab Driver"},
    {183, 1, 800, "Pedestre"},
    {184, 1, 200, "Pedestre"},
    {185, 1, 200, "Pedestre"},
    {186, 1, 200, "Pedestre"},
    {187, 1, 500, "Businessman"},
    {188, 1, 500, "Pedestre"},
    {189, 1, 600, "Valet"},
    {190, 2, 900, "Barbara"},
    {191, 2, 900, "Helena"},
    {192, 2, 900, "Michelle"},
    {193, 2, 900, "Katie Zhan"},
    {194, 2, 900, "Millie Perkins"},
    {195, 2, 900, "Denise Robinson"},
    {196, 2, 900, "Farm-Town inhabitant"},
    {197, 2, 900, "Hillbilly"},
    {198, 2, 900, "Farm-Town inhabitant"},
    {199, 2, 900, "Farm-Town inhabitant"},
    {200, 1, 800, "Hillbilly"},
    {201, 2, 800, "Farmer"},
    {202, 1, 800, "Farmer"},
    {203, 1, 800, "Karate Teacher"},
    {204, 1, 800, "Karate Teacher"},
    {205, 2, 800, "Burger Shot Cashier"},
    {206, 1, 800, "Cab Driver"},
    {207, 2, 800, "Prostitute"},
    {208, 1, 800, "Su Xi Mu (Suzie)"},
    {209, 1, 700, "Oriental Noodle"},
    {210, 1, 900, "Oriental Boating"},
    {211, 2, 900, "Staff"},
    {212, 1, 800, "Homeless"},
    {213, 1, 800, "Weird old man"},
    {214, 2, 800, "Maria Latore"},
    {215, 2, 800, "Pedestre"},
    {216, 2, 800, "Pedestre"},
    {217, 1, 800, "Staff"},
    {218, 2, 600, "Pedestre"},
    {219, 2, 800, "Rich Woman"},
    {220, 1, 300, "Cab Driver"},
    {221, 1, 800, "Baiano"},
    {222, 1, 800, "Pedestre"},
    {223, 1, 800, "Pedestre"},
    {224, 2, 900, "Pedestre"},
    {225, 2, 900, "Pedestre"},
    {226, 2, 900, "Pedestre"},
    {227, 1, 800, "Businessman"},
    {228, 1, 800, "Oriental Pedestre"},
    {229, 1, 400, "Oriental Pedestre"},
    {230, 1, 900, "Homeless"},
    {231, 2, 900, "Pedestre"},
    {232, 2, 900, "Pedestre"},
    {233, 2, 900, "Pedestre"},
    {234, 1, 900, "Cab Driver"},
    {235, 1, 700, "Pedestre"},
    {236, 1, 700, "Pedestre"},
    {237, 2, 700, "Prostitute"},
    {238, 2, 700, "Prostitute"},
    {239, 1, 800, "Homeless"},
    //{240, 1, 700, "The D.A"}, // Kettler
    {241, 1, 700, "Afro-American"},
    {242, 1, 700, "Mexican"},
    {243, 2, 600, "Prostitute"},
    {244, 2, 600, "Prostitute"},
    {245, 2, 600, "Prostitute"},
    {246, 2, 600, "Stripper"},
    {247, 1, 700, "Biker"},
    {248, 1, 700, "Biker"},
    {249, 1, 800, "Pimp"},
    {250, 1, 800, "Pedestre"},
    {251, 2, 800, "Lifeguard"},
    {252, 1, 800, "Naked Valet"},
    {253, 1, 800, "Bus Driver"},
    {254, 1, 800, "Biker Drug Dealer"},
    {255, 1, 800, "Chauffeur"},
    {256, 2, 800, "Stripper"},
    {257, 2, 800, "Stripper"},
    {258, 1, 800, "Heckler"},
    {259, 1, 800, "Heckler"},
    {260, 1, 800, "Construction Worker"},
    {261, 1, 800, "Cab driver"},
    {262, 1, 800, "Cab driver"},
    {263, 2, 900, "Pedestre"},
    {264, 1, 900, "Rippzy"},
    {268, 1, 900, "Dwaine/Dwayne"},
    {269, 1, 900, "Big Smoke"},
    {270, 1, 900, "Sweet"},
    {271, 1, 900, "Ryder"},
    {272, 1, 900, "Mafia Boss"},
    {273, 1, 900, "T-Boné Mendez"},
    {274, 1, 900, "Paramedic"},
    {275, 1, 900, "Paramedic"},
    {276, 1, 900, "Paramedic"},
    {289, 1, 900, "Zero"},
    {290, 1, 900, "Ken Rosenberg"},
    {291, 1, 900, "Kent Paul"},
    {292, 1, 900, "Cesar Vialpando"},
    {293, 1, 900, "OG Loc"},
    {294, 1, 900, "Wu Zi Mu"},
    {295, 1, 900, "Michael Toreno"},
    {296, 1, 900, "Jizzy B."},
    {297, 1, 900, "Madd Dogg"},
    {298, 2, 900, "Catalina"},
    {299, 1, 900, "Claude Speed"}
};

enum AcessorioLInfo
{
    AcObjeto,
    AcPreco,
    AcNome[40],
    bool:AcVip,

    Float:AcRotX,
    Float:AcRotY,
    Float:AcRotZ,
    Float:AcZoom

};

new LAcessorio[][AcessorioLInfo] =
{
    {19137, 2500, "Chapéu de Galinha", false, 0.000000, -90.000000, 0.000000, 1.000000},
    {19064, 900, "Gorro", false, 0.000000, 0.000000, 180.000000, 1.000000},
    {18962, 760, "Chapéu de Cowboy", false, -30.000000, -90.000000, 0.000000, 1.000000}, 
    {19095, 760, "Chapéu de Cowboy", false, -30.000000, -90.000000, 0.000000, 1.000000},
    {19096, 760, "Chapéu de Cowboy", false, -30.000000, -90.000000, 0.000000, 1.000000},
    {19097, 760, "Chapéu de Cowboy", false, -30.000000, -90.000000, 0.000000, 1.000000},
    {19098, 760, "Chapéu de Cowboy", false, -30.000000, -90.000000, 0.000000, 1.000000},
    {18951, 600, "Chapéu Amarelo", false, -30.000000, -90.000000, 0.000000, 1.000000},
    {18947, 600, "Chapéu Preto", false, -30.000000, -90.000000, 0.000000, 1.000000},
    {19488, 980, "Chapéu Branco", true, -30.000000, -90.000000, 0.000000, 1.000000},
    {18950, 750, "Chapéu Vermelho", true, -30.000000, -90.000000, 0.000000, 1.000000},
    {19528, 2900, "Chapéu de Bruxa", true, 0.000000, -90.000000, 0.000000, 1.000000},
    {18968, 800, "Chapéu", false, 0.000000, 50.000000, 0.000000, 1.000000},
    {18927, 650, "Boné Azul", false, -30.000000, -90.000000, 20.000000, 1.000000},
    {18932, 650, "Boné Laranja", false, -30.000000, -90.000000, 20.000000, 1.000000},
    {18928, 650, "Boné Arco", false, -30.000000, -90.000000, 20.000000, 1.000000},
    {18931, 650, "Boné Azul Escuro", false, -30.000000, -90.000000, 20.000000, 1.000000},
    {19558, 1250, "Boné Pizza", true, -30.000000, -90.000000, 20.000000, 1.000000},
    {18942, 1300, "Boné Cinza", true, -30.000000, -90.000000, 20.000000, 1.000000},
    {18961, 800, "Boné Preto e Branco", false, -30.000000, -90.000000, 20.000000, 1.000000},
    {18636, 2100, "Boné Policia", true, -30.000000, -90.000000, 20.000000, 1.000000},
    {19487, 2000, "Cartola", true, -30.000000, 0.000000, 0.000000, 1.000000},
    {19025, 950, "Óculos Rosa", false, -30.000000, 0.000000, 120.000000, 1.000000},
    {19026, 950, "Óculos Vermelho", false, -30.000000, 0.000000, 120.000000, 1.000000},
    {19028, 950, "Óculos Amarelo", false, -30.000000, 0.000000, 120.000000, 1.000000},
    {19023, 950, "Óculos Azul", false, -30.000000, 0.000000, 120.000000, 1.000000},
    {19010, 950, "Óculos Tingido", false, -30.000000, 0.000000, 120.000000, 1.000000},
    {19024, 950, "Óculos Roxo", true, -30.000000, 0.000000, 120.000000, 1.000000},
    {19034, 1000, "Óculos de Vidro", true, -30.000000, 0.000000, 120.000000, 1.000000},
    {19022, 950, "Óculos de Sol", false, -30.000000, 0.000000, 120.000000, 1.000000},
    {19033, 820, "Óculos Escuro", false, 0.000000, 0.000000, 90.000000, 1.000000},
    {358, 3500, "Sniper", true, -30.000000, 0.000000, 120.000000, 2.599999},
    {356, 5000, "M4", true, -30.000000, 0.000000, 120.000000, 2.599999},
    {372, 1500, "Tec-9", false, -30.000000, 0.000000, 120.000000, 2.599999},
    {355, 5900, "AK-47", true, -30.000000, 0.000000, 120.000000, 2.599999},
    {353, 4500, "MP5", true, -30.000000, 0.000000, 120.000000, 2.599999},
    {352, 1000, "Uzi", false, -30.000000, 0.000000, 120.000000, 2.599999},
    {19942, 3000, "Radio Comunicador", true, 0.000000, 50.000000, -20.000000, 1.000000},
    //{19878, "Skate", true, -30.000000, 0.000000, 120.000000, 2.599999},
    {19610, 950, "Microfone", true, 0.000000, 50.000000, -20.000000, 1.000000},
    {19421, 850, "Fones", false, 90.000000, 0.000000, 0.000000, 1.00000},
    {19422, 850, "Fones", false, 90.000000, 0.000000, 0.000000, 1.00000},
    {19423, 850, "Fones", false, 90.000000, 0.000000, 0.000000, 1.00000},
    {19039, 450, "Relogio", false, 90.000000, 0.000000, 0.000000, 1.00000},
    {19038, 750, "Máscara Verde", false, 0.000000, 0.000000, 90.000000, 1.000000},
    {19036, 750, "Máscara Branca", false, 0.000000, 0.000000, 90.000000, 1.000000},
    {19037, 750, "Máscara Vermelha", false, 0.000000, 0.000000, 90.000000, 1.000000},
    {18916, 750, "Bandana Amarela", false, -50.000000, -60.000000, 200.000000, 1.000000},
    {18915, 750, "Bandana Rosa", false, -50.000000, -60.000000, 200.000000, 1.000000},
    {18914, 750, "Bandana Camuflada", false, -50.000000, -60.000000, 200.000000, 1.000000},
    {18917, 750, "Bandana Azul", false, -50.000000, -60.000000, 200.000000, 1.000000},
    {18918, 750, "Bandana Verde", false, -50.000000, -60.000000, 200.000000, 1.000000},
    {18913, 750, "Bandana Verde Lama", false, -50.000000, -60.000000, 200.000000, 1.000000},
    {18919, 750, "Bandana Branca", true, -50.000000, -60.000000, 200.000000, 1.000000},
    {19801, 1300, "BalaClava", false, 0.000000, 0.000000, 200.000000, 1.000000},
    {19515, 3850, "Colete Cinza", true, 0.000000, -90.000000, 60.000000, 1.000000},
    {19142, 3300, "Colete Preto", false, 0.000000, -90.000000, 60.000000, 1.000000},
    {19472, 2000, "Máscara de Gás", true, 0.000000, 0.000000, 90.000000, 1.000000},
    {2703, 980, "Hamburguer", false, -60.000000, 0.000000, 0.000000, 1.000000},
    {335, 1500, "Faca", true, -60.000000, 0.000000, 0.000000, 1.000000},
    {1238, 1270, "Cone", false, -60.000000, 0.000000, 0.000000, 1.000000},
    {19590, 790, "Espada", false, 0.000000, 0.000000, -50.000000, 1.000000},
    {19318, 2980, "Guitarra", true, 0.000000, 0.000000, -180.000000, 1.000000},
    {19319, 2700, "Guitarra", true, 0.000000, 0.000000, -180.000000, 1.000000},
    {19317, 2180, "Guitarra", true, 0.000000, 0.000000, -180.000000, 1.000000},
    {19078, 1600, "Papagaio", false, -90.000000, -60.000000, -90.000000, 1.000000},
    {18922, 1450, "Boina Vermelha", false, -90.000000, -60.000000, -90.000000, 1.000000},
    {18923, 1350, "Boina Azul", false, -90.000000, -60.000000, -90.000000, 1.000000},
    {18924, 1650, "Boina Exército", true, -90.000000, -60.000000, -90.000000, 1.000000},
    {18925, 1700, "Boina Exército Vermelho", true, -90.000000, -60.000000, -90.000000, 1.000000},
    {18921, 1200, "Boina Preta", true, -90.000000, -60.000000, -90.000000, 1.000000},
    {19141, 3900, "Capacete", false, -90.000000, -60.000000, -90.000000, 1.000000},
    {19108, 3700, "Capacete", true, -90.000000, -60.000000, -90.000000, 1.000000},
    {19113, 3100, "Capacete Colorido", false, -90.000000, -60.000000, -90.000000, 1.000000},
    {19107, 2900, "Capacete Camuflado", false, -90.000000, -60.000000, -90.000000, 1.000000},
    {18952, 2750, "Capacete Boxer", true, -90.000000, -60.000000, -90.000000, 1.000000},
    {19115, 3000, "Chapéu Sad", true, -90.000000, -60.000000, -90.000000, 1.000000},
    {19114, 3800, "Chapéu", false, -90.000000, -60.000000, -90.000000, 1.000000},
    {19833, 5000, "Vaca", false, 0.000000, 0.000000, 160.000000, 1.000000}, 
    {1608, 5600, "Tubarão", false, 0.000000, 0.000000, 160.000000, 1.000000},
    {18846, 6000, "Ufo", true, 0.000000, 0.000000, 160.000000, 1.000000},
    {19631, 5000, "Marreta", false, 0.000000, 0.000000, 160.000000, 1.000000},
    {19315, 5000, "Veado", false, 0.000000, 0.000000, 160.000000, 1.000000},
    {371, 10000, "Mochila", true, 0.000000, 0.000000, 160.000000, 1.000000}
};

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    // Fechar
    if(playertextid == SkinT[playerid][10]) OcultarLojaSkin(playerid);

    // Próximo
    else if(playertextid == SkinT[playerid][3]) 
    {
        if(LojaSkinAtual[playerid] >= sizeof(SkinI)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há skins para frente");
        LojaSkinAtual[playerid] += 1;
        AtualizarLojaSkin(playerid, LojaSkinAtual[playerid]);    
    }

    // Voltar
    else if(playertextid == SkinT[playerid][2])
    {
        if(LojaSkinAtual[playerid] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há skins para trás");
        LojaSkinAtual[playerid] -= 1;
        AtualizarLojaSkin(playerid, LojaSkinAtual[playerid]);
    }

    // Comprar
    else if(playertextid == SkinT[playerid][8])
    {
        new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
        if(Jogador[playerid][Sexo] != SkinI[LojaSkinAtual[playerid]][SexoS]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode comprar essa skin");
        if(Jogador[playerid][Skin] == SkinI[LojaSkinAtual[playerid]][SkinID]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você já possui essa skin");
        if(Jogador[playerid][Dinheiro] < SkinI[LojaSkinAtual[playerid]][PrecoSkin]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente!");
        if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de roupas nessa empresa");

        // Enviar o dinheiro para Loja
        EnviarDinheiroEmpresa(id, SkinI[LojaSkinAtual[playerid]][PrecoSkin]); 

        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| LOJA | Você comprou skin {FF8C00}%s{FFFFFF} por {32CD32}$%s", SkinI[LojaSkinAtual[playerid]][Nome], DinheiroSeparar(SkinI[LojaSkinAtual[playerid]][PrecoSkin]));
        SendClientMessage(playerid, -1, Mensagem);

        Jogador[playerid][Dinheiro] -= SkinI[LojaSkinAtual[playerid]][PrecoSkin];
        Jogador[playerid][Skin] = SkinI[LojaSkinAtual[playerid]][SkinID];
        SetPlayerSkin(playerid, SkinI[LojaSkinAtual[playerid]][SkinID]);
        OcultarLojaSkin(playerid);
        pEmpresa[id][eEstoque]--;
    }

    // Acessórios
    else if(playertextid == SkinT[playerid][9])
    {
        OcultarLojaSkin(playerid);
        MostrarLojaAcessorios(playerid);
        AtualizarLojaAcessorio(playerid, LojaAcessorioAtual[playerid]);
        
    }

    // Acessorios
        // Fechar
    else if(playertextid == AcessorioL[playerid][9]) OcultarLojaAcessorios(playerid); 

    // Comprar
    else if(playertextid == AcessorioL[playerid][8])
    {
        if(LAcessorio[LojaAcessorioAtual[playerid]][AcVip] == true){
            if(Jogador[playerid][Vip] < gettime()) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse acessório é exclusivo apenas para VIP ou Nitro Boost");
        }

        new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
        if(Jogador[playerid][Dinheiro] < LAcessorio[LojaAcessorioAtual[playerid]][AcPreco]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro para comprar esse acessório");
        if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de roupas nessa empresa");
        
        Jogador[playerid][Dinheiro] -= LAcessorio[LojaAcessorioAtual[playerid]][AcPreco];
        EnviarDinheiroEmpresa(id, LAcessorio[LojaAcessorioAtual[playerid]][AcPreco]); 

        pEmpresa[id][eEstoque]--;
        OcultarLojaAcessorios(playerid);
        AdicionarAcessorio(playerid, LojaAcessorioAtual[playerid]);
    }

    // Tras
    else if(playertextid == AcessorioL[playerid][2])
    {
        if(LojaAcessorioAtual[playerid] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há acessórios para trás");
        LojaAcessorioAtual[playerid]--;
        AtualizarLojaAcessorio(playerid, LojaAcessorioAtual[playerid]);
    }

    // Frente
    else if(playertextid == AcessorioL[playerid][3])
    {
        if(LojaAcessorioAtual[playerid] >= sizeof(LAcessorio)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há acessórios para frente");
        LojaAcessorioAtual[playerid]++;
        AtualizarLojaAcessorio(playerid, LojaAcessorioAtual[playerid]);
    }
    return 0;
}


function AtualizarLojaSkin(playerid, item)
{
    new Formatar[70];

    // Atualizar Modelo
    PlayerTextDrawSetPreviewModel(playerid, SkinT[playerid][1], SkinI[item][SkinID]);
    PlayerTextDrawShow(playerid, SkinT[playerid][1]);

    // Atualizar Preço
    format(Formatar, sizeof(Formatar), "$%s", DinheiroSeparar(SkinI[item][PrecoSkin]));
    PlayerTextDrawSetString(playerid, SkinT[playerid][4], Formatar);

    // Atualizar Nome
    PlayerTextDrawSetString(playerid, SkinT[playerid][5], SkinI[item][Nome]);

    // Atualizar Tipo do Sexo
    if(SkinI[item][SexoS] == 1) PlayerTextDrawSetString(playerid, SkinT[playerid][6], "Masculino");
    else if(SkinI[item][SexoS] == 2) PlayerTextDrawSetString(playerid, SkinT[playerid][6], "Feminina");
    return 1;
}

function AtualizarLojaAcessorio(playerid, item)
{
    new Formatar[70];

    // Atualizar Objeto
    PlayerTextDrawSetPreviewModel(playerid, AcessorioL[playerid][1], LAcessorio[item][AcObjeto]);
    PlayerTextDrawSetPreviewRot(playerid, AcessorioL[playerid][1], LAcessorio[item][AcRotX], LAcessorio[item][AcRotY], LAcessorio[item][AcRotZ], LAcessorio[item][AcZoom]);
    PlayerTextDrawShow(playerid, AcessorioL[playerid][1]);

    // Atualizar Preço
    format(Formatar, sizeof(Formatar), "$%s", DinheiroSeparar(LAcessorio[item][AcPreco]));
    PlayerTextDrawSetString(playerid, AcessorioL[playerid][4], Formatar);

    // Atualizar Nome
    PlayerTextDrawSetString(playerid, AcessorioL[playerid][5], ConverterTexto(LAcessorio[item][AcNome])); 

    // Atualizar Tipo do Sexo
    if(LAcessorio[item][AcVip] == true) PlayerTextDrawSetString(playerid, AcessorioL[playerid][6], "Exclusivo_para_VIPs_e_Nitro_Booster");
    else if(LAcessorio[item][AcVip] == false) PlayerTextDrawSetString(playerid, AcessorioL[playerid][6], " ");
    return 1;
}

function AdicionarAcessorio(playerid, item)
{
    new bool:temespaco = false;
    for(new i=0; i < MAX_ACESSORIOSINV; i++)
    {
        if(pAcessorio[playerid][i][AcessorioObj] != 0) continue;

        new Enviar[400];
        format(Enviar, sizeof(Enviar), "INSERT INTO `acessorios` (`Nome`, `Slot`, `AcessorioNome`, `ModeloID`, `ScaleX`, `ScaleY`, `ScaleZ`) VALUES ('%s', %d, '%s', %d, %f, %f, %f)", EscapeString(PegarNick(playerid)), i, EscapeString(LAcessorio[item][AcNome]), LAcessorio[item][AcObjeto], 1.0, 1.0, 1.0);
        mysql_query(IDConexao, Enviar, false);
        if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um erro ao adicionar esse acessorio em sua conta");

        new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
        EnviarDinheiroEmpresa(id, LAcessorio[item][AcPreco]); 
        Jogador[playerid][Dinheiro] -= LAcessorio[item][AcPreco];
        pAcessorio[playerid][i][AcessorioObj] = LAcessorio[item][AcObjeto];
        format(pAcessorio[playerid][i][AcessorioNome], 90, LAcessorio[item][AcNome]);
        format(Enviar, sizeof(Enviar), "| LOJA | Você comprou o {FF8C00}%s{FFFFFF} por {32CD32}$%s{FFFFFF}, Use: /Acessorios", LAcessorio[item][AcNome], DinheiroSeparar(LAcessorio[item][AcPreco]));
        SendClientMessage(playerid, -1, Enviar);
        temespaco = true;
        break;
    }

    if(temespaco == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem espaço sucifiente para mais acessórios!");
    return 1;
}