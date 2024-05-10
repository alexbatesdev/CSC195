#pragma once
#include <string>
#include <iostream>
using namespace std;
class Controller
{
public:
	int GetNum(string prompt, unsigned short low, unsigned short high);
	string GetString(string prompt);
	string GetLine(string prompt);
	char GetChar(string prompt);
	bool GetBool(string prompt, string yes, string no);
private:
protected:
};