#include "terminal_io.h"
using namespace std;

// Buffer "Class"
// --------------------------------------------------------------------------

char str_buffer[BUFFER_SIZE];
char str_buffer_idx=0;

// remove last character
void strBufferRemove(){
	if (str_buffer_idx!=0){
		str_buffer_idx-=1;
		str_buffer[str_buffer_idx]=0;
	}
}

// append character at current index
void strBufferAppend(char c){
	if (str_buffer_idx<BUFFER_SIZE-1){
		str_buffer[str_buffer_idx]=c;
		str_buffer_idx+=1;
		str_buffer[str_buffer_idx]=0;
	}
}

// clear all characters
void strBufferClear(){
	str_buffer_idx=0;
	str_buffer[str_buffer_idx]=0;
}

// fill buffer with data from string
void strBufferFill(string str){
	str.copy(str_buffer,20);
	str_buffer[str.size()]=0;
	str_buffer_idx=str.size();
}

// --------------------------------------------------------------------------

// used to standardize keyboard special input characters
// not sure if it's necessary though
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