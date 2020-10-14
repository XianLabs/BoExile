//for heist patch oct 14 2020

#pragma once
#include <Windows.h>

//Constants/offsets
CONST UINT64 SendPacketFuncOffset = 0x127D890;
CONST UINT64 LogSendOffset = SendPacketFuncOffset + 0x34; //41 56 48 8D A8 F8 FC FF FF 48 81 EC F0 03 00 00
CONST UINT64 LogSendReturnOffset = LogSendOffset + 0x0E;

//Antihack?
CONST UINT64 AntiMigrateFunction = 0x1A8C30; //40 57 48 83 EC 30 48 C7 44 24 20 FE FF FF FF 48 89 5c 24 40 48 8b d9
CONST UINT64 MinidumpUploadOffset = 0x5AABF0; //FF 15 ? ? ? ? 45 33 C9 48 8D 85 80 05 00 00 45 33 c0 48 89 44 24 20 fix
CONST UINT64 MinimapLogOffset = 0x1B58EE0; //48 8D 68 B9 48 81 EC C0 00 00 00 45 8B E1 4D 8B F0 44 8B 4D 77

CONST UINT64 MaphackAddressOffset = 0x159920C + 5; //66 C7 ?? 78 00 00 C6

CONST UINT64 CharacterPointerBaseOffset = 0x3663868;
CONST UINT64 GridCoordsXOffset = 0x1140;
CONST UINT64 GridCoordsYOffset = GridCoordsXOffset + 4;

CONST UINT64 CurrentHPMPAddressOffset = 0x24E8CE4; //48 8B B4 24 B8 00 00 00 48 8B BC 24 C0 00 00 00

CONST UINT64 SendPlayerActionOffset = 0xC4EAB0; //41 56 48 83 ec 50 48 c7 44 24 20 fe ff ff ff 48 89 5c 24 68 48 89 6C 24 70 48 89 7c 24 78

CONST UINT64 LogRecvOffset = 0xD6E675; //48 8B AC 24 90 00 00 00 48 63 C7 48 01 83 98 01 00 00 48 8B 83 E8 00 00 00

CONST UINT64 EntitySpawnOffset = 0xC37A79; //48 81 EC 50 01 00 00 48 C7 44 24 ? FE FF FF FF 48 89 9c 24 70 01 00 00, top of function sub rsp 150

CONST UINT64 LogDebugFileOutputOffset = 0x1B57D7E; //4c 8d 4c 24 30 44 8b c7 48 8d 54 24 40 49 8b ce ff 15 ? ? ? ? 85 c0 74 12 8b 44 24 30 

CONST UINT64 AccountNameOffset = 0x1EF3D40; //0F 11 05 ? ? ? ? 0F 10 4D 80 0F 11 0D ? ? ? ? 66 0F 6F 05 ? ? ? ? fix this

//Lights, etc
CONST UINT64 MapLightExpanseOffset = 0x13C169A; //F2 0F 11 44 24 20 F3 0F 5F -> above movd mxx3,[rsp+b8]

CONST UINT64 ZoomHackOffset = 0x6FED33 + 0x3; //F3 0F 11 93 ? ? 00 00 C6 07 01 48 8B 74 24 40

CONST UINT64 ActionSpeedDelayOffset = 0x1812770; //useless anyways, dont have AoB

