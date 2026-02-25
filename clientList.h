#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct stClient {
	string accountId;
	string pinCode;
	string fullName;
	string phone;
	double accountBalance;
};

vector<string>   readLineFromFile();
vector<string>   split(string str, string delimiter = "#//#");
stClient         vectorToSt(vector<string>& vStr);
vector<stClient> FileToStClient();
void             printClientInfos();
