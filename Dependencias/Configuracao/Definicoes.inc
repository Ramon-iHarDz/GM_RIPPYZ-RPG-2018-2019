#include <YSI_Coding\y_hooks>

//Macros
#define strcatEx(%0,%1,%2) \
    format(AleatoriooooooH, sizeof(AleatoriooooooH), %1, %2) , strcat(%0, AleatoriooooooH)

#if !defined isnull
    #define isnull(%1) \
                ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define PRESSED(%0) \
    ((newkeys & (%0)) == (%0))

#define PRESSEDEx(%0) \
             (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

#define HOLDING(%0) \
    ((newkeys & (%0)) == (%0))

#if !defined IsValidVehicle
    native IsValidVehicle(vehicleid);
#endif

#if !defined gpci
    native gpci(playerid, serial[], len);
#endif

#define stringclear(%0) \
    %0[0] = '\0'

#define function%0(%1) \ 
    forward%0(%1); public%0(%1)

// -negativo ( Para obter um numero negativo )
#define negativo(%1) \
        (((%1) < 0) ? (-(%1)) : ((%1)))

#define par(%0) \
	(%0 % 2)

//#define IsPlayerPaused(%1) GetTickCount() > (Jogador[%1][AltTab]+1000)
#define forEx(%0,%1) for(new %1=0; %1 < %0; %1++)
#define MaximoEstrelas 500


//Variaveis Obrigatorias
new AleatoriooooooH[2000]; //StrcatEx
new PlayerText:Federal[MAX_PLAYERS][3];
new PlayerText:GariMenu[MAX_PLAYERS][3];
new PlayerText:VelocimetroRC[MAX_PLAYERS][4];
new PlayerText:GasN[MAX_PLAYERS][1];
new PlayerText:RadarRC[MAX_PLAYERS][5];
new PlayerText:AbastecimentoPosto[MAX_PLAYERS][6];
//new PlayerText:TestDrive[MAX_PLAYERS][3];
new PlayerText:StatusTxd[MAX_PLAYERS][20];
new PlayerText:BlackSono[MAX_PLAYERS][15];
new PlayerText:AntiAFKTXD[MAX_PLAYERS][13];
new PlayerText:CounterMenu[MAX_PLAYERS][8];
new PlayerText:ArenaKD[MAX_PLAYERS][9];
new PlayerText:SkinT[MAX_PLAYERS][11];
new PlayerText:AcessorioL[MAX_PLAYERS][10];
new PlayerText:Relogio[MAX_PLAYERS][2];
new PlayerText:LocalizarComando[MAX_PLAYERS][1];

//Policia
new PlayerText:PreArmario[MAX_PLAYERS][3];
new PlayerText:PainelPolicial[MAX_PLAYERS][11];
//new PlayerText:PoliciaVeiculoTXD[MAX_PLAYERS][15];
new PlayerText:VestiarioPM[MAX_PLAYERS][12]; 

//Cnn e ann
new Text:AlertaAdmin[3];
new TempoAlertaAdmin;
new bool:AlertaAdminStt;

//Respawn - rvs
new Text:RespawnAdmin[1];
new EstadoRespawn;
new TempoRespawnAdmin;
new bool:RespawnAtivo;

//Stings
new MySQL:IDConexao;

hook OnPlayerUpdate(playerid){
	// Jogador[playerid][AltTab] = GetTickCount();
	return 1;
}

//Retirar ChatGlobal
function ProxDetector(Float:radi, playerid, const string[], col1, col2, col3, col4, col5)
{
    if(!IsPlayerConnected(playerid)) return 1;
    new Float:posx, Float:posy, Float:posz,
        Float:oldposx, Float:oldposy, Float:oldposz,
        Float:tempposx, Float:tempposy, Float:tempposz;
    GetPlayerPos(playerid, oldposx, oldposy, oldposz);
    for(new i=0; i < MAX_PLAYERS; i++)
    {
		if(!IsPlayerConnected(i)) continue;
		if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(i)) continue;
        if(GetPlayerInterior(playerid) != GetPlayerInterior(i)) continue;

		GetPlayerPos(i, posx, posy, posz);
		tempposx = (oldposx -posx);
		tempposy = (oldposy -posy);
		tempposz = (oldposz -posz);

		if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16))) {
			SendClientMessage(i, col1, string);
		}
		else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8))) {
			SendClientMessage(i, col2, string);
		}
		else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4))) {
			SendClientMessage(i, col3, string);
		}
		else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2))) {
			SendClientMessage(i, col4, string);
		}
		else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi))) {
			SendClientMessage(i, col5, string);
        }
    }
    return 1;
}

stock ProxDetectorFade(playerid, Float:max_range, color, const string[], Float:max_ratio = 1.6)
{
    new
        Float:pos_x,
        Float:pos_y,
        Float:pos_z,
        Float:range,
        Float:range_ratio,
        Float:range_with_ratio,
        clr_r, clr_g, clr_b,
        Float:color_r, Float:color_g, Float:color_b
	;

    if(!GetPlayerPos(playerid, pos_x, pos_y, pos_z)) {
        return 0;
    }

    color_r = float(color >> 24 & 0xFF);
    color_g = float(color >> 16 & 0xFF);
    color_b = float(color >> 8 & 0xFF);
    range_with_ratio = max_range * max_ratio;

	for(new i=0; i < MAX_PLAYERS; i++)
	{
        if(!IsPlayerConnected(i)) continue;
		if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(i)) continue;

        range = GetPlayerDistanceFromPoint(i, pos_x, pos_y, pos_z);
        if (range > max_range){
            continue;
        }
        range_ratio = (range_with_ratio - range) / range_with_ratio;
        clr_r = floatround(range_ratio * color_r);
        clr_g = floatround(range_ratio * color_g);
        clr_b = floatround(range_ratio * color_b);
        SendClientMessage(i, (color & 0xFF) | (clr_b << 8) | (clr_g << 16) | (clr_r << 24), string);
    }
    SendClientMessage(playerid, color, string);
    return 1;
}