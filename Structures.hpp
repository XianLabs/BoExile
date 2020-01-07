#pragma once
#include <Windows.h>

#define POE_BASE (UINT64)GetModuleHandle(NULL); //get base address of .exe for ASLR

struct Vector2
{
	INT32 X;
	INT32 Y;
};

struct Vector3
{
	FLOAT X;
	FLOAT Y;
	FLOAT Z;
};

struct ComponentListNode //doubly link list
{
	UINT64 NextPtr;
	UINT64 PrevPtr;
	UINT64 NamePtr;
	UINT64 IndexPtr;

	char Name[255];
	UINT Index;
};

