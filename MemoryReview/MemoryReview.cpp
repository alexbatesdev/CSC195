#include <iostream>
using namespace std;

struct Person
{
	char name[32];
	int id;
};

int Square(int num) {
	num = num * num;
	return num;
}

int Double(int* num) {
	*num = *num * 2;
	return *num;
}

int main()
{
	cout << "Text";
	// ** REFERENCE **
	// 
	// declare an int variable and set the value to some number (less than 10)
	// declare a int reference and set it to the int variable above
	int value = 9;
	int &ref = value;
	// output the int variable
	cout << '\n' << value;
	// set the int reference to some number
	ref = 4;
	// output the int variable
	cout << '\n' << value;
	// what happened to the int variable when the reference was changed? (insert answer)
	cout << '\n' << "It changed, wow! It's almost as if they refer to the same location!";

	// output the address of the int variable
	cout << '\n' << &value;
	// output the address of the int reference
	cout << '\n' << &ref;
	// are the addresses the same or different? (insert answer)
	cout << '\n' << "They are the exact same, ref is just another alias for value";
	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	Square(value);
	// output the int variable to the console
	cout << '\n' << value;
	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""

	// ** POINTER VARIABLE **
	// 
	// declare an int pointer, set it to nullptr (it points to nothing)
	// set the int pointer to the address of the int variable created in the REFERENCE section
	int* pointer = nullptr;
	pointer = &ref;
	// output the value of the pointer
	cout << '\n' << pointer;
	// what is this address that the pointer is pointing to? (insert answer)
	cout << '\n' << "The pointer is pointing to the address in memory that ref is at";
	// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << '\n' << *pointer;

	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter (i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(pointer);
	// output the dereference pointer
	cout << '\n' << *pointer;
	// output the int variable created in the REFERENCE section
	cout << '\n' << value;
	// did the int variable's value change when using the pointer?
	cout << '\n' << "Yes";
	// ** ALLOCATION/DEALLOCATION **
	//
	// create an int pointer that points at an int allocated on the heap, set the allocated int value to some number
	int* pointer1 = (int*)malloc(10);
	// output the pointer value, this should be the address of the int allocated on the heap
	cout << '\n' << pointer1;
	// output the dereference pointer
	cout << '\n' << *pointer1;
	// deallocate the int pointer to free up the memory
	delete pointer1;
	// create an int pointer that points at an array of ints allocated on the heap, the array size should be 4-6
	int* fiveGum = new int [5];
	// use a for loop and set each int in the array to a random number (use => rand() % 10 to get a random number
	for (int count = 0; count < 5; count++) {
		fiveGum[count] = rand() % 10;
	}
	// use a for loop and output each of the ints in the array
	for (int count = 0; count < 5; count++) {
		cout << '\n' << fiveGum[count];
	}
	// use a for loop and output the address of each of the ints in the array
	for (int count = 0; count < 5; count++) {
	cout << '\n' << &fiveGum[count];
	}
	// deallocate the int pointer to free up the memory block (remember it's an array)
	delete[] fiveGum;

	// ** STRUCTURE **
	//
	// create a Person pointer that points at an array of Persons allocated on the heap, the array size should be 2
	Person* people = new Person[2];
	// read in a name from the console and set it to the person name, do this for the id also, do this for both Persons
	for (int count = 0; count < 2; count++) {
		cout << '\n' << "Enter Name: ";
		cin >> people[count].name;
		cout << '\n' << "Enter ID: ";
		cin >> people[count].id;
	}
	// use a for loop and output the name and id of each person in the array 
	for (int count = 0; count < 2; count++) {
		cout << '\n' << people[count].name;
	}
	// deallocate the person pointer to free up the memory block (remember it's an array)
	delete [] people;
}