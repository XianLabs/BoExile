#include "Chest.hpp"

byte Chest::GetIsOpened(Entity* e)
{
	byte isOpened;
	UINT64 ChestComponentAddr = e->GetComponentAddress("Chest");

	if (ChestComponentAddr != 0)
	{
		isOpened = *(byte*)(ChestComponentAddr + 0x58);
		this->IsOpened = isOpened;
		return isOpened;
	}

	return 0;
}

byte Chest::GetIsLocked(Entity* e)
{
	byte isLocked;
	UINT64 ChestComponentAddr = e->GetComponentAddress("Chest");

	if (ChestComponentAddr != 0)
	{
		isLocked = *(byte*)(ChestComponentAddr + 0x59);
		this->IsLocked = isLocked;
		return isLocked;
	}

	return 0;
}

byte Chest::GetQuality(Entity* e)
{
	byte Quality;
	UINT64 ChestComponentAddr = e->GetComponentAddress("Chest");

	if (ChestComponentAddr != 0)
	{
		Quality = *(byte*)(ChestComponentAddr + 0x5C);
		return Quality;
	}

	return 0;
}

byte Chest::GetIsStrongbox(Entity* e)
{
	byte isStrongbox;
	UINT64 ChestComponentAddr = e->GetComponentAddress("Chest");

	if (ChestComponentAddr != 0)
	{
		isStrongbox = *(byte*)(ChestComponentAddr + 0x98);
		this->IsStrongbox = isStrongbox;
		return isStrongbox;
	}

	return 0;
}