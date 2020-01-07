#include "Targetable.hpp"

bool Targetable::GetIsTargetable(Entity* e)
{
	byte IsTargetable;
	UINT64 TargetableComponentAddr = e->GetComponentAddress("Targetable");

	if (TargetableComponentAddr != 0 && TargetableComponentAddr != 0xDEADBEEF)
	{
		IsTargetable = DereferenceSafe<byte>(TargetableComponentAddr + 0x30);
		return IsTargetable;
	}
	return false;
}

bool Targetable::GetIsTargeted(Entity* e)
{
	byte IsTargeted;
	UINT64 TargetableComponentAddr = e->GetComponentAddress("Targetable");

	if (TargetableComponentAddr != 0 && TargetableComponentAddr != 0xDEADBEEF)
	{
		IsTargeted = DereferenceSafe<byte>(TargetableComponentAddr + 0x32);
		return IsTargeted;
	}
	return false;
}