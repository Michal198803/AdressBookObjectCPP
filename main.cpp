#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>
#include "AddressBook.h"
#include "Contact.h"

using namespace std;

int main() {
	int selection;
	int iDNumberLogedUser = 0;

	string loginInserted;
	vector<Contact> contacts;
	vector<Contact> allContactsFromTxtFile;
	vector<Login> logins;
	Login login;
	AddressBook book;

	while (true) {

		cout << endl;
		cout << "1.Login" << endl << endl;
		cout << "2.Registration" << endl << endl;
		cout << "3.Close program" << endl << endl;

		cin >> selection;

		switch (selection) {

		case 1:

			book.logOn(logins, contacts, login, iDNumberLogedUser,
					allContactsFromTxtFile);

			break;
		case 2:
			book.registration(logins, contacts, login, loginInserted);

			break;
		case 3:
			exit(0);

		}
	}
}
