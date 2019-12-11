/*
 * PersonalData.cpp
 *
 *  Created on: 28 Apr 2019
 *      Author: ainal.farhan
 */

#include "../Header/Data.h"

#include <iostream>

using namespace std;

Data::Data(): perFirstname(""), perLastname(""), perEmail(""), perEmailext(""), perPassword(""), perAge(0), perGender('N'), totalTrip(10){
	from = new string[totalTrip];
	destination = new string[totalTrip];
	price = new double[totalTrip];
	depart = new string[totalTrip];
	arrive = new string[totalTrip];
	airline = new string[totalTrip];

	for(int i = 0; i < totalTrip; i++){
		from[i] = "";
		destination[i] = "";
		price[i] = 0;
		depart[i] = "";
		arrive[i] = "";
		airline[i] = "";
	}
}
Data::~Data(){
	delete [] from;
	delete [] destination;
	delete [] price;
	delete [] depart;
	delete [] arrive;
	delete [] airline;
}

void Data::setPersonalData(string f, string l, string e, string ee, string p, unsigned short int a, char g){
	perFirstname	= f;
	perLastname		= l;
	perEmail		= e;
	perEmailext		= ee;
	perPassword		= p;
	perAge			= a;
	perGender		= g;
}

void Data::setDetailsTrip(string _from[], string _dest[], double _price[], string _depart[], string _arrive[], string _airline[]){
	for(int i = 0; i < totalTrip; i++){
		from[i]			= _from[i];
		destination[i]	= _dest[i];
		price[i]		= _price[i];
		depart[i]		= _depart[i];
		arrive[i]		= _arrive[i];
		airline[i]		= _airline[i];
	}
}

void Data::setPassengerDetails(int _pasNum, string _pasName[], int _pasAge[],char _pasGender[], string _pasDepart[], string _pasArrive[],string _pasFrom[], string _pasDest[], string _pasAirline[], double _pasPrice[], string _dateBook[]){
	pasName = new string[_pasNum];
	pasAge = new unsigned short int[_pasNum];
	pasGender = new char[_pasNum];
	pasDepart = new string[_pasNum];
	pasArrive = new string[_pasNum];
	pasFrom = new string[_pasNum];
	pasDest = new string[_pasNum];
	pasAirline = new string[_pasNum];
	pasPrice = new double[_pasNum];
	dateBook = new string[_pasNum];

	pasNum = _pasNum;

	for(int i = 0; i < _pasNum; i++){
		pasName[i] = _pasName[i];
		pasAge[i] = _pasAge[i];
		pasGender[i] = _pasGender[i];
		pasDepart[i] = _pasDepart[i];
		pasArrive[i] = _pasArrive[i];
		pasFrom[i] = _pasFrom[i];
		pasDest[i] = _pasDest[i];
		pasAirline[i] = _pasAirline[i];
		pasPrice[i] = _pasPrice[i];
		dateBook[i] = _dateBook[i];
	}


}

void Data::setTimeBook(string _t){timeBook = _t;}

void Data::setDateFlight(string _d){dateFlight = _d;}

string			Data::getPersonalFirstname()	const{return perFirstname;				}
string			Data::getPersonalLastname()		const{return perLastname;				}
string			Data::getPersonalEmail()		const{return (perEmail+"@"+perEmailext);	}
char			Data::getPersonalGender()		const{return perGender;				}
unsigned int	Data::getPersonalAge()			const{return perAge;					}

void Data::setCardData(int set, string bank[], string cn[], int me[], int ye[], int c[]){
	card = set;

	cardBank = new string[set];
	cardNumber = new string[set];
	cardMonthEXP = new int[set];
	cardYearEXP = new int[set];
	cardCVV = new int[set];

	for(int i = 0; i < set; i++){
		cardBank[i] = bank[i];
		cardNumber[i] = cn[i];
		cardMonthEXP[i] = me[i];
		cardYearEXP[i] = ye[i];
		cardCVV[i] = c[i];
	}
}
