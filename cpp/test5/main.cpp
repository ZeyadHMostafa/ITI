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

char lst_idx = 0;
char menu=M_PRI;
extern char str_buffer[];

struct Game{
string name = "";
int time_played;
int rating;
};
Game default_game, new_game, all_games[10];
int free_game_idx=0;
int game_idx=0;

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
			drawMenu("Main Menu",menu_items,3,lst_idx);
		}
			
		break;
		case M_NEW:
		{	
			// TODO: this is a temporary work around
			string menu_items[] = {
				"Name: ",
				"Time Played: ",
				"Rating: ",
			};
			string menu_data[] = {
				new_game.name,
				to_string(new_game.time_played),
				to_string(new_game.rating)
			};
			menu_data[lst_idx]=str_buffer;
			for (int i=0; i<3;i++){
				menu_items[i]+=menu_data[i];
			}
			drawMenu("Add Game[" + to_string(free_game_idx) +string("]"),menu_items,3,lst_idx);
			cout.flush();
			
		}
		break;
		case M_DSP:
		{
			// TODO: this is a temporary work around
			string menu_items[] = {
				"Name: ",
				"Time Played: ",
				"Rating: ",
			};
			string menu_data[] = {
				all_games[game_idx].name,
				to_string(all_games[game_idx].time_played),
				to_string(all_games[game_idx].rating)
			};
			for (int i=0; i<3;i++){
				menu_items[i]+=menu_data[i];
			}
			drawMenu("Display Game [" + to_string(game_idx) +string("]"),menu_items,3,22);
			cout.flush();
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

string getGameData(int i){
	string menu_data[] = {
		new_game.name,
		to_string(new_game.time_played),
		to_string(new_game.rating)
	};
	return menu_data[i];
}

void setGameData(int i,string str){
	switch(i){
		case 0:
		new_game.name = str;
		break;
		case 1:
		new_game.time_played =atoi(str.c_str());
		break;
		case 2:
		int x=atoi(str.c_str());
		if (x>0 && x<5){
			new_game.rating = x;
		}
		break;
	}
}

// button functions
void btnNew(){
	menu = M_NEW;
	strBufferFill(getGameData(lst_idx));
}
void btnDisp(){
	if (free_game_idx==0) {return;}
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
				switch (menu){
					case M_NEW:
					setGameData(lst_idx,str_buffer);
					lst_idx = (lst_idx+3-1)%3;
					strBufferFill(getGameData(lst_idx));
					break;
					case M_PRI:
					lst_idx = (lst_idx+3-1)%3;
					break;
					case M_DSP:
					game_idx = (game_idx+free_game_idx-1)%free_game_idx;
					break;
				}
			break;
			case 'D':
			case 'R':
				switch (menu){
					case M_NEW:
					setGameData(lst_idx,str_buffer);
					lst_idx = (lst_idx+1)%3;
					strBufferFill(getGameData(lst_idx));
					break;
					case M_PRI:
					lst_idx = (lst_idx+1)%3;
					break;
					case M_DSP:
					game_idx = (game_idx+1)%free_game_idx;
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
					setGameData(lst_idx,str_buffer);
					// final validation steps
					if (getGameData(0).size()<3){
						break;
					}
					all_games[free_game_idx]=new_game;
					new_game=default_game;
					free_game_idx+=1;
					strBufferFill(getGameData(lst_idx));
					break;
				}
			}
			break;

			// back
			case 'B':
			if (menu==M_NEW){
				strBufferRemove();
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
		}
		// draw
		drawScreen();

		//for debugging purposes
		std::cout << "BTN: " << c ;
		//if (str_buffer[0]!=0){cout << " | Text Buffer: " <<str_buffer;}
		cout.flush();
	}

	return 0;
}