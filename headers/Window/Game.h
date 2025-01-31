#pragma once

#include <Windows.h>
#include "Logging.h"
#include "Data/WindowData.h"
#include "Data/GameData.h"
#include "../Math/Vector2I.h"

extern char title[256];

extern void START_GAME(Vector2I SIZE,char *title) 
{
    title = title;
    WINDOWDATA_handle = DefineWindow(SIZE.X,SIZE.Y,title);
}