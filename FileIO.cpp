#include "FileIO.hpp"


BOOL FileHasLineA(char* FilePath, char* Substring)
{
	BOOL FoundLine = FALSE;

	std::ifstream infile(FilePath);
	std::string line;

	while (std::getline(infile, line)) //make this more portable
	{
		if (strstr(Substring, line.c_str()) != NULL)
		{
			FoundLine = TRUE;
			return FoundLine;
		}
	}

	infile.close();

	return FoundLine;
}

BOOL FileHasLineW(wchar_t* FilePath, wchar_t* Substring)
{
	BOOL FoundLine = FALSE;

	std::wifstream infile(FilePath);
	std::wstring line;

	while (std::getline(infile, line)) //make this more portable
	{
		if (wcsstr(Substring, line.c_str()) != NULL)
		{
			FoundLine = TRUE;
			return FoundLine;
		}
	}

	infile.close();

	return FoundLine;
}