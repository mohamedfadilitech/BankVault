/**
 * transaction.cpp
 * Core logic for bank transactions: deposits, withdrawals, and balance inquiries.
 * Operates on the clientsData.txt store to persist changes.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include "transaction.h"
#include "deleteClient.h"
#include "menu.h"
double readAmount(string operation) {

	double amount;

	do {
		cout << "Please Enter The " << operation << " Amount ? : ";
		cin >> amount;
	} while (amount <= 0);
	return amount;
}

char askingPermission() {
	char choice;

	do {
		cout << "Are You Sure You Wanna Performe This Transaction ? Y : N : ";
		cin >> choice;
		choice = tolower(choice);
	} while (choice != 'y' && choice != 'n');
	return choice;
}

void backToFileUpdatedBalance(string& accountId, vector<stClient>& vClients, stClient& updatedClient) {

	for (stClient& c : vClients) {
		if (c.accountId == accountId) {
			c.accountBalance = updatedClient.accountBalance;
			break;
		}
	}

	fstream myFile("clientsData.txt", ios::out | ios::trunc);

	if (!myFile.is_open()) {
		cout << "Error!\n";
		return;
	}

	for (stClient& c : vClients) {
		vector<string> vStr;
		vStr.push_back(c.accountId);
		vStr.push_back(c.pinCode);
		vStr.push_back(c.fullName);
		vStr.push_back(c.phone);
		vStr.push_back(to_string(c.accountBalance));
		myFile << join(vStr) << "\n";
	}
    myFile.close();
}

/**
 * Validates permission and updates the user's account balance positively.
 */
void addToTheAccountBalance(string& accountId, double& amount) {

	if (askingPermission() == 'n')
		return;

	vector<stClient> vClients = FileToStClient();

	for (stClient& c : vClients) {
		if (c.accountId == accountId) {
			c.accountBalance += amount;
			backToFileUpdatedBalance(accountId, vClients, c);
			cout << "The Deposit Operation Has Been Done succesfully \n";
			break;
		}
	}
}

/**
 * Prepares the deposit flow reading inputs and updating balances.
 */
void depositOperation() {
	cout << "======================================\n";
	cout << "\t Deposit Screen\n";
	cout << "======================================\n";

	double amount;
	string accountId = readAccountId();

	if (!print_answer(accountId)) {
		return;
	}
	else {
		amount = readAmount("Deposit");
		addToTheAccountBalance(accountId, amount);
	}
}

void withdrawFromTheAccountBalance(string& accountId, double& amount) {

	if (askingPermission() == 'n')
		return;

	vector<stClient> vClients = FileToStClient();

	for (stClient& c : vClients) {
		if (c.accountId == accountId) {
			if (amount > c.accountBalance) {
				cout << "You Cannot Do This Operation The Balance Is Not Enough \n";
				return;
			}
			c.accountBalance -= amount;
			backToFileUpdatedBalance(accountId, vClients, c);
			cout << "The Withdraw Operation Has Been Done succesfully \n";
			break;
		}
	}
}

/**
 * Prepares the withdrawal flow reading inputs and executing withdraw.
 */
void withdrawOperation() {
	cout << "======================================\n";
	cout << "\t Withdraw Screen\n";
	cout << "======================================\n";

	double amount;
	string accountId = readAccountId();

	if (!print_answer(accountId)) {
	}
	else {
		amount = readAmount("Withdraw");
		withdrawFromTheAccountBalance(accountId, amount);
	}
}

double totalBalances(vector<stClient>& vClients) {

	double total = 0;

	for (const stClient& c : vClients)
		total += c.accountBalance;
	return total;
}

void printBalances() {

	vector<stClient> vClients = FileToStClient();

	cout << "\t\t\t\t\t\t Balances List(" << vClients.size() << ") " << "\t\t" << endl;
	cout << "=================================================================================================================\n";
	cout << "| " << left << setw(20) << "Account Id";
	cout << "| " << left << setw(30) << "Client Name";
	cout << "| " << left << setw(40) << "Account balance" << endl;
	cout << "\n";
	cout << "=================================================================================================================\n";

	for (const stClient& c : vClients) {
		cout << "| " << left << setw(20) << c.accountId;
		cout << "| " << left << setw(30) << c.fullName;
		cout << "| " << left << setw(40) << c.accountBalance << endl;
		cout << "\n";
	}
	cout << "=================================================================================================================\n";
	cout << "\t\t\t\t\t ToTal Balances = (" << totalBalances(vClients) << ") " << "\t\t" << endl;
}

/**
 * Delegates the user's selected transaction action.
 */
void choosingOperation(short selectedOption) {

	while (selectedOption != 4) {
		system("cls");

		switch (selectedOption) {
		case 1:
			depositOperation();
			break;
		case 2:
			withdrawOperation();
			break;
		case 3:
			printBalances();
			break;
		}
		cout << "\n Press Any Key To Go Back To The Main Menu ..... \n";
		system("pause>0");
		system("cls");
		selectedOption = transactionMenu();
	}
}

/**
 * Initiates the transaction flow by prompting for operation and dispatching.
 */
void transaction() {
	short selectedOption = transactionMenu();
	choosingOperation(selectedOption);
}
