#include "../Header/SaveLoad.h"
#include "../Header/ExceptionHandler.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

SaveLoad::SaveLoad(): pd(0) {}

SaveLoad::~SaveLoad() {}

void SaveLoad::saveRegistration(string _f, string _l, string _e, string _ee, string _p, int _a, char _g){

	fstream fin;
	fstream fout;
	fin.open("Data//PersonalData.txt", ios::in);
	if(!fin.is_open()){
		fin.close();
		pd = 1;
		fout.open ("Data//PersonalData.txt", ios::out);
		fout << "Unique Number,Firstname,Lastname,Age,Gender,Email,Email Extension,Password" << endl;
	}
	else
		fout.open ("Data//PersonalData.txt", ios::app);
	while(!fin.eof()){
		if(fin.get() == '\n'){
			++pd;
		}
	}
	fout << pd << "," << _f << "," << _l << "," << _a << "," << _g << "," << _e << "," << _ee << "," << _p << endl;

	fout.close ();
	fin.close();
}

void SaveLoad::saveCardData(int unique, string _bank, string _numC, int _mm, int _yy, int _cvvN){
	fstream outFile;
	fstream inFile;
	inFile.open("Data//Card Data.txt", ios::in);

	if(!inFile.is_open()){
		inFile.close();
		outFile.open("Data//Card Data.txt", ios::out);
		outFile << "Unique Number,Bank,Card Number,Expired Month,Expired Year,CVV" << endl;
	}
	else
		outFile.open("Data//Card Data.txt", ios::app);

	inFile.close();

	outFile << unique << "," << _bank << "," << _numC << "," << _mm << "," << _yy << "," << _cvvN << endl;

	outFile.close();
}

void SaveLoad::savePassengerDetails(int uniqueN, string _from, string _dest, double _price, string _depart, string _arrive, string _airline, string f,string l, char g, int a, string _t){
	fstream inFile;
	fstream outFile;
	inFile.open("Data//PassengerDetails.txt", ios::in);

	if(!inFile.is_open()){
		inFile.close();
		outFile.open("Data//PassengerDetails.txt", ios::out);
		outFile << "Unique Number,Name,Age,Gender From,Destination,Departure Time,Arrival Time,Price,Airline, Book Time" << endl;
		outFile << uniqueN << "," << f + " " + l << "," << a << "," << g << "," << _from << ","
				<< _dest << "," << _depart << "," << _arrive
				<< "," << _price << "," << _airline << "," << _t << endl;
		outFile.close();
	}
	else{
		outFile.open("Data//PassengerDetails.txt", ios::app);
		outFile << uniqueN << "," << f + " " + l << "," << a << "," << g << "," << _from << ","
				<< _dest << "," << _depart << "," << _arrive << ","
				<< _price << "," << _airline << "," << _t << endl;
		outFile.close();
	}
}

bool SaveLoad::loadCardData(int u){

	fstream inFile;
	inFile.open("Data//Card Data.txt", ios::in);

	char n;
	int count = -1;

	if(!inFile.is_open()){
			return false;
		}

	while(inFile.get(n)){
		if(inFile.eof())
			break;
		else if(n == '\n')
			count++;
	}

	string bank[count];
	string cardNum[count];
	int m[count];
	int y[count];
	int cvv[count];
	int number[count];

	inFile.clear();
	inFile.seekg(0L, ios::beg);
	while(inFile.get(n)){
		if(n == '\n')
			break;
	}

	for(int i = 0; i < count; i++){

		inFile >> number[i];
		inFile.ignore(1, ',');
		getline(inFile, bank[i], ',');
		getline(inFile, cardNum[i], ',');
		inFile >> m[i];
		inFile.ignore(1, ',');
		inFile >> y[i];
		inFile.ignore(1, ',');
		inFile >> cvv[i];
	}
	inFile.close();

	int count1 = 0;

	for(int i = 0; i < count; i++){
		if(number[i] == u)
			count1++;
	}

	if(count1 == 0)
		return false;

	string bank1[count1];
	string cardNum1[count1];
	int m1[count1];
	int y1[count1];
	int cvv1[count1];

	for(int i = 0, j = 0; i < count; i++){
		if(number[i] == u){
			bank1[j] = bank[i];
			cardNum1[j] = cardNum[i];
			m1[j] = m[i];
			y1[j] = y[i];
			cvv1[j] = cvv[i];
			j++;
		}
	}
	setCardData(count1, bank1, cardNum1, m1, y1, cvv1);
	return true;
}

void SaveLoad::loadPersonalData(int &_i, bool login = false, string _email = "", string _password = ""){
	char n;
	int count = -1;

	fstream fin;
	fin.open("Data//PersonalData.txt", ios::in);

	if(!fin.is_open()){
			cout << "Error: File \"" << "Data//PersonalData.txt" << "\" does not exist..." << endl;
		}

	while(fin.get(n)){
		if(fin.eof())
			break;
		else if(n == '\n')
			count++;
	}

	string firstname[count];
	string lastname[count];
	unsigned short int age[count];
	unsigned int number[count];
	char gender[count];
	string email[count];
	string emailext[count];
	string pass[count];

	fin.clear();
	fin.seekg(0L, ios::beg);
	while(fin.get(n)){
		if(n == '\n')
			break;
	}

	for(int i = 0; i < count; i++){
		firstname[i] = "";
		lastname[i] = "";
		email[i] = "";
		emailext[i] = "";
		pass[i] = "";
		age[i] = 0;
		number[i] = 0;

		fin >> number[i];
		fin.ignore(1, ',');
		getline(fin, firstname[i], ',');
		getline(fin, lastname[i], ',');
		fin >> age[i];
		fin.ignore(1, ',');
		fin.get(gender[i]);
		fin.ignore(1, ',');
		getline(fin, email[i], ',');
		getline(fin, emailext[i], ',');
		getline(fin, pass[i], '\n');
	}
	fin.close();

	if(login){
		ExceptionHandler obj;
		_i = obj.loginValidate(_email, _password, firstname, lastname, email, emailext, pass, gender, count, age);
	}else{
		setPersonalData(firstname[_i-1], lastname[_i-1], email[_i-1], emailext[_i-1], pass[_i-1], age[_i-1], gender[_i-1]);
	}

}

void SaveLoad::loadPassengerDetails(int _u){
	fstream inFile;
	inFile.open("Data//PassengerDetails.txt", ios::in);

	if(!inFile.is_open()){
		cout << "There is no passenger data being save at the moment" << endl;
	}
	else{
		int count = -1;
		char n;

		while(inFile.get(n)){
			if(n == '\n')
				count++;
		}

		int _unique[count];
		string name[count];
		int age[count];
		char gender[count];
		string from[count];
		string dest[count];
		string depart[count];
		string arrive[count];
		string airline[count];
		double price[count];
		string timeBook[count];



		inFile.clear();
		inFile.seekg(0L, ios::beg);

		while(inFile.get(n)){
			if(n == '\n')
				break;
		}

		for(int i = 0; i < count; i++){
			inFile >> _unique[i];
			inFile.ignore(1, ',');
			getline(inFile, name[i], ',');
			inFile >> age[i];
			inFile.ignore(1, ',');
			inFile.get(gender[i]);
			inFile.ignore(1, ',');
			getline(inFile, from[i], ',');
			getline(inFile, dest[i], ',');
			getline(inFile, depart[i], ',');
			getline(inFile, arrive[i], ',');
			inFile >> price[i];
			inFile.ignore(1, ',');
			getline(inFile, airline[i], ',');
			getline(inFile, timeBook[i], '\n');

		}inFile.close();

		int count1 = 0;

		for(int i = 0; i < count; i++){
			if(_unique[i] == _u)
				count1++;
		}

		string name1[count1];
		int age1[count1];
		char gender1[count1];
		string from1[count1];
		string dest1[count1];
		string depart1[count1];
		string arrive1[count1];
		string airline1[count1];
		double price1[count1];
		string timeBook1[count1];

		for(int i = 0, j =0; i < count; i++){
			if(_unique[i] == _u){
				name1[j] = name[i];
				age1[j] = age[i];
				gender1[j] = gender[i];
				from1[j] = from[i];
				dest1[j] = dest[i];
				depart1[j] = depart[i];
				arrive1[j] = arrive[i];
				airline1[j] = airline[i];
				price1[j] = price[i];
				timeBook1[j] = timeBook[i];
				j++;
			}
		}

		setPassengerDetails(count1, name1, age1, gender1, depart1, arrive1, from1, dest1, airline1, price1, timeBook1);
	}

}

void SaveLoad::loadDetailsTrip(){
	const int trip = 10;

	string from[trip];
	string destination[trip];
	double price[trip];
	string depart[trip];
	string arrive[trip];
	string airline[trip];

	char c;

	fstream inFile;
	inFile.open("Data//DetailsTrip.txt", ios::in);

	if(!(inFile.is_open()))
		cout << "ERROR: \"Data//DetailsTrip.txt\" does not exist" << endl;

	else{
		for(int i = 0; i < trip; i++){
			while(inFile.get(c)){
				if(c == ':'){
					inFile.get(c);
					break;
				}
			}
			getline(inFile, from[i], '\n');

			while(inFile.get(c)){
				if(c == ':'){
					inFile.get(c);
					break;
				}
			}
			getline(inFile, destination[i], '\n');

			while(inFile.get(c)){
				if(c == 'M'){
					inFile.get(c);
					break;
				}
			}
			inFile >> price[i];
			inFile.ignore(1, '\n');

			while(inFile.get(c)){
				if(c == ':'){
					inFile.get(c);
					break;
				}
			}
			getline(inFile, depart[i], '\n');

			while(inFile.get(c)){
				if(c == ':'){
					inFile.get(c);
					break;
				}
			}
			getline(inFile, arrive[i], '\n');

			while(inFile.get(c)){
				if(c == ':'){
					inFile.get(c);
					break;
				}
			}
			getline(inFile, airline[i], '\n');

			while(inFile.get(c)){
				if(c == '\n')
					break;
			}
			inFile.ignore(1, '\n');
		}
		setDetailsTrip(from, destination, price, depart, arrive, airline);
	}
}

void SaveLoad::printTicket(string _f, string _l, string _from, string _dest, string _airline, string _time, string _date){
	fstream outfile;

		outfile.open("BoardingPass.txt",ios::out);

		for (int i = 0; i < 59; i++)
			outfile << "-";
		outfile << endl;

		outfile << "BOARDING PASS" << endl;
		for (int j = 0; j < 59; j++)
			outfile << "_";
		outfile << endl;

		outfile << "Name of Passenger: ";
		outfile << _f + " " + _l;
		outfile << endl << endl;

		outfile << "From: " << setw(6) << _from << "\tFlight: "
		<< setw(20) << _airline;
		outfile << endl << endl;

		outfile << "To: ";
		outfile << _dest;
		outfile << "\t\tDate: " << setw(12) << _date << "Time: " << _time << endl << endl;

		for (int j = 0; j < 59; j++)
			outfile << "_";
		outfile << endl;

	outfile.close();
}

void SaveLoad::printPNR(){
	fstream outfile;

		outfile.open("Passenger Name Record (PNR).txt",ios::out);

		outfile <<"PNR DETAIL REPORT" << endl;
		outfile << endl;

		outfile << setw(50) << left << "PNR NUMBER : "<<
		"PNR CREATE DATE : " << endl;
		outfile << endl;

		outfile << "Passengers" << endl;
		outfile << setw(12) << left << "First Name " << setw(13) << left
		<< " Last Name " << setw(12) << "DOB" << setw(36) << "CC"
		<< "Comment" << endl;
		outfile << endl << endl;

		outfile << setw(25) << "Form of Payment " << setw(17) << "Number" <<
		setw(11) << "Exp. Date" << setw(20) << "Telephone No. " << setw(10)
		<< "Ext. " << "Location " << endl;

	outfile.close();
}

