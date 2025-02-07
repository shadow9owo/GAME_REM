#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"

#include "DeltaTime.h"
#include "WindowBG.h"
#include "Sound.h"
#include "Keys.h"
#include "Brush.h"
#include "Mouse.h"
#include "FailFast.h"
#include "WindowsAPI.h"

void init_lua_funcs(lua_State *L)
{
    lua_register(L,"GetDeltaTime", lua_GetDeltaTime);
    lua_register(L,"ClearBackground", lua_ClearBackground);
    lua_register(L,"DrawBackground", lua_Drawbackground);
    lua_register(L,"UpdateWindow",lua_UpdateWindow);
    lua_register(L,"DrawPixel",lua_drawpixel);
    lua_register(L,"DrawSquare",lua_drawsquare);
    lua_register(L,"PlaySound",lua_Playsound);
    lua_register(L,"IsKeyDown",lua_IsKeyDown);
    lua_register(L,"SetBrushColor",lua_SetBrushColor);
    lua_register(L,"DrawImage",lua_drawimage);
    lua_register(L,"GetMouseX",lua_getmouse_X);
    lua_register(L,"GetMouseY",lua_getmouse_Y);
    lua_register(L,"FailFast",lua_FailFast);
    lua_register(L,"WindowVisibility",lua_ConsoleVisibility);
    lua_register(L,"MBOX",lua_MBOX);

    return;
}