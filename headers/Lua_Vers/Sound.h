#include <limits.h>
#include <Windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"

#pragma comment(lib, "winmm.lib")

extern int lua_Playsound(lua_State *L) 
{
    const char *inputPath = luaL_checkstring(L, 1); 

    if (inputPath == NULL || *inputPath == '\0') {
        return -1;
    }

    char currentDir[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, currentDir);

    char fullPath[MAX_PATH];
    snprintf(fullPath, sizeof(fullPath), "%s\\assets\\%s", currentDir, inputPath);

    char command[512];
    sprintf(command, "open \"%s\" type mpegvideo alias myMP3", fullPath);

    mciSendString(command, NULL, 0, NULL);
    mciSendString("play myMP3", NULL, 0, NULL);
    
    lua_pushinteger(L,0);
    return 0;
}
