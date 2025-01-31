#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"

int Pixel_Array_Lenght = 0;
int Pixel_Array[2048][4];

extern int lua_drawpixel(lua_State *L)
{
    if (Pixel_Array_Lenght < sizeof(Pixel_Array) / sizeof(Pixel_Array[0])) {
        int x = luaL_checkinteger(L, 1);
        int y = luaL_checkinteger(L, 2);
        int w = 1;
        int h = 1;

        Pixel_Array[Pixel_Array_Lenght][0] = x;
        Pixel_Array[Pixel_Array_Lenght][1] = y;
        Pixel_Array[Pixel_Array_Lenght][2] = w;
        Pixel_Array[Pixel_Array_Lenght][3] = h;

        Pixel_Array_Lenght++;
    }
    lua_pushinteger(L,0);
    return 0;
}

extern int lua_drawsquare(lua_State *L)
{
    if (Pixel_Array_Lenght < sizeof(Pixel_Array) / sizeof(Pixel_Array[0])) {
        int x = luaL_checkinteger(L, 1);
        int y = luaL_checkinteger(L, 2);
        int w = luaL_checkinteger(L, 3);
        int h = luaL_checkinteger(L, 4);

        Pixel_Array[Pixel_Array_Lenght][0] = x;
        Pixel_Array[Pixel_Array_Lenght][1] = y;
        Pixel_Array[Pixel_Array_Lenght][2] = w;
        Pixel_Array[Pixel_Array_Lenght][3] = h;

        Pixel_Array_Lenght++;
    }
    lua_pushinteger(L,0);
    return 0;
}
