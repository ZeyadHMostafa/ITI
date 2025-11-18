#ifndef MYLIB
#define MYLIB

#include <iostream>
#include <map>
#include <chrono>
#include <thread>
#ifdef _WIN32
	// System headers
	#include <windows.h>

	// Standard library C-style
	#include <wchar.h>
	#include <stdlib.h>
	#include <stdio.h>
	#define CSI "\x1b["
#else
	#define CSI "\e["
#endif

extern std::map<std::string,std::string> color_codes;

// set compatibility
bool EnableVTMode();

// Get Colors on Terminal (Linux & Windows)
bool set_color(std::string color_name);

// Set Cursor on Terminal (Linux & Windows)
void set_cursor(unsigned int x,unsigned int y);

// Clear The Whole Screen (Linux & Windows)
void clear_screen();
// Sleep for Certain Time (Linux & Windows)
void sleep(unsigned int x);

#endif