/**
 * login.cpp
 * Implements data extraction for user authentication details from the file-based system.
 */
#include "login.h"
#include "clientList.h" // Needed for readLineFromFile and split functions

    stUser vectorToStUser(vector<string>&vStr) {
        stUser user;

        if (vStr.size() < 3) {
            user.userName = "";
            user.passwd = "";
            user.permissions = 0;
            return user;
        }

        user.userName = vStr.at(0);
        user.passwd = vStr.at(1);
        user.permissions = stoi(vStr.at(2));
        return user;
    }


vector<stUser> FileToStUser() {

    vector<string> vLines = readLineFromFile("users.txt");
    vector<string> splittedLine;
    vector<stUser> users;

    // Parse each line from the users file into a stUser object
    for (const string& vLine : vLines) {
        splittedLine = split(vLine);
        users.push_back(vectorToStUser(splittedLine));
    }
    return users;
}