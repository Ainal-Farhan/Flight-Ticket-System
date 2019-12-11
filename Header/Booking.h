#ifndef BOOKING_H_
#define BOOKING_H_

#include "SaveLoad.h"
#include "Payment.h"

using namespace std;

class Booking: public SaveLoad{
	protected:
		SaveLoad s;
		Payment pm;
		int uniqueNum;
	public:
		Booking();
		Booking(SaveLoad &);
		virtual ~Booking();

		void bookingMenu();

		void dateForFlight(int);
		void categoryPassenger(int);
		void detailsTrip();
		void detailsPassenger(double, int);
		void display(double, int, string, string, char, int, string);
		void displayPassengerDetails(int);
};

#endif /* BOOKING_H_ */
