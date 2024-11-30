new Naoiuwe[MAX_PLAYERS][9];

stock CorFake(playerid)
{
	new Var[300],
		rra = random(3);
	strcatEx(Var, "%s}", GetRandomHex(6));
	for(new i=0; i < rra; i++)
	{
		switch(random(8))
		{
			case 0: strcatEx(Var, "{%s}{%s}%s{%s}", GetRandomHex(6), Naoiuwe[playerid], GetRandomString(random(8-5)+5), GetRandomHex(6));
			case 1: strcatEx(Var, "{%s}{%s}%s{%s}", Naoiuwe[playerid], Naoiuwe[playerid], GetRandomString(random(8-5)+5), Naoiuwe[playerid]);
			case 2: strcatEx(Var, "{%s}{%s}%s{%s}", GetRandomHex(6), Naoiuwe[playerid], GetRandomString(random(8-5)+5), Naoiuwe[playerid]);
			case 3: strcatEx(Var, "{%s}{%s}%s{%s}", Naoiuwe[playerid], Naoiuwe[playerid], GetRandomString(random(8-5)+5), GetRandomHex(6));
			case 4: strcatEx(Var, "{%s}{%s}", GetRandomHex(6), GetRandomHex(6));
			case 5: strcatEx(Var, "{%s}{%s}", Naoiuwe[playerid], Naoiuwe[playerid]);
			case 6: strcatEx(Var, "{%s}{%s}", GetRandomHex(6), Naoiuwe[playerid]);
			case 7: strcatEx(Var, "{%s}{%s}", Naoiuwe[playerid], GetRandomHex(6));
			case 8: strcatEx(Var, "{%s}%s{%s}", Naoiuwe[playerid], GetRandomString(random(8-5)+5), GetRandomHex(6));
		}
	}
	strcatEx(Var, "{%s}{%s", GetRandomHex(6), Naoiuwe[playerid]);
	return Var;
}

stock GerarAntiAFK(playerid, const String[])
{
    // new MaxS = random(8-6)+6;
	new MaxS = 6,
        CorReal[8];
	new CodePos = MaxS;

	CodePos -= random(MaxS);
	if(CodePos >= MaxS) CodePos -= 1;

	format(Naoiuwe[playerid], 8, GetRandomHex(6));
	format(CorReal, sizeof(CorReal), "%s", GetRandomHex(6));
    pAFK[playerid][CodePosEx] = CodePos;

	stringclear(pAFK[playerid][LogAFK]);
	strcat(pAFK[playerid][LogAFK], "Slot\tCódigo\tCódigo\tCódigo\n");
	for(new i=0; i < MaxS; i++)
	{
	    if(i == CodePos)
	    {
	        switch(random(2))
	        {
	            case 0: strcatEx(pAFK[playerid][LogAFK], "%d.\t{%s}%s\t{%s}%s\t{%s}%s\n", i+1, CorFake(playerid), GetRandomString(random(8-5)+5), CorReal, String, CorFake(playerid), GetRandomString(random(8-5)+5));
	            case 1: strcatEx(pAFK[playerid][LogAFK], "%d.\t{%s}%s\t{%s}%s\t{%s}%s\n", i+1, CorReal, String, CorFake(playerid), GetRandomString(random(8-5)+5), CorFake(playerid), GetRandomString(random(8-5)+5));
				case 2: strcatEx(pAFK[playerid][LogAFK], "%d.\t{%s}%s\t{%s}%s\t{%s}%s\n", i+1, CorFake(playerid), GetRandomString(random(8-5)+5), CorFake(playerid), GetRandomString(random(8-5)+5), CorReal, String);
			}
	    }
	    else strcatEx(pAFK[playerid][LogAFK], "%d.\t{%s}%s\t{%s}%s\t{%s}%s\n", i+1, CorFake(playerid), GetRandomString(random(8-5)+5), CorFake(playerid), GetRandomString(random(8-5)+5), CorFake(playerid), GetRandomString(random(8-5)+5));
	}
    return 1;
}

stock MostrarListaAFK(playerid)
{
	Dialog_Show(playerid, SemFuncao, DIALOG_STYLE_TABLIST_HEADERS, "{FF4500}Anti-AFK", pAFK[playerid][LogAFK], "Fechar", "");
    return 1;
}