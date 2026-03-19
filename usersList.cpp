/**
 * usersList.cpp
 * Fetches and displays existing users and their roles/permissions in a formatted table.
 */
#include "usersList.h"
#include <iostream>
#include <iomanip>

void printUsersInfos() {

	vector<stUser> vUsers = FileToStUser();
	cout << "======================================\n";
	cout << "\t Show User List Screen\n";
	cout << "======================================\n";
	cout << "\t\t\t\t\t\t Users List(" << vUsers.size() << ") " << "\t\t" << endl;
	cout << "=================================================================================================================\n";
	cout << "| " << left << setw(20) << "Full Name";
	cout << "| " << left << setw(20) << "Password";
	cout << "| " << left << setw(20) << "Permissions";
	cout << "\n";
	cout << "=================================================================================================================\n";

	for (const stUser& user : vUsers) {
		cout << "| " << left << setw(20) << user.userName;
		cout << "| " << left << setw(20) << user.passwd;
		cout << "| " << left << setw(20) << user.permissions;
		cout << "\n";
	}
	cout << "=================================================================================================================\n";
}


