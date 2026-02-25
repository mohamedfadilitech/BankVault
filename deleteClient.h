#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clientList.h"

using namespace std;

string readAccountId();
string join(vector<string>& vStr, string delim = "#//#");
bool   is_match(string& accountId, vector<stClient>& vClients, stClient& client);
bool   print_answer(string& accountId, stClient& client);
void   removeTheMatch(string& accountId, vector<stClient>& vClients);
void   backToFile(string& accountId);
void   DeleteClient(string& accountId);
