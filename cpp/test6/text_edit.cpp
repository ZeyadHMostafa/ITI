#include "text_edit.h"
#include "terminal_io.h"

using namespace std;

extern char str_buffer[];

char* scripts[SCRIPT_COUNT];
int script_sizes[SCRIPT_COUNT];
int current_script_count=0;
int script_index=0;

char* script;
int script_size = 0;

int cursor_pos = 0;

void displayScript(const char* script, int script_size){
	// added text auto wrap for now
	for (int i=0; i<(script_size-1)/32+1; i++){ // rows
		setCursor(1,3+i);
		for (int j=0; j<min(32,script_size-32*i);j++){
			if ((i*32+j)==cursor_pos){setColor(C_BLU);}
			cout << script[i*32+j];
			if ((i*32+j)==cursor_pos){setColor(C_WHT);}
		}
	}
}

void displayTextEditMenu(int mode){
	switch (mode){
		case TEXT_MENU_MODE_NEW:
		{
			setCursor(1,4);
			cout << "Enter Size: " << str_buffer;
			int entered_size = atoi(str_buffer);
			if (entered_size==0 || entered_size>1024){
				setColor(C_RED);
				setCursor(1,5);
				cout<<"Please enter a valid value for the size (1->1024)";
				setColor(C_WHT);
			} else {
				setColor(C_GRN);
				setCursor(1,5);
				cout<<"Size will be specified as: " << entered_size;
				setColor(C_WHT);
			}
			break;
		}

		case TEXT_MENU_MODE_EDIT:
		{
			setCursor(1,1);
			setColor(C_YLW);
			cout << "ENTERING TEXT:";
			setCursor(1,2);
			setColor(C_WHT);
			for (int i=0;i<32;i++){cout << "-";}
			displayScript(script,script_size);
			break;
		}

		case TEXT_MENU_MODE_DISP:
		{
			setCursor(1,1);
			setColor(C_YLW);
			cout << "DISPLAYING TEXT: [" << script_index << "]";
			setCursor(1,2);
			setColor(C_WHT);
			for (int i=0;i<32;i++){cout << "-";}
			displayScript(scripts[script_index],script_sizes[script_index]);
			break;
		}
	}
	cout.flush();
}

void moveScriptCursor(int amount){
	cursor_pos=min(max(cursor_pos+amount,0),script_size-1);
}

void moveScriptIndex(int amount){
	script_index = (script_index+amount+current_script_count)%current_script_count;
}

bool newScript(int entered_size){
	if (entered_size!=0&&entered_size<=1024){
		script_size=entered_size;
		script=new char[script_size];
		// initialize
		for(int i=0;i<script_size;i++){script[i]=' ';}
		return true;
	}
	return false;
}

void submitScript(){
	scripts[current_script_count]=script;
	script_sizes[current_script_count]=script_size;
	current_script_count++;

	cursor_pos=0;
}

void scriptBackSpace(){
	script[cursor_pos]=' ';
	cursor_pos = max(0,cursor_pos-1);
}

void scriptAppend(char c){
	script[cursor_pos]=c;
	if (cursor_pos<script_size-1){
		cursor_pos+=1;
	}
}