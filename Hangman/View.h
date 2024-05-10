#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

class View
{
public:
	void title(int egg);
	void display(std::vector<char> slots);
	void display(int lives, int egg);
	void display(char inc_guesses[]);
	void win();
	void lose(string answer);
protected:
private:
};

