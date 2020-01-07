#pragma once
#include <Windows.h>
#include <fstream>
#include <string>

BOOL FileHasLineA(char* FilePath, char* Substring);
BOOL FileHasLineW(wchar_t* FilePath, wchar_t* Substring);