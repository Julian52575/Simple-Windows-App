
#include "my.hpp"
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

extern HWND hWnd;                                      // the Window
using namespace std;

void download_buttonf(void)
{
    wstring header = L"Everything is fine so far";
    LPWSTR convertedPath = NULL;

    LPCWSTR L_header; //define an array with size of my_str + 1
    LPCWSTR L_core;

    L_header = header.c_str();
    
    //Open the file explorer
    LPITEMIDLIST lol = open_folder(NULL);


    //Thank you ChatGPT for saving me from the Win32 api hell
    WCHAR selected_folder[MAX_PATH];
    if (SHGetPathFromIDListW(lol, selected_folder))
    {
        // Allocate memory for the converted path
        int pathLength = lstrlenW(selected_folder) + 1;
        convertedPath = new WCHAR[pathLength];

        // Copy the path to the convertedPath buffer
        lstrcpyW(convertedPath, selected_folder);

    }


    MessageBox(hWnd, convertedPath, L_header, NULL);
}
