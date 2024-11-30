#include <YSI_Coding\y_hooks>

new PlayerText:AmongEJ[MAX_PLAYERS][4];
new bool:tin[MAX_PLAYERS],
    tine[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i=0; i < 12; i++){
        AmongTasks[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }

    for(new i=0; i < 50; i++){
        VoteAmong[playerid][i] = PlayerText:INVALID_TEXT_DRAW; 
    }

    for(new i=0; i < 4; i++){
        AmongEJ[playerid][i] = PlayerText:INVALID_TEXT_DRAW; 
    }

    if(tin[playerid] == true){
        KillTimer(tine[playerid]);
        tin[playerid] = false;
    }
    return 1;
}

stock MostrarTasks(playerid)
{
    AmongTasks[playerid][0] = CreatePlayerTextDraw(playerid, 545.812622, 141.000000, "box");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][0], 0.000000, 16.325035);
    PlayerTextDrawTextSize(playerid, AmongTasks[playerid][0], 634.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][0], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, AmongTasks[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, AmongTasks[playerid][0], 80);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][0], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][0], 0);

    AmongTasks[playerid][1] = CreatePlayerTextDraw(playerid, 545.812622, 172.300155, "box");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][1], 0.000000, 12.842061);
    PlayerTextDrawTextSize(playerid, AmongTasks[playerid][1], 634.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][1], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, AmongTasks[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, AmongTasks[playerid][1], 471604479);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][1], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][1], 0);

    AmongTasks[playerid][2] = CreatePlayerTextDraw(playerid, 589.922180, 142.466690, "~y~Aguardando~w~~n~Among_US");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][2], 0.300673, 1.179998);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][2], 2);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][2], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][2], 1);

    AmongTasks[playerid][3] = CreatePlayerTextDraw(playerid, 548.123962, 173.283340, "Tasks:");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][3], 0.237422, 1.185832);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][3], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][3], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][3], 0);

    AmongTasks[playerid][4] = CreatePlayerTextDraw(playerid, 548.155334, 192.333328, "1._N/A");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][4], 0.210715, 1.045832);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][4], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][4], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][4], 0);

    AmongTasks[playerid][5] = CreatePlayerTextDraw(playerid, 548.155334, 203.733428, "2._N/A");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][5], 0.210715, 1.045832);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][5], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][5], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][5], 0);

    AmongTasks[playerid][6] = CreatePlayerTextDraw(playerid, 548.155334, 215.133850, "3._N/A");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][6], 0.210715, 1.045832);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][6], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][6], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][6], 0);

    AmongTasks[playerid][7] = CreatePlayerTextDraw(playerid, 548.155334, 226.534545, "4._N/A");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][7], 0.210715, 1.045832);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][7], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][7], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][7], 0);

    AmongTasks[playerid][8] = CreatePlayerTextDraw(playerid, 548.155334, 238.235260, "5._N/A");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][8], 0.210715, 1.045832);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][8], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][8], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][8], 0);

    AmongTasks[playerid][9] = CreatePlayerTextDraw(playerid, 556.325988, 259.266632, "Aperte_~r~N~w~_para_matar");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][9], 0.194786, 1.051664);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][9], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][9], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][9], 0);

    AmongTasks[playerid][10] = CreatePlayerTextDraw(playerid, 576.771972, 271.799926, "#Rippzy");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][10], 0.207906, 1.051665);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][10], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][10], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][10], 0);

    AmongTasks[playerid][11] = CreatePlayerTextDraw(playerid, 547.818237, 255.683486, "box");
    PlayerTextDrawLetterSize(playerid, AmongTasks[playerid][11], 0.000000, -0.259909);
    PlayerTextDrawTextSize(playerid, AmongTasks[playerid][11], 631.800048, 0.000000);
    PlayerTextDrawAlignment(playerid, AmongTasks[playerid][11], 1);
    PlayerTextDrawColor(playerid, AmongTasks[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, AmongTasks[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, AmongTasks[playerid][11], 97);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, AmongTasks[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongTasks[playerid][11], 255);
    PlayerTextDrawFont(playerid, AmongTasks[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, AmongTasks[playerid][11], 1);
    PlayerTextDrawSetShadow(playerid, AmongTasks[playerid][11], 0);

    for(new i=0; i < 12; i++){
        PlayerTextDrawShow(playerid, AmongTasks[playerid][i]);
    }
    return 1;
}

OcultarTasks(playerid)
{
    for(new i=0; i < 12; i++){
        PlayerTextDrawDestroy(playerid, AmongTasks[playerid][i]);
        AmongTasks[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarVotacaoAmong(playerid)
{
    VoteAmong[playerid][0] = CreatePlayerTextDraw(playerid, 176.617858, 131.666687, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][0], 0.000000, 21.853584);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][0], 411.449951, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][0], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][0], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][0], 1);

    VoteAmong[playerid][1] = CreatePlayerTextDraw(playerid, 182.608627, 167.183120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][1], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][1], 286.899993, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][1], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][1], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][1], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][1], 1);

    VoteAmong[playerid][2] = CreatePlayerTextDraw(playerid, 182.708633, 192.683120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][2], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][2], 287.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][2], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][2], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][2], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][2], 1);

    VoteAmong[playerid][3] = CreatePlayerTextDraw(playerid, 182.708633, 219.183120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][3], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][3], 287.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][3], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][3], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][3], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][3], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][3], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][3], 1);

    VoteAmong[playerid][4] = CreatePlayerTextDraw(playerid, 182.708633, 244.683120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][4], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][4], 287.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][4], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][4], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][4], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][4], 1);

    VoteAmong[playerid][5] = CreatePlayerTextDraw(playerid, 182.708633, 271.183105, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][5], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][5], 287.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][5], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][5], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][5], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][5], 1);

    VoteAmong[playerid][6] = CreatePlayerTextDraw(playerid, 182.708633, 296.683105, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][6], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][6], 287.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][6], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][6], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][6], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][6], 1);

    VoteAmong[playerid][7] = CreatePlayerTextDraw(playerid, 301.007965, 167.183120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][7], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][7], 405.299316, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][7], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][7], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][7], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][7], 1);

    VoteAmong[playerid][8] = CreatePlayerTextDraw(playerid, 301.007965, 192.382949, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][8], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][8], 405.299316, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][8], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][8], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][8], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][8], 1);

    VoteAmong[playerid][9] = CreatePlayerTextDraw(playerid, 301.007965, 217.582778, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][9], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][9], 405.299316, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][9], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][9], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][9], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][9], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][9], 1);

    VoteAmong[playerid][10] = CreatePlayerTextDraw(playerid, 301.007965, 243.682601, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][10], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][10], 405.299316, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][10], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][10], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][10], 153);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][10], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][10], 1);

    VoteAmong[playerid][11] = CreatePlayerTextDraw(playerid, 301.007965, 269.782440, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][11], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][11], 405.299316, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][11], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][11], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][11], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][11], -2147483393);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][11], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][11], 1);

    VoteAmong[playerid][12] = CreatePlayerTextDraw(playerid, 353.833740, 295.416687, "Tempo:_02:20");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][12], 0.233204, 1.203330);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][12], 0.000000, 95.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][12], 2);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][12], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][12], 1);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][12], 123);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][12], 1);

    VoteAmong[playerid][13] = CreatePlayerTextDraw(playerid, 182.708633, 167.183120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][13], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][13], 197.329605, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][13], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][13], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][13], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][13], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][13], 1);

    VoteAmong[playerid][14] = CreatePlayerTextDraw(playerid, 173.595733, 159.866699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][14], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][14], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][14], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][14], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][14], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][14], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][14], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][14], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][14], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][15] = CreatePlayerTextDraw(playerid, 182.708633, 192.883804, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][15], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][15], 197.329605, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][15], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][15], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][15], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][15], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][15], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][15], 1);

    VoteAmong[playerid][16] = CreatePlayerTextDraw(playerid, 182.708633, 219.383804, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][16], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][16], 197.329605, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][16], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][16], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][16], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][16], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][16], 1);

    VoteAmong[playerid][17] = CreatePlayerTextDraw(playerid, 182.708633, 244.883804, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][17], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][17], 197.329605, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][17], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][17], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][17], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][17], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][17], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][17], 1);

    VoteAmong[playerid][18] = CreatePlayerTextDraw(playerid, 182.708633, 270.883789, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][18], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][18], 197.329605, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][18], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][18], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][18], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][18], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][18], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][18], 1);

    VoteAmong[playerid][19] = CreatePlayerTextDraw(playerid, 182.708633, 296.883789, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][19], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][19], 197.329605, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][19], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][19], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][19], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][19], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][19], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][19], 1);

    VoteAmong[playerid][20] = CreatePlayerTextDraw(playerid, 300.708618, 167.183120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][20], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][20], 315.329589, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][20], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][20], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][20], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][20], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][20], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][20], 1);

    VoteAmong[playerid][21] = CreatePlayerTextDraw(playerid, 300.708618, 192.183120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][21], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][21], 315.329589, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][21], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][21], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][21], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][21], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][21], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][21], 1);

    VoteAmong[playerid][22] = CreatePlayerTextDraw(playerid, 300.708618, 217.183120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][22], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][22], 315.329589, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][22], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][22], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][22], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][22], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][22], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][22], 1);

    VoteAmong[playerid][23] = CreatePlayerTextDraw(playerid, 300.708618, 243.683120, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][23], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][23], 315.329589, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][23], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][23], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][23], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][23], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][23], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][23], 1);

    VoteAmong[playerid][24] = CreatePlayerTextDraw(playerid, 300.708618, 269.683105, "box");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][24], 0.000000, 1.800879);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][24], 315.329589, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][24], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][24], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][24], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][24], -2139062172);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][24], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][24], 1);

    VoteAmong[playerid][25] = CreatePlayerTextDraw(playerid, 173.595733, 185.866699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][25], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][25], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][25], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][25], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][25], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][25], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][25], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][25], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][25], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][25], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][26] = CreatePlayerTextDraw(playerid, 173.595733, 212.366699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][26], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][26], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][26], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][26], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][26], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][26], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][26], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][26], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][26], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][26], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][27] = CreatePlayerTextDraw(playerid, 173.595733, 237.366699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][27], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][27], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][27], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][27], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][27], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][27], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][27], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][27], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][27], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][27], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][28] = CreatePlayerTextDraw(playerid, 173.595733, 264.366699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][28], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][28], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][28], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][28], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][28], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][28], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][28], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][28], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][28], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][28], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][29] = CreatePlayerTextDraw(playerid, 173.595733, 290.366699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][29], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][29], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][29], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][29], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][29], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][29], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][29], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][29], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][29], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][29], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][30] = CreatePlayerTextDraw(playerid, 292.095733, 159.866699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][30], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][30], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][30], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][30], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][30], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][30], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][30], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][30], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][30], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][30], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][31] = CreatePlayerTextDraw(playerid, 292.095733, 185.366699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][31], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][31], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][31], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][31], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][31], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][31], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][31], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][31], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][31], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][31], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][32] = CreatePlayerTextDraw(playerid, 292.095733, 210.366699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][32], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][32], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][32], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][32], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][32], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][32], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][32], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][32], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][32], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][32], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][33] = CreatePlayerTextDraw(playerid, 292.095733, 236.866699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][33], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][33], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][33], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][33], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][33], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][33], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][33], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][33], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][33], 18978);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][33], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][34] = CreatePlayerTextDraw(playerid, 292.095733, 262.866699, "");
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][34], 33.000000, 29.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][34], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][34], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][34], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][34], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][34], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][34], 5);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][34], 0);
    PlayerTextDrawSetPreviewModel(playerid, VoteAmong[playerid][34], 11712);
    PlayerTextDrawSetPreviewRot(playerid, VoteAmong[playerid][34], 0.000000, 0.000000, 120.000000, 1.000000);

    VoteAmong[playerid][35] = CreatePlayerTextDraw(playerid, 203.792083, 170.183364, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][35], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][35], 283.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][35], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][35], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][35], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][35], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][35], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][35], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][35], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][35], true);

    VoteAmong[playerid][36] = CreatePlayerTextDraw(playerid, 203.792083, 196.583465, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][36], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][36], 283.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][36], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][36], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][36], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][36], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][36], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][36], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][36], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][36], true);

    VoteAmong[playerid][37] = CreatePlayerTextDraw(playerid, 203.792083, 222.483352, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][37], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][37], 283.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][37], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][37], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][37], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][37], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][37], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][37], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][37], true);

    VoteAmong[playerid][38] = CreatePlayerTextDraw(playerid, 203.792083, 247.683242, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][38], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][38], 283.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][38], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][38], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][38], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][38], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][38], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][38], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][38], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][38], true);

    VoteAmong[playerid][39] = CreatePlayerTextDraw(playerid, 203.792083, 274.983551, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][39], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][39], 283.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][39], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][39], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][39], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][39], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][39], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][39], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][39], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][39], true);

    VoteAmong[playerid][40] = CreatePlayerTextDraw(playerid, 203.792083, 300.183990, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][40], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][40], 283.000000, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][40], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][40], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][40], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][40], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][40], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][40], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][40], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][40], true);

    VoteAmong[playerid][41] = CreatePlayerTextDraw(playerid, 322.093017, 170.683593, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][41], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][41], 401.302062, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][41], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][41], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][41], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][41], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][41], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][41], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][41], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][41], true);

    VoteAmong[playerid][42] = CreatePlayerTextDraw(playerid, 322.093017, 195.183486, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][42], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][42], 401.302062, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][42], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][42], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][42], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][42], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][42], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][42], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][42], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][42], true);

    VoteAmong[playerid][43] = CreatePlayerTextDraw(playerid, 322.093017, 220.383377, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][43], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][43], 401.302062, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][43], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][43], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][43], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][43], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][43], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][43], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][43], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][43], true);

    VoteAmong[playerid][44] = CreatePlayerTextDraw(playerid, 322.093017, 246.983261, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][44], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][44], 401.302062, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][44], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][44], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][44], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][44], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][44], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][44], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][44], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][44], true);

    VoteAmong[playerid][45] = CreatePlayerTextDraw(playerid, 322.093017, 272.883514, "Nao_Conectado(a)");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][45], 0.236485, 1.028332);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][45], 401.302062, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][45], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][45], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][45], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][45], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][45], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][45], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][45], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][45], true);

    VoteAmong[playerid][46] = CreatePlayerTextDraw(playerid, 294.479461, 133.366653, "R");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][46], 0.451068, 1.798334);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][46], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][46], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][46], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][46], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][46], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][46], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][46], 1);

    VoteAmong[playerid][47] = CreatePlayerTextDraw(playerid, 298.679504, 140.566726, "C");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][47], 0.451068, 1.798334);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][47], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][47], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][47], 0);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][47], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][47], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][47], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][47], 1);

    VoteAmong[playerid][48] = CreatePlayerTextDraw(playerid, 185.519775, 141.599990, "Among_US_-_Rippzy");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][48], 0.224304, 1.028331);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][48], 190.519775, 0.000000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][48], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][48], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][48], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][48], -5963521);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][48], 255);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][48], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][48], 1);

    VoteAmong[playerid][49] = CreatePlayerTextDraw(playerid, 340.731811, 310.800079, "Pular");
    PlayerTextDrawLetterSize(playerid, VoteAmong[playerid][49], 0.308638, 1.279165);
    PlayerTextDrawTextSize(playerid, VoteAmong[playerid][49], 366.000030, 12.0000);
    PlayerTextDrawAlignment(playerid, VoteAmong[playerid][49], 1);
    PlayerTextDrawColor(playerid, VoteAmong[playerid][49], -1);
    PlayerTextDrawUseBox(playerid, VoteAmong[playerid][49], 1);
    PlayerTextDrawBoxColor(playerid, VoteAmong[playerid][49], 0);
    PlayerTextDrawSetShadow(playerid, VoteAmong[playerid][49], 1);
    PlayerTextDrawBackgroundColor(playerid, VoteAmong[playerid][49], 0);
    PlayerTextDrawFont(playerid, VoteAmong[playerid][49], 1);
    PlayerTextDrawSetProportional(playerid, VoteAmong[playerid][49], 1);
    PlayerTextDrawSetSelectable(playerid, VoteAmong[playerid][49], true);

    for(new i=0; i < 50; i++){
        PlayerTextDrawShow(playerid, VoteAmong[playerid][i]);
    }
    SelectTextDrawEx(playerid, 0xFFA500FF, "OcultarVotacaoAmong", true);
    return 1;
}

function OcultarVotacaoAmong(playerid)
{
    CancelSelectTextDrawEx(playerid, "OcultarVotacaoAmong");
    for(new i=0; i < 50; i++){
        PlayerTextDrawDestroy(playerid, VoteAmong[playerid][i]);
        VoteAmong[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock MostrarAmongMensagem(playerid, const EjN[], const Mensagem[], TempoID)
{
    
    AmongEJ[playerid][0] = CreatePlayerTextDraw(playerid, 15.915077, 271.083312, "box");
    PlayerTextDrawLetterSize(playerid, AmongEJ[playerid][0], 0.000000, 3.516954);
    PlayerTextDrawTextSize(playerid, AmongEJ[playerid][0], 135.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, AmongEJ[playerid][0], 1);
    PlayerTextDrawColor(playerid, AmongEJ[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, AmongEJ[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, AmongEJ[playerid][0], 471604479);
    PlayerTextDrawSetShadow(playerid, AmongEJ[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, AmongEJ[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongEJ[playerid][0], 255);
    PlayerTextDrawFont(playerid, AmongEJ[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, AmongEJ[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, AmongEJ[playerid][0], 0);

    AmongEJ[playerid][1] = CreatePlayerTextDraw(playerid, 15.915077, 271.083312, "box");
    PlayerTextDrawLetterSize(playerid, AmongEJ[playerid][1], 0.000000, 0.140959);
    PlayerTextDrawTextSize(playerid, AmongEJ[playerid][1], 135.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, AmongEJ[playerid][1], 1);
    PlayerTextDrawColor(playerid, AmongEJ[playerid][1], -1);
    PlayerTextDrawUseBox(playerid, AmongEJ[playerid][1], 1);
    PlayerTextDrawBoxColor(playerid, AmongEJ[playerid][1], -5963521);
    PlayerTextDrawSetShadow(playerid, AmongEJ[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, AmongEJ[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongEJ[playerid][1], 255);
    PlayerTextDrawFont(playerid, AmongEJ[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, AmongEJ[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, AmongEJ[playerid][1], 0);

    AmongEJ[playerid][2] = CreatePlayerTextDraw(playerid, 77.091339, 277.966613, ConverterTexto(EjN));
    PlayerTextDrawLetterSize(playerid, AmongEJ[playerid][2], 0.221024, 1.086666);
    PlayerTextDrawAlignment(playerid, AmongEJ[playerid][2], 2);
    PlayerTextDrawColor(playerid, AmongEJ[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, AmongEJ[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, AmongEJ[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongEJ[playerid][2], 255);
    PlayerTextDrawFont(playerid, AmongEJ[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, AmongEJ[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, AmongEJ[playerid][2], 0);

    AmongEJ[playerid][3] = CreatePlayerTextDraw(playerid, 75.911720, 289.016693, ConverterTexto(Mensagem));
    PlayerTextDrawLetterSize(playerid, AmongEJ[playerid][3], 0.128726, 1.156666);
    PlayerTextDrawAlignment(playerid, AmongEJ[playerid][3], 2);
    PlayerTextDrawColor(playerid, AmongEJ[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, AmongEJ[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, AmongEJ[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, AmongEJ[playerid][3], 255);
    PlayerTextDrawFont(playerid, AmongEJ[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, AmongEJ[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, AmongEJ[playerid][3], 0);

    for(new i=0; i < 4; i++){
        PlayerTextDrawShow(playerid, AmongEJ[playerid][i]);
    }

    tin[playerid] = true;
    tine[playerid] = SetTimerEx("OcultarEJ", TempoID, false, "d", playerid);
    return 1;
}

function OcultarEJ(playerid)
{
    tin[playerid] = false;
    for(new i=0; i < 4; i++){
        PlayerTextDrawDestroy(playerid, AmongEJ[playerid][i]);
        AmongEJ[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}