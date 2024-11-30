/**********************************
 *                                *
 *   @Author:      blueN          *
 *   @Version:     0.0.1          *
 *   @Released:    27/12/2020     *
 *                                *
 **********************************/

#define MAX_FUNC_NAME (32)
#define COMMANDDC:%1(%2)          \
			forward dc_%1(%2); \
			public dc_%1(%2)

#define DC:%1(%2) \
			COMMANDDC:%1(%2)

#define commanddc(%1,%2,%3) \
			COMMANDDC:%1(%2, %3)

#define dc(%1,%2,%3) \
			COMMANDDC:%1(%2, %3)


hook DCC_OnMessageCreate(DCC_Message:message)
{
    new Mensagem[128];
    if(!DCC_GetMessageContent(message, Mensagem, sizeof(Mensagem))) return 1;
    if(isnull(Mensagem)) return 1;

	new DCC_Channel:Canal;
    if(!DCC_GetMessageChannel(message, DCC_Channel:Canal)) return 1; // ID do canal

    new CanalRID[DCC_ID_SIZE],
        UsuarioRID[DCC_ID_SIZE],
        ServidorRID[DCC_ID_SIZE],
        DCC_User:DCMID,
        DCC_Guild:ServidorMID,
        DCC_ChannelType:asdsadas;

    DCC_GetChannelType(Canal, asdsadas); 
    if(asdsadas == DM){
        ServidorRID = "N/A";
    }else{
        DCC_GetChannelGuild(Canal, ServidorMID);
        DCC_GetGuildId(ServidorMID, ServidorRID);
    }
    DCC_GetChannelId(Canal, CanalRID);
    DCC_GetMessageAuthor(message, DCMID); 
    DCC_GetUserId(DCMID, UsuarioRID);
    
    new bool:bot;
    DCC_IsUserBot(DCMID, bot);
    if(bot) return 1;
 
    
    // Delay
    for(new i=0; i < 999; i++)
    {
        if(strcmp(pDiscordEx[i][SeuDID], UsuarioRID)) continue;
        if(pDiscordEx[i][TempoDID] > gettime()) return 1;
        break;
    }
    new bool:Jkaj = false;
    for(new i=0; i < 999; i++)
    {
        if(pDiscordEx[i][TempoDID] > gettime()) continue;
        format(pDiscordEx[i][SeuDID], DCC_ID_SIZE, UsuarioRID);
        pDiscordEx[i][TempoDID] = gettime()+10;
        Jkaj = true;
        break;
    }
    if(Jkaj == false) return 1;


    new Maksd[MAX_FUNC_NAME],
        MaksdEx[MAX_FUNC_NAME];
    
    format(Maksd, sizeof(Maksd), " %s", Mensagem);

    new pos,
        posxx,
        funcname[MAX_FUNC_NAME],
        funcnameEx[MAX_FUNC_NAME];

    while(Maksd[++pos] > ' '){
		if(pos == 1) funcname[pos-1] = Maksd[pos];
		else funcname[pos-1] = tolower(Maksd[pos]);
	}

    while(Mensagem[++posxx] > ' '){
	    funcnameEx[posxx-1] = tolower(Mensagem[posxx]);
	}

    format(MaksdEx, sizeof(MaksdEx), "!%s", funcnameEx);
    if(strcmp(MaksdEx, funcname)) return 1;


	format(funcname, sizeof(funcname), "dc_%s", funcnameEx);
    while (Maksd[pos] == ' ') pos++; 

    // printf("%s - %s - %s - %s", UsuarioRID, ServidorRID, CanalRID, Maksd[pos]);
	if(!Maksd[pos])
	{
		return CallLocalFunction(funcname, "ssss", UsuarioRID, ServidorRID, CanalRID, "\1");
	}
	return CallLocalFunction(funcname, "ssss", UsuarioRID, ServidorRID, CanalRID, Maksd[pos]);
}