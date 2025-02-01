//RENTEST ENGINE
//DEVELOPED BY SHADOWSTUDIOS 2025
//shadowdevreal@protonmail.com

#include <stdio.h>
#include "headers/Window/Game.h"
#include <stdbool.h>
#include "Lua542/include/lua.h"
#include "Lua542/include/lualib.h"
#include "Lua542/include/lauxlib.h"
#include "headers/Math/Vector2I.h"
#include "headers/Math/MathUtils.h"
#include "headers/Lua_Vers/InitLuaFuncs.h"

int main() {
    int Tick = 0;

    GetDeltaTime(); //inits delta time

    //define lua variables
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    lua_pushstring(L, WINDOWDATA_Title);
    lua_setglobal(L,"WINDOWDATA_Title");

    lua_pushinteger(L,WINDOWDATA_WindowHeight);
    lua_setglobal(L,"WINDOWDATA_WindowHeight");

    lua_pushinteger(L,WINDOWDATA_WindowWidth);
    lua_setglobal(L,"WINDOWDATA_WindowWidth");

    lua_pushinteger(L,TICKRATE);
    lua_setglobal(L,"GAME_TICKRATE");

    lua_pushinteger(L,Tick);
    lua_setglobal(L,"C_Tick");
    
    lua_pushboolean(L,UpdateLUAISRUNNING);
    lua_setglobal(L,"UpdateLUAISRUNNING"); //change this before exiting update

    lua_pushinteger(L,FrameDelay);
    lua_setglobal(L,"GAME_FRAMEDELAY");

    lua_pushboolean(L,GAME_ISRUNNING);
    lua_setglobal(L,"GAME_ISRUNNING");

    init_lua_funcs(L);

    //INIT
    Vector2I windowsize = 
    {
        1280, //X
        720 //Y
    };

    char title[256]  = "title"; //WINDOW TITLE

    //execute an script on app load
    if (luaL_dofile(L, "scripts/onload.lua") != LUA_OK) {
        printf("%s", lua_tostring(L, -1));
        lua_pop(L, 1);
    }

    START_GAME(windowsize,title);
    
    MSG msg;
    while (GAME_ISRUNNING) {

        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (Tick >= TICKRATE && !UpdateLUAISRUNNING)
        {
            Pixel_Array_Lenght = 0;
            if (luaL_dofile(L, "scripts/update.lua") != LUA_OK) {
                printf("%s", lua_tostring(L, -1));
                lua_pop(L, 1);
            }
        }
        else 
        {
            Tick++;
        }
    }

    lua_close(L);

    return 0;
}
