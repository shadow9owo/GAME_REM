#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"
#include "../Window/Data/WindowData.h"
#include "Draw.h"

#include <Windows.h>
#include <windowsx.h>
#include <gdiplus.h> 

extern int lua_ClearBackground(lua_State *L) {
    BackgroundColor = CreateSolidBrush(RGB(255, 255, 255));
    lua_pushinteger(L,0);
    return 0;
}

extern int lua_Drawbackground(lua_State *L) {
    if (lua_gettop(L) == 3) {
        int r = luaL_checkinteger(L, 1);
        int g = luaL_checkinteger(L, 2);
        int b = luaL_checkinteger(L, 3);
        BackgroundColor = CreateSolidBrush(RGB(r, g, b));
        lua_pushinteger(L,0);
        return 0;
    } else {
        luaL_error(L, "Expected 3 arguments for Drawbackground (r, g, b)");
    }
}

extern int lua_UpdateWindow() {
    InvalidateRect(WINDOWDATA_handle, NULL, TRUE);
    UpdateWindow(WINDOWDATA_handle);
    Pixel_Array_Lenght = 0;
    Bmp_Array_Length = 0;
    return 0;
}