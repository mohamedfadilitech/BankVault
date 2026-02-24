#pragma once
#include<iostream>
#include<cctype>
#include<string>
#include<fstream>
#include "clientList.h"

using namespace std;

string readAccountId() {
	string accountId;

	cout << "Enter the account Id : ";
	getline(cin >> ws, accountId);
	return accountId;
}

string	join(vector<string>& vStr, string delim = "#//#") {

	string s = "";
	for (string& str : vStr) {
		s += str + delim;
	}
	return s.substr(0, s.length() - delim.length());

}

bool is_match(string& accountId, vector<stClient>& vClients, stClient& client) {

	for (const stClient& vClient : vClients) {
		if (vClient.accountId == accountId) {
			client = vClient;
			return true;
		}
	}
	return false;
}
bool	print_answer(string& accountId, stClient& client) {


	vector<stClient> vClients = FileToStClient();
	bool found = is_match(accountId, vClients, client);

	if (found) {
		cout << "\n\n The Following Are Client Details \n\n";
		cout << "Account Id : " << client.accountId << endl;
		cout << "Pin Code: " << client.pinCode << endl;
		cout << "Full Name: " << client.fullName << endl;
		cout << "Phone Number: " << client.phone << endl;
		cout << "Account Balance: " << client.accountBalance << endl;
		return true;
	}
	else {
		cout << "The Client With Account Id :" << accountId << " Not Found" << endl;
		return false;
	}


}
void removeTheMatch(string& accountId, vector<stClient>& vClients) {

	for (int i = 0; i < vClients.size(); i++) {
		if (vClients.at(i).accountId == accountId) {
			vClients.erase(vClients.begin() + i);
			break;
		}
	}
}

void backToFile(string& accountId) {
	vector<stClient> vClients = FileToStClient();
	removeTheMatch(accountId, vClients);

	fstream myFile("clientsData.txt", ios::out | ios::trunc);

	if (!myFile.is_open()) {
		cout << "Error!\n";
		return;
	}

	vector<string> vStr;
	string s;

	for (stClient& client : vClients) {
		vStr.push_back(client.accountId);
		vStr.push_back(client.pinCode);
		vStr.push_back(client.fullName);
		vStr.push_back(client.phone);
		vStr.push_back(to_string(client.accountBalance));

		s = join(vStr);
		myFile << s << "\n";
		vStr.clear();
	}

	myFile.close();
}

void	DeleteClient(string& accountId) {
	char choice;
	do {
		cout << "Do You Wanna Delete This Client ? Y : N : ";
		cin >> choice;
		choice = tolower(choice);
	} while (choice != 'y' && choice != 'n');

	if (choice == 'y') {
		backToFile(accountId);
		cout << "\n\n The Client With Account Id (" << accountId << ") Is Deleted \n" << endl;
	}

}

//int main() {
//	string accountId = readAccountId();
//	stClient client;
//	bool found = print_answer(accountId, client);
//	if (found)
//		DeleteClient(accountId);
//}
