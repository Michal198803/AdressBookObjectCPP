#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>
#include "Contact.h"
#include "Login.h"

class AddressBook {

private:
	int selection;
	int iDNumberLogedUser = 0;
	int idNumberToRemove = 0;
	string loginInserted;
	vector<Contact> contacts;
	vector<Contact> allContactsFromTxtFile;
	vector<Login> logins;

public:

	int logOn(vector<Login>&logins, vector<Contact> contacts, Login login,
			int iDNumberLogedUser, vector<Contact> allContactsFromTxtFile);

	void registration(vector<Login>&logins, vector<Contact> contacts, Login login,
			string loginInserted);



};

