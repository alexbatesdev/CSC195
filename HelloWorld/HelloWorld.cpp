// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "I have made changes to this file that is written in a language I do not know!\n";
    
    int iVal1 = -1;
    short shVal2 = 0;
    int iVal3 = -2;

    std::cout << "\nV1 = " << iVal1;
    std::cout << "\nAddress of V1 is " << &iVal1;

    std::cout << "\nV2 = " << shVal2;
    std::cout << "\nAddress of V2 is " << &shVal2;

    std::cout << "\nV3 = " << iVal3;
    std::cout << "\nAddress of V3 is " << &iVal3;

    std::cout << "\n\n !!! diff V1 and V3 = " << (&iVal1 - &iVal3);
    std::cout << "\nsize of(v1) = " << sizeof(iVal1);
    std::cout << "\nsize of(v2) = " << sizeof(shVal2);
    std::cout << "\nsize of(v3) = " << sizeof(iVal3);

    int* ptr = NULL;
    ptr = &iVal1;
    std::cout << "\nValue of ptr = " << ptr;
    std::cout << "\nValue ptr points to = " << *(ptr - 6);

    //*ptr = 5;
    std::cout << "\nValue of iVal1 = " << iVal1;
    
    //*(ptr + 11) = 12345;
    std::cout << "\n\n *** End of Prog *** ";
}