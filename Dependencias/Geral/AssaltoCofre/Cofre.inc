#include <YSI_Coding\y_hooks>
#define     MAX_COFRES      (60)

enum CofreInfo
{
    bool:CofreColocado,
    Float:CofreX,  
    Float:CofreY,
    Float:CofreZ,
    Float:CofreA,
    CofreVw,
    CofreInterior
};
new pCofre[MAX_COFRES][CofreInfo];

hook OnPlayerDisconnect(playerid, reason){

    return 1;
}

stock PegarCofreID(){
    for(new i=0; i < MAX_COFRES; i++){
        if(pCofre[i][CofreColocado] == true) continue;
        return i;
    }
    return -1;
}

CMD:criarcofre(playerid){
    if(Jogador[playerid][Admin] < 7) return 0;
    if(GetPVarInt(playerid, "CriandoCofre") == 1) return SendClientMessage(playerid, )

    return 1;
}