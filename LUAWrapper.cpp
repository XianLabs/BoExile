#include "LUAWrapper.hpp"
#include <fstream>
#include <vector>

//global LUA ptr
lua_State* L;
HANDLE ScriptThread; //lua

extern "C" void SendPacket(UINT64, LPBYTE, UINT64);
extern "C" UINT64 GetSendClass();

void init_lua()
{
	L = luaL_newstate();
	luaL_openlibs(L);

	lua_register(L, "MessageBox", LUA_MessageBox);
	lua_register(L, "Sleep", LUA_Sleep);
	lua_register(L, "SendPacket", LUA_SendPacket);
	lua_register(L, "EntityInteraction", LUA_EntityInteraction);
	lua_register(L, "CharacterAction", LUA_SendCharacterAction);
	lua_register(L, "MoveToGridCoord", LUA_MoveWorldGridCoord);
	lua_register(L, "CutDelveRope", LUA_CutDelveRope);
	lua_register(L, "UseSelfSkill", LUA_UseSelfSkill);
	lua_register(L, "UseFlask", LUA_UseFlask);
	lua_register(L, "GetPlayerHP", LUA_GetPlayerHP);
	lua_register(L, "GetPlayerMP", LUA_GetPlayerMP);
	lua_register(L, "ChangeHideout", LUA_ChangeHideout);
	lua_register(L, "ThrowDynamite", LUA_ThrowDynamite);
	lua_register(L, "UseFlare", LUA_ThrowFlare);
	lua_register(L, "VisitDelveNode", LUA_VisitDelveNode);
}

void execute_lua(char* stream)
{
	init_lua();

	std::ofstream tempFile;
	tempFile.open("./tempScript.lua");
	tempFile << stream;
	tempFile.close();

	if (stream == NULL || strcmp(stream, "Enter script here...") == 0 || strcmp(stream, "") == 0)
	{
		return;
	}
	else
		luaL_dofile(L, "./tempScript.lua"); //execute LUA script
}

void end_lua()
{
	lua_close(L);
	TerminateThread(ScriptThread, 0);
}

//LUA Custom Functions
static int LUA_MessageBox(LUA_PTR)
{
	const char* str = lua_tostring(L, 1); // get function argument
	MessageBoxA(0, str, "PoE PE", 0);
	return 0;
}

int LUA_Sleep(LUA_PTR)
{
	int n = lua_gettop(L);
	int delay = lua_tonumber(L, 1);
	Sleep(delay);
	return 0;
}

static int LUA_SendPacket(LUA_PTR)
{
	const char* str = lua_tostring(L, 1);
	BYTE* hexbytes = convertStringToPacketFormat((char*)str);
	DWORD length = getPacketLength((char*)str);
	UINT64 SendClass = GetSendClass();
	SendPacket(SendClass, hexbytes, length);
	delete[] hexbytes;
	return 0;
}

static int LUA_SendCharacterAction(LUA_PTR)
{
	//get char xy
	UINT64 SendClass = GetSendClass();
	const USHORT SkillID = lua_tointeger(L, 1);
	PacketWriter* p = UseAttack(0, 0, SkillID);
	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
	return 0;
}

static int LUA_EntityInteraction(LUA_PTR)
{
	const UINT32 EntityID = lua_tointeger(L, 1);
	UINT64 SendClass = GetSendClass();
	PacketWriter* p = ClickEntity(EntityID, 0);
	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
	return 0;
}
static int LUA_MoveWorldGridCoord(LUA_PTR)
{
	const UINT32 X = lua_tointeger(L, 1);
	const UINT32 Y = lua_tointeger(L, 2);
	UINT64 SendClass = GetSendClass();
	PacketWriter* p = MoveToPosition(X, Y);
	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
	return 0;
}

static int LUA_CutDelveRope(LUA_PTR)
{
	return 0;
}

static int LUA_UseSelfSkill(LUA_PTR)
{
	const UINT32 EntityID = lua_tointeger(L, 1);
	const UINT16 SkillID = lua_tointeger(L, 2);
	UINT64 SendClass = GetSendClass();
	PacketWriter* p = UseSelfSkill(EntityID, SkillID);
	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
	return 0;
}

static int LUA_UseFlask(LUA_PTR)
{
	const byte BeltSlot = lua_tointeger(L, 1);
	UINT64 SendClass = GetSendClass();
	PacketWriter* p = ConsumeFlask(BeltSlot);
	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
	return 0;
}

static int LUA_GetPlayerHP(LUA_PTR)
{

	return 0;
}

static int LUA_GetPlayerMP(LUA_PTR)
{

	return 0;
}

static int LUA_ChangeHideout(LUA_PTR)
{
	const byte Hideout = lua_tointeger(L, 1);
	UINT64 SendClass = GetSendClass();
	PacketWriter* p = SwapHideout(Hideout);
	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
	return 0;
}

static int LUA_ThrowDynamite(LUA_PTR)
{
	UINT64 SendClass = GetSendClass();
	//PacketWriter* p = ChangeHideout(Hideout);
	//	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	//	delete p;
	return 0;
}

static int LUA_ThrowFlare(LUA_PTR)
{
	UINT64 SendClass = GetSendClass();
	//	PacketWriter* p = ChangeHideout(Hideout);
	//	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	//	delete p;
	return 0;
}

static int LUA_VisitDelveNode(LUA_PTR)
{
	const int HorizontalDepth = lua_tointeger(L, 1);
	const int VerticalDepth = lua_tointeger(L, 2);
	const int HorizontalGrid = lua_tointeger(L, 3);
	const int VerticalGrid = lua_tointeger(L, 4);

	UINT64 SendClass = GetSendClass();
	PacketWriter* p = EnterDelveNode(HorizontalDepth, VerticalDepth, HorizontalGrid, VerticalGrid);
	SendPacket(SendClass, (LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
	return 0;
}