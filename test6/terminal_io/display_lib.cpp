#include "terminal_io.h"
using namespace std;

// quick draw for menus with title
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