#include <iostream>
#include "mylib.h"

using namespace std;

int main(){
	EnableVTMode();
	set_cursor(5,1);
	set_color("BLUE");
	cout<<"My Program\n";
	set_color("WHITE");
	set_cursor(1,2);
	cout<<"--------------------";
	for (int i=0; i<5;i++){
		set_color("RED");
		set_cursor(1,i+3); cout<<"|";
		set_cursor(20,i+3); cout<<"|";
		set_color("WHITE");
		set_cursor(1,i+2); cout<<"|";
		set_cursor(20,i+2); cout<<"|";
		sleep(1000);
	}
	set_cursor(1,5+2);
	cout<<"--------------------";
	sleep(1000);

	//reset
	set_cursor(8,4);
	cout<<"hello!";
	sleep(1000);
	clear_screen();
	set_cursor(1,1);
	set_color("WHITE");

	// use LRUD Home End ESC

	// set_cursor(10,4);
	// cout<<"New";
	// set_cursor(10,6);
	// cout<<"Display";
	// set_cursor(10,8);
	// cout<<"Exit";
	return 0;
}