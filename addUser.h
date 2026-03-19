#pragma once
#include "login.h"
#include "addNewClient.h"

/**
 * addUser.h
 * Declarations for user addition logic and permissions assignment.
 */

using namespace std;

bool isAccountUserIdExist(string& userName);
char checkYesOrNo(string sentence);
stUser readUserInfos();
string recordToLineUserFile(stUser& user, string delim);
int readUserPermissions();
void recordToUserFile();



