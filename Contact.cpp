#include <iostream>
#include "Contact.h"
using namespace std;

int Contact::getId() {
	return id;
}
void Contact::setId(int id) {
	this->id = id;
}
int Contact::getUserID() {
	return userId;
}
void Contact::setUserID(int userId) {
	this->userId = userId;
}

string Contact::getName() {
	return name;

}

void Contact::setName(string name) {
	this->name = name;
}

string Contact::getSurname() {
	return surname;

}

void Contact::setSurname(string surname) {
	this->surname = surname;
}
string Contact::getAddress() {
	return address;

}
void Contact::setAddress(string address) {
	this->address = address;
}
string Contact::getEmail() {
	return email;

}
void Contact::setEmail(string email) {
	this->email = email;
}
string Contact::getPhone() {
	return phone;

}
void Contact::setPhone(string phone) {
	this->phone = phone;
}
