#include "updateUser.h"
#include "deleteUser.h"
#include <iostream>
#include <fstream>

 
stUser updateUserInfos(string& userName) {

	stUser updatedUser;

	updatedUser.userName = userName;

	cout << "Enter The Password : ";
	getline(cin >> ws, updatedUser.passwd);
	updatedUser.permissions = readUserPermissions();
	return updatedUser;
}

void backToFileUpdatedUser(string& userName) {

	vector<stUser> vUsers = FileToStUser();
	removeTheUserMatch(userName, vUsers);
	stUser updatedClient = updateUserInfos(userName);
	vUsers.push_back(updatedClient);

	fstream myFile("users.txt", ios::out | ios::trunc);

	if (!myFile.is_open()) {
		cout << "Error!\n";
		return;
	}

	vector<string> vStr;
	string s;

	for (stUser& user : vUsers) {
		vStr.push_back(user.userName);
		vStr.push_back(user.passwd);
		vStr.push_back(to_string(user.permissions));

		s = join(vStr);
		myFile << s << "\n";
		vStr.clear();
	}
	myFile.close();
}

void updateUser(string& userName) {
	
	char ch;
	ch = checkYesOrNo("Do You Wanna Update This User ? Y : N ");
	if (ch == 'y') {
		backToFileUpdatedUser(userName);
		cout << "\n\n The User With userName (" << userName << ") Is updated \n" << endl;
		cout << "\n";
	}
}
