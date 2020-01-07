#include "Actor.hpp"

ActionIDs Actor::GetCurrentActionID(Entity* e)
{
	UINT32 Action;
	UINT64 ActorCompAddr = e->GetComponentAddress("Actor");

	if (ActorCompAddr != 0)
	{
		Action = DereferenceSafe<UINT32>(ActorCompAddr + 0xF8);
		if (Action != 0xDEADBEEF)
		{
			this->CurrentActionID = (ActionIDs)Action;
			this->ActionID = (ActionIDs)Action;
			return this->CurrentActionID;
		}
	}

	
	return (ActionIDs)0xDEADBEEF;
}
