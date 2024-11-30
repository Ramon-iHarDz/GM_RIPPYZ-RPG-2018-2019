enum RaridadeInfo
{
    CorR[20],
    RaridadeN[30]
};

enum PresentesCaixas
{
    Rarid,
    PresenteR[60],
    Prt
};

new Presentes[][PresentesCaixas] =
{
    // Lendários
    {3, "Dildo Roxo", 70},
    {3, "$10.000", 60},
    {3, "$15.000", 70},
    {3, "Dildo Roxo", 60},
    {3, "Dildo Roxo", 60},
    {3, "Colete", 50},
    {3, "Dildo Roxo", 70}, 
    {3, "+2 Experência", 80},
    {3, "+1 Experência", 99},


    // Épicos
    {2, "Dildo Roxo", 40},
    {2, "$5.000", 20},
    {2, "$8.000", 20},
    {2, "Dildo Roxo", 40},
    {2, "Dildo Roxo", 45},
    {2, "+2 Leveis", 50},
    {2, "+2 de Experiência", 20},
    {2, "+1 Level", 20},
    {2, "+10 Vasos", 10},
    {2, "+10 Sementes", 10},
    {2, "+15 Dinamites", 15}, 


    // Raro
    {1, "$1.000", 20},
    {1, "$1.500", 35},
    {1, "$100 de Coins", 20},
    {1, "$300 de Coins", 20},
    {1, "$-2.000", 20},
    {1, "+2 Dinamites", 20},
    {1, "+5 Vasos", 10},
    {1, "+5 Sementes", 10},
    {1, "Dildo Roxo", 5},
    {1, "+1 Caixa", 10},


    // Comuns
    {0, "$200", 0},
    {0, "Vazio", 0},
    {0, "$500", 0},
    {0, "+1 Vazo", 0},
    {0, "+1 Semente", 0},
    {0, "+1 Crédito", 0},
    {0, "$-500 =(", 0},
    {0, "$-100 =(", 0},
    {0, "$1", 0},
    {0, "$5", 0},
    {0, "$-5", 0},
    {0, "Congelar por 5 Segundos", 0},
    {0, "Bêbado(a)", 0}

    
};

new Raridade[][RaridadeInfo] =
{
    {"FFD700FF", "Lendário"},
    {"00BFFFFF", "Comum"},
    {"FA8072FF", "Raro"},
    {"9932CCFF", "Épico"}   
};