#pragma once
#include "Animal.h"

class Bird :
    public Animal
{
public:
    eType GetType() override { return eType::Bird; }

    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;

    virtual void Read(std::ifstream& istream);
    virtual void Write(std::ofstream& ostream);
protected:
    int m_numwings{ 0 };
};

