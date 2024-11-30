stock EnviarPresenteCaixa(playerid, id)
{
    switch(id)
    {
        // Lendários
        case 0: GivePlayerWeapon(playerid, 10, 1);
        case 1: Jogador[playerid][Dinheiro] += 10000;
        case 2: Jogador[playerid][Dinheiro] += 15000;
        case 3: GivePlayerWeapon(playerid, 10, 1);
        case 4: GivePlayerWeapon(playerid, 10, 1);
        case 5: SetPlayerArmour(playerid, 100.0);
        case 6: GivePlayerWeapon(playerid, 10, 1);
        case 7: Jogador[playerid][Experiencia] += 2;
        case 8: Jogador[playerid][Experiencia] += 1;
        
        // Épicos
        case 9: GivePlayerWeapon(playerid, 10, 1);
        case 10: Jogador[playerid][Dinheiro] += 5000;
        case 11: Jogador[playerid][Dinheiro] += 8000;
        case 12: GivePlayerWeapon(playerid, 10, 1);
        case 13: GivePlayerWeapon(playerid, 10, 1);
        case 14: Jogador[playerid][Level] += 2;
        case 15: Jogador[playerid][Experiencia] += 2;
        case 16: Jogador[playerid][Level] += 1;
        case 17: Jogador[playerid][Vasos] += 10;
        case 18: Jogador[playerid][Sementes] += 10;
        case 19: Jogador[playerid][Dinamites] += 15;

        // Raros
        case 20: Jogador[playerid][Dinheiro] += 1000;
        case 21: Jogador[playerid][Dinheiro] += 1500;
        case 22: Jogador[playerid][Coins] += 100;
        case 23: Jogador[playerid][Coins] += 300;
        case 24: Jogador[playerid][Dinheiro] -= 1000;
        case 25: Jogador[playerid][Dinamites] += 2;
        case 26: Jogador[playerid][Vasos] += 5;
        case 27: Jogador[playerid][Sementes] += 5;
        case 28: GivePlayerWeapon(playerid, 10, 1);
        case 29: Jogador[playerid][PandoraCaixa] += 1;


        // Comuns
        case 30: Jogador[playerid][Dinheiro] += 200;
        case 31: Jogador[playerid][Dinheiro] += 500;
        case 32: Jogador[playerid][Vasos] += 1;
        case 33: Jogador[playerid][Sementes] += 1;
        case 34: Jogador[playerid][Creditos] += 1;
        case 35: Jogador[playerid][Dinheiro] -= 500;
        case 36: Jogador[playerid][Dinheiro] -= 100;
        case 37: Jogador[playerid][Dinheiro] += 1;
        case 38: Jogador[playerid][Dinheiro] += 5;
        case 39: Jogador[playerid][Dinheiro] -= 5;
        case 40:
        {
            TogglePlayerControllable(playerid, 0);
            SetTimerEx("Destravar", 5000, false, "d", playerid);
        }
        case 41: SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_BEER);
    }


    return 1;
}

CMD:abrircaixa(playerid)
{
    if(Jogador[playerid][PandoraCaixa] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não possui nenhuma caixa");
    Jogador[playerid][PandoraCaixa] -= 1;
    new idc = random(sizeof(Presentes)),
        Mensagem[128];

    if(random(100) > Presentes[idc][Prt]) return SendClientMessage(playerid, 0xFF4500FF, "| CAIXA | Você tentou abrir uma caixa mas a chave acabou quebrando, tente novamente com outra");
    else format(Mensagem, sizeof(Mensagem), "| CAIXA | Você abriu uma caixa {%06x}%s{FFFFFF} e ganhou %s", StrToHex(Raridade[Presentes[idc][Rarid]][CorR]) >>> 8, Raridade[Presentes[idc][Rarid]][RaridadeN], Presentes[idc][PresenteR]);
    SendClientMessage(playerid, -1, Mensagem);
    EnviarPresenteCaixa(playerid, idc);
    return 1;
}