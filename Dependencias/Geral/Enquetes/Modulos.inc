new Text:EnqueteInf[12];

stock MostrarEnquete(playerid, const Msgg[])
{
    EnqueteInf[0] = TextDrawCreate(535.973571, 202.833328, "box");
    TextDrawLetterSize(EnqueteInf[0], 0.000000, 11.247814);
    TextDrawTextSize(EnqueteInf[0], 635.000000, 0.000000);
    TextDrawAlignment(EnqueteInf[0], 1);
    TextDrawColor(EnqueteInf[0], -1);
    TextDrawUseBox(EnqueteInf[0], 1);
    TextDrawBoxColor(EnqueteInf[0], 471604479);
    TextDrawSetShadow(EnqueteInf[0], 0);
    TextDrawBackgroundColor(EnqueteInf[0], 255);
    TextDrawFont(EnqueteInf[0], 1);
    TextDrawSetProportional(EnqueteInf[0], 1);

    EnqueteInf[1] = TextDrawCreate(535.873901, 202.782989, "box");
    TextDrawLetterSize(EnqueteInf[1], 0.000000, 0.822574);
    TextDrawTextSize(EnqueteInf[1], 635.000000, 0.000000);
    TextDrawAlignment(EnqueteInf[1], 1);
    TextDrawColor(EnqueteInf[1], -1);
    TextDrawUseBox(EnqueteInf[1], 1);
    TextDrawBoxColor(EnqueteInf[1], -5963521);
    TextDrawSetShadow(EnqueteInf[1], 0);
    TextDrawBackgroundColor(EnqueteInf[1], 255);
    TextDrawFont(EnqueteInf[1], 1);
    TextDrawSetProportional(EnqueteInf[1], 1);

    EnqueteInf[2] = TextDrawCreate(585.326049, 200.333374, "Enquete");
    TextDrawLetterSize(EnqueteInf[2], 0.243959, 1.121664);
    TextDrawAlignment(EnqueteInf[2], 2);
    TextDrawColor(EnqueteInf[2], -1);
    TextDrawUseBox(EnqueteInf[2], 0);
    TextDrawBoxColor(EnqueteInf[2], 0);
    TextDrawSetShadow(EnqueteInf[2], 1);
    TextDrawBackgroundColor(EnqueteInf[2], 74);
    TextDrawFont(EnqueteInf[2], 1);
    TextDrawSetProportional(EnqueteInf[2], 1);

    EnqueteInf[3] = TextDrawCreate(539.721923, 258.533477, "box");
    TextDrawLetterSize(EnqueteInf[3], 0.000000, 0.756281);
    TextDrawTextSize(EnqueteInf[3], 547.000000, 0.000000);
    TextDrawAlignment(EnqueteInf[3], 1);
    TextDrawColor(EnqueteInf[3], -1);
    TextDrawUseBox(EnqueteInf[3], 1);
    TextDrawBoxColor(EnqueteInf[3], 80);
    TextDrawSetShadow(EnqueteInf[3], 0);
    TextDrawBackgroundColor(EnqueteInf[3], 255);
    TextDrawFont(EnqueteInf[3], 1);
    TextDrawSetProportional(EnqueteInf[3], 1);

    EnqueteInf[4] = TextDrawCreate(585.936401, 216.633270, ConverterTexto(Msgg));
    TextDrawLetterSize(EnqueteInf[4], 0.182918, 0.870832);
    TextDrawAlignment(EnqueteInf[4], 2);
    TextDrawColor(EnqueteInf[4], -1);
    TextDrawUseBox(EnqueteInf[4], 0);
    TextDrawBoxColor(EnqueteInf[4], 0);
    TextDrawSetShadow(EnqueteInf[4], 0);
    TextDrawBackgroundColor(EnqueteInf[4], 255);
    TextDrawFont(EnqueteInf[4], 1);
    TextDrawSetProportional(EnqueteInf[4], 1);

    EnqueteInf[5] = TextDrawCreate(539.721923, 274.334472, "box");
    TextDrawLetterSize(EnqueteInf[5], 0.000000, 0.756281);
    TextDrawTextSize(EnqueteInf[5], 547.000000, 0.000000);
    TextDrawAlignment(EnqueteInf[5], 1);
    TextDrawColor(EnqueteInf[5], -1);
    TextDrawUseBox(EnqueteInf[5], 1);
    TextDrawBoxColor(EnqueteInf[5], 80);
    TextDrawSetShadow(EnqueteInf[5], 0);
    TextDrawBackgroundColor(EnqueteInf[5], 255);
    TextDrawFont(EnqueteInf[5], 1);
    TextDrawSetProportional(EnqueteInf[5], 1);

    EnqueteInf[6] = TextDrawCreate(551.566345, 257.599822, "Sim_(0)");
    TextDrawLetterSize(EnqueteInf[6], 0.225710, 0.969999);
    TextDrawAlignment(EnqueteInf[6], 1);
    TextDrawColor(EnqueteInf[6], -1);
    TextDrawUseBox(EnqueteInf[6], 0);
    TextDrawBoxColor(EnqueteInf[6], 0);
    TextDrawSetShadow(EnqueteInf[6], 0);
    TextDrawBackgroundColor(EnqueteInf[6], 255);
    TextDrawFont(EnqueteInf[6], 1);
    TextDrawSetProportional(EnqueteInf[6], 1);

    EnqueteInf[7] = TextDrawCreate(551.566345, 272.800689, ConverterTexto("Não_(0)"));
    TextDrawLetterSize(EnqueteInf[7], 0.221024, 0.964164);
    TextDrawAlignment(EnqueteInf[7], 1);
    TextDrawColor(EnqueteInf[7], -1);
    TextDrawUseBox(EnqueteInf[7], 0);
    TextDrawBoxColor(EnqueteInf[7], 0);
    TextDrawSetShadow(EnqueteInf[7], 0);
    TextDrawBackgroundColor(EnqueteInf[7], 255);
    TextDrawFont(EnqueteInf[7], 1);
    TextDrawSetProportional(EnqueteInf[7], 1);

    EnqueteInf[8] = TextDrawCreate(537.610778, 257.216491, "ld_chat:thumbup");
    TextDrawTextSize(EnqueteInf[8], 11.000000, 10.000000);
    TextDrawAlignment(EnqueteInf[8], 1);
    TextDrawColor(EnqueteInf[8], -1);
    TextDrawUseBox(EnqueteInf[8], 0);
    TextDrawBoxColor(EnqueteInf[8], 0);
    TextDrawSetShadow(EnqueteInf[8], 0);
    TextDrawBackgroundColor(EnqueteInf[8], 255);
    TextDrawFont(EnqueteInf[8], 4);
    TextDrawSetProportional(EnqueteInf[8], 0);
    TextDrawSetSelectable(EnqueteInf[8], true);

    EnqueteInf[9] = TextDrawCreate(537.679260, 272.634033, "ld_chat:thumbdn");
    TextDrawTextSize(EnqueteInf[9], 11.000000, 10.000000);
    TextDrawAlignment(EnqueteInf[9], 1);
    TextDrawColor(EnqueteInf[9], -1);
    TextDrawUseBox(EnqueteInf[9], 0);
    TextDrawBoxColor(EnqueteInf[9], 0);
    TextDrawSetShadow(EnqueteInf[9], 0);
    TextDrawBackgroundColor(EnqueteInf[9], 255);
    TextDrawFont(EnqueteInf[9], 4);
    TextDrawSetProportional(EnqueteInf[9], 0);
    TextDrawSetSelectable(EnqueteInf[9], true);

    new Mensagem[41];
    format(Mensagem, sizeof(Mensagem), "Criado por %s", PegarNick(playerid));
    EnqueteInf[10] = TextDrawCreate(585.384887, 292.317749, ConverterTexto(Mensagem));
    TextDrawLetterSize(EnqueteInf[10], 0.185883, 0.870831);
    TextDrawTextSize(EnqueteInf[10], 0.000000, 94.000000);
    TextDrawAlignment(EnqueteInf[10], 2);
    TextDrawColor(EnqueteInf[10], -1);
    TextDrawUseBox(EnqueteInf[10], 1);
    TextDrawBoxColor(EnqueteInf[10], -1523963137);
    TextDrawSetShadow(EnqueteInf[10], 1);
    TextDrawBackgroundColor(EnqueteInf[10], 70);
    TextDrawFont(EnqueteInf[10], 1);
    TextDrawSetProportional(EnqueteInf[10], 1);

    EnqueteInf[11] = TextDrawCreate(551.599609, 307.833435, "Para_votar_use:_/votar");
    TextDrawLetterSize(EnqueteInf[11], 0.171362, 0.812499);
    TextDrawAlignment(EnqueteInf[11], 1);
    TextDrawColor(EnqueteInf[11], -1);
    TextDrawUseBox(EnqueteInf[11], 0);
    TextDrawBoxColor(EnqueteInf[11], 0);
    TextDrawSetShadow(EnqueteInf[11], 0);
    TextDrawSetOutline(EnqueteInf[11], 1);
    TextDrawBackgroundColor(EnqueteInf[11], 255);
    TextDrawFont(EnqueteInf[11], 1);
    TextDrawSetProportional(EnqueteInf[11], 1);

    for(new i=0; i < 12; i++){
        TextDrawShowForAll(EnqueteInf[i]);
    }
    return 1;
}

stock OcultarEnquete()
{
    for(new i=0; i < 12; i++){
        TextDrawDestroy(EnqueteInf[i]);
        EnqueteInf[i] = Text:INVALID_TEXT_DRAW;
    }
    return 1;
}