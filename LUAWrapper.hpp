#pragma once

#pragma once
#define LUA_PTR lua_State* L

//LUA includes: loaded into binary
#include "LUA/lua.hpp"
#include "LUA/lauxlib.h"
#include "LUA/lualib.h"
#include "Packets.hpp"
#include "PacketBuilder.hpp"

void init_lua(); //has hooks installed here, don't forget.
void execute_lua(char* stream);
void end_lua();

static int LUA_MessageBox(LUA_PTR);
static int LUA_Sleep(LUA_PTR);
static int LUA_SendPacket(LUA_PTR);
static int LUA_SendCharacterAction(LUA_PTR);
static int LUA_EntityInteraction(LUA_PTR);
static int LUA_MoveWorldGridCoord(LUA_PTR);
static int LUA_CutDelveRope(LUA_PTR);
static int LUA_UseSelfSkill(LUA_PTR);
static int LUA_UseFlask(LUA_PTR);
static int LUA_GetPlayerHP(LUA_PTR);
static int LUA_GetPlayerMP(LUA_PTR);
static int LUA_ChangeHideout(LUA_PTR);
static int LUA_ThrowDynamite(LUA_PTR);
static int LUA_ThrowFlare(LUA_PTR);
static int LUA_VisitDelveNode(LUA_PTR);
static int LUA_FlipStackedDeck(LUA_PTR);
