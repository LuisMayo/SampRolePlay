#if defined _rz_messages_included
  #endinput
#endif
#define _rz_messages_included
 
#if !defined _samp_included
        #tryinclude <a_samp>
        #if !defined _samp_included
                #error The include a_samp.inc could not be found, please check your includes!
        #endif
#endif
 
#if !defined foreach
        #tryinclude <foreach>
        #if !defined foreach
                #error The include foreach.inc could not be found, please check your includes!
        #endif
#endif
 
#if !defined MAX_LENGTH
    #define MAX_LENGTH 100
#endif
 
#if !defined MAX_PREFIX_LENGTH
    #define MAX_PREFIX_LENGTH 144
#endif
 
// GENERAL MESSAGES:
 
stock SendMessage(playerid, color, message[], length = MAX_LENGTH)
{
    new len = strlen(message);
    if(len <= length) SendClientMessage(playerid, color, message);
    else
    {
        new string[180], lastspace, escape = floatround(length / 1.2);
        while(len > length)
        {
            format(string, sizeof(string), "%s", message);
            for(new i = 0; i <= len; i ++)
            {
                if(message[i] == ' ' && i <= length) lastspace = i;
                if(i > length) i = len;
            }
 
            if(lastspace == 0)
            {
                strdel(string, length, strlen(string));
                strdel(message, 0, length);
                len -= length;
            }
            else if(lastspace < escape)
            {
                strdel(string, escape, strlen(string));
                strdel(message, 0, escape);
                len -= escape;
                lastspace = 0;
            }
            else
            {
                strdel(string, lastspace, strlen(string));
                strdel(message, 0, lastspace + 1);
                len -= lastspace;
                lastspace = 0;
            }
 
            SendClientMessage(playerid, color, string);
            if(len < length) SendClientMessage(playerid, color, message);
        }
    }
    return 1;
}
 
stock SendMessageToAll(color, message[], length = MAX_LENGTH)
{
    new len = strlen(message);
    if(len <= length)
    {
        foreach(new i: Player)
        {
            SendClientMessage(i, color, message);
        }
    }
    else
    {
        new string[144], lastspace, escape = floatround(length / 1.2);
        while(len > length)
        {
            format(string, sizeof(string), "%s", message);
            for(new i = 0; i <= len; i ++)
            {
                if(message[i] == ' ' && i <= length) lastspace = i;
                if(i > length) i = len;
            }
 
            if(lastspace == 0)
            {
                strdel(string, length, strlen(string));
                strdel(message, 0, length);
                len -= length;
            }
            else if(lastspace < escape)
            {
                strdel(string, escape, strlen(string));
                strdel(message, 0, escape);
                len -= escape;
                lastspace = 0;
            }
            else
            {
                strdel(string, lastspace, strlen(string));
                strdel(message, 0, lastspace + 1);
                len -= lastspace;
                lastspace = 0;
            }
 
            foreach(new i: Player)
            {
                SendClientMessage(i, color, string);
                if(len < length) SendClientMessage(i, color, message);
            }
        }
    }
    return 1;
}
 
stock SendWhisperMessage(Float:range, playerid, color, message[], length = MAX_LENGTH)
{
    new len = strlen(message);
    if(len <= length)
    {
        foreach(new i: Player)
        {
            if(IsPlayerCloseToPlayer(playerid, i, range))
            {
                SendClientMessage(i, color, message);
            }
        }
    }
    else
    {
        new string[144], lastspace, escape = floatround(length / 1.2);
        while(len > length)
        {
            format(string, sizeof(string), "%s", message);
            for(new i = 0; i <= len; i ++)
            {
                if(message[i] == ' ' && i <= length) lastspace = i;
                if(i > length) i = len;
            }
 
            if(lastspace == 0)
            {
                strdel(string, length, strlen(string));
                strdel(message, 0, length);
                len -= length;
            }
            else if(lastspace < escape)
            {
                strdel(string, escape, strlen(string));
                strdel(message, 0, escape);
                len -= escape;
                lastspace = 0;
            }
            else
            {
                strdel(string, lastspace, strlen(string));
                strdel(message, 0, lastspace + 1);
                len -= lastspace;
                lastspace = 0;
            }
 
            foreach(new i: Player)
            {
                if(IsPlayerCloseToPlayer(playerid, i, range))
                {
                    SendClientMessage(i, color, string);
                    if(len < length) SendClientMessage(i, color, message);
                }
            }
        }
    }
    return 1;
}
 
stock SendPrivateMessage(forplayerid, color, message[], length = MAX_LENGTH) return SendMessage(forplayerid, color, message, length);
 
stock SendMessageToRCONAdmins(color, message[], length = MAX_LENGTH)
{
    new len = strlen(message);
    if(len <= length)
    {
        foreach(new i: Player)
        {
            if(IsPlayerAdmin(i))
            {
                SendClientMessage(i, color, message);
            }
        }
    }
    else
    {
        new string[144], lastspace, escape = floatround(length / 1.2);
        while(len > length)
        {
            format(string, sizeof(string), "%s", message);
            for(new i = 0; i <= len; i ++)
            {
                if(message[i] == ' ' && i <= length) lastspace = i;
                if(i > length) i = len;
            }
 
            if(lastspace == 0)
            {
                strdel(string, length, strlen(string));
                strdel(message, 0, length);
                len -= length;
            }
            else if(lastspace < escape)
            {
                strdel(string, escape, strlen(string));
                strdel(message, 0, escape);
                len -= escape;
                lastspace = 0;
            }
            else
            {
                strdel(string, lastspace, strlen(string));
                strdel(message, 0, lastspace + 1);
                len -= lastspace;
                lastspace = 0;
            }
 
            foreach(new i: Player)
            {
                if(IsPlayerAdmin(i))
                {
                    SendClientMessage(i, color, string);
                    if(len < length) SendClientMessage(i, color, message);
                }
            }
        }
    }
    return 1;
}
 
// PREFIX MESSAGES:
 
stock SendPrefixMessage(playerid, color, prefix[MAX_PREFIX_LENGTH], message[], length = MAX_LENGTH)
{
    new len = strlen(message);
    if(len <= length)
    {
        strins(message, prefix, 0, sizeof(prefix));
        SendClientMessage(playerid, color, message);
    }
    else
    {
        new string[144], lastspace, escape = floatround(length / 1.2);
        while(len > length)
        {
            format(string, sizeof(string), "%s", message);
            for(new i = 0; i <= len; i ++)
            {
                if(message[i] == ' ' && i <= length) lastspace = i;
                if(i > length) i = len;
            }
 
            if(lastspace == 0)
            {
                strdel(string, length, strlen(string));
                strdel(message, 0, length);
                len -= length;
            }
            else if(lastspace < escape)
            {
                strdel(string, escape, strlen(string));
                strdel(message, 0, escape);
                len -= escape;
                lastspace = 0;
            }
            else
            {
                strdel(string, lastspace, strlen(string));
                strdel(message, 0, lastspace + 1);
                len -= lastspace;
                lastspace = 0;
            }
 
            strins(string, prefix, 0, sizeof(prefix));
            SendClientMessage(playerid, color, string);
            if(len < length)
            {
                strins(message, prefix, 0, sizeof(prefix));
                SendClientMessage(playerid, color, message);
            }
        }
    }
    return 1;
}
 
stock SendPrefixMessageToAll(color, prefix[MAX_PREFIX_LENGTH], message[], length = MAX_LENGTH)
{
    new len = strlen(message);
    if(len <= length)
    {
        foreach(new i: Player)
        {
            strins(message, prefix, 0, sizeof(prefix));
            SendClientMessage(i, color, message);
        }
    }
    else
    {
        new string[144], lastspace, escape = floatround(length / 1.2);
        while(len > length)
        {
            format(string, sizeof(string), "%s", message);
            for(new i = 0; i <= len; i ++)
            {
                if(message[i] == ' ' && i <= length) lastspace = i;
                if(i > length) i = len;
            }
 
            if(lastspace == 0)
            {
                strdel(string, length, strlen(string));
                strdel(message, 0, length);
                len -= length;
            }
            else if(lastspace < escape)
            {
                strdel(string, escape, strlen(string));
                strdel(message, 0, escape);
                len -= escape;
                lastspace = 0;
            }
            else
            {
                strdel(string, lastspace, strlen(string));
                strdel(message, 0, lastspace + 1);
                len -= lastspace;
                lastspace = 0;
            }
 
            foreach(new i: Player)
            {
                strins(string, prefix, 0, sizeof(prefix));
                SendClientMessage(i, color, string);
                if(len < length)
                {
                    strins(message, prefix, 0, sizeof(prefix));
                    SendClientMessage(i, color, message);
                }
            }
        }
    }
    return 1;
}
 
stock SendPrefixWhisperMessage(Float:range, playerid, color, prefix[MAX_PREFIX_LENGTH], message[], length = MAX_LENGTH)
{
    new len = strlen(message);
    if(len <= length)
    {
        foreach(new i: Player)
        {
            if(IsPlayerCloseToPlayer(playerid, i, range))
            {
                strins(message, prefix, 0, sizeof(prefix));
                SendClientMessage(i, color, message);
            }
        }
    }
    else
    {
        new string[144], lastspace, escape = floatround(length / 1.2);
        while(len > length)
        {
            format(string, sizeof(string), "%s", message);
            for(new i = 0; i <= len; i ++)
            {
                if(message[i] == ' ' && i <= length) lastspace = i;
                if(i > length) i = len;
            }
 
            if(lastspace == 0)
            {
                strdel(string, length, strlen(string));
                strdel(message, 0, length);
                len -= length;
            }
            else if(lastspace < escape)
            {
                strdel(string, escape, strlen(string));
                strdel(message, 0, escape);
                len -= escape;
                lastspace = 0;
            }
            else
            {
                strdel(string, lastspace, strlen(string));
                strdel(message, 0, lastspace + 1);
                len -= lastspace;
                lastspace = 0;
            }
 
            foreach(new i: Player)
            {
                if(IsPlayerCloseToPlayer(playerid, i, range))
                {
                    strins(string, prefix, 0, sizeof(prefix));
                    SendClientMessage(i, color, string);
                    if(len < length)
                    {
                        strins(message, prefix, 0, sizeof(prefix));
                        SendClientMessage(i, color, message);
                    }
                }
            }
        }
    }
    return 1;
}
 
stock SendPrefixPrivateMessage(forplayerid, color, prefix[MAX_PREFIX_LENGTH], message[], length = MAX_LENGTH) return SendPrefixMessage(forplayerid, color, prefix, message, length);
 
stock SendPrefixMessageToRCONAdmins(color, prefix[MAX_PREFIX_LENGTH], message[], length = MAX_LENGTH)
{
    new len = strlen(message);
    if(len <= length)
    {
        foreach(new i: Player)
        {
            if(IsPlayerAdmin(i))
            {
                strins(message, prefix, 0, sizeof(prefix));
                SendClientMessage(i, color, message);
            }
        }
    }
    else
    {
        new string[144], lastspace, escape = floatround(length / 1.2);
        while(len > length)
        {
            format(string, sizeof(string), "%s", message);
            for(new i = 0; i <= len; i ++)
            {
                if(message[i] == ' ' && i <= length) lastspace = i;
                if(i > length) i = len;
            }
 
            if(lastspace == 0)
            {
                strdel(string, length, strlen(string));
                strdel(message, 0, length);
                len -= length;
            }
            else if(lastspace < escape)
            {
                strdel(string, escape, strlen(string));
                strdel(message, 0, escape);
                len -= escape;
                lastspace = 0;
            }
            else
            {
                strdel(string, lastspace, strlen(string));
                strdel(message, 0, lastspace + 1);
                len -= lastspace;
                lastspace = 0;
            }
 
            foreach(new i: Player)
            {
                if(IsPlayerAdmin(i))
                {
                    strins(string, prefix, 0, sizeof(prefix));
                    SendClientMessage(i, color, string);
                    if(len < length)
                    {
                        strins(message, prefix, 0, sizeof(prefix));
                        SendClientMessage(i, color, message);
                    }
                }
            }
        }
    }
    return 1;
}
 
// FUNCTIONS:
 
stock IsPlayerCloseToPlayer(playerid, lookupid, Float:distance)
{
    new Float:x, Float:y, Float:z;
    GetPlayerPos(lookupid, x, y, z);
    if(IsPlayerInRangeOfPoint(playerid, distance, x, y, z) && GetPlayerInterior(playerid) == GetPlayerInterior(lookupid) && \
    GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(lookupid) && GetPlayerState(playerid) != PLAYER_STATE_SPECTATING &&
    GetPlayerState(lookupid) != PLAYER_STATE_SPECTATING) return true;
    return false;
}