#include <iostream>
#include "Login.h"
using namespace std;

string Login::getLogin() {
	return login;

}

void Login::setLogin(string login) {
	this->login = login;
}
string Login::getpassword() {
	return password;

}

void Login::setpassword(string password) {
	this->password = password;
}

int Login::getUserID() {
	return userId;

}

void Login::setUserID(int userId) {
	this->userId = userId;
}
