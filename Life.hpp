#pragma once
#include "CComponent.hpp"
#include "Entity.hpp"

class Life : public CComponent
{
private:
		
	INT32 MaxHP; //0xEC
	INT32 CurrentHP; //0xE8

	INT32 MaxMP; //0xF0
	INT32 CurrentMP; //0xF4

public:

	static INT32 GetCurrentHP(Entity* e);
	static INT32 GetMaxHP(Entity* e);

	static INT32 GetCurrentMP(Entity* e);
	static INT32 GetMaxMP(Entity* e);
};