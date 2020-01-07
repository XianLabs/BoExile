#include "AreaTransition.hpp"

UINT16 AreaTransition::GetAreaID(Entity* e)
{
	UINT16 AreaID;
	UINT64 AreaTComponentAddr = e->GetComponentAddress("AreaTransition");

	if (AreaTComponentAddr != 0)
	{
		AreaID = *(UINT16*)(AreaTComponentAddr + 0x28);
		return AreaID;
	}

	return -1;
}

byte AreaTransition::GetTransitionType(Entity* e)
{
	byte Type;
	UINT64 AreaTComponentAddr = e->GetComponentAddress("AreaTransition");

	if (AreaTComponentAddr != 0)
	{
		Type = *(byte*)(AreaTComponentAddr + 0x2A);
		return Type;
	}

	return -1;
}

