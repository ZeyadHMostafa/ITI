#include "terminal_io.h"
/*
Contains code for Initializtion of terminal
and OS dependant code interaction
*/

using namespace std;

char buffer_mode=0;

char should_append(char c){
return (isdigit(c)||isalpha(c)&&(buffer_mode==BUFFER_MODE_ALPHA)||c==' ');
}

#ifdef _WIN32
	void initTerminal(){
		// Enable VT mode
		// this was taken from windows documentation

		// Set output mode to handle virtual terminal sequences

		// get handle and verify it is valid
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut == INVALID_HANDLE_VALUE) {return false;}

		// get console mode and verify the code worked
		DWORD dwMode = 0;
		if (!GetConsoleMode(hOut, &dwMode)) {return false;}

		// attempt to set virtual terminal processing to true
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		if (!SetConsoleMode(hOut, dwMode)) {return false;}

		// if succesful return true
		return true;
	}

	void revertTerminal(){}

	char getButtonCode(){
		// return when desired button is pressed
		while (true)
		{
			for(int i = 8; i <= 256; i++)
			{
				if(GetAsyncKeyState(i) & 0x7FFF)
				{
					char k_code = matchCode(i);
					if (k_code!= ' ') return k_code;
				}
			}
		}
	}
#else
	struct termios old_tio, new_tio;

	void initTerminal(){

		// Get the current terminal settings
		tcgetattr(STDIN_FILENO, &old_tio);

		// Copy settings to a new structure
		new_tio = old_tio;

		// Set non-canonical mode and disable echo
		new_tio.c_lflag &= ~(ICANON | ECHO);
		new_tio.c_cc[VMIN] = 1;  // Read at least 1 character
		new_tio.c_cc[VTIME] = 0; // No timeout for read()

		// Apply the new settings
		tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
	}

	void revertTerminal(){
		// Restore original terminal settings
		tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
	}
	char getButtonCode(){
		unsigned int x;
		int length=read(STDIN_FILENO, &x, 4);
		if (length == -1){
			return' ';
		}
		x=x&~(0xFFFFFFFF<<(length*8));

		char k_code = matchCode(x);
		if (k_code!= ' ') return k_code;	

		//currently only allows alpha numeric characters & space
		char c = x&255;
		if ((length==1) && should_append(c)){strBufferAppend(c);}
		return ' ';
	}
#endif