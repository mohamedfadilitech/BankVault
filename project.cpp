#include "menu.h"
#include "clientList.h"
#include "addNewClient.h"
#include "deleteClient.h"
#include "update.h"
#include "transaction.h"
#include "login.h"
#include "manageUsers.h"
#include "addUser.h"
#include <iostream>

/**
 * project.cpp
 * Entry point for the Bank Project application.
 * Handles the main login flow and the primary dispatch menu.
 */

using namespace std;

/**
 * Prompts the user for login credentials and verifies them against users.txt.
 * Keeps prompting until a valid username and password combination is provided.
 * @return The authenticated stUser struct on success, empty struct if loop exits unexpectedly.
 */
stUser logIn() {

    stUser None;
    cout << "======================================\n";
    cout << "\t Login Screen\n";
    cout << "======================================\n";

    vector<stUser> vUsers = FileToStUser();
    string loginUserName;
    string loginPasswd;
    bool sw = false;

    do {
        cout << "Enter The the userName : ";
        getline(cin >> ws, loginUserName);
        cout << "\n";
        cout << "Enter The the password : ";
        getline(cin >> ws, loginPasswd);

        for (int i = 0; i < vUsers.size(); i++)
        {
            if (loginUserName == vUsers.at(i).userName && loginPasswd == vUsers.at(i).passwd) {
                sw = true;
                return vUsers.at(i);
            }
        }
        system("cls");
        cout << "invalid UserName/password \n";
    } while (sw == false);
    return None;
}

/**
 * Prints an ACCESS DENIED screen.
 * Called whenever a user attempts an operation they don't have permission for.
 */
void accessDenied() {
    cout << "======================================\n";
    cout << "\t ACCESS DENIED\n";
    cout << "======================================\n";
}

/**
 * Displays the client list if the user has the eShowClientList permission.
 * @param currentUser The currently authenticated user.
 */
void showClientList(stUser& currentUser) {
    if (!hasPermission(currentUser, eShowClientList)) { accessDenied(); return; }
    printClientInfos();
}

/**
 * Launches the Add New Client screen if the user has the eAddNewClient permission.
 * @param currentUser The currently authenticated user.
 */
void addNewClient(stUser& currentUser) {
    if (!hasPermission(currentUser, eAddNewClient)) { accessDenied(); return; }
    recordToFile();
}

/**
 * Prints the Delete Client screen header.
 * Extracted to avoid repeating the title inside the delete loop.
 */

/**
 * Handles the Delete Client flow if the user has the eDeleteClient permission.
 * Allows deleting multiple clients in a single session via a loop.
 * @param currentUser The currently authenticated user.
 */
void deleteClientScreen(stUser& currentUser) {
    if (!hasPermission(currentUser, eDeleteClient)) { accessDenied(); return; }
    char ch;
    string accountId;
    do {
        deleteScreenTitle("Client");
        accountId = readAccountId();
        if (print_answer(accountId))
            DeleteClient(accountId);
        ch = checkYesOrNo("You Want To Delete Another Account ? Y:N");
        system("cls");
    } while (ch == 'y');
}

/**
 * Handles the Update Client flow if the user has the eUpdateClient permission.
 * Looks up the client by account ID before allowing updates.
 * @param currentUser The currently authenticated user.
 */
void updateClientScreen(stUser& currentUser) {
    if (!hasPermission(currentUser, eUpdateClient)) { accessDenied(); return; }
    string accountId;
    char ch;
   
    do {
         updateScreenTitle("Client");
         accountId = readAccountId();
        if (print_answer(accountId))
            update(accountId);
        ch = checkYesOrNo("You Want To Update Another Account ? Y:N ");
        system("cls");
    } while (ch == 'y');
}

/**
 * Handles the Find Client flow if the user has the eFindClient permission.
 * Searches for a client by account ID and displays their details.
 * @param currentUser The currently authenticated user.
 */
void findClientScreen(stUser& currentUser) {
    if (!hasPermission(currentUser, eFindClient)) { accessDenied(); return; }

    string accountId;
    char ch;
    do {
        findUserScreenTitle("Client");
        accountId = readAccountId();
        print_answer(accountId);
        ch = checkYesOrNo("You Want To find Another Client ? Y:N ");
        system("cls");
    } while (ch == 'y');
}

/**
 * Launches the Transaction screen if the user has the eTransactions permission.
 * Covers deposit, withdrawal, and total balance operations.
 * @param currentUser The currently authenticated user.
 */
void transactionScreen(stUser& currentUser) {
    if (!hasPermission(currentUser, eTransactions)) { accessDenied(); return; }
    transaction();
}

/**
 * Launches the Manage Users screen if the user has the eManageUsers permission.
 * Allows listing, adding, deleting, and updating system users.
 * @param currentUser The currently authenticated user.
 */
void manageUsersScreen(stUser& currentUser) {
    if (!hasPermission(currentUser, eManageUsers)) { accessDenied(); return; }
    manageUsers(currentUser);
}

/**
 * Displays the main menu and dispatches to the selected screen.
 * Loops until the user selects option 8 (Logout).
 * Each case delegates to a dedicated screen function that handles its own permission check.
 * @param currentUser The currently authenticated user passed by reference.
 * @return The selected option when the loop exits (8 = Logout).
 */
int runMainMenu(stUser& currentUser) {

    short selectedOption = menu(currentUser);

    while (selectedOption != 8) {
        system("cls");

        switch (selectedOption) {
        case 1: showClientList(currentUser);     break;
        case 2: addNewClient(currentUser);       break;
        case 3: deleteClientScreen(currentUser); break;
        case 4: updateClientScreen(currentUser); break;
        case 5: findClientScreen(currentUser);   break;
        case 6: transactionScreen(currentUser);  break;
        case 7: manageUsersScreen(currentUser);  break;
        }

        cout << "\n Press Any Key To Go Back To The Main Menu .....\n";
        system("pause>0");
        system("cls");
        selectedOption = menu(currentUser);
    }
    return selectedOption;
}

/**
 * Application entry point.
 * Runs a continuous login/logout loop — when the user logs out (i == 8),
 * the login screen appears again instead of closing the program.
 */
int main() {
    stUser currentUser;
    int i;
    do {
        system("cls");
        currentUser = logIn();
        system("cls");
        i = runMainMenu(currentUser);
    } while (i == 8);
}