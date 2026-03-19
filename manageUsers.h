#pragma once
#include "usersList.h"
#include "menu.h"

/**
 * Contains functions for routing user-management actions like adding users,
 * listing users, or displaying the manage users menu.
 */

using namespace std;

void choosingOperationForUsers(short selectedOption, stUser& currentUser);
void deleteUserScreen(stUser& currentUser);
void manageUsers(stUser &currentUser);
void deleteScreenTitle(string placeholder);
void updateScreenTitle(string placeholder);
void	findUserScreenTitle(string placeholder);

