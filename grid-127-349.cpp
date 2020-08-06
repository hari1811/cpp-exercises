//Name : K Haripriya , Employee ID : 127349

#include <iostream>
#include <windows.h>  
using namespace std;


class GRID_STRING {
	char* input_string;
	int len;

private:

	void printString() {
		int i;
		for (i = 0; i < len; i++) {
			cout << input_string[i] << " ";
		}
		cout << endl;
	}

	void printReverse() {
		int i;
		if (len > 1) {
			for (i = len - 1; i >= 0; i--) {
				cout << (char)input_string[i] << " ";
			}
			cout << endl;
		}
	}

	void printSides() {
		int i;
		if (len > 2) {
			for (i = 1; i < len - 1; i++) {
				cout << input_string[i];
				cout << string((len - 2) * 2 + 1, ' ');
				cout << input_string[len - 1 - i] << endl;
			}
		}
	}

public:

	GRID_STRING(char* input) : input_string(input), len(strlen(input)) {
	}

	//Member function to print the grid
	void printGrid() {
		
		system("Color 74"); //changing print and background color
		printString();
		printSides();
		printReverse();
	}

};



void main(int argc, char* argv[]){

	//creating GRID_STRING object
	GRID_STRING inpString(argv[1]);

	//printing the grid
	inpString.printGrid();
}

