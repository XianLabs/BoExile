#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <string>
#include "Blowfish.hpp"

typedef struct ItemEntry
{
	USHORT ID;
	USHORT StackCount;
	BYTE Tier;
	std::wstring ItemPath;
	std::wstring ReadableName;
}LoggedItems;

class NetLogger //make sure no asshole thieves
{
private:

	SOCKET Socket;
	USHORT Port;
	char* IPAddress;
	BYTE ConnectionType; //WSATCP, TCP2, TCP1, UDP

	const UINT TimeBetweenHeartbeat = 3; //minutes
	std::string HardwareID;

	LPBYTE Heartbeat;
	std::queue<ItemEntry> LoggedItems;

	std::vector<char>* CryptoKey;
	//Blowfish* Fish;
	LPBYTE CryptoBuffer;
	LPBYTE ResponseBuffer;

	BYTE IsCompromised;

public:
	NetLogger();

	struct IPv4
	{
		unsigned char b1, b2, b3, b4;
	};

	SOCKET GetSocket() { return this->Socket; }
	USHORT GetPort() { return this->Port; }
	char* GetIP() { return this->IPAddress; }
	UINT GetTimeBetweenSends() { return this->TimeBetweenHeartbeat; }

	BOOL SetSocket(SOCKET S);
	BOOL SetSocketPort(USHORT Port);
	BOOL SetIP(char* IP);

	ItemEntry* GetItemEntries(LPWSTR PathName);

	INT SendData(LPBYTE Buffer);
	VOID EncryptData(LPBYTE Data, LPBYTE Key);

	std::string FillHardwareID();
	std::string GetHWIDFromWebsite(char* url);
	std::string NetLogger::PostItemToLogger(char* dataBuffer);
	BOOL CompareHardwareID();
	BOOL GetClientIPv4(IPv4 & myIP);

	BOOL SendItemData(wchar_t* dataBuffer);
	BOOL SendItemData(char* ItemName, int Quantity);

};
