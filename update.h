#pragma once
#include <iostream>
#include <string>
#include "clientList.h"
#include "deleteClient.h"

using namespace std;

stClient updateClient(string& accountId);
void     backToFileUpdated(string& accountId);
void     update(string& accountId);
