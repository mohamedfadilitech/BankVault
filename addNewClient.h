#pragma once
#include <string>
#include "clientList.h"

/**
 * addNewClient.h
 * Declarations for the routines that accept new client information and
 * append them to the text storage.
 */

using namespace std;

string    toUpper(string str);
bool      isAccountIdExist(string& accountId);
stClient  readCustomerInfos();
string    recordToLine(stClient& client, string delim = "#//#");
void      addToFile(string& line,string fileName);
void      recordToFile();