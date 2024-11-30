stock EnviarComida(playerid, id, Float:quantidade)
{
    new Float:Vffa;
    GetPlayerHealth(playerid, Vffa);
    Vffa += 20.0;
    if(Vffa > 100.0) Vffa = 100.0;
    SetPlayerHealth(playerid, Vffa);

    // Fome
    if(id == 1)
    {
        Jogador[playerid][Fome] += quantidade;
        if(Jogador[playerid][Fome] > 100) Jogador[playerid][Fome] = 100;
        AtualizarStatus(playerid);
    }

    // Sede
    else if(id == 2)
    {
        Jogador[playerid][Sede] += quantidade;
        if(Jogador[playerid][Sede] > 100) Jogador[playerid][Sede] = 100;
        AtualizarStatus(playerid);  
    }
    return 1;
}

Dialog:RestauranteMenu(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    //if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de comidas nessa empresa");

    new i = listitem;
    if(Restaurante[i][QuantidadeComida] == 0.0) return 1;
    if(Jogador[playerid][Dinheiro] < Restaurante[i][PrecoComida]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente!");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= Restaurante[i][PrecoComida];
    EnviarDinheiroEmpresaEx(id, Restaurante[i][PrecoComida], true); 
    if(Restaurante[i][ComidaEstiloID] == 1) ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
    else ApplyAnimation(playerid, "VENDING", "VEND_Drink_P", 3.0, 0, 0, 0, 0, 0);
    format(Mensagem, sizeof(Mensagem), "| RESTAURANTE | Você comprou um(a) {00BFFF}%s{FFFFFF} por {32CD32}$%d", Restaurante[i][NomeComida], Restaurante[i][PrecoComida]);
    SendClientMessage(playerid, -1, Mensagem);
    EnviarComida(playerid, Restaurante[i][ComidaEstiloID], Restaurante[i][QuantidadeComida]);
    //pEmpresa[id][eEstoque]--;

    return 0;
}

Dialog:PizzariasMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    //if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de comidas nessa empresa");

    new i = listitem;
    if(Pizzarias[i][QuantidadeComida] == 0.0) return 1;
    if(Jogador[playerid][Dinheiro] < Pizzarias[i][PrecoComida]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente!");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= Pizzarias[i][PrecoComida];
    EnviarDinheiroEmpresaEx(id, Pizzarias[i][PrecoComida], true); 
    if(Pizzarias[i][ComidaEstiloID] == 1) ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
    else ApplyAnimation(playerid, "VENDING", "VEND_Drink_P", 3.0, 0, 0, 0, 0, 0);
    format(Mensagem, sizeof(Mensagem), "| PIZZARIA | Você comprou um(a) {00BFFF}%s{FFFFFF} por {32CD32}$%d", Pizzarias[i][NomeComida], Pizzarias[i][PrecoComida]);
    SendClientMessage(playerid, -1, Mensagem);
    EnviarComida(playerid, Pizzarias[i][ComidaEstiloID], Pizzarias[i][QuantidadeComida]);
    //pEmpresa[id][eEstoque]--;

    return 0;
}

Dialog:HamburgueriaMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    //if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de comidas nessa empresa");

    new i = listitem;
    if(Hamburgueria[i][QuantidadeComida] == 0.0) return 1;
    if(Jogador[playerid][Dinheiro] < Hamburgueria[i][PrecoComida]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente!");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= Hamburgueria[i][PrecoComida];
    EnviarDinheiroEmpresaEx(id, Hamburgueria[i][PrecoComida], true); 
    if(Hamburgueria[i][ComidaEstiloID] == 1) ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
    else ApplyAnimation(playerid, "VENDING", "VEND_Drink_P", 3.0, 0, 0, 0, 0, 0);
    format(Mensagem, sizeof(Mensagem), "| HAMBURGUERIA | Você comprou um(a) {00BFFF}%s{FFFFFF} por {32CD32}$%d", Hamburgueria[i][NomeComida], Hamburgueria[i][PrecoComida]);
    SendClientMessage(playerid, -1, Mensagem); 
    EnviarComida(playerid, Hamburgueria[i][ComidaEstiloID], Hamburgueria[i][QuantidadeComida]);
    //pEmpresa[id][eEstoque]--;

    return 0;
}

Dialog:BaresMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    //if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de comidas nessa empresa");

    new i = listitem;
    if(Bares[i][QuantidadeComida] == 0.0) return 1;
    if(Jogador[playerid][Dinheiro] < Bares[i][PrecoComida]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente!");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= Bares[i][PrecoComida];
    EnviarDinheiroEmpresaEx(id, Bares[i][PrecoComida], true); 
    if(Bares[i][ComidaEstiloID] == 1) ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
    else ApplyAnimation(playerid, "VENDING", "VEND_Drink_P", 3.0, 0, 0, 0, 0, 0);
    format(Mensagem, sizeof(Mensagem), "| BAR | Você comprou um(a) {00BFFF}%s{FFFFFF} por {32CD32}$%d", Bares[i][NomeComida], Bares[i][PrecoComida]);
    SendClientMessage(playerid, -1, Mensagem);
    EnviarComida(playerid, Bares[i][ComidaEstiloID], Bares[i][QuantidadeComida]);
    //pEmpresa[id][eEstoque]--;

    return 0;
}

Dialog:DonaldsMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new id = GetPVarInt(playerid, "InteriorPersonalizadoID");
    //if(pEmpresa[id][eEstoque] < 1) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Não há estoque de comidas nessa empresa");

    new i = listitem;
    if(Donalds[i][QuantidadeComida] == 0.0) return 1;
    if(Jogador[playerid][Dinheiro] < Donalds[i][PrecoComida]) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente!");
    new Mensagem[128];
    Jogador[playerid][Dinheiro] -= Donalds[i][PrecoComida];
    EnviarDinheiroEmpresaEx(id, Donalds[i][PrecoComida], true); 
    if(Donalds[i][ComidaEstiloID] == 1) ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
    else ApplyAnimation(playerid, "VENDING", "VEND_Drink_P", 3.0, 0, 0, 0, 0, 0);
    format(Mensagem, sizeof(Mensagem), "| ROSQUINHA | Você comprou um(a) {00BFFF}%s{FFFFFF} por {32CD32}$%d", Donalds[i][NomeComida], Donalds[i][PrecoComida]);
    SendClientMessage(playerid, -1, Mensagem);
    EnviarComida(playerid, Donalds[i][ComidaEstiloID], Donalds[i][QuantidadeComida]);
    //pEmpresa[id][eEstoque]--;
    return 0;
}