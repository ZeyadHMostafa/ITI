#ifndef TEXT_EDIT
#define TEXT_EDIT

#define SCRIPT_COUNT 10

#define TEXT_MENU_MODE_NEW 0
#define TEXT_MENU_MODE_EDIT 1
#define TEXT_MENU_MODE_DISP 2

// Displays a single script
void displayScript(const char* script, int script_size);

// Displays script menu in both modes
void displayTextEditMenu(int mode);

// move the cursor in edit menu
void moveScriptCursor(int amount);

// move in script list
void moveScriptIndex(int amount);

// create new empty script for modification
bool newScript(int entered_size);

// add script to script list
void submitScript();

// backspace implementation
void scriptBackSpace();

// text append implementation
void scriptAppend(char c);

#endif