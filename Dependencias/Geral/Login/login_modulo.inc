#include <YSI_Coding\y_hooks>

new PlayerText:LoginRC[MAX_PLAYERS][17];

new bool:EsperandoKick[MAX_PLAYERS];
new KickLoginTempo[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    if(EsperandoKick[playerid] == true){
        EsperandoKick[playerid] = false;
        KillTimer(KickLoginTempo[playerid]);
    }
    for(new i=0; i < 17; i++){
        LoginRC[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock LoginMensagem(id)
{
    new Texto[70];
    switch(id)
    {
        case 0: Texto = "Acesse_nosso_discord_e_fique_atento_nas_novidades!";
        case 1: Texto = "Lembre-se_de_ler_as_regras_do_servidor!";
        case 2: Texto = "Esta_gostando_do_servidor?_salve-o_nos_favoritos!";
        case 3: Texto = "Sabia_que_antes_o_nome_da_rippzy_era_rippyz?";
        case 4: Texto = "Sincronize_sua_conta_usando_~r~/discord";
    }
    return (Texto);
}

stock MostrarLogin(playerid)
{
    SetPVarInt(playerid, "LoginEtap1", GetTickCount());
    LoginRC[playerid][0] = CreatePlayerTextDraw(playerid, 248.770019, 119.999977, "box");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][0], 0.000000, 17.352823);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][0], 395.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][0], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, LoginRC[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, LoginRC[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][0], 255);
    PlayerTextDrawFont(playerid, LoginRC[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][0], 0);

    LoginRC[playerid][1] = CreatePlayerTextDraw(playerid, 248.644134, 119.916664, "box");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][1], 0.000000, 1.341999);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][1], 394.979614, 0.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][1], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, LoginRC[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, LoginRC[playerid][1], -2139062262);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][1], 255);
    PlayerTextDrawFont(playerid, LoginRC[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][1], 0);

    LoginRC[playerid][2] = CreatePlayerTextDraw(playerid, 258.609008, 150.333389, "box");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][2], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][2], 385.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][2], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, LoginRC[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, LoginRC[playerid][2], -2139062248);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][2], 255);
    PlayerTextDrawFont(playerid, LoginRC[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][2], 0);

    LoginRC[playerid][3] = CreatePlayerTextDraw(playerid, 258.609008, 150.333389, "box");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][3], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][3], 269.339538, 0.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][3], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, LoginRC[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, LoginRC[playerid][3], 471604370);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][3], 255);
    PlayerTextDrawFont(playerid, LoginRC[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][3], 0);

    LoginRC[playerid][4] = CreatePlayerTextDraw(playerid, 258.609008, 181.633407, "box");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][4], 0.000000, 1.193246);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][4], 385.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][4], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, LoginRC[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, LoginRC[playerid][4], -2139062248);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][4], 255);
    PlayerTextDrawFont(playerid, LoginRC[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][4], 0);

    LoginRC[playerid][5] = CreatePlayerTextDraw(playerid, 258.609008, 181.833175, "box");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][5], 0.000000, 1.183246);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][5], 269.339538, 0.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][5], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, LoginRC[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, LoginRC[playerid][5], 471604370);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][5], 255);
    PlayerTextDrawFont(playerid, LoginRC[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][5], 0);

    LoginRC[playerid][6] = CreatePlayerTextDraw(playerid, 301.707427, 120.949935, "Rippzy_City");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][6], 0.231330, 1.104162);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][6], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][6], 1);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][6], 83);
    PlayerTextDrawFont(playerid, LoginRC[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][6], 1);

    LoginRC[playerid][7] = CreatePlayerTextDraw(playerid, 250.844314, 148.416687, "");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][7], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][7], 24.000000, 15.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][7], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][7], 0);
    PlayerTextDrawFont(playerid, LoginRC[playerid][7], 5);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][7], 0);
    PlayerTextDrawSetPreviewModel(playerid, LoginRC[playerid][7], 1239);
    PlayerTextDrawSetPreviewRot(playerid, LoginRC[playerid][7], 0.000000, 0.000000, 180.000000, 1.000000);

    LoginRC[playerid][8] = CreatePlayerTextDraw(playerid, 251.844314, 178.016479, "");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][8], 24.000000, 18.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][8], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][8], 0);
    PlayerTextDrawFont(playerid, LoginRC[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][8], 0);
    PlayerTextDrawSetPreviewModel(playerid, LoginRC[playerid][8], 19804);
    PlayerTextDrawSetPreviewRot(playerid, LoginRC[playerid][8], 0.000000, 0.000000, 0.000000, 1.000000);

    LoginRC[playerid][9] = CreatePlayerTextDraw(playerid, 275.944274, 149.749969, PegarNick(playerid));
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][9], 0.264126, 1.250000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][9], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][9], 1);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][9], 100);
    PlayerTextDrawFont(playerid, LoginRC[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][9], 1);

    LoginRC[playerid][10] = CreatePlayerTextDraw(playerid, 275.944274, 181.249755, "Coloque_sua_senha_aqui");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][10], 0.231800, 1.156666);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][10], 368.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][10], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][10], -1);
    //PlayerTextDrawUseBox(playerid, LoginRC[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, LoginRC[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][10], 1);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][10], 64);
    PlayerTextDrawFont(playerid, LoginRC[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, LoginRC[playerid][10], true);

    LoginRC[playerid][11] = CreatePlayerTextDraw(playerid, 211.588577, 78.583358, "");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][11], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][11], 90.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][11], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][11], 0);
    PlayerTextDrawFont(playerid, LoginRC[playerid][11], 5);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][11], 0);
    PlayerTextDrawSetPreviewModel(playerid, LoginRC[playerid][11], NatalGorroID);
    PlayerTextDrawSetPreviewRot(playerid, LoginRC[playerid][11], 0.000000, 0.000000, 180.000000, 1.000000);

    LoginRC[playerid][12] = CreatePlayerTextDraw(playerid, 312.578430, 203.399978, "");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][12], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][12], 23.000000, 27.000000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][12], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][12], 0);
    PlayerTextDrawFont(playerid, LoginRC[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][12], 0);
    PlayerTextDrawSetPreviewModel(playerid, LoginRC[playerid][12], 19134);
    PlayerTextDrawSetPreviewRot(playerid, LoginRC[playerid][12], 0.000000, -90.000000, 90.000000, 1.000000);
    PlayerTextDrawSetSelectable(playerid, LoginRC[playerid][12], true);

    LoginRC[playerid][13] = CreatePlayerTextDraw(playerid, 260.988861, 237.833374, ConverterTexto("Ainda não possui uma conta?"));
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][13], 0.180261, 1.156666);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][13], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][13], 1);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][13], 101);
    PlayerTextDrawFont(playerid, LoginRC[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][13], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][13], 1);

    LoginRC[playerid][14] = CreatePlayerTextDraw(playerid, 349.051849, 237.816665, "Registrar-se");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][14], 0.173234, 1.156666);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][14], 383.300018, 12.0000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][14], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][14], -1448498689);
    //PlayerTextDrawUseBox(playerid, LoginRC[playerid][14], 1);
    PlayerTextDrawBoxColor(playerid, LoginRC[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][14], 1);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][14], 255);
    PlayerTextDrawFont(playerid, LoginRC[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][14], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, LoginRC[playerid][14], true);

    LoginRC[playerid][15] = CreatePlayerTextDraw(playerid, 273.773773, 253.000015, "Esqueceu_sua_senha?");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][15], 0.189163, 1.098333);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][15], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][15], 1);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][15], 101);
    PlayerTextDrawFont(playerid, LoginRC[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][15], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][15], 1);

    LoginRC[playerid][16] = CreatePlayerTextDraw(playerid, 338.373321, 253.000015, "Recuperar");
    PlayerTextDrawLetterSize(playerid, LoginRC[playerid][16], 0.189163, 1.098333);
    PlayerTextDrawTextSize(playerid, LoginRC[playerid][16], 367.799987, 12.0000);
    PlayerTextDrawAlignment(playerid, LoginRC[playerid][16], 1);
    PlayerTextDrawColor(playerid, LoginRC[playerid][16], -1061109505);
    //PlayerTextDrawUseBox(playerid, LoginRC[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, LoginRC[playerid][16], 0);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][16], 1);
    PlayerTextDrawSetOutline(playerid, LoginRC[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginRC[playerid][16], 255);
    PlayerTextDrawFont(playerid, LoginRC[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, LoginRC[playerid][16], 1);
    PlayerTextDrawSetShadow(playerid, LoginRC[playerid][16], 1);
    PlayerTextDrawSetSelectable(playerid, LoginRC[playerid][16], true);
    
    for(new i=0; i < 17; i++){
        PlayerTextDrawShow(playerid, LoginRC[playerid][i]);
    }

    EsperandoKick[playerid] = true;
    KickLoginTempo[playerid] = SetTimerEx("ExpulsarLogin", 120000, false, "d", playerid);
    SetTimerEx("TelasAnimadas", 2000, false, "d", playerid); 
    SetTimerEx("TelasMusica", 2000, false, "d", playerid); 
    SelectTextDrawEx(playerid, 0x00BFFFFF, "OcultarLogin", false);
    // BugarInterior(playerid);
    return 1;
}

function OcultarLogin(playerid)
{
    KillTimer(KickLoginTempo[playerid]);
    EsperandoKick[playerid] = false;
    CancelSelectTextDrawEx(playerid, "OcultarLogin");
    for(new i=0; i < 17; i++){
        PlayerTextDrawDestroy(playerid, LoginRC[playerid][i]);
        LoginRC[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

function TelasMusica(playerid)
{
    switch(random(3))
	{
		case 0: PlayAudioStreamForPlayer(playerid, "https://www.dropbox.com/s/b0zy4xnvrt96yyc/Billie%20Eilish%20-%20ilomilo%20%28DESPER%20Remix%29.mp3?dl=1");
		case 1: PlayAudioStreamForPlayer(playerid, "https://www.dropbox.com/s/z7emxx4yj0dqme7/Raca.mp3?dl=1");
		case 2: PlayAudioStreamForPlayer(playerid, "https://www.dropbox.com/s/kzcn8x4tolyeiq5/DESPER%20-%20Arcade%20Things.mp3?dl=1");
		case 3: PlayAudioStreamForPlayer(playerid, "https://www.dropbox.com/s/oiot30j4boioufs/Billie%20Eilish%20-%20everything%20i%20wanted%20%28DESPER%20Remix%29.mp3?dl=1");
	}
    return 1;
}

function TelasAnimadas(playerid)
{
    // SetPlayerInterior(playerid, 0);
    TogglePlayerSpectating(playerid, 0);
    TogglePlayerControllable(playerid, 0);
    switch(random(13))
    {
        case 0:
        {
            SetPlayerPos(playerid, 1335.117309, -982.668579, 202.226531-100.0);
            InterpolateCameraPos(playerid, 1335.117309, -982.668579, 202.226531, 1359.346557, -994.981811, 43.454010, 9000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 1335.542968, -982.761779, 197.245559, 1355.163452, -992.879699, 41.698246, 9000, CAMERA_MOVE);
        }
        case 1:
        {
            SetPlayerPos(playerid, -2800.575439, 1946.292846, 9.821128-100.0);
            InterpolateCameraPos(playerid, -2800.575439, 1946.292846, 9.821128, -2095.973876, 2414.078613, 36.446117, 15000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, -2795.944580, 1948.178100, 9.817220, -2100.835449, 2413.132080, 35.760780, 15000, CAMERA_MOVE);
        }
        case 2:
        {
            SetPlayerPos(playerid, -2565.683593, -575.448120, 128.396759-100.0);
            InterpolateCameraPos(playerid, -2565.683593, -575.448120, 128.396759, -2731.914794, -186.188644, 16.551181, 15000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, -2567.003417, -570.895935, 126.804222, -2731.856445, -191.182617, 16.789693, 15000, CAMERA_MOVE);
        }
        case 3:
        {
            SetPlayerPos(playerid, 827.323547, -1874.888305, 23.979452-100.0);
            InterpolateCameraPos(playerid, 827.323547, -1874.888305, 23.979452, 66.566551, -1988.415527, 43.567714, 45000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 822.343505, -1874.958496, 23.538618, 70.389862, -1985.299560, 42.747226, 45000, CAMERA_MOVE);
        }
        case 4:
        {
            SetPlayerPos(playerid, -1156.062622, 561.796325, 17.635738-100.0);
            InterpolateCameraPos(playerid, -1156.062622, 561.796325, 17.635738, -1519.754760, 1208.645385, 82.424659, 20000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, -1156.982055, 566.701599, 17.331239, -1522.607910, 1204.658447, 81.442802, 20000, CAMERA_MOVE);
        }
        case 5:
        {
            SetPlayerPos(playerid, -2832.894042, 1075.414916, 40.042976-100.0);
            InterpolateCameraPos(playerid, -2832.894042, 1075.414916, 40.042976, -2567.480957, 1694.606323, 147.083724, 15000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, -2831.105224, 1080.040283, 39.405303, -2569.622802, 1690.272949, 145.805419, 15000, CAMERA_MOVE);
        }
        case 6:
        {
            SetPlayerPos(playerid, 2077.037597, 1910.735107, 29.922159-100.0);
            InterpolateCameraPos(playerid, 2077.037597, 1910.735107, 29.922159, 2177.085693, 1914.485717, 76.301391, 25000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 2072.054443, 1910.988037, 30.246150, 2172.086914, 1914.438598, 76.406852, 25000, CAMERA_MOVE);
        }
        case 7:
        {
            SetPlayerPos(playerid, 1544.126220, -1353.114868, 329.288299-100.0);
            InterpolateCameraPos(playerid, 1544.126220, -1353.114868, 329.288299, 1626.332641, -1373.562133, 440.902526, 30000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 1543.690429, -1353.117797, 324.307312, 1624.042602, -1371.274536, 437.091674, 30000, CAMERA_MOVE);
        }
        case 8:
        {
            SetPlayerPos(playerid, 724.966247, -1802.078857, 2.082828-100.0);
            InterpolateCameraPos(playerid, 724.966247, -1802.078857, 2.082828, 715.309692, -1489.849365, 23.671327, 30000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 724.936828, -1797.081787, 1.915112, 720.096557, -1488.412963, 23.822275, 30000, CAMERA_MOVE);
        }
        case 9:
        {
            SetPlayerPos(playerid, 591.171752, -2012.596191, 1.286335-100.0);
            InterpolateCameraPos(playerid, 591.171752, -2012.596191, 1.286335, 646.246154, -1321.586425, 99.962242, 20000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 591.206115, -2017.527465, 2.112067, 651.110412, -1320.434082, 99.856185, 20000, CAMERA_MOVE);
        }
        case 10:
        {
            SetPlayerPos(playerid, 2057.707763, 1182.382080, 19.827589-100.0);
            InterpolateCameraPos(playerid, 2057.707763, 1182.382080, 19.827589, 2352.199218, 1027.007446, 115.217376, 30000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 2062.035156, 1179.977661, 20.529798, 2348.497802, 1029.874023, 113.461807, 30000, CAMERA_MOVE);
        }
        case 11:
        {
            SetPlayerPos(playerid, 1977.258300, 1915.498413, 135.402572-100.0);
            InterpolateCameraPos(playerid, 1977.258300, 1915.498413, 135.402572, 2134.105712, 1906.739868, 17.790742, 20000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 1980.819702, 1915.437622, 131.893600, 2129.328857, 1907.125000, 19.217063, 20000, CAMERA_MOVE);
        }
        case 12:
        {
            SetPlayerPos(playerid, 2518.935302, 2130.874511, 11.243128-100.0);
            InterpolateCameraPos(playerid, 2518.935302, 2130.874511, 11.243128, 2104.693359, 2144.577148, 43.355522, 90000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 2513.973388, 2131.480712, 11.352965, 2109.667236, 2144.506103, 42.849361, 90000, CAMERA_MOVE);
        }
        case 13:
        {
            SetPlayerPos(playerid, 1478.807250, -1606.916503, 15.334312-100.0);
            InterpolateCameraPos(playerid, 1478.807250, -1606.916503, 15.334312, 1478.807250, -1606.916503, 15.334312, 30000, CAMERA_MOVE);
            InterpolateCameraLookAt(playerid, 1478.829345, -1610.452026, 18.869846, 1478.787109, -1611.898681, 15.754904, 30000, CAMERA_MOVE);
        }
    }
    for(new i=0; i < 99; i++){
        SendClientMessage(playerid, -1, " ");
    }
    return 1;
}

function ExpulsarLogin(playerid)
{
    SendClientMessage(playerid, 0xFF4500FF, "| SERVIDOR | Você ficou parado por muito tempo e foi expulso(a)");
    SetTimerEx("KickEx", 1000, false, "d", playerid);
    return 1;
}