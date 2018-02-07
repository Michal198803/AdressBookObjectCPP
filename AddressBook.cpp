#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>
#include "Contact.h"
#include "Login.h"
#include "AddressBook.h"

using namespace std;

string conversionIntToString(int number) {

	ostringstream ss;
	ss << number;
	string string = ss.str();

	return string;

}

string formatNotation(string text) {
	if (!text.empty()) {
		transform(text.begin(), text.end(), text.begin(), ::tolower);
		text[0] = toupper(text[0]);
	}
	return text;
}

void loadDataFromLoginFile(vector<Login>&logins, vector<Contact>&contacts,
		Login login, int &iDNumberLogedUser) {
	int index = 0;
	string DataTabFromLine[3];
	string dataFromLine;
	string line;

	fstream file;
	file.open("login.txt", ios::in);
	if (file.good() == true) {

		while (getline(file, line)) {

			for (int i = 0; i < line.size(); i++) {

				if (line[i] == '|') {
					DataTabFromLine[index] = dataFromLine;
					dataFromLine = "";
					index++;
					continue;
				}
				dataFromLine += line[i];
			}
			DataTabFromLine[2] = dataFromLine;
			login.setUserID(atoi(DataTabFromLine[0].c_str()));
			login.setLogin(DataTabFromLine[1]);
			login.setpassword(DataTabFromLine[2]);
			index = 0;
			logins.push_back(login);
			dataFromLine = "";

		}
		file.close();
	}
}

Contact getContactFromFile(string contactDataTxt) {

	Contact contact;
	string singleDataContact = "";
	int numberSIngleDataContact = 1;

	for (int charPosition = 0; charPosition < contactDataTxt.length();
			charPosition++) {
		if (contactDataTxt[charPosition] != '|') {
			singleDataContact += contactDataTxt[charPosition];
		} else {
			switch (numberSIngleDataContact) {
			case 1:
				contact.setId(atoi(singleDataContact.c_str()));
				break;
			case 2:
				contact.setUserID(atoi(singleDataContact.c_str()));
				break;
			case 3:
				contact.setName(singleDataContact);
				break;
			case 4:
				contact.setSurname(singleDataContact);
				break;
			case 5:
				contact.setPhone(singleDataContact);
				break;
			case 6:
				contact.setEmail(singleDataContact);

			}
			singleDataContact = "";
			numberSIngleDataContact++;
		}
	}
	contact.setAddress(singleDataContact);
	return contact;
}

void findByContactName(vector<Contact>&contacts)

{
	bool ifFoundPerson = false;
	string name;

	system("cls");
	cout << ">>> SEARCH CONTACT <<<" << endl << endl;
	cout << "Enter name the person you are looking for: " << endl;

	cin >> name;

	for (int indeks = 0; indeks < contacts.size(); indeks++)

	{
		if (contacts[indeks].getName() == name)

		{
			ifFoundPerson = true;

			cout << "Complies with: " << "name " << name << endl;
			cout << endl;

			cout << "Addition number: " << contacts[indeks].getId() << endl;

			cout << "Name: " << contacts[indeks].getName() << endl;

			cout << "Surname: " << contacts[indeks].getSurname() << endl;

			cout << "Phone: " << contacts[indeks].getPhone() << endl;

			cout << "Email: " << contacts[indeks].getEmail() << endl;

			cout << "Address: " << contacts[indeks].getAddress() << endl;
			cout << endl;
		}
	}

	if (ifFoundPerson == false) {
		cout << "There is no such person";
	}
	cout << endl;

}

void loadContactsFromTxtFile(vector<Contact>&contacts,
		int &iDNumberLogedUser) {
	string nameOfTheAdressBookFile = "AddressBook.txt";
	Contact contact;
	string singleDataContact = "";

	fstream textfile;
	textfile.open(nameOfTheAdressBookFile.c_str(), ios::in);

	if (textfile.good() == true) {
		while (getline(textfile, singleDataContact)) {
			contact = getContactFromFile(singleDataContact);

			if (contact.getUserID() == iDNumberLogedUser)
				contacts.push_back(contact);
		}
		textfile.close();
	}
}

void AddContactToFileContact (Contact contact, int iDNumberLogedUser) {
	fstream textfile;
	textfile.open("AddressBook.txt", ios::out | ios::app);

	if (textfile.good() == true) {
		contact.setUserID(iDNumberLogedUser);

		textfile << contact.getId() << '|';
		textfile << contact.getUserID() << '|';
		textfile << contact.getName() << '|';
		textfile << contact.getSurname() << '|';
		textfile << contact.getPhone() << '|';
		textfile << contact.getEmail() << '|';
		textfile << contact.getAddress() << endl;

		textfile.close();
		cout << endl << "Contact added" << endl;
		system("pause");
	} else {
		cout << "No file to open." << endl
				<< endl;
		system("pause");
	}
}

void loadAllEntriesToVector(vector<Contact>&allContactsFromTxtFile) {
	allContactsFromTxtFile.clear();
	Contact contact;
	string singleDataContact = "";

	fstream textfile;
	textfile.open("AddressBook.txt", ios::in);

	if (textfile.good() == true) {
		while (getline(textfile, singleDataContact)) {
			contact = getContactFromFile(singleDataContact);
			allContactsFromTxtFile.push_back(contact);

		}
	}
}

void addContact(vector<Contact> &contacts, vector<Login>&logins,
		vector<Contact> &allContactsFromTxtFile, int &iDNumberLogedUser) {
	loadAllEntriesToVector(allContactsFromTxtFile);
	Contact contact;

	int id, userId;
	string name, surname, address, email, phone;

	string line, dataFromLine;
	char c;
	int numberLinesInFileAdressBook = 0, index = 0, numerIdaddressata;

	system("cls");
	cout << ">>> ADDITION NEW CONTACT <<<" << endl << endl;

	fstream file;
	file.open("login.txt", ios::in);

	std::ifstream f("AddressBook.txt");

	if (allContactsFromTxtFile.size() == 0) {
		contact.setId(1);
	}

	else if (allContactsFromTxtFile.size() != 0) {

		if (file.good() == true) {

			while (f.get(c)) {
				if (c == '\n') {

					++numberLinesInFileAdressBook;
				}
			}
			int idNumbers[numberLinesInFileAdressBook];
			fstream file;
			file.open("AddressBook.txt", ios::in);

			while (getline(file, line)) {
				for (int lineLength = 0; lineLength < line.size();
						lineLength++) {
					if (line[lineLength] == '|') {
						idNumbers[index] = atoi(dataFromLine.c_str());
						index++;

						dataFromLine = "";
						break;

					}

					else {
						dataFromLine += line[lineLength];
					}
				}

			}

			sort(idNumbers, idNumbers + numberLinesInFileAdressBook);
			id = idNumbers[numberLinesInFileAdressBook - 1] + 1;
			contact.setId(id);
		}

	}
	userId = iDNumberLogedUser;
	contact.setUserID(userId);
	cout << "Give the name: ";
	cin >> name;
	name = formatNotation(name);
	contact.setName(name);
	cout << "Give the surname: ";
	cin >> surname;
	surname = formatNotation(surname);
	contact.setSurname(surname);
	cout << "Give the phone number: ";
	cin.sync();
	getline(cin, phone);
	contact.setPhone(phone);
	cout << "Give the email: ";
	cin >> email;
	contact.setEmail(email);
	cout << "Give the address: ";
	cin.sync();
	getline(cin, address);
	contact.setAddress(address);

	contacts.push_back(contact);

 AddContactToFileContact(contact, iDNumberLogedUser);
}

void findByContactSurname(vector<Contact>&contacts)

{
	bool ifFoundPerson = false;

	string surname;

	system("cls");
	cout << ">>> SEARCHING CONTACT <<<" << endl << endl;
	cout << "Give the contact surname: " << endl;

	cin >> surname;

	for (int indeks = 0; indeks < contacts.size(); indeks++) {
		if (contacts[indeks].getSurname() == surname)

		{
			cout << "Correct with: " << "surname " << surname << endl;
			cout << endl;

			cout << "Addition number: " << contacts[indeks].getId() << endl;

			cout << "Name: " << contacts[indeks].getName() << endl;

			cout << "Surname: " << contacts[indeks].getSurname() << endl;

			cout << "Phone: " << contacts[indeks].getPhone() << endl;

			cout << "Email: " << contacts[indeks].getEmail() << endl;

			cout << "Address: " << contacts[indeks].getAddress() << endl;
			cout << endl;

			ifFoundPerson = true;

		}
	}

	if (ifFoundPerson == false)

	{

		cout << "No found";

	}
	cout << endl;

}

void showAllContacts(vector<Contact>&contacts) {
	system("cls");

	{
		cout << ">>> Contacts list <<<" << endl << endl;
		for (int indeks = 0; indeks < contacts.size(); indeks++)

		{
			cout << endl;

			cout << "Addition number:" << contacts[indeks].getId() << endl;

			cout << "Name: " << contacts[indeks].getName() << endl;

			cout << "Surname: " << contacts[indeks].getSurname() << endl;

			cout << "Phone: " << contacts[indeks].getPhone() << endl;

			cout << "Email: " << contacts[indeks].getEmail() << endl;

			cout << "Address: " << contacts[indeks].getAddress() << endl;

			cout << endl;
		}
	}
	system("pause");
}

void deleteLine(int idNumberToRemove, vector<Contact> &allContactsFromTxtFile) {

	loadAllEntriesToVector(allContactsFromTxtFile);

	for (int i = 0; i < allContactsFromTxtFile.size(); i++) {

		if (allContactsFromTxtFile[i].getId() == idNumberToRemove)
			allContactsFromTxtFile.erase(allContactsFromTxtFile.begin() + i);
	}

	fstream fileFormat;
	fileFormat.open("AddressBook.txt", ios::in);
	fileFormat.clear();
	ofstream file;
	file.open("AddressBook.txt", ios::trunc);

	for (int i = 0; i < allContactsFromTxtFile.size(); i++) {

		file << allContactsFromTxtFile[i].getId() << "|"
				<< allContactsFromTxtFile[i].getUserID() << "|"
				<< allContactsFromTxtFile[i].getName() << "|"
				<< allContactsFromTxtFile[i].getSurname() << "|"
				<< allContactsFromTxtFile[i].getEmail() << "|"
				<< allContactsFromTxtFile[i].getPhone() << "|"
				<< allContactsFromTxtFile[i].getAddress() << endl;

	}
	file.close();

}

void deleteFromPhoneBook(vector<Contact>&contacts) {
	char confirmDeletion;
	int deleteContact = 0;
	int idNumberToRemove;
	cout << endl;
	cout << ">>> CONTACT DELETION<<<" << endl << endl;
	cout << "Give ID number person to deletion: " << endl << endl;
	cin >> idNumberToRemove;

	for (int i = 0; i < contacts.size(); i++) {

		if (contacts[i].getId() == idNumberToRemove) {
			cout << "Press t to confirm deletion " << endl;
			cin >> confirmDeletion;

			if (confirmDeletion == 't') {

				contacts.erase(contacts.begin() + i);
				deleteLine(idNumberToRemove, contacts);

				deleteContact = 1;

			}
		}
	}

	switch (deleteContact) {

	case 1:
		cout << "Contact was deleted " << endl;

		break;

	case 0:
		cout << "No found " << endl;

		break;

	}
}

void changeContactData(vector<Contact>&contacts) {

	system("cls");

	fstream file;
	fstream fileTemp;

	file.open("AddressBook.txt", ios::in);
	fileTemp.open("temp.txt", ios::out);



	char id[25];
	char userId[25];
	char nameCharTab[25];
	char surname[25];
	char email[25];
	char phone[25];
	char address[25];
	bool change = false;
	char idToChange[25];
	int selection;
	cin.ignore();
	int indexVectorChange;
	cout << "Enter contact id to change";
	cin >> idToChange;
	string idToStringChange = idToChange;

	if (file.good() == true) {

		while (!file.eof()) {
			file.getline(id, 25, '|');
			file.getline(userId, 25, '|');
			file.getline(nameCharTab, 25, '|');
			file.getline(surname, 25, '|');
			file.getline(email, 100, '|');
			file.getline(phone, 25, '|');
			file.getline(address, 100);

			for (int i = 0; i < contacts.size(); i++) {
				if (contacts[i].getId() == atoi(idToStringChange.c_str())) {

					indexVectorChange = i;

				}
			}

			if (strcmp(id, idToChange) == 0) {

				cout << ">>> Change contact file <<<" << endl << endl;
				cout << "Chose the option: " << endl;

				cout << "1. Name" << endl;

				cout << "2. Surname" << endl;

				cout << "3. Phone" << endl;

				cout << "4. Email" << endl;

				cout << "5.Address" << endl;

				cout << "6.Return to main menu" << endl;

				cin >> selection;
				cin.ignore();
				switch (selection) {

				case 1:
					cout << "Enter new name:  ";
					cin.sync();
					cin.getline(nameCharTab, 25);
					contacts[indexVectorChange].setName(nameCharTab);
					break;
				case 2:
					cout << "Enter new surname:  ";
					cin.sync();
					cin.getline(surname, 25);
					contacts[indexVectorChange].setSurname(surname);
					break;
				case 4:
					cout << "Enter new email:  ";
					cin.sync();
					cin.getline(email, 100);
					contacts[indexVectorChange].setEmail(email);
					break;
				case 3:
					cout << "Enter new phone number:  ";
					cin.sync();
					cin.getline(phone, 25);
					contacts[indexVectorChange].setPhone(phone);
					break;
				case 5:
					cout << "Enter new address:  ";
					cin.sync();
					cin.getline(address, 100);
					contacts[indexVectorChange].setAddress(address);
					break;

				case 6:
					return;

				}
				fileTemp << id << "|" << userId << "|" << nameCharTab << "|"
						<< surname << "|" << phone << "|" << email << "|"
						<< address << '\n';
				change = true;

			} else if (id[0] != '\000') {
				fileTemp << id << "|" << userId << "|" << nameCharTab << "|"
						<< surname << "|" << phone << "|" << email << "|"
						<< address << '\n';
			}

		}
		fileTemp.close();
		file.close();
	}
	file.open("AddressBook.txt", ios::out);
	fileTemp.open("temp.txt", ios::in);
	while (!fileTemp.eof()) {

		fileTemp.getline(id, 25, '|');
		fileTemp.getline(userId, 25, '|');
		fileTemp.getline(nameCharTab, 25, '|');
		fileTemp.getline(surname, 25, '|');
		fileTemp.getline(email, 100, '|');
		fileTemp.getline(phone, 25, '|');
		fileTemp.getline(address, 25);

		if (id[0] != '\000') {
			file << id << "|" << userId << "|" << nameCharTab << "|" << surname
					<< "|" << phone << "|" << email << "|" << address << '\n';
		}
	}
	fileTemp.close();
	file.close();
	remove("temp.txt");
	if (change == true)
		cout << "Contact updated" << endl;
	else if (change == false)
		cout << "Contact are not updated. Please check ID";

}

static void adressBookMenu(vector<Contact>&contacts, vector<Login>&logins,
		Login login, int &iDNumberLogedUser,
		vector<Contact>&allContactsFromTxtFile) {

	loadContactsFromTxtFile(contacts, iDNumberLogedUser);
	int selection;

	while (true)

	{

		system("cls");

		cout << endl;

		cout << "1. Add new contact" << endl;

		cout << "2. Search by name" << endl;

		cout << "3. Search by surname" << endl;

		cout << "4. Show all contacts" << endl;

		cout << "5. Change contacts file" << endl;

		cout << "6. Contact deletion" << endl;

		cout << "9. End of the program" << endl;

		cin >> selection;

		switch (selection) {

		case 1:

			addContact(contacts, logins, allContactsFromTxtFile,
					iDNumberLogedUser);

			break;

		case 2:

			findByContactName(contacts);

			break;

		case 3:

			findByContactSurname(contacts);

			break;

		case 4:

			showAllContacts(contacts);

			break;

		case 5:

			changeContactData(contacts);
			break;

		case 6:

			deleteFromPhoneBook(contacts);

			break;

		case 9:

			exit(0);

		}

	}

}
int AddressBook::logOn(vector<Login>&logins, vector<Contact> contacts,
		Login login, int iDNumberLogedUser,
		vector<Contact> allContactsFromTxtFile) {

	string password;
	string loginInserted;

	cout << "Enter the login: ";
	cin >> loginInserted;
	cout << "Enter the password: ";
	cin >> password;

	loadDataFromLoginFile(logins, contacts, login, iDNumberLogedUser);

	for (int i = 0; i < logins.size(); i++) {
		if ((logins[i].getLogin() == loginInserted)
				&& (logins[i].getpassword() == password)) {
			iDNumberLogedUser = i + 1;

			adressBookMenu(contacts, logins, login, iDNumberLogedUser,
					allContactsFromTxtFile);
		}

	}
	return iDNumberLogedUser;
}

void AddressBook::registration(vector<Login> &logins, vector<Contact> contacts,
		Login login, string loginInserted) {
	system("cls");
	string nameOfTheAdressBookFileLogowania = "login.txt";
	string password, loginString;

	loadDataFromLoginFile(logins, contacts, login, iDNumberLogedUser);
	cout << "Enther the new contact name: " << endl << endl;
	cin >> loginString;
	login.setLogin(loginString);
	cout << "Enter the new password: " << endl << endl;
	cin >> password;
	login.setpassword(password);

	login.setUserID(logins.size() + 1);
	fstream textfilelogOn;
	textfilelogOn.open(nameOfTheAdressBookFileLogowania.c_str(),
			ios::out | ios::app);

	if (textfilelogOn.good() == true) {

		textfilelogOn << login.getUserID() << '|';
		textfilelogOn << login.getLogin() << '|';
		textfilelogOn << login.getpassword() << endl;
		textfilelogOn.close();

		cout << "Login added" << endl << endl;
	} else {
		cout << "No file founded: login.txt" << endl << endl;
	}

}

