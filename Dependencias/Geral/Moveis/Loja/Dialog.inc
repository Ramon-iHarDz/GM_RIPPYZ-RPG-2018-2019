Dialog:QuartoLoja(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 0); // Camas
        case 1: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 1); // Abajures
        case 2: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 2); // Guarda Roupas
        case 3: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 3); // Criado Mudo
    }
    return 1;
}

Dialog:EletronicoLoja(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 4); // Mesas de Escritório
        case 1: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 5); // Cadeiras de Escritório
        case 2: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 6); // Vídeo Games
        case 3: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 7); // Rádios
        case 4: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 8); // Computadores
        case 5: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 9); // Televisões
        case 6: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 10); // Equipamentos de Treinos
        case 7: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 11); // Outros
    }
    return 1;
}

Dialog:SalaLoja(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 12); // Sofas
        case 1: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 13); // Centros e Mesas
        case 2: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 14); // Quadros
        case 3: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 23); // Outros
    }
    return 1;
}

Dialog:BanheiroLoja(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 15); // Boxes e Banheiras
        case 1: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 16); // Pias
        case 2: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 17); // Outros
    }
    return 1;
}

Dialog:CozinhaLoja(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 18); // Cadeiras
        case 1: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 19); // Mesas
        case 2: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 20); // Eletrônicos
        case 3: RequestLoja(playerid, GetPVarInt(playerid, "MoveisSlot"), 21); // Outros 
    }
    return 1;
}