#include<iostream>
#include<vector>
using namespace std;
vector<string> TASKS;
vector<char> status;
void AddTasks() {
    string task;
    cout << "Enter a task to add to your to-do list: ";
    cin.ignore(); 
    getline(cin, task);
    TASKS.push_back(task);
    status.push_back('p'); 
}
void PrintTasks() {
    cout << endl << "Your To-Do list:" << endl;
    for (int i = 0; i < TASKS.size(); i++) {
        cout << i + 1 << ". " << TASKS[i] << " [" << status[i] << "]" << endl;
    }
    cout << endl;
}
void DeleteTask() {
    int num;
    cout << "Enter the task number you want to remove: ";
    cin >> num;
    if (num >= 1 && num <= TASKS.size()) {
        TASKS.erase(TASKS.begin() + num - 1);
        status.erase(status.begin() + num - 1);
    }
    else {
        cout << "Invalid Task Number" << endl;
    }
}
void SetStatus() {
    int num;
    cout << "Enter the task number to set status (1 to " << TASKS.size() << "): ";
    cin >> num;
    if (num >= 1 && num <= TASKS.size()) {
        char newStatus;
        cout << "Enter the status (c for completed and p for pending): ";
        cin >> newStatus;
        if (newStatus == 'c' || newStatus == 'p') {
            status[num - 1] = newStatus;
        }
        else {
            cout << "Invalid Status" << endl;
        }
    }
    else {
        cout << "Invalid Task Number" << endl;
    }
}
int main() {
    int choice;
    while (1) {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Print Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Set Status" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            AddTasks();
            break;
        case 2:
            PrintTasks();
            break;
        case 3:
            DeleteTask();
            break;
        case 4:
            SetStatus();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}

