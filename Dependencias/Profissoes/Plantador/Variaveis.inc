enum PlantadorInfo
{
    // Verificações
    bool:Plantado,
    bool:UsouAdubo, // Evitar que o uso do adubo duas vezes

    // Processos
    ProgressoPlantio, // Progresso do crescimento
    AbudoUsado, // Quantidades de vezes do adubo
    TempoPerca, // Tempo para perder se não colher
    ProximaRegada, // Definir próxima regada
    AguaPrecisa, // Precisa de Água
    bool:AnularReg,
    bool:ColheuEntrega,

    PlantioTempo, // Tempo
    Text3D:TextoPlantio, // Texto 
    IconePlantio, // Icone
    PlantaObj, // Planta Objeto

    Float:PlantioX,
    Float:PlantioY,
    Float:PlantioZ
};

new Plantador[MAX_PLAYERS][10][PlantadorInfo];
new MensagemArea;