#pragma once
#include <vector>
#include <string>
#include "clientList.h"

/**
 * transaction.h
 * Declarations for account transactions (depositing, withdrawing, total sums).
 */

using namespace std;

double readAmount(string operation);
char   askingPermission();
void   backToFileUpdatedBalance(string& accountId, vector<stClient>& vClients, stClient& updatedClient);
void   addToTheAccountBalance(string& accountId, double& amount);
void   depositOperation();
void   withdrawFromTheAccountBalance(string& accountId, double& amount);
void   withdrawOperation();
double totalBalances(vector<stClient>& vClients);
void   printBalances();
void   choosingOperation(short selectedOption);
void   transaction();
