#include <YSI_Coding\y_hooks>

#define     MAX_ORGS            (15)
#define     MAX_ORGMEMBROS      (30)

enum CorporacaoInfo{
    bool:CorpColocado,
    OrgDono[30],
    OrgNome[30],
    OrgTag[10]
};

enum CorporacaoMembro{
    bool:CorpMembro,
    CorpMembroNome[30],
    CorpMembroCargo
};

new Org[MAX_ORGS][CorporacaoInfo];
new mOrb[MAX_ORGS][MAX_ORGMEMBROS][CorporacaoMembro];

CMD:orgs(playerid){
    new Dialog[1000];
    strcat(Dialog, "Organização\tTag\tStatus\n");
    for(new i=0; i < MAX_ORGS; i++){
        if(Org[i][CorpColocado] == false) continue;
        if(!strcmp(Org[i][OrgDono], "*")) strcatEx(Dialog, "{00BFFF}%s\t{daa520}%s\t{FF4500}Sem Dono(a)\n", Org[i][OrgNome], Org[i][OrgTag]);
        else strcatEx(Dialog, "{00BFFF}%s\t{daa520}%s\t{FFA500}%s\n", Org[i][OrgNome], Org[i][OrgTag], Org[i][OrgDono]);
    }
    Dialog_Show(playerid, OrgMenu, DIALOG_STYLE_TABLIST_HEADERS, "{1E90FF}Organização", Dialog, "Selecionar", "Fechar");
    return 1;
}