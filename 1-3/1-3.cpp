// 1-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "Welcome to da app";
    string FirstName;
    cout << "\nEnter name: ";
    cin >> FirstName;

    char LastInitial;
    cout << "Enter last initial: ";
    cin >> LastInitial;

    short age;
    cout << "Enter Age: ";
    cin >> age;

    bool isAdult;
    if (age >= 18) {
        isAdult = true;
    }
    else {
        isAdult = false;
    }

    int zipcode;
    cout << "Enter Zipcode: ";
    cin >> zipcode;

    float wage;
    cout << "Enter wage: ";
    cin >> wage;

    short daysWorked;
    cout << "Enter days worked this week: ";
    cin >> daysWorked;

    int hoursWorkedPerDay[7];
    for (int i = 0; i < daysWorked; i++) {
        cout << "Enter hours worked on day " << (i+1) << ": ";
        cin >> hoursWorkedPerDay[i];
    }
    const float TAX = 0.1f;

    cout << "\nName: " << FirstName;
    cout << "\nLast Initial: " << LastInitial;
    if (isAdult) {
        cout << "\nAge: " << age << " (Adult)";
    }
    else {
        cout << "\nAge: " << age;
    }
    cout << "\nZipcode: " << zipcode;
    cout << "\nWage: " << wage;
    cout << "\nDays Worked: " << daysWorked;

    int hours = 0;
    //Hours worked per day
    for (int i = 0; i < daysWorked; i++) {
        cout << "\nHours worked on day " << (i+1) << ": " << hoursWorkedPerDay[i];
        hours += hoursWorkedPerDay[i];
    }
    //PERSON work [Total Hours Worked] at [WAGE] per hour
    cout << "\n" << FirstName << " worked " << hours << " hours at $" << wage << " per hour";
    //Gross (before tax
    cout << "\nGross Income: $" << (hours * wage);
    //Net (after tex
    cout << "\nNet Income: $" << ((hours * wage) - ((hours * wage) * TAX));
    //Tax
    cout << "\nTaxxed Income: $" << ((hours * wage) * TAX);

    cout << "\n\n ** End of Program ** ";


}