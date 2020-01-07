#pragma once
#include "Entity.hpp"
#include "ASMExterns.hpp"
#include "CComponent.hpp"

enum ActionIDs //powers of 2
{
	ACTION_NONE = 0,
	ACTION_ABILITY = 2,
	ACTION_COOLDOWN = 16,
	ACTION_DEAD = 64,
	ACTION_MOVING = 128,
	ACTION_SHOREBOUND = 256,
	ACTION_HAS_MINES = 2048,
	ACTION_UNKNOWN = 0xFFFF
};

class Actor : public CComponent
{
public:

	bool GetIsAttacking(Entity* e);
	bool GetIsMoving(Entity* e);
	float GetDestX(Entity* e);
	float GetDestY(Entity* e);
	std::list<UINT16>* GetActorSkillList();

	ActionIDs GetCurrentActionID(Entity* e);

	static BOOL IsLocalActor(Entity* e);

private:

	float DestinationX; //0x48
	float DestinationY; //0x4C
	int ActionID; //0xF0
	ActionIDs CurrentActionID;
	bool IsAttacking;
	bool IsMoving; //0x11C;
	std::list<UINT16>* Skills; //0x3B8 for start ptr, 0x3C0 for endPtr
	
};