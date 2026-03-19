#pragma once
#include <vector>
#include <string>
#include "clientList.h"

/**
 * deleteClient.h
 * Declarations for deleting clients from the system, tracking matches,
 * and maintaining the file integrity.
 */

using namespace std;

string readAccountId();
string join(vector<string>& vStr, string delim = "#//#");
bool   is_match(string& accountId, vector<stClient>& vClients, stClient& client);
bool   print_answer(string& accountId);
void   removeTheMatch(string& accountId, vector<stClient>& vClients);
void   backToFile(string& accountId);
void   DeleteClient(string& accountId);
