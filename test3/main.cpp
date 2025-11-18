#include <iostream>
#include "mylib.h"

#define DELAY_TIME 40*5

using namespace std;

void drawSquare(int s){
	// desired reference image
	// +---+---+
	// |   |   |
	// +---+---+
	// |   |   |
	// +---+---+

	for (int i=0; i<s; i++){
		// add separating line
		setCursor(1,2*i+1);
		for (int j=0;j<s;j++){
			cout<<"+---";
		}
		cout<<"+";

		// add entry line
		setCursor(1,2*i+2);
		for (int j=0;j<s;j++){
			cout<<"|   ";
		}
		cout<<"|";
	}

	// add final line
	setCursor(1,2*s+1);
	for (int j=0;j<s;j++){
		cout<<"+---";
	}
	cout<<"+";
}

void drawMagic(int s){
	int x = (s-1)/2;
	int y = s-1;

	// step forward
	for (int i=1; i<=s*s; i++){

		// print
		setCursor(x*4+2,(s-y-1)*2+2);
		terminalSleep(DELAY_TIME);

		cout << i;
		if (i%s!=0){
			x=(x+1)%s;
			y=(y+1)%s;
		} else{
			y=(y+s-1)%s;
		}
	}
}


// --------------------------------------------------------

int main(){

	int x = 0;
	cout << "Please enter the side length: ";

	// validation check (odd and in range 1-15)
	while ( (x<1) || (x%2==0) || (x>15) ) {
		cin >> x;
	}
	
	initTerminal();
	clearScreen();
	drawSquare(x);
	drawMagic(x);
	terminalSleep(1000);
	cout.flush();
	revertTerminal();
	//TODO: on keyboard interrupt (ctrl-c) 
	//		revert terminal isn't called
	//		messes up terminal

	return 0;
}