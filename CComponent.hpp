#pragma once
#include "MemoryOffsets.hpp"
#include <string>

typedef enum ComponentType
{
	COMPONENT_WORLDITEM,
	COMPONENT_POSITIONED,
	COMPONENT_RENDER,
	COMPONENT_ANIMATED,
	COMPONENT_TARGETABLE,
	COMPONENT_ITEMMODS,
	COMPONENT_STAT
};

class CComponent
{

private:

	std::string Name;
	ComponentType Type;
	UINT64 OwnerEntityAddr;
	UINT64 SubEntityAddr; //<WorldItem> component
	UINT64 ComponentListNodeAddress;
	UINT64 ComponentLookupAddress;

	UINT64 ComponentMemoryAddress;

public:
	CComponent() { };
	CComponent(UINT64 Address, UINT64 ListNodeAddress);

	std::string GetComponentName();
	UINT64 GetOwnerEntity() { return this->OwnerEntityAddr; }
	ComponentType GetComponentType() { return this->Type; }
	UINT64 GetComponentMemoryAddress() { return this->ComponentMemoryAddress; }

	VOID SetComponentName(char* Name) { this->Name = std::string(Name); }
	VOID SetOwnerEntity(UINT64 Addr) { this->OwnerEntityAddr = Addr; }
	VOID SetComponentListAddress(UINT64 Addr) { this->ComponentListNodeAddress = Addr; }
	VOID SetComponentLookupAddress(UINT64 Addr) { this->ComponentLookupAddress = Addr; }
	VOID SetComponentName(UINT64 NamePtr);
	VOID SetComponentListNodePtr(UINT64 Addr, UINT64 Next, UINT64 Prev, UINT64 NamePtr, INT Index);
	VOID SetComponentType(ComponentType T) { this->Type = T; }
	VOID SetComponentMemoryAddress(UINT64 Addr) { this->ComponentMemoryAddress = Addr; }
};