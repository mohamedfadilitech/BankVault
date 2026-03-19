#pragma once
#include <vector>
#include <string>

/**
 * clientList.h
 * Contains the core stClient structure definition, along with the logic for 
 * reading and displaying the client database.
 */

using namespace std;

struct stClient {
	string accountId;
	string pinCode;
	string fullName;
	string phone;
	double accountBalance;
};

vector<string>   readLineFromFile(string fileName);
vector<string>   split(string str, string delimiter = "#//#");
stClient         vectorToSt(vector<string>& vStr);
vector<stClient> FileToStClient();
void             printClientInfos();
