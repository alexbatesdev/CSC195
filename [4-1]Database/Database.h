#pragma once
#include "Animal.h"
class Database
{
public:
	bool Save(Animal& animal);
	bool DisplayAll(std::ostream& ostream);
	bool Empty();

private:
	Animal* Create(Animal::eType type);
};

