#pragma once

#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <windowsx.h>
#include <gdiplus.h> 
#include "../../Math/MathUtils.h"
#include "GameData.h"
#include "../../Lua_Vers/Draw.h"

//FOR FUCKS SAKE DONT TOUCH THIS

int WINDOWDATA_WindowHeight;
int WINDOWDATA_WindowWidth;
char WINDOWDATA_Title[256];
HWND WINDOWDATA_handle;

ULONG_PTR gdiplusToken;

HBRUSH BackgroundColor = NULL;
HBRUSH BrushColor = NULL;

double Framebuffer = 0;

bool keyStates[256] = { false };

extern bool iskeydown(int keycode) {
    if (keyStates[keycode] == true) {
        return true;
    }else {
        return false;
    }
}

HBITMAP hBitmap = NULL;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static POINT ptOld;

    // Initialize the background and brush colors
    if (BackgroundColor == NULL) {
        BackgroundColor = CreateSolidBrush(RGB(255, 255, 255));  
    }
    if (BrushColor == NULL) {
        BrushColor = CreateSolidBrush(RGB(0, 0, 0));  
    }

    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            GAME_ISRUNNING = false;
            return 0;

        case WM_LBUTTONDOWN:
            ptOld.x = GET_X_LPARAM(lParam);
            ptOld.y = GET_Y_LPARAM(lParam);
            SetCapture(hwnd);
            return 0;
        
        case WM_KEYDOWN: {
            printf("%i",wParam);
            keyStates[wParam] = true;
            return 0;
        }
        case WM_KEYUP: {
            printf("%i",wParam);
            keyStates[wParam] = false;
            return 0;
        }

        case WM_MOUSEMOVE:
            if (wParam & MK_LBUTTON) {
                POINT ptNew;
                ptNew.x = GET_X_LPARAM(lParam);
                ptNew.y = GET_Y_LPARAM(lParam);

                int dx = ptNew.x - ptOld.x;
                int dy = ptNew.y - ptOld.y;
                RECT rect;
                GetWindowRect(hwnd, &rect);
                SetWindowPos(hwnd, NULL, rect.left + dx, rect.top + dy, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

                ptOld = ptNew;
            }
            return 0;

        case WM_LBUTTONUP:
            ReleaseCapture();
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            HDC hdcMem = CreateCompatibleDC(hdc);
            HBITMAP hbmMem = CreateCompatibleBitmap(hdc, WINDOWDATA_WindowWidth, WINDOWDATA_WindowHeight);
            HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, hbmMem);

            RECT bgrect = {0, 0, WINDOWDATA_WindowWidth, WINDOWDATA_WindowHeight};
            FillRect(hdcMem, &bgrect, BackgroundColor);

            for (size_t i = 0; i < Pixel_Array_Lenght; i++) {
                RECT rect = {
                    Pixel_Array[i][0],                   
                    Pixel_Array[i][1],                    
                    Pixel_Array[i][0] + Pixel_Array[i][2],
                    Pixel_Array[i][1] + Pixel_Array[i][3]
                };
                FillRect(hdcMem, &rect, BrushColor);
            }
            for (size_t i = 0; i < Bmp_Array_Length; i++)
            {
                GetObject(hBitmap, sizeof(BITMAP), &Bmp_Array[i]);

                BitBlt(hdc, Bmp_Pos_Array[i][0], Bmp_Pos_Array[i][1], Bmp_Pos_Array[i][2], Bmp_Pos_Array[i][3], hdcMem, 0, 0, SRCCOPY);
            }
            
        
            BitBlt(hdc, 0, 0, WINDOWDATA_WindowWidth, WINDOWDATA_WindowHeight, hdcMem, 0, 0, SRCCOPY);

            SelectObject(hdcMem, hbmOld);
            DeleteObject(hbmMem);
            DeleteDC(hdcMem);
        
            EndPaint(hwnd, &ps);
            Pixel_Array_Lenght = 0;
            Bmp_Array_Length = 0;
        
            return 0;
        }

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

HWND DefineWindow(int WindowWidth, int WindowHeight, char *WINDOWDATA_Title) 
{
    if (WINDOWDATA_handle != NULL) 
    {
        return NULL;
    }

    WINDOWDATA_WindowHeight = WindowHeight;
    WINDOWDATA_WindowWidth = WindowWidth;
    WINDOWDATA_Title = WINDOWDATA_Title;

    HINSTANCE hInstance = GetModuleHandle(NULL);

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "RENENGINECLASS";

    if (!RegisterClass(&wc)) {
        return NULL;
    }

    HWND hwnd = CreateWindowEx(
        0x00040000L,
        wc.lpszClassName,           
        WINDOWDATA_Title,           
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WindowWidth,
        WindowHeight,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return NULL;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    return hwnd;
}

bool UndefineWindow() 
{
    if (WINDOWDATA_handle != NULL) {
        PostMessage(WINDOWDATA_handle, WM_DESTROY, 0, 0);
        WINDOWDATA_WindowHeight = 0;
        WINDOWDATA_WindowWidth = 0;
        strncpy(WINDOWDATA_Title, "", sizeof(WINDOWDATA_Title) - 1);
        WINDOWDATA_handle = NULL;
        return true;
    }
    return false;
}