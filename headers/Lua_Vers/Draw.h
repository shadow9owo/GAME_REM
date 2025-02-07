#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"
#include "../Window/Data/WindowData.h"

#include <Windows.h>

int Pixel_Array_Lenght = 0;
int Pixel_Array[8192][5];

HBITMAP Bmp_Array[8192];
int Bmp_Pos_Array[8192][5];
int Bmp_Array_Length = 0;

extern int lua_drawimage(lua_State *L)
{
    if (Bmp_Array_Length >= 8192)
        return luaL_error(L, "Too many images loaded (max 8192)");

    const char *inputPath = luaL_checkstring(L, 1); 

    char currentDir[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, currentDir);

    char fullPath[MAX_PATH];
    snprintf(fullPath, sizeof(fullPath), "%s\\assets\\%s", currentDir, inputPath);

    HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, fullPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    if (!hBitmap)
        return luaL_error(L, "Failed to load image: %s", fullPath);

    Bmp_Array[Bmp_Array_Length] = hBitmap;

    Bmp_Pos_Array[Bmp_Array_Length][0] = luaL_checkinteger(L, 2);
    Bmp_Pos_Array[Bmp_Array_Length][1] = luaL_checkinteger(L, 3);
    Bmp_Pos_Array[Bmp_Array_Length][2] = luaL_checkinteger(L, 4);
    Bmp_Pos_Array[Bmp_Array_Length][3] = luaL_checkinteger(L, 5);
    Bmp_Pos_Array[Bmp_Array_Length][4] = luaL_optinteger(L, 6, 0); 
    Bmp_Array_Length++;

    lua_pushinteger(L, 0);
    return 1;
}


extern int lua_drawpixel(lua_State *L)
{
    if (Pixel_Array_Lenght < sizeof(Pixel_Array) / sizeof(Pixel_Array[0])) {
        int x = luaL_checkinteger(L, 1);
        int y = luaL_checkinteger(L, 2);
        int w = 1;
        int h = 1;
        int depth = luaL_optinteger(L, 3, 0);

        Pixel_Array[Pixel_Array_Lenght][0] = x;
        Pixel_Array[Pixel_Array_Lenght][1] = y;
        Pixel_Array[Pixel_Array_Lenght][2] = w;
        Pixel_Array[Pixel_Array_Lenght][3] = h;

        Pixel_Array[Pixel_Array_Lenght][4] = depth;

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
        int depth = luaL_optinteger(L, 5, 0);

        Pixel_Array[Pixel_Array_Lenght][0] = x;
        Pixel_Array[Pixel_Array_Lenght][1] = y;
        Pixel_Array[Pixel_Array_Lenght][2] = w;
        Pixel_Array[Pixel_Array_Lenght][3] = h;
        
        Pixel_Array[Pixel_Array_Lenght][4] = depth;

        Pixel_Array_Lenght++;
    }
    lua_pushinteger(L,0);
    return 0;
}
