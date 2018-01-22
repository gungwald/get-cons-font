// GetCurrentConsoleFontEx.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int exitCode = EXIT_FAILURE;
	HANDLE hConsOutput = CreateFile(
		L"CONOUT$",
		GENERIC_READ,
		FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hConsOutput == INVALID_HANDLE_VALUE) {
		writeErrorMessage(L"CreateFile", GetLastError());
	}
	else {
		CONSOLE_FONT_INFOEX fontInfo;
		fontInfo.cbSize = sizeof(fontInfo);
		if (GetCurrentConsoleFontEx(hConsOutput, FALSE, &fontInfo)) {
			exitCode = EXIT_SUCCESS;
			wprintf(L"FaceName: %s\n", fontInfo.FaceName);
		}
		else {
			writeErrorMessage(L"GetCurrentConsoleFontEx", GetLastError());
		}
	}
	printf("Press Enter to continue: ");
	char buf[BUFSIZ];
	fgets(buf, BUFSIZ, stdin);
    return exitCode;
}

