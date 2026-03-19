/**
 * addNewClient.cpp
 * Contains functions for adding new clients to the bank system.
 */
#include <iostream>
#include <fstream>
#include "addNewClient.h"

string toUpper(string str) {
	for (char& c : str)
		c = toupper(c);
	return str;
}

/**
 * Validates if the given account ID already exists in the file records.
 * @param accountId ID string to verify.
 * @return True if exists, else False.
 */
bool isAccountIdExist(string& accountId) {
	vector<stClient> vClients = FileToStClient();

	for (stClient& vClient : vClients) {
		if (toUpper(vClient.accountId) == toUpper(accountId))
			return true;
	}
	return false;
}

/**
 * Prompts user to input all required fields for a new client.
 * Continuously validates uniqueness of the Account ID.
 * @return Newly constructed client struct.
 */
stClient readCustomerInfos() {

	stClient customer;

	do {
		cout << "Enter Account Number ? : ";
		getline(cin >> ws, customer.accountId);
		if (isAccountIdExist(customer.accountId)) {
			cout << "\nClient With Id [" << customer.accountId << "] Is Already Exist Enter Another Id \n";
		}
	} while (isAccountIdExist(customer.accountId));

	cout << "Enter Pincode ? : ";
	getline(cin >> ws, customer.pinCode);

	cout << "Enter Name ? : ";
	getline(cin >> ws, customer.fullName);

	cout << "Enter PhoneNumber ? : ";
	getline(cin >> ws, customer.phone);

	cout << "Enter Account Balance ? : ";
	cin >> customer.accountBalance;

	return customer;
}

/**
 * Formats client details into a single delimited string for file storage.
 * @param client Struct containing the formatted details.
 * @param delim The delimiter used to space out tokens.
 * @return Formatted string.
 */
string recordToLine(stClient& client, string delim) {

	string str = "";

	str += client.accountId + delim;
	str += client.pinCode + delim;
	str += client.fullName + delim;
	str += client.phone + delim;
	str += to_string(client.accountBalance);
	return str;
}

/**
 * Appends a delimited string representing client record to the provided filename.
 */
void addToFile(string& line, string fileName) {

	fstream myFile(fileName, ios::app);

	if (!myFile.is_open()) {
		cout << "can't find the file";
		return;
	}
	myFile << line << "\n";
	myFile.close();
}

/**
 * Initiates the flow to add new clients, reads details, saves to file,
 * and handles prompt loop to add multiple if needed.
 */
void recordToFile() {

	stClient client;
	string line;
	char ch;

	do {
		system("cls");
		cout << "======================================\n";
		cout << "\t Add New Client Screen\n";
		cout << "======================================\n";
		cout << "Adding New Client : \n\n";
		client = readCustomerInfos();
		line = recordToLine(client, "#//#");
		addToFile(line, "clientsData.txt");
		do {
			cout << "\nYou Want To Add Another Client Press ? Y : N : ";
			cin >> ch;
			ch = tolower(ch);
		} while (ch != 'y' && ch != 'n');
	} while (ch == 'y');
}