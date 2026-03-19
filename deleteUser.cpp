#include "deleteUser.h"
#include <iostream>
#include <fstream>
string readAccountUserName() {
	string userName;

	cout << "Enter The Account UserName : ";
	getline(cin >> ws, userName);
	return userName;
}

bool isAmatchUser(string& userName, vector<stUser>& vUsers, stUser &user) {

	for (const stUser& vUser : vUsers) {
		if (vUser.userName ==userName) {
			user = vUser;
			return true;
		}
	}
	return false;
}

bool print_answer_users(string& userName) {
	stUser user;
	vector<stUser> vUser = FileToStUser();
	bool found = isAmatchUser(userName, vUser, user);

	if (found) {
		cout << "\n\n The Following Are User Details \n\n";
		cout << "User UserName : " << user.userName << endl;
		cout << "User Password: " << user.passwd << endl;
		cout << "User Permissions: " << user.permissions << endl;
		return true;
	}
	else {
		cout << "The User UserName :" << userName<< " Not Found" << endl;
		return false;
	}
}

void removeTheUserMatch(string& userName, vector<stUser>& vUsers) {

	for (int i = 0; i < vUsers.size(); i++) {
		if (vUsers.at(i).userName == userName) {
			vUsers.erase(vUsers.begin() + i);
			break;
		}
	}
}

void backToUsersFile(string& userName) {

	vector<stUser> vUsers = FileToStUser();
	removeTheUserMatch(userName, vUsers);

	fstream myFile("users.txt", ios::out | ios::trunc);

	if (!myFile.is_open()) {
		cout << "Error!\n";
		return;
	}

	vector<string> vStr;
	string s;

	for (stUser& user : vUsers) {
		vStr.push_back(user.userName);
		vStr.push_back(user.passwd);;
		vStr.push_back(to_string(user.permissions));
		s = join(vStr);
		myFile << s << "\n";
		vStr.clear();
	}

	myFile.close();
}

void DeleteUser(string& userName, stUser &currentUser) {
	if (userName == currentUser.userName) { cout << "\nCan't Do This Operations \n"; return; }
	char ch;
	ch = checkYesOrNo("You Want To Delete This User ? Y:N ");

	if (ch == 'y') {
		backToUsersFile(userName);
		cout << "\n\n The User With UserName (" << userName << ") Is Deleted \n" << endl;
	}
}
