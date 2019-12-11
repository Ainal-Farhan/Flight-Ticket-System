#include "../Header/RegisterInOut.h"
#include "../Header/ExceptionHandler.h"
#include "../Header/MainMenu.h"

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>

using namespace std;

RegisterInOut::RegisterInOut(): unique(0) {}

RegisterInOut::~RegisterInOut() {}

void RegisterInOut::setUnique(int _u){unique = _u;}

int RegisterInOut::getUnique()const {return unique;}

void RegisterInOut::registerInOutMenu(){
	unsigned short int option = 0;

	while(option != 3){
		system("cls");
		cout << "\n\n \t\tWelcome To Flight Booking System" << endl << endl;
		cout <<"\t   <><><><><><><><><><><><><><><><><><><><><><><><>\n";
		cout << "\t   Book your Flight ticket(s) at affordable prices!" << endl;
		cout <<"\t   <><><><><><><><><><><><><><><><><><><><><><><><>\n\n";
		cout << "\t\t\t1. Login"		<< endl;
		cout << "\t\t\t2. Register"	<< endl;
		cout << "\t\t\t3. Exit"		<< endl;
		cout << "\n\t\t\toption: ";
		cin >> option;
		cin.ignore();

		switch(option){
			case 1:
				loginMenu();
				break;
			case 2:
				registerMenu();
				break;
			case 3:
				cout << "Thank you for using our program..." << endl;
				Sleep(3000);
				exit(0);
				break;
			default:
				cout << "ERROR: Invalid input!" << endl;
				Sleep(1000);
				cin.ignore();
				break;
		}
	}
}

void RegisterInOut::registerMenu(){
	ExceptionHandler obj;

	string f, l, e, ee, p, p2;
	char g;
	short int a;
	bool save = true;

	while( g != 'y' || g!= 'Y'){
		system("cls");
		cout << "\n\t$~#~#~$ WELCOME TO REGISTRATION MENU $~#~#~$" << endl << endl;

		cout << "\tFirstname\t: ";
		getline(cin, f, '\n');

		cout << "\tLastname\t: ";
		getline(cin, l, '\n');

		try{
			obj.registerName(f, l);

			cout << "\tGender (M /F)\t: ";
			cin >> g;
			cin.ignore();
			obj.registerGender(g);

			cout << "\tAge\t\t: ";
			cin >> a;
			cin.ignore();
			obj.registerAge(a);

			cout << "\tEmail\t\t: ";
			getline(cin, e, '@');
			getline(cin, ee, '\n');
			obj.registerEmail(ee);

			cout << "\tPassword\t: ";
			getline(cin, p, '\n');
			cout << "\tRe-Type Password: ";
			getline(cin, p2, '\n');
			obj.registerPassword(p, p2);
		}
		catch(const char *exceptionString){
			cout << "\n\tERROR: " << exceptionString;
			save = false;
		}
		catch(...){}

		if(save){
			saveRegistration(f, l, e, ee, p, a, g);
			cout << "\n\tYour Registration is success" << endl;
			cout << "Please login ..." << endl;
			Sleep(3000);
			return;
		}
		else{
			cin.clear();
			char option;
			cout << "Back to main menu? (Y/ N)" << endl;

			cout << "Option: ";
			cin >> option;
			cin.ignore();

			switch(option){
				case 'y':
				case 'Y':
					system("cls");
					return;
					break;
				case 'n':
				case 'N':
					system("cls");
					continue;
					break;
				default:
					cout << "ERROR: Invalid Input!" << endl;
					cout << "Going back to Main Menu" << endl;
					Sleep(3000);
					system("cls");
					return;
					break;
				}
		}
	}
}

void RegisterInOut::loginMenu(){
	system("cls");

	string email;
	string password;
	bool success = false;
	int identify;
	cout << "        ";
	for (int i=0;i<90;i++)cout<<'-';
	cout << endl;
	cout << "******************************* WELCOME TO THE SKYTRAVEL SYSTEM *****************************************\n";
	cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< \"Makes Others Fly\" >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	cout << "        ";
	for (int i=0;i<90;i++)cout<<'-';

	cout << "\nPlease Log In First To Use Our System\n" << endl;
	cout << "Email" <<setw(6) << ": ";
	getline(cin, email, '\n');

	cout << "Password : ";
	getline(cin, password, '\n');



	success = loginProcess(identify, email, password);

	if(success){
		cout << "\nLogin Process has succeed..." << endl;
		setUnique(identify);
		Sleep(1000);
		MainMenu obj(unique);
		obj.menu();
	}
	else{
		char option;
		cout << "Back to main menu? (Y/ N)" << endl;
		cout << "Option: ";
		cin >> option;
		cin.ignore();

		switch(option){
			case 'y':
			case 'Y':
				return;
				break;
			case 'n':
			case 'N':
				loginMenu();
				break;
			default:
				cout << "ERROR: Invalid Input!" << endl;
				cout << "Going back to Main Menu" << endl;
				Sleep(1500);
				return;
				break;
		}
	}
}

bool RegisterInOut::loginProcess(int &_identify, string _e, string _p){
	SaveLoad obj;

	try{
		obj.loadPersonalData(_identify, true, _e, _p);
		return true;
	}
	catch(const char* error){
		cout << "ERROR: " << error << endl;
		return false;
	}
	catch(...){
		cout << "Error Happen!!!" << endl;
		return false;
	}
}

void RegisterInOut::logoutMenu(){
	system("cls");

	char option;

	cout << "Log Out from the system? (Y/ N)" << endl;
	cout << "Option: ";
	cin >> option;

	switch(option){
		case 'y':
		case 'Y':
			cout << "Logging Out from the system" << endl;
			Sleep(3000);
			registerInOutMenu();
			break;
		case 'N':
		case 'n':
			return;
			break;
		default:
			cout << "ERROR: Invalid input" << endl;
			return;
			break;
	}
}

