// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <windowsx.h>

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // sort through and find what code to run for the message given
    switch (message) {
    case WM_PAINT:
        // we will replace this part with Rendering Module
    {
        printf("paint!\n");
    }
    break;

    // this message is read when the window is closed
    case WM_DESTROY: {
        // close the application entirely
        PostQuitMessage(0);
        return 0;
    }
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc(hWnd, message, wParam, lParam);
}

int Initialize()
{
    int result = 0;



    WCHAR appName[10] = { '\0' };
    wcscpy_s(appName, L"GameEngine");

    // get the HINSTANCE of the Console Program
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // the handle for the window, filled by a function
    HWND hWnd;
    // this struct holds information for the window class
    WNDCLASSEX wc;

    // clear out the window class for use
    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    // fill in the struct with the needed information
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = _T("GameEngineFromScratch");
    printf("startup from winMain\n");
    // register the window class
    RegisterClassEx(&wc);

    // create the window and use the result as the handle
    hWnd = CreateWindowExW(0,
                           L"GameEngineFromScratch",      // name of the window class
                           appName,             // title of the window
                           WS_OVERLAPPEDWINDOW,              // window style
                           CW_USEDEFAULT,                    // x-position of the window
                           CW_USEDEFAULT,                    // y-position of the window
                           800,             // width of the window
                           600,            // height of the window
                           NULL,                             // we have no parent window, NULL
                           NULL,                             // we aren't using menus, NULL
                           hInstance,                        // application handle
                           NULL);                            // used with multiple windows, NULL

// display the window on the screen
    ShowWindow(hWnd, SW_SHOW);

    return result;
}

void Tick()
{
    // this struct holds Windows event messages
    MSG msg;

    // we use PeekMessage instead of GetMessage here
    // because we should not block the thread at anywhere
    // except the engine execution driver module
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        // translate keystroke messages into the right format
        TranslateMessage(&msg);

        // send the message to the WindowProc function
        DispatchMessage(&msg);
    }
}

int main(int argc, char** argv)
{
    int ret;

    if ((ret = Initialize()) != 0) {
        printf("App Initialize failed, will exit now.");
        return ret;
    }

    while (true) {
        Tick();
    }

    return 0;
}

