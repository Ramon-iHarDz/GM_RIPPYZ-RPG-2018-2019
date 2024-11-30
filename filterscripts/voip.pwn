#include <a_samp>
#include <streamer>
#include <sampvoice>

///new SV_GSTREAM:gstream = SV_NULL;
new SV_LSTREAM:lstream[MAX_PLAYERS] = { SV_NULL, ... };
//new Text3D:VoipTexto[MAX_PLAYERS];

public SV_VOID:OnPlayerActivationKeyPress(SV_UINT:playerid, SV_UINT:keyid)
{
    // Local - B
    if(keyid == 0x42 && lstream[playerid]){
        //if(CallRemoteFunction("OnPlayerVoip", "dd", playerid, 0)){
        SvAttachSpeakerToStream(lstream[playerid], playerid);
            //UpdateDynamic3DTextLabelText(VoipTexto[playerid], -1, "Voip [{32CD32}Falando{FFFFFF}]");
        //}
    }

    /*// Global - Z
    if(keyid == 0x5A && gstream){
        //if(CallRemoteFunction("OnPlayerVoip", "dd", playerid, 1)){
        SvAttachSpeakerToStream(gstream, playerid);
        //    UpdateDynamic3DTextLabelText(VoipTexto[playerid], -1, "Voip [{FFA500}Global{FFFFFF}]");
        //}
    }*/
}

public SV_VOID:OnPlayerActivationKeyRelease(SV_UINT:playerid, SV_UINT:keyid)
{
    // Desativar o VOIP Local - B
    if(keyid == 0x42 && lstream[playerid]){
        SvDetachSpeakerFromStream(lstream[playerid], playerid);
        //UpdateDynamic3DTextLabelText(VoipTexto[playerid], -1, "Voip [{1E90FF}Calado(a){FFFFFF}]");
    }
    
    /*// Desativar o VOIP Global - Z
    if(keyid == 0x5A && gstream){
        SvDetachSpeakerFromStream(gstream, playerid);
        //UpdateDynamic3DTextLabelText(VoipTexto[playerid], -1, "Voip [{1E90FF}Calado(a){FFFFFF}]");
    }*/
}

public OnPlayerSpawn(playerid)
{
    if(GetPVarInt(playerid, "LDPLASDPLASPDAS") == 1) return 1;
    SetPVarInt(playerid, "LDPLASDPLASPDAS", 1);

    // Verificar o plugin do Sampvoice
    if(SvGetVersion(playerid) == SV_NULL) SendClientMessage(playerid, 0xFF4500FF, "| VOIP | Você pode instalar nosso VOIP acessando nosso discord ( /Ajuda > Contato )");
    
    // Verificar microfone
    else if(SvHasMicro(playerid) == SV_FALSE) SendClientMessage(playerid, 0xFF4500FF, "| VOIP | Seu microfone não foi encontrado, verifique seu computador.");
    
    // Verificar se tem VOIP
    else
    {
        lstream[playerid] = SvCreateDLStreamAtPlayer(40.0, SV_INFINITY, playerid, 0xff0000ff, "Local");
        SendClientMessage(playerid, -1, "| VOIP | Você pode utilizar o VOIP apertando a tecla: {FFA500}B");
        //if(gstream) SvAttachListenerToStream(gstream, playerid);
        SvAddKey(playerid, 0x42);
        //SvAddKey(playerid, 0x5A);
        //VoipTexto[playerid] = CreateDynamic3DTextLabel("Voip [{1E90FF}Calado(a){FFFFFF}]", -1, 0.0, 0.0, 0.5, 35.0, playerid, INVALID_VEHICLE_ID, 1, -1, -1, -1, 36.0, -1);
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    if(lstream[playerid])
    {
        SvDeleteStream(lstream[playerid]);
        lstream[playerid] = SV_NULL;
        //DestroyDynamic3DTextLabel(VoipTexto[playerid]);
    }
}

/*public OnGameModeInit()
{
    // Uncomment the line to enable debug mode
    //SvDebug(SV_TRUE);
    gstream = SvCreateGStream(0xffff0000, "Admin");
}

public OnGameModeExit()
{
    if(gstream) SvDeleteStream(gstream);
}*/