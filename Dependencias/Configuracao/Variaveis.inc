#include <YSI_Coding\y_hooks>

// Veiculos
#define     MAX_SLOT_VEH            (10)
#define     MAX_SOM                 (200)

// Casas
#define     MAX_CASAS               (1200)
#define     MAX_MORADOR             (6)
#define     MAX_MOVEIS              (150)

// Empresas
#define     MAX_EMPRESAS            (300)
#define     MAX_FABRICAS            (20)
#define     MAX_FUNCIONARIOS        (7)
#define     MAX_FUNCIONARIOSFAB     (10)

// Jogador
#define     MAX_ACESSORIOS          (6)
#define     MAX_ACESSORIOSINV       (15)
#define     MAX_NUMEROS             (40)

// Ônibus / Rotas
#define     MAX_PARADAS             (1000)
#define     MAX_ROTAS               (40)
#define     MAX_ROTASID             (70)

// Bases
#define     MAX_BASES               (50)
#define     MAX_BASEVEH             (5)
#define     MAX_MEMBROS             (50) 

// Caixas Eletrônicos
#define     MAX_CAIXAS              (250)

// Concessionária
#define     MAX_CONCESSIONARIA      (10)
#define     MAX_CONCESSIONARIA_VEH  (30)

new bool:Whitelist;
new bool:ServidorBeta;
new IpEmail[60];
new PortaEmail[30];
new SenhaEmail[90];
new VoipID[4][23];
new NatalGorroID = 18723; // Não Natal: 18723 / Natal: 19064
new normalclima;
// new JogadoresOn;


// Sistemas de Gerais
new bool:EmailFunc,
    bool:RegistroFunc,
    bool:LoginFunc,
    bool:CaixaFunc;


new bool:Horapers;
new HorasSyncMic;
new HorasSync;
//new SemTeleportes;

hook OnGameModeInit()
{
    for(new i=0; i < 4; i++){
        switch(i){
            case 0: VoipID[i] = "753481633524482069";
            case 1: VoipID[i] = "786729697349861376";
            case 2: VoipID[i] = "786729734007685120";
            case 3: VoipID[i] = "786729760666419200";
        }
    }
    return 1;
}

// ========================================== Informações do Jogador ==================================== //
enum JogadorInfo
{
    Nome[30],
    Senha[70],
    Salt[12],
    SenhaAdmin[70],
    SaltAdmin[12],
    Email[70],
    Discord[70],
    Profissao[70],
    Codigo[70],
    uIp[20],
    Admin,
    TempAdmin,
    Level,
    Experiencia,
    TempoUp,
    Registro,
    Dinheiro,
    DinheiroBanco,
    DinheiroSujo,
    TagPersonalizada,
    Cartao,
    Coins,
    Skin,
    Sexo,
    Luta,
    Vip,
    Avisos,
    uLogin,
    Estrelas,
    Doenca,
    Prisoes,
    CorVIP,
    PandoraCaixa,
    PlanoDeSaude,
    PorteDeArmas,
    bool:MobileAcesso,
    Vacina,
    BaseID,
    KitReparos,
    KitMedico,
    Raspberry,
    Cilindro,
    SementeFazenda,

    //Temp
    bool:ContaAntiga,

    //Arena Feed
    VitimasArena,
    MortesArena,

    //Base Feed
    VitimasBase,
    MortesBase,

    //Utilitarios
        //Celular
    bool:Celular,
    Creditos,
    
        //Outros
    bool:MP4,
    bool:Gps,
    bool:RelogioUP,
    bool:GalaoGasolina,
    GasolinaGalao,
    GasJetpack,
    Mochila,
    VicioEstilo,
    Casado[30],

    //Saúde
    Float:Fome,
    Float:Sede,
    Float:Saude,
    Float:Sono,
    Float:Vicio,

    // Tempo - Conta
    Mutado,
    MutadoVoip,

    //Carteiras
    CarteiraA,
    CarteiraB,
    CarteiraC,
    CarteiraD,
    CarteiraE,

    MultaA,
    MultaB,
    MultaC,
    MultaD,
    MultaE,

    //Informações
    bool:Logado,
    bool:Contratado,
    bool:BlockChatVip,
    bool:Trabalhando,
    SkinProfissao,
    uInterior,
    // AltTab,
    bool:AntiEsc,
    Salario,
    bool:PodeRadar,
    bool:EstadoAFK,
    CodigoAFK[90],
    bool:SemStatus,
    uVeiculo,

    //Posições
    Float:PosicaoX,
    Float:PosicaoY,
    Float:PosicaoZ,
    Float:PosicaoA,
    bool:EncomendasPlayer,

    //Cadeia
    Preso, 
    CadeiaEstilo, 
    MotivoCadeia[30],
    AdminName[30],

    //Drogas
    Sementes,  
    Adubos, 
    Sacos, 
    Agua, 
    Vasos,
    Drogas,
    LockPick,
    Dinamites, 
    Maconha,
    Crack,
    Cocaina,
    Lsd,
    Capsulas,
    Pecas,

    //Anti Preso em Interior
    uInteriorEx,
    Float:uInteriorExP[4],

    //Celular
    Operadora,
    pNumero

};

enum SmsBlock
{
    bool:BloqueadoSms
};

new JogadorSms[MAX_PLAYERS][MAX_PLAYERS][SmsBlock];
new Jogador[MAX_PLAYERS][JogadorInfo];
// ======================================================================================================= //





// =================================================== AGENDA ============================================ //

enum AgendaTelefonica
{
    bool:aUsada,
    aNumero,
    aNome[30],
    Contato[30]
};

new pAgenda[MAX_PLAYERS][MAX_NUMEROS][AgendaTelefonica];

// ======================================================================================================= //





// =================================================== TEMPOS ============================================ //
enum JogadorDelay
{
    TrocaProfissao,
    RoubarCaixa,
    RoubarJogador,
    RoubarCarroForte,
    TransferirMao,
    TransferirBanco,
    TransferirCoins,
    TrocarLuta,
    AbrirDenuncia,
    TransferirCelular,
    TrabalharFabrica,
    Homembomba,
    ExplosaoBomba, 
    UsoApoio,
    FabricaProduc,

    // Olx
    AnunciarOlx,
    AnunciarRadio,

    // Hobbies
    HobbieProdutor
};

new pTempo[MAX_PLAYERS][JogadorDelay];


// ======================================================================================================= //




// ==================================================== CASA ============================================= //
enum MoradorInfo
{
    bool:TemMorador,
    bool:Aluguel,
    AluguelValor,
    Morador[30]
};

enum CasasInfo
{
    Numero,
    bool:Colocado,
    cDono[30],
    cTranca,
    cSenha[30],
    cPreco,
    cCoins,
    cJPreco,
    cReforma,
    Impostos,
    LixoF,
    LixoD,
    cInterior,
    cInteriorMax,
    bool:cBloqueada,
    cMensagem[35],
    Float:cPosicaoX,
    Float:cPosicaoY, 
    Float:cPosicaoZ,
    Float:cPosicaoA,
    PortaArrombada,

    //Informações
    Text3D:cTexto,
    cMapa,
    cPickup,
    LixoOb
};
 
new Apartamentos[] =
{
    816, 814, 818, 817, 822, 820, 826, 824, 829, 827, 832, 831, 834, 833, 836, 835, 828, 830, 823, 825, 819, 821, 815, 1086
};

new pCasa[MAX_CASAS][CasasInfo];
new pMorador[MAX_CASAS][MAX_MORADOR][MoradorInfo];


// ======================================================================================================= //








// ================================================== Empresa ============================================ //
enum AdminEmpresa
{
    EmpEscolheu[50],
    eValorEsc,
    IntID,
    Float:eAPos[4],
    bool:eConfimacao
}; 

enum FuncionarioInfo
{
    // Modo Geral
    bool:TemFunc,
    Funcionario[30],
    Contratacao,
    CargoEmpresa,


    // Empresa Modo
    bool:BaysideEntrega,
    Entregas,
    BonusValor,
    BonusFazer,
    BonusEntrega,
    UltimaEntrega,

    // Fábrica Modo
    ProdFabrica
};

enum EmpresaInfo
{
    eNumero,
    bool:Colocado,
    eDono[30],
    eCofre,
    eEntregasG,
    eProducao,  
    eConsumo,
    eEntregasValor,
    eEmpresa[30],
    eMensagem[40],
    eInterior,
    ePreco,
    eJPreco,
    eImpostos,
    eFabricacao,
    eConcluidas,
    eMateriaPrima,
    eCaixasFabrica,
    eEstoque,
    bool:eBloqueada,
    Float:ePosicaoX,
    Float:ePosicaoY,
    Float:ePosicaoZ,
    Float:ePosicaoA,

    // Veículo
    Float:eVposX,
    Float:eVposY,
    Float:eVposZ,
    Float:eVposA,

    //Picks
    ePickup,
    eMapa,
    Text3D:eTexto
};


new pFuncionario[MAX_EMPRESAS][MAX_FUNCIONARIOS][FuncionarioInfo];
new pFuncionarioFab[MAX_FABRICAS][MAX_FUNCIONARIOSFAB][FuncionarioInfo];
new pEmpresa[MAX_EMPRESAS][EmpresaInfo];
new pEADM[MAX_PLAYERS][AdminEmpresa];

// Fab
enum FabricaInfo
{
    bool:Colocado,
    fDono[30],
    Float:fPosicaoX,
    Float:fPosicaoY,
    Float:fPosicaoZ,
    FabricaTipo,
    FabricaPreco,
    FabricaImposto,
    FabricaProducao,
    FabricaCofre,

    // Informações
    LiquidoTonel,
    ReparoTonel,

    // Fábrica
    LiquidosInfo,
    ReparoInfo,
    FabricaIDInfo,

    // Infos
    fMapa,
    fPick,
    Text3D:FabricaTexto
};
new pFabrica[MAX_FABRICAS][FabricaInfo];
new pFabricaObjeto[MAX_FABRICAS][269]; 
new Text3D:pFabricaTexto[MAX_FABRICAS][8];
new pFabricaBot[MAX_FABRICAS][2];

// ======================================================================================================= //











// ======================================= Informações da Concessionaria ================================= //


enum ConcessionariaInfo{
    bool:Colocado,

    // Int
    ImpostosConce,
    EstoqueConce,
    VendasConce,
    TypeConce,
    PrecoConce,
    CofreConce,
    ModoConce,
    TimerConce,

    // Stings
    ConceDono[30],
    ConceMsg[128],

    // Float
    Float:ConceX,
    Float:ConceY,
    Float:ConceZ,
    //
    Float:vConceX,
    Float:vConceY,
    Float:vConceZ,
    Float:vConceA,

    // Informações
    Text3D:ConceTexto,
    ConceIcone,
    ConcePick
};

enum ConcessionariaVeh{
    bool:SpecColocado,
    bool:SpecDb,
    SpecVehIndex,
    SpecVehID,
    SpecStatus,
    SpecTimer,
    Text3D:SpecText,
    SpecPick,
    Float:SpecVehX,
    Float:SpecVehY,
    Float:SpecVehZ,
    Float:SpecVehA
};

new vConcessionaria[MAX_CONCESSIONARIA][MAX_CONCESSIONARIA_VEH][ConcessionariaVeh]; 
new Concessionaria[MAX_CONCESSIONARIA][ConcessionariaInfo];


// ======================================================================================================= //








// ========================================== Informações do Veiculo ==================================== //

enum PlayerVeiculoInfo
{
    MeuVeiculoModelo,
    Tranca,
    MeuVeiculoID,
    Cor1Veh,
    Cor2Veh,
    Preco,

    Apreendido[90],
    Placa[12],

    Float:GasolinaEx,
    Float:KilometrosEx,
    bool:VehConectado,
    bool:TemTranca,
    bool:TemSom,
    bool:VeiculoUber,
    bool:PortaMalas,
    Float:vVida,
    Float:vPosX,
    Float:vPosY,
    Float:vPosZ,
    Float:vPosA,
    
    // Prisão
    Patio,

    Text3D:PortaMalasText
};

enum TuningVehh
{
    TalentoID
};

new pVeiculo[MAX_PLAYERS][MAX_SLOT_VEH][PlayerVeiculoInfo];
new pTunagem[MAX_PLAYERS][MAX_SLOT_VEH][18][TuningVehh];


// ====================================================================================================== //








// =============================================== ACESSORIOS =========================================== //
enum AcessoriosJogador
{
    bool:Ativado,
    ADono[30],
    AcessorioNome[20],
    AcessorioObj,
    Bone,
    IndexAcessorio,
    CorIndex, 

    Float:AOffsetX,
    Float:AOffsetY,
    Float:AOffsetZ,

    Float:ARotX,
    Float:ARotY,
    Float:ARotZ,

    Float:AScaleX,
    Float:AScaleY,
    Float:AScaleZ
};
new pAcessorio[MAX_PLAYERS][MAX_ACESSORIOSINV][AcessoriosJogador];

// ====================================================================================================== //








// ================================================== Admin ============================================== //
enum AdminInfo
{
    CarroAdmin,
    bool:Camuflado,
    bool:LogadoAdm,
    bool:ModoGhost,
    bool:AntiNotificacao,
    bool:FalsoPlayer,
    bool:SemCorAdm,
    EspiandoProf[60],

    //Tela o Jogador
    bool:Espiando,
    EspiandoID,
    Float:aPos[4],
    InteriorADM,
    VirtualWorldADM,
    AntigoState,

    //Visualzar comandos
    bool:VerComandos,
    bool:VerTelegram,
    bool:VerLigacoes,
    VerCID,

    //Timers
    UpdateAdmin,
    bool:AdminUp

};
new pAdmin[MAX_PLAYERS][AdminInfo];
// ======================================================================================================= //



/////// ========================================== Anti Cheater ========================================== //////
enum AntiCheatsInfo
{
    Float:Suspeito[4], //Pegar Posição do Jogador no Anti CarFuncs (Desnecesario)
    Float:Carro[4], //Pegar Posição do Carro no Anti CarFuncs
    Float:VidaOldA, //Pegar Vida Antiga para anti respawn veículos
    Float:Vida, //Pegar Vida do Veiculo no Anti CarFuncs
    Velocidade, //Anti Speed Hack
    bool:AntiFlood, //Proteção Contra Flood em algumas funções
    VeiculoPermitido, //Anti Vehicle Teleport
    VerificaoPRB, //Anti Vehicle Air
    bool:SkinVerificao, //Anti Skin Changer
    bool:Morreu, //Anti KillFeed
    fKill, //Anti FakeKill
    EstadoDaTranca, //Anti Fake Kick do Anti Roubo
    SpeedHackVeh, //Anti Speed
    AntigoSpeed, //AntiNoClip Pedestre
    AntigoSpeedVeh, //AntiNoClip Veiculo
    bool:Travado, //Anti Nop Controlable
    Float:AntigoAnglePed, //AntiNoClip Angle
    Float:AntigoAngleVeh, //AntiNoClip Angle

    //Anti Interior Cheat
    InteriorSec,
    bool:InteriorChanger, 
    bool:InteriorBloqueioEx,
    bool:SpawnadoAntiFd, // Verificação de Spawn

    //RapidFire
    fTiros, 
    tTiros,

    //Anti PaintJob
    bool:Pintando,

    //Status
    bool:MorreuStatus,

    //Anti Teleporte
    Float:tPos[3],
    Float:hPos[3],
    Float:aPos[3],
    bool:tTeleporte,
    TempoTeleporte,
    TpTempo,

    EnviarMensagem //Delay para o anti cheater enviar mensagem
    
};

enum iI{ //Anti Mass Connection
    IncomingIP[16],
    IncomingVezes,
    IncomingTempo
};

enum ConfigAntiCheater{ //Configuração
    bool:Entrou
};

enum Timers  //Timers
{
    tFly,
    tCheck,
    tTP,
    tRoubo,
    tDebug,
    bool:Aguardando
};

enum DetecatacaoInfos
{
    HoraDD,
    DetectID,
    TipoDD,
    DetectName[30],
    MotivoDD[30]
};

new IncomingConnection[iI];
new cAC[MAX_PLAYERS][AntiCheatsInfo];
new aConfig[MAX_PLAYERS][ConfigAntiCheater];
new tConfig[MAX_PLAYERS][Timers];

new dACT;
new dAC[10][DetecatacaoInfos];

// ======================================================================================================= //






// ============================================ Veiculos - Profs ========================================= //

enum VeiculosCriadosSv
{
    VeiculoIDExx,
    bool:VeiculoOn,
    Cor1VeiculoEx,
    Cor2VeiculoEx,
    Dono,
    Dono2,
    Tranca,
    vInterior,
    vVirtual,

    Float:Kilometros,
    Float:Gasolina,
    Float:VidaMaxima,

    Float:PosicaoCarX,
    Float:PosicaoCarZ,
    Float:PosicaoCarY, 
    Float:PosicaoCarA,

    bool:VeiculoRegenerar,
    bool:VeiculoPublico,
    bool:vQuebrado, // Se tiver sem gasolina ou quebrado
    bool:AntiRadar,
    bool:AntiFurar, // Anti Furar Pneu

    PlacaEx[12],
    ApreendidoEx[30], 
    LocalVerificacao[128]
};

new VeiculoServer[MAX_VEHICLES][VeiculosCriadosSv];

// ======================================================================================================= //






// =============================================== Jogador =============================================== //
enum ConfigJogador
{
    bool:Set,
    bool:Morreu,
    bool:VeloHab,

    //Timers
    TagUsuario,
    UpdateJogador,
    TimerRapido,
    NatalNeve
};

enum ConfigVeiculo
{
    bool:SetVeh,
    UpdateVeiculo,
    Float:hKm[3],
    KmA,
    KmD,
    GaA // JetPack Gás
}; 

new vDados[MAX_PLAYERS][ConfigVeiculo];
new cDados[MAX_PLAYERS][ConfigJogador];
// ======================================================================================================= //



// ================================================ Agencia ============================================== //

enum AgenciaJogador
{
    Selecionado[70], //Honestas etc.
    bool:Pegou,
    LocalMapa,
    Text3D:MensagemEmprego,
    Pickup, 
    ComandoAG, // == 1 Agencia / == 2 Crime
    EmpregoID //Emprego para achar no size / for
};

enum AgenciaDeEmpregosInfo
{
    ProfID,
    ProfissaoNome[30],
    Categoria[20],
    Level,
    Salario,
    Disponivel,
    Float:HQx,
    Float:HQy,
    Float:HQz,
    CorProfissao[10],
    ProfissaoPreset[90],
    ProfissaoRemove[90]
};

new pAgencia[][AgenciaDeEmpregosInfo] =
{
    //Honestas
    {8, "Uber Eats", "Honestas", 0, 450, 1, 793.7515, -1625.1282, 13.3828, 0x8cf04aFF, "*", "*"},
    {12, "Pizza Delivery", "Honestas", 1, 470, 1, 206.7064,-182.8804,1.5781, 0xDAA520FF, "*", "*"},
    {29, "Açougueiro", "Honestas", 5, 350, 1, 1214.1790, 188.7298, 20.3013, 0xD2691EFF, "*", "*"},
    {13, "Lenhador", "Honestas", 10, 400, 1, -379.0767,-1417.3885,25.7438, 0x805429FF, "*", "*"},
    {24, "Fruteiro", "Honestas", 15, 450, 1, -117.9679,91.7869,3.1172, 0x339933FF, "*", "*"},
    {30, "Perícia", "Honestas", 20, 500, 1, -2446.3743,527.4733,30.2091, 0xDCDCDCFF, "*", "*"}, 
    {1, "Gari", "Honestas", 25, 650, 1, 2096.4504,-2077.9224,13.5469, 0xd17717FF, "*", "*"},
    {16, "Ourives", "Honestas", 30, 700, 1, 816.6512, 856.9218, 12.7891, 0xFFD700FF, "*", "*"},
    {37, "Leiteiro", "Honestas", 35, 750, 1, -23.8381,66.6037,3.1172, 0xDCDCDCFF, "*", "*"},
    {15, "Vendedor de Rua", "Honestas", 40, 800, 1, 2481.5059,-1536.7554,24.1071, 0xcc7229FF, "*", "*"},
    {40, "Fazendeiro", "Honestas", 45, 850, 1, -103.7864,-15.1605,3.1094, 0xF4A460FF, "*", "*"},
    {9, "Mecânico", "Honestas", 50, 900, 1, 326.1163, -57.3819, 1.5358, 0x228B22FF, "*", "*"},
    {24, "Meteorologista", "Honestas", 60, 1000, 1, -2529.3794,-623.4029,132.7526, 0x7FFF00FF, "*", "*"},
    {33, "Eletricista", "Honestas", 70, 1100, 1, 1352.0984,348.4387,20.5009, 0x8FBC8FFF, "*", "*"},
    {36, "Mergulhador", "Honestas", 75, 1200, 1, 2750.0815,-2555.1885,13.6427, 0x858073FF, "*", "*"},
    {14, "Advogado", "Honestas", 80, 1300, 1, 1547.2533, -1270.1443, 17.4063, 0x4B0082FF, "*", "*"},
    {15, "Paramédico", "Honestas", 110, 1400, 1, -2641.1509, 635.9762, 14.4531, 0x00FA9AFF, "*", "*"}, 
    

    //Transportes
    //{2, "Uber", "Transportes", 10, 500, 1, 1172.1110,1353.9791,10.9219, 0x4F4F4FFF, "*", "*"},
    {35, "Transportador de Carne", "Transportes", 15, 550, 1, 801.0743, -613.1609, 16.3359, 0xD2B48CFF, "*", "*"},
    {3, "Motorista de Ônibus", "Transportes", 20, 600, 1, 1580.9113, 707.4812, 10.7000, 0x32CD32FF, "*", "*"},
    {12, "Transportador", "Transportes", 30, 650, 1, 2184.7036, -2251.4204, 14.7700, 0x3CB371FF, "*", "*"},
    {38, "Transportador de Concreto", "Transportes", 35, 665, 1, 631.7957, 897.0770, -42.7988, 0x778899FF, "*", "*"},
    {23, "Petroleiro", "Transportes", 40, 700, 0, -1096.5348, -713.0133, 32.0078, 0xC0C0C0FF, "*", "*"},
    {39, "Transportador de Eletrônicos", "Transportes", 50, 800, 1, 2695.9961, -2488.1963, 13.6505, 0x008000FF, "*", "*"},
    {26, "Maquinista", "Transportes", 50, 750, 1, 1746.6066, -1944.2023, 13.5675, 0xA0522DFF, "*", "*"}, 
    {28, "Entregador de Móveis", "Transportes", 60, 800, 1, -1711.7583, 1003.0759, 17.9141, 0xBDB76BFF, "*", "*"},
    {27, "Piloto", "Transportes", 65, 950, 1, 1925.5909,-2640.6143,13.5469, 0x4682B4FF, "*", "*"},
    {12, "Motorista de Carro Forte", "Transportes", 100, 1100, 1, 1093.6857, 1938.9519, 10.8130, 0xA9A9A9FF, "*", "*"},


    //Governo
    {21, "Corregedoria", "Governo", 1100, 3500, 1, 1738.6523, -1269.7811, 13.5433, 0x7289adFF, "*", "*"},
    {25, "Exército", "Governo", 1400, 3000, 0, 287.6622, 1969.8844, 17.6406, 0x808000FF, "*", "*"},
    {32, "Marinha", "Governo", 1450, 3700, 0, -1338.7968,489.3310,11.1953, 0x000080FF, "*", "*"},
    {31, "Aeronáutica", "Governo", 1500, 4000, 0, -1338.7968,489.3310,11.1953, 0x6B8E23FF, "*", "*"},


    //Servidor Público
    {5, "Policial Militar", "Serviços Publicos", 100, 1200, 1, 1575.7035, -1633.4850, 13.5578, 0x3492ebFF, "*", "*"},
    {22, "Força Tática", "Serviços Publicos", 200, 1400, 0, 1575.7035, -1633.4850, 13.5578, 0x4359e8FF, "*", "*"},
    {17, "Bombeiro", "Serviços Publicos", 250, 2100, 1, 1736.1858, 2106.6965, 12.2891, 0xdb531dFF, "*", "*"},


    // Mafia
    {10, "Plantador de Maconha", "Mafia", 10, 0, 1, -1103.5625,-1218.6946,129.2188, 0xFF6347FF, "*", "*"},
    {11, "Ladrão de Veículos", "Mafia", 15, 0, 1, -2807.2253, -1531.0927, 139.2891, 0x800000FF, "PrepararLadraoVeh", "RemoverLadraoVeh"},
    //{36, "Produtor da Máfia", "Mafia", 40, 0, 1, -2148.6252,-242.3781,36.5156, 0x9c0b0bFF, "*", "*"},
    //{20, "Assaltante", "Mafia", 300, 0, 1, -2817.0503,-1531.4276,139.2891, 0xff2617FF, "*", "*"},
    {19, "Assassino", "Mafia", 400, 0, 1, -2817.0503,-1531.4276,139.2891, 0xf02626FF, "*", "*"}, 
    {18, "Terrorista", "Mafia", 900, 0, 1, -2817.0503,-1531.4276,139.2891, 0xba0909FF, "*", "*"} 
};

new Agencia[MAX_PLAYERS][AgenciaJogador];


// ======================================================================================================= //







// ============================================ Locais Publicos ========================================== //

enum PickupsItens
{
    LocalID,
    MapIcon,
    PickupIcon,
    Float:EntradaX,
    Float:EntradaY,
    Float:EntradaZ,
    Float:SaidaX,
    Float:SaidaY,
    Float:SaidaZ,
    MensagemPickup[50],
    Interior,
    VirtualWorld,
    RegiaoGPS[50],
    CheckPoint
};

new Pick[][PickupsItens] =
{
    //Hospital 
    {1, 22, 1240, 1172.8807,-1323.6239, 15.3994, 1028.0850,61.8398,1000.4591, "Hospital", 3, 1299, "Los Santos"},  // Porta Hospital Central de LS
    {2, 22, 1240, 2035.8093,-1404.2039, 17.2653, 1028.0850,61.8398,1000.4591, "Hospital", 3, 1299, "Los Santos"},  // Porta Hospital de LS GROVE
    {3, 22, 1240, 1607.5264,1816.0905, 10.8203, 1028.0850,61.8398,1000.4591, "Hospital", 3, 1299, "Las Venturas"},   // Hospital Normal perto da Avenidada LV
    {4, 22, 1240, -2664.9656,638.9591, 14.4531, 1028.0850,61.8398,1000.4591, "Hospital", 3, 1299, "San Fierro"},   // Hospital SF CENTRAL
    {5, 22, 1240, -320.2877,1049.3739, 20.3403, 1028.0850,61.8398,1000.4591, "Hospital", 3, 1299, "Las Venturas"},   // Hospital FortCarson
    {6, 22, 1240, -1514.7906,2521.0884, 55.8670, 1028.0850,61.8398,1000.4591, "Hospital", 3, 1299, "Las Venturas"},  // Hospital TierraRobada
    {7, 22, 1240, -2208.8765,-2287.5933, 30.6250, 1028.0850,61.8398,1000.4591, "Hospital", 3, 1299, "San Fierro"}, // Hospital ANGEL PINE
    {8, 22, 1240, 1244.1959,332.2817, 19.5547, 1028.0850,61.8398,1000.4591, "Hospital", 3, 1299, "Los Santos"},    // Mont

    //Departamento de Polícia
    {9, 30, 1247, -2161.8408,-2385.4343,30.6250, 246.7292,62.9664,1003.6406, "Departamento de Polícia", 6, 1300, "San Fierro"}, // Angel Pine
    {10, 30, 1247, -1390.0569,2638.2708,55.9844, 246.7292,62.9664,1003.6406, "Departamento de Polícia", 6, 1300, "Las Venturas"},  // El quebrados
    {11, 30, 1247, 1554.9633,-1675.6489,16.1953, 246.7292,62.9664,1003.6406, "Departamento de Polícia", 6, 1300, "Los Santos"},  // Los Santos
    {12, 30, 1247, 2290.0571,2431.0540,10.8203, 246.7292,62.9664,1003.6406, "Departamento de Polícia", 6, 1300, "Las Venturas"},   // Las Venturas
    {13, 30, 1247, -1605.5205,710.7170,13.8672, 246.7292,62.9664,1003.6406, "Departamento de Polícia", 6, 1300, "San Fierro"},   // San Fierro
    {14, 30, 1247, -217.8340,979.1722,19.5040, 246.7292,62.9664,1003.6406, "Departamento de Polícia", 6, 1300, "Las Venturas"},  // Fort Carson
    {15, 30, 1247, 627.5583,-571.7900,17.6525, 246.7292,62.9664,1003.6406, "Departamento de Polícia", 6, 1300, "Los Santos"},  // BluerBratyy

    //Concessionarias
    /*{999, 0, 0, 532.6002, -1292.5789, 17.2422, 0.0, 0.0, 0.0, "Concessionaria Terreste", 0, 0000, "Los Santos"}, //Concessionaria de Los Santos
    {999, 0, 0, 2131.8818, -1150.4889, 24.1525, 0.0, 0.0, 0.0, "Concessionaria Terreste", 0, 0000, "Los Santos"}, //Concessionaria de Los Santos
    {999, 0, 0, -1657.9063, 1210.6770, 7.2500, 0.0, 0.0, 0.0, "Concessionaria Terreste", 0, 0000, "San Fierro"}, //Concessionaria de San Fierro
    {999, 0, 0, -1966.3468, 293.8265, 35.4688, 0.0, 0.0, 0.0, "Concessionaria Terreste", 0, 0000, "San Fierro"}, //Concessionaria de San Fierro
    {999, 0, 0, 1948.4673, 2068.8025, 11.0610, 0.0, 0.0, 0.0, "Concessionaria Terreste", 0, 0000, "Las Venturas"}, //Concessionaria de Las Venturas
    {999, 0, 0, 2200.8113, 1394.2528, 11.0625, 0.0, 0.0, 0.0, "Concessionaria Terreste", 0, 0000, "Las Venturas"}, //Concessionaria de Las Venturas
    {999, 0, 0, -1262.8848, 40.7986, 14.1391, 0.0, 0.0, 0.0, "Concessionaria Aérea", 0, 0000, "San Fierro"}, //Concessionaria de San Fierro Aerea*/

    //Detran
    {16, 24, 1239, 1685.1655,-1343.3431,17.4346, 404.9329,320.8669,1005.8495, "Detran", 4, 1301, "Los Santos"}, // Detran LS
    {29, 24, 1239, -1492.7238,920.0656,7.1875, 404.9329,320.8669,1005.8495, "Detran", 4, 1301, "San Fierro"}, // Detran San Fierro
    {30, 24, 1239, 2183.6807,2295.4919,10.8203, 404.9329,320.8669,1005.8495, "Detran", 4, 1301, "Las Venturas"}, // Detran Las Venturas
 
    //Agencia de Empregos
    //{17, 23, 1314, 1153.9882,-1772.1722,16.5992, 389.3434,173.7952,1008.3828, "Agência de Empregos", 3, 1302, "Los Santos"}, // Agencia de Empregos Los Santos
    {17, 23, 1314, 1209.2472,-1752.2314,13.5936, 389.3434,173.7952,1008.3828, "Agência de Empregos", 3, 1302, "Los Santos"}, // Agencia de Empregos Los Santos
    {18, 23, 1314, 2364.1155,2377.5986,10.8203, 389.3434,173.7952,1008.3828, "Agência de Empregos", 3, 1302, "Las Venturas"}, // Agencia de Empregos Las Venturas
    //{19, 23, 1314, -2171.3850,252.0984,35.3368, 389.3434,173.7952,1008.3828, "Agência de Empregos", 3, 1302, "San Fierro"}, // Agencia de Empregos San Fierro
    {19, 23, 1314, -1988.7341,1039.4275,55.7266, 389.3434,173.7952,1008.3828, "Agência de Empregos", 3, 1302, "San Fierro"}, // Agencia de Empregos San Fierro
    
    //Prefeitura
    {20, 42, 1239, 1493.5272,-1766.9049,13.5469, -51.3711,-1.6534,1003.3881, "Prefeitura", 3, 1303, "Los Santos"}, // Prefeitura Los Santos
    {21, 42, 1239, 2445.7109,2376.3018,12.1635, -51.3711,-1.6534,1003.3881, "Prefeitura", 3, 1303, "Las Venturas"}, // Prefeitura Las Venturas
    {22, 42, 1239, -2764.7466,375.4982,6.3422, -51.3711,-1.6534,1003.3881, "Prefeitura", 3, 1303, "San Fierro"}, // Prefeitura San Fierro

    //Banco
    // Antigo LS: 593.5710,-1249.7272,18.2158
    {23, 52, 1274, 1778.4766,-1663.2407,14.4367, 2613.2021,-1707.2418,1016.5886, "Banco", 1, 1064, "Los Santos"}, //Banco de Los Santos
    {24, 52, 1274, 2388.8396,2466.0107,10.8203, 2613.2021,-1707.2418,1016.5886, "Banco", 1, 1064, "Las Venturas"}, //Banco de Las Venturas
    {31, 52, 1274, -179.6006,1133.1871,19.7422, 2613.2021,-1707.2418,1016.5886, "Banco", 1, 1064, "Las Venturas"}, //Banco de Las Venturas [FC]
    {25, 52, 1274, -2649.1685,376.0640,6.1593, 2613.2021,-1707.2418,1016.5886, "Banco", 1, 1064, "San Fierro"}, //Banco de San Fierro

    //Auto Escola
    {26, 53, 1238, 1518.9653,-1453.1774,14.2059, 714.9142,-590.0194,-24.5022, "Auto Escola", 1, 1001, "Los Santos"}, //Auto Escola de Los Santos
    {27, 53, 1238, 938.0917,1733.2111,8.8516, 714.9142,-590.0194,-24.5022, "Auto Escola", 1, 1001, "Las Venturas"}, //Auto Escola de Las Venturas
    {28, 53, 1238, -1881.3190,822.9159,35.1770, 714.9142,-590.0194,-24.5022, "Auto Escola", 1, 1001, "San Fierro"}, //Auto Escola de San Fierro

    //CarMax
    //{999, 55, 1010, -2055.3425,455.6263,35.1719, 0.0, 0.0, 0.0, "CarMax", 0, 0000, "San Fierro"}, //CarMax San Fierro
    {999, 0, 0, -2434.1501,2308.9834,4.9844, 0.0, 0.0, 0.0, "Área de Encomendas", 0, 0000, "Las Venturas"}, //Encomendas LV

    //Áreas VIP
    {999, 0, 0, 1022.4569,-1121.8407,23.8717, 0.0, 0.0, 0.0, "Área VIP", 0, 0000, "Los Santos"},
    {999, 0, 0, 2015.0822,1106.4320,10.8203, 0.0, 0.0, 0.0, "Área VIP", 0, 0000, "Las Venturas"},
    {999, 0, 0, -2664.9631,-8.9631,6.1328, 0.0, 0.0, 0.0, "Área VIP", 0, 0000, "San Fierro"},

    //Aeroportos
    {999, 0, 0, 1685.9163,-2238.2937,13.5469, 0.0, 0.0, 0.0, "Aeroporto", 0, 0000, "Los Santos"},
    {999, 0, 0, 1664.4301,1471.1442,10.7813, 0.0, 0.0, 0.0, "Aeroporto", 0, 0000, "Las Venturas"},
    {999, 0, 0, -1421.6479,-287.6295,14.1484, 0.0, 0.0, 0.0, "Aeroporto", 0, 0000, "San Fierro"},

    //iRippzy
    {999, 0, 0, 561.2976,-1506.6814,14.5479, 0.0, 0.0, 0.0, "iRippzy", 0, 0000, "Los Santos"},

    //Pátio 
    {999, 0, 0, -1616.4994,678.6681,7.1875, 0.0, 0.0, 0.0, "Pátio Policial", 0, 0000, "San Fierro"},

    //Lojas de Móveis
    {999, 0, 0, -1754.1930,962.8623,24.8828, 0.0, 0.0, 0.0, "Loja de Móveis", 0, 0000, "San Fierro"},

    //Estande
    {999, 0, 0, -1942.8262,456.9880,35.1719, 0.0, 0.0, 0.0, "Escola de Tiros", 0, 0000, "San Fierro"},

    //Transferencia de Veículos
    {999, 0, 0, -1656.3829,1217.9264,7.2500, 0.0, 0.0, 0.0, "Transferência de Veículo", 0, 0000, "San Fierro"},

    //Lotéricas
    {999, 0, 0, 1544.6781,-1180.8154,24.0939, 0.0, 0.0, 0.0, "Lotérica", 0, 0000, "Los Santos"},

    //Rádios
    {999, 0, 0, -2002.6700,-1020.0964,32.1719, 0.0, 0.0, 0.0, "Rádio / Anúncios", 0, 0000, "San Fierro"},
    {999, 0, 0, 1616.1407,-1897.1450,13.5491, 0.0, 0.0, 0.0, "Rádio / Anúncios", 0, 0000, "Los Santos"},
    {999, 0, 0, 2810.9124,1987.4006,10.8203, 0.0, 0.0, 0.0, "Rádio / Anúncios", 0, 0000, "Las Venturas"}
};

// ======================================================================================================= //





// ================================================ Doenças ============================================== //

enum DoencasInfo
{
    DoencaNome[20],
    Contaminacao,
    Float:RaioTransmissao
};

new Doencas[][DoencasInfo] =
{
    {"Nenhuma Doença", -1, 0.0},
    {"Covid-19", 30, 5.0},
    {"Tuberculose", 15, 5.0},
    {"Hepatite", 10, 5.0},
    {"Febre Amarela", 25, 6.0},
    {"Sarampo", 6, 4.0},
    {"Zika Vírus", 10, 5.0},
    {"Gripe", 30, 8.0},
    {"Ébola", 25, 8.0}
};

// ======================================================================================================= //






// =============================================== Anti AFK ============================================== //

enum JogadorAFK
{
    bool:IniciouAFK,
    TempoAFK,
    TempoKickAfk,
    CodigoInformado[15],
    ErrosAFK,
    TempoFicouAw,
    Float:afkPos[3],
    CodePosEx,
    LogAFK[1500]
};

new pAFK[MAX_PLAYERS][JogadorAFK];

// ======================================================================================================= //





// ================================================ Policia ============================================== //

enum CargosPolicias
{
    CargoTexto[30]
};

enum AbordadoInfo
{
    bool:Acompanhando,
    bool:SeRendeu,
    bool:Algemado, 
    bool:Abordado,
    TempoAbordado,
    APolicial,
    PmID
}

enum PolicialInfo
{
    bool:PegouUniformePolicia,
    bool:PegouVeiculoPolicia,
    PoliciaCarroID,
    UltimoPolicia
};

new pPolicia[MAX_PLAYERS][PolicialInfo];
new pAbordado[MAX_PLAYERS][AbordadoInfo];

// Hook > Veiculo
enum PegarVeiculoPMInfo
{
    pLista,
    TempoAlugarPM,

    //Objetos
    bool:TemObjetos,
    pBarra,
    pSirene
};

new pVPolicia[MAX_PLAYERS][PegarVeiculoPMInfo];

// ======================================================================================================= //



// ============================================= Localizador ============================================= //

enum LocalizacaoInfo
{
    bool:Localizando, // Variavel para se tiver localizando
    TemporizadorLoc, // Timer do localizador
    MapIconLoc, // Icone no mapa
    PontoTempo, // Tempo para localizar novamente

    // Sistema para marcar veículo no mapa
    bool:vLocalizando,
    vCheckLoc
};

new pLocalizacao[MAX_PLAYERS][LocalizacaoInfo];

// ======================================================================================================= //





// ========================================== Motorista de Ônibus ======================================== //

enum ParadaInfo
{
	// Sistema em si
	ParadaID,
	bool:pColocado,
	ObjetoParada,
	
	// Posicao Parada
	Float:pPosX,
	Float:pPosY,
	Float:pPosZ,
	
	// Rotação
	Float:pCamX, 
	Float:pCamY,
	Float:pCamZ,

    MapIconParada,
    RangeParada //Distancia entre a rua e a parada ( Facilitar minha vida )
};

enum RotasInfo
{
	pDestino[30],
	NomeDaRota[70],
	ParadaSel,
	bool:Setando,
	bool:RotaAtiva 
};

// Sistema de Paradas / Rotas
new oRota[MAX_ROTAS][MAX_ROTASID][RotasInfo];
new oParada[MAX_PARADAS][ParadaInfo];

// ======================================================================================================= //



// ================================================= CARGOS ============================================== //

// Cargos
new CargoPM[][CargoTexto] =
{
    {"Policial Militar"},
    {"Exército"},
    {"Corregedoria"},
    {"Aeronáutica"},
    {"Marinha"}
};


new CargoMafia[][CargoTexto] =
{
    {"Plantador de Maconha"},
    {"Ladrão de Veículos"},
    {"Assassino"},
    //{"Assaltante"},
    {"Terrorista"}
    //{"Produtor da Máfia"}
};


// ======================================================================================================= //



// ================================================ ASSALTANTE =========================================== //

/*enum JogadorAssaltante
{
    RoubandoCaixa,
    Float:Expp[3],
    C4Dinamite,
    CaixaAsst,
    TempoRoubo,

    // Assalto CF
    AssaltandoCF, // Status
    AssaltandoID, // Roubo ID
    AssaltandoCFID,
    Text3D:RouboCF,
    RouboCFCP,
    RouboCFIC, 
    CFAssaltoTempo, // SetTimer
    FiAssaltoCF // Tempo do Roubo
};

new pAssaltante[MAX_PLAYERS][JogadorAssaltante];*/


// ======================================================================================================= //



// ============================================== ACESSO CÓDIGO ========================================== //

enum AcessoJogador
{
    bool:CodeTempo,
    CodeTimer,

    bool:UmaVezA,
    AcessoRestante
};

new pAcesso[MAX_PLAYERS][AcessoJogador];

// ======================================================================================================= //





// =================================================== Bases ============================================= //
enum MembroBase
{
    bool:TemMembro,
    bNome[30],
    BaseCargo,
    BaseDeposito,
    BaseEntregas
};

enum BaseVeiculo
{
    bool:VeiculoColocado,
    bool:SlotDataBase,
    VeiculoBaseID,
    VeiculoModeloBase,
    BaseCor1,
    BaseCor2,
    Float:vBaseX,
    Float:vBaseY,
    Float:vBaseZ,
    Float:vBaseA 
};

enum BaseInfo
{
    bool:BaseColocada, // Verificar se tem base
    BaseCofre,
    BaseVencimento,
    BaseStatus,
    BaseCoins,
    BaseTagCor,
    BaseCompra,
    BaseDesconto,
    BaseEntregasGeral,
    BaseAnunciar,

    // Identificações
    bool:BaseInvasao,
    bool:BaseDM,
    bool:BaseArma,
    bool:BloquearRenovacao,

    // Stings
    BaseNome[26], // MAX 24
    BaseTag[10], // MAX 9 - 2
    BaseSenha[30],

    // Posição Range
    Float:CimaX,
    Float:CimaY,
    Float:BaixoX,
    Float:BaixoY,

    // Posição Portão
    Float:BasePortaoX,
    Float:BasePortaoY,
    Float:BasePortaoZ,
    Float:BasePortaoRX,
    Float:BasePortaoRY,
    Float:BasePortaoRZ,
    bool:PortaoAberto,
    bool:TrazerPortao,
    TimerPortao,

    // Posição Base
    Float:BaseX,
    Float:BaseY,
    Float:BaseZ,
    Float:BaseA,

    // Portao Fora
    Float:BaseForaX,
    Float:BaseForaY,
    Float:BaseForaZ,

    // Identificações
    BasePortaoID,
    BaseArea,
    BaseIcone,
    BasePickup,
    Text3D:BaseTexto
};

new Base[MAX_BASES][BaseInfo]; 
new bMembro[MAX_BASES][MAX_MEMBROS][MembroBase];
new vBase[MAX_BASES][MAX_BASEVEH][BaseVeiculo];
new BaseObjeto[MAX_BASES][18];

// ======================================================================================================= //



// ================================================= Telefone ============================================ //


enum TelefonePlayer
{
    Ligando,
    LigacaoS,
    TempoLigacao,
    LigacaoTimer
};

new jTelefone[MAX_PLAYERS][TelefonePlayer];

// ======================================================================================================= //


// ================================================ Paramédico =========================================== //

/*enum JogadorParamedico
{
    AmbuID,
    Text3D:AmbuTexto,

    // Bool
    bool:PegouParaFarda,
    bool:PegouAmbu,
    bool:AmbuComTexto,
    bool:KitNaMao,

    // Rev
    RevivendoID,
    bool:Revivendo,
    TempoRevivendo
};

enum ParamedicoInfo
{
    bool:SendoUsado,
    IconeMorte
};

enum MorteInfo
{
    bool:EstaCaido,

    ParamedicoID,
    TimerMorte,
    TempoMorte,
    MorteStatus,
    Float:MoPosX,
    Float:MoPosY,
    Float:MoPosZ,
    Float:MoPosA
};*/

// new pMorreu[MAX_PLAYERS][MorteInfo];
// new pParamedico[MAX_PLAYERS][JogadorParamedico];
// new pMedico[MAX_PLAYERS][MAX_PLAYERS][ParamedicoInfo];

// ======================================================================================================= //



// =================================================== Caixa ============================================= //
enum CaixasInfo
{
    CaixaID,
    Dinheiro, 
    Float:PosicaoX,
    Float:PosicaoY,
    Float:PosicaoZ,
    Float:PosicaoRX,
    Float:PosicaoRY,
    Float:PosicaoRZ, 

    CaixaVW,
    CaixaInterior,

    // Warn
    Explodido,
    BombaCaixaID, // Mochila e Bomba
    Text3D:BombaTextoID,

    Text3D:CaixaTexto,
    CaixaObjeto,

    bool:Conectado
};

new pCaixa[MAX_CAIXAS][CaixasInfo];

// ======================================================================================================= //



// =================================================== UBER ============================================== //

enum UberJogador
{
    // Motorista
    bool:EmServico,
    UberStatus,
    UberSlot,

    // Misc
    UberID,
    Float:UberApos[3],
    UberValor,
    MapIc,
    UberTimer,

    // Passageiro
    UberChamada,
    UberStatusChamada

};
new pUber[MAX_PLAYERS][UberJogador];

// ======================================================================================================= //





// ================================================= MECÂNICO ============================================ //

enum MecanicoInfo
{
    bool:MecanicoAlugado,
    MecanicoID,
    bool:AtendendoMec,
    SoliID,
    dada,

    MapID,
    Text3D:TextID,
    TimerMec
};

enum ChamMec
{
    ChamouMecanico,
    bool:FuiAtendido,
    VeiculoReparo,
    MecID,
    MapID
};


new pMecanico[MAX_PLAYERS][MecanicoInfo];
new ChamadoMec[MAX_PLAYERS][ChamMec];
new MecQuery[MAX_PLAYERS][MAX_PLAYERS];

// ======================================================================================================= //





// ================================================== MOVEIS ============================================= //
enum MoveisInfo
{
    bool:cAtivado,
    cMovelID,
    cStatus,
    cMovelObjeto,
    cmPreco,
    cmPrecoCoins,
    cMovelNome[30],
    Float:MovelX,
    Float:MovelY,
    Float:MovelZ,
    Float:MovelRx,
    Float:MovelRy,
    Float:MovelRz
};

enum MoveisEntregaInfo
{
    bool:JaLevando,
    MovelStatusPlayer,
    MoveisQuantidade
};

new cMovel[MAX_CASAS][MAX_MOVEIS][MoveisInfo]; 
new eMoveis[MAX_CASAS][MoveisEntregaInfo];


// ======================================================================================================= //