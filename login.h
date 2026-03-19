#pragma once
#include <vector>
#include <string>

/**
 * login.h
 * Declarations defining User authentication structures and enums governing User permissions.
 */

using namespace std;

enum enOperations {eShowClientList = 1, 
	eAddNewClient = 2, 
	eDeleteClient = 4, 
	eUpdateClient = 8, 
	eFindClient	 = 16,
	eTransactions = 32,
	eManageUsers  = 64
	};

struct stUser {

	string userName;
	string passwd;
	int permissions;
};

stUser vectorToStUser(vector<string>& vStr);
vector<stUser> FileToStUser();