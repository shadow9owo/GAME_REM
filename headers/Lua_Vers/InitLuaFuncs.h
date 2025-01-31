#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"

//lua wrapped versions of funcs
#include "DeltaTime.h"
#include "WindowBG.h"
#include "Sound.h"
#include "Keys.h"

void init_lua_funcs(lua_State *L)
{
    lua_register(L,"GetDeltaTime", lua_GetDeltaTime);
    lua_register(L,"ClearBackground", lua_ClearBackground);
    lua_register(L,"DrawbBckground", lua_Drawbackground);
    lua_register(L,"UpdateWindow",lua_UpdateWindow);
    lua_register(L,"DrawPixel",lua_drawpixel);
    lua_register(L,"DrawSquare",lua_drawsquare);
    lua_register(L,"PlaySound",lua_Playsound);
    lua_register(L,"IsKeyDown",lua_IsKeyDown);
    return;
}