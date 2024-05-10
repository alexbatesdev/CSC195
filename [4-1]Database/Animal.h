#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <fstream>

class Animal
{
public:
	enum class eType {
		Dolphin = 1,
		Bird = 2
	};

protected:
	std::string m_name;
	unsigned int m_lifespan = 42;

public:
	std::string GetName() { return m_name; }
	int GetLifespan() { return m_lifespan; }
	void SetName(std::string val) { m_name = val; }
	void SetLifespan(int lifespan) { m_lifespan = lifespan; }

	virtual eType GetType() = 0;

	virtual void Read(std::ostream& ostream, std::istream& istream);
	virtual void Write(std::ostream& ostream);

	virtual void Read(std::ifstream& istream);
	virtual void Write(std::ofstream& ostream);

	friend std::istream& operator >> (std::istream& istream, Animal& animal);
	friend std::ostream& operator << (std::ostream& ostream, Animal& animal);

	friend std::ifstream& operator >> (std::ifstream& istream, Animal& animal);
	friend std::ofstream& operator << (std::ofstream& ostream, Animal& animal);
};

