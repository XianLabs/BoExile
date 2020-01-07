#pragma once
#include "PacketWriter.hpp"

namespace LoginServerSendOpcodes
{
	const USHORT SelectCharacter = 0x0C00;

};

namespace SendOpcodes
{
	const USHORT Ping = 0x0100;
	const USHORT ChatMessage = 0x0800;
	const USHORT ItemToCursor = 0x1B00;
	const USHORT DropCursorItem = 0x1C00;
	const USHORT LevelUpSkillGem = 0x2100;
	const USHORT AscendCharacter = 0x2600;
	const USHORT PrompInstanceListUI = 0x3200;
	const USHORT ReviveCharacter = 0x3600;
	const USHORT UseFlask = 0x3E00;
	const USHORT JoinInstance = 0x6A00;
	const USHORT ExitToCharacterScreen = 0xD100;
	const USHORT WaypointToAzuriteMines = 0xE300;
	const USHORT CharacterAction = 0xF200;
	const USHORT TargetedAction = 0xF100;
	const USHORT SelfAction = 0xEF00;
	const USHORT ContinuedAction = 0xF100;
	const USHORT EndAction = 0xF800;
	const USHORT StartDelveInstance = 0x6401;
	
};

namespace RecvOpcodes
{

};

PacketWriter* UseAttack(UINT32 x, UINT32 y, SHORT SkillID);
PacketWriter* UseSelfSkill(UINT32 EntityID, UINT16 SkillID);
PacketWriter* MoveToPosition(UINT32 x, UINT32 y);
PacketWriter* ContinuousAction(UINT32 x, UINT32 y);
PacketWriter* StopAction();
PacketWriter* ConsumeFlask(BYTE Slot);
PacketWriter* ExitToCharScreen();
PacketWriter* SelectCharacter(BYTE Index);
PacketWriter* MoveToAzuriteMine();
PacketWriter* ClickEntity(UINT32 EntityID, byte numInteractions);
PacketWriter* SwapHideout(BYTE HideoutIndex);
PacketWriter* ReviveCharacter(BOOL ReviveInTown);
PacketWriter* EnterDelveNode(UINT32 HorizontalDepth, UINT32 VerticalDepth, UINT32 HorizontalGridPosition, UINT32 VerticalGridPosition);
PacketWriter* ChangeAscendency(BYTE JobClassID);
PacketWriter* InstanceList(UINT32 MapHash, UINT32 WaypointEntID, BOOL EnteringDefaultInstance);
PacketWriter* JoinInstance(BYTE InstanceListNum);
PacketWriter* FlipStackedDeck(UINT32 InventoryID, UINT32 EntityID);
PacketWriter* DropCursorItem();
PacketWriter* AttackEntity(UINT32 EntityID, USHORT SkillID, byte NumInteractions);