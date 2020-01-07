#pragma once
#include "ASMExterns.hpp"
#include "PacketWriter.hpp"

unsigned char* convertStringToPacketFormat(char* convertStr);
char* convertPacketFormatToString(unsigned char* packetStr, int byteLength);
int getPacketLength(char* grabbedTextPacket);
short changeEndianness16(short val);

BOOL CreatePacket(LPBYTE data, DWORD length);
BOOL CreateRecvPacket(LPBYTE data, DWORD length);