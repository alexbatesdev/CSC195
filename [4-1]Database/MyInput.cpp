#include "MyInput.h"
#include <iostream>

using namespace std;

int MyInput::GetUserInt(string prompt, unsigned short low, unsigned short high) {
	int iTemp = 0;

	do {
		cout << prompt << '(' << low << " to " << high << "): ";
		cin >> iTemp;

		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			cout << "\n !!! Improper Input Dipshit !!! \n";
			iTemp = low - 1;
		}

	} while ((iTemp < low) || (iTemp > high));
	return iTemp;
}


string MyInput::GetUserStr(string prompt) {
	string temp;
	cout << prompt;
	cin >> temp;
	return temp;
}