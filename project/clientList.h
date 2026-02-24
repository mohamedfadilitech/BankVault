#pragma once
#include<iostream>
#include<vector>
#include<cctype>
#include<string>
#include<fstream>
#include <iomanip>

using namespace std;

	struct stClient {

		string accountId;
		string pinCode;
		string fullName;
		string phone;
		double accountBalance;
	};


	vector<string>	readLineFromFile() {

		fstream myFile;
		string line;
		vector <string> vLines;

		myFile.open("clientsData.txt", ios::in);
		if (!myFile.is_open()) {
			cout << "error opening file \n";
			return vLines;
		}
		while (getline(myFile, line))
			vLines.push_back(line);
		myFile.close();
		return vLines;
	}

	vector<string>	split(string str, string delimiter = "#//#") {

		vector<string> vStr;
		string sWord;
		int pos;

		while ((pos = str.find(delimiter)) != string::npos) {

			sWord = str.substr(0, pos);
			if (sWord != "")
				vStr.push_back(sWord);
			str.erase(0, pos + delimiter.length());
		}
		if (str != "")
			vStr.push_back(str);
		return vStr;
	}

	stClient	vectorToSt(vector<string>& vStr) {

		stClient client;

		client.accountId = vStr.at(0);
		client.pinCode = vStr.at(1);
		client.fullName = vStr.at(2);
		client.phone = vStr.at(3);
		client.accountBalance = stod(vStr.at(4));

		return client;
	}

	vector<stClient>	FileToStClient() {

		vector<string> vLines = readLineFromFile();

		vector<string> splittedLine;
		vector<stClient> clients;

		for (const string& vLine : vLines) {

			splittedLine = split(vLine);
			clients.push_back(vectorToSt(splittedLine));
		}
		return clients;
	}

	void	printClientInfos() {

		vector<stClient> vClients = FileToStClient();

		cout << "\t\t\t\t\t\t Clients List(" << vClients.size() << ") " << "\t\t" << endl;
		cout << "=================================================================================================================\n";
		cout << "| " << left << setw(13) << "Account Id";
		cout << "| " << left << setw(20) << "pin code";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(20) << "Phone";
		cout << "| " << left << setw(20) << "Account balance" << endl;
		cout << "\n";
		cout << "=================================================================================================================\n";

		for (const stClient& client : vClients) {

			cout << "| " << left << setw(13) << client.accountId;
			cout << "| " << left << setw(20) << client.pinCode;
			cout << "| " << left << setw(20) << client.fullName;
			cout << "| " << left << setw(20) << client.phone;
			cout << "| " << left << setw(20) << client.accountBalance << endl;
			cout << "\n";
		}
		cout << "=================================================================================================================\n";

	}



