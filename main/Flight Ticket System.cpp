#include <iostream>
#include <Windows.h>
#include "../Header/RegisterInOut.h"

using namespace std;

int main() {
	system("cls");
	char a = 177, b = 219;

	cout << "\n\n\n\t\t\t\t\tLoading...\n\n";
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

	RegisterInOut obj;
	obj.registerInOutMenu();

	return 0;
}
