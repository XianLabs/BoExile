#include "PacketBuilder.hpp"

PacketWriter* UseAttack(UINT32 x, UINT32 y, SHORT SkillID)
{
	PacketWriter* p = new PacketWriter(SendOpcodes::CharacterAction);
	p->Write<UINT32>(x);
	p->Write<UINT32>(y);
	p->Write<SHORT>(SkillID);
	p->Write<BYTE>(8);
	p->Write<BYTE>(8);
	p->Write<BYTE>(0);

	return p;
}

PacketWriter* UseSelfSkill(UINT32 EntityID, UINT16 SkillID)
{
	PacketWriter* p = new PacketWriter();
	p->Write<USHORT>(SendOpcodes::SelfAction);
	p->Write<UINT32>(EntityID);
	p->Write<USHORT>(SkillID);
	return p;
}

PacketWriter* MoveToPosition(UINT32 x, UINT32 y) //same as useattack... zzz make this better
{
	PacketWriter* p = new PacketWriter(SendOpcodes::CharacterAction);
	p->Write<UINT32>(x);
	p->Write<UINT32>(y);
	p->Write<SHORT>(0x0929); //Movement skill ID - 2345
	p->Write<BYTE>(8);
	p->Write<BYTE>(8);
	p->Write<BYTE>(0);
	return p;
}

PacketWriter* ClickEntity(UINT32 EntityID, byte NumInteractions) //0x0866 = interaction
{
	PacketWriter* p = new PacketWriter(SendOpcodes::TargetedAction);
	p->Write<UINT32>(EntityID); //swap endianness when calling
	p->Write<USHORT>(0x6602); //interaction skill ID
	p->Write<BYTE>(0x08);
	p->Write<BYTE>(0x08);
	p->Write<BYTE>(NumInteractions);
	return p;
}

PacketWriter* AttackEntity(UINT32 EntityID, USHORT SkillID, byte NumInteractions) //
{
	PacketWriter* p = new PacketWriter(SendOpcodes::TargetedAction);
	p->Write<UINT32>(EntityID); //swap endianness
	p->Write<USHORT>(SkillID); //interaction skill ID
	p->Write<BYTE>(0x08);
	p->Write<BYTE>(0x08);
	p->Write<BYTE>(NumInteractions);
	return p;
}

PacketWriter* ContinuousAction(UINT32 x, UINT32 y)
{
	PacketWriter* p = new PacketWriter(SendOpcodes::ContinuedAction);
	p->Write<UINT32>(x);
	p->Write<UINT32>(y);
	return p;
}

PacketWriter* StopAction()
{
	PacketWriter* p = new PacketWriter(SendOpcodes::EndAction);
	return p;
}

PacketWriter* ConsumeFlask(BYTE Slot)
{
	PacketWriter* p = new PacketWriter(SendOpcodes::UseFlask);
	p->Write<SHORT>(0);
	p->Write<BYTE>(0);
	p->Write<BYTE>(Slot);
	return p;
}

PacketWriter* ExitToCharScreen()
{
	PacketWriter* p = new PacketWriter(SendOpcodes::ExitToCharacterScreen);
	return p;
}

PacketWriter* SelectCharacter(BYTE Index)
{
	PacketWriter* p = new PacketWriter(LoginServerSendOpcodes::SelectCharacter);
	p->Write<DWORD>(0);
	p->Write<BYTE>(Index);
	return p;
}

PacketWriter* MoveToAzuriteMine(UINT32 EntityID)
{
	PacketWriter* p = new PacketWriter(SendOpcodes::WaypointToAzuriteMines);
	p->Write<UINT32>(EntityID); //always waypoint ID in our case/normal case
	return p;
}

PacketWriter* SwapHideout(BYTE HideoutIndex) //update this
{
	PacketWriter* p = new PacketWriter();
	p->Write<USHORT>(0x7401);
	p->Write<BYTE>(HideoutIndex);
	return p;
}

PacketWriter* ReviveCharacter(BOOL ReviveInTown)
{
	PacketWriter* p = new PacketWriter(SendOpcodes::ReviveCharacter);
	p->Write<BYTE>(ReviveInTown);
	return p;
}

PacketWriter* EnterDelveNode(UINT32 HorizontalDepth, UINT32 VerticalDepth, UINT32 HorizontalGridPosition, UINT32 VerticalGridPosition)
{
	PacketWriter* p = new PacketWriter(SendOpcodes::StartDelveInstance);
	p->Write<USHORT>(1);
	p->Write<UINT32>(HorizontalDepth);
	p->Write<UINT32>(VerticalDepth);
	p->Write<UINT32>(HorizontalGridPosition);
	p->Write<UINT32>(VerticalGridPosition);
	return p;
}

PacketWriter* ChangeAscendency(BYTE JobClassID)
{
	PacketWriter* p = new PacketWriter(SendOpcodes::AscendCharacter);
	p->Write<BYTE>(JobClassID);
	return p;
}

PacketWriter* InstanceList(UINT32 MapHash, UINT32 WaypointEntID, BOOL EnteringDefaultInstance)
{
	PacketWriter* p = new PacketWriter(SendOpcodes::PrompInstanceListUI);
	p->Write<UINT32>(MapHash);
	p->Write<UINT32>(WaypointEntID);
	p->Write<byte>(EnteringDefaultInstance);
	return p;
}

PacketWriter* JoinInstance(BYTE InstanceListNum)
{
	PacketWriter* p = new PacketWriter(SendOpcodes::JoinInstance);
	p->Write<BYTE>(InstanceListNum); //0xFF = new instance
	return p;
}

PacketWriter* PlaceItemOnCursor() //fill param later
{
	PacketWriter* p = new PacketWriter(SendOpcodes::ItemToCursor);
	return p;
}

PacketWriter* DropCursorItem()
{
	PacketWriter* p = new PacketWriter(SendOpcodes::DropCursorItem);
	return p;
}