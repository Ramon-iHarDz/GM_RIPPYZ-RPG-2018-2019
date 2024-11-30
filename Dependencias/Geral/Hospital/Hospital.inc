#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("{00BFFF}Hospital\n{FFFFFF}Aperte {CCCCCC}'Y'{FFFFFF} abrir o menu", -1, 1032.7554,59.2491,1000.4590, 20.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1299, 3, -1);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
    if(newkeys != KEY_YES) return 1;
    if(GetPlayerVirtualWorld(playerid) != 1299 || GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1032.7554,59.2491,1000.4590)) return 1;

    new Dialog[400];
    strcat(Dialog, "Opção\tPreço\n");
    strcat(Dialog, "{FFFFFF}Plano de Saúde\t{32CD32}$400/Up\n");
    strcat(Dialog, "{FFFFFF}Curativo\t{32CD32}$1.000\n");
    strcat(Dialog, "{FFFFFF}Cura\t{32CD32}$4.000\n");
    strcat(Dialog, "{FFFFFF}Vacinas\t{32CD32}$3.500\n");
    strcat(Dialog, "{FFFFFF}Troca de Gênero\t{32CD32}$100.000\n");
    strcat(Dialog, "{FFFFFF}Kit's Médico\t{32CD32}$1.000\n");
    strcat(Dialog, "{FFFFFF}Tratamento de Vício\t{32CD32}$10.000\n");
    Dialog_Show(playerid, HospitalMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Hospital", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:PlanoDeSaudeA(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[128],
        Soma = gettime()+(15*86400);
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `PlanoDeSaude` = %d WHERE `Nome` = '%s'", Soma, EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false); 
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao assinar seu plano!");
    Jogador[playerid][PlanoDeSaude] = Soma;
    format(Enviar, sizeof(Enviar), "| HOSPITAL | Seu plano de saúde vai vencer em %s", GetDateFromTimeEx(Soma));
    SendClientMessage(playerid, 0x3CB371FF, Enviar);
    return 1;
}

Dialog:PlanoDeSaudeB(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new Enviar[128];
    format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `PlanoDeSaude` = 0 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    mysql_query(IDConexao, Enviar, false); 
    if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao assinar seu plano!");
    Jogador[playerid][PlanoDeSaude] = 0;
    SendClientMessage(playerid, 0x3CB371FF, "| HOSPITAL | Seu plano de saúde foi cancelado");
    return 1;
}

Dialog:HospitalMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0:
        {
            if(Jogador[playerid][PlanoDeSaude] > gettime()) return Dialog_Show(playerid, PlanoDeSaudeB, DIALOG_STYLE_MSGBOX, "{FF0000}Plano de Saúde", "{FFFFFF}Você deseja cancelar seu plano de saúde?", "Confirmar", "Cancelar");
            Dialog_Show(playerid, PlanoDeSaudeA, DIALOG_STYLE_MSGBOX, "{FF0000}Plano de Saúde", "{FFFFFF}Você realmente deseja contratar o plano de saúde?", "Confirmar", "Cancelar");
        }
        case 1:
        {
            new Float:idaa;
            GetPlayerHealth(playerid, idaa);
            if(idaa > 80) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você tem mais de 80 de vida");
            if(Jogador[playerid][Dinheiro] < 1000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");
            Jogador[playerid][Dinheiro] -= 1000;
            SetPlayerHealth(playerid, 100);
            SendClientMessage(playerid, -1, "| HOSPITAL | Você pagou {32CD32}$1.000{FFFFFF} pelo curativo");
        }
        case 2:
        {
            if(Jogador[playerid][Doenca] == 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem nenhuma doença");
            if(Jogador[playerid][PlanoDeSaude] > gettime())
            {
                if(Jogador[playerid][Dinheiro] < 4000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente ( $4.000 )");
                Jogador[playerid][Dinheiro] -= 4000;
            }
            else
            {
                if(Jogador[playerid][Dinheiro] < 3000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente ( $3.000 )");
                SendClientMessage(playerid, -1, "| HOSPITAL | Seu plano de saúde pagou {32CD32}$2.000{FFFFFF} para você");
                Jogador[playerid][Dinheiro] -= 3000;       
            }
            
            Jogador[playerid][Doenca] = 0;
            Jogador[playerid][Saude] = 100.0;
            AtualizarStatus(playerid);
            DarVacina(playerid, 2);
            SendClientMessage(playerid, -1, "| HOSPITAL | Você pagou {32CD32}$4.000{FFFFFF} pela cura"); 
        }
        case 3: 
        {
            if(Jogador[playerid][Doenca] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa se curar antes");
            if(Jogador[playerid][Vacina] > 18000) return SendClientMessage(playerid, 0xFF4500FF, "| HOSPITAL | Você já possui bastante vacinas");
            
            if(Jogador[playerid][PlanoDeSaude] > gettime())
            {
                if(Jogador[playerid][Dinheiro] < 3500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente ( $3.500 )");
                Jogador[playerid][Dinheiro] -= 3500;
            }
            else
            {
                if(Jogador[playerid][Dinheiro] < 2500) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente ( $2.500 )");
                SendClientMessage(playerid, -1, "| HOSPITAL | Seu plano de saúde pagou {32CD32}$1.000{FFFFFF} para você!");
                Jogador[playerid][Dinheiro] -= 2500;   
            }

            DarVacina(playerid, 15);
            SendClientMessage(playerid, -1, "| HOSPITAL | Você pagou {40E0D0}10 vacinas{FFFFFF} por {32CD32}$3.500");
        }
        case 4:
        {
            if(Jogador[playerid][Dinheiro] < 100000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente");

            new Enviar[128];
            if(Jogador[playerid][Sexo] == 1)
            {
                format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Sexo` = 2 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
                mysql_query(IDConexao, Enviar, false); 
                if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao alterar seu sexo");  
                
                Jogador[playerid][Sexo] = 2;
                Jogador[playerid][Dinheiro] -= 100000;
                Jogador[playerid][Skin] = 56;
                SetPlayerSkin(playerid, 56);
                SendClientMessage(playerid, -1, "| HOSPITAL | Você alterou seu sexo para {EE82EE}Feminino{FFFFFF} por {32CD32}$100.000");
                return 1;

            }
            format(Enviar, sizeof(Enviar), "UPDATE `rippzyrpg` SET `Sexo` = 1 WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
            mysql_query(IDConexao, Enviar, false); 
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um problema ao alterar seu sexo");  
            Jogador[playerid][Sexo] = 1;
            Jogador[playerid][Dinheiro] -= 100000;
            Jogador[playerid][Skin] = 59;
            SetPlayerSkin(playerid, 59);
            SendClientMessage(playerid, -1, "| HOSPITAL | Você alterou seu sexo para {00BFFF}Masculino{FFFFFF} por {32CD32}$100.000");
        }
        case 5:
        {
            if(Jogador[playerid][KitMedico] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você ainda tem kits médico");
            if(Jogador[playerid][Dinheiro] < 1000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
            Jogador[playerid][Dinheiro] -= 1000;
            Jogador[playerid][KitMedico] += 3;
            SendClientMessage(playerid, -1, "| HOSPITAL | Você comprou {00BFFF}3 kits médico{FFFFFF} por {32CD32}$1.000");
        }
        case 6:
        {
            if(Jogador[playerid][VicioEstilo] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem vícios");
            if(Jogador[playerid][Dinheiro] < 10000) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente");
            Jogador[playerid][Dinheiro] -= 10000;
            Jogador[playerid][VicioEstilo] = 0;
            Jogador[playerid][Vicio] = 100.0;
            SendClientMessage(playerid, -1, "| HOSPITAL | Você se tratou do vício por {32CD32}$10.000");
            AtualizarStatus(playerid);
        }
    }
    return 1;
}

CMD:usarkit(playerid)
{
    if(Jogador[playerid][KitMedico] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem kit médico");
    
    new Float:asd;
    GetPlayerHealth(playerid, asd);
    if(asd > 50.0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está com menos de 50 de vida");

    SetPlayerHealth(playerid, 100.0);
    Jogador[playerid][KitMedico] -= 1;

    new Msg[50];
    format(Msg, sizeof(Msg), "| KIT-MÉDICO | Você usou um kit-médico ( %d/3 )", Jogador[playerid][KitMedico]);
    SendClientMessage(playerid, 0x00BFFFFF, Msg);
    return 1;
}