#pragma once
#include "Actor.hpp"

class LocalActor : public Actor
{
private:
	Entity* LocalPlayer;

	std::list<Entity*>* MinionList;
	std::list<Entity*>* AuraList; //change this and below to list of skill components
	std::list<Entity*>* BuffList;

public:
	LocalActor();
	static Entity* GetEntityFromCharacterBasePtr();

	static VOID SendPlayerAction(SHORT SkillID, UINT64 optional_entity, Vector2* v2);
	static VOID EndAction();
	static VOID UseFlare(Vector2* ThrowPosition);
	static VOID UseDynamite(Vector2* ThrowPosition);
	static VOID UseFlask(BYTE Slot);

	VOID SendActionAndWaitForCooldown(SHORT SkillID, UINT64 optional_entity, Vector2* v2);
	VOID SendContinuousActionAndWaitForCooldown(SHORT SkillID, UINT64 optional_entity, Vector2* v2);
	
	VOID CreateNewInstance(UINT32 MapHash, UINT32 WaypointEntityID);

	static VOID ReviveCharacterOnDeath(bool SpawningInTown);
	static VOID ChangeHideout(byte HideoutIndex);
};
