#include "Employee.h"
#include <string.h>
#include <iostream>
using namespace std;
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
Employee::Employee() {
	memset(this->name, '\0', sizeof(this->name));
}
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
Employee::~Employee() {
    // Clean Up
}
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void Employee::Read() {
	// Put read code here
	// Pretty much just recieving input
    cout << "\nEnter name: ";
    cin >> this->name;

    
    cout << "Enter last initial: ";
    cin >> this->LastInitial;

    
    cout << "Enter Age: ";
    cin >> this->age;

    
    if (this->age >= 18) {
        this->isAdult = true;
    }
    else {
        this->isAdult = false;
    }

    cout << "Enter Zipcode: ";
    cin >> this->zipcode;

    cout << "Enter wage: ";
    cin >> this->wage;

    cout << "Enter days worked this week: ";
    cin >> this->daysWorked;

    if (this->daysWorked > this->maxDaysPerWeek)

    for (int i = 0; i < this->daysWorked; i++) {
        cout << "Enter hours worked on day " << (i + 1) << ": ";
        cin >> this->hoursWorkedPerDay[i];
    }
}
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void Employee::Write() {
    cout << "\nName: " << this->name;
    cout << "\nLast Initial: " << this->LastInitial;
    if (this->isAdult) {
        cout << "\nAge: " << this->age << " (Adult)";
    }
    else {
        cout << "\nAge: " << this->age;
    }
    cout << "\nZipcode: " << this->zipcode;
    cout << "\nWage: " << this->wage;
    cout << "\nDays Worked: " << this->daysWorked;

    //Hours worked per day
    for (int i = 0; i < this->daysWorked; i++) {
        cout << "\nHours worked on day " << (i + 1) << ": " << this->hoursWorkedPerDay[i];
        hours += this->hoursWorkedPerDay[i];
    }
    //PERSON work [Total Hours Worked] at [WAGE] per hour
    cout << "\n" << this->name << " worked " << this->hours << " hours at $" << wage << " per hour";
    //Gross (before tax
    cout << "\nGross Income: $" << (this->hours * this->wage);
    //Net (after tex
    cout << "\nNet Income: $" << ((this->hours * this->wage) - ((this->hours * this->wage) * this->TAX));
    //Tax
    cout << "\nTaxxed Income: $" << ((this->hours * this->wage) * this->TAX) << "\n\n";
}