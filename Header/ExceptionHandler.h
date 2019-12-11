#ifndef EXCEPTIONHANDLER_H_
#define EXCEPTIONHANDLER_H_

#include <iostream>

using namespace std;

class ExceptionHandler {
public:
	ExceptionHandler();
	~ExceptionHandler();
	void registerName(string, string);
	void registerEmail(string);
	void registerGender(char);
	void registerAge(int);
	void registerPassword(string, string);

	int loginValidate(string, string, string [], string [], string [], string [], string [], char [], int, unsigned short int []);

	bool cardNumberChecker(string);
	bool cardExpiredChecker(int, int);
	bool cardCVVChecker(int);

	bool dateValidator(int, int, int);
};

#endif /* EXCEPTIONHANDLER_H_ */
