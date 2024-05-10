// Week4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void addbyref(int& ref) {
    ref = ref + 1;
}

void addbyval (int val) {
    val = val + 1;
}

void addbyptr(int* ptr) {
    ptr = ptr + 1;
}

int main()
{
    std::cout << "Hello World!\n";
    int ival = 5;
    cout << ival << '\n';

    addbyval(ival);
    cout << ival << '\n';
    addbyref(ival);
    cout << ival << '\n';
    addbyptr(&ival);
    cout << ival << '\n';

    ////////////////////////////////////////
    long* iptr;
    while (true) {
        iptr = new long; /// Memory leak loop
        cout << "loop";
    }
    
    *iptr = 6;
    cout << *iptr;

    delete iptr;

    void* ptr = malloc(10); //allocates nutyped memory of this amount of bytes
    free(ptr);
}

