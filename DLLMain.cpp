#include "Hacks.hpp"
#include "Hook.hpp"
#include "ASMExterns.hpp"
#include "MemoryOffsets.hpp"
#include "Packets.hpp"
#include <fstream>
#include "HideDLL.hpp"

extern int Main();
HMODULE hDLLModule = 0;

//tls callback is called each time a new thread is created
//There may be actually 2+ callbacks (we will actually use only one) and we may want to call them in order, now we know how. Just place these callbacks in sections named in alphabetical order.
void NTAPI tls_callback(PVOID DllHandle, DWORD dwReason, PVOID Reserved)
{
	if (dwReason == DLL_THREAD_ATTACH)
	{

	}
	else if (dwReason == DLL_PROCESS_ATTACH)
	{

	}
}

#pragma comment (linker, "/INCLUDE:_tls_used") 
#pragma comment (linker, "/INCLUDE:tls_callback_func")
#pragma const_seg(".CRT$XLF") //set segment
EXTERN_C const PIMAGE_TLS_CALLBACK tls_callback_func = tls_callback;
#pragma const_seg() //set segment back to .rdata

VOID InitializeGUI()
{  
	UINT64 PoEBase = (UINT64)GetModuleHandle(NULL); //get base address of .exe for ASLR

	//HACK hkAntiDumpUpload = { PoEBase + MinidumpUploadOffset, "\x40", "\xC3", 1 };
	//WriteHackBytes(hkAntiDumpUpload, TRUE);

	HACK hkAntiMigrate = { PoEBase + AntiMigrateFunction, "\x40", "\xC3", 1 };
	WriteHackBytes(hkAntiMigrate, TRUE);

	HACK hkAntiMinimapUpload = { PoEBase + MinimapLogOffset, "\x48", "\xC3", 1 };
	//WriteHackBytes(hkAntiMinimapUpload, TRUE);

	Main();	
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		AllocConsole();
		freopen("CON", "w", stdout);
		freopen("CON", "r", stdin);

		hDLLModule = hModule;

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&InitializeGUI, 0, 0, 0);

	}break;

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}