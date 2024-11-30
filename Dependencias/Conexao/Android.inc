#include <YSI_Coding\y_hooks>
#pragma warning disable 239

#define IsPlayerAndroid(%0)                 GetPVarInt(%0, "NotAndroid") == 0

hook OnPlayerConnect(playerid)
{
    SendClientCheck(playerid, 0x48, 0, 0, 2);
    return 1;
}

public OnClientCheckResponseFix(playerid, type, arg, response)
{
    switch(type)
    {       
        case 0x48:{SetPVarInt(playerid, "NotAndroid", 1);}
    }
    return 1;
}