
#define WINVER 0x0501
#define _WIN32_WINNT 0x0501

#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>

#define BUF_SIZE 512

int main() {

	OPENFILENAME ofn;       // common dialog box structure
	char szFile[260];       // buffer for file name
	HWND hwnd = GetConsoleWindow();              // owner window

	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = szFile;
	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	
	if (GetOpenFileName(&ofn) == TRUE) {
		printf("Selected file %s\n", ofn.lpstrFile);
		HANDLE hf = CreateFile(ofn.lpstrFile,
			GENERIC_READ,
			0,
			(LPSECURITY_ATTRIBUTES) NULL,
			OPEN_EXISTING,
			FILE_FLAG_NO_BUFFERING | FILE_ATTRIBUTE_NORMAL,
			(HANDLE) NULL);

		if (hf != INVALID_HANDLE_VALUE) {
			DWORD dwBytesRead;
			char buf[BUF_SIZE];
			std::string s, old_s;
			bool fExit = false;

			std::cout << "Press \"Esc\" for exit." << std::endl;
			while (!fExit) {
				if (_kbhit() && getch() == 27) fExit = true;
				SetFilePointer(hf, 0, NULL, 0);
				if(ReadFile(hf, buf, BUF_SIZE, &dwBytesRead, NULL)) {
					buf[dwBytesRead]='\0';
					s = buf;
					if (s != old_s) {
						std::cout << s << std::endl;
						old_s = s;
					}
				} else {
					std::cout << "Could not read from file \
						(error GetLastError())" << std::endl;
				}
			}
			CloseHandle(hf);
		} else {
			std::cout << "Invalid handle." << std::endl;
		}
	} else {
		std::cout << "No file." << std::endl;
	}

	return 0;
}
