#include <iostream>
#include <unistd.h>
#include "mylib.h"


#ifdef _WIN32
	#define USER_MSG "Windows User :("
#else
	#define USER_MSG "Linux User <3"
#endif

using namespace std;

#define M_PRI 0
#define M_NEW 1
#define M_DSP 2

char btn_idx = 0;
char menu=M_PRI;

bool exit_flag =false;
void exitCleanly(){
	clearScreen();
	revertTerminal();
	exit_flag = true;
}

void drawScreen(){
	clearScreen();

	// draw the currently selected menu
	switch (menu){
		case M_PRI:
		{
			string menu_items[] = {"New","Display","Exit"};
			drawMenu("Main Menu",menu_items,3,btn_idx);
		}
			
		break;
		case M_NEW:
		{	
			string menu_items[] = {"BTN1","BTN2","BTN3"};
			drawMenu("New Menu",menu_items,3,btn_idx);
		}
		break;
		case M_DSP:
		{
			string menu_items[] = {"BTN1","BTN2","BTN3"};
			drawMenu("Disp Menu",menu_items,3,btn_idx);
		}
		break;
	}

	// print user message
	setColor(C_GRN);
	setCursor(1,11);
	cout<<USER_MSG;
	setColor(C_WHT);

	// set final cursor location
	setCursor(1,10);
	cout.flush();
}

// button functions
void btnNew(){
	menu = M_NEW;
}
void btnDisp(){
	menu = M_DSP;
}
void btnExit(){
	exitCleanly();
}
void (*m_pri_btns[])() = {
	btnNew,
	btnDisp,
	btnExit
};


// --------------------------------------------------------
int main(){
	initTerminal();
	drawScreen();
	terminalSleep(1000);

	// Event Handler Loop
	while(!exit_flag){
		setCursor(1,10);


		char c = getButtonCode();
		switch (c){

			// movement
			case 'U':
			case 'L':
				btn_idx = (btn_idx-1);
				if (btn_idx==-1){btn_idx=2;}
			break;
			case 'D':
			case 'R':
				btn_idx = (btn_idx+1)%3;
			break;
			
			// entry
			case 'N':{
				switch (menu){
					case M_PRI:
					m_pri_btns[btn_idx]();
					break;
				}
			}
			break;

			// back
			case 'B':
			case 'H':
			if (menu==M_PRI){
				exitCleanly();
			}else{
				menu=M_PRI;
			}
			break;

			// exit
			case 'E':
			exitCleanly();
			break;
		}

		// draw
		drawScreen();

		//for debuggin purposes
		std::cout << "BTN PseudoCode: " << c /*<<(int)c*/;
		cout.flush();
	}

	return 0;
}