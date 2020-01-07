#pragma once
#include "Hacks.hpp"
#include <Psapi.h>
#include <TlHelp32.h>

VOID WriteHackBytes(HACK hHack, BOOL bEnable) {
	if (bEnable) {
		DWORD dwOldProt;
		VirtualProtect((void*)hHack.dwAddress, hHack.nSize, PAGE_EXECUTE_READWRITE, &dwOldProt);
		memcpy((void*)hHack.dwAddress, (void*)hHack.szNewBytes, hHack.nSize);
	}
	else {
		memcpy((void*)hHack.dwAddress, (void*)hHack.szOriginalBytes, hHack.nSize);
	}
}

VOID ReduceRAM()
{
	while (1)
	{
		EmptyWorkingSet(GetCurrentProcess());
		Sleep(10000);
	}
}