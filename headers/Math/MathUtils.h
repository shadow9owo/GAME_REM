#pragma once

#include "Vector2.h"
#include "Vector2I.h"
#include "Vector3.h"
#include "Vector3I.h"
#include "Vector4.h"
#include <math.h>
#include <Windows.h>

extern float Clamp(float input,float minimum,float maximum) 
{
    if (input > maximum) {
        return maximum;
    }else if (input < minimum) {
        return minimum;
    }else {
        return input;
    }
}

extern float InvertedClamp(float input,float minimum,float maximum) 
{
    if (input > maximum) {
        return minimum;
    }else if (input < minimum) {
        return maximum;
    }else {
        return input;
    }
}

extern float GetDistance_VECTOR2(Vector2 point_a,Vector2 point_b) 
{
    return sqrtf((point_b.X - point_a.X) * (point_b.X - point_a.X) + 
                 (point_b.Y - point_a.Y) * (point_b.Y - point_a.Y));
}

extern int GetDistance_VECTOR2I(Vector2I point_a,Vector2I point_b) 
{
    return (int)sqrtf((point_b.X - point_a.X) * (point_b.X - point_a.X) + 
                 (point_b.Y - point_a.Y) * (point_b.Y - point_a.Y));
}

extern float GetDistance_VECTOR3(Vector3 point_a,Vector3 point_b) 
{
    return sqrtf((point_b.X - point_a.X) * (point_b.X - point_a.X) + 
                 (point_b.Y - point_a.Y) * (point_b.Y - point_a.Y) + 
                 (point_b.Z - point_a.Z) * (point_b.Z - point_a.Z));
}

extern int GetDistance_VECTOR3I(Vector3I point_a,Vector3I point_b) 
{
    return (int)sqrtf((point_b.X - point_a.X) * (point_b.X - point_a.X) + 
                 (point_b.Y - point_a.Y) * (point_b.Y - point_a.Y) + 
                 (point_b.Z - point_a.Z) * (point_b.Z - point_a.Z));
}

extern float GetDistance_VECTOR4(Vector4 point_a,Vector4 point_b) //please dont while true this
{
    return sqrtf((point_b.X - point_a.X) * (point_b.X - point_a.X) + 
                 (point_b.Y - point_a.Y) * (point_b.Y - point_a.Y) + 
                 (point_b.Z - point_a.Z) * (point_b.Z - point_a.Z) + 
                 (point_b.W - point_a.W) * (point_b.W - point_a.W));
}

static LARGE_INTEGER frequency;  
static LARGE_INTEGER lastTime;
static int initialized = 0;

extern float GetDeltaTime() {
    if (!initialized) {
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&lastTime);
        initialized = 1;
        return 0.0f;
    }

    LARGE_INTEGER currentTime;
    QueryPerformanceCounter(&currentTime);

    float deltaTime = (float)(currentTime.QuadPart - lastTime.QuadPart) / (float)frequency.QuadPart;
    lastTime = currentTime;

    return deltaTime;
}