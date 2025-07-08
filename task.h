#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>
using namespace std;
class task {
public:
    int id = 0;
    string title = "";
    string description = "";
    string prior = "";
    bool isdone = false;
    void add_task();
    void view_task();
};

#endif // TASK_H
