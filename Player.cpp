#include "Player.hpp"

std::string Player::GetCharacterName(Entity* e)
{
	return std::string("test");
}

UINT32 Player::GetExperience(Entity* e)
{
	UINT64 PlayerComponentAddr = e->GetComponentAddress("Player");

	if (PlayerComponentAddr != 0)
	{
		UINT32 Exp = *(UINT32*)(PlayerComponentAddr + 0x80);
		this->Experience = Exp;
		return Exp;
	}

	return 0;
}

UINT32 Player::GetStr(Entity* e)
{
	UINT32 Str;
	UINT64 PlayerComponentAddr = e->GetComponentAddress("Player");

	if (PlayerComponentAddr != 0)
	{
		Str = *(UINT32*)(PlayerComponentAddr + 0x84);
		this->Strength = Str;
		return Str;
	};

	return 0;
}

UINT32 Player::GetDex(Entity* e)
{
	UINT64 PlayerComponentAddr = e->GetComponentAddress("Player");
	UINT32 Dex = 0;
	
	if (PlayerComponentAddr != 0)
	{
		Dex = *(UINT32*)(PlayerComponentAddr + 0x88);
		this->Dex = Dex;
		return Dex;
	}

	return 0;
}

UINT32 Player::GetInt(Entity* e)
{
	UINT64 PlayerComponentAddr = e->GetComponentAddress("Player");
	UINT32 Int;

	if (PlayerComponentAddr != 0)
	{
		Int = *(UINT32*)(PlayerComponentAddr + 0x8C);
		this->Int = Int;
		return Int;
	}

	return 0;
}

byte Player::GetLevel(Entity* e)
{
	UINT64 PlayerComponentAddr = e->GetComponentAddress("Player");
	byte Lvl;

	if (PlayerComponentAddr != 0)
	{
		Lvl = *(byte*)(PlayerComponentAddr + 0x90);
		this->Level = Lvl;
		return Lvl;
	}

	return 0;
}

byte Player::GetProphecyCount(Entity* e)
{
	UINT64 PlayerComponentAddr = e->GetComponentAddress("Player");
	byte ProphecyCount = 0;

	if (PlayerComponentAddr != 0)
	{
		ProphecyCount = *(byte*)(PlayerComponentAddr + 0x112);
		this->ProphecyCount = ProphecyCount;
		return ProphecyCount;
	}

	return -1;
}