#include "menu.h"
#include "clientList.h"
#include "addNewClient.h"
#include "deleteClient.h"
#include "update.h"
#include "transaction.h"
#include <iostream>

using namespace std;

void runMainMenu(stClient& client) {

    short selectedOption = menu();
    bool found;
    string accountId;

    while (selectedOption != 7) {
        system("cls");

        switch (selectedOption) {

        case 1:
            printClientInfos();
            break;

        case 2:
            recordToFile();
            break;

        case 3:
            cout << "======================================\n";
            cout << "\t Delete Client Screen\n";
            cout << "======================================\n";
            accountId = readAccountId();
            found = print_answer(accountId, client);
            if (found)
                DeleteClient(accountId);
            break;

        case 4:
            cout << "======================================\n";
            cout << "\t Update Client Info Screen\n";
            cout << "======================================\n";
            accountId = readAccountId();
            found = print_answer(accountId, client);
            if (found)
                update(accountId);
            break;

        case 5:
            cout << "======================================\n";
            cout << "\t Find Client Screen\n";
            cout << "======================================\n";
            accountId = readAccountId();
            print_answer(accountId, client);
            break;

        case 6:
            transaction(client);
            break;
        }

        cout << "\n Press Any Key To Go Back To The Main Menu ..... \n";
        system("pause>0");
        system("cls");
        selectedOption = menu();
    }
}

int main() {
    stClient client;
    runMainMenu(client);
}
