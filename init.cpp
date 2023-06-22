// Windows APP.cpp : Defines the entry point for the application.
//

#include "my.hpp"

//Global Variables:
extern HINSTANCE hInst;                                // current instance
extern WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
extern WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
extern HWND hWnd;                                      // the Window
HWND Download_Button;

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSAPP));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSAPP);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd) {
        return FALSE;
    }

    HWND Download_Button = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Download Folder",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON ,  // Styles 
        300,         // x position 
        300,         // y position 
        200,        // Button width
        40,        // Button height
        hWnd,     // Parent window
        (HMENU) 3,       // Function on click.
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        &download_buttonf );      // Pointer (not) needed.
    
    HWND Download_path = CreateWindow(
        L"EDIT",  // Predefined class; Unicode assumed 
        L"this is your download path",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        300,         // x position 
        340,         // y position 
        200,        // Button width
        40,        // Button height
        hWnd,     // Parent window
        NULL,       // No special interaction on click.
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    char buffer[999];
    GetWindowText(Download_path, (LPWSTR) buffer, 999);

    return TRUE;
}
