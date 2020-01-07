#include "Hook.hpp"

BOOL WINAPI SetHook(UINT64 HookAddress, PVOID HookFunc, CHAR* HookNameOpt) {

	_Hook hook = (_Hook)HookAddress;

	BOOL bHook = Mhook_SetHook((PVOID*)&hook,
		HookFunc);

	if (!bHook)
	{
		if (HookNameOpt != NULL)
		{
			MessageBoxA(0, "Couldn't hook!", HookNameOpt, 0);
			return FALSE;
		}
		else
		{
			MessageBoxA(0, "Couldn't hook!", 0, 0);
			return FALSE;
		}
	}


	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
	return Mhook_Unhook((PVOID*)&hook);
}

VOID RemoveHook(UINT64 HookAddress, INT ByteLength, BYTE* OriginalBytes)
{
	DWORD dwOldProt;
	VirtualProtect((LPVOID)HookAddress, ByteLength, PAGE_EXECUTE_READWRITE, &dwOldProt);
	memcpy((void*)HookAddress, (void*)OriginalBytes, ByteLength);
	VirtualProtect((LPVOID)HookAddress, ByteLength, dwOldProt, &dwOldProt);
}