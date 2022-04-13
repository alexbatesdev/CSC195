#include <iostream>
#include "MyDerived.h"
using namespace std;

int main()
{
    MyDerived MD = MyDerived();
    MyDerived* MDPtr = new MyDerived();

    cout << MDPtr->AddSomething(3);
    cout << MD.AddSomething(3);
}