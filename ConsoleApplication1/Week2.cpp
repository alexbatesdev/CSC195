// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Employee.h"
#include <iostream>
using namespace std;

int main()
{

    Employee workers[5];
    //(sizeof(workers)/sizeof(workers[0])); Gets the size of the array

    Employee* empPtr = new Employee();
    int* intPtr = new int;
    cout << '\n' << sizeof(Employee);
    
    empPtr->age = 32;
    cout << '\n' << *intPtr;
    *intPtr = 3;
    
    void* ptr = malloc(10);

    int somevalue = 1;

    /*for (int count = 0; count < size(workers); count++) {
        workers[count].Read();
    }
    for (int count = 0; count < size(workers); count++) {
        workers[count].Write();
    }

    cout << "\n\n ** End of Program **";*/
}