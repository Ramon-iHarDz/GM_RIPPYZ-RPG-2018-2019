#include <YSI_Coding\y_hooks>

enum PosicaoUber
{
    Float:UberPosX,
    Float:UberPosY,
    Float:UberPosZ,
    Float:UberPosA
};

new UberPosVeh[][PosicaoUber] =
{
    {2285.0281,2038.6969,10.7028,90.4815}, //Posicao 1
    {2284.8137,2042.5123,10.7028,90.4123}, //Posicao 2
    {2284.7334,2046.4103,10.7028,90.5384}, //Posicao 3
    {2284.9399,2050.2246,10.7028,90.5106}, //Posicao 4
    {2296.4697,2050.2893,10.7047,269.8872}, //Posicao 5
    {2296.9070,2046.3923,10.7028,270.6228}, //Posicao 6
    {2296.8042,2042.5260,10.7028,270.0674}, //Posicao 7
    {2297.0044,2038.6975,10.7028,270.7911} //Posicao 8 
};

hook OnPlayerDisconnect(playerid, reason)
{
    // Passageiro
    if(pUber[playerid][StatusChamado] > 0)
    {
        new id = pUber[playerid][UberID],
            Mensagem[128]
        ;
        KillTimer(pUber[id][UberTemporizador]);
        DestroyDynamicMapIconEx(pUber[playerid][UberIcone]);
        DestroyDynamicMapIconEx(pUber[id][UberIcone]);
        pUber[id][UberAtendeu] = false;
        format(Mensagem, sizeof(Mensagem), "| AVISO | Seu passageiro %s desconectou-se", PegarNick(playerid));
        SendClientMessage(id, 0xFF4500FF, Mensagem);

        if(pUber[playerid][StatusChamado] == 2)
        {
            OcultarUber(id);
            Jogador[id][Dinheiro] += pUber[id][UberValor];
            Jogador[playerid][Dinheiro] -= pUber[id][UberValor];
            format(Mensagem, sizeof(Mensagem), "| AVISO | Você recebeu $%s pela corrida", DinheiroSeparar(pUber[id][UberValor]));
            SendClientMessage(id, 0xFF4500FF, Mensagem);  
        }

    }

    // Motorista
    if(pUber[playerid][UberAtendeu] == true)
    {
        new id = pUber[playerid][PassageiroID],
            Mensagem[128]
        ;
        KillTimer(pUber[playerid][UberTemporizador]);

        if(pUber[playerid][StatusChamado] == 1)
        {
            DestroyDynamicMapIconEx(pUber[playerid][UberIcone]);
            DestroyDynamicMapIconEx(pUber[id][UberIcone]);
        }

        pUber[id][StatusChamado] = 0;
        format(Mensagem, sizeof(Mensagem), "| AVISO | Seu motorista %s desconectou-se", PegarNick(playerid));
        SendClientMessage(id, 0xFF4500FF, Mensagem);    
    }

    if(pUber[playerid][UberPegouVeiculo] == true) DestroyVehicleEx(pUber[playerid][UberVeiculo]);

    new sadas[UberJogador];
    pUber[playerid] = sadas;

    return 1;
}