#include "../Header/Payment.h"
#include "../Header/ExceptionHandler.h"
#include "../Header/SaveLoad.h"
#include "../Header/MainMenu.h"

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <iomanip>

using namespace std;

Payment::Payment(): cardNum(""), cardbankName(""), expMonth(0), expYear(0), cvv(0), payPrice(0){}

Payment::~Payment() {
}

string	Payment::getBankName()	const{return cardbankName;	}
string	Payment::getCardNum()	const{return cardNum;	}
int 	Payment::getExpMonth()	const{return expMonth;	}
int 	Payment::getExpYear()	const{return expYear;	}
int 	Payment::getCvv()		const{return cvv;		}

void Payment::setBankName(string _bankName){cardbankName = _bankName;}

void Payment :: setCardNum(string _cardNum){cardNum = _cardNum;}

void Payment::setExpMonth(int _expMonth){expMonth = _expMonth;}

void Payment::setExpYear(int _expYear){expYear = _expYear;}

void Payment::setCvv(int cv){cvv = cv;}

void Payment::setPrice(double _p){payPrice = _p;}

bool Payment::displayCardData(int u){
	system("cls");
	bool exist = false;
	exist = loadCardData(u); //load card data if exist

	if(exist){
		int choice;

		for(int i = 0; i < card; i++){
			cout << i+1 << ": " << endl;
			cout << "**********************************" << endl;
			cout << setw(15) << "Bank Name" << ": " << cardBank[i] << endl;
			cout << setw(15) << "Card Number" << ": " << cardNumber[i] << endl;
			cout << setw(15) << "Expired Month" << ": " << cardMonthEXP[i] << endl;
			cout << setw(15) << "Expired Year" << ": 20" << cardYearEXP[i] << endl;
			cout << setw(15) << "CVV" << ": " << cardCVV[i] << endl;
			cout << "**********************************" << endl << endl;;
		}
		cout << "Choose the card you want to use" << endl;
		cout << "Enter any other number to use a new card" << endl;
		cout << ">> ";
		cin  >> choice;
		if(choice > 0 && choice <= card){
			paylastStep(u, cardBank[choice-1], cardNumber[choice-1], cardMonthEXP[choice-1], cardYearEXP[choice-1], cardCVV[choice-1]);
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void Payment::paymentMenu(int unique){
	while(payPrice > 0){
		bool success = false;
		bool usePreviousCard = false;

		ExceptionHandler obj;

		string bankName;
		string cardCreditNum;
		int expiredMonth;
		int expiredYear;
		int cvvNum;
		int proceed1, proceed2;
		int check;
		int bankComp;

		system("cls");

		cout << "\n                                  Payment" << endl << endl;
		cout << "-------Remainder: The current program cannot accept online payment yet-------" << endl;
		cout << "----------------------ONLY Credit or Debit Card accepted!--------------------" << endl;
		cout << endl;

		cout << "Continue?\n"
			 << "YES[1] or NO[2]\n\t>> ";
		cin  >> proceed1;
		cout << endl;

		if(proceed1 == 1){
			system("cls");
			char a = 177, b = 219;

			cout << "\n\n\n\t\t\t\t\tProcessing.....\n\n";
			cout << "\t\t\t\t";

			for(int i = 0; i <30; i++)
				cout << a;
			Sleep(100);

			cout << "\r";
			cout << "\t\t\t\t";

			for(int i = 0; i <30;i++){
					cout << b;
					Sleep(150);
			}

			usePreviousCard = displayCardData(unique);

			if(usePreviousCard){
				cout << "Thank you for using our system." << endl;
				Sleep(3000);
				return;
			}
			else{
				system("cls");
				cout << "Please select your Bank Company -> \n\n"
					 << "Bank Islam\t\t\t[1]\t|\tCimb Bank\t\t[2]\n"
					 << "MayBank\t\t\t\t[3]\t|\tPublic Bank Berhad\t[4]\n"
					 << "RHB Bank\t\t\t[5]\t|\tHong Leong Bank\t\t[6]\n"
					 << "AmBank\t\t\t\t[7]\t|\tBank Rakyat\t\t[8]\n"
					 << "Bank Simpanan Nasional (BSN)\t[9]\n\n";

				cout << "Bank : ";
				cin  >> bankComp;
				cout << endl;

				if (bankComp > 0 && bankComp < 10){
					cout << "Your Bank is exist! Continuing your payment..." << endl << endl;

					switch(bankComp){
						case 1:
							bankName = "Bank Islam";
							break;
						case 2:
							bankName = "Cimb Bank";
							break;
						case 3:
							bankName = "MayBank";
							break;
						case 4:
							bankName = "Public Bank Berhad";
							break;
						case 5:
							bankName = "RHB Bank";
							break;
						case 6:
							bankName = "Hong Leong Bank";
							break;
						case 7:
							bankName = "AmBank";
							break;
						case 8:
							bankName = "Bank Rakyat";
							break;
						default:
							bankName = "Bank Simpanan Nasional (BSN)";
							break;
					}

					cout << "Continue?\n"
						 << "YES[1] or NO[2]\n\t>> ";
					cin  >> proceed2;
					cout << endl;


					if (proceed2 == 1){
						try{
							cin.ignore();

							cout << setw(31) << "Credit/debit Number (16 digits)" << ": ";
							getline(cin, cardCreditNum, '\n');
							success = obj.cardNumberChecker(cardCreditNum);

							cout << setw(31) <<  "Expired date (MM/YY)" << ": ";
							cin  >> expiredMonth;
							cin.ignore(1, '/');
							cin  >> expiredYear;
							success = obj.cardExpiredChecker(expiredMonth, expiredYear);

							cout << setw(31) <<  "CVV (3 Number behind the card)" << ": ";
							cin  >> cvvNum;
							success = obj.cardCVVChecker(cvvNum);
						}
						catch(const char *error){
							cout << "ERROR: " << error << endl;
							success = false;
							Sleep(2000);
							system("cls");
							continue;
						}
						catch(...){
							success = false;
							cout << "ERROR: Unexpected Error happened!" << endl;
							Sleep(2000);
							system("cls");
							continue;
						}

						if(success){
							paylastStep(unique, bankName, cardCreditNum, expiredMonth, expiredYear, cvvNum);
							cout << "Do you want to save your card data for future transaction?" << endl;
							cout << "YES[PUSH 1] or GO BACK[PUSH 2]\n\t>> ";
							cin  >> check;

							if(check == 1){
								saveCardData(unique, bankName, cardCreditNum, expiredMonth, expiredYear, cvvNum);
								cout << "Your data have successfully saved for future use. Thank you!" << endl;
								Sleep(1000);
								return;
							}
							else{
								cout << "Going back to Main Screen..." << endl;
								Sleep(1000);
								return;
							}
						}
					}
					else {
						cout << endl;
						cout << endl;
						cout << "Thank You! See you again! " << endl;
						Sleep(1000);
						return;
					}
				}
				else{
					cout << "Sorry! The bank that you choose is not exist\n"
						 << "Back to Main Screen\n" << endl << endl;
					Sleep(1000);
					return;
				}
			}
		}
		else{
			cout << "Thank You, See you again!" << endl;
			Sleep(1000);
			return;
		}
	}
	if(payPrice <= 0){
		cout << "\n\tYou don't have any payment need to be done!" << endl;
		Sleep(1000);
		return;
	}
}

void Payment::paylastStep(int _u, string _cardBankName, string _cardCreditNum, int _expiredMonth, int _expiredYear, int _cvvNum){
	Sleep(1000);
	system("cls");

	int check;

	setBankName(_cardBankName);
	setCardNum(_cardCreditNum);
	setExpMonth(_expiredMonth);
	setExpYear(_expiredYear);
	setCvv(_cvvNum);

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "------------------------------------------------" << endl;
	cout << endl;

	cout << "----------Check your information below----------" << endl;
	cout << endl;
	cout << "Bank\t\t: "		<<	getBankName()	<< endl;
	cout << "Card number\t: "	<<	getCardNum()	<< endl;
	cout << "Exp Month\t: "		<<	getExpMonth()	<< endl;
	cout << "Exp Year\t: 20"	<<	getExpYear()	<< endl;
	cout << "CVV\t\t: "			<<	getCvv()		<< endl;
	cout << endl;

	cout << "Is the information true?\n"
		 << "YES[PUSH 1] or GO BACK[PUSH 2]\n\t>> ";
	cin  >> check;

	if(check == 1){

		time_t curr_time;
		time(&curr_time);
		string timePayment = asctime(localtime(&curr_time));

		cout << "Total Payment   : RM " << showpoint <<setprecision(2) << payPrice << endl;
		cout << "Payment Status  : Success" << endl;
		cout << "Time\t\t: " << timePayment << endl << endl;
		payPrice = 0;

	}
	else{
		cout << "Your payment have been cancelled..." << endl;
		Sleep(1000);
		return;
	}
}
