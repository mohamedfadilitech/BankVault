/**
 * updateClient.cpp
 * Contains logic to update the details of an existing client and syncs the changes
 * to the storage file.
 */
#include <iostream>
#include <fstream>
#include "update.h"
#include "deleteClient.h"

/**
 * Prompts user to input updated details for a specified client ID.
 * @return Struct with new client information.
 */
stClient updateClient(string& accountId) {

	stClient updatedClient;

	updatedClient.accountId = accountId;

	cout << "Enter The Pin Code : ";
	getline(cin >> ws, updatedClient.pinCode);
	cout << "Enter The fullName: ";
	getline(cin >> ws, updatedClient.fullName);
	cout << "Enter The phone : ";
	getline(cin >> ws, updatedClient.phone);
	cout << "Enter The Account Balance : ";
	cin >> updatedClient.accountBalance;

	return updatedClient;
}

/**
 * Modifies the target client in the vector and overwrites the text record file.
 * @param accountId Client to update.
 */
void backToFileUpdated(string& accountId) {

	vector<stClient> vClients = FileToStClient();
	removeTheMatch(accountId, vClients);
	stClient updatedClient = updateClient(accountId);
	vClients.push_back(updatedClient);

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

/**
 * Initiates the update process, asks for permission, and saves details.
 */
void update(string& accountId) {
	char choice;
	do {
		cout << "Do You Wanna Update This Client ? Y : N : ";
		cin >> choice;
		choice = tolower(choice);
	} while (choice != 'y' && choice != 'n');

	if (choice == 'y') {
		backToFileUpdated(accountId);
		cout << "\n\n The Client With Account Id (" << accountId << ") Is updated \n" << endl;
		cout << "\n";
	}
}
