#include "LocalActor.hpp"
#include "PacketBuilder.hpp"


LocalActor::LocalActor()
{
	this->LocalPlayer = GetEntityFromCharacterBasePtr();
}

Entity* LocalActor::GetEntityFromCharacterBasePtr() 
{

	UINT64 PoEBase = (UINT64)GetModuleHandle(NULL);
	UINT64 ptrCharBase = PoEBase + CharacterPointerBaseOffset;
	UINT64 Ptr = ReadPointer<UINT64>(ptrCharBase, 0x378);
	
	if (Ptr == 0)
		return NULL;

	Ptr += 0x6658; //we get this from mov rcx,[rcx+X] inside char action func
	Ptr = *(UINT64*)Ptr;
	Ptr += 0x8;
	Ptr = *(UINT64*)Ptr;
	Entity* LocalActor = new Entity();
	LocalActor->SetInfo(Ptr);
	return LocalActor;
}

VOID LocalActor::SendPlayerAction(SHORT SkillID, UINT64 optional_entityID, Vector2* v2)
{
	UINT64 PoEBase = (UINT64)GetModuleHandle(NULL);
	UINT64 ptrCharBase = PoEBase + CharacterPointerBaseOffset;
	UINT64 Ptr = ReadPointer<UINT64>(ptrCharBase, 0x378);
	
	if (Ptr != -1)
		SendAction(Ptr, SkillID, optional_entityID, v2);
}

VOID LocalActor::EndAction()
{
	UINT64 SendClass = GetSendClass();
	PacketWriter* p = StopAction();
	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
}

VOID LocalActor::SendContinuousActionAndWaitForCooldown(SHORT SkillID, UINT64 optional_entity, Vector2* v2)
{
	Entity* e = GetEntityFromCharacterBasePtr();
	this->SetOwnerEntity(e->GetMemoryAddress());//probably unneeded

	ActionIDs aID = ACTION_UNKNOWN;

	while (aID != ActionIDs::ACTION_NONE)
	{
		aID = Actor::GetCurrentActionID(e);
		Sleep(75);
	}

	SendPlayerAction(SkillID, optional_entity, v2);
	Sleep(100);
	//send continuous action packets here


	delete e; e = nullptr;
}

VOID LocalActor::SendActionAndWaitForCooldown(SHORT SkillID, UINT64 optional_entity, Vector2* v2) //attack/interaction full wrapper
{
	static bool InUse;

	if (!InUse)
	{
		InUse = TRUE;

		Entity e = *GetEntityFromCharacterBasePtr();

		//this->SetOwnerEntity(e->GetMemoryAddress());//probably unneeded

		ActionIDs aID = ACTION_UNKNOWN;

		while (aID != ActionIDs::ACTION_NONE)
		{
			aID = Actor::GetCurrentActionID(&e);
			Sleep(75);
		}

		SendPlayerAction(SkillID, optional_entity, v2);
		Sleep(100);
		EndAction();

		int before = GetTickCount();

		aID = ACTION_UNKNOWN;

		while (aID != ActionIDs::ACTION_NONE)
		{
		
			aID = Actor::GetCurrentActionID(&e);
			Sleep(100);
			if (aID != ActionIDs::ACTION_NONE)
			{
				int after = GetTickCount();
				if ((after - before) / 1000 >= 6)
				{
					EndAction();
				}
			}
		}

		InUse = FALSE;
	}	

	
}

VOID LocalActor::UseFlare(Vector2* ThrowPosition)
{
	SendPlayerAction(34560, 0, ThrowPosition);
	Sleep(150);
	EndAction();
}

VOID LocalActor::UseDynamite(Vector2* ThrowPosition)
{
	SendPlayerAction(36608, 0, ThrowPosition);
	Sleep(150);
	EndAction();
}

VOID LocalActor::UseFlask(BYTE Slot)
{
	UINT64 SendClass = GetSendClass();
	if (SendClass != 0)
	{
		PacketWriter* p = ConsumeFlask(Slot); //todo: add a damn namespace
		SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
		delete p;
	}

}

VOID LocalActor::ReviveCharacterOnDeath(bool SpawningInTown)
{
	UINT64 SendClass = GetSendClass();
	if (SendClass != 0)
	{
		PacketWriter* p = ReviveCharacter(SpawningInTown); //todo: add a damn namespace
		SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
		delete p;
	}
}

VOID LocalActor::ChangeHideout(byte HideoutIndex)
{
	UINT64 SendClass = GetSendClass();
	if (SendClass != 0)
	{
		PacketWriter* p = SwapHideout(HideoutIndex); //todo: add a damn namespace
		SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
		delete p;
	}

}

VOID LocalActor::CreateNewInstance(UINT32 MapHash, UINT32 WaypointEntityID)
{
	SendActionAndWaitForCooldown(0x0266, WaypointEntityID, 0);
	Sleep(3000);

	PacketWriter* p = InstanceList(htonl(MapHash), htonl(WaypointEntityID), 1);
	SendPacket(GetSendClass(), (LPBYTE)p->GetBuffer(), p->GetSize());
	delete[] p;

	Sleep(1000);

	PacketWriter* p1 = JoinInstance(0xFF);
	SendPacket(GetSendClass(), (LPBYTE)p1->GetBuffer(), p1->GetSize());
	delete[] p1;

	Sleep(10000);
}