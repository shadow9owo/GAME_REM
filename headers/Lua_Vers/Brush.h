#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"
#include "../Window/Data/WindowData.h"

extern int lua_SetBrushColor(lua_State *L) {
    if (lua_gettop(L) == 3) {
        int r = luaL_checkinteger(L, 1);
        int g = luaL_checkinteger(L, 2);
        int b = luaL_checkinteger(L, 3);
        BrushColor = CreateSolidBrush(RGB(r, g, b));
        lua_pushinteger(L,0);
        return 0;
    } else {
        luaL_error(L, "Expected 3 arguments for Drawbackground (r, g, b)");
    }
}
