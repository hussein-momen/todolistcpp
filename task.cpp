#include "task.h"
#include <iostream>
#include <string>
using namespace std;

void task::add_task() {
    cin.ignore(); // Clear leftover newline from previous input

    cout << "Enter Task Title: ";
    getline(cin, title);

    cout << "Enter Task Description: ";
    getline(cin, description);

    cout << "Enter Task Priority[High-Medium-Low..You Can Add Any Priority Type]: ";
    getline(cin, prior);
    isdone = false; // Default: task is not done
}

void task::view_task() {
    cout << "Title              : " << title << endl;
    cout << "Description  : " << description << endl;
    cout << "Priority        : " << prior << endl;
    cout << "Status          : " << (isdone ? "Done" : "Not Done") << endl;
}
