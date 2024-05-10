#include "Model.h"
const std::string filename = "Words.txt";

void Model::run() {
	answer = getWord(c.GetLine("Please name the victim: ")); //Easter egg to make it a crucifiction if you input the name jesus
	cout << h_seed << endl;
	v.title(h_seed);
	start();
	while (playing) {
		char userInput = c.GetChar("Guess: ");
		if (!check(userInput)) lives--;
		v.display(lives, h_seed);
		v.display(inc_guesses);
		v.display(slots);

		if (win() || lives == 0) {
			play_again(win());
		}
	}
}

void Model::start() {
	playing = true;
	lives = 6;
	for (int i = 0; i < 6; i++) {
		inc_guesses[i] = ' ';
	}
	//--------------
	
	slots.clear();
	for (int i = 0; i < answer.length(); i++) {
		slots.push_back('_');
	}
	//---------------
	v.display(lives, h_seed);
	v.display(slots);
}

string Model::getWord(string _seed) {
	ifstream myFile(filename, std::ofstream::out | std::ofstream::app);
	vector<string> words;
	string word;
	if (h_seed == 0) {
		h_seed = seed(_seed);
		srand(h_seed);
	}
	if (myFile.is_open()) {
		while (getline(myFile, word, ' ')) {
			words.push_back(word);
		}
		myFile.close();
		
	}
	int r = rand() % words.size();
	return words[r];
}

int Model::seed(string prompt) {
	int seed = 0;
	for (int i = 0; i < prompt.length(); i++) {
		seed += (int)prompt[i];
	}
	return seed;
}

bool Model::check(char guess) {
	bool safe = false;
	for (int i = 0; i < answer.length(); i++) {
		if (toupper(guess) == answer[i]) {
			slots[i] = guess;
			safe = true;
		}
	}
	if (!safe) inc_guesses[6 - lives] = guess;
	return safe;
}

bool Model::win() {
	int count = 0;
	for (int i = 0; i < slots.size(); i++)
		if (slots[i] != '_') {
			count++;
		}
	if (count == 5) return true;
	else return false;
}

void Model::play_again(bool w_l) {
	if (w_l) v.win();
	else v.lose(answer);
	bool again = c.GetBool("Play again ? [YES / NO] ", "YES", "NO");
	if (again) {
		start();
		answer = getWord("Repeat");
	}
	else if (!again) playing = false;
}