#pragma once
#include <Windows.h>
#include "mhook.h"

typedef void(__fastcall* _Hook)();

BOOL WINAPI SetHook(UINT64 HookAddress, PVOID HookFunc, CHAR* HookNameOpt);
VOID RemoveHook(UINT64 HookAddress, INT ByteLength, BYTE* OriginalBytes);

