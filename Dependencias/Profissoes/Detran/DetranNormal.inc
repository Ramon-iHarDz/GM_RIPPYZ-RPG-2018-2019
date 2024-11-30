#include <YSI_Coding\y_hooks>

new CNHA = 600;
new CNHB = 1200;
new CNHC = 1700;
new CNHD = 1700;


enum ApreencoesInfo
{
    AprendidoMotivo[90],
    ValorApreencao
};

new Apreencoes[][ApreencoesInfo] =
{
    {"Estacionado(a) na Calçada", 1950},
    {"Trafegando na Contra Mão", 9560},
    {"Estacionado(a) no Meio da Rua", 5150}
};

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{00BFFF}Detran\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} para visualizar", -1, 400.6127, 306.5691, 1005.8494, 30.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1301, 4, -1, 35.0, -1, 0);
    return 1;
}

stock ValorMultas(Multas, por)
{
    new Soma = (Multas*por);
    return Soma;
}

Dialog:DetranMultas(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            if(Jogador[playerid][CarteiraA] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui essa CNH");
            if(Jogador[playerid][CarteiraA] == 1){
                new ValorMT = ValorMultas(Jogador[playerid][MultaA], CNHA),
                    Mensagem[128]
                ;
                if(Jogador[playerid][Dinheiro] < ValorMT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
                Jogador[playerid][Dinheiro] -= ValorMT;
                format(Mensagem, sizeof(Mensagem), "| DETRAN | Você retirou {FF8C00}%d{FFFFFF} multa(s) por {00FF00}$%s", Jogador[playerid][MultaA], DinheiroSeparar(ValorMT));
                SendClientMessage(playerid, -1, Mensagem);
                Jogador[playerid][MultaA] = 0;
            }
            if(Jogador[playerid][CarteiraA] == 2){
                if(Jogador[playerid][Dinheiro] < 3000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");  
                Jogador[playerid][Dinheiro] -= 3000;
                Jogador[playerid][CarteiraA] = 1;
                SendClientMessage(playerid, -1, "| DETRAN | Você pagou {00FF00}$3.000{FFFFFF} para regularizar sua CNH");
            }
            if(Jogador[playerid][CarteiraA] == 3){
                if(Jogador[playerid][Dinheiro] < 9000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");  
                Jogador[playerid][Dinheiro] -= 9000;
                Jogador[playerid][CarteiraA] = 1;
                SendClientMessage(playerid, -1, "| DETRAN | Você pagou {00FF00}$9.000{FFFFFF} e regularizou sua CNH");
            }
        }
        case 1:
        {
            if(Jogador[playerid][CarteiraB] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui essa CNH");
            if(Jogador[playerid][CarteiraB] == 1){
                new ValorMT = ValorMultas(Jogador[playerid][MultaB], CNHB),
                    Mensagem[128]
                ;
                if(Jogador[playerid][Dinheiro] < ValorMT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
                Jogador[playerid][Dinheiro] -= ValorMT;
                format(Mensagem, sizeof(Mensagem), "| DETRAN | Você retirou {FF8C00}%d{FFFFFF} multa(s) por {00FF00}$%s", Jogador[playerid][MultaB], DinheiroSeparar(ValorMT));
                SendClientMessage(playerid, -1, Mensagem);
                Jogador[playerid][MultaB] = 0;
            }
            if(Jogador[playerid][CarteiraB] == 2){
                if(Jogador[playerid][Dinheiro] < 6000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");  
                Jogador[playerid][Dinheiro] -= 6000;
                Jogador[playerid][CarteiraB] = 1;
                SendClientMessage(playerid, -1, "| DETRAN | Você pagou {00FF00}$6.000{FFFFFF} para regularizar sua CNH");
            }
            if(Jogador[playerid][CarteiraB] == 3){
                if(Jogador[playerid][Dinheiro] < 15000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");  
                Jogador[playerid][Dinheiro] -= 15000;
                Jogador[playerid][CarteiraB] = 1;
                SendClientMessage(playerid, -1, "| DETRAN | Você pagou {00FF00}$15.000{FFFFFF} e regularizou sua CNH");
            }
        }
        case 2:
        {
            if(Jogador[playerid][CarteiraC] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui essa CNH");
            if(Jogador[playerid][CarteiraC] == 1){
                new ValorMT = ValorMultas(Jogador[playerid][MultaC], CNHC),
                    Mensagem[128]
                ;
                if(Jogador[playerid][Dinheiro] < ValorMT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
                Jogador[playerid][Dinheiro] -= ValorMT;
                format(Mensagem, sizeof(Mensagem), "| DETRAN | Você retirou {FF8C00}%d{FFFFFF} multa(s) por {00FF00}$%s", Jogador[playerid][MultaC], DinheiroSeparar(ValorMT));
                SendClientMessage(playerid, -1, Mensagem);
                Jogador[playerid][MultaC] = 0;
            }
            if(Jogador[playerid][CarteiraC] == 2){
                if(Jogador[playerid][Dinheiro] < 8000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");  
                Jogador[playerid][Dinheiro] -= 8000;
                Jogador[playerid][CarteiraC] = 1;
                SendClientMessage(playerid, -1, "| DETRAN | Você pagou {00FF00}$8.000{FFFFFF} para regularizar sua CNH");
            }
            if(Jogador[playerid][CarteiraC] == 3){
                if(Jogador[playerid][Dinheiro] < 18000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");  
                Jogador[playerid][Dinheiro] -= 18000;
                Jogador[playerid][CarteiraC] = 1;
                SendClientMessage(playerid, -1, "| DETRAN | Você pagou {00FF00}$18.000{FFFFFF} e regularizou sua CNH");
            }
        }
        case 3:
        {
            if(Jogador[playerid][CarteiraD] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui essa CNH");
            if(Jogador[playerid][CarteiraD] == 1){
                new ValorMT = ValorMultas(Jogador[playerid][MultaD], CNHD),
                    Mensagem[128]
                ;
                if(Jogador[playerid][Dinheiro] < ValorMT) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
                Jogador[playerid][Dinheiro] -= ValorMT;
                format(Mensagem, sizeof(Mensagem), "| DETRAN | Você retirou {FF8C00}%d{FFFFFF} multa(s) por {00FF00}$%s", Jogador[playerid][MultaD], DinheiroSeparar(ValorMT));
                SendClientMessage(playerid, -1, Mensagem);
                Jogador[playerid][MultaD] = 0;
            }
            if(Jogador[playerid][CarteiraD] == 2){
                if(Jogador[playerid][Dinheiro] < 7000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");  
                Jogador[playerid][Dinheiro] -= 7000;
                Jogador[playerid][CarteiraD] = 1;
                SendClientMessage(playerid, -1, "| DETRAN | Você pagou {00FF00}$7.000{FFFFFF} para regularizar sua CNH");
            }
            if(Jogador[playerid][CarteiraD] == 3){
                if(Jogador[playerid][Dinheiro] < 16000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");  
                Jogador[playerid][Dinheiro] -= 16000;
                Jogador[playerid][CarteiraD] = 1;
                SendClientMessage(playerid, -1, "| DETRAN | Você pagou {00FF00}$16.000{FFFFFF} e regularizou sua CNH");
            }
        }
    }
    return 0;
}

Dialog:DetranMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            new Dialog[600];
            strcat(Dialog, "Cnh\tMultas\tPreço\tEstado\n");
            if(Jogador[playerid][CarteiraA] == 0) strcat(Dialog, "Motos\t{FF6347}Não possui CNH{FFFFFF}\t{FF0000}N/A{FFFFFF}\t{FF0000}N/A{FFFFFF}\n");
            else if(Jogador[playerid][CarteiraA] == 1){
                if(Jogador[playerid][MultaA] > 0) strcatEx(Dialog, "Motos\t{FF6347}%d\t{00FF00}$%s\n", Jogador[playerid][MultaA], DinheiroSeparar(ValorMultas(Jogador[playerid][MultaA], CNHA)));
                else strcat(Dialog, "Motos\t{FF6347}0\t{00FF00}$0\n");
            }
            else if(Jogador[playerid][CarteiraA] == 2) strcatEx(Dialog, "Motos\t{FF6347}%d\t{00FF00}$3.000\t{FF0000}Vencida\n", Jogador[playerid][MultaA]);
            else if(Jogador[playerid][CarteiraA] == 3) strcatEx(Dialog, "Motos\t{FF6347}%d\t{00FF00}$9.000\t{FF6347}Retida\n", Jogador[playerid][MultaA]);


            //
            if(Jogador[playerid][CarteiraB] == 0) strcat(Dialog, "Carros\t{FF6347}Não possui CNH{FFFFFF}\t{FF0000}N/A{FFFFFF}\t{FF0000}N/A{FFFFFF}\n");
            else if(Jogador[playerid][CarteiraB] == 1){
                if(Jogador[playerid][MultaB] > 0) strcatEx(Dialog, "Carros\t{FF6347}%d\t{00FF00}$%s\n", Jogador[playerid][MultaB], DinheiroSeparar(ValorMultas(Jogador[playerid][MultaB], CNHB)));
                else strcat(Dialog, "Carros\t{FF6347}0\t{00FF00}$0\n");
            }
            else if(Jogador[playerid][CarteiraB] == 2) strcatEx(Dialog, "Carros\t{FF6347}%d\t{00FF00}$6.000\t{FF0000}Vencida\n", Jogador[playerid][MultaB]);
            else if(Jogador[playerid][CarteiraB] == 3) strcatEx(Dialog, "Carros\t{FF6347}%d\t{00FF00}$15.000\t{FF6347}Retida\n", Jogador[playerid][MultaB]);


            //
            if(Jogador[playerid][CarteiraC] == 0) strcat(Dialog, "Caminhões\t{FF6347}Não possui CNH{FFFFFF}\t{FF0000}N/A{FFFFFF}\t{FF0000}N/A{FFFFFF}\n");
            else if(Jogador[playerid][CarteiraC] == 1){
                if(Jogador[playerid][MultaC] > 0) strcatEx(Dialog, "Caminhões\t{FF6347}%d\t{00FF00}$%s\n", Jogador[playerid][MultaC], DinheiroSeparar(ValorMultas(Jogador[playerid][MultaC], CNHC)));
                else strcat(Dialog, "Caminhões\t{FF6347}0\t{00FF00}$0\n");
            }
            else if(Jogador[playerid][CarteiraC] == 2) strcatEx(Dialog, "Caminhões\t{FF6347}%d\t{00FF00}$8.000\t{FF0000}Vencida\n", Jogador[playerid][MultaC]);
            else if(Jogador[playerid][CarteiraC] == 3) strcatEx(Dialog, "Caminhões\t{FF6347}%d\t{00FF00}$18.000\t{FF6347}Retida\n", Jogador[playerid][MultaC]);
        

            //
            if(Jogador[playerid][CarteiraD] == 0) strcat(Dialog, "Ônibus\t{FF6347}Não possui CNH{FFFFFF}\t{FF0000}N/A{FFFFFF}\t{FF0000}N/A{FFFFFF}\n");
            else if(Jogador[playerid][CarteiraD] == 1){
                if(Jogador[playerid][MultaD] > 0) strcatEx(Dialog, "Ônibus\t{FF6347}%d\t{00FF00}$%s\n", Jogador[playerid][MultaD], DinheiroSeparar(ValorMultas(Jogador[playerid][MultaD], CNHD)));
                else strcat(Dialog, "Ônibus\t{FF6347}0\t{00FF00}$0\n");
            }
            else if(Jogador[playerid][CarteiraD] == 2) strcatEx(Dialog, "Ônibus\t{FF6347}%d\t{00FF00}$7.000\t{FF0000}Vencida\n", Jogador[playerid][MultaD]);
            else if(Jogador[playerid][CarteiraD] == 3) strcatEx(Dialog, "Ônibus\t{FF6347}%d\t{00FF00}$16.000\t{FF6347}Retida\n", Jogador[playerid][MultaD]);
            Dialog_Show(playerid, DetranMultas, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Multas", Dialog, "Selecionar", "Fechar");
        }
        case 1:
        {
            new Dialog[1500];
            strcat(Dialog, "ID\tVeículo\tEstado\n");
            for(new i=0; i < MAX_SLOT_VEH; i++)
            {
                if(pVeiculo[playerid][i][MeuVeiculoModelo] > 0)
                {
                    if(strcmp(pVeiculo[playerid][i][Apreendido], "*"))
                    {
                        for(new o=0; o < sizeof(Apreencoes); o++)
                        {
                            if(strcmp(pVeiculo[playerid][i][Apreendido], Apreencoes[i][AprendidoMotivo])) continue;
                            strcatEx(Dialog, "{FFFFFF}%d.\t%s\t%s\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]), Apreencoes[i][AprendidoMotivo]);
                        } 
                    }
                    else strcatEx(Dialog, "{FFFFFF}%d.\t%s\t{FF0000}Nenhuma Irregularidade\n", i, GetVehicleNameByModel(pVeiculo[playerid][i][MeuVeiculoModelo]));
                }
                else strcatEx(Dialog, "{FFFFFF}%d.\t{FF0000}{FF0000}N/A{FFFFFF}\t{FF0000}{FF0000}N/A{FFFFFF}\n", i);
            }
            Dialog_Show(playerid, DetranVeiculos, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Seus Veículos", Dialog, "Selecionar", "Fechar");
        }
    }
    return 0;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(newkeys != KEY_YES) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 400.6127, 306.5691, 1005.8494)) return 1;
    if(GetPlayerVirtualWorld(playerid) != 1301 || GetPlayerInterior(playerid) != 4) return 1;

    new Dialog[200];
    strcat(Dialog, "Ver Multas\n");
    strcat(Dialog, "Ver Veículos");
    Dialog_Show(playerid, DetranMenu, DIALOG_STYLE_LIST, "{FF0000}Detran", Dialog, "Selecionar", "Fechar");
    return 1;
}