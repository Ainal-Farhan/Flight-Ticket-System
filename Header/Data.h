#ifndef DATA_H_
#define DATA_H_

#include <string>

using namespace std;

class Data{
	private:
		//variable for user data
		string perFirstname;
		string perLastname;
		string perEmail;
		string perEmailext;		//email extension eg: gmail.com, yahoo.com etc
		string perPassword;
		unsigned short int perAge;
		char perGender;

	protected:
		//variable for passenger(s) data from booking class
		int pasNum;
		string *pasName;
		unsigned short int *pasAge;
		char *pasGender;
		string *pasDepart;
		string *pasArrive;
		string *pasFrom;
		string *pasDest;
		string *pasAirline;
		double *pasPrice;
		string *dateBook;

	protected:
		//Variable for the price of ticket
		const int totalTrip;
		string *from;
		string *destination;
		double *price;
		string *depart;
		string *arrive;
		string *airline;
		string timeBook;
		string dateFlight;

	protected:
		//variable for the card data
		int card;
		string *cardBank;
		string *cardNumber;
		int *cardMonthEXP;
		int *cardYearEXP;
		int *cardCVV;

	public:
		Data();
		~Data();

		void setPersonalData(string, string, string, string, string, unsigned short int, char);
		void setDetailsTrip(string [], string [], double [], string [], string [], string []);
		void setPassengerDetails(int , string[], int[], char[], string[], string[], string[], string[], string[], double[], string []);

		void setTimeBook(string);
		void setDateFlight(string);

		void setCardData(int, string[], string[], int[], int[], int[]);

		string getPersonalFirstname() const;
		string getPersonalLastname() const;
		string getPersonalEmail() const;
		char getPersonalGender() const;
		unsigned int getPersonalAge() const;

};

#endif /* DATA_H_ */
