#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>

#include "View.h"
#include "Controller.h"

using namespace std;

class Model
{
public:
	int lives = 6;
	vector<char> slots;
	char inc_guesses [5];
	string answer;
private:
	View v;
	Controller c;
	bool playing;
	int h_seed = 0;
protected:
	// ///////////////////////////////
public:
	void run();
	void start();
private:
	string getWord(string _seed);
	int seed(string prompt);
	bool check(char guess);
	bool win();
	void play_again(bool w_l);
protected:
	

};

