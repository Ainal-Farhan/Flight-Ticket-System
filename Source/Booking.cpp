#include "../Header/Booking.h"
#include "../Header/Data.h"
#include "../Header/MainMenu.h"
#include "../Header/ExceptionHandler.h"
#include "../Header/Payment.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

Booking::Booking(SaveLoad &obj): s(obj), pm(Payment()), uniqueNum(0){}
Booking::Booking(): s(SaveLoad()), pm(Payment()), uniqueNum(0){}

Booking::~Booking(){}

void Booking::bookingMenu(){

}

void Booking::dateForFlight(int _u){
	uniqueNum = _u;

	ExceptionHandler obj;

	system("cls");

	int day;
	int month;
	int year;
	bool valid = false;

	string date;


	try{
		cin.ignore();
		cout << "\tDate:" << endl;
		cout << "\tDay\t: ";
		cin >> day;
		cout << "\tMonth\t: ";
		cin >> month;
		cout << "\tYear\t: ";
		cin >> year;

		valid = obj.dateValidator(day, month, year);

		if(valid){
			stringstream ss;
			ss << day << "/" << month << "/" << year;
			date = ss.str();
			setDateFlight(date);
			detailsTrip();
		}
	}
	catch(const char *error){
		cout << "ERROR: " << error << endl;
		valid = false;
		cout << "Back to main menu..." << endl;
		Sleep(1000);
	}
	catch(...){
		valid = false;
		cout << "Back to main menu..." << endl;
		Sleep(1000);
	}
}

void Booking::categoryPassenger(int opt){
	system("cls");

	cout << "\t\tFrom -> Destination" << endl;
	cout << "\t----------------------------------" << endl;
	cout << "\t----------------------------------" << endl;
	cout << "\t\t" << from[opt] << " -> " << destination[opt] << "[" << opt+1 << "]" << endl;
	cout << "\t    **********************" << endl;
	cout << "\tDeparture\t: " << depart[opt] << endl;
	cout << "\tArrival\t\t: " << arrive[opt] << endl;
	cout << "\tAirline\t\t: " << airline[opt] << endl;
	cout << "\t\tPrice" << endl;
	cout << "\t      *********" << endl;
	cout << "\t(Child)\t\t: RM " << fixed << showpoint << setprecision(2) <<  (0.9 * price[opt]) << endl;
	cout << "\t(Teenager)\t: RM " << fixed << showpoint << setprecision(2) <<  (0.95 * price[opt]) << endl;
	cout << "\t(Adult)\t\t: RM " << fixed << showpoint << setprecision(2) <<  price[opt] << endl;
	cout << "\t(Senior)\t: RM " << fixed << showpoint << setprecision(2) <<  (0.75 * price[opt]) << endl;
	cout << "\t----------------------------------" << endl;
	cout << "\t----------------------------------" << endl << endl;

	int option;
	cout << "\t\t><><><>Category of Passenger<><><><" << endl;
	cout << "\t***************************************************" << endl;
	cout << "\t* Child\t\t\t->\t[1]\t(0 - 12)  *"
			"\n\t* Teenager\t\t->\t[2]\t(13 - 18) *"
			"\n\t* Adult\t\t\t->\t[3]\t(19 - 60) *"
			"\n\t* Senior Citizen\t->\t[4]\t(61++)    *\n";
	cout << "\t***************************************************" << endl;

	cout << "\tCategory of Passenger >> ";
	cin  >> option;

	switch(option){
		case 1:
			detailsPassenger((0.9 * price[opt]), opt);
			break;
		case 2:
			detailsPassenger((0.95 * price[opt]), opt);
			break;
		case 3:
			detailsPassenger(price[opt], opt);
			break;
		case 4:
			detailsPassenger((0.75 * price[opt]), opt);
			break;
		default:
			cout << "ERROR: Invalid Input!" << endl;
			cout << "Going back to previous menu..." << endl;
			Sleep(1500);
			break;
	}
}

void Booking::detailsTrip(){
	system("cls");
	int option;

	loadDetailsTrip();

	cout << "\t\tFrom -> Destination" << endl;
	cout << "\t----------------------------------" << endl;
	cout << "\t----------------------------------" << endl;
	for(int i = 0; i < 10; i++){
		cout << "\t\t" << from[i] << " -> " << destination[i] << "[" << i+1 << "]" << endl;
		cout << "\t    **********************" << endl;
		cout << "\tDeparture\t: " << depart[i] << endl;
		cout << "\tArrival\t\t: " << arrive[i] << endl;
		cout << "\tAirline\t\t: " << airline[i] << endl;
		cout << "\t\tPrice" << endl;
		cout << "\t      *********" << endl;
		cout << "\t(Child)\t\t: RM " << fixed << showpoint << setprecision(2) <<  (0.9 * price[i]) << endl;
		cout << "\t(Teenager)\t: RM " << fixed << showpoint << setprecision(2) <<  (0.95 * price[i]) << endl;
		cout << "\t(Adult)\t\t: RM " << fixed << showpoint << setprecision(2) <<  price[i] << endl;
		cout << "\t(Senior)\t: RM " << fixed << showpoint << setprecision(2) <<  (0.75 * price[i]) << endl;
		cout << "\t----------------------------------" << endl;
	}cout << "\t----------------------------------" << endl;

	cout << setw(20) << "\n\tTrip " << ">> ";
	cin  >> option;

		switch(option){
			case 1:
				categoryPassenger(option - 1);
				break;
			case 2:
				categoryPassenger(option - 1);
				break;
			case 3:
				categoryPassenger(option - 1);
				break;
			case 4:
				categoryPassenger(option - 1);
				break;
			case 5:
				categoryPassenger(option - 1);
				break;
			case 6:
				categoryPassenger(option - 1);
				break;
			case 7:
				categoryPassenger(option - 1);
				break;
			case 8:
				categoryPassenger(option - 1);
				break;
			case 9:
				categoryPassenger(option - 1);
				break;
			case 10:
				categoryPassenger(option - 1);
				break;
			default:
				cout << "ERROR: Invalid Input!" << endl;
				cout << "Going back to previous menu..." << endl;
				Sleep(1500);
				break;
		}
}

void Booking::detailsPassenger(double _price, int opt){
	string _f;
	string _l;
	int _a;
	char _g;
	int choice;

	int option;

	ExceptionHandler obj;

	cout << "\n\t\t><><><>Details of Passenger<><><><" << endl;
	cout << "\t\t-^-v-^-v-^-v-^-v-^-v-^-v-^-v-^-v-^" << endl;
	cout << endl << endl;

	cout << "\tThe passenger is the account holder or another person?" << endl;
	cout << "\tAnother Person [1] or Account Holder [2]" << endl;
	cout << "\t\t>> ";
	cin  >> option;

	if(option == 1){
		cin.ignore();

		cout << "\n\tFirstname    : ";
		getline(cin, _f, '\n');

		cout << "\tLastname     : ";
		getline(cin, _l, '\n');

		try{
			obj.registerName(_f, _l);

			cout << "\tGender (M /F): ";
			cin >> _g;
			cin.ignore();
			obj.registerGender(_g);

			cout << "\tAge" << right << setw(12) << " : ";
			cin  >> _a;
			cin.ignore();
			obj.registerAge(_a);
		}
		catch(const char *exceptionString){
			cout << "\n\tERROR: " << exceptionString;
			cout << "Going back to Main menu...";
			Sleep(1000);
			return;
		}
		catch(...){}
	}
	else if(option == 2){
		loadPersonalData(uniqueNum, false, "", "");
		_f = getPersonalFirstname();
		_l = getPersonalLastname();
		_g = getPersonalGender();
		_a = getPersonalAge();
	}
	else{
		cout << "ERROR: Invalid Input!" << endl;
		cout << "Going back to previous menu..." << endl;
		Sleep(1500);
		return;
	}
	if((option == 1) || (option == 2)){
		time_t curr_time;
		time(&curr_time);
		string tBook = asctime(localtime(&curr_time));

		int length = tBook.find('\n');
		tBook.erase(length, 1);

		setTimeBook(tBook);
		display(_price, opt, _f, _l, _g, _a, tBook);

		cout << "\n\nSave the data?" << endl;
		cout << "Yes [1] or No [2]" << endl;
		cout << "\t>> ";
		cin  >> choice;

		if(choice == 1){
			cout << "Saving the data..." << endl;
			Sleep(500);
			cout << "Proceed to payment" << endl;
			Sleep(500);
			pm.setPrice(price[opt]);
			savePassengerDetails(uniqueNum, from[opt], destination[opt], price[opt], depart[opt], arrive[opt], airline[opt], _f, _l, _g, _a, tBook);
			printTicket(_f, _l, from[opt], destination[opt], airline[opt], depart[opt], dateFlight);
			pm.paymentMenu(uniqueNum);
		}
		else{
			cout << "Back to main menu..." << endl;
			Sleep(1000);
		}
	}
}

void Booking::display(double _price, int _opt, string f, string l, char g, int a, string t){

	system("cls");
	cout << "*~~~~~~~~~~~~~~~~~~~~~Details~~~~~~~~~~~~~~~~~~~~~*" << endl;
	cout << endl << endl;
	cout << "##################################################" << endl;
	cout << "# " << left << setw(15) << "TIME"			<<	": " << setw(30) << t					<< "#" << endl;
	cout << "# " << left << setw(15) << "FIRST NAME"	<<	": " << setw(30) << f					<< "#" << endl;
	cout << "# " << left << setw(15) << "LAST NAME"		<<	": " << setw(30) << l					<< "#" << endl;
	cout << "# " << left << setw(15) << "GENDER"		<<	": " << setw(30) << g					<< "#" << endl;
	cout << "# " << left << setw(15) << "AGE"			<<	": " << setw(30) << a					<< "#" << endl;
	cout << "# " << left << setw(15) << "DATE"			<<	": " << setw(30) << dateFlight			<< "#" << endl;
	cout << "# " << left << setw(15) << "FROM"			<<	": " << setw(30) << from[_opt]			<< "#" << endl;
	cout << "# " << left << setw(15) << "TO"			<<	": " << setw(30) << destination[_opt]	<< "#" << endl;
	cout << "# " << left << setw(15) << "DEPARTURE"		<<	": " << setw(30) << depart[_opt]		<< "#" << endl;
	cout << "# " << left << setw(15) << "ARRIVAL"		<<	": " << setw(30) << arrive[_opt]		<< "#" << endl;
	cout << "# " << left << setw(15) << "AIRLINE"		<<	": " << setw(30) << airline[_opt]		<< "#" << endl;
	cout << "##################################################" << endl;
}

void Booking::displayPassengerDetails(int _u){
	uniqueNum = _u;
	system("cls");

	loadPassengerDetails(_u);
	if(pasNum > 0){
		string deco1;
		string deco2;

		deco1.assign(156, '*');
		deco2.assign(156, '-');

		cout << "Passenger Details:" << endl;
		cout << deco1 << endl;
		cout << left << setw(35) << "NAME" << setw(5) << "AGE" << setw(9) << "GENDER" << setw(16) << "DEPARTURE TIME"
					 << setw(14) << "ARRIVAL TIME" << setw(8) << "FROM" << setw(14) << "Destination"
					 << setw(18) << "AIRLINE" << setw(12) << "Price (RM)" << setw(25) << "BOOKING TIME" << endl;
		cout << deco1 << endl;
		for(int i = 0; i < pasNum; i++){
			cout << deco2 << endl;
			cout << left << setw(35) << pasName[i] << setw(5) << pasAge[i] << setw(9) << pasGender[i]
				 << setw(16) << pasDepart[i] << setw(14) << pasArrive[i] << setw(8) << pasFrom[i]
				 << setw(14) << pasDest[i] << setw(18) << pasAirline[i] << setw(12) << fixed
				 << showpoint << setprecision(2) << pasPrice[i] << setw(25) << dateBook[i] << endl;
			cout << deco2 << endl;
		}
		cout << deco1 << endl;
		cout << deco1 << endl;
		cout << endl;
		system("pause");
	}
	else{
		cout << "You haven\'t book any ticket..." << endl;
		cout << endl;
		system("pause");
	}
}
