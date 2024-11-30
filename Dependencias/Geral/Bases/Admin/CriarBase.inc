#include <YSI_Coding\y_hooks> 

enum AdminBaseCriacao
{
    Float:aBPosX,
    Float:aBPosY,
    Float:aBPosZ,
    Float:aBPosA,

    Float:aCimaX,
    Float:aCimaY,
    Float:aBaixoX,
    Float:aBaixoY,

    Float:aBaseForaX,
    Float:aBaseForaY,
    Float:aBaseForaZ,

    Float:aPortaoX,
    Float:aPortaoY,
    Float:aPortaoZ,
    Float:aPortaoRX,
    Float:aPortaoRY,
    Float:aPortaoRZ,

    aPrecoBase,
    PortaoBaseAdminID,
    bool:CriandoPortao
};

enum VeiculoBaseAdmin
{
    bool:aVeiculoDB,
    Float:aVPosX,
    Float:aVPosY,
    Float:aVPosZ,
    Float:aVPosA
};

new aVbase[MAX_PLAYERS][MAX_BASEVEH][VeiculoBaseAdmin];
new aBase[MAX_PLAYERS][AdminBaseCriacao];

hook OnPlayerDisconnect(playerid, reason)
{
    if(aBase[playerid][CriandoPortao] == true) DestroyDynamicObjectEx(aBase[playerid][PortaoBaseAdminID]);

    new dasdac[AdminBaseCriacao];
    aBase[playerid] = dasdac;

    for(new i=0; i < MAX_BASEVEH; i++)
    {
        new FASDAAS[VeiculoBaseAdmin];   
        aVbase[playerid][i] = FASDAAS;
    }
    return 1;
}

hook OnPlayerEditDynObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(aBase[playerid][CriandoPortao] == false) return 1;
    switch(response)
    {
        case EDIT_RESPONSE_CANCEL:
        {
            aBase[playerid][CriandoPortao] = false;
            DestroyDynamicObjectEx(aBase[playerid][PortaoBaseAdminID]);
            SendClientMessage(playerid, -1, "| ADMIN | Você cancelou a criação do portão");
        }
        case EDIT_RESPONSE_FINAL:
        {
            aBase[playerid][CriandoPortao] = false;
            aBase[playerid][aPortaoX] = x;
            aBase[playerid][aPortaoY] = y;
            aBase[playerid][aPortaoZ] = z;
            aBase[playerid][aPortaoRX] = rx;
            aBase[playerid][aPortaoRY] = ry;
            aBase[playerid][aPortaoRZ] = rz;
            DestroyDynamicObjectEx(aBase[playerid][PortaoBaseAdminID]);
            SendClientMessage(playerid, -1, "| ADMIN | Você colocou o portão com sucesso");
        }
    }
    return 1;
} 

Dialog:OpcaoConfigVeiculoBase(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new idx = GetPVarInt(playerid, "avehidx");

    switch(listitem)
    {
        case 0:
        {
            if(aVbase[playerid][idx][aVeiculoDB] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Nenhuma configuração aplicada");
            new FASDAAS[VeiculoBaseAdmin];   
            aVbase[playerid][idx] = FASDAAS;  
            SendClientMessage(playerid, -1, "| ADMIN | Configuração removida");
        }
        case 1:
        {
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não está dirigindo");
            aVbase[playerid][idx][aVeiculoDB] = true;
            GetVehiclePos(GetPlayerVehicleID(playerid), aVbase[playerid][idx][aVPosX], aVbase[playerid][idx][aVPosY], aVbase[playerid][idx][aVPosZ]);
            GetVehicleZAngle(GetPlayerVehicleID(playerid), aVbase[playerid][idx][aVPosA]);
            SendClientMessage(playerid, -1, "| ADMIN | Configuração aplicada.");
        }
    }

    return 1;
}

Dialog:AdminConfigVeiculoBase(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    SetPVarInt(playerid, "avehidx", listitem);

    new Dialog[80];
    strcat(Dialog, "Remover Veículo\n");
    strcat(Dialog, "Adicionar / Atualizar");
    Dialog_Show(playerid, OpcaoConfigVeiculoBase, DIALOG_STYLE_TABLIST, "{FF0000}Opção", Dialog, "Selecionar", "Fechar");
    return 1;
}

Dialog:PrecoBaseAdmin(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id;
    if(sscanf(inputtext, "d", id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Valor Inválido");
    aBase[playerid][aPrecoBase] = id;
    SendClientMessage(playerid, -1, "| ADMIN | Você adicionou um preço para a base");
    return 1;
}

Dialog:BaseCriacaoMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new Float:Bolado[4];
    GetPlayerPos(playerid, Bolado[0], Bolado[1], Bolado[2]);

    switch(listitem)
    {
        case 0:
        {
            new Mensagem[128];
            GetPlayerPos(playerid, Bolado[0], Bolado[1], Bolado[2]);
            GetPlayerFacingAngle(playerid, Bolado[3]);
            aBase[playerid][aBPosX] = Bolado[0];
            aBase[playerid][aBPosY] = Bolado[1];
            aBase[playerid][aBPosZ] = Bolado[2];
            aBase[playerid][aBPosA] = Bolado[3];
            format(Mensagem, sizeof(Mensagem), "| ADMIN | Você setou a posição da base: {FFA500}%0.2f %0.2f %0.2f %0.2f", Bolado[0], Bolado[1], Bolado[2], Bolado[3]);
            SendClientMessage(playerid, -1, Mensagem);
        }
        case 1:
        {
            new Mensagem[128];
            if(GetPVarInt(playerid, "CantoEstado") == 0)
            {
                aBase[playerid][aCimaX] = Bolado[0];
                aBase[playerid][aCimaY] = Bolado[1];
                SetPVarInt(playerid, "CantoEstado", 1);
                format(Mensagem, sizeof(Mensagem), "| ADMIN | Você setou a posição maior: {FFA500}%0.2f %0.2f", Bolado[0], Bolado[1]);
            }
            else if(GetPVarInt(playerid, "CantoEstado") == 1)
            {
                aBase[playerid][aBaixoX] = Bolado[0];
                aBase[playerid][aBaixoY] = Bolado[1];
                SetPVarInt(playerid, "CantoEstado", 0);
                format(Mensagem, sizeof(Mensagem), "| ADMIN | Você setou a posição menor: {FFA500}%0.2f %0.2f", Bolado[0], Bolado[1]);
            }
            SendClientMessage(playerid, -1, Mensagem);
        }
        case 2:
        {
            aBase[playerid][CriandoPortao] = true;
            aBase[playerid][PortaoBaseAdminID] = CreateDynamicObject(19912, Bolado[0], Bolado[1], Bolado[2], 0.0, 0.0, 0.0, 0, 0, -1, 100.0, 100.0, -1);
            EditDynamicObject(playerid, aBase[playerid][PortaoBaseAdminID]);
        }
        case 3:
        {
            new Dialog[200];
            for(new i=0; i < MAX_BASEVEH; i++)
            {
                if(aVbase[playerid][i][aVeiculoDB] == false) strcatEx(Dialog, "%d. Sem configuração\n", i+1);
                else strcatEx(Dialog, "%d. Configurado.\n", i+1);
            }
            Dialog_Show(playerid, AdminConfigVeiculoBase, DIALOG_STYLE_TABLIST, "{FF0000}Configuração", Dialog, "Selecionar", "Fechar");
        }
        case 4:
        {
            new Mensagem[128];
            GetPlayerPos(playerid, Bolado[0], Bolado[1], Bolado[2]);
            aBase[playerid][aBaseForaX] = Bolado[0];
            aBase[playerid][aBaseForaY] = Bolado[1];
            aBase[playerid][aBaseForaZ] = Bolado[2];
            format(Mensagem, sizeof(Mensagem), "| ADMIN | Você setou a posição fora da base: {FFA500}%0.2f %0.2f %0.2f %0.2f", Bolado[0], Bolado[1], Bolado[2], Bolado[3]);
            SendClientMessage(playerid, -1, Mensagem);
        }
        case 5: Dialog_Show(playerid, PrecoBaseAdmin, DIALOG_STYLE_INPUT, "{FF0000}Preço", "Coloque o preço da base abaixo", "Confirmar", "Fechar");
        case 6: 
        {
            new id = PegarBaseID();
            if(id == -1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há mais espaço no servidor para bases");

            new Enviar[1900];
            strcat(Enviar, "INSERT INTO `bases` ");
            strcat(Enviar, "(`Nome`, `Numero`, `Senha`, `CimaX`, `CimaY`, `BaixoX`, `BaixoY`, `BasePortaoX`, `BasePortaoY`, `BasePortaoZ`, `BasePortaoRX`, `BasePortaoRY`, `BasePortaoRZ`, `BaseX`, `BaseY`, `BaseZ`, `BaseA`, `Valor`, `BaseForaX`, `BaseForaY`, `BaseForaZ`) VALUES ");
            strcatEx(Enviar, "('*', %d, '*', %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %d, %f, %f, %f)", id, aBase[playerid][aCimaX], aBase[playerid][aCimaY], aBase[playerid][aBaixoX], aBase[playerid][aBaixoY], aBase[playerid][aPortaoX], aBase[playerid][aPortaoY], aBase[playerid][aPortaoZ], aBase[playerid][aPortaoRX], aBase[playerid][aPortaoRY], aBase[playerid][aPortaoRZ], aBase[playerid][aBPosX], aBase[playerid][aBPosY], aBase[playerid][aBPosZ], aBase[playerid][aBPosA], aBase[playerid][aPrecoBase], aBase[playerid][aBaseForaX], aBase[playerid][aBaseForaY], aBase[playerid][aBaseForaZ]);
            mysql_query(IDConexao, Enviar, false);
            if(mysql_errno(IDConexao) != 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Houve um erro ao registrar a base na database");

            Base[id][BaseX] = aBase[playerid][aBPosX];
            Base[id][BaseY] = aBase[playerid][aBPosY];
            Base[id][BaseZ] = aBase[playerid][aBPosZ];
            Base[id][BaseA] = aBase[playerid][aBPosA];

            Base[id][BasePortaoX] = aBase[playerid][aPortaoX];
            Base[id][BasePortaoY] = aBase[playerid][aPortaoY];
            Base[id][BasePortaoZ] = aBase[playerid][aPortaoZ];
            Base[id][BasePortaoRX] = aBase[playerid][aPortaoRX];
            Base[id][BasePortaoRY] = aBase[playerid][aPortaoRY];
            Base[id][BasePortaoRZ] = aBase[playerid][aPortaoRZ];

            Base[id][CimaX] = aBase[playerid][aCimaX];
            Base[id][CimaY] = aBase[playerid][aCimaY];
            Base[id][BaixoX] = aBase[playerid][aBaixoX];
            Base[id][BaixoY] = aBase[playerid][aBaixoY];

            Base[id][BaseForaX] = aBase[playerid][aBaseForaX];
            Base[id][BaseForaY] = aBase[playerid][aBaseForaY];
            Base[id][BaseForaZ] = aBase[playerid][aBaseForaZ];

            Base[id][BaseCoins] = aBase[playerid][aPrecoBase];

            CarregarBase(id);

            for(new i=0; i < MAX_BASEVEH; i++)
            {
                if(aVbase[playerid][i][aVeiculoDB] == false) continue;
                format(Enviar, sizeof(Enviar), "INSERT INTO `baseveiculos` (`BaseID`, `PosicaoID`, `BaseX`, `BaseY`, `BaseZ`, `BaseA`) VALUES (%d, %d, %f, %f, %f, %f)", id, i, aVbase[playerid][i][aVPosX], aVbase[playerid][i][aVPosY], aVbase[playerid][i][aVPosZ], aVbase[playerid][i][aVPosA]);
                mysql_query(IDConexao, Enviar, false);
                
                vBase[id][i][SlotDataBase] = true;
                vBase[id][i][vBaseX] = aVbase[playerid][i][aVPosX];
                vBase[id][i][vBaseY] = aVbase[playerid][i][aVPosY];
                vBase[id][i][vBaseZ] = aVbase[playerid][i][aVPosZ];
                vBase[id][i][vBaseA] = aVbase[playerid][i][aVPosA];
            }

            new dasdac[AdminBaseCriacao];
            aBase[playerid] = dasdac;
            for(new i=0; i < MAX_BASEVEH; i++)
            {
                new FASDAAS[VeiculoBaseAdmin];   
                aVbase[playerid][i] = FASDAAS;
            }
            SendClientMessage(playerid, -1, "| ADMIN | Base criada com sucesso");

        }
        case 7:
        {
            new dasdac[AdminBaseCriacao];
            aBase[playerid] = dasdac;

            for(new i=0; i < MAX_BASEVEH; i++)
            {
                new FASDAAS[VeiculoBaseAdmin];   
                aVbase[playerid][i] = FASDAAS;
            }
            SendClientMessage(playerid, -1, "| ADMIN | Configuração resetada.");   
        }
    }

    return 1;
}

CMD:criarbase(playerid)
{
    if(Jogador[playerid][Admin] != 7) return 0;
    if(aBase[playerid][CriandoPortao] == true) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você precisa posicionar o portão antes de abrir as configurações");

    new Dialog[450];
    strcat(Dialog, "Opção\tAdicional\n");
    strcatEx(Dialog, "{FFFFFF}Posição\t{FFA500}X: %0.2f Y: %0.2f Z: %0.2f A: %0.2f\n", aBase[playerid][aBPosX], aBase[playerid][aBPosY], aBase[playerid][aBPosZ], aBase[playerid][aBPosA]);
    strcatEx(Dialog, "{FFFFFF}Cantos\t{FFA500}%0.2f %0.2f / %0.2f %0.2f\n", aBase[playerid][aCimaX], aBase[playerid][aCimaY], aBase[playerid][aBaixoX], aBase[playerid][aBaixoY]);
    strcatEx(Dialog, "{FFFFFF}Configurar Portão\t{FFA500}%0.2f %0.2f %0.2f\n", aBase[playerid][aPortaoX], aBase[playerid][aPortaoY], aBase[playerid][aPortaoZ]);
    strcatEx(Dialog, "{FFFFFF}Configurar Veículos\t{FFA500}%d\n", BaseVeiculoAdmin(playerid));
    strcatEx(Dialog, "{FFFFFF}Configurar Posição Fora\t{FFA500}%0.2f %0.2f %0.2f\n", aBase[playerid][aBaseForaX], aBase[playerid][aBaseForaY], aBase[playerid][aBaseForaZ]);
    strcatEx(Dialog, "{FFFFFF}Preço\t{FFA500}$%s\n", DinheiroSeparar(aBase[playerid][aPrecoBase]));
    strcat(Dialog, "{32CD32}Criar Base\n");
    strcat(Dialog, "{FF0000}Resertar Configuração");
    Dialog_Show(playerid, BaseCriacaoMenu, DIALOG_STYLE_TABLIST_HEADERS, "{FF0000}Admin", Dialog, "Selecionar", "Fechar");
    return 1;
}

stock BaseVeiculoAdmin(playerid)
{
    new blasd;
    for(new i=0; i < MAX_BASEVEH; i++)
    {
        if(aVbase[playerid][i][aVeiculoDB] == false) continue;
        blasd++;
    }
    return blasd;
}