#include <YSI_Coding\y_hooks>

enum NpcMafiaInfo
{
    Float:nMafiaX,
    Float:nMafiaY,
    Float:nMafiaZ,
    Float:nMafiaA,
    nCheckMafia
};

new NpcMafia[][NpcMafiaInfo] =
{
    {2662.7861,-1106.4414,69.4359,225.7847},
    {1337.7528,203.9930,19.5547,202.7350},
    // {-1825.3180,-149.2787,9.3984,216.2979},
    // {-2208.1514,711.9216,49.4166,322.9955},
    {650.8036,-510.9296,16.3359,51.0952},
    {2746.8557,-2018.7314,13.5547,0.5899},
    {-2623.1060,2242.7185,4.9844,247.3879},
    {-662.5264,2307.0759,136.1190,173.2265},
    {2302.6848,1867.3281,10.8203,359.0734}
};
new nMafia[sizeof(NpcMafia)][NpcMafiaInfo];

hook OnGameModeInit()
{
    new Float:Sentad[2],id;
    for(new i=0; i < sizeof(NpcMafia); i++)
    {
        id = CreateDynamicActor(28, NpcMafia[i][nMafiaX], NpcMafia[i][nMafiaY], NpcMafia[i][nMafiaZ], NpcMafia[i][nMafiaA], 1, 100.0, 0, 0, -1, 90.0, -1, 0);
        ApplyDynamicActorAnimation(id,"DEALER","DEALER_IDLE",4.0,1,0,0,0,0);
        Sentad[0] = NpcMafia[i][nMafiaX];
        Sentad[1] = NpcMafia[i][nMafiaY];
        GetXY(Sentad[0], Sentad[1], NpcMafia[i][nMafiaA], -1.0, 0.0);
        nMafia[i][nCheckMafia] = CreateDynamicCP(Sentad[0], Sentad[1], NpcMafia[i][nMafiaZ], 1.0, 0, 0, -1, 10.0, -1);
    }
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid)
{
    for(new i=0; i < sizeof(NpcMafia); i++)
    {
        if(checkpointid != nMafia[i][nCheckMafia]) continue; 
        new Dialog[20];
        strcat(Dialog, "Produtor da Máfia");
        Dialog_Show(playerid, "MafiaNPC", DIALOG_STYLE_TABLIST, "{FF0000}Máfia", Dialog, "Selecionar", "Fechar");
        break; 
    }
    return 1;
}

Dialog:MafiaNPC(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Dialog[1500];
    strcat(Dialog, "Opção\tAdicional\n");
    switch(listitem)
    {
        case 0:
        {
            strcat(Dialog, "Caixa de Cápsulas\t{32CD32}R$1.000\n");
            strcat(Dialog, "Caixa de Peças\t{32CD32}R$1.900");
            Dialog_Show(playerid, "MafiaProducaoCompra", DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Produção", Dialog, "Selecionar", "Fechar");
        }
    }
    return 1;
}

stock NpcBoca(playerid)
{
    new i = random(sizeof(NpcMafia));
    EnviarGps(playerid, NpcMafia[i][nMafiaX], NpcMafia[i][nMafiaY], NpcMafia[i][nMafiaZ]);
    SendClientMessage(playerid, 0xFFA500FF, "| MÁFIA | Siga o GPS para chegar até o ponto de compra");
    return 1;
}