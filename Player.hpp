#pragma once
#include "CComponent.hpp"
#include "Entity.hpp"

class Player : public CComponent
{
private:

	std::string CharacterName; //0x58
	UINT32 Experience; //0x80
	INT Strength; //0x84
	INT Dex; //0x88
	INT Int; //0x8C
	byte Level; //0x90
	byte AllocatedLootId; // 0x7c?

	int HideoutLevel; //0x28E
	UINT64 HideoutAddress; //0x268

	byte ProphecyCount;  //0x112
	std::list<UINT16>* ProphecyList; //0x114

public:

	std::string GetCharacterName(Entity* e);
	UINT32 GetExperience(Entity* e);
	UINT32 GetStr(Entity* e);
	UINT32 GetDex(Entity* e);
	UINT32 GetInt(Entity* e);
	byte GetLevel(Entity* e);

	byte GetProphecyCount(Entity* e);

};