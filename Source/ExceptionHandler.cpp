#include "../Header/ExceptionHandler.h"
#include "../Header/Data.h"

#include <cmath>

using namespace std;

ExceptionHandler::ExceptionHandler() {
}

ExceptionHandler::~ExceptionHandler() {
}

void ExceptionHandler::registerName(string _f, string _l){

	char special[33] = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
	char num[11] = "0123456789";
	string name = _f + _l;
	bool valid = true;

	for(int i = 0; i < 32; i++)
		if(name.find(special[i]) != (pow(2, 32) - 1)){
			valid = false;
			break;
		}
	for(int j = 0; j < 10; j++)
		if(name.find(num[j]) != (pow(2, 32) - 1)){
			valid = false;
			break;
		}

	if(!valid)
		throw "Name must not be included any special character (except whitespace) or number!\n";
}
void ExceptionHandler::registerEmail(string _ee){

	if(_ee.find(".com") == (pow(2, 32) - 1))
		throw "Invalid Email Format!\n";
}
void ExceptionHandler::registerGender(char _g){
	switch(_g){
		case 'M':
		case 'm':
		case 'F':
		case 'f':
			break;
		default:
			throw "Invalid Gender Format!\n";
			break;
	}
}
void ExceptionHandler::registerAge(int _a){
	if(_a < 0)
		throw "Invalid Age Format!\n";
}
void ExceptionHandler::registerPassword(string _p, string _p2){
	if(_p.length() < 8 || _p.length() > 16)
		throw "Password must more than 8 and less than 16 characters!\n";

	char special[34] = " !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
	char num[11] = "0123456789";
	char alpha[53] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	bool valid = false;

	for(int i = 0; i < 33; i++){

		if(_p.find(special[i]) != (pow(2, 32) - 1))
			for(int j = 0; j < 10; j++){

				if(_p.find(num[j]) != (pow(2, 32) - 1))
					for(int k = 0; k < 52; k++)
						if(_p.find(alpha[k]) != (pow(2, 32) - 1)){
							valid = true;
							break;
						}
				if(valid)
					break;
			}
		if(valid)
			break;
	}

	if(!valid)
		throw "Password must include at least 1 special character, alphabate and number!\n";
	else{
		if(_p != _p2)
			throw "Both Password Entered must be same!\n";
	}
}
int ExceptionHandler::loginValidate(string email, string password, string _f[], string _l[], string _e[], string _ee[], string _pass[], char _g[], int _c, unsigned short int _a[]){
	Data obj;
	bool success = false;
	for(int i = 0; i < _c; i++){
		if(email == (_e[i] + "@" + _ee[i]) && password == _pass[i]){
			success = true;
			obj.setPersonalData(_f[i], _l[i], _e[i], _ee[i], _pass[i], _a[i], _g[i]);
			return (i+1);
		}
	}
	if(!success){
		throw "Either Email or Password or both are wrong!";
	}
	return 0;
}

bool ExceptionHandler::cardNumberChecker(string _num){
	char alpha[53] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	char special[34] = " !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";

	if(_num.length() != 16)
		throw "The number of digits must be 16!";
	else{
		for(int i = 0; i < 33; i++){
			if(_num.find(special[i]) != (pow(2, 32) - 1))
				throw "Invalid input!";

		for(int k = 0; k < 52; k++)
			if(_num.find(alpha[k]) != (pow(2, 32) - 1))
				throw "Invalid input!";
		}
	}

	return true;
}

bool ExceptionHandler::cardExpiredChecker(int _m, int _y){
	if((_m >= 1) && (_m <= 12) && (_y <= 99) && (_y >= 19))
		return true;
	else
		throw "Invalid Input!";
}

bool ExceptionHandler::cardCVVChecker(int _cvv){
	if((_cvv < 1000) && (_cvv > 99))
		return true;
	else
		throw "Invalid Input!";

	return true;
}

bool ExceptionHandler::dateValidator(int _d, int _m, int _y){
	bool valid = false;
	if(((_m == 1) || (_m == 3) || (_m == 5) || (_m == 7) ||(_m == 8) || (_m == 10) || (_m == 12)) && ((_d > 0 ) && (_d < 32)) && ((_y < 3000) && (_y >= 2018)))
		valid = true;
	else if(((_m == 4) || (_m == 6) || (_m == 9) || (_m == 11)) && ((_d > 0 ) && (_d < 31)) && ((_y < 3000) && (_y >= 2018)))
		valid = true;
	else if((_m == 2) && ((_d > 0 ) && (_d < 30))){
		if( ((_y < 3000) && (_y >= 2018)) && (((_y - 2000) % 4) != 0)){
			if(_d < 29)
				valid = true;
			else
				throw "Invalid Input";
		}

		else if ( ((_y < 3000) && (_y >= 2018)) && (((_y - 2000) % 4) == 0)){
			valid = true;
		}
		else
			throw "Invalid Input";

	}else
		throw "Invalid Input";

	return valid;
}
