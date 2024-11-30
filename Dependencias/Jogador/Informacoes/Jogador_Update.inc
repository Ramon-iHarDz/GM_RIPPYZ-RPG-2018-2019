#include <YSI_Coding\y_hooks>

hook OnPlayerDeath(playerid, killerid, reason)
{
    cDados[playerid][Morreu] = true;
    Hospital(1, playerid);
    ResetPlayerWeapons(playerid);
    SendDeathMessage(killerid, playerid, reason);  
    if(pModo[playerid][Jogando] == false && killerid != INVALID_PLAYER_ID && GetPVarInt(playerid, "BaseDMM") == 0)
    {
        new Mensagem[198];
        if(Jogador[playerid][Contratado] == true && !strcmp(Jogador[killerid][Profissao], "Assassino")) return 1;
        else if(IsMafia(killerid) && IsPolicia(playerid))
        {
            format(Mensagem, sizeof(Mensagem), "| PROCURADO | O(A) Jogador(a) %s[%d] ganhou +10 estrelas de procurados por matar o(a) policial %s[%d]", PegarNick(killerid), killerid, PegarNick(playerid), playerid);
            Jogador[killerid][Estrelas] += 10;
        }
        else if(IsPolicia(killerid) && pPolicia[killerid][PegouUniformePolicia] == true && Jogador[playerid][Estrelas] > 0) return 1;
        else
        {
            format(Mensagem, sizeof(Mensagem), "| PROCURADO | O(A) Jogador(a) %s[%d] ganhou +5 estrelas de procurados por matar %s[%d]", PegarNick(killerid), killerid, PegarNick(playerid), playerid);
            Jogador[killerid][Estrelas] += 5;
        }
        ProxDetector(40.0, playerid, Mensagem, -1,-1,-1,-1,-1);
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    if(cDados[playerid][Set] == false){
        cDados[playerid][TagUsuario] = SetTimerEx("TagJogador", 1000, true, "d", playerid);
        cDados[playerid][UpdateJogador] = SetTimerEx("JogadorUpdate", 1000, true, "d", playerid);
        cDados[playerid][TimerRapido] = SetTimerEx("VeiculoUpdateExx", 500, true, "d", playerid);
        cDados[playerid][Set] = true;
        DebugCasa(playerid);
    }

    // new Mensagem[10];
    // JogadoresOn++;
    // format(Mensagem, sizeof(Mensagem), "%d/500", JogadoresOn);
    // DCC_SetBotActivity(ConverterTexto(Mensagem));

    return 1;
}

function VoltarJogoNormal(playerid)
{
    SetPVarInt(playerid, "NaAnimacaoGTA", 0);
    SetCameraBehindPlayer(playerid);
    TogglePlayerControllable(playerid, 1);
	return 1;
}

function AnimacaoGTAV(playerid)
{
    SetPVarInt(playerid, "AnimacaoVV", 0);
    SetPVarInt(playerid, "NaAnimacaoGTA", 1);
    TogglePlayerControllable(playerid, 0);
    SetCameraBehindPlayer(playerid);

	new Float:cPos[3],
		Float:fVX, Float:fVY, Float:fVZ,
		Float:object_x, Float:object_y, Float:object_z, Float:object_zE;
	const Float:fScale = 5.0;

	GetPlayerCameraPos(playerid, cPos[0], cPos[1], cPos[2]);
	GetPlayerCameraFrontVector(playerid, fVX, fVY, fVZ);

	object_x = cPos[0] + floatmul(fVX, fScale);
	object_y = cPos[1] + floatmul(fVY, fScale);
	object_z = cPos[2] + floatmul(fVZ, fScale);
	object_zE = cPos[2] + floatmul(fVZ-5.0, fScale);

	InterpolateCameraPos(playerid, cPos[0], cPos[1], cPos[2]+60, cPos[0], cPos[1], cPos[2], 6000);
	InterpolateCameraLookAt(playerid, object_x, object_y, object_zE, object_x, object_y, object_z, 6000, CAMERA_MOVE);
	new id = SetTimerEx("VoltarJogoNormal", 5000, false, "d", playerid);
    SetPVarInt(playerid, "TimerGtaV", id);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if(GetPVarInt(playerid, "PreLoad") == 0){
        SetPVarInt(playerid, "PreLoad", 1);
        PreLoadAnim(playerid); // Pre carregar animações
        if(ServidorBeta == true) MostrarMarca(playerid);

        //if(NatalGorroID == 19064){
        //    cDados[playerid][NatalNeve] = CreateDynamicObject(18864, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1, 0, playerid, 9999.9, 9999.9, -1);
        //}
    }

    if(Jogador[playerid][SkinProfissao] == -1) SetPlayerSkin(playerid, Jogador[playerid][Skin]);
    else SetPlayerSkin(playerid, Jogador[playerid][SkinProfissao]);
    if(pModo[playerid][Jogando] == false) VerificarAcessorios(playerid);
    if(cDados[playerid][Morreu] == true)
    {
        SetPVarInt(playerid, "AntiFakeStatus", 1);
        if(Jogador[playerid][Preso] > gettime()) ColocarNaCadeia(playerid);
        else if(GetPVarInt(playerid, "BaseDMM") == 1) RespawnBase(playerid);
        else if(pModo[playerid][Jogando] == false && pAbordado[playerid][Acompanhando] == false) Hospital(3, playerid);
        cDados[playerid][Morreu] = false;

        if(pAbordado[playerid][Acompanhando] == true || GetPVarInt(playerid, "AntiAbordagem") > gettime())
        {
            new id = pAbordado[playerid][APolicial];
            if(pAbordado[playerid][Acompanhando] == true || pAbordado[playerid][SeRendeu] == true || pAbordado[playerid][Algemado] == true){
                KillTimer(pAbordado[playerid][TempoAbordado]);
            }
            EnviarCadeia(playerid, id);
        }
    }

    /*if(GetPVarInt(playerid, "JogoAoNormalV") == 0){ 
        TogglePlayerControllable(playerid, 0);
        SetPVarInt(playerid, "JogoAoNormalV", 1);
        SetPVarInt(playerid, "AnimacaoVV", 1);
        new id = SetTimerEx("AnimacaoGTAV", 5000, false, "d", playerid);
        SetPVarInt(playerid, "TimerVV", id);
        //AnimacaoGTAV(playerid);
    }*/

    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(GetPVarInt(playerid, "NaAnimacaoGTA") == 1) KillTimer(GetPVarInt(playerid, "TimerGtaV"));
    if(GetPVarInt(playerid, "AnimacaoVV") == 1) KillTimer(GetPVarInt(playerid, "TimerVV"));

    VerificarMarcacao(playerid);
    //if(NatalGorroID == 19064) DestroyDynamicObjectEx(cDados[playerid][NatalNeve]);
    if(cDados[playerid][Set] == true)
    {
        KillTimer(cDados[playerid][TagUsuario]);
        KillTimer(cDados[playerid][UpdateJogador]);
        KillTimer(cDados[playerid][TimerRapido]);
    }

    // new Mensagem[10];
    // JogadoresOn--;
    //format(Mensagem, sizeof(Mensagem), "%d/500", JogadoresOn);
    // DCC_SetBotActivity(ConverterTexto(Mensagem));

    new Limpar[ConfigJogador];
    cDados[playerid] = Limpar;
    return 1;
}

function JogadorUpdate(playerid)
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "JogadorUpdate", 1)) return 1;
    new XP,
        StatusS[30];

    //Atualizar Procurados
    if(Jogador[playerid][Estrelas] > 500) Jogador[playerid][Estrelas] = 500;
    format(StatusS, sizeof(StatusS), "%d", Jogador[playerid][Estrelas]);
    PlayerTextDrawSetString(playerid, StatusTxd[playerid][7], StatusS);

    // Sistema para atualizar o Status
    if(Jogador[playerid][RelogioUP] == true)
    {
        if(Jogador[playerid][EstadoAFK] == true) PlayerTextDrawSetString(playerid, StatusTxd[playerid][8], "~r~+~w~EXP_~y~Pausado");
        else if(Jogador[playerid][Preso] == 0 || Jogador[playerid][CadeiaEstilo] == 1){
            format(StatusS, sizeof(StatusS), "~r~+~w~EXP_~b~%s", SegundosParaMinutosEx(Jogador[playerid][TempoUp]));
            PlayerTextDrawSetString(playerid, StatusTxd[playerid][8], StatusS);
        }
        else PlayerTextDrawSetString(playerid, StatusTxd[playerid][8], "~y~+~w~EXP_~r~Pausado");
    }else PlayerTextDrawSetString(playerid, StatusTxd[playerid][8], "~y~+~w~EXP_~y~N/A");
    
    // Sistema para expirar o VIP
    if(Jogador[playerid][Vip] < gettime() && Jogador[playerid][Vip] != 0){
        SendClientMessage(playerid, 0xFF7F50FF, "| VIP | Seu VIP expirou, acesse nosso discord/site para obter mais!");
        Jogador[playerid][Vip] = 0;
        // VerificarTags(playerid);
    }

    // Sistema de Remoção da Prisão
    if(Jogador[playerid][Preso] == 1 || Jogador[playerid][Preso] < 0)
    {
        Jogador[playerid][Preso] = 0;
        RemoverDaCadeia(playerid); 
    }
    else if(Jogador[playerid][Preso] != 0)
    {
        Jogador[playerid][Preso]--; 
        SetPlayerHealth(playerid, 999.0);
        PlayerTextDrawSetString(playerid, Federal[playerid][2], SegundosParaMinutos(Jogador[playerid][Preso])); 
    }

    // Sistema de UP //
    if(Jogador[playerid][Vip] > gettime()) XP = 5;
    else XP = 6;

    if(Jogador[playerid][Experiencia] >= XP){
        Jogador[playerid][Level]++;
        PlayerPlaySound(playerid, 1057, 0, 0, 0);
        new Mensagem[128];
        format(Mensagem, sizeof(Mensagem), "| EXP | Você upou para o level {00BFFF}%d", Jogador[playerid][Level]);
        SendClientMessage(playerid, -1, Mensagem);
        Jogador[playerid][TempoUp] = 600;
        Jogador[playerid][Experiencia] = 0;
        DarSalario(playerid);
        DarRecompensaUP(playerid);
    }

    if(Jogador[playerid][EstadoAFK] == false){
        if(Jogador[playerid][Preso] == 0 || Jogador[playerid][CadeiaEstilo] == 1){
            Jogador[playerid][TempoUp]--;
            if(Jogador[playerid][TempoUp] <= 0){
                Jogador[playerid][Experiencia]++;
                new Mensagem[128];
                format(Mensagem, sizeof(Mensagem), "| EXP | Você ganhou {00BFFF}+1{FFFFFF} de experiência ( %d/%d )", Jogador[playerid][Experiencia], XP);  
                SendClientMessage(playerid, -1, Mensagem);
                Jogador[playerid][TempoUp] = 600;
                PlayerPlaySound(playerid, 1057, 0, 0, 0);
                GameTextForPlayer(playerid, "~w~UP!", 6000, 6);
            }
        } 
    }
    return 1;
}

function TagJogador(playerid)
{
    if(Jogador[playerid][Logado] == false) return 1;
    if(TravarCodigo(playerid, "TagJogador", 1)) return 1;
    if(GetPVarInt(playerid, "EventoJogador") > 0) return 1;
    if(Jogador[playerid][Admin] > 0 && pAdmin[playerid][Camuflado] == false)
    {
        switch(Jogador[playerid][Admin])
        { 
            case 1: SetPlayerChatBubble(playerid, "Aprendiz", 0x6af3afFF, 30.0, 2000);
            case 2: SetPlayerChatBubble(playerid, "Ajudante", 0xf2b138FF, 30.0, 2000);
            case 3: SetPlayerChatBubble(playerid, "Moderador(a)", 0xf7960fFF, 30.0, 2000);
            case 4: SetPlayerChatBubble(playerid, "Administrador(a)", 0x25b2e6FF, 30.0, 2000);
            case 5: SetPlayerChatBubble(playerid, "Coordenador(a)", 0x9c27cfFF, 30.0, 2000);
            case 6: SetPlayerChatBubble(playerid, "Diretor(a)", 0xFF0000FF, 30.0, 2000);
            case 7: SetPlayerChatBubble(playerid, "Desenvolvedor(a)", 0x1eec3eFF, 30.0, 2000);
        }
    }
    else if(Jogador[playerid][EstadoAFK] == true)
    {
        new Enviar[90];
        format(Enviar, sizeof(Enviar), "Ausente: %s", SegundosParaMinutosEx(pAFK[playerid][TempoKickAfk]));
        SetPlayerChatBubble(playerid, Enviar, -1, 30.0, 2000);
    }
    else if(Jogador[playerid][TagPersonalizada] > 0)
    {
        switch(Jogador[playerid][TagPersonalizada])
        {
            case 1: SetPlayerChatBubble(playerid, "YouTuber", 0xFF0000FF, 30.0, 2000);
            case 2: SetPlayerChatBubble(playerid, "Locutor(a)", 0xad2ec9FF, 30.0, 2000);
            case 3: SetPlayerChatBubble(playerid, "Beta Tester", 0xFF4500FF, 30.0, 2000);
            case 4: SetPlayerChatBubble(playerid, "Aguardando", 0x0AFA9AFF, 30.0, 2000);
            case 5: SetPlayerChatBubble(playerid, "Streamer", 0x9932CCFF, 30.0, 2000);
            case 6: SetPlayerChatBubble(playerid, "Girl", 0xFF69B4FF, 30.0, 2000);
        }
    }
    else if(Jogador[playerid][Vip] > gettime())
    {
        new vCor[200];
        if(Jogador[playerid][BaseID] > 0) format(vCor, sizeof(vCor), "{%06x}VIP{FFFFFF} {%06x}[%s]", StrToHex(IntToHex(Jogador[playerid][CorVIP])) >>> 8, StrToHex(IntToHex(Base[Jogador[playerid][BaseID]][BaseTagCor])) >>> 8, Base[Jogador[playerid][BaseID]][BaseTag]);
        else format(vCor, sizeof(vCor), "{%06x}VIP", StrToHex(IntToHex(Jogador[playerid][CorVIP])) >>> 8);
        SetPlayerChatBubble(playerid, vCor, -1, 30.0, 2000);
    }
    else if(Jogador[playerid][BaseID] > 0)
    {
        new vSSBase[128];
        format(vSSBase, sizeof(vSSBase), "{%06x}[%s]", StrToHex(IntToHex(Base[Jogador[playerid][BaseID]][BaseTagCor])) >>> 8, Base[Jogador[playerid][BaseID]][BaseTag]);
        SetPlayerChatBubble(playerid, vSSBase, -1, 30.0, 2000);   
    }
    else if(Jogador[playerid][Level] < 11) SetPlayerChatBubble(playerid, "Novato(a)", 0xFFFF00FF, 30.0, 2000);
    return 1; 
}

/*CMD:evento(playerid)
{
    if(GetPVarInt(playerid, "DASDASDSADAS") > gettime()) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Aguarde.");
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(strcmp(PegarCidade(x, y), "Las Venturas")) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não está em Las Venturas");
    GivePlayerWeapon(playerid, 31, 999);
    GivePlayerWeapon(playerid, 26, 999);
    SetPVarInt(playerid, "DASDASDSADAS", gettime()+15);
    SendClientMessage(playerid, 0xFFFF00FF, "| EVENTO | Você pegou as armas do evento");
    return 1;
}*/