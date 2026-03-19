/**
 * addUser.cpp
 * Includes logic to accept new banking system users, configuring their
 * authorization matrix, and saving records to users.txt.
 */
#include <iostream>
#include "addUser.h"

bool isAccountUserIdExist(string& userName) {
	vector<stUser> vUsers = FileToStUser();

	for (stUser& vUser : vUsers) {
		if ((toUpper(vUser.userName) == toUpper(userName)))
			return true;
	}
	return false;
}

char checkYesOrNo(string sentence) {
	char ch;
	do {
		cout << sentence;
		cin >> ch;
		ch = tolower(ch);
	} while (ch != 'y' && ch != 'n');
	return ch;
}
string readUserName() {
	string userName;
	do {
		cout << "Enter userName ? : ";
		getline(cin >> ws, userName);
		if (isAccountUserIdExist(userName))
			cout << "\nThe User With UserName [" << userName << "] Is Already Exist Enter Another userName \n";
	} while (isAccountUserIdExist(userName));
	return userName;
}

int readUserPermissions() {
	if (checkYesOrNo("Do you want to give full access? y/n?") == 'y')
		return -1;

	int permissions = 0;
	cout << "Do you want to give access to : \n\n";
	if (checkYesOrNo("Allow Show Client List ? (Y/N) : ") == 'y') permissions += enOperations::eShowClientList;
	if (checkYesOrNo("Allow Add New Client ? (Y/N) : ") == 'y') permissions += enOperations::eAddNewClient;
	if (checkYesOrNo("Allow Delete Client ? (Y/N) :") == 'y') permissions += enOperations::eDeleteClient;
	if (checkYesOrNo("Allow Update Client ? (Y/N) :") == 'y') permissions += enOperations::eUpdateClient;
	if (checkYesOrNo("Allow Find Client ? (Y/N) :") == 'y') permissions += enOperations::eFindClient;
	if (checkYesOrNo("Allow Transactions ? (Y/N) :") == 'y') permissions += enOperations::eTransactions;
	if (checkYesOrNo("Allow Manage Users ? (Y/N) :") == 'y') permissions += enOperations::eManageUsers;
	return permissions;
}

stUser readUserInfos() {

	stUser user;
	user.userName = readUserName();
	cout << "Enter The Password ? : ";
	getline(cin >> ws, user.passwd);
	user.permissions = readUserPermissions();
	return user;
}

string recordToLineUserFile(stUser& user, string delim) {

	string str = "";

	str += user.userName + delim;
	str += user.passwd + delim;
	str += to_string(user.permissions);
	return str;
}

void recordToUserFile() {

	stUser user;
	string line;
	char ch;

	do {
		system("cls");
		cout << "======================================\n";
		cout << "\t Add New User Screen\n";
		cout << "======================================\n";
		cout << "Adding New user : \n\n";
		user = readUserInfos();
		line = recordToLineUserFile(user, "#//#");
		addToFile(line, "users.txt");
		ch = checkYesOrNo("\nYou Want To Add Another User Press ? Y : N : ");
	} while (ch == 'y');
}