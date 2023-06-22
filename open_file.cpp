
#include "my.hpp"
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

extern HWND hWnd;                                      // the Window
using namespace std;

OPENFILENAME open_file(char *path)
{
    if (path == NULL)
        path = (char *) "C:\\";

    OPENFILENAME ofn;

    wstring file_type_msg = L"Any folder";
    LPWSTR file_extension = (LPWSTR)malloc(sizeof(LPWSTR) * 100);
    LPWSTR file_name = (LPWSTR)malloc(sizeof(LPWSTR) * 100);
    ZeroMemory(file_name, 100);
    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd; //Parent Window
    ofn.lpstrFile = file_name; //The file selected
    ofn.nMaxFile = 100; //Taille maximale du path
    ofn.lpstrFilter = file_type_msg.c_str(); //The file type you want to open
    ofn.nFilterIndex = 1; //???
    ofn.lpstrInitialDir = (LPCWSTR) path; //The starting folder
    ofn.lpstrTitle = L"Select your folder"; //Explorer title
    ofn.lpstrFileTitle = file_extension; //File name and extension

    GetOpenFileName(&ofn);
    //name is stocked in lpstrFilter*
    MessageBox(hWnd, ofn.lpstrFile, ofn.lpstrFile, NULL);
    free(file_extension);
    free(file_name);
    return ofn;
}