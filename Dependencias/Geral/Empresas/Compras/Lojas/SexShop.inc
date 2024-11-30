Dialog:SexoShopLoJa(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de toys nessa empresa");
    switch(listitem)
    {

        // Dildo Roxo
        case 0:
        {
            if(Jogador[playerid][Dinheiro] < 1500) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArma(playerid, 10)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui esse objeto sexual");
            GivePlayerWeapon(playerid, 10, 1);
            Jogador[playerid][Dinheiro] -= 1500;
            EnviarDinheiroEmpresa(id, 1500);
            SendClientMessage(playerid, 0x32CD32FF, "| SEXSHOP | Você comprou um Dildo Roxo por $1.500");
        }

        // Dildo
        case 1:
        {
            if(Jogador[playerid][Dinheiro] < 1200) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArma(playerid, 11)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui esse objeto sexual");
            GivePlayerWeapon(playerid, 11, 1);
            Jogador[playerid][Dinheiro] -= 1200;
            EnviarDinheiroEmpresa(id, 1200);
            SendClientMessage(playerid, 0x32CD32FF, "| SEXSHOP | Você comprou um Dildo Roxo por $1.200");
        }

        // Vibrador
        case 2:
        {
            if(Jogador[playerid][Dinheiro] < 1700) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArma(playerid, 12)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui esse objeto sexual");
            GivePlayerWeapon(playerid, 12, 1);
            Jogador[playerid][Dinheiro] -= 1700;
            EnviarDinheiroEmpresa(id, 1700);
            SendClientMessage(playerid, 0x32CD32FF, "| SEXSHOP | Você comprou um Vibrador Roxo por $1.700");
        }

        // Dildo Branco
        case 3:
        {
            if(Jogador[playerid][Dinheiro] < 1100) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não tem dinheiro sucifiente");
            if(VerificarArma(playerid, 13)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você já possui esse objeto sexual");
            GivePlayerWeapon(playerid, 13, 1);
            Jogador[playerid][Dinheiro] -= 1100;
            EnviarDinheiroEmpresa(id, 1100);
            SendClientMessage(playerid, 0x32CD32FF, "| SEXSHOP | Você comprou um Dildo Branco Roxo por $1.100");
        }
    }
    pEmpresa[id][eEstoque]--;
    return 1;
}