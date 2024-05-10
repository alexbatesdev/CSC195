// [4-1]Database.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "MyInput.h"
#include "Animal.h"
#include "Dolphin.h"
#include "Bird.h"
#include "Database.h"

int main()
{
	MyInput input;
	Animal* myAnimal = NULL;
	Database db;

	bool quit = false;
	int iMenu = 0;
	int iSubMenu = 0;
	do	{
		cout << '\n' << "1) Create";
		cout << '\n' << "2) Display All";
		cout << '\n' << "3) Display Name";
		cout << '\n' << "4) Clear";
		cout << '\n' << "5) Quit";
		cout << '\n' << "Enter Selection: ";

		//cin >> iMenu;
		//if (!cin.good())
		//{
		//	cin.clear();
		//	cin.ignore();
		//}

		iMenu = input.GetUserInt("Please enter a selection ", 1, 5);

		//switch here
		switch (iMenu) {
			case 1:
				// Add Record - 1
				cout << '\n' << "1) Dolphin";
				cout << '\n' << "2) Bird";
				iSubMenu = input.GetUserInt("\nPlease enter a selection ", 1, 2);

				switch (iSubMenu) {
					case (int)Animal::eType::Dolphin:
						//Dolphin* tempDolphin = new Dolphin();
						//tempDolphin->setLegs(input.GetUserInt("\nEnter Number of legs ", 0, 8));
						myAnimal = new Dolphin;
						//myAnimal = tempDolphin;
						break;

					case (int)Animal::eType::Bird:
						myAnimal = new Bird;
						break;
				} // inner switch end
				//myAnimal->SetLifespan(input.GetUserInt("\nEnter Lifespan ", 1, 100));
				//myAnimal->SetName(input.GetUserStr("\nEnter Name: "));
				if (myAnimal != NULL) {
					cin >> *myAnimal;
					cout << *myAnimal;
					db.Save(*myAnimal);
				}
				break;
			case 2:
				db.DisplayAll(cout);
					break;
			case 3:
				cout << "lol";
				break;
			case 4:
				db.Empty();
				break;
			case 5:
				quit = true;
				break;
		} //outer switch

		if (myAnimal != NULL) {
			delete myAnimal;
			myAnimal = NULL;
		}
	} while (!quit); //end while
}