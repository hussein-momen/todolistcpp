#include "authentication.h"
#include <iostream>
#include <cstdlib> // for rand()


bool UserAuth::signup() {
    string user, pass;
    cout << "Enter a new username: ";
    cin >> user;

    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == user) {
            cout << "Username already exists.\n";
            return false;
        }
    }

    cout << "Enter a new password: ";
    cin >> pass;

    string backup = to_string(rand() % 90000 + 10000);

    usernames[userCount] = user;
    passwords[userCount] = pass;
    backupCodes[userCount] = backup;
    userCount++;

    cout << "Signup successful! Your backup code is: " << backup << "\n";
    return true;
}

bool UserAuth::login() {
    string user, pass;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == user && passwords[i] == pass) {
            cout << "Login successful!\n";
            return true;
        }
    }

    cout << "Invalid credentials.\n";
    return false;
}

bool UserAuth::forgetPassword() {
    string user, code;
    cout << "Enter your username: ";
    cin >> user;
    cout << "Enter your backup code: ";
    cin >> code;

    for (int i = 0; i < userCount; i++) {
        if (usernames[i] == user && backupCodes[i] == code) {
            string newPass;
            cout << "Backup code verified.\nEnter new password: ";
            cin >> newPass;
            passwords[i] = newPass;
            cout << "Password reset successful!\n";
            return true;
        }
    }

    cout << "Invalid username or backup code.\n";
    return false;
}
