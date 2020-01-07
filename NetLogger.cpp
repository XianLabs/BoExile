#include "NetLogger.hpp"

NetLogger::NetLogger()
{
	//printf("BoE Debug: NetLogger Enabled \n");

	this->CryptoKey = new std::vector<char>();

	for (int i = 0; i < 8; i++)
	{
		char j = i;
		this->CryptoKey->push_back(j);
	}

	//this->Fish = new Blowfish(*this->CryptoKey);

	this->IsCompromised = FALSE;
}

BOOL NetLogger::SetSocket(SOCKET S)
{
	if (S != NULL)
	{
		this->Socket = S;
		return TRUE;
	}

	this->Socket = NULL;
	return FALSE;
}

BOOL NetLogger::SetSocketPort(USHORT Port)
{
	if (Port != 0)
	{
		this->Port = Port;
		return TRUE;
	}

	this->Port = 0;
	return FALSE;
}

BOOL NetLogger::SetIP(char* IP)
{
	return TRUE;
}

INT NetLogger::SendData(LPBYTE Buffer)
{
	return 0;
}

BOOL NetLogger::GetClientIPv4(IPv4 & myIP)
{
	char szBuffer[1024];

#ifdef WIN32
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD(2, 0);
	if (::WSAStartup(wVersionRequested, &wsaData) != 0)
		return false;
#endif


	if (gethostname(szBuffer, sizeof(szBuffer)) == SOCKET_ERROR)
	{
#ifdef WIN32
		WSACleanup();
#endif
		return false;
	}

	struct hostent *host = gethostbyname(szBuffer);
	if (host == NULL)
	{
#ifdef WIN32
		WSACleanup();
#endif
		return false;
	}

	//Obtain the computer's IP
	myIP.b1 = ((struct in_addr *)(host->h_addr))->S_un.S_un_b.s_b1;
	myIP.b2 = ((struct in_addr *)(host->h_addr))->S_un.S_un_b.s_b2;
	myIP.b3 = ((struct in_addr *)(host->h_addr))->S_un.S_un_b.s_b3;
	myIP.b4 = ((struct in_addr *)(host->h_addr))->S_un.S_un_b.s_b4;

#ifdef WIN32
	WSACleanup();
#endif
	return true;
}

BOOL NetLogger::CompareHardwareID()
{
	std::string HWID = this->FillHardwareID();
	std::string SiteHWID = this->GetHWIDFromWebsite("www.xianlabs.net");

	if (SiteHWID.find(HWID) != std::string::npos)
	{
		printf("Found matching HWID - Enjoy BoE!\n");
		this->IsCompromised = FALSE;
		return TRUE;
	}
	else
	{
		printf("Non-matching HWID. Shutting down BoE.\n");
		this->IsCompromised = TRUE;
		return FALSE;
	}
}

VOID NetLogger::EncryptData(LPBYTE Key, LPBYTE Data)
{

}

ItemEntry* NetLogger::GetItemEntries(LPWSTR PathName)
{
	return new ItemEntry();
}

std::string NetLogger::GetHWIDFromWebsite(char* url)
{
	WSADATA wsaData;
	SOCKET Socket;
	SOCKADDR_IN SockAddr;
	int lineCount = 0;
	int rowCount = 0;
	struct hostent *host = (hostent*)malloc(sizeof(struct hostent) * 1);
	std::string get_http = std::string("GET /hwid/ HTTP/1.1\r\nHost: www.xianlabs.net\r\nConnection: close\r\n\r\n");
	std::string website_HTML;
	char buffer[1024];
	int i = 0;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup failed: %d.\n", WSAGetLastError());
		return NULL;
	}

	Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	host = gethostbyname(url);
	SockAddr.sin_port = htons(80);
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

	if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0)
	{
		printf("Could not connect?");
		return NULL;
	}

	int BytesSent = send(Socket, get_http.c_str(), strlen(get_http.c_str()), 0);
	int nDataLength;
	while ((nDataLength = recv(Socket, buffer, 1024, 0)) > 0){
		int i = 0;
		while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r')
		{
			website_HTML += buffer[i];
			i += 1;
		}
	}

	const char* HWID = NULL;
	HWID = strstr(website_HTML.c_str(), "<body>");
	const char* HWIDStart = HWID + 7;

	CHAR HardwareID[256] = { 0 };
	int j = 0;

	//while not </body>, new start HWID at \n.
	for (int i = 0; i < strlen(HWIDStart); i++)
	{
		if (HWIDStart[i] == '/')
		{
			break;
		}
		else if (HWIDStart[i] == '\n')
		{
			continue;
		}
		else
		{
			HardwareID[j++] = HWIDStart[i];
		}
	}

	closesocket(Socket);
	WSACleanup();

	return std::string(HardwareID);
}

//collect timestamp, item name, quantity, char name
BOOL NetLogger::SendItemData(wchar_t* dataBuffer)
{
	//convert wchar_t* to char*
	char Buffer[256] = { 0 };

	if (wcstombs(&Buffer[0], dataBuffer, (sizeof(byte)*wcslen(dataBuffer) * 2) + 1) == static_cast<std::size_t>(-1))
	{
		printf("Couldn't convert to lower!\n");
		return FALSE;
	}

	printf("Buffer: %s\n", Buffer);

	WSADATA wsaData;
	SOCKET Socket;
	SOCKADDR_IN SockAddr;
	int lineCount = 0;
	int rowCount = 0;
	struct hostent *host = (hostent*)malloc(sizeof(struct hostent) * 1);
	std::string post_http = std::string("POST /log/ HTTP/1.1\r\n");
	post_http += "Host: www.xianlabs.net\r\n";
	post_http += "Connection: close\r\n";
	post_http += "Content-Type: application/x-www-form-urlencoded; charset=UTF-8\r\n\r\n";
	post_http += Buffer;
	std::string website_HTML;
	char buffer[1024];
	int i = 0;

	printf("%s\n", post_http.c_str());

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup failed: %d.\n", WSAGetLastError());
		return FALSE;
	}

	Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	host = gethostbyname("www.xianlabs.net");
	SockAddr.sin_port = htons(80);
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

	if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0)
	{
		printf("Could not connect to server: %d\n", WSAGetLastError());
		return FALSE;
	}

	int BytesSent = send(Socket, post_http.c_str(), strlen(post_http.c_str()), 0);
	int nDataLength;
	while ((nDataLength = recv(Socket, buffer, 1024, 0)) > 0){
		int i = 0;
		while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r')
		{
			website_HTML += buffer[i];
			i += 1;
		}
	}

	printf("\n\n %s \n", website_HTML.c_str());

	closesocket(Socket);
	WSACleanup();

	//decrypt and check data sent back
	return TRUE;
}

std::string NetLogger::FillHardwareID()
{
	std::string HWID;

	CHAR volumeName[MAX_PATH + 1] = { 0 };
	CHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;

	if (GetVolumeInformationA("C:\\", volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName)))
	{
		CHAR serialBuf[20];
		_itoa_s(serialNumber, serialBuf, 10);

		CHAR username[1024 + 1];
		DWORD size = 1024 + 1;
		GetUserNameA((CHAR*)username, &size);

		HWID = username;
		HWID += "-";
		HWID += serialBuf;
	}
	else
	{
		HWID = "Failed to generate HWID.";
		return NULL;
	}
	return HWID;
}