#include "Database.h"
#include "Dolphin.h"
#include "Bird.h"
const std::string filename = "testFile.txt";
/////////////////////////////////////////////////////////////
bool Database::Save(Animal& animal) {
	std::ofstream myFile(filename, std::ofstream::out | std::ofstream::app);

	if (myFile.is_open()) {
		myFile << animal;
		myFile.close();
		return true;
	}

	return false;
}

bool Database::Empty() {
	std::ofstream myFile(filename, std::ofstream::trunc);

	if (myFile.is_open()) {
		myFile.close();
		return true;
	}

	return false;
}
///////////////////////////////////////
bool Database::DisplayAll(std::ostream& stream) {
	std::ifstream file(filename);
	int type = 0;
	Animal* animal;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> type;
			animal = Create((Animal::eType)type);

			if (file.fail()) {
				file.close();
				return true;
			}

			file >> *animal;
			stream << *animal;
		}
	}
}
/////////////////////////////////////
Animal* Database::Create(Animal::eType type) {
	switch (type)
	{
	case Animal::eType::Dolphin:
		return new Dolphin;
		break;
	case Animal::eType::Bird:
		return new Bird;
		break;
	default:
		return nullptr;
		break;
	}
}