#ifndef LOGIN
#define LOGIN

#include <iostream>
using namespace std;

class Login {

private:
	int userId;
	string login;
	string password;

public:
	string getLogin();
	void setLogin(string login);
	string getpassword();
	void setpassword(string password);
	int getUserID();
	void setUserID(int userId);

};
#endif
