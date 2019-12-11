#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "Booking.h"
#include "Payment.h"
#include "RegisterInOut.h"
#include "SaveLoad.h"

class MainMenu: private RegisterInOut {
	protected:
		Payment p;
		Booking b;
		SaveLoad sl;
	private:
		const int uniqueNumber;
	public:
		MainMenu();
		MainMenu(int);
		~MainMenu();

		void menu();

		int getUniqueNumber() const;
};

#endif /* MAINMENU_H_ */
