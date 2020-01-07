#pragma once
#include "CComponent.hpp"
#include "Entity.hpp"

typedef enum Type
{
	Normal = 0,
	InArea,
	VaalSideArea,
	VaalSideAreaToNormal,
	Labyrinth
};

class AreaTransition : public CComponent
{

private:
	enum Type TransitionType; //0x2A
	UINT16 AreaID; //0x28
	BYTE Type;


public:
	
	static byte GetTransitionType(Entity* e);
	static UINT16 GetAreaID(Entity* e);
};