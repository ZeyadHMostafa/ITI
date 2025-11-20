#include "mylib.h"

using namespace std;

#define BUFFER_SIZE 20

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

		char c = x&255;
		if (length==1 && isalnum(c)){strBufferAppend(c);}
		return ' ';
	}
#endif

// TODO: 
// - [x] Create a text entry buffer
// - [x] Add functions to access it?
// - [x] Allow ascii letters to be entered
// - [x] Create a new struct
// - [ ] Add entry usingcreated buffer
// - [ ] Add display functionality in display
// - [ ] Add scrolling?


char str_buffer[BUFFER_SIZE];
char str_buffer_id=0;

void strBufferRemove(){
	if (str_buffer_id!=0){
		str_buffer_id-=1;
		str_buffer[str_buffer_id]=0;
	}
}

void strBufferAppend(char c){
	if (str_buffer_id<BUFFER_SIZE-1){
		str_buffer[str_buffer_id]=c;
		str_buffer_id+=1;
		str_buffer[str_buffer_id]=0;
	}
}

void strBufferClear(){
	str_buffer_id=0;
	str_buffer[str_buffer_id]=0;
}


void strBufferFill(string str){
	str.copy(str_buffer,20);
	str_buffer[str.size()]=0;
	str_buffer_id=str.size();
}

void drawMenu(string title, string * items, int item_count, int btn_idx){
	// title
	setColor(C_YLW);
	setCursor(7,2);
	cout<<title;

	// menu items
	setColor(C_WHT);
	for (int i=0; i<item_count; i++){
		setCursor(10,4+i*2);
		if (btn_idx==i){setColor(C_BLU);} //set color of selected to blue
		cout<<items[i];
		setColor(C_WHT);
	}
}

// match code (reducing code inside #ifdef)
char matchCode(int code){
	switch (code){
		case K_L:
		return 'L';
		case K_U:
		return 'U';
		case K_R:
		return 'R';
		case K_D:
		return 'D';
		case K_N:
		return 'N';
		case K_H:
		return 'H';
		case K_E:
		return 'E';
		case K_B:
		return 'B';
		default:
		return ' ';
	}
}

// Get Colors on Terminal (Linux & Windows)
bool setColor(string color_code){
	cout<<CSI<<color_code;
	return true;
}

// Set Cursor on Terminal (Linux & Windows)
void setCursor(unsigned int x,unsigned int y){
	cout<<CSI<<y<<";"<<x<<"H";
}

// Clear The Whole Screen (Linux & Windows)
void clearScreen(){
	cout<<CSI<<"2J";
}

// Sleep for Certain Time (Linux & Windows)
void terminalSleep(unsigned int x){
	cout.flush();
	this_thread::sleep_for(std::chrono::milliseconds(x));
}
