#pragma once
#include "Animal.h"
class Dolphin :
    public Animal
{
public:
    eType GetType() override { return eType::Dolphin; }

    void setLegs(unsigned int qty) {
        m_numlegs = qty;
    }

    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;

    void Read(std::ifstream& istream) override;
    void Write(std::ofstream& ostream) override;

protected:
    int m_numlegs{ 0 };
};

