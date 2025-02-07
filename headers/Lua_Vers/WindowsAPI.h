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

int lua_MBOX(lua_State *L) 
{
    LPCSTR title = luaL_checkstring(L, 1);
    LPCSTR caption = luaL_checkstring(L, 2);
    UINT button = (UINT)luaL_checkinteger(L, 3);
    UINT icon = (UINT)luaL_checkinteger(L, 4);

    MessageBoxA(NULL, title, caption, button | icon);
    return 0;
}