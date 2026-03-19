#pragma once
#include "deleteClient.h"
#include "login.h"
#include "addUser.h"

using namespace std;

string readAccountUserName();
bool isAmatchUser(string& userName, vector<stUser>& vUsers, stUser& user);
bool print_answer_users(string& userName);
void removeTheUserMatch(string& userName, vector<stUser>& vUsers);
void backToUsersFile(string& userName);
void DeleteUser(string& userName, stUser &currentUser);