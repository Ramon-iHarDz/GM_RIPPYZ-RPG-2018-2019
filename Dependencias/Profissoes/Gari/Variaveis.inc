#define MAX_LIXOS 999
#define MaximoLixo 100
#define LixoPreco 50

enum GariInfo
{
    // Sistema do Lixo
    bool:UniformeAlugado, // Verificar se tem uniforme alugado
    bool:VeiculoAlugado, // Verificar se tem veículo alugado
    LixoNaMao, // Verificar se tem lixo na mão
    
    // Suas Informações
    CaminhaoLixo, // ID do veículo
    Text3D:GariTexto, // Texto dos do Gari

    // Informações
    LixosColetado, // Verificar lixos coleatdos
    GariIcone, // ID do Icone no Radar
    GariCheck, // ID do CheckPoint

    // Sistema de Parceiro
    bool:TemParceiro, // Verificar se tem parceiro
    Parceiro, // Verificar ID do parceiro(a)

    // Delay
    GariDelayRoupa,
    GariDelayVeiculo,
};

enum Lixos
{
    LixoID,
    ModeloLixo,
    LixoMaximo,
    LixoAtual,
    Separacao,
    Float:PosX,
    Float:PosY,
    Float:PosZ,
    Text3D:LixoTexto,
    bool:cColocado
};

enum CaminhoesDeLixoInfo
{
    Float:PosicaoX,
    Float:PosicaoY,
    Float:PosicaoZ,
    Float:PosicaoA
};

new pLixo[][CaminhoesDeLixoInfo] =
{
    {2140.2305,-2098.4814,14.1982,133.7785}, //Posicao (1) 
    {2133.0100,-2092.6018,14.1988,135.7392}, //Posicao (2)
    {2125.0205,-2085.9573,14.2067,135.8790}, //Posicao (3)
    {2118.4141,-2077.9438,14.2079,136.3692} //Posicao (4)
};

new Lixo[MAX_LIXOS][Lixos];
new pGari[MAX_PLAYERS][GariInfo];