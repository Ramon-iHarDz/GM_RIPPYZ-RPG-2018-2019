stock MostrarRVS()
{
    RespawnAdmin[0] = TextDrawCreate(314.375000, 426.249664, "Respawn_de_veiculos_em_30_segundos");
    TextDrawLetterSize(RespawnAdmin[0], 0.349999, 1.174165);
    TextDrawTextSize(RespawnAdmin[0], 0.000000, 226.000000);
    TextDrawAlignment(RespawnAdmin[0], 2);
    TextDrawColor(RespawnAdmin[0], -1);
    TextDrawUseBox(RespawnAdmin[0], 1);
    TextDrawBoxColor(RespawnAdmin[0], -16777151);
    TextDrawSetShadow(RespawnAdmin[0], 0);
    TextDrawSetOutline(RespawnAdmin[0], 0);
    TextDrawBackgroundColor(RespawnAdmin[0], -16776961);
    TextDrawFont(RespawnAdmin[0], 1);
    TextDrawSetProportional(RespawnAdmin[0], 1);
    TextDrawSetShadow(RespawnAdmin[0], 0);
    TextDrawShowForAll(RespawnAdmin[0]);
    return 1;
}

function OcultarRVS()
{
    TextDrawDestroy(RespawnAdmin[0]);
    RespawnAdmin[0] = Text:INVALID_TEXT_DRAW;
    RespawnAtivo = false;
    EstadoRespawn = 0;
    return 1;
}

function OcultarRVSPos()
{
    TextDrawDestroy(RespawnAdmin[0]);
    RespawnAdmin[0] = Text:INVALID_TEXT_DRAW;
    return 1;
}