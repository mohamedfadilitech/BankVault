#pragma once
#include<iostream>
using namespace std;

void	menuDesign() {

	cout << "================================================\n";
	cout << "\t\tMain Menu \n";
	cout << "================================================\n";
	cout << "\t [1] Show Client List. \n";
	cout << "\t [2] Add New Client. \n";
	cout << "\t [3] Delete Client. \n";
	cout << "\t [4] Update Client Info. \n";
	cout << "\t [5] Find Client. \n";
	cout << "\t [6] Exit. \n";
	cout << "================================================\n";
}

short	menu() {

	short i;
	menuDesign();
	do {
		cout << "Choose Waht Do You Want To Do ? [1 To 6] ? ";
		cin >> i;
	} while (i < 1 || i > 6);
	return i;
}