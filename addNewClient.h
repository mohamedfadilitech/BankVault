#pragma once
#include <iostream>
#include <string>
#include "clientList.h"

using namespace std;

string    toUpper(string str);
bool      isAccountIdExist(string& accountId);
stClient  readCustomerInfos();
string    recordToLine(stClient& client, string delim = "#//#");
void      addToFile(string& line);
void      recordToFile();
