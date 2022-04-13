#pragma once
class Employee
{
//public, protected, and private sections for variables
public:
	const float TAX = 0.1f;
	char name[33];
	char LastInitial;
	int age = 0;
	bool isAdult = false;
	int zipcode;
	float wage;
	short daysWorked;
	static const int maxDaysPerWeek = 7;
	int hoursWorkedPerDay[maxDaysPerWeek];
	int hours = 0;
protected:
	//stuff
private:
	//Things
	

//public protected and private sections for methods (It's a convention thing to keep them in seperate sections)
public:
	Employee(); //Constructor
	~Employee(); //Destructor
	void Read();
	void Write();
protected:
private:
};

