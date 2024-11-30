CMD:animes(playerid)
{
    new Dialog[2000];
    strcat(Dialog, "{00BFFF}/fall{FFFFFF} - {00BFFF}/fallback{FFFFFF} - {00BFFF}/injured{FFFFFF} - {00BFFF}/akick{FFFFFF} - {00BFFF}/push\n");
    strcat(Dialog, "{00BFFF}/handsup{FFFFFF} - {00BFFF}/bomb{FFFFFF} - {00BFFF}/drunk{FFFFFF} - {00BFFF}/sup\n");
    strcat(Dialog, "{00BFFF}/basket{FFFFFF} - {00BFFF}/spray{FFFFFF} - {00BFFF}/taichi{FFFFFF} - {00BFFF}/punheta\n");
    strcat(Dialog, "{00BFFF}/kiss{FFFFFF} - {00BFFF}/cellout{FFFFFF} - {00BFFF}/crossarms{FFFFFF} - {00BFFF}/lay{FFFFFF} - {00BFFF}/chairsit\n");
    strcat(Dialog, "{00BFFF}/deal{FFFFFF} - {00BFFF}/crack{FFFFFF} - {00BFFF}/smoke{FFFFFF} - {00BFFF}/groundsit{FFFFFF} - {00BFFF}/chat\n");
    strcat(Dialog, "{00BFFF}/fucku{FFFFFF} - {00BFFF}/strip{FFFFFF} - {00BFFF}/hide{FFFFFF} - {00BFFF}/vomit{FFFFFF} - {00BFFF}/eat\n");
    strcat(Dialog, "{00BFFF}/reload{FFFFFF} - {00BFFF}/bat{FFFFFF} - {00BFFF}/koface{FFFFFF} - {00BFFF}/rollfall{FFFFFF} - {00BFFF}/dance\n");
    strcat(Dialog, "{00BFFF}/exhaust{FFFFFF} - {00BFFF}/carlock{FFFFFF} - {00BFFF}/chant{FFFFFF} - {00BFFF}/finger{FFFFFF}\n");
    strcat(Dialog, "{00BFFF}/lightcig{FFFFFF} - {00BFFF}/tapcig{FFFFFF} - {00BFFF}/box{FFFFFF} - {00BFFF}/lay2{FFFFFF}\n");
    strcat(Dialog, "{00BFFF}/shouting{FFFFFF} - {00BFFF}/knife{FFFFFF} - {00BFFF}/cop{FFFFFF} - {00BFFF}/elbow{FFFFFF} - {00BFFF}/kneekick\n");
    strcat(Dialog, "{00BFFF}/gkick{FFFFFF} - {00BFFF}/gpunch{FFFFFF} - {00BFFF}/fstance{FFFFFF} - {00BFFF}/aim{FFFFFF}\n");
    strcat(Dialog, "{00BFFF}/mijar{FFFFFF} - {00BFFF}/lean{FFFFFF} - {00BFFF}/dealstance{FFFFFF} - {00BFFF}/segurarvinho\n");
    strcat(Dialog, "{00BFFF}/sentar - {00BFFF}/oi{FFFFFF} - {00BFFF}/bananeira{FFFFFF} - {00BFFF}/vapo{FFFFFF}\n");
    strcat(Dialog, "{FF0000}/parar - Para parar animação");
    ShowPlayerDialog(playerid, 666, DIALOG_STYLE_MSGBOX, "{FF0000}Animações", Dialog, "Fechar", "");
    return 1;
}

CMD:parar(playerid)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar dirigindo!");
    ClearAnimations(playerid);
    return 1;
}

CMD:handsup(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "ROB_BANK","SHP_HandsUp_Scr", 4.0, 0, 1, 1, 1, 0);
    return 1;
}

CMD:cellout(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
    return 1;
}

CMD:drunk(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","WALK_DRUNK",4.1,1,1,1,1,1);
    return 1;
}

CMD:bomb(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "BOMBER","BOM_Plant_Loop",4.0,1,0,0,1,0);
    return 1;
}

CMD:crossarms(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);
    return 1;
}

CMD:lay(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"BEACH", "bather", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:hide(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:vomit(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:eat(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:wave(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:slapass(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:deal(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:crack(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:gro(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0); // Sit
    return 1;
}

CMD:chat(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","IDLE_CHAT",4.0,1,0,0,1,1);
    return 1;
}

CMD:fucku(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","fucku",4.0,0,0,0,0,0);
    return 1;
}

CMD:taichi(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,0);
    return 1;
}

CMD:chairsit(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","SEAT_down",4.1,0,1,1,1,0);
    return 1;
}

CMD:fall(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","KO_skid_front",4.1,0,1,1,1,0);
    return 1;
}

CMD:fallback(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "PED","FLOOR_hit_f", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:kiss(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "KISSING", "Playa_Kiss_02", 3.0, 1, 1, 1, 1, 0);
    return 1;
}

CMD:injured(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:push(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"GANGS","shake_cara",4.0,0,0,0,0,0);
    return 1;
}

CMD:akick(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"POLICE","Door_Kick",4.0,0,0,0,0,0);
    return 1;
}


CMD:spray(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"SPRAYCAN","spraycan_full",4.0,0,0,0,0,0);
    return 1;
}

CMD:lightcig(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"SMOKING","M_smk_in",3.0,0,0,0,0,0);
    return 1;
}

CMD:tapcig(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"SMOKING","M_smk_tap",3.0,0,0,0,0,0);
    return 1;
}

CMD:bat(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"BASEBALL","Bat_IDLE",4.0,1,1,1,1,0);
    return 1;
}

CMD:box(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"GYMNASIUM","GYMshadowbox",4.0,1,1,1,1,0);
    return 1;
}

CMD:lay2(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"SUNBATHE","Lay_Bac_in",3.0,0,1,1,1,0);
    return 1;
}

CMD:chant(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"RIOT","RIOT_CHANT",4.0,1,1,1,1,0);
    return 1;
}

CMD:finger(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"RIOT","RIOT_FUKU",2.0,0,0,0,0,0);
    return 1;
}
CMD:shouting(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"RIOT","RIOT_shout",4.0,1,0,0,0,0);
    return 1;
}

CMD:cop(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"SWORD","sword_block",50.0,0,1,1,1,1);
    return 1;
}

CMD:elbow(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"FIGHT_D","FightD_3",4.0,0,1,1,0,0);
    return 1;
}

CMD:kneekick(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"FIGHT_D","FightD_2",4.0,0,1,1,0,0);
    return 1;
}

CMD:fstance(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"FIGHT_D","FightD_IDLE",4.0,1,1,1,1,0);
    return 1;
}

CMD:gpunch(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"FIGHT_B","FightB_G",4.0,0,0,0,0,0);
    return 1;
}

CMD:gkick(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"FIGHT_D","FightD_G",4.0,0,0,0,0,0);
    return 1;
}

CMD:dealstance(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"DEALER","DEALER_IDLE",4.0,1,0,0,0,0);
    return 1;
}

CMD:mijar(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_PISSING);
    return 1;
}

CMD:koface(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","KO_shot_face",4.0,0,1,1,1,0);
    return 1;
}

CMD:exhaust(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","IDLE_tired",3.0,1,0,0,0,0);
    return 1;
}

CMD:rollfall(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","BIKE_fallR",4.0,0,1,1,1,0);
    return 1;
}

CMD:carlock(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PED","CAR_doorlocked_LHS",4.0,0,0,0,0,0);
    return 1;
}

CMD:smoke(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new animid;
    if(sscanf(params, "d", animid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /smoke [1-4]");
    if(animid < 1 || animid > 4) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /smoke [1-4]");
    else if(animid == 1) return ApplyAnimation(playerid,"SMOKING", "F_smklean_loop", 4.0, 1, 0, 0, 0, 0);
    else if(animid == 2) return ApplyAnimation(playerid,"SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);
    else if(animid == 3) return ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop", 4.0, 1, 0, 0, 0, 0);
    else if(animid == 4) return ApplyAnimation(playerid,"SMOKING","M_smk_out", 4.0, 1, 0, 0, 0, 0);
    return 1;
}

CMD:sup(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new animid;
    if(sscanf(params, "d", animid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /sup [1-3]");
    if(animid < 0 || animid > 3) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /sup [1-3]");
    if(animid == 1) return ApplyAnimation(playerid,"GANGS","hndshkba",4.0,0,0,0,0,0);
    if(animid == 2) return ApplyAnimation(playerid,"GANGS","hndshkda",4.0,0,0,0,0,0);
    if(animid == 3) return ApplyAnimation(playerid,"GANGS","hndshkfa_swt",4.0,0,0,0,0,0);
    return 1;
}

CMD:rap(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new animid;
    if(sscanf(params, "d", animid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /rap [1-4]");
    if(animid < 0 || animid > 4) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /rap [1-4]");
    if(animid == 1) return ApplyAnimation(playerid,"RAPPING","RAP_A_Loop",4.0,1,0,0,0,0);
    if(animid == 2) return ApplyAnimation(playerid,"RAPPING","RAP_C_Loop",4.0,1,0,0,0,0);
    if(animid == 3) return ApplyAnimation(playerid,"GANGS","prtial_gngtlkD",4.0,1,0,0,0,0);
    if(animid == 4) return ApplyAnimation(playerid,"GANGS","prtial_gngtlkH",4.0,1,0,0,1,1);
    return 1;
}

CMD:knife(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new animid;
    if(sscanf(params, "d", animid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /knife [1-4]");
    if(animid < 0 || animid > 4) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /knife [1-4]");
    if(animid == 1) return ApplyAnimation(playerid,"KNIFE","KILL_Knife_Ped_Damage",4.0,0,1,1,1,0);
    if(animid == 2) return ApplyAnimation(playerid,"KNIFE","KILL_Knife_Ped_Die",4.0,0,1,1,1,0);
    if(animid == 3) return ApplyAnimation(playerid,"KNIFE","KILL_Knife_Player",4.0,0,0,0,0,0);
    if(animid == 4) return ApplyAnimation(playerid,"KNIFE","KILL_Partial",4.0,0,1,1,1,1);
    return 1;
}

CMD:basket(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new animid;
    if(sscanf(params, "d", animid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /knife [1-6]");
    if(animid < 0 || animid > 6) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /knife [1-6]");
    if(animid == 1) return ApplyAnimation(playerid,"BSKTBALL","BBALL_idleloop",4.0,1,0,0,0,0);
    if(animid == 2) return ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
    if(animid == 3) return ApplyAnimation(playerid,"BSKTBALL","BBALL_pickup",4.0,0,0,0,0,0);
    if(animid == 4) return ApplyAnimation(playerid,"BSKTBALL","BBALL_run",4.1,1,1,1,1,1);
    if(animid == 5) return ApplyAnimation(playerid,"BSKTBALL","BBALL_def_loop",4.0,1,0,0,0,0);
    if(animid == 6) return ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk",4.0,1,0,0,0,0);
    return 1;
}

CMD:reload(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new anims[70];
    if(sscanf(params, "s[70]", anims)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /reload [deagle/smg/ak/m4]");
    if(strcmp(anims, "deagle", true) == 0) return ApplyAnimation(playerid,"COLT45","colt45_reload",4.0,0,0,0,0,1);
    if(strcmp(anims, "smg", true) == 0 || strcmp(anims, "ak", true) == 0 || strcmp(anims, "m4", true) == 0) return ApplyAnimation(playerid,"UZI","UZI_reload",4.0,0,0,0,0,0);
    return 1;
}

/*CMD:gwalk(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new animid;
    if(sscanf(params, "d", animid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /gwalk [1-2]"); 
    if(animid < 0 || animid > 2) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /gwalk [1-2]"); 
    if(animid == 1) return ApplyAnimation(playerid,"PED","WALK_gang1",4.1,1,1,1,1,1);
    if(animid == 2) return ApplyAnimation(playerid,"PED","WALK_gang2",4.1,1,1,1,1,1);
    return 1;
}*/

CMD:aim(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new animid;
    if(sscanf(params, "d", animid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /aim [1-3]");
    if(animid < 0 || animid > 3) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /aim [1-3]");
    if(animid == 1) return ApplyAnimation(playerid,"PED","gang_gunstand",4.0,1,1,1,1,1);
    if(animid == 2) return ApplyAnimation(playerid,"PED","Driveby_L",4.0,0,1,1,1,1);
    if(animid == 3) return ApplyAnimation(playerid,"PED","Driveby_R",4.0,0,1,1,1,1);
    return 1;
}

CMD:lean(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new animid;
    if(sscanf(params, "d", animid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /lean [1-2]");
    if(animid < 0 || animid > 2) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /lean [1-2]");
    if(animid == 1) return ApplyAnimation(playerid,"GANGS","leanIDLE",4.0,0,1,1,1,0);
    if(animid == 2) return ApplyAnimation(playerid,"MISC","Plyrlean_loop",4.0,0,1,1,1,0);
    return 1;
}

CMD:strip(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new anims[70];
    if(sscanf(params, "s[70]", anims)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /strip [a-g]");
    if(strcmp(anims, "a", true) == 0) return ApplyAnimation(playerid,"STRIP", "strip_A", 4.1, 1, 1, 1, 1, 1 );
    if(strcmp(anims, "b", true) == 0) return ApplyAnimation(playerid,"STRIP", "strip_B", 4.1, 1, 1, 1, 1, 1 );
    if(strcmp(anims, "c", true) == 0) return ApplyAnimation(playerid,"STRIP", "strip_C", 4.1, 1, 1, 1, 1, 1 );
    if(strcmp(anims, "d", true) == 0) return ApplyAnimation(playerid,"STRIP", "strip_D", 4.1, 1, 1, 1, 1, 1 );
    if(strcmp(anims, "e", true) == 0) return ApplyAnimation(playerid,"STRIP", "strip_E", 4.1, 1, 1, 1, 1, 1 );
    if(strcmp(anims, "f", true) == 0) return ApplyAnimation(playerid,"STRIP", "strip_F", 4.1, 1, 1, 1, 1, 1 );
    if(strcmp(anims, "g", true) == 0) return ApplyAnimation(playerid,"STRIP", "strip_G", 4.1, 1, 1, 1, 1, 1 );
    return 1;
}

CMD:dance(playerid, params[])
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    new animid;
    if(sscanf(params, "d", animid)) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Dance [1-6]");
    if(animid < 1 || animid > 6) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Use: /Dance [1-6]");
    
    switch(animid)
    {
        case 1: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
        case 2: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
        case 3: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
        case 4: ApplyAnimation(playerid, "DANCING", "DAN_DOWN_A", 40.0, 1, 0, 0, 0, -1);
        case 5: ApplyAnimation(playerid, "DANCING", "DAN_LOOP_A", 40.0, 1, 0, 0, 0, -1);
        case 6: ApplyAnimation(playerid, "DANCING", "DNCE_M_A", 40.0, 1, 0, 0, 0, -1);
    }

    
    return 1;
}

CMD:segurarvinho(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_WINE);
    return 1;
}

CMD:sentar(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ApplyAnimation(playerid, "PED", "SEAT_IDLE", 4.0, 0, 1, 1, 1, 0);
    return 1;
}

CMD:punheta(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid,"PAULNMAC", "wank_loop", 1.800001, 1, 0, 0, 1, 600);
    return 1;
}

CMD:vapo(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "PED", "ENDCHAT_02", 50.0, 0, 0, 0, 1, 900);
    return 1;
}

CMD:oi(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "PED", "ENDCHAT_03", 50.0, 0, 0, 0, 1, 900);
    return 1;
}

CMD:bananeira(playerid)
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando agora");
    if(GetPlayerSpeed(playerid) > 10) return SendClientMessage(playerid, 0xfc520fFF, "| ERRO | Você não pode usar esse comando se movimentando");
    ClearAnimations(playerid);
    ApplyAnimation(playerid, "DAM_JUMP", "DAM_DIVE_LOOP", 50.0, 0, 0, 0, 1, 900);
    return 1;
}