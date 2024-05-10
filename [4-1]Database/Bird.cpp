#include "Bird.h"
void Bird::Read(std::ostream& ostream, std::istream& istream)
{
	Animal::Read(ostream, istream);

	ostream << "Enter Wings: ";
	istream >> m_numwings;
}
void Bird::Write(std::ostream& ostream)
{
	Animal::Write(ostream);

	ostream << "Num of wings: " << m_numwings << std::endl;
}

void Bird::Read(std::ifstream& istream)
{
	Animal::Read(istream);
	istream >> m_numwings;
}

void Bird::Write(std::ofstream& ostream)
{
	Animal::Write(ostream);
	ostream << m_numwings << std::endl;
}