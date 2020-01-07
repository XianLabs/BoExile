#pragma once
#include "Structures.hpp"

extern "C" UINT64 GetSendClass();
extern "C" VOID SendPacket(UINT64 SendClass, LPBYTE Data, UINT64 Length);

extern "C" VOID LogSendPacketHook();
extern "C" VOID MoveSendPacketReturnAddress(UINT64);
extern "C" VOID MoveCreatePacketAddress(UINT64);
extern "C" VOID MoveSendPacketAddress(UINT64);

extern "C" VOID SendAction(UINT64 ptrCharBase, SHORT SkillID, UINT64 optional_entity, Vector2* v2);
extern "C" VOID SetSendActionAddress(UINT64);

extern "C" VOID EntitySpawnHook();
extern "C" VOID SetEntitySpawnHookReturnAddress(UINT64);
extern "C" VOID SetEntitySpawnHookCallbackAddress(UINT64);

extern "C" VOID SetWriteFileHookReturnAddress(UINT64);
extern "C" VOID SetWriteFileHookCallbackAddress(UINT64);
extern "C" VOID WriteFileHook();

extern "C" VOID MoveAutoPotCallbackHookAddress(UINT64);
extern "C" VOID MoveAutoPotReturnHookAddress(UINT64);
extern "C" VOID GetCurrentHPMPHook();
