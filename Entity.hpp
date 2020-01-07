#pragma once
#include <list>
#include "Structures.hpp"
#include "CComponent.hpp"
#include "MathHelper.hpp"
#include "Pointer.hpp"

class Entity
{
private:

protected:

	UINT64 MemoryAddress;
	UINT64 EntityListNodeAddress; //Addr + 0x08
	UINT64 PositionedComponentMemAddress; //Addr + 0x50
	std::wstring FilePath; //[Addr] + 0x18

	Vector2 v2;
	Vector3 RealLocation; //this is actually "Positioned" Component
	
	DWORD UUID; //0x40
	
	UINT64 ComponentListAddress;
	UINT64 ComponentLookupAddress;
	std::list<ComponentListNode> ComponentList;
	INT ComponentCount;

public:
	Entity();

	Vector2 GetVector2();
	VOID SetVector2(UINT32 x, UINT32 y, BOOL WritePtr); //World2Grid
	static Vector2* GetEntityGridPosition(Entity* e);

	std::list<ComponentListNode> GetComponentList() { return this->ComponentList; }

	VOID SetMemoryAddress(UINT64 Address) { this->MemoryAddress = Address; }
	UINT64 GetMemoryAddress() { return this->MemoryAddress; }

	UINT32 GetIDFromMemory(UINT64 EntityPtr);
	UINT32 GetEntityID() { return this->UUID; } //+0x40
	VOID SetEntityID(UINT32 ID) { this->UUID = ID; }

	std::wstring GetFilePathFromMemory(UINT64 EntityListNode);

	UINT64 SetComponentListAddress();
	CComponent* GetComponent(char* ComponentName);
	Entity* GetSubObjectEntity(UINT64 ComponentAddress, char* ComponentName);

	VOID FillComponentList();
	VOID ClearComponentList();
	UINT64 GetComponentAddress(char* ComponentName);
	VOID SetComponentLookupAddress();

	BOOL IsEntityClickable();
	BOOL SetInfo(UINT64 EntityWrapperAddress);
};