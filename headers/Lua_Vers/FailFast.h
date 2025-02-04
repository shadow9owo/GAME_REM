#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"
#include <Windows.h>
#include "../Window/Data/WindowData.h"
#include "../Window/Data/GameData.h"

int lua_FailFast(lua_State *L) 
{
    MessageBoxA(NULL,luaL_checkstring(L,1),WINDOWDATA_Title,MB_OK | MB_ICONERROR);
    GAME_ISRUNNING = false;
    return 0;
}