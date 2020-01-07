#pragma once
#include "CComponent.hpp"
#include "Entity.hpp"

enum MonsterQuality
{
	Normal,
	Magic,
	Rare,
	Unique
};


class ObjectMagicProperties : public CComponent
{
private:
	MonsterQuality MobQuality; //0x7C
	std::list<std::wstring>* Properties; //Start: 0x98, End: 0xA0

public:
	ObjectMagicProperties() { this->Properties = new std::list<std::wstring>; }

	MonsterQuality GetQuality(Entity* e);
	VOID FillPropertiesList(Entity* e);



};