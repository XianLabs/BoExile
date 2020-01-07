#pragma once
#include "CComponent.hpp"
#include "Entity.hpp"

class Chest : public CComponent
{
private:

	bool IsOpened; // 0x58 == 1
	bool IsLocked; //0x59 > 1
	bool IsStrongbox; //0x98 > 0
	byte Quality; //0x5C

	long StrongboxInfo; //0x20
	bool IsDestroyingAfterOpening; //(StrongBoxInfo + 0x20) == 1 and if addr != 0
	bool IsLargeBox; //(StrongBoxInfo + 0x21) == 1
	bool IsBreakable; //(StrongboxInfo + 0x22) == 1
	bool IsOpenOnDamageTaken; //StrongboxData + 0x25 == 1
	bool IsOpenWhenMonstersDie; //strongboxInfo + 0x28 == 1

public:

	byte GetIsOpened(Entity* e);
	byte GetIsLocked(Entity* e);
	byte GetIsStrongbox(Entity* e);
	byte GetQuality(Entity* e);


};