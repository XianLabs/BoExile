#include "Life.hpp"

INT32 Life::GetMaxHP(Entity* e)
{
	INT32 MaxHP;
	UINT64 LifeComponentAddr = e->GetComponentAddress("Life");

	if (LifeComponentAddr != 0)
	{
		MaxHP = *(INT32*)(LifeComponentAddr + 0x154);
		return MaxHP;
	}

	return -1;
}

INT32 Life::GetCurrentHP(Entity* e) //should be INT32
{
	INT32 HP;
	UINT64 LifeComponentAddr = e->GetComponentAddress("Life");
	
	if (LifeComponentAddr != 0)
	{
		HP = DereferenceSafe<INT32>(LifeComponentAddr + 0x15C);
		if (HP != 0xDEADBEEF)
		{
			return HP;
		}
	}

	return -1;
}

INT32 Life::GetCurrentMP(Entity* e)
{
	INT32 MP;
	UINT64 LifeComponentAddr = e->GetComponentAddress("Life");

	if (LifeComponentAddr != 0)
	{
		MP = *(INT32*)(LifeComponentAddr + 0xC4);
		return MP;
	}

	return -1;
}

INT32 Life::GetMaxMP(Entity* e)
{
	INT32 MaxMP;
	UINT64 LifeComponentAddr = e->GetComponentAddress("Life");

	if (LifeComponentAddr != 0)
	{
		MaxMP = *(INT32*)(LifeComponentAddr + 0xBC);
		return MaxMP;
	}
	return -1;
}