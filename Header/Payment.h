#ifndef PAYMENT_H_
#define PAYMENT_H_

#include "SaveLoad.h"

#include <iostream>

using namespace std;

class Payment: SaveLoad{
	private:
		string cardNum;
		string cardbankName;
		int expMonth;
		int expYear;
		int cvv;
		double payPrice;
	public:
		Payment();
		~Payment();

		void setBankName(string);
		void setCardNum(string);
		void setExpMonth(int);
		void setExpYear(int);
		void setCvv(int);
		void paylastStep(int, string, string, int, int, int);
		bool displayCardData(int);

		string getBankName()	const;
		string	getCardNum()	const;
		int		getExpMonth()	const;
		int		getExpYear()	const;
		int		getCvv()		const;

		void paymentMenu(int);
		void setPrice(double);
};

#endif /* PAYMENT_H_ */
