#pragma once
#include "CComponent.hpp"
#include "Entity.hpp"

class Targetable : public CComponent
{
private:
	bool isTargetable; //0x30
	bool IsTargeted; //0x32
public:
	Targetable(); //Put memory reads inside constructor on component init.
	static bool GetIsTargeted(Entity* e);
	static bool GetIsTargetable(Entity* e);
};