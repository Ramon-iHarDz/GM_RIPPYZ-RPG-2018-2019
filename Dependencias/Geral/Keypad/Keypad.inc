#include <YSI_Coding\y_hooks>
#include "../Dependencias/Geral/Keypad/Modulos/Keypaddraw"

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid){
    if(playertextid == KeypadTextDraw[playerid][14]) CancelarKeypad(playerid); // Cancelar
    else if(playertextid == KeypadTextDraw[playerid][11]) ConfirmarKeypad(playerid); // Confirmar
    else if(playertextid == KeypadTextDraw[playerid][12]) ApagarKeypad(playerid); // Apagar

    // KeyPads
    else if(playertextid == KeypadTextDraw[playerid][15]) AdicionarNumeroKeypad(playerid, 1);
    else if(playertextid == KeypadTextDraw[playerid][16]) AdicionarNumeroKeypad(playerid, 2);
    else if(playertextid == KeypadTextDraw[playerid][19]) AdicionarNumeroKeypad(playerid, 3);
    else if(playertextid == KeypadTextDraw[playerid][20]) AdicionarNumeroKeypad(playerid, 4);
    else if(playertextid == KeypadTextDraw[playerid][21]) AdicionarNumeroKeypad(playerid, 5);
    else if(playertextid == KeypadTextDraw[playerid][22]) AdicionarNumeroKeypad(playerid, 6);
    else if(playertextid == KeypadTextDraw[playerid][23]) AdicionarNumeroKeypad(playerid, 7);
    else if(playertextid == KeypadTextDraw[playerid][24]) AdicionarNumeroKeypad(playerid, 8);
    else if(playertextid == KeypadTextDraw[playerid][25]) AdicionarNumeroKeypad(playerid, 9);
    else if(playertextid == KeypadTextDraw[playerid][26]) AdicionarNumeroKeypad(playerid, 0);
    return 0;
}

function OnPlayerKeypad(playerid, keypad, const Nsadas[]){
    return 1;
}

stock Keypad(playerid, bool:tavv, const ConfirmKeypad[] = "*", const CancelKeypad[] = "*", const NomePad[] = "Keypad") 
{
    MostrarKeypad(playerid, tavv);
    DeletePVar(playerid, "KeypadNumeros");
    SetPVarString(playerid, "KeypadCancel", CancelKeypad);
    SetPVarString(playerid, "KeypadConfirm", ConfirmKeypad);
    PlayerTextDrawSetString(playerid, KeypadTextDraw[playerid][28], ConverterTexto(NomePad));    
    return 1;
}

stock CancelarKeypad(playerid){
    new ppad[40];
    GetPVarString(playerid, "KeypadCancel", ppad, 40);
    if(!strcmp(ppad, "*")) return 1;
    OcultarKeypad(playerid);
    CallRemoteFunction(ppad, "d", playerid);
    return 1;
}

stock ConfirmarKeypad(playerid){
    new njka[30],
        nbak[30];
    GetPVarString(playerid, "KeypadNumeros", njka, 30);
    GetPVarString(playerid, "KeypadConfirm", nbak, 30);

    if(!strcmp(nbak, "*")){
        if(CallRemoteFunction("OnPlayerKeypad", "dds", playerid, 1, njka)) OcultarKeypad(playerid);
    }
    else if(CallRemoteFunction(nbak, "dds", playerid, 1, njka)) OcultarKeypad(playerid);
    return 1;
}

stock ApagarKeypad(playerid){
    new njka[30];
    GetPVarString(playerid, "KeypadNumeros", njka, 30);
    if(strlen(njka) < 1) return 1;
    strdel(njka, strlen(njka)-1, strlen(njka));
    if(strlen(njka) < 1) format(njka, sizeof(njka), "....");
    else format(njka, sizeof(njka), "%s", njka);
    SetPVarString(playerid, "KeypadNumeros", njka);
    if(!strcmp(njka, "....")) DeletePVar(playerid, "KeypadNumeros");
    PlayerTextDrawSetString(playerid, KeypadTextDraw[playerid][27], ConverterTexto(njka));
    return 1;
}

stock AdicionarNumeroKeypad(playerid, nub)
{
    new nba[30],
        njka[30];
    GetPVarString(playerid, "KeypadNumeros", njka, 30);
    if(strlen(njka) >= 11) return 1;
    format(nba, sizeof(nba), "%s%d", njka, nub);
    SetPVarString(playerid, "KeypadNumeros", nba);
    PlayerTextDrawSetString(playerid, KeypadTextDraw[playerid][27], ConverterTexto(nba));
    return 1;
}