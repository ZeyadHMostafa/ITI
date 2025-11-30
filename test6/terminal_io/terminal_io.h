#ifndef TERMINAL_IO
#define TERMINAL_IO

#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#ifdef _WIN32
	// System Headers
	#include <windows.h>

	// Wide/windows Characters
	#include <wchar.h>

	// Standard Library and i/o
	#include <stdlib.h>
	#include <stdio.h>

	// user dependant message
	#define USER_MSG "Windows User :("

	// Escape character
	#define CSI "\x1b["

	//keycodes
	#define K_L 37
	#define K_U 38
	#define K_R 39
	#define K_D 40
	#define K_N 13
	#define K_H 36
	#define K_E 27
	#define K_B 8
#else
	// terminal library
	#include <termios.h>

	// user dependnt message
	#define USER_MSG "Linux User <3"

	// Escape character
	#define CSI "\e["

	//keycodes
	#define K_L 0x445B1B
	#define K_R 0x435B1B
	#define K_D 0x425B1B
	#define K_U 0x415B1B
	#define K_H 0x485B1B
	#define K_N 0x0A
	#define K_E 0x1B
	#define K_B 0x7F
#endif

// input text buffer
#define BUFFER_SIZE 20
#define BUFFER_MODE_ALPHA 0
#define BUFFER_MODE_NUMERIC 1

// color codes
#define C_BLK "0;30m"
#define C_RED "0;31m"
#define C_GRN "0;32m"
#define C_YLW "0;33m"
#define C_BLU "0;34m"
#define C_WHT "0;37m"

// initialize terminal
void initTerminal();

// revert_terminal
void revertTerminal();

// switch terminalmodes
void switchTerminalMode(char terminal_mode);

// switch matching code
char matchCode(int code);

void strBufferRemove();

void strBufferAppend(char c);

void strBufferClear();

void strBufferFill(std::string str);

// quick draw for menus with title
void drawMenu(std::string title, std::string * items, int item_count, int btn_idx);

//get button codes
char getButtonCode();

// Get Colors on Terminal (Linux & Windows)
bool setColor(std::string color_code);

// Set Cursor on Terminal (Linux & Windows)
void setCursor(unsigned int x,unsigned int y);

// Clear The Whole Screen (Linux & Windows)
void clearScreen();
// Sleep for Certain Time (Linux & Windows)
void terminalSleep(unsigned int x);

#endif