#ifndef SAVELOAD_H_
#define SAVELOAD_H_

#include "Data.h"

#include <iostream>
#include <fstream>

using namespace std;

class SaveLoad: public Data{
private:
	unsigned int pd;	//Personal Data counter
public:
	SaveLoad();
	~SaveLoad();
	void saveRegistration(string, string, string, string, string, int, char);
	void saveCardData(int, string, string, int, int, int);
	void savePassengerDetails(int, string, string, double, string, string, string, string, string, char, int, string);

	void loadPersonalData(int &, bool, string , string );
	bool loadCardData(int);
	void loadPassengerDetails(int);

	void loadDetailsTrip();

	void printTicket(string, string, string, string, string, string, string);
	void printPNR();
};


#endif /* SAVELOAD_H_ */
