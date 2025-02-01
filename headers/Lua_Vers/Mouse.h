#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"

#include "../Window/Data/WindowData.h"

#include <windows.h>
#include <stdio.h>

extern int lua_getmouse_X(lua_State *L) {
    POINT p;
    if (GetCursorPos(&p)) {
        ScreenToClient(WINDOWDATA_handle, &p);
        lua_pushinteger(L,p.x);
    }
    return 0;
}

extern int lua_getmouse_Y(lua_State *L) {
    POINT p;
    if (GetCursorPos(&p)) {
        ScreenToClient(WINDOWDATA_handle, &p);
        lua_pushinteger(L,p.y);
    }
    return 0;
}