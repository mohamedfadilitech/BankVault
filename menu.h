#pragma once
#include "login.h"

/**
 * menu.h
 * Declarations for the UI display systems relating to selection menus.
 */

using namespace std;

bool	hasPermission(stUser currentUser, enOperations operation);
void  menuDesign(stUser currentUser);
short transactionMenu();
short manageUsersMenu();
short menu(stUser currentUser);

