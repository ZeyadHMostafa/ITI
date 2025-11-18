#include "mylib.h"
#ifdef _WIN32	
	bool EnableVTMode()
	{
		// Set output mode to handle virtual terminal sequences
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut == INVALID_HANDLE_VALUE)
		{
			return false;
		}

		DWORD dwMode = 0;
		if (!GetConsoleMode(hOut, &dwMode))
		{
			return false;
		}

		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		if (!SetConsoleMode(hOut, dwMode))
		{
			return false;
		}
		return true;
	}
#else
	bool EnableVTMode(){return true;}
#endif

using namespace std;

std::map<std::string,std::string> color_codes={
	{"BLACK",	"0;30m"},
	{"RED",		"0;31m"},
	{"GREEN",	"0;32m"},
	{"YELLOW",	"0;33m"},
	{"BLUE",	"0;34m"},
	{"WHITE",	"0;37m"},
};

// Get Colors on Terminal (Linux & Windows)
bool set_color(string color_name){
	if (color_codes.count(color_name)==0) return false;
	cout<<CSI<<color_codes[color_name];
	return true;
}

// Set Cursor on Terminal (Linux & Windows)
void set_cursor(unsigned int x,unsigned int y){
	cout<<CSI<<y<<";"<<x<<"H";
}

// Clear The Whole Screen (Linux & Windows)
void clear_screen(){
	cout<<CSI<<"2J";
}

// Sleep for Certain Time (Linux & Windows)
void sleep(unsigned int x){
	cout.flush();
	this_thread::sleep_for(std::chrono::milliseconds(x));
}
