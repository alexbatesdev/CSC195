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

    std::cout << "\n\n *** End of Prog *** ";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
