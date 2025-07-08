#include <iostream>
#include "authentication.h" // Including Auth Header File
#include "task.h"           // Including Task Header File
#include <vector>
using namespace std;

int main() {
    int choice; // Choice Variable
    UserAuth auth; // Object From Auth
    vector<task> user_tasks; // Dynamic list of tasks

    do {
        cout << "----To-Do List App----\nAll Data Is Erased After Application Is Terminated\n";
        cout << "1. Signup\n2. Login\n3. Forget Password\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            auth.signup();

        } else if (choice == 2) {
            if (auth.login() == true) {
                int menu_choice; // Moved declaration here to avoid conflict

                do {
                    cout << "\n----To-Do List Menu----\n";
                    cout << "1. Add Task\n2. View Tasks\n3. Exit to Main Menu\n";
                    cout << "Enter Your Choice: ";
                    cin >> menu_choice;

                    if (menu_choice == 1) {
                        task new_task; // Create a new task object
                        new_task.add_task();
                        user_tasks.push_back(new_task);
                        cout << "Task Added Successfully.\n";

                    } else if (menu_choice == 2) {
                        if (user_tasks.empty()) {
                            cout << "-------------------------------------" << endl;
                            cout << "No Tasks Were Found.";
                            cout << "-------------------------------------" << endl;
                        } else {
                            for (int i = 0; i < user_tasks.size(); i++) {
                                cout << "-------------------------------------" << endl;
                                cout << "\nTask #" << i + 1 << ":\n";
                                user_tasks[i].view_task();
                                cout << "-------------------------------------" << endl;
                            }
                        }

                    } else if (menu_choice == 3) {
                        cout << "Returning to main menu...\n";

                    } else {
                        cout << "Invalid choice.\n";
                    }

                } while (menu_choice != 3); // Loop Task Menu
            }

        } else if (choice == 3) {
            auth.forgetPassword();

        } else if (choice == 4) {
            cout << "Goodbye :)\n";

        } else {
            cout << "Invalid main menu choice.\n";
        }

    } while (choice != 4); // Loop Main Menu

    return 0;
}
