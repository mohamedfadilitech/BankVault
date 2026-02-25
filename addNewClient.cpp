#include "addNewClient.h"

string toUpper(string str) {
	for (char& c : str)
		c = toupper(c);
	return str;
}

bool isAccountIdExist(string& accountId) {
	vector<stClient> vClients = FileToStClient();

	for (stClient& vClient : vClients) {
		if (vClient.accountId == toUpper(accountId))
			return true;
	}
	return false;
}

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

string recordToLine(stClient& client, string delim) {

	string str = "";

	str += client.accountId + delim;
	str += client.pinCode   + delim;
	str += client.fullName  + delim;
	str += client.phone     + delim;
	str += to_string(client.accountBalance);
	return str;
}

void addToFile(string& line) {

	fstream myFile("clientsData.txt", ios::app);

	if (!myFile.is_open()) {
		cout << "can't find the file";
		return;
	}
	myFile << line << "\n";
	myFile.close();
}

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
		addToFile(line);
		do {
			cout << "\nYou Want To Add Another Client Press ? Y : N : ";
			cin >> ch;
			ch = tolower(ch);
		} while (ch != 'y' && ch != 'n');
	} while (ch == 'y');
}
