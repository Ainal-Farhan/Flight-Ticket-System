#include "../Header/MainMenu.h"

#include <iostream>
#include <Windows.h>

MainMenu::MainMenu():p(Payment()), b(Booking(sl)), sl(SaveLoad()), uniqueNumber(getUnique()){}

MainMenu::MainMenu(int _u): uniqueNumber(_u){}

MainMenu::~MainMenu(){}

void MainMenu::menu(){
	bool a = true;
	int option = 0;

	while(a){
		system("cls");
		cout << "\n\n \t\tWelcome To Flight Booking System" << endl << endl;
		cout <<"\t   <><><><><><><><><><><><><><><><><><><><><><><><>\n";
		cout << "\t   Book your Flight ticket(s) at affordable prices!" << endl;
		cout <<"\t   <><><><><><><><><><><><><><><><><><><><><><><><>\n\n";
		cout << "\t\t\t1. Booking"					<< endl;
		cout << "\t\t\t2. Display Passenger Detail"	<< endl;
		cout << "\t\t\t3. Payment"					<< endl;
		cout << "\t\t\t4. log Out"					<< endl;
		cout << "\n\t\t\toption: ";
		cin >> option;

		switch(option){
			case 1:
				b.dateForFlight(uniqueNumber);
				continue;
				break;
			case 2:
				b.displayPassengerDetails(uniqueNumber);
				continue;
				break;
			case 3:
				p.paymentMenu(uniqueNumber);
				continue;
				break;
			case 4:
				registerInOutMenu();
				continue;
				break;
			default:
				cout << "ERROR: Invalid Input!" << endl;
				Sleep(1000);
				continue;
				break;
		}
	}
}

int MainMenu::getUniqueNumber() const {return uniqueNumber;}
