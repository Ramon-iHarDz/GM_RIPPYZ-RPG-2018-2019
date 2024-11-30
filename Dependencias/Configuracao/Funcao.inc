/*#if defined _ALS_DestroyDynamicMapIcon
	#undef DestroyDynamicMapIcon
#else
	#define _ALS_DestroyDynamicMapIcon
#endif
#define DestroyDynamicMapIcon DestroyDynamicMapIconEx

#if defined _ALS_DestroyDynamicCP
	#undef DestroyDynamicCP
#else
	#define _ALS_DestroyDynamicCP
#endif
#define DestroyDynamicCP DestroyDynamicCPEx

#if defined _ALS_DestroyDynamicRaceCP
	#undef DestroyDynamicRaceCP
#else
	#define _ALS_DestroyDynamicRaceCP
#endif
#define DestroyDynamicRaceCP DestroyDynamicRaceCPEx

#if defined _ALS_DestroyDynamicObject
	#undef DestroyDynamicObject
#else
	#define _ALS_DestroyDynamicObject
#endif
#define DestroyDynamicObject DestroyDynamicObjectEx

#if defined _ALS_DestroyDynamicPickup
	#undef DestroyDynamicPickup
#else
	#define _ALS_DestroyDynamicPickup
#endif
#define DestroyDynamicPickup DestroyDynamicPickupEx

#if defined _ALS_DestroyDynamicArea
	#undef DestroyDynamicArea
#else
	#define _ALS_DestroyDynamicArea
#endif
#define DestroyDynamicArea DestroyDynamicAreaEx

#if defined _ALS_DestroyDynamicActor
	#undef DestroyDynamicActor
#else
	#define _ALS_DestroyDynamicActor
#endif
#define DestroyDynamicActor DestroyDynamicActorEx

#if defined _ALS_DestroyDynamic3DTextLabel
	#undef DestroyDynamic3DTextLabel
#else
	#define _ALS_DestroyDynamic3DTextLabel
#endif
#define DestroyDynamic3DTextLabel DestroyDynamic3DTextLabelEx*/

new ANT_CARACTER[] = { "-", "+", ",", "=", "'", "*", "?", "[", "]", "`", "´", "/",
"|", "{", "}", "<", ">", "£", "³", "¢¬", "³", "²", "²", "¹", "#", "&", ")",
"(", "¹", "°", "¨", "¬", "%", "$", "!", "^", "~"};

new const g_aPreloadLibs[][] = //topo
{
	"AIRPORT","ATTRACTORS","BAR","BASEBALL","BD_FIRE","BEACH","BENCHPRESS","BF_INJECTION",
	"BIKE_DBZ","BIKED","BIKEH","BIKELEAP","BIKES","BIKEV","BLOWJOBZ","BMX","BOMBER","BOX",
	"BSKTBALL","BUDDY","BUS","CAMERA","CAR","CAR_CHAT","CARRY","CASINO","CHAINSAW","CHOPPA",
	"CLOTHES","COACH","COLT45","COP_AMBIENT","COP_DVBYZ","CRACK","CRIB","DAM_JUMP","DANCING",
	"DEALER","DILDO","DODGE","DOZER","DRIVEBYS","FAT","FIGHT_B","FIGHT_C","FIGHT_D","FIGHT_E",
	"FINALE","FINALE2","FLAME","FLOWERS","FOOD","FREEWEIGHTS","GANGS","GFUNK","GHANDS","GHETTO_DB",
	"GOGGLES","GRAFFITI","GRAVEYARD","GRENADE","GYMNASIUM","HAIRCUTS","HEIST9","INT_HOUSE",
	"INT_OFFICE","INT_SHOP","JST_BUISNESS", "KART","KISSING","KNIFE","LAPDAN1","LAPDAN2","LAPDAN3",
	"LOWRIDER","MD_CHASE","MD_END","MEDIC","MISC","MTB","MUSCULAR","NEVADA","ON_LOOKERS","OTB",
	"PARACHUTE","PARK","PAULNMAC","PED","PLAYER_DVBYS","PLAYIDLES","POLICE","POOL","POOR","PYTHON",
	"QUAD","QUAD_DBZ","RAPPING","RIFLE","RIOT","ROB_BANK","ROCKET","RUNNINGMAN","RUSTLER","RYDER",
	"SCRATCHING","SEX","SHAMAL","SHOP","SHOTGUN","SILENCED","SKATE","SMOKING","SNIPER","SNM","SPRAYCAN",
	"STRIP","SUNBATHE","SWAT","SWEET","SWIM","SWORD","TANK","TATTOOS","TEC","TRAIN","TRUCK","UZI","VAN",
	"VENDING","VORTEX","WAYFARER","WEAPONS","WOP","WUZI"
};

/*new VehicleNames[212][] =
{
    {"Landstalker"},{"Bravura"},{"Buffalo"},{"Linerunner"},{"Perrenial"},{"Sentinel"},{"Dumper"},
    {"Firetruck"},{"Trashmaster"},{"Stretch"},{"Manana"},{"Infernus"},{"Voodoo"},{"Pony"},{"Mule"},
    {"Cheetah"},{"Ambulance"},{"Leviathan"},{"Moonbeam"},{"Esperanto"},{"Taxi"},{"Washington"},
    {"Bobcat"},{"Mr Whoopee"},{"BF Injection"},{"Hunter"},{"Premier"},{"Enforcer"},{"Securicar"},
    {"Banshee"},{"Predator"},{"Bus"},{"Rhino"},{"Barracks"},{"Hotknife"},{"Trailer 1"},{"Previon"},
    {"Coach"},{"Cabbie"},{"Stallion"},{"Rumpo"},{"RC Bandit"},{"Romero"},{"Packer"},{"Monster"},
    {"Admiral"},{"Squalo"},{"Seasparrow"},{"Pizzaboy"},{"Tram"},{"Trailer 2"},{"Turismo"},
    {"Speeder"},{"Reefer"},{"Tropic"},{"Flatbed"},{"Yankee"},{"Caddy"},{"Solair"},{"Berkley's RC Van"},
    {"Skimmer"},{"PCJ-600"},{"Faggio"},{"Freeway"},{"RC Baron"},{"RC Raider"},{"Glendale"},{"Oceanic"},
    {"Sanchez"},{"Sparrow"},{"Patriot"},{"Quad"},{"Coastguard"},{"Dinghy"},{"Hermes"},{"Sabre"},
    {"Rustler"},{"ZR-350"},{"Walton"},{"Regina"},{"Comet"},{"BMX"},{"Burrito"},{"Camper"},{"Marquis"},
    {"Baggage"},{"Dozer"},{"Maverick"},{"News Chopper"},{"Rancher"},{"FBI Rancher"},{"Virgo"},{"Greenwood"},
    {"Jetmax"},{"Hotring"},{"Sandking"},{"Blista Compact"},{"Police Maverick"},{"Boxville"},{"Benson"},
    {"Mesa"},{"RC Goblin"},{"Hotring Racer A"},{"Hotring Racer B"},{"Bloodring Banger"},{"Rancher"},
    {"Super GT"},{"Elegant"},{"Journey"},{"Bike"},{"Mountain Bike"},{"Beagle"},{"Cropdust"},{"Stunt"},
    {"Tanker"}, {"Roadtrain"},{"Nebula"},{"Majestic"},{"Buccaneer"},{"Shamal"},{"Hydra"},{"FCR-900"},
    {"NRG-500"},{"HPV1000"},{"Cement Truck"},{"Tow Truck"},{"Fortune"},{"Cadrona"},{"FBI Truck"},
    {"Willard"},{"Forklift"},{"Tractor"},{"Combine"},{"Feltzer"},{"Remington"},{"Slamvan"},
    {"Blade"},{"Freight"},{"Streak"},{"Vortex"},{"Vincent"},{"Bullet"},{"Clover"},{"Sadler"},
    {"Firetruck LA"},{"Hustler"},{"Intruder"},{"Primo"},{"Cargobob"},{"Tampa"},{"Sunrise"},{"Merit"},
    {"Utility"},{"Nevada"},{"Yosemite"},{"Windsor"},{"Monster A"},{"Monster B"},{"Uranus"},{"Jester"},
    {"Sultan"},{"Stratum"},{"Elegy"},{"Raindance"},{"RC Tiger"},{"Flash"},{"Tahoma"},{"Savanna"},
    {"Bandito"},{"Freight Flat"},{"Streak Carriage"},{"Kart"},{"Mower"},{"Duneride"},{"Sweeper"},
    {"Broadway"},{"Tornado"},{"AT-400"},{"DFT-30"},{"Huntley"},{"Stafford"},{"BF-400"},{"Newsvan"},
    {"Tug"},{"Trailer 3"},{"Emperor"},{"Wayfarer"},{"Euros"},{"Hotdog"},{"Club"},{"Freight Carriage"},
    {"Trailer 3"},{"Andromada"},{"Dodo"},{"RC Cam"},{"Launch"},{"Police Car (LSPD)"},{"Police Car (SFPD)"},
    {"Police Car (LVPD)"},{"Police Ranger"},{"Picador"},{"S.W.A.T. Van"},{"Alpha"},{"Phoenix"},{"Glendale"},
    {"Sadler"},{"Luggage Trailer A"},{"Luggage Trailer B"},{"Stair Trailer"},{"Boxville"},{"Farm Plow"},
    {"Utility Trailer"}
};*/

function Destravar(playerid){
    TogglePlayerControllable(playerid, 1);
    return 1;
}

enum CidadesDoCaralhoZonas
{
    NomeCidade[72],
    CMaxX,
    CMaxY,
    DMaxX,
    DMaxY
};

new Cidades[][CidadesDoCaralhoZonas] =
{
    {"Los Santos", -1056, -3000, 3003, 504},
    {"San Fierro", -3000, -3000, -1056, 1532},
    {"Las Venturas", -3000, 1532, 3000, 2992},
    {"Las Venturas", -1056, 504, 3000, 1544}
};

new Acce[sizeof(Cidades)];
hook OnGameModeInit()
{
    for(new i=0; i < sizeof(Cidades); i++){
        Acce[i] = CreateDynamicRectangle(Cidades[i][CMaxX], Cidades[i][CMaxY], Cidades[i][DMaxX], Cidades[i][DMaxY], 0, 0, -1);
    }
    return 1;
}

stock PegarCidade(Float:X, Float:Y)
{
    new localr[90],
        Float:Z
    ;
    format(localr, 90, "Sem nada caralho");
    for(new i=0; i < sizeof(Cidades); i++){
        if(!IsPointInDynamicArea(Acce[i], X, Y,  MapAndreas_FindZ_For2DCoord(Y, X, Z))) continue;
        format(localr, 90, Cidades[i][NomeCidade]);
        break;
    }
	return(localr);
}

stock PegarNick(playerid, bool:ComFake = false)
{
    new NickCapturado[30];
    if(Jogador[playerid][Logado] == false){
        GetPlayerName(playerid, NickCapturado, sizeof(NickCapturado));
        return(NickCapturado);
    }else if(Jogador[playerid][Logado] == true){
        if(ComFake == true) GetPlayerName(playerid, NickCapturado, sizeof(NickCapturado));   
        else format(NickCapturado, 70, Jogador[playerid][Nome]);
    }
    return(NickCapturado);
}

stock PegarIdPeloNick(const Procurado[])
{
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(strcmp(Procurado, PegarNick(i), true)) continue;
        return i;
    }
    return INVALID_PLAYER_ID;
}

stock PegarIdPeloNickEx(const Procurado[])
{
    for(new i=0; i < MAX_PLAYERS; i++){
        if(!IsPlayerConnected(i)) continue;
        if(strcmp(Procurado, PegarNick(i), true, 4)) continue;
        return i;
    }
    return INVALID_PLAYER_ID;
}

stock ApenasNumeros(const string[])
{
    for (new i = 0, j = strlen(string); i < j; i++)
    {
        if (string[i] > '9' || string[i] < '0') return 0;
    }
    return 1;
}

stock TemEspaco(const string[])
{
    for(new i=0, j=strlen(string); i < j; i++){
		if(string[i] == ' ') return true;
    }
    return false;
}

stock ConverterTexto(const texto[])
{
	new string[256];
	for(new i = 0; texto[i]; ++i){
		string[i] = texto[i];
		switch(string[i]){
			case 0xC0 .. 0xC3: string[i] -= 0x40;            case 0xC7 .. 0xC9: string[i] -= 0x42;            case 0xD2 .. 0xD5: string[i] -= 0x44;            case 0xD9 .. 0xDC: string[i] -= 0x47;            case 0xE0 .. 0xE3: string[i] -= 0x49;
			case 0xE7 .. 0xEF: string[i] -= 0x4B;            case 0xF2 .. 0xF5: string[i] -= 0x4D;            case 0xF9 .. 0xFC: string[i] -= 0x50;            case 0xC4, 0xE4: string[i] = 0x83;            case 0xC6, 0xE6: string[i] = 0x84;            case 0xD6, 0xF6: string[i] = 0x91;            case 0xD1, 0xF1: string[i] = 0xEC;            case 0xDF: string[i] = 0x96;            case 0xBF: string[i] = 0xAF;
		}
	}
	return string;
}

stock CaracterEspecial(const text[])
{
    for(new a; a < strlen(text); ++a){
        for(new b; b < sizeof(ANT_CARACTER); b++){
            if(text[a] == ANT_CARACTER[b]) return 1;
        }
    }
    return 0;
}

stock VerificarEmail(const email[])
{
    new at_pos = strfind(email, "@", true) + 1;
    if(email[0] == '@' || at_pos == -1){
        return false;
    }

    static const providers[][] ={
        "hotmail.com",
        "gmail.com",
        "outlook.com.br",
        "outlook.com",
        "live.com"
    };

    for(new i = 0; i < sizeof(providers); i ++){
        if(!strcmp(email[at_pos], providers[i], true)){
            return true;
        }
    }
    return false;
}

stock GetDistanceBetweenPlayers(playerid, playerid2) 
{
    new Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:tmpdis;
    GetPlayerPos(playerid, x1, y1, z1);
    GetPlayerPos(playerid2, x2, y2, z2);
    tmpdis = floatsqroot(floatpower(floatabs(floatsub(x2, x1)), 2) +floatpower(floatabs(floatsub(y2, y1)), 2)+floatpower(floatabs(floatsub(z2, z1)), 2));
    return floatround(tmpdis);
} 

stock IsPolicia(playerid){
    for(new i=0; i < sizeof(CargoPM); i++){ 
        if(!strcmp(CargoPM[i][CargoTexto], Jogador[playerid][Profissao])) return true;
    }
    return false;
}

stock IsMafia(playerid){
    for(new i=0; i < sizeof(CargoMafia); i++){
        if(!strcmp(CargoMafia[i][CargoTexto], Jogador[playerid][Profissao])) return true;
    }
    return false;   
}

stock CargoAdmin(status, playerid)
{
    static Cargo[70],
        CorCargoADM[10]
    ;

    // 1 = Com cor
    // 2 = Sem cor

    switch(Jogador[playerid][TempAdmin])
    {
        case 1: Cargo = "Aprendiz";
        case 2: Cargo = "Ajudante";
        case 3: Cargo = "Moderador";
        case 4: Cargo = "Administrador";
        case 5: Cargo = "Coordenador";
        case 6: Cargo = "Diretor";
        case 7: Cargo = "Desenvolvedor";
    }

    if(status == 1)
    {
        switch(Jogador[playerid][TempAdmin])
        {
            case 1: CorCargoADM = "{6af3af}";
            case 2: CorCargoADM = "{f2b138}";
            case 3: CorCargoADM = "{f7960f}";
            case 4: CorCargoADM = "{25b2e6}";
            case 5: CorCargoADM = "{9c27cf}";
            case 6: CorCargoADM = "{FF0000}";
            case 7: CorCargoADM = "{1eec3e}";
        }
        strins(Cargo, CorCargoADM, 0);
    }

    /*if(status == 1)
    {
        switch(Jogador[playerid][TempAdmin])
        {
            case 1: CorCargoADM = "{6af3af}";
            case 2: CorCargoADM = "{f2b138}";
            case 3: CorCargoADM = "{f7960f}";
            case 4: CorCargoADM = "{25b2e6}";
            case 5: CorCargoADM = "{9c27cf}";
            case 6: CorCargoADM = "{FF0000}";
            case 7: CorCargoADM = "{1eec3e}";
        }
        strins(Cargo, CorCargoADM, 0);
    }*/

    if(Jogador[playerid][Sexo] == 2)
    {
        if(Jogador[playerid][TempAdmin] != 1 &&
        Jogador[playerid][TempAdmin] != 2)
        {
            strins(Cargo, "a", strlen(Cargo));  
        }
    }
    return (Cargo);
}

stock JogadorSexo(cor, playerid)
{
    new Sex[70];
    if(cor == 1){
        if(Jogador[playerid][Sexo] == 1) Sex = "{00BFFF}Masculino";
        else if(Jogador[playerid][Sexo] == 2) Sex = "{FF69B4}Feminino";
    }else if(cor == 2){
        if(Jogador[playerid][Sexo] == 1) Sex = "Masculino";
        else if(Jogador[playerid][Sexo] == 2) Sex = "Feminino";    
    }
    return (Sex);
}

stock IsVip(playerid){
    if(Jogador[playerid][Vip] > gettime()) return true;
    return false;
}

stock EscapeString(const string[])
{
    new escpass[128];
    mysql_escape_string(string, escpass);
    return escpass;
}

stock PegarEstadoJogador(playerid)
{
    new Loka[30];
    switch(GetPlayerState(playerid))
    {
        case PLAYER_STATE_ONFOOT: {Loka = "A pé";}
        case PLAYER_STATE_DRIVER: {Loka = "Dirigindo";}
        case PLAYER_STATE_PASSENGER: {Loka = "Passageiro";}
    }
    return (Loka);
}

stock PegarIP(playerid)
{
    new plrIP[16];
    GetPlayerIp(playerid, plrIP, sizeof(plrIP));
    return plrIP;
}

stock PegarHWID(playerid){
    new szSerial[41];
    gpci(playerid, szSerial, sizeof(szSerial));
    return szSerial;
}

stock SegundosParaMinutos(SEGUNDOS)
{
    new MINUTOS, HORAS, DIAS, String[200];
    if(SEGUNDOS > 59){
        MINUTOS = SEGUNDOS / 60;
        SEGUNDOS = SEGUNDOS - MINUTOS * 60;
    }if(MINUTOS > 59){
        HORAS = MINUTOS / 60;
        MINUTOS = MINUTOS - HORAS * 60;
    }if(HORAS > 23){
        DIAS = HORAS / 24;
        HORAS = HORAS - DIAS * 24;
    }

    if(HORAS == 0) format(String, sizeof(String), "%02d:%02d", MINUTOS, SEGUNDOS);
    else format(String, sizeof(String), "%02d:%02d:%02d", HORAS, MINUTOS, SEGUNDOS);
    return String;
}

stock SegundosParaMinutosEx(SEGUNDOS)
{
    new MINUTOS, HORAS, DIAS, String[200];
    if(SEGUNDOS > 59){
        MINUTOS = SEGUNDOS / 60;
        SEGUNDOS = SEGUNDOS - MINUTOS * 60;
    }if(MINUTOS > 59){
        HORAS = MINUTOS / 60;
        MINUTOS = MINUTOS - HORAS * 60;
    }if(HORAS > 23){
        DIAS = HORAS / 24;
        HORAS = HORAS - DIAS * 24;
    }
    if(HORAS == 0) format(String, sizeof(String), "%02d:%02d", MINUTOS, SEGUNDOS);
    else format(String, sizeof(String), "%02d:%02d:%02d", HORAS, MINUTOS, SEGUNDOS);
    return String;
}

stock ConverterSegundos(n)
{
    new t[5], Converter[75];
    t[4] = n-gettime();
    t[0] = t[4] / 3600;
    t[1] = ((t[4] / 60) - (t[0] * 60));
    t[2] = (t[4] - ((t[0] * 3600) + (t[1] * 60)));
    t[3] = (t[0]/24);

    if(t[3] > 0)
        t[0] = t[0] % 24,
        format(Converter, sizeof(Converter), "%d Dia(s) %02d:%02d:%02d", t[3], t[0], t[1], t[2]);
    else if(t[0] > 0)
        format(Converter, sizeof(Converter), "%02d:%02d:%02d", t[0], t[1], t[2]);
    else
        format(Converter, sizeof(Converter), "%02d:%02d", t[1], t[2]);
    return Converter;
}

stock ConverterSegundosEx(SEGUNDOS) 
{
    new MINUTOS, HORAS, DIAS, String[200];

    if(SEGUNDOS > 59){
        MINUTOS = SEGUNDOS / 60;
        SEGUNDOS = SEGUNDOS - MINUTOS * 60;
    }if(MINUTOS > 59){
        HORAS = MINUTOS / 60;
        MINUTOS = MINUTOS - HORAS * 60;
    }if(HORAS > 23){
        DIAS = HORAS / 24;
        HORAS = HORAS - DIAS * 24;
    }

    format(String, sizeof(String), "%d Dia(s)", DIAS);
    if(DIAS == 0) format(String, sizeof(String),"%d Hora(s)", HORAS);
    if(DIAS == 0 && HORAS == 0) format(String, sizeof(String),"%d Minuto(s)", MINUTOS);
    if(DIAS == 0 && HORAS == 0 && MINUTOS == 0) format(String, sizeof(String),"%d Segundo(s)", SEGUNDOS);
    return String;
}

stock GetDateFromTime(timestamp)
{
    new string[32];
	new	tm <tmStamp>;
	localtime(Time:timestamp, tmStamp);

	strftime(string, sizeof(string), "%d/%m/%Y | %H:%M", tmStamp);
	return string;
}

stock GetDateFromTimeEx(timestamp)
{
    new string[32];
	new	tm <tmStamp>;
	localtime(Time:timestamp, tmStamp);
	strftime(string, sizeof(string), "%d/%m/%Y", tmStamp);
	return string;
}

stock GetDateFromTimeExx(timestamp)
{
    new string[32];
	new	tm <tmStamp>;
	localtime(Time:timestamp, tmStamp);
	strftime(string, sizeof(string), "%d/%m/%Y %H:%M:%S", tmStamp); 
	return string;
}

stock IsPlayerBot(playerid)
{  
    if(IsPlayerNPC(playerid)) return 0;
    new Serial[80], Contador;  
    gpci(playerid, Serial, sizeof(Serial));  
    for(new i = 0; i < strlen(Serial); i++)  
    {  
        if(Serial[i] >= '0' && Serial[i] <= '9')  Contador++;  
    }  
    return(Contador >= 30 || strlen(Serial) <= 30);
}

stock GetDistanceBetweenPoints(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
    return floatround(floatsqroot((( x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)) + ((z1 - z2) * (z1 - z2))));
}

stock IsVehicleInRangeOfPoint(vehicleid,Float:range,Float:x,Float:y,Float:z)
{
    return range >= GetVehicleDistanceFromPoint(vehicleid, x,y,z);
}

stock DinheiroSeparar(numbers)
{
    new temp[100], counter = -1;
    valstr(temp,numbers);
    for(new i = strlen(temp); i > 0; i--){
        counter++;
        if(counter == 3){
            strins(temp, ".",i);
            counter = 0;
        }
    }
    return temp;
}

stock alfabetohex[] = {'A','b','C','d','E','F','a','B','c','D','e','f'};
stock alfabeto [ 1 + ('Z' - 'A') ] = { 'A', 'B', ...};
stock numeros [ 1 + ('9' - '0') ] = { '0', '1', ...};
stock GetRandomString(size = 0xff)
{
    static stringBuff[0xff];
    if(size < 0xff && size) {
        for(new i; i != size; i++) stringBuff[i] = bool: random(2) ? numeros [random(sizeof numeros )] : alfabeto [random(sizeof alfabeto )];
        stringBuff[size] = EOS;
    }
    return stringBuff;
}

stock GetRandomHex(size = 0xff)
{
    new stringBuff[0xff];
    if(size < 0xff && size){
        for(new i; i != size; i++){
            stringBuff[i] = bool: random(2) ? numeros [random(sizeof numeros)] : alfabetohex[random(sizeof alfabetohex)];
		}
        stringBuff[size] = EOS;
    }
    return stringBuff;
}

function KickEx(playerid)
{
    if(!IsPlayerConnected(playerid)) return 1;
    Kick(playerid);
    return 1;
}

stock GetPointInfrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{
    new Float:angle,
	    Float:z;
    
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);
    if (IsPlayerInAnyVehicle(playerid))
	{
		GetVehicleZAngle(GetPlayerVehicleID(playerid), angle);
	}
    x += (distance * floatsin(-angle + LookingAngle[playerid], degrees));
    y += (distance * floatcos(-angle + LookingAngle[playerid], degrees));
}

stock Float:AngleToPoint(Float:x,Float:y,Float:x1,Float:y1)
{
    new Float:newang = atan(floatabs((x-x1)/(y-y1)));
    if (x1 <= x && y1 >= y) newang += 90.0;
    else if (x1 < x && y1 < y) newang = -newang + 270.0;
    else if (x1 >= x && y1 <= y) newang += 270.0;
    else if (x1 > x && y1 > y) newang = 90.0 - newang;
    return newang;
}

// Hospital //
new Float:HospitalCoords[][4] =
{
    {2027.4375,-1421.0703,16.9922,137.2809}, // Los Santos Hospital
    {1177.9089,-1323.9611,14.0939,269.8222},  // Los Santos Hospital #2
    {1579.6106,1769.0625,10.8203,90.7178},  // Las Venturas Hospital
    {-321.8259,1056.7279,19.7422,316.0064}, // Fort Carson Hospital
    {-1514.8807,2527.8003,55.7315,358.6234},  // El Quebrados Hospital
    {-2662.0439,630.5056,14.4531,177.8114}, // San Fierro Hospital
    {-2199.2495,-2311.0444,30.6250,321.2772}, // Angel Pine Hospital
    {1244.1959,332.2817,19.5547,338.3063} // Montgomery Hospital
};
new HospitalPosID[MAX_PLAYERS];

function Hospital(id, playerid)
{
    if(id == 1)
    {
        new closest, Float:distance = 99999.9;
        for(new i, j = sizeof(HospitalCoords), Float:tmp_distance; i < j; i++){
            tmp_distance = GetPlayerDistanceFromPoint(playerid, HospitalCoords[i][0], HospitalCoords[i][1], HospitalCoords[i][2]+1);
            if(tmp_distance < distance){
                distance = tmp_distance;
                closest = i;
            }
        }
        HospitalPosID[playerid] = closest;
        if(Jogador[playerid][SkinProfissao] == -1) SetSpawnInfo(playerid, 0, Jogador[playerid][Skin], HospitalCoords[HospitalPosID[playerid]][0], HospitalCoords[HospitalPosID[playerid]][1], HospitalCoords[HospitalPosID[playerid]][2]+0.5, HospitalCoords[HospitalPosID[playerid]][3], 0, 0, 0, 0, 0, 0);
        else SetSpawnInfo(playerid, 0, Jogador[playerid][SkinProfissao], HospitalCoords[HospitalPosID[playerid]][0], HospitalCoords[HospitalPosID[playerid]][1], HospitalCoords[HospitalPosID[playerid]][2]+0.5, HospitalCoords[HospitalPosID[playerid]][3], 0, 0, 0, 0, 0, 0);
    }

    else if(id == 2)
    {
        if(GetPVarInt(playerid, "SemHospital") > gettime()) return 1;
        
        SetPVarInt(playerid, "EscVeiculoTAP", 1);
        SetPVarInt(playerid, "TimX", gettime()+2);
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerInterior(playerid, 0);
        SetPlayerPos(playerid, HospitalCoords[HospitalPosID[playerid]][0], HospitalCoords[HospitalPosID[playerid]][1], HospitalCoords[HospitalPosID[playerid]][2]+0.5);
        SetPlayerFacingAngle(playerid, HospitalCoords[HospitalPosID[playerid]][3]);
        
        Jogador[playerid][uInterior] = 0;
        Jogador[playerid][uInteriorEx] = 0;
        SetPVarInt(playerid, "InteriorPersonalizadoID", 0); 
    }

    // Morrer no local
    else if(id == 3)
    {
        if(GetPVarInt(playerid, "SemHospital") > gettime()) return 1;
        if(GetPVarInt(playerid, "AssassinoMatou") == 1)
        {
            SetPVarInt(playerid, "AssassinoMatou", 0);
            Hospital(2, playerid); 
            return 1;
        }

        if(Jogador[playerid][PlanoDeSaude] < gettime())
        {
            SendClientMessage(playerid, 0x40E0D0FF, "| HOSPITAL | Você não tem plano de saúde e pagou {32CD32}$3.000{40E0D0} para o hospital");
            Jogador[playerid][DinheiroBanco] -= 3000;
        }
        Hospital(2, playerid); 
        
        /*SetPlayerPos(playerid, pMorreu[playerid][MoPosX], pMorreu[playerid][MoPosY], pMorreu[playerid][MoPosZ]);
        SetPlayerFacingAngle(playerid, pMorreu[playerid][MoPosA]);
        SetCameraBehindPlayer(playerid);
        // EnviarMorte(playerid);
        TogglePlayerControllable(playerid, 0);
        ClearAnimations(playerid);
        ApplyAnimation(playerid,"PED","KO_skid_front",4.1,0,1,1,1,0);
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerInterior(playerid, 0);
        Jogador[playerid][uInterior] = 0;
        Jogador[playerid][uInteriorEx] = 0;
        // MostrarMorte(playerid);
        pMorreu[playerid][TempoMorte] = 300; 
        pMorreu[playerid][TimerMorte] = SetTimerEx("TempoVida", 1000, true, "d", playerid);*/
    }
    return 1;
}

function Departamento(playerid)
{
    new closest, Float:distance = 999999.9;
    for(new i, j = sizeof(Pick), Float:tmp_distance; i < j; i++){
        if(!strcmp(Pick[i][MensagemPickup], "Departamento de Polícia")){
            tmp_distance = GetPlayerDistanceFromPoint(playerid, Pick[i][EntradaX], Pick[i][EntradaY], Pick[i][EntradaZ]);
            if(tmp_distance < distance){
                distance = tmp_distance;
                closest = Pick[i][LocalID];
            }
        }
    }
    return closest;
}

function GetXYBehindOfVehicle(vehicleid, &Float:x, &Float:y, Float:distance)
{
    new
        Float:a;
    GetVehiclePos( vehicleid, x, y, a );
    GetVehicleZAngle( vehicleid, a );
    x += ( distance * floatsin( -a+180, degrees ));
    y += ( distance * floatcos( -a+180, degrees ));
}

function ProfissaoExiste(const NomeProfissao[])
{
    if(!strcmp(NomeProfissao, "Desempregado")) return true;
    for(new i=0; i < sizeof(pAgencia); i++){
        if(!strcmp(NomeProfissao, pAgencia[i][ProfissaoNome])) return true;
    }
    return false;
}

function SetPlayerEmprego(playerid, const NomeProfissao[])
{
    if(!strcmp(NomeProfissao, "Desempregado")){
        SetPlayerColor(playerid, 0xFFFFFFFF);   
        Jogador[playerid][Salario] = 350;
        ResetProfissao(playerid);
        format(Jogador[playerid][Profissao], 90, "Desempregado");
        return 1;
    }

    for(new i=0; i < sizeof(pAgencia); i++)
    {
        if(!strcmp(NomeProfissao, pAgencia[i][ProfissaoNome])){
            SetPlayerColor(playerid, pAgencia[i][CorProfissao]);
            Jogador[playerid][Salario] = pAgencia[i][Salario];

            ResetProfissao(playerid);
            if(strcmp(pAgencia[i][ProfissaoPreset], "*")) CallRemoteFunction(pAgencia[i][ProfissaoPreset], "d", playerid);

            format(Jogador[playerid][Profissao], 90, NomeProfissao);
            return 1;
        }
    }
    return 0;
}

stock ResetProfissao(playerid)
{
    if(!strcmp(Jogador[playerid][Profissao], "Desempregado")) return 1;
    for(new i=0; i < sizeof(pAgencia); i++){
        if(!strcmp(pAgencia[i][ProfissaoNome], Jogador[playerid][Profissao])){
            if(strcmp(pAgencia[i][ProfissaoRemove], "*")) CallRemoteFunction(pAgencia[i][ProfissaoRemove], "d", playerid);
            break;
        }
    }
    return 1;
}

stock MesR(mess)
{
    new convertermes[20];
    switch(mess)
    {
        case 1: { convertermes = "Janeiro"; }
        case 2: { convertermes = "Fevereiro"; }
        case 3: { convertermes = "Marco"; }
        case 4: { convertermes = "Abril"; }
        case 5: { convertermes = "Maio"; }
        case 6: { convertermes = "Junho"; }
        case 7: { convertermes = "Julho"; }
        case 8: { convertermes = "Agosto"; }
        case 9: { convertermes = "Setembro"; }
        case 10: { convertermes = "Outubro"; }
        case 11: { convertermes = "Novembro"; }
        case 12: { convertermes = "Dezembro"; }
    }
    return convertermes;
}

stock GetVehicleNameByModel(vehicleid)
{
    new vehname[18];
    switch(vehicleid)
    {
        case 400: vehname = "Landstalker";
        case 401: vehname = "Bravura";
        case 402: vehname = "Buffalo";
        case 403: vehname = "Linerunner";
        case 404: vehname = "Perenniel";
        case 405: vehname = "Sentinel";
        case 406: vehname = "Dumper";
        case 407: vehname = "Firetruck";
        case 408: vehname = "Trashmaster";
        case 409: vehname = "Stretch";
        case 410: vehname = "Manana";
        case 411: vehname = "Infernus";
        case 412: vehname = "Voodoo";
        case 413: vehname = "Pony";
        case 414: vehname = "Mule";
        case 415: vehname = "Cheetah";
        case 416: vehname = "Ambulance";
        case 417: vehname = "Leviathan";
        case 418: vehname = "Moonbeam";
        case 419: vehname = "Esperanto";
        case 420: vehname = "Taxi";
        case 421: vehname = "Washington";
        case 422: vehname = "Bobcat";
        case 423: vehname = "Mr Whoopee";
        case 424: vehname = "BF Injection";
        case 425: vehname = "Hunter";
        case 426: vehname = "Premier";
        case 427: vehname = "Enforcer";
        case 428: vehname = "Securicar";
        case 429: vehname = "Banshee";
        case 430: vehname = "Predator";
        case 431: vehname = "Bus";
        case 432: vehname = "Rhino";
        case 433: vehname = "Barracks";
        case 434: vehname = "Hotknife";
        case 435: vehname = "Article Trailer";
        case 436: vehname = "Previon";
        case 437: vehname = "Coach";
        case 438: vehname = "Cabbie";
        case 439: vehname = "Stallion";
        case 440: vehname = "Rumpo";
        case 441: vehname = "RC Bandit";
        case 442: vehname = "Romero";
        case 443: vehname = "Packer";
        case 444: vehname = "Monster";
        case 445: vehname = "Admiral";
        case 446: vehname = "Squallo";
        case 447: vehname = "Seasparrow";
        case 448: vehname = "Pizzaboy";
        case 449: vehname = "Tram";
        case 450: vehname = "Article Trailer 2";
        case 451: vehname = "Turismo";
        case 452: vehname = "Speeder";
        case 453: vehname = "Reefer";
        case 454: vehname = "Tropic";
        case 455: vehname = "Flatbed";
        case 456: vehname = "Yankee";
        case 457: vehname = "Caddy";
        case 458: vehname = "Solair";
        case 459: vehname = "Topfun Van";
        case 460: vehname = "Skimmer";
        case 461: vehname = "PCJ-600";
        case 462: vehname = "Faggio";
        case 463: vehname = "Freeway";
        case 464: vehname = "RC Baron";
        case 465: vehname = "RC Raider";
        case 466: vehname = "Glendale";
        case 467: vehname = "Oceanic";
        case 468: vehname = "Sanchez";
        case 469: vehname = "Sparrow";
        case 470: vehname = "Patriot";
        case 471: vehname = "Quad";
        case 472: vehname = "Coastguard";
        case 473: vehname = "Dinghy";
        case 474: vehname = "Hermes";
        case 475: vehname = "Sabre";
        case 476: vehname = "Rustler";
        case 477: vehname = "ZR-350";
        case 478: vehname = "Walton";
        case 479: vehname = "Regina";
        case 480: vehname = "Comet";
        case 481: vehname = "BMX";
        case 482: vehname = "Burrito";
        case 483: vehname = "Camper";
        case 484: vehname = "Marquis";
        case 485: vehname = "Baggage";
        case 486: vehname = "Dozer";
        case 487: vehname = "Maverick";
        case 488: vehname = "SAN News Maverick";
        case 489: vehname = "Rancher";
        case 490: vehname = "FBI Rancher";
        case 491: vehname = "Virgo";
        case 492: vehname = "Greenwook";
        case 493: vehname = "Jetmax";
        case 494: vehname = "Hotring Racer";
        case 495: vehname = "Sandking";
        case 496: vehname = "Blista Compact";
        case 497: vehname = "Police Maverick";
        case 498: vehname = "Boxville";
        case 499: vehname = "Benson";
        case 500: vehname = "Messa";
        case 501: vehname = "RC Goblin";
        case 502: vehname = "Hotring Racer";
        case 503: vehname = "Hotring Racer";
        case 504: vehname = "Bloodring Banger";
        case 505: vehname = "Rancher";
        case 506: vehname = "Super GT";
        case 507: vehname = "Elegant";
        case 508: vehname = "Journey";
        case 509: vehname = "Bike";
        case 510: vehname = "Mountain Bike";
        case 511: vehname = "Beagle";
        case 512: vehname = "Cropduster";
        case 513: vehname = "Stuntplane";
        case 514: vehname = "Tanker";
        case 515: vehname = "Roadtrain";
        case 516: vehname = "Nebula";
        case 517: vehname = "Majestic";
        case 518: vehname = "Buccaneer";
        case 519: vehname = "Shamal";
        case 520: vehname = "Hydra";
        case 521: vehname = "FCR-900";
        case 522: vehname = "NRG-500";
        case 523: vehname = "HPV1000";
        case 524: vehname = "Cement Truck";
        case 525: vehname = "Towtruck";
        case 526: vehname = "Fortune";
        case 527: vehname = "Cadrona";
        case 528: vehname = "FBI Truck";
        case 529: vehname = "Willard";
        case 530: vehname = "Forklift";
        case 531: vehname = "Tractor";
        case 532: vehname = "Combine Harvester";
        case 533: vehname = "Feltzer";
        case 534: vehname = "Remington";
        case 535: vehname = "Slamvan";
        case 536: vehname = "Blade";
        case 537: vehname = "Freight";
        case 538: vehname = "Brownstreak";
        case 539: vehname = "Vortex";
        case 540: vehname = "Vincent";
        case 541: vehname = "Bullet";
        case 542: vehname = "Clover";
        case 543: vehname = "Sadler";
        case 544: vehname = "Firetruck LA";
        case 545: vehname = "Hustler";
        case 546: vehname = "Intruder";
        case 547: vehname = "Primo";
        case 548: vehname = "Cargobob";
        case 549: vehname = "Tampa";
        case 550: vehname = "Sunrise";
        case 551: vehname = "Merit";
        case 552: vehname = "Utility Van";
        case 553: vehname = "Nevada";
        case 554: vehname = "Yosemite";
        case 555: vehname = "Windsor";
        case 556: vehname = "Monster 'A'";
        case 557: vehname = "Monster 'B'";
        case 558: vehname = "Uranus";
        case 559: vehname = "Jester";
        case 560: vehname = "Sultan";
        case 561: vehname = "Stratum";
        case 562: vehname = "Elegy";
        case 563: vehname = "Raindance";
        case 564: vehname = "RC Tiger";
        case 565: vehname = "Flash";
        case 566: vehname = "Tahoma";
        case 567: vehname = "Savanna";
        case 568: vehname = "Bandito";
        case 569: vehname = "Freight Trailer";
        case 570: vehname = "Streak Trailer";
        case 571: vehname = "Kart";
        case 572: vehname = "Mover";
        case 573: vehname = "Dune";
        case 574: vehname = "Sweeper";
        case 575: vehname = "Broadway";
        case 576: vehname = "Tornado";
        case 577: vehname = "AT400";
        case 578: vehname = "DFT-30";
        case 579: vehname = "Huntley";
        case 580: vehname = "Stafford";
        case 581: vehname = "BF-400";
        case 582: vehname = "Newsvan";
        case 583: vehname = "Tug";
        case 584: vehname = "Petrol Trailer";
        case 585: vehname = "Emperor";
        case 586: vehname = "Wayfarer";
        case 587: vehname = "Euros";
        case 588: vehname = "Hotdog";
        case 589: vehname = "Club";
        case 590: vehname = "Freight Box";
        case 591: vehname = "Article Trailer 3";
        case 592: vehname = "Andromada";
        case 593: vehname = "Dodo";
        case 594: vehname = "RC Cam";
        case 595: vehname = "Launch";
        case 596: vehname = "Police Car (LSPD)";
        case 597: vehname = "Police Car (SFPD)";
        case 598: vehname = "Police Car (LVPD)";
        case 599: vehname = "Police Ranger";
        case 600: vehname = "Picador";
        case 601: vehname = "S.W.A.T";
        case 602: vehname = "Alpha";
        case 603: vehname = "Phoenix";
        case 604: vehname = "Glendale Shit";
        case 605: vehname = "Sadler Shit";
        case 606: vehname = "Baggage Trailer";
        case 607: vehname = "Baggage Traier";
        case 608: vehname = "Tug Stairs";
        case 609: vehname = "Boxville";
        case 610: vehname = "Farm Trailer";
        case 611: vehname = "Utility Trailer";
    }
    return vehname;
}

function IsVehicleOccupied(vehicleid)
{
    for(new i=0; i < MAX_PLAYERS; i++){
        if(IsPlayerInVehicle(i, vehicleid) && GetPlayerState(i) == PLAYER_STATE_DRIVER) return 1;
    }
    return 0;
}

function IsVehicleOccupiedEx(vehicleid)
{
    for(new i=0; i < MAX_PLAYERS; i++){
        if(IsPlayerInVehicle(i, vehicleid) && GetPlayerState(i) == PLAYER_STATE_DRIVER){
            return 1;
        }
    }
    return -1;
}

stock CreateVehicleEx(DonoHHHH, Vehicletype, Float:xExx, Float:yExx, Float:zExx, Float:rotationExxxx, cor1Exxx, cor2Exxx, RespawnDelayEx, SireneExxx=0)
{
    new id;
    //if(Vehicletype == 537 || Vehicletype == 538 || Vehicletype == 449) id = AddStaticVehicleEx(Vehicletype, xExx, yExx, zExx, rotationExxxx, cor1Exxx, cor2Exxx, RespawnDelayEx, SireneExxx);
    //else id = CreateVehicle(Vehicletype, xExx, yExx, zExx, rotationExxxx, cor1Exxx, cor2Exxx, RespawnDelayEx, SireneExxx);
    id = AddStaticVehicleEx(Vehicletype, xExx, yExx, zExx, rotationExxxx, cor1Exxx, cor2Exxx, RespawnDelayEx, SireneExxx);
    if(id == INVALID_VEHICLE_ID) return 1;

    format(VeiculoServer[id][LocalVerificacao], 5, "*");
    VeiculoServer[id][PosicaoCarX] = xExx;
    VeiculoServer[id][PosicaoCarY] = yExx;
    VeiculoServer[id][PosicaoCarZ] = zExx;
    VeiculoServer[id][PosicaoCarA] = rotationExxxx;

    VeiculoServer[id][vQuebrado] = false;
    VeiculoServer[id][AntiRadar] = false;
    VeiculoServer[id][AntiFurar] = false;
    VeiculoServer[id][VeiculoRegenerar] = false;

    VeiculoServer[id][VeiculoPublico] = false;
    VeiculoServer[id][VidaMaxima] = 1000.0;
    VeiculoServer[id][Tranca] = 0;
    VeiculoServer[id][Gasolina] = SuporteGasolina(PegarGasolina(id)); 
    VeiculoServer[id][Kilometros] = 0;

    VeiculoServer[id][vVirtual] = 0;
    VeiculoServer[id][vInterior] = 0;

    VeiculoServer[id][Dono] = DonoHHHH;
    if(DonoHHHH != -1)
    {
        if(VeiculoServer[id][Dono] == 99 || DonoHHHH == 99 || VeiculoServer[id][Dono] != DonoHHHH)
        {
            new Mensagem[128];
            format(Mensagem, sizeof(Mensagem), "[Log:Veiculo]: Bugou ( ID: %d / Dono: %d / Variavel: %d / Modelo: %d )", id, DonoHHHH, VeiculoServer[id][Dono], GetVehicleModel(id));
            for(new i=0; i < MAX_PLAYERS; i++)
            {
                if(!IsPlayerConnected(i)) continue;
                if(Jogador[i][Logado] == false) continue;
                if(Jogador[i][Admin] != 7) continue;
                SendClientMessage(i, -1, Mensagem);
            }
            printf("%s", Mensagem);
        }
    }

    VeiculoServer[id][Dono2] = -1;
    VeiculoServer[id][VeiculoIDExx] = id;
    VeiculoServer[id][Cor1VeiculoEx] = cor1Exxx;
    VeiculoServer[id][Cor2VeiculoEx] = cor2Exxx;

    SetVehicleNumberPlate(id, "Rippzy-2021");

    new engine, lights, alarm, doors, bonnet, boot, objective;
	GetVehicleParamsEx(id, engine, lights, alarm, doors, bonnet, boot, objective);
	if(Vehicletype == 569 || Vehicletype == 481 || Vehicletype == 509 || Vehicletype == 510) SetVehicleParamsEx(id, VEHICLE_PARAMS_ON, lights, alarm, doors, bonnet, boot, objective); 
	else SetVehicleParamsEx(id, VEHICLE_PARAMS_OFF, lights, alarm, doors, bonnet, boot, objective); 

    VeiculoServer[id][VeiculoOn] = true;
    return id;
}

function DestroyVehicleEx(&vehicleid)
{
    if(vehicleid == INVALID_VEHICLE_ID){
        printf("[Servidor:Debug] Veículo ID: %d retornou inválido", vehicleid);
        return true;
    }
    
    new sadas[VeiculosCriadosSv],
        ida = vehicleid;
    VeiculoServer[vehicleid] = sadas;
    vehicleid = INVALID_VEHICLE_ID;
    DestroyVehicle(ida);
   //CallRemoteFunction("OnVehicleDestruido", "d", vehicleid);
    return true;
}

stock GerarPlaca()
{
    new NovaPlaca[90];
    format(NovaPlaca, sizeof(NovaPlaca), "%s-%d", GetRandomString(3), random(1000-101)+101);
    return NovaPlaca;
}

function VerificarAcessorios(playerid)
{
    new aa;
    for(new id=0; id < MAX_ACESSORIOSINV; id++){
        if(pAcessorio[playerid][id][Ativado] == true){ 
            aa = InvSlotID(playerid);
            SetPlayerAttachedObject(playerid, aa, pAcessorio[playerid][id][AcessorioObj], pAcessorio[playerid][id][Bone], pAcessorio[playerid][id][AOffsetX], pAcessorio[playerid][id][AOffsetY], pAcessorio[playerid][id][AOffsetZ], pAcessorio[playerid][id][ARotX], pAcessorio[playerid][id][ARotY], pAcessorio[playerid][id][ARotZ], pAcessorio[playerid][id][AScaleX], pAcessorio[playerid][id][AScaleY], pAcessorio[playerid][id][AScaleZ], 0xFFFFFFFF, 0xFFFFFFFF);
            pAcessorio[playerid][id][IndexAcessorio] = aa;
        }
    }
    return 1;
}

function RemoverAcessorios(playerid)
{
    for(new id=0; id < MAX_ACESSORIOSINV; id++){
        if(pAcessorio[playerid][id][Ativado] == true){
            RemovePlayerAttachedObject(playerid, pAcessorio[playerid][id][IndexAcessorio]);
        }
    }
    return 1;
}

stock BanirIp(const Ip[])
{
    new rconenviar[128];
    format(rconenviar, sizeof(rconenviar), "banip %s", Ip);
    SendRconCommand(rconenviar);
    SendRconCommand("reloadbans");
    return 1;
}

stock BanF(playerid, AdminIDBAN, const MotivoBANF[], RestanteBanF, bool:CancelWebhook = false)
{
    if(GetPVarInt(playerid, "AntiFloodPunir") == 1) return 1;
    SetPVarInt(playerid, "AntiFloodPunir", 1);

    new Cache:Conectar,
        Enviar[200],
        Mensagem[300],
        AdminZeus[90],
        RestanteBanFF = RestanteBanF,
        NovoTempo = RestanteBanF;

    format(Enviar, sizeof(Enviar), "SELECT * FROM `banimentos` WHERE `Nome` = '%s'", EscapeString(PegarNick(playerid)));
    Conectar = mysql_query(IDConexao, Enviar);
    if(mysql_errno(IDConexao) != 0) return 1;

    if(AdminIDBAN == -1) format(AdminZeus, 90, "Isabella");
    else format(AdminZeus, 90, PegarNick(AdminIDBAN));

    if(RestanteBanF != 1){
        RestanteBanFF = (RestanteBanF * 24 * 60 * 60) + gettime();
    }

    new Conc = cache_num_rows();
    cache_delete(Conectar);
    
    if(Conc > 0)
    {
        format(Enviar, sizeof(Enviar), "UPDATE `banimentos` SET `Banido` = 1, `Tempo` = %d, `Data` = %d, `Admin` = '%s', `Motivo` = '%s', `Ip` = '%s' WHERE `Nome` = '%s'", RestanteBanFF, gettime(), EscapeString(AdminZeus), EscapeString(MotivoBANF), PegarIP(playerid), EscapeString(PegarNick(playerid)));
        mysql_query(IDConexao, Enviar, false);  
        if(mysql_errno(IDConexao) != 0) return 1;
    }
    else
    {
        format(Enviar, sizeof(Enviar), "INSERT INTO `banimentos` (`Nome`, `Banido`, `Tempo`, `Data`, `Admin`, `Motivo`, `Ip`) VALUES ('%s', '%d', '%d', '%d', '%s', '%s', '%s')", EscapeString(PegarNick(playerid)), 1, RestanteBanFF, gettime(), EscapeString(AdminZeus), EscapeString(MotivoBANF), PegarIP(playerid));
        mysql_query(IDConexao, Enviar, false);  
        if(mysql_errno(IDConexao) != 0) return 1;
    }

    if(CancelWebhook == false)
    {
        SendClientMessage(playerid, -1, "| BAN | Você foi banido(a) do servidor");
        SendClientMessage(playerid, -1, "| BAN | Tire uma print apertando 'F8' caso ache que foi injusto");

        if(NovoTempo != 1)
        {
            if(AdminIDBAN == -1) format(Mensagem, sizeof(Mensagem), "| ANTI-CHEATER | Administradora Isabella baniu por %d dias o(a) jogador(a) %s ( Motivo: %s )", NovoTempo, PegarNick(playerid), MotivoBANF); 
            else format(Mensagem, sizeof(Mensagem), "| SERVIDOR | %s %s baniu por %d dias o(a) jogador(a) %s ( Motivo: %s )", CargoAdmin(2, AdminIDBAN), PegarNick(AdminIDBAN), NovoTempo, PegarNick(playerid), MotivoBANF); 
        }
        else
        {
            if(AdminIDBAN == -1) format(Mensagem, sizeof(Mensagem), "| ANTI-CHEATER | Administradora Isabella baniu o(a) jogador(a) %s ( Motivo: %s )", PegarNick(playerid), MotivoBANF); 
            else format(Mensagem, sizeof(Mensagem), "| SERVIDOR | %s %s baniu o(a) jogador(a) %s ( Motivo: %s )", CargoAdmin(2, AdminIDBAN), PegarNick(AdminIDBAN), PegarNick(playerid), MotivoBANF); 
        }

        SendClientMessageToAll(0xf03629FF, Mensagem);
        GameTextForPlayer(playerid, "~r~Banido(a)", 5000, 0);

        // Ban IP
        new rconenviar[90];
        format(rconenviar, sizeof(rconenviar), "banip %s", PegarIP(playerid));
        SendRconCommand(rconenviar);
        SendRconCommand("reloadbans");
    }
    SetTimerEx("KickEx", 1000, false, "d", playerid);
    return 1;
}

stock KickF(playerid, AdminKickF, const MotivoFFKick[], bool:AntiMsgGlobal = false)
{
    if(GetPVarInt(playerid, "AntiFloodPunir") == 1) return 1;
    SetPVarInt(playerid, "AntiFloodPunir", 1);
    new Mensagem[200];

    if(AntiMsgGlobal == false) {
        if(AdminKickF == -1) format(Mensagem, sizeof(Mensagem), "| ANTI-CHEATER | Administradora Isabella expulsou o(a) jogador(a) %s ( Motivo: %s )", PegarNick(playerid), MotivoFFKick);
        else format(Mensagem, sizeof(Mensagem), "| SERVIDOR | %s %s expulsou o(a) jogador(a) %s ( Motivo: %s )", CargoAdmin(2, AdminKickF), PegarNick(AdminKickF), PegarNick(playerid), MotivoFFKick); 
        SendClientMessageToAll(0xf03629FF, Mensagem);
    }
    SetTimerEx("KickEx", 500, false, "d", playerid);
    return 1;
}

function DarSalario(playerid)
{
    // Gambiarra
    new bangaa = Jogador[playerid][DinheiroBanco],
        Alg = Jogador[playerid][DinheiroBanco];
    if(!strcmp(Jogador[playerid][Profissao], "Desempregado")){
        Alg += 350;
        Jogador[playerid][DinheiroBanco] += 350;
    }

    new Mensagem[128];
    // SendClientMessage(playerid, 0x7FFF00FF, "+ ====================================================== +");

    // Salário Profissão
    if(!strcmp(Jogador[playerid][Profissao], "Desempregado")) format(Mensagem, sizeof(Mensagem), "» Auxílio Emergencial: {32CD32}$%d", 350);
    else if(Jogador[playerid][Salario] != 0)
    {
        Alg += Jogador[playerid][Salario];
        Jogador[playerid][DinheiroBanco] += Jogador[playerid][Salario];
        format(Mensagem, sizeof(Mensagem), "» Salário: {32CD32}$%s", DinheiroSeparar(Jogador[playerid][Salario]));
        SendClientMessage(playerid, -1, Mensagem);
    }
    
    // Salário VIP
    if(Jogador[playerid][Vip] > gettime())
    {
        Alg += 3000;
        Jogador[playerid][DinheiroBanco] += 3000;
        format(Mensagem, sizeof(Mensagem), "» Salário VIP: {32CD32}$%s", DinheiroSeparar(3000));
        SendClientMessage(playerid, -1, Mensagem); 
    }

    if(Jogador[playerid][Luta] > 0)
    {
        Alg -= 950;
        Jogador[playerid][DinheiroBanco] -= 950;
        format(Mensagem, sizeof(Mensagem), "» Academia: {FE2E2E}-$%s", DinheiroSeparar(950));
        SendClientMessage(playerid, -1, Mensagem);    
    }

    // Verificar se tem plano de saúde
    if(Jogador[playerid][PlanoDeSaude] > gettime())
    {
        Alg -= 400;
        Jogador[playerid][DinheiroBanco] -= 400;
        format(Mensagem, sizeof(Mensagem), "» Plano de Saúde: {FE2E2E}-$%s", DinheiroSeparar(400));
        SendClientMessage(playerid, -1, Mensagem);    
    }

    AtualizarSaldoBancario(playerid, Alg);
    format(Mensagem, sizeof(Mensagem), "» Saldo Bancário: {FFFF00}$%s{FFFFFF} | Saldo Antigo: {FE2E2E}$%s", DinheiroSeparar(Jogador[playerid][DinheiroBanco]), DinheiroSeparar(bangaa));
    SendClientMessage(playerid, -1, Mensagem);
    // SendClientMessage(playerid, 0x7FFF00FF, "+ ====================================================== +"); 
    GerarMercadoria(playerid);
    return 1;
}

// Ponta(17, 21, 20);
// Sistema de Ponta ( Feito por mim CRL <3 )
// Como usar:
// Atual - Valor atual, exemplo seu créditos atuais
// Informad - Valor informado na dialog ou algo do gênero
// ValorMaximo - É o valor maximo que não pode passar, exemplo das semente que o máximo é 20
function Ponta(ValorAtl, Informad, ValorMaximo)
{
    new Contad = 0;
    if(Informad >= ValorMaximo){
        for(new i=ValorAtl; i < ValorMaximo; i++){
            Contad++;
        }
    }else{
        for(new i=Informad; i < ValorMaximo; i++){
            Contad++;
        }
    }

    new Cleiton = Informad;
    Cleiton += Contad;

    if(Cleiton > ValorMaximo) Contad = ValorMaximo;
    return Contad;
}

function PontaEx(valor1, valor2)
{
	new valor;
	for(new i=valor1; i < valor2; i++){
	    valor++;
	}
	return valor;
}

function VerificarApartamento(casaid)
{
    for(new i=0; i < sizeof(Apartamentos); i++)
    {
        if(Apartamentos[i] != casaid) continue;
        return true;
    }
    return false;
}

stock PreLoadAnim(playerid)
{
	new tudo = sizeof(g_aPreloadLibs);
	for(new i; i < tudo; ++i) ApplyAnimation(playerid, g_aPreloadLibs[i], "null", 4.0, 0, 0, 0, 0, 0, 1);
	return 1;
}

function RemoverArma(playerid, pweaponid)
{
    new plyWeapons[12],
        plyAmmo[12];
        
    for(new slot = 0; slot < 12; slot++){
        new pwep, pammo;
        GetPlayerWeaponData(playerid, slot, pwep, pammo);
        if(pwep != pweaponid){
            GetPlayerWeaponData(playerid, slot, plyWeapons[slot], plyAmmo[slot]);
        }
    }
    ResetPlayerWeapons(playerid);
    for(new slot = 0; slot < 12; slot++){
        GivePlayerWeapon(playerid, plyWeapons[slot], plyAmmo[slot]);
    }
    return 1;
}

stock Ligacao(playerid, id, bool:Cong = false)
{
    if(playerid == id) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode ligar para sí mesmo!");

    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) não está conectado(a)");
    if(Jogador[id][Logado] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não entrou na cidade!");

    if(Jogador[id][Celular] == false) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) não possui celular");
    if(jTelefone[id][LigacaoS] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Jogador(a) está com a linha ocupada");
    if(jTelefone[playerid][LigacaoS] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você está com a linha ocupada");
    if(Jogador[id][Preso] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Esse jogador(a) está preso(a)");

    if(Jogador[playerid][Admin] < 1){
        if(Jogador[id][Admin] > 0) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não pode ligar para um admin");
    }

    if(Cong == true)
    {
        if(Jogador[playerid][Dinheiro] < 50) return SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro sucifiente!");
        Jogador[playerid][Dinheiro] -= 50;
        SendClientMessage(playerid, -1, "| TELEFONE | Você pagou {32CD32}$50{FFFFFF} pela ligação");
        TogglePlayerControllable(playerid, 0);
    }
    
    new Mensagem[128];
    jTelefone[id][Ligando] = playerid;
    jTelefone[playerid][Ligando] = id;

    jTelefone[playerid][LigacaoS] = 3;
    jTelefone[id][LigacaoS] = 1;
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);

    jTelefone[playerid][LigacaoTimer] = SetTimerEx("LigacaoVerify", 30000, true, "ddd", playerid, id, Cong);

    format(Mensagem, sizeof(Mensagem), "| TELEFONE | %s[%d] está ligando para você ( /Atender ou /Desligar )", PegarNick(playerid), playerid);
    SendClientMessage(id, 0xFFA500FF, Mensagem);

    format(Mensagem, sizeof(Mensagem), "| TELEFONE | Você está ligando para %s[%d]", PegarNick(id), id);
    SendClientMessage(playerid, 0xFFA500FF, Mensagem);
     
    return 1;
}

function AtrasVeiculo(playerid, vehicleid, Float:Distance)
{
    if(vehicleid == INVALID_VEHICLE_ID) return false;
    new Float:cMotoH[3],
        Float:X, Float:Y;
    GetVehiclePos(vehicleid, cMotoH[0], cMotoH[1], cMotoH[2]);
    GetXYBehindOfVehicle(vehicleid, X, Y, Distance);
    if(IsPlayerInRangeOfPoint(playerid, Distance, X, Y, cMotoH[2])) return true;
    return false;
}

function TravarCodigo(playerid, const TravaNome[], Tempp)
{
    if(GetPVarInt(playerid, TravaNome) > gettime()) return true;
    if(GetPVarInt(playerid, TravaNome) == 0){
        SetPVarInt(playerid, TravaNome, gettime()+Tempp);
        return true;
    }
    return false;
}

function PegarMotorista(playerid)
{
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(i == playerid) continue;
        if(!IsPlayerConnected(i)) continue;
        if(Jogador[i][Logado] == false) continue;
        if(GetPlayerState(i) != PLAYER_STATE_DRIVER) continue;
        if(GetPlayerVehicleID(i) != GetPlayerVehicleID(playerid)) continue;
        return i;
    }
    return -1;
}

stock PegarArmaNome(id)
{
    new ArN[30];
    GetWeaponName(id, ArN, 30);
    return(ArN);
}

function FrentePosicao(Float:Infx, Float:Infy, Float:a, Float:distance, &Float:x, &Float:y)
{
    a+=180;
    Infx += ( distance * floatsin( -a+180, degrees ));
    Infy += ( distance * floatcos( -a+180, degrees ));
    x = Infx;
    y = Infy;
}

stock DestroyDynamicMapIconEx(&idasdasda)
{
    if(idasdasda == INVALID_STREAMER_ID) return 1;
    DestroyDynamicMapIcon(idasdasda);
    idasdasda = INVALID_STREAMER_ID;
    return 1;
}

stock DestroyDynamicCPEx(&idasdasda)
{
    if(idasdasda == INVALID_STREAMER_ID) return 1;
    DestroyDynamicCP(idasdasda);
    idasdasda = INVALID_STREAMER_ID;
    return 1;
}

stock DestroyDynamicRaceCPEx(&idasdasda)
{
    if(idasdasda == INVALID_STREAMER_ID) return 1;
    DestroyDynamicRaceCP(idasdasda);
    idasdasda = INVALID_STREAMER_ID;
    return 1;
}

stock DestroyDynamicObjectEx(&idasdasda)
{
    if(idasdasda == INVALID_STREAMER_ID) return 1;
    DestroyDynamicObject(idasdasda);
    idasdasda = INVALID_STREAMER_ID;
    return 1;
}

stock DestroyDynamicPickupEx(&idasdasda)
{
    if(idasdasda == INVALID_STREAMER_ID) return 1;
    DestroyDynamicPickup(idasdasda);
    idasdasda = INVALID_STREAMER_ID;
    return 1;
}

stock DestroyDynamicAreaEx(&idasdasda)
{
    if(idasdasda == INVALID_STREAMER_ID) return 1;
    DestroyDynamicArea(idasdasda);
    idasdasda = INVALID_STREAMER_ID;  
    return 1;
}

stock DestroyDynamicActorEx(&idasdasda)
{
    if(idasdasda == INVALID_STREAMER_ID) return 1;
    DestroyDynamicActor(idasdasda);
    idasdasda = INVALID_STREAMER_ID;  
    return 1;   
}

stock DestroyDynamic3DTextLabelEx(&STREAMER_TAG_3D_TEXT_LABEL:idsad)
{
    if(idsad == INVALID_3DTEXT_ID) return 1;
    DestroyDynamic3DTextLabel(idsad);
    idsad = INVALID_3DTEXT_ID;
    return 1;
}

stock DistanciaValor(Float:Dis, Vlr, VidaJggg = 2)
{
    new IntValor = floatround(Dis, floatround_round);
	new TotalValor = IntValor*Vlr/VidaJggg;
    return TotalValor;
}

stock VerificarArma(playerid, armaid)
{
    new cArmaID,
        cBalaID;
    for(new i=0; i < 12; i++)
    {
        GetPlayerWeaponData(playerid, i, cArmaID, cBalaID);
        if(cArmaID == armaid) return true;
    }
    return false;
}

stock VerificarArmaLimite(playerid, armaid, limitee)
{
    if(!VerificarArma(playerid, armaid)) return false;
    new cArmaID,
        cBalaID;
    for(new i=0; i < 12; i++)
    {
        GetPlayerWeaponData(playerid, i, cArmaID, cBalaID);
        if(cArmaID != armaid) continue;
        if(cBalaID > limitee) return true;
        break;
    }
    return false;
}

/*randomEx(min, max)
{
    new rand = random(max-min)+min;
    return rand;
}*/

stock EncodeTexto(const Texto[]) 
{
    new TextoCodee[700];
    strcat(TextoCodee, Texto);
    utf8encode(TextoCodee, TextoCodee);
    return(TextoCodee);
}

stock UncodeTexto(const Texto[]) 
{
    new TextoCodee[700];
    strcat(TextoCodee, Texto);
    utf8decode(TextoCodee, TextoCodee);
    return(TextoCodee);
}

stock LimparChat(playerid)
{
    for(new i=0; i < 99; i++){
        SendClientMessage(playerid, -1, " ");
    }
    return 1;
}

stock BugarInterior(playerid)
{
    SetPlayerInterior(playerid, 15);
    SetPlayerPos(playerid, 377.1524,1417.3621,1081.3281+10);
    return 1;   
}

stock EnviarPosicaoAdmin(playerid, int, vww, Float:x, Float:y, Float:z)
{
    SetPlayerInterior(playerid, int);
    SetPlayerVirtualWorld(playerid, vww);
    SetPlayerPos(playerid, x, y, z);
    return 1;
}

stock SelectTextDrawEx(playerid, hovercolor, const Janela[], bool:Trav = false)
{
    new Intt[60];
    GetPVarString(playerid, "JanelaClose", Intt, 60);
    
    if(Trav == true && cAC[playerid][Travado] == false)
    {
        TogglePlayerControllable(playerid, 0);
        SetPVarInt(playerid, "UsouTravamento", 1);
        SetPVarString(playerid, "JanelaCloseTrav", Janela); 
    }
    if(!strcmp(Intt, "*")) SetPVarString(playerid, "JanelaClose", Janela); 

    Jogador[playerid][AntiEsc] = true;
    SelectTextDraw(playerid, hovercolor);
    return 1;
}

stock CancelSelectTextDrawEx(playerid, const Janela[])
{
    new Intt[60],
        Inttt[60];
    GetPVarString(playerid, "JanelaClose", Intt, 60);
    GetPVarString(playerid, "JanelaCloseTrav", Inttt, 60);
    
    if(!strcmp(Intt, Janela))
    {
        SetPVarString(playerid, "JanelaClose", "*");
        CancelSelectTextDraw(playerid);
        Jogador[playerid][AntiEsc] = false;
    }

    if(GetPVarInt(playerid, "UsouTravamento") == 1 && !strcmp(Janela, Inttt))
    {
        TogglePlayerControllable(playerid, 1);
        SetPVarInt(playerid, "UsouTravamento", 0);
    }

    return 1;
}

stock GetXY(&Float:x, &Float:y, Float:a, Float:distance, Float:Rot = 90.0)
{
	a += Rot;
    x += ( distance * floatsin( -a+180, degrees ));
    y += ( distance * floatcos( -a+180, degrees ));
}

stock GetPlayerFPS(playerid)
{
    new id = playerid;
    return id;
} 

stock IsPlayerSprayingVehicle(playerid, vehicleid)
{
	new index = GetPlayerAnimationIndex(playerid),
		Float:x,
		Float:y,
		Float:z,
		Float:a;

	if(IsVehicleStreamedIn(vehicleid, playerid))
	{
		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, a);

		x += 2.0 * floatsin(-a, degrees);
		y += 2.0 * floatcos(-a, degrees);

		if(IsVehicleInRangeOfPoint(vehicleid, 2.0, x, y, z))
		{
			return (1160 <= index <= 1163) || index == 1167 || index == 640;
		}
	}
	return false;
}

stock GetPlayerSpeed(playerid) {
    new Float:tempPos[4];
    
    if(IsPlayerInAnyVehicle(playerid)) GetVehicleVelocity(GetPlayerVehicleID(playerid), tempPos[0], tempPos[1], tempPos[2]);
    else GetPlayerVelocity(playerid, tempPos[0], tempPos[1], tempPos[2]);
    tempPos[3] = floatsqroot(floatpower(floatabs(tempPos[0]), 2.0) + floatpower(floatabs(tempPos[1]), 2.0) + floatpower(floatabs(tempPos[2]), 2.0)) * 179.28625;
    
    return floatround(tempPos[3]);
}

stock GetVehicleSpeed(vehicleid)
{
    new Float:v_x;
    new Float:v_y;
    new Float:v_z;

    GetVehicleVelocity(vehicleid, v_x, v_y, v_z);

    return floatround(floatsqroot((v_x * v_x) + (v_y * v_y) + (v_z * v_z)) * 181.5);
}