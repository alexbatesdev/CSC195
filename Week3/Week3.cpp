#include <iostream>
#include "MyDerived.h"
#include "MyConfig.h"
using namespace std;

int main()
{
    MyDerived MD = MyDerived();
    MyDerived* MDPtr = new MyDerived();

    cout << MDPtr->AddSomething(3);
    cout << MD.AddSomething(3);

    Config myConf;
    myConf.something = 3;
    myConf.thing = 42;

    Config* conf[2];
    conf[0] = new Config;
    conf[1] = new Config;

    conf[0]->something = 6;

    int* ptr = new int;
    
    *ptr = 5;
    cout << '\n' << &ptr << ' ' << ptr << ' ' << *ptr;
}