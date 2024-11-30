stock AtualizarLixeira(LixeiraID)
{
    DestroyDynamic3DTextLabelEx(Lixo[LixeiraID][LixoTexto]);
    new LixoAA[228];
    format(LixoAA, sizeof(LixoAA), "Lixo(s) {6ff542}%d{FFFFFF} / {00FF00}%d\n{FFFFFF}Aperte {CCCCCC}'N'{FFFFFF} para coletar", Lixo[LixeiraID][LixoAtual], Lixo[LixeiraID][LixoMaximo]);
    Lixo[LixeiraID][LixoTexto] = CreateDynamic3DTextLabel(LixoAA, 0xFFFFFFFF, Lixo[LixeiraID][PosX], Lixo[LixeiraID][PosY], Lixo[LixeiraID][PosZ]+1, 18.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
    return 1;
}

function ResetarLixos(LixeiraID)
{
    Lixo[LixeiraID][LixoAtual]++;
    AtualizarLixeira(LixeiraID);
    if(Lixo[LixeiraID][LixoAtual] != Lixo[LixeiraID][LixoMaximo]) SetTimerEx("ResetarLixos", 180000, false, "i", LixeiraID);
    return 1;
}