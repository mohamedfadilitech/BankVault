#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clientList.h"
#include "deleteClient.h"
#include "menu.h"

using namespace std;

double readAmount(string operation);
char   askingPermission();
void   backToFileUpdatedBalance(string& accountId, vector<stClient>& vClients, stClient& updatedClient);
void   addToTheAccountBalance(string& accountId, double& amount, stClient& client);
void   depositOperation(stClient& client);
void   withdrawFromTheAccountBalance(string& accountId, double& amount, stClient& client);
void   withdrawOperation(stClient& client);
double totalBalances(vector<stClient>& vClients);
void   printBalances();
void   choosingOperation(short selectedOption, stClient& client);
void   transaction(stClient& client);
