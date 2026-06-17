#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string FILE_NAME = "tasks.txt";
const int MAX_TASKS = 100;

// Add a new task
void addTask(const string& task) {
    ofstream file(FILE_NAME, ios::app);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }
    file << task << endl;
    file.close();
    cout << "Task added.\n";
}

// View all tasks
int viewTasks(string tasks[]) {
    ifstream file(FILE_NAME);
    if (!file) {
        cout << "No tasks found.\n";
        return 0;
    }

    int count = 0;
    string line;
    cout << "\n--- To-Do List ---\n";
    while (getline(file, line) && count < MAX_TASKS) {
        tasks[count] = line;
        cout << count + 1 << ". " << tasks[count] << endl;
        count++;
    }
    file.close();
    return count;
}

// Remove a task by number
void markTaskDone(int indexToRemove, string tasks[], int taskCount) {
    ofstream file(FILE_NAME); // overwrite
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        if (i != indexToRemove - 1) {
            file << tasks[i] << endl;
        }
    }
    file.close();
    cout << "Task marked as done and removed.\n";
}

int main() {
    int choice;
    string task;
    string tasks[MAX_TASKS];
    int taskNum;

    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Done\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        if (choice == 1) {
            cout << "Enter task: ";
            getline(cin, task);
            addTask(task);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            int total = viewTasks(tasks);
            if (total == 0) continue;
            cout << "Enter task number to mark as done: ";
            cin >> taskNum;
            if (taskNum >= 1 && taskNum <= total)
                markTaskDone(taskNum, tasks, total);
            else
                cout << "Invalid task number.\n";
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

