#include "Controller.h"

int Controller::GetNum(string prompt, unsigned short low, unsigned short high) {
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

string Controller::GetString(string prompt) {
	string temp;
	cout << prompt;
	cin >> temp;
	return temp;
}

string Controller::GetLine(string prompt) {
	string temp;
	cout << prompt;
	getline(cin, temp);
	return temp;
}

char Controller::GetChar(string prompt) {
	char temp;
	cout << prompt;
	cin >> temp;
	return temp;
}

bool Controller::GetBool(string prompt, string yes, string no) {
	bool invalid = false;
	do {
	string input = GetString(prompt);
	
		for (int i = 0; i < input.length(); i++) {
			input[i] = toupper(input[i]);
			yes[i] = toupper(yes[i]);
			no[i] = toupper(no[i]);
		}
		if (input == yes) return true;
		else if (input == no) return false;
		else {
			cout << "Please answer " << yes << " or " << no << endl;
			invalid = true;
		}
	} while (invalid);
}