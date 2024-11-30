#include <a_samp>

forward OnClientCheckResponse(playerid, type, arg, response);
public OnClientCheckResponse(playerid, type, arg, response)
        CallRemoteFunction("OnClientCheckResponseFix", "dddd", playerid, type, arg, response);