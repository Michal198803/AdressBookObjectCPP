#ifndef CONTACT
#define CONTACT
#include <iostream>

using namespace std;

class Contact {

private:
	int id;
	int userId;
	string name;
	string surname;
	string phone;
	string email;
	string address;

public:
	int getId();
	void setId(int id);
	int getUserID();
	void setUserID(int id);
	string getName();
	void setName(string name);
	string getSurname();
	void setSurname(string surname);
	string getAddress();
	void setAddress(string address);
	string getPhone();
	void setPhone(string phone);
	string getEmail();
	void setEmail(string email);

};
#endif
