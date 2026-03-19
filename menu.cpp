/**
 * menu.cpp
 * Contains implementation of permission verifications and textual user interfaces for menus.
 */
#include "menu.h"
#include <iostream>

// Main menu permissions verification
bool hasPermission(stUser currentUser, enOperations operation) {
    if (currentUser.permissions == -1) // check for full access assuming -1 is full
        return true;
	if (currentUser.permissions & operation)
		return true;
	return false;
}

void menuDesign(stUser currentUser) {

	cout << "================================================\n";
	cout << "\t\tMain Menu \n";
	cout << "================================================\n";
	if(hasPermission(currentUser,eShowClientList))
		cout << "\t [1] Show Client List. \n";
	if (hasPermission(currentUser, eAddNewClient))
		cout << "\t [2] Add New Client. \n";
	if (hasPermission(currentUser, eDeleteClient))
		cout << "\t [3] Delete Client. \n";
	if (hasPermission(currentUser, eUpdateClient))
		cout << "\t [4] Update Client Info. \n";
	if (hasPermission(currentUser, eFindClient))
		cout << "\t [5] Find Client. \n";
	if (hasPermission(currentUser, eTransactions))
		cout << "\t [6] Transaction. \n";
	if (hasPermission(currentUser, eManageUsers))
		cout << "\t [7] Manage Users. \n";
	cout << "\t [8] Logout. \n";
	cout << "================================================\n";
}

// transaction menu
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
		cout << "Choose Operation You Want To Do ? [1 To 4] ? ";
		cin >> i;
	} while (i < 1 || i > 4);
	return i;
}

//manage users menu

short manageUsersMenu() {

	short i;

	cout << "================================================\n";
	cout << "\t\tManage Users \n";
	cout << "================================================\n";
	cout << "\t [1] List Users. \n";
	cout << "\t [2] Add New User. \n";
	cout << "\t [3] Delete User. \n";
	cout << "\t [4] Update User Info. \n";
	cout << "\t [5] Find User. \n";
	cout << "\t [6] Main Menu. \n";
	cout << "================================================\n";
	do {
		cout << "Choose Operation You Want To Do ? [1 To 6] ? ";
		cin >> i;
	} while (i < 1 || i > 6);
	return i;

}

short menu(stUser currentUser) {

	short i;
	menuDesign(currentUser);
	do {
		cout << "Choose What Do You Want To Do ? [1 To 8] ? ";
		cin >> i;
	} while (i < 1 || i > 8);
	return i;
}
