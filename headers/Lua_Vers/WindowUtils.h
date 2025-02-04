#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"
#include <Windows.h>

int lua_ConsoleVisibility(lua_State *L) 
{
    ShowWindow(GetConsoleWindow(),luaL_checkinteger(L,1));
    return 0;
}