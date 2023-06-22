#pragma once

#include "framework.h"
#include "Windows APP.h"
#include <shlobj_core.h>
#include <commdlg.h>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>
using namespace std;

constexpr auto MAX_LOADSTRING = 100;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//buttons
void download_buttonf(void);
OPENFILENAME open_file(char* path);
LPITEMIDLIST open_folder(char* path);


//cool C functions
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

unsigned int how_many_c_in_str(char* str, char c);
char** my_str_to_word_array(char* str, char delimiter);

bool read_folder(char* file);
bool read_in_individual_file(char name[256]);
