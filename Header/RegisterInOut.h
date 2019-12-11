#ifndef REGISTERINOUT_H_
#define REGISTERINOUT_H_

#include "Data.h"
#include "SaveLoad.h"

using namespace std;

class RegisterInOut: public SaveLoad{
	private:
		int unique;
	public:
		RegisterInOut();
		~RegisterInOut();

		void setUnique(int);
		int getUnique() const;

		void registerInOutMenu();
		void registerMenu();
		void loginMenu();
		bool loginProcess(int &, string, string);
		void logoutMenu();
};


#endif /* REGISTERINOUT_H_ */
