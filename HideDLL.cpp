#include "HideDLL.hpp"
#include <stdio.h>

std::wstring GetEXEDirectory() 
{
	wchar_t buffer[MAX_PATH];
	GetModuleFileNameW(NULL, buffer, MAX_PATH);
	std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
	return std::wstring(buffer).substr(0, pos);
}

void ChangeDLLNameRuntime(wchar_t* szModule, wchar_t* newName)
{
	PPEB PEB = (PPEB)__readgsqword(0x60);
	_LIST_ENTRY* f = PEB->Ldr->InMemoryOrderModuleList.Flink;
	UINT64 ProcessBase = (UINT64)GetModuleHandle(NULL);
	bool Found = FALSE;

	while (!Found)
	{
		PLDR_DATA_TABLE_ENTRY dataEntry = CONTAINING_RECORD(f, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);

		if (wcsstr(dataEntry->FullDllName.Buffer, szModule) != NULL)
		{
			std::wstring Path = GetEXEDirectory();
			Path += L"\\";
			Path += newName;
			dataEntry->CheckSum = 0xDEADBEEF; //seems to successfully cloak from non-admin mode protections, more methods to come soon
			dataEntry->DllBase = GetModuleHandle(NULL);
			wcscpy(dataEntry->FullDllName.Buffer, Path.c_str());
			wprintf(L"%s, %llX\n", dataEntry->FullDllName.Buffer, (UINT64)dataEntry->DllBase);		
			Found = TRUE;
			return;
		}

		f = dataEntry->InMemoryOrderLinks.Flink;
	}
}

void UnlinkModule(char *szModule)
{
	DWORD dwPEB = 0, dwOffset = 0;
	PLIST_ENTRY pUserModuleHead, pUserModule;
	PPEB_LDR_DATA1 pLdrData;
	PLDR_MODULE pLdrModule = NULL;
	PUNICODE_STRING lpModule = NULL;
	char szModuleName[512];
	int i = 0, n = 0;

	BYTE* _teb = (BYTE*)__readgsqword(0x30);
	pLdrData = (PPEB_LDR_DATA1)(PULONGLONG)(*(PULONGLONG)((*(PULONGLONG)(_teb + 0x60)) + 0x18));


	for (; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			pUserModuleHead = pUserModule = (PLIST_ENTRY)(&(pLdrData->InLoadOrderModuleList));
			dwOffset = 0;
			break;

		case 1:
			pUserModuleHead = pUserModule = (PLIST_ENTRY)(&(pLdrData->InMemoryOrderModuleList));
			dwOffset = sizeof(UINT64)*2;
			break;
		case 2:
			pUserModuleHead = pUserModule = (PLIST_ENTRY)(&(pLdrData->InInitializationOrderModuleList));
			dwOffset = sizeof(UINT64)*4;
			break;
		}

		while (pUserModule->Flink != pUserModuleHead)
		{
			pUserModule = pUserModule->Flink;
			lpModule = (PUNICODE_STRING)(((LONGLONG)(pUserModule)) + (72 - dwOffset));
        
			for (n = 0; n <(lpModule->Length) / 2 && n < 512; n++)
				szModuleName[n] = (CHAR)(*((lpModule->Buffer) + (n)));

			szModuleName[n] = '\0';
			if (strstr(szModuleName, szModule))
			{
				if (!pLdrModule)
					pLdrModule = (PLDR_MODULE)(((LONGLONG)(pUserModule)) - dwOffset);
             
				pUserModule->Blink->Flink = pUserModule->Flink;
				pUserModule->Flink->Blink = pUserModule->Blink;
				printf("Found...\n");
			}
		}
	}

	// Unlink from LdrpHashTable
	if (pLdrModule)
	{
		pLdrModule->HashTableEntry.Blink->Flink = pLdrModule->HashTableEntry.Flink;
		pLdrModule->HashTableEntry.Flink->Blink = pLdrModule->HashTableEntry.Blink;
	}
}

void RemovePeHeader(HANDLE GetModuleBase)
{
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)GetModuleBase;
	PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)((PBYTE)pDosHeader + (DWORD)pDosHeader->e_lfanew);

	if (pNTHeader->Signature != IMAGE_NT_SIGNATURE)
		return;

	if (pNTHeader->FileHeader.SizeOfOptionalHeader)
	{
		DWORD Protect;
		WORD Size = pNTHeader->FileHeader.SizeOfOptionalHeader;
		VirtualProtect((void*)GetModuleBase, Size, PAGE_EXECUTE_READWRITE, &Protect);
		RtlZeroMemory((void*)GetModuleBase, Size);
		VirtualProtect((void*)GetModuleBase, Size, Protect, &Protect);
	}
}