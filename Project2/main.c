#include <stdio.h>

#include <windows.h>
#include "range.h"
#include "parseRange.h"
#include "style.h"
                                                                               
                                                                               
#define BUFFERSIZE 1024                                                                           


int main(int argc, char *argv[]) {
	// Set output mode to handle virtual terminal sequences
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return GetLastError();
	}

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return GetLastError();
	}

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(hOut, dwMode))
	{
		return GetLastError();
	}

	printf(" ________                     ______                       __            ___    \n");
	printf("|        \\                   /      \\                     |  \\          |   \\   \n");
	printf(" \\$$$$$$$$______   __    __ |  $$$$$$\\ _______    ______  | $$       __  \\$$$\\   \n");
	printf("   | $$  /      \\ |  \\  /  \\| $$__| $$|       \\  |      \\ | $$      |  \\   \\$$\\ \n");
	printf("   | $$ |  $$$$$$\\ \\$$\\/  $$| $$    $$| $$$$$$$\\  \\$$$$$$\\| $$       \\$$   | $$ \n");
	printf("   | $$ | $$    $$  >$$  $$ | $$$$$$$$| $$  | $$ /      $$| $$       __    | $$ \n");
	printf("   | $$ | $$$$$$$$ /  $$$$\\ | $$  | $$| $$  | $$|  $$$$$$$| $$      |  \\ _/  $$ \n");
	printf("   | $$  \\$$     \\|  $$ \\$$\\| $$  | $$| $$  | $$ \\$$    $$| $$      | $$|   $$  \n");
	printf("    \\$$   \\$$$$$$$ \\$$   \\$$ \\$$   \\$$ \\$$   \\$$  \\$$$$$$$ \\$$       \\$  \\$$$   \n");
	printf("\n\n");

	printf("Enter range: ");

	char buffer[BUFFERSIZE];
	fgets(buffer, BUFFERSIZE, stdin);
	if (buffer[strlen(buffer) - 1] == '\n') {
		buffer[strlen(buffer) - 1] = '\0';
	}
	range_t range = u_parseRange(buffer);
	r_printRange(range);

	u_resetStyle();
	//getchar();
	return 0;
}