#pragma once

#include "../../Lua542/include/lua.h"
#include "../../Lua542/include/lualib.h"
#include "../../Lua542/include/lauxlib.h"
#include "../Math/MathUtils.h"

extern int lua_GetDeltaTime(lua_State *L) {
    double deltaTime = (double)GetDeltaTime();
    lua_pushnumber(L, (double)deltaTime);    
    return 1; 
}