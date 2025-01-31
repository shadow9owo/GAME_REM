#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"
#include "../Window/Data/WindowData.h"
#include <stdbool.h>

extern int lua_IsKeyDown(lua_State *L)
{
    int keyCode = luaL_checkinteger(L, 1);

    if (keyCode >= 0 && keyCode < 256 && keyStates[keyCode]) {
        lua_pushinteger(L,1);
        return 1;
    }else {
        lua_pushinteger(L,0);
        return 0;
    }
}