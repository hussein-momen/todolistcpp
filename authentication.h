#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H


#include <string>
using namespace std;

const int MAX_USERS = 100;

class UserAuth {
private:
    string usernames[MAX_USERS];
    string passwords[MAX_USERS];
    string backupCodes[MAX_USERS];
    int userCount = 0;

public:


    bool signup();
    bool login();
    bool forgetPassword();
};
#endif // AUTHENTICATION_H
