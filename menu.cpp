#include "menu.h"

void menuDesign() {

	cout << "================================================\n";
	cout << "\t\tMain Menu \n";
	cout << "================================================\n";
	cout << "\t [1] Show Client List. \n";
	cout << "\t [2] Add New Client. \n";
	cout << "\t [3] Delete Client. \n";
	cout << "\t [4] Update Client Info. \n";
	cout << "\t [5] Find Client. \n";
	cout << "\t [6] Transaction. \n";
	cout << "\t [7] Exit. \n";
	cout << "================================================\n";
}

short transactionMenu() {
	short i;

	cout << "================================================\n";
	cout << "\t\tTransaction Menu Screen\n";
	cout << "================================================\n";
	cout << "\t [1] Deposit. \n";
	cout << "\t [2] Withdraw. \n";
	cout << "\t [3] Total Balance. \n";
	cout << "\t [4] Main Menu. \n";
	cout << "================================================\n";
	do {
		cout << "Choose What Do You Want To Do ? [1 To 4] ? ";
		cin >> i;
	} while (i < 1 || i > 4);
	return i;
}

short menu() {

	short i;
	menuDesign();
	do {
		cout << "Choose Whatt Do You Want To Do ? [1 To 7] ? ";
		cin >> i;
	} while (i < 1 || i > 7);
	return i;
}
