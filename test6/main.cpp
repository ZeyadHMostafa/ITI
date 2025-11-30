#include <iostream>
#include <unistd.h>
#include "terminal_io.h"
#include "text_edit.h"

using namespace std;

#define M_PRI 0
#define M_NEW 1
#define M_DSP 2

// general menus
char lst_idx = 0;
char menu=M_PRI;
extern char str_buffer[];

// text specific
bool size_specified = false;
extern int current_script_count;
extern char buffer_mode;

//---------------------------------------

// functions 
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
			// work around
			buffer_mode = BUFFER_MODE_ALPHA;
			//-------
			string menu_items[] = {"New","Display","Exit"};
			drawMenu("Main Menu",menu_items,3,lst_idx);
		}
			
		break;
		case M_NEW:
		{
			if (size_specified){
				displayTextEditMenu(TEXT_MENU_MODE_EDIT);
			}else{
				displayTextEditMenu(TEXT_MENU_MODE_NEW);
			}
		}
		break;
		case M_DSP:
		{	
			displayTextEditMenu(TEXT_MENU_MODE_DISP);
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
	if (!size_specified) buffer_mode = BUFFER_MODE_NUMERIC;
	strBufferClear();
}
void btnDisp(){
	if (current_script_count==0) {return;}
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
				switch (menu){
					case M_NEW:
					moveScriptCursor(-32);
					break;
					case M_PRI:
					lst_idx = (lst_idx+3-1)%3;
					break;
					case M_DSP:
					moveScriptIndex(1);
					break;
				}
				break;
			case 'L':
				switch (menu){
					case M_NEW:
					moveScriptCursor(-1);
					break;
				}
			break;
			case 'D':
				switch (menu){
					case M_NEW:
					moveScriptCursor(32);
					break;
					case M_PRI:
					lst_idx = (lst_idx+1)%3;
					break;
					case M_DSP:
					moveScriptIndex(-1);
					break;
				}
				break;
			case 'R':
				switch (menu){
					case M_NEW:
					moveScriptCursor(-1);
					break;
				}
			break;
			
			// entry
			case 'N':{
				switch (menu){
					case M_PRI:
					m_pri_btns[lst_idx]();
					break;
					case M_NEW:
					if (!size_specified){
						int entered_size = atoi(str_buffer);
						if (newScript(entered_size)){
							strBufferClear();
							size_specified=true;
							buffer_mode = BUFFER_MODE_ALPHA;
						}
					} else {
						submitScript();
						size_specified=false;
						menu=M_PRI;
					}
					break;
				}
			}
			break;

			// back
			case 'B':
			if (menu==M_NEW){
				strBufferRemove();
				if (size_specified){
					scriptBackSpace();
				}
			}
			else if (menu==M_PRI){
				exitCleanly();
			}else{
				menu=M_PRI;
			}
			break;

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

			// other
			default:
			switch(menu){
				case M_NEW:
				if (size_specified){
					if (str_buffer[0]!=0){
					scriptAppend(str_buffer[0]);
					strBufferClear();
					}
				}
			}
		}
		// draw
		drawScreen();

		//for debugging purposes
		std::cout << "BTN: " << c ;
		if (str_buffer[0]!=0){cout << " | Text Buffer: " <<str_buffer;}
		setCursor(1,12);
		cout.flush();
	}

	return 0;
}