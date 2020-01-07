#include "Entity.hpp"

Entity::Entity()
{
	this->ComponentList = std::list<ComponentListNode>();
}

Vector2 Entity::GetVector2()
{
	return this->v2;
}

VOID Entity::SetVector2(UINT32 x, UINT32 y, BOOL WritePtr)
{
	this->v2.X = x;
	this->v2.Y = y;

	if (WritePtr) //needs changing.
	{
		WritePointer<UINT32>(this->GetMemoryAddress(), 0xE8, x);
		WritePointer<UINT32>(this->GetMemoryAddress(), 0xEC, y);
	}
}

//Wrapper to fill entity with requires memory stuff
BOOL Entity::SetInfo(UINT64 EntityWrapperAddress) //todo: check for failures
{
	this->SetMemoryAddress(EntityWrapperAddress);
	UINT32 ID = this->GetIDFromMemory(EntityWrapperAddress);
	this->SetEntityID(ID);
	this->GetFilePathFromMemory(EntityWrapperAddress);
	this->SetComponentListAddress();
	this->SetComponentLookupAddress();
	this->FillComponentList();

	Vector2* v = Entity::GetEntityGridPosition(this);
	delete v; v = nullptr;
	
	return TRUE;
}

UINT32 Entity::GetIDFromMemory(UINT64 EntityWrapperPtr)
{
	UINT64 IDAddress = EntityWrapperPtr + 0x40;

	if (IDAddress != 0)
	{
		UINT32 ID = DereferenceSafe<UINT32>(IDAddress);
		if (ID != 0xDEADBEEF)
			return ID;
	}
	
	return 0;
}

std::wstring Entity::GetFilePathFromMemory(UINT64 EntityListNode)
{
	wchar_t arrPath[256];

	UINT64 PathPtr = ReadPointer<UINT64>(EntityListNode, 0x18);

	if (PathPtr == -1)
		return NULL;

	wcscpy(arrPath, (const wchar_t*)PathPtr);
	this->FilePath = std::wstring(arrPath);

	return this->FilePath;
}

VOID Entity::FillComponentList()
{
	UINT64 CurrentAddress = this->ComponentLookupAddress;

	for (int i = 0; i < this->ComponentCount; i++)
	{
		char ComponentName[256] = { 0 };

		ComponentListNode CLN = ComponentListNode();

		CLN.NextPtr = CurrentAddress;
		CLN.PrevPtr = CurrentAddress + 8;
		CLN.NamePtr = CurrentAddress + 16;
		CLN.IndexPtr = CurrentAddress + 24;

		CLN.NextPtr = DereferenceSafe<UINT64>(CLN.NextPtr);
		CLN.PrevPtr = DereferenceSafe<UINT64>(CLN.PrevPtr);
		CLN.NamePtr = DereferenceSafe<UINT64>(CLN.NamePtr);
		CLN.Index = DereferenceSafe<UINT>(CLN.IndexPtr);

		//printf("Current: %llX, NamePtr: %llX, Index: %d\n", CurrentAddress, CLN.NamePtr, CLN.Index);

		if (CLN.Index >= 0 && CLN.Index < 128)
			this->ComponentList.push_back(CLN);

		CurrentAddress = CLN.NextPtr;
	}
}

VOID Entity::ClearComponentList()
{
	//no mem leaks to worry about iirc. need double check on CLN's
	this->ComponentList.clear();
}

UINT64 Entity::GetComponentAddress(char* ComponentName)
{
	//traverse list, scan for name, return actual address
	std::list<ComponentListNode>::const_iterator iterator;

	for (iterator = this->ComponentList.begin(); iterator != ComponentList.end(); ++iterator)
	{
		if (iterator._Ptr != NULL)
		{
			if (strcmp((const char*)iterator._Ptr->_Myval.NamePtr, ComponentName) == 0)
			{
				UINT64 Index = iterator._Ptr->_Myval.Index;
				//printf("Node Index: %d\n", Index);
				UINT64 ComponentAddress = (UINT64)(this->ComponentListAddress + (8 * Index));
				ComponentAddress = *(UINT64*)ComponentAddress;
				//printf("GetComponentAddress result: %llX\n", ComponentAddress);
				return ComponentAddress;
			}
		}
	}

	return 0; //unfound case
}

VOID Entity::SetComponentLookupAddress()
{
	UINT64 MemAddr = this->GetMemoryAddress(); //crash issue, fix this
	this->ComponentLookupAddress = *(UINT64*)MemAddr;
	this->ComponentLookupAddress = *(UINT64*)(this->ComponentLookupAddress + 0x40);
	this->ComponentCount = *(UINT*)(this->ComponentLookupAddress + 0x38);
	this->ComponentLookupAddress = *(UINT64*)(this->ComponentLookupAddress + 0x30);
	this->ComponentLookupAddress = *(UINT64*)(this->ComponentLookupAddress);
}

UINT64 Entity::SetComponentListAddress()
{
	UINT64 MemAddr = this->GetMemoryAddress();
	if (MemAddr != 0)
	{
		this->ComponentListAddress = *(UINT64*)(MemAddr + 8);
		return this->ComponentListAddress;
	}

	return 0;
}

BOOL Entity::IsEntityClickable()
{
	UINT64 TargetableAddr = this->GetComponentAddress("Targetable");

	if (TargetableAddr == 0)
		return FALSE;

	BYTE Clickable = DereferenceSafe<BYTE>(TargetableAddr + 0x30);
	return Clickable;
}

Vector2* Entity::GetEntityGridPosition(Entity* e)
{
	Vector2* v = new Vector2 { 0, 0 };
	//from memory
	UINT64 PositionedComponentPtr = e->GetComponentAddress("Positioned");

	if (PositionedComponentPtr == 0)
		return NULL;

	INT32 X = DereferenceSafe<INT32>(PositionedComponentPtr + 0xE8);
	INT32 Y = DereferenceSafe<INT32>(PositionedComponentPtr + 0xEC);
	
	if (X == 0xDEADBEEF || Y == 0xDEADBEEF)
	{
		delete v;
		return NULL;
	}

	v->X = X;
	v->Y = Y;

	e->SetVector2(X, Y, FALSE);

	return v;
}

Entity* Entity::GetSubObjectEntity(UINT64 ComponentAddress, char* ComponentName)
{
	Entity* e = new Entity();

	if (strcmp(ComponentName, "WorldItem") == 0) //create item subentity
	{
		UINT64 SubEntityItemAddress = ComponentAddress + 0x28;
		SubEntityItemAddress = DereferenceSafe<UINT64>(SubEntityItemAddress);
		if (SubEntityItemAddress != 0xDEADBEEF)
			e->SetInfo(SubEntityItemAddress);
	}

	return e;
}