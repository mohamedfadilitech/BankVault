/**
 * manageUsers.cpp
 * Provides routing logic for user management tasks requested by an admin.
 */
#include <iostream>
#include "manageUsers.h"
#include "addUser.h"
#include "deleteUser.h"
#include "updateUser.h"
#include "login.h"

/**
 * Executes a chosen user-management operation based on user input.
 * @param selectedOption The action chosen from the manage users menu.
 */

void deleteScreenTitle(string placeholder) {
	cout << "======================================\n";
	cout << "\t Delete " << placeholder << " Screen\n";
	cout << "======================================\n";
}

void	updateScreenTitle(string placeholder)
{
	cout << "======================================\n";
	cout << "\t Update " << placeholder << " Info Screen\n";
	cout << "======================================\n";
}
void	findUserScreenTitle(string placeholder) {
	cout << "======================================\n";
	cout << "\t Find "<< placeholder << " Screen\n";
	cout << "======================================\n";

}
void deleteUserScreen(stUser &currentUser) {
	char ch;
	string userName;
	do {
		deleteScreenTitle("User");
		userName = readAccountUserName();
		if (print_answer_users(userName))
			DeleteUser(userName, currentUser);
		ch = checkYesOrNo("You Want To Delete Another Account ? Y:N ");
		system("cls");
	} while (ch == 'y');
}

void updateUserScreen() {
	char ch;
	string userName;
	do {
		updateScreenTitle("User");
		userName = readAccountUserName();
		if (print_answer_users(userName))
			updateUser(userName);
		ch = checkYesOrNo("You Want To Update Another User ? Y:N ");
		system("cls");
	} while (ch == 'y');
}
void findUserScreen() {
	
	string userName;
	char ch;
	do{
		findUserScreenTitle("User");
		userName = readAccountUserName();
		print_answer_users(userName);
		ch = checkYesOrNo("You Want To find Another User ? Y:N ");
		system("cls");
	} while (ch == 'y');

}
void choosingOperationForUsers(short selectedOption, stUser& currentUser) {

	while (selectedOption != 6) {
		system("cls");
		switch (selectedOption) {
		case 1:printUsersInfos(); break;
		case 2:recordToUserFile(); break;
		case 3: deleteUserScreen(currentUser); break;
		case 4 :updateUserScreen(); break;
		case 5: findUserScreen(); break;
		}
		cout << "\n Press Any Key To Go Back To The Main Menu ..... \n";
		system("pause>0");
		system("cls");
		selectedOption = manageUsersMenu();
	}
}

/**
 * Entry point for managing users, displays a menu and delegates execution.
 */
void manageUsers(stUser &currentUser) {
	short selectedOption = manageUsersMenu();
	choosingOperationForUsers(selectedOption, currentUser);
}
