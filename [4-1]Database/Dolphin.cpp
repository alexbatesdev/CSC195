#include "Dolphin.h"
void Dolphin::Read(std::ostream& ostream, std::istream& istream)
{
	Animal::Read(ostream, istream);

	ostream << "Enter Legs: ";
	istream >> m_numlegs;
}
void Dolphin::Write(std::ostream& ostream)
{
	Animal::Write(ostream);

	ostream << "Num of legs: " << m_numlegs << std::endl;
}

void Dolphin::Read(std::ifstream& istream)
{
	Animal::Read(istream);
	istream >> m_numlegs;
}

void Dolphin::Write(std::ofstream& ostream)
{
	Animal::Write(ostream);
	ostream << m_numlegs << std::endl;
}