#pragma once
#include <string>
#include <vector>
#include "clientList.h"

/**
 * update.h
 * Declarations for updating client account information, such as rewriting the
 * data file with the new details.
 */

using namespace std;

stClient updateClient(string& accountId);
void     backToFileUpdated(string& accountId);
void     update(string& accountId);
