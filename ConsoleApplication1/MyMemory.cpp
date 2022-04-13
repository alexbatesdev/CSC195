#include <iostream>
#include "Employee.h"
using namespace std;

void something() {
	while (true) {
		Employee Bob;

		cout << &Bob;

		Employee* empPtr;
		empPtr = new Employee(); //Heap memory

		cout << &empPtr;
		cout << empPtr;

		delete empPtr;
	}

}
