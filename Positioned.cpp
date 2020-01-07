#include "Positioned.hpp"

VOID Positioned::SetEntitySize(Entity* e, FLOAT size)
{
	UINT64 PositionedCompAddr = e->GetComponentAddress("Positioned");

	if (PositionedCompAddr != 0)
	{
		UINT64 EntitySizeAddr = PositionedCompAddr + 0x100;
		memcpy((void*)EntitySizeAddr, (void*)&size, sizeof(FLOAT));
	}
}

VOID Positioned::SetEntityPosition(Entity* e, Vector2 v2)
{


}