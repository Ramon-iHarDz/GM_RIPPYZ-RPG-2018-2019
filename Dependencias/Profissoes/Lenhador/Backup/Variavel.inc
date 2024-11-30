#include <YSI_Coding\y_hooks>

#define MAX_LENHA 25

enum PosicaoInfoLenha
{
    Float:LenhaLPosX,
    Float:LenhaLPosY,
    Float:LenhaLPosZ,

    Float:LenhaLRotX,
    Float:LenhaLRotY,
    Float:LenhaLRotZ
};

enum VeiculoLenha
{
    Float:LenhaVehX,
    Float:LenhaVehY,
    Float:LenhaVehZ,
    Float:LenhaVehA
};

enum JogadorLenhador
{
    // Veículo
    bool:LenhadorVeiculo,
    LenhadorVeiculoID,

    // Codes
    bool:TemTextoLenha,
    Text3D:LenhaVehTexto,

    // Lenhas
    bool:Motoserra, // Verificar se tem motoserra
    bool:MadeiraMao, // Verificar se pegou na mão a madeira :D
    bool:LenhaQuebrando,
    SuaLenhaID,
    StatusLenha,
    LenhaTempo,
    CheckLenhaID,

    // Madeiras
    bool:NoCarroLenhador,
    LenhaObjetoID,

    AntigoLenhaVehID
};

enum LenhaInfo
{
    bool:TemLenha,

    // Verificações de Uso
    bool:LenhaSendoUsada,
    bool:LenhaQuebrada,

    // Misc
    LenhaObjeto,
    IDQuebrando

};

new Lenhador[MAX_PLAYERS][JogadorLenhador];
new Lenha[MAX_LENHA][LenhaInfo];
new LenhadorMensagem;
new Text3D:LenhaTexto[MAX_LENHA];

new LenhaLoad[][PosicaoInfoLenha] =
{
    {-401.07651, -1488.68250, 24.12630,   0.00000, 0.00000, 0.00000},
    {-401.07651, -1514.05249, 22.89030,   0.00000, 0.00000, 0.00000},
    {-401.07651, -1539.05249, 21.64430,   0.00000, 0.00000, 0.00000},
    {-387.72220, -1526.19495, 21.75130,   0.00000, 0.00000, 0.00000},
    {-387.72220, -1501.19495, 23.78530,   0.00000, 0.06000, 0.00000},
    {-401.07651, -1562.55249, 20.50630,   -0.06000, 0.06000, 0.00000},
    {-387.72220, -1551.69495, 21.31730,   0.00000, 0.00000, 0.00000},
    {-412.48819, -1501.19495, 23.07630,   0.00000, 0.00000, 0.00000},
    {-422.86450, -1488.68250, 22.89930,   0.00000, 0.00000, 0.00000},
    {-412.48819, -1524.69495, 21.80430,   0.00000, 0.00000, 0.00000},
    {-412.48819, -1550.19495, 20.97230,   0.00000, 0.00000, 0.00000},
    {-422.86450, -1512.26245, 21.78930,   0.00000, 0.00000, 0.00000},
    {-422.86450, -1539.05249, 20.61330,   0.00000, 0.00000, 0.00000},
    {-432.63220, -1501.19495, 20.60630,   0.00000, 0.00000, 0.00000},
    {-440.65451, -1488.68250, 19.83530,   0.00000, 0.00000, 0.00000},
    {-432.63220, -1524.69495, 19.60530,   0.00000, 0.00000, 0.00000},
    {-432.63220, -1550.19495, 18.33530,   0.00000, 0.00000, 0.00000},
    {-440.65451, -1512.26245, 18.76630,   0.00000, 0.00000, 0.00000},
    {-440.65451, -1539.05249, 17.49230,   0.00000, 0.00000, 0.00000},
    {-448.98819, -1501.19495, 17.60530,   0.00000, 0.00000, 0.00000},
    {-456.94250, -1488.68250, 16.68430,   0.00000, 0.00000, 0.00000},
    {-448.98819, -1524.69495, 16.52830,   0.00000, 0.00000, 0.00000},
    {-448.98819, -1550.19495, 15.11030,   0.00000, 0.00000, 0.00000},
    {-456.94250, -1512.26245, 15.63730,   0.00000, 0.18000, 0.00000},
    {-456.94250, -1539.05249, 13.99930,   0.00000, 0.00000, 0.00000}
};

new VeiculoLLoad[][VeiculoLenha] =
{
    {-502.1937,-1500.8071,11.8435,268.7256},
    {-501.5592,-1496.3843,12.0549,268.5005},
    {-501.9583,-1490.9937,12.2385,268.8297},
    {-502.3901,-1485.0940,12.4404,271.2248}
};